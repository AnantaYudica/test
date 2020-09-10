#ifndef TEST_TRAIT_TYPE_INDEX_ISBASEOF_H_
#define TEST_TRAIT_TYPE_INDEX_ISBASEOF_H_

#include "../../../type/Index.h"

#include <type_traits>
#include <utility>

namespace test
{
namespace trait
{
namespace type
{
namespace index
{

template<typename T>
class IsBaseOf
{
private:
    template<typename _T, std::size_t _I>
    static constexpr std::true_type _IsBaseOf(
        const test::type::Index<_T, _I>&);
    static constexpr std::false_type _IsBaseOf(...);
public:
    IsBaseOf() = delete;
public:
    static constexpr bool Value = 
        decltype(_IsBaseOf(std::declval<T>()))::value;
};

} //!index

} //!type

} //!trait

} //!test

#endif //!TEST_TRAIT_TYPE_INDEX_ISBASEOF_H_
