#ifndef TEST_INTEGER_FMT_CONVERSION_H_
#define TEST_INTEGER_FMT_CONVERSION_H_

#include "../../System.h"
#include "Definition.h"
#include "../Format.h"

#include <cstddef>
#include <cstdint>
#include <type_traits>

namespace test::integer::fmt
{

template<typename TInt, std::size_t NBase>
class Conversion;

}

#ifndef TEST_INTEGER_FMT_CONVERSION_DLEVEL

#define TEST_INTEGER_FMT_CONVERSION_DLEVEL 2

#endif //!TEST_INTEGER_FMT_CONVERSION_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TInt>,\
    test::sys::dbg::type::Value<std::size_t , NBase>

template<typename TInt, std::size_t NBase>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_INTEGER_FMT_CONVERSION_DLEVEL, 
    "test::integer::fmt::Conversion", 
    test::integer::fmt::Conversion<TInt, NBase>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace integer
{
namespace fmt
{

template<typename TInt, std::size_t NBase>
class Conversion
{};

template<typename TInt>
class Conversion<TInt, 2>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::integer::fmt::
        Conversion<TInt, 2>> DebugType;
public:
    typedef test::integer::fmt::Definition<TInt, 2> DefinitionType;
    typedef typename DefinitionType::ExpandType ExpandType;
public:
    template<std::size_t NToBase, std::size_t N, std::size_t NTo = 2 * N>
    static void To(const test::integer::Format<TInt, 2, N>& from, 
        test::integer::Format<TInt, NToBase, NTo>& out_ref);
    template<std::size_t NToBase, std::size_t N, std::size_t NTo = 2 * N>
    static test::integer::Format<TInt, NToBase, NTo> 
        To(const test::integer::Format<TInt, 2, N>& from);
};

template<typename TInt>
class Conversion<TInt, 8>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::integer::fmt::
        Conversion<TInt, 8>> DebugType;
public:
    typedef test::integer::fmt::Definition<TInt, 8> DefinitionType;
    typedef typename DefinitionType::ExpandType ExpandType;
public:
    template<std::size_t NToBase, std::size_t N, 
        std::size_t NTo = (N <= 1 ? 1 : (N % 2 == 0 ? N : (N + 1)) / 2)>
    static typename std::enable_if<NToBase == 2>::type 
        To(const test::integer::Format<TInt, 8, N>& from, 
            test::integer::Format<TInt, NToBase, NTo>& out_ref);
    template<std::size_t NToBase, std::size_t N, 
        std::size_t NTo = (N <= 1 ? 1 : (N % 2 == 0 ? N : (N + 1)) / 2)>
    static typename std::enable_if<NToBase == 2,
        test::integer::Format<TInt, NToBase, NTo>>::type 
            To(const test::integer::Format<TInt, 8, N>& from);
public:
    template<std::size_t NToBase, std::size_t N, 
        std::size_t NTo = N>
    static typename std::enable_if<NToBase == 10>::type 
        To(const test::integer::Format<TInt, 8, N>& from,
            test::integer::Format<TInt, NToBase, NTo>& out_ref);
    template<std::size_t NToBase, std::size_t N, 
        std::size_t NTo = N>
    static typename std::enable_if<NToBase == 10,
        test::integer::Format<TInt, NToBase, NTo>>::type 
            To(const test::integer::Format<TInt, 8, N>& from);
};

template<typename TInt>
class Conversion<TInt, 10>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::integer::fmt::
        Conversion<TInt, 10>> DebugType;
public:
    typedef test::integer::fmt::Definition<TInt, 10> DefinitionType;
    typedef typename DefinitionType::ExpandType ExpandType;
public:
    template<std::size_t NToBase, std::size_t N, 
        std::size_t NTo = (N <= 1 ? 1 : (N % 2 == 0 ? N : (N + 1)) / 2)>
    static typename std::enable_if<NToBase == 2>::type 
        To(const test::integer::Format<TInt, 10, N>& from, 
            test::integer::Format<TInt, NToBase, NTo>& out_ref);
    template<std::size_t NToBase, std::size_t N, 
        std::size_t NTo = (N <= 1 ? 1 : (N % 2 == 0 ? N : (N + 1)) / 2)>
    static typename std::enable_if<NToBase == 2,
        test::integer::Format<TInt, NToBase, NTo>>::type 
            To(const test::integer::Format<TInt, 10, N>& from);
public:
    template<std::size_t NToBase, std::size_t N, 
        std::size_t NTo = N>
    static typename std::enable_if<NToBase == 8>::type 
        To(const test::integer::Format<TInt, 10, N>& from,
            test::integer::Format<TInt, NToBase, NTo>& out_ref);
    template<std::size_t NToBase, std::size_t N, 
        std::size_t NTo = N>
    static typename std::enable_if<NToBase == 8,
        test::integer::Format<TInt, NToBase, NTo>>::type 
            To(const test::integer::Format<TInt, 10, N>& from);
};

template<typename TInt>
template<std::size_t NToBase, std::size_t N, std::size_t NTo>
void Conversion<TInt, 2>::To(const test::integer::Format<TInt, 2, N>& from, 
    test::integer::Format<TInt, NToBase, NTo>& out_ref)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
        "To<%s>(from=%p, out_ref=%p)", TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NToBase),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, N),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NTo)), &from, &out_ref);
    
    typedef test::integer::fmt::Definition<TInt, NToBase> ToDefinitionType;

    test::integer::Format<TInt, 2, N> divisor;
    test::integer::Format<TInt, 2, N> rem;
    test::integer::Format<TInt, 2, N> tmp(from);
    test::math::integer::div::Flag flag;
    
    divisor += ExpandType(ToDefinitionType::ElementMaxValue + 1);
    
    for (std::size_t i = 0; i < NTo; ++i)
    {
        test::integer::Format<TInt, 2, N>::Division(tmp, divisor, flag, &rem);
        out_ref[i] = *(rem[0]);
        rem = test::integer::Format<TInt, 2, N>();
    }
}

template<typename TInt>
template<std::size_t NToBase, std::size_t N, std::size_t NTo>
test::integer::Format<TInt, NToBase, NTo> 
Conversion<TInt, 2>::To(const test::integer::Format<TInt, 2, N>& from)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
        "To<%s>(from=%p)", TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NToBase),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, N),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NTo)), &from);
    
    test::integer::Format<TInt, NToBase, NTo> res;
    To<NToBase>(from, res);
    return res;
}

template<typename TInt>
template<std::size_t NToBase, std::size_t N, std::size_t NTo>
typename std::enable_if<NToBase == 2>::type 
Conversion<TInt, 8>::To(const test::integer::Format<TInt, 8, N>& from, 
    test::integer::Format<TInt, NToBase, NTo>& out_ref)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
        "To<%s>(from=%p, out_ref=%p)", TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NToBase),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, N),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NTo)), &from, &out_ref);
    
    for (std::size_t i = 1; i <= N; ++i)
    {
        out_ref *= ExpandType(DefinitionType::ElementMaxValue + 1);
        out_ref += (ExpandType)(*(from[N - i]));
    }
}

template<typename TInt>
template<std::size_t NToBase, std::size_t N, std::size_t NTo>
typename std::enable_if<NToBase == 2,
    test::integer::Format<TInt, NToBase, NTo>>::type 
Conversion<TInt, 8>::To(const test::integer::Format<TInt, 8, N>& from)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
        "To<%s>(from=%p)", TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NToBase),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, N),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NTo)), &from);
    
    test::integer::Format<TInt, NToBase, NTo> res;
    To<NToBase>(from, res);
    return res;
}

template<typename TInt>
template<std::size_t NToBase, std::size_t N, std::size_t NTo>
typename std::enable_if<NToBase == 10>::type 
Conversion<TInt, 8>::To(const test::integer::Format<TInt, 8, N>& from,
    test::integer::Format<TInt, NToBase, NTo>& out_ref)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
        "To<%s>(from=%p, out_ref=%p)", TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NToBase),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, N),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NTo)), &from, &out_ref);
    
    auto from_base2 = Conversion<TInt, 8>::To<2>(from);
    Conversion<TInt, 2>::template To<NToBase>(from_base2, out_ref);
}

template<typename TInt>
template<std::size_t NToBase, std::size_t N, std::size_t NTo>
typename std::enable_if<NToBase == 10,
    test::integer::Format<TInt, NToBase, NTo>>::type 
Conversion<TInt, 8>::To(const test::integer::Format<TInt, 8, N>& from)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
        "To<%s>(from=%p)", TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NToBase),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, N),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NTo)), &from);
    
    test::integer::Format<TInt, NToBase, NTo> res;
    To<NToBase>(from, res);
    return res;
}

template<typename TInt>
template<std::size_t NToBase, std::size_t N, std::size_t NTo>
typename std::enable_if<NToBase == 2>::type 
Conversion<TInt, 10>::To(const test::integer::Format<TInt, 10, N>& from, 
    test::integer::Format<TInt, NToBase, NTo>& out_ref)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
        "To<%s>(from=%p, out_ref=%p)", TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NToBase),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, N),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NTo)), &from, &out_ref);
    
    for (std::size_t i = 1; i <= N; ++i)
    {
        out_ref *= ExpandType(DefinitionType::ElementMaxValue + 1);
        out_ref += (ExpandType)(*(from[N - i]));
    }
}

template<typename TInt>
template<std::size_t NToBase, std::size_t N, std::size_t NTo>
typename std::enable_if<NToBase == 2,
    test::integer::Format<TInt, NToBase, NTo>>::type 
Conversion<TInt, 10>::To(const test::integer::Format<TInt, 10, N>& from)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
        "To<%s>(from=%p)", TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NToBase),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, N),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NTo)), &from);
    
    test::integer::Format<TInt, NToBase, NTo> res;
    To<NToBase>(from, res);
    return res;
}

template<typename TInt>
template<std::size_t NToBase, std::size_t N, std::size_t NTo>
typename std::enable_if<NToBase == 8>::type 
Conversion<TInt, 10>::To(const test::integer::Format<TInt, 10, N>& from,
    test::integer::Format<TInt, NToBase, NTo>& out_ref)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
        "To<%s>(from=%p, out_ref=%p)", TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NToBase),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, N),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NTo)), &from, &out_ref);
    
    auto from_base2 = Conversion<TInt, 10>::To<2>(from);
    Conversion<TInt, 2>::template To<NToBase>(from_base2, out_ref);
}

template<typename TInt>
template<std::size_t NToBase, std::size_t N, std::size_t NTo>
typename std::enable_if<NToBase == 8,
    test::integer::Format<TInt, NToBase, NTo>>::type 
Conversion<TInt, 10>::To(const test::integer::Format<TInt, 10, N>& from)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
        "To<%s>(from=%p)", TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NToBase),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, N),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NTo)), &from);
    
    test::integer::Format<TInt, NToBase, NTo> res;
    To<NToBase>(from, res);
    return res;
}


} //!fmt

} //!integer

} //!test

#endif //!TEST_INTEGER_FMT_CONVERSION_H_
