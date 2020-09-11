#ifndef TEST_OUT_BASE_DELEGATE_H_
#define TEST_OUT_BASE_DELEGATE_H_

#include "../CString.h"
#include "../Interface.h"
#include "Interface.h"
#include "deleg/Status.h"
#include "task/Interface.h"
#include "task/Buffer.h"

#include <cstdint>
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
namespace base
{

template<typename TChar, typename TStatus, typename TTaskStatus>
class Delegate :
    public test::out::Interface<TChar>
{
public:
    typedef test::out::base::task::Interface<TChar, TTaskStatus> TaskInterfaceType;
    typedef typename TaskInterfaceType::BufferType BufferType;
    typedef test::out::base::Interface<TStatus> BaseInterfaceType;
    typedef typename BaseInterfaceType::SizeType SizeType;
    typedef test::out::base::deleg::Status<std::uint8_t> StatusType;
private:
    StatusType m_status;
    const std::intptr_t m_id;
    std::intptr_t m_task_id;
    TaskInterfaceType * m_task;
    BaseInterfaceType * m_base_intf;
public:
    Delegate();
    Delegate(BaseInterfaceType * base_intf, TaskInterfaceType * task);
public:
    virtual ~Delegate();
public:
    Delegate(const Delegate<TChar, TStatus, TTaskStatus>&) = delete;
    Delegate(Delegate<TChar, TStatus, TTaskStatus>&& mov);
public:
    Delegate<TChar, TStatus, TTaskStatus>& 
        operator=(const Delegate<TChar, TStatus, TTaskStatus>&) = delete;
    Delegate<TChar, TStatus, TTaskStatus>& 
        operator=(Delegate<TChar, TStatus, TTaskStatus>&&) = delete;
protected:
    BufferType GetBuffer();
public:
    virtual SizeType VPrint(const char * format, va_list var_args) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));;
    virtual SizeType Print(const char * format, ...) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 3)));;
public:
    virtual SizeType Puts(const TChar * cstr, const SizeType& size) override;
    virtual SizeType Puts(const TChar * cstr) override;
    virtual SizeType Puts(const test::CString<TChar>& cstr) override;
    virtual SizeType Puts(const test::CString<const TChar>& cstr) override;
public:
    virtual bool IsGood() const override;
    virtual bool IsBad() const override;
public:
    typename StatusType::IntegerValueType GetBadCode() const;
};

template<typename TChar, typename TStatus, typename TTaskStatus>
Delegate<TChar, TStatus, TTaskStatus>::Delegate() :
    m_status(),
    m_id(0),
    m_task_id(0),
    m_task(nullptr),
    m_base_intf(nullptr)
{
    m_status.Bad(StatusType::task_and_base_intf_nullptr);
}

template<typename TChar, typename TStatus, typename TTaskStatus>
Delegate<TChar, TStatus, TTaskStatus>::Delegate(BaseInterfaceType * base_intf, 
    TaskInterfaceType * task) :
        m_status(),
        m_id(reinterpret_cast<std::intptr_t>(this)),
        m_task_id(0),
        m_task(task),
        m_base_intf(base_intf)
{
    if (m_task == nullptr && m_base_intf == nullptr)
    {
        m_status.Bad(StatusType::task_and_base_intf_nullptr);
    }
    else if (m_task == nullptr)
    {
        m_status.Bad(StatusType::task_nullptr);
    }
    else if(m_base_intf == nullptr)
    {
        m_status.Bad(StatusType::base_intf_nullptr);
    }
    else
    {
        if (!m_task->Assign(m_id, m_task_id))
        {
            m_status.Bad(StatusType::task_assign_failed);
        }
    }
}

template<typename TChar, typename TStatus, typename TTaskStatus>
Delegate<TChar, TStatus, TTaskStatus>::~Delegate()
{
    if (m_base_intf != nullptr && m_task != nullptr) 
    {
        m_task->Release(m_id);
        m_base_intf->Finalize(m_task_id);
    }
    m_task_id = 0;
    m_task = nullptr;
}

template<typename TChar, typename TStatus, typename TTaskStatus>
Delegate<TChar, TStatus, TTaskStatus>::
    Delegate(Delegate<TChar, TStatus, TTaskStatus>&& mov) :
        m_status(std::move(mov.m_status)),
        m_id(mov.m_id),
        m_task_id(mov.m_task_id),
        m_task(mov.m_task),
        m_base_intf(mov.m_base_intf)
{
    mov.m_task_id = 0;
    mov.m_task = nullptr;
    mov.m_base_intf = nullptr;
    mov.m_status.Bad(StatusType::task_and_base_intf_nullptr);
}

template<typename TChar, typename TStatus, typename TTaskStatus>
typename Delegate<TChar, TStatus, TTaskStatus>::BufferType 
Delegate<TChar, TStatus, TTaskStatus>::GetBuffer()
{
    if (m_task == nullptr) return {};
    return m_task->Buffer(m_id);
}

template<typename TChar, typename TStatus, typename TTaskStatus>
typename Delegate<TChar, TStatus, TTaskStatus>::SizeType 
Delegate<TChar, TStatus, TTaskStatus>::VPrint(const char * format, 
    va_list var_args)
{
    return GetBuffer().VPrint(format, var_args);
}

template<typename TChar, typename TStatus, typename TTaskStatus>
typename Delegate<TChar, TStatus, TTaskStatus>::SizeType 
Delegate<TChar, TStatus, TTaskStatus>::Print(const char * format, ...)
{
    va_list args;
    va_start(args, format);
    const auto ret = GetBuffer().VPrint(format, args);
    va_end(args);
    return ret;
}

template<typename TChar, typename TStatus, typename TTaskStatus>
typename Delegate<TChar, TStatus, TTaskStatus>::SizeType 
Delegate<TChar, TStatus, TTaskStatus>::Puts(const TChar * cstr, 
    const SizeType& size)
{
    return GetBuffer().Puts(cstr, size);
}

template<typename TChar, typename TStatus, typename TTaskStatus>
typename Delegate<TChar, TStatus, TTaskStatus>::SizeType 
Delegate<TChar, TStatus, TTaskStatus>::Puts(const TChar * cstr)
{
    return GetBuffer().Puts(cstr);
}

template<typename TChar, typename TStatus, typename TTaskStatus>
typename Delegate<TChar, TStatus, TTaskStatus>::SizeType 
Delegate<TChar, TStatus, TTaskStatus>::Puts(const test::CString<TChar>& cstr)
{
    return GetBuffer().Puts(cstr);
}

template<typename TChar, typename TStatus, typename TTaskStatus>
typename Delegate<TChar, TStatus, TTaskStatus>::SizeType 
Delegate<TChar, TStatus, TTaskStatus>::
    Puts(const test::CString<const TChar>& cstr)
{
    return GetBuffer().Puts(cstr);
}

template<typename TChar, typename TStatus, typename TTaskStatus>
bool Delegate<TChar, TStatus, TTaskStatus>::IsGood() const
{
    return m_status.IsGood();
}

template<typename TChar, typename TStatus, typename TTaskStatus>
bool Delegate<TChar, TStatus, TTaskStatus>::IsBad() const
{
    return m_status.IsBad();
}

template<typename TChar, typename TStatus, typename TTaskStatus>
typename Delegate<TChar, TStatus, TTaskStatus>::StatusType::IntegerValueType 
Delegate<TChar, TStatus, TTaskStatus>::GetBadCode() const
{
    return m_status.GetBadCode();
}

} //!base

} //!out

} //!test

#endif //!TEST_OUT_BASE_DELEGATE_H_
