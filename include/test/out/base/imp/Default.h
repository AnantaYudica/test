#ifndef TEST_OUT_BASE_IMP_DEFAULT_H_
#define TEST_OUT_BASE_IMP_DEFAULT_H_

#include "../Delegate.h"
#include "../Interface.h"
#include "../Status.h"
#include "../task/Base.h"
#include "../../../Guard.h"

#include <cstdint>

namespace test
{
namespace out
{
namespace base
{
namespace imp
{

class Default :
    protected test::out::base::Interface<
        test::out::base::Status<std::uint8_t>>
{
protected:
    typedef test::out::base::Status<std::uint8_t> StatusType;
    typedef test::out::base::Interface<StatusType> BaseType;
protected:
    inline Default() = default;
public:
    virtual inline ~Default() = default;
public:
    inline Default(const Default&) = delete;
    inline Default(Default&&) = delete;
public:
    inline Default& operator=(const Default&) = delete;
    inline Default& operator=(Default&&) = delete;
private:
    inline bool Finalize(const std::intptr_t& id) override final;
private:
    inline bool _BeginRequestTask() override final;
    inline void _EndRequestTask() override final;
private:
    inline bool _BeginExecuteTask() override final;
    inline void _EndExecuteTask() override final;
protected:
    inline test::Guard<BaseType> RequestTaskGuard() override final;
    inline test::Guard<BaseType> ExecuteTaskGuard() override final;
protected:
    virtual inline bool ExecuteTask(const std::intptr_t& id) override;
};

inline bool Default::Finalize(const std::intptr_t& m_id)
{
    return ExecuteTask(m_id);
}

inline bool Default::_BeginRequestTask()
{
    return true;
}

inline void Default::_EndRequestTask()
{}

inline bool Default::_BeginExecuteTask()
{
    return true;
}

inline void Default::_EndExecuteTask()
{}

inline test::Guard<typename Default::BaseType> Default::RequestTaskGuard()
{
    return {this, &BaseType::_BeginRequestTask, &BaseType::_EndRequestTask};
}

inline test::Guard<typename Default::BaseType> Default::ExecuteTaskGuard()
{
    return {this, &BaseType::_BeginExecuteTask, &BaseType::_EndExecuteTask};
}

inline bool Default::ExecuteTask(const std::intptr_t&)
{
    return false;
}

} //!imp

} //!base

} //!out

} //!test

#endif //!TEST_OUT_BASE_IMP_DEFAULT_H_
