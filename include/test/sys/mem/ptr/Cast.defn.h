#ifndef TEST_SYS_MEM_PTR_CAST_H_DEFN_
#define TEST_SYS_MEM_PTR_CAST_H_DEFN_

#include "../../Definition.h"
#include "../../Interface.h"

#include "Cast.decl.h"
#include "cast/Const.decl.h"
#include "Const.decl.h"
#include "../Pointer.decl.h"

#include <cstdint>
#include <cstddef>
#include <type_traits>

namespace test
{
namespace sys
{
namespace mem
{
namespace ptr
{

template<typename T, typename TBlock>
class Cast : public test::sys::mem::ptr::cast::Const<T, TBlock>
{
private:
    typedef test::sys::Definition DefinitionType;
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::mem::ptr::Cast<T, 
        TBlock>> DebugType;
public:
    typedef test::sys::mem::ptr::cast::Const<T, TBlock> BaseType;
    typedef TBlock BlockType;
    typedef typename BlockType::TimestampType TimestampType;
public:
    typedef test::sys::mem::Pointer<TBlock> PointerType;
    typedef test::sys::mem::ptr::Const<TBlock> PointerConstType;
public:
    Cast();
    Cast(TBlock * ptr);
public:
    Cast(const PointerConstType& base_cpy) = delete;
    Cast(PointerConstType&& base_mov) = delete;
public:
    Cast(const PointerType& ptr_cpy);
    Cast(PointerType&& ptr_mov);
public:
    Cast(const Cast<T, TBlock>& cpy);
    Cast(Cast<T, TBlock>&& mov);
public:
    ~Cast();
public:
    Cast<T, TBlock>& operator=(const Cast<T, TBlock>& cpy);
    Cast<T, TBlock>& operator=(Cast<T, TBlock>&& mov);
public:
    void* operator new (std::size_t) = delete;
    void* operator new[] (std::size_t) = delete;
    void operator delete(void*) = delete;
    void operator delete[](void*) = delete;
public:
    using BaseType::operator bool;
public:
    using BaseType::Size;
public:
    using BaseType::Count;
public:
    using BaseType::Timestamp;
public:
    T* operator[](const std::size_t& n);
    const T* operator[](const std::size_t& n) const;
public:
    T& operator*();
    const T& operator*() const;
public:
    T* operator->();
    const T* operator->() const;
public:
    bool operator==(void * ptr) const;
    bool operator==(const void * ptr) const;
    bool operator==(std::nullptr_t) const;
    bool operator==(const BaseType& other) const;
    bool operator==(const Cast<T, TBlock>& other) const;
    bool operator!=(void * ptr) const;
    bool operator!=(const void * ptr) const;
    bool operator!=(std::nullptr_t) const;
    bool operator!=(const BaseType& other) const;
    bool operator!=(const Cast<T, TBlock>& other) const;
public:
    template<typename TValue, typename TNull = decltype(NULL)>
    typename std::enable_if<!std::is_same<TNull, void*>::value
        && std::is_same<TValue, TNull>::value, bool>::type 
            operator==(const TValue& val) const;
    template<typename TValue, typename TNull = decltype(NULL)>
    typename std::enable_if<!std::is_same<TNull, void*>::value
        && std::is_same<TValue, TNull>::value, bool>::type 
            operator!=(const TValue& val) const;
};

} //!ptr

} //!mem

} //!sys

} //test

#endif //!TEST_SYS_MEM_PTR_CAST_H_DEFN_
