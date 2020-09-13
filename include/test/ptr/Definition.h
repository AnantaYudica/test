#ifndef TEST_PTR_DEFINITION_H_
#define TEST_PTR_DEFINITION_H_

#include "Flag.h"
#include "arg/Array.h"
#include "arg/Foreach.h"
#include "defn/Finalization.h"

#include <cstddef>
#include <type_traits>
#include <utility>
#include <new>

namespace test
{
namespace ptr
{

template<typename T, T(*Func)() = nullptr, typename TEnable = void>
class Definition : public test::ptr::defn::Finalization
{
public:
    typedef test::ptr::FlagIntegerType FlagIntegerType;
    typedef T ValueType;
public:
    Definition() = default;
    virtual ~Definition() = default;
public:
    Definition(const Definition&) = default;
    Definition(Definition&&) = default;
public:
    Definition& operator=(const Definition&) = default;
    Definition& operator=(Definition&&) = default;
public:
    void Constructor(const test::ptr::arg::Array& arr, void* data) const;
    template<typename TArg, typename... TArgs>
    void Constructor(const test::ptr::arg::Array& arr, void* data,
        TArg&& arg, TArgs&&... args) const;
    void Constructor(const test::ptr::arg::Array& arr,
        const test::ptr::arg::Foreach& foreach, void* data) const;
    template<typename TArg, typename... TArgs>
    void Constructor(const test::ptr::arg::Array& arr,
        const test::ptr::arg::Foreach& foreach, void* data, TArg&& arg,
        TArgs&&... args) const;
    void Constructor(void* data) const;
    template<typename TArg, typename... TArgs>
    void Constructor(void* data, TArg&& arg, TArgs&&... args) const;
    virtual void Destructor(void* data) const override;
};

template<typename T, T(*Func)()>
class Definition<T, Func, 
    typename std::enable_if<Func == nullptr>::type> :
        public test::ptr::defn::Finalization
{
public:
    typedef test::ptr::FlagIntegerType FlagIntegerType;
    typedef T ValueType;
public:
    Definition() = default;
    virtual ~Definition() = default;
public:
    Definition(const Definition&) = default;
    Definition(Definition&&) = default;
public:
    Definition& operator=(const Definition&) = default;
    Definition& operator=(Definition&&) = default;
public:
    void Constructor(const test::ptr::arg::Array& arr, void* data) const;
    template<typename TArg, typename... TArgs>
    void Constructor(const test::ptr::arg::Array& arr, void* data,
        TArg&& arg, TArgs&&... args) const;
    template<typename... TArgs>
    void Constructor(const test::ptr::arg::Array& arr,
        const test::ptr::arg::Foreach& foreach, void* data, 
        TArgs&&... args) const;
    template<typename... TArgs>
    void Constructor(void* data, TArgs&&... args) const;
    virtual void Destructor(void* data) const override;
};

template<typename T, T(*Func)(), typename TEnable>
void Definition<T, Func, TEnable>::
    Constructor(const test::ptr::arg::Array& arr, void* data) const
{
    if (arr.GetSize() == 0) return;
    new(data) T(Func());
    Definition<T, Func, TEnable>::Constructor(
        test::ptr::arg::Array{arr.GetSize() - 1}, 
        ((char*) data) + sizeof(T));
}

template<typename T, T(*Func)(), typename TEnable>
template<typename TArg, typename... TArgs>
void Definition<T, Func, TEnable>::
    Constructor(const test::ptr::arg::Array& arr, void* data, TArg&& arg, 
        TArgs&&... args) const
{
    if (arr.GetSize() == 0) return;
    new(data) T(std::forward<TArg>(arg));
    Definition<T, Func, TEnable>::Constructor(
        test::ptr::arg::Array{arr.GetSize() - 1}, 
        ((char*) data) + sizeof(T), std::forward<TArgs>(args)...);
}

template<typename T, T(*Func)(), typename TEnable>
void Definition<T, Func, TEnable>::
    Constructor(const test::ptr::arg::Array& arr,
        const test::ptr::arg::Foreach& foreach, void* data) const
{
    if (arr.GetSize() == 0) return;
    new(data) T(Func());
    Definition<T, Func, TEnable>::Constructor(
        test::ptr::arg::Array{arr.GetSize() - 1}, 
        ((char*) data) + sizeof(T), foreach);
}

template<typename T, T(*Func)(), typename TEnable>
template<typename TArg, typename... TArgs>
void Definition<T, Func, TEnable>::
    Constructor(const test::ptr::arg::Array& arr,
        const test::ptr::arg::Foreach& foreach, void* data, TArg&& arg,
        TArgs&&... args) const
{
    if (arr.GetSize() == 0) return;
    new(data) T(std::forward<TArgs>(args)...);
    Definition<T, Func, TEnable>::Constructor(
        test::ptr::arg::Array{arr.GetSize() - 1}, foreach,
        ((char*) data) + sizeof(T), std::forward<TArgs>(args)...);
}

template<typename T, T(*Func)(), typename TEnable>
void Definition<T, Func, TEnable>::Constructor(void* data) const
{
    new(data) T(Func());
}

template<typename T, T(*Func)(), typename TEnable>
template<typename TArg, typename... TArgs>
void Definition<T, Func, TEnable>::Constructor(void* data, TArg&& arg, 
    TArgs&&... args) const
{
    new(data) T(std::forward<TArg>(arg), std::forward<TArgs>(args)...);
}

template<typename T, T(*Func)(), typename TEnable>
void Definition<T, Func, TEnable>::Destructor(void* data) const
{
    T *cast = (T*)data;
    cast->~T();
}

template<typename T, T(*Func)()>
void Definition<T, Func, typename std::enable_if<Func == nullptr>::type>::
    Constructor(const test::ptr::arg::Array& arr, void* data) const
{
    if (arr.GetSize() == 0) return;
    new(data) T();
    Definition<T, Func, void>::Constructor(
        test::ptr::arg::Array{arr.GetSize() - 1}, 
        ((char*) data) + sizeof(T));
}

template<typename T, T(*Func)()>
template<typename TArg, typename... TArgs>
void Definition<T, Func, typename std::enable_if<Func == nullptr>::type>::
    Constructor(const test::ptr::arg::Array& arr, void* data, TArg&& arg, 
        TArgs&&... args) const
{
    if (arr.GetSize() == 0) return;
    new(data) T(std::forward<TArg>(arg));
    Definition<T, Func, void>::Constructor(
        test::ptr::arg::Array{arr.GetSize() - 1}, 
        ((char*) data) + sizeof(T), std::forward<TArgs>(args)...);
}

template<typename T, T(*Func)()>
template<typename... TArgs>
void Definition<T, Func, typename std::enable_if<Func == nullptr>::type>::
    Constructor(const test::ptr::arg::Array& arr,
    const test::ptr::arg::Foreach& foreach, void* data, TArgs&&... args) const
{
    if (arr.GetSize() == 0) return;
    new(data) T(std::forward<TArgs>(args)...);
    Definition<T, Func, void>::Constructor(
        test::ptr::arg::Array{arr.GetSize() - 1}, foreach,
        ((char*) data) + sizeof(T), std::forward<TArgs>(args)...);
}

template<typename T, T(*Func)()>
template<typename... TArgs>
void Definition<T, Func, typename std::enable_if<Func == nullptr>::type>::
    Constructor(void* data, TArgs&&... args) const
{
    new(data) T(std::forward<TArgs>(args)...);
}

template<typename T, T(*Func)()>
void Definition<T, Func, typename std::enable_if<Func == nullptr>::type>::
    Destructor(void* data) const
{
    T *cast = (T*)data;
    cast->~T();
}

} //!ptr

} //!test

#endif //!TEST_PTR_DEFINITION_H_
