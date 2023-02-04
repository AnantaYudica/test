#ifndef TEST_TRAIT_OUT_FMT_ISFLAG_H_
#define TEST_TRAIT_OUT_FMT_ISFLAG_H_

#include "../../../out/fmt/flag/Decimal.h"
#include "../../../out/fmt/flag/Define.h"
#include "../../../out/fmt/flag/Exponent.h"
#include "../../../out/fmt/flag/Fixed.h"
#include "../../../out/fmt/flag/Hexadecimal.h"
#include "../../../out/fmt/flag/Length.h"
#include "../../../out/fmt/flag/Lower.h"
#include "../../../out/fmt/flag/Octal.h"
#include "../../../out/fmt/flag/Precision.h"
#include "../../../out/fmt/flag/Prefix.h"
#include "../../../out/fmt/flag/PrefixPlus.h"
#include "../../../out/fmt/flag/PrefixSpace.h"
#include "../../../out/fmt/flag/PrefixZero.h"
#include "../../../out/fmt/flag/Short.h"
#include "../../../out/fmt/flag/Signed.h"
#include "../../../out/fmt/flag/Unsigned.h"
#include "../../../out/fmt/flag/Upper.h"
#include "../../../out/fmt/flag/Value.h"
#include "../../../out/fmt/flag/Width.h"

#include <type_traits>
#include <utility>

namespace test
{
namespace trait
{
namespace out
{
namespace fmt
{

template<typename T>
class IsFlag
{
private:
    static constexpr std::false_type _IsFlag(...);
    static constexpr std::true_type _IsFlag(const test::out::fmt::flag::Decimal&);
    template<typename T_>
    static constexpr std::true_type _IsFlag(const test::out::fmt::flag::Define<T_>&);
    static constexpr std::true_type _IsFlag(const test::out::fmt::flag::Exponent&);
    static constexpr std::true_type _IsFlag(const test::out::fmt::flag::Fixed&);
    static constexpr std::true_type _IsFlag(const test::out::fmt::flag::Hexadecimal&);
    static constexpr std::true_type _IsFlag(const test::out::fmt::flag::Length&);
    static constexpr std::true_type _IsFlag(const test::out::fmt::flag::Lower&);
    static constexpr std::true_type _IsFlag(const test::out::fmt::flag::Octal&);
    static constexpr std::true_type _IsFlag(const test::out::fmt::flag::Precision&);
    static constexpr std::true_type _IsFlag(const test::out::fmt::flag::Prefix&);
    static constexpr std::true_type _IsFlag(const test::out::fmt::flag::PrefixPlus&);
    static constexpr std::true_type _IsFlag(const test::out::fmt::flag::PrefixSpace&);
    static constexpr std::true_type _IsFlag(const test::out::fmt::flag::PrefixZero&);
    static constexpr std::true_type _IsFlag(const test::out::fmt::flag::Short&);
    static constexpr std::true_type _IsFlag(const test::out::fmt::flag::Signed&);
    static constexpr std::true_type _IsFlag(const test::out::fmt::flag::Unsigned&);
    static constexpr std::true_type _IsFlag(const test::out::fmt::flag::Upper&);
    template<typename T_>
    static constexpr std::true_type _IsFlag(const test::out::fmt::flag::Value<T_>&);
    static constexpr std::true_type _IsFlag(const test::out::fmt::flag::Width&);
public:
    IsFlag() = delete;
public:
    static constexpr bool Value = 
        decltype(_IsFlag(std::declval<T>()))::value;
};

} //!fmt

} //!out

} //!trait

} //!test

#endif //!TEST_TRAIT_OUT_FMT_ISFLAG_H_
