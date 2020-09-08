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

class Warn : public test::out::log::Tag
{
public:
    typedef typename test::out::log::Tag::SizeType SizeType;
    typedef test::out::tag::Warn OutTagType;
private:
    static inline const char (&_Name())[8];
public:
    Warn() = default;
public:
    ~Warn() = default;
public:
    inline const char * GetName() const override;
    inline SizeType GetNameSize() const override;
};

inline const char (&Warn::_Name())[8]
{
    static const char name[] = "Warning";
    return name;
}

inline const char * Warn::GetName() const
{
    return _Name();
}

inline typename Warn::SizeType Warn::GetNameSize() const
{
    return sizeof(_Name()) - 1;
}

} //!tag

namespace make
{

inline test::out::log::tag::Warn Tag(const test::out::tag::Warn&)
{
    return {};
}

} //!make

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_TAG_WARN_H_