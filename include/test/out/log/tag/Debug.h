#ifndef TEST_OUT_LOG_TAG_DEBUG_H_
#define TEST_OUT_LOG_TAG_DEBUG_H_

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

class Debug : public test::out::log::Tag
{
public:
    typedef typename test::out::log::Tag::SizeType SizeType;
    typedef test::out::tag::Debug OutTagType;
private:
    static inline const char (&_Name())[6];
public:
    Debug() = default;
public:
    ~Debug() = default;
public:
    inline const char * GetName() const override;
    inline SizeType GetNameSize() const override;
};

inline const char (&Debug::_Name())[6]
{
    static const char name[] = "Debug";
    return name;
}

inline const char * Debug::GetName() const
{
    return _Name();
}

inline typename Debug::SizeType Debug::GetNameSize() const
{
    return sizeof(_Name()) - 1;
}

} //!tag

namespace make
{

inline test::out::log::tag::Debug Tag(const test::out::tag::Debug&)
{
    return {};
}

} //!make

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_TAG_DEBUG_H_