#ifndef TEST_MSG_FMT_PARAM_PRECISION_H_
#define TEST_MSG_FMT_PARAM_PRECISION_H_

#include "../Parameter.h"

#include <utility>
#include <cstdarg>

namespace test
{
namespace msg
{
namespace fmt
{
namespace param
{

template<typename TChar>
class Precision : public test::msg::fmt::Parameter<TChar>
{
public:
    typedef test::msg::fmt::Parameter<TChar> ParameterBaseType;
    typedef typename ParameterBaseType::StatusType StatusType;
    typedef typename ParameterBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef int ValueType;
private:
    ValueType m_value;
public:
    Precision();
    Precision(const ValueType& val);
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
        va_list args) override;
    std::size_t Load(std::size_t size, ...) override;
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
    m_value(0)
{}

template<typename TChar>
Precision<TChar>::Precision(const ValueType& val) :
    ParameterBaseType(StatusType::set_value),
    m_value(val)
{}

template<typename TChar>
Precision<TChar>::~Precision()
{
    m_value = 0;
}

template<typename TChar>
Precision<TChar>::Precision(const Precision<TChar>& cpy) :
    ParameterBaseType(cpy),
    m_value(cpy.m_value)
{}

template<typename TChar>
Precision<TChar>::Precision(Precision<TChar>&& mov) :
    ParameterBaseType(std::move(mov)),
    m_value(mov.m_value)
{
    mov.m_value = 0;
}

template<typename TChar>
Precision<TChar>& Precision<TChar>::operator=(const Precision<TChar>& cpy)
{
    ParameterBaseType::operator=(cpy);
    m_value = cpy.m_value;
    return *this;
}

template<typename TChar>
Precision<TChar>& Precision<TChar>::operator=(Precision<TChar>&& mov)
{
    ParameterBaseType::operator=(std::move(mov));
    m_value = mov.m_value;
    mov.m_value = 0;
    return *this;
}

template<typename TChar>
std::size_t Precision<TChar>::VLoad(std::size_t, std::size_t index, va_list args)
{
    auto& status = ParameterBaseType::GetStatus();
    if (status.IsSetValue()) return index;
    m_value = va_arg(args, ValueType);
    status.SetValue();
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
typename Precision<TChar>::ValueType Precision<TChar>::GetValue() const
{
    return m_value;
}

template<typename TChar>
void Precision<TChar>::Unset()
{
    m_value = 0;
    ParameterBaseType::GetStatus().UnsetValue();
}

template<typename TChar>
bool Precision<TChar>::IsSet() const
{
    return ParameterBaseType::GetStatus().IsSetValue();
}

} //!param

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_PARAM_PRECISION_H_