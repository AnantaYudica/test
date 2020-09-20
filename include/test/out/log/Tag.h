#ifndef TEST_OUT_LOG_TAG_H_
#define TEST_OUT_LOG_TAG_H_

#include "../Tag.h"

#include <cstddef>
#include <cwchar>

namespace test
{
namespace out
{
namespace log
{

template<typename TChar = char>
class Tag
{
public:
    typedef std::size_t SizeType;
    typedef test::out::tag::Unknown OutTagType;
};

template<>
class Tag<char>
{
public:
    typedef std::size_t SizeType;
    typedef test::out::tag::Unknown OutTagType;
private:
    static const char (&_Name())[8];
public:
    Tag() = default;
public:
    virtual ~Tag() = default;
public:
    virtual const char * GetName() const;
    virtual SizeType GetNameSize() const;
};

template<>
class Tag<wchar_t>
{
public:
    typedef std::size_t SizeType;
    typedef test::out::tag::Unknown OutTagType;
private:
    static const wchar_t (&_Name())[8];
public:
    Tag() = default;
public:
    virtual ~Tag() = default;
public:
    virtual const wchar_t * GetName() const;
    virtual SizeType GetNameSize() const;
};

const char (&Tag<char>::_Name())[8]
{
    static const char name[] = "Unknown";
    return name;
}

const char * Tag<char>::GetName() const
{
    return _Name();
}

typename Tag<char>::SizeType Tag<char>::GetNameSize() const
{
    return sizeof(_Name()) - 1;
}

const wchar_t (&Tag<wchar_t>::_Name())[8]
{
    static const wchar_t name[] = L"Unknown";
    return name;
}

const wchar_t * Tag<wchar_t>::GetName() const
{
    return _Name();
}

typename Tag<char>::SizeType Tag<wchar_t>::GetNameSize() const
{
    return sizeof(_Name()) - 1;
}

namespace tag
{

template<typename TChar>
using Unknown = test::out::log::Tag<TChar>;

} //!tag

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_TAG_H_
