#ifndef TEST_OUT_BASE_TASK_BASE_IMP_DEFAULT_H_
#define TEST_OUT_BASE_TASK_BASE_IMP_DEFAULT_H_

#include "../Interface.h"
#include "../../Interface.h"
#include "../../Status.h"
#include "../../../../Interface.h"
#include "../../../../Type.h"

#include <cstdint>
#include <utility>
#include <cwchar>

namespace test
{
namespace out
{
namespace base
{
namespace task
{
namespace base
{
namespace imp
{

class Default :
    protected test::out::base::task::base::Interface<
        test::out::base::task::Status<std::uint8_t>>,
    public test::out::base::task::Interface< 
        test::out::base::task::Status<std::uint8_t>>
{
protected:
    typedef test::out::base::task::base::Interface<StatusType> BaseType;
public:
    typedef test::out::base::task::Status<std::uint8_t> StatusType;
    typedef test::out::base::task::Interface< 
        StatusType> TaskInterfaceType;
    template<typename TChar>
    using BufferType = typename TaskInterfaceType::template BufferType<TChar>;
protected:
    inline Default();
    inline Default(const std::uint8_t& val);
public:
    virtual inline ~Default();
public:
    inline Default(const Default&) = delete;
    inline Default(Default&& mov);
public:
    inline Default& operator=(const Default&) = delete;
    inline Default& operator=(Default&&) = delete;
private:
    inline bool _BeginExecute() override final;
    inline void _EndExecute() override final;
private:
    inline bool _BeginAssign() override final;
    inline void _EndAssign() override final;
private:
    inline bool _BeginRelease() override final;
    inline void _EndRelease() override final;
private:
    inline bool _BeginBuffer() override final;
    inline void _EndBuffer() override final;
protected:
    inline test::Guard<BaseType> ExecuteGuard() override final;
    inline test::Guard<BaseType> AssignGuard() override final;
    inline test::Guard<BaseType> ReleaseGuard() override final;
    inline test::Guard<BaseType> BufferGuard() override final;
public:
    virtual inline bool Execute(test::out::Interface<char>& out) override;
    virtual inline bool Execute(test::out::Interface<wchar_t>& out) override;
    virtual inline bool Execute(test::out::Interface<char, 
        wchar_t>& out) override;
public:
    virtual inline bool Assign(const std::intptr_t& deleg_id,
        std::intptr_t& task_id) override;
public:
    virtual inline bool Release(const std::intptr_t& deleg_id) override;
public:
    virtual inline BufferType<char> Buffer(test::out::Type<char>,
        const std::intptr_t& deleg_id) override;
    virtual inline BufferType<wchar_t> Buffer(test::out::Type<wchar_t>,
        const std::intptr_t& deleg_id) override;
};

inline Default::Default() :
    BaseType()
{}

inline Default::Default(const std::uint8_t& val) :
    BaseType(val)
{}

inline Default::~Default()
{}

inline Default::Default(Default&& mov) :
    BaseType(std::move(static_cast<BaseType&&>(mov)))
{}

inline bool Default::_BeginExecute()
{
    return true;
}

inline void Default::_EndExecute()
{}

inline bool Default::_BeginAssign()
{
    return true;
}

inline void Default::_EndAssign()
{}

inline bool Default::_BeginRelease()
{
    return true;
}

inline void Default::_EndRelease()
{}

inline bool Default::_BeginBuffer()
{
    return true;
}

inline void Default::_EndBuffer()
{}

inline test::Guard<typename Default::BaseType> Default::ExecuteGuard()
{
    return {this, &BaseType::_BeginExecute, &BaseType::_EndExecute};
}

test::Guard<typename Default::BaseType> Default::AssignGuard()
{
    return {this, &BaseType::_BeginAssign, &BaseType::_EndAssign};
}

inline test::Guard<typename Default::BaseType> Default::ReleaseGuard()
{
    return {this, &BaseType::_BeginRelease, &BaseType::_EndRelease};
}

inline test::Guard<typename Default::BaseType> Default::BufferGuard()
{
    return {this, &BaseType::_BeginBuffer, &BaseType::_EndBuffer};
}

inline bool Default::Execute(test::out::Interface<char>&)
{
    return false;
}

inline bool Default::Execute(test::out::Interface<wchar_t>&)
{
    return false;
}

inline bool Default::Execute(test::out::Interface<char, wchar_t>&)
{
    return false;
}

inline bool Default::Assign(const std::intptr_t&, 
    std::intptr_t&)
{
    return false;
}

inline bool Default::Release(const std::intptr_t&)
{
    return false;
}

inline typename Default::template BufferType<char> 
Default::Buffer(test::out::Type<char>, const std::intptr_t&)
{
    return {};
}

inline typename Default::template BufferType<wchar_t> 
Default::Buffer(test::out::Type<wchar_t>, const std::intptr_t&)
{
    return {};
}

} //!imp

} //!base

} //!task

} //!base

} //!out

} //!test

#endif //!TEST_OUT_BASE_TASK_BASE_IMP_DEFAULT_H_
