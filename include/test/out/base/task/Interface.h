#ifndef TEST_OUT_BASE_TASK_INTERFACE_H_
#define TEST_OUT_BASE_TASK_INTERFACE_H_

#include "../../Interface.h"
#include "base/Interface.h"
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
class Interface
{
public:
    typedef test::out::base::task::Buffer<TChar,
        test::out::base::task::base::Interface<TStatus>> BufferType;
protected:
    Interface() = default;
public:
    virtual ~Interface() = default;
public:
    Interface(const Interface<TChar, TStatus>&) = delete;
    Interface(Interface<TChar, TStatus>&& mov) = default;
public:
    Interface<TChar, TStatus>& 
        operator=(const Interface<TChar, TStatus>&) = delete;
    Interface<TChar, TStatus>& 
        operator=(Interface<TChar, TStatus>&&) = delete;
public:
    virtual bool Execute(test::out::Interface<TChar>& out) = 0;
public:
    virtual bool Assign(const std::intptr_t& deleg_id) = 0;
public:
    virtual bool Release(const std::intptr_t& deleg_id) = 0;
public:
    virtual BufferType Buffer(const std::intptr_t& deleg_id) = 0;
};

} //!task

} //!base

} //!out

} //!test

#endif //!TEST_OUT_BASE_TASK_INTERFACE_H_
