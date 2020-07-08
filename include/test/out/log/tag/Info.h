#ifndef TEST_OUT_LOG_TAG_INFO_H_
#define TEST_OUT_LOG_TAG_INFO_H_

#include "../Tag.h"

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
public:
    Info() = default;
public:
    ~Info() = default;
public:
    inline const char * GetName() const override;
    inline SizeType GetNameSize() const override;
};

inline const char * Info::GetName() const
{
    return "Informational";
}

inline typename Info::SizeType Info::GetNameSize() const
{
    return sizeof("Informational") - 1;
}

} //!tag

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_TAG_INFO_H_