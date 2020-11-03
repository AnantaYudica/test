#ifndef TEST_OUT_PRINT_FP_PRECISION_H_
#define TEST_OUT_PRINT_FP_PRECISION_H_

#include "../../../CString.h"
#include "../../../FloatingPoint.h"
#include "../../../cstr/Format.h"
#include "../../../def/cstr/val/Zero.h"
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

struct Precision
{
    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value, 
        int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<10, 
        test::FloatingPoint<float>, false>& fp_base, 
        const std::size_t& size = -1)
    {
        if (size == 0) return test::def::cstr::val::Zero::CStr<TChar>();
        const auto num = fp_base.GetNumber();
        const int rem_size = num.GetExponent() >= 0 ? 1 : 
            std::abs(num.GetExponent());
        const std::size_t cstr_size = size < (std::size_t)rem_size ? size : 
            rem_size;
        const auto cstr = test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_FLOAT_MANT_U, rem_size, 
            num.GetRemainder());
        if (cstr.Size() == size || size == -1) return cstr; 
        return test::cstr::Format<TChar>(size + 1, "%s%0*u", 
            *cstr, (int)size, 0);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value, 
        int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<10, 
        test::FloatingPoint<double>, false>& fp_base, 
        const std::size_t& size = -1)
    {
        if (size == 0) return test::def::cstr::val::Zero::CStr<TChar>();
        const auto num = fp_base.GetNumber();
        const int rem_size = num.GetExponent() >= 0 ? 1 : 
            std::abs(num.GetExponent());
        const std::size_t cstr_size = size < (std::size_t)rem_size ? size : 
            rem_size;
        const auto cstr = test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_DOUBLE_MANT_U, rem_size, 
            num.GetRemainder());
        if (cstr.Size() == size || size == -1) return cstr; 
        return test::cstr::Format<TChar>(size + 1, "%s%0*u", *cstr, 
            (int)size, 0);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value, 
        int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<10, 
        test::FloatingPoint<long double>, false>& fp_base, 
        const std::size_t& size = -1)
    {
        if (size == 0) return test::def::cstr::val::Zero::CStr<TChar>();
        const auto num = fp_base.GetNumber();
        const int rem_size = num.GetExponent() >= 0 ? 1 : 
            std::abs(num.GetExponent());
        const std::size_t cstr_size = size < (std::size_t)rem_size ? size : 
            rem_size;
        const auto cstr = test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_LDOUBLE_MANT_U, rem_size, 
            num.GetRemainder());
        if (cstr.Size() == size || size == -1) return cstr; 
        return test::cstr::Format<TChar>(size + 1, "%s%0*u", 
            *cstr, (int)size, 0);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value, 
        int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<10, 
        test::FloatingPoint<float>, true>& fp_base, 
        const std::size_t& size = -1)
    {
        if (size == 0) return test::def::cstr::val::Zero::CStr<TChar>();
        const auto num = fp_base.GetNumber();
        const int rem_size = num.GetRemainderDigitSize();
        const std::size_t cstr_size = size < (std::size_t)rem_size ? size : 
            rem_size;
        const auto cstr = test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_FLOAT_MANT_U, rem_size, 
            num.GetRemainder());
        if (cstr.Size() == size || size == -1) return cstr; 
        return test::cstr::Format<TChar>(size + 1, "%s%0*u", 
            *cstr, (int)size, 0);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value, 
        int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<10, 
        test::FloatingPoint<double>, true>& fp_base, 
        const std::size_t& size = -1)
    {
        if (size == 0) return test::def::cstr::val::Zero::CStr<TChar>();
        const auto num = fp_base.GetNumber();
        const int rem_size = num.GetRemainderDigitSize();
        const std::size_t cstr_size = size < (std::size_t)rem_size ? size : 
            rem_size;
        const auto cstr = test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_DOUBLE_MANT_U, rem_size, 
            num.GetRemainder());
        if (cstr.Size() == size || size == -1) return cstr; 
        return test::cstr::Format<TChar>(size + 1, "%s%0*u", 
            *cstr, (int)size, 0);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value, 
        int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<10, 
        test::FloatingPoint<long double>, true>& fp_base, 
        const std::size_t& size = -1)
    {
        if (size == 0) return test::def::cstr::val::Zero::CStr<TChar>();
        const auto num = fp_base.GetNumber();
        const int rem_size = num.GetRemainderDigitSize();
        const std::size_t cstr_size = size < (std::size_t)rem_size ? size : 
            rem_size;
        const auto cstr = test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_LDOUBLE_MANT_U, rem_size, 
            num.GetRemainder());
        if (cstr.Size() == size || size == -1) return cstr; 
        return test::cstr::Format<TChar>(size + 1, "%s%0*u", 
            *cstr, (int)size, 0);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            BLower == true, int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<2, 
        test::FloatingPoint<float>, true>& fp_base, 
        const std::size_t& size = -1)
    {
        if (size == 0) return test::def::cstr::val::Zero::CStr<TChar>();
        const auto num = fp_base.GetNumber();
        const int rem_size = num.GetRemainderDigitSize() / 4;
        const std::size_t cstr_size = size < (std::size_t)rem_size ? size : 
            rem_size;
        const auto cstr = test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_FLOAT_MANT_X, rem_size, 
            num.GetRemainder());
        if (cstr.Size() == size || size == -1) return cstr; 
        return test::cstr::Format<TChar>(size + 1, "%s%0*u", 
            *cstr, (int)size, 0);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            BLower == true, int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<2, 
        test::FloatingPoint<double>, true>& fp_base, 
        const std::size_t& size = -1)
    {
        if (size == 0) return test::def::cstr::val::Zero::CStr<TChar>();
        const auto num = fp_base.GetNumber();
        const int rem_size = num.GetRemainderDigitSize() / 4;
        const std::size_t cstr_size = size < (std::size_t)rem_size ? size : 
            rem_size;
        const auto cstr = test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_DOUBLE_MANT_X, rem_size, 
            num.GetRemainder());
        if (cstr.Size() == size || size == -1) return cstr; 
        return test::cstr::Format<TChar>(size + 1, "%s%0*u", 
            *cstr, (int)size, 0);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            BLower == true, int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<2, 
        test::FloatingPoint<long double>, true>& fp_base, 
        const std::size_t& size = -1)
    {
        if (size == 0) return test::def::cstr::val::Zero::CStr<TChar>();
        const auto num = fp_base.GetNumber();
        const int rem_size = num.GetRemainderDigitSize() / 4;
        const std::size_t cstr_size = size < (std::size_t)rem_size ? size : 
            rem_size;
        const auto cstr = test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_LDOUBLE_MANT_X, rem_size, 
            num.GetRemainder());
        if (cstr.Size() == size || size == -1) return cstr; 
        return test::cstr::Format<TChar>(size + 1, "%s%0*u", 
            *cstr, (int)size, 0);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            BLower == false, int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<2, 
        test::FloatingPoint<float>, true>& fp_base, 
        const std::size_t& size = -1)
    {
        if (size == 0) return test::def::cstr::val::Zero::CStr<TChar>();
        const auto num = fp_base.GetNumber();
        const int rem_size = num.GetRemainderDigitSize() / 4;
        const std::size_t cstr_size = size < (std::size_t)rem_size ? size : 
            rem_size;
        const auto cstr = test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_FLOAT_MANT__X, rem_size, 
            num.GetRemainder());
        if (cstr.Size() == size || size == -1) return cstr; 
        return test::cstr::Format<TChar>(size + 1, "%s%0*u", 
            *cstr, (int)size, 0);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            BLower == false, int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<2, 
        test::FloatingPoint<double>, true>& fp_base, 
        const std::size_t& size = -1)
    {
        if (size == 0) return test::def::cstr::val::Zero::CStr<TChar>();
        const auto num = fp_base.GetNumber();
        const int rem_size = num.GetRemainderDigitSize() / 4;
        const std::size_t cstr_size = size < (std::size_t)rem_size ? size : 
            rem_size;
        const auto cstr = test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_DOUBLE_MANT__X, rem_size, 
            num.GetRemainder());
        if (cstr.Size() == size || size == -1) return cstr; 
        return test::cstr::Format<TChar>(size + 1, "%s%0*u", 
            *cstr, (int)size, 0);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            BLower == false, int>::type = 0>
    static test::CString<TChar> CStr(const test::fp::Base<2, 
        test::FloatingPoint<long double>, true>& fp_base, 
        const std::size_t& size = -1)
    {
        if (size == 0) return test::def::cstr::val::Zero::CStr<TChar>();
        const auto num = fp_base.GetNumber();
        const int rem_size = num.GetRemainderDigitSize() / 4;
        const std::size_t cstr_size = size < (std::size_t)rem_size ? size : 
            rem_size;
        const auto cstr = test::cstr::Format<TChar>(cstr_size + 1,
            "%0*" TEST_OUT_PRINT_FP_LDOUBLE_MANT__X, rem_size, 
            num.GetRemainder());
        if (cstr.Size() == size || size == -1) return cstr; 
        return test::cstr::Format<TChar>(size + 1, "%s%0*u", 
            *cstr, (int)size, 0);
    }

    template<typename TChar = char, bool BLower = true,
        typename std::enable_if<!std::is_same<TChar, char>::value &&
            std::is_same<TChar, wchar_t>::value, int>::type = 0, 
            std::size_t NBase, typename TFloat, bool BNormalize>
    static test::CString<TChar> CStr(const test::fp::Base<NBase, 
        test::FloatingPoint<TFloat>, BNormalize>& fp_base, 
        const std::size_t& size = -1)
    {
        const auto cstr = CStr<char, BLower>(fp_base, size);
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }

};

} //!fp

} //!print

} //!out

} //!test

#endif //!TEST_OUT_PRINT_FP_PRECISION_H_
