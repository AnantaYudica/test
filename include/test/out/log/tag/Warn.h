#ifndef TEST_OUT_LOG_TAG_WARN_H_
#define TEST_OUT_LOG_TAG_WARN_H_

#include "../Tag.h"

namespace test
{
namespace out
{
namespace log
{
namespace tag
{

class Warn : public test::out::log::Tag
{
public:
    typedef typename test::out::log::Tag::SizeType SizeType;
public:
    Warn() = default;
public:
    ~Warn() = default;
public:
    inline const char * GetName() const override;
    inline SizeType GetNameSize() const override;
};

inline const char * Warn::GetName() const
{
    return "Warning";
}

inline typename Warn::SizeType Warn::GetNameSize() const
{
    return sizeof("Warning") - 1;
}

} //!tag

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_TAG_WARN_H_