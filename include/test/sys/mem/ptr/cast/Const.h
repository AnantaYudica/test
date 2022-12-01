#ifndef TEST_SYS_MEM_PTR_CONST_CAST_H_
#define TEST_SYS_MEM_PTR_CONST_CAST_H_

#include "Const.defn.h"
#include "../../Pointer.defn.h"
#include "../Const.defn.h"
#include "../../Dummy.h"

#include <utility>

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
Const<T, TBlock>::Const() :
    BaseType()
{}

template<typename T, typename TBlock>
Const<T, TBlock>::Const(TBlock * ptr) :
    BaseType(ptr)
{}

template<typename T, typename TBlock>
Const<T, TBlock>::Const(const PointerType& ptr_cpy) :
    BaseType(ptr_cpy)
{}

template<typename T, typename TBlock>
Const<T, TBlock>::Const(PointerType&& ptr_mov) :
    BaseType(std::move(ptr_mov))
{}

template<typename T, typename TBlock>
Const<T, TBlock>::Const(const PointerConstType& ptr_const_cpy) :
    BaseType(ptr_const_cpy)
{}

template<typename T, typename TBlock>
Const<T, TBlock>::Const(PointerConstType&& ptr_const_mov) :
    BaseType(std::move(ptr_const_mov))
{}

template<typename T, typename TBlock>
Const<T, TBlock>::Const(const Const<T, TBlock>& cpy) :
    BaseType(cpy)
{}

template<typename T, typename TBlock>
Const<T, TBlock>::Const(Const<T, TBlock>&& mov) :
    BaseType(std::move(mov))
{}

template<typename T, typename TBlock>
Const<T, TBlock>::~Const()
{}

template<typename T, typename TBlock>
Const<T, TBlock>& 
Const<T, TBlock>::operator=(const Const<T, TBlock>& cpy)
{
    BaseType::operator=(cpy);
    return *this;
}

template<typename T, typename TBlock>
Const<T, TBlock>& Const<T, TBlock>::operator=(Const<T, TBlock>&& mov)
{
    BaseType::operator=(std::move(mov));
    return *this;
}

template<typename T, typename TBlock>
Const<T, TBlock>::operator bool()
{
    return BaseType::operator bool();
}

template<typename T, typename TBlock>
Const<T, TBlock>::operator bool() const
{
    return BaseType::operator bool();
}

template<typename T, typename TBlock>
std::size_t Const<T, TBlock>::Size()
{
    return BaseType::Size();
}

template<typename T, typename TBlock>
std::size_t Const<T, TBlock>::Size() const
{
    return BaseType::Size();
}

template<typename T, typename TBlock>
std::size_t Const<T, TBlock>::Count()
{
    return BaseType::Count();
}

template<typename T, typename TBlock>
std::size_t Const<T, TBlock>::Count() const
{
    return BaseType::Count();
}

template<typename T, typename TBlock>
typename Const<T, TBlock>::TimestampType 
Const<T, TBlock>::Timestamp()
{
    return BaseType::Timestamp();
}

template<typename T, typename TBlock>
typename Const<T, TBlock>::TimestampType 
Const<T, TBlock>::Timestamp() const
{
    return BaseType::Timestamp();
}

template<typename T, typename TBlock>
const T* Const<T, TBlock>::operator[](const std::size_t& n)
{
    const std::size_t req_size = (sizeof(T) * (n + 1));
    if (req_size > Size())
    {
        const std::size_t last_index = Size() / sizeof(T);
        SystemType::GetInstance().Error(
            DefinitionType::Status::sMemPointerIndexOutOfBounds,
            "index out of bounds");
        
        return static_cast<const T*>(test::sys::mem::Dummy::Get<T>()); 
    }
    return static_cast<const T*>(BaseType::Get()) + n; 
}

template<typename T, typename TBlock>
const T* Const<T, TBlock>::operator[](const std::size_t& n) const
{
    Const<T, TBlock>* cast = const_cast<Const<T, TBlock>*>(this);
    return cast->operator[](n);
}

template<typename T, typename TBlock>
const T& Const<T, TBlock>::operator*()
{
    return *(static_cast<const T*>(BaseType::Get()));
}

template<typename T, typename TBlock>
const T& Const<T, TBlock>::operator*() const
{
    return *(static_cast<const T*>(BaseType::Get()));
}

template<typename T, typename TBlock>
const T* Const<T, TBlock>::operator->()
{
    return static_cast<const T*>(BaseType::Get());
}

template<typename T, typename TBlock>
const T* Const<T, TBlock>::operator->() const
{
    return static_cast<const T*>(BaseType::Get());
}

template<typename T, typename TBlock>
bool Const<T, TBlock>::operator==(void * ptr) const
{
    return BaseType::operator==(ptr);
}

template<typename T, typename TBlock>
bool Const<T, TBlock>::operator==(const void * ptr) const
{
    return BaseType::operator==(ptr);
}

template<typename T, typename TBlock>
bool Const<T, TBlock>::operator==(std::nullptr_t) const
{
    return BaseType::operator==(nullptr);
}

template<typename T, typename TBlock>
bool Const<T, TBlock>::operator==(const Const<T, TBlock>& other) const
{
    return BaseType::operator==(other);
}

template<typename T, typename TBlock>
bool Const<T, TBlock>::operator!=(void * ptr) const
{
    return BaseType::operator!=(ptr);
}

template<typename T, typename TBlock>
bool Const<T, TBlock>::operator!=(const void * ptr) const
{
    return BaseType::operator!=(ptr);
}

template<typename T, typename TBlock>
bool Const<T, TBlock>::operator!=(std::nullptr_t) const
{
    return BaseType::operator!=(nullptr);
}

template<typename T, typename TBlock>
bool Const<T, TBlock>::operator!=(const Const<T, TBlock>& other) const
{
    return BaseType::operator!=(other);
}

template<typename T, typename TBlock>
template<typename TValue, typename TNull>
    typename std::enable_if<!std::is_same<TNull, void*>::value
        && std::is_same<TValue, TNull>::value, bool>::type 
Const<T, TBlock>::operator==(const TValue& val) const
{
    return *this == (const void*&)val;
}
            
template<typename T, typename TBlock>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Const<T, TBlock>::operator!=(const TValue& val) const
{
    return *this != (const void*&)val;
}

} //!cast

} //!ptr

} //!mem

} //!sys

} //!test

#include "../../Pointer.h"
#include "../Const.h"

#endif //!TEST_SYS_MEM_PTR_CONST_CAST_H_
