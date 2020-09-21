#ifndef TEST_OUT_LOG_H_
#define TEST_OUT_LOG_H_

#include "Interface.h"
#include "CString.h"
#include "../CString.h"
#include "log/Base.h"
#include "log/Status.h"
#include "log/Tag.h"
#include "log/Time.h"

#include <cstdint>
#include <chrono>
#include <ctime>
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

template<typename TChar>
class Log : 
    private test::out::log::Base<TChar>,
    public test::out::Interface<TChar>
{
private:
    typedef test::out::log::Base<TChar> BaseType;
public:
    typedef typename BaseType::OnBeginFunctionType OnBeginFunctionType;
    typedef typename BaseType::OnEndFunctionType OnEndFunctionType;
    typedef typename BaseType::DeleterFunctionType DeleterFunctionType;
    typedef typename BaseType::SizeType SizeType;
    typedef typename BaseType::StatusType StatusType;
    typedef typename BaseType::TagType TagType;
public:
    using BaseType::DefaultDeleter;
    using BaseType::Deleter;
public:
    Log();
    template<typename TTag>
    Log(TTag&& tag, OnBeginFunctionType * on_begin = nullptr,
        OnEndFunctionType * on_end = nullptr);

    template<typename TTag>
    Log(test::out::Interface<TChar> * out, TTag&& tag, 
        OnBeginFunctionType * on_begin = nullptr, 
        OnEndFunctionType * on_end = nullptr);

    template<typename TTag>
    Log(test::out::Interface<TChar> * out, DeleterFunctionType * deleter,
        TTag&& tag, OnBeginFunctionType * on_begin = nullptr,
        OnEndFunctionType * on_end = nullptr);

public:
    virtual ~Log();
public:
    Log(const Log<TChar>&) = delete;
    Log(Log<TChar>&& mov);
public:
    Log<TChar>& operator=(const Log<TChar>&) = delete;
    Log<TChar>& operator=(Log<TChar>&&) = delete;
public:
    using BaseType::GetTag;
    using BaseType::GetTimestamp;
    using BaseType::GetMessage;
private:
    using BaseType::_GetMessage;
public:
    using BaseType::GetOnBegin;
    using BaseType::GetOnEnd;
public:
    using BaseType::IsEnd;
public:
    bool IsGood() const override;
    bool IsBad() const override;
public:
    using BaseType::GetBadCode;
public:
    using BaseType::Output;
public:
    using BaseType::End;
protected:
    virtual bool OnBegin(test::out::Interface<TChar>& out) override;
    virtual bool OnEnd(test::out::Interface<TChar>& out) override;
public:
    virtual SizeType VPrint(const char * format, va_list var_args) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));
    virtual SizeType Print(const char * format, ...) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 3)));
public:
    virtual SizeType Puts(const TChar * cstr, const SizeType& size) override;
    virtual SizeType Puts(const TChar * cstr) override;
    virtual SizeType Puts(const test::CString<TChar>& cstr) override;
    virtual SizeType Puts(const test::CString<const TChar>& cstr) override;
};

template<>
class Log<char> : 
    private test::out::log::Base<char>,
    public test::out::Interface<char>
{
private:
    typedef test::out::log::Base<char> BaseType;
public:
    typedef typename BaseType::OnBeginFunctionType OnBeginFunctionType;
    typedef typename BaseType::OnEndFunctionType OnEndFunctionType;
    typedef typename BaseType::DeleterFunctionType DeleterFunctionType;
    typedef typename BaseType::SizeType SizeType;
    typedef typename BaseType::StatusType StatusType;
    typedef typename BaseType::TagType TagType;
public:
    static bool DefaultOnBegin(test::out::Interface<char>& out, 
        std::chrono::time_point<std::chrono::system_clock> timestamp, 
        test::CString<char> tag);
    static bool DefaultOnEnd(test::out::Interface<char>& out,
        std::chrono::time_point<std::chrono::system_clock> timestamp,
        test::CString<char> tag);
public:
    using BaseType::DefaultDeleter;
    using BaseType::Deleter;
public:
    Log();
    template<typename TTag>
    Log(TTag&& tag, 
        OnBeginFunctionType * on_begin = &Log<char>::DefaultOnBegin, 
        OnEndFunctionType * on_end = &Log<char>::DefaultOnEnd);

    template<typename TTag>
    Log(test::out::Interface<char> * out, TTag&& tag, 
        OnBeginFunctionType * on_begin = &Log<char>::DefaultOnBegin, 
        OnEndFunctionType * on_end = &Log<char>::DefaultOnEnd);

    template<typename TTag>
    Log(test::out::Interface<char> * out, DeleterFunctionType * deleter,
        TTag&& tag, 
        OnBeginFunctionType * on_begin = &Log<char>::DefaultOnBegin,
        OnEndFunctionType * on_end = &Log<char>::DefaultOnEnd);

public:
    virtual ~Log();
public:
    Log(const Log<char>&) = delete;
    Log(Log<char>&& mov);
public:
    Log<char>& operator=(const Log<char>&) = delete;
    Log<char>& operator=(Log<char>&&) = delete;
public:
    using BaseType::GetTag;
    using BaseType::GetTimestamp;
    using BaseType::GetMessage;
private:
    using BaseType::_GetMessage;
public:
    using BaseType::GetOnBegin;
    using BaseType::GetOnEnd;
public:
    using BaseType::IsEnd;
public:
    bool IsGood() const override;
    bool IsBad() const override;
public:
    using BaseType::GetBadCode;
public:
    using BaseType::Output;
public:
    using BaseType::End;
protected:
    virtual bool OnBegin(test::out::Interface<char>& out) override;
    virtual bool OnEnd(test::out::Interface<char>& out) override;
public:
    virtual SizeType VPrint(const char * format, va_list var_args) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));
    virtual SizeType Print(const char * format, ...) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 3)));
public:
    virtual SizeType Puts(const char * cstr, const SizeType& size) override;
    virtual SizeType Puts(const char * cstr) override;
    virtual SizeType Puts(const test::CString<char>& cstr) override;
    virtual SizeType Puts(const test::CString<const char>& cstr) override;
};

template<>
class Log<wchar_t> : 
    private test::out::log::Base<wchar_t>,
    public test::out::Interface<wchar_t>
{
private:
    typedef test::out::log::Base<wchar_t> BaseType;
public:
    typedef typename BaseType::OnBeginFunctionType OnBeginFunctionType;
    typedef typename BaseType::OnEndFunctionType OnEndFunctionType;
    typedef typename BaseType::DeleterFunctionType DeleterFunctionType;
    typedef typename BaseType::SizeType SizeType;
    typedef typename BaseType::StatusType StatusType;
    typedef typename BaseType::TagType TagType;
public:
    static bool DefaultOnBegin(test::out::Interface<wchar_t>& out, 
        std::chrono::time_point<std::chrono::system_clock> timestamp, 
        test::CString<wchar_t> tag);
    static bool DefaultOnEnd(test::out::Interface<wchar_t>& out,
        std::chrono::time_point<std::chrono::system_clock> timestamp,
        test::CString<wchar_t> tag);
public:
    using BaseType::DefaultDeleter;
    using BaseType::Deleter;
public:
    Log();
    template<typename TTag>
    Log(TTag&& tag, 
        OnBeginFunctionType * on_begin = &Log<wchar_t>::DefaultOnBegin,
        OnEndFunctionType * on_end = &Log<wchar_t>::DefaultOnEnd);

    template<typename TTag>
    Log(test::out::Interface<wchar_t> * out, TTag&& tag, 
        OnBeginFunctionType * on_begin = &Log<wchar_t>::DefaultOnBegin, 
        OnEndFunctionType * on_end = &Log<wchar_t>::DefaultOnEnd);

    template<typename TTag>
    Log(test::out::Interface<wchar_t> * out, DeleterFunctionType * deleter,
        TTag&& tag, 
        OnBeginFunctionType * on_begin = &Log<wchar_t>::DefaultOnBegin,
        OnEndFunctionType * on_end = &Log<wchar_t>::DefaultOnEnd);

public:
    virtual ~Log();
public:
    Log(const Log<wchar_t>&) = delete;
    Log(Log<wchar_t>&& mov);
public:
    Log<wchar_t>& operator=(const Log<wchar_t>&) = delete;
    Log<wchar_t>& operator=(Log<wchar_t>&&) = delete;
public:
    using BaseType::GetTag;
    using BaseType::GetTimestamp;
    using BaseType::GetMessage;
private:
    using BaseType::_GetMessage;
public:
    using BaseType::GetOnBegin;
    using BaseType::GetOnEnd;
public:
    using BaseType::IsEnd;
public:
    bool IsGood() const override;
    bool IsBad() const override;
public:
    using BaseType::GetBadCode;
public:
    using BaseType::Output;
public:
    using BaseType::End;
protected:
    virtual bool OnBegin(test::out::Interface<wchar_t>& out) override;
    virtual bool OnEnd(test::out::Interface<wchar_t>& out) override;
public:
    virtual SizeType VPrint(const wchar_t * format, va_list var_args) override;
    virtual SizeType Print(const wchar_t * format, ...) override;
public:
    virtual SizeType Puts(const wchar_t * cstr, const SizeType& size) override;
    virtual SizeType Puts(const wchar_t * cstr) override;
    virtual SizeType Puts(const test::CString<wchar_t>& cstr) override;
    virtual SizeType Puts(const test::CString<const wchar_t>& cstr) override;
};

template<typename TChar>
Log<TChar>::Log() :
    BaseType()
{}

template<typename TChar>
template<typename TTag>
Log<TChar>::Log(TTag&& tag, OnBeginFunctionType * on_begin, 
    OnEndFunctionType * on_end) :
        BaseType(std::forward<TTag>(tag), on_begin, on_end)
{}

template<typename TChar>
template<typename TTag>
Log<TChar>::Log(test::out::Interface<TChar> * out, TTag&& tag,
    OnBeginFunctionType * on_begin, OnEndFunctionType * on_end) :
        BaseType(out, std::forward<TTag>(tag), on_begin, on_end)
{}

template<typename TChar>
template<typename TTag>
Log<TChar>::Log(test::out::Interface<TChar> * out, 
    DeleterFunctionType * deleter, TTag&& tag,
    OnBeginFunctionType * on_begin, OnEndFunctionType * on_end) :
        BaseType(out, deleter, std::forward<TTag>(tag), on_begin, on_end)
{}

template<typename TChar>
Log<TChar>::~Log()
{}

template<typename TChar>
Log<TChar>::Log(Log<TChar>&& mov) :
    BaseType(std::move(mov)),
    test::out::Interface<TChar>()
{}

template<typename TChar>
bool Log<TChar>::IsGood() const
{
    return BaseType::IsGood();
}

template<typename TChar>
bool Log<TChar>::IsBad() const
{
    return BaseType::IsBad();
}

template<typename TChar>
bool Log<TChar>::OnBegin(test::out::Interface<TChar>& out)
{
    return BaseType::OnBegin(out);
}

template<typename TChar>
bool Log<TChar>::OnEnd(test::out::Interface<TChar>& out)
{
    return BaseType::OnEnd(out);
}

template<typename TChar>
typename Log<TChar>::SizeType 
Log<TChar>::VPrint(const char * format, va_list var_args)
{
    if (IsBad() || IsEnd()) return 0;
    return _GetMessage().VPrint(format, var_args);
}

template<typename TChar>
typename Log<TChar>::SizeType 
Log<TChar>::Print(const char * format, ...)
{
    if (IsBad() || IsEnd()) return 0;
    va_list args;
    va_start(args, format);
    const auto ret = _GetMessage().VPrint(format, args);
    va_end(args);
    return ret;
}

template<typename TChar>
typename Log<TChar>::SizeType 
Log<TChar>::Puts(const TChar * cstr, const SizeType& size)
{
    return BaseType::Puts(cstr, size);
}

template<typename TChar>
typename Log<TChar>::SizeType 
Log<TChar>::Puts(const TChar * cstr)
{
    return BaseType::Puts(cstr);
}

template<typename TChar>
typename Log<TChar>::SizeType 
Log<TChar>::Puts(const test::CString<TChar>& cstr)
{
    return BaseType::Puts(cstr);
}

template<typename TChar>
typename Log<TChar>::SizeType 
Log<TChar>::Puts(const test::CString<const TChar>& cstr)
{
    return BaseType::Puts(cstr);
}

bool Log<char>::DefaultOnBegin(test::out::Interface<char>& out, 
    std::chrono::time_point<std::chrono::system_clock> timestamp, 
    test::CString<char> tag)
{
    auto time_cstr = test::out::log::Time::CStr<char>(timestamp);
    if (time_cstr.Size() == 0) return false;
    auto out_size = out.Print("%s [%s] ", *time_cstr, *tag);
    return out_size != 0;
}

bool Log<char>::DefaultOnEnd(test::out::Interface<char>& out,
    std::chrono::time_point<std::chrono::system_clock>,
    test::CString<char>)
{
    return out.Puts("\n") != 0;
}

Log<char>::Log() :
    BaseType(&Log<char>::DefaultOnBegin, &Log<char>::DefaultOnEnd)
{}

template<typename TTag>
Log<char>::Log(TTag&& tag, OnBeginFunctionType * on_begin, 
    OnEndFunctionType * on_end) :
        BaseType(std::forward<TTag>(tag), 
            (on_begin == nullptr ? &Log<char>::DefaultOnBegin : on_begin), 
            (on_end == nullptr ? &Log<char>::DefaultOnEnd : on_end))
{}

template<typename TTag>
Log<char>::Log(test::out::Interface<char> * out, TTag&& tag,
    OnBeginFunctionType * on_begin, OnEndFunctionType * on_end) :
        BaseType(out, std::forward<TTag>(tag),
            (on_begin == nullptr ? &Log<char>::DefaultOnBegin : on_begin), 
            (on_end == nullptr ? &Log<char>::DefaultOnEnd : on_end))
{}

template<typename TTag>
Log<char>::Log(test::out::Interface<char> * out, 
    DeleterFunctionType * deleter, TTag&& tag,
    OnBeginFunctionType * on_begin, OnEndFunctionType * on_end) :
        BaseType(out, deleter, std::forward<TTag>(tag), 
            (on_begin == nullptr ? &Log<char>::DefaultOnBegin : on_begin), 
            (on_end == nullptr ? &Log<char>::DefaultOnEnd : on_end))
{}

Log<char>::~Log()
{}

Log<char>::Log(Log<char>&& mov) :
    BaseType(std::move(mov), &Log<char>::DefaultOnBegin, 
        &Log<char>::DefaultOnEnd),
    test::out::Interface<char>()
{}

bool Log<char>::IsGood() const
{
    return BaseType::IsGood();
}

bool Log<char>::IsBad() const
{
    return BaseType::IsBad();
}

bool Log<char>::OnBegin(test::out::Interface<char>& out)
{
    return BaseType::OnBegin(out);
}

bool Log<char>::OnEnd(test::out::Interface<char>& out)
{
    return BaseType::OnEnd(out);
}

typename Log<char>::SizeType 
Log<char>::VPrint(const char * format, va_list var_args)
{
    if (IsBad() || IsEnd()) return 0;
    return _GetMessage().VPrint(format, var_args);
}

typename Log<char>::SizeType 
Log<char>::Print(const char * format, ...)
{
    if (IsBad() || IsEnd()) return 0;
    va_list args;
    va_start(args, format);
    const auto ret = _GetMessage().VPrint(format, args);
    va_end(args);
    return ret;
}

typename Log<char>::SizeType 
Log<char>::Puts(const char * cstr, const SizeType& size)
{
    return BaseType::Puts(cstr, size);
}

typename Log<char>::SizeType 
Log<char>::Puts(const char * cstr)
{
    return BaseType::Puts(cstr);
}

typename Log<char>::SizeType 
Log<char>::Puts(const test::CString<char>& cstr)
{
    return BaseType::Puts(cstr);
}

typename Log<char>::SizeType 
Log<char>::Puts(const test::CString<const char>& cstr)
{
    return BaseType::Puts(cstr);
}

bool Log<wchar_t>::DefaultOnBegin(test::out::Interface<wchar_t>& out, 
    std::chrono::time_point<std::chrono::system_clock> timestamp, 
    test::CString<wchar_t> tag)
{
    auto time_cstr = test::out::log::Time::CStr<char>(timestamp);
    if (time_cstr.Size() == 0) return false;
    auto out_size = out.Print(L"%s [%s] ", *time_cstr, *tag);
    return out_size != 0;
}

bool Log<wchar_t>::DefaultOnEnd(test::out::Interface<wchar_t>& out,
    std::chrono::time_point<std::chrono::system_clock>,
    test::CString<wchar_t>)
{
    return out.Puts(L"\n") != 0;
}

Log<wchar_t>::Log() :
    BaseType(&Log<wchar_t>::DefaultOnBegin, &Log<wchar_t>::DefaultOnEnd)
{}

template<typename TTag>
Log<wchar_t>::Log(TTag&& tag, OnBeginFunctionType * on_begin, 
    OnEndFunctionType * on_end) :
        BaseType(std::forward<TTag>(tag),
            (on_begin == nullptr ? &Log<wchar_t>::DefaultOnBegin : on_begin), 
            (on_end == nullptr ? &Log<wchar_t>::DefaultOnEnd : on_end))
{}

template<typename TTag>
Log<wchar_t>::Log(test::out::Interface<wchar_t> * out, TTag&& tag,
    OnBeginFunctionType * on_begin, OnEndFunctionType * on_end) :
        BaseType(out, std::forward<TTag>(tag),  
            (on_begin == nullptr ? &Log<wchar_t>::DefaultOnBegin : on_begin), 
            (on_end == nullptr ? &Log<wchar_t>::DefaultOnEnd : on_end))
{}

template<typename TTag>
Log<wchar_t>::Log(test::out::Interface<wchar_t> * out, 
    DeleterFunctionType * deleter, TTag&& tag,
    OnBeginFunctionType * on_begin, OnEndFunctionType * on_end) :
        BaseType(out, deleter, std::forward<TTag>(tag),  
            (on_begin == nullptr ? &Log<wchar_t>::DefaultOnBegin : on_begin), 
            (on_end == nullptr ? &Log<wchar_t>::DefaultOnEnd : on_end))
{}

Log<wchar_t>::~Log()
{}

Log<wchar_t>::Log(Log<wchar_t>&& mov) :
    BaseType(std::move(mov), &Log<wchar_t>::DefaultOnBegin, 
        &Log<wchar_t>::DefaultOnEnd),
    test::out::Interface<wchar_t>()
{}

bool Log<wchar_t>::IsGood() const
{
    return BaseType::IsGood();
}

bool Log<wchar_t>::IsBad() const
{
    return BaseType::IsBad();
}

bool Log<wchar_t>::OnBegin(test::out::Interface<wchar_t>& out)
{
    return BaseType::OnBegin(out);
}

bool Log<wchar_t>::OnEnd(test::out::Interface<wchar_t>& out)
{
    return BaseType::OnEnd(out);
}

typename Log<wchar_t>::SizeType 
Log<wchar_t>::VPrint(const wchar_t * format, va_list var_args)
{
    if (IsBad() || IsEnd()) return 0;
    return _GetMessage().VPrint(format, var_args);
}

typename Log<wchar_t>::SizeType 
Log<wchar_t>::Print(const wchar_t * format, ...)
{
    if (IsBad() || IsEnd()) return 0;
    va_list args;
    va_start(args, format);
    const auto ret = _GetMessage().VPrint(format, args);
    va_end(args);
    return ret;
}

typename Log<wchar_t>::SizeType 
Log<wchar_t>::Puts(const wchar_t * cstr, const SizeType& size)
{
    return BaseType::Puts(cstr, size);
}

typename Log<wchar_t>::SizeType 
Log<wchar_t>::Puts(const wchar_t * cstr)
{
    return BaseType::Puts(cstr);
}

typename Log<wchar_t>::SizeType 
Log<wchar_t>::Puts(const test::CString<wchar_t>& cstr)
{
    return BaseType::Puts(cstr);
}

typename Log<wchar_t>::SizeType 
Log<wchar_t>::Puts(const test::CString<const wchar_t>& cstr)
{
    return BaseType::Puts(cstr);
}

} //!out

} //!test

#endif //!TEST_OUT_LOG_H_
