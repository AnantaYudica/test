#ifndef TEST_OUT_LOG_TAG_H_
#define TEST_OUT_LOG_TAG_H_

#include "../Tag.h"

#include <cstddef>

namespace test
{
namespace out
{
namespace log
{

class Tag
{
public:
    typedef std::size_t SizeType;
    typedef test::out::tag::Unknown OutTagType;
private:
    static inline const char (&_Name())[8];
public:
    Tag() = default;
public:
    virtual ~Tag() = default;
public:
    virtual inline const char * GetName() const;
    virtual inline SizeType GetNameSize() const;
};

inline const char (&Tag::_Name())[8]
{
    static const char name[] = "Unknown";
    return name;
}

inline const char * Tag::GetName() const
{
    return _Name();
}

inline typename Tag::SizeType Tag::GetNameSize() const
{
    return sizeof(_Name()) - 1;
}

namespace tag
{

typedef test::out::log::Tag Unknown;

} //!tag

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_TAG_H_