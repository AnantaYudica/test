#ifndef TEST_OUT_STANDARD_H_
#define TEST_OUT_STANDARD_H_

#include <cstdio>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <type_traits>

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

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, char>::value, int>::type = 1>
inline int Print(const char * fmt, ...) TEST_ATTRIBUTE((format(printf, 1, 2)));

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, char>::value, int>::type = 1>
inline int FPrint(std::FILE* stream, const char * fmt, ...)
    TEST_ATTRIBUTE((format(printf, 2, 3)));

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, char>::value, int>::type = 1>
inline int SPrint(char * buff, std::size_t buff_size, const char * fmt, ...)
    TEST_ATTRIBUTE((format(printf, 3, 4)));

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, char>::value, int>::type = 1>
inline int VPrint(const char * fmt, va_list args) 
    TEST_ATTRIBUTE((format(printf, 1, 0)));

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, char>::value, int>::type = 1>
inline int VFPrint(std::FILE* stream, const char * fmt, va_list args)
    TEST_ATTRIBUTE((format(printf, 2, 0)));

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, char>::value, int>::type = 1>
inline int VSPrint(char * buff, std::size_t buff_size, const char * fmt, 
    va_list args) TEST_ATTRIBUTE((format(printf, 3, 0)));

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, wchar_t>::value, int>::type = 1>
inline int Print(const wchar_t * fmt, ...);

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, wchar_t>::value, int>::type = 1>
inline int FPrint(std::FILE* stream, const wchar_t * fmt, ...);

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, wchar_t>::value, int>::type = 1>
inline int SPrint(wchar_t * buff, std::size_t buff_size, 
    const wchar_t * fmt, ...);

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, wchar_t>::value, int>::type = 1>
inline int VPrint(const wchar_t * fmt, va_list args);

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, wchar_t>::value, int>::type = 1>
inline int VFPrint(std::FILE* stream, const wchar_t * fmt, va_list args);

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, wchar_t>::value, int>::type = 1>
inline int VSPrint(wchar_t * buff, std::size_t buff_size, 
    const wchar_t * fmt, va_list args);

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, char>::value, int>::type>
inline int Print(const char * fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    const int ret = test::out::VPrint<char>(fmt, args);
    va_end(args);
    return ret;
}

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, char>::value, int>::type>
inline int FPrint(std::FILE* stream, const char * fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    const int ret = VFPrint<char>(stream, fmt, args);
    va_end(args);
    return ret;
}

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, char>::value, int>::type>
inline int SPrint(char * buff, std::size_t buff_size, const char * fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    const int ret = VSPrint<char>(buff, buff_size, fmt, args);
    va_end(args);
    return ret;
}

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, char>::value, int>::type>
inline int VPrint(const char * fmt, va_list args)
{
    return std::vprintf(fmt, args);
}

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, char>::value, int>::type>
inline int VFPrint(std::FILE* stream, const char * fmt, va_list args)
{
    return std::vfprintf(stream, fmt, args);
}

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, char>::value, int>::type>
inline int VSPrint(char * buff, std::size_t buff_size, const char * fmt, 
    va_list args)
{
    return std::vsnprintf(buff, buff_size, fmt, args);
}

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, wchar_t>::value, int>::type>
inline int Print(const wchar_t * fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    const int ret = VPrint<wchar_t>(fmt, args);
    va_end(args);
    return ret;
}

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, wchar_t>::value, int>::type>
inline int FPrint(std::FILE* stream, const wchar_t * fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    const int ret = VFPrint<wchar_t>(stream, fmt, args);
    va_end(args);
    return ret;
}

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, wchar_t>::value, int>::type>
inline int SPrint(wchar_t * buff, std::size_t buff_size, 
    const wchar_t * fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    const int ret = VSPrint<wchar_t>(buff, buff_size, fmt, args);
    va_end(args);
    return ret;
}

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, wchar_t>::value, int>::type>
inline int VPrint(const wchar_t * fmt, va_list args)
{
    return std::vwprintf(fmt, args);
}

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, wchar_t>::value, int>::type>
inline int VFPrint(std::FILE* stream, const wchar_t * fmt, va_list args)
{
    return std::vfwprintf(stream, fmt, args);
}

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, wchar_t>::value, int>::type>
inline int VSPrint(wchar_t * buff, std::size_t buff_size, 
    const wchar_t * fmt, va_list args)
{
    return std::vswprintf(buff, buff_size, fmt, args);
}

} //!out

} //!test

#endif //!TEST_OUT_STANDARD_H_
