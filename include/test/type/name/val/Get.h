#ifndef TEST_TYPE_NAME_VAL_GET_H_
#define TEST_TYPE_NAME_VAL_GET_H_

#include "../../../CString.h"
#include "../../../cstr/Format.h"
#include "Enumeration.h"

#include <cstdint>

namespace test
{
namespace type
{
namespace name
{
namespace val
{

template<typename T>
struct Get
{
    template<T V, typename TChar= char>
    static test::CString<TChar> CStr()
    {
        return {test::type::name::val::Enumeration<T, V>::template
            CStr<TChar>()};
    }
};

template<typename T>
struct Get<T&>
{
    template<T& V, typename TChar= char>
    static test::CString<TChar> CStr()
    {
        test::CString<TChar> _val = test::cstr::Format(
            (sizeof(int*) * 2) + 3, "%p", &V);
        return {_val};
    }
};

template<typename T>
struct Get<T*>
{
    template<T* V, typename TChar= char>
    static test::CString<TChar> CStr()
    {
        test::CString<TChar> _val = test::cstr::Format(
            (sizeof(int*) * 2) + 3, "%p", V);
        return {_val};
    }
};

template<typename T, typename TM>
struct Get<T TM::*>
{
    template<T TM::* V, typename TChar= char>
    static test::CString<TChar> CStr()
    {
        auto _v = static_cast<T TM::*>(V);
        auto p = reinterpret_cast<uintptr_t*>(&_v);
        test::CString<TChar> _val = test::cstr::Format(
            (sizeof(uintptr_t*) * 2) + 3, "%p", (void*)*p);
        return {_val};
    }
};

template<typename T, typename TM>
struct Get<T TM::*const>
{
    template<T TM::*const V, typename TChar= char>
    static test::CString<TChar> CStr()
    {
        auto _v = static_cast<T TM::*>(V);
        auto p = reinterpret_cast<uintptr_t*>(&_v);
        test::CString<TChar> _val = test::cstr::Format(
            (sizeof(uintptr_t*) * 2) + 3, "%p", (void*)*p);
        return {_val};
    }
};

template<typename T, typename TM>
struct Get<T TM::*volatile>
{
    template<T TM::*volatile V, typename TChar= char>
    static test::CString<TChar> CStr()
    {
        auto _v = static_cast<T TM::*>(V);
        auto p = reinterpret_cast<uintptr_t*>(&_v);
        test::CString<TChar> _val = test::cstr::Format(
            (sizeof(uintptr_t*) * 2) + 3, "%p", (void*)*p);
        return {_val};
    }
};

template<typename T, typename TM>
struct Get<T TM::*const volatile>
{
    template<T TM::*const volatile V, typename TChar= char>
    static test::CString<TChar> CStr()
    {
        auto _v = static_cast<T TM::*>(V);
        auto p = reinterpret_cast<uintptr_t*>(&_v);
        test::CString<TChar> _val = test::cstr::Format(
            (sizeof(uintptr_t*) * 2) + 3, "%p", (void*)*p);
        return {_val};
    }
};


} //!val

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_VAL_GET_H_
