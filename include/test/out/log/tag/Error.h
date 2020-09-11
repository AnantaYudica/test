#ifndef TEST_OUT_LOG_TAG_ERROR_H_
#define TEST_OUT_LOG_TAG_ERROR_H_

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

class Error : public test::out::log::Tag
{
public:
    typedef typename test::out::log::Tag::SizeType SizeType;
    typedef test::out::tag::Error OutTagType;
private:
    static inline const char (&_Name())[6];
public:
    Error() = default;
public:
    ~Error() = default;
public:
    inline const char * GetName() const override;
    inline SizeType GetNameSize() const override;
};

inline const char (&Error::_Name())[6]
{
    static const char name[] = "Error";
    return name;
}

inline const char * Error::GetName() const
{
    return _Name();
}

inline typename Error::SizeType Error::GetNameSize() const
{
    return sizeof(_Name()) - 1;
}

} //!tag

namespace make
{

inline test::out::log::tag::Error Tag(const test::out::tag::Error&)
{
    return {};
}

} //!make

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_TAG_ERROR_H_
