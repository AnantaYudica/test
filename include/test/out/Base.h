#ifndef TEST_OUT_BASE_H_
#define TEST_OUT_BASE_H_

#include "File.h"
#include "Log.h"
#include "Interface.h"
#include "CString.h"
#include "Type.h"
#include "base/Task.h"
#include "base/task/Base.h"
#include "base/Delegate.h"
#include "../Queue.h"
#include "log/Tag.h"
#include "log/make/Tag.h"
#include "log/tag/Debug.h"
#include "log/tag/Info.h"
#include "log/tag/Error.h"
#include "log/tag/Warn.h"
#include "log/tag/Crit.h"

#include "base/imp/Default.h"

#include <cstdarg>
#include <cstddef>
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

template<std::size_t MaximumQueue = 512>
class Base :
    private test::out::base::imp::Default,
    protected test::out::Interface<char, wchar_t>
{
private:
    typedef test::out::base::imp::Default BaseType;
protected:
    typedef test::out::Interface<char, wchar_t> OutputInterfaceType;
public:
    typedef test::out::base::task::Base TaskBaseType;
public:
    typedef typename BaseType::SizeType SizeType;
public:
    typedef typename BaseType::StatusType StatusType;
public:
    template<typename TChar>
    using DelegateType = test::out::base::Delegate<TChar, StatusType,
        typename TaskBaseType::StatusType>;
public:
    typedef test::out::File<> FileType;
    typedef typename FileType::ModeType ModeType;
    typedef typename FileType::StatusType FileStatusType;
public:
    template<typename TChar>
    using LogType = test::out::Log<TChar>;
    template<typename TChar>
    using LogTagType = test::out::log::Tag<TChar>;
    typedef test::out::tag::Crit TagCritType;
    typedef test::out::tag::Debug TagDebugType;
    typedef test::out::tag::Error TagErrorType;
    typedef test::out::tag::Info TagInfoType;
    typedef test::out::tag::Warn TagWarnType;
private:
    typedef test::out::base::Task TaskType;
private:
    FileType m_file;
    test::Queue<TaskType *const> m_queue;
protected:
    Base();
    Base(const char * filename, const ModeType& mode);
    Base(const char * filename, const ModeType& mode, 
        const SizeType& maximum_size);
public:
    virtual ~Base();
public:
    Base(const Base<MaximumQueue>&) = delete;
    Base(Base<MaximumQueue> &&) = delete;
public:
    Base<MaximumQueue>& operator=(const Base<MaximumQueue>&) = delete;
    Base<MaximumQueue>& operator=(Base<MaximumQueue>&&) = delete;
protected:
    virtual bool OnMaximumSize(test::CString<char> old_filename,
        test::CString<char>& new_filename, ModeType& mode);
private:
    template<typename TChar>
    TaskType * RequestTask();
private:
    bool ExecuteTask(const std::intptr_t& id) override;
protected:
    virtual SizeType VPrint(const char * format, va_list var_args) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));
    virtual SizeType Print(const char * format, ...) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 3)));
    virtual SizeType VPrint(const wchar_t * format, va_list var_args) override;
    virtual SizeType Print(const wchar_t * format, ...) override;
protected:
    virtual SizeType Puts(const char * cstr, const SizeType& size) override;
    virtual SizeType Puts(const char * cstr) override;
    virtual SizeType Puts(const test::CString<char>& cstr) override;
    virtual SizeType Puts(const test::CString<const char>& cstr) override;
    virtual SizeType Puts(const wchar_t * cstr, const SizeType& size) override;
    virtual SizeType Puts(const wchar_t * cstr) override;
    virtual SizeType Puts(const test::CString<wchar_t>& cstr) override;
    virtual SizeType Puts(const test::CString<const wchar_t>& cstr) override;
public:
    template<typename TOutTag>
    SizeType VPrint(const TOutTag& tag, const char * format, 
        va_list var_args) TEST_ATTRIBUTE((__format__ (__printf__, 3, 0)));
    template<typename TOutTag>
    SizeType Print(const TOutTag& tag, const char * format, ...)
         TEST_ATTRIBUTE((__format__ (__printf__, 3, 4)));
    template<typename TOutTag>
    SizeType VPrint(const TOutTag& tag, const wchar_t * format, 
        va_list var_args);
    template<typename TOutTag>
    SizeType Print(const TOutTag& tag, const wchar_t * format, ...);
public:
    template<typename TChar, typename TOutTag>
    SizeType Puts(const TOutTag& tag, const TChar * cstr, 
        const SizeType& size);
    template<typename TChar, typename TOutTag>
    SizeType Puts(const TOutTag& tag, const TChar * cstr);
    template<typename TChar, typename TOutTag>
    SizeType Puts(const TOutTag& tag, const test::CString<TChar>& cstr);
    template<typename TChar, typename TOutTag>
    SizeType Puts(const TOutTag& tag, 
        const test::CString<const TChar>& cstr);
public:
    template<typename TChar = char, typename TOutTag>
    LogType<TChar> Log(const TOutTag& tag);
public:
    template<typename TChar = char>
    LogType<TChar> Debug();
public:
    template<typename TChar = char>
    LogType<TChar> Info();
public:
    template<typename TChar = char>
    LogType<TChar> Error();
public:
    template<typename TChar = char>
    LogType<TChar> Warn();
public:
    template<typename TChar = char>
    LogType<TChar> Crit();
public:
    bool IsBad() const override;
    bool IsGood() const override;
public:
    typename StatusType::IntegerValueType GetBadCode() const;
    typename FileStatusType::IntegerValueType GetFileBadCode() const;
};

template<std::size_t MaximumQueue>
Base<MaximumQueue>::Base() :
    BaseType(),
    OutputInterfaceType(),
    m_file(),
    m_queue()
{}

template<std::size_t MaximumQueue>
Base<MaximumQueue>::Base(const char * filename, const ModeType& mode) :
    BaseType(),
    OutputInterfaceType(),
    m_file(filename, mode),
    m_queue()
{}

template<std::size_t MaximumQueue>
Base<MaximumQueue>::Base(const char * filename, const ModeType& mode, 
    const SizeType& maximum_size) :
        BaseType(),
        OutputInterfaceType(),
        m_file(filename, mode, maximum_size),
        m_queue()
{}

template<std::size_t MaximumQueue>
Base<MaximumQueue>::~Base()
{
    while(m_queue.Size() > 0)
    {
        m_queue.Pop();
    }
}

template<std::size_t MaximumQueue>
bool Base<MaximumQueue>::OnMaximumSize(test::CString<char>,
    test::CString<char>&, ModeType&)
{
    return false;
}

template<std::size_t MaximumQueue>
template<typename TChar>
typename Base<MaximumQueue>::TaskType *
Base<MaximumQueue>::RequestTask()
{
    auto guard = BaseType::RequestTaskGuard();
    if (!guard) return nullptr;

    auto& status = BaseType::GetStatus();
    if (m_queue.Size() >= MaximumQueue)
    {
        status.Bad(StatusType::queue_overflow);
        return nullptr;
    }
    const auto size =  m_queue.Size();
    auto& data = m_queue.Push(test::out::Type<TChar>());
    if (size == m_queue.Size())
    {
        status.Bad(StatusType::task_request_failed);
        return nullptr;
    }
    return &(*data);
}

template<std::size_t MaximumQueue>
bool Base<MaximumQueue>::ExecuteTask(const std::intptr_t& id)
{
    auto guard = BaseType::ExecuteTaskGuard();
    if (!guard) return false;

    auto& status = BaseType::GetStatus();

    if (status.IsBad()) return false;

    if (m_queue.Size() > 0)
    {
        auto * front = &(m_queue.Front());
        if (*front != id) return true;

        while(front->IsRelease())
        {
            if (!front->Execute(m_file))
            {
                status.Bad(StatusType::task_execute_failed);
                return false;
            }
            m_queue.Pop();
            front = &(m_queue.Front());
        }
    }
    return true;
}

template<std::size_t MaximumQueue>
typename Base<MaximumQueue>::SizeType 
Base<MaximumQueue>::VPrint(const char * format, va_list var_args)
{
    auto* task = RequestTask<char>();
    SizeType size = 0;
    if (task == nullptr) return 0;
    {
        DelegateType<char> deleg(this, task);
        size = deleg.VPrint(format, var_args);
    }
    return size;
}

template<std::size_t MaximumQueue>
typename Base<MaximumQueue>::SizeType 
Base<MaximumQueue>::Print(const char * format, ...)
{
    auto* task = RequestTask<char>();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType<char> deleg(this, task);
        va_list args;
        va_start(args, format);
        ret = deleg.VPrint(format, args);
        va_end(args);
    }
    return ret;
}

template<std::size_t MaximumQueue>
typename Base<MaximumQueue>::SizeType 
Base<MaximumQueue>::VPrint(const wchar_t * format, va_list var_args)
{
    auto* task = RequestTask<wchar_t>();
    SizeType size = 0;
    if (task == nullptr) return 0;
    {
        DelegateType<wchar_t> deleg(this, task);
        size = deleg.VPrint(format, var_args);
    }
    return size;
}

template<std::size_t MaximumQueue>
typename Base<MaximumQueue>::SizeType 
Base<MaximumQueue>::Print(const wchar_t * format, ...)
{
    auto* task = RequestTask<wchar_t>();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType<wchar_t> deleg(this, task);
        va_list args;
        va_start(args, format);
        ret = deleg.VPrint(format, args);
        va_end(args);
    }
    return ret;
}

template<std::size_t MaximumQueue>
typename Base<MaximumQueue>::SizeType 
Base<MaximumQueue>::Puts(const char * cstr, const SizeType& size)
{
    auto* task = RequestTask<char>();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType<char> deleg(this, task);
        ret = deleg.Puts(cstr, size);
    }
    return ret;
}

template<std::size_t MaximumQueue>
typename Base<MaximumQueue>::SizeType 
Base<MaximumQueue>::Puts(const char * cstr)
{
    auto* task = RequestTask<char>();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType<char> deleg(this, task);
        ret = deleg.Puts(cstr);
    }
    return ret;
}

template<std::size_t MaximumQueue>
typename Base<MaximumQueue>::SizeType 
Base<MaximumQueue>::Puts(const test::CString<char>& cstr)
{
    auto* task = RequestTask<char>();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType<char> deleg(this, task);
        ret = deleg.Puts(cstr);
    }
    return ret;
}

template<std::size_t MaximumQueue>
typename Base<MaximumQueue>::SizeType 
Base<MaximumQueue>::Puts(const test::CString<const char>& cstr)
{
    auto* task = RequestTask<char>();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType<char> deleg(this, task);
        ret = deleg.Puts(cstr);
    }
    return ret;
}

template<std::size_t MaximumQueue>
typename Base<MaximumQueue>::SizeType 
Base<MaximumQueue>::Puts(const wchar_t * cstr, const SizeType& size)
{
    auto* task = RequestTask<wchar_t>();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType<wchar_t> deleg(this, task);
        ret = deleg.Puts(cstr, size);
    }
    return ret;
}

template<std::size_t MaximumQueue>
typename Base<MaximumQueue>::SizeType 
Base<MaximumQueue>::Puts(const wchar_t * cstr)
{
    auto* task = RequestTask<wchar_t>();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType<wchar_t> deleg(this, task);
        ret = deleg.Puts(cstr);
    }
    return ret;
}

template<std::size_t MaximumQueue>
typename Base<MaximumQueue>::SizeType 
Base<MaximumQueue>::Puts(const test::CString<wchar_t>& cstr)
{
    auto* task = RequestTask<wchar_t>();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType<wchar_t> deleg(this, task);
        ret = deleg.Puts(cstr);
    }
    return ret;
}

template<std::size_t MaximumQueue>
typename Base<MaximumQueue>::SizeType 
Base<MaximumQueue>::Puts(const test::CString<const wchar_t>& cstr)
{
    auto* task = RequestTask<wchar_t>();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType<wchar_t> deleg(this, task);
        ret = deleg.Puts(cstr);
    }
    return ret;
}

template<std::size_t MaximumQueue>
template<typename TOutTag>
typename Base<MaximumQueue>::SizeType 
Base<MaximumQueue>::VPrint(const TOutTag& tag, const char * format,
    va_list var_args)
{
    auto* task = RequestTask<char>();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType<char> deleg(this, task);
        {
            LogType<char> log(&deleg, test::out::log::make::Tag<char>(tag));
            ret = log.VPrint(format, var_args);
        }
    }
    return ret;
}

template<std::size_t MaximumQueue>
template<typename TOutTag>
typename Base<MaximumQueue>::SizeType 
Base<MaximumQueue>::Print(const TOutTag& tag, const char * format, ...)
{
    auto* task = RequestTask<char>();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType<char> deleg(this, task);
        {
            LogType<char> log(&deleg, test::out::log::make::Tag<char>(tag));
            va_list args;
            va_start(args, format);
            ret = log.VPrint(format, args);
            va_end(args);
        }
    }
    return ret;
}

template<std::size_t MaximumQueue>
template<typename TOutTag>
typename Base<MaximumQueue>::SizeType 
Base<MaximumQueue>::VPrint(const TOutTag& tag, const wchar_t * format,
    va_list var_args)
{
    auto* task = RequestTask<wchar_t>();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType<wchar_t> deleg(this, task);
        {
            LogType<wchar_t> log(&deleg, 
                test::out::log::make::Tag<wchar_t>(tag));
            ret = log.VPrint(format, var_args);
        }
    }
    return ret;
}

template<std::size_t MaximumQueue>
template<typename TOutTag>
typename Base<MaximumQueue>::SizeType 
Base<MaximumQueue>::Print(const TOutTag& tag, const wchar_t * format, ...)
{
    auto* task = RequestTask<wchar_t>();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType<wchar_t> deleg(this, task);
        {
            LogType<wchar_t> log(&deleg, 
                test::out::log::make::Tag<wchar_t>(tag));
            va_list args;
            va_start(args, format);
            ret = log.VPrint(format, args);
            va_end(args);
        }
    }
    return ret;
}

template<std::size_t MaximumQueue>
template<typename TChar, typename TOutTag>
typename Base<MaximumQueue>::SizeType 
Base<MaximumQueue>::Puts(const TOutTag& tag, const TChar * cstr, 
    const SizeType& size)
{
    auto* task = RequestTask<TChar>();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType<TChar> deleg(this, task);
        {
            LogType<TChar> log(&deleg, test::out::log::make::Tag<TChar>(tag));
            ret = log.Puts(cstr, size);
        }
    }
    return ret;
}

template<std::size_t MaximumQueue>
template<typename TChar, typename TOutTag>
typename Base<MaximumQueue>::SizeType 
Base<MaximumQueue>::Puts(const TOutTag& tag, const TChar * cstr)
{
    auto* task = RequestTask<TChar>();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType<TChar> deleg(this, task);
        {
            LogType<TChar> log(&deleg, test::out::log::make::Tag<TChar>(tag));
            ret = log.Puts(cstr);
        }
    }
    return ret;
}

template<std::size_t MaximumQueue>
template<typename TChar, typename TOutTag>
typename Base<MaximumQueue>::SizeType 
Base<MaximumQueue>::Puts(const TOutTag& tag, const test::CString<TChar>& cstr)
{
    auto* task = RequestTask<TChar>();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType<TChar> deleg(this, task);
        {
            LogType<TChar> log(&deleg, test::out::log::make::Tag<TChar>(tag));
            ret = log.Puts(cstr);
        }
    }
    return ret;
}

template<std::size_t MaximumQueue>
template<typename TChar, typename TOutTag>
typename Base<MaximumQueue>::SizeType 
Base<MaximumQueue>::Puts(const TOutTag& tag, 
    const test::CString<const TChar>& cstr)
{
    auto* task = RequestTask<TChar>();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType<TChar> deleg(this, task);
        {
            LogType<TChar> log(&deleg, test::out::log::make::Tag<TChar>(tag));
            ret = log.Puts(cstr);
        }
    }
    return ret;
}

template<std::size_t MaximumQueue>
template<typename TChar, typename TOutTag>
typename Base<MaximumQueue>::template LogType<TChar>
Base<MaximumQueue>::Log(const TOutTag& tag)
{
    auto* task = RequestTask<TChar>();
    DelegateType<TChar> * deleg = new DelegateType<TChar>(this, task);
    return {deleg, &LogType<TChar>::Deleter, 
        test::out::log::make::Tag<TChar>(tag)};
}

template<std::size_t MaximumQueue>
template<typename TChar>
typename Base<MaximumQueue>::template LogType<TChar> 
Base<MaximumQueue>::Debug()
{
    auto* task = RequestTask<TChar>();
    DelegateType<TChar> * deleg = new DelegateType<TChar>(this, task);
    return {deleg, &LogType<TChar>::Deleter, 
        test::out::log::tag::Debug<TChar>{}};
}

template<std::size_t MaximumQueue>
template<typename TChar>
typename Base<MaximumQueue>::template LogType<TChar>
Base<MaximumQueue>::Info()
{
    auto* task = RequestTask<TChar>();
    DelegateType<TChar> * deleg = new DelegateType<TChar>(this, task);
    return {deleg, &LogType<TChar>::Deleter, 
        test::out::log::tag::Info<TChar>{}};
}

template<std::size_t MaximumQueue>
template<typename TChar>
typename Base<MaximumQueue>::template LogType<TChar> 
Base<MaximumQueue>::Error()
{
    auto* task = RequestTask<TChar>();
    DelegateType<TChar> * deleg = new DelegateType<TChar>(this, task);
    return {deleg, &LogType<TChar>::Deleter, 
        test::out::log::tag::Error<TChar>{}};
}

template<std::size_t MaximumQueue>
template<typename TChar>
typename Base<MaximumQueue>::template LogType<TChar> 
Base<MaximumQueue>::Warn()
{
    auto* task = RequestTask<TChar>();
    DelegateType<TChar> * deleg = new DelegateType<TChar>(this, task);
    return {deleg, &LogType<TChar>::Deleter, 
        test::out::log::tag::Warn<TChar>{}};
}

template<std::size_t MaximumQueue>
template<typename TChar>
typename Base<MaximumQueue>::template LogType<TChar> 
Base<MaximumQueue>::Crit()
{
    auto* task = RequestTask<TChar>();
    DelegateType<TChar> * deleg = new DelegateType<TChar>(this, task);
    return {deleg, &LogType<TChar>::Deleter, 
        test::out::log::tag::Crit<TChar>{}};
}

template<std::size_t MaximumQueue>
bool Base<MaximumQueue>::IsBad() const
{
    return BaseType::GetStatus().IsBad();
}

template<std::size_t MaximumQueue>
bool Base<MaximumQueue>::IsGood() const
{
    return BaseType::GetStatus().IsGood();
}

template<std::size_t MaximumQueue>
typename Base<MaximumQueue>::StatusType::IntegerValueType 
Base<MaximumQueue>::GetBadCode() const
{
    return BaseType::GetStatus().GetBadCode();
}


template<std::size_t MaximumQueue>
typename Base<MaximumQueue>::FileStatusType::IntegerValueType 
Base<MaximumQueue>::GetFileBadCode() const
{
    return m_file.GetBadCode();
}

} //!out

} //!test

#endif //!TEST_OUT_BASE_H_
