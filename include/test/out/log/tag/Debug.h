#ifndef TEST_OUT_LOG_TAG_DEBUG_H_
#define TEST_OUT_LOG_TAG_DEBUG_H_

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
class Debug
{
public:
    typedef typename test::out::log::Tag<TChar>::SizeType SizeType;
    typedef test::out::tag::Debug OutTagType;
};

template<>
class Debug<char> : public test::out::log::Tag<char>
{
public:
    typedef typename test::out::log::Tag<char>::SizeType SizeType;
    typedef test::out::tag::Debug OutTagType;
private:
    static const char (&_Name())[6];
public:
    Debug() = default;
public:
    ~Debug() = default;
public:
    const char * GetName() const override;
    SizeType GetNameSize() const override;
};

template<>
class Debug<wchar_t> : public test::out::log::Tag<wchar_t>
{
public:
    typedef typename test::out::log::Tag<wchar_t>::SizeType SizeType;
    typedef test::out::tag::Debug OutTagType;
private:
    static const wchar_t (&_Name())[6];
public:
    Debug() = default;
public:
    ~Debug() = default;
public:
    const wchar_t * GetName() const override;
    SizeType GetNameSize() const override;
};

const char (&Debug<char>::_Name())[6]
{
    static const char name[] = "Debug";
    return name;
}

const char * Debug<char>::GetName() const
{
    return _Name();
}

inline typename Debug<char>::SizeType Debug<char>::GetNameSize() const
{
    return sizeof(_Name()) - 1;
}

const wchar_t (&Debug<wchar_t>::_Name())[6]
{
    static const wchar_t name[] = L"Debug";
    return name;
}

const wchar_t * Debug<wchar_t>::GetName() const
{
    return _Name();
}

inline typename Debug<wchar_t>::SizeType Debug<wchar_t>::GetNameSize() const
{
    return sizeof(_Name()) - 1;
}

} //!tag

namespace make
{

template<typename TChar>
inline test::out::log::tag::Debug<TChar> Tag(const test::out::tag::Debug&)
{
    return {};
}

} //!make

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_TAG_DEBUG_H_
