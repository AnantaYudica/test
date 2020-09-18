#ifndef TEST_OUT_STANDARD_H_
#define TEST_OUT_STANDARD_H_

#include <cstdio>
#include <cstdarg>
#include <cstddef>
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
class Standard
{
public:
    typedef std::size_t SizeType; 
public:
    Standard() = default;
public:
    virtual ~Standard() = default;
public:
    Standard(const Standard<TChar>&) = delete;
    Standard(Standard<TChar>&&) = delete;
public:
    Standard<TChar>& operator=(const Standard<TChar>&) = delete;
    Standard<TChar>& operator=(Standard<TChar>&&) = delete;
};

template<>
class Standard<char>
{
public:
    typedef std::size_t SizeType; 
public:
    Standard() = default;
public:
    virtual ~Standard() = default;
public:
    Standard(const Standard<char>&) = delete;
    Standard(Standard<char>&&) = delete;
public:
    Standard<char>& operator=(const Standard<char>&) = delete;
    Standard<char>& operator=(Standard<char>&&) = delete;
public:
    virtual inline SizeType VPrint(const char * format, va_list var_args)
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0))) = 0;
    virtual inline SizeType Print(const char * format, ...) 
        TEST_ATTRIBUTE((format(printf, 2, 3))) = 0;
};

template<>
class Standard<wchar_t>
{
public:
    typedef std::size_t SizeType; 
public:
    Standard() = default;
public:
    virtual ~Standard() = default;
public:
    Standard(const Standard<wchar_t>&) = delete;
    Standard(Standard<wchar_t>&&) = delete;
public:
    Standard<wchar_t>& operator=(const Standard<wchar_t>&) = delete;
    Standard<wchar_t>& operator=(Standard<wchar_t>&&) = delete;
public:
    virtual inline SizeType VPrint(const wchar_t * format, 
        va_list var_args) = 0;
    virtual inline SizeType Print(const wchar_t * format, ...) = 0;
};

} //!out

} //!test

#endif //!TEST_OUT_STANDARD_H_
