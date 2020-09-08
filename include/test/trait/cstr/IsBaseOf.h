#ifndef TEST_TRAIT_CSTR_ISBASEOF_H_
#define TEST_TRAIT_CSTR_ISBASEOF_H_

#include "../../CString.h"

#include <type_traits>
#include <utility>

namespace test
{
namespace trait
{
namespace cstr
{

template<typename T>
class IsBaseOf
{
private:
    template<typename _T>
    static constexpr std::true_type _IsBaseOf(const test::CString<_T>&);
    static constexpr std::false_type _IsBaseOf(...);
public:
    IsBaseOf() = delete;
public:
    static constexpr bool Value = 
        decltype(_IsBaseOf(std::declval<T>()))::value;
};

} //!cstr

} //!trait

} //!test

#endif //!TEST_TRAIT_CSTR_ISBASEOF_H_