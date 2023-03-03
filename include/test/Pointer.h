#ifndef TEST_POINTER_H_
#define TEST_POINTER_H_

#include "System.h"
#include "trait/ptr/defn/IsBaseOf.h"
#include "ptr/Base.h"
#include "ptr/Definition.h"
#include "ptr/Flag.h"
#include "ptr/arg/Array.h"
#include "ptr/arg/Foreach.h"
#include "ptr/Iterator.h"

#include <type_traits>
#include <utility>
#include <cstdint>
#include <cstddef>

namespace test
{
template<typename T, typename TDefinition>
class Pointer;
}

#ifndef TEST_POINTER_DLEVEL

#define TEST_POINTER_DLEVEL 2

#endif //!TEST_POINTER_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>,\
    test::sys::dbg::Type<TDefinition>

template<typename T, typename TDefinition>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_POINTER_DLEVEL, 
    "test::Pointer", 
    test::Pointer<T, TDefinition>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{

template<typename T, typename TDefinition = test::ptr::Definition<T>>
class Pointer : public test::ptr::Base
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::Pointer<T, TDefinition>> DebugType;
public:
    static_assert(test::trait::ptr::defn::IsBaseOf<TDefinition>::Value,
        "T is base of test::ptr::Definition<...>");
public:
    typedef TDefinition DefinitionType;
    typedef test::ptr::Base BaseType;
    typedef T ValueType;
    typedef std::size_t IntegerCountType;
    typedef std::atomic<IntegerCountType> CountType;
private:
    typedef test::ptr::Flag FlagType;
    typedef test::ptr::FlagIntegerType FlagIntegerType;
private:
    std::size_t m_step;
public:
    Pointer();
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_pointer<
            typename std::remove_reference<TArg>::type>::type>::type, 
        typename std::enable_if<
            !std::is_base_of<Pointer<T, TDefinition>, _TArg>::value &&
            !std::is_base_of<test::ptr::Base, _TArg>::value &&
            !std::is_base_of<test::ptr::arg::Array, _TArg>::value &&
            !std::is_same<std::nullptr_t, _TArg>::value, int>::type = 0>
    Pointer(TArg&& arg, TArgs&&... args);
    Pointer(std::nullptr_t);
    Pointer(test::ptr::arg::Array&& array);
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_pointer<
            typename std::remove_reference<TArg>::type>::type>::type,
        typename std::enable_if<!std::is_base_of<test::ptr::arg::Foreach, 
            _TArg>::value, int>::type = 0>
    Pointer(test::ptr::arg::Array&& array, TArg&& arg, TArgs&&... args);
    template<typename... TArgs>
    Pointer(test::ptr::arg::Array&& array, test::ptr::arg::Foreach&& foreach, 
        TArgs&&... args);
public:
    explicit Pointer(const BaseType& base, const std::size_t& step);
public:
    ~Pointer();
public:
    Pointer(const Pointer<T, TDefinition>& cpy);
    Pointer(Pointer<T, TDefinition>&& mov);
public:
    Pointer<T, TDefinition>& operator=(const Pointer<T, TDefinition>& cpy);
    Pointer<T, TDefinition>& operator=(Pointer<T, TDefinition>&& mov);
public:
    template<typename T_To, typename T_ToDefinition = TDefinition,
        typename std::enable_if<std::is_same<
            decltype(const_cast<T_To*>(std::declval<T*>())), T_To*>::value,
            int>::type = 0>
    Pointer<T_To, T_ToDefinition> ConstCast();
    template<typename T_To, typename T_ToDefinition = TDefinition,
        typename std::enable_if<std::is_same<
            decltype(dynamic_cast<T_To*>(std::declval<T*>())), T_To*>::value,
            int>::type = 0>
    Pointer<T_To, T_ToDefinition> DynamicCast();
    template<typename T_To, typename T_ToDefinition = TDefinition,
        typename std::enable_if<std::is_same<
            decltype(reinterpret_cast<T_To*>(std::declval<T*>())), 
            T_To*>::value, int>::type = 0>
    Pointer<T_To, T_ToDefinition> ReinterpretCast();
    template<typename T_To, typename T_ToDefinition = TDefinition,
        typename std::enable_if<std::is_same<
            decltype(static_cast<T_To*>(std::declval<T*>())), T_To*>::value,
            int>::type = 0>
    Pointer<T_To, T_ToDefinition> StaticCast();
public:
    std::size_t StepSize() const;
    std::size_t AllocationSize() const;
    std::size_t Size() const;
public:
    std::size_t Offset() const;
public:
    std::size_t Index() const;
    void SetIndex(const std::size_t& set);
public:
    test::ptr::Iterator<Pointer, T, TDefinition> Begin() const;
    test::ptr::Iterator<Pointer, T, TDefinition> End() const;
public:
    Pointer<T, TDefinition>& operator+=(const std::size_t& index);
    Pointer<T, TDefinition>& operator-=(const std::size_t& index);
public:
    T& operator*();
    const T& operator*() const;
public:
    T* operator->();
public:
    T& operator[](const std::size_t& index);
    const T& operator[](const std::size_t& index) const;
public:
    Pointer<T, TDefinition>& operator++();
    Pointer<T, TDefinition> operator++(int);
public:
    Pointer<T, TDefinition>& operator--();
    Pointer<T, TDefinition> operator--(int);
public:
    Pointer<T, TDefinition> operator+(const std::size_t& index);
    Pointer<T, TDefinition> operator-(const std::size_t& index);
    Pointer<T, TDefinition> operator+(const int& index);
    Pointer<T, TDefinition> operator-(const int& index);
public:
    void* GetData();
    void* GetData() const;
public:
    template<typename TOther, typename TOtherDefinition>
    bool operator==(const Pointer<TOther, TOtherDefinition>& other) const;
    template<typename TOther, typename TOtherDefinition>
    bool operator!=(const Pointer<TOther, TOtherDefinition>& other) const;
    bool operator==(std::nullptr_t other) const;
    bool operator!=(std::nullptr_t other) const;
    bool operator==(void * other) const;
    bool operator!=(void * other) const;
};

template<typename T, typename TDefinition>
Pointer<T, TDefinition>::Pointer() :
    BaseType(),
    m_step(sizeof(typename TDefinition::ValueType))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

    auto defn = new TDefinition();
    void* data = BaseType::Allocation(FlagType::default_initialization, 
        m_step, 1, defn);
    defn->Constructor(data);
}

template<typename T, typename TDefinition>
template<typename TArg, typename... TArgs, typename _TArg, 
    typename std::enable_if<
        !std::is_base_of<Pointer<T, TDefinition>, _TArg>::value &&
        !std::is_base_of<test::ptr::Base, _TArg>::value &&
        !std::is_base_of<test::ptr::arg::Array, _TArg>::value &&
        !std::is_same<std::nullptr_t, _TArg>::value, int>::type>
Pointer<T, TDefinition>::Pointer(TArg&& arg, TArgs&&... args) :
    BaseType(),
    m_step(sizeof(typename TDefinition::ValueType))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor<%s>(args={%s})",
        TEST_SYS_DEBUG_TARGS_NAME_STR(TArg, TArgs...),
        TEST_SYS_DEBUG_TARGS_VALUE_STR(arg, args...));

    auto defn = new TDefinition();
    void* data = BaseType::Allocation(FlagType::value_initialization, m_step,
        1, defn);
    defn->Constructor(data, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename T, typename TDefinition>
Pointer<T, TDefinition>::Pointer(std::nullptr_t) :
    BaseType(),
    m_step(sizeof(typename TDefinition::ValueType))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(nullptr)");
    
}

template<typename T, typename TDefinition>
Pointer<T, TDefinition>::Pointer(test::ptr::arg::Array&& array) :
    BaseType(),
    m_step(sizeof(typename TDefinition::ValueType))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(array=%p)", &array);

    auto defn = new TDefinition();
    const auto size = array.GetSize();
    void* data = BaseType::Allocation(FlagType::array_allocation, m_step, 
        size == 0 ? 1 : size, defn);
    defn->Constructor(array, data);
}

template<typename T, typename TDefinition>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_base_of<test::ptr::arg::Foreach, 
        _TArg>::value, int>::type>
Pointer<T, TDefinition>::Pointer(test::ptr::arg::Array&& array, 
    TArg&& arg, TArgs&&... args) :
        BaseType(),
        m_step(sizeof(typename TDefinition::ValueType))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor<%s>(array=%p, args={%s})", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TArg, TArgs...), &array,
        TEST_SYS_DEBUG_TARGS_VALUE_STR(arg, args...));

    auto defn = new TDefinition();
    const auto size = array.GetSize();
    void* data = BaseType::Allocation(FlagType::array_allocation, m_step, 
        size == 0 ? 1 : size, defn);
    defn->Constructor(array, data, std::forward<TArg>(arg),
        std::forward<TArgs>(args)...);
}

template<typename T, typename TDefinition>
template<typename... TArgs>
Pointer<T, TDefinition>::Pointer(test::ptr::arg::Array&& array, 
    test::ptr::arg::Foreach&& foreach, TArgs&&... args) :
        BaseType(),
        m_step(sizeof(typename TDefinition::ValueType))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor<%s>(array=%p, foreach=%p, args={%s})", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TArgs...),
        &array, &foreach,
        TEST_SYS_DEBUG_TARGS_VALUE_STR(args...));

    auto defn = new TDefinition();
    const auto size = array.GetSize();
    void* data = BaseType::Allocation(FlagType::array_allocation, m_step, 
        size == 0 ? 1 : size, defn);
    defn->Constructor(array, std::forward<test::ptr::arg::Foreach>(foreach), 
        data, std::forward<TArgs>(args)...);
}

template<typename T, typename TDefinition>
Pointer<T, TDefinition>::Pointer(const BaseType& base, 
    const std::size_t& step) :
        BaseType(base),
        m_step(step)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(base=%p, step=%zu)", &base, step);

}

template<typename T, typename TDefinition>
Pointer<T, TDefinition>::~Pointer()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

    BaseType::Deallocation();
    m_step = 0;
}

template<typename T, typename TDefinition>
Pointer<T, TDefinition>::Pointer(const Pointer<T, TDefinition>& cpy) :
    BaseType(cpy),
    m_step(cpy.m_step)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);

}

template<typename T, typename TDefinition>
Pointer<T, TDefinition>::Pointer(Pointer<T, TDefinition>&& mov) :
    BaseType(std::move(mov)),
    m_step(mov.m_step)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

    auto defn = new TDefinition();
    mov.m_step = sizeof(typename TDefinition::ValueType);
    void * data = mov.BaseType::Allocation(FlagType::default_initialization, 
        mov.m_step, 1, defn);
    defn->Constructor(data);
}

template<typename T, typename TDefinition>
Pointer<T, TDefinition>& 
Pointer<T, TDefinition>::operator=(const Pointer<T, TDefinition>& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);

    BaseType::operator=(cpy);
    m_step = cpy.m_step;
    return *this;
}

template<typename T, typename TDefinition>
Pointer<T, TDefinition>& 
Pointer<T, TDefinition>::operator=(Pointer<T, TDefinition>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(cpy=%p)", &mov);

    BaseType::operator=(std::move(mov));
    m_step = mov.m_step;
    auto defn = new TDefinition();
    mov.m_step = sizeof(typename TDefinition::ValueType);
    void * data = mov.BaseType::Allocation(FlagType::default_initialization, 
        mov.m_step, 1, defn);
    defn->Constructor(data);
    return *this;
}

template<typename T, typename TDefinition>
template<typename T_To, typename T_ToDefinition,
    typename std::enable_if<std::is_same<
        decltype(const_cast<T_To*>(std::declval<T*>())), T_To*>::value,
        int>::type>
Pointer<T_To, T_ToDefinition> Pointer<T, TDefinition>::ConstCast()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "ConstCast<%s>()", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(T_To, T_ToDefinition));

    Pointer<T_To, T_ToDefinition> ret{(BaseType&)*this, m_step};
    return ret;
}

template<typename T, typename TDefinition>
template<typename T_To, typename T_ToDefinition,
    typename std::enable_if<std::is_same<
        decltype(dynamic_cast<T_To*>(std::declval<T*>())), T_To*>::value,
        int>::type>
Pointer<T_To, T_ToDefinition> Pointer<T, TDefinition>::DynamicCast()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "DynamicCast<%s>()", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(T_To, T_ToDefinition));

    T_To* ptr = dynamic_cast<T_To*>(BaseType::Get<T>());
    if (ptr == nullptr)
    {
        Pointer<T_To, T_ToDefinition> ret;
        return ret;
    }
    Pointer<T_To, T_ToDefinition> ret{(BaseType&)*this, m_step};
    return ret;
}

template<typename T, typename TDefinition>
template<typename T_To, typename T_ToDefinition,
    typename std::enable_if<std::is_same<
        decltype(reinterpret_cast<T_To*>(std::declval<T*>())), T_To*>::value,
        int>::type>
Pointer<T_To, T_ToDefinition> Pointer<T, TDefinition>::ReinterpretCast()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "ReinterpretCast<%s>()", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(T_To, T_ToDefinition));

    Pointer<T_To, T_ToDefinition> ret{(BaseType&)*this, sizeof(T_To)};
    return ret;
}

template<typename T, typename TDefinition>
template<typename T_To, typename T_ToDefinition,
    typename std::enable_if<std::is_same<
        decltype(static_cast<T_To*>(std::declval<T*>())), T_To*>::value,
        int>::type>
Pointer<T_To, T_ToDefinition> Pointer<T, TDefinition>::StaticCast()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "StaticCast<%s>()", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(T_To, T_ToDefinition));

    Pointer<T_To, T_ToDefinition> ret{(BaseType&)*this, m_step};
    return ret;
}

template<typename T, typename TDefinition>
std::size_t Pointer<T, TDefinition>::StepSize() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "StepSize()");

    return m_step;
}

template<typename T, typename TDefinition>
std::size_t Pointer<T, TDefinition>::AllocationSize() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "AllocationSize()");

    return BaseType::GetDataSize();
}

template<typename T, typename TDefinition>
std::size_t Pointer<T, TDefinition>::Size() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Size()");

    return BaseType::GetDataSize() / m_step;
}

template<typename T, typename TDefinition>
std::size_t Pointer<T, TDefinition>::Offset() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Offset()");

    return BaseType::GetOffset();
}

template<typename T, typename TDefinition>
std::size_t Pointer<T, TDefinition>::Index() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Index()");

    return BaseType::GetOffset() / m_step;
}

template<typename T, typename TDefinition>
void Pointer<T, TDefinition>::SetIndex(const std::size_t& set)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "SetIndex(set=%zu)", set);

    BaseType::SetOffset(set * m_step);
}

template<typename T, typename TDefinition>
test::ptr::Iterator<Pointer, T, TDefinition> 
    Pointer<T, TDefinition>::Begin() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Begin() const");

    const std::size_t index = Index();
    return {*this, index, Size(), index};
}

template<typename T, typename TDefinition>
test::ptr::Iterator<Pointer, T, TDefinition> 
    Pointer<T, TDefinition>::End() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "End() const");

    const std::size_t size = Size();
    return {*this, Index(), size, size};
}

template<typename T, typename TDefinition>
Pointer<T, TDefinition>& 
Pointer<T, TDefinition>::operator+=(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+=(index=%zu)", index);

    BaseType::operator+=(index * m_step);
    return *this;
}

template<typename T, typename TDefinition>
Pointer<T, TDefinition>& 
Pointer<T, TDefinition>::operator-=(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-=(index=%zu)", index);

    BaseType::operator-=(index * m_step);
    return *this;
}

template<typename T, typename TDefinition>
T& Pointer<T, TDefinition>::operator*()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator*()");

    return *(BaseType::Get<T>());
}

template<typename T, typename TDefinition>
const T& Pointer<T, TDefinition>::operator*() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator*() const");

    return *(const_cast<Pointer<T, TDefinition>*>(this)->BaseType::Get<T>());
}

template<typename T, typename TDefinition>
T* Pointer<T, TDefinition>::operator->()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator->()");

    return BaseType::Get<T>();
}

template<typename T, typename TDefinition>
T& Pointer<T, TDefinition>::operator[](const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator[](index=%zu)", index);

    Pointer<T, TDefinition> ret{*this};
    ret.SetIndex(index);
    return *(ret.Get<T>());
}

template<typename T, typename TDefinition>
const T& Pointer<T, TDefinition>::operator[](const std::size_t& index) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator[](index=%zu) const", index);

    Pointer<T, TDefinition> ret{*this};
    ret.SetIndex(index);
    return *(ret.Get<T>());
}

template<typename T, typename TDefinition>
Pointer<T, TDefinition>& Pointer<T, TDefinition>::operator++()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++()");

    BaseType::operator+=(m_step);
    return *this;
}

template<typename T, typename TDefinition>
Pointer<T, TDefinition> Pointer<T, TDefinition>::operator++(int)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++(int)");

    Pointer<T, TDefinition> ret{*this};
    BaseType::operator+=(m_step);
    return ret;
}

template<typename T, typename TDefinition>
Pointer<T, TDefinition>& Pointer<T, TDefinition>::operator--()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--()");

    BaseType::operator-=(m_step);
    return *this;
}

template<typename T, typename TDefinition>
Pointer<T, TDefinition> Pointer<T, TDefinition>::operator--(int)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--(int)");

    Pointer<T, TDefinition> ret{*this};
    BaseType::operator-=(m_step);
    return ret;
}

template<typename T, typename TDefinition>
Pointer<T, TDefinition> Pointer<T, TDefinition>::
    operator+(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+(index=%zu)", index);

    Pointer<T, TDefinition> ret{*this};
    ret += index;
    return ret;
}

template<typename T, typename TDefinition>
Pointer<T, TDefinition> Pointer<T, TDefinition>::
    operator-(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-(index=%zu)", index);

    Pointer<T, TDefinition> ret{*this};
    ret -= index;
    return ret;
}

template<typename T, typename TDefinition>
Pointer<T, TDefinition> Pointer<T, TDefinition>::operator+(const int& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+(index=%d)", index);

    if (index >= 0)
        return (*this + std::size_t(index));
    return (*this - std::size_t(-index));
}
    
template<typename T, typename TDefinition>
Pointer<T, TDefinition> Pointer<T, TDefinition>::operator-(const int& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-(index=%d)", index);

    if (index >= 0)
        return (*this - std::size_t(index));
    return (*this + std::size_t(-index));
}

template<typename T, typename TDefinition>
void* Pointer<T, TDefinition>::GetData()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetData()");

    return BaseType::GetData();
}

template<typename T, typename TDefinition>
void* Pointer<T, TDefinition>::GetData() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetData() const");

    auto* _this = const_cast<Pointer<T, TDefinition>*>(this);
    return _this->BaseType::GetData();
}

template<typename T, typename TDefinition>
template<typename TOther, typename TOtherDefinition>
bool Pointer<T, TDefinition>::
    operator==(const Pointer<TOther, TOtherDefinition>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==<%s>(other=%p) const", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TOther, TOtherDefinition),
        &other);

    return this->BaseType::operator==(other);
}

template<typename T, typename TDefinition>
template<typename TOther, typename TOtherDefinition>
bool Pointer<T, TDefinition>::
    operator!=(const Pointer<TOther, TOtherDefinition>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=<%s>(other=%p) const", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TOther, TOtherDefinition),
        &other);
    
    return this->BaseType::operator!=(other);
}

template<typename T, typename TDefinition>
bool Pointer<T, TDefinition>::operator==(std::nullptr_t other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(nullptr) const");

    return BaseType::GetCount() == 0;
}

template<typename T, typename TDefinition>
bool Pointer<T, TDefinition>::operator!=(std::nullptr_t other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(nullptr) const");

    return BaseType::GetCount() != 0;
}

template<typename T, typename TDefinition>
bool Pointer<T, TDefinition>::operator==(void * other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", other);

    return this->BaseType::operator==(other);
}

template<typename T, typename TDefinition>
bool Pointer<T, TDefinition>::operator!=(void * other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", other);

    return this->BaseType::operator!=(other);
}

} //!test

#endif //!TEST_POINTER_H_
