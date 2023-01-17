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
    static constexpr bool HasSuffix = false;
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
public:
    static inline std::size_t WritePrefixName(char * name_out, std::size_t n)
    {
        return test::sys::Debug::WriteName(name_out, n);
    }
public:
    static inline std::size_t WriteSufixName(char * name_out, std::size_t n)
    {
        return 0;
    }
public:
    static inline std::size_t WriteInfixName(char * name_out, std::size_t n)
    {
        return 0;
    }
};

} //!dbg

} //!sys

} //!test

#endif //!TEST_SYS_DBG_TYPE_H_DEFN_
