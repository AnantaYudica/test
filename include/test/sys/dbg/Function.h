#ifndef TEST_SYS_DBG_FUNCTION_H_
#define TEST_SYS_DBG_FUNCTION_H_

#include "../Debug.defn.h"

#include <cstddef>

namespace test
{
namespace sys
{
namespace dbg
{

template<std::size_t N>
class Function : public test::sys::Debug
{
public:
    typedef typename test::sys::Debug::CStrType CStrType;
private:
    char m_name[N];
    std::size_t m_size;
public:
    inline Function(std::int8_t level, const char (&name)[N]) : 
        test::sys::Debug(level),
        m_name(),
        m_size(N) 
    {
        for(std::size_t i = 0; i < N; ++i)
        {
            m_name[i] = name[i];
        }
    };
public:
    inline virtual ~Function() = default;
public:
    inline Function(const Function&) = delete;
    inline Function(Function&&) = delete;
public:
    inline Function& operator=(const Function&) = delete;
    inline Function& operator=(Function&&) = delete;
public:
    virtual inline std::size_t TagName(char * tag_out, std::size_t n)
    {
        const char* name = m_name;
        const std::size_t name_size = N;
        std::size_t i = 0;
        std::size_t j = 0;
        bool is_bg = false;
        while(i < name_size && j < n)
        {
            if (name[i] == ':')
            {
                if (is_bg)
                {
                    tag_out[j++] = ']';
                    is_bg = false;
                }
                ++i; continue;
            }
            if (!is_bg)
            {
                tag_out[j++] = '[';
                is_bg = true;
                if (j >= n) break;
            }
            tag_out[j++] = name[i++];
        }
        if (j == n)
        {
            return j;
        }
        if (j != 0)
        {
            j -= 1;
        }
        if (is_bg)
        {
            return snprintf(tag_out + j, n - j, "]") + j;
        }
        return j;
    }
public:
    virtual inline std::size_t Name(char * name_out, std::size_t n)
    {
        return snprintf(name_out, n, m_name);
    }
public:
    virtual inline typename test::sys::Debug::CStrType&
        Name(CStrType& cstr)
    {
        Name(cstr.Buffer(), cstr.BufferSize());
        return cstr;
    }
};

} //!dbg

} //!sys

} //!test

#endif //!TEST_SYS_DBG_FUNCTION_H_
