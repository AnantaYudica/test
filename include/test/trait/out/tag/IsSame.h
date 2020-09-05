#ifndef TEST_TRAIT_OUT_TAG_ISSAME_H_
#define TEST_TRAIT_OUT_TAG_ISSAME_H_

#include "../../../out/Tag.h"

#include <type_traits>

namespace test
{
namespace trait
{
namespace out
{
namespace tag
{

template<typename TTag>
struct IsSame
{
    typedef bool ValueType;
    typedef typename std::remove_cv<typename std::remove_pointer<
        typename std::remove_reference<TTag>::type>::type>::type TagType;
    static constexpr ValueType Value = std::conditional<
        (((((std::is_same<TagType, test::out::tag::Crit>::value || 
        std::is_same<TagType, test::out::tag::Debug>::value) ||
        std::is_same<TagType, test::out::tag::Error>::value) || 
        std::is_same<TagType, test::out::tag::Info>::value) || 
        std::is_same<TagType, test::out::tag::Warn>::value) ||
        std::is_same<TagType, test::out::tag::Unknown>::value),
        std::true_type, std::false_type>::type::value;
};

} //!tag

} //!out

} //!trait

} //!test
#endif //!TEST_TRAIT_OUT_TAG_ISSAME_H_