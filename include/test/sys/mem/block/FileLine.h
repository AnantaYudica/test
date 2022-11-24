#ifndef TEST_SYS_MEM_BLOCK_FILELINE_H_
#define TEST_SYS_MEM_BLOCK_FILELINE_H_

#include <cstddef>
#include <utility>
#include <cstdlib>

#define TEST_MEM_BLOCK_FILE_DEFAULT_STR ""

namespace test
{
namespace sys
{
namespace mem
{
namespace block
{

class FileLine
{
private:
    char * m_file;
    int m_line;
protected:
    inline FileLine();
    template<std::size_t N>
    inline FileLine(const char (&f)[N], const int& l);
protected:
    inline FileLine(const FileLine& cpy) = delete;
    inline FileLine(FileLine&& mov);
public:
    inline ~FileLine();
public:
    inline FileLine& operator=(const FileLine& cpy) = delete;
    inline FileLine& operator=(FileLine&& mov);
public:
    inline const char* File() const;
    inline int Line() const;
};

inline FileLine::FileLine() :
    m_file(nullptr),
    m_line(-1)
{}

template<std::size_t N>
inline FileLine::FileLine(const char (&f)[N], const int& l) :
    m_file((char*)std::malloc((N + 1) * sizeof(char))),
    m_line(l)
{
    for (std::size_t i = 0; i < N; ++i)
        m_file[i] = f[i];
    m_file[N] = 0;
}

inline FileLine::FileLine(FileLine&& mov) :
    m_file(std::move(mov.m_file)),
    m_line(std::move(mov.m_line))
{
    mov.m_file = nullptr;
    mov.m_line = -1;
}

inline FileLine::~FileLine()
{
    if (m_file != nullptr)
    {
        free(m_file);
    }
    m_file = nullptr;
}

inline FileLine& FileLine::operator=(FileLine&& mov)
{
    if (m_file != nullptr)
    {
        free(m_file);
    }
    m_file = mov.m_file,
    mov.m_file = nullptr;
    m_line = mov.m_line;
    mov.m_line = -1;
    return *this;
}

inline const char* FileLine::File() const
{
    const char * tmp = TEST_MEM_BLOCK_FILE_DEFAULT_STR;
    if(m_file == nullptr) return tmp;
    return m_file;
}

inline int FileLine::Line() const
{
    return m_line;
}

} //!block

} //!mem

} //!sys

} //!test

#endif //!TEST_SYS_MEM_BLOCK_FILELINE_H_
