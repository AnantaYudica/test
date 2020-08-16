#ifndef TEST_MSG_FMT_PARAM_NOTHING_H_
#define TEST_MSG_FMT_PARAM_NOTHING_H_

#include "../Parameter.h"
#include "../var/Nothing.h"

#include <cstdarg>
#include <utility>
#include <type_traits>

namespace test
{
namespace msg
{
namespace fmt
{
    
template<typename TChar>
class Parameter<TChar, test::msg::fmt::var::Nothing<TChar>> :
    public Parameter<TChar>
{
public:
    typedef typename Parameter<TChar>::StatusType StatusType;
    typedef typename StatusType::ValueType ValueStatusType;
    typedef typename StatusType::IntegerValueType IntegerValueStatusType;
    typedef typename Parameter<TChar>::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename Parameter<TChar>::StatusPointerType StatusPointerType;
private:
    test::msg::fmt::var::Nothing<TChar> m_value;
public:
    Parameter();
    Parameter(test::msg::fmt::var::Nothing<TChar>&& nothing_var);
public:
    Parameter(StatusPointerType&& status);
    Parameter(StatusPointerType&& status, 
        test::msg::fmt::var::Nothing<TChar>&& nothing_var);
public:
    virtual ~Parameter();
public:
    Parameter(const Parameter<TChar, 
        test::msg::fmt::var::Nothing<TChar>>& cpy);
    Parameter(Parameter<TChar, 
        test::msg::fmt::var::Nothing<TChar>>&& mov);
public:
    Parameter<TChar, test::msg::fmt::var::Nothing<TChar>>& 
        operator=(const Parameter<TChar, 
            test::msg::fmt::var::Nothing<TChar>>& cpy);
    Parameter<TChar, test::msg::fmt::var::Nothing<TChar>>& 
        operator=(Parameter<TChar, 
            test::msg::fmt::var::Nothing<TChar>>&& mov);
public:
    virtual std::size_t VLoad(std::size_t size, std::size_t index, 
        va_list& args) override;
    virtual std::size_t Load(std::size_t size, ...) override;
public:
    virtual typename OutputInterfaceType::SizeType 
        Output(OutputInterfaceType& out) override;
public:
    virtual void Unset() override;
public:
    virtual bool IsSet() const override;
};

template<typename TChar, typename... TParam>
class Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, TParam...> :
    public Parameter<TChar, TParam...>
{
public:
    typedef typename Parameter<TChar, TParam...>::StatusType StatusType;
    typedef typename StatusType::ValueType ValueStatusType;
    typedef typename StatusType::IntegerValueType IntegerValueStatusType;
    typedef typename Parameter<TChar, TParam...>::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename Parameter<TChar>::StatusPointerType StatusPointerType;
private:
    test::msg::fmt::var::Nothing<TChar> m_value;
public:
    Parameter();
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_reference<
            typename std::remove_cv<TArg>::type>::type,
        typename _TStatusPointer = 
            typename Parameter<TChar>::StatusPointerType,
        typename std::enable_if<
            !std::is_base_of<Parameter<TChar>, _TArg>::value && 
            !std::is_same<_TArg, 
                test::msg::fmt::var::Nothing<TChar>>::value &&
            !std::is_same<_TArg, _TStatusPointer>::value, int>::type = 0>
    Parameter(TArg&& arg, TArgs&&... args);
    template<typename... TArgs>
    Parameter(test::msg::fmt::var::Nothing<TChar>&& nothing_var, 
        TArgs&&... args);
public:
    Parameter(StatusPointerType&& status);
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_reference<
            typename std::remove_cv<TArg>::type>::type,
        typename std::enable_if<!std::is_same<_TArg, 
            test::msg::fmt::var::Nothing<TChar>>::value, int>::type = 0>
    Parameter(StatusPointerType&& status, TArg&& arg, TArgs&&... args);
    template<typename... TArgs>
    Parameter(StatusPointerType&& status, 
        test::msg::fmt::var::Nothing<TChar>&& nothing_var, TArgs&&... args);
public:
    virtual ~Parameter();
public:
    Parameter(const Parameter<TChar, test::msg::fmt::var::Nothing<TChar>,
        TParam...>& cpy);
    Parameter(Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, 
        TParam...>&& mov);
public:
    Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, TParam...>& 
        operator=(const Parameter<TChar, 
            test::msg::fmt::var::Nothing<TChar>, TParam...>& cpy);
    Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, TParam...>& 
        operator=(Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, 
            TParam...>&& mov);
public:
    virtual std::size_t VLoad(std::size_t size, std::size_t index, 
        va_list& args) override;
    virtual std::size_t Load(std::size_t size, ...) override;
public:
    virtual typename OutputInterfaceType::SizeType 
        Output(OutputInterfaceType& out) override;
public:
    virtual void Unset() override;
public:
    virtual bool IsSet() const override;
};


template<typename TChar>
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>>::Parameter() :
    Parameter<TChar>(),
    m_value(Parameter<TChar>::GetStatusPointer())
{}

template<typename TChar>
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>>::
    Parameter(test::msg::fmt::var::Nothing<TChar>&& nothing_var) :
        Parameter<TChar>(),
        m_value(Parameter<TChar>::GetStatusPointer())
{
    m_value = std::move(nothing_var);
}

template<typename TChar>
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>>::
    Parameter(StatusPointerType&& status) :
        Parameter<TChar>(std::forward<StatusPointerType>(status)),
        m_value(Parameter<TChar>::GetStatusPointer())
{}

template<typename TChar>
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>>::
    Parameter(StatusPointerType&& status, 
        test::msg::fmt::var::Nothing<TChar>&& nothing_var) :
            Parameter<TChar>(std::forward<StatusPointerType>(status)),
            m_value(Parameter<TChar>::GetStatusPointer())
{
    m_value = std::move(nothing_var);
}

template<typename TChar>
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>>::~Parameter()
{}

template<typename TChar>
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>>::
    Parameter(const Parameter<TChar, 
        test::msg::fmt::var::Nothing<TChar>>& cpy) :
            Parameter<TChar>(cpy),
            m_value(cpy.m_value)
{}
    
template<typename TChar>
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>>::
    Parameter(Parameter<TChar, 
        test::msg::fmt::var::Nothing<TChar>>&& mov) :
            Parameter<TChar>(std::move(mov)),
            m_value(std::move(mov.m_value))
{}

template<typename TChar>
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>>& 
    Parameter<TChar, test::msg::fmt::var::Nothing<TChar>>::
        operator=(const Parameter<TChar, 
            test::msg::fmt::var::Nothing<TChar>>& cpy)
{
    Parameter<TChar>::operator=(cpy);
    m_value = cpy.m_value;
    return *this;
}

template<typename TChar>
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>>& 
    Parameter<TChar, test::msg::fmt::var::Nothing<TChar>>::
        operator=(Parameter<TChar, test::msg::fmt::var::Nothing<TChar>>&& mov)
{
    Parameter<TChar>::operator=(std::move(mov));
    m_value = std::move(mov.m_value);
    return *this;
}

template<typename TChar>
std::size_t Parameter<TChar, test::msg::fmt::var::Nothing<TChar>>::
    VLoad(std::size_t size, std::size_t index, va_list& args)
{
    return m_value.VLoad(size, index, args);
}

template<typename TChar>
std::size_t Parameter<TChar, test::msg::fmt::var::Nothing<TChar>>::
    Load(std::size_t size, ...)
{
    va_list args;
    va_start(args, size);
    auto ret = VLoad(size, 0, args);
    va_end(args);
    return ret;
}

template<typename TChar>
typename Parameter<TChar, test::msg::fmt::var::Nothing<TChar>>::
    OutputInterfaceType::SizeType 
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>>::
    Output(OutputInterfaceType& out)
{
    return m_value.Output(out);
}

template<typename TChar>
void Parameter<TChar, test::msg::fmt::var::Nothing<TChar>>::Unset()
{
    m_value.Unset();
}

template<typename TChar>
bool Parameter<TChar, test::msg::fmt::var::Nothing<TChar>>::IsSet() const
{
    return m_value.IsSet();
}

template<typename TChar, typename... TParam>
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, TParam...>::
    Parameter() :
        Parameter<TChar, TParam...>(),
        m_value(Parameter<TChar>::GetStatusPointer())
{}

template<typename TChar, typename... TParam>
template<typename TArg, typename... TArgs, typename _TArg,
    typename _TStatusPointer,
    typename std::enable_if<
        !std::is_base_of<Parameter<TChar>, _TArg>::value && 
        !std::is_same<_TArg, 
            test::msg::fmt::var::Nothing<TChar>>::value &&
        !std::is_same<_TArg, _TStatusPointer>::value, int>::type>
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, TParam...>::
    Parameter(TArg&& arg, TArgs&&... args) :
        Parameter<TChar, TParam...>(std::forward<TArg>(arg), 
            std::forward<TArgs>(args)...),
        m_value(Parameter<TChar>::GetStatusPointer())
{}

template<typename TChar, typename... TParam>
template<typename... TArgs>
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, TParam...>::
    Parameter(test::msg::fmt::var::Nothing<TChar>&& nothing_var, 
        TArgs&&... args) :
            Parameter<TChar, TParam...>(std::forward<TArgs>(args)...),
            m_value(Parameter<TChar>::GetStatusPointer())
{
    m_value = std::move(nothing_var);
}

template<typename TChar, typename... TParam>
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, TParam...>::
    Parameter(StatusPointerType&& status) :
        Parameter<TChar, TParam...>(std::forward<StatusPointerType>(status)),
        m_value(Parameter<TChar>::GetStatusPointer())
{}

template<typename TChar, typename... TParam>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_same<_TArg, 
        test::msg::fmt::var::Nothing<TChar>>::value, int>::type>
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, TParam...>::
    Parameter(StatusPointerType&& status, TArg&& arg, TArgs&&... args) :
        Parameter<TChar, TParam...>(std::forward<StatusPointerType>(status),
            std::forward<TArg>(arg), std::forward<TArgs>(args)...),
        m_value(Parameter<TChar>::GetStatusPointer())
{}

template<typename TChar, typename... TParam>
template<typename... TArgs>
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, TParam...>::
    Parameter(StatusPointerType&& status, 
        test::msg::fmt::var::Nothing<TChar>&& nothing_var, TArgs&&... args) :
            Parameter<TChar, TParam...>(
                std::forward<StatusPointerType>(status),
                std::forward<TArgs>(args)...),
            m_value(Parameter<TChar>::GetStatusPointer())
{
    m_value = std::move(nothing_var);
}

template<typename TChar, typename... TParam>
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, TParam...>::
    ~Parameter()
{}

template<typename TChar, typename... TParam>
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, TParam...>::
    Parameter(const Parameter<TChar, test::msg::fmt::var::Nothing<TChar>,
        TParam...>& cpy) :
            Parameter<TChar, TParam...>(cpy),
            m_value(cpy.m_value)
{}

template<typename TChar, typename... TParam>
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, TParam...>::
    Parameter(Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, 
        TParam...>&& mov) :
            Parameter<TChar, TParam...>(std::move(mov)),
            m_value(std::move(mov.m_value))
{}

template<typename TChar, typename... TParam>
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, TParam...>& 
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, TParam...>::
    operator=(const Parameter<TChar, test::msg::fmt::var::Nothing<TChar>,
        TParam...>& cpy)
{
    Parameter<TChar, TParam...>::operator=(cpy);
    m_value = cpy.m_value;
    return *this;
}

template<typename TChar, typename... TParam>
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, TParam...>& 
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, TParam...>::
    operator=(Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, 
        TParam...>&& mov)
{
    Parameter<TChar, TParam...>::operator=(std::move(mov));
    m_value = std::move(mov.m_value);
    return *this;
}

template<typename TChar, typename... TParam>
std::size_t Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, 
    TParam...>::VLoad(std::size_t size, std::size_t index, va_list& args)
{
    const auto next_index = m_value.VLoad(size, index, args);
    return Parameter<TChar, TParam...>::VLoad(size, next_index, args);
}

template<typename TChar, typename... TParam>
std::size_t Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, 
    TParam...>::Load(std::size_t size, ...)
{
    va_list args;
    va_start(args, size);
    auto ret = VLoad(size, 0, args);
    va_end(args);
    return ret;
}

template<typename TChar, typename... TParam>
typename Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, 
    TParam...>::OutputInterfaceType::SizeType 
Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, 
    TParam...>::Output(OutputInterfaceType& out)
{
    const auto size = m_value.Output(out);
    const auto next_size = Parameter<TChar, TParam...>::Output(out);
    return (size + next_size);
}

template<typename TChar, typename... TParam>
void Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, 
    TParam...>::Unset()
{
    m_value.Unset();
    Parameter<TChar, TParam...>::Unset();
}

template<typename TChar, typename... TParam>
bool Parameter<TChar, test::msg::fmt::var::Nothing<TChar>, TParam...>::
    IsSet() const
{
    if (!m_value.IsSet()) return false;
    return Parameter<TChar, TParam...>::IsSet();
}

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_PARAM_NOTHING_H_
