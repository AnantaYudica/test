#ifndef TEST_BYTE_BASE_H_
#define TEST_BYTE_BASE_H_

#include "../System.h"
#include "../Queue.h"
#include "Operator.h"
#include "Iterator.h"
#include "Order.h"

#include <cstdlib>
#include <cstdint>
#include <cstring>

namespace test::byte
{
template<std::size_t N, bool Sign>
class Base;
}

#ifndef TEST_BYTE_BASE_DLEVEL

#define TEST_BYTE_BASE_DLEVEL 2

#endif //!TEST_BYTE_BASE_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::type::Value<std::size_t, N>,\
    test::sys::dbg::type::Value<bool, Sign>

template<std::size_t N, bool Sign>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_BYTE_BASE_DLEVEL, 
    "test::byte::Base", 
    test::byte::Base<N, Sign>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace byte
{

template<std::size_t N, bool Sign>
class Base 
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::byte::Base<N, Sign>> DebugType;
public:
    typedef test::byte::Operator OperatorType;
public:
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    using IteratorType = test::byte::Iterator<std::uint8_t*, TCast, NStep>;
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    using ConstIteratorType = test::byte::Iterator<const std::uint8_t*, 
        TCast, NStep>;
private:
    std::uint8_t m_block[N];
protected:
    Base();
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    Base(ConstIteratorType<TCast, NStep> begin, ConstIteratorType<TCast, NStep> end);
    Base(std::uint8_t* begin, std::uint8_t* end);
public:
    ~Base();
public:
    Base(const Base<N, Sign>& cpy);
    Base(Base<N, Sign>&& mov);
public:
    Base<N, Sign>& operator=(const Base<N, Sign>& cpy);
    Base<N, Sign>& operator=(Base<N, Sign>&& mov);
public:
    std::size_t Size() const;
public:
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    IteratorType<TCast, NStep> Begin();
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    IteratorType<TCast, NStep> End();
public:
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    ConstIteratorType<TCast, NStep> Begin() const;
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    ConstIteratorType<TCast, NStep> End() const;
public:
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    IteratorType<TCast, NStep> ReverseBegin();
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    IteratorType<TCast, NStep> ReverseEnd();
public:
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    ConstIteratorType<TCast, NStep> ReverseBegin() const;
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    ConstIteratorType<TCast, NStep> ReverseEnd() const;
public:
    template<typename T>
    T CastTo(const std::size_t& off = 0) const;
public:
    std::uint8_t* Get();
    const std::uint8_t* Get() const;
public:
    std::uint8_t& operator[](const std::size_t& index);
    std::uint8_t operator[](const std::size_t& index) const;
public:
    bool operator==(const Base<N, Sign>& other) const;
public:
    bool operator!=(const Base<N, Sign>& other) const;
};

template<std::size_t N, bool Sign>
Base<N, Sign>::Base() :
    m_block{}
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

    OperatorType::GetInstance().SetZero(m_block, N);
}

template<std::size_t N, bool Sign>
template<typename TCast, std::size_t NStep>
Base<N, Sign>::Base(ConstIteratorType<TCast, NStep> begin, ConstIteratorType<TCast, NStep> end)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor<%s>(begin=%p, end=%p)",
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_T_TYPE(TCast),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NStep)),
        &*begin, &*end);

    OperatorType::GetInstance().SetZero(m_block, N);
    OperatorType::GetInstance().Set(Begin(), End(), begin, end);
}

template<std::size_t N, bool Sign>
Base<N, Sign>::~Base()
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

}

template<std::size_t N, bool Sign>
Base<N, Sign>::Base(const Base<N, Sign>& cpy) :
    m_block{}
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);

    OperatorType::GetInstance().SetZero(m_block, N);
    OperatorType::GetInstance().Set(Begin(), End(), cpy.Begin(), cpy.End());
}

template<std::size_t N, bool Sign>
Base<N, Sign>::Base(Base<N, Sign>&& mov) :
    m_block{}
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);
    
    OperatorType::GetInstance().SetZero(m_block, N);
    OperatorType::GetInstance().Set(Begin(), End(), mov.Begin(), mov.End());
    OperatorType::GetInstance().SetZero(mov.Get(), _N);
}

template<std::size_t N, bool Sign>
Base<N, Sign>& Base<N, Sign>::operator=(const Base<N, Sign>& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);

    OperatorType::GetInstance().Set(Begin(), End(), cpy.Begin(), cpy.End());
    return *this;
}

template<std::size_t N, bool Sign>
Base<N, Sign>& Base<N, Sign>::operator=(Base<N, Sign>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);
    
    OperatorType::GetInstance().Set(Begin(), End(), mov.Begin(), mov.End());
    OperatorType::GetInstance().SetZero(mov.Get(), _N);
    return *this;
}

template<std::size_t N, bool Sign>
std::size_t Base<N, Sign>::Size() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Size() const");
    
    return N;
}

template<std::size_t N, bool Sign>
template<typename TCast, std::size_t NStep>
typename Base<N, Sign>::template IteratorType<TCast, NStep> 
Base<N, Sign>::Begin()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "Begin<%s>()",
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_T_TYPE(TCast),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NStep)));
    
    const auto op = OperatorType::GetInstance().GetOrder();
    return {m_block, 0, N, op.Begin(0, N, NStep), op};
}

template<std::size_t N, bool Sign>
template<typename TCast, std::size_t NStep>
typename Base<N, Sign>::template IteratorType<TCast, NStep>  
Base<N, Sign>::End()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "End<%s>()",
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_T_TYPE(TCast),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NStep)));
    
    const auto op = OperatorType::GetInstance().GetOrder();
    return {m_block, 0, N, op.End(0, N, NStep), op};
}

template<std::size_t N, bool Sign>
template<typename TCast, std::size_t NStep>
typename Base<N, Sign>::template ConstIteratorType<TCast, NStep> 
Base<N, Sign>::Begin() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "Begin<%s>() const",
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_T_TYPE(TCast),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NStep)));
    
    return const_cast<Base<N, Sign>*>(this)->template Begin<TCast, NStep>();
}

template<std::size_t N, bool Sign>
template<typename TCast, std::size_t NStep>
typename Base<N, Sign>::template ConstIteratorType<TCast, NStep> 
Base<N, Sign>::End() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "End<%s>() const",
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_T_TYPE(TCast),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NStep)));
    
    return const_cast<Base<N, Sign>*>(this)->template End<TCast, NStep>();
}

template<std::size_t N, bool Sign>
template<typename TCast, std::size_t NStep>
typename Base<N, Sign>::template IteratorType<TCast, NStep> 
Base<N, Sign>::ReverseBegin()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "ReverseBegin<%s>()",
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_T_TYPE(TCast),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NStep)));
    
    const auto op = OperatorType::GetInstance().GetReverseOrder();
    return {m_block, 0, N, op.Begin(0, N, NStep), op};
}

template<std::size_t N, bool Sign>
template<typename TCast, std::size_t NStep>
typename Base<N, Sign>::template IteratorType<TCast, NStep> 
Base<N, Sign>::ReverseEnd()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "ReverseEnd<%s>()",
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_T_TYPE(TCast),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NStep)));
    
    const auto op = OperatorType::GetInstance().GetReverseOrder();
    return {m_block, 0, N, op.End(0, N, NStep), op};
}

template<std::size_t N, bool Sign>
template<typename TCast, std::size_t NStep>
typename Base<N, Sign>::template ConstIteratorType<TCast, NStep> 
Base<N, Sign>::ReverseBegin() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "ReverseBegin<%s>() const",
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_T_TYPE(TCast),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NStep)));
    
    return const_cast<Base<N, Sign>*>(this)->
        template ReverseBegin<TCast, NStep>();
}

template<std::size_t N, bool Sign>
template<typename TCast, std::size_t NStep>
typename Base<N, Sign>::template ConstIteratorType<TCast, NStep> 
Base<N, Sign>::ReverseEnd() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "ReverseEnd<%s>() const",
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_T_TYPE(TCast),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NStep)));
    
    return const_cast<Base<N, Sign>*>(this)->
        template ReverseEnd<TCast, NStep>();
}

template<std::size_t N, bool Sign>
template<typename T>
T Base<N, Sign>::CastTo(const std::size_t& off) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "CastTo<%s>(off=%zu) const",
        TEST_SYS_DEBUG_T_NAME_STR(T), off);
    
    T ret;
    std::memset(&ret, 0, sizeof(T));
    const std::size_t size = (off >= N ? N : off);
    OperatorType::GetInstance().Set((std::uint8_t*)&ret, 
        sizeof(T), Begin() + size, End());
    return ret;
}

template<std::size_t N, bool Sign>
std::uint8_t* Base<N, Sign>::Get()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Get()");
    
    return m_block;
}

template<std::size_t N, bool Sign>
const std::uint8_t* Base<N, Sign>::Get() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Get() const");
    
    return m_block;
}

template<std::size_t N, bool Sign>
std::uint8_t& Base<N, Sign>::operator[](const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator[](index=%zu)", index);
    
    static std::uint8_t tmp;
    tmp = 0;
    if (index >= N) return tmp;
    return *(Begin() + index);
}

template<std::size_t N, bool Sign>
std::uint8_t Base<N, Sign>::operator[](const std::size_t& index) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator[](index=%zu)", index);
    
    return const_cast<Base<N, Sign>*>(this)->operator[](index);
}

template<std::size_t N, bool Sign>
bool Base<N, Sign>::operator==(const Base<N, Sign>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p)", &other);
    
    return OperatorType::GetInstance().Equal(Begin(), End(), 
        other.Begin(), other.End());
}

template<std::size_t N, bool Sign>
bool Base<N, Sign>::operator!=(const Base<N, Sign>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p)", &other);
    
    return !(*this == other);
}

} //!byte

} //!test

#endif //!TEST_BYTE_BASE_H_
