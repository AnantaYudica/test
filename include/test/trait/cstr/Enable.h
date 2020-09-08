#ifndef TEST_TRAIT_CSTR_ENABLE_H_
#define TEST_TRAIT_CSTR_ENABLE_H_

#include <cstddef>

namespace test
{
namespace trait
{
namespace cstr
{

template<typename TChar, typename TArg, typename T = void>
struct Enable
{};

template<typename TChar, std::size_t N, typename T>
struct Enable<TChar, TChar[N], T>
{
    typedef T Type;
};

template<typename TChar, std::size_t N, typename T>
struct Enable<TChar, TChar(&)[N], T>
{
    typedef T Type;
};

template<typename TChar, std::size_t N, typename T>
struct Enable<TChar, TChar(*)[N], T>
{
    typedef T Type;
};

template<typename TChar, typename T>
struct Enable<TChar, TChar*, T>
{
    typedef T Type;
};

template<typename TChar, typename T>
struct Enable<TChar, TChar*&, T>
{
    typedef T Type;
};

template<typename TChar, std::size_t N, typename T>
struct Enable<TChar, const TChar[N], T>
{
    typedef T Type;
};

template<typename TChar, std::size_t N, typename T>
struct Enable<TChar, const TChar(&)[N], T>
{
    typedef T Type;
};

template<typename TChar, std::size_t N, typename T>
struct Enable<TChar, const TChar(*)[N], T>
{
    typedef T Type;
};

template<typename TChar, typename T>
struct Enable<TChar, const TChar*, T>
{
    typedef T Type;
};

template<typename TChar, typename T>
struct Enable<TChar, const TChar*&, T>
{
    typedef T Type;
};

} //!cstr

} //!trait

} //!test

#endif //!TEST_TRAIT_CSTR_ENABLE_H_
