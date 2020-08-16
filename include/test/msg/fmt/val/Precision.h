#ifndef TEST_MSG_FMT_VAL_PRECISION_H_
#define TEST_MSG_FMT_VAL_PRECISION_H_

#include "../Parameter.h"
#include "Status.h"

#include <utility>
#include <cstdarg>

namespace test
{
namespace msg
{
namespace fmt
{
namespace val
{

template<typename TChar>
class Precision : public test::msg::fmt::Parameter<TChar>
{
public:
    typedef test::msg::fmt::Parameter<TChar> ParameterBaseType;
    typedef typename ParameterBaseType::StatusType StatusType;
    typedef typename ParameterBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename ParameterBaseType::StatusPointerType StatusPointerType;
    typedef test::msg::fmt::val::Status ValueStatusType;
    typedef int ValueType;
private:
    ValueStatusType m_value_status;
    ValueType m_value;
public:
    Precision();
    Precision(const ValueType& val);
protected:
    Precision(StatusPointerType&& status);
    Precision(StatusPointerType&& status, const ValueType& val);
public:
    ~Precision();
public:
    Precision(const Precision<TChar>& cpy);
    Precision(Precision<TChar>&& mov);
public:
    Precision<TChar>& operator=(const Precision<TChar>& cpy);
    Precision<TChar>& operator=(Precision<TChar>&& mov);
public:
    std::size_t VLoad(std::size_t size, std::size_t index, 
        va_list& args) override;
    std::size_t Load(std::size_t size, ...) override;
public:
    typename OutputInterfaceType::SizeType
        Output(OutputInterfaceType& out) override;
public:
    ValueType GetValue() const;
public:
    void Unset();
public:
    bool IsSet() const;
};

template<typename TChar>
Precision<TChar>::Precision() :
    ParameterBaseType(),
    m_value_status(0),
    m_value(0)
{}

template<typename TChar>
Precision<TChar>::Precision(const ValueType& val) :
    ParameterBaseType(),
    m_value_status(ValueStatusType::default_value),
    m_value(val)
{}

template<typename TChar>
Precision<TChar>::Precision(StatusPointerType&& status) :
    ParameterBaseType(std::forward<StatusPointerType>(status)),
    m_value_status(0),
    m_value(0)
{}

template<typename TChar>
Precision<TChar>::Precision(StatusPointerType&& status, const ValueType& val) :
    ParameterBaseType(std::forward<StatusPointerType>(status)),
    m_value_status(ValueStatusType::default_value),
    m_value(val)
{}

template<typename TChar>
Precision<TChar>::~Precision()
{
    m_value_status.Reset();
    m_value = 0;
}

template<typename TChar>
Precision<TChar>::Precision(const Precision<TChar>& cpy) :
    ParameterBaseType(cpy),
    m_value_status(cpy.m_value_status),
    m_value(cpy.m_value)
{}

template<typename TChar>
Precision<TChar>::Precision(Precision<TChar>&& mov) :
    ParameterBaseType(std::move(mov)),
    m_value_status(std::move(mov.m_value_status)),
    m_value(mov.m_value)
{
    if (!mov.m_value_status.IsDefaultValue())
        mov.m_value = 0;
}

template<typename TChar>
Precision<TChar>& Precision<TChar>::operator=(const Precision<TChar>& cpy)
{
    ParameterBaseType::operator=(cpy);
    m_value_status = cpy.m_value_status;
    m_value = cpy.m_value;
    return *this;
}

template<typename TChar>
Precision<TChar>& Precision<TChar>::operator=(Precision<TChar>&& mov)
{
    ParameterBaseType::operator=(std::move(mov));
    m_value_status = std::move(mov.m_value_status);
    m_value = mov.m_value;
    if (!mov.m_value_status.IsDefaultValue())
        mov.m_value = 0;
    return *this;
}

template<typename TChar>
std::size_t Precision<TChar>::VLoad(std::size_t, std::size_t index, 
    va_list& args)
{
    if (m_value_status.IsSetValue()) return index;
    m_value = va_arg(args, ValueType);
    m_value_status.SetValue();
    return index + 1;
}

template<typename TChar>
std::size_t Precision<TChar>::Load(std::size_t size, ...)
{
    va_list args;
    va_start(args, size);
    const auto last_index = VLoad(size, 0, args);
    va_end(args);
    return last_index;
}

template<typename TChar>
typename Precision<TChar>::OutputInterfaceType::SizeType
Precision<TChar>::Output(OutputInterfaceType&)
{
    return 0;
}

template<typename TChar>
typename Precision<TChar>::ValueType Precision<TChar>::GetValue() const
{
    return m_value;
}

template<typename TChar>
void Precision<TChar>::Unset()
{
    m_value_status.UnsetValue();
    if (!m_value_status.IsSetValue())
    {
        m_value = 0;
    }
}

template<typename TChar>
bool Precision<TChar>::IsSet() const
{
    return m_value_status.IsSetValue();
}

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_PRECISION_H_