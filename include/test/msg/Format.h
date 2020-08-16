#ifndef TEST_MSG_FORMAT_H_
#define TEST_MSG_FORMAT_H_

#include "../out/Interface.h"
#include "../Pointer.h"
#include "fmt/Parameter.h"
#include "fmt/param/Character.h"
#include "fmt/param/FloatingPoint.h"
#include "fmt/param/Integer.h"
#include "fmt/param/Nothing.h"
#include "fmt/param/Pointer.h"
#include "fmt/param/String.h"
#include "fmt/param/Empty.h"

#include <cstddef>
#include <cstring>
#include <cstdio>
#include <utility>
#include <type_traits>

namespace test
{
namespace msg
{

template<typename TChar = char>
class Format
{
public:
    typedef typename std::remove_const<TChar>::type CharType;
    typedef test::out::Interface<TChar> OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
    typedef typename test::msg::fmt::Parameter<TChar>::StatusType StatusType;
    typedef typename StatusType::IntegerValueType BadValueType;
    typedef test::msg::fmt::var::Character<TChar> VarCharacterType;
    typedef test::msg::fmt::var::FloatingPoint<TChar> VarFloatingPointType;
    typedef test::msg::fmt::var::Integer<TChar> VarIntegerType;
    typedef test::msg::fmt::var::Nothing<TChar> VarNothingType;
    typedef test::msg::fmt::var::Pointer<TChar> VarPointerType;
    typedef test::msg::fmt::var::String<TChar> VarStringType;
    template<typename... TArgs>
    using ParameterType = test::msg::fmt::Parameter<TChar, TArgs...>;
private:
    template<test::msg::fmt::Parameter<TChar, 
        test::msg::fmt::var::Empty> (*DefaultConstructorFunc)()>
    using PointerDefaultType = test::ptr::Default<
        test::msg::fmt::Parameter<TChar, test::msg::fmt::var::Empty>,
        DefaultConstructorFunc>;
    template<test::msg::fmt::Parameter<TChar, 
        test::msg::fmt::var::Empty> (*DefaultConstructorFunc)()>
    using ParameterPointerType = test::Pointer<
        test::msg::fmt::Parameter<TChar>,
        test::ptr::Default<
            test::msg::fmt::Parameter<TChar, test::msg::fmt::var::Empty>,
            DefaultConstructorFunc>>;
public:
    static test::msg::fmt::Parameter<TChar, 
        test::msg::fmt::var::Empty> _DefaultParamConstructor();
private:
    ParameterPointerType<_DefaultParamConstructor> m_param;
public:
    Format();
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_reference<
            typename std::remove_cv<TArg>::type>::type, 
        typename std::enable_if<!std::is_same<_TArg, Format<TChar>>::value, 
            int>::type = 0>
    Format(TArg&& arg, TArgs&&... args);
public:
    ~Format();
public:
    Format(const Format<TChar>& cpy);
    Format(Format<TChar>&& mov);
public:
    Format<TChar>& operator=(const Format<TChar>& cpy);
    Format<TChar>& operator=(Format<TChar>&& mov);
public:
    template<typename... TArgs>
    std::size_t Load(TArgs&&... args);
public:
    SizeType Output(OutputInterfaceType& out);
    template<typename TArg, typename... TArgs>
    SizeType Output(OutputInterfaceType& out, TArg&& arg, TArgs&&... args);
public:
    void Unset();
public:
    bool IsSet() const;
public:
    bool IsGood() const;
    bool IsBad() const;
public:
    void Reset();
public:
    BadValueType GetBadCode() const;
public:
    operator bool() const; 
};

template<typename TChar>
test::msg::fmt::Parameter<TChar, test::msg::fmt::var::Empty>
Format<TChar>::_DefaultParamConstructor()
{
    static test::msg::fmt::Parameter<TChar, 
        test::msg::fmt::var::Empty> def;
    return def;
}

template<typename TChar>
Format<TChar>::Format() :
    m_param()
{}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg, 
    typename std::enable_if<!std::is_same<_TArg, Format<TChar>>::value, 
        int>::type>
Format<TChar>::Format(TArg&& arg, TArgs&&... args) :
    m_param()
{
    test::Pointer<ParameterType<TArg, TArgs...>> ptr{
        std::forward<TArg>(arg), std::forward<TArgs>(args)...};
    m_param = ptr.template DynamicCast<test::msg::fmt::Parameter<TChar>, 
        PointerDefaultType<_DefaultParamConstructor>>();
}

template<typename TChar>
Format<TChar>::~Format()
{}

template<typename TChar>
Format<TChar>::Format(const Format<TChar>& cpy) :
    m_param(cpy.m_param)
{}

template<typename TChar>
Format<TChar>::Format(Format<TChar>&& mov) :
    m_param(std::move(mov.m_param))
{}

template<typename TChar>
Format<TChar>& Format<TChar>::operator=(const Format<TChar>& cpy)
{
    m_param = cpy.m_param;
    return *this;
}

template<typename TChar>
Format<TChar>& Format<TChar>::operator=(Format<TChar>&& mov)
{
    m_param = std::move(mov.m_param);
    return *this;
}

template<typename TChar>
template<typename... TArgs>
std::size_t Format<TChar>::Load(TArgs&&... args)
{
    return m_param->Load(sizeof...(TArgs), std::forward<TArgs>(args)...);
}

template<typename TChar>
typename Format<TChar>::SizeType 
Format<TChar>::Output(OutputInterfaceType& out)
{
    return m_param->Output(out);
}

template<typename TChar>
void Format<TChar>::Unset()
{
    m_param->Unset();
}

template<typename TChar>
bool Format<TChar>::IsSet() const
{
    return (*m_param).IsSet();
}

template<typename TChar>
bool Format<TChar>::IsGood() const
{
    return (*m_param).IsGood();
}

template<typename TChar>
bool Format<TChar>::IsBad() const
{
    return (*m_param).IsBad();
}

template<typename TChar>
void Format<TChar>::Reset()
{
    m_param->Reset();
}

template<typename TChar>
typename Format<TChar>::BadValueType Format<TChar>::GetBadCode() const
{
    return (*m_param).GetBadCode();
}

template<typename TChar>
Format<TChar>::operator bool() const
{
    auto pthis = const_cast<Format<TChar>*>(this);
    auto cast = pthis->m_param.template DynamicCast<
        test::msg::fmt::Parameter<TChar, test::msg::fmt::var::Empty>, 
        PointerDefaultType<_DefaultParamConstructor>>();
    return cast != m_param;
}

} //!msg

} //!test

#endif //!TEST_MSG_FORMAT_H_
