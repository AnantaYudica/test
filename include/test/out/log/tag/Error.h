#ifndef TEST_OUT_LOG_TAG_ERROR_H_
#define TEST_OUT_LOG_TAG_ERROR_H_

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
class Error : public test::out::log::Tag<TChar>
{
public:
    typedef typename test::out::log::Tag<TChar>::SizeType SizeType;
    typedef test::out::tag::Error OutTagType;
private:
    static const char (&_Name())[6];
public:
    Error() = default;
public:
    ~Error() = default;
public:
    const char * GetName() const override;
    SizeType GetNameSize() const override;
};

template<>
class Error<char> : public test::out::log::Tag<char>
{
public:
    typedef typename test::out::log::Tag<char>::SizeType SizeType;
    typedef test::out::tag::Error OutTagType;
private:
    static const char (&_Name())[6];
public:
    Error() = default;
public:
    ~Error() = default;
public:
    const char * GetName() const override;
    SizeType GetNameSize() const override;
};

template<>
class Error<wchar_t> : public test::out::log::Tag<wchar_t>
{
public:
    typedef typename test::out::log::Tag<wchar_t>::SizeType SizeType;
    typedef test::out::tag::Error OutTagType;
private:
    static const wchar_t (&_Name())[6];
public:
    Error() = default;
public:
    ~Error() = default;
public:
    const wchar_t * GetName() const override;
    SizeType GetNameSize() const override;
};

const char (&Error<char>::_Name())[6]
{
    static const char name[] = "Error";
    return name;
}

const char * Error<char>::GetName() const
{
    return _Name();
}

typename Error<char>::SizeType Error<char>::GetNameSize() const
{
    return sizeof(_Name()) - 1;
}

const wchar_t (&Error<wchar_t>::_Name())[6]
{
    static const wchar_t name[] = L"Error";
    return name;
}

const wchar_t * Error<wchar_t>::GetName() const
{
    return _Name();
}

typename Error<wchar_t>::SizeType Error<wchar_t>::GetNameSize() const
{
    return sizeof(_Name()) - 1;
}

} //!tag

namespace make
{

template<typename TChar>
inline test::out::log::tag::Error<TChar> Tag(const test::out::tag::Error&)
{
    return {};
}

} //!make

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_TAG_ERROR_H_
