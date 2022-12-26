#ifndef TEST_TRAIT_BYTE_ISBASEOF_H_
#define TEST_TRAIT_BYTE_ISBASEOF_H_

#include "../../byte/Base.h"

#include <type_traits>
#include <utility>
#include <cstddef>

namespace test
{
namespace trait
{
namespace byte
{

template<typename T>
class IsBaseOf
{
private:
    template<std::size_t N, bool Sign = false>
    static constexpr std::true_type _IsBaseOf(const test::byte::Base<N, Sign>&);
    static constexpr std::false_type _IsBaseOf(...);
public:
    IsBaseOf() = delete;
public:
    static constexpr bool Value = 
        decltype(_IsBaseOf(std::declval<T>()))::value;
};

} //!byte

} //!trait

} //!test

#endif //!TEST_TRAIT_BYTE_ISBASEOF_H_
