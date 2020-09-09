#ifndef TEST_OUT_LOG_H_
#define TEST_OUT_LOG_H_

#include "Interface.h"
#include "CString.h"
#include "../CString.h"
#include "log/Status.h"
#include "log/Tag.h"

#include <cstdint>
#include <chrono>
#include <ctime>
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

template<typename TChar>
class Log : public test::out::Interface<TChar>
{
public:
    typedef bool (OnBeginFunctionType)(test::out::Interface<TChar>&,
        std::chrono::time_point<std::chrono::system_clock>, test::CString<TChar>);
    typedef bool (OnEndFunctionType)(test::out::Interface<TChar>&,
        std::chrono::time_point<std::chrono::system_clock>, test::CString<TChar>);
    typedef void (DeleterFunctionType)(test::out::Interface<TChar> *);
    typedef typename test::out::Interface<TChar>::SizeType SizeType;
    typedef test::out::log::Status<std::uint8_t> StatusType;
    typedef test::out::log::Tag TagType;
public:
    static bool DefaultOnBegin(test::out::Interface<TChar>& out, 
        std::chrono::time_point<std::chrono::system_clock> timestamp, 
        test::CString<TChar> tag);
    static bool DefaultOnEnd(test::out::Interface<TChar>& out,
        std::chrono::time_point<std::chrono::system_clock> timestamp,
        test::CString<TChar> tag);
    static void DefaultDeleter(test::out::Interface<TChar> * out);
    static void Deleter(test::out::Interface<TChar> * out);
private:
    StatusType m_status;
    test::out::Interface<TChar> * m_out;
    OnBeginFunctionType * m_on_begin;
    OnEndFunctionType * m_on_end;
    DeleterFunctionType * m_deleter;
    std::chrono::time_point<std::chrono::system_clock> m_timestamp;
    test::CString<TChar> m_tag;
    test::out::CString<TChar> m_message;
public:
    Log();
    template<std::size_t S>
    Log(const TChar(&tag)[S],
        OnBeginFunctionType * on_begin = &Log<TChar>::DefaultOnBegin, 
        OnEndFunctionType * on_end = &Log<TChar>::DefaultOnEnd);
    Log(const test::CString<TChar>& tag, 
        OnBeginFunctionType * on_begin = &Log<TChar>::DefaultOnBegin,
        OnEndFunctionType * on_end = &Log<TChar>::DefaultOnEnd);
    Log(const TagType& tag, 
        OnBeginFunctionType * on_begin = &Log<TChar>::DefaultOnBegin,
        OnEndFunctionType * on_end = &Log<TChar>::DefaultOnEnd);

    template<std::size_t S>
    Log(test::out::Interface<TChar> * out, const TChar(&tag)[S], 
        OnBeginFunctionType * on_begin = &Log<TChar>::DefaultOnBegin, 
        OnEndFunctionType * on_end = &Log<TChar>::DefaultOnEnd);
    Log(test::out::Interface<TChar> * out, const test::CString<TChar>& tag, 
        OnBeginFunctionType * on_begin = &Log<TChar>::DefaultOnBegin, 
        OnEndFunctionType * on_end = &Log<TChar>::DefaultOnEnd);
    Log(test::out::Interface<TChar> * out, const TagType& tag, 
        OnBeginFunctionType * on_begin = &Log<TChar>::DefaultOnBegin, 
        OnEndFunctionType * on_end = &Log<TChar>::DefaultOnEnd);

    template<std::size_t S>
    Log(test::out::Interface<TChar> * out, DeleterFunctionType * deleter,
        const TChar(&tag)[S], 
        OnBeginFunctionType * on_begin = &Log<TChar>::DefaultOnBegin, 
        OnEndFunctionType * on_end = &Log<TChar>::DefaultOnEnd);
    Log(test::out::Interface<TChar> * out, DeleterFunctionType * deleter,
        const test::CString<TChar>& tag, 
        OnBeginFunctionType * on_begin = &Log<TChar>::DefaultOnBegin, 
        OnEndFunctionType * on_end = &Log<TChar>::DefaultOnEnd);
    Log(test::out::Interface<TChar> * out, DeleterFunctionType * deleter,
        const TagType& tag, 
        OnBeginFunctionType * on_begin = &Log<TChar>::DefaultOnBegin, 
        OnEndFunctionType * on_end = &Log<TChar>::DefaultOnEnd);

public:
    virtual ~Log();
public:
    Log(const Log<TChar>&) = delete;
    Log(Log<TChar>&& mov);
public:
    Log<TChar>& operator=(const Log<TChar>&) = delete;
    Log<TChar>& operator=(Log<TChar>&&) = delete;
private:
    bool _Output(test::out::Interface<TChar>& out, StatusType& status);
public:
    test::CString<TChar> GetTag() const;
    std::chrono::time_point<std::chrono::system_clock> GetTimestamp() const;
    test::CString<TChar> GetMessage() const;
public:
    OnBeginFunctionType * GetOnBegin() const;
    OnEndFunctionType * GetOnEnd() const;
public:
    bool IsEnd() const;
    bool IsGood() const override;
    bool IsBad() const override;
    typename StatusType::IntegerValueType GetBadCode() const;
public:
    bool Output(test::out::Interface<TChar>& out);
public:
    bool End();
protected:
    virtual bool OnBegin(test::out::Interface<TChar>& out);
    virtual bool OnEnd(test::out::Interface<TChar>& out);
public:
    virtual SizeType VPrint(const char * format, va_list var_args) override
        __ATTRIBUTE__ ((__format__ (__printf__, 2, 0)));
    virtual SizeType Print(const char * format, ...) override
        __ATTRIBUTE__ ((__format__ (__printf__, 2, 3)));
public:
    virtual SizeType Puts(const TChar * cstr, const SizeType& size) override;
    virtual SizeType Puts(const TChar * cstr) override;
    virtual SizeType Puts(const test::CString<TChar>& cstr) override;
    virtual SizeType Puts(const test::CString<const TChar>& cstr) override;
};

template<typename TChar>
bool Log<TChar>::DefaultOnBegin(test::out::Interface<TChar>& out, 
    std::chrono::time_point<std::chrono::system_clock> timestamp, 
    test::CString<TChar> tag)
{
    using namespace std::chrono;
    auto time = system_clock::to_time_t(timestamp);
    struct tm * timeinfo;
    timeinfo = std::localtime (&time);
    TChar * tmp = new TChar[64];
    const auto size = strftime(tmp, 64, "%F %X", timeinfo);
    if (size >= 64)
    {
        delete[] tmp;
        tmp = new TChar[size + 1];
        strftime(tmp, size + 1, "%F %X", timeinfo);
    }
    auto out_size = out.Puts(tmp, size);
    delete[] tmp;
    if (out_size == 0) return false;
    auto tp_msec = time_point_cast<milliseconds>(timestamp);
    auto d_msec = duration_cast<milliseconds>(tp_msec.time_since_epoch());
    auto tp_sec = time_point_cast<seconds>(timestamp);
    auto d_sec = duration_cast<seconds>(tp_sec.time_since_epoch());
    std::chrono::milliseconds::rep msec = d_msec.count() - 
        std::chrono::milliseconds::rep(d_sec.count() * 1000);
    out_size = out.Print(".%03llu [%s] : ", msec, *tag);
    return out_size != 0;
}

template<typename TChar>
bool Log<TChar>::DefaultOnEnd(test::out::Interface<TChar>& out, 
    std::chrono::time_point<std::chrono::system_clock>,
    test::CString<TChar>)
{
    return out.Puts("\n") != 0;
}

template<typename TChar>
void Log<TChar>::DefaultDeleter(test::out::Interface<TChar> *)
{}

template<typename TChar>
void Log<TChar>::Deleter(test::out::Interface<TChar> * out)
{
    delete out;
}

template<typename TChar>
Log<TChar>::Log() :
    m_status(),
    m_out(nullptr),
    m_on_begin(&Log<TChar>::DefaultOnBegin),
    m_on_end(&Log<TChar>::DefaultOnEnd),
    m_deleter(&Log<TChar>::DefaultDeleter),
    m_timestamp(std::chrono::system_clock::now()),
    m_tag("Undefined"),
    m_message()
{}

template<typename TChar>
template<std::size_t S>
Log<TChar>::Log(const TChar(&tag)[S], OnBeginFunctionType * on_begin, 
    OnEndFunctionType * on_end) :
        m_status(),
        m_out(nullptr),
        m_on_begin(on_begin == nullptr ? 
            &Log<TChar>::DefaultOnBegin : on_begin),
        m_on_end(on_end == nullptr ?
            &Log<TChar>::DefaultOnEnd : on_end),
        m_deleter(&Log<TChar>::DefaultDeleter),
        m_timestamp(std::chrono::system_clock::now()),
        m_tag(tag),
        m_message()
{}
    
template<typename TChar>
Log<TChar>::Log(const test::CString<TChar>& tag, 
    OnBeginFunctionType * on_begin, OnEndFunctionType * on_end) :
        m_status(),
        m_out(nullptr),
        m_on_begin(on_begin == nullptr ? 
            &Log<TChar>::DefaultOnBegin : on_begin),
        m_on_end(on_end == nullptr ?
            &Log<TChar>::DefaultOnEnd : on_end),
        m_deleter(&Log<TChar>::DefaultDeleter),
        m_timestamp(std::chrono::system_clock::now()),
        m_tag(tag),
        m_message()
{}

template<typename TChar>
Log<TChar>::Log(const TagType& tag, OnBeginFunctionType * on_begin, 
    OnEndFunctionType * on_end) :
        m_status(),
        m_out(nullptr),
        m_on_begin(on_begin == nullptr ? 
            &Log<TChar>::DefaultOnBegin : on_begin),
        m_on_end(on_end == nullptr ?
            &Log<TChar>::DefaultOnEnd : on_end),
        m_deleter(&Log<TChar>::DefaultDeleter),
        m_timestamp(std::chrono::system_clock::now()),
        m_tag(tag.GetName(), tag.GetNameSize()),
        m_message()
{}
    
template<typename TChar>
template<std::size_t S>
Log<TChar>::Log(test::out::Interface<TChar> * out, const TChar(&tag)[S],
    OnBeginFunctionType * on_begin, OnEndFunctionType * on_end) :
        m_status(),
        m_out(out),
        m_on_begin(on_begin == nullptr ? 
            &Log<TChar>::DefaultOnBegin : on_begin),
        m_on_end(on_end == nullptr ?
            &Log<TChar>::DefaultOnEnd : on_end),
        m_deleter(&Log<TChar>::DefaultDeleter),
        m_timestamp(std::chrono::system_clock::now()),
        m_tag(tag),
        m_message()
{}
    
template<typename TChar>
Log<TChar>::Log(test::out::Interface<TChar> * out, 
    const test::CString<TChar>& tag, OnBeginFunctionType * on_begin, 
    OnEndFunctionType * on_end) :
        m_status(),
        m_out(out),
        m_on_begin(on_begin == nullptr ? 
            &Log<TChar>::DefaultOnBegin : on_begin),
        m_on_end(on_end == nullptr ?
            &Log<TChar>::DefaultOnEnd : on_end),
        m_deleter(&Log<TChar>::DefaultDeleter),
        m_timestamp(std::chrono::system_clock::now()),
        m_tag(tag),
        m_message()
{}

template<typename TChar>
Log<TChar>::Log(test::out::Interface<TChar> * out, const TagType& tag, 
    OnBeginFunctionType * on_begin, OnEndFunctionType * on_end) :
        m_status(),
        m_out(out),
        m_on_begin(on_begin == nullptr ? 
            &Log<TChar>::DefaultOnBegin : on_begin),
        m_on_end(on_end == nullptr ?
            &Log<TChar>::DefaultOnEnd : on_end),
        m_deleter(&Log<TChar>::DefaultDeleter),
        m_timestamp(std::chrono::system_clock::now()),
        m_tag(tag.GetName(), tag.GetNameSize()),
        m_message()
{}
    
template<typename TChar>
template<std::size_t S>
Log<TChar>::Log(test::out::Interface<TChar> * out, 
    DeleterFunctionType * deleter, const TChar(&tag)[S],
    OnBeginFunctionType * on_begin, OnEndFunctionType * on_end) :
        m_status(),
        m_out(out),
        m_on_begin(on_begin == nullptr ? 
            &Log<TChar>::DefaultOnBegin : on_begin),
        m_on_end(on_end == nullptr ?
            &Log<TChar>::DefaultOnEnd : on_end),
        m_deleter(deleter == nullptr ?
            &Log<TChar>::DefaultDeleter : deleter),
        m_timestamp(std::chrono::system_clock::now()),
        m_tag(tag),
        m_message()
{}
    
template<typename TChar>
Log<TChar>::Log(test::out::Interface<TChar> * out, 
    DeleterFunctionType * deleter, const test::CString<TChar>& tag, 
    OnBeginFunctionType * on_begin, OnEndFunctionType * on_end) :
        m_status(),
        m_out(out),
        m_on_begin(on_begin == nullptr ? 
            &Log<TChar>::DefaultOnBegin : on_begin),
        m_on_end(on_end == nullptr ?
            &Log<TChar>::DefaultOnEnd : on_end),
        m_deleter(deleter == nullptr ?
            &Log<TChar>::DefaultDeleter : deleter),
        m_timestamp(std::chrono::system_clock::now()),
        m_tag(tag),
        m_message()
{}

template<typename TChar>
Log<TChar>::Log(test::out::Interface<TChar> * out, 
    DeleterFunctionType * deleter, const TagType& tag, 
    OnBeginFunctionType * on_begin, OnEndFunctionType * on_end) :
        m_status(),
        m_out(out),
        m_on_begin(on_begin == nullptr ? 
            &Log<TChar>::DefaultOnBegin : on_begin),
        m_on_end(on_end == nullptr ?
            &Log<TChar>::DefaultOnEnd : on_end),
        m_deleter(deleter == nullptr ?
            &Log<TChar>::DefaultDeleter : deleter),
        m_timestamp(std::chrono::system_clock::now()),
        m_tag(tag.GetName(), tag.GetNameSize()),
        m_message()
{}

template<typename TChar>
Log<TChar>::~Log()
{
    End();
    if (m_out != nullptr)
    {
        m_deleter(m_out);
        m_out = nullptr;
    }
}

template<typename TChar>
Log<TChar>::Log(Log<TChar>&& mov) :
    m_status(std::move(mov.m_status)),
    m_out(mov.m_out),
    m_on_begin(mov.m_on_begin),
    m_on_end(mov.m_on_end),
    m_deleter(mov.m_deleter),
    m_timestamp(mov.m_timestamp),
    m_tag(std::move(mov.m_tag)),
    m_message(std::move(mov.m_message))
{
    mov.m_out = nullptr;
    mov.m_on_begin = &Log<TChar>::DefaultOnBegin;
    mov.m_on_end = &Log<TChar>::DefaultOnEnd;
    mov.m_deleter = &Log<TChar>::DefaultDeleter;
    mov.m_timestamp = std::chrono::system_clock::now();
    mov.m_tag = "Undefined";
}

template<typename TChar>
bool Log<TChar>::_Output(test::out::Interface<TChar>& out, StatusType& status)
{
    if (!OnBegin(out))
    {
        status.Bad(StatusType::on_begin_failed);
        return false;
    }
    if (!status.Begin())
    {
        status.Bad(StatusType::set_begin_failed);
        return false;
    }
    if (!m_message.Output(out))
    {
        status.Bad(StatusType::message_failed);
        return false;
    }
    if (!OnEnd(out))
    {
        status.Bad(StatusType::on_end_failed);
        return false;
    }
    if (!status.End())
    {
        status.Bad(StatusType::set_end_failed);
        return false;
    }
    return true;
}

template<typename TChar>
test::CString<TChar> Log<TChar>::GetTag() const
{
    return {m_tag};
}

template<typename TChar>
std::chrono::time_point<std::chrono::system_clock> 
Log<TChar>::GetTimestamp() const
{
    return m_timestamp;
}

template<typename TChar>
test::CString<TChar> Log<TChar>::GetMessage() const
{
    return {m_message.Get()};
}

template<typename TChar>
typename Log<TChar>::OnBeginFunctionType * 
Log<TChar>::GetOnBegin() const
{
    return m_on_begin;
}

template<typename TChar>
typename Log<TChar>::OnEndFunctionType * 
Log<TChar>::GetOnEnd() const
{
    return m_on_end;
}

template<typename TChar>
bool Log<TChar>::IsEnd() const
{
    return m_status.IsEnd();
}

template<typename TChar>
bool Log<TChar>::IsGood() const
{
    return m_status.IsGood();
}

template<typename TChar>
bool Log<TChar>::IsBad() const
{
    return m_status.IsBad();
}

template<typename TChar>
typename Log<TChar>::StatusType::IntegerValueType 
Log<TChar>::GetBadCode() const
{
    return m_status.GetBadCode();
}

template<typename TChar>
bool Log<TChar>::End()
{
    if (m_out == nullptr)
    {
        m_status.Bad(StatusType::output_undefined);
        return false;
    }
    if (!m_status.IsBad() && !m_status.IsBegin())
    {
        return _Output(*m_out, m_status);
    }
    return false;
}

template<typename TChar>
bool Log<TChar>::Output(test::out::Interface<TChar>& out)
{
    StatusType status;
    return _Output(out, status);
}

template<typename TChar>
bool Log<TChar>::OnBegin(test::out::Interface<TChar>& out)
{
    return m_on_begin(out, m_timestamp, m_tag);
}

template<typename TChar>
bool Log<TChar>::OnEnd(test::out::Interface<TChar>& out)
{
    return m_on_end(out, m_timestamp, m_tag);
}

template<typename TChar>
typename Log<TChar>::SizeType 
Log<TChar>::VPrint(const char * format, va_list var_args)
{
    if (m_status.IsBad() || m_status.IsEnd()) return 0;
    return m_message.VPrint(format, var_args);
}

template<typename TChar>
typename Log<TChar>::SizeType 
Log<TChar>::Print(const char * format, ...)
{
    if (m_status.IsBad() || m_status.IsEnd()) return 0;
    va_list args;
    va_start(args, format);
    const auto ret = m_message.VPrint(format, args);
    va_end(args);
    return ret;
}

template<typename TChar>
typename Log<TChar>::SizeType 
Log<TChar>::Puts(const TChar * cstr, const SizeType& size)
{
    if (m_status.IsBad() || m_status.IsEnd()) return 0;
    return m_message.Puts(cstr, size);
}

template<typename TChar>
typename Log<TChar>::SizeType 
Log<TChar>::Puts(const TChar * cstr)
{
    if (m_status.IsBad() || m_status.IsEnd()) return 0;
    return m_message.Puts(cstr);
}

template<typename TChar>
typename Log<TChar>::SizeType 
Log<TChar>::Puts(const test::CString<TChar>& cstr)
{
    if (m_status.IsBad() || m_status.IsEnd()) return 0;
    return m_message.Puts(cstr);
}

template<typename TChar>
typename Log<TChar>::SizeType 
Log<TChar>::Puts(const test::CString<const TChar>& cstr)
{
    if (m_status.IsBad() || m_status.IsEnd()) return 0;
    return m_message.Puts(cstr);
}

} //!out

} //!test

#endif //!TEST_OUT_LOG_H_
