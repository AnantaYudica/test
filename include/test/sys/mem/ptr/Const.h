#ifndef TEST_SYS_MEM_PTR_CONST_H_
#define TEST_SYS_MEM_PTR_CONST_H_

#include "Const.defn.h"
#include "cast/Const.defn.h"

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
    static char instance[sizeof(BlockType)];
    memset(instance, 0, sizeof(BlockType));
    return reinterpret_cast<BlockType*>(instance);
}

template<typename TBlock>
Const<TBlock>::Const() :
    m_block(Default())
{}

template<typename TBlock>
Const<TBlock>::Const(BlockType * ptr) :
    m_block(ptr)
{
    Validation();
}

template<typename TBlock>
Const<TBlock>::Const(const Const<TBlock>& cpy) :
    m_block(cpy.m_block)
{
    Validation();
}

template<typename TBlock>
Const<TBlock>::Const(Const<TBlock>&& mov) :
    m_block(mov.m_block)
{
    mov.m_block = Default();
}

template<typename TBlock>
Const<TBlock>::~Const()
{
    Reset();
}

template<typename TBlock>
Const<TBlock>& Const<TBlock>::operator=(const Const<TBlock>& cpy)
{
    Reset();
    m_block = cpy.m_block;
    Validation();
    return *this;
}

template<typename TBlock>
Const<TBlock>& Const<TBlock>::operator=(Const<TBlock>&& mov)
{
    Reset();
    m_block = mov.m_block;
    mov.m_block = Default();
    return *this;
}

template<typename TBlock>
void Const<TBlock>::Validation()
{
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
    if (m_block != nullptr && m_block != Default())
    {
        m_block->ReleaseReference();
    }
}

template<typename TBlock>
void * Const<TBlock>::Get()
{
    return m_block->Pointer();
}

template<typename TBlock>
void * Const<TBlock>::Get() const
{
    return m_block->Pointer();
}

template<typename TBlock>
Const<TBlock>::operator bool()
{
    return m_block != nullptr && m_block != Default();
}

template<typename TBlock>
Const<TBlock>::operator bool() const
{
    return m_block != nullptr &&  m_block != Default();
}

template<typename TBlock>
std::size_t Const<TBlock>::Size()
{
    return m_block->Size();
}

template<typename TBlock>
std::size_t Const<TBlock>::Size() const
{
    return m_block->Size();
}

template<typename TBlock>
std::size_t Const<TBlock>::Count()
{
    return m_block->ReferenceCount();
}

template<typename TBlock>
std::size_t Const<TBlock>::Count() const
{
    return m_block->ReferenceCount();
}

template<typename TBlock>
typename Const<TBlock>::TimestampType 
Const<TBlock>::Timestamp()
{
    return m_block->AllocationTimestamp();
}

template<typename TBlock>
typename Const<TBlock>::TimestampType 
Const<TBlock>::Timestamp() const
{
    return m_block->AllocationTimestamp();
}

template<typename TBlock>
template<typename T>
typename Const<TBlock>::CastConstType<T> Const<TBlock>::Cast()
{
    if (sizeof(T) > Size())
    {
        if (m_block != nullptr && m_block != Default())
        {
            SystemType::GetInstance().Error(
                DefinitionType::Status::sMemRecordCastFailed,
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
    if (sizeof(T) > Size())
    {
        if (m_block != nullptr && m_block != Default())
        {
            SystemType::GetInstance().Error(
                DefinitionType::Status::sMemRecordCastFailed,
                "Cast is not enough size");
        }
        return {};
    }
    return CastConstType<T>(*this);
}

template<typename TBlock>
bool Const<TBlock>::operator==(void * ptr) const
{
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
    return operator==(const_cast<void*>(ptr));
}

template<typename TBlock>
bool Const<TBlock>::operator==(std::nullptr_t) const
{
    return m_block == Default() || !static_cast<bool>(*m_block);
}

template<typename TBlock>
bool Const<TBlock>::operator==(const Const<TBlock>& other) const
{
    return m_block == other.m_block;
}

template<typename TBlock>
bool Const<TBlock>::operator!=(void * ptr) const
{
    return !(*this == ptr);
}

template<typename TBlock>
bool Const<TBlock>::operator!=(const void * ptr) const
{
    return !(*this == ptr);
}

template<typename TBlock>
bool Const<TBlock>::operator!=(std::nullptr_t) const
{
    return !(*this == std::nullptr_t());
}

template<typename TBlock>
bool Const<TBlock>::operator!=(const Const<TBlock>& other) const
{
    return !(*this == other);
}

template<typename TBlock>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Const<TBlock>::operator==(const TValue& val) const
{
    return *this == (const void*&)val;
}

template<typename TBlock>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Const<TBlock>::operator!=(const TValue& val) const
{
    return *this != (const void*&)val;
}

} //!ptr

} //!mem

} //!sys

} //test


#include "cast/Const.h"


#endif //!TEST_SYS_MEM_PTR_CONST_H_
