#ifndef TEST_INTEGER_FMT_ELEMENT_H_
#define TEST_INTEGER_FMT_ELEMENT_H_

#include "../../System.h"
#include "../Raw.h"
#include "Definition.h"

#include <cstddef>
#include <utility>

namespace test::integer::fmt
{

template<std::size_t N, typename TDefinition>
class Element;

}

#ifndef TEST_INTEGER_FMT_ELEMENT_DLEVEL

#define TEST_INTEGER_FMT_ELEMENT_DLEVEL 2

#endif //!TEST_INTEGER_FMT_ELEMENT_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::type::Value<std::size_t , N>,\
    test::sys::dbg::Type<TDefinition>

template<std::size_t N, typename TDefinition>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_INTEGER_FMT_ELEMENT_DLEVEL, 
    "test::integer::fmt::Element", 
    test::integer::fmt::Element<N, TDefinition>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace integer
{
namespace fmt
{

template<std::size_t N, typename TDefinition>
class Element
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::integer::fmt::Element<N, 
        TDefinition>> DebugType;
public: 
    typedef TDefinition DefinitionType;
public:
    typedef typename DefinitionType::ElementType ElementType;
    typedef typename DefinitionType::ExpandType ExpandType;
    typedef typename DefinitionType::SizeType SizeType;
public:
    typedef ElementType&(*GetFuncType)(test::integer::Raw<N>&, 
        const std::size_t&);
public:
    static ElementType& GetValue(test::integer::Raw<N>& ref, 
        const std::size_t& index);
private:
    std::size_t m_index;
    test::integer::Raw<N>& m_ref;
public:
    Element(test::integer::Raw<N>& raw_ref, const std::size_t& n);
    ~Element();
public:
    Element(const Element<N, TDefinition>&) = delete;
    Element(Element<N, TDefinition>&& mov);
public:
    Element<N, TDefinition>& 
        operator=(const Element<N, TDefinition>&) = delete;
    Element<N, TDefinition>& 
        operator=(Element<N, TDefinition>&&) = delete;
public:
    Element<N, TDefinition>& operator=(const ElementType& elem) &&;
public:
    ElementType operator*() &&;
public:
    bool operator==(const ElementType& elem) &&;
    bool operator!=(const ElementType& elem) &&;
public:
    bool operator<(const ElementType& elem) const;
    bool operator>(const ElementType& elem) const;
public:
    bool operator<=(const ElementType& elem) const;
    bool operator>=(const ElementType& elem) const;
};

template<std::size_t N, typename TDefinition>
typename Element<N, TDefinition>::ElementType& 
Element<N, TDefinition>::GetValue(test::integer::Raw<N>& ref, 
    const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "GetValue(ref=%p, index=%zu)", &ref, index);

    return ref.template CastTo<ElementType>(index);
}

template<std::size_t N, typename TDefinition>
Element<N, TDefinition>::Element(test::integer::Raw<N>& raw_ref, 
    const std::size_t& n) :
        m_index(n),
        m_ref(raw_ref)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(raw_ref=%p, n=%zu)", &raw_ref, n);

}

template<std::size_t N, typename TDefinition>
Element<N, TDefinition>::~Element()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

}

template<std::size_t N, typename TDefinition>
Element<N, TDefinition>::Element(Element<N, TDefinition>&& mov) :
    m_ref(mov.m_ref),
    m_index(mov.m_index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

}

template<std::size_t N, typename TDefinition>
Element<N, TDefinition>& 
Element<N, TDefinition>::operator=(const ElementType& elem) &&
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "operator=(elem=%s) &&", TEST_SYS_DEBUG_VALUE_STR(0, elem));

    ElementType set = elem & DefinitionType::ElementMaxValue;
    GetValue(m_ref, m_index) = set;

    return *this;
}

template<std::size_t N, typename TDefinition>
typename Element<N, TDefinition>::ElementType
Element<N, TDefinition>::operator*() &&
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator*() &&");

    return GetValue(m_ref, m_index);
}

template<std::size_t N, typename TDefinition>
bool Element<N, TDefinition>::operator==(const ElementType& elem) &&
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(elem=%s) &&",TEST_SYS_DEBUG_VALUE_STR(0, elem));

    return *(*this) == elem;
}

template<std::size_t N, typename TDefinition>
bool Element<N, TDefinition>::operator!=(const ElementType& elem) &&
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(elem=%s) &&",TEST_SYS_DEBUG_VALUE_STR(0, elem));
        
    return *(*this) != elem;

}

} //!fmt

} //!integer

} //!test

#endif //!TEST_INTEGER_FMT_ELEMENT_H_
