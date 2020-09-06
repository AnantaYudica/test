#ifndef TEST_NODE_DATA_H_
#define TEST_NODE_DATA_H_

#include "../CString.h"

#include <utility>
#include <type_traits>
#include <cstddef>

namespace test
{
namespace node
{

template<typename T>
class Data
{
public:
    static_assert(!std::is_reference<T>::value, "Not support reference type");
    static_assert(!std::is_array<T>::value, "Not support array type");
    static_assert(!std::is_function<T>::value, "Not support function type");
    static_assert(!std::is_member_function_pointer<T>::value, 
        "Not support pointer to member function type");
    static_assert(!std::is_member_object_pointer<T>::value, 
        "Not support pointer to member object type");
private:
    T m_data;
public:
    Data();
    Data(const T & set);
    Data(T && set);
    template<typename... TArgs, typename std::enable_if<
        std::is_constructible<T, TArgs...>::value, int>::type = 0>
    Data(TArgs && ... args);
public:
    ~Data();
public:
    Data(const Data<T>& cpy);
    Data(Data<T>&& mov);
public:
    Data<T>& operator=(const Data<T>& cpy);
    Data<T>& operator=(Data<T>&& mov);
    Data<T>& operator=(const T& cpy);
    Data<T>& operator=(T&& mov);
public:
    T& operator*();
    T operator*() const;
public:
    T* operator->();
};

template<typename T>
class Data<const T>
{
public:
    static_assert(!std::is_reference<T>::value, "Not support reference type");
    static_assert(!std::is_pointer<T>::value, "Not support pointer type");
private:
    const T m_data;
public:
    Data();
    Data(const T & set);
    template<typename... TArgs, typename std::enable_if<
        std::is_constructible<T, TArgs...>::value, int>::type = 0>
    Data(TArgs && ... args);
public:
    ~Data();
public:
    Data(const Data<const T>& cpy);
    Data(Data<const T>&& mov);
public:
    Data<const T>& operator=(const Data<const T>& cpy);
    Data<const T>& operator=(Data<const T>&& mov);
    Data<const T>& operator=(const T& cpy);
    Data<const T>& operator=(T&& mov);
public:
    const T& operator*();
    T operator*() const;
public:
    const T* operator->();
};

template<typename T>
class Data<T*>
{
public:
    static_assert(!std::is_pointer<T>::value, "Not support multiple pointers type");
    static_assert(!std::is_const<T>::value, "Not support const pointer type");
    static_assert(!std::is_function<T>::value, "Not support pointer to function type");
private:
    T* m_data;
public:
    Data();
    Data(const T & set);
    Data(T && set);
    template<typename... TArgs, typename std::enable_if<
        std::is_constructible<T, TArgs...>::value, int>::type = 0>
    Data(TArgs && ... args);
public:
    ~Data();
public:
    Data(const Data<T*>& cpy);
    Data(Data<T*>&& mov);
public:
    Data<T*>& operator=(const Data<T*>& cpy);
    Data<T*>& operator=(Data<T*>&& mov);
    Data<T*>& operator=(const T& cpy);
    Data<T*>& operator=(T&& mov);
public:
    T& operator*();
    T operator*() const;
public:
    T* operator->();
};

template<typename T>
class Data<const T*>
{
public:
    static_assert(!std::is_pointer<T>::value, "Not support multiple pointers type");
    static_assert(!std::is_const<T>::value, "Not support const pointer type");
    static_assert(!std::is_function<T>::value, "Not support pointer to function type");
private:
    const T* m_data;
public:
    Data();
    Data(const T & set);
    Data(T && set);
    template<typename... TArgs, typename std::enable_if<
        std::is_constructible<T, TArgs...>::value, int>::type = 0>
    Data(TArgs && ... args);
public:
    ~Data();
public:
    Data(const Data<const T*>& cpy);
    Data(Data<const T*>&& mov);
public:
    Data<const T*>& operator=(const Data<const T*>& cpy);
    Data<const T*>& operator=(Data<const T*>&& mov);
    Data<const T*>& operator=(const T& cpy);
    Data<const T*>& operator=(T&& mov);
public:
    const T& operator*();
    T operator*() const;
public:
    const T* operator->();
};

template<typename T>
class Data<T*const>
{
public:
    static_assert(!std::is_pointer<T>::value, "Not support multiple pointers type");
    static_assert(!std::is_const<T>::value, "Not support const pointer type");
    static_assert(!std::is_function<T>::value, "Not support pointer to function type");
private:
    T*const m_data;
public:
    Data();
    Data(const T & set);
    template<typename... TArgs, typename std::enable_if<
        std::is_constructible<T, TArgs...>::value, int>::type = 0>
    Data(TArgs && ... args);
public:
    ~Data();
public:
    Data(const Data<T*const>& cpy);
    Data(Data<T*const>&& mov);
public:
    Data<T*const>& operator=(const Data<T*const>& cpy);
    Data<T*const>& operator=(Data<T*const>&& mov);
    Data<T*const>& operator=(const T& cpy);
    Data<T*const>& operator=(T&& mov);
public:
    T& operator*();
    T operator*() const;
public:
    T* operator->();
};


template<typename T>
class Data<const T*const>
{
public:
    static_assert(!std::is_pointer<T>::value, "Not support multiple pointers type");
    static_assert(!std::is_const<T>::value, "Not support const pointer type");
    static_assert(!std::is_function<T>::value, "Not support pointer to function type");
private:
    const T*const m_data;
public:
    Data();
    Data(const T & set);
    template<typename... TArgs, typename std::enable_if<
        std::is_constructible<T, TArgs...>::value, int>::type = 0>
    Data(TArgs && ... args);
public:
    ~Data();
public:
    Data(const Data<const T*const>& cpy);
    Data(Data<const T*const>&& mov);
public:
    Data<const T*const>& operator=(const Data<const T*const>& cpy);
    Data<const T*const>& operator=(Data<const T*const>&& mov);
    Data<const T*const>& operator=(const T& cpy);
    Data<const T*const>& operator=(T&& mov);
public:
    const T& operator*();
    T operator*() const;
public:
    const T* operator->();
};

template<typename T>
Data<T>::Data() :
    m_data()
{}

template<typename T>
Data<T>::Data(const T & set) :
    m_data(set)
{}

template<typename T>
Data<T>::Data(T && set) :
    m_data(std::move(set))
{}

template<typename T>
template<typename... TArgs, typename std::enable_if<
    std::is_constructible<T, TArgs...>::value, int>::type>
Data<T>::Data(TArgs &&... args) :
    m_data(std::forward<TArgs>(args)...)
{}

template<typename T>
Data<T>::~Data()
{}

template<typename T>
Data<T>::Data(const Data<T>& cpy) :
    m_data(cpy.m_data)
{}

template<typename T>
Data<T>::Data(Data<T>&& mov) :
    m_data(std::move(mov.m_data))
{}

template<typename T>
Data<T>& Data<T>::operator=(const Data<T>& cpy)
{
    m_data = cpy.m_data;
    return *this;
}

template<typename T>
Data<T>& Data<T>::operator=(Data<T>&& mov)
{
    m_data = std::move(mov.m_data);
    return *this;
}

template<typename T>
Data<T>& Data<T>::operator=(const T& cpy)
{
    m_data = cpy;
    return *this;
}

template<typename T>
Data<T>& Data<T>::operator=(T&& mov)
{
    m_data = std::move(mov);
    return *this;
}

template<typename T>
T& Data<T>::operator*()
{
    return m_data;
}

template<typename T>
T Data<T>::operator*() const
{
    return {m_data};
}

template<typename T>
T* Data<T>::operator->()
{
    return &m_data;
}

template<typename T>
Data<const T>::Data() :
    m_data()
{}

template<typename T>
Data<const T>::Data(const T & set) :
    m_data(set)
{}

template<typename T>
template<typename... TArgs, typename std::enable_if<
    std::is_constructible<T, TArgs...>::value, int>::type>
Data<const T>::Data(TArgs && ... args) :
    m_data(std::forward<TArgs>(args)...)
{}

template<typename T>
Data<const T>::~Data()
{}

template<typename T>
Data<const T>::Data(const Data<const T>& cpy) :
    m_data(cpy.m_data)
{}

template<typename T>
Data<const T>::Data(Data<const T>&& mov) :
    m_data(mov.m_data)
{}

template<typename T>
Data<const T>& Data<const T>::operator=(const Data<const T>&)
{
    return *this;
}

template<typename T>
Data<const T>& Data<const T>::operator=(Data<const T>&&)
{
    return *this;
}

template<typename T>
Data<const T>& Data<const T>::operator=(const T&)
{
    return *this;
}

template<typename T>
Data<const T>& Data<const T>::operator=(T&&)
{
    return *this;
}

template<typename T>
const T& Data<const T>::operator*()
{
    return m_data;
}

template<typename T>
T Data<const T>::operator*() const
{
    return {m_data};
}

template<typename T>
const T* Data<const T>::operator->()
{
    return &m_data;
}

template<typename T>
Data<T*>::Data() :
    m_data(new T())
{}

template<typename T>
Data<T*>::Data(const T & set) :
    m_data(new T(set))
{}

template<typename T>
Data<T*>::Data(T && set) :
    m_data(new T(std::move(set)))
{}

template<typename T>
template<typename... TArgs, typename std::enable_if<
    std::is_constructible<T, TArgs...>::value, int>::type>
Data<T*>::Data(TArgs && ... args) :
    m_data(new T(std::forward<TArgs>(args)...))
{}

template<typename T>
Data<T*>::~Data()
{
    if (m_data != nullptr) 
    {
        delete m_data;
        m_data = nullptr;
    }
}

template<typename T>
Data<T*>::Data(const Data<T*>& cpy) :
    m_data(cpy.m_data != nullptr ? new T(*(cpy.m_data)) : nullptr)
{}

template<typename T>
Data<T*>::Data(Data<T*>&& mov) :
    m_data(mov.m_data)
{
    mov.m_data = nullptr;
}

template<typename T>
Data<T*>& Data<T*>::operator=(const Data<T*>& cpy)
{
    if (m_data != nullptr)
    {
        delete m_data;
        m_data = nullptr;
    }
    if (cpy.m_data != nullptr)
    {
        m_data = new T(*(cpy.m_data));
    }
    return *this;
}

template<typename T>
Data<T*>& Data<T*>::operator=(Data<T*>&& mov)
{
    if (m_data != nullptr)
        delete m_data;
    m_data = mov.m_data;
    mov.m_data = nullptr;
    return *this;
}

template<typename T>
Data<T*>& Data<T*>::operator=(const T& cpy)
{
    if (m_data != nullptr)
    {
        delete m_data;
        m_data = nullptr;
    }
    m_data = new T(cpy);
    return *this;
}

template<typename T>
Data<T*>& Data<T*>::operator=(T&& mov)
{
    if (m_data != nullptr)
    {
        delete m_data;
        m_data = nullptr;
    }
    m_data = new T(std::move(mov));
    return *this;
}

template<typename T>
T& Data<T*>::operator*()
{
    if (m_data == nullptr)
        m_data = new T();
    return *m_data;
}

template<typename T>
T Data<T*>::operator*() const
{
    if (m_data == nullptr)
        return {};
    return {*m_data};
}

template<typename T>
T* Data<T*>::operator->()
{
    if (m_data == nullptr)
        m_data = new T();
    return m_data;
}

template<typename T>
Data<const T*>::Data() :
    m_data(new const T())
{}

template<typename T>
Data<const T*>::Data(const T & set) :
    m_data(new const T(set))
{}

template<typename T>
Data<const T*>::Data(T && set) :
    m_data(new const T(std::move(set)))
{}

template<typename T>
template<typename... TArgs, typename std::enable_if<
    std::is_constructible<T, TArgs...>::value, int>::type>
Data<const T*>::Data(TArgs && ... args) :
    m_data(new const T(std::forward<TArgs>(args)...))
{}

template<typename T>
Data<const T*>::~Data()
{
    if (m_data != nullptr) 
    {
        delete m_data;
        m_data = nullptr;
    }
}

template<typename T>
Data<const T*>::Data(const Data<const T*>& cpy) :
    m_data(cpy.m_data != nullptr ? new const T(*(cpy.m_data)) : nullptr)
{}

template<typename T>
Data<const T*>::Data(Data<const T*>&& mov) :
    m_data(mov.m_data)
{
    mov.m_data = nullptr;
}

template<typename T>
Data<const T*>& Data<const T*>::operator=(const Data<const T*>& cpy)
{
    if (m_data != nullptr)
    {
        delete m_data;
        m_data = nullptr;
    }
    if (cpy.m_data != nullptr)
        m_data = new const T(*(cpy.m_data));
    return *this;
}

template<typename T>
Data<const T*>& Data<const T*>::operator=(Data<const T*>&& mov)
{
    if (m_data != nullptr)
    {
        delete m_data;
        m_data = nullptr;
    }
    if (mov.m_data != nullptr)
    {
        m_data = mov.m_data;
        mov.m_data = nullptr;
    }
    return *this;
}

template<typename T>
Data<const T*>& Data<const T*>::operator=(const T& cpy)
{
    if (m_data != nullptr)
        delete m_data;
    m_data = new const T(cpy);
    return *this;
}

template<typename T>
Data<const T*>& Data<const T*>::operator=(T&& mov)
{
    if (m_data != nullptr)
        delete m_data;
    m_data = new const T(std::move(mov));
    return *this;
}

template<typename T>
const T& Data<const T*>::operator*()
{
    if (m_data == nullptr)
        m_data = new const T();
    return *m_data;
}

template<typename T>
T Data<const T*>::operator*() const
{
    if (m_data == nullptr)
        return {};
    return {*m_data};
}

template<typename T>
const T* Data<const T*>::operator->()
{
    if (m_data == nullptr)
        m_data = new const T();
    return m_data;
}

template<typename T>
Data<T*const>::Data() :
    m_data(new T())
{}

template<typename T>
Data<T*const>::Data(const T & set) :
    m_data(new T(set))
{}

template<typename T>
template<typename... TArgs, typename std::enable_if<
    std::is_constructible<T, TArgs...>::value, int>::type>
Data<T*const>::Data(TArgs && ... args) :
    m_data(new T(std::forward<TArgs>(args)...))
{}

template<typename T>
Data<T*const>::~Data()
{
    if (m_data != nullptr)
    {
        delete m_data;
    } 
}

template<typename T>
Data<T*const>::Data(const Data<T*const>& cpy) :
    m_data(new T(*(cpy.m_data)))
{}

template<typename T>
Data<T*const>::Data(Data<T*const>&& mov) :
    m_data(new T(*(mov.m_data)))
{}

template<typename T>
Data<T*const>& Data<T*const>::operator=(const Data<T*const>&)
{
    return *this;
}

template<typename T>
Data<T*const>& Data<T*const>::operator=(Data<T*const>&&)
{
    return *this;
}

template<typename T>
Data<T*const>& Data<T*const>::operator=(const T&)
{
    return *this;
}

template<typename T>
Data<T*const>& Data<T*const>::operator=(T&&)
{
    return *this;
}

template<typename T>
T& Data<T*const>::operator*()
{
    return *m_data;
}

template<typename T>
T Data<T*const>::operator*() const
{
    return {*m_data};
}

template<typename T>
T* Data<T*const>::operator->()
{
    return m_data;
}

template<typename T>
Data<const T*const>::Data() :
    m_data(new const T())
{}

template<typename T>
Data<const T*const>::Data(const T & set) :
    m_data(new const T(set))
{}

template<typename T>
template<typename... TArgs, typename std::enable_if<
    std::is_constructible<T, TArgs...>::value, int>::type>
Data<const T*const>::Data(TArgs && ... args) :
    m_data(new const T(std::forward<TArgs>(args)...))
{}

template<typename T>
Data<const T*const>::~Data()
{
    if (m_data != nullptr)
    {
        delete m_data;
    }
}

template<typename T>
Data<const T*const>::Data(const Data<const T*const>& cpy) :
    m_data(new const T(*(cpy.m_data)))
{}

template<typename T>
Data<const T*const>::Data(Data<const T*const>&& mov) :
    m_data(new const T(std::move(*(mov.m_data))))
{}

template<typename T>
Data<const T*const>& 
Data<const T*const>::operator=(const Data<const T*const>&)
{
    return *this;
}

template<typename T>
Data<const T*const>& 
Data<const T*const>::operator=(Data<const T*const>&&)
{
    return *this;
}

template<typename T>
Data<const T*const>& 
Data<const T*const>::operator=(const T&)
{
    return *this;
}

template<typename T>
Data<const T*const>& Data<const T*const>::operator=(T&&)
{
    return *this;
}

template<typename T>
const T& Data<const T*const>::operator*()
{
    return *m_data;
}

template<typename T>
T Data<const T*const>::operator*() const
{
    return {*m_data};
}

template<typename T>
const T* Data<const T*const>::operator->()
{
    return m_data;
}

} //!node

} //!test

#endif //!TEST_NODE_DATA_H_