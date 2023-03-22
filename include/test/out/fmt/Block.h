#ifndef TEST_OUT_FMT_BLOCK_H_
#define TEST_OUT_FMT_BLOCK_H_

#include "../../System.h"
#include "../../Pointer.h"
#include "../../sys/mem/Dummy.h"
#include "Flag.h"
#include "Argument.h"
#include "Definition.h"
#include "out/Block.h"

#include <type_traits>
#include <utility>
#include <cstdlib>
#include <cstring>

namespace test
{
namespace out
{
namespace fmt
{

class Block;

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_BLOCK_DLEVEL

#define TEST_OUT_FMT_BLOCK_DLEVEL 2

#endif //!TEST_OUT_FMT_BLOCK_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_BLOCK_DLEVEL, 
    "test::out::fmt::Block", test::out::fmt::Block);


namespace test
{
namespace out
{
namespace fmt
{

class Block
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::out::fmt::Block> DebugType;
public:
    typedef test::out::fmt::Definition DefinitionType;
    typedef typename DefinitionType::FlagType FlagType;
    typedef test::Pointer<char> RawType;
    typedef typename DefinitionType::FormatOutputType OutputBlockType;
public:
    typedef void (*DestructorFuncType)(Block*, RawType);
public:
    typedef decltype(test::out::fmt::flag::Width{}.GetValue()) 
        WidthIntegerType;
    typedef decltype(test::out::fmt::flag::Length{}.GetValue()) 
        LengthIntegerType;
    typedef decltype(test::out::fmt::flag::Precision{}.GetValue()) 
        PrecisionIntegerType;
        
    static_assert(sizeof(LengthIntegerType) == 
        sizeof(PrecisionIntegerType), 
        "Length and precision type is not same size");
public:
    template<typename T>
    using ArgumentType = test::out::fmt::Argument<T, FlagType>;
private:
    static constexpr std::false_type HasGetValue_(...);
    template<typename T>
    static constexpr auto HasGetValue_(ArgumentType<T>&& arg) -> 
        decltype(arg.GetValue(), std::true_type());
public:
    template<typename TArg>
    using HasGetValue = decltype(HasGetValue_(TArg{}));
public:
    template<typename TChar>
    using FormatOutputFuncType = typename DefinitionType::
        FormatOutputFuncType<TChar>;
private:
    static constexpr inline std::size_t WidthAllocSize(FlagType flag);
private:
    static constexpr inline std::size_t 
        LengthPrecisionAllocSize(FlagType flag);
private:
    static constexpr inline std::size_t OutputAllocSize(FlagType flag);
private:
    static constexpr inline std::size_t WidthOffset(FlagType flag);
private:
    static constexpr inline std::size_t LengthPrecisionOffset(FlagType flag);
private:
    static constexpr inline std::size_t OutputOffset(FlagType flag);
private:
    static constexpr inline std::size_t ValueOffset(FlagType flag);
public:
    template<typename TArg, typename TCond_ = HasGetValue<ArgumentType<TArg>>,
        typename std::enable_if<TCond_::value, int>::type = 0>
    static inline std::size_t 
        ValueAllocationSize(const ArgumentType<TArg>& arg);
    static inline std::size_t 
        ValueAllocationSize(const ArgumentType<void>& arg);
public:
    template<typename TArg>
    static inline std::size_t 
        DataAllocationSize(const ArgumentType<TArg>& arg);
public:
    template<typename TValue>
    static inline void Destructor(Block* t, RawType raw);
private:
    FlagType m_flag;
    std::size_t m_off;
    std::size_t m_alloc;
    DestructorFuncType m_destructor;
public:
    inline Block();
    inline Block(const FlagType& flag, const std::size_t& off,
        const std::size_t& size);
public:
    inline ~Block();
public:
    inline Block(const Block& cpy);
    inline Block(Block&& mov);
public:
    inline Block& operator=(const Block& cpy);
    inline Block& operator=(Block&& mov);
public:
    inline FlagType Flag() const;
public:
    inline std::size_t AllocationSize() const;
public:
    inline std::size_t Offset() const;
public:
    inline void Initialize(RawType raw);
    template<typename TArg, typename TCond_ = HasGetValue<ArgumentType<TArg>>,
        typename std::enable_if<TCond_::value, int>::type = 0>
    inline void Initialize(RawType raw, const ArgumentType<TArg>& arg);
    inline void Initialize(RawType raw, const ArgumentType<void>& arg);
public:
    template<typename T>
    inline void SetValue(RawType raw, const T& val) const;
public:
    template<typename T, typename T_ = typename std::remove_cv<
            typename std::remove_reference<T>::type>::type,
        typename std::enable_if<std::is_void<T_>::value, int>::type = 0>
    inline void* GetValue(RawType raw) const;
    template<typename T, typename T_ = typename std::remove_cv<
            typename std::remove_reference<T>::type>::type,
        typename std::enable_if<!std::is_void<T_>::value, int>::type = 1>
    inline T& GetValue(RawType raw) const;
public:
    inline std::size_t GetValueSize() const;
public:
    inline void SetWidth(RawType raw, const WidthIntegerType& val);
    inline WidthIntegerType GetWidth(RawType raw) const;
public:
    inline void SetLength(RawType raw, const LengthIntegerType& val);
    inline LengthIntegerType GetLength(RawType raw) const;
public:
    inline void SetPrecision(RawType raw, const PrecisionIntegerType& val);
    inline PrecisionIntegerType GetPrecision(RawType raw) const;
public:
    template<typename TChar>
    inline FormatOutputFuncType<TChar> GetFormatOutput(RawType raw) const;
public:
    inline void Destroy(RawType raw) const;
};

constexpr inline std::size_t Block::WidthAllocSize(FlagType flag)
{
    return flag.IsSpecifierSubWidth() ? sizeof(WidthIntegerType) : 0;
}

constexpr inline std::size_t Block::LengthPrecisionAllocSize(FlagType flag)
{
    return (flag.IsSpecifierSubLength() || flag.IsSpecifierSubPrecision()) ?
        sizeof(LengthIntegerType) : 0;
}

constexpr inline std::size_t Block::OutputAllocSize(FlagType flag)
{
    return flag.IsSpecifierUndefined() ? std::size_t(0) : sizeof(OutputBlockType);
}

constexpr inline std::size_t Block::WidthOffset(FlagType flag)
{
    return 0;
}

constexpr inline std::size_t Block::LengthPrecisionOffset(FlagType flag)
{
    return WidthAllocSize(flag);
}

constexpr inline std::size_t Block::OutputOffset(FlagType flag)
{
    return WidthAllocSize(flag) + LengthPrecisionAllocSize(flag);
}

constexpr inline std::size_t Block::ValueOffset(FlagType flag)
{
    return WidthAllocSize(flag) + LengthPrecisionAllocSize(flag) +
        OutputAllocSize(flag);
}

template<typename TArg, typename TCond_,
    typename std::enable_if<TCond_::value, int>::type>
inline std::size_t Block::ValueAllocationSize(const ArgumentType<TArg>& arg)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "ValueAllocationSize<%s>(arg=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TArg), &arg);
    
    typedef typename std::remove_cv<typename std::remove_reference<
        decltype(arg.GetValue())>::type>::type ValueType;

    return sizeof(ValueType);
}

inline std::size_t Block::ValueAllocationSize(const ArgumentType<void>& arg)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "DataAllocationSize(arg=%p)", &arg);
    
    return 0;
}

template<typename TArg>
inline std::size_t Block::DataAllocationSize(const ArgumentType<TArg>& arg)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "DataAllocationSize<%s>(arg=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TArg), &arg);

    const FlagType flag = arg.GetFlag();

    return ValueAllocationSize(arg) + WidthAllocSize(flag) +
        LengthPrecisionAllocSize(flag) + OutputAllocSize(flag);
}

template<typename TValue>
inline void Block::Destructor(Block* t, RawType raw)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL,
        "Destructor(raw=%p)", raw.GetData());

    RawType curr = raw + (t->m_off + ValueOffset(t->m_flag));

    (*(curr.ReinterpretCast<TValue>())).~TValue();
}

inline Block::Block() :
    m_flag(),
    m_off(0),
    m_alloc(0),
    m_destructor(nullptr)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

inline Block::Block(const FlagType& flag, const std::size_t& off, 
    const std::size_t& size) :
        m_flag{flag},
        m_off(off),
        m_alloc(size),
        m_destructor(nullptr)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(flag=%x, off=%zu, alloc=%zu)", 
        flag.GetValue(), off, size);

}

inline Block::~Block()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

    m_flag = FlagType();
    m_off = 0;
    m_alloc = 0;
    m_destructor = nullptr;
}

inline Block::Block(const Block& cpy) :
    m_flag(cpy.m_flag),
    m_off(cpy.m_off),
    m_alloc(cpy.m_alloc),
    m_destructor(cpy.m_destructor)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);
}

inline Block::Block(Block&& mov) :
    m_flag(std::move(mov.m_flag)),
    m_off(mov.m_off),
    m_alloc(mov.m_alloc),
    m_destructor(mov.m_destructor)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

    mov.m_off = 0;
    mov.m_alloc = 0;
    mov.m_destructor = nullptr;
}

inline Block& Block::operator=(const Block& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);

    m_flag = cpy.m_flag;
    m_off = cpy.m_off;
    m_alloc = cpy.m_alloc;
    m_destructor = cpy.m_destructor;
    return *this;
}

inline Block& Block::operator=(Block&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);

    m_flag = std::move(mov.m_flag);
    m_off = mov.m_off;
    m_alloc = mov.m_alloc;
    m_destructor = mov.m_destructor;
    mov.m_off = 0;
    mov.m_alloc = 0;
    mov.m_destructor = nullptr;

    return *this;
}

inline typename Block::FlagType Block::Flag() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Flag() const");

    return m_flag;
}

inline std::size_t Block::AllocationSize() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "AllocationSize() const");

    return m_alloc + ValueOffset(m_flag);
}

inline std::size_t Block::Offset() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Offset() const");

    return m_off;
}

inline void Block::Initialize(RawType raw)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Initialize(raw=%p)", raw.GetData());

    RawType curr = raw + m_off;
    const std::size_t end = m_off + m_alloc;
    const auto size = raw.Size();
    if (end == 0)
    {
        return;
    }
    else if (end > size)
    {
        memset(&*curr, 0, size - m_off);
    }
    else
    {
        memset(&*curr, 0, m_alloc);
    }

    m_destructor = nullptr;
}

template<typename TArg, typename TCond_,
    typename std::enable_if<TCond_::value, int>::type>
inline void Block::Initialize(RawType raw, const ArgumentType<TArg>& arg)
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Initialize<%s>(raw=%p, arg=%p)", TEST_SYS_DEBUG_T_NAME_STR(TArg), 
        raw.GetData(), &arg);
    
    if (m_alloc == 0 || raw.Size() == 0) return;

    typedef typename std::remove_cv<typename std::remove_reference<
        decltype(arg.GetValue())>::type>::type ValueType;
    
    RawType curr = raw + m_off;
    const auto width_alloc_size = WidthAllocSize(m_flag);
    const auto length_precision_alloc_size = LengthPrecisionAllocSize(m_flag);
    const auto output_alloc_size = OutputAllocSize(m_flag);

    if (width_alloc_size > 0)
    {
        *(curr.ReinterpretCast<WidthIntegerType>()) = arg.GetWidth();

        curr += width_alloc_size;
    }

    if (length_precision_alloc_size > 0)
    {
        *(curr.ReinterpretCast<LengthIntegerType>()) = arg.GetLength();

        curr += length_precision_alloc_size;
    }

    if (output_alloc_size > 0)
    {
        new (&*(curr.ReinterpretCast<OutputBlockType>()))
            OutputBlockType(arg.GetFormatOutput());
        curr += output_alloc_size;
    }
    
    if (m_alloc > 0)
    {
        memset(&*curr, 0, sizeof(ValueType));
        if (m_flag.HasInputValue())
        {
            new (&*curr)ValueType(arg.GetValue());
        }
        else
        {
            new (&*curr)ValueType();
        }
        m_destructor = &Destructor<ValueType>;
    }
}

inline void Block::Initialize(RawType raw, const ArgumentType<void>& arg)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Initialize(raw=%p, arg=%p)", raw.GetData(), &arg);
    
    if (raw.Size() == 0) return;
    
    RawType curr = raw + m_off;
    const auto width_alloc_size = WidthAllocSize(m_flag);
    const auto length_precision_alloc_size = LengthPrecisionAllocSize(m_flag);
    const auto output_alloc_size = OutputAllocSize(m_flag);

    if (width_alloc_size > 0)
    {
        *(curr.ReinterpretCast<WidthIntegerType>()) = arg.GetWidth();

        curr += width_alloc_size;
    }

    if (length_precision_alloc_size > 0)
    {
        *(curr.ReinterpretCast<LengthIntegerType>()) = arg.GetLength();

        curr += length_precision_alloc_size;
    }

    if (output_alloc_size > 0)
    {
        new (&*(curr.ReinterpretCast<OutputBlockType>()))
            OutputBlockType(arg.GetFormatOutput());
        curr += output_alloc_size;
    }
    
    m_destructor = nullptr;
}

template<typename T>
inline void Block::SetValue(RawType raw, const T& val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "SetValue<%s>(raw=%p, val=%s)", TEST_SYS_DEBUG_T_NAME_STR(T), 
        raw.GetData(), TEST_SYS_DEBUG_TARGS_VALUE_STR(val));

    const auto raw_size = raw.Size() - raw.Offset();
    const auto size = m_off + ValueOffset(m_flag) + m_alloc;
    
    if (m_alloc == 0 || raw_size < size)
    {
        return;
    }
    
    RawType curr = raw + (m_off + ValueOffset(m_flag));
    
    *(curr.ReinterpretCast<T>()) = val;
}

template<typename T, typename T_,
    typename std::enable_if<std::is_void<T_>::value, int>::type>
inline void* Block::GetValue(RawType raw) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "GetValue<%s>(raw=%p)", TEST_SYS_DEBUG_T_NAME_STR(T), 
        raw.GetData());
    
    const auto raw_size = raw.Size() - raw.Offset();
    const auto size = m_off + ValueOffset(m_flag) + m_alloc;

    if (m_alloc == 0 || raw_size < size)
    {
        return (void*)test::sys::mem::Dummy::Get<char>();
    }

    RawType curr = raw + (m_off + ValueOffset(m_flag));
    
    return (void*)&*(curr.ReinterpretCast<char>());
}

template<typename T, typename T_,
    typename std::enable_if<!std::is_void<T_>::value, int>::type>
inline T& Block::GetValue(RawType raw) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "GetValue<%s>(raw=%p)", TEST_SYS_DEBUG_T_NAME_STR(T), 
        raw.GetData());
    
    const auto raw_size = raw.Size() - raw.Offset();
    const auto size = m_off + ValueOffset(m_flag) + m_alloc;

    if (m_alloc == 0 || raw_size < size)
    {
        return *test::sys::mem::Dummy::Get<T>();
    }

    RawType curr = raw + (m_off + ValueOffset(m_flag));
    
    return *(curr.ReinterpretCast<T>());
}

inline std::size_t Block::GetValueSize() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "GetValueSize() const");

    return m_alloc;
}

inline void Block::SetWidth(RawType raw, const WidthIntegerType& val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "SetWidth(raw=%p, val=%p)", raw.GetData(), 
        TEST_SYS_DEBUG_TARGS_VALUE_STR(val));

    const auto raw_size = raw.Size() - raw.Offset();
    const auto size = m_off + WidthOffset(m_flag) + WidthAllocSize(m_flag);

    if (WidthAllocSize(m_flag) == 0 || raw_size < size)
    {
        return;
    }
    
    RawType curr = raw + (m_off + WidthOffset(m_flag));

    *(curr.ReinterpretCast<WidthIntegerType>()) = val;
}

inline typename Block::WidthIntegerType 
Block::GetWidth(RawType raw) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "GetWidth(raw=%p)", raw.GetData());
    
    const auto raw_size = raw.Size() - raw.Offset();
    const auto size = m_off + WidthOffset(m_flag) + WidthAllocSize(m_flag);

    if (WidthAllocSize(m_flag) == 0 || raw_size < size)
    {
        return (WidthIntegerType)0;
    }
    
    RawType curr = raw + (m_off + WidthOffset(m_flag));
    
    return *(curr.ReinterpretCast<WidthIntegerType>());
}

inline void Block::SetLength(RawType raw, const LengthIntegerType& val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "SetLength(raw=%p, val=%p)", raw.GetData(), 
        TEST_SYS_DEBUG_TARGS_VALUE_STR(val));
    
    const auto raw_size = raw.Size() - raw.Offset();
    const auto size = m_off + LengthPrecisionOffset(m_flag) + 
        LengthPrecisionAllocSize(m_flag);

    if (LengthPrecisionAllocSize(m_flag) == 0 || raw_size < size)
    {
        return;
    }

    RawType curr = raw + (m_off + LengthPrecisionOffset(m_flag));

    *(curr.ReinterpretCast<LengthIntegerType>()) = val;
}

inline typename Block::LengthIntegerType 
Block::GetLength(RawType raw) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "GetLength(raw=%p)", raw.GetData());
    
    const auto raw_size = raw.Size() - raw.Offset();
    const auto size = m_off + LengthPrecisionOffset(m_flag) + 
        LengthPrecisionAllocSize(m_flag);

    if (LengthPrecisionAllocSize(m_flag) == 0 || raw_size < size)
    {
        return (LengthIntegerType)0;
    }

    RawType curr = raw + (m_off + LengthPrecisionOffset(m_flag));
    
    return *(curr.ReinterpretCast<LengthIntegerType>());
}

inline void Block::SetPrecision(RawType raw, const PrecisionIntegerType& val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "SetPrecision(raw=%p, val=%p)", raw.GetData(), 
        TEST_SYS_DEBUG_TARGS_VALUE_STR(val));
    
    const auto raw_size = raw.Size() - raw.Offset();
    const auto size = m_off + LengthPrecisionOffset(m_flag) + 
        LengthPrecisionAllocSize(m_flag);

    if (LengthPrecisionAllocSize(m_flag) == 0 || raw_size < size)
    {
        return;
    }

    RawType curr = raw + (m_off + LengthPrecisionOffset(m_flag));

    *(curr.ReinterpretCast<PrecisionIntegerType>()) = val;

}

inline typename Block::PrecisionIntegerType 
Block::Block::GetPrecision(RawType raw) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "GetLength(raw=%p)", raw.GetData());
    
    const auto raw_size = raw.Size() - raw.Offset();
    const auto size = m_off + LengthPrecisionOffset(m_flag) + 
        LengthPrecisionAllocSize(m_flag);

    if (LengthPrecisionAllocSize(m_flag) == 0 || raw_size < size)
    {
        return (PrecisionIntegerType)0;
    }

    RawType curr = raw + (m_off + LengthPrecisionOffset(m_flag));
    
    return *(curr.ReinterpretCast<PrecisionIntegerType>());
}

template<typename TChar>
inline typename Block::FormatOutputFuncType<TChar> 
Block::GetFormatOutput(RawType raw) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "GetFormatOutput<%s>(raw=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TChar), raw.GetData());
    
    const auto raw_size = raw.Size() - raw.Offset();
    const auto size = m_off + OutputOffset(m_flag) + 
        OutputAllocSize(m_flag);

    if (OutputAllocSize(m_flag) == 0 || raw_size < size)
    {
        return nullptr;
    }

    RawType curr = raw + (m_off + OutputOffset(m_flag));

    return (*(curr.ReinterpretCast<OutputBlockType>())).template Get<TChar>();
}

inline void Block::Destroy(RawType raw) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this,
        "Destroy(raw=%p)", raw.GetData());
    
    if (m_destructor == nullptr)
    {
        return;
    }

    m_destructor(const_cast<Block*>(this), raw);
}

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_BLOCK_H_
