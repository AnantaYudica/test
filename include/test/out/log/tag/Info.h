#ifndef TEST_OUT_LOG_TAG_INFO_H_
#define TEST_OUT_LOG_TAG_INFO_H_

#include "../../Tag.h"
#include "../Tag.h"
#include "../make/Tag.h"

#include <cwchar>

namespace test
{
namespace out
{
namespace log
{
namespace tag
{

template<typename TChar = char>
class Info
{
public:
    typedef typename test::out::log::Tag<TChar>::SizeType SizeType;
    typedef test::out::tag::Info OutTagType;
};

template<>
class Info<char> : public test::out::log::Tag<char>
{
public:
    typedef typename test::out::log::Tag<char>::SizeType SizeType;
    typedef test::out::tag::Info OutTagType;
private:
    static inline const char (&_Name())[14];
public:
    Info() = default;
public:
    ~Info() = default;
public:
    const char * GetName() const override;
    SizeType GetNameSize() const override;
};

template<>
class Info<wchar_t> : public test::out::log::Tag<wchar_t>
{
public:
    typedef typename test::out::log::Tag<wchar_t>::SizeType SizeType;
    typedef test::out::tag::Info OutTagType;
private:
    static inline const wchar_t (&_Name())[14];
public:
    Info() = default;
public:
    ~Info() = default;
public:
    const wchar_t * GetName() const override;
    SizeType GetNameSize() const override;
};

const char (&Info<char>::_Name())[14]
{
    static const char name[] = "Informational";
    return name;
}

const char * Info<char>::GetName() const
{
    return _Name();
}

typename Info<char>::SizeType Info<char>::GetNameSize() const
{
    return sizeof(_Name()) - 1;
}

const wchar_t (&Info<wchar_t>::_Name())[14]
{
    static const wchar_t name[] = L"Informational";
    return name;
}

const wchar_t * Info<wchar_t>::GetName() const
{
    return _Name();
}

typename Info<wchar_t>::SizeType Info<wchar_t>::GetNameSize() const
{
    return sizeof(_Name()) - 1;
}

} //!tag

namespace make
{

template<typename TChar>
inline test::out::log::tag::Info<TChar> Tag(const test::out::tag::Info&)
{
    return {};
}

} //!make

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_TAG_INFO_H_
