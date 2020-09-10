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

template<typename TChar>
class Default :
    protected test::out::base::Interface<
        test::out::base::Status<std::uint8_t>>
{
private:
    typedef test::out::base::task::Base<TChar> TaskBaseType;
protected:
    typedef test::out::base::Status<std::uint8_t> StatusType;
    typedef test::out::base::Interface<StatusType> BaseType;
    typedef test::out::base::Delegate<TChar, StatusType,
        typename TaskBaseType::StatusType> DelegateType;
protected:
    Default() = default;
public:
    virtual ~Default() = default;
public:
    Default(const Default<TChar>&) = delete;
    Default(Default<TChar>&&) = delete;
public:
    Default<TChar>& operator=(const Default<TChar>&) = delete;
    Default<TChar>& operator=(Default<TChar>&&) = delete;
private:
    bool Finalize(const std::intptr_t& id) override final;
private:
    bool _BeginRequestTask() override final;
    void _EndRequestTask() override final;
private:
    bool _BeginExecuteTask() override final;
    void _EndExecuteTask() override final;
protected:
    test::Guard<BaseType> RequestTaskGuard() override final;
    test::Guard<BaseType> ExecuteTaskGuard() override final;
protected:
    virtual bool ExecuteTask(const std::intptr_t& id) override;
};

template<typename TChar>
bool Default<TChar>::Finalize(const std::intptr_t& m_id)
{
    return ExecuteTask(m_id);
}

template<typename TChar>
bool Default<TChar>::_BeginRequestTask()
{
    return true;
}

template<typename TChar>
void Default<TChar>::_EndRequestTask()
{}

template<typename TChar>
bool Default<TChar>::_BeginExecuteTask()
{
    return true;
}

template<typename TChar>
void Default<TChar>::_EndExecuteTask()
{}

template<typename TChar>
test::Guard<typename Default<TChar>::BaseType> 
Default<TChar>::RequestTaskGuard()
{
    return {this, &BaseType::_BeginRequestTask, &BaseType::_EndRequestTask};
}

template<typename TChar>
test::Guard<typename Default<TChar>::BaseType> 
Default<TChar>::ExecuteTaskGuard()
{
    return {this, &BaseType::_BeginExecuteTask, &BaseType::_EndExecuteTask};
}

template<typename TChar>
bool Default<TChar>::ExecuteTask(const std::intptr_t&)
{
    return false;
}

} //!imp

} //!base

} //!out

} //!test

#endif //!TEST_OUT_BASE_IMP_DEFAULT_H_
