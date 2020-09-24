#ifndef TEST_TYPE_PARAM_NAME_H_
#define TEST_TYPE_PARAM_NAME_H_

#include "../Parameter.h"
#include "../Name.h"
#include "../../CString.h"
#include "../../cstr/Format.h"

#include <cstddef>
#include <utility>
#include <type_traits>

namespace test
{
namespace type
{
namespace param
{

template<typename T>
class Name
{};

template<typename... TArgs>
class Name<type::Parameter<TArgs...>>
{
protected:
    static char* Forward(std::size_t& size);
public:
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<char> CStr();
    template<typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr();
};

template<typename TArg, typename... TArgs>
class Name<type::Parameter<TArg, TArgs...>> : 
    public Name<type::Parameter<TArgs...>>
{
protected:
    static char* Forward(std::size_t& size);
public:
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<char> CStr();
    template<typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr();
};

template<typename... TArgs>
char* Name<type::Parameter<TArgs...>>::Forward(std::size_t& size)
{
    char * cstr = new char[size + 1];
    cstr[size] = '\0';
    size += 1;
    return cstr;
}

template<typename... TArgs>
template<typename TChar, typename std::enable_if<
    std::is_same<TChar, char>::value, int>::type>
test::CString<char> Name<type::Parameter<TArgs...>>::CStr()
{
    std::size_t size = 0;
    return {std::move(Forward(size)), size};
}

template<typename... TArgs>
template<typename TChar, typename std::enable_if<
    !std::is_same<TChar, char>::value &&
    std::is_same<TChar, wchar_t>::value, int>::type>
test::CString<wchar_t> Name<type::Parameter<TArgs...>>::CStr()
{
    const auto cstr = CStr<char>();
    return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
}

template<typename TArg, typename... TArgs>
char* Name<type::Parameter<TArg, TArgs...>>::Forward(std::size_t& size)
{
    char * cstr;
    std::size_t begin = size;
    test::CString<char> arg_cstr = std::move(type::Name<TArg>::
        template CStr<char>());
    size += arg_cstr.Size();
    if (arg_cstr.Size() != 0)
    {
        size += 2;
        cstr = Name<type::Parameter<TArgs...>>::Forward(size);
        memcpy(cstr + (begin + 2), *arg_cstr, arg_cstr.Size() * sizeof(TChar));
        cstr[begin] = ',';
        cstr[begin + 1] = ' ';
    }
    else
    {
        cstr = Name<type::Parameter<TArgs...>>::Forward(size);
    }
    return cstr;
}

template<typename TArg, typename... TArgs>
template<typename TChar, typename std::enable_if<
    std::is_same<TChar, char>::value, int>::type>
test::CString<char> Name<type::Parameter<TArg, TArgs...>>::CStr()
{
    std::size_t size = 0;
    char * cstr;
    test::CString<char> arg_cstr = std::move(type::Name<TArg>::
        template CStr<char>());
    size += arg_cstr.Size();
    cstr = Name<type::Parameter<TArgs...>>::Forward(size);
    if (arg_cstr.Size() != 0)
    {
        memcpy(cstr, *arg_cstr, arg_cstr.Size() * sizeof(TChar));
    }
    return {std::move(cstr), size};
}

template<typename TArg, typename... TArgs>
template<typename TChar, typename std::enable_if<
    !std::is_same<TChar, char>::value &&
    std::is_same<TChar, wchar_t>::value, int>::type>
test::CString<wchar_t> Name<type::Parameter<TArg, TArgs...>>::CStr()
{
    const auto cstr = CStr<char>();
    return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
}

} //!param

} //!type

} //!test

#endif //!TEST_TYPE_PARAM_NAME_H_
