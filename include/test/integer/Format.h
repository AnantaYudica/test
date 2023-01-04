#ifndef TEST_INTEGER_FORMAT_H_
#define TEST_INTEGER_FORMAT_H_

#include "../System.h"
#include "Raw.h"
#include "fmt/Definition.h"
#include "fmt/Element.h"
#include "../math/integer/Addition.h"
#include "../math/integer/Subtraction.h"
#include "../math/integer/Multiplication.h"
#include "../math/integer/Division.h"
#include "../math/integer/Negation.h"
#include "../math/integer/Shift.h"
#include "../math/integer/Comparison.h"
#include "../math/integer/Logarithm.h"

#include <cstddef>
#include <cstdint>
#include <utility>
#include <type_traits>

namespace test::integer
{

template<typename TInt, std::size_t NBase, std::size_t N>
class Format;

}

#ifndef TEST_INTEGER_FORMAT_DLEVEL

#define TEST_INTEGER_FORMAT_DLEVEL 2

#endif //!TEST_INTEGER_FORMAT_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TInt>,\
    test::sys::dbg::type::Value<std::size_t, NBase>,\
    test::sys::dbg::type::Value<std::size_t , N>

template<typename TInt, std::size_t NBase, std::size_t N>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_INTEGER_FORMAT_DLEVEL, 
    "test::integer::Format", 
    test::integer::Format<TInt, NBase, N>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace integer
{

template<typename TInt, std::size_t NBase = 2, std::size_t N = 1>
class Format :
    public test::integer::Raw<N * test::integer::fmt::Definition<TInt, 
        NBase>::ElementAllocSize>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::integer::Format<TInt, 
        NBase, N>> DebugType;
public:
    typedef test::integer::Raw<N * test::integer::fmt::Definition<TInt, 
        NBase>::ElementAllocSize> BaseType;
public: 
    typedef test::integer::fmt::Definition<TInt, NBase> DefinitionType;
public:
    typedef typename DefinitionType::ElementType ElementType;
    typedef typename DefinitionType::ExpandType ExpandType;
    typedef typename DefinitionType::SizeType SizeType;
public:
    typedef test::integer::Flag FlagType;
    typedef typename FlagType::OperatorValueType FlagOperatorValType;
public:
    typedef test::integer::fmt::Element<N * 
        DefinitionType::ElementAllocSize, DefinitionType> FmtElementType;
public:
    static constexpr SizeType Size = N;
public:
    static constexpr SizeType AllocationSize = 
        N * DefinitionType::ElementAllocSize;
public:
    static constexpr ElementType ElementMaxExponent = 
        DefinitionType::ElementMaxExponent;
public:
    static ExpandType ExpandSplit(const ExpandType& expand);
public:
    static ExpandType ExpandNegationValue(const ExpandType& expand);
public:
    static ElementType ExpandElementValue(const ExpandType& expand_split);
public:
    static ElementType ExpandCarryValue(const ExpandType& expand_split);
public:
    static ElementType LogElementValue(const ElementType& v);
public:
    static ElementType ShiftRightElementValue(const ElementType& v, 
        const SizeType& n);
public:
    static ElementType ShiftLeftElementValue(const ElementType& v, 
        const SizeType& n);
public:
    static ElementType GetElement(const Format<TInt, NBase, N>& v,
        const SizeType& at);
public:
    static ElementType SetElement(Format<TInt, NBase, N>& v,
        const std::size_t& at, const ElementType& set_v);
public:
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::HasAdditionOp == true, 
            int>::type = 1>
    static void Addition(Format<TInt, NBase, N>& obj, 
        const Format<TInt, NBase, N>& other, ElementType* carry = nullptr);
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::HasAdditionOp == false, 
            int>::type = 1>
    static void Addition(Format<TInt, NBase, N>& obj, 
        const Format<TInt, NBase, N>& other, ElementType* carry = nullptr);
public:
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::HasSubtractionOp == true, 
            int>::type = 1>
    static void Subtraction(Format<TInt, NBase, N>& obj, 
        const Format<TInt, NBase, N>& other, ElementType* carry = nullptr);
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::HasSubtractionOp == false, 
            int>::type = 1>
    static void Subtraction(Format<TInt, NBase, N>& obj, 
        const Format<TInt, NBase, N>& other, ElementType* carry = nullptr);
public:
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::
            HasMultiplicationOp == true, int>::type = 1>
    static void Multiplication(Format<TInt, NBase, N>& obj, 
        const Format<TInt, NBase, N>& other, 
        Format<TInt, NBase, N>* overflow = nullptr);
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::
            HasMultiplicationOp == false, int>::type = 1>
    static void Multiplication(Format<TInt, NBase, N>& obj, 
        const Format<TInt, NBase, N>& other, 
        Format<TInt, NBase, N>* overflow = nullptr);
public:
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::
            HasDivisionOp == true, int>::type = 1>
    static void Division(Format<TInt, NBase, N>& obj, 
        const Format<TInt, NBase, N>& other, 
        test::math::integer::div::Flag& flag,
        Format<TInt, NBase, N>* rem = nullptr);
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::
            HasDivisionOp == false, int>::type = 1>
    static void Division(Format<TInt, NBase, N>& obj, 
        const Format<TInt, NBase, N>& other, 
        test::math::integer::div::Flag& flag,
        Format<TInt, NBase, N>* rem = nullptr);
public:
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::HasShiftOp == true, 
            int>::type = 1>
    static void ShiftR(Format<TInt, NBase, N>& obj, const std::size_t& n,
        Format<TInt, NBase, N>* overflow = nullptr, 
        Format<TInt, NBase, N>* before = nullptr,
        const ElementType& end_pattern = 0);
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::HasShiftOp == false, 
            int>::type = 1>
    static void ShiftR(Format<TInt, NBase, N>& obj, const std::size_t& n,
        Format<TInt, NBase, N>* overflow = nullptr, 
        Format<TInt, NBase, N>* before = nullptr,
        const ElementType& end_pattern = 0);
public:
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::HasShiftOp == true, 
            int>::type = 1>
    static void ShiftL(Format<TInt, NBase, N>& obj, const std::size_t& n,
        Format<TInt, NBase, N>* overflow = nullptr, 
        Format<TInt, NBase, N>* before = nullptr);
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::HasShiftOp == false, 
            int>::type = 1>
    static void ShiftL(Format<TInt, NBase, N>& obj, const std::size_t& n,
        Format<TInt, NBase, N>* overflow = nullptr, 
        Format<TInt, NBase, N>* before = nullptr);
public:
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::HasNegationOp == true, 
            int>::type = 1>
    static void Negation(Format<TInt, NBase, N>& obj, 
        ElementType* carry = nullptr);
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::HasNegationOp == false, 
            int>::type = 1>
    static void Negation(Format<TInt, NBase, N>& obj, 
        ElementType* carry = nullptr);
public:
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::HasAndOp == true, 
            int>::type = 1>
    static void And(Format<TInt, NBase, N>& obj, 
        const Format<TInt, NBase, N>& other);
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::HasAndOp == false, 
            int>::type = 1>
    static void And(Format<TInt, NBase, N>& obj, 
        const Format<TInt, NBase, N>& other);
public:
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::HasOrOp == true, 
            int>::type = 1>
    static void Or(Format<TInt, NBase, N>& obj, 
        const Format<TInt, NBase, N>& other);
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::HasOrOp == false, 
            int>::type = 1>
    static void Or(Format<TInt, NBase, N>& obj, 
        const Format<TInt, NBase, N>& other);
public:
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::HasXorOp == true, 
            int>::type = 1>
    static void Xor(Format<TInt, NBase, N>& obj, 
        const Format<TInt, NBase, N>& other);
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::HasXorOp == false, 
            int>::type = 1>
    static void Xor(Format<TInt, NBase, N>& obj, 
        const Format<TInt, NBase, N>& other);
public:
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::HasNotOp == true, 
            int>::type = 1>
    static void Not(Format<TInt, NBase, N>& obj);
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::HasNotOp == false, 
            int>::type = 1>
    static void Not(Format<TInt, NBase, N>& obj);
public:
    Format();
    explicit Format(const ElementType& set);
    ~Format();
public:
    Format(const Format<TInt, NBase, N>& cpy);
    Format(Format<TInt, NBase, N>&& mov);
public:
    Format<TInt, NBase, N>& operator=(const Format<TInt, NBase, N>& cpy);
    Format<TInt, NBase, N>& operator=(Format<TInt, NBase, N>&& mov);
private:
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::Signed == true, 
            int>::type = 1>
    Format<TInt, NBase, N>& AdditionSubtraction(
        const Format<TInt, NBase, N>& other,
        const FlagOperatorValType& op_val);
    template<typename TDefinition = 
            test::integer::fmt::Definition<TInt, NBase>,
        typename std::enable_if<TDefinition::Signed == false, 
            int>::type = 1>
    Format<TInt, NBase, N>& AdditionSubtraction(
        const Format<TInt, NBase, N>& other,
        const FlagOperatorValType& op_val);
public:
    BaseType& Raw();
    const BaseType& Raw() const;
public:
    bool IsZero() const;
protected:
    using BaseType::Begin;
    using BaseType::End;
protected:
    using BaseType::ReverseBegin;
    using BaseType::ReverseEnd;
protected:
    using BaseType::CastTo;
protected:
    using BaseType::Resize;
protected:
    using BaseType::Get;
public:
    Format<TInt, NBase, N>& operator+=(const Format<TInt, NBase, N>& other);
public:
    Format<TInt, NBase, N>& operator-=(const Format<TInt, NBase, N>& other);
public:
    Format<TInt, NBase, N>& operator*=(const Format<TInt, NBase, N>& other);
public:
    Format<TInt, NBase, N>& operator/=(const Format<TInt, NBase, N>& other);
public:
    Format<TInt, NBase, N>& operator%=(const Format<TInt, NBase, N>& other);
public:
    Format<TInt, NBase, N>& operator&=(const Format<TInt, NBase, N>& other);
public:
    Format<TInt, NBase, N>& operator|=(const Format<TInt, NBase, N>& other);
public:
    Format<TInt, NBase, N>& operator^=(const Format<TInt, NBase, N>& other);
public:
    Format<TInt, NBase, N>& operator>>=(const SizeType& n);
public:
    Format<TInt, NBase, N>& operator<<=(const SizeType& n);
public:
    Format<TInt, NBase, N>& operator++();
    Format<TInt, NBase, N> operator++(int);
public:
    Format<TInt, NBase, N>& operator--();
    Format<TInt, NBase, N> operator--(int);
public:
    Format<TInt, NBase, N> operator-() const;
public:
    Format<TInt, NBase, N> operator~() const;
public:
    FmtElementType operator[](const SizeType& n);
    const FmtElementType operator[](const SizeType& n) const;
public:
    Format<TInt, NBase, N> 
        operator+(const Format<TInt, NBase, N>& other) const;
    Format<TInt, NBase, N> 
        operator-(const Format<TInt, NBase, N>& other) const;
    Format<TInt, NBase, N> 
        operator*(const Format<TInt, NBase, N>& other) const;
    Format<TInt, NBase, N> 
        operator/(const Format<TInt, NBase, N>& other) const;
    Format<TInt, NBase, N> 
        operator%(const Format<TInt, NBase, N>& other) const;
    Format<TInt, NBase, N> 
        operator&(const Format<TInt, NBase, N>& other) const;
    Format<TInt, NBase, N> 
        operator|(const Format<TInt, NBase, N>& other) const;
    Format<TInt, NBase, N> 
        operator^(const Format<TInt, NBase, N>& other) const;
    Format<TInt, NBase, N> operator>>(const SizeType& n) const;
    Format<TInt, NBase, N> operator<<(const SizeType& n) const;
public:
    bool operator==(const Format<TInt, NBase, N>& other) const;
    bool operator!=(const Format<TInt, NBase, N>& other) const;
public:
    bool operator<(const Format<TInt, NBase, N>& other) const;
    bool operator>(const Format<TInt, NBase, N>& other) const;
public:
    bool operator<=(const Format<TInt, NBase, N>& other) const;
    bool operator>=(const Format<TInt, NBase, N>& other) const;
};

template<typename TInt, std::size_t NBase, std::size_t N>
typename Format<TInt, NBase, N>::ExpandType 
Format<TInt, NBase, N>::ExpandSplit(const ExpandType& expand)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, "ExpandSplit(expand=%s)",
        TEST_SYS_DEBUG_VALUE_STR(0, expand));
    
    return DefinitionType::ExpandSplit(expand);
}

template<typename TInt, std::size_t NBase, std::size_t N>
typename Format<TInt, NBase, N>::ExpandType 
Format<TInt, NBase, N>::ExpandNegationValue(const ExpandType& expand)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "ExpandNegationValue(expand=%s)", TEST_SYS_DEBUG_VALUE_STR(0, expand));
    
    return DefinitionType::ExpandNegationValue(expand);
}

template<typename TInt, std::size_t NBase, std::size_t N>
typename Format<TInt, NBase, N>::ElementType 
Format<TInt, NBase, N>::ExpandElementValue(const ExpandType& expand_split)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "ExpandElementValue(expand_split=%s)", 
        TEST_SYS_DEBUG_VALUE_STR(0, expand_split));
    
    return DefinitionType::ExpandElementValue(expand_split);
}

template<typename TInt, std::size_t NBase, std::size_t N>
typename Format<TInt, NBase, N>::ElementType 
Format<TInt, NBase, N>::ExpandCarryValue(const ExpandType& expand_split)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "ExpandCarryValue(expand_split=%s)",  
        TEST_SYS_DEBUG_VALUE_STR(0, expand_split));
    
    return DefinitionType::ExpandCarryValue(expand_split);
}

template<typename TInt, std::size_t NBase, std::size_t N>
typename Format<TInt, NBase, N>::ElementType 
Format<TInt, NBase, N>::LogElementValue(const ElementType& v)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "LogElementValue(v=%s)", TEST_SYS_DEBUG_VALUE_STR(0, v));
    
    return DefinitionType::LogElementValue(v);
}

template<typename TInt, std::size_t NBase, std::size_t N>
typename Format<TInt, NBase, N>::ElementType 
Format<TInt, NBase, N>::ShiftRightElementValue(const ElementType& v, 
    const SizeType& n)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "LogElementValue(v=%s, n=%s)", TEST_SYS_DEBUG_VALUE_STR(0, v),
        TEST_SYS_DEBUG_VALUE_STR(1, n));
    
    return DefinitionType::ShiftRightElementValue(v, n);
}

template<typename TInt, std::size_t NBase, std::size_t N>
typename Format<TInt, NBase, N>::ElementType 
Format<TInt, NBase, N>::ShiftLeftElementValue(const ElementType& v, 
    const SizeType& n)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "ShiftLeftElementValue(v=%s, n=%s)", TEST_SYS_DEBUG_VALUE_STR(0, v),
        TEST_SYS_DEBUG_VALUE_STR(1, n));
    
    return DefinitionType::ShiftLeftElementValue(v, n);
}

template<typename TInt, std::size_t NBase, std::size_t N>
typename Format<TInt, NBase, N>::ElementType 
Format<TInt, NBase, N>::GetElement(const Format<TInt, NBase, N>& v,
    const SizeType& at)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "GetElement(v=%p, at=%zu)", &v, at);
    
    return v.template CastTo<ElementType>(at * 
        DefinitionType::ElementAllocSize);
}

template<typename TInt, std::size_t NBase, std::size_t N>
typename Format<TInt, NBase, N>::ElementType 
Format<TInt, NBase, N>::SetElement(Format<TInt, NBase, N>& v,
    const std::size_t& at, const ElementType& set_v)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "SetElement(v=%p, at=%zu, set_v=%s)", &v, at,
        TEST_SYS_DEBUG_VALUE_STR(0, set_v));
    
    return (v.template CastTo<ElementType>(at * 
        DefinitionType::ElementAllocSize) = set_v);
}

template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
    HasAdditionOp == true, int>::type>
void Format<TInt, NBase, N>::Addition(Format<TInt, NBase, N>& obj, 
    const Format<TInt, NBase, N>& other, ElementType* carry)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "Addition<%s, true>(obj=%p, other=%p, carry=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TDefinition),
        &obj, &other, carry);
    
    if (carry != nullptr)
    {
        *carry = test::math::integer::Addition(obj, other, *carry);
    }
    else
    {
        test::math::integer::Addition(obj, other);
    }
}

template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
    HasAdditionOp == false, int>::type>
void Format<TInt, NBase, N>::Addition(Format<TInt, NBase, N>& obj, 
    const Format<TInt, NBase, N>& other, ElementType* carry)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "Addition<%s, false>(obj=%p, other=%p, carry=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TDefinition),
        &obj, &other, carry);
    
}

template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
    HasSubtractionOp == true, int>::type>
void Format<TInt, NBase, N>::Subtraction(Format<TInt, NBase, N>& obj, 
    const Format<TInt, NBase, N>& other, ElementType* carry)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "Subtraction<%s, true>(obj=%p, other=%p, carry=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TDefinition),
        &obj, &other, carry);
    
    if (carry != nullptr)
    {
        *carry = test::math::integer::Subtraction(obj, other, *carry);
    }
    else
    {
        test::math::integer::Subtraction(obj, other);
    }
}

template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
    HasSubtractionOp == false, int>::type>
void Format<TInt, NBase, N>::Subtraction(Format<TInt, NBase, N>& obj, 
    const Format<TInt, NBase, N>& other, ElementType* carry)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "Subtraction<%s, false>(obj=%p, other=%p, carry=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TDefinition),
        &obj, &other, carry);
    
}

template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
    HasMultiplicationOp == true, int>::type>
void Format<TInt, NBase, N>::Multiplication(Format<TInt, NBase, N>& obj, 
    const Format<TInt, NBase, N>& other, Format<TInt, NBase, N>* overflow)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "Multiplication<%s, true>(obj=%p, other=%p, overflow=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TDefinition),
        &obj, &other, overflow);
    
    if (overflow != nullptr)
    {
        test::math::integer::Multiplication(obj, other, overflow);
    }
    else
    {
        test::math::integer::Multiplication(obj, other);
    }
}

template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
        HasMultiplicationOp == false, int>::type>
void Format<TInt, NBase, N>::Multiplication(Format<TInt, NBase, N>& obj, 
    const Format<TInt, NBase, N>& other, Format<TInt, NBase, N>* overflow)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "Multiplication<%s, false>(obj=%p, other=%p, overflow=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TDefinition),
        &obj, &other, overflow);
    
}

template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
        HasDivisionOp == true, int>::type>
void Format<TInt, NBase, N>::Division(Format<TInt, NBase, N>& obj, 
    const Format<TInt, NBase, N>& other, 
    test::math::integer::div::Flag& flag,
    Format<TInt, NBase, N>* rem)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "Division<%s, true>(obj=%p, other=%p, flag=%p, rem=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TDefinition),
        &obj, &other, &flag, rem);
    
    if (rem != nullptr)
    {
        flag = test::math::integer::Division(obj, other, rem);
    }
    else
    {
        flag = test::math::integer::Division(obj, other);
    }
}

template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
    HasDivisionOp == false, int>::type>
void Format<TInt, NBase, N>::Division(Format<TInt, NBase, N>& obj, 
    const Format<TInt, NBase, N>& other, 
    test::math::integer::div::Flag& flag,
    Format<TInt, NBase, N>* rem)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "Division<%s, false>(obj=%p, other=%p, flag=%p, rem=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TDefinition),
        &obj, &other, &flag, rem);
}

template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
    HasShiftOp == true, int>::type>
void Format<TInt, NBase, N>::ShiftR(Format<TInt, NBase, N>& obj, 
    const std::size_t& n, Format<TInt, NBase, N>* overflow, 
    Format<TInt, NBase, N>* before, const ElementType& end_pattern)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "ShiftR<%s, true>(obj=%p, n=%zu, overflow=%p, before=%p, "
        "end_pattern=%d)", TEST_SYS_DEBUG_TARGS_NAME_STR(TDefinition),
        &obj, n, overflow, before, end_pattern);
    
    if (overflow != nullptr && before != nullptr)
    {
        test::math::integer::Shift<test::math::integer::shift::
            Right>(*before, obj, *overflow, n, end_pattern);
    }
    else if (overflow != nullptr)
    {
        test::math::integer::Shift<test::math::integer::shift::
            Right>(obj, *overflow, n, end_pattern);
    }
    else if (before != nullptr)
    {
        test::math::integer::Shift<test::math::integer::shift::
            Right>(*before, obj, n, end_pattern);
    }
    else
    {
        test::math::integer::Shift<test::math::integer::shift::
            Right>(obj, n, end_pattern);
    }
}

template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition,typename std::enable_if<TDefinition::
    HasShiftOp == false, int>::type>
void Format<TInt, NBase, N>::ShiftR(Format<TInt, NBase, N>& obj, 
    const std::size_t& n, Format<TInt, NBase, N>* overflow, 
    Format<TInt, NBase, N>* before, const ElementType& end_pattern)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "ShiftR<%s, false>(obj=%p, n=%zu, overflow=%p, before=%p, "
        "end_pattern=%d)", TEST_SYS_DEBUG_TARGS_NAME_STR(TDefinition),
        &obj, n, overflow, before, end_pattern);

}

template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
    HasShiftOp == true, int>::type>
void Format<TInt, NBase, N>::ShiftL(Format<TInt, NBase, N>& obj, 
    const std::size_t& n, Format<TInt, NBase, N>* overflow, 
    Format<TInt, NBase, N>* before)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "ShiftL<%s, true>(obj=%p, n=%zu, overflow=%p, before=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TDefinition),
        &obj, n, overflow, before);
    
    if (overflow != nullptr && before != nullptr)
    {
        test::math::integer::Shift<test::math::integer::shift::
            Left>(*overflow, obj, before, n);
    }
    else if (overflow != nullptr)
    {
        test::math::integer::Shift<test::math::integer::shift::
            Left>(*overflow, obj, n);
    }
    else
    {
        test::math::integer::Shift<test::math::integer::shift::
            Left>(obj, n);
    }
}

template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
    HasShiftOp == false, int>::type>
void Format<TInt, NBase, N>::ShiftL(Format<TInt, NBase, N>& obj, 
    const std::size_t& n, Format<TInt, NBase, N>* overflow, 
    Format<TInt, NBase, N>* before)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "ShiftL<%s, false>(obj=%p, n=%zu, overflow=%p, before=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TDefinition),
        &obj, n, overflow, before);
    
}

template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
    HasNegationOp == true, int>::type>
void Format<TInt, NBase, N>::Negation(Format<TInt, NBase, N>& obj, 
    ElementType* carry)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "Negation<%s, true>(obj=%p, carry=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TDefinition), &obj, carry);
    
    if (carry != nullptr)
    {
        *carry = test::math::integer::Negation(obj, *carry);
    }
    else
    {
        test::math::integer::Negation(obj);
    }
}

template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
    HasNegationOp == false, int>::type>
void Format<TInt, NBase, N>::Negation(Format<TInt, NBase, N>& obj, 
    ElementType* carry)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "Negation<%s, false>(obj=%p, carry=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TDefinition), &obj, carry);
    
}

template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
    HasAndOp == true, int>::type>
void Format<TInt, NBase, N>::And(Format<TInt, NBase, N>& obj, 
    const Format<TInt, NBase, N>& other)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "And<%s, true>(obj=%p, other=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TDefinition), &obj, &other);
    
    BaseType& base_obj = static_cast<BaseType&>(obj);
    base_obj &= other;
}
    
template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
    HasAndOp == false, int>::type>
void Format<TInt, NBase, N>::And(Format<TInt, NBase, N>& obj, 
    const Format<TInt, NBase, N>& other)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "And<%s, false>(obj=%p, other=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TDefinition), &obj, &other);
    
}

template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
    HasOrOp == true, int>::type>
void Format<TInt, NBase, N>::Or(Format<TInt, NBase, N>& obj, 
    const Format<TInt, NBase, N>& other)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "Or<%s, true>(obj=%p, other=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TDefinition), &obj, &other);
    
    BaseType& base_obj = static_cast<BaseType&>(obj);
    base_obj |= other;
}
    
template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
    HasOrOp == false, int>::type>
void Format<TInt, NBase, N>::Or(Format<TInt, NBase, N>& obj, 
    const Format<TInt, NBase, N>& other)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "Or<%s, false>(obj=%p, other=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TDefinition), &obj, &other);

}

template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
    HasXorOp == true, int>::type>
void Format<TInt, NBase, N>::Xor(Format<TInt, NBase, N>& obj, 
    const Format<TInt, NBase, N>& other)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "Xor<%s, true>(obj=%p, other=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TDefinition), &obj, &other);
    
    BaseType& base_obj = static_cast<BaseType&>(obj);
    base_obj ^= other;
}
    
template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
    HasXorOp == false, int>::type>
void Format<TInt, NBase, N>::Xor(Format<TInt, NBase, N>& obj, 
    const Format<TInt, NBase, N>& other)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "Xor<%s, false>(obj=%p, other=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TDefinition), &obj, &other);
    
}

template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
    HasNotOp == true, int>::type>
void Format<TInt, NBase, N>::Not(Format<TInt, NBase, N>& obj)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "Not<%s, true>(obj=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TDefinition), &obj);
    
    BaseType& base_obj = static_cast<BaseType&>(obj);
    base_obj = ~base_obj;
}

template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
    HasNotOp == false, int>::type>
void Format<TInt, NBase, N>::Not(Format<TInt, NBase, N>& obj)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "Not<%s, false>(obj=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TDefinition), &obj);
    
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N>::Format() :
    BaseType(DefinitionType::Flag())
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");
    
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N>::Format(const ElementType& set) :
    BaseType(DefinitionType::Flag())
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Constructor(set=%s)",
        TEST_SYS_DEBUG_VALUE_STR(0, set));
    
    memset(this->Get(), set, AllocationSize);
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N>::~Format()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");
    
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N>::Format(const Format<TInt, NBase, N>& cpy) :
    BaseType(cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);
    
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N>::Format(Format<TInt, NBase, N>&& mov) :
    BaseType(std::move(mov))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);
    
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N>& 
Format<TInt, NBase, N>::operator=(const Format<TInt, NBase, N>& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);
    
    BaseType::operator=(cpy);
    return *this;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N>& 
Format<TInt, NBase, N>::operator=(Format<TInt, NBase, N>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);
    
    BaseType::operator=(std::move(mov));
    return *this;
}

template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
    Signed == true, int>::type>
Format<TInt, NBase, N>& Format<TInt, NBase, N>::AdditionSubtraction(
    const Format<TInt, NBase, N>& other,
    const FlagOperatorValType& op_val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "AdditionSubtraction<%s, true>(other=%p, op=%d)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TDefinition), &other, op_val);
    
    ElementType carry = 0;

    if (op_val & FlagType::kAdditionOp)
    {
        Addition(*this, other, &carry);
        if (carry > 0)
        {
            this->Flag().Error(FlagType::kOverflow);
        }
    }
    else if (op_val & FlagType::kNegationOp)
    {
        const auto comp = test::math::integer::Comparison(*this, other);
        if (comp < 0)
        {
            Format<TInt, NBase, N> cpy = other;
            if (cpy.Flag().IsNegative())
            {
                cpy.Flag().UnsetNegative();
            }
            else if (cpy.Flag().IsSigned())
            {
                cpy.Flag().SetNegative();
            }
            Subtraction(cpy, *this);
            *this = cpy;
        }
        else
        {
            Subtraction(*this, other);
            if (comp == 0 && this->Flag().IsNegative())
            {
                this->Flag().UnsetNegative();
            }
        }
    }

    return *this;
}

template<typename TInt, std::size_t NBase, std::size_t N>
template<typename TDefinition, typename std::enable_if<TDefinition::
    Signed == false, int>::type>
Format<TInt, NBase, N>& Format<TInt, NBase, N>::
    AdditionSubtraction(const Format<TInt, NBase, N>& other,
    const FlagOperatorValType& op_val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "AdditionSubtraction<%s, false>(other=%p, op=%d)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TDefinition), &other, op_val);
        
    ElementType carry = 0;

    if (op_val & FlagType::kAdditionOp)
    {
        Addition(*this, other, &carry);
        if (carry > 0)
        {
            this->Flag().Error(FlagType::kOverflow);
        }
    }
    else if (op_val & FlagType::kNegationOp)
    {
        Subtraction(*this, other);
    }

    return *this;
}
    
template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N>&
Format<TInt, NBase, N>::operator+=(const Format<TInt, NBase, N>& other)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+=(other=%p)", &other);
    
    FlagOperatorValType op_val = (BaseType::Flag() += other.Flag());
    
    return AdditionSubtraction(other, op_val);
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N>& 
Format<TInt, NBase, N>::operator-=(const Format<TInt, NBase, N>& other)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-=(other=%p)", &other);
    
    FlagOperatorValType op_val = (BaseType::Flag() -= other.Flag());
    
    return AdditionSubtraction(other, op_val);
}

template<typename TInt, std::size_t NBase, std::size_t N>
typename Format<TInt, NBase, N>::BaseType& 
Format<TInt, NBase, N>::Raw()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Raw()");

    return *this;
}

template<typename TInt, std::size_t NBase, std::size_t N>
const typename Format<TInt, NBase, N>::BaseType& 
Format<TInt, NBase, N>::Raw() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Raw() const");

    return *this;
}

template<typename TInt, std::size_t NBase, std::size_t N>
bool Format<TInt, NBase, N>::IsZero() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsZero() const");

    for (auto it = BaseType::Begin(); it != BaseType::End(); ++it)
    {
        if (*it != 0)
        {
            return false;
        }
    }
    return true;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N>& 
Format<TInt, NBase, N>::operator*=(const Format<TInt, NBase, N>& other)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator*=(other=%p)", &other);

    BaseType::Flag() *= other.Flag();

    Format<TInt, NBase, N> overflow;
    
    Multiplication(*this, other, &overflow);

    if (!overflow.IsZero())
    {
        this->Flag().Error(FlagType::kOverflow);
    }

    return *this;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N>& 
Format<TInt, NBase, N>::operator/=(const Format<TInt, NBase, N>& other)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator/=(other=%p)", &other);
    
    BaseType::Flag() /= other.Flag();
    
    typedef test::math::integer::div::Flag DivFlag;
    DivFlag flag;
    Division(*this, other, flag);
    int int_flag = (int) flag;

    if (int_flag < (int)DivFlag::Ok)
    {
        if (int_flag == (int)FlagType::kDivByZero)
        {
            BaseType::Flag().Error(FlagType::kDivByZero);
        }
        else
        {
            BaseType::Flag().Error(FlagType::kDivError);
        }
    }

    return *this;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N>& 
Format<TInt, NBase, N>::operator%=(const Format<TInt, NBase, N>& other)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator%=(other=%p)", &other);
    
    BaseType::Flag() %= other.Flag();

    Format<TInt, NBase, N> rem;
    
    typedef test::math::integer::div::Flag DivFlag;
    DivFlag flag;
    Division(*this, other, flag, &rem);

    *this = rem;
    return *this;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N>& 
Format<TInt, NBase, N>::operator&=(const Format<TInt, NBase, N>& other)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator&=(other=%p)", &other);
    
    BaseType::Flag() &= other.Flag();
    
    And(*this, other);

    return *this;
}


template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N>& 
Format<TInt, NBase, N>::operator|=(const Format<TInt, NBase, N>& other)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator|=(other=%p)", &other);
    
    BaseType::Flag() |= other.Flag();
    
    Or(*this, other);

    return *this;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N>& 
Format<TInt, NBase, N>::operator^=(const Format<TInt, NBase, N>& other)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator^=(other=%p)", &other);
    
    BaseType::Flag() ^= other.Flag();
    
    Xor(*this, other);
    
    return *this;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N>& 
Format<TInt, NBase, N>::operator>>=(const SizeType& n)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator>>=(n=%zu)", n);

    BaseType::Flag() >>= n;

    if (BaseType::Flag().IsNegative())
    {
        Format<TInt, NBase, N> neg = *this;
        Negation(neg);
        ShiftR(neg, n, nullptr, nullptr, DefinitionType::ElementMaxValue);
        Negation(neg);
        *this = neg;
    }
    else
    {
        ShiftR(*this, n);
    }
    
    return *this;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N>& 
Format<TInt, NBase, N>::operator<<=(const SizeType& n)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator<<=(n=%zu)", n);

    BaseType::Flag() <<= n;

    ShiftL(*this, n);

    return *this;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N>& Format<TInt, NBase, N>::operator++()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++()");

    Format<TInt, NBase, N> one;
    one[0] = 1;
    *this += one;

    return *this;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N> Format<TInt, NBase, N>::operator++(int)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++(int)");

    Format<TInt, NBase, N> cpy = *this;

    ++(*this);

    return cpy;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N>& Format<TInt, NBase, N>::operator--()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--()");

    Format<TInt, NBase, N> one;
    one[0] = 1;
    *this -= one;

    return *this;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N> Format<TInt, NBase, N>::operator--(int)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--(int)");

    Format<TInt, NBase, N> cpy = *this;

    --(*this);

    return cpy;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N> Format<TInt, NBase, N>::operator-() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator-() const");

    Format<TInt, NBase, N> cpy = *this;

    if (!cpy.Flag().IsSigned())
    {
        Negation(cpy);
    }
    else if (cpy.Flag().IsNegative())
    {
        cpy.Flag().UnsetNegative();
    }
    else
    {
        cpy.Flag().SetNegative();
    }

    return cpy;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N> Format<TInt, NBase, N>::operator~() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator~() const");

    Format<TInt, NBase, N> cpy = *this;

    Not(cpy);

    return cpy;
}

template<typename TInt, std::size_t NBase, std::size_t N>
typename Format<TInt, NBase, N>::FmtElementType
Format<TInt, NBase, N>::operator[](const SizeType& n)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator[](n=%zu)", n);

    return {*this, n * DefinitionType::ElementAllocSize};
}

template<typename TInt, std::size_t NBase, std::size_t N>
const typename Format<TInt, NBase, N>::FmtElementType 
Format<TInt, NBase, N>::operator[](const SizeType& n) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator[](n=%zu) const", n);
    
    auto* cast = const_cast<Format<TInt, NBase, N>*>(this);
    return {*cast, n* DefinitionType::ElementAllocSize};
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N> 
Format<TInt, NBase, N>::operator+(const Format<TInt, NBase, N>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+(other=%p) const", &other);
    
    Format<TInt, NBase, N> cpy(*this);

    cpy += other;

    return cpy;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N> 
Format<TInt, NBase, N>::operator-(const Format<TInt, NBase, N>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-(other=%p) const", &other);
    
    Format<TInt, NBase, N> cpy(*this);

    cpy -= other;

    return cpy;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N> 
Format<TInt, NBase, N>::operator*(const Format<TInt, NBase, N>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator*(other=%p) const", &other);
    
    Format<TInt, NBase, N> cpy(*this);

    cpy *= other;

    return cpy;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N> 
Format<TInt, NBase, N>::operator/(const Format<TInt, NBase, N>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator/(other=%p) const", &other);
    
    Format<TInt, NBase, N> cpy(*this);

    cpy /= other;

    return cpy;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N> 
Format<TInt, NBase, N>::operator%(const Format<TInt, NBase, N>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator%(other=%p) const", &other);
    
    Format<TInt, NBase, N> cpy(*this);

    cpy %= other;

    return cpy;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N> 
Format<TInt, NBase, N>::operator&(const Format<TInt, NBase, N>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator&(other=%p) const", &other);
    
    Format<TInt, NBase, N> cpy(*this);

    cpy &= other;

    return cpy;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N> 
Format<TInt, NBase, N>::operator|(const Format<TInt, NBase, N>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator|(other=%p) const", &other);
    
    Format<TInt, NBase, N> cpy(*this);

    cpy |= other;

    return cpy;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N> 
Format<TInt, NBase, N>::operator^(const Format<TInt, NBase, N>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator^(other=%p) const", &other);
    
    Format<TInt, NBase, N> cpy(*this);

    cpy ^= other;

    return cpy;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N> 
Format<TInt, NBase, N>::operator>>(const SizeType& n) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator>>(n=%zu) const", n);
    
    Format<TInt, NBase, N> cpy(*this);

    cpy >>= n;

    return cpy;
}

template<typename TInt, std::size_t NBase, std::size_t N>
Format<TInt, NBase, N> 
Format<TInt, NBase, N>::operator<<(const SizeType& n) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator<<(n=%zu) const", n);
    
    Format<TInt, NBase, N> cpy(*this);

    cpy <<= n;

    return cpy;
}

template<typename TInt, std::size_t NBase, std::size_t N>
bool Format<TInt, NBase, N>::
    operator==(const Format<TInt, NBase, N>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", other);
    
    return test::math::integer::Comparison(*this, other) == 0 &&
        this->Flag().IsNegative() == other.Flag().IsNegative();
}

template<typename TInt, std::size_t NBase, std::size_t N>
bool Format<TInt, NBase, N>::
    operator!=(const Format<TInt, NBase, N>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", other);

    return !(*this == other);
}

template<typename TInt, std::size_t NBase, std::size_t N>
bool Format<TInt, NBase, N>::
    operator<(const Format<TInt, NBase, N>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator<(other=%p) const", other);
    
    return (!this->Flag().IsNegative() && other.Flag().IsNegative()) ||
        test::math::integer::Comparison(*this, other) < 0;
}

template<typename TInt, std::size_t NBase, std::size_t N>
bool Format<TInt, NBase, N>::
    operator>(const Format<TInt, NBase, N>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator>(other=%p) const", other);

    return (this->Flag().IsNegative() && !other.Flag().IsNegative()) ||
        test::math::integer::Comparison(*this, other) > 0;
}

template<typename TInt, std::size_t NBase, std::size_t N>
bool Format<TInt, NBase, N>::
    operator<=(const Format<TInt, NBase, N>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator<=(other=%p) const", other);
    
    return (!this->Flag().IsNegative() && other.Flag().IsNegative()) ||
        test::math::integer::Comparison(*this, other) <= 0;
}

template<typename TInt, std::size_t NBase, std::size_t N>
bool Format<TInt, NBase, N>::
    operator>=(const Format<TInt, NBase, N>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator>=(other=%p) const", other);

    return (this->Flag().IsNegative() && !other.Flag().IsNegative()) ||
        test::math::integer::Comparison(*this, other) >= 0;
}

} //!integer

} //!test

#endif //!TEST_INTEGER_FORMAT_H_
