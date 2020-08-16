#ifndef TEST_MSG_FMT_VAR_POINTER_H_
#define TEST_MSG_FMT_VAR_POINTER_H_

#include "../Parameter.h"
#include "../val/specifier/Pointer.h"

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
class Pointer :
    public test::msg::fmt::Parameter<TChar>
{
public:
    typedef test::msg::fmt::val::specifier::Pointer<TChar> SpecifierType;
    typedef test::msg::fmt::Parameter<TChar> BaseType;
    typedef typename BaseType::OutputInterfaceType OutputInterfaceType;
    typedef typename BaseType::StatusPointerType StatusPointerType;
private:
    SpecifierType m_specifier;
public:
    Pointer();
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_reference<
            typename std::remove_cv<TArg>::type>::type,
        typename _TStatusPointer = 
            typename test::msg::fmt::Parameter<TChar>::StatusPointerType,
        typename std::enable_if<!std::is_same<_TArg, 
                Pointer<TChar>>::value &&
            !std::is_same<_TArg, _TStatusPointer>::value, int>::type = 0>
    Pointer(TArg&& arg, TArgs&&... args);
public:
    template<typename... TArgs>
    Pointer(StatusPointerType&& status, TArgs&&... args);
public:
    ~Pointer();
public:
    Pointer(const Pointer<TChar>& cpy);
    Pointer(Pointer<TChar>&& mov);
public:
    Pointer<TChar>& operator=(const Pointer<TChar>& cpy);
    Pointer<TChar>& operator=(Pointer<TChar>&& mov);
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
Pointer<TChar>::Pointer() :
    BaseType(),
    m_specifier(BaseType::GetStatusPointer())
{}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename _TStatusPointer,
    typename std::enable_if<!std::is_same<_TArg, 
            Pointer<TChar>>::value &&
        !std::is_same<_TArg, _TStatusPointer>::value, int>::type>
Pointer<TChar>::Pointer(TArg&& arg, TArgs&&... args) :
    BaseType(),
    m_specifier(BaseType::GetStatusPointer(), 
        std::forward<TArg>(arg), std::forward<TArgs>(args)...)
{}

template<typename TChar>
template<typename... TArgs>
Pointer<TChar>::Pointer(StatusPointerType&& status, TArgs&&... args) :
    BaseType(std::forward<StatusPointerType>(status)),
    m_specifier(BaseType::GetStatusPointer(), 
        std::forward<TArgs>(args)...)
{}

template<typename TChar>
Pointer<TChar>::~Pointer()
{}

template<typename TChar>
Pointer<TChar>::Pointer(const Pointer<TChar>& cpy) :
    BaseType(cpy),
    m_specifier(cpy.m_specifier)
{}

template<typename TChar>
Pointer<TChar>::Pointer(Pointer<TChar>&& mov) :
    BaseType(std::move(mov)),
    m_specifier(std::move(mov.m_specifier))
{}

template<typename TChar>
Pointer<TChar>& Pointer<TChar>::operator=(const Pointer<TChar>& cpy)
{
    BaseType::operator=(cpy);
    m_specifier = cpy.m_specifier;
    return *this;
}

template<typename TChar>
Pointer<TChar>& Pointer<TChar>::operator=(Pointer<TChar>&& mov)
{
    BaseType::operator=(std::move(mov));
    m_specifier = std::move(mov.m_specifier);
    return *this;
}

template<typename TChar>
std::size_t Pointer<TChar>::VLoad(std::size_t size, std::size_t index, 
    va_list& args)
{
    return m_specifier.VLoad(size, index, args);
}

template<typename TChar>
std::size_t Pointer<TChar>::Load(std::size_t size, ...)
{
    va_list args;
    va_start(args, size);
    auto ret = VLoad(size, 0, args);
    va_end(args);
    return ret;
}

template<typename TChar>
typename Pointer<TChar>::OutputInterfaceType::SizeType 
Pointer<TChar>::Output(OutputInterfaceType& out)
{
    return m_specifier.Output(out);
}

template<typename TChar>
void Pointer<TChar>::Unset()
{
    m_specifier.Unset();
}

template<typename TChar>
bool Pointer<TChar>::IsSet() const
{
    return m_specifier.IsSet();
}

} //!var

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAR_POINTER_H_