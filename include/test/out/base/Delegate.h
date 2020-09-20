#ifndef TEST_OUT_BASE_DELEGATE_H_
#define TEST_OUT_BASE_DELEGATE_H_

#include "../CString.h"
#include "../Interface.h"
#include "Interface.h"
#include "deleg/Status.h"
#include "deleg/Base.h"
#include "task/Interface.h"
#include "task/Buffer.h"

#include <cstdint>
#include <cstdarg>
#include <cwchar>

#ifndef TEST_ATTRIBUTE
#ifdef __GNUC__
#define TEST_ATTRIBUTE(...) __attribute__(__VA_ARGS__)
#else
#define TEST_ATTRIBUTE(...)
#endif
#endif //!TEST_ATTRIBUTE

namespace test
{
namespace out
{
namespace base
{

template<typename TChar, typename TStatus, typename TTaskStatus>
class Delegate :
    private test::out::base::deleg::Base<TChar, TStatus, TTaskStatus>,
    public test::out::Interface<TChar>
{
private:
    typedef test::out::base::deleg::Base<TChar, TStatus, TTaskStatus> BaseType;
public:
    typedef typename BaseType::TaskInterfaceType TaskInterfaceType;
    typedef typename BaseType::BufferType BufferType;
    typedef typename BaseType::BaseInterfaceType BaseInterfaceType;
    typedef typename BaseType::SizeType SizeType;
    typedef typename BaseType::StatusType StatusType;
public:
    Delegate();
    Delegate(BaseInterfaceType * base_intf, TaskInterfaceType * task);
public:
    virtual ~Delegate();
public:
    Delegate(const Delegate<TChar, TStatus, TTaskStatus>&) = delete;
    Delegate(Delegate<TChar, TStatus, TTaskStatus>&& mov);
public:
    Delegate<TChar, TStatus, TTaskStatus>& 
        operator=(const Delegate<TChar, TStatus, TTaskStatus>&) = delete;
    Delegate<TChar, TStatus, TTaskStatus>& 
        operator=(Delegate<TChar, TStatus, TTaskStatus>&&) = delete;
protected:
    using BaseType::GetBuffer;
public:
    virtual SizeType VPrint(const char * format, va_list var_args) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));;
    virtual SizeType Print(const char * format, ...) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 3)));;
public:
    virtual SizeType Puts(const TChar * cstr, const SizeType& size) override;
    virtual SizeType Puts(const TChar * cstr) override;
    virtual SizeType Puts(const test::CString<TChar>& cstr) override;
    virtual SizeType Puts(const test::CString<const TChar>& cstr) override;
public:
    virtual bool IsGood() const override;
    virtual bool IsBad() const override;
public:
    using BaseType::GetBadCode;
};

template<typename TStatus, typename TTaskStatus>
class Delegate<char, TStatus, TTaskStatus> :
    private test::out::base::deleg::Base<char, TStatus, TTaskStatus>,
    public test::out::Interface<char>
{
private:
    typedef test::out::base::deleg::Base<char, TStatus, TTaskStatus> BaseType;
public:
    typedef typename BaseType::TaskInterfaceType TaskInterfaceType;
    typedef typename BaseType::BufferType BufferType;
    typedef typename BaseType::BaseInterfaceType BaseInterfaceType;
    typedef typename BaseType::SizeType SizeType;
    typedef typename BaseType::StatusType StatusType;
public:
    Delegate();
    Delegate(BaseInterfaceType * base_intf, TaskInterfaceType * task);
public:
    virtual ~Delegate();
public:
    Delegate(const Delegate<char, TStatus, TTaskStatus>&) = delete;
    Delegate(Delegate<char, TStatus, TTaskStatus>&& mov);
public:
    Delegate<char, TStatus, TTaskStatus>& 
        operator=(const Delegate<char, TStatus, TTaskStatus>&) = delete;
    Delegate<char, TStatus, TTaskStatus>& 
        operator=(Delegate<char, TStatus, TTaskStatus>&&) = delete;
protected:
    using BaseType::GetBuffer;
public:
    virtual SizeType VPrint(const char * format, va_list var_args) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));
    virtual SizeType Print(const char * format, ...) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 3)));
public:
    virtual SizeType Puts(const char * cstr, const SizeType& size) override;
    virtual SizeType Puts(const char * cstr) override;
    virtual SizeType Puts(const test::CString<char>& cstr) override;
    virtual SizeType Puts(const test::CString<const char>& cstr) override;
public:
    virtual bool IsGood() const override;
    virtual bool IsBad() const override;
public:
    using BaseType::GetBadCode;
};

template<typename TStatus, typename TTaskStatus>
class Delegate<wchar_t, TStatus, TTaskStatus> :
    private test::out::base::deleg::Base<wchar_t, TStatus, TTaskStatus>,
    public test::out::Interface<wchar_t>
{
private:
    typedef test::out::base::deleg::Base<wchar_t, TStatus, 
        TTaskStatus> BaseType;
public:
    typedef typename BaseType::TaskInterfaceType TaskInterfaceType;
    typedef typename BaseType::BufferType BufferType;
    typedef typename BaseType::BaseInterfaceType BaseInterfaceType;
    typedef typename BaseType::SizeType SizeType;
    typedef typename BaseType::StatusType StatusType;
public:
    Delegate();
    Delegate(BaseInterfaceType * base_intf, TaskInterfaceType * task);
public:
    virtual ~Delegate();
public:
    Delegate(const Delegate<wchar_t, TStatus, TTaskStatus>&) = delete;
    Delegate(Delegate<wchar_t, TStatus, TTaskStatus>&& mov);
public:
    Delegate<wchar_t, TStatus, TTaskStatus>& 
        operator=(const Delegate<wchar_t, TStatus, TTaskStatus>&) = delete;
    Delegate<wchar_t, TStatus, TTaskStatus>& 
        operator=(Delegate<wchar_t, TStatus, TTaskStatus>&&) = delete;
protected:
    using BaseType::GetBuffer;
public:
    virtual SizeType VPrint(const wchar_t * format, va_list var_args) override;
    virtual SizeType Print(const wchar_t * format, ...) override;
public:
    virtual SizeType Puts(const wchar_t * cstr, const SizeType& size) override;
    virtual SizeType Puts(const wchar_t * cstr) override;
    virtual SizeType Puts(const test::CString<wchar_t>& cstr) override;
    virtual SizeType Puts(const test::CString<const wchar_t>& cstr) override;
public:
    virtual bool IsGood() const override;
    virtual bool IsBad() const override;
public:
    using BaseType::GetBadCode;
};

template<typename TChar, typename TStatus, typename TTaskStatus>
Delegate<TChar, TStatus, TTaskStatus>::Delegate() :
    BaseType()
{}

template<typename TChar, typename TStatus, typename TTaskStatus>
Delegate<TChar, TStatus, TTaskStatus>::Delegate(BaseInterfaceType * base_intf, 
    TaskInterfaceType * task) :
        BaseType(base_intf, task)
{}

template<typename TChar, typename TStatus, typename TTaskStatus>
Delegate<TChar, TStatus, TTaskStatus>::~Delegate()
{}

template<typename TChar, typename TStatus, typename TTaskStatus>
Delegate<TChar, TStatus, TTaskStatus>::
    Delegate(Delegate<TChar, TStatus, TTaskStatus>&& mov) :
        BaseType(std::move(mov))
{}

template<typename TChar, typename TStatus, typename TTaskStatus>
typename Delegate<TChar, TStatus, TTaskStatus>::SizeType 
Delegate<TChar, TStatus, TTaskStatus>::Puts(const TChar * cstr, 
    const SizeType& size)
{
    return GetBuffer().Puts(cstr, size);
}

template<typename TChar, typename TStatus, typename TTaskStatus>
typename Delegate<TChar, TStatus, TTaskStatus>::SizeType 
Delegate<TChar, TStatus, TTaskStatus>::Puts(const TChar * cstr)
{
    return GetBuffer().Puts(cstr);
}

template<typename TChar, typename TStatus, typename TTaskStatus>
typename Delegate<TChar, TStatus, TTaskStatus>::SizeType 
Delegate<TChar, TStatus, TTaskStatus>::Puts(const test::CString<TChar>& cstr)
{
    return GetBuffer().Puts(cstr);
}

template<typename TChar, typename TStatus, typename TTaskStatus>
typename Delegate<TChar, TStatus, TTaskStatus>::SizeType 
Delegate<TChar, TStatus, TTaskStatus>::
    Puts(const test::CString<const TChar>& cstr)
{
    return GetBuffer().Puts(cstr);
}

template<typename TChar, typename TStatus, typename TTaskStatus>
bool Delegate<TChar, TStatus, TTaskStatus>::IsGood() const
{
    return BaseType::IsGood();
}

template<typename TChar, typename TStatus, typename TTaskStatus>
bool Delegate<TChar, TStatus, TTaskStatus>::IsBad() const
{
    return BaseType::IsBad();
}

template<typename TStatus, typename TTaskStatus>
Delegate<char, TStatus, TTaskStatus>::Delegate() :
    BaseType()
{}

template<typename TStatus, typename TTaskStatus>
Delegate<char, TStatus, TTaskStatus>::Delegate(BaseInterfaceType * base_intf, 
    TaskInterfaceType * task) :
        BaseType(base_intf, task)
{}

template<typename TStatus, typename TTaskStatus>
Delegate<char, TStatus, TTaskStatus>::~Delegate()
{}

template<typename TStatus, typename TTaskStatus>
Delegate<char, TStatus, TTaskStatus>::
    Delegate(Delegate<char, TStatus, TTaskStatus>&& mov) :
        BaseType(std::move(mov))
{}

template<typename TStatus, typename TTaskStatus>
typename Delegate<char, TStatus, TTaskStatus>::SizeType 
Delegate<char, TStatus, TTaskStatus>::VPrint(const char * format, 
    va_list var_args)
{
    return GetBuffer().VPrint(format, var_args);
}

template<typename TStatus, typename TTaskStatus>
typename Delegate<char, TStatus, TTaskStatus>::SizeType 
Delegate<char, TStatus, TTaskStatus>::Print(const char * format, ...)
{
    va_list args;
    va_start(args, format);
    const auto ret = GetBuffer().VPrint(format, args);
    va_end(args);
    return ret;
}

template<typename TStatus, typename TTaskStatus>
typename Delegate<char, TStatus, TTaskStatus>::SizeType 
Delegate<char, TStatus, TTaskStatus>::Puts(const char * cstr, 
    const SizeType& size)
{
    return GetBuffer().Puts(cstr, size);
}

template<typename TStatus, typename TTaskStatus>
typename Delegate<char, TStatus, TTaskStatus>::SizeType 
Delegate<char, TStatus, TTaskStatus>::Puts(const char * cstr)
{
    return GetBuffer().Puts(cstr);
}

template<typename TStatus, typename TTaskStatus>
typename Delegate<char, TStatus, TTaskStatus>::SizeType 
Delegate<char, TStatus, TTaskStatus>::Puts(const test::CString<char>& cstr)
{
    return GetBuffer().Puts(cstr);
}

template<typename TStatus, typename TTaskStatus>
typename Delegate<char, TStatus, TTaskStatus>::SizeType 
Delegate<char, TStatus, TTaskStatus>::
    Puts(const test::CString<const char>& cstr)
{
    return GetBuffer().Puts(cstr);
}

template<typename TStatus, typename TTaskStatus>
bool Delegate<char, TStatus, TTaskStatus>::IsGood() const
{
    return BaseType::IsGood();
}

template<typename TStatus, typename TTaskStatus>
bool Delegate<char, TStatus, TTaskStatus>::IsBad() const
{
    return BaseType::IsBad();
}

template<typename TStatus, typename TTaskStatus>
Delegate<wchar_t, TStatus, TTaskStatus>::Delegate() :
    BaseType()
{}

template<typename TStatus, typename TTaskStatus>
Delegate<wchar_t, TStatus, TTaskStatus>::
    Delegate(BaseInterfaceType * base_intf, TaskInterfaceType * task) :
        BaseType(base_intf, task)
{}

template<typename TStatus, typename TTaskStatus>
Delegate<wchar_t, TStatus, TTaskStatus>::~Delegate()
{}

template<typename TStatus, typename TTaskStatus>
Delegate<wchar_t, TStatus, TTaskStatus>::
    Delegate(Delegate<wchar_t, TStatus, TTaskStatus>&& mov) :
        BaseType(std::move(mov))
{}

template<typename TStatus, typename TTaskStatus>
typename Delegate<wchar_t, TStatus, TTaskStatus>::SizeType 
Delegate<wchar_t, TStatus, TTaskStatus>::VPrint(const wchar_t * format, 
    va_list var_args)
{
    return GetBuffer().VPrint(format, var_args);
}

template<typename TStatus, typename TTaskStatus>
typename Delegate<wchar_t, TStatus, TTaskStatus>::SizeType 
Delegate<wchar_t, TStatus, TTaskStatus>::Print(const wchar_t * format, ...)
{
    va_list args;
    va_start(args, format);
    const auto ret = GetBuffer().VPrint(format, args);
    va_end(args);
    return ret;
}

template<typename TStatus, typename TTaskStatus>
typename Delegate<wchar_t, TStatus, TTaskStatus>::SizeType 
Delegate<wchar_t, TStatus, TTaskStatus>::Puts(const wchar_t * cstr, 
    const SizeType& size)
{
    return GetBuffer().Puts(cstr, size);
}

template<typename TStatus, typename TTaskStatus>
typename Delegate<wchar_t, TStatus, TTaskStatus>::SizeType 
Delegate<wchar_t, TStatus, TTaskStatus>::Puts(const wchar_t * cstr)
{
    return GetBuffer().Puts(cstr);
}

template<typename TStatus, typename TTaskStatus>
typename Delegate<wchar_t, TStatus, TTaskStatus>::SizeType 
Delegate<wchar_t, TStatus, TTaskStatus>::
    Puts(const test::CString<wchar_t>& cstr)
{
    return GetBuffer().Puts(cstr);
}

template<typename TStatus, typename TTaskStatus>
typename Delegate<wchar_t, TStatus, TTaskStatus>::SizeType 
Delegate<wchar_t, TStatus, TTaskStatus>::
    Puts(const test::CString<const wchar_t>& cstr)
{
    return GetBuffer().Puts(cstr);
}

template<typename TStatus, typename TTaskStatus>
bool Delegate<wchar_t, TStatus, TTaskStatus>::IsGood() const
{
    return BaseType::IsGood();
}

template<typename TStatus, typename TTaskStatus>
bool Delegate<wchar_t, TStatus, TTaskStatus>::IsBad() const
{
    return BaseType::IsBad();
}

} //!base

} //!out

} //!test

#endif //!TEST_OUT_BASE_DELEGATE_H_
