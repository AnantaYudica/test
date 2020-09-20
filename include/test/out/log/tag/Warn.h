#ifndef TEST_OUT_LOG_TAG_WARN_H_
#define TEST_OUT_LOG_TAG_WARN_H_

#include "../../Tag.h"
#include "../Tag.h"
#include "../make/Tag.h"

namespace test
{
namespace out
{
namespace log
{
namespace tag
{

template<typename TChar = char>
class Warn
{
public:
    typedef typename test::out::log::Tag<TChar>::SizeType SizeType;
    typedef test::out::tag::Warn OutTagType;
};

template<>
class Warn<char> : public test::out::log::Tag<char>
{
public:
    typedef typename test::out::log::Tag<char>::SizeType SizeType;
    typedef test::out::tag::Warn OutTagType;
private:
    static const char (&_Name())[8];
public:
    Warn() = default;
public:
    ~Warn() = default;
public:
    const char * GetName() const override;
    SizeType GetNameSize() const override;
};

template<>
class Warn<wchar_t> : public test::out::log::Tag<wchar_t>
{
public:
    typedef typename test::out::log::Tag<wchar_t>::SizeType SizeType;
    typedef test::out::tag::Warn OutTagType;
private:
    static const wchar_t (&_Name())[8];
public:
    Warn() = default;
public:
    ~Warn() = default;
public:
    const wchar_t * GetName() const override;
    SizeType GetNameSize() const override;
};

const char (&Warn<char>::_Name())[8]
{
    static const char name[] = "Warning";
    return name;
}

const char * Warn<char>::GetName() const
{
    return _Name();
}

typename Warn<char>::SizeType Warn<char>::GetNameSize() const
{
    return sizeof(_Name()) - 1;
}

const wchar_t (&Warn<wchar_t>::_Name())[8]
{
    static const wchar_t name[] = L"Warning";
    return name;
}

const wchar_t * Warn<wchar_t>::GetName() const
{
    return _Name();
}

typename Warn<wchar_t>::SizeType Warn<wchar_t>::GetNameSize() const
{
    return sizeof(_Name()) - 1;
}

} //!tag

namespace make
{

template<typename TChar>
inline test::out::log::tag::Warn<TChar> Tag(const test::out::tag::Warn&)
{
    return {};
}

} //!make

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_TAG_WARN_H_
