#ifndef TEST_OUT_LOG_TAG_H_
#define TEST_OUT_LOG_TAG_H_

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
public:
    Tag() = default;
public:
    virtual ~Tag() = default;
public:
    virtual const char * GetName() const = 0;
    virtual SizeType GetNameSize() const = 0;
};

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_TAG_H_