#ifndef TEST_OUT_CSTRING_H_
#define TEST_OUT_CSTRING_H_

#include "../CString.h"
#include "../cstr/Length.h"
#include "cstr/Status.h"
#include "Interface.h"
#include "Standard.h"
#include "cstr/Base.h"

#include <cstddef>
#include <type_traits>
#include <cstring>
#include <utility>
#include <cstdarg>

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

template<typename TChar = char>
class CString : 
    private test::out::cstr::Base<TChar>,
    public test::out::Interface<TChar>
{
private:
    typedef test::out::cstr::Base<TChar> BaseType;
public:
    typedef typename BaseType::CharType CharType;
    typedef typename BaseType::SizeType SizeType; 
    typedef typename BaseType::StatusType StatusType;
public:
    CString();
    CString(const SizeType & minimum_capacity);
    CString(const SizeType & minimum_capacity, 
        const SizeType & maximum_capacity);
public:
    ~CString();
public:
    CString(const CString<TChar>& cpy);
    CString(CString<TChar>&& mov);
public:
    CString<TChar>& operator=(const CString<TChar>& cpy);
    CString<TChar>& operator=(CString<TChar>&& mov);
public:
    using BaseType::Size;
    using BaseType::Capacity;
    using BaseType::MaximumCapacity;
    using BaseType::MinimumCapacity;
private:
    using BaseType::_Set;
public:
    SizeType Puts(const TChar * cstr, const SizeType& size) override;
    SizeType Puts(const TChar * cstr) override;
    template<std::size_t S>
    SizeType Puts(const TChar(&cstr)[S]);
    SizeType Puts(const test::CString<TChar>& cstr) override;
    SizeType Puts(const test::CString<const TChar>& cstr) override;
    SizeType Puts(const CString<TChar>& cpy);
public:
    using BaseType::Get;
public:
    bool IsBad() const override;
    bool IsGood() const override;
public:
    using BaseType::GetBadCode;
private:
    using BaseType::Bad;
public:
    using BaseType::Output;
};

template<>
class CString<char> : 
    private test::out::cstr::Base<char>,
    public test::out::Interface<char>
{
private:
    typedef test::out::cstr::Base<char> BaseType;
public:
    typedef typename BaseType::CharType CharType;
    typedef typename BaseType::SizeType SizeType; 
    typedef typename BaseType::StatusType StatusType;
public:
    CString();
    CString(const SizeType & minimum_capacity);
    CString(const SizeType & minimum_capacity, 
        const SizeType & maximum_capacity);
public:
    ~CString();
public:
    CString(const CString<char>& cpy);
    CString(CString<char>&& mov);
public:
    CString<char>& operator=(const CString<char>& cpy);
    CString<char>& operator=(CString<char>&& mov);
public:
    using BaseType::Size;
    using BaseType::Capacity;
    using BaseType::MaximumCapacity;
    using BaseType::MinimumCapacity;
private:
    using BaseType::_Set;
    SizeType _Set(const SizeType& index, const char * format, 
        va_list var_args) TEST_ATTRIBUTE ((__format__ (__printf__, 3, 0)));
public:
    SizeType VPrint(const char * format, va_list var_args) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));
    SizeType Print(const char * format, ...) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 3)));
public:
    SizeType Puts(const char * cstr, const SizeType& size) override;
    SizeType Puts(const char * cstr) override;
    template<std::size_t S>
    SizeType Puts(const char(&cstr)[S]);
    SizeType Puts(const test::CString<char>& cstr) override;
    SizeType Puts(const test::CString<const char>& cstr) override;
    SizeType Puts(const CString<char>& cpy);
public:
    using BaseType::Get;
public:
    bool IsBad() const override;
    bool IsGood() const override;
public:
    using BaseType::GetBadCode;
private:
    using BaseType::Bad;
public:
    using BaseType::Output;
};

template<>
class CString<wchar_t> : 
    private test::out::cstr::Base<wchar_t>,
    public test::out::Interface<wchar_t>
{
private:
    typedef test::out::cstr::Base<wchar_t> BaseType;
public:
    typedef typename BaseType::CharType CharType;
    typedef typename BaseType::SizeType SizeType; 
    typedef typename BaseType::StatusType StatusType;
public:
    CString();
    CString(const SizeType & minimum_capacity);
    CString(const SizeType & minimum_capacity, 
        const SizeType & maximum_capacity);
public:
    ~CString();
public:
    CString(const CString<wchar_t>& cpy);
    CString(CString<wchar_t>&& mov);
public:
    CString<wchar_t>& operator=(const CString<wchar_t>& cpy);
    CString<wchar_t>& operator=(CString<wchar_t>&& mov);
public:
    using BaseType::Size;
    using BaseType::Capacity;
    using BaseType::MaximumCapacity;
    using BaseType::MinimumCapacity;
private:
    using Base::_Set;
    SizeType _Set(const SizeType& index, const wchar_t * format, 
        va_list var_args);
public:
    SizeType VPrint(const wchar_t * format, va_list var_args) override;
    SizeType Print(const wchar_t * format, ...) override;
public:
    SizeType Puts(const wchar_t * cstr, const SizeType& size) override;
    SizeType Puts(const wchar_t * cstr) override;
    template<std::size_t S>
    SizeType Puts(const wchar_t(&cstr)[S]);
    SizeType Puts(const test::CString<wchar_t>& cstr) override;
    SizeType Puts(const test::CString<const wchar_t>& cstr) override;
    SizeType Puts(const CString<wchar_t>& cpy);
public:
    using BaseType::Get;
public:
    bool IsBad() const override;
    bool IsGood() const override;
public:
    using BaseType::GetBadCode;
private:
    using BaseType::Bad;
public:
    using BaseType::Output;
};

template<typename TChar>
CString<TChar>::CString() :
    BaseType()
{}

template<typename TChar>
CString<TChar>::CString(const SizeType & minimum_capacity)  :
    BaseType(minimum_capacity)
{}

template<typename TChar>
CString<TChar>::CString(const SizeType & minimum_capacity, 
    const SizeType & maximum_capacity) :
        BaseType(minimum_capacity, maximum_capacity)
{}

template<typename TChar>
CString<TChar>::~CString()
{}

template<typename TChar>
CString<TChar>::CString(const CString<TChar>& cpy) :
    BaseType(cpy),
    test::out::Interface<TChar>()
{}

template<typename TChar>
CString<TChar>::CString(CString<TChar>&& mov) :
    BaseType(std::move(mov)),
    test::out::Interface<TChar>()
{}

template<typename TChar>
CString<TChar>& CString<TChar>::operator=(const CString<TChar>& cpy)
{
    BaseType::operator=(cpy);
    return *this;
}

template<typename TChar>
CString<TChar>& CString<TChar>::operator=(CString<TChar>&& mov)
{   
    BaseType::operator=(std::move(mov));
    return *this;
}

template<typename TChar>
typename CString<TChar>::SizeType  
CString<TChar>::Puts(const TChar * cstr, const SizeType& size)
{
    if (IsBad()) return 0;
    if (cstr == nullptr || size == static_cast<SizeType>(0)) return 0;
    return _Set(Size(), cstr, size);
}

template<typename TChar>
typename CString<TChar>::SizeType  
CString<TChar>::Puts(const TChar * cstr)
{
    if (IsBad()) return 0;
    if (cstr == nullptr) return 0;
    const SizeType size = test::cstr::Length<TChar>::Value(cstr, 
        MaximumCapacity() - 1);
    if (size == 0) return 0;
    return _Set(Size(), cstr, size);
}

template<typename TChar>
template<std::size_t S>
typename CString<TChar>::SizeType  
CString<TChar>::Puts(const TChar(&cstr)[S])
{
    if (IsBad()) return 0;
    return _Set(Size(), cstr, S);
}

template<typename TChar>
typename CString<TChar>::SizeType  
CString<TChar>::Puts(const test::CString<TChar>& cstr)
{
    if (IsBad()) return 0;
    return _Set(Size(), *cstr, cstr.Size());
}

template<typename TChar>
typename CString<TChar>::SizeType  
CString<TChar>::Puts(const test::CString<const TChar>& cstr)
{
    if (IsBad()) return 0;
    return _Set(Size(), *cstr, cstr.Size());
}

template<typename TChar>
typename CString<TChar>::SizeType  
CString<TChar>::Puts(const CString<TChar>& cstr)
{
    if (IsBad()) return 0;
    return _Set(Size(), cstr.GetCStr(), cstr.Size());
}

template<typename TChar>
bool CString<TChar>::IsGood() const
{
    return BaseType::IsGood();
}

template<typename TChar>
bool CString<TChar>::IsBad() const
{
    return BaseType::IsBad();
}

CString<char>::CString()  :
    BaseType()
{}

CString<char>::CString(const SizeType & minimum_capacity)  :
    BaseType(minimum_capacity)
{}

CString<char>::CString(const SizeType & minimum_capacity, 
    const SizeType & maximum_capacity) :
        BaseType(minimum_capacity, maximum_capacity)
{}

CString<char>::~CString()
{}

CString<char>::CString(const CString<char>& cpy) :
    BaseType(cpy),
    test::out::Interface<char>()
{}

CString<char>::CString(CString<char>&& mov) :
    BaseType(std::move(mov)),
    test::out::Interface<char>()
{}

CString<char>& CString<char>::operator=(const CString<char>& cpy)
{
    BaseType::operator=(cpy);
    return *this;
}

CString<char>& CString<char>::operator=(CString<char>&& mov)
{   
    BaseType::operator=(std::move(mov));
    return *this;
}

typename CString<char>::SizeType 
CString<char>::_Set(const SizeType& index, const char * format, 
    va_list var_args)
{
    char * buffer = new char[MinimumCapacity()];
    
    int print_size = test::out::VSPrint<char>(buffer, MinimumCapacity(),
        format, var_args);
    
    if (print_size < 0) 
    {
        Bad(StatusType::print_buffer_failed);
        return 0;
    }

    if ((SizeType)print_size >= MinimumCapacity())
    {
        delete[] buffer;
        buffer = new char[print_size + 1];
        auto print_res = test::out::VSPrint<char>(buffer, print_size + 1, 
            format, var_args);
        if (print_res < 0) 
        {
            Bad(StatusType::print_buffer_failed);
            return 0;
        }
    }

    const auto res = _Set(index, buffer, print_size);

    delete[] buffer;
    return res;
}

typename CString<char>::SizeType 
CString<char>::VPrint(const char * format, va_list var_args)
{
    if (IsBad()) return 0;
    return _Set(Size(), format, var_args);
}

typename CString<char>::SizeType 
CString<char>::Print(const char * format, ...)
{
    if (IsBad()) return 0;
    va_list args;
    va_start(args, format);
    const auto res = _Set(Size(), format, args);
    va_end(args);
    return res;
}

typename CString<char>::SizeType  
CString<char>::Puts(const char * cstr, const SizeType& size)
{
    if (IsBad()) return 0;
    if (cstr == nullptr || size == static_cast<SizeType>(0)) return 0;
    return _Set(Size(), cstr, size);
}

typename CString<char>::SizeType  
CString<char>::Puts(const char * cstr)
{
    if (IsBad()) return 0;
    if (cstr == nullptr) return 0;
    const SizeType size = test::cstr::Length<char>::Value(cstr, 
        MaximumCapacity() - 1);
    if (size == 0) return 0;
    return _Set(Size(), cstr, size);
}

template<std::size_t S>
typename CString<char>::SizeType  
CString<char>::Puts(const char(&cstr)[S])
{
    if (IsBad()) return 0;
    return _Set(Size(), cstr, S);
}

typename CString<char>::SizeType  
CString<char>::Puts(const test::CString<char>& cstr)
{
    if (IsBad()) return 0;
    return _Set(Size(), *cstr, cstr.Size());
}

typename CString<char>::SizeType  
CString<char>::Puts(const test::CString<const char>& cstr)
{
    if (IsBad()) return 0;
    return _Set(Size(), *cstr, cstr.Size());
}

typename CString<char>::SizeType  
CString<char>::Puts(const CString<char>& cstr)
{
    if (IsBad()) return 0;
    return _Set(Size(), cstr.GetCStr(), cstr.Size());
}

bool CString<char>::IsGood() const
{
    return BaseType::IsGood();
}

bool CString<char>::IsBad() const
{
    return BaseType::IsBad();
}

CString<wchar_t>::CString() :
    BaseType()
{}

CString<wchar_t>::CString(const SizeType & minimum_capacity)  :
    BaseType(minimum_capacity)
{}

CString<wchar_t>::CString(const SizeType & minimum_capacity, 
    const SizeType & maximum_capacity) :
        BaseType(minimum_capacity, maximum_capacity)
{}

CString<wchar_t>::~CString()
{}

CString<wchar_t>::CString(const CString<wchar_t>& cpy) :
    BaseType(cpy),
    test::out::Interface<wchar_t>()
{}

CString<wchar_t>::CString(CString<wchar_t>&& mov) :
    BaseType(std::move(mov)),
    test::out::Interface<wchar_t>()
{}

CString<wchar_t>& CString<wchar_t>::operator=(const CString<wchar_t>& cpy)
{
    BaseType::operator=(cpy);
    return *this;
}

CString<wchar_t>& CString<wchar_t>::operator=(CString<wchar_t>&& mov)
{   
    BaseType::operator=(std::move(mov));
    return *this;
}

typename CString<wchar_t>::SizeType 
CString<wchar_t>::_Set(const SizeType& index, const wchar_t * format, 
    va_list var_args)
{
    wchar_t * buffer = new wchar_t[MinimumCapacity()];
    
    int print_size = test::out::VSPrint<wchar_t>(buffer, MinimumCapacity(),
        format, var_args);
    
    if (print_size < 0) 
    {
        Bad(StatusType::print_buffer_failed);
        return 0;
    }

    if ((SizeType)print_size >= MinimumCapacity())
    {
        delete[] buffer;
        buffer = new wchar_t[print_size + 1];
        auto print_res = test::out::VSPrint<wchar_t>(buffer, print_size + 1, 
            format, var_args);
        if (print_res < 0) 
        {
            Bad(StatusType::print_buffer_failed);
            return 0;
        }
    }

    const auto res = _Set(index, buffer, print_size);

    delete[] buffer;
    return res;
}

typename CString<wchar_t>::SizeType 
CString<wchar_t>::VPrint(const wchar_t * format, va_list var_args)
{
    if (IsBad()) return 0;
    return _Set(Size(), format, var_args);
}

typename CString<wchar_t>::SizeType 
CString<wchar_t>::Print(const wchar_t * format, ...)
{
    if (IsBad()) return 0;
    va_list args;
    va_start(args, format);
    const auto res = _Set(Size(), format, args);
    va_end(args);
    return res;
}

typename CString<wchar_t>::SizeType  
CString<wchar_t>::Puts(const wchar_t * cstr, const SizeType& size)
{
    if (IsBad()) return 0;
    if (cstr == nullptr || size == static_cast<SizeType>(0)) return 0;
    return _Set(Size(), cstr, size);
}

typename CString<wchar_t>::SizeType  
CString<wchar_t>::Puts(const wchar_t * cstr)
{
    if (IsBad()) return 0;
    if (cstr == nullptr) return 0;
    const SizeType size = test::cstr::Length<wchar_t>::Value(cstr, 
        MaximumCapacity() - 1);
    if (size == 0) return 0;
    return _Set(Size(), cstr, size);
}

template<std::size_t S>
typename CString<wchar_t>::SizeType  
CString<wchar_t>::Puts(const wchar_t(&cstr)[S])
{
    if (IsBad()) return 0;
    return _Set(Size(), cstr, S);
}

typename CString<wchar_t>::SizeType  
CString<wchar_t>::Puts(const test::CString<wchar_t>& cstr)
{
    if (IsBad()) return 0;
    return _Set(Size(), *cstr, cstr.Size());
}

typename CString<wchar_t>::SizeType  
CString<wchar_t>::Puts(const test::CString<const wchar_t>& cstr)
{
    if (IsBad()) return 0;
    return _Set(Size(), *cstr, cstr.Size());
}

typename CString<wchar_t>::SizeType  
CString<wchar_t>::Puts(const CString<wchar_t>& cstr)
{
    if (IsBad()) return 0;
    return _Set(Size(), cstr.GetCStr(), cstr.Size());
}

bool CString<wchar_t>::IsGood() const
{
    return BaseType::IsGood();
}

bool CString<wchar_t>::IsBad() const
{
    return BaseType::IsBad();
}

} //!out

} //!test

#endif //!TEST_OUT_CSTRING_H_
