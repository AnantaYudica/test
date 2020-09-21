#ifndef TEST_OUT_PRINT_SPECIFIER_CHARACTER_H_
#define TEST_OUT_PRINT_SPECIFIER_CHARACTER_H_

#include "../../Standard.h"
#include "../../fmt/Flag.h"
#include "../Character.h"

#include <cstddef>
#include <cwchar>

namespace test
{
namespace out
{
namespace print
{
namespace specifier
{

template<typename TChar, 
    typename test::out::fmt::FlagType::IntegerValueType IFmt>
struct Character
{};

template<>
struct Character<char, test::out::print::Character::char_fmt>
{
    static std::size_t Output(test::out::Standard<char>& out, 
        int * width, void * value)
    {
        return out.Print("%c", *((char *)value));
    }
};

template<>
struct Character<wchar_t, test::out::print::Character::char_fmt>
{
    static std::size_t Output(test::out::Standard<wchar_t>& out, 
        int * width, void * value)
    {
        return out.Print(L"%c", *((char *)value));
    }
};

template<>
struct Character<char, test::out::print::Character::w_char_fmt>
{
    static std::size_t Output(test::out::Standard<char>& out, 
        int * width, void * value)
    {
        return out.Print("%*c", *width, *((char *)value));
    }
};

template<>
struct Character<wchar_t, test::out::print::Character::w_char_fmt>
{
    static std::size_t Output(test::out::Standard<wchar_t>& out, 
        int * width, void * value)
    {
        return out.Print(L"%*c", *width, *((char *)value));
    }
};

template<>
struct Character<char, test::out::print::Character::wchar_fmt>
{
    static std::size_t Output(test::out::Standard<char>& out, 
        int * width, void * value)
    {
        return out.Print("%lc", *((wchar_t *)value));
    }
};

template<>
struct Character<wchar_t, test::out::print::Character::wchar_fmt>
{
    static std::size_t Output(test::out::Standard<wchar_t>& out, 
        int * width, void * value)
    {
        return out.Print(L"%lc", *((wchar_t *)value));
    }
};

template<>
struct Character<char, test::out::print::Character::w_wchar_fmt>
{
    static std::size_t Output(test::out::Standard<char>& out, 
        int * width, void * value)
    {
        return out.Print("%*lc", *width, *((wchar_t *)value));
    }
};

template<>
struct Character<wchar_t, test::out::print::Character::w_wchar_fmt>
{
    static std::size_t Output(test::out::Standard<wchar_t>& out, 
        int * width, void * value)
    {
        return out.Print(L"%*lc", *width, *((wchar_t *)value));
    }
};

} //!specifier

} //!print

} //!out

} //!test

#endif //!TEST_OUT_PRINT_SPECIFIER_CHARACTER_H_
