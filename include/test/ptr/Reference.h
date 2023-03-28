#ifndef TEST_PTR_REFERENCE_H_
#define TEST_PTR_REFERENCE_H_

#include "../System.h"
#include "../Pointer.h"

namespace test
{
namespace ptr
{

template<typename T>
class Reference;

} //!ptr

} //!test

#ifndef TEST_PTR_REFERENCE_DLEVEL

#define TEST_PTR_REFERENCE_DLEVEL 2

#endif //!TEST_PTR_REFERENCE_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>

template<typename T>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_PTR_REFERENCE_DLEVEL, 
    "test::ptr::Reference", 
    test::ptr::Reference<T>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace ptr
{

template<typename T>
class Reference : public test::ptr::Base
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::ptr::Reference<T>> DebugType;
public:
    typedef test::ptr::Base BaseType;
    typedef T ValueType;
    typedef std::size_t IntegerCountType;
    typedef std::atomic<IntegerCountType> CountType;
private:
    std::size_t m_step;
public:
    Reference();
    template<typename To, typename ToDefinition>
    explicit Reference(test::Pointer<To, ToDefinition> ptr);
public:
    explicit Reference(BaseType& base, const std::size_t& step);
public:
    ~Reference();
public:
    Reference(const Reference<T>& cpy);
    Reference(Reference<T>&& mov);
public:
    Reference<T>& operator=(const Reference<T>& cpy);
    Reference<T>& operator=(Reference<T>&& mov);
public:
    template<typename To, typename ToDefinition = test::ptr::Definition<To>,
        typename std::enable_if<std::is_same<
            decltype(const_cast<To*>(std::declval<T*>())), To*>::value, 
            int>::type = 0>
    Reference<To> ConstCast();
    template<typename To, typename ToDefinition = test::ptr::Definition<To>,
        typename std::enable_if<std::is_same<
            decltype(dynamic_cast<To*>(std::declval<T*>())), To*>::value,
            int>::type = 0>
    Reference<To> DynamicCast();
    template<typename To, typename ToDefinition = test::ptr::Definition<To>,
        typename std::enable_if<std::is_same<
            decltype(reinterpret_cast<To*>(std::declval<T*>())), To*>::value, 
            int>::type = 0>
    Reference<To> ReinterpretCast();
    template<typename To, typename ToDefinition = test::ptr::Definition<To>,
        typename std::enable_if<std::is_same<
            decltype(static_cast<To*>(std::declval<T*>())), To*>::value,
            int>::type = 0>
    Reference<To> StaticCast();
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
    test::ptr::Iterator<Reference, T> Begin() const;
    test::ptr::Iterator<Reference, T> End() const;
public:
    void* GetData();
    void* GetData() const;
public:
    template<typename To, typename ToDefinition = 
        typename test::Pointer<T>::DefinitionType>
    test::Pointer<To, ToDefinition> Pointer();
public:
    template<typename To, typename ToDefinition = 
        typename test::Pointer<T>::DefinitionType>
    test::Pointer<To, ToDefinition> Pointer() const;
public:
    Reference<T>& operator+=(const std::size_t& index);
    Reference<T>& operator-=(const std::size_t& index);
public:
    T& operator*();
    const T& operator*() const;
public:
    T* operator->();
public:
    T& operator[](const std::size_t& index);
    const T& operator[](const std::size_t& index) const;
public:
    Reference<T>& operator++();
    Reference<T> operator++(int);
public:
    Reference<T>& operator--();
    Reference<T> operator--(int);
public:
    Reference<T> operator+(const std::size_t& index);
    Reference<T> operator-(const std::size_t& index);
    Reference<T> operator+(const int& index);
    Reference<T> operator-(const int& index);
public:
    template<typename TOther>
    bool operator==(const Reference<TOther>& other) const;
    template<typename TOther>
    bool operator!=(const Reference<TOther>& other) const;
    bool operator==(std::nullptr_t other) const;
    bool operator!=(std::nullptr_t other) const;
    bool operator==(void * other) const;
    bool operator!=(void * other) const;
};

template<typename T>
Reference<T>::Reference() :
    BaseType(),
    m_step(0)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

template<typename T>
template<typename To, typename ToDefinition>
Reference<T>::Reference(test::Pointer<To, ToDefinition> ptr) :
    BaseType(ptr),
    m_step(ptr.StepSize())
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Constructor(ptr=%p)",
        ptr.GetData());
    
}

template<typename T>
Reference<T>::Reference(BaseType& base, const std::size_t& step) :
    BaseType(base),
    m_step(step)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(base=%p, step=%zu)", this->BaseType::GetData(), step);
    
}

template<typename T>
Reference<T>::~Reference()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

    m_step = 0;
}

template<typename T>
Reference<T>::Reference(const Reference<T>& cpy) :
    BaseType(cpy),
    m_step(cpy.m_step)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);

}

template<typename T>
Reference<T>::Reference(Reference<T>&& mov) :
    BaseType(std::move(mov)),
    m_step(mov.m_step)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

    mov.m_step = 0;
}

template<typename T>
Reference<T>& Reference<T>::operator=(const Reference<T>& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);

    BaseType::operator=(cpy);
    m_step = cpy.m_step;
    return *this;
}

template<typename T>
Reference<T>& Reference<T>::operator=(Reference<T>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(cpy=%p)", &mov);

    BaseType::operator=(std::move(mov));
    m_step = mov.m_step;
    mov.m_step = 0;
    return *this;
}

template<typename T>
template<typename To, typename ToDefinition, 
    typename std::enable_if<std::is_same<
        decltype(const_cast<To*>(std::declval<T*>())), To*>::value,
        int>::type>
Reference<To> Reference<T>::ConstCast()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "ConstCast<%s>()", TEST_SYS_DEBUG_TARGS_NAME_STR(To, ToDefinition));

    Reference<To> ret{(BaseType&)*this, m_step};
    return ret;
}

template<typename T>
template<typename To, typename ToDefinition, 
    typename std::enable_if<std::is_same<
        decltype(dynamic_cast<To*>(std::declval<T*>())), To*>::value,
        int>::type>
Reference<To> Reference<T>::DynamicCast()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "DynamicCast<%s>()", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(To, ToDefinition));

    To* ptr = dynamic_cast<To*>(BaseType::Get<T>());
    if (ptr == nullptr)
    {
        Reference<To> ret;
        return ret;
    }
    Reference<To> ret{(BaseType&)*this, m_step};
    return ret;
}

template<typename T>
template<typename To, typename ToDefinition, 
    typename std::enable_if<std::is_same<
        decltype(reinterpret_cast<To*>(std::declval<T*>())), To*>::value,
        int>::type>
Reference<To> Reference<T>::ReinterpretCast()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "ReinterpretCast<%s>()", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(To, ToDefinition));

    Reference<To> ret{(BaseType&)*this, 
        sizeof(typename ToDefinition::ValueType)};
    return ret;
}

template<typename T>
template<typename To, typename ToDefinition,
    typename std::enable_if<std::is_same<
        decltype(static_cast<To*>(std::declval<T*>())), To*>::value,
        int>::type>
Reference<To> Reference<T>::StaticCast()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "StaticCast<%s>()", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(To, ToDefinition));

    Reference<To> ret{(BaseType&)*this, m_step};
    return ret;
}

template<typename T>
std::size_t Reference<T>::StepSize() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "StepSize()");

    return m_step;
}

template<typename T>
std::size_t Reference<T>::AllocationSize() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "AllocationSize()");

    return BaseType::GetDataSize();
}

template<typename T>
std::size_t Reference<T>::Size() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Size()");

    return BaseType::GetDataSize() / m_step;
}

template<typename T>
std::size_t Reference<T>::Offset() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Offset()");

    return BaseType::GetOffset();
}

template<typename T>
std::size_t Reference<T>::Index() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Index()");

    return BaseType::GetOffset() / m_step;
}

template<typename T>
void Reference<T>::SetIndex(const std::size_t& set)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "SetIndex(set=%zu)", set);

    BaseType::SetOffset(set * m_step);
}

template<typename T>
test::ptr::Iterator<Reference, T> Reference<T>::Begin() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Begin() const");

    const std::size_t index = Index();
    return {*this, index, Size(), index};
}

template<typename T>
test::ptr::Iterator<Reference, T> Reference<T>::End() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "End() const");

    const std::size_t size = Size();
    return {*this, Index(), size, size};
}

template<typename T>
void* Reference<T>::GetData()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetData()");

    return BaseType::GetData();
}

template<typename T>
void* Reference<T>::GetData() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetData() const");

    auto* _this = const_cast<Reference<T>*>(this);
    return _this->BaseType::GetData();
}

template<typename T>
template<typename To, typename ToDefinition>
test::Pointer<To, ToDefinition> Reference<T>::Pointer()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Pointer()");

    return test::Pointer<To, ToDefinition>{*this, m_step};
}

template<typename T>
template<typename To, typename ToDefinition>
test::Pointer<To, ToDefinition> Reference<T>::Pointer() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Pointer() const");

    return test::Pointer<To, ToDefinition>{*this, m_step};
}

template<typename T>
Reference<T>& Reference<T>::operator+=(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+=(index=%zu)", index);

    BaseType::operator+=(index * m_step);
    return *this;
}

template<typename T>
Reference<T>& Reference<T>::operator-=(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-=(index=%zu)", index);

    BaseType::operator-=(index * m_step);
    return *this;
}

template<typename T>
T& Reference<T>::operator*()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator*()");

    return *(BaseType::Get<T>());
}

template<typename T>
const T& Reference<T>::operator*() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator*() const");

    return *(const_cast<Reference<T>*>(this)->BaseType::Get<T>());
}

template<typename T>
T* Reference<T>::operator->()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator->()");

    return BaseType::Get<T>();
}

template<typename T>
T& Reference<T>::operator[](const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator[](index=%zu)", index);

    Reference<T> ret{*this};
    ret.SetIndex(index);
    return *(ret.BaseType::Get<T>());
}

template<typename T>
const T& Reference<T>::operator[](const std::size_t& index) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator[](index=%zu) const", index);

    Reference<T> ret{*this};
    ret.SetIndex(index);
    return *(ret.BaseType::Get<T>());
}

template<typename T>
Reference<T>& Reference<T>::operator++()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++()");

    BaseType::operator+=(m_step);
    return *this;
}

template<typename T>
Reference<T> Reference<T>::operator++(int)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++(int)");

    Reference<T> ret{*this};
    BaseType::operator+=(m_step);
    return ret;
}

template<typename T>
Reference<T>& Reference<T>::operator--()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--()");

    BaseType::operator-=(m_step);
    return *this;
}

template<typename T>
Reference<T> Reference<T>::operator--(int)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--(int)");

    Reference<T> ret{*this};
    BaseType::operator-=(m_step);
    return ret;
}

template<typename T>
Reference<T> Reference<T>::operator+(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+(index=%zu)", index);

    Reference<T> ret{*this};
    ret += index;
    return ret;
}

template<typename T>
Reference<T> Reference<T>::operator-(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-(index=%zu)", index);

    Reference<T> ret{*this};
    ret -= index;
    return ret;
}

template<typename T>
Reference<T> Reference<T>::operator+(const int& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+(index=%d)", index);

    if (index >= 0)
        return (*this + std::size_t(index));
    return (*this - std::size_t(-index));
}
    
template<typename T>
Reference<T> Reference<T>::operator-(const int& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-(index=%d)", index);

    if (index >= 0)
        return (*this - std::size_t(index));
    return (*this + std::size_t(-index));
}

template<typename T>
template<typename TOther>
bool Reference<T>::operator==(const Reference<TOther>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==<%s>(other=%p) const", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TOther),
        &other);

    return this->BaseType::operator==(other);
}

template<typename T>
template<typename TOther>
bool Reference<T>::operator!=(const Reference<TOther>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=<%s>(other=%p) const", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TOther),
        &other);
    
    return this->BaseType::operator!=(other);
}

template<typename T>
bool Reference<T>::operator==(std::nullptr_t other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(nullptr) const");

    return BaseType::GetCount() == 0;
}

template<typename T>
bool Reference<T>::operator!=(std::nullptr_t other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(nullptr) const");

    return BaseType::GetCount() != 0;
}

template<typename T>
bool Reference<T>::operator==(void * other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", other);

    return this->BaseType::operator==(other);
}

template<typename T>
bool Reference<T>::operator!=(void * other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", other);

    return this->BaseType::operator!=(other);
}

} //!ptr

} //!test

#endif //!TEST_PTR_REFERENCE_H_
