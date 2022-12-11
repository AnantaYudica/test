#ifndef TEST_SYS_DBG_TYPE_H_DEFN_
#define TEST_SYS_DBG_TYPE_H_DEFN_

#include "../Debug.defn.h"

namespace test
{
namespace sys
{
namespace dbg
{

template<typename T>
class Type : public test::sys::Debug
{
public:
    typedef typename test::sys::Debug::CStrType CStrType;
public:
    inline static test::sys::Debug& GetInstance()
    {
        static Type<T> instance;
        return instance;
    }
protected:
    inline Type() = default;
public:
    inline virtual ~Type() = default;
};

} //!dbg

} //!sys

} //!test

#endif //!TEST_SYS_DBG_TYPE_H_DEFN_