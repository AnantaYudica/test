#ifndef TEST_OUT_BASE_H_
#define TEST_OUT_BASE_H_

#include "File.h"
#include "Log.h"
#include "Interface.h"
#include "CString.h"
#include "base/Task.h"
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

template<typename TChar, std::size_t MaximumQueue = 512>
class Base :
    private test::out::base::imp::Default<TChar>,
    protected test::out::Interface<TChar>
{
private:
    typedef test::out::base::imp::Default<TChar> BaseType;
protected:
    typedef test::out::Interface<TChar> OutputInterfaceType;
public:
    typedef test::out::File<TChar> FileType;
    typedef typename BaseType::SizeType SizeType;
    typedef typename BaseType::StatusType StatusType;
    typedef typename BaseType::DelegateType DelegateType;
    typedef typename test::out::Log<TChar> LogType;
    typedef typename test::out::log::Tag LogTagType;
    typedef typename FileType::ModeType ModeType;
    typedef typename FileType::StatusType FileStatusType;
    typedef typename test::out::tag::Crit TagCritType;
    typedef typename test::out::tag::Debug TagDebugType;
    typedef typename test::out::tag::Error TagErrorType;
    typedef typename test::out::tag::Info TagInfoType;
    typedef typename test::out::tag::Warn TagWarnType;
private:
    typedef test::out::base::Task<TChar> TaskType;
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
    Base(const Base<TChar, MaximumQueue>&) = delete;
    Base(Base<TChar, MaximumQueue> &&) = delete;
public:
    Base<TChar, MaximumQueue>& 
        operator=(const Base<TChar, MaximumQueue>&) = delete;
    Base<TChar, MaximumQueue>&
        operator=(Base<TChar, MaximumQueue>&&) = delete;
protected:
    virtual bool OnMaximumSize(test::CString<char> old_filename,
        test::CString<char>& new_filename, ModeType& mode);
private:
    TaskType * RequestTask();
private:
    bool ExecuteTask(const std::intptr_t& id) override;
protected:
    virtual SizeType VPrint(const char * format, va_list var_args) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));
    virtual SizeType Print(const char * format, ...) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 3)));
protected:
    virtual SizeType Puts(const TChar * cstr, const SizeType& size) override;
    virtual SizeType Puts(const TChar * cstr) override;
    virtual SizeType Puts(const test::CString<TChar>& cstr) override;
    virtual SizeType Puts(const test::CString<const TChar>& cstr) override;
public:
    template<typename TOutTag>
    SizeType VPrint(const TOutTag& tag, const char * format, 
        va_list var_args) TEST_ATTRIBUTE((__format__ (__printf__, 3, 0)));
    template<typename TOutTag>
    SizeType Print(const TOutTag& tag, const char * format, ...)
         TEST_ATTRIBUTE((__format__ (__printf__, 3, 4)));
public:
    template<typename TOutTag>
    SizeType Puts(const TOutTag& tag, const TChar * cstr, 
        const SizeType& size);
    template<typename TOutTag>
    SizeType Puts(const TOutTag& tag, const TChar * cstr);
    template<typename TOutTag>
    SizeType Puts(const TOutTag& tag, const test::CString<TChar>& cstr);
    template<typename TOutTag>
    SizeType Puts(const TOutTag& tag, 
        const test::CString<const TChar>& cstr);
public:
    template<typename TOutTag>
    LogType Log(const TOutTag& tag);
public:
    LogType Debug();
public:
    LogType Info();
public:
    LogType Error();
public:
    LogType Warn();
public:
    LogType Crit();
public:
    bool IsBad() const override;
    bool IsGood() const override;
public:
    typename StatusType::IntegerValueType GetBadCode() const;
    typename FileStatusType::IntegerValueType GetFileBadCode() const;
};

template<typename TChar, std::size_t MaximumQueue>
Base<TChar, MaximumQueue>::Base() :
    BaseType(),
    OutputInterfaceType(),
    m_file(),
    m_queue()
{}

template<typename TChar, std::size_t MaximumQueue>
Base<TChar, MaximumQueue>::Base(const char * filename, const ModeType& mode) :
    BaseType(),
    OutputInterfaceType(),
    m_file(filename, mode),
    m_queue()
{}

template<typename TChar, std::size_t MaximumQueue>
Base<TChar, MaximumQueue>::Base(const char * filename, const ModeType& mode, 
    const SizeType& maximum_size) :
        BaseType(),
        OutputInterfaceType(),
        m_file(filename, mode, maximum_size),
        m_queue()
{}

template<typename TChar, std::size_t MaximumQueue>
Base<TChar, MaximumQueue>::~Base()
{
    while(m_queue.Size() > 0)
    {
        m_queue.Pop();
    }
}

template<typename TChar, std::size_t MaximumQueue>
bool Base<TChar, MaximumQueue>::OnMaximumSize(test::CString<char>,
    test::CString<char>&, ModeType&)
{
    return false;
}

template<typename TChar, std::size_t MaximumQueue>
typename Base<TChar, MaximumQueue>::TaskType *
Base<TChar, MaximumQueue>::RequestTask()
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
    auto& data = m_queue.Push();
    if (size == m_queue.Size())
    {
        status.Bad(StatusType::task_request_failed);
        return nullptr;
    }
    return &(*data);
}

template<typename TChar, std::size_t MaximumQueue>
bool Base<TChar, MaximumQueue>::ExecuteTask(const std::intptr_t& id)
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

template<typename TChar, std::size_t MaximumQueue>
typename Base<TChar, MaximumQueue>::SizeType 
Base<TChar, MaximumQueue>::VPrint(const char * format, va_list var_args)
{
    auto* task = RequestTask();
    SizeType size = 0;
    if (task == nullptr) return 0;
    {
        DelegateType deleg(this, task);
        size = deleg.VPrint(format, var_args);
    }
    return size;
}

template<typename TChar, std::size_t MaximumQueue>
typename Base<TChar, MaximumQueue>::SizeType 
Base<TChar, MaximumQueue>::Print(const char * format, ...)
{
    auto* task = RequestTask();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType deleg(this, task);
        va_list args;
        va_start(args, format);
        ret = deleg.VPrint(format, args);
        va_end(args);
    }
    return ret;

}

template<typename TChar, std::size_t MaximumQueue>
typename Base<TChar, MaximumQueue>::SizeType 
Base<TChar, MaximumQueue>::Puts(const TChar * cstr, const SizeType& size)
{
    auto* task = RequestTask();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType deleg(this, task);
        ret = deleg.Puts(cstr, size);
    }
    return ret;
}

template<typename TChar, std::size_t MaximumQueue>
typename Base<TChar, MaximumQueue>::SizeType 
Base<TChar, MaximumQueue>::Puts(const TChar * cstr)
{
    auto* task = RequestTask();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType deleg(this, task);
        ret = deleg.Puts(cstr);
    }
    return ret;
}

template<typename TChar, std::size_t MaximumQueue>
typename Base<TChar, MaximumQueue>::SizeType 
Base<TChar, MaximumQueue>::Puts(const test::CString<TChar>& cstr)
{
    auto* task = RequestTask();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType deleg(this, task);
        ret = deleg.Puts(cstr);
    }
    return ret;
}

template<typename TChar, std::size_t MaximumQueue>
typename Base<TChar, MaximumQueue>::SizeType 
Base<TChar, MaximumQueue>::Puts(const test::CString<const TChar>& cstr)
{
    auto* task = RequestTask();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType deleg(this, task);
        ret = deleg.Puts(cstr);
    }
    return ret;
}

template<typename TChar, std::size_t MaximumQueue>
template<typename TOutTag>
typename Base<TChar, MaximumQueue>::SizeType 
Base<TChar, MaximumQueue>::VPrint(const TOutTag& tag, const char * format,
    va_list var_args)
{
    auto* task = RequestTask();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType deleg(this, task);
        {
            LogType log(&deleg, test::out::log::make::Tag(tag));
            ret = log.VPrint(format, var_args);
        }
    }
    return ret;
}

template<typename TChar, std::size_t MaximumQueue>
template<typename TOutTag>
typename Base<TChar, MaximumQueue>::SizeType 
Base<TChar, MaximumQueue>::Print(const TOutTag& tag, const char * format, ...)
{
    auto* task = RequestTask();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType deleg(this, task);
        {
            LogType log(&deleg, test::out::log::make::Tag(tag));
            va_list args;
            va_start(args, format);
            ret = log.VPrint(format, args);
            va_end(args);
        }
    }
    return ret;
}

template<typename TChar, std::size_t MaximumQueue>
template<typename TOutTag>
typename Base<TChar, MaximumQueue>::SizeType 
Base<TChar, MaximumQueue>::Puts(const TOutTag& tag, const TChar * cstr, 
    const SizeType& size)
{
    auto* task = RequestTask();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType deleg(this, task);
        {
            LogType log(&deleg, test::out::log::make::Tag(tag));
            ret = log.Puts(cstr, size);
        }
    }
    return ret;
}

template<typename TChar, std::size_t MaximumQueue>
template<typename TOutTag>
typename Base<TChar, MaximumQueue>::SizeType 
Base<TChar, MaximumQueue>::Puts(const TOutTag& tag, const TChar * cstr)
{
    auto* task = RequestTask();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType deleg(this, task);
        {
            LogType log(&deleg, test::out::log::make::Tag(tag));
            ret = log.Puts(cstr);
        }
    }
    return ret;
}

template<typename TChar, std::size_t MaximumQueue>
template<typename TOutTag>
typename Base<TChar, MaximumQueue>::SizeType 
Base<TChar, MaximumQueue>::Puts(const TOutTag& tag, 
    const test::CString<TChar>& cstr)
{
    auto* task = RequestTask();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType deleg(this, task);
        {
            LogType log(&deleg, test::out::log::make::Tag(tag));
            ret = log.Puts(cstr);
        }
    }
    return ret;
}

template<typename TChar, std::size_t MaximumQueue>
template<typename TOutTag>
typename Base<TChar, MaximumQueue>::SizeType 
Base<TChar, MaximumQueue>::Puts(const TOutTag& tag, 
    const test::CString<const TChar>& cstr)
{
    auto* task = RequestTask();
    SizeType ret = 0;
    if (task == nullptr) return 0;
    {
        DelegateType deleg(this, task);
        {
            LogType log(&deleg, test::out::log::make::Tag(tag));
            ret = log.Puts(cstr);
        }
    }
    return ret;
}

template<typename TChar, std::size_t MaximumQueue>
template<typename TOutTag>
typename Base<TChar, MaximumQueue>::LogType 
Base<TChar, MaximumQueue>::Log(const TOutTag& tag)
{
    auto* task = RequestTask();
    DelegateType * deleg = new DelegateType(this, task);
    return {deleg, &LogType::Deleter, test::out::log::make::Tag(tag)};
}

template<typename TChar, std::size_t MaximumQueue>
typename Base<TChar, MaximumQueue>::LogType 
Base<TChar, MaximumQueue>::Debug()
{
    auto* task = RequestTask();
    DelegateType * deleg = new DelegateType(this, task);
    return {deleg, &LogType::Deleter, test::out::log::tag::Debug{}};
}

template<typename TChar, std::size_t MaximumQueue>
typename Base<TChar, MaximumQueue>::LogType 
Base<TChar, MaximumQueue>::Info()
{
    auto* task = RequestTask();
    DelegateType * deleg = new DelegateType(this, task);
    return {deleg, &LogType::Deleter, test::out::log::tag::Info{}};
}

template<typename TChar, std::size_t MaximumQueue>
typename Base<TChar, MaximumQueue>::LogType 
Base<TChar, MaximumQueue>::Error()
{
    auto* task = RequestTask();
    DelegateType * deleg = new DelegateType(this, task);
    return {deleg, &LogType::Deleter, test::out::log::tag::Error{}};
}

template<typename TChar, std::size_t MaximumQueue>
typename Base<TChar, MaximumQueue>::LogType 
Base<TChar, MaximumQueue>::Warn()
{
    auto* task = RequestTask();
    DelegateType * deleg = new DelegateType(this, task);
    return {deleg, &LogType::Deleter, test::out::log::tag::Warn{}};
}

template<typename TChar, std::size_t MaximumQueue>
typename Base<TChar, MaximumQueue>::LogType 
Base<TChar, MaximumQueue>::Crit()
{
    auto* task = RequestTask();
    DelegateType * deleg = new DelegateType(this, task);
    return {deleg, &LogType::Deleter, test::out::log::tag::Crit{}};
}

template<typename TChar, std::size_t MaximumQueue>
bool Base<TChar, MaximumQueue>::IsBad() const
{
    return BaseType::GetStatus().IsBad();
}

template<typename TChar, std::size_t MaximumQueue>
bool Base<TChar, MaximumQueue>::IsGood() const
{
    return BaseType::GetStatus().IsGood();
}

template<typename TChar, std::size_t MaximumQueue>
typename Base<TChar, MaximumQueue>::StatusType::IntegerValueType 
Base<TChar, MaximumQueue>::GetBadCode() const
{
    return BaseType::GetStatus().GetBadCode();
}


template<typename TChar, std::size_t MaximumQueue>
typename Base<TChar, MaximumQueue>::FileStatusType::IntegerValueType 
Base<TChar, MaximumQueue>::GetFileBadCode() const
{
    return m_file.GetBadCode();
}

} //!out

} //!test

#endif //!TEST_OUT_BASE_H_