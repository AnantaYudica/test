#ifndef TEST_OUT_BASE_TASK_BUFFER_H_
#define TEST_OUT_BASE_TASK_BUFFER_H_

#include "../../../Guard.h"
#include "../../CString.h"
#include "../../Interface.h"

#include <utility>
#include <cstdarg>

#ifndef TEST_ATTRIBUTE
#ifdef __GNUC__
#define TEST_ATTRIBUTE(...) __attribute__(__VA_ARGS__)
#else
#define TEST_ATTRIBUTE(...)
#endif
#endif //!TEST_ATTRIBUTE

namespace test
{
namespace out
{
namespace base
{
namespace task
{

template<typename TChar, typename TInterface>
class Buffer : public test::out::Interface<TChar>
{
private:
    typedef test::Guard<TInterface> GuardType;
public:
    typedef test::out::Interface<TChar> BaseType;
    typedef typename GuardType::BeginPointerFunctionMemberType 
        BeginPointerFunctionMemberType;
    typedef typename GuardType::EndPointerFunctionMemberType
        EndPointerFunctionMemberType;
    typedef typename test::out::CString<TChar>::StatusType StatusType;
    typedef typename test::out::CString<TChar>::SizeType SizeType;
private:
    test::out::CString<TChar> * m_cstr;
    GuardType m_guard;
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
    virtual ~Buffer();
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
    SizeType VPrint(const char * format, va_list var_args) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));
    SizeType Print(const char * format, ...) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 3)));
public:
    SizeType Puts(const TChar * cstr, const SizeType& size) override;
    SizeType Puts(const TChar * cstr) override;
    SizeType Puts(const test::CString<TChar>& cstr) override;
    SizeType Puts(const test::CString<const TChar>& cstr) override;
public:
    bool IsBad() const override;
    bool IsGood() const override;
};

template<typename TChar, typename TInterface>
Buffer<TChar, TInterface>::Buffer() :
    BaseType(),
    m_cstr(nullptr),
    m_guard(nullptr, nullptr)
{}

template<typename TChar, typename TInterface>
Buffer<TChar, TInterface>::Buffer(test::out::CString<TChar> * cstr_ptr, 
    TInterface * ptr, BeginPointerFunctionMemberType begin) :
        BaseType(),
        m_cstr(cstr_ptr),
        m_guard(ptr, begin)
{}
    
template<typename TChar, typename TInterface>
Buffer<TChar, TInterface>::Buffer(test::out::CString<TChar> * cstr_ptr, 
    TInterface * ptr, BeginPointerFunctionMemberType begin,
    EndPointerFunctionMemberType end) :
        BaseType(),
        m_cstr(cstr_ptr),
        m_guard(ptr, begin, end)
{}

template<typename TChar, typename TInterface>
Buffer<TChar, TInterface>::Buffer(test::out::CString<TChar> * cstr_ptr,
    test::Guard<TInterface> && mov) :
        BaseType(),
        m_cstr(cstr_ptr),
        m_guard(std::move(mov))
{}

template<typename TChar, typename TInterface>
Buffer<TChar, TInterface>::~Buffer()
{
    m_cstr = nullptr;
}

template<typename TChar, typename TInterface>
Buffer<TChar, TInterface>::Buffer(Buffer<TChar, TInterface>&& mov) :
    BaseType(),
    m_cstr(mov.m_cstr),
    m_guard(std::move(mov.m_guard))
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
bool Buffer<TChar, TInterface>::IsBad() const
{
    return (!m_guard || m_cstr == nullptr);
}

template<typename TChar, typename TInterface>
bool Buffer<TChar, TInterface>::IsGood() const
{
    return (m_guard && m_cstr != nullptr);
}

} //!task

} //!base

} //!out

} //!test

#endif //!TEST_OUT_BASE_TASK_BUFFER_H_
