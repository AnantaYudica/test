#ifndef TEST_OUT_BASE_TASK_H_
#define TEST_OUT_BASE_TASK_H_

#include "../CString.h"
#include "../Interface.h"
#include "task/Base.h"

#include <cstdint>
#include <utility>

namespace test
{
namespace out
{
namespace base
{

template<typename TChar>
class Task : 
    public test::out::base::task::Base<TChar>
{
private:
    typedef test::out::base::task::Base<TChar> BaseType;
public:
    typedef typename BaseType::TaskInterfaceType TaskInterfaceType;
    typedef typename BaseType::StatusType StatusType;
    typedef typename StatusType::IntegerValueType IntegerValueType;
    typedef typename test::out::CString<TChar>::StatusType::IntegerValueType
        BufferIntegerValueType;
    typedef typename TaskInterfaceType::BufferType BufferType;
private:
    const std::intptr_t m_id; 
    std::intptr_t m_delegate_id;
    test::out::CString<TChar> m_buffer;
public:
    Task();
public:
    ~Task();
public:
    Task(const Task<TChar>&) = delete;
    Task(Task<TChar>&& mov);
public:
    Task<TChar>& operator=(const Task<TChar>&) = delete;
    Task<TChar>& operator=(Task<TChar>&&) = delete;
public:
    bool operator==(const std::intptr_t& id) const;
    bool operator!=(const std::intptr_t& id) const;
public:
    bool Execute(test::out::Interface<TChar>& out) override final;
public:
    bool Assign(const std::intptr_t& deleg_id,
        std::intptr_t& task_id) override final;
public:
    bool Release(const std::intptr_t& deleg_id) override final;
public:
    BufferType Buffer(const std::intptr_t& deleg_id) override final;
public:
    bool IsDone() const;
    bool IsRelease() const;
    bool IsAssign() const;
    bool IsGood() const;
    bool IsBad() const;
public:
    IntegerValueType GetBadCode() const;
    BufferIntegerValueType GetBufferBadCode() const;
};

template<typename TChar>
Task<TChar>::Task() :
    BaseType(),
    m_id(reinterpret_cast<std::intptr_t>(this)),
    m_delegate_id(0),
    m_buffer()
{}

template<typename TChar>
Task<TChar>::~Task()
{}

template<typename TChar>
Task<TChar>::Task(Task<TChar>&& mov) :
    BaseType(std::move(static_cast<BaseType&&>(mov))),
    m_id(mov.m_id),
    m_delegate_id(mov.m_delegate_id),
    m_buffer(std::move(mov.m_buffer))
{
    mov.m_delegate_id = 0;
    mov.GetStatus().Remove();
}

template<typename TChar>
bool Task<TChar>::operator==(const std::intptr_t& id) const
{
    return m_id == id;
}

template<typename TChar>
bool Task<TChar>::operator!=(const std::intptr_t& id) const
{
    return m_id != id;
}

template<typename TChar>
bool Task<TChar>::Execute(test::out::Interface<TChar>& out)
{
    auto guard = BaseType::ExecuteGuard();
    if (!guard) return false;
    
    auto& status = BaseType::GetStatus();
    if (!status.Execute()) return false;

    return m_buffer.Output(out);
}

template<typename TChar>
bool Task<TChar>::Assign(const std::intptr_t& deleg_id,
    std::intptr_t& task_id)
{
    auto guard = BaseType::AssignGuard();
    if (!guard) return false;

    if (m_delegate_id != 0 && task_id != 0) return false;
    
    auto& status = BaseType::GetStatus();
    if (!status.Assign()) return false;
    m_delegate_id = deleg_id;
    task_id = m_id;
    return true;
}

template<typename TChar>
bool Task<TChar>::Release(const std::intptr_t& deleg_id)
{
    auto guard = BaseType::ReleaseGuard();
    if (!guard) return false;

    if (m_delegate_id != 0 && m_delegate_id != deleg_id) return false;
    auto& status = BaseType::GetStatus();
    return status.Release();
}

template<typename TChar>
typename Task<TChar>::BufferType 
Task<TChar>::Buffer(const std::intptr_t& deleg_id)
{
    auto guard = BaseType::BufferGuard();
    if (!guard) return {};

    if (m_delegate_id != 0 && m_delegate_id != deleg_id) return {};

    auto& status = BaseType::GetStatus();
    if (m_buffer.IsBad())
    {
        status.Bad(StatusType::buffer_failed);
        return {};
    }

    return {&m_buffer, std::move(guard)};
}

template<typename TChar>
bool Task<TChar>::IsDone() const
{
    return BaseType::GetStatus().IsDone();
}

template<typename TChar>
bool Task<TChar>::IsRelease() const
{
    return BaseType::GetStatus().IsRelease();
}

template<typename TChar>
bool Task<TChar>::IsAssign() const
{
    return BaseType::GetStatus().IsAssign();
}

template<typename TChar>
bool Task<TChar>::IsGood() const
{
    return BaseType::GetStatus().IsGood();
}

template<typename TChar>
bool Task<TChar>::IsBad() const
{
    return BaseType::GetStatus().IsBad(); 
}

template<typename TChar>
typename Task<TChar>::IntegerValueType 
Task<TChar>::GetBadCode() const
{
    return BaseType::GetStatus().GetBadCode(); 
}

template<typename TChar>
typename Task<TChar>::BufferIntegerValueType 
Task<TChar>::GetBufferBadCode() const
{
    return m_buffer.GetBadCode();
}

} //!base

} //!out

} //!test

#endif //!TEST_OUT_BASE_TASK_H_
