#ifndef TEST_OUT_LOG_BASE_H_
#define TEST_OUT_LOG_BASE_H_

#include "../../CString.h"
#include "../Interface.h"
#include "../CString.h"
#include "Status.h"
#include "Tag.h"

#include <cstdint>
#include <chrono>
#include <ctime>
#include <utility>

namespace test
{
namespace out
{
namespace log
{

template<typename TChar>
class Base
{
public:
    typedef bool (OnBeginFunctionType)(test::out::Interface<TChar>&,
        std::chrono::time_point<std::chrono::system_clock>, test::CString<TChar>);
    typedef bool (OnEndFunctionType)(test::out::Interface<TChar>&,
        std::chrono::time_point<std::chrono::system_clock>, test::CString<TChar>);
    typedef void (DeleterFunctionType)(test::out::Interface<TChar> *);
    typedef typename test::out::Interface<TChar>::SizeType SizeType;
    typedef test::out::log::Status<std::uint8_t> StatusType;
    typedef test::out::log::Tag<TChar> TagType;
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
protected:
    Base();
    Base(OnBeginFunctionType * on_begin, OnEndFunctionType * on_end);
    template<std::size_t S>
    Base(const TChar(&tag)[S], OnBeginFunctionType * on_begin, 
        OnEndFunctionType * on_end);
    Base(const test::CString<TChar>& tag, OnBeginFunctionType * on_begin,
        OnEndFunctionType * on_end);
    Base(const TagType& tag, OnBeginFunctionType * on_begin,
        OnEndFunctionType * on_end);

    template<std::size_t S>
    Base(test::out::Interface<TChar> * out, const TChar(&tag)[S], 
        OnBeginFunctionType * on_begin, OnEndFunctionType * on_end);
    Base(test::out::Interface<TChar> * out, const test::CString<TChar>& tag,
        OnBeginFunctionType * on_begin, OnEndFunctionType * on_end);
    Base(test::out::Interface<TChar> * out, const TagType& tag, 
        OnBeginFunctionType * on_begin, OnEndFunctionType * on_end);

    template<std::size_t S>
    Base(test::out::Interface<TChar> * out, DeleterFunctionType * deleter,
        const TChar(&tag)[S], OnBeginFunctionType * on_begin, 
        OnEndFunctionType * on_end);
    Base(test::out::Interface<TChar> * out, DeleterFunctionType * deleter,
        const test::CString<TChar>& tag, OnBeginFunctionType * on_begin, 
        OnEndFunctionType * on_end);
    Base(test::out::Interface<TChar> * out, DeleterFunctionType * deleter,
        const TagType& tag, OnBeginFunctionType * on_begin, 
        OnEndFunctionType * on_end);

public:
    virtual ~Base();
public:
    Base(const Base<TChar>&) = delete;
protected:
    Base(Base<TChar>&& mov);
    Base(Base<TChar>&& mov, OnBeginFunctionType * on_begin, 
        OnEndFunctionType * on_end);
public:
    Base<TChar>& operator=(const Base<TChar>&) = delete;
    Base<TChar>& operator=(Base<TChar>&&) = delete;
private:
    bool _Output(test::out::Interface<TChar>& out, StatusType& status);
public:
    test::CString<TChar> GetTag() const;
    std::chrono::time_point<std::chrono::system_clock> GetTimestamp() const;
    test::CString<TChar> GetMessage() const;
protected:
    test::out::CString<TChar>& _GetMessage();
public:
    OnBeginFunctionType * GetOnBegin() const;
    OnEndFunctionType * GetOnEnd() const;
public:
    bool IsEnd() const;
    bool IsGood() const;
    bool IsBad() const;
    typename StatusType::IntegerValueType GetBadCode() const;
public:
    bool Output(test::out::Interface<TChar>& out);
public:
    bool End();
protected:
    virtual bool OnBegin(test::out::Interface<TChar>& out);
    virtual bool OnEnd(test::out::Interface<TChar>& out);
public:
    SizeType Puts(const TChar * cstr, const SizeType& size);
    SizeType Puts(const TChar * cstr);
    SizeType Puts(const test::CString<TChar>& cstr);
    SizeType Puts(const test::CString<const TChar>& cstr);
};

template<typename TChar>
bool Base<TChar>::DefaultOnBegin(test::out::Interface<TChar>&, 
    std::chrono::time_point<std::chrono::system_clock>, 
    test::CString<TChar>)
{
    return true;
}

template<typename TChar>
bool Base<TChar>::DefaultOnEnd(test::out::Interface<TChar>&, 
    std::chrono::time_point<std::chrono::system_clock>,
    test::CString<TChar>)
{
    return true;
}

template<typename TChar>
void Base<TChar>::DefaultDeleter(test::out::Interface<TChar> *)
{}

template<typename TChar>
void Base<TChar>::Deleter(test::out::Interface<TChar> * out)
{
    delete out;
}

template<typename TChar>
Base<TChar>::Base() :
    m_status(),
    m_out(nullptr),
    m_on_begin(&Base<TChar>::DefaultOnBegin),
    m_on_end(&Base<TChar>::DefaultOnEnd),
    m_deleter(&Base<TChar>::DefaultDeleter),
    m_timestamp(std::chrono::system_clock::now()),
    m_tag(TagType{}.GetName(), TagType{}.GetNameSize()),
    m_message()
{}

template<typename TChar>
Base<TChar>::Base(OnBeginFunctionType * on_begin, OnEndFunctionType * on_end) :
    m_status(),
    m_out(nullptr),
    m_on_begin(on_begin == nullptr ? 
        &Base<TChar>::DefaultOnBegin : on_begin),
    m_on_end(on_end == nullptr ?
        &Base<TChar>::DefaultOnEnd : on_end),
    m_deleter(&Base<TChar>::DefaultDeleter),
    m_timestamp(std::chrono::system_clock::now()),
    m_tag(TagType{}.GetName(), TagType{}.GetNameSize()),
    m_message()
{}

template<typename TChar>
template<std::size_t S>
Base<TChar>::Base(const TChar(&tag)[S], OnBeginFunctionType * on_begin, 
    OnEndFunctionType * on_end) :
        m_status(),
        m_out(nullptr),
        m_on_begin(on_begin == nullptr ? 
            &Base<TChar>::DefaultOnBegin : on_begin),
        m_on_end(on_end == nullptr ?
            &Base<TChar>::DefaultOnEnd : on_end),
        m_deleter(&Base<TChar>::DefaultDeleter),
        m_timestamp(std::chrono::system_clock::now()),
        m_tag(tag),
        m_message()
{}
    
template<typename TChar>
Base<TChar>::Base(const test::CString<TChar>& tag, 
    OnBeginFunctionType * on_begin, OnEndFunctionType * on_end) :
        m_status(),
        m_out(nullptr),
        m_on_begin(on_begin == nullptr ? 
            &Base<TChar>::DefaultOnBegin : on_begin),
        m_on_end(on_end == nullptr ?
            &Base<TChar>::DefaultOnEnd : on_end),
        m_deleter(&Base<TChar>::DefaultDeleter),
        m_timestamp(std::chrono::system_clock::now()),
        m_tag(tag),
        m_message()
{}

template<typename TChar>
Base<TChar>::Base(const TagType& tag, OnBeginFunctionType * on_begin, 
    OnEndFunctionType * on_end) :
        m_status(),
        m_out(nullptr),
        m_on_begin(on_begin == nullptr ? 
            &Base<TChar>::DefaultOnBegin : on_begin),
        m_on_end(on_end == nullptr ?
            &Base<TChar>::DefaultOnEnd : on_end),
        m_deleter(&Base<TChar>::DefaultDeleter),
        m_timestamp(std::chrono::system_clock::now()),
        m_tag(tag.GetName(), tag.GetNameSize()),
        m_message()
{}
    
template<typename TChar>
template<std::size_t S>
Base<TChar>::Base(test::out::Interface<TChar> * out, const TChar(&tag)[S],
    OnBeginFunctionType * on_begin, OnEndFunctionType * on_end) :
        m_status(),
        m_out(out),
        m_on_begin(on_begin == nullptr ? 
            &Base<TChar>::DefaultOnBegin : on_begin),
        m_on_end(on_end == nullptr ?
            &Base<TChar>::DefaultOnEnd : on_end),
        m_deleter(&Base<TChar>::DefaultDeleter),
        m_timestamp(std::chrono::system_clock::now()),
        m_tag(tag),
        m_message()
{}
    
template<typename TChar>
Base<TChar>::Base(test::out::Interface<TChar> * out, 
    const test::CString<TChar>& tag, OnBeginFunctionType * on_begin, 
    OnEndFunctionType * on_end) :
        m_status(),
        m_out(out),
        m_on_begin(on_begin == nullptr ? 
            &Base<TChar>::DefaultOnBegin : on_begin),
        m_on_end(on_end == nullptr ?
            &Base<TChar>::DefaultOnEnd : on_end),
        m_deleter(&Base<TChar>::DefaultDeleter),
        m_timestamp(std::chrono::system_clock::now()),
        m_tag(tag),
        m_message()
{}

template<typename TChar>
Base<TChar>::Base(test::out::Interface<TChar> * out, const TagType& tag, 
    OnBeginFunctionType * on_begin, OnEndFunctionType * on_end) :
        m_status(),
        m_out(out),
        m_on_begin(on_begin == nullptr ? 
            &Base<TChar>::DefaultOnBegin : on_begin),
        m_on_end(on_end == nullptr ?
            &Base<TChar>::DefaultOnEnd : on_end),
        m_deleter(&Base<TChar>::DefaultDeleter),
        m_timestamp(std::chrono::system_clock::now()),
        m_tag(tag.GetName(), tag.GetNameSize()),
        m_message()
{}
    
template<typename TChar>
template<std::size_t S>
Base<TChar>::Base(test::out::Interface<TChar> * out, 
    DeleterFunctionType * deleter, const TChar(&tag)[S],
    OnBeginFunctionType * on_begin, OnEndFunctionType * on_end) :
        m_status(),
        m_out(out),
        m_on_begin(on_begin == nullptr ? 
            &Base<TChar>::DefaultOnBegin : on_begin),
        m_on_end(on_end == nullptr ?
            &Base<TChar>::DefaultOnEnd : on_end),
        m_deleter(deleter == nullptr ?
            &Base<TChar>::DefaultDeleter : deleter),
        m_timestamp(std::chrono::system_clock::now()),
        m_tag(tag),
        m_message()
{}
    
template<typename TChar>
Base<TChar>::Base(test::out::Interface<TChar> * out, 
    DeleterFunctionType * deleter, const test::CString<TChar>& tag, 
    OnBeginFunctionType * on_begin, OnEndFunctionType * on_end) :
        m_status(),
        m_out(out),
        m_on_begin(on_begin == nullptr ? 
            &Base<TChar>::DefaultOnBegin : on_begin),
        m_on_end(on_end == nullptr ?
            &Base<TChar>::DefaultOnEnd : on_end),
        m_deleter(deleter == nullptr ?
            &Base<TChar>::DefaultDeleter : deleter),
        m_timestamp(std::chrono::system_clock::now()),
        m_tag(tag),
        m_message()
{}

template<typename TChar>
Base<TChar>::Base(test::out::Interface<TChar> * out, 
    DeleterFunctionType * deleter, const TagType& tag, 
    OnBeginFunctionType * on_begin, OnEndFunctionType * on_end) :
        m_status(),
        m_out(out),
        m_on_begin(on_begin == nullptr ? 
            &Base<TChar>::DefaultOnBegin : on_begin),
        m_on_end(on_end == nullptr ?
            &Base<TChar>::DefaultOnEnd : on_end),
        m_deleter(deleter == nullptr ?
            &Base<TChar>::DefaultDeleter : deleter),
        m_timestamp(std::chrono::system_clock::now()),
        m_tag(tag.GetName(), tag.GetNameSize()),
        m_message()
{}

template<typename TChar>
Base<TChar>::~Base()
{
    End();
    if (m_out != nullptr)
    {
        m_deleter(m_out);
        m_out = nullptr;
    }
}

template<typename TChar>
Base<TChar>::Base(Base<TChar>&& mov) :
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
    mov.m_on_begin = &Base<TChar>::DefaultOnBegin;
    mov.m_on_end = &Base<TChar>::DefaultOnEnd;
    mov.m_deleter = &Base<TChar>::DefaultDeleter;
    mov.m_timestamp = std::chrono::system_clock::now();
    mov.m_tag = test::CString<TChar>(TagType{}.GetName(), 
        TagType{}.GetNameSize());
}

template<typename TChar>
Base<TChar>::Base(Base<TChar>&& mov, OnBeginFunctionType * on_begin, 
    OnEndFunctionType * on_end) :
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
    mov.m_on_begin = on_begin;
    mov.m_on_end = on_end;
    mov.m_deleter = &Base<TChar>::DefaultDeleter;
    mov.m_timestamp = std::chrono::system_clock::now();
    mov.m_tag = test::CString<TChar>(TagType{}.GetName(), 
        TagType{}.GetNameSize());
}

template<typename TChar>
bool Base<TChar>::_Output(test::out::Interface<TChar>& out, StatusType& status)
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
test::CString<TChar> Base<TChar>::GetTag() const
{
    return {m_tag};
}

template<typename TChar>
std::chrono::time_point<std::chrono::system_clock> 
Base<TChar>::GetTimestamp() const
{
    return m_timestamp;
}

template<typename TChar>
test::CString<TChar> Base<TChar>::GetMessage() const
{
    return {m_message.Get()};
}

template<typename TChar>
test::out::CString<TChar>& Base<TChar>::_GetMessage()
{
    return m_message;
}

template<typename TChar>
typename Base<TChar>::OnBeginFunctionType * 
Base<TChar>::GetOnBegin() const
{
    return m_on_begin;
}

template<typename TChar>
typename Base<TChar>::OnEndFunctionType * 
Base<TChar>::GetOnEnd() const
{
    return m_on_end;
}

template<typename TChar>
bool Base<TChar>::IsEnd() const
{
    return m_status.IsEnd();
}

template<typename TChar>
bool Base<TChar>::IsGood() const
{
    return m_status.IsGood();
}

template<typename TChar>
bool Base<TChar>::IsBad() const
{
    return m_status.IsBad();
}

template<typename TChar>
typename Base<TChar>::StatusType::IntegerValueType 
Base<TChar>::GetBadCode() const
{
    return m_status.GetBadCode();
}

template<typename TChar>
bool Base<TChar>::End()
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
bool Base<TChar>::Output(test::out::Interface<TChar>& out)
{
    StatusType status;
    return _Output(out, status);
}

template<typename TChar>
bool Base<TChar>::OnBegin(test::out::Interface<TChar>& out)
{
    return m_on_begin(out, m_timestamp, m_tag);
}

template<typename TChar>
bool Base<TChar>::OnEnd(test::out::Interface<TChar>& out)
{
    return m_on_end(out, m_timestamp, m_tag);
}

template<typename TChar>
typename Base<TChar>::SizeType 
Base<TChar>::Puts(const TChar * cstr, const SizeType& size)
{
    if (m_status.IsBad() || m_status.IsEnd()) return 0;
    return m_message.Puts(cstr, size);
}

template<typename TChar>
typename Base<TChar>::SizeType 
Base<TChar>::Puts(const TChar * cstr)
{
    if (m_status.IsBad() || m_status.IsEnd()) return 0;
    return m_message.Puts(cstr);
}

template<typename TChar>
typename Base<TChar>::SizeType 
Base<TChar>::Puts(const test::CString<TChar>& cstr)
{
    if (m_status.IsBad() || m_status.IsEnd()) return 0;
    return m_message.Puts(cstr);
}

template<typename TChar>
typename Base<TChar>::SizeType 
Base<TChar>::Puts(const test::CString<const TChar>& cstr)
{
    if (m_status.IsBad() || m_status.IsEnd()) return 0;
    return m_message.Puts(cstr);
}

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_BASE_H_
