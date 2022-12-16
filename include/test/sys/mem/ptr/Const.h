#ifndef TEST_SYS_MEM_PTR_CONST_H_
#define TEST_SYS_MEM_PTR_CONST_H_

#include "Const.defn.h"
#include "cast/Const.defn.h"

#ifndef TEST_SYS_MEMORY_H_
#define TEST_SYS_MEMORY_H_IMPL_LATER
#endif //!TEST_SYS_MEMORY_H_

#include "../../Memory.h"

#include <cstring>

namespace test
{
namespace sys
{
namespace mem
{
namespace ptr
{

template<typename TBlock>
typename Const<TBlock>::BlockType* Const<TBlock>::Default()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, "Default()");

    static char instance[sizeof(BlockType)];
    memset(instance, 0, sizeof(BlockType));
    return reinterpret_cast<BlockType*>(instance);
}

template<typename TBlock>
Const<TBlock>::Const() :
    m_block(Default())
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

template<typename TBlock>
Const<TBlock>::Const(BlockType * ptr) :
    m_block(ptr)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(ptr=%p)", ptr);

    Validation();
}

template<typename TBlock>
Const<TBlock>::Const(const Const<TBlock>& cpy) :
    m_block(cpy.m_block)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);
    
    Validation();
}

template<typename TBlock>
Const<TBlock>::Const(Const<TBlock>&& mov) :
    m_block(mov.m_block)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);
    
    mov.m_block = Default();
}

template<typename TBlock>
Const<TBlock>::~Const()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

    Reset();
}

template<typename TBlock>
Const<TBlock>& Const<TBlock>::operator=(const Const<TBlock>& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);

    Reset();
    m_block = cpy.m_block;
    Validation();
    return *this;
}

template<typename TBlock>
Const<TBlock>& Const<TBlock>::operator=(Const<TBlock>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);
    
    Reset();
    m_block = mov.m_block;
    mov.m_block = Default();
    return *this;
}

template<typename TBlock>
void Const<TBlock>::Validation()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "Validation()");

    if (m_block != nullptr && m_block != Default() && 
        static_cast<bool>(*m_block))
    {
        m_block->AddReference();
    }
    else
    {
        m_block = Default();
    }
}

template<typename TBlock>
void Const<TBlock>::Reset()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "Reset()");

    if (m_block != nullptr && m_block != Default())
    {   
        m_block->ReleaseReference();
        
        TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "ReferenceCount = %zu",
            m_block->ReferenceCount());
        if (m_block->ReferenceCount() == 1)
        {
            test::sys::Memory::GetInstance().Free(m_block->Pointer());
        }
    }
}

template<typename TBlock>
void * Const<TBlock>::Get()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Get()");

    return m_block->Pointer();
}

template<typename TBlock>
void * Const<TBlock>::Get() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Get() const");

    return m_block->Pointer();
}

template<typename TBlock>
typename Const<TBlock>::BlockType* Const<TBlock>::GetBlock()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetBlock()");

    return m_block;
}

template<typename TBlock>
Const<TBlock>::operator bool()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator bool()");

    return m_block != nullptr && m_block != Default();
}

template<typename TBlock>
Const<TBlock>::operator bool() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator bool() const");
    
    return m_block != nullptr &&  m_block != Default();
}

template<typename TBlock>
std::size_t Const<TBlock>::Size()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Size()");
    
    return m_block->Size();
}

template<typename TBlock>
std::size_t Const<TBlock>::Size() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Size() const");
    
    return m_block->Size();
}

template<typename TBlock>
std::size_t Const<TBlock>::Count()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Count()");
    
    return m_block->ReferenceCount();
}

template<typename TBlock>
std::size_t Const<TBlock>::Count() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Count() const");
    
    return m_block->ReferenceCount();
}

template<typename TBlock>
typename Const<TBlock>::TimestampType 
Const<TBlock>::Timestamp()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Timestamp()");
    
    return m_block->AllocationTimestamp();
}

template<typename TBlock>
typename Const<TBlock>::TimestampType 
Const<TBlock>::Timestamp() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Timestamp() const");
    
    return m_block->AllocationTimestamp();
}

template<typename TBlock>
typename Const<TBlock>::IDType Const<TBlock>::ID()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "ID()");

    return m_block->ID();
}

template<typename TBlock>
typename Const<TBlock>::IDType Const<TBlock>::ID() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "ID() const");
    
    return m_block->ID();
}

template<typename TBlock>
template<typename T>
typename Const<TBlock>::CastConstType<T> Const<TBlock>::Cast()
{
    TEST_SYS_DEBUG_T(SystemType, DebugType, 3, this, "Cast<%s>()",
        TEST_SYS_DEBUG_T_NAME_STR(T));
    
    if (sizeof(T) > Size())
    {
        if (m_block != nullptr && m_block != Default())
        {
            SystemType::GetInstance().Error(
                DefinitionType::Status::sMemPointerCastFailed,
                "Cast is not enough size");
        }
        return {};
    }
    return CastConstType<T>(*this);
}

template<typename TBlock>
template<typename T>
typename Const<TBlock>::CastConstType<T> Const<TBlock>::Cast() const
{
    TEST_SYS_DEBUG_T(SystemType, DebugType, 3, this, "Cast<%s>() const",
        TEST_SYS_DEBUG_T_NAME_STR(T));

    if (sizeof(T) > Size())
    {
        if (m_block != nullptr && m_block != Default())
        {
            SystemType::GetInstance().Error(
                DefinitionType::Status::sMemPointerCastFailed,
                "Cast is not enough size");
        }
        return {};
    }
    return CastConstType<T>(*this);
}

template<typename TBlock>
bool Const<TBlock>::operator<(void *ptr) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator<(ptr=%p) const", ptr);
    
    if (m_block == Default())
    {
        return (void*)NULL < ptr;
    }
    return m_block->Pointer() < ptr;
}

template<typename TBlock>
bool Const<TBlock>::operator<(const void *ptr) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator<(ptr=%p) const", ptr);
    
    return operator<(const_cast<void*>(ptr));
}

template<typename TBlock>
bool Const<TBlock>::operator<=(void *ptr) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator<=(ptr=%p) const", ptr);
    
    return operator<(ptr) || operator==(ptr);
}

template<typename TBlock>
bool Const<TBlock>::operator<=(const void *ptr) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator<=(ptr=%p) const", ptr);
    
    return operator<=(const_cast<void*>(ptr));
}

template<typename TBlock>
bool Const<TBlock>::operator>(void *ptr) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator>(ptr=%p) const", ptr);
    
    if (m_block == Default())
    {
        return (void*)NULL > ptr;
    }
    return m_block->Pointer() > ptr;
}

template<typename TBlock>
bool Const<TBlock>::operator>(const void *ptr) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator>(ptr=%p) const", ptr);
    
    return operator>(const_cast<void*>(ptr));
}

template<typename TBlock>
bool Const<TBlock>::operator>=(void *ptr) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator>=(ptr=%p) const", ptr);
    
    return operator>(ptr) || operator==(ptr);
}

template<typename TBlock>
bool Const<TBlock>::operator>=(const void *ptr) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator>=(ptr=%p) const", ptr);
    
    
    return operator>=(const_cast<void*>(ptr));
}

template<typename TBlock>
bool Const<TBlock>::operator==(void * ptr) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(ptr=%p) const", ptr);

    if (ptr == nullptr)
    {
        return m_block == Default() || !static_cast<bool>(*m_block);
    }
    else
    {
        return m_block != Default() && static_cast<bool>(*m_block) &&
            m_block->Pointer() == ptr;
    }
}

template<typename TBlock>
bool Const<TBlock>::operator==(const void * ptr) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(ptr=%p) const", ptr);

    return operator==(const_cast<void*>(ptr));
}

template<typename TBlock>
bool Const<TBlock>::operator==(std::nullptr_t) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(nullptr) const");

    return m_block == Default() || !static_cast<bool>(*m_block);
}

template<typename TBlock>
bool Const<TBlock>::operator==(const Const<TBlock>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", &other);

    return m_block == other.m_block;
}

template<typename TBlock>
bool Const<TBlock>::operator!=(void * ptr) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(ptr=%p) const", ptr);

    return !(*this == ptr);
}

template<typename TBlock>
bool Const<TBlock>::operator!=(const void * ptr) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(ptr=%p) const", ptr);

    return !(*this == ptr);
}

template<typename TBlock>
bool Const<TBlock>::operator!=(std::nullptr_t) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(nullptr) const");

    return !(*this == std::nullptr_t());
}

template<typename TBlock>
bool Const<TBlock>::operator!=(const Const<TBlock>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", &other);

    return !(*this == other);
}

template<typename TBlock>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Const<TBlock>::operator==(const TValue& val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(val=%p) const", (const void*)val);
    
    return *this == (const void*&)val;
}

template<typename TBlock>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Const<TBlock>::operator!=(const TValue& val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(val=%p) const", (const void*)val);
    
    return *this != (const void*&)val;
}

} //!ptr

} //!mem

} //!sys

} //test


#include "cast/Const.h"

#ifdef TEST_SYS_MEMORY_H_IMPL_LATER
#include "../../Memory.impl.h"
#endif //!TEST_SYS_MEMORY_H_IMPL_LATER


#endif //!TEST_SYS_MEM_PTR_CONST_H_
