#ifndef TEST_SYS_MEM_PTR_CAST_H_
#define TEST_SYS_MEM_PTR_CAST_H_

#include "Cast.defn.h"
#include "cast/Const.defn.h"
#include "Const.defn.h"
#include "../Pointer.defn.h"
#include "../Dummy.h"

#include <utility>

namespace test
{
namespace sys
{
namespace mem
{
namespace ptr
{

template<typename T, typename TBlock>
Cast<T, TBlock>::Cast() :
    BaseType()
{}

template<typename T, typename TBlock>
Cast<T, TBlock>::Cast(TBlock * ptr) :
    BaseType(ptr)
{}

template<typename T, typename TBlock>
Cast<T, TBlock>::Cast(const PointerType& ptr_cpy) :
    BaseType(ptr_cpy)
{}

template<typename T, typename TBlock>
Cast<T, TBlock>::Cast(PointerType&& ptr_mov) :
    BaseType(std::move(ptr_mov))
{}

template<typename T, typename TBlock>
Cast<T, TBlock>::Cast(const Cast<T, TBlock>& cpy) :
    BaseType(cpy)
{}

template<typename T, typename TBlock>
Cast<T, TBlock>::Cast(Cast<T, TBlock>&& mov) :
    BaseType(std::move(mov))
{}

template<typename T, typename TBlock>
Cast<T, TBlock>::~Cast()
{}

template<typename T, typename TBlock>
Cast<T, TBlock>& Cast<T, TBlock>::operator=(const Cast<T, TBlock>& cpy)
{
    BaseType::operator=(cpy);
    return *this;
}

template<typename T, typename TBlock>
Cast<T, TBlock>& Cast<T, TBlock>::operator=(Cast<T, TBlock>&& mov)
{
    BaseType::operator=(std::move(mov));
    return *this;
}

template<typename T, typename TBlock>
T* Cast<T, TBlock>::operator[](const std::size_t& n)
{
    const std::size_t req_size = (sizeof(T) * (n + 1));
    if (req_size > Size())
    {
        const std::size_t last_index = Size() / sizeof(T);
        SystemType::GetInstance().Error(
            DefinitionType::Status::sMemRecordIndexOutOfBounds,
            "index out of bounds");
        
        return static_cast<T*>(test::sys::mem::Dummy::Get<T>()); 
    }
    return static_cast<T*>(BaseType::Get()) + n; 
}

template<typename T, typename TBlock>
const T* Cast<T, TBlock>::operator[](const std::size_t& n) const
{
    return BaseType::operator[](n);
}

template<typename T, typename TBlock>
T& Cast<T, TBlock>::operator*()
{
    T& cast = const_cast<T&>(BaseType::operator*());
    return cast;
}

template<typename T, typename TBlock>
const T& Cast<T, TBlock>::operator*() const
{
    return BaseType::operator*();
}

template<typename T, typename TBlock>
T* Cast<T, TBlock>::operator->()
{
    T* cast = const_cast<T*>(BaseType::operator->());
    return cast;
}

template<typename T, typename TBlock>
const T* Cast<T, TBlock>::operator->() const
{
    return BaseType::operator->();
}

template<typename T, typename TBlock>
bool Cast<T, TBlock>::operator==(void * ptr) const
{
    return BaseType::operator==(ptr);
}

template<typename T, typename TBlock>
bool Cast<T, TBlock>::operator==(const void * ptr) const
{
    return BaseType::operator==(ptr);
}

template<typename T, typename TBlock>
bool Cast<T, TBlock>::operator==(std::nullptr_t) const
{
    return BaseType::operator==(nullptr);
}

template<typename T, typename TBlock>
bool Cast<T, TBlock>::operator==(const BaseType& other) const
{
    return BaseType::operator==(other);
}

template<typename T, typename TBlock>
bool Cast<T, TBlock>::operator==(const Cast<T, TBlock>& other) const
{
    return BaseType::operator==(other);
}

template<typename T, typename TBlock>
bool Cast<T, TBlock>::operator!=(void * ptr) const
{
    return BaseType::operator!=(ptr);
}

template<typename T, typename TBlock>
bool Cast<T, TBlock>::operator!=(const void * ptr) const
{
    return BaseType::operator!=(ptr);
}

template<typename T, typename TBlock>
bool Cast<T, TBlock>::operator!=(std::nullptr_t) const
{
    return BaseType::operator!=(nullptr);
}

template<typename T, typename TBlock>
bool Cast<T, TBlock>::operator!=(const BaseType& other) const
{
    return BaseType::operator!=(other);
}

template<typename T, typename TBlock>
bool Cast<T, TBlock>::operator!=(const Cast<T, TBlock>& other) const
{
    return BaseType::operator!=(other);
}

template<typename T, typename TBlock>
template<typename TValue, typename TNull>
    typename std::enable_if<!std::is_same<TNull, void*>::value
        && std::is_same<TValue, TNull>::value, bool>::type 
Cast<T, TBlock>::operator==(const TValue& val) const
{
    return *this == (const void*&)val;
}

template<typename T, typename TBlock>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Cast<T, TBlock>::operator!=(const TValue& val) const
{
    return *this != (const void*&)val;
}

} //!ptr

} //!mem

} //!sys

} //test

#include "Const.h"
#include "cast/Const.h"
#include "../Pointer.h"

#endif //!TEST_SYS_MEM_PTR_CAST_H_
