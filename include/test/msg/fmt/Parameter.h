#ifndef TEST_MSG_FMT_PARAMETER_H_
#define TEST_MSG_FMT_PARAMETER_H_

#include "../../out/Interface.h"
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

template<typename TChar>
class Parameter
{
public:
    typedef test::msg::fmt::Status<std::uint8_t> StatusType;
    typedef typename StatusType::ValueType ValueStatusType;
    typedef typename StatusType::IntegerValueType IntegerValueStatusType;
    typedef test::out::Interface<TChar> OutputInterfaceType;
private:
    StatusType m_status;
protected:
    Parameter();
    Parameter(const IntegerValueStatusType& val);
public:
    virtual ~Parameter();
protected:
    Parameter(const Parameter<TChar>& cpy);
    Parameter(Parameter<TChar>&& mov);
protected:
    Parameter<TChar>& operator=(const Parameter<TChar>& cpy);
    Parameter<TChar>& operator=(Parameter<TChar>&& mov);
public:
    virtual std::size_t VLoad(std::size_t size, std::size_t index, 
        va_list args) = 0;
    virtual std::size_t Load(std::size_t size, ...) = 0;
protected:
    StatusType& GetStatus();
    StatusType GetStatus() const;
};

template<typename TChar>
Parameter<TChar>::Parameter() :
    m_status()
{}

template<typename TChar>
Parameter<TChar>::Parameter(const IntegerValueStatusType& val) :
    m_status(val)
{}

template<typename TChar>
Parameter<TChar>::~Parameter()
{
    m_status.Reset();
}

template<typename TChar>
Parameter<TChar>::Parameter(const Parameter<TChar>& cpy) :
    m_status(cpy.m_status)
{}

template<typename TChar>
Parameter<TChar>::Parameter(Parameter<TChar>&& mov) :
    m_status(std::move(mov.m_status))
{}

template<typename TChar>
Parameter<TChar>& Parameter<TChar>::operator=(const Parameter<TChar>& cpy)
{
    m_status = cpy.m_status;
    return *this;
}

template<typename TChar>
Parameter<TChar>& Parameter<TChar>::operator=(Parameter<TChar>&& mov)
{
    m_status = std::move(mov.m_status);
    return *this;
}

template<typename TChar>
typename Parameter<TChar>::StatusType& 
Parameter<TChar>::GetStatus()
{
    return m_status;
}

template<typename TChar>
typename Parameter<TChar>::StatusType 
Parameter<TChar>::GetStatus() const
{
    return {m_status};
}

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_PARAMETER_H_
