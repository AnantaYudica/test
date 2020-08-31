#ifndef TEST_FORWARD_H_
#define TEST_FORWARD_H_

#include <type_traits>

namespace test
{

template<typename T>
struct Forward
{
    typedef T Type;
    static T&& Value(typename std::remove_reference<T>::type & val);
    static T&& Value(typename std::remove_reference<T>::type && val);
};

template<typename T>
T&& Forward<T>::Value(typename std::remove_reference<T>::type & val)
{
    return static_cast<T&&>(val);
}

template<typename T>
T&& Forward<T>::Value(typename std::remove_reference<T>::type && val)
{
    return static_cast<T&&>(val);
}

} //!test

#endif //!TEST_FORWARD_H_
