#ifndef TEST_SYS_MEM_BLOCK_FILELINE_H_
#define TEST_SYS_MEM_BLOCK_FILELINE_H_

#include "../../Definition.h"
#include "../../Interface.h"
#include "../../Debug.h"

#include <cstddef>
#include <utility>
#include <cstdlib>

#define TEST_MEM_BLOCK_FILE_DEFAULT_STR ""

#ifndef TEST_SYS_MEM_BLOCK_FILELINE_DLEVEL

#define TEST_SYS_MEM_BLOCK_FILELINE_DLEVEL 2

#endif //!TEST_SYS_MEM_BLOCK_FILELINE_DLEVEL

namespace test::sys::mem::block
{
class FileLine;
}

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_SYS_MEM_BLOCK_FILELINE_DLEVEL, 
    "test::sys::mem::block::FileLine", test::sys::mem::block::FileLine);

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
    typedef test::sys::Definition DefinitionType;
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::mem::block::FileLine> DebugType;
private:
    char * m_file;
    int m_line;
    std::size_t m_fileAllocSize;
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
public:
    inline std::size_t FileAllocationSize() const;
};

inline FileLine::FileLine() :
    m_file(nullptr),
    m_line(-1),
    m_fileAllocSize(0)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");
}

template<std::size_t N>
inline FileLine::FileLine(const char (&f)[N], 
    const int& l) :
        m_file((char*)std::malloc((N + 1) * sizeof(char))),
        m_line(l),
        m_fileAllocSize((N + 1) * sizeof(char))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Constructor(f=%s, l=%d)",
        f, l);

    if (m_file != nullptr)
    {
        for (std::size_t i = 0; i < N; ++i)
            m_file[i] = f[i];
        m_file[N] = 0;
    }
    else
    {
        m_fileAllocSize = 0;
        SystemType::GetInstance().Error(
            DefinitionType::Status::sMemBlockAllocationFailed, 
            "Memory allocation is failed");
    }
}

inline FileLine::FileLine(FileLine&& mov) :
    m_file(std::move(mov.m_file)),
    m_line(std::move(mov.m_line)),
    m_fileAllocSize(std::move(mov.m_fileAllocSize))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Move Constructor(%p)",
        &mov);

    mov.m_file = nullptr;
    mov.m_line = -1;
    mov.m_fileAllocSize = 0;
}

inline FileLine::~FileLine()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

    if (m_file != nullptr)
    {
        free(m_file);
    }
    m_file = nullptr;
    m_fileAllocSize = 0;
}

inline FileLine& FileLine::operator=(FileLine&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(%p)", &mov);

    if (m_file != nullptr)
    {
        free(m_file);
    }
    m_file = mov.m_file,
    mov.m_file = nullptr;
    m_line = mov.m_line;
    mov.m_line = -1;
    m_fileAllocSize = mov.m_fileAllocSize;
    mov.m_fileAllocSize = 0;
    return *this;
}

inline const char* FileLine::File() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "File()");

    const char * tmp = TEST_MEM_BLOCK_FILE_DEFAULT_STR;
    if(m_file == nullptr) return tmp;
    return m_file;
}

inline int FileLine::Line() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Line()");

    return m_line;
}

inline std::size_t FileLine::FileAllocationSize() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "FileAllocationSize()");

    return m_fileAllocSize;
}

} //!block

} //!mem

} //!sys

} //!test

#endif //!TEST_SYS_MEM_BLOCK_FILELINE_H_
