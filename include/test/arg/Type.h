#ifndef TEST_ARG_TYPE_H_
#define TEST_ARG_TYPE_H_

#include "../System.h"
#include "../Pointer.h"

#include <cstddef>
#include <cstdint>

namespace test
{
namespace arg
{

template<typename T>
class Type;

} //!arg

} //!test

#ifndef TEST_ARG_TYPE_DLEVEL

#define TEST_ARG_TYPE_DLEVEL 2

#endif //!TEST_ARG_TYPE_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>

template<typename T>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_ARG_TYPE_DLEVEL, 
    "test::arg::Type", 
    test::arg::Type<T>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace arg
{

template<typename T>
struct Type
{
    typedef T BaseType;
    typedef T ValueType;
    typedef const T& RValueType;
    static constexpr std::size_t Size = sizeof(T);
    static BaseType Initialize(ValueType&& val)
    {
        return std::move(val);
    }
    template<typename Tp, typename TpD>
    static RValueType Get(test::Pointer<Tp, TpD> buff)
    {
        return *(buff.template ReinterpretCast<ValueType>());
    }
    template<typename Tp, typename TpD>
    static void Set(test::Pointer<Tp, TpD> buff, ValueType&& val)
    {
        *(buff.template ReinterpretCast<ValueType>()) = std::move(val);
    }
};

template<>
struct Type<char*>
{
    typedef test::Pointer<char> BaseType;
    typedef const char* ValueType;
    typedef const char* RValueType;
    static constexpr std::size_t Size = sizeof(test::Pointer<char>);
    static BaseType Initialize(ValueType&& val)
    {
        std::size_t len = strlen(std::forward<ValueType>(val));
        BaseType base_val{test::ptr::arg::Array{len + 1}};
        
        strcpy(&*base_val, std::forward<ValueType>(val));
        base_val[len] = '\0';
        return base_val;
    }
    template<typename Tp, typename TpD>
    static RValueType Get(test::Pointer<Tp, TpD> buff)
    {
        return &**(buff.template ReinterpretCast<BaseType>());
    }
    template<typename Tp, typename TpD>
    static void Set(test::Pointer<Tp, TpD> buff, ValueType&& val)
    {
        std::size_t len = strlen(std::forward<ValueType>(val));
        auto& cast = *(buff.template ReinterpretCast<BaseType>());

        cast = BaseType{test::ptr::arg::Array{len + 1}};
        
        strcpy(&*cast, std::forward<ValueType>(val));
        cast[len] = '\0';
    }
};

template<>
struct Type<wchar_t*>
{
    typedef test::Pointer<wchar_t> BaseType;
    typedef const wchar_t* ValueType;
    typedef const wchar_t* RValueType;
    static constexpr std::size_t Size = sizeof(test::Pointer<wchar_t>);
    static BaseType Initialize(ValueType&& val)
    {
        std::size_t len = wcslen(std::forward<ValueType>(val));
        BaseType base_val{test::ptr::arg::Array{len + 1}};
        
        wcscpy(&*base_val, std::forward<ValueType>(val));
        base_val[len] = L'\0';
        return base_val;
    }
    template<typename Tp, typename TpD>
    static RValueType Get(test::Pointer<Tp, TpD> buff)
    {
        return &**(buff.template ReinterpretCast<BaseType>());
    }
    template<typename Tp, typename TpD>
    static void Set(test::Pointer<Tp, TpD> buff, ValueType&& val)
    {
        std::size_t len = wcslen(std::forward<ValueType>(val));
        auto& cast = *(buff.template ReinterpretCast<BaseType>());

        cast = BaseType{test::ptr::arg::Array{len + 1}};
        
        wcscpy(&*cast, std::forward<ValueType>(val));
        cast[len] = L'\0';
    }
};

template<typename T>
struct Type<const T*> : Type<T*>
{
    typedef typename Type<T*>::BaseType BaseType;
    typedef typename Type<T*>::ValueType ValueType;
    typedef typename Type<T*>::RValueType RValueType;
    static constexpr std::size_t Size = Type<T*>::Size;
    
    using Type<T*>::Initialize;
    using Type<T*>::Get;
    using Type<T*>::Set;
};

template<typename T>
struct Type<volatile T*> : Type<T*>
{
    typedef typename Type<T*>::BaseType BaseType;
    typedef typename Type<T*>::ValueType ValueType;
    typedef typename Type<T*>::RValueType RValueType;
    static constexpr std::size_t Size = Type<T*>::Size;
    
    using Type<T*>::Initialize;
    using Type<T*>::Get;
    using Type<T*>::Set;
};

template<typename T>
struct Type<const volatile T*> : Type<T*>
{
    typedef typename Type<T*>::BaseType BaseType;
    typedef typename Type<T*>::ValueType ValueType;
    typedef typename Type<T*>::RValueType RValueType;
    static constexpr std::size_t Size = Type<T*>::Size;
    
    using Type<T*>::Initialize;
    using Type<T*>::Get;
    using Type<T*>::Set;
};

template<typename T, std::size_t N>
struct Type<T(&)[N]> : Type<T*>
{
    typedef typename Type<T*>::BaseType BaseType;
    typedef typename Type<T*>::ValueType ValueType;
    typedef typename Type<T*>::RValueType RValueType;
    static constexpr std::size_t Size = Type<T*>::Size;

    using Type<T*>::Initialize;
    using Type<T*>::Get;
    using Type<T*>::Set;
};

template<typename T>
struct Type<const T> : Type<T>
{
    typedef typename Type<T>::BaseType BaseType;
    typedef typename Type<T>::ValueType ValueType;
    typedef typename Type<T>::RValueType RValueType;
    static constexpr std::size_t Size = Type<T>::Size;
    
    using Type<T>::Initialize;
    using Type<T>::Get;
    using Type<T>::Set;
};

template<typename T>
struct Type<volatile T> : Type<T>
{
    typedef typename Type<T>::BaseType BaseType;
    typedef typename Type<T>::ValueType ValueType;
    typedef typename Type<T>::RValueType RValueType;
    static constexpr std::size_t Size = Type<T>::Size;
    
    using Type<T>::Initialize;
    using Type<T>::Get;
    using Type<T>::Set;
};

template<typename T>
struct Type<const volatile T> : Type<T>
{
    typedef typename Type<T>::BaseType BaseType;
    typedef typename Type<T>::ValueType ValueType;
    typedef typename Type<T>::RValueType RValueType;
    static constexpr std::size_t Size = Type<T>::Size;
    
    using Type<T>::Initialize;
    using Type<T>::Get;
    using Type<T>::Set;
};

template<typename T>
struct Type<T&> : Type<T>
{
    typedef typename Type<T>::BaseType BaseType;
    typedef typename Type<T>::ValueType ValueType;
    typedef typename Type<T>::RValueType RValueType;
    static constexpr std::size_t Size = Type<T>::Size;
    
    using Type<T>::Initialize;
    using Type<T>::Get;
    using Type<T>::Set;
};

} //!arg

} //!test

#endif //!TEST_ARG_TYPE_H_
