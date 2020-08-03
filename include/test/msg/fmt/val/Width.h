#ifndef TEST_MSG_FMT_VAL_WIDTH_H_
#define TEST_MSG_FMT_VAL_WIDTH_H_

#include "../Parameter.h"

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
class Width : public test::msg::fmt::Parameter<TChar>
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
    Width();
    Width(const ValueType& val);
public:
    ~Width();
public:
    Width(const Width<TChar>& cpy);
    Width(Width<TChar>&& mov);
public:
    Width<TChar>& operator=(const Width<TChar>& cpy);
    Width<TChar>& operator=(Width<TChar>&& mov);
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
Width<TChar>::Width() :
    ParameterBaseType(),
    m_value(0)
{}

template<typename TChar>
Width<TChar>::Width(const ValueType& val) :
    ParameterBaseType(StatusType::default_value),
    m_value(val)
{}

template<typename TChar>
Width<TChar>::~Width()
{
    m_value = 0;
}

template<typename TChar>
Width<TChar>::Width(const Width<TChar>& cpy) :
    ParameterBaseType(cpy),
    m_value(cpy.m_value)
{}

template<typename TChar>
Width<TChar>::Width(Width<TChar>&& mov) :
    ParameterBaseType(std::move(mov)),
    m_value(mov.m_value)
{
    if (!mov.GetStatus().IsDefaultValue())
        mov.m_value = 0;
}

template<typename TChar>
Width<TChar>& Width<TChar>::operator=(const Width<TChar>& cpy)
{
    ParameterBaseType::operator=(cpy);
    m_value = cpy.m_value;
    return *this;
}

template<typename TChar>
Width<TChar>& Width<TChar>::operator=(Width<TChar>&& mov)
{
    ParameterBaseType::operator=(std::move(mov));
    m_value = mov.m_value;
    if (!mov.GetStatus().IsDefaultValue())
        mov.m_value = 0;
    return *this;
}

template<typename TChar>
std::size_t Width<TChar>::VLoad(std::size_t, std::size_t index, va_list args)
{
    auto& status = ParameterBaseType::GetStatus();
    if (status.IsSetValue()) return index;
    m_value = va_arg(args, ValueType);
    status.SetValue();
    return index + 1;
}

template<typename TChar>
std::size_t Width<TChar>::Load(std::size_t size, ...)
{
    va_list args;
    va_start(args, size);
    const auto last_index = VLoad(size, 0, args);
    va_end(args);
    return last_index;
}

template<typename TChar>
typename Width<TChar>::ValueType Width<TChar>::GetValue() const
{
    return m_value;
}

template<typename TChar>
void Width<TChar>::Unset()
{
    auto& status = ParameterBaseType::GetStatus();
    status.UnsetValue();
    if (!status.IsSetValue())
    {
        m_value = 0;
    }
}

template<typename TChar>
bool Width<TChar>::IsSet() const
{
    return ParameterBaseType::GetStatus().IsSetValue();
}

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_WIDTH_H_