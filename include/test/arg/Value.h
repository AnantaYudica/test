#ifndef TEST_ARG_VALUE_H_
#define TEST_ARG_VALUE_H_

#include "../System.h"
#include "../Pointer.h"

#include <cstddef>
#include <cstdint>

namespace test::arg
{
class Value;
}

#ifndef TEST_ARG_VALUE_DLEVEL

#define TEST_ARG_VALUE_DLEVEL 2

#endif //!TEST_ARG_VALUE_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_ARG_VALUE_DLEVEL, 
    "test::arg::Value", test::arg::Value);

namespace test
{
namespace arg
{

class Value
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::arg::Value> DebugType;
private:
    test::Pointer<std::uint8_t> m_values;
public:
    inline Value();
    inline Value(const std::size_t& alloc_size);
public:
    inline ~Value();
public:
    inline Value(const Value& cpy);
    inline Value(Value&& mov);
public:
    inline Value& operator=(const Value& cpy);
    inline Value& operator=(Value&& mov);
public:
    template<typename T>
    inline void Set(const std::size_t& off, const T& val);
public:
    template<typename T>
    inline T* Get(const std::size_t& off);
public:
    inline std::size_t AllocationSize() const;
public:
    inline bool operator==(const Value& other) const;
    inline bool operator!=(const Value& other) const;
};

inline Value::Value() :
    m_values()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

inline Value::Value(const std::size_t& alloc_size) :
    m_values(test::ptr::arg::Array(alloc_size + 1), 
        test::ptr::arg::Foreach{}, 0)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this,
        "Constructor(alloc_size=%zu)", alloc_size);

}

inline Value::~Value()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

}

inline Value::Value(const Value& cpy) :
    m_values(cpy.m_values)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);

}

inline Value::Value(Value&& mov) :
    m_values(mov.m_values)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

}

inline Value& Value::operator=(const Value& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);

    m_values = cpy.m_values;
    return *this;
}

inline Value& Value::operator=(Value&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);

    m_values = mov.m_values;
    return *this;
}

template<typename T>
inline void Value::Set(const std::size_t& off, const T& val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Set<%s>(off=%zu, val=%s)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(T), off,
        TEST_SYS_DEBUG_TARGS_VALUE_STR(val));

    m_values.SetIndex(off);
    auto cast = m_values.template ReinterpretCast<T>();
    *cast = val;
}

template<typename T>
inline T* Value::Get(const std::size_t& off)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "Set<%s>(off=%zu)", TEST_SYS_DEBUG_TARGS_NAME_STR(T), off);

    m_values.SetIndex(off);
    auto cast = m_values.template ReinterpretCast<T>();
    return &*cast;
}

inline std::size_t Value::AllocationSize() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "AllocationSize() const");

    return m_values.AllocationSize() - 1;
}

inline bool Value::operator==(const Value& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", &other);

    return m_values == other.m_values.GetData();
}

inline bool Value::operator!=(const Value& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", &other);

    return m_values != other.m_values.GetData();
}

} //!arg

} //!test

#endif //!TEST_ARG_VALUE_H_
