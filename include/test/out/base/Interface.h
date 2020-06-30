#ifndef TEST_OUT_BASE_INTERFACE_H_
#define TEST_OUT_BASE_INTERFACE_H_

#include "../../CString.h"

#include <cstdlib>
#include <cstdint>
#include <cstdarg>
#include <utility>

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

template<typename TChar, typename TStatus>
class Interface
{
public:
    typedef std::size_t SizeType;
    typedef TStatus StatusType;
private:
    StatusType m_status;
protected:
    Interface();
    template<typename... TArgs>
    Interface(TArgs&&... args);
public:
    virtual ~Interface();
public:
    Interface(const Interface<TChar, TStatus>&) = delete;
    Interface(Interface<TChar, TStatus>&&) = delete;
public:
    Interface<TChar, TStatus>& 
        operator=(const Interface<TChar, TStatus>&) = delete;
    Interface<TChar, TStatus>& 
        operator=(Interface<TChar, TStatus>&&) = delete;
public:
    virtual bool VPrint(const char * format, va_list var_args) 
        __ATTRIBUTE__ ((__format__ (__printf__, 3, 0))) = 0;
    virtual bool Print(const char * format, ...) 
        __ATTRIBUTE__((format(printf, 2, 3))) = 0;
public:
    virtual bool Puts(const TChar * cstr, const SizeType& size) = 0;
    virtual bool Puts(const TChar * cstr) = 0;
    virtual bool Puts(const test::CString<TChar>& cstr) = 0;
    virtual bool Puts(const test::CString<const TChar>& cstr) = 0;
public:
    TStatus& GetStatus();
    TStatus GetStatus() const;
};

template<typename TChar, typename TStatus>
Interface<TChar, TStatus>::Interface() :
    m_status()
{}

template<typename TChar, typename TStatus>
template<typename... TArgs>
Interface<TChar, TStatus>::Interface(TArgs&&... args) :
    m_status(std::forward<TArgs>(args)...)
{}

template<typename TChar, typename TStatus>
Interface<TChar, TStatus>::~Interface()
{}

template<typename TChar, typename TStatus>
TStatus& Interface<TChar, TStatus>::GetStatus()
{
    return m_status;
}

template<typename TChar, typename TStatus>
TStatus Interface<TChar, TStatus>::GetStatus() const
{
    return {m_status};
}

} //!base

} //!out

} //!test

#endif //!TEST_OUT_BASE_INTERFACE_H_
