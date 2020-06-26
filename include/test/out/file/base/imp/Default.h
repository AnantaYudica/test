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
private:
    StatusType m_status;
protected:
    inline Default() = default;
public:
    inline ~Default() = default;
public:
    Default(const Default &) = delete;
    Default(Default &&) = delete;
public:
    Default& operator=(const Default&) = delete;
    Default& operator=(Default&&) = delete;
protected:
    inline StatusType& GetStatus();
    inline StatusType GetStatus() const;
private:
    inline bool BeginPrint();
    inline void EndPrint();
private:
    inline bool BeginPuts();
    inline void EndPuts();
private:
    inline bool BeginLastOutput();
    inline void EndLastOutput();
protected:
    inline test::Guard<test::out::file::base::Interface<
        StatusType>> PrintGuard();
    inline test::Guard<test::out::file::base::Interface<
        StatusType>> PutsGuard();
    inline test::Guard<test::out::file::base::Interface<
        StatusType>> LastOutputGuard();
};

inline typename Default::StatusType& Default::GetStatus()
{
    return m_status;
}

inline typename Default::StatusType Default::GetStatus() const
{
    return {m_status};
}

inline bool Default::BeginPrint()
{
    return true;
}

inline void Default::EndPrint()
{}

inline bool Default::BeginPuts()
{
    return true;
}

inline void Default::EndPuts()
{}

inline bool Default::BeginLastOutput()
{
    return true;
}

inline void Default::EndLastOutput()
{}

inline test::Guard<test::out::file::base::Interface<
    typename Default::StatusType>> 
Default::PrintGuard()
{
    return {this, &BaseType::BeginPrint, &BaseType::EndPrint};
}

inline test::Guard<test::out::file::base::Interface<
    typename Default::StatusType>> 
Default::PutsGuard()
{
    return {this, &BaseType::BeginPuts, &BaseType::EndPuts};
}

inline test::Guard<test::out::file::base::Interface<
    typename Default::StatusType>> 
Default::LastOutputGuard()
{
    return {this, &BaseType::BeginLastOutput, &BaseType::EndLastOutput};
}

} //!imp

} //!base

} //!file

} //!out

} //!test

#endif //!TEST_OUT_FILE_BASE_IMP_DEFAULT_H_