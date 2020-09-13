#ifndef TEST_TRAIT_PTR_DEFN_ISBASEOF_H_
#define TEST_TRAIT_PTR_DEFN_ISBASEOF_H_

#include "../../../ptr/Definition.h"

#include <type_traits>
#include <utility>

namespace test
{
namespace trait
{
namespace ptr
{
namespace defn
{

template<typename T>
class IsBaseOf
{
private:
    template<typename _T, _T(*Func)()>
    static constexpr std::true_type _IsBaseOf(
        const test::ptr::Definition<_T, Func>&);
    static constexpr std::false_type _IsBaseOf(...);
public:
    IsBaseOf() = delete;
public:
    static constexpr bool Value = 
        decltype(_IsBaseOf(std::declval<T>()))::value;
};

} //!defn

} //!ptr

} //!trait

} //!test

#endif //!TEST_TRAIT_PTR_DEFN_ISBASEOF_H_
