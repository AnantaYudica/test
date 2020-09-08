#ifndef TEST_MSG_TAG_H_
#define TEST_MSG_TAG_H_

#include "../type/Index.h"
#include "../out/Tag.h"

namespace test
{
namespace msg
{
namespace tag
{

typedef test::out::tag::Debug Debug;

typedef test::out::tag::Error Error;

typedef test::out::tag::Info Info;

typedef test::out::tag::Unknown Unknown;

} //!tag

template<typename TTag, typename... TArgs>
struct Tag
{
    typedef TTag TagType;
    typedef void ArgumentType;
    typedef void IndexType;
};

template<typename TTag, typename TArg>
struct Tag<TTag, TArg>
{
    typedef TTag TagType;
    typedef TArg ArgumentType;
    typedef void IndexType;
};

template<typename TTag, typename TArg, std::size_t IAt>
struct Tag<test::type::Index<TTag, IAt>, TArg>
{
    typedef TTag TagType;
    typedef TArg ArgumentType;
    typedef test::type::Index<TTag, IAt> IndexType;
};

template<typename TArg>
using TagDebug = Tag<test::msg::tag::Debug, TArg>;
template<typename TArg>
using TagError = Tag<test::msg::tag::Error, TArg>;
template<typename TArg>
using TagInfo = Tag<test::msg::tag::Info, TArg>;

template<typename TTag, std::size_t IAt, typename TArg>
using TagIndex = Tag<test::type::Index<TTag, IAt>, TArg>;
template<std::size_t IAt, typename TArg>
using TagDebugIndex = Tag<test::type::Index<test::msg::tag::Debug, IAt>, TArg>;
template<std::size_t IAt, typename TArg>
using TagErrorIndex = Tag<test::type::Index<test::msg::tag::Error, IAt>, TArg>;
template<std::size_t IAt, typename TArg>
using TagInfoIndex = Tag<test::type::Index<test::msg::tag::Info, IAt>, TArg>;


} //!msg

} //!test

#endif //!TEST_MSG_TAG_H_
