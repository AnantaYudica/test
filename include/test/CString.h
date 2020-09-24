#ifndef TEST_CSTRING_H_
#define TEST_CSTRING_H_

#include <cstddef>
#include <cstring>

namespace test
{

template<typename TChar>
class CString
{
public:
    typedef TChar CharType;
    typedef std::size_t SizeType;
private:
    TChar* m_cstr;
    std::size_t m_size;
public:
    CString();
    template<std::size_t S>
    CString(const TChar(&cstr)[S]);
    CString(TChar*&& cstr, const std::size_t& size);
    CString(const TChar* cstr, const std::size_t& size);
    CString(const CString<TChar>& cpy);
    CString(const CString<const TChar>& cpy);
    CString(CString<TChar>&& mov);
    CString(CString<const TChar>&& mov);
    ~CString();
public:
    CString<TChar>& operator=(const CString<const TChar>& cpy);
    template<std::size_t S>
    CString<TChar>& operator=(const TChar(&cstr)[S]);
    CString<TChar>& operator=(const CString<TChar>& cpy);
    CString<TChar>& operator=(CString<TChar>&& mov);
    CString<TChar>& operator=(CString<const TChar>&& mov);
public:
    TChar& operator[](const std::size_t& index);
    const TChar& operator[](const std::size_t& index) const;
    const TChar* operator*() const;
    const std::size_t& Size() const;
public:
    TChar*& Get();
    const TChar*& Get() const;
};

template<typename TChar>
class CString<const TChar>
{
public:
    typedef TChar CharType;
    typedef std::size_t SizeType;
private:
    const TChar* m_cstr;
    std::size_t m_size;
public:
    template<std::size_t S>
    CString(const TChar(&cstr)[S]);
    CString(const TChar* cstr, const std::size_t& size);
    CString(const CString<TChar>& cpy);
    CString(const CString<const TChar>& cpy);
    CString(CString<const TChar>&& mov);
public:
    CString<TChar>& operator=(const CString<const TChar>& cpy) = delete;
    CString<TChar>& operator=(CString<const TChar>&& mov) = delete;
public:
    const TChar& operator[](const std::size_t& index) const;
    const TChar* operator*() const;
    const std::size_t& Size() const;
public:
    const TChar*& Get() const;
};

template<typename TChar>
CString<TChar>::CString() :
    m_cstr(nullptr),
    m_size(0)
{}

template<typename TChar>
template<std::size_t S>
CString<TChar>::CString(const TChar(&cstr)[S]) :
    m_cstr(new TChar[S]),
    m_size(S - 1)
{
    memcpy(m_cstr, cstr, S * sizeof(TChar));
}

template<typename TChar>
CString<TChar>::CString(TChar*&& cstr, const std::size_t& size) :
    m_cstr(cstr),
    m_size(size)
{
    cstr = nullptr;
}

template<typename TChar>
CString<TChar>::CString(const TChar* cstr, const std::size_t& size) :
    m_cstr(new TChar[size + 1]),
    m_size(size)
{
    memcpy(m_cstr, cstr, size * sizeof(TChar));
    memset(m_cstr + size, 0, sizeof(TChar));
}

template<typename TChar>
CString<TChar>::CString(const CString<TChar>& cpy) :
    m_cstr(new TChar[cpy.m_size + 1]),
    m_size(cpy.m_size)
{
    memcpy(m_cstr, cpy.m_cstr, cpy.m_size * sizeof(TChar));
    memset(m_cstr + m_size, 0, sizeof(TChar));
}

template<typename TChar>
CString<TChar>::CString(const CString<const TChar>& cpy) :
    m_cstr(new TChar[cpy.Size() + 1]),
    m_size(cpy.Size())
{
    memcpy(m_cstr, *cpy, cpy.Size() * sizeof(TChar));
    memset(m_cstr + m_size, 0, sizeof(TChar));
}

template<typename TChar>
CString<TChar>::CString(CString<TChar>&& mov) :
    m_cstr(mov.m_cstr),
    m_size(mov.m_size)
{
    mov.m_cstr = nullptr;
    mov.m_size = 0;
}

template<typename TChar>
CString<TChar>::CString(CString<const TChar>&& mov) :
    m_cstr(new TChar[mov.Size() + 1]),
    m_size(mov.Size())
{
    memcpy(m_cstr, *mov, mov.Size() * sizeof(TChar));
    memset(m_cstr + m_size, 0, sizeof(TChar));
}

template<typename TChar>
CString<TChar>::~CString()
{
    if (m_cstr != nullptr)
    {
        delete[] m_cstr;
        m_cstr = nullptr;
        m_size = 0;
    }
}

template<typename TChar>
CString<TChar>& CString<TChar>::
    operator=(const CString<const TChar>& cpy)
{
    if (m_cstr != nullptr)
    {
        delete[] m_cstr;
        m_cstr = nullptr;
        m_size = 0;
    }
    if (*cpy != nullptr)
    {
        m_cstr = new TChar[cpy.Size() + 1];
        m_size = cpy.Size();
        memcpy(m_cstr, *cpy, cpy.Size() * sizeof(TChar));
        memset(m_cstr + m_size, 0, sizeof(TChar));
    }
    return *this;
}

template<typename TChar>
template<std::size_t S>
CString<TChar>& CString<TChar>::operator=(const TChar(&cstr)[S])
{
    return operator=(CString<const TChar>(cstr));
}

template<typename TChar>
CString<TChar>& CString<TChar>::operator=(const CString<TChar>& cpy)
{
    return operator=(CString<const TChar>(cpy));
}

template<typename TChar>
CString<TChar>& CString<TChar>::operator=(CString<TChar>&& mov)
{
    if (m_cstr != nullptr)
    {
        delete[] m_cstr;
        m_cstr = nullptr;
        m_size = 0;
    }
    if (mov.m_cstr != nullptr)
    {
        m_cstr = mov.m_cstr;
        m_size = mov.m_size;
        mov.m_cstr = nullptr;
        mov.m_size = 0;
    }
    return *this;
}

template<typename TChar>
CString<TChar>& CString<TChar>::operator=(CString<const TChar>&& mov)
{
    if (m_cstr != nullptr)
    {
        delete[] m_cstr;
        m_cstr = nullptr;
        m_size = 0;
    }
    if (*mov != nullptr)
    {
        m_cstr = new TChar[mov.Size() + 1];
        m_size = mov.Size();
        memcpy(m_cstr, *mov, mov.Size() * sizeof(TChar));
        memset(m_cstr + m_size, 0, sizeof(TChar));
    }
    return *this;
}

template<typename TChar>
TChar& CString<TChar>::operator[](const std::size_t& index)
{
    return m_cstr[index];
}

template<typename TChar>
const TChar& CString<TChar>::operator[](const std::size_t& index) const
{
    return m_cstr[index];
}

template<typename TChar>
const TChar* CString<TChar>::operator*() const
{
    return m_cstr;
}

template<typename TChar>
const std::size_t& CString<TChar>::Size() const
{
    return m_size;
}

template<typename TChar>
TChar*& CString<TChar>::Get()
{
    return m_cstr;
}

template<typename TChar>
const TChar*& CString<TChar>::Get() const
{
    return m_cstr;
}

template<typename TChar>
template<std::size_t S>
CString<const TChar>::CString(const TChar(&cstr)[S]) :
    m_cstr(cstr),
    m_size(S - 1)
{}

template<typename TChar>
CString<const TChar>::CString(const TChar* cstr, const std::size_t& size) :
    m_cstr(cstr),
    m_size(size)
{}

template<typename TChar>
CString<const TChar>::CString(const CString<TChar>& cpy) :
    m_cstr(*cpy),
    m_size(cpy.Size())
{}

template<typename TChar>
CString<const TChar>::CString(const CString<const TChar>& cpy) :
    m_cstr(cpy.m_cstr),
    m_size(cpy.m_size)
{}

template<typename TChar>
CString<const TChar>::CString(CString<const TChar>&& mov) :
    m_cstr(mov.m_cstr),
    m_size(mov.m_size)
{}

template<typename TChar>
const TChar& CString<const TChar>::operator[](const std::size_t& index) const
{
    return m_cstr[index];
}

template<typename TChar>
const TChar* CString<const TChar>::operator*() const
{
    return m_cstr;
}

template<typename TChar>
const std::size_t& CString<const TChar>::Size() const
{
    return m_size;
}

template<typename TChar>
const TChar*& CString<const TChar>::Get() const
{
    return m_cstr;
}

} //!test

#endif //!TEST_CSTRING_H_
