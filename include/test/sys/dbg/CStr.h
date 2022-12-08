#ifndef TEST_SYS_DBG_CSTR_H_
#define TEST_SYS_DBG_CSTR_H_

#include <cstdlib>
#include <cstring>

namespace test
{
namespace sys
{
namespace dbg
{

template<std::size_t N>
class CStr
{
private:
    char m_buff[N + 1];
public:
    CStr();
    CStr(const CStr<N>& cpy);
    CStr(CStr<N>&& mov);
public:
    ~CStr();
public:
    char* Buffer();
    std::size_t BufferSize();
};

template<std::size_t N>
CStr<N>::CStr() :
    m_buff{0}
{
    memset(m_buff, 0, N + 1);
}

template<std::size_t N>
CStr<N>::CStr(const CStr<N>& cpy):
    m_buff{0}
{
    memccpy(m_buff, cpy.m_buff, N);
}

template<std::size_t N>
CStr<N>::CStr(CStr<N>&& mov) :
    m_buff{0}
{
    memccpy(m_buff, mov.m_buff, N);
    memset(mov.m_buff, 0, N);
}

template<std::size_t N>
CStr<N>::~CStr()
{
    memset(m_buff, 0, N);
}

template<std::size_t N>
char* CStr<N>::Buffer()
{
    return m_buff;
}

template<std::size_t N>
std::size_t CStr<N>::BufferSize()
{
    return N;
}

} //!dbg

} //!sys

} //!test

#endif //!TEST_SYS_DBG_CSTR_H_
