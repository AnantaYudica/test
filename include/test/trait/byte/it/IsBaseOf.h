#ifndef TEST_TRAIT_BYTE_IT_ISBASEOF_H_
#define TEST_TRAIT_BYTE_IT_ISBASEOF_H_

#include "../../../byte/Iterator.h"

#include <type_traits>
#include <utility>
#include <cstddef>

namespace test
{
namespace trait
{
namespace byte
{
namespace it
{

template<typename T>
class IsBaseOf
{
private:
    template<typename _T>
    static constexpr std::true_type _IsBaseOf(const test::byte::Iterator<_T>&);
    static constexpr std::false_type _IsBaseOf(...);
public:
    IsBaseOf() = delete;
public:
    static constexpr bool Value = 
        decltype(_IsBaseOf(std::declval<T>()))::value;
};

} //!it

} //!byte

} //!trait

} //!test

#endif //!TEST_TRAIT_BYTE_IT_ISBASEOF_H_
