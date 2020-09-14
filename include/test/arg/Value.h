#ifndef TEST_ARG_VALUE_H_
#define TEST_ARG_VALUE_H_

#include "../Pointer.h"

#include <cstddef>
#include <cstdint>

namespace test
{
namespace arg
{

class Value
{
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
{}

inline Value::Value(const std::size_t& alloc_size) :
    m_values(test::ptr::arg::Array(alloc_size + 1), 
        test::ptr::arg::Foreach{}, 0)
{}

inline Value::~Value()
{}

inline Value::Value(const Value& cpy) :
    m_values(cpy.m_values)
{}

inline Value::Value(Value&& mov) :
    m_values(mov.m_values)
{}

inline Value& Value::operator=(const Value& cpy)
{
    m_values = cpy.m_values;
    return *this;
}

inline Value& Value::operator=(Value&& mov)
{
    m_values = mov.m_values;
    return *this;
}

template<typename T>
inline void Value::Set(const std::size_t& off, const T& val)
{
    m_values.SetIndex(off);
    auto cast = m_values.template ReinterpretCast<T>();
    *cast = val;
}

template<typename T>
inline T* Value::Get(const std::size_t& off)
{
    m_values.SetIndex(off);
    auto cast = m_values.template ReinterpretCast<T>();
    return &*cast;
}

inline std::size_t Value::AllocationSize() const
{
    return m_values.AllocationSize() - 1;
}

inline bool Value::operator==(const Value& other) const
{
    return m_values == other.m_values.GetData();
}

inline bool Value::operator!=(const Value& other) const
{
    return m_values != other.m_values.GetData();
}

} //!arg

} //!test

#endif //!TEST_ARG_VALUE_H_
