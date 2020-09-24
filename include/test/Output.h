#ifndef TEST_OUTPUT_H_
#define TEST_OUTPUT_H_

#include "Status.h"
#include "out/Base.h"
#include "out/Tag.h"

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cstdarg>
#include <type_traits>
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

template<typename Ts = Status>
class Output : protected test::out::Base<>
{
public:
    template<typename TChar>
    using LogType = typename test::out::Base<>::template LogType<TChar>;
private:
    bool m_enable;
    bool m_infoEnable;
    bool m_debugEnable;
    Ts* m_status;
public:
    Output(Ts& status);
    Output(Ts& status, const char* file_output);
public:
    Output(const Output<Ts>& cpy) = delete;
    Output(Output<Ts>&& mov);
public:
    ~Output();
public:
    Output<Ts>& operator=(const Output<Ts>& cpy) = delete;
    Output<Ts>& operator=(Output<Ts>&& mov) = delete;
public:
    void Set(Ts& status);
public:
    std::size_t VError(const char* format, va_list args) 
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));
    std::size_t VInfo(const char* format, va_list args) 
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));
    std::size_t VDebug(const char* format, va_list args)
        TEST_ATTRIBUTE((__format__ (__printf__, 2, 0)));
    std::size_t VError(const wchar_t* format, va_list args);
    std::size_t VInfo(const wchar_t* format, va_list args);
    std::size_t VDebug(const wchar_t* format, va_list args);
public:
    std::size_t Error(const char* format, ...) 
        TEST_ATTRIBUTE((__format__ (__printf__, 2, 3)));
    std::size_t Info(const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 2, 3)));
    std::size_t Debug(const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 2, 3)));
    std::size_t Error(const wchar_t* format, ...);
    std::size_t Info(const wchar_t* format, ...);
    std::size_t Debug(const wchar_t* format, ...);
public:
    template<typename TChar = char, typename TOutTag>
    LogType<TChar> Log(const TOutTag& tag);
public:
    template<typename TChar = char>
    LogType<TChar> Error();
    template<typename TChar = char>
    LogType<TChar> Info();
    template<typename TChar = char>
    LogType<TChar> Debug();
public:
    bool Enable() const;
    bool Enable(const test::out::tag::Error& tag) const;
    bool Enable(const test::out::tag::Info& tag) const;
    bool Enable(const test::out::tag::Debug& tag) const;
    void Enable(const bool& enable);
    void Enable(const test::out::tag::Error& tag, const bool& enable);
    void Enable(const test::out::tag::Info& tag, const bool& enable);
    void Enable(const test::out::tag::Debug& tag, const bool& enable);
public:
    bool InfoEnable();
    void InfoEnable(bool info_enable);
    bool DebugEnable();
    void DebugEnable(bool debug_enable);
};

template<typename Ts>
Output<Ts>::Output(Ts& status) :
    test::out::Base<>(),
    m_enable(true),
    m_infoEnable(true),
    m_debugEnable(true),
    m_status(&status)
{}

template<typename Ts>
Output<Ts>::Output(Ts& status, const char* file_output) :
    test::out::Base<>(file_output, 
        test::out::Base<>::FileType::mode_write),
    m_enable(true),
    m_infoEnable(true),
    m_debugEnable(true),
    m_status(&status)
{}

template<typename Ts>
Output<Ts>::Output(Output<Ts>&& mov) :
    test::out::Base<>(std::move(mov)),
    m_enable(mov.m_enable),
    m_infoEnable(mov.m_infoEnable),
    m_debugEnable(mov.m_debugEnable),
    m_status(NULL)
{
    mov.m_status = NULL;
}

template<typename Ts>
Output<Ts>::~Output()
{}

template<typename Ts>
void Output<Ts>::Set(Ts& status)
{
    assert(m_status == NULL);
    m_status = &status;
}

template<typename Ts>
std::size_t Output<Ts>::VError(const char* format, va_list args)
{
    assert(m_status != NULL);
    m_status->Error();
    if (m_enable)
    {
        auto&& err = test::out::Base<>::template Error<char>();
        return err.VPrint(format, args);
    }
    return 0;
}

template<typename Ts>
std::size_t Output<Ts>::VInfo(const char* format, va_list args) 
{
    if (m_enable && m_infoEnable)
    {
        auto&& info = test::out::Base<>::template Info<char>();
        return info.VPrint(format, args);
    }
    return 0;
}

template<typename Ts>
std::size_t Output<Ts>::VDebug(const char* format, va_list args)
{
    if (m_enable && m_debugEnable)
    {
        auto&& debug = test::out::Base<>::template Debug<char>();
        return debug.VPrint(format, args);
    }
    return 0;
}

template<typename Ts>
std::size_t Output<Ts>::VError(const wchar_t* format, va_list args)
{
    assert(m_status != NULL);
    m_status->Error();
    if (m_enable)
    {
        auto&& err = test::out::Base<>::template Error<wchar_t>();
        return err.VPrint(format, args);
    }
    return 0;
}

template<typename Ts>
std::size_t Output<Ts>::VInfo(const wchar_t* format, va_list args)
{
    if (m_enable && m_infoEnable)
    {
        auto&& info = test::out::Base<>::template Info<wchar_t>();
        return info.VPrint(format, args);
    }
    return 0;
}

template<typename Ts>
std::size_t Output<Ts>::VDebug(const wchar_t* format, va_list args)
{
    if (m_enable && m_debugEnable)
    {
        auto&& debug = test::out::Base<>::template Debug<wchar_t>();
        return debug.VPrint(format, args);
    }
    return 0;
}

template<typename Ts>
std::size_t Output<Ts>::Error(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    auto ret = VError(format, args);
    va_end(args);
    return ret;
}

template<typename Ts>
std::size_t Output<Ts>::Info(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    auto ret = VInfo(format, args);
    va_end(args);
    return ret;
}

template<typename Ts>
std::size_t Output<Ts>::Debug(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    auto ret = VDebug(format, args);
    va_end(args);
    return ret;
}

template<typename Ts>
std::size_t Output<Ts>::Error(const wchar_t* format, ...)
{
    va_list args;
    va_start(args, format);
    auto ret = VError(format, args);
    va_end(args);
    return ret;
}

template<typename Ts>
std::size_t Output<Ts>::Info(const wchar_t* format, ...)
{
    va_list args;
    va_start(args, format);
    auto ret = VInfo(format, args);
    va_end(args);
    return ret;
}

template<typename Ts>
std::size_t Output<Ts>::Debug(const wchar_t* format, ...)
{
    va_list args;
    va_start(args, format);
    auto ret = VDebug(format, args);
    va_end(args);
    return ret;
}

template<typename Ts>
template<typename TChar, typename TOutTag>
typename Output<Ts>::template LogType<TChar> 
Output<Ts>::Log(const TOutTag& tag)
{
    if (Enable(tag))
        return test::out::Base<>::template Log<TChar>(tag);
    LogType<TChar> out;
    out.End();
    return out;
}

template<typename Ts>
template<typename TChar>
typename Output<Ts>::template LogType<TChar> Output<Ts>::Error()
{
    assert(m_status != NULL);
    m_status->Error();
    if (m_enable)
        return test::out::Base<>::template Error<TChar>();
    LogType<TChar> out;
    out.End();
    return out;
}

template<typename Ts>
template<typename TChar>
typename Output<Ts>::template LogType<TChar> Output<Ts>::Info()
{
    if (InfoEnable())
        return test::out::Base<>::template Info<TChar>();
    LogType<TChar> out;
    out.End();
    return out;
}

template<typename Ts>
template<typename TChar>
typename Output<Ts>::template LogType<TChar> Output<Ts>::Debug()
{
    if (DebugEnable())
        return test::out::Base<>::template Debug<TChar>();
    LogType<TChar> out;
    out.End();
    return out;
}

template<typename Ts>
bool Output<Ts>::Enable() const
{
    return m_enable;
}

template<typename Ts>
bool Output<Ts>::Enable(const test::out::tag::Error&) const
{
    return m_enable;
}

template<typename Ts>
bool Output<Ts>::Enable(const test::out::tag::Info&) const
{
    return m_infoEnable;
}

template<typename Ts>
bool Output<Ts>::Enable(const test::out::tag::Debug&) const
{
    return m_debugEnable;
}

template<typename Ts>
void Output<Ts>::Enable(const bool& enable)
{
    m_enable = enable;
}

template<typename Ts>
void Output<Ts>::Enable(const test::out::tag::Error&, const bool&)
{}

template<typename Ts>
void Output<Ts>::Enable(const test::out::tag::Info&, 
    const bool& enable)
{
    m_infoEnable = enable;
}

template<typename Ts>
void Output<Ts>::Enable(const test::out::tag::Debug&, 
    const bool& enable)
{
    m_debugEnable = enable;
}

template<typename Ts>
bool Output<Ts>::InfoEnable()
{
    return m_infoEnable;
}

template<typename Ts>
void Output<Ts>::InfoEnable(bool info_enable)
{
    m_infoEnable = info_enable;
}

template<typename Ts>
bool Output<Ts>::DebugEnable()
{
    return m_debugEnable;
}

template<typename Ts>
void Output<Ts>::DebugEnable(bool debug_enable)
{
    m_debugEnable = debug_enable;
}

} //!test

#endif //!TEST_OUTPUT_H_
