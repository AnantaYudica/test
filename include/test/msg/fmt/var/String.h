#ifndef TEST_MSG_FMT_VAR_STRING_H_
#define TEST_MSG_FMT_VAR_STRING_H_

#include "../../../Pointer.h"
#include "../../../CString.h"
#include "../../../cstr/Length.h"
#include "../../../trait/cstr/Enable.h"
#include "../../../trait/cstr/IsBaseOf.h"
#include "../Parameter.h"
#include "../val/specifier/String.h"

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
class String :
    public test::msg::fmt::Parameter<TChar>
{
public:
    typedef test::msg::fmt::val::specifier::String<TChar> SpecifierType;
    typedef test::msg::fmt::Parameter<TChar> BaseType;
    typedef typename BaseType::OutputInterfaceType OutputInterfaceType;
    typedef typename BaseType::StatusPointerType StatusPointerType;
    typedef test::CString<TChar> CStringType;
    typedef test::Pointer<CStringType> CStringPtrType;
private:
    CStringPtrType m_cstr_ptr;
    SpecifierType m_specifier;
public:
    String();
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_extent<
            typename std::remove_pointer<typename std::remove_reference<TArg>::
            type>::type>::type>::type,
        typename _TStatusPointer = 
            typename test::msg::fmt::Parameter<TChar>::StatusPointerType,
        typename std::enable_if<
            ((!std::is_base_of<String<TChar>, _TArg>::value &&
            !std::is_base_of<_TStatusPointer, _TArg>::value) &&
            !std::is_same<_TArg, TChar>::value) &&
            !test::trait::cstr::IsBaseOf<_TArg>::Value, int>::type = 0>
    String(TArg&& arg, TArgs&&... args);
public:
    template<typename _TChar, typename... TArgs,  
        typename test::trait::cstr::Enable<TChar, _TChar, int>::Type = 0>
    String(_TChar&& str, TArgs&&... args);
    template<typename... TArgs>
    String(const test::CString<TChar>& str, TArgs&&... args);
    template<typename... TArgs>
    String(const test::CString<const TChar>& str, TArgs&&... args);
    template<typename... TArgs>
    String(test::CString<TChar>&& str, TArgs&&... args);
    template<typename... TArgs>
    String(test::CString<const TChar>&& str, TArgs&&... args);
public:
    String(StatusPointerType&& status);
    template<typename TArg, typename... TArgs, 
        typename _TArg = 
            typename std::remove_cv<typename std::remove_extent<
            typename std::remove_pointer<typename std::remove_reference<TArg>::
            type>::type>::type>::type, 
        typename std::enable_if<
            !std::is_same<_TArg, TChar>::value &&
            !test::trait::cstr::IsBaseOf<_TArg>::Value, int>::type = 0>
    String(StatusPointerType&& status, TArg&& arg, TArgs&&... args);
public:
     template<typename _TChar, typename... TArgs,  
        typename test::trait::cstr::Enable<TChar, _TChar, int>::Type = 0>
    String(StatusPointerType&& status, _TChar&& str, TArgs&&... args);
    template<typename... TArgs>
    String(StatusPointerType&& status, 
        const test::CString<TChar>& str, TArgs&&... args);
    template<typename... TArgs>
    String(StatusPointerType&& status, 
        const test::CString<const TChar>& str, TArgs&&... args);
    template<typename... TArgs>
    String(StatusPointerType&& status, test::CString<TChar>&& str, 
        TArgs&&... args);
    template<typename... TArgs>
    String(StatusPointerType&& status, 
        test::CString<const TChar>&& str, TArgs&&... args);
public:
    ~String();
public:
    String(const String<TChar>& cpy);
    String(String<TChar>&& mov);
public:
    String<TChar>& operator=(const String<TChar>& cpy);
    String<TChar>& operator=(String<TChar>&& mov);
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
String<TChar>::String() :
    BaseType(),
    m_cstr_ptr(),
    m_specifier(BaseType::GetStatusPointer())
{}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg, 
    typename _TStatusPointer, typename std::enable_if<
        ((!std::is_base_of<String<TChar>, _TArg>::value &&
        !std::is_base_of<_TStatusPointer, _TArg>::value) &&
        !std::is_same<_TArg, TChar>::value) &&
        !test::trait::cstr::IsBaseOf<_TArg>::Value, int>::type>
String<TChar>::String(TArg&& arg, TArgs&&... args) :
    BaseType(),
    m_cstr_ptr(),
    m_specifier(BaseType::GetStatusPointer(), 
        std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...)
{}

template<typename TChar>
template<typename _TChar, typename... TArgs, 
    typename test::trait::cstr::Enable<TChar, _TChar, int>::Type>
String<TChar>::String(_TChar&& str, TArgs&&... args) :
    BaseType(),
    m_cstr_ptr(str, test::cstr::Length<TChar, _TChar>::Value(
        std::forward<_TChar>(str))),
    m_specifier(BaseType::GetStatusPointer(),
        m_cstr_ptr->Get(), 
        std::forward<TArgs>(args)...)
{}

template<typename TChar>
template<typename... TArgs>
String<TChar>::String(const test::CString<TChar>& str, TArgs&&... args) :
    BaseType(),
    m_cstr_ptr(str),
    m_specifier(BaseType::GetStatusPointer(), 
       m_cstr_ptr->Get(),
        std::forward<TArgs>(args)...)
{}

template<typename TChar>
template<typename... TArgs>
String<TChar>::String(const test::CString<const TChar>& str, TArgs&&... args) :
    BaseType(),
    m_cstr_ptr(str),
    m_specifier(BaseType::GetStatusPointer(), 
       m_cstr_ptr->Get(),
        std::forward<TArgs>(args)...)
{}

template<typename TChar>
template<typename... TArgs>
String<TChar>::String(test::CString<TChar>&& str, TArgs&&... args) :
    BaseType(),
    m_cstr_ptr(std::move(str)),
    m_specifier(BaseType::GetStatusPointer(), 
       m_cstr_ptr->Get(),
        std::forward<TArgs>(args)...)
{}

template<typename TChar>
template<typename... TArgs>
String<TChar>::String(test::CString<const TChar>&& str, TArgs&&... args) :
    BaseType(),
    m_cstr_ptr(std::move(str)),
    m_specifier(BaseType::GetStatusPointer(), 
       m_cstr_ptr->Get(),
        std::forward<TArgs>(args)...)
{}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg, 
    typename std::enable_if<
        !std::is_same<_TArg, TChar>::value &&
        !test::trait::cstr::IsBaseOf<_TArg>::Value, int>::type>
String<TChar>::String(StatusPointerType&& status, TArg&& arg, 
    TArgs&&... args) :
        BaseType(std::forward<StatusPointerType>(status)),
        m_cstr_ptr(),
        m_specifier(BaseType::GetStatusPointer(), 
            std::forward<TArg>(arg), std::forward<TArgs>(args)...)
{}

template<typename TChar>
String<TChar>::String(StatusPointerType&& status) :
    BaseType(std::forward<StatusPointerType>(status)),
    m_cstr_ptr(),
    m_specifier(BaseType::GetStatusPointer())
{}

template<typename TChar>
    template<typename _TChar, typename... TArgs,  
    typename test::trait::cstr::Enable<TChar, _TChar, int>::Type>
String<TChar>::String(StatusPointerType&& status, _TChar&& str, 
    TArgs&&... args) :
        BaseType(std::forward<StatusPointerType>(status)),
        m_cstr_ptr(str, test::cstr::Length<TChar, _TChar>::Value(
            std::forward<_TChar>(str))),
        m_specifier(BaseType::GetStatusPointer(),
           m_cstr_ptr->Get(), 
            std::forward<TArgs>(args)...)
{}

template<typename TChar>
template<typename... TArgs>
String<TChar>::String(StatusPointerType&& status, 
    const test::CString<TChar>& str, TArgs&&... args) :
        BaseType(std::forward<StatusPointerType>(status)),
        m_cstr_ptr(str),
        m_specifier(BaseType::GetStatusPointer(), 
           m_cstr_ptr->Get(),
            std::forward<TArgs>(args)...)
{}
    
template<typename TChar>
template<typename... TArgs>
String<TChar>::String(StatusPointerType&& status, 
    const test::CString<const TChar>& str, TArgs&&... args) :
        BaseType(std::forward<StatusPointerType>(status)),
        m_cstr_ptr(str),
        m_specifier(BaseType::GetStatusPointer(), 
           m_cstr_ptr->Get(),
            std::forward<TArgs>(args)...)
{}
    
template<typename TChar>
template<typename... TArgs>
String<TChar>::String(StatusPointerType&& status, test::CString<TChar>&& str, 
    TArgs&&... args) :
        BaseType(std::forward<StatusPointerType>(status)),
        m_cstr_ptr(str),
        m_specifier(BaseType::GetStatusPointer(), 
           m_cstr_ptr->Get(),
            std::forward<TArgs>(args)...)
{}
    
template<typename TChar>
template<typename... TArgs>
String<TChar>::String(StatusPointerType&& status, 
    test::CString<const TChar>&& str, TArgs&&... args) :
        BaseType(std::forward<StatusPointerType>(status)),
        m_cstr_ptr(str),
        m_specifier(BaseType::GetStatusPointer(), 
           m_cstr_ptr->Get(),
            std::forward<TArgs>(args)...)
{}
    
template<typename TChar>
String<TChar>::~String()
{}

template<typename TChar>
String<TChar>::String(const String<TChar>& cpy) :
    BaseType(cpy),
    m_cstr_ptr(cpy.m_cstr_ptr),
    m_specifier(cpy.m_specifier)
{}

template<typename TChar>
String<TChar>::String(String<TChar>&& mov) :
    BaseType(std::move(mov)),
    m_cstr_ptr(std::move(mov.m_cstr_ptr)),
    m_specifier(std::move(mov.m_specifier))
{}

template<typename TChar>
String<TChar>& String<TChar>::operator=(const String<TChar>& cpy)
{
    BaseType::operator=(cpy);
    m_cstr_ptr = cpy.m_cstr_ptr;
    m_specifier = cpy.m_specifier;
    return *this;
}

template<typename TChar>
String<TChar>& String<TChar>::operator=(String<TChar>&& mov)
{
    BaseType::operator=(std::move(mov));
    m_cstr_ptr =(std::move(mov.m_cstr_ptr));
    m_specifier = std::move(mov.m_specifier);
    return *this;
}

template<typename TChar>
std::size_t String<TChar>::VLoad(std::size_t size, std::size_t index, 
    va_list& args)
{
    return m_specifier.VLoad(size, index, args);
}

template<typename TChar>
std::size_t String<TChar>::Load(std::size_t size, ...)
{
    va_list args;
    va_start(args, size);
    auto ret = VLoad(size, 0, args);
    va_end(args);
    return ret;
}

template<typename TChar>
typename String<TChar>::OutputInterfaceType::SizeType 
String<TChar>::Output(OutputInterfaceType& out)
{
    return m_specifier.Output(out);
}

template<typename TChar>
void String<TChar>::Unset()
{
    m_specifier.Unset();
}

template<typename TChar>
bool String<TChar>::IsSet() const
{
    return m_specifier.IsSet();
}

} //!var

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAR_STRING_H_