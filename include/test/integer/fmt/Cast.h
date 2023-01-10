#ifndef TEST_INTEGER_FMT_CAST_H_
#define TEST_INTEGER_FMT_CAST_H_

#include "../../System.h"
#include "../Format.h"
#include "Definition.h"

#include <cstddef>
#include <cstdint>
#include <utility>

namespace test::integer::fmt
{

template<typename TInt, std::size_t NBase>
class Cast;

}

#ifndef TEST_INTEGER_FMT_CAST_DLEVEL

#define TEST_INTEGER_FMT_CAST_DLEVEL 2

#endif //!TEST_INTEGER_FMT_CAST_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TInt>,\
    test::sys::dbg::type::Value<std::size_t , NBase>

template<typename TInt, std::size_t NBase>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_INTEGER_FMT_CAST_DLEVEL, 
    "test::integer::fmt::Cast", 
    test::integer::fmt::Cast<TInt, NBase>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace integer
{
namespace fmt
{

template<typename TInt, std::size_t NBase>
class Cast
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::integer::fmt::
        Cast<TInt, NBase>> DebugType;
public:
    typedef test::integer::fmt::Definition<TInt, NBase> DefinitionType;
public:
    typedef typename DefinitionType::ElementType ElementType;
public:
    template<typename TToInt, 
        typename TToDefinition = test::integer::fmt::Definition<TToInt, NBase>, 
        typename TToElement = typename TToDefinition::ElementType>
    static constexpr std::size_t Resize(const std::size_t n) 
    {
        return DefinitionType::template ElementResize<TToElement>(n);
    }
public:
    template<typename TToInt, std::size_t N, std::size_t NTo = 
        test::integer::fmt::Cast<TInt, NBase>::Resize<TToInt>(N)>
    static void To(const test::integer::Format<TInt, NBase, N>& from,
        test::integer::Format<TToInt, NBase, NTo>& out_ref)
    {
        TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
            "To<%s>(from=%p, out_ref=%p)", TEST_SYS_DEBUG_TARGS_NAME_STR(
                TEST_SYS_DEBUG_T_TYPE(TToInt),
                TEST_SYS_DEBUG_TV_TYPE(std::size_t, N),
                TEST_SYS_DEBUG_TV_TYPE(std::size_t, NTo)), &from, &out_ref);
        
        typedef test::integer::fmt::Definition<TToInt, NBase> ToDefinitionType;
        const auto elem_to_valsize = test::integer::fmt::Cast<TInt, NBase>::
            Resize<TToInt>(1);
        for (std::size_t i = 1; i <= N; ++i)
        {
            for (std::size_t j = 1; j <= elem_to_valsize; ++j)
            {
                const std::size_t curr = elem_to_valsize - j;
                const auto elem = ToDefinitionType::
                    ElementValueAt(*(from[N - i]), curr);
                out_ref *= ToDefinitionType::
                    ElementMaxValueAt(ElementType(0), curr) + 1;
                out_ref += elem;
            }
        }

    }
    
    template<typename TToInt, std::size_t N, std::size_t NTo = 
        test::integer::fmt::Cast<TInt, NBase>::Resize<TToInt>(N)>
    static test::integer::Format<TToInt, NBase, NTo> 
        To(const test::integer::Format<TInt, NBase, N>& from)
    {
        TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
            "To<%s>(from=%p)", TEST_SYS_DEBUG_TARGS_NAME_STR(
                TEST_SYS_DEBUG_T_TYPE(TToInt),
                TEST_SYS_DEBUG_TV_TYPE(std::size_t, N),
                TEST_SYS_DEBUG_TV_TYPE(std::size_t, NTo)), &from);
        
        test::integer::Format<TToInt, NBase, NTo> res;
        To<TToInt, N, NTo>(from, res);
        return res;
    }
};

} //!fmt

} //!integer

} //!test

#endif //!TEST_INTEGER_FMT_CAST_H_
