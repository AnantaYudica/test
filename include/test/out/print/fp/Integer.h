#ifndef TEST_OUT_PRINT_FP_INTEGER_H_
#define TEST_OUT_PRINT_FP_INTEGER_H_

#include "../../../CString.h"
#include "../../../FloatingPoint.h"
#include "../../../cstr/Format.h"
#include "../../../def/out/cstr/fp/Precision.h"
#include "Specifier.h"

#include <cmath>
#include <cwchar>
#include <cfloat>
#include <type_traits>

namespace test
{
namespace out
{
namespace print
{
namespace fp
{

struct Integer
{
    template<std::size_t NBase, typename TFloatingPoint, 
        bool BNormalize = false>
    using ValueType = typename test::fp::Base<NBase, TFloatingPoint, 
        BNormalize>::MantissaType;

    template<typename TFloat, std::size_t NBase, bool BNormalize,
        typename std::enable_if<!test::def::out::cstr::fp::Precision::
            IsRound<TFloat, NBase>(), int>::type = 0>
    static ValueType<NBase, test::FloatingPoint<TFloat>, BNormalize> 
        Round(const test::fp::Base<NBase, test::FloatingPoint<TFloat>, 
            BNormalize>& fp_base, const std::size_t& precision)
    {
        return fp_base.GetNumber().GetInteger();
    }

    template<typename TFloat, std::size_t NBase,
        typename std::enable_if<test::def::out::cstr::fp::Precision::
            IsRound<TFloat, NBase>(), int>::type = 0>
    static ValueType<NBase, test::FloatingPoint<TFloat>, false> 
        Round(const test::fp::Base<NBase, test::FloatingPoint<TFloat>, 
            false>& fp_base, const std::size_t& precision)
    {
        const auto num = fp_base.GetNumber();
        const auto exp = num.GetExponent();
        const auto rem_digit = num.GetRemainderDigitSize();
        TFloat rem = num.GetRemainder();
        if (precision != 0 || exp > rem_digit || rem == 0)
            return num.GetInteger();
        rem *= std::pow(NBase, -rem_digit);
        rem = std::round(rem);
        return num.GetInteger() + rem;
    }

    template<typename TFloat, std::size_t NBase,
        typename std::enable_if<test::def::out::cstr::fp::Precision::
            IsRound<TFloat, NBase>(), int>::type = 0>
    static ValueType<NBase, test::FloatingPoint<TFloat>, true> 
        Round(const test::fp::Base<NBase, test::FloatingPoint<TFloat>, 
            true>& fp_base, const std::size_t& precision)
    {
        const auto num = fp_base.GetNumber();
        const auto rem_digit = num.GetRemainderDigitSize();
        TFloat rem = num.GetRemainder();
        if (precision != 0 || rem == 0)
            return num.GetInteger();
        rem *= std::pow(NBase, -rem_digit);
        rem = std::round(rem);
        return num.GetInteger() + rem;
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value, 
        int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<10, 
        test::FloatingPoint<float>, false>& fp_base, 
        const std::size_t& size = 0)
    {
        const auto num = fp_base.GetNumber();
        const auto _int = num.GetInteger();
        
        const std::size_t int_size = _int == 0 ? 1 : 
            std::floor(std::log10(_int)) + 1;
        std::size_t cstr_size = int_size;
        if (cstr_size < size) cstr_size = size;
        return test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_FLOAT_MANT_U, (int)size, _int);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value, 
        int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<10, 
        test::FloatingPoint<double>, false>& fp_base, 
        const std::size_t& size = 0)
    {
        const auto num = fp_base.GetNumber();
        const auto _int = num.GetInteger();
        
        const std::size_t int_size = _int == 0 ? 1 : 
            std::floor(std::log10(_int)) + 1;
        std::size_t cstr_size = int_size;
        if (cstr_size < size) cstr_size = size;
        return test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_DOUBLE_MANT_U, (int)size, _int);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value, 
        int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<10, 
        test::FloatingPoint<long double>, false>& fp_base, 
        const std::size_t& size = 0)
    {
        const auto num = fp_base.GetNumber();
        const auto _int = num.GetInteger();
        
        const std::size_t int_size = _int == 0 ? 1 : 
            std::floor(std::log10(_int)) + 1;
        std::size_t cstr_size = int_size;
        if (cstr_size < size) cstr_size = size;
        return test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_LDOUBLE_MANT_U, (int)size, _int);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value, 
        int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<10, 
        test::FloatingPoint<float>, true>& fp_base, 
        const std::size_t& size = 0)
    {
        const auto num = fp_base.GetNumber();
        const auto _int = num.GetInteger();
        
        const std::size_t int_size = 1;
        std::size_t cstr_size = int_size;
        if (cstr_size < size) cstr_size = size;
        return test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_FLOAT_MANT_U, (int)size, _int);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value, 
        int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<10, 
        test::FloatingPoint<double>, true>& fp_base, 
        const std::size_t& size = 0)
    {
        const auto num = fp_base.GetNumber();
        const auto _int = num.GetInteger();
        
        const std::size_t int_size = 1;
        std::size_t cstr_size = int_size;
        if (cstr_size < size) cstr_size = size;
        return test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_DOUBLE_MANT_U, (int)size, _int);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value, 
        int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<10, 
        test::FloatingPoint<long double>, true>& fp_base, 
        const std::size_t& size = 0)
    {
        const auto num = fp_base.GetNumber();
        const auto _int = num.GetInteger();
        
        const std::size_t int_size = 1;
        std::size_t cstr_size = int_size;
        if (cstr_size < size) cstr_size = size;
        return test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_LDOUBLE_MANT_U, (int)size, _int);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            BLower == true, int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<2, 
        test::FloatingPoint<float>, true>& fp_base, 
        const std::size_t& size = 0)
    {
        const auto num = fp_base.GetNumber();
        const auto _int = num.GetInteger();
        
        const std::size_t int_size = 1;
        std::size_t cstr_size = int_size;
        if (cstr_size < size) cstr_size = size;
        return test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_FLOAT_MANT_X, (int)size, _int);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            BLower == true, int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<2, 
        test::FloatingPoint<double>, true>& fp_base, 
        const std::size_t& size = 0)
    {
        const auto num = fp_base.GetNumber();
        const auto _int = num.GetInteger();
        
        const std::size_t int_size = 1;
        std::size_t cstr_size = int_size;
        if (cstr_size < size) cstr_size = size;
        return test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_DOUBLE_MANT_X, (int)size, _int);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            BLower == true, int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<2, 
        test::FloatingPoint<long double>, true>& fp_base, 
        const std::size_t& size = 0)
    {
        const auto num = fp_base.GetNumber();
        const auto _int = num.GetInteger();
        
        const std::size_t int_size = 1;
        std::size_t cstr_size = int_size;
        if (cstr_size < size) cstr_size = size;
        return test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_LDOUBLE_MANT_X, (int)size, _int);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            BLower == false, int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<2, 
        test::FloatingPoint<float>, true>& fp_base, 
        const std::size_t& size = 0)
    {
        const auto num = fp_base.GetNumber();
        const auto _int = num.GetInteger();
        
        const std::size_t int_size = 1;
        std::size_t cstr_size = int_size;
        if (cstr_size < size) cstr_size = size;
        return test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_FLOAT_MANT__X, (int)size, _int);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            BLower == false, int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<2, 
        test::FloatingPoint<double>, true>& fp_base, 
        const std::size_t& size = 0)
    {
        const auto num = fp_base.GetNumber();
        const auto _int = num.GetInteger();
        
        const std::size_t int_size = 1;
        std::size_t cstr_size = int_size;
        if (cstr_size < size) cstr_size = size;
        return test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_DOUBLE_MANT__X, (int)size, _int);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            BLower == false, int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<2, 
        test::FloatingPoint<long double>, true>& fp_base, 
        const std::size_t& size = 0)
    {
        const auto num = fp_base.GetNumber();
        const auto _int = num.GetInteger();
        
        const std::size_t int_size = 1;
        std::size_t cstr_size = int_size;
        if (cstr_size < size) cstr_size = size;
        return test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_LDOUBLE_MANT__X, (int)size, _int);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<!std::is_same<TChar, char>::value &&
            std::is_same<TChar, wchar_t>::value, int>::type = 0,
        std::size_t NBase, typename TFloat, bool BNormalize>
    static test::CString<TChar> CStr(const test::fp::Base<NBase, 
        test::FloatingPoint<TFloat>, BNormalize>& fp_base, 
        const std::size_t& size = 0)
    {
        const auto cstr = CStr<char, BLower>(fp_base, size);
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }

};

} //!fp

} //!print

} //!out

} //!test

#endif //!TEST_OUT_PRINT_FP_INTEGER_H_
