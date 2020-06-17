#ifndef TEST_TYPE_VALUE_H_
#define TEST_TYPE_VALUE_H_

namespace test
{
namespace type
{

template<typename T, T ValueT>
class Value
{
public:
    typedef T Type;
    typedef Type ConstGetType;
public:
    constexpr Value();
public:
    constexpr ConstGetType Get() const;
};

template<typename T, T ValueT>
constexpr Value<T, ValueT>::Value()
{}

template<typename T, T ValueT>
constexpr typename Value<T, ValueT>::ConstGetType 
    Value<T, ValueT>::Get() const
{
    return ValueT;
}

} //!type

} //!test

#endif //!TEST_TYPE_VALUE_H_

