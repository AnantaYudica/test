#ifndef TEST_PTR_DEFINITION_H_
#define TEST_PTR_DEFINITION_H_

#include "Flag.h"

#include <cstddef>
#include <type_traits>
#include <utility>
#include <new>

namespace test
{
namespace ptr
{

template<typename T, T(*Func)() = nullptr, typename TEnable = void>
struct Definition
{
    typedef test::ptr::FlagIntegerType FlagIntegerType;
    typedef T ValueType;

    static void Constructor(const std::size_t& size, void* data);
    template<typename TArg, typename... TArgs>
    static void Constructor(const std::size_t& size, void* data, TArg&& arg, 
        TArgs&&... args);
    static void Constructor(void* data);
    template<typename TArg, typename... TArgs>
    static void Constructor(void* data, TArg&& arg, TArgs&&... args);
    static void Destructor(void* data);

    Definition() = delete;
};

template<typename T, T(*Func)()>
struct Definition<T, Func, 
    typename std::enable_if<Func == nullptr>::type>
{
    typedef test::ptr::FlagIntegerType FlagIntegerType;
    typedef T ValueType;

    static void Constructor(const std::size_t& size, void* data);
    template<typename TArg, typename... TArgs>
    static void Constructor(const std::size_t& size, void* data, TArg&& arg, 
        TArgs&&... args);
    template<typename... TArgs>
    static void Constructor(void* data, TArgs&&... args);
    static void Destructor(void* data);
    
    Definition() = delete;
};

template<typename T, T(*Func)(), typename TEnable>
void Definition<T, Func, TEnable>::Constructor(const std::size_t& size, 
    void* data)
{
    if (size == 0) return;
    new(data) T(Func());
    Definition<T, Func, TEnable>::Constructor(size - 1, 
        ((char*) data) + sizeof(T));
}

template<typename T, T(*Func)(), typename TEnable>
template<typename TArg, typename... TArgs>
void Definition<T, Func, TEnable>::Constructor(const std::size_t& size, 
    void* data, TArg&& arg, TArgs&&... args)
{
    if (size == 0) return;
    new(data) T(std::forward<TArg>(arg));
    Definition<T, Func, TEnable>::Constructor(size - 1, 
        ((char*) data) + sizeof(T), std::forward<TArgs>(args)...);
}

template<typename T, T(*Func)(), typename TEnable>
void Definition<T, Func, TEnable>::Constructor(void* data)
{
    new(data) T(Func());
}

template<typename T, T(*Func)(), typename TEnable>
template<typename TArg, typename... TArgs>
void Definition<T, Func, TEnable>::Constructor(void* data, TArg&& arg, 
    TArgs&&... args)
{
    new(data) T(std::forward<TArg>(arg), std::forward<TArgs>(args)...);
}

template<typename T, T(*Func)(), typename TEnable>
void Definition<T, Func, TEnable>::Destructor(void* data)
{
    T *cast = (T*)data;
    cast->~T();
}

template<typename T, T(*Func)()>
void Definition<T, Func, typename std::enable_if<Func == nullptr>::type>::
    Constructor(const std::size_t& size, void* data)
{
    if (size == 0) return;
    new(data) T();
    Definition<T, Func, void>::Constructor(size - 1, ((char*) data) + sizeof(T));
}

template<typename T, T(*Func)()>
template<typename TArg, typename... TArgs>
void Definition<T, Func, typename std::enable_if<Func == nullptr>::type>::
    Constructor(const std::size_t& size, void* data, TArg&& arg, 
        TArgs&&... args)
{
    if (size == 0) return;
    new(data) T(std::forward<TArg>(arg));
    Definition<T, Func, void>::Constructor(size - 1, 
        ((char*) data) + sizeof(T), std::forward<TArgs>(args)...);
}

template<typename T, T(*Func)()>
template<typename... TArgs>
void Definition<T, Func, typename std::enable_if<Func == nullptr>::type>::
    Constructor(void* data, TArgs&&... args)
{
    new(data) T(std::forward<TArgs>(args)...);
}

template<typename T, T(*Func)()>
void Definition<T, Func, typename std::enable_if<Func == nullptr>::type>::
    Destructor(void* data)
{
    T *cast = (T*)data;
    cast->~T();
}

template<typename T, T(*Func)()>
std::true_type IsBaseOfDefault(Definition<T, Func>);

std::false_type IsBaseOfDefault(...);

} //!ptr

} //!test

#endif //!TEST_PTR_DEFINITION_H_
