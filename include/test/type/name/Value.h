#ifndef TEST_TYPE_NAME_VALUE_H_
#define TEST_TYPE_NAME_VALUE_H_

#include "../../CString.h"
#include "../../cstr/Format.h"
#include "../Name.h"
#include "val/Get.h"

namespace test
{
namespace type
{
namespace name
{

template<typename T, T V>
struct Value
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _ptr = test::cstr::Format(
            (test::type::Name<T>::template CStr<TChar>().Size() + 4 + 
                test::type::name::val::Get<T>::template CStr<V, TChar>().Size()),
            "(%s) %s", *(test::type::Name<T>::template CStr<TChar>()), 
                *(test::type::name::val::Get<T>::template CStr<V, TChar>()));
        return {_ptr};
    }
};

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_VALUE_H_
