#ifndef TEST_OUT_INTERFACE_H_
#define TEST_OUT_INTERFACE_H_

#include "../CString.h"
#include "Standard.h"

#include <cstdlib>
#include <cstdint>
#include <cstdarg>
#include <utility>
#include <cwchar>

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

template<typename TChar>
class Interface : public test::out::Standard<TChar>
{
public:
    typedef std::size_t SizeType; 
public:
    Interface() = default;
public:
    virtual ~Interface() = default;
public:
    Interface(const Interface<TChar>&) = delete;
    Interface(Interface<TChar>&&) = delete;
public:
    Interface<TChar>& operator=(const Interface<TChar>&) = delete;
    Interface<TChar>& operator=(Interface<TChar>&&) = delete;
public:
    virtual SizeType Puts(const TChar * cstr, const SizeType& size) = 0;
    virtual SizeType Puts(const TChar * cstr) = 0;
    virtual SizeType Puts(const test::CString<TChar>& cstr) = 0;
    virtual SizeType Puts(const test::CString<const TChar>& cstr) = 0;
public:
    virtual bool IsBad() const = 0;
    virtual bool IsGood() const = 0;
};

template<>
class Interface<char> : public test::out::Standard<char>
{
public:
    typedef std::size_t SizeType; 
public:
    Interface() = default;
public:
    virtual ~Interface() = default;
public:
    Interface(const Interface<char>&) = delete;
    Interface(Interface<char>&&) = delete;
public:
    Interface<char>& operator=(const Interface<char>&) = delete;
    Interface<char>& operator=(Interface<char>&&) = delete;
public:
    virtual SizeType VPrint(const char * format, va_list var_args) 
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0))) = 0;
    virtual SizeType Print(const char * format, ...) 
        TEST_ATTRIBUTE((format(printf, 2, 3))) = 0;
public:
    virtual SizeType Puts(const char * cstr, const SizeType& size) = 0;
    virtual SizeType Puts(const char * cstr) = 0;
    virtual SizeType Puts(const test::CString<char>& cstr) = 0;
    virtual SizeType Puts(const test::CString<const char>& cstr) = 0;
public:
    virtual bool IsBad() const = 0;
    virtual bool IsGood() const = 0;
};

template<>
class Interface<wchar_t> : public test::out::Standard<wchar_t>
{
public:
    typedef std::size_t SizeType; 
public:
    Interface() = default;
public:
    virtual ~Interface() = default;
public:
    Interface(const Interface<wchar_t>&) = delete;
    Interface(Interface<wchar_t>&&) = delete;
public:
    Interface<wchar_t>& operator=(const Interface<wchar_t>&) = delete;
    Interface<wchar_t>& operator=(Interface<wchar_t>&&) = delete;
public:
    virtual SizeType VPrint(const wchar_t * format, va_list var_args) = 0;
    virtual SizeType Print(const wchar_t * format, ...) = 0;
public:
    virtual SizeType Puts(const wchar_t * cstr, const SizeType& size) = 0;
    virtual SizeType Puts(const wchar_t * cstr) = 0;
    virtual SizeType Puts(const test::CString<wchar_t>& cstr) = 0;
    virtual SizeType Puts(const test::CString<const wchar_t>& cstr) = 0;
public:
    virtual bool IsBad() const = 0;
    virtual bool IsGood() const = 0;
};

} //!out

} //!test

#endif //!TEST_OUT_INTERFACE_H_
