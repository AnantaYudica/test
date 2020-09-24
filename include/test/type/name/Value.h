#ifndef TEST_TYPE_NAME_VALUE_H_
#define TEST_TYPE_NAME_VALUE_H_

#include "../../CString.h"
#include "../../cstr/Format.h"
#include "../Name.h"
#include "val/Get.h"

#include <type_traits>
#include <cwchar>

namespace test
{
namespace type
{
namespace name
{

template<typename T, T V>
struct Value
{
    template<typename TChar = char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _ptr = test::cstr::Format<char>(
            (test::type::Name<T>::template CStr<char>().Size() + 4 + 
                test::type::name::val::Get<T>::template CStr<V, char>().Size()),
            "(%s) %s", *(test::type::Name<T>::template CStr<char>()), 
                *(test::type::name::val::Get<T>::template CStr<V, char>()));
        return {_ptr};
    }
    template<typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_VALUE_H_
