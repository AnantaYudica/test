#ifndef TEST_OUT_BASE_DELEGATE_H_
#define TEST_OUT_BASE_DELEGATE_H_

#include "../CString.h"
#include "Interface.h"
#include "task/Interface.h"
#include "task/Buffer.h"

#include <cstdint>

namespace test
{
namespace out
{
namespace base
{

template<typename TChar, typename TStatus, typename TTaskStatus>
class Delegate
{
public:
    typedef test::out::base::task::Interface<TChar, TTaskStatus> TaskInterfaceType;
    typedef test::out::base::task::Buffer<TChar, TaskInterfaceType>
        BufferType;
    typedef test::out::base::Interface<TStatus> InterfaceType;
    typedef typename InterfaceType::SizeType SizeType;
private:
    const std::intptr_t m_id;
    std::intptr_t m_task_id;
    TaskInterfaceType * m_task;
public:
    Delegate();
    Delegate(TaskInterfaceType * task);
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
    virtual SizeType VPrint(const char * format, va_list var_args) 
        __ATTRIBUTE__ ((__format__ (__printf__, 3, 0))) = 0;
    virtual SizeType Print(const char * format, ...) 
        __ATTRIBUTE__((format(printf, 2, 3))) = 0;
public:
    virtual SizeType Puts(const TChar * cstr, const SizeType& size) = 0;
    virtual SizeType Puts(const TChar * cstr) = 0;
    virtual SizeType Puts(const test::CString<TChar>& cstr) = 0;
    virtual SizeType Puts(const test::CString<const TChar>& cstr) = 0;
public:
    operator bool() const;
};

template<typename TChar, typename TStatus, typename TTaskStatus>
Delegate<TChar, TStatus, TTaskStatus>::Delegate() :
    m_id(0),
    m_task_id(0),
    m_task(nullptr)
{}

template<typename TChar, typename TStatus, typename TTaskStatus>
Delegate<TChar, TStatus, TTaskStatus>::Delegate(TaskInterfaceType * task) :
    m_id(reinterpret_cast<std::intptr_t>(this)),
    m_task_id(0),
    m_task(task)
{
    if (m_task != nullptr) m_task->Assign(m_id, m_task_id);
}

template<typename TChar, typename TStatus, typename TTaskStatus>
Delegate<TChar, TStatus, TTaskStatus>::~Delegate()
{
    if (m_task != nullptr) m_task->Release(m_id);
    m_task_id = 0;
    m_task = nullptr;
}

template<typename TChar, typename TStatus, typename TTaskStatus>
Delegate<TChar, TStatus, TTaskStatus>::
    Delegate(Delegate<TChar, TStatus, TTaskStatus>&& mov) :
        m_id(mov.m_id),
        m_task_id(mov.m_task_id),
        m_task(mov.m_task)
{
    mov.m_task_id = 0;
    mov.m_task = nullptr;
}

template<typename TChar, typename TStatus, typename TTaskStatus>
typename Delegate<TChar, TStatus, TTaskStatus>::BufferType 
Delegate<TChar, TStatus, TTaskStatus>::GetBuffer()
{
    if (m_task == nullptr) return {};
    return m_task->Buffer(m_id);
}

template<typename TChar, typename TStatus, typename TTaskStatus>
Delegate<TChar, TStatus, TTaskStatus>::operator bool() const
{
    return m_id != 0 && m_task != nullptr;
}

} //!base

} //!out

} //!test

#endif //!TEST_OUT_BASE_DELEGATE_H_
