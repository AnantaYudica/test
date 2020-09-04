#ifndef TEST_POINTER_H_
#define TEST_POINTER_H_

#include "ptr/Base.h"
#include "ptr/Default.h"
#include "ptr/Flag.h"
#include "ptr/arg/Array.h"

#include <type_traits>
#include <utility>
#include <cstdint>
#include <cstddef>

namespace test
{

template<typename T, typename TDefault = test::ptr::Default<T>>
class Pointer : public test::ptr::Base
{
public:
    static_assert(decltype(IsBaseOfDefault(std::declval<TDefault>()))::value,
        "T is base of test::ptr::Default<...>");
public:
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
            !std::is_base_of<Pointer<T, TDefault>, _TArg>::value &&
            !std::is_base_of<test::ptr::Base, _TArg>::value &&
            !std::is_base_of<test::ptr::arg::Array, _TArg>::value, int>::type = 0>
    Pointer(TArg&& arg, TArgs&&... args);
    template<typename... TArgs>
    Pointer(test::ptr::arg::Array&& array, TArgs&&... args);
public:
    explicit Pointer(const BaseType& base, const std::size_t& step);
public:
    ~Pointer();
public:
    Pointer(const Pointer<T, TDefault>& cpy);
    Pointer(Pointer<T, TDefault>&& mov);
public:
    Pointer<T, TDefault>& operator=(const Pointer<T, TDefault>& cpy);
    Pointer<T, TDefault>& operator=(Pointer<T, TDefault>&& mov);
public:
    template<typename TTo, typename TToDefault = TDefault,
        typename std::enable_if<std::is_same<
            decltype(const_cast<TTo*>(std::declval<T*>())), TTo*>::value,
            int>::type = 0>
    Pointer<TTo, TToDefault> ConstCast();
    template<typename TTo, typename TToDefault = TDefault,
        typename std::enable_if<std::is_same<
            decltype(dynamic_cast<TTo*>(std::declval<T*>())), TTo*>::value,
            int>::type = 0>
    Pointer<TTo, TToDefault> DynamicCast();
    template<typename TTo, typename TToDefault = TDefault,
        typename std::enable_if<std::is_same<
            decltype(reinterpret_cast<TTo*>(std::declval<T*>())), TTo*>::value,
            int>::type = 0>
    Pointer<TTo, TToDefault> ReinterpretCast();
    template<typename TTo, typename TToDefault = TDefault,
        typename std::enable_if<std::is_same<
            decltype(static_cast<TTo*>(std::declval<T*>())), TTo*>::value,
            int>::type = 0>
    Pointer<TTo, TToDefault> StaticCast();
public:
    std::size_t StepSize() const;
    std::size_t AllocationSize() const;
    std::size_t Size() const;
public:
    std::size_t Offset() const;
    std::size_t Index() const;
    void SetIndex(const std::size_t& set);
public:
    Pointer<T, TDefault>& operator+=(const std::size_t& index);
    Pointer<T, TDefault>& operator-=(const std::size_t& index);
public:
    T& operator*();
    const T& operator*() const;
public:
    T* operator->();
public:
    T& operator[](const std::size_t& index);
    const T& operator[](const std::size_t& index) const;
public:
    Pointer<T, TDefault>& operator++();
    Pointer<T, TDefault> operator++(int);
public:
    Pointer<T, TDefault>& operator--();
    Pointer<T, TDefault> operator--(int);
public:
    Pointer<T, TDefault> operator+(const std::size_t& index);
    Pointer<T, TDefault> operator-(const std::size_t& index);
    Pointer<T, TDefault> operator+(const int& index);
    Pointer<T, TDefault> operator-(const int& index);
public:
    template<typename TOther, typename TOtherDefault>
    bool operator==(const Pointer<TOther, TOtherDefault>& other) const;
    template<typename TOther, typename TOtherDefault>
    bool operator!=(const Pointer<TOther, TOtherDefault>& other) const;
};

template<typename T, typename TDefault>
Pointer<T, TDefault>::Pointer() :
    BaseType(),
    m_step(sizeof(typename TDefault::ValueType))
{
    void* data = BaseType::Allocation(FlagType::default_initialization, 
        m_step, 1, TDefault::Destructor);
    TDefault::Constructor(data);
}

template<typename T, typename TDefault>
template<typename TArg, typename... TArgs, typename _TArg, 
    typename std::enable_if<
        !std::is_base_of<Pointer<T, TDefault>, _TArg>::value &&
        !std::is_base_of<test::ptr::Base, _TArg>::value &&
        !std::is_base_of<test::ptr::arg::Array, _TArg>::value, int>::type>
Pointer<T, TDefault>::Pointer(TArg&& arg, TArgs&&... args) :
    BaseType(),
    m_step(sizeof(typename TDefault::ValueType))
{
    void* data = BaseType::Allocation(FlagType::empty, m_step, 1, 
        TDefault::Destructor);
    TDefault::Constructor(data, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename T, typename TDefault>
template<typename... TArgs>
Pointer<T, TDefault>::Pointer(test::ptr::arg::Array&& array, TArgs&&... args) :
    BaseType(),
    m_step(sizeof(typename TDefault::ValueType))
{
    void* data = BaseType::Allocation(FlagType::array_allocation, m_step, 
        array.GetSize(), TDefault::Destructor);
    TDefault::Constructor(array.GetSize(), data, std::forward<TArgs>(args)...);
}

template<typename T, typename TDefault>
Pointer<T, TDefault>::Pointer(const BaseType& base, const std::size_t& step) :
    BaseType(base),
    m_step(step)
{}

template<typename T, typename TDefault>
Pointer<T, TDefault>::~Pointer()
{
    BaseType::Deallocation();
    m_step = 0;
}

template<typename T, typename TDefault>
Pointer<T, TDefault>::Pointer(const Pointer<T, TDefault>& cpy) :
    BaseType(cpy),
    m_step(cpy.m_step)
{}

template<typename T, typename TDefault>
Pointer<T, TDefault>::Pointer(Pointer<T, TDefault>&& mov) :
    BaseType(std::move(mov)),
    m_step(mov.m_step)
{
    mov.m_step = sizeof(typename TDefault::ValueType);
    void * data = mov.BaseType::Allocation(FlagType::default_initialization, 
        mov.m_step, 1, TDefault::Destructor);
    TDefault::Constructor(data);
}

template<typename T, typename TDefault>
Pointer<T, TDefault>& 
Pointer<T, TDefault>::operator=(const Pointer<T, TDefault>& cpy)
{
    BaseType::operator=(cpy);
    m_step = cpy.m_step;
    return *this;
}

template<typename T, typename TDefault>
Pointer<T, TDefault>& 
Pointer<T, TDefault>::operator=(Pointer<T, TDefault>&& mov)
{
    BaseType::operator=(std::move(mov));
    m_step = mov.m_step;
    mov.m_step = sizeof(typename TDefault::ValueType);
    void * data = mov.BaseType::Allocation(FlagType::default_initialization, 
        mov.m_step, 1, TDefault::Destructor);
    TDefault::Constructor(data);
    return *this;
}

template<typename T, typename TDefault>
template<typename TTo, typename TToDefault,
    typename std::enable_if<std::is_same<
        decltype(const_cast<TTo*>(std::declval<T*>())), TTo*>::value,
        int>::type>
Pointer<TTo, TToDefault> Pointer<T, TDefault>::ConstCast()
{
    Pointer<TTo, TToDefault> ret{(BaseType&)*this, m_step};
    return ret;
}

template<typename T, typename TDefault>
template<typename TTo, typename TToDefault,
    typename std::enable_if<std::is_same<
        decltype(dynamic_cast<TTo*>(std::declval<T*>())), TTo*>::value,
        int>::type>
Pointer<TTo, TToDefault> Pointer<T, TDefault>::DynamicCast()
{
    TTo* ptr = dynamic_cast<TTo*>(BaseType::Get<T>());
    if (ptr == nullptr)
    {
        Pointer<TTo, TToDefault> ret;
        return ret;
    }
    Pointer<TTo, TToDefault> ret{(BaseType&)*this, m_step};
    return ret;
}

template<typename T, typename TDefault>
template<typename TTo, typename TToDefault,
    typename std::enable_if<std::is_same<
        decltype(reinterpret_cast<TTo*>(std::declval<T*>())), TTo*>::value,
        int>::type>
Pointer<TTo, TToDefault> Pointer<T, TDefault>::ReinterpretCast()
{
    Pointer<TTo, TToDefault> ret{(BaseType&)*this, sizeof(TTo)};
    return ret;
}

template<typename T, typename TDefault>
template<typename TTo, typename TToDefault,
    typename std::enable_if<std::is_same<
        decltype(static_cast<TTo*>(std::declval<T*>())), TTo*>::value,
        int>::type>
Pointer<TTo, TToDefault> Pointer<T, TDefault>::StaticCast()
{
    Pointer<TTo, TToDefault> ret{(BaseType&)*this, m_step};
    return ret;
}

template<typename T, typename TDefault>
std::size_t Pointer<T, TDefault>::StepSize() const
{
    return m_step;
}

template<typename T, typename TDefault>
std::size_t Pointer<T, TDefault>::AllocationSize() const
{
    return BaseType::GetDataSize();
}

template<typename T, typename TDefault>
std::size_t Pointer<T, TDefault>::Size() const
{
    return BaseType::GetDataSize() / m_step;
}

template<typename T, typename TDefault>
std::size_t Pointer<T, TDefault>::Offset() const
{
    return BaseType::GetOffset();
}

template<typename T, typename TDefault>
std::size_t Pointer<T, TDefault>::Index() const
{
    return BaseType::GetOffset() / m_step;
}

template<typename T, typename TDefault>
void Pointer<T, TDefault>::SetIndex(const std::size_t& set)
{
    BaseType::SetOffset(set * m_step);
}

template<typename T, typename TDefault>
Pointer<T, TDefault>& 
Pointer<T, TDefault>::operator+=(const std::size_t& index)
{
    BaseType::operator+=(index * m_step);
    return *this;
}

template<typename T, typename TDefault>
Pointer<T, TDefault>& 
Pointer<T, TDefault>::operator-=(const std::size_t& index)
{
    BaseType::operator-=(index * m_step);
    return *this;
}

template<typename T, typename TDefault>
T& Pointer<T, TDefault>::operator*()
{
    return *(BaseType::Get<T>());
}

template<typename T, typename TDefault>
const T& Pointer<T, TDefault>::operator*() const
{
    return *(const_cast<Pointer<T, TDefault>*>(this)->BaseType::Get<T>());
}

template<typename T, typename TDefault>
T* Pointer<T, TDefault>::operator->()
{
    return BaseType::Get<T>();
}

template<typename T, typename TDefault>
T& Pointer<T, TDefault>::operator[](const std::size_t& index)
{
    Pointer<T, TDefault> ret{*this};
    ret.SetIndex(index);
    return *(ret.Get<T>());
}

template<typename T, typename TDefault>
const T& Pointer<T, TDefault>::operator[](const std::size_t& index) const
{
    Pointer<T, TDefault> ret{*this};
    ret.SetIndex(index);
    return *(ret.Get<T>());
}

template<typename T, typename TDefault>
Pointer<T, TDefault>& Pointer<T, TDefault>::operator++()
{
    BaseType::operator+=(m_step);
    return *this;
}

template<typename T, typename TDefault>
Pointer<T, TDefault> Pointer<T, TDefault>::operator++(int)
{
    Pointer<T, TDefault> ret{*this};
    BaseType::operator+=(m_step);
    return ret;
}

template<typename T, typename TDefault>
Pointer<T, TDefault>& Pointer<T, TDefault>::operator--()
{
    BaseType::operator-=(m_step);
    return *this;
}

template<typename T, typename TDefault>
Pointer<T, TDefault> Pointer<T, TDefault>::operator--(int)
{
    Pointer<T, TDefault> ret{*this};
    BaseType::operator-=(m_step);
    return ret;
}

template<typename T, typename TDefault>
Pointer<T, TDefault> Pointer<T, TDefault>::operator+(const std::size_t& index)
{
    Pointer<T, TDefault> ret{*this};
    ret += index;
    return ret;
}

template<typename T, typename TDefault>
Pointer<T, TDefault> Pointer<T, TDefault>::operator-(const std::size_t& index)
{
    Pointer<T, TDefault> ret{*this};
    ret -= index;
    return ret;
}

template<typename T, typename TDefault>
Pointer<T, TDefault> Pointer<T, TDefault>::operator+(const int& index)
{
    if (index >= 0)
        return (*this + std::size_t(index));
    return (*this - std::size_t(-index));
}
    
template<typename T, typename TDefault>
Pointer<T, TDefault> Pointer<T, TDefault>::operator-(const int& index)
{
    if (index >= 0)
        return (*this - std::size_t(index));
    return (*this + std::size_t(-index));
}

template<typename T, typename TDefault>
template<typename TOther, typename TOtherDefault>
bool Pointer<T, TDefault>::
    operator==(const Pointer<TOther, TOtherDefault>& other) const
{
    return this->BaseType::operator==(other);
}

template<typename T, typename TDefault>
template<typename TOther, typename TOtherDefault>
bool Pointer<T, TDefault>::
    operator!=(const Pointer<TOther, TOtherDefault>& other) const
{
    return this->BaseType::operator!=(other);
}

} //!test

#endif //!TEST_POINTER_H_