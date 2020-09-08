#ifndef TEST_TRAIT_OUT_TAG_ENABLE_H_
#define TEST_TRAIT_OUT_TAG_ENABLE_H_

#include "../../../out/Tag.h"

namespace test
{
namespace trait
{
namespace out
{
namespace tag
{

template<typename TTag, typename T = void>
struct Enable
{};

template<typename T>
struct Enable<test::out::tag::Crit, T>
{
    typedef T Type;
};

template<typename T>
struct Enable<test::out::tag::Debug, T>
{
    typedef T Type;
};

template<typename T>
struct Enable<test::out::tag::Error, T>
{
    typedef T Type;
};

template<typename T>
struct Enable<test::out::tag::Info, T>
{
    typedef T Type;
};

template<typename T>
struct Enable<test::out::tag::Warn, T>
{
    typedef T Type;
};

template<typename T>
struct Enable<test::out::tag::Unknown, T>
{
    typedef T Type;
};


} //!tag

} //!out

} //!trait

} //!test

#endif //!TEST_TRAIT_OUT_TAG_ENABLE_H_