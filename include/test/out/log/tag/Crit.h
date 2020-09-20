#ifndef TEST_OUT_LOG_TAG_CRIT_H_
#define TEST_OUT_LOG_TAG_CRIT_H_

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
class Crit
{
public:
    typedef typename test::out::log::Tag<TChar>::SizeType SizeType;
    typedef test::out::tag::Crit OutTagType;
};

template<>
class Crit<char> : public test::out::log::Tag<char>
{
public:
    typedef typename test::out::log::Tag<char>::SizeType SizeType;
    typedef test::out::tag::Crit OutTagType;
private:
    static const char (&_Name())[9];
public:
    Crit() = default;
public:
    ~Crit() = default;
public:
    const char * GetName() const override;
    SizeType GetNameSize() const override;
};

template<>
class Crit<wchar_t> : public test::out::log::Tag<wchar_t>
{
public:
    typedef typename test::out::log::Tag<wchar_t>::SizeType SizeType;
    typedef test::out::tag::Crit OutTagType;
private:
    static const wchar_t (&_Name())[9];
public:
    Crit() = default;
public:
    ~Crit() = default;
public:
    const wchar_t * GetName() const override;
    SizeType GetNameSize() const override;
};

inline const char (&Crit<char>::_Name())[9]
{
    static const char name[] = "Critical";
    return name;
}

inline const char * Crit<char>::GetName() const
{
    return _Name();
}

inline typename Crit<char>::SizeType Crit<char>::GetNameSize() const
{
    return sizeof( _Name()) - 1;
}

inline const wchar_t (&Crit<wchar_t>::_Name())[9]
{
    static const wchar_t name[] = L"Critical";
    return name;
}

inline const wchar_t * Crit<wchar_t>::GetName() const
{
    return _Name();
}

inline typename Crit<wchar_t>::SizeType Crit<wchar_t>::GetNameSize() const
{
    return sizeof( _Name()) - 1;
}

} //!tag

namespace make
{

template<typename TChar>
inline test::out::log::tag::Crit<TChar> Tag(const test::out::tag::Crit&)
{
    return {};
}

} //!make

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_TAG_CRIT_H_
