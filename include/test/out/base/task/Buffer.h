#ifndef TEST_OUT_BASE_TASK_BUFFER_H_
#define TEST_OUT_BASE_TASK_BUFFER_H_

#include "../../../Guard.h"
#include "../../CString.h"

#include <utility>
#include <cstdarg>

#ifndef __ATTRIBUTE__
#ifdef __GNUC__
#define __ATTRIBUTE__(...) __attribute__(__VA_ARGS__)
#else
#define __ATTRIBUTE__(...)
#endif
#endif //!__ATTRIBUTE__

namespace test
{
namespace out
{
namespace base
{
namespace task
{

template<typename TChar, typename TInterface>
class Buffer : private test::Guard<TInterface>
{
public:
    typedef test::Guard<TInterface> BaseType;
    typedef typename BaseType::BeginPointerFunctionMemberType 
        BeginPointerFunctionMemberType;
    typedef typename BaseType::EndPointerFunctionMemberType
        EndPointerFunctionMemberType;
    typedef typename test::out::CString<TChar>::StatusType StatusType;
    typedef typename test::out::CString<TChar>::SizeType SizeType;
private:
    test::out::CString<TChar> * m_cstr;
public:
    Buffer();
    Buffer(test::out::CString<TChar> * cstr_ptr, 
        TInterface * ptr, BeginPointerFunctionMemberType begin);
    Buffer(test::out::CString<TChar> * cstr_ptr, 
        TInterface * ptr, BeginPointerFunctionMemberType begin,
        EndPointerFunctionMemberType end);
    Buffer(test::out::CString<TChar> * cstr_ptr,
        test::Guard<TInterface> && mov);
public:
    ~Buffer();
public:
    Buffer(const Buffer<TChar, TInterface>&) = delete;
    Buffer(Buffer<TChar, TInterface>&& mov);
public:
    Buffer<TChar, TInterface>& 
        operator=(const Buffer<TChar, TInterface>&) = delete;
    Buffer<TChar, TInterface>& 
        operator=(Buffer<TChar, TInterface>&&) = delete;
public:
    SizeType Size() const;
public:
    SizeType VPrint(const char * format, va_list var_args) 
        __ATTRIBUTE__ ((__format__ (__printf__, 3, 0)));
    SizeType Print(const char * format, ...) 
        __ATTRIBUTE__((format(printf, 2, 3)));
public:
    SizeType Puts(const TChar * cstr, const SizeType& size);
    SizeType Puts(const TChar * cstr);
    SizeType Puts(const test::CString<TChar>& cstr);
    SizeType Puts(const test::CString<const TChar>& cstr);
public:
    operator bool() const;
};

template<typename TChar, typename TInterface>
Buffer<TChar, TInterface>::Buffer() :
    BaseType(nullptr, nullptr),
    m_cstr(nullptr)
{}

template<typename TChar, typename TInterface>
Buffer<TChar, TInterface>::Buffer(test::out::CString<TChar> * cstr_ptr, 
    TInterface * ptr, BeginPointerFunctionMemberType begin) :
        BaseType(ptr, begin),
        m_cstr(cstr_ptr)
{}
    
template<typename TChar, typename TInterface>
Buffer<TChar, TInterface>::Buffer(test::out::CString<TChar> * cstr_ptr, 
    TInterface * ptr, BeginPointerFunctionMemberType begin,
    EndPointerFunctionMemberType end) :
        BaseType(ptr, begin, end),
        m_cstr(cstr_ptr)
{}

template<typename TChar, typename TInterface>
Buffer<TChar, TInterface>::Buffer(test::out::CString<TChar> * cstr_ptr,
    test::Guard<TInterface> && mov) :
        BaseType(std::move(mov)),
        m_cstr(cstr_ptr)
{}

template<typename TChar, typename TInterface>
Buffer<TChar, TInterface>::~Buffer()
{
    m_cstr = nullptr;
}

template<typename TChar, typename TInterface>
Buffer<TChar, TInterface>::Buffer(Buffer<TChar, TInterface>&& mov) :
    BaseType(std::move(mov)),
    m_cstr(mov.m_cstr)
{
    mov.m_cstr = nullptr;
}

template<typename TChar, typename TInterface>
typename Buffer<TChar, TInterface>::SizeType 
Buffer<TChar, TInterface>::Size() const
{
    if (m_cstr == nullptr) return 0;
    return m_cstr->Size();
}

template<typename TChar, typename TInterface>
typename Buffer<TChar, TInterface>::SizeType 
Buffer<TChar, TInterface>::VPrint(const char * format, va_list var_args)
{
    if (m_cstr == nullptr) return 0;
    return m_cstr->VPrint(format, var_args);
}

template<typename TChar, typename TInterface>
typename Buffer<TChar, TInterface>::SizeType 
Buffer<TChar, TInterface>::Print(const char * format, ...)
{
    if (m_cstr == nullptr) return 0;
    va_list args;
    va_start(args, format);
    const auto ret = m_cstr->VPrint(format, args);
    va_end(args);
    return ret;

}

template<typename TChar, typename TInterface>
typename Buffer<TChar, TInterface>::SizeType 
Buffer<TChar, TInterface>::Puts(const TChar * cstr, const SizeType& size)
{
    if (m_cstr == nullptr) return 0;
    return m_cstr->Puts(cstr, size);
}

template<typename TChar, typename TInterface>
typename Buffer<TChar, TInterface>::SizeType 
Buffer<TChar, TInterface>::Puts(const TChar * cstr)
{
    if (m_cstr == nullptr) return 0;
    return m_cstr->Puts(cstr);
}

template<typename TChar, typename TInterface>
typename Buffer<TChar, TInterface>::SizeType 
Buffer<TChar, TInterface>::Puts(const test::CString<TChar>& cstr)
{
    if (m_cstr == nullptr) return 0;
    return m_cstr->Puts(cstr);
}

template<typename TChar, typename TInterface>
typename Buffer<TChar, TInterface>::SizeType 
Buffer<TChar, TInterface>::Puts(const test::CString<const TChar>& cstr)
{
    if (m_cstr == nullptr) return 0;
    return m_cstr->Puts(cstr);
}

template<typename TChar, typename TInterface>
Buffer<TChar, TInterface>::operator bool() const
{
    return (BaseType::operator bool() && m_cstr != nullptr);
}

} //!task

} //!base

} //!out

} //!test

#endif //!TEST_OUT_BASE_TASK_BUFFER_H_