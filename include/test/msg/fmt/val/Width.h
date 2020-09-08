#ifndef TEST_MSG_FMT_VAL_WIDTH_H_
#define TEST_MSG_FMT_VAL_WIDTH_H_

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
class Width : public test::msg::fmt::Parameter<TChar>
{
public:
    typedef test::msg::fmt::Parameter<TChar> ParameterBaseType;
    typedef typename ParameterBaseType::StatusType StatusType;
    typedef typename ParameterBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename ParameterBaseType::StatusPointerType StatusPointerType;
    typedef test::msg::fmt::val::Status StatusValueType;
    typedef int ValueType;
private:
    StatusValueType m_value_status;
    ValueType m_value;
public:
    Width();
    Width(const ValueType& val);
protected:
    Width(StatusPointerType&& status);
    Width(StatusPointerType&& status, const ValueType& val);
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
Width<TChar>::Width() :
    ParameterBaseType(),
    m_value_status(0),
    m_value(0)
{}

template<typename TChar>
Width<TChar>::Width(const ValueType& val) :
    ParameterBaseType(),
    m_value_status(StatusValueType::default_value),
    m_value(val)
{}

template<typename TChar>
Width<TChar>::Width(StatusPointerType&& status) :
    ParameterBaseType(std::forward<StatusPointerType>(status)),
    m_value_status(0),
    m_value(0)
{}

template<typename TChar>
Width<TChar>::Width(StatusPointerType&& status, const ValueType& val) :
    ParameterBaseType(std::forward<StatusPointerType>(status)),
    m_value_status(StatusValueType::default_value),
    m_value(val)
{}

template<typename TChar>
Width<TChar>::~Width()
{
    m_value_status.Reset();
    m_value = 0;
}

template<typename TChar>
Width<TChar>::Width(const Width<TChar>& cpy) :
    ParameterBaseType(cpy),
    m_value_status(cpy.m_value_status),
    m_value(cpy.m_value)
{}

template<typename TChar>
Width<TChar>::Width(Width<TChar>&& mov) :
    ParameterBaseType(std::move(mov)),
    m_value_status(std::move(mov.m_value_status)),
    m_value(mov.m_value)
{
    if (!mov.m_value_status.IsDefaultValue())
        mov.m_value = 0;
}

template<typename TChar>
Width<TChar>& Width<TChar>::operator=(const Width<TChar>& cpy)
{
    ParameterBaseType::operator=(cpy);
    m_value_status = cpy.m_value_status;
    m_value = cpy.m_value;
    return *this;
}

template<typename TChar>
Width<TChar>& Width<TChar>::operator=(Width<TChar>&& mov)
{
    ParameterBaseType::operator=(std::move(mov));
    m_value_status = std::move(mov.m_value_status);
    m_value = mov.m_value;
    if (!mov.m_value_status.IsDefaultValue())
        mov.m_value = 0;
    return *this;
}

template<typename TChar>
std::size_t Width<TChar>::VLoad(std::size_t, std::size_t index, 
    va_list& args)
{
    if (m_value_status.IsSetValue()) return index;
    m_value = va_arg(args, ValueType);
    m_value_status.SetValue();
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
typename Width<TChar>::OutputInterfaceType::SizeType
Width<TChar>::Output(OutputInterfaceType&)
{
    return 0;
}
    
template<typename TChar>
typename Width<TChar>::ValueType Width<TChar>::GetValue() const
{
    return m_value;
}

template<typename TChar>
void Width<TChar>::Unset()
{
    m_value_status.UnsetValue();
    if (!m_value_status.IsSetValue())
    {
        m_value = 0;
    }
}

template<typename TChar>
bool Width<TChar>::IsSet() const
{
    return m_value_status.IsSetValue();
}

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_WIDTH_H_