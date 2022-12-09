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
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor()");

}

template<typename T, typename TBlock>
Cast<T, TBlock>::Cast(TBlock * ptr) :
    BaseType(ptr)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Constructor(ptr=%p)", ptr);

}

template<typename T, typename TBlock>
Cast<T, TBlock>::Cast(const PointerType& ptr_cpy) :
    BaseType(ptr_cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(ptr_cpy=%p)", &ptr_cpy);

}

template<typename T, typename TBlock>
Cast<T, TBlock>::Cast(PointerType&& ptr_mov) :
    BaseType(std::move(ptr_mov))
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(ptr_mov=%p)", &ptr_mov);

}

template<typename T, typename TBlock>
Cast<T, TBlock>::Cast(const Cast<T, TBlock>& cpy) :
    BaseType(cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);

}

template<typename T, typename TBlock>
Cast<T, TBlock>::Cast(Cast<T, TBlock>&& mov) :
    BaseType(std::move(mov))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);
    
}

template<typename T, typename TBlock>
Cast<T, TBlock>::~Cast()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

}

template<typename T, typename TBlock>
Cast<T, TBlock>& Cast<T, TBlock>::operator=(const Cast<T, TBlock>& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);
    
    BaseType::operator=(cpy);
    return *this;
}

template<typename T, typename TBlock>
Cast<T, TBlock>& Cast<T, TBlock>::operator=(Cast<T, TBlock>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(move=%p)", &mov);
    
    BaseType::operator=(std::move(mov));
    return *this;
}

template<typename T, typename TBlock>
T* Cast<T, TBlock>::operator[](const std::size_t& n)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator[](n=%zu)", n);
    
    const std::size_t req_size = (sizeof(T) * (n + 1));
    if (req_size > Size())
    {
        const std::size_t last_index = Size() / sizeof(T);
        SystemType::GetInstance().Error(
            DefinitionType::Status::sMemPointerIndexOutOfBounds,
            "index out of bounds");
        
        return static_cast<T*>(test::sys::mem::Dummy::Get<T>()); 
    }
    return static_cast<T*>(BaseType::Get()) + n; 
}

template<typename T, typename TBlock>
const T* Cast<T, TBlock>::operator[](const std::size_t& n) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator[](n=%zu) const", n);

    return BaseType::operator[](n);
}

template<typename T, typename TBlock>
T& Cast<T, TBlock>::operator*()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator*()");

    T& cast = const_cast<T&>(BaseType::operator*());
    return cast;
}

template<typename T, typename TBlock>
const T& Cast<T, TBlock>::operator*() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator*() const");

    return BaseType::operator*();
}

template<typename T, typename TBlock>
T* Cast<T, TBlock>::operator->()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator->()");

    T* cast = const_cast<T*>(BaseType::operator->());
    return cast;
}

template<typename T, typename TBlock>
const T* Cast<T, TBlock>::operator->() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator->() const");

    return BaseType::operator->();
}

template<typename T, typename TBlock>
bool Cast<T, TBlock>::operator==(void * ptr) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(ptr=%p) const", ptr);

    return BaseType::operator==(ptr);
}

template<typename T, typename TBlock>
bool Cast<T, TBlock>::operator==(const void * ptr) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(ptr=%p) const", ptr);

    return BaseType::operator==(ptr);
}

template<typename T, typename TBlock>
bool Cast<T, TBlock>::operator==(std::nullptr_t) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(nullptr) const");

    return BaseType::operator==(nullptr);
}

template<typename T, typename TBlock>
bool Cast<T, TBlock>::operator==(const BaseType& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", &other);

    return BaseType::operator==(other);
}

template<typename T, typename TBlock>
bool Cast<T, TBlock>::operator==(const Cast<T, TBlock>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", &other);

    return BaseType::operator==(other);
}

template<typename T, typename TBlock>
bool Cast<T, TBlock>::operator!=(void * ptr) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(ptr=%p) const", ptr);

    return BaseType::operator!=(ptr);
}

template<typename T, typename TBlock>
bool Cast<T, TBlock>::operator!=(const void * ptr) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(ptr=%p) const", ptr);

    return BaseType::operator!=(ptr);
}

template<typename T, typename TBlock>
bool Cast<T, TBlock>::operator!=(std::nullptr_t) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(nullptr) const");

    return BaseType::operator!=(nullptr);
}

template<typename T, typename TBlock>
bool Cast<T, TBlock>::operator!=(const BaseType& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", &other);

    return BaseType::operator!=(other);
}

template<typename T, typename TBlock>
bool Cast<T, TBlock>::operator!=(const Cast<T, TBlock>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", &other);

    return BaseType::operator!=(other);
}

template<typename T, typename TBlock>
template<typename TValue, typename TNull>
    typename std::enable_if<!std::is_same<TNull, void*>::value
        && std::is_same<TValue, TNull>::value, bool>::type 
Cast<T, TBlock>::operator==(const TValue& val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(val=%p) const", (const void*)val);
    
    return *this == (const void*&)val;
}

template<typename T, typename TBlock>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Cast<T, TBlock>::operator!=(const TValue& val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(val=%p) const", (const void*)val);
    
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
