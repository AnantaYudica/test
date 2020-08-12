#ifndef TEST_POINTER_H_
#define TEST_POINTER_H_

#include <cstddef>
#include <type_traits>
#include <atomic>

namespace test
{

template<typename T, T(*DefaultValueFunc)() = nullptr, typename TEnable = void>
class Pointer
{
public:
    typedef T ValueType;
    typedef std::size_t IntegerCountType;
    typedef std::atomic<IntegerCountType> CountType;
private:
    static void _Reset(ValueType*& value, CountType*& count);
private:
    ValueType * m_value;
    CountType * m_count;
public:
    Pointer();
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_pointer<typename std::remove_reference<
            typename std::remove_cv<TArg>::type>::type>::type, 
        typename std::enable_if<!std::is_same<_TArg, Pointer<T, 
            DefaultValueFunc, TEnable>>::value, int>::type = 0>
    Pointer(TArg&& arg, TArgs&&... args);
public:
    ~Pointer();
public:
    Pointer(const Pointer<T, DefaultValueFunc, TEnable>& cpy);
    Pointer(Pointer<T, DefaultValueFunc, TEnable>&& mov);
public:
    Pointer<T, DefaultValueFunc, TEnable>& 
        operator=(const Pointer<T, DefaultValueFunc, TEnable>& cpy);
    Pointer<T, DefaultValueFunc, TEnable>& 
        operator=(Pointer<T, DefaultValueFunc, TEnable>&& mov);
public:
    T& operator*();
public:
    T* operator->();
public:
    bool operator==(const Pointer<T, 
        DefaultValueFunc, TEnable>& other) const;
    bool operator!=(const Pointer<T, 
        DefaultValueFunc, TEnable>& other) const;
};

template<typename T, T(*DefaultValueFunc)()>
class Pointer<T, DefaultValueFunc, 
    typename std::enable_if<DefaultValueFunc == nullptr>::type>
{
public:
    typedef T ValueType;
    typedef std::size_t IntegerCountType;
    typedef std::atomic<IntegerCountType> CountType;
private:
    static void _Reset(ValueType*& value, CountType*& count);
private:
    ValueType * m_value;
    CountType * m_count;
public:
    Pointer();
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_pointer<typename std::remove_reference<
            typename std::remove_cv<TArg>::type>::type>::type, 
        typename std::enable_if<!std::is_same<_TArg, Pointer<T, 
            DefaultValueFunc, void>>::value, int>::type = 0>
    Pointer(TArg&& arg, TArgs&&... args);
public:
    ~Pointer();
public:
    Pointer(const Pointer<T, DefaultValueFunc, void>& cpy);
    Pointer(Pointer<T, DefaultValueFunc, void>&& mov);
public:
    Pointer<T, DefaultValueFunc, void>& 
        operator=(const Pointer<T, DefaultValueFunc, void>& cpy);
    Pointer<T, DefaultValueFunc, void>& 
        operator=(Pointer<T, DefaultValueFunc, void>&& mov);
public:
    T& operator*();
public:
    T* operator->();
public:
    bool operator==(const Pointer<T, DefaultValueFunc, void>& other) const;
    bool operator!=(const Pointer<T, DefaultValueFunc, void>& other) const;
};

template<typename T, T(*DefaultValueFunc)(), typename TEnable>
void Pointer<T, DefaultValueFunc, TEnable>::
    _Reset(ValueType*& value, CountType*& count)
{
    const auto is_count_null = (count == nullptr);
    if (!is_count_null && *count == 1)
    {
        if (value != nullptr)
            delete value;
        delete count;
    }
    else if (!is_count_null)
        (*count)--;
    count = nullptr;
    value = nullptr;
}

template<typename T, T(*DefaultValueFunc)(), typename TEnable>
Pointer<T, DefaultValueFunc, TEnable>::Pointer() :
    m_value(new ValueType(DefaultValueFunc())),
    m_count(new CountType(1))
{}

template<typename T, T(*DefaultValueFunc)(), typename TEnable>
template<typename TArg, typename... TArgs, typename _TArg, 
    typename std::enable_if<!std::is_same<_TArg, Pointer<T, 
        DefaultValueFunc, TEnable>>::value, int>::type>
Pointer<T, DefaultValueFunc, TEnable>::Pointer(TArg&& arg, TArgs&&... args) :
    m_value(new ValueType(std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...)),
    m_count(new CountType(1))
{}

template<typename T, T(*DefaultValueFunc)(), typename TEnable>
Pointer<T, DefaultValueFunc, TEnable>::~Pointer()
{
    _Reset(m_value, m_count);
}

template<typename T, T(*DefaultValueFunc)(), typename TEnable>
Pointer<T, DefaultValueFunc, TEnable>::
    Pointer(const Pointer<T, DefaultValueFunc, TEnable>& cpy) :
        m_value(cpy.m_value),
        m_count(cpy.m_count)
{
    (*m_count)++;
}

template<typename T, T(*DefaultValueFunc)(), typename TEnable>
Pointer<T, DefaultValueFunc, TEnable>::
    Pointer(Pointer<T, DefaultValueFunc, TEnable>&& mov) :
        m_value(mov.m_value),
        m_count(mov.m_count)
{
    mov.m_value = new ValueType(DefaultValueFunc());
    mov.m_count = new CountType(1);
}

template<typename T, T(*DefaultValueFunc)(), typename TEnable>
Pointer<T, DefaultValueFunc, TEnable>& 
Pointer<T,DefaultValueFunc, TEnable>::
    operator=(const Pointer<T, DefaultValueFunc, TEnable>& cpy)
{
    _Reset(m_value, m_count);
    m_value = cpy.m_value;
    m_count = cpy.m_count;
    (*m_count)++;
    return *this;
}

template<typename T, T(*DefaultValueFunc)(), typename TEnable>
Pointer<T, DefaultValueFunc, TEnable>& 
Pointer<T, DefaultValueFunc, TEnable>::
    operator=(Pointer<T, DefaultValueFunc, TEnable>&& mov)
{
    _Reset(m_value, m_count);
    m_value = mov.m_value;
    m_count = mov.m_count;
    mov.m_value = new ValueType(DefaultValueFunc());
    mov.m_count = new CountType(1);
    return *this;
}

template<typename T, T(*DefaultValueFunc)(), typename TEnable>
T& Pointer<T, DefaultValueFunc, TEnable>::operator*()
{
    return *m_value;
}

template<typename T, T(*DefaultValueFunc)(), typename TEnable>
T* Pointer<T, DefaultValueFunc, TEnable>::operator->()
{
    return m_value;
}

template<typename T, T(*DefaultValueFunc)(), typename TEnable>
bool Pointer<T, DefaultValueFunc, TEnable>::
    operator==(const Pointer<T, DefaultValueFunc, TEnable>& other) const
{
    return m_value == other.m_value;
}

template<typename T, T(*DefaultValueFunc)(), typename TEnable>
bool Pointer<T, DefaultValueFunc, TEnable>::
    operator!=(const Pointer<T, DefaultValueFunc, TEnable>& other) const
{
    return m_value != other.m_value;
}

template<typename T, T(*DefaultValueFunc)()>
void Pointer<T, DefaultValueFunc, 
    typename std::enable_if<DefaultValueFunc == nullptr>::type>::
        _Reset(ValueType*& value, CountType*& count)
{
    const auto is_count_null = (count == nullptr);
    if (!is_count_null && *count == 1)
    {
        if (value != nullptr)
            delete value;
        delete count;
    }
    else if (!is_count_null)
        (*count)--;
    count = nullptr;
    value = nullptr;
}

template<typename T, T(*DefaultValueFunc)()>
Pointer<T, DefaultValueFunc, 
    typename std::enable_if<DefaultValueFunc == nullptr>::type>::Pointer() :
        m_value(new ValueType()),
        m_count(new CountType(1))
{}

template<typename T, T(*DefaultValueFunc)()>
template<typename TArg, typename... TArgs, typename _TArg, 
    typename std::enable_if<!std::is_same<_TArg, Pointer<T, 
        DefaultValueFunc, void>>::value, int>::type>
Pointer<T, DefaultValueFunc, 
    typename std::enable_if<DefaultValueFunc == nullptr>::type>::
        Pointer(TArg&& arg, TArgs&&... args) :
            m_value(new ValueType(std::forward<TArg>(arg), 
                std::forward<TArgs>(args)...)),
            m_count(new CountType(1))
{}

template<typename T, T(*DefaultValueFunc)()>
Pointer<T, DefaultValueFunc, 
    typename std::enable_if<DefaultValueFunc == nullptr>::type>::~Pointer()
{
    _Reset(m_value, m_count);
}

template<typename T, T(*DefaultValueFunc)()>
Pointer<T, DefaultValueFunc, 
    typename std::enable_if<DefaultValueFunc == nullptr>::type>::
        Pointer(const Pointer<T, DefaultValueFunc, void>& cpy) :
            m_value(cpy.m_value),
            m_count(cpy.m_count)
{
    (*m_count)++;
}

template<typename T, T(*DefaultValueFunc)()>
Pointer<T, DefaultValueFunc, 
    typename std::enable_if<DefaultValueFunc == nullptr>::type>::
        Pointer(Pointer<T, DefaultValueFunc, void>&& mov) :
            m_value(mov.m_value),
            m_count(mov.m_count)
{
    mov.m_value = new ValueType();
    mov.m_count = new CountType(1);
}

template<typename T, T(*DefaultValueFunc)()>
Pointer<T, DefaultValueFunc, void>& 
Pointer<T, DefaultValueFunc, 
    typename std::enable_if<DefaultValueFunc == nullptr>::type>::
        operator=(const Pointer<T, DefaultValueFunc, void>& cpy)
{
    _Reset(m_value, m_count);
    m_value = cpy.m_value;
    m_count = cpy.m_count;
    (*m_count)++;
    return *this;
}

template<typename T, T(*DefaultValueFunc)()>
Pointer<T, DefaultValueFunc, void>& 
Pointer<T, DefaultValueFunc, 
    typename std::enable_if<DefaultValueFunc == nullptr>::type>::
        operator=(Pointer<T, DefaultValueFunc, void>&& mov)
{
    _Reset(m_value, m_count);
    m_value = mov.m_value;
    m_count = mov.m_count;
    mov.m_value = new ValueType();
    mov.m_count = new CountType(1);
    return *this;
}

template<typename T, T(*DefaultValueFunc)()>
T& Pointer<T, DefaultValueFunc, 
    typename std::enable_if<DefaultValueFunc == nullptr>::type>::operator*()
{
    return *m_value;
}

template<typename T, T(*DefaultValueFunc)()>
T* Pointer<T, DefaultValueFunc, 
    typename std::enable_if<DefaultValueFunc == nullptr>::type>::operator->()
{
    return m_value;
}

template<typename T, T(*DefaultValueFunc)()>
bool Pointer<T, DefaultValueFunc, 
    typename std::enable_if<DefaultValueFunc == nullptr>::type>::
        operator==(const Pointer<T, DefaultValueFunc, void>& other) const
{
    return m_value == other.m_value;
}

template<typename T, T(*DefaultValueFunc)()>
bool Pointer<T, DefaultValueFunc, 
    typename std::enable_if<DefaultValueFunc == nullptr>::type>::
        operator!=(const Pointer<T, DefaultValueFunc, void>& other) const
{
    return m_value != other.m_value;
}

} //!test

#endif //!TEST_POINTER_H_