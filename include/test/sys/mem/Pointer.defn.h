#ifndef TEST_SYS_MEM_POINTER_H_DEFN_
#define TEST_SYS_MEM_POINTER_H_DEFN_

#include "../Definition.h"
#include "../Interface.h"

#include "Pointer.decl.h"
#include "ptr/Const.decl.h"
#include "ptr/Cast.decl.h"
#include "ptr/cast/Const.decl.h"

#include <cstdint>
#include <cstddef>
#include <type_traits>

namespace test
{
namespace sys
{
namespace mem
{

template<typename TBlock>
class Pointer : 
    public test::sys::mem::ptr::Const<TBlock>
{
private:
    typedef test::sys::Definition DefinitionType;
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::mem::Pointer<TBlock>> DebugType;
public:
    typedef test::sys::mem::ptr::Const<TBlock> BaseType;
    typedef typename test::sys::Definition::TimestampType TimestampType; 
    typedef TBlock BlockType;
public:
    typedef typename BlockType::IDType IDType;
public:
    typedef test::sys::mem::ptr::Const<TBlock> PointerConstType;
public:
    template<typename T>
    using CastType = test::sys::mem::ptr::Cast<T, TBlock>;
    template<typename T>
    using CastConstType = test::sys::mem::ptr::cast::Const<T, TBlock>;
public:
    Pointer();
    Pointer(BlockType * ptr);
protected:
    Pointer(const PointerConstType& cpy);
    Pointer(PointerConstType&& mov);
public:
    Pointer(const Pointer<TBlock>& cpy);
    Pointer(Pointer<TBlock>&& mov);
public:
    ~Pointer();
protected:
    Pointer<TBlock>& operator=(const PointerConstType& cpy);
    Pointer<TBlock>& operator=(PointerConstType&& mov);
public:
    Pointer<TBlock>& operator=(const Pointer<TBlock>& cpy);
    Pointer<TBlock>& operator=(Pointer<TBlock>&& mov);
public:
    void* operator new (std::size_t) = delete;
    void* operator new[] (std::size_t) = delete;
    void operator delete(void*) = delete;
    void operator delete[](void*) = delete;
public:
    void* Unlock();
public:
    using BaseType::operator bool;
    using BaseType::Size;
    using BaseType::Count;
    using BaseType::Timestamp;
    using BaseType::ID;
public:
    template<typename T>
    CastType<T> Cast();
    template<typename T>
    CastConstType<T> Cast() const;
public:
    bool operator<(void *ptr) const;
    bool operator<(const void *ptr) const;
    bool operator<=(void *ptr) const;
    bool operator<=(const void *ptr) const;
    bool operator>(void *ptr) const;
    bool operator>(const void *ptr) const;
    bool operator>=(void *ptr) const;
    bool operator>=(const void *ptr) const;
public:
    bool operator==(void *ptr) const;
    bool operator==(const void *ptr) const;
    bool operator==(std::nullptr_t) const;
    bool operator==(const PointerConstType& other) const;
    bool operator==(const Pointer<TBlock>& other) const;
    bool operator!=(void * ptr) const;
    bool operator!=(const void * ptr) const;
    bool operator!=(std::nullptr_t) const;
    bool operator!=(const PointerConstType& other) const;
    bool operator!=(const Pointer<TBlock>& other) const;
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

} //!mem

} //!sys

} //!test

#endif //!TEST_SYS_MEM_POINTER_H_DEFN_
