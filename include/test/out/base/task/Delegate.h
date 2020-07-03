#ifndef TEST_OUT_BASE_TASK_DELEGATE_H_
#define TEST_OUT_BASE_TASK_DELEGATE_H_

#include "../../CString.h"
#include "../Interface.h"
#include "Interface.h"
#include "Buffer.h"

#include <cstdint>

namespace test
{
namespace out
{
namespace base
{
namespace task
{

template<typename TChar, typename TStatus>
class Delegate
{
public:
    typedef test::out::base::task::Interface<TChar, TStatus>
        TaskInterfaceType;
    typedef test::out::base::task::Buffer<TChar, TaskInterfaceType>
        BufferType;
private:
    const std::intptr_t m_id;
    TaskInterfaceType * m_task;
public:
    Delegate();
    Delegate(TaskInterfaceType * task);
public:
    virtual ~Delegate();
public:
    Delegate(const Delegate<TChar, TStatus>&) = delete;
    Delegate(Delegate<TChar, TStatus>&& mov);
public:
    Delegate<TChar, TStatus>& 
        operator=(const Delegate<TChar, TStatus>&) = delete;
    Delegate<TChar, TStatus>& operator=(Delegate<TChar, TStatus>&&) = delete;
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

template<typename TChar, typename TStatus>
Delegate<TChar, TStatus>::Delegate() :
    m_id(0),
    m_task(nullptr)
{}

template<typename TChar, typename TStatus>
Delegate<TChar, TStatus>::Delegate(TaskInterfaceType * task) :
    m_id(reinterpret_cast<std::intptr_t>(this)),
    m_task(task)
{}

template<typename TChar, typename TStatus>
Delegate<TChar, TStatus>::~Delegate()
{
    m_task = nullptr;
}

template<typename TChar, typename TStatus>
Delegate<TChar, TStatus>::Delegate(Delegate<TChar, TStatus>&& mov) :
    m_id(mov.m_id),
    m_task(mov.m_task)
{
    mov.m_id = 0;
    m_task = nullptr;
}

template<typename TChar, typename TStatus>
typename Delegate<TChar, TStatus>::BufferType 
Delegate<TChar, TStatus>::GetBuffer()
{
    if (m_task == nullptr) return {};
    return m_task->Buffer(m_id);
}

template<typename TChar, typename TStatus>
Delegate<TChar, TStatus>::operator bool() const
{
    return m_id != 0 && m_task != nullptr;
}

} //!task

} //!base

} //!out

} //!test

#endif //!TEST_OUT_BASE_TASK_DELEGATE_H_
