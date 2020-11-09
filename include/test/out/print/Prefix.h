#ifndef TEST_OUT_PRINT_PREFIX_H_
#define TEST_OUT_PRINT_PREFIX_H_

#include "../fmt/Flag.h"
#include "../../CString.h"
#include "../../cstr/Format.h"
#include "../../def/cstr/val/num/Prefix.h"
#include "../../def/cstr/val/num/Minus.h"
#include "../../def/cstr/val/num/Plus.h"
#include "../../def/cstr/val/Empty.h"
#include "../../def/cstr/val/Space.h"

#include <cwchar>
#include <cstddef>
#include <type_traits>

namespace test
{
namespace out
{
namespace print
{

struct Prefix
{
    typedef test::out::fmt::FlagType FlagType;
    typedef typename FlagType::IntegerValueType IntegerValueType;

    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value, 
        int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, ...)
    {
        return val_cstr;
    }

    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierIntegerUnsigned() &&
            FlagType{IFormat}.IsSpecifierBaseOctal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 8>();
        const auto size_cstr = num_cstr.Size() + val_cstr.Size();
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s", 
            *num_cstr, *val_cstr);
    }

    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierIntegerUnsigned() &&
            FlagType{IFormat}.IsSpecifierBaseOctal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 8>();
        const auto size_cstr = num_cstr.Size() + val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%s%0*u%s", 
                *num_cstr, (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, 
            "%s%s", *num_cstr, *val_cstr);
    }

    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierIntegerUnsigned() &&
            FlagType{IFormat}.IsSpecifierBaseDecimal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 10>();
        const auto size_cstr = num_cstr.Size() + val_cstr.Size();
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s", 
            *num_cstr, *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierIntegerUnsigned() &&
            FlagType{IFormat}.IsSpecifierBaseDecimal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 10>();
        const auto size_cstr = num_cstr.Size() + val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%s%0*u%s", *num_cstr, 
                (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, 
            "%s%s", *num_cstr, *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            (FlagType{IFormat}.IsSpecifierIntegerSigned() ||
            FlagType{IFormat}.IsSpecifierFloatingPoint()) &&
            FlagType{IFormat}.IsSpecifierBaseDecimal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::Empty::CStr<TChar>();
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 10>();
        const auto size_cstr = sign_cstr.Size() + num_cstr.Size() + 
            val_cstr.Size();
        
        return test::cstr::Format<TChar>(size_cstr + 1, 
            "%s%s%s", *sign_cstr, *num_cstr, *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            (FlagType{IFormat}.IsSpecifierIntegerSigned() ||
            FlagType{IFormat}.IsSpecifierFloatingPoint()) &&
            FlagType{IFormat}.IsSpecifierBaseDecimal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::Empty::CStr<TChar>();
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 10>();
        const auto size_cstr = sign_cstr.Size() + num_cstr.Size() + 
            val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%s%s%0*u%s", 
                *sign_cstr, *num_cstr, (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s%s", *sign_cstr, 
            *num_cstr, *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            (FlagType{IFormat}.IsSpecifierIntegerSigned() ||
            FlagType{IFormat}.IsSpecifierFloatingPoint()) &&
            FlagType{IFormat}.IsSpecifierBaseDecimal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::num::Plus::CStr<TChar>();
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 10>();
        const auto size_cstr = sign_cstr.Size() + num_cstr.Size() + 
            val_cstr.Size();
        
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s%s", *sign_cstr, 
            *num_cstr, *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            (FlagType{IFormat}.IsSpecifierIntegerSigned() ||
            FlagType{IFormat}.IsSpecifierFloatingPoint()) &&
            FlagType{IFormat}.IsSpecifierBaseDecimal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::num::Plus::CStr<TChar>();
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 10>();
        const auto size_cstr = sign_cstr.Size() + num_cstr.Size() + 
            val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%s%s%0*u%s", 
                *sign_cstr, *num_cstr, (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s%s", *sign_cstr, 
            *num_cstr, *val_cstr);
    }

    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            (FlagType{IFormat}.IsSpecifierIntegerSigned() ||
            FlagType{IFormat}.IsSpecifierFloatingPoint()) &&
            FlagType{IFormat}.IsSpecifierBaseDecimal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::Space::CStr<TChar>();
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 10>();
        const auto size_cstr = sign_cstr.Size() + num_cstr.Size() + 
            val_cstr.Size();
        
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s%s", *sign_cstr, 
            *num_cstr, *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            (FlagType{IFormat}.IsSpecifierIntegerSigned() ||
            FlagType{IFormat}.IsSpecifierFloatingPoint()) &&
            FlagType{IFormat}.IsSpecifierBaseDecimal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::Space::CStr<TChar>();
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 10>();
        const auto size_cstr = sign_cstr.Size() + num_cstr.Size() + 
            val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%s%s%0*u%s", 
                *sign_cstr, *num_cstr, (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s%s", *sign_cstr, 
            *num_cstr, *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierIntegerUnsigned() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal() &&
            FlagType{IFormat}.IsSpecifierLowerCase(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 16, true>();
        const auto size_cstr = num_cstr.Size() + val_cstr.Size();
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s", 
            *num_cstr, *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierIntegerUnsigned() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal() &&
            FlagType{IFormat}.IsSpecifierUpperCase(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 16, false>();
        const auto size_cstr = num_cstr.Size() + val_cstr.Size();
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s", 
            *num_cstr, *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierIntegerUnsigned() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal() &&
            FlagType{IFormat}.IsSpecifierLowerCase(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 16, true>();
        const auto size_cstr = num_cstr.Size() + val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%s%0*u%s", 
                *num_cstr, (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s", 
            *num_cstr, *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierIntegerUnsigned() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal() &&
            FlagType{IFormat}.IsSpecifierUpperCase(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 16, false>();
        const auto size_cstr = num_cstr.Size() + val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%s%0*u%s", *num_cstr, 
                (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s", *num_cstr, 
            *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierFloatingPoint() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal() &&
            FlagType{IFormat}.IsSpecifierLowerCase(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::Empty::CStr<TChar>();
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 16, true>();
        const auto size_cstr = sign_cstr.Size() + num_cstr.Size() + 
            val_cstr.Size();
        
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s%s", *sign_cstr, 
            *num_cstr, *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierFloatingPoint() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal() &&
            FlagType{IFormat}.IsSpecifierUpperCase(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::Empty::CStr<TChar>();
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 16, false>();
        const auto size_cstr = sign_cstr.Size() + num_cstr.Size() + 
            val_cstr.Size();
        
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s%s", *sign_cstr, 
            *num_cstr, *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierFloatingPoint() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal() &&
            FlagType{IFormat}.IsSpecifierLowerCase(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::Empty::CStr<TChar>();
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 16, true>();
        const auto size_cstr = sign_cstr.Size() + num_cstr.Size() + 
            val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%s%s%0*u%s", 
                *sign_cstr, *num_cstr, (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s%s", *sign_cstr, 
            *num_cstr, *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierFloatingPoint() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal() &&
            FlagType{IFormat}.IsSpecifierUpperCase(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::Empty::CStr<TChar>();
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 16, false>();
        const auto size_cstr = sign_cstr.Size() + num_cstr.Size() + 
            val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%s%s%0*u%s", 
                *sign_cstr, *num_cstr, (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s%s", *sign_cstr, 
            *num_cstr, *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierFloatingPoint() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal() &&
            FlagType{IFormat}.IsSpecifierLowerCase(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::num::Plus::CStr<TChar>();
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 16, true>();
        const auto size_cstr = sign_cstr.Size() + num_cstr.Size() + 
            val_cstr.Size();
        
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s%s", *sign_cstr, 
            *num_cstr, *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierFloatingPoint() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal() &&
            FlagType{IFormat}.IsSpecifierUpperCase(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::num::Plus::CStr<TChar>();
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 16, false>();
        const auto size_cstr = sign_cstr.Size() + num_cstr.Size() + 
            val_cstr.Size();
        
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s%s", *sign_cstr, 
            *num_cstr, *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierFloatingPoint() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal() &&
            FlagType{IFormat}.IsSpecifierLowerCase(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::num::Plus::CStr<TChar>();
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 16, true>();
        const auto size_cstr = sign_cstr.Size() + num_cstr.Size() + 
            val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%s%s%0*u%s", 
                *sign_cstr, *num_cstr, (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s%s", *sign_cstr, 
            *num_cstr, *val_cstr);
    }

    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierFloatingPoint() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal() &&
            FlagType{IFormat}.IsSpecifierUpperCase(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::num::Plus::CStr<TChar>();
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 16, false>();
        const auto size_cstr = sign_cstr.Size() + num_cstr.Size() + 
            val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%s%s%0*u%s", 
                *sign_cstr, *num_cstr, (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s%s", *sign_cstr, 
            *num_cstr, *val_cstr);
    }

    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierFloatingPoint() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal() &&
            FlagType{IFormat}.IsSpecifierLowerCase(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::Space::CStr<TChar>();
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 16, true>();
        const auto size_cstr = sign_cstr.Size() + num_cstr.Size() + 
            val_cstr.Size();
        
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s%s", *sign_cstr, 
            *num_cstr, *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierFloatingPoint() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal() &&
            FlagType{IFormat}.IsSpecifierUpperCase(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::Space::CStr<TChar>();
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 16, false>();
        const auto size_cstr = sign_cstr.Size() + num_cstr.Size() + 
            val_cstr.Size();
        
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s%s", *sign_cstr, 
            *num_cstr, *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierFloatingPoint() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal() &&
            FlagType{IFormat}.IsSpecifierLowerCase(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::Space::CStr<TChar>();
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 16, true>();
        const auto size_cstr = sign_cstr.Size() + num_cstr.Size() + 
            val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%s%s%0*u%s", 
                *sign_cstr, *num_cstr, (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s%s", *sign_cstr, 
            *num_cstr, *val_cstr);
    }

    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierFloatingPoint() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal() &&
            FlagType{IFormat}.IsSpecifierUpperCase(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::Space::CStr<TChar>();
        const auto num_cstr = test::def::cstr::val::num::Prefix::
            CStr<TChar, 16, false>();
        const auto size_cstr = sign_cstr.Size() + num_cstr.Size() + 
            val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%s%s%0*u%s", 
                *sign_cstr, *num_cstr, (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s%s", *sign_cstr,
            *num_cstr, *val_cstr);
    }

    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            !FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierIntegerUnsigned() &&
            FlagType{IFormat}.IsSpecifierBaseOctal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto size_cstr = val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%0*u%s", 
                (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, "%s", *val_cstr);
    }

    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            !FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierIntegerUnsigned() &&
            FlagType{IFormat}.IsSpecifierBaseDecimal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto size_cstr = val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%0*u%s", 
                (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, "%s", *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            !FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            (FlagType{IFormat}.IsSpecifierIntegerSigned() ||
            FlagType{IFormat}.IsSpecifierFloatingPoint()) &&
            FlagType{IFormat}.IsSpecifierBaseDecimal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::Empty::CStr<TChar>();
        const auto size_cstr = sign_cstr.Size() + val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%s%0*u%s", *sign_cstr, 
                (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s", *sign_cstr, 
            *val_cstr);
    }
    
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            !FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            (FlagType{IFormat}.IsSpecifierIntegerSigned() ||
            FlagType{IFormat}.IsSpecifierFloatingPoint()) &&
            FlagType{IFormat}.IsSpecifierBaseDecimal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::num::Plus::CStr<TChar>();
        const auto size_cstr = sign_cstr.Size() + val_cstr.Size();
        
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s", *sign_cstr, 
            *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            !FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            (FlagType{IFormat}.IsSpecifierIntegerSigned() ||
            FlagType{IFormat}.IsSpecifierFloatingPoint()) &&
            FlagType{IFormat}.IsSpecifierBaseDecimal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::num::Plus::CStr<TChar>();
        const auto size_cstr = sign_cstr.Size() + val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%s%0*u%s", *sign_cstr, 
                (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s", *sign_cstr, 
            *val_cstr);
    }

    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            !FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            (FlagType{IFormat}.IsSpecifierIntegerSigned() ||
            FlagType{IFormat}.IsSpecifierFloatingPoint()) &&
            FlagType{IFormat}.IsSpecifierBaseDecimal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::Space::CStr<TChar>();
        const auto size_cstr = sign_cstr.Size() + val_cstr.Size();
        
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s", *sign_cstr, 
            *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            !FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            (FlagType{IFormat}.IsSpecifierIntegerSigned() ||
            FlagType{IFormat}.IsSpecifierFloatingPoint()) &&
            FlagType{IFormat}.IsSpecifierBaseDecimal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::Space::CStr<TChar>();
        const auto size_cstr = sign_cstr.Size() + val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%s%0*u%s", *sign_cstr, 
                (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s", *sign_cstr, 
            *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            !FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierIntegerUnsigned() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto size_cstr = val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%0*u%s", 
                (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, "%s", *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            !FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierFloatingPoint() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::Empty::CStr<TChar>();
        const auto size_cstr = sign_cstr.Size() + val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%s%0*u%s", 
                *sign_cstr, (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s", *sign_cstr, 
            *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            !FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierFloatingPoint() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::num::Plus::CStr<TChar>();
        const auto size_cstr = sign_cstr.Size() + val_cstr.Size();
        
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s", *sign_cstr, 
            *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            !FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierFloatingPoint() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::num::Plus::CStr<TChar>();
        const auto size_cstr = sign_cstr.Size() + val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%s%0*u%s", *sign_cstr, 
                (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s", *sign_cstr, 
            *val_cstr);
    }

    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            !FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierFloatingPoint() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::Space::CStr<TChar>();
        const auto size_cstr = sign_cstr.Size() + val_cstr.Size();
        
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s", *sign_cstr, 
            *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            !FlagType{IFormat}.IsSpecifierFlagPrefix() &&
            !FlagType{IFormat}.IsSpecifierFlagPrefixPlus() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixSpace() &&
            FlagType{IFormat}.IsSpecifierFlagPrefixZero() &&
            FlagType{IFormat}.IsSpecifierFloatingPoint() &&
            FlagType{IFormat}.IsSpecifierBaseHexadecimal(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        const auto sign_cstr = is_neg ? 
            test::def::cstr::val::num::Minus::CStr<TChar>():
            test::def::cstr::val::Space::CStr<TChar>();
        const auto size_cstr = sign_cstr.Size() + val_cstr.Size();

        if (size_cstr < size)
            return test::cstr::Format<TChar>(size + 1, "%s%0*u%s", *sign_cstr, 
                (int)(size - size_cstr), 0, *val_cstr);
        return test::cstr::Format<TChar>(size_cstr + 1, "%s%s", *sign_cstr, 
            *val_cstr);
    }

    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<!std::is_same<TChar, char>::value &&
            std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const bool& is_neg = false, const std::size_t size = 0)
    {
        auto empy_cstr = test::def::cstr::val::Empty::CStr<char>();
        if (size > val_cstr.Size())
        {
            const auto cstr = CStr<char, IFormat>(empy_cstr, is_neg, 
                size - val_cstr.Size());
            const auto cstr_size = val_cstr.Size() + cstr.Size();
            return test::cstr::Format<wchar_t>(cstr_size + 1, 
                L"%s%ls", *cstr, *val_cstr);
        }
        const auto cstr = CStr<char, IFormat>(empy_cstr, is_neg, 0);
            const auto cstr_size = val_cstr.Size() + cstr.Size();
        return test::cstr::Format<wchar_t>(cstr_size + 1, 
            L"%s%ls", *cstr, *val_cstr);
    }
};

} //!print

} //!out

} //!test

#endif //!TEST_OUT_PRINT_PREFIX_H_
