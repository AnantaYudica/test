#ifndef TEST_GUARD_H_
#define TEST_GUARD_H_

#include <new>

namespace test
{

template<typename T>
class Guard
{
public:
    typedef bool (T::*BeginPointerFunctionMemberType)();
    typedef void (T::*EndPointerFunctionMemberType)();
private:
    bool m_status;
    T * m_obj;
    BeginPointerFunctionMemberType m_begin;
    EndPointerFunctionMemberType m_end;
public:
    Guard(T * ptr, BeginPointerFunctionMemberType begin);
    Guard(T * ptr, BeginPointerFunctionMemberType begin,
        EndPointerFunctionMemberType end);
    ~Guard();
public:
    Guard(const Guard<T>&) = delete;
    Guard(Guard<T>&& mov);
public:
    Guard<T>& operator=(const Guard<T>&) = delete;
    Guard<T>& operator=(Guard<T>&&) = delete;
private:
    void _Begin();
    void _End();
public:
    operator bool() const;
public:
    void* operator new (std::size_t) = delete;
    void operator delete(void*) = delete;
};

template<typename T>
Guard<T>::Guard(T * ptr, BeginPointerFunctionMemberType begin) :
    m_status(ptr != nullptr ? true : false),
    m_obj(ptr),
    m_begin(begin),
    m_end(nullptr)
{
    _Begin();
}

template<typename T>
Guard<T>::Guard(T * ptr, BeginPointerFunctionMemberType begin,
    EndPointerFunctionMemberType end) :
        m_status(ptr != nullptr ? true : false),
        m_obj(ptr),
        m_begin(begin),
        m_end(end)
{
    _Begin();
}

template<typename T>
Guard<T>::~Guard()
{
    _End();
    m_status = false;
    m_obj = nullptr;
    m_begin = nullptr;
    m_end = nullptr;
}

template<typename T>
Guard<T>::Guard(Guard<T>&& mov) :
    m_status(mov.m_status),
    m_obj(mov.m_obj),
    m_begin(mov.m_begin),
    m_end(mov.m_end)
{}

template<typename T>
void Guard<T>::_Begin()
{
    if (m_begin != nullptr && m_status)
        m_status = (m_obj->*m_begin)();
    else
        m_status = false;
}

template<typename T>
void Guard<T>::_End()
{
    if (m_end != nullptr && m_status)
        (m_obj->*m_end)();
}

template<typename T>
Guard<T>::operator bool() const
{
    return m_status;
}

} //!test

#endif //!TEST_GUARD_H_