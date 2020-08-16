#ifndef TEST_MSG_FMT_VAR_FLOATINGPOINT_H_
#define TEST_MSG_FMT_VAR_FLOATINGPOINT_H_

#include "../Parameter.h"
#include "../val/specifier/FloatingPoint.h"

#include <cstdarg>
#include <utility>
#include <type_traits>

namespace test
{
namespace msg
{
namespace fmt
{
namespace var
{

template<typename TChar>
class FloatingPoint :
    public test::msg::fmt::Parameter<TChar>
{
public:
    typedef test::msg::fmt::val::specifier::FloatingPoint<TChar> SpecifierType;
    typedef test::msg::fmt::Parameter<TChar> BaseType;
    typedef typename BaseType::OutputInterfaceType OutputInterfaceType;
    typedef typename BaseType::StatusPointerType StatusPointerType;
private:
    SpecifierType m_specifier;
public:
    FloatingPoint();
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_reference<
            typename std::remove_cv<TArg>::type>::type,
        typename _TStatusPointer = 
            typename test::msg::fmt::Parameter<TChar>::StatusPointerType,
        typename std::enable_if<!std::is_same<_TArg, 
                FloatingPoint<TChar>>::value &&
            !std::is_same<_TArg, _TStatusPointer>::value, int>::type = 0>
    FloatingPoint(TArg&& arg, TArgs&&... args);
public:
    template<typename... TArgs>
    FloatingPoint(StatusPointerType&& status, TArgs&&... args);
public:
    ~FloatingPoint();
public:
    FloatingPoint(const FloatingPoint<TChar>& cpy);
    FloatingPoint(FloatingPoint<TChar>&& mov);
public:
    FloatingPoint<TChar>& operator=(const FloatingPoint<TChar>& cpy);
    FloatingPoint<TChar>& operator=(FloatingPoint<TChar>&& mov);
public:
    std::size_t VLoad(std::size_t size, std::size_t index, va_list& args);
    std::size_t Load(std::size_t size, ...);
public:
    typename OutputInterfaceType::SizeType Output(OutputInterfaceType& out);
public:
    void Unset();
public:
    bool IsSet() const;
};

template<typename TChar>
FloatingPoint<TChar>::FloatingPoint() :
    BaseType(),
    m_specifier(BaseType::GetStatusPointer())
{}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename _TStatusPointer,
    typename std::enable_if<!std::is_same<_TArg, 
            FloatingPoint<TChar>>::value &&
        !std::is_same<_TArg, _TStatusPointer>::value, int>::type>
FloatingPoint<TChar>::FloatingPoint(TArg&& arg, TArgs&&... args) :
    BaseType(),
    m_specifier(BaseType::GetStatusPointer(), 
        std::forward<TArg>(arg), std::forward<TArgs>(args)...)
{}

template<typename TChar>
template<typename... TArgs>
FloatingPoint<TChar>::FloatingPoint(StatusPointerType&& status, 
    TArgs&&... args) :
        BaseType(std::forward<StatusPointerType>(status)),
        m_specifier(BaseType::GetStatusPointer(), 
            std::forward<TArgs>(args)...)
{}

template<typename TChar>
FloatingPoint<TChar>::~FloatingPoint()
{}

template<typename TChar>
FloatingPoint<TChar>::FloatingPoint(const FloatingPoint<TChar>& cpy) :
    BaseType(cpy),
    m_specifier(cpy.m_specifier)
{}

template<typename TChar>
FloatingPoint<TChar>::FloatingPoint(FloatingPoint<TChar>&& mov) :
    BaseType(std::move(mov)),
    m_specifier(std::move(mov.m_specifier))
{}

template<typename TChar>
FloatingPoint<TChar>& 
FloatingPoint<TChar>::operator=(const FloatingPoint<TChar>& cpy)
{
    BaseType::operator=(cpy);
    m_specifier = cpy.m_specifier;
    return *this;
}

template<typename TChar>
FloatingPoint<TChar>& 
FloatingPoint<TChar>::operator=(FloatingPoint<TChar>&& mov)
{
    BaseType::operator=(std::move(mov));
    m_specifier = std::move(mov.m_specifier);
    return *this;
}

template<typename TChar>
std::size_t FloatingPoint<TChar>::VLoad(std::size_t size, std::size_t index, 
    va_list& args)
{
    return m_specifier.VLoad(size, index, args);
}

template<typename TChar>
std::size_t FloatingPoint<TChar>::Load(std::size_t size, ...)
{
    va_list args;
    va_start(args, size);
    auto ret = VLoad(size, 0, args);
    va_end(args);
    return ret;
}

template<typename TChar>
typename FloatingPoint<TChar>::OutputInterfaceType::SizeType 
FloatingPoint<TChar>::Output(OutputInterfaceType& out)
{
    return m_specifier.Output(out);
}

template<typename TChar>
void FloatingPoint<TChar>::Unset()
{
    m_specifier.Unset();
}

template<typename TChar>
bool FloatingPoint<TChar>::IsSet() const
{
    return m_specifier.IsSet();
}

} //!var

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAR_FLOATINGPOINT_H_