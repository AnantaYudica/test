#ifndef TEST_OUT_INTERFACE_H_
#define TEST_OUT_INTERFACE_H_

#include "../CString.h"

#include <cstdlib>
#include <cstdint>
#include <cstdarg>
#include <utility>

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
class Interface
{
public:
    typedef std::size_t SizeType; 
public:
    Interface();
public:
    virtual ~Interface();
public:
    Interface(const Interface<TChar>&) = delete;
    Interface(Interface<TChar>&&) = delete;
public:
    Interface<TChar>& operator=(const Interface<TChar>&) = delete;
    Interface<TChar>& operator=(Interface<TChar>&&) = delete;
public:
    virtual SizeType VPrint(const char * format, va_list var_args) 
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0))) = 0;
    virtual SizeType Print(const char * format, ...) 
        TEST_ATTRIBUTE((format(printf, 2, 3))) = 0;
public:
    virtual SizeType Puts(const TChar * cstr, const SizeType& size) = 0;
    virtual SizeType Puts(const TChar * cstr) = 0;
    virtual SizeType Puts(const test::CString<TChar>& cstr) = 0;
    virtual SizeType Puts(const test::CString<const TChar>& cstr) = 0;
public:
    virtual bool IsBad() const = 0;
    virtual bool IsGood() const = 0;
};

template<typename TChar>
Interface<TChar>::Interface()
{}

template<typename TChar>
Interface<TChar>::~Interface()
{}

} //!out

} //!test

#endif //!TEST_OUT_INTERFACE_H_