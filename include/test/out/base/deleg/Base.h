#ifndef TEST_OUT_BASE_DELEG_BASE_H_
#define TEST_OUT_BASE_DELEG_BASE_H_

#include "../Interface.h"
#include "../task/Interface.h"
#include "../task/Buffer.h"
#include "Status.h"

#include <cstdint>

namespace test
{
namespace out
{
namespace base
{
namespace deleg
{

template<typename TChar, typename TStatus, typename TTaskStatus>
class Base
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
    Base();
    Base(BaseInterfaceType * base_intf, TaskInterfaceType * task);
public:
    ~Base();
public:
    Base(const Base<TChar, TStatus, TTaskStatus>&) = delete;
    Base(Base<TChar, TStatus, TTaskStatus>&& mov);
public:
    Base<TChar, TStatus, TTaskStatus>& 
        operator=(const Base<TChar, TStatus, TTaskStatus>&) = delete;
    Base<TChar, TStatus, TTaskStatus>& 
        operator=(Base<TChar, TStatus, TTaskStatus>&&) = delete;
protected:
    BufferType GetBuffer();
public:
    bool IsGood() const;
    bool IsBad() const;
public:
    typename StatusType::IntegerValueType GetBadCode() const;
};

template<typename TChar, typename TStatus, typename TTaskStatus>
Base<TChar, TStatus, TTaskStatus>::Base() :
    m_status(),
    m_id(0),
    m_task_id(0),
    m_task(nullptr),
    m_base_intf(nullptr)
{
    m_status.Bad(StatusType::task_and_base_intf_nullptr);
}

template<typename TChar, typename TStatus, typename TTaskStatus>
Base<TChar, TStatus, TTaskStatus>::Base(BaseInterfaceType * base_intf, 
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
Base<TChar, TStatus, TTaskStatus>::~Base()
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
Base<TChar, TStatus, TTaskStatus>::
    Base(Base<TChar, TStatus, TTaskStatus>&& mov) :
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
typename Base<TChar, TStatus, TTaskStatus>::BufferType 
Base<TChar, TStatus, TTaskStatus>::GetBuffer()
{
    if (m_task == nullptr) return {};
    return m_task->Buffer(m_id);
}

template<typename TChar, typename TStatus, typename TTaskStatus>
bool Base<TChar, TStatus, TTaskStatus>::IsGood() const
{
    return m_status.IsGood();
}

template<typename TChar, typename TStatus, typename TTaskStatus>
bool Base<TChar, TStatus, TTaskStatus>::IsBad() const
{
    return m_status.IsBad();
}

template<typename TChar, typename TStatus, typename TTaskStatus>
typename Base<TChar, TStatus, TTaskStatus>::StatusType::IntegerValueType 
Base<TChar, TStatus, TTaskStatus>::GetBadCode() const
{
    return m_status.GetBadCode();
}

} //!deleg

} //!base

} //!out

} //!test

#endif //!TEST_OUT_BASE_DELEG_BASE_H_
