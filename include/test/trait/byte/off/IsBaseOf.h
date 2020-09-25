#ifndef TEST_TRAIT_BYTE_OFF_ISBASEOF_H_
#define TEST_TRAIT_BYTE_OFF_ISBASEOF_H_

#include "../../../byte/Offset.h"

#include <type_traits>
#include <utility>
#include <cstddef>

namespace test
{
namespace trait
{
namespace byte
{
namespace off
{

template<typename T>
class IsBaseOf
{
private:
    template<typename _T>
    static constexpr std::true_type _IsBaseOf(const test::byte::Offset<_T>&);
    static constexpr std::false_type _IsBaseOf(...);
public:
    IsBaseOf() = delete;
public:
    static constexpr bool Value = 
        decltype(_IsBaseOf(std::declval<T>()))::value;
};

} //!off

} //!byte

} //!trait

} //!test

#endif //!TEST_TRAIT_BYTE_OFF_ISBASEOF_H_
