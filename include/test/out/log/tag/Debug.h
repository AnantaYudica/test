#ifndef TEST_OUT_LOG_TAG_DEBUG_H_
#define TEST_OUT_LOG_TAG_DEBUG_H_

#include "../Tag.h"

namespace test
{
namespace out
{
namespace log
{
namespace tag
{

class Debug : public test::out::log::Tag
{
public:
    typedef typename test::out::log::Tag::SizeType SizeType;
public:
    Debug() = default;
public:
    ~Debug() = default;
public:
    inline const char * GetName() const override;
    inline SizeType GetNameSize() const override;
};

inline const char * Debug::GetName() const
{
    return "Debug";
}

inline typename Debug::SizeType Debug::GetNameSize() const
{
    return sizeof("Debug") - 1;
}

} //!tag

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_TAG_DEBUG_H_