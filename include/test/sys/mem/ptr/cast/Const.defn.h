#ifndef TEST_SYS_MEM_PTR_CONST_CAST_H_DEFN_
#define TEST_SYS_MEM_PTR_CONST_CAST_H_DEFN_

#include "../../../Definition.h"
#include "../../../Interface.h"

#include "Const.decl.h"
#include "../../Pointer.decl.h"
#include "../Const.decl.h"

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
namespace cast
{

template<typename T, typename TBlock>
class Const : 
    protected test::sys::mem::Pointer<TBlock>
{
private:
    typedef test::sys::mem::Pointer<TBlock> BaseType;
    typedef test::sys::Definition DefinitionType;
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::mem::ptr::cast::Const<T, 
        TBlock>> DebugType;
public:
    typedef TBlock BlockType;
    typedef typename BlockType::TimestampType TimestampType;
public:
    typedef test::sys::mem::Pointer<TBlock> PointerType;
    typedef test::sys::mem::ptr::Const<TBlock> PointerConstType;
public:

public:
    Const();
    Const(TBlock * ptr);
public:
    Const(const PointerType& ptr_cpy);
    Const(PointerType&& ptr_mov);
public:
    Const(const PointerConstType& ptr_const_cpy);
    Const(PointerConstType&& ptr_const_mov);
public:
    Const(const Const<T, TBlock>& cpy);
    Const(Const<T, TBlock>&& mov);
public:
    ~Const();
public:
    Const<T, TBlock>& operator=(const Const<T, TBlock>& cpy);
    Const<T, TBlock>& operator=(Const<T, TBlock>&& mov);
public:
    void* operator new (std::size_t) = delete;
    void* operator new[] (std::size_t) = delete;
    void operator delete(void*) = delete;
    void operator delete[](void*) = delete;
public:
    template<typename _T>
    Const<_T, TBlock> Cast() = delete;
    template<typename _T>
    Const<_T, TBlock> Cast() const = delete;
public:
    operator bool();
    operator bool() const;
public:
    std::size_t Size();
    std::size_t Size() const;
public:
    std::size_t Count();
    std::size_t Count() const;
public:
    TimestampType Timestamp();
    TimestampType Timestamp() const;
public:
    const T* operator[](const std::size_t& n);
    const T* operator[](const std::size_t& n) const;
public:
    const T& operator*();
    const T& operator*() const;
public:
    const T* operator->();
    const T* operator->() const;
public:
    bool operator==(void * ptr) const;
    bool operator==(const void * ptr) const;
    bool operator==(std::nullptr_t) const;
    bool operator==(const Const<T, TBlock>& other) const;
    bool operator!=(void * ptr) const;
    bool operator!=(const void * ptr) const;
    bool operator!=(std::nullptr_t) const;
    bool operator!=(const Const<T, TBlock>& other) const;
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

} //!cast

} //!ptr

} //!mem

} //!sys

} //!test

#endif //!TEST_SYS_MEM_PTR_CONST_CAST_H_DEFN_
