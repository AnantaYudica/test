#ifndef TEST_MSG_FMT_VAL_SPECIFIER_H_
#define TEST_MSG_FMT_VAL_SPECIFIER_H_

#include "../Parameter.h"
#include "Status.h"

#include <utility>

namespace test
{
namespace msg
{
namespace fmt
{
namespace val
{

template<typename TChar>
class Specifier :
    public test::msg::fmt::Parameter<TChar>
{
public:
    typedef test::msg::fmt::Parameter<TChar> ParameterBaseType;
    typedef typename ParameterBaseType::StatusType StatusType;
    typedef typename ParameterBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename ParameterBaseType::StatusPointerType StatusPointerType;
    typedef test::msg::fmt::val::Status ValueStatusType;
    typedef typename ValueStatusType::IntegerValueType 
        ValueStatusIntegerValueType;
private:
    ValueStatusType m_value_status;
protected:
    Specifier();
    Specifier(const ValueStatusIntegerValueType& val);
protected:
    Specifier(StatusPointerType&& status);
    Specifier(StatusPointerType&& status, 
        const ValueStatusIntegerValueType& val);
public:
    virtual ~Specifier() = default;
protected:
    Specifier(const Specifier<TChar>& cpy);
    Specifier(Specifier<TChar>&& mov);
protected:
    Specifier<TChar>& operator=(const Specifier<TChar>& cpy);
    Specifier<TChar>& operator=(Specifier<TChar>&& mov);
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
protected:
    ValueStatusType& GetValueStatus();
    const ValueStatusType& GetValueStatus() const;
};

template<typename TChar>
Specifier<TChar>::Specifier() :
    ParameterBaseType(),
    m_value_status(0)
{}

template<typename TChar>
Specifier<TChar>::Specifier(const ValueStatusIntegerValueType& val) :
    ParameterBaseType(),
    m_value_status(val)
{}

template<typename TChar>
Specifier<TChar>::Specifier(StatusPointerType&& status) :
    ParameterBaseType(std::forward<StatusPointerType>(status)),
    m_value_status(0)
{}

template<typename TChar>
Specifier<TChar>::Specifier(StatusPointerType&& status, 
    const ValueStatusIntegerValueType& val) :
        ParameterBaseType(std::forward<StatusPointerType>(status)),
        m_value_status(val)
{}

template<typename TChar>
Specifier<TChar>::Specifier(const Specifier<TChar>& cpy) :
    ParameterBaseType(cpy),
    m_value_status(cpy.m_value_status)
{}

template<typename TChar>
Specifier<TChar>::Specifier(Specifier<TChar>&& mov) :
    ParameterBaseType(std::move(mov)),
    m_value_status(std::move(mov.m_value_status))
{}

template<typename TChar>
Specifier<TChar>& Specifier<TChar>::operator=(const Specifier<TChar>& cpy)
{
    ParameterBaseType::operator=(cpy);
    m_value_status = cpy.m_value_status;
    return *this;
}

template<typename TChar>
Specifier<TChar>& Specifier<TChar>::operator=(Specifier<TChar>&& mov)
{
    ParameterBaseType::operator=(std::move(mov));
    m_value_status = std::move(mov.m_value_status);
    return *this;
}

template<typename TChar>
typename Specifier<TChar>::ValueStatusType& Specifier<TChar>::GetValueStatus()
{
    return m_value_status;
}

template<typename TChar>
const typename Specifier<TChar>::ValueStatusType& 
Specifier<TChar>::GetValueStatus() const
{
    return m_value_status;
}

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_SPECIFIER_H_