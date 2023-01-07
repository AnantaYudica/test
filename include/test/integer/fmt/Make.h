#ifndef TEST_INTEGER_FMT_MAKE_H_
#define TEST_INTEGER_FMT_MAKE_H_

#include "../../System.h"
#include "../../Byte.h"
#include "../../trait/type/Definition.h"
#include "../Format.h"
#include "Definition.h"

#include <cstddef>
#include <cstdint>

namespace test::integer::fmt
{
template<typename TInt, std::size_t NBase>
class Make;
}

#ifndef TEST_INTEGER_FMT_MAKE_DLEVEL

#define TEST_INTEGER_FMT_MAKE_DLEVEL 2

#endif //!TEST_INTEGER_FMT_MAKE_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TInt>,\
    test::sys::dbg::type::Value<std::size_t , NBase>

template<typename TInt, std::size_t NBase>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_INTEGER_FMT_MAKE_DLEVEL, 
    "test::integer::fmt::Make", 
    test::integer::fmt::Make<TInt, NBase>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace integer
{
namespace fmt
{

template<typename TInt, std::size_t NBase>
class Make
{
public:
    typedef void DefinitionType;
public:
    Make() = delete;
};

template<typename TInt>
class Make<TInt, 2>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::integer::fmt::Make<TInt, 2>> DebugType;
public:
    typedef test::integer::fmt::Definition<TInt, 2> DefinitionType;
    template<std::size_t N>
    using FormatType = test::integer::Format<TInt, 2, N>;
public:
    template<std::size_t N = 1, typename TValue>
    static void From(const TValue& val, FormatType<N>& out_ref)
    {
        TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
            "From<%s>(out_ref= %p, val=%s)", TEST_SYS_DEBUG_TARGS_NAME_STR(
                TEST_SYS_DEBUG_TV_TYPE(std::size_t, N),
                TEST_SYS_DEBUG_T_TYPE(TValue)), &out_ref,
                TEST_SYS_DEBUG_VALUE_STR(0, val));
        
        typedef test::integer::fmt::Definition<TValue, 2> DefinitionValueType;
        typedef typename FormatType<N>::BaseType RawType;
        constexpr std::size_t alloc_size = DefinitionType::AllocationSize(N);
        constexpr std::size_t val_alloc_size = 
            DefinitionValueType::AllocationSize(1);
        const bool cast_is_signed = DefinitionType::Signed;
        const bool value_is_negative = val < (TValue)0;
        
        TValue value_copy = val;
        if (cast_is_signed)
        {
            const bool value_is_signed = DefinitionValueType::Signed;
            test::Byte<alloc_size> tmp_last_bit(val);
            bool cast_is_negative = false;
            const bool last_bit = 
                (*(tmp_last_bit.ReverseBegin()) & 0x80) != (std::uint8_t)0;
            if (value_is_signed && (val_alloc_size < alloc_size))
            {
                cast_is_negative = value_is_negative;
            }
            if (cast_is_negative || last_bit)
            {
                value_copy = ~val;
                value_copy += 1;
                out_ref.Flag().SetNegative();
            }
            test::Byte<val_alloc_size> val_byte{value_copy};

            auto& raw = static_cast<RawType&>(out_ref);
            auto raw_it = raw.Begin();
            for (auto val_it = val_byte.Begin(); raw_it != raw.End() && 
                val_it != val_byte.End(); ++raw_it, ++val_it)
            {
                *raw_it = *val_it;
            }
        }
        else if (value_is_negative)
        { 
            value_copy = ~val;
            value_copy += 1;

            test::Byte<val_alloc_size> val_byte(value_copy);
            auto& raw = static_cast<RawType&>(out_ref);
            auto raw_it = raw.Begin();
            for (auto val_it = val_byte.Begin(); raw_it != raw.End() && 
                val_it != val_byte.End(); ++raw_it, ++val_it)
            {
                *raw_it = *val_it;
            }

            out_ref = ~out_ref;
            
            ++out_ref;
        }
        else
        {
            test::Byte<val_alloc_size> val_byte(val);
            auto& raw = static_cast<RawType&>(out_ref);
            auto raw_it = raw.Begin();
            for (auto val_it = val_byte.Begin(); raw_it != raw.End() && 
                val_it != val_byte.End(); ++raw_it, ++val_it)
            {
                *raw_it = *val_it;
            }
        }
    }
    template<std::size_t N = 1, typename TValue>
    static FormatType<N> From(const TValue& val)
    {
        TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
            "From<%s>(val=%s)", TEST_SYS_DEBUG_TARGS_NAME_STR(
                TEST_SYS_DEBUG_TV_TYPE(std::size_t, N),
                TEST_SYS_DEBUG_T_TYPE(TValue)), 
                TEST_SYS_DEBUG_VALUE_STR(0, val));
        
        FormatType<N> res;
        From<N>(val, res);
        return res;
    }
public:
    template<typename TValue, std::size_t N>
    static TValue To(const FormatType<N>& fmt)
    {
        TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
            "To<%s>(fmt=%p)", TEST_SYS_DEBUG_TARGS_NAME_STR(
                TEST_SYS_DEBUG_T_TYPE(TValue),
                TEST_SYS_DEBUG_TV_TYPE(std::size_t, N)), &fmt);
        
        typedef test::integer::fmt::Definition<TValue, 2> DefinitionValueType;
        typedef typename FormatType<N>::BaseType RawType;
        typedef test::integer::Format<TValue, 2, 1> ValueFormatType;
        typedef typename ValueFormatType::BaseType ValueRawType;
        
        const bool cast_is_signed = DefinitionType::Signed;
        const bool value_is_signed = DefinitionValueType::Signed;

        ValueFormatType val_fmt;
        auto& res_raw = static_cast<ValueRawType&>(val_fmt);
        auto& raw = static_cast<const RawType&>(fmt);
        auto raw_it = raw.Begin();
        for (auto res_it = res_raw.Begin(); raw_it != raw.End() && 
            res_it != res_raw.End(); ++raw_it, ++res_it)
        {
            *res_it = *raw_it;
        }
        if (fmt.Flag().IsNegative())
        {
            val_fmt = ~val_fmt;
            ++val_fmt;
        }
        return res_raw.template CastTo<TValue>();
    }
public:
    Make() = delete;
};

template<typename TInt>
class Make<TInt, 8>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::integer::fmt::Make<TInt, 8>> DebugType;
public:
    typedef test::integer::fmt::Definition<TInt, 8> DefinitionType;
    template<std::size_t N>
    using FormatType = test::integer::Format<TInt, 8, N>;
public:
    template<std::size_t N = 1, typename TValue>
    static FormatType<N> From(const TValue& val)
    {
        TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
            "From<%s>(val=%s)", TEST_SYS_DEBUG_TARGS_NAME_STR(
                TEST_SYS_DEBUG_TV_TYPE(std::size_t, N),
                TEST_SYS_DEBUG_T_TYPE(TValue)), 
                TEST_SYS_DEBUG_VALUE_STR(0, val));
        
        //todo implementing
        return {};
    }
public:
    template<typename TValue, std::size_t N>
    static TValue To(const FormatType<N>& fmt)
    {
        TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
            "To<%s>(fmt=%p)", TEST_SYS_DEBUG_TARGS_NAME_STR(
                TEST_SYS_DEBUG_T_TYPE(TValue),
                TEST_SYS_DEBUG_TV_TYPE(std::size_t, N)), &fmt);
        
        //todo implementing
        return 0;
    }
public:
    Make() = delete;
};

template<typename TInt>
class Make<TInt, 10>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::integer::fmt::Make<TInt, 10>> DebugType;
public:
    typedef test::integer::fmt::Definition<TInt, 10> DefinitionType;
    template<std::size_t N>
    using FormatType = test::integer::Format<TInt, 10, N>;
public:
    template<std::size_t N = 1, typename TValue>
    static FormatType<N> From(const TValue& val)
    {
        TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
            "From<%s>(val=%s)", TEST_SYS_DEBUG_TARGS_NAME_STR(
                TEST_SYS_DEBUG_TV_TYPE(std::size_t, N),
                TEST_SYS_DEBUG_T_TYPE(TValue)), 
                TEST_SYS_DEBUG_VALUE_STR(0, val));
        
        //todo implementing
        return {};
    }
public:
    template<typename TValue, std::size_t N>
    static TValue To(const FormatType<N>& fmt)
    {
        TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
            "To<%s>(fmt=%p)", TEST_SYS_DEBUG_TARGS_NAME_STR(
                TEST_SYS_DEBUG_T_TYPE(TValue),
                TEST_SYS_DEBUG_TV_TYPE(std::size_t, N)), &fmt);
        
        //todo implementing
        return 0;
    }
public:
    Make() = delete;
};

} //!fmt

} //!integer

} //!test

#endif //!TEST_INTEGER_FMT_MAKE_H_
