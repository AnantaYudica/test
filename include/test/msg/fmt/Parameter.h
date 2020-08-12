#ifndef TEST_MSG_FMT_PARAMETER_H_
#define TEST_MSG_FMT_PARAMETER_H_

#include "../../out/Interface.h"
#include "../../Pointer.h"
#include "Status.h"

#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <utility>

namespace test
{
namespace msg
{
namespace fmt
{

template<typename TChar, typename... TParam>
class Parameter
{
public:
    typedef test::msg::fmt::Status<std::uint8_t> StatusType;
    typedef typename StatusType::ValueType ValueStatusType;
    typedef typename StatusType::IntegerValueType IntegerValueStatusType;
    typedef test::out::Interface<TChar> OutputInterfaceType;
private:
    test::Pointer<StatusType> m_status;
protected:
    Parameter();
    Parameter(test::Pointer<StatusType>&& status);
public:
    virtual ~Parameter();
protected:
    Parameter(const Parameter<TChar, TParam...>& cpy);
    Parameter(Parameter<TChar, TParam...>&& mov);
protected:
    Parameter<TChar, TParam...>& 
        operator=(const Parameter<TChar, TParam...>& cpy);
    Parameter<TChar, TParam...>& operator=(Parameter<TChar, TParam...>&& mov);
protected:
    StatusType& GetStatus();
    StatusType GetStatus() const;
protected:
    test::Pointer<StatusType> GetStatusPointer();
public:
    virtual std::size_t VLoad(std::size_t size, std::size_t index, 
        va_list& args) = 0;
    virtual std::size_t Load(std::size_t size, ...) = 0;
public:
    virtual typename OutputInterfaceType::SizeType
        Output(OutputInterfaceType& out) = 0;
public:
    virtual void Unset() = 0;
public:
    virtual bool IsSet() const = 0;
public:
    bool IsGood() const;
    bool IsBad() const;
public:
    void Reset();
public:
    typename StatusType::IntegerValueType GetBadCode() const;
};

template<typename TChar, typename... TParam>
Parameter<TChar, TParam...>::Parameter() :
    m_status()
{}

template<typename TChar, typename... TParam>
Parameter<TChar, TParam...>::Parameter(test::Pointer<StatusType>&& status) :
    m_status(std::move(status))
{}

template<typename TChar, typename... TParam>
Parameter<TChar, TParam...>::~Parameter()
{}

template<typename TChar, typename... TParam>
Parameter<TChar, TParam...>::
    Parameter(const Parameter<TChar, TParam...>& cpy) :
        m_status(cpy.m_status)
{}

template<typename TChar, typename... TParam>
Parameter<TChar, TParam...>::Parameter(Parameter<TChar, TParam...>&& mov) :
    m_status(std::move(mov.m_status))
{}

template<typename TChar, typename... TParam>
Parameter<TChar, TParam...>& 
Parameter<TChar, TParam...>::operator=(const Parameter<TChar, TParam...>& cpy)
{
    m_status = cpy.m_status;
    return *this;
}

template<typename TChar, typename... TParam>
Parameter<TChar, TParam...>& 
Parameter<TChar, TParam...>::operator=(Parameter<TChar, TParam...>&& mov)
{
    m_status = std::move(mov.m_status);
    return *this;
}

template<typename TChar, typename... TParam>
typename Parameter<TChar, TParam...>::StatusType& 
Parameter<TChar, TParam...>::GetStatus()
{
    return *m_status;
}

template<typename TChar, typename... TParam>
typename Parameter<TChar, TParam...>::StatusType 
Parameter<TChar, TParam...>::GetStatus() const
{
    return {*m_status};
}

template<typename TChar, typename... TParam>
test::Pointer<typename Parameter<TChar, TParam...>::StatusType> 
Parameter<TChar, TParam...>::GetStatusPointer()
{
    return m_status;
}

template<typename TChar, typename... TParam>
bool Parameter<TChar, TParam...>::IsGood() const
{
    return (*m_status).IsGood();
}

template<typename TChar, typename... TParam>
bool Parameter<TChar, TParam...>::IsBad() const
{
    return (*m_status).IsBad();
}

template<typename TChar, typename... TParam>
void Parameter<TChar, TParam...>::Reset()
{
    Unset();
    m_status->Reset();
}

template<typename TChar, typename... TParam>
typename Parameter<TChar, TParam...>::StatusType::IntegerValueType 
Parameter<TChar, TParam...>::GetBadCode() const
{
    return (*m_status).GetBadCode();
}

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_PARAMETER_H_
