#ifndef TEST_OUT_LOG_TAG_CRIT_H_
#define TEST_OUT_LOG_TAG_CRIT_H_

#include "../Tag.h"

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
public:
    Crit() = default;
public:
    ~Crit() = default;
public:
    inline const char * GetName() const override;
    inline SizeType GetNameSize() const override;
};

inline const char * Crit::GetName() const
{
    return "Critical";
}

inline typename Crit::SizeType Crit::GetNameSize() const
{
    return sizeof("Critical") - 1;
}

} //!tag

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_TAG_CRIT_H_