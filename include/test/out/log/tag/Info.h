#ifndef TEST_OUT_LOG_TAG_INFO_H_
#define TEST_OUT_LOG_TAG_INFO_H_

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

class Info : public test::out::log::Tag
{
public:
    typedef typename test::out::log::Tag::SizeType SizeType;
    typedef test::out::tag::Info OutTagType;
private:
    static inline const char (&_Name())[14];
public:
    Info() = default;
public:
    ~Info() = default;
public:
    inline const char * GetName() const override;
    inline SizeType GetNameSize() const override;
};

inline const char (&Info::_Name())[14]
{
    static const char name[] = "Informational";
    return name;
}

inline const char * Info::GetName() const
{
    return _Name();
}

inline typename Info::SizeType Info::GetNameSize() const
{
    return sizeof(_Name()) - 1;
}

} //!tag

namespace make
{

inline test::out::log::tag::Info Tag(const test::out::tag::Info&)
{
    return {};
}

} //!make

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_TAG_INFO_H_