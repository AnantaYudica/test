#ifndef TEST_OUT_LOG_TAG_CRIT_H_
#define TEST_OUT_LOG_TAG_CRIT_H_

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

class Crit : public test::out::log::Tag
{
public:
    typedef typename test::out::log::Tag::SizeType SizeType;
    typedef test::out::tag::Crit OutTagType;
private:
    static inline const char (&_Name())[9];
public:
    Crit() = default;
public:
    ~Crit() = default;
public:
    inline const char * GetName() const override;
    inline SizeType GetNameSize() const override;
};

inline const char (&Crit::_Name())[9]
{
    static const char name[] = "Critical";
    return name;
}

inline const char * Crit::GetName() const
{
    return _Name();
}

inline typename Crit::SizeType Crit::GetNameSize() const
{
    return sizeof( _Name()) - 1;
}

} //!tag

namespace make
{

inline test::out::log::tag::Crit Tag(const test::out::tag::Crit&)
{
    return {};
}

} //!make

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_TAG_CRIT_H_
