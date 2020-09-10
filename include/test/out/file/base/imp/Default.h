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
    inline bool _BeginInitialize() override final;
    inline void _EndInitialize() override final;
private:
    inline bool _BeginMode() override final;
    inline void _EndMode() override final;
private:
    inline bool _BeginSize() override final;
    inline void _EndSize() override final;
private:
    inline bool _BeginFilename() override final;
    inline void _EndFilename() override final;
private:
    inline bool _BeginPrint() override final;
    inline void _EndPrint() override final;
private:
    inline bool _BeginPuts() override final;
    inline void _EndPuts() override final;
private:
    inline bool _BeginBuffer() override final;
    inline void _EndBuffer() override final;
protected:
    inline test::Guard<test::out::file::base::Interface<
        StatusType>> InitializeGuard() override final;
    inline test::Guard<test::out::file::base::Interface<
        StatusType>> ModeGuard() override final;
    inline test::Guard<test::out::file::base::Interface<
        StatusType>> SizeGuard() override final;
    inline test::Guard<test::out::file::base::Interface<
        StatusType>> FilenameGuard() override final;
    inline test::Guard<test::out::file::base::Interface<
        StatusType>> PrintGuard() override final;
    inline test::Guard<test::out::file::base::Interface<
        StatusType>> PutsGuard() override final;
    inline test::Guard<test::out::file::base::Interface<
        StatusType>> BufferGuard() override final;
};

inline Default::Default() :
    BaseType()
{}

inline Default::Default(const std::uint8_t& val) :
    BaseType(val)
{}

inline bool Default::_BeginInitialize()
{
    return true;
}

inline void Default::_EndInitialize()
{}

inline bool Default::_BeginMode()
{
    return true;
}

inline void Default::_EndMode()
{}

inline bool Default::_BeginSize()
{
    return true;
}

inline void Default::_EndSize()
{}

inline bool Default::_BeginFilename()
{
    return true;
}

inline void Default::_EndFilename()
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

inline bool Default::_BeginBuffer()
{
    return true;
}

inline void Default::_EndBuffer()
{}

inline test::Guard<test::out::file::base::Interface<
    typename Default::StatusType>> 
Default::InitializeGuard()
{
    return {this, &BaseType::_BeginInitialize, 
        &BaseType::_EndInitialize};
}

inline test::Guard<test::out::file::base::Interface<
    typename Default::StatusType>> 
Default::ModeGuard()
{
    return {this, &BaseType::_BeginMode, &BaseType::_EndMode};
}

inline test::Guard<test::out::file::base::Interface<
    typename Default::StatusType>> 
Default::SizeGuard()
{
    return {this, &BaseType::_BeginSize, &BaseType::_EndSize};
}

inline test::Guard<test::out::file::base::Interface<
    typename Default::StatusType>> 
Default::FilenameGuard()
{
    return {this, &BaseType::_BeginFilename, &BaseType::_EndFilename};
}

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
Default::BufferGuard()
{
    return {this, &BaseType::_BeginBuffer, &BaseType::_EndBuffer};
}

} //!imp

} //!base

} //!file

} //!out

} //!test

#endif //!TEST_OUT_FILE_BASE_IMP_DEFAULT_H_
