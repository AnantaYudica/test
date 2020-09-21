#ifndef TEST_OUT_BASE_TASK_INTERFACE_H_
#define TEST_OUT_BASE_TASK_INTERFACE_H_

#include "../../Interface.h"
#include "../../Type.h"
#include "base/Interface.h"
#include "Buffer.h"

#include <cstdint>
#include <cwchar>

namespace test
{
namespace out
{
namespace base
{
namespace task
{

template<typename TStatus>
class Interface
{
public:
    template<typename TChar>
    using BufferType = test::out::base::task::Buffer<TChar,
        test::out::base::task::base::Interface<TStatus>>;
protected:
    Interface() = default;
public:
    virtual ~Interface() = default;
public:
    Interface(const Interface<TStatus>&) = delete;
    Interface(Interface<TStatus>&& mov) = default;
public:
    Interface<TStatus>& operator=(const Interface<TStatus>&) = delete;
    Interface<TStatus>& operator=(Interface<TStatus>&&) = delete;
public:
    virtual bool Execute(test::out::Interface<char>& out) = 0;
    virtual bool Execute(test::out::Interface<wchar_t>& out) = 0;
    virtual bool Execute(test::out::Interface<char, wchar_t>& out) = 0;
public:
    virtual bool Assign(const std::intptr_t& deleg_id,
        std::intptr_t& task_id) = 0;
public:
    virtual bool Release(const std::intptr_t& deleg_id) = 0;
public:
    virtual BufferType<char> Buffer(test::out::Type<char>, 
        const std::intptr_t& deleg_id) = 0;
    virtual BufferType<wchar_t> Buffer(test::out::Type<wchar_t>, 
        const std::intptr_t& deleg_id) = 0;
};

} //!task

} //!base

} //!out

} //!test

#endif //!TEST_OUT_BASE_TASK_INTERFACE_H_
