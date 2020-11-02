#ifndef TEST_OUT_PRINT_FP_EXPONENT_H_
#define TEST_OUT_PRINT_FP_EXPONENT_H_

#include "../../../CString.h"
#include "../../../FloatingPoint.h"
#include "../../../cstr/Format.h"
#include "../../../def/cstr/val/fp/Exponent.h"
#include "../../../def/cstr/val/Empty.h"
#include "Specifier.h"

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

template<typename TChar = char, bool BLower = true, bool BPrefix = true,
    std::size_t NBase, typename TFloat>
test::CString<TChar> Exponent(const test::fp::Base<NBase, 
    test::FloatingPoint<TFloat>, false>& fp_base, const std::size_t& size = 0)
{
    return test::def::cstr::val::Empty::CStr<TChar>();
}

template<typename TChar = char, bool BLower = true, bool BPrefix = true,
    typename std::enable_if<std::is_same<TChar, char>::value &&
    BPrefix == true, int>::type = 0, std::size_t NBase>
test::CString<TChar> Exponent(const test::fp::Base<NBase, 
    test::FloatingPoint<float>, true>& fp_base, const std::size_t& size = 0)
{
    const auto num = fp_base.GetNumber();
    const auto exp = num.GetExponent();
    const auto exp_cstr = test::def::cstr::val::fp::Exponent::
        CStr<TChar, NBase, BLower>();
    
    const std::size_t exp_size = exp == 0 ? 1 : 
        std::floor(std::log10(std::abs(exp))) + 1;
    std::size_t cstr_size = exp_size + exp_cstr.Size() + 1;
    if (cstr_size < size) cstr_size = size;
    return test::cstr::Format<TChar>(cstr_size + 1,
        "%s%+0*" TEST_OUT_PRINT_FP_FLOAT_EXP_D, *exp_cstr,
        (int)((size - exp_cstr.Size())), exp);
}

template<typename TChar = char, bool BLower = true, bool BPrefix = true,
    typename std::enable_if<std::is_same<TChar, char>::value &&
    BPrefix == true, int>::type = 0, std::size_t NBase>
test::CString<TChar> Exponent(const test::fp::Base<NBase, 
    test::FloatingPoint<double>, true>& fp_base, const std::size_t& size = 0)
{
    const auto num = fp_base.GetNumber();
    const auto exp = num.GetExponent();
    const auto exp_cstr = test::def::cstr::val::fp::Exponent::
        CStr<TChar, NBase, BLower>();
    
    const std::size_t exp_size = exp == 0 ? 1 : 
        std::floor(std::log10(std::abs(exp))) + 1;
    std::size_t cstr_size = exp_size + exp_cstr.Size() + 1;
    if (cstr_size < size) cstr_size = size;
    return test::cstr::Format<TChar>(cstr_size + 1,
        "%s%+0*" TEST_OUT_PRINT_FP_DOUBLE_EXP_D, *exp_cstr,
        (int)((size - exp_cstr.Size())), exp);
}

template<typename TChar = char, bool BLower = true, bool BPrefix = true,
    typename std::enable_if<std::is_same<TChar, char>::value &&
    BPrefix == true, int>::type = 0, std::size_t NBase>
test::CString<TChar> Exponent(const test::fp::Base<NBase, 
    test::FloatingPoint<long double>, true>& fp_base, 
    const std::size_t& size = 0)
{
    const auto num = fp_base.GetNumber();
    const auto exp = num.GetExponent();
    const auto exp_cstr = test::def::cstr::val::fp::Exponent::
        CStr<TChar, NBase, BLower>();
    
    const std::size_t exp_size = exp == 0 ? 1 : 
        std::floor(std::log10(std::abs(exp))) + 1;
    std::size_t cstr_size = exp_size + exp_cstr.Size() + 1;
    if (cstr_size < size) cstr_size = size;
    return test::cstr::Format<TChar>(cstr_size + 1,
        "%s%+0*" TEST_OUT_PRINT_FP_DOUBLE_EXP_D, *exp_cstr,
        (int)((size - exp_cstr.Size())), exp);
}

template<typename TChar = char, bool BLower = true, bool BPrefix = true,
    typename std::enable_if<std::is_same<TChar, char>::value &&
    BPrefix == false, int>::type = 0, std::size_t NBase>
test::CString<TChar> Exponent(const test::fp::Base<NBase, 
    test::FloatingPoint<float>, true>& fp_base, const std::size_t& size = 0)
{
    const auto num = fp_base.GetNumber();
    const auto exp = num.GetExponent();
    
    const std::size_t exp_size = exp == 0 ? 1 : 
        std::floor(std::log10(std::abs(exp))) + 1;
    std::size_t cstr_size = exp < 0 ? exp_size + 1 : exp_size;
    if (cstr_size < size) cstr_size = size;
    return test::cstr::Format<TChar>(cstr_size + 1,
        "%0*" TEST_OUT_PRINT_FP_FLOAT_EXP_D, (int)size, exp);
}

template<typename TChar = char, bool BLower = true, bool BPrefix = true,
    typename std::enable_if<std::is_same<TChar, char>::value &&
    BPrefix == false, int>::type = 0, std::size_t NBase>
test::CString<TChar> Exponent(const test::fp::Base<NBase, 
    test::FloatingPoint<double>, true>& fp_base, const std::size_t& size = 0)
{
    const auto num = fp_base.GetNumber();
    const auto exp = num.GetExponent();
    
    const std::size_t exp_size = exp == 0 ? 1 : 
        std::floor(std::log10(std::abs(exp))) + 1;
    std::size_t cstr_size = exp < 0 ? exp_size + 1 : exp_size;
    if (cstr_size < size) cstr_size = size;
    return test::cstr::Format<TChar>(cstr_size + 1,
        "%0*" TEST_OUT_PRINT_FP_DOUBLE_EXP_D, (int)size, exp);
}

template<typename TChar = char, bool BLower = true, bool BPrefix = true,
    typename std::enable_if<std::is_same<TChar, char>::value &&
    BPrefix == false, int>::type = 0, std::size_t NBase>
test::CString<TChar> Exponent(const test::fp::Base<NBase, 
    test::FloatingPoint<long double>, true>& fp_base, 
    const std::size_t& size = 0)
{
    const auto num = fp_base.GetNumber();
    const auto exp = num.GetExponent();
    
    const std::size_t exp_size = exp == 0 ? 1 : 
        std::floor(std::log10(std::abs(exp))) + 1;
    std::size_t cstr_size = exp < 0 ? exp_size + 1 : exp_size;
    if (cstr_size < size) cstr_size = size;
    return test::cstr::Format<TChar>(cstr_size + 1,
        "%0*" TEST_OUT_PRINT_FP_DOUBLE_EXP_D, (int)size, exp);
}

template<typename TChar = char, bool BLower = true, bool BPrefix = true,
    typename std::enable_if<!std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0,
    std::size_t NBase, typename TFloat>
test::CString<TChar> Exponent(const test::fp::Base<NBase, 
    test::FloatingPoint<TFloat>, true>& fp_base, const std::size_t& size = 0)
{
    const auto cstr = Exponent<char, BLower, BPrefix>(fp_base, size);
    return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
}

} //!fp

} //!print

} //!out

} //!test

#endif //!TEST_OUT_PRINT_FP_EXPONENT_H_
