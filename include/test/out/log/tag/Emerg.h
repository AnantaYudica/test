#ifndef TEST_OUT_LOG_TAG_EMERG_H_
#define TEST_OUT_LOG_TAG_EMERG_H_

#include "../Tag.h"

namespace test
{
namespace out
{
namespace log
{
namespace tag
{

class Emerg : public test::out::log::Tag
{
public:
    typedef typename test::out::log::Tag::SizeType SizeType;
public:
    Emerg() = default;
public:
    ~Emerg() = default;
public:
    inline const char * GetName() const override;
    inline SizeType GetNameSize() const override;
};

inline const char * Emerg::GetName() const
{
    return "Emergency";
}

inline typename Emerg::SizeType Emerg::GetNameSize() const
{
    return sizeof("Emergency") - 1;
}

} //!tag

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_TAG_EMERG_H_