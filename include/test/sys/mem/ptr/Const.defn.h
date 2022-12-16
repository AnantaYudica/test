#ifndef TEST_SYS_MEM_PTR_CONST_H_DEFN_
#define TEST_SYS_MEM_PTR_CONST_H_DEFN_

#include "../../Definition.h"
#include "../../Interface.h"

#include "cast/Const.decl.h"
#include "Const.decl.h"

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

template<typename TBlock>
class Const
{
private:
    typedef test::sys::Definition DefinitionType;
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::mem::ptr::Const<TBlock>> DebugType;
public:
    typedef typename test::sys::Definition::TimestampType TimestampType; 
    typedef TBlock BlockType;
public:
    typedef typename BlockType::IDType IDType;
public:
    template<typename T>
    using CastConstType = test::sys::mem::ptr::cast::Const<T, TBlock>;
private:
    static BlockType* Default();
public:
    BlockType* m_block;
public:
    Const();
    Const(BlockType * ptr);
public:
    Const(const Const<TBlock>& cpy);
    Const(Const<TBlock>&& mov);
public:
    ~Const();
public:
    Const<TBlock>& operator=(const Const<TBlock>& cpy);
    Const<TBlock>& operator=(Const<TBlock>&& mov);
public:
    void* operator new (std::size_t) = delete;
    void* operator new[] (std::size_t) = delete;
    void operator delete(void*) = delete;
    void operator delete[](void*) = delete;
private:
    void Validation();
private:
    void Reset();
protected:
    void * Get();
    void * Get() const;
protected:
    BlockType* GetBlock();
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
    IDType ID();
    IDType ID() const;
public:
    template<typename T>
    CastConstType<T> Cast();
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
    bool operator==(void * ptr) const;
    bool operator==(const void * ptr) const;
    bool operator==(std::nullptr_t) const;
    bool operator==(const Const<TBlock>& other) const;
    bool operator!=(void * ptr) const;
    bool operator!=(const void * ptr) const;
    bool operator!=(std::nullptr_t) const;
    bool operator!=(const Const<TBlock>& other) const;
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

} //!test

#endif //!TEST_SYS_MEM_PTR_CONST_H_DEFN_
