#ifndef TEST_SYS_RUNNER_INDEX_H_
#define TEST_SYS_RUNNER_INDEX_H_

#include <cstdlib>
#include <type_traits>

namespace test
{
namespace sys
{
namespace runner
{

template<std::size_t Key, std::size_t... Keys>
struct Index;

} //!runner

} //!sys

} //!test

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS \
    test::sys::dbg::type::Value<std::size_t, Key>,\
    test::sys::dbg::type::Value<std::size_t, Keys>...

template<std::size_t Key, std::size_t... Keys>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE(
    "test::sys::runner::Index", 
    test::sys::runner::Index<Key, Keys...>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace sys
{
namespace runner
{

template<std::size_t Key, std::size_t... Keys>
struct Index : Index<Keys...>
{
    Index() = delete;
    static constexpr std::size_t ConstSize()
    {
        return sizeof...(Keys) + 1;
    }
    template<std::size_t I>
    static constexpr std::size_t ConstGet()
    {
        return I == 0 ? Key : Index<Keys...>::template ConstGet<I - 1>();
    }
    template<std::size_t N, std::size_t I = 0>
    static constexpr std::size_t ConstGetBegin()
    {
        return I >= ConstSize() ? I - 1 : 
            (N < Key ? I : Index<Keys...>::template ConstGetBegin<N, I + 1>());
    }
    static const std::size_t* Get()
    {
        static std::size_t keys[] = {Key, Keys...};
        return keys;
    }
};

template<std::size_t Key>
struct Index<Key>
{
    Index() = delete;
    static constexpr std::size_t ConstSize()
    {
        return 1;
    }
    
    template<std::size_t I>
    static constexpr std::size_t ConstGet()
    {
        return Key;
    }
    template<std::size_t N, std::size_t I = 0>
    static constexpr std::size_t ConstGetBegin()
    {
        return I;
    }
    static const std::size_t* Get()
    {
        static std::size_t keys[] = {Key};
        return keys;
    }
};

} //!runner

} //!sys

} //!test

#endif //!TEST_SYS_RUNNER_INDEX_H_
