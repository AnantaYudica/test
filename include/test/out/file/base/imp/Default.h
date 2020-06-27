#ifndef TEST_OUT_FILE_BASE_IMP_DEFAULT_H_
#define TEST_OUT_FILE_BASE_IMP_DEFAULT_H_

#include "../Interface.h"
#include "../../Status.h"

namespace test
{
namespace out
{
namespace file
{
namespace base
{
namespace imp
{

class Default : protected test::out::file::base::Interface<
    test::out::file::Status<std::uint8_t>>
{
public:
    typedef test::out::file::Status<std::uint8_t> StatusType;
    typedef test::out::file::base::Interface<StatusType> BaseType;
protected:
    inline Default();
    inline Default(const std::uint8_t& val);
public:
    inline ~Default() = default;
public:
    Default(const Default &) = delete;
    Default(Default &&) = delete;
public:
    Default& operator=(const Default&) = delete;
    Default& operator=(Default&&) = delete;
private:
    inline bool _BeginPrint() override final;
    inline void _EndPrint() override final;
private:
    inline bool _BeginPuts() override final;
    inline void _EndPuts() override final;
private:
    inline bool _BeginLastOutput() override final;
    inline void _EndLastOutput() override final;
protected:
    inline test::Guard<test::out::file::base::Interface<
        StatusType>> PrintGuard() override final;
    inline test::Guard<test::out::file::base::Interface<
        StatusType>> PutsGuard() override final;
    inline test::Guard<test::out::file::base::Interface<
        StatusType>> LastOutputGuard() override final;
};

inline Default::Default() :
    BaseType()
{}

inline Default::Default(const std::uint8_t& val) :
    BaseType(val)
{}

inline bool Default::_BeginPrint()
{
    return true;
}

inline void Default::_EndPrint()
{}

inline bool Default::_BeginPuts()
{
    return true;
}

inline void Default::_EndPuts()
{}

inline bool Default::_BeginLastOutput()
{
    return true;
}

inline void Default::_EndLastOutput()
{}

inline test::Guard<test::out::file::base::Interface<
    typename Default::StatusType>> 
Default::PrintGuard()
{
    return {this, &BaseType::_BeginPrint, &BaseType::_EndPrint};
}

inline test::Guard<test::out::file::base::Interface<
    typename Default::StatusType>> 
Default::PutsGuard()
{
    return {this, &BaseType::_BeginPuts, &BaseType::_EndPuts};
}

inline test::Guard<test::out::file::base::Interface<
    typename Default::StatusType>> 
Default::LastOutputGuard()
{
    return {this, &BaseType::_BeginLastOutput, &BaseType::_EndLastOutput};
}

} //!imp

} //!base

} //!file

} //!out

} //!test

#endif //!TEST_OUT_FILE_BASE_IMP_DEFAULT_H_