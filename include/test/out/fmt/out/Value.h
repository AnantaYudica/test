#ifndef TEST_OUT_FMT_OUT_VALUE_H_
#define TEST_OUT_FMT_OUT_VALUE_H_

#include "../../../System.h"
#include "../../../Pointer.h"
#include "../Definition.h"
#include "Block.h"

#include <utility>
#include <type_traits>

namespace test::out::fmt::out
{

class Value;

}

#ifndef TEST_OUT_FMT_OUT_VALUE_DLEVEL

#define TEST_OUT_FMT_OUT_VALUE_DLEVEL 2

#endif //!TEST_OUT_FMT_OUT_VALUE_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_OUT_VALUE_DLEVEL, 
    "test::out::fmt::out::Value", test::out::fmt::out::Value);


namespace test
{
namespace out
{
namespace fmt
{
namespace out
{

class Value
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::out::fmt::out::Value> DebugType;
public:
    typedef test::out::fmt::Definition DefinitionType;
    typedef typename DefinitionType::OutputIntegerType OutputIntegerType;
    template<typename TChar>
    using FormatOutputFuncType = DefinitionType::FormatOutputFuncType<TChar>;
    typedef test::out::fmt::out::Block BlockType;
    typedef test::Pointer<char> RawType;
private:
    static inline std::size_t SetBlocks(RawType& raw, std::size_t n, std::size_t i);
    template<typename... TBlockArgs>
    static inline std::size_t SetBlocks(RawType& raw, std::size_t n, 
        std::size_t i, BlockType&& block, TBlockArgs&&... blocks);
private:
    template<typename... TBlockArgs>
    static inline std::size_t SetRaw(RawType raw, BlockType&& block, 
        TBlockArgs&&... blocks);
private:
    RawType m_raw;
public:
    inline Value();
    inline Value(const std::size_t& n);
    template<typename... TBlockArgs>
    inline Value(BlockType&& block, TBlockArgs&&... blocks);
    inline explicit Value(RawType ptr);
    inline ~Value();
public:
    inline Value(const Value& cpy);
    inline Value(Value&& mov);
public:
    inline Value& operator=(const Value& cpy);
    inline Value& operator=(Value&& mov);
public:
    template<typename... TBlockArgs>
    inline std::size_t Set(BlockType&& block, TBlockArgs&&... blocks);
public:
    inline std::size_t Size() const;
public:
    template<typename TChar>
    inline FormatOutputFuncType<TChar> GetFormatOutput() const;
    template<typename TChar>
    inline FormatOutputFuncType<TChar> GetFormatOutput(TChar&&) const;
public:
    inline RawType GetRaw();
};

inline std::size_t Value::SetBlocks(RawType& raw, std::size_t n, std::size_t i)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "SetBlocks(raw=%p, n=%zu, i=%zu)", raw.GetData(), n, i);

    return i;
}

template<typename... TBlockArgs>
inline std::size_t Value::SetBlocks(RawType& raw, std::size_t n, 
    std::size_t i, BlockType&& block, TBlockArgs&&... blocks)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "SetBlocks<%s>(raw=%p, n=%zu, i=%zu, args={%s})",
        TEST_SYS_DEBUG_TARGS_NAME_STR(BlockType, TBlockArgs...),
        raw.GetData(), n, i, TEST_SYS_DEBUG_TARGS_VALUE_STR(block, blocks...));

    if (i >= n)
    {
        return i;
    }

    auto raw_block = 
        (raw + (i * sizeof(BlockType))).ReinterpretCast<BlockType>();
    *raw_block = block;
    return SetBlocks(raw, n, i + 1, std::forward<TBlockArgs>(blocks)...);
}

template<typename... TBlockArgs>
inline std::size_t Value::SetRaw(RawType raw, BlockType&& block, 
    TBlockArgs&&... blocks)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "SetRaw<%s>(raw=%p, args={%s})",
        TEST_SYS_DEBUG_TARGS_NAME_STR(BlockType, TBlockArgs...),
        raw.GetData(), TEST_SYS_DEBUG_TARGS_VALUE_STR(block, blocks...));

    const std::size_t size = sizeof...(TBlockArgs) + 1;
    auto raw_size = raw.ReinterpretCast<std::size_t>();
    *raw_size = size;
    auto raw_blocks = raw + sizeof(std::size_t);
    return SetBlocks(raw_blocks, size, (std::size_t)0, std::forward<BlockType>(block),
        std::forward<TBlockArgs>(blocks)...);
}

inline Value::Value() :
    m_raw(nullptr)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");
}

inline Value::Value(const std::size_t& n) :
    m_raw(test::ptr::arg::Array{sizeof(std::size_t) + 
        (n * sizeof(BlockType))})
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(n=%zu)", n);

    auto raw_size = m_raw.template ReinterpretCast<std::size_t>();
    *raw_size = n;
}


template<typename... TBlockArgs>
inline Value::Value(BlockType&& block, TBlockArgs&&... blocks) :
    m_raw(test::ptr::arg::Array{sizeof(std::size_t) + 
        ((sizeof...(TBlockArgs) + 1) * sizeof(BlockType))})
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor<%s>(args={%s})", 
            TEST_SYS_DEBUG_TARGS_NAME_STR(BlockType, TBlockArgs...),
            TEST_SYS_DEBUG_TARGS_VALUE_STR(block, blocks...));
    
    SetRaw(m_raw, std::forward<BlockType>(block),
        std::forward<TBlockArgs>(blocks)...);
}

inline Value::Value(RawType ptr) :
    m_raw(ptr)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(ptr=%p)", ptr.GetData());
}

inline Value::~Value()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor()");
}

inline Value::Value(const Value& cpy) :
    m_raw(cpy.m_raw)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);
}

inline Value::Value(Value&& mov) :
    m_raw(std::move(mov.m_raw))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);
}

inline Value& Value::operator=(const Value& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);
    
    m_raw = cpy.m_raw;
    return *this;
}

inline Value& Value::operator=(Value&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);

    m_raw = std::move(mov.m_raw);
    return *this;
}

template<typename... TBlockArgs>
inline std::size_t Value::Set(BlockType&& block, TBlockArgs&&... blocks)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "Set<%s>(args={%s})", 
            TEST_SYS_DEBUG_TARGS_NAME_STR(BlockType, TBlockArgs...),
            TEST_SYS_DEBUG_TARGS_VALUE_STR(block, blocks...));
    
    const std::size_t size = Size();
    auto raw_blocks = m_raw + sizeof(std::size_t);
    return SetBlocks(raw_blocks, size, (std::size_t)0, 
        std::forward<BlockType>(block), std::forward<TBlockArgs>(blocks)...);
}

inline std::size_t Value::Size() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Size() const");

    auto t = const_cast<Value*>(this);
    if (m_raw.Size() >= sizeof(std::size_t))
    {
        return *(t->m_raw.ReinterpretCast<std::size_t>());
    }
    return 0;
}

template<typename TChar>
inline typename Value::FormatOutputFuncType<TChar> 
Value::GetFormatOutput() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "GetFormatOutput<%s>() const", TEST_SYS_DEBUG_T_NAME_STR(TChar));
    
    return GetFormatOutput((TChar)0);
}

template<typename TChar>
inline typename Value::FormatOutputFuncType<TChar> 
Value::GetFormatOutput(TChar&& ch) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "GetFormatOutput<%s>(%s) const", TEST_SYS_DEBUG_T_NAME_STR(TChar),
        TEST_SYS_DEBUG_TARGS_VALUE_STR(ch));

    auto t = const_cast<Value*>(this);
    const std::size_t size = Size();
    const auto type = DefinitionType::OutputValue(std::forward<TChar>(ch));
    if (size == 0)
    {
        return nullptr;
    }
    auto raw_blocks = (t->m_raw + sizeof(std::size_t));

    for (std::size_t i = 0; i < size; ++i)
    {
        auto block = raw_blocks.ReinterpretCast<BlockType>();
        if (block->GetType() == type)
        {
            return block->template GetFormatOutput<TChar>();
        }
        raw_blocks += sizeof(BlockType);
    }

    return nullptr;
}

inline typename Value::RawType Value::GetRaw()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetRaw() const");
    
    return m_raw;
}

} //!out

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_OUT_VALUE_H_
