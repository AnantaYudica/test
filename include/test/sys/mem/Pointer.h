#ifndef TEST_SYS_MEM_POINTER_H_
#define TEST_SYS_MEM_POINTER_H_

#include "Pointer.defn.h"
#include "ptr/Const.defn.h"
#include "ptr/Cast.defn.h"
#include "ptr/cast/Const.defn.h"

#include <utility>

namespace test
{
namespace sys
{
namespace mem
{

template<typename TBlock>
Pointer<TBlock>::Pointer() :
    BaseType()
{}

template<typename TBlock>
Pointer<TBlock>::Pointer(BlockType * ptr) :
    BaseType(ptr)
{}

template<typename TBlock>
Pointer<TBlock>::Pointer(const PointerConstType& cpy) :
    BaseType(cpy)
{}

template<typename TBlock>
Pointer<TBlock>::Pointer(PointerConstType&& mov) :
    BaseType(std::move(mov))
{}

template<typename TBlock>
Pointer<TBlock>::Pointer(const Pointer<TBlock>& cpy) :
    BaseType(cpy)
{}

template<typename TBlock>
Pointer<TBlock>::Pointer(Pointer<TBlock>&& mov) :
    BaseType(std::move(mov))
{}

template<typename TBlock>
Pointer<TBlock>::~Pointer()
{}

template<typename TBlock>
Pointer<TBlock>& Pointer<TBlock>::operator=(const PointerConstType& cpy)
{
    BaseType::operator=(cpy);
    return *this;
}

template<typename TBlock>
Pointer<TBlock>& Pointer<TBlock>::operator=(PointerConstType&& mov)
{
    BaseType::operator=(std::move(mov));
    return *this;
}

template<typename TBlock>
Pointer<TBlock>& Pointer<TBlock>::operator=(const Pointer<TBlock>& cpy)
{
    BaseType::operator=(cpy);
    return *this;
}

template<typename TBlock>
Pointer<TBlock>& Pointer<TBlock>::operator=(Pointer<TBlock>&& mov)
{
    BaseType::operator=(std::move(mov));
    return *this;
}

template<typename TBlock>
template<typename T>
typename Pointer<TBlock>::CastType<T> 
Pointer<TBlock>::Cast()
{
    if (sizeof(T) > Size())
    {
        if ((bool)(*this))
        {
            SystemType::GetInstance().Error(
                DefinitionType::Status::sMemPointerCastFailed,
                "Cast is not enough size");
        }
        return {};
    }
    return CastType<T>(*this);
}

template<typename TBlock>
template<typename T>
typename Pointer<TBlock>::CastConstType<T> 
Pointer<TBlock>::Cast() const
{
    return BaseType::template Cast<T>();
}

template<typename TBlock>
bool Pointer<TBlock>::operator==(void * ptr) const
{
    return BaseType::operator==(ptr);
}

template<typename TBlock>
bool Pointer<TBlock>::operator==(const void *ptr) const
{
    return BaseType::operator==(ptr);
}

template<typename TBlock>
bool Pointer<TBlock>::operator==(std::nullptr_t) const
{
    return BaseType::operator==(nullptr);
}

template<typename TBlock>
bool Pointer<TBlock>::operator==(const PointerConstType& other) const
{
    return BaseType::operator==(other);
}

template<typename TBlock>
bool Pointer<TBlock>::operator==(const Pointer<TBlock>& other) const
{
    return BaseType::operator==(other);
}

template<typename TBlock>
bool Pointer<TBlock>::operator!=(void * ptr) const
{
    return BaseType::operator!=(ptr);
}

template<typename TBlock>
bool Pointer<TBlock>::operator!=(const void *ptr) const
{
    return BaseType::operator!=(ptr);
}

template<typename TBlock>
bool Pointer<TBlock>::operator!=(std::nullptr_t) const
{
    return BaseType::operator!=(nullptr);
}

template<typename TBlock>
bool Pointer<TBlock>::operator!=(const PointerConstType& other) const
{
    return BaseType::operator!=(other);
}

template<typename TBlock>
bool Pointer<TBlock>::operator!=(const Pointer<TBlock>& other) const
{
    return BaseType::operator!=(other);
}

template<typename TBlock>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Pointer<TBlock>::operator==(const TValue& val) const
{
    return BaseType::operator==((const void*&)val);
}

template<typename TBlock>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Pointer<TBlock>::operator!=(const TValue& val) const
{
    return BaseType::operator!=((const void*&)val);
}

} //!mem

} //!sys

} //!test

#include "ptr/Const.h"
#include "ptr/Cast.h"
#include "ptr/cast/Const.h"

#endif //!TEST_SYS_MEM_POINTER_H_
