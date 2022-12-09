#ifndef TEST_SYS_MEM_POINTER_H_
#define TEST_SYS_MEM_POINTER_H_

#include "Pointer.defn.h"
#include "ptr/Const.defn.h"
#include "ptr/Cast.defn.h"
#include "ptr/cast/Const.defn.h"
#include "../Debug.h"

#include <utility>

#define TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T test::sys::mem::Pointer<TBlock>

template<typename TBlock>
TEST_SYS_DBG_VALUE_PARAMETER_DEFINE("{id=%zu, size=%zu}", val.ID(), val.Size());

#undef TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T

namespace test
{
namespace sys
{
namespace mem
{

template<typename TBlock>
Pointer<TBlock>::Pointer() :
    BaseType()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

template<typename TBlock>
Pointer<TBlock>::Pointer(BlockType * ptr) :
    BaseType(ptr)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Constructor(ptr=%p)", ptr);

}

template<typename TBlock>
Pointer<TBlock>::Pointer(const PointerConstType& cpy) :
    BaseType(cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(cpy=%p)", &cpy);

}

template<typename TBlock>
Pointer<TBlock>::Pointer(PointerConstType&& mov) :
    BaseType(std::move(mov))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(mov=%p)", &mov);

}

template<typename TBlock>
Pointer<TBlock>::Pointer(const Pointer<TBlock>& cpy) :
    BaseType(cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);

}

template<typename TBlock>
Pointer<TBlock>::Pointer(Pointer<TBlock>&& mov) :
    BaseType(std::move(mov))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

}

template<typename TBlock>
Pointer<TBlock>::~Pointer()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

}

template<typename TBlock>
Pointer<TBlock>& Pointer<TBlock>::operator=(const PointerConstType& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Assignment(cpy=%p)", &cpy);

    BaseType::operator=(cpy);
    return *this;
}

template<typename TBlock>
Pointer<TBlock>& Pointer<TBlock>::operator=(PointerConstType&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Assignment(mov=%p)", &mov);

    BaseType::operator=(std::move(mov));
    return *this;
}

template<typename TBlock>
Pointer<TBlock>& Pointer<TBlock>::operator=(const Pointer<TBlock>& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);

    BaseType::operator=(cpy);
    return *this;
}

template<typename TBlock>
Pointer<TBlock>& Pointer<TBlock>::operator=(Pointer<TBlock>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);

    BaseType::operator=(std::move(mov));
    return *this;
}

template<typename TBlock>
template<typename T>
typename Pointer<TBlock>::CastType<T> 
Pointer<TBlock>::Cast()
{
    TEST_SYS_DEBUG_T(SystemType, DebugType, 3, this, "Cast<%s>()",
        TEST_SYS_DEBUG_T_NAME_STR(T));
    
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
    TEST_SYS_DEBUG_T(SystemType, DebugType, 3, this, "Cast<%s>() const",
        TEST_SYS_DEBUG_T_NAME_STR(T));
    
    return BaseType::template Cast<T>();
}

template<typename TBlock>
bool Pointer<TBlock>::operator==(void * ptr) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(ptr=%p) const", ptr);
    
    return BaseType::operator==(ptr);
}

template<typename TBlock>
bool Pointer<TBlock>::operator==(const void *ptr) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(ptr=%p) const", ptr);
    
    return BaseType::operator==(ptr);
}

template<typename TBlock>
bool Pointer<TBlock>::operator==(std::nullptr_t) const
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(nullptr) const");

    return BaseType::operator==(nullptr);
}

template<typename TBlock>
bool Pointer<TBlock>::operator==(const PointerConstType& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", &other);

    return BaseType::operator==(other);
}

template<typename TBlock>
bool Pointer<TBlock>::operator==(const Pointer<TBlock>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", &other);

    return BaseType::operator==(other);
}

template<typename TBlock>
bool Pointer<TBlock>::operator!=(void * ptr) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(ptr=%p) const", ptr);
    
    return BaseType::operator!=(ptr);
}

template<typename TBlock>
bool Pointer<TBlock>::operator!=(const void *ptr) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(ptr=%p) const", ptr);
    
    return BaseType::operator!=(ptr);
}

template<typename TBlock>
bool Pointer<TBlock>::operator!=(std::nullptr_t) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(nullptr) const");

    return BaseType::operator!=(nullptr);
}

template<typename TBlock>
bool Pointer<TBlock>::operator!=(const PointerConstType& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", &other);

    return BaseType::operator!=(other);
}

template<typename TBlock>
bool Pointer<TBlock>::operator!=(const Pointer<TBlock>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", &other);

    return BaseType::operator!=(other);
}

template<typename TBlock>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Pointer<TBlock>::operator==(const TValue& val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(val=%p) const", (const void*)val);
    
    return BaseType::operator==((const void*&)val);
}

template<typename TBlock>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Pointer<TBlock>::operator!=(const TValue& val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(val=%p) const", (const void*)val);
    
    return BaseType::operator!=((const void*&)val);
}

} //!mem

} //!sys

} //!test

#include "ptr/Const.h"
#include "ptr/Cast.h"
#include "ptr/cast/Const.h"

#endif //!TEST_SYS_MEM_POINTER_H_
