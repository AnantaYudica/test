#ifndef TEST_OUT_BASE_TASK_H_
#define TEST_OUT_BASE_TASK_H_

#include "../CString.h"
#include "../Interface.h"
#include "../Type.h"
#include "task/Base.h"

#include <cstdint>
#include <utility>

namespace test
{
namespace out
{
namespace base
{

class Task : 
    public test::out::base::task::Base
{
private:
    typedef test::out::base::task::Base BaseType;
public:
    typedef typename BaseType::TaskInterfaceType TaskInterfaceType;
    typedef typename BaseType::StatusType StatusType;
    typedef typename StatusType::IntegerValueType IntegerValueType;
    typedef typename test::out::CString<>::StatusType::IntegerValueType
        BufferIntegerValueType;
    template<typename TChar>
    using BufferType = typename TaskInterfaceType::template BufferType<TChar>;
private:
    union BufferPtrType
    {
        test::out::CString<char> * char_out_ptr;
        test::out::CString<wchar_t> * wchar_out_ptr;
    };
public:
    static constexpr std::uint8_t undefined_type_id = 0;
    static constexpr std::uint8_t char_type_id = 1;
    static constexpr std::uint8_t wchar_type_id = 2;
private:
    std::uint8_t m_type_id;
    const std::intptr_t m_id; 
    std::intptr_t m_delegate_id;
    BufferPtrType m_buffer;
public:
    inline Task();
    inline Task(test::out::Type<char>);
    inline Task(test::out::Type<wchar_t>);
public:
    inline ~Task();
public:
    inline Task(const Task&) = delete;
    inline Task(Task&& mov);
public:
    inline Task& operator=(const Task&) = delete;
    inline Task& operator=(Task&&) = delete;
public:
    inline bool operator==(const std::intptr_t& id) const;
    inline bool operator!=(const std::intptr_t& id) const;
public:
    inline bool Execute(test::out::Interface<char>& out) override final;
    inline bool Execute(test::out::Interface<wchar_t>& out) override final;
    inline bool Execute(test::out::Interface<char, 
        wchar_t>& out) override final;
public:
    inline bool Assign(const std::intptr_t& deleg_id,
        std::intptr_t& task_id) override final;
public:
    inline bool Release(const std::intptr_t& deleg_id) override final;
public:
    inline BufferType<char> Buffer(test::out::Type<char>, 
        const std::intptr_t& deleg_id) override final;
    inline BufferType<wchar_t> Buffer(test::out::Type<wchar_t>, 
        const std::intptr_t& deleg_id) override final;
public:
    inline bool IsDone() const;
    inline bool IsRelease() const;
    inline bool IsAssign() const;
    inline bool IsGood() const;
    inline bool IsBad() const;
public:
    inline IntegerValueType GetBadCode() const;
    inline BufferIntegerValueType GetBufferBadCode() const;
};

inline Task::Task() :
    BaseType(),
    m_type_id(undefined_type_id),
    m_id(reinterpret_cast<std::intptr_t>(this)),
    m_delegate_id(0),
    m_buffer{.char_out_ptr = nullptr}
{}

inline Task::Task(test::out::Type<char>) :
    BaseType(),
    m_type_id(char_type_id),
    m_id(reinterpret_cast<std::intptr_t>(this)),
    m_delegate_id(0),
    m_buffer{.char_out_ptr = new test::out::CString<char>()}
{}

inline Task::Task(test::out::Type<wchar_t>) :
    BaseType(),
    m_type_id(wchar_type_id),
    m_id(reinterpret_cast<std::intptr_t>(this)),
    m_delegate_id(0),
    m_buffer{.wchar_out_ptr = new test::out::CString<wchar_t>()}
{}

inline Task::~Task()
{
    if (m_type_id == char_type_id &&
        m_buffer.char_out_ptr != nullptr)
    {
        delete m_buffer.char_out_ptr;
        m_buffer.char_out_ptr = nullptr;
    }
    else if(m_type_id == wchar_type_id &&
        m_buffer.wchar_out_ptr != nullptr)
    {
        delete m_buffer.wchar_out_ptr;
        m_buffer.wchar_out_ptr = nullptr;
    }
}

inline Task::Task(Task&& mov) :
    BaseType(std::move(static_cast<BaseType&&>(mov))),
    m_type_id(mov.m_type_id),
    m_id(mov.m_id),
    m_delegate_id(mov.m_delegate_id),
    m_buffer(mov.m_buffer)
{
    mov.m_type_id = undefined_type_id;
    mov.m_delegate_id = 0;
    mov.m_buffer.char_out_ptr = nullptr;
    mov.GetStatus().Remove();
}

inline bool Task::operator==(const std::intptr_t& id) const
{
    return m_id == id;
}

inline bool Task::operator!=(const std::intptr_t& id) const
{
    return m_id != id;
}

inline bool Task::Execute(test::out::Interface<char>& out)
{
    auto guard = BaseType::ExecuteGuard();
    if (!guard) return false;
    
    auto& status = BaseType::GetStatus();
    if (!status.Execute()) return false;

    if (m_type_id != char_type_id || 
        m_buffer.char_out_ptr == nullptr)
    {
        status.Bad(status.execute_output_failed);
        return false;
    }

    return m_buffer.char_out_ptr->Output(out);
}

inline bool Task::Execute(test::out::Interface<wchar_t>& out)
{
    auto guard = BaseType::ExecuteGuard();
    if (!guard) return false;
    
    auto& status = BaseType::GetStatus();
    if (!status.Execute()) return false;

    if (m_type_id != wchar_type_id ||
        m_buffer.wchar_out_ptr == nullptr)
    {
        status.Bad(status.execute_output_failed);
        return false;
    }

    return m_buffer.wchar_out_ptr->Output(out);
}

inline bool Task::Execute(test::out::Interface<char, wchar_t>& out)
{
    auto guard = BaseType::ExecuteGuard();
    if (!guard) return false;
    
    auto& status = BaseType::GetStatus();
    if (!status.Execute()) return false;

    if (m_type_id == char_type_id &&
        m_buffer.char_out_ptr != nullptr)
    {
        return m_buffer.char_out_ptr->Output(out);
    }
    else if (m_type_id == wchar_type_id &&
        m_buffer.wchar_out_ptr != nullptr)
    {
        return m_buffer.wchar_out_ptr->Output(out);
    }
    status.Bad(status.execute_output_failed);
    return false;
}

inline bool Task::Assign(const std::intptr_t& deleg_id,
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

inline bool Task::Release(const std::intptr_t& deleg_id)
{
    auto guard = BaseType::ReleaseGuard();
    if (!guard) return false;

    if (m_delegate_id != 0 && m_delegate_id != deleg_id) return false;
    auto& status = BaseType::GetStatus();
    return status.Release();
}

inline typename Task::BufferType<char>
Task::Buffer(test::out::Type<char>, const std::intptr_t& deleg_id)
{
    auto guard = BaseType::BufferGuard();
    if (!guard) return {};

    if (m_delegate_id != 0 && m_delegate_id != deleg_id) return {};

    auto& status = BaseType::GetStatus();

    if (m_type_id != char_type_id || 
        m_buffer.char_out_ptr == nullptr)
    {
        status.Bad(status.bad_buffer);
        return {};
    }

    if (m_buffer.char_out_ptr->IsBad())
    {
        status.Bad(StatusType::buffer_failed);
        return {};
    }

    return {m_buffer.char_out_ptr, std::move(guard)};
}

inline typename Task::BufferType<wchar_t>
Task::Buffer(test::out::Type<wchar_t>, const std::intptr_t& deleg_id)
{
    auto guard = BaseType::BufferGuard();
    if (!guard) return {};

    if (m_delegate_id != 0 && m_delegate_id != deleg_id) return {};

    auto& status = BaseType::GetStatus();

    if (m_type_id != wchar_type_id || 
        m_buffer.wchar_out_ptr == nullptr)
    {
        status.Bad(status.bad_buffer);
        return {};
    }

    if (m_buffer.char_out_ptr->IsBad())
    {
        status.Bad(StatusType::buffer_failed);
        return {};
    }

    return {m_buffer.wchar_out_ptr, std::move(guard)};
}

inline bool Task::IsDone() const
{
    return BaseType::GetStatus().IsDone();
}

inline bool Task::IsRelease() const
{
    return BaseType::GetStatus().IsRelease();
}

inline bool Task::IsAssign() const
{
    return BaseType::GetStatus().IsAssign();
}

inline bool Task::IsGood() const
{
    return BaseType::GetStatus().IsGood();
}

inline bool Task::IsBad() const
{
    return BaseType::GetStatus().IsBad(); 
}

inline typename Task::IntegerValueType Task::GetBadCode() const
{
    return BaseType::GetStatus().GetBadCode(); 
}

inline typename Task::BufferIntegerValueType Task::GetBufferBadCode() const
{
    if (m_type_id == char_type_id &&
        m_buffer.char_out_ptr != nullptr)
    {
        return m_buffer.char_out_ptr->GetBadCode();
    }
    else if (m_type_id == wchar_type_id &&
        m_buffer.wchar_out_ptr != nullptr)
    {
        return m_buffer.wchar_out_ptr->GetBadCode();
    }
    return test::out::CString<>::StatusType::bad;
}

} //!base

} //!out

} //!test

#endif //!TEST_OUT_BASE_TASK_H_
