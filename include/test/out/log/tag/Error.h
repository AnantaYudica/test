#ifndef TEST_OUT_LOG_TAG_ERROR_H_
#define TEST_OUT_LOG_TAG_ERROR_H_

#include "../Tag.h"

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
public:
    Error() = default;
public:
    ~Error() = default;
public:
    inline const char * GetName() const override;
    inline SizeType GetNameSize() const override;
};

inline const char * Error::GetName() const
{
    return "Error";
}

inline typename Error::SizeType Error::GetNameSize() const
{
    return sizeof("Error") - 1;
}

} //!tag

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_TAG_ERROR_H_