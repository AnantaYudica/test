#ifndef TEST_INTEGER_RAW_H_
#define TEST_INTEGER_RAW_H_

#include "../System.h"
#include "Flag.h"
#include "../Byte.h"

#include <cstddef>
#include <cstdint>
#include <type_traits>
#include <utility>

namespace test::integer
{
template<std::size_t N>
class Raw;  
}

#ifndef TEST_INTEGER_RAW_DLEVEL

#define TEST_INTEGER_RAW_DLEVEL 2

#endif //!TEST_INTEGER_RAW_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::type::Value<std::size_t , N>

template<std::size_t N>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_INTEGER_RAW_DLEVEL, 
    "test::integer::Raw", 
    test::integer::Raw<N>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace integer
{

template<std::size_t N>
class Raw : public test::Byte<N>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::integer::Raw<N>> DebugType;
public:
    typedef test::integer::Flag FlagType;
    typedef typename FlagType::ValueType FlagValueType;
private:
    test::integer::Flag m_flag;
public:
    Raw(const FlagValueType& flag_val);
    Raw(const FlagType& flag);
    template<std::size_t N_>
    Raw(const FlagValueType& flag_val, const test::Byte<N_>& byte_val);
    template<std::size_t N_>
    Raw(const FlagType& flag_val, const test::Byte<N_>& byte_val);
    template<std::size_t N_>
    Raw(const FlagValueType& flag_val, test::Byte<N_>&& byte_rval);
    template<std::size_t N_>
    Raw(const FlagType& flag_val, test::Byte<N_>&& byte_rval);
    ~Raw();
public:
    template<std::size_t N_>
    Raw(const Raw<N_>& cpy);
    template<std::size_t N_>
    Raw(Raw<N_>&& mov);
public:
    template<std::size_t N_>
    Raw<N>& operator=(const Raw<N_>& cpy);
    template<std::size_t N_>
    Raw<N>& operator=(Raw<N_>&& mov);
    template<std::size_t N_>
    Raw<N>& operator=(const test::Byte<N_>& byte_val);
    template<std::size_t N_>
    Raw<N>& operator=(test::Byte<N_>&& byte_rval);
public:
    FlagType& Flag();
    FlagType Flag() const;
};

template<std::size_t N>
Raw<N>::Raw(const FlagValueType& flag_val) :
    test::Byte<N>(),
    m_flag(flag_val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(flag_val=%s)", TEST_SYS_DEBUG_VALUE_STR(0, flag_val));
    
}

template<std::size_t N>
Raw<N>::Raw(const FlagType& flag) :
    test::Byte<N>(),
    m_flag(flag)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(flag=%s)", TEST_SYS_DEBUG_VALUE_STR(0, flag));
    
}

template<std::size_t N>
template<std::size_t N_>
Raw<N>::Raw(const FlagValueType& flag_val, const test::Byte<N_>& byte_val) :
    test::Byte<N>(byte_val),
    m_flag(flag_val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor<%s>>flag_val=%s, byte_val=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, N_)),
        TEST_SYS_DEBUG_VALUE_STR(0, flag_val), &byte_val);
    
}

template<std::size_t N>
template<std::size_t N_>
Raw<N>::Raw(const FlagType& flag, const test::Byte<N_>& byte_val) :
    test::Byte<N>(byte_val),
    m_flag(flag)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor<%s>(flag=%s, byte_val=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, N_)),
        TEST_SYS_DEBUG_VALUE_STR(0, flag), &byte_val);
    
}

template<std::size_t N>
template<std::size_t N_>
Raw<N>::Raw(const FlagValueType& flag_val, test::Byte<N_>&& byte_rval) :
    test::Byte<N>(std::forward<test::Byte<N_>>(byte_rval)),
    m_flag(flag_val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor<%s>(flag_val=%s, byte_rval=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, N_)),
        TEST_SYS_DEBUG_VALUE_STR(0, flag_val), &byte_rval);
    
}

template<std::size_t N>
template<std::size_t N_>
Raw<N>::Raw(const FlagType& flag, test::Byte<N_>&& byte_rval) :
    test::Byte<N>(std::forward<test::Byte<N_>>(byte_rval)),
    m_flag(flag)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor<%s>(flag=%s, byte_rval=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, N_)),
        TEST_SYS_DEBUG_VALUE_STR(0, flag), &byte_rval);

}

template<std::size_t N>
Raw<N>::~Raw()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");
}

template<std::size_t N>
template<std::size_t N_>
Raw<N>::Raw(const Raw<N_>& cpy) :
    test::Byte<N>(cpy),
    m_flag(cpy.Flag())
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor<%s>(cpy=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, N_)), &cpy);

}

template<std::size_t N>
template<std::size_t N_>
Raw<N>::Raw(Raw<N_>&& mov) :
    test::Byte<N>(std::move(mov)),
    m_flag(std::move(mov.Flag()))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor<%s>(mov=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, N_)), &mov);

}

template<std::size_t N>
template<std::size_t N_>
Raw<N>& Raw<N>::operator=(const Raw<N_>& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment<%s>(cpy=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, N_)), &cpy);

    test::Byte<N>::operator=(cpy);
    m_flag = cpy.Flag();
    return *this;
}

template<std::size_t N>
template<std::size_t N_>
Raw<N>& Raw<N>::operator=(Raw<N_>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment<%s>(mov=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, N_)), &mov);

    test::Byte<N>::operator=(std::move(mov));
    m_flag = std::move(mov.Flag());
    return *this;
}

template<std::size_t N>
template<std::size_t N_>
Raw<N>& Raw<N>::operator=(const test::Byte<N_>& byte_val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "operator=<%s>(byte_val=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, N_)), &byte_val);

    test::Byte<N>::operator=(byte_val);
    return *this;
}

template<std::size_t N>
template<std::size_t N_>
Raw<N>& Raw<N>::operator=(test::Byte<N_>&& byte_rval)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "operator=<%s>(byte_rval=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, N_)), &byte_rval);

    test::Byte<N>::operator=(std::move(byte_rval));
    return *this;
}

template<std::size_t N>
typename Raw<N>::FlagType& Raw<N>::Flag()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Flag()");
    
    return m_flag;
}

template<std::size_t N>
typename Raw<N>::FlagType Raw<N>::Flag() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Flag() const");
    
    return m_flag;
}

} //!integer

} //!test

#endif //!TEST_INTEGER_RAW_H_
