#ifndef TEST_OUT_BASE_TASK_BASE_IMP_DEFAULT_H_
#define TEST_OUT_BASE_TASK_BASE_IMP_DEFAULT_H_

#include "../Interface.h"
#include "../../Interface.h"
#include "../../Status.h"

#include <cstdint>
#include <utility>

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

template<typename TChar>
class Default :
    protected test::out::base::task::base::Interface<
        test::out::base::task::Status<std::uint8_t>>,
    public test::out::base::task::Interface<TChar, 
        test::out::base::task::Status<std::uint8_t>>
{
protected:
    typedef test::out::base::task::base::Interface<StatusType> BaseType;
public:
    typedef test::out::base::task::Status<std::uint8_t> StatusType;
    typedef test::out::base::task::Interface<TChar, 
        StatusType> TaskInterfaceType;
    typedef typename TaskInterfaceType::BufferType BufferType;
protected:
    Default();
    Default(const std::uint8_t& val);
public:
    virtual ~Default();
public:
    Default(const Default&) = delete;
    Default(Default&& mov);
public:
    Default& operator=(const Default&) = delete;
    Default& operator=(Default&&) = delete;
private:
    bool _BeginExecute() override final;
    void _EndExecute() override final;
private:
    bool _BeginAssign() override final;
    void _EndAssign() override final;
private:
    bool _BeginRelease() override final;
    void _EndRelease() override final;
private:
    bool _BeginBuffer() override final;
    void _EndBuffer() override final;
protected:
    test::Guard<BaseType> ExecuteGuard() override final;
    test::Guard<BaseType> AssignGuard() override final;
    test::Guard<BaseType> ReleaseGuard() override final;
    test::Guard<BaseType> BufferGuard() override final;
public:
    virtual bool Execute(test::out::Interface<TChar>& out);
public:
    virtual bool Assign(const std::intptr_t& deleg_id,
        std::intptr_t& task_id);
public:
    virtual bool Release(const std::intptr_t& deleg_id);
public:
    virtual BufferType Buffer(const std::intptr_t& deleg_id);
};

template<typename TChar>
Default<TChar>::Default() :
    BaseType()
{}

template<typename TChar>
Default<TChar>::Default(const std::uint8_t& val) :
    BaseType(val)
{}

template<typename TChar>
Default<TChar>::~Default()
{}

template<typename TChar>
Default<TChar>::Default(Default&& mov) :
    BaseType(std::move(static_cast<BaseType&&>(mov)))
{}

template<typename TChar>
bool Default<TChar>::_BeginExecute()
{
    return true;
}

template<typename TChar>
void Default<TChar>::_EndExecute()
{}

template<typename TChar>
bool Default<TChar>::_BeginAssign()
{
    return true;
}

template<typename TChar>
void Default<TChar>::_EndAssign()
{}

template<typename TChar>
bool Default<TChar>::_BeginRelease()
{
    return true;
}

template<typename TChar>
void Default<TChar>::_EndRelease()
{}

template<typename TChar>
bool Default<TChar>::_BeginBuffer()
{
    return true;
}

template<typename TChar>
void Default<TChar>::_EndBuffer()
{}

template<typename TChar>
test::Guard<typename Default<TChar>::BaseType> 
Default<TChar>::ExecuteGuard()
{
    return {this, &BaseType::_BeginExecute, &BaseType::_EndExecute};
}

template<typename TChar>
test::Guard<typename Default<TChar>::BaseType> 
Default<TChar>::AssignGuard()
{
    return {this, &BaseType::_BeginAssign, &BaseType::_EndAssign};
}

template<typename TChar>
test::Guard<typename Default<TChar>::BaseType> 
Default<TChar>::ReleaseGuard()
{
    return {this, &BaseType::_BeginRelease, &BaseType::_EndRelease};
}

template<typename TChar>
test::Guard<typename Default<TChar>::BaseType> 
Default<TChar>::BufferGuard()
{
    return {this, &BaseType::_BeginBuffer, &BaseType::_EndBuffer};
}

template<typename TChar>
bool Default<TChar>::Execute(test::out::Interface<TChar>& out)
{
    return false;
}

template<typename TChar>
bool Default<TChar>::Assign(const std::intptr_t& deleg_id, 
    std::intptr_t& task_id)
{
    return false;
}

template<typename TChar>
bool Default<TChar>::Release(const std::intptr_t& deleg_id)
{
    return false;
}

template<typename TChar>
typename Default<TChar>::BufferType 
Default<TChar>::Buffer(const std::intptr_t& deleg_id)
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