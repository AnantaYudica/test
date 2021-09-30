#ifndef TEST_MATH_INTEGER_FMT_TRAIT_H_
#define TEST_MATH_INTEGER_FMT_TRAIT_H_

#include <type_traits>
#include <utility>

namespace test
{
namespace _helper
{
namespace _math
{
namespace _integer
{
namespace _fmt
{

template<typename T1, typename T2 = T1>
static constexpr auto _HasElementType(int) -> 
    decltype(std::declval<typename T1::ElementType>(), 
        std::declval<typename T2::ElementType>(),
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type _HasElementType(...);

template<typename T1, typename T2 = T1>
static constexpr auto _HasExpandType(int) -> 
    decltype(std::declval<typename T1::ExpandType>(), 
        std::declval<typename T2::ExpandType>(),
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type _HasExpandType(...);

template<typename T1, typename T2 = T1>
static constexpr auto _HasSizeType(int) -> 
    decltype(std::declval<typename T1::SizeType>(), 
        std::declval<typename T2::SizeType>(),
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type _HasSizeType(...);

template<typename T1, typename T2 = T1>
static constexpr auto _HasSizeStaticConstantMember(int) -> 
    decltype(std::declval<decltype(T1::Size)>(),
        std::declval<decltype(T2::Size)>(),
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type _HasSizeStaticConstantMember(...);

template<typename T1, typename T2 = T1>
static constexpr auto _HasElementMaxExponentStaticConstantMember(int) -> 
    decltype(std::declval<decltype(T1::ElementMaxExponent)>(),
        std::declval<decltype(T2::ElementMaxExponent)>(),
        std::true_type());
    
template<typename T1, typename T2 = T1>
static constexpr std::false_type 
    _HasElementMaxExponentStaticConstantMember(...);

template<typename T1, typename T2 = T1>
static constexpr auto _HasExpandSplitStaticMemberFunction(int) ->
    decltype(std::declval<decltype(&T1::ExpandSplit)>(),
        std::declval<decltype(&T2::ExpandSplit)>(),
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type _HasExpandSplitStaticMemberFunction(...);

template<typename T1, typename T2 = T1>
static constexpr auto _HasExpandNegationValueStaticMemberFunction(int) ->
    decltype(std::declval<decltype(&T1::ExpandNegationValue)>(),
        std::declval<decltype(&T2::ExpandNegationValue)>(),
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type 
    _HasExpandNegationValueStaticMemberFunction(...);

template<typename T1, typename T2 = T1>
static constexpr auto _HasExpandElementValueStaticMemberFunction(int) ->
    decltype(std::declval<decltype(&T1::ExpandElementValue)>(),
        std::declval<decltype(&T2::ExpandElementValue)>(),
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type 
    _HasExpandElementValueStaticMemberFunction(...);
    
template<typename T1, typename T2 = T1>
static constexpr auto _HasExpandCarryValueStaticMemberFunction(int) ->
    decltype(std::declval<decltype(&T1::ExpandCarryValue)>(),
        std::declval<decltype(&T2::ExpandCarryValue)>(),
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type 
    _HasExpandCarryValueStaticMemberFunction(...);

template<typename T1, typename T2 = T1>
static constexpr auto _HasLogElementValueStaticMemberFunction(int) ->
    decltype(std::declval<decltype(&T1::LogElementValue)>(),
        std::declval<decltype(&T2::LogElementValue)>(),
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type 
    _HasLogElementValueStaticMemberFunction(...);
  
template<typename T1, typename T2 = T1>
static constexpr auto _HasShiftRightElementValueStaticMemberFunction(int) ->
    decltype(std::declval<decltype(&T1::ShiftRightElementValue)>(),
        std::declval<decltype(&T2::ShiftRightElementValue)>(),
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type 
    _HasShiftRightElementValueStaticMemberFunction(...);

template<typename T1, typename T2 = T1>
static constexpr auto _HasShiftLeftElementValueStaticMemberFunction(int) ->
    decltype(std::declval<decltype(&T1::ShiftLeftElementValue)>(),
        std::declval<decltype(&T2::ShiftLeftElementValue)>(),
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type 
    _HasShiftLeftElementValueStaticMemberFunction(...);

template<typename T1, typename T2 = T1>
static constexpr auto _HasGetElementStaticMemberFunction(int) ->
    decltype(std::declval<decltype(&T1::GetElement)>(),
        std::declval<decltype(&T2::GetElement)>(),
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type _HasGetElementStaticMemberFunction(...);

template<typename T1, typename T2 = T1>
static constexpr auto _HasSetElementStaticMemberFunction(int) ->
    decltype(std::declval<decltype(&T1::SetElement)>(),
        std::declval<decltype(&T2::SetElement)>(),
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type _HasSetElementStaticMemberFunction(...);


template<typename T1, typename T2 = T1>
static constexpr auto _Has(int) ->
    decltype(std::declval<typename std::enable_if<
        decltype(test::_helper::_math::_integer::_fmt::
            _HasElementType<T1, T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _HasExpandType<T1, T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _HasSizeType<T1, T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _HasSizeStaticConstantMember<T1, T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _HasElementMaxExponentStaticConstantMember<T1, T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _HasExpandSplitStaticMemberFunction<T1, T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _HasExpandNegationValueStaticMemberFunction<T1, T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _HasExpandElementValueStaticMemberFunction<T1, T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _HasExpandCarryValueStaticMemberFunction<T1, T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _HasLogElementValueStaticMemberFunction<T1, T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _HasShiftRightElementValueStaticMemberFunction<T1, T2>(0))::
                value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _HasShiftLeftElementValueStaticMemberFunction<T1, T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _HasGetElementStaticMemberFunction<T1, T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _HasSetElementStaticMemberFunction<T1, T2>(0))::value,
                int>::type>(),
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type _Has(...);


template<typename T1, typename T2>
static constexpr auto _IsSameElementType(int) -> 
    decltype(std::declval<typename std::enable_if<
        std::is_same<typename T1::ElementType, 
            typename T2::ElementType>::value, int>::type>(), 
        std::true_type());

template<typename T1, typename T2>
static constexpr std::false_type _IsSameElementType(...);

template<typename T1, typename T2>
static constexpr auto _IsSameExpandType(int) -> 
    decltype(std::declval<typename std::enable_if<
        std::is_same<typename T1::ExpandType, 
            typename T2::ExpandType>::value, int>::type>(), 
        std::true_type());

template<typename T1, typename T2>
static constexpr std::false_type _IsSameExpandType(...);

template<typename T1, typename T2>
static constexpr auto _IsSameSizeType(int) -> 
    decltype(std::declval<typename std::enable_if<
        std::is_same<typename T1::SizeType, 
            typename T2::SizeType>::value, int>::type>(), 
        std::true_type());

template<typename T1, typename T2>
static constexpr std::false_type _IsSameSizeType(...);

template<typename T1, typename T2>
static constexpr auto _IsSameElementMaxExponentStaticConstantMember(int) -> 
    decltype(std::declval<typename std::enable_if<
        T1::ElementMaxExponent == T2::ElementMaxExponent, int>::type>(), 
        std::true_type());

template<typename T1, typename T2>
static constexpr std::false_type 
    _IsSameElementMaxExponentStaticConstantMember(...);

template<typename T1, typename T2>
static constexpr auto _IsSameExpandSplitStaticMemberFunction(int) -> 
    decltype(std::declval<typename std::enable_if<
        T1::ExpandSplit == T2::ExpandSplit, int>::type>(), 
        std::true_type());

template<typename T1, typename T2>
static constexpr std::false_type _IsSameExpandSplitStaticMemberFunction(...);

template<typename T1, typename T2>
static constexpr auto _IsSameExpandNegationValueStaticMemberFunction(int) -> 
    decltype(std::declval<typename std::enable_if<
        T1::ExpandNegationValue == T2::ExpandNegationValue, int>::type>(), 
        std::true_type());

template<typename T1, typename T2>
static constexpr std::false_type 
    _IsSameExpandNegationValueStaticMemberFunction(...);

template<typename T1, typename T2>
static constexpr auto _IsSameExpandElementValueStaticMemberFunction(int) -> 
    decltype(std::declval<typename std::enable_if<
        T1::ExpandElementValue == T2::ExpandElementValue, int>::type>(), 
        std::true_type());

template<typename T1, typename T2>
static constexpr std::false_type 
    _IsSameExpandElementValueStaticMemberFunction(...);

template<typename T1, typename T2>
static constexpr auto _IsSameExpandCarryValueStaticMemberFunction(int) -> 
    decltype(std::declval<typename std::enable_if<
        T1::ExpandCarryValue == T2::ExpandCarryValue, int>::type>(), 
        std::true_type());

template<typename T1, typename T2>
static constexpr std::false_type 
    _IsSameExpandCarryValueStaticMemberFunction(...);

template<typename T1, typename T2>
static constexpr auto _IsSameLogElementValueStaticMemberFunction(int) -> 
    decltype(std::declval<typename std::enable_if<
        T1::LogElementValue == T2::LogElementValue, int>::type>(), 
        std::true_type());

template<typename T1, typename T2>
static constexpr std::false_type 
    _IsSameLogElementValueStaticMemberFunction(...);
    
template<typename T1, typename T2>
static constexpr auto _IsSameShiftRightElementValueStaticMemberFunction(int) ->
    decltype(std::declval<typename std::enable_if<
        T1::ShiftRightElementValue == T2::ShiftRightElementValue, 
            int>::type>(), 
        std::true_type());

template<typename T1, typename T2>
static constexpr std::false_type 
    _IsSameShiftRightElementValueStaticMemberFunction(...);

template<typename T1, typename T2>
static constexpr auto _IsSameShiftLeftElementValueStaticMemberFunction(int) ->
    decltype(std::declval<typename std::enable_if<
        T1::ShiftLeftElementValue == T2::ShiftLeftElementValue, 
            int>::type>(), 
        std::true_type());

template<typename T1, typename T2>
static constexpr std::false_type 
    _IsSameShiftLeftElementValueStaticMemberFunction(...);

    
template<typename T1, typename T2>
static constexpr auto _IsSame(int) -> 
    decltype(std::declval<typename std::enable_if<
        decltype(test::_helper::_math::_integer::_fmt::
            _IsSameElementType<T1, T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _IsSameExpandType<T1, T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _IsSameSizeType<T1, T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _IsSameElementMaxExponentStaticConstantMember<T1, T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _IsSameExpandSplitStaticMemberFunction<T1, T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _IsSameExpandNegationValueStaticMemberFunction<T1, 
                T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _IsSameExpandElementValueStaticMemberFunction<T1, T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _IsSameExpandCarryValueStaticMemberFunction<T1, T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _IsSameLogElementValueStaticMemberFunction<T1, T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _IsSameShiftRightElementValueStaticMemberFunction<T1, 
                T2>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _IsSameShiftLeftElementValueStaticMemberFunction<T1, 
                T2>(0))::value, 
            int>::type>(), 
        std::true_type());

template<typename T1, typename T2>
static constexpr std::false_type _IsSame(...);

} //!_fmt

} //!_integer

} //!_math

} //!_helper
    
namespace math
{
namespace integer
{
namespace fmt
{

template<typename TFormat, typename TFormatO = TFormat,
    typename = void>
struct Trait
{
    typedef int ElementType;
    typedef int ExpandType;
    typedef int SizeType;

    static constexpr bool Has = decltype(
        test::_helper::_math::_integer::_fmt::
            _Has<TFormat, TFormatO>(0))::value;

    static constexpr bool HasElementType = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasElementType<TFormat, TFormatO>(0))::value;

    static constexpr bool HasExpandType = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasExpandType<TFormat, TFormatO>(0))::value;

    static constexpr bool HasSizeType = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasSizeType<TFormat, TFormatO>(0))::value;

    static constexpr bool HasConstantSize = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasSizeStaticConstantMember<TFormat, TFormatO>(0))::value;
            
    static constexpr bool HasConstantElementMaxExponent = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasElementMaxExponentStaticConstantMember<TFormat, 
                TFormatO>(0))::value;

    static constexpr bool HasExpandSplitFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasExpandSplitStaticMemberFunction<TFormat, 
                TFormatO>(0))::value;
    
    static constexpr bool HasExpandNegationValueFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasExpandNegationValueStaticMemberFunction<TFormat, 
                TFormatO>(0))::value;
                
    static constexpr bool HasExpandElementValueFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasExpandElementValueStaticMemberFunction<TFormat, 
                TFormatO>(0))::value;

    static constexpr bool HasExpandCarryValueFunction =decltype(
        test::_helper::_math::_integer::_fmt::
            _HasExpandCarryValueStaticMemberFunction<TFormat, 
                TFormatO>(0))::value;

    static constexpr bool HasLogElementValueFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasLogElementValueStaticMemberFunction<TFormat, 
                TFormatO>(0))::value;
        
    static constexpr bool HasShiftRightElementValueFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasShiftRightElementValueStaticMemberFunction<TFormat, 
                TFormatO>(0))::value;
    
    static constexpr bool HasShiftLeftElementValueFunction =  decltype(
        test::_helper::_math::_integer::_fmt::
            _HasShiftLeftElementValueStaticMemberFunction<TFormat, 
                TFormatO>(0))::value;

    static constexpr bool HasGetElementFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasGetElementStaticMemberFunction<TFormat, 
                TFormatO>(0))::value;
    
    static constexpr bool HasSetElementFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasSetElementStaticMemberFunction<TFormat, 
                TFormatO>(0))::value;

    static constexpr bool IsSame = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSame<TFormat, TFormatO>(0))::value;

    static constexpr bool IsSameElementType = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameElementType<TFormat, TFormatO>(0))::value;

    static constexpr bool IsSameExpandType = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameExpandType<TFormat, TFormatO>(0))::value;

    static constexpr bool IsSameSizeType = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameSizeType<TFormat, TFormatO>(0))::value;

    static constexpr bool IsSameConstantElementMaxExponent = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameElementMaxExponentStaticConstantMember<TFormat, 
                TFormatO>(0))::value;

    static constexpr bool IsSameExpandSplitFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameExpandSplitStaticMemberFunction<TFormat, 
                TFormatO>(0))::value;

    static constexpr bool IsSameExpandNegationValueFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameExpandNegationValueStaticMemberFunction<TFormat, 
                TFormatO>(0))::value;

    static constexpr bool IsSameExpandElementValueFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameExpandElementValueStaticMemberFunction<TFormat, 
                TFormatO>(0))::value;

    static constexpr bool IsSameExpandCarryValueFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameExpandCarryValueStaticMemberFunction<TFormat, 
                TFormatO>(0))::value;

    static constexpr bool IsSameLogElementValueFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameLogElementValueStaticMemberFunction<TFormat, 
                TFormatO>(0))::value;

    static constexpr bool IsSameShiftRightElementValueFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameShiftRightElementValueStaticMemberFunction<TFormat, 
                TFormatO>(0))::value;

    static constexpr bool IsSameShiftLeftElementValueFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameShiftLeftElementValueStaticMemberFunction<TFormat, 
                TFormatO>(0))::value;

    static constexpr int Size = 0;

    static constexpr int ElementMaxExponent = 0;
    
    static int ExpandSplit(...);
    static int ExpandNegationValue(...);
    static int ExpandElementValue(...);
    static int ExpandCarryValue(...);
    static int LogElementValue(...);
    static int ShiftRightElementValue(...);
    static int ShiftLeftElementValue(...);
    static int GetElement(...);
    static int SetElement(...);
    
};

template<typename TFormat, typename TFormatO>
struct Trait<TFormat, TFormatO, typename std::enable_if<
    decltype(test::_helper::_math::_integer::_fmt::
        _Has<TFormat, TFormatO>(0))::value &&
    decltype(test::_helper::_math::_integer::_fmt::
        _IsSame<TFormat, TFormatO>(0))::value, void>::type>
{
    typedef typename TFormat::ElementType ElementType;
    typedef typename TFormat::ExpandType ExpandType;
    typedef typename TFormat::SizeType SizeType;

    static constexpr bool Has = true;

    static constexpr bool HasElementType = true;

    static constexpr bool HasExpandType = true;

    static constexpr bool HasSizeType = true;

    static constexpr bool HasConstantSize = true;

    static constexpr bool HasConstantElementMaxExponent = true;

    static constexpr bool HasExpandSplitFunction = true;
    
    static constexpr bool HasExpandNegationValueFunction = true;
                
    static constexpr bool HasExpandElementValueFunction = true;

    static constexpr bool HasExpandCarryValueFunction = true;

    static constexpr bool HasLogElementValueFunction = true;

    static constexpr bool HasShiftRightElementValueFunction = true;

    static constexpr bool HasShiftLeftElementValueFunction = true;
    
    static constexpr bool HasGetElementFunction = true;

    static constexpr bool HasSetElementFunction = true;

    static constexpr bool IsSame = true;

    static constexpr bool IsSameElementType = true;

    static constexpr bool IsSameExpandType = true;

    static constexpr bool IsSameSizeType = true;
    
    static constexpr bool IsSameConstantElementMaxExponent = true;

    static constexpr bool IsSameExpandSplitFunction = true;

    static constexpr bool IsSameExpandNegationValueFunction = true;

    static constexpr bool IsSameExpandElementValueFunction = true;

    static constexpr bool IsSameExpandCarryValueFunction = true;

    static constexpr bool IsSameLogElementValueFunction = true;

    static constexpr bool IsSameShiftRightElementValueFunction = true;

    static constexpr bool IsSameShiftLeftElementValueFunction = true;

    static constexpr SizeType Size = TFormat::Size;

    static constexpr ElementType ElementMaxExponent = TFormat::ElementMaxExponent;

    static typename TFormat::ExpandType 
        ExpandSplit(const ExpandType& expand);
    static typename TFormat::ExpandType 
        ExpandNegationValue(const ExpandType& expand);
    static typename TFormat::ElementType 
        ExpandElementValue(const ExpandType& expand_split);
    static typename TFormat::ElementType 
        ExpandCarryValue(const ExpandType& expand_split);
    static typename TFormat::ElementType 
        LogElementValue(const ElementType& element);
    static typename TFormat::ElementType
        ShiftRightElementValue(const ElementType& element, const SizeType& n);
    static typename TFormat::ElementType
        ShiftLeftElementValue(const ElementType& element, const SizeType& n);
    static typename TFormat::ElementType GetElement(const TFormat& format,
        const SizeType& at);
    static typename TFormat::ElementType SetElement(TFormat& format,
        const SizeType& at, const ElementType& val);
};

template<typename TFormat, typename TFormatO, typename TVoid>
int Trait<TFormat, TFormatO, TVoid>::ExpandSplit(...)
{
    return 0;
}

template<typename TFormat, typename TFormatO, typename TVoid>
int Trait<TFormat, TFormatO, TVoid>::ExpandNegationValue(...)
{
    return 0;
}

template<typename TFormat, typename TFormatO, typename TVoid>
int Trait<TFormat, TFormatO, TVoid>::ExpandElementValue(...)
{
    return 0;
}

template<typename TFormat, typename TFormatO, typename TVoid>
int Trait<TFormat, TFormatO, TVoid>::ExpandCarryValue(...)
{
    return 0;
}

template<typename TFormat, typename TFormatO, typename TVoid>
int Trait<TFormat, TFormatO, TVoid>::LogElementValue(...)
{
    return 0;
}

template<typename TFormat, typename TFormatO, typename TVoid>
int Trait<TFormat, TFormatO, TVoid>::ShiftRightElementValue(...)
{
    return 0;
}

template<typename TFormat, typename TFormatO, typename TVoid>
int Trait<TFormat, TFormatO, TVoid>::ShiftLeftElementValue(...)
{
    return 0;
}

template<typename TFormat, typename TFormatO, typename TVoid>
int Trait<TFormat, TFormatO, TVoid>::GetElement(...)
{
    return 0;
}

template<typename TFormat, typename TFormatO, typename TVoid>
int Trait<TFormat, TFormatO, TVoid>::SetElement(...)
{
    return 0;
}

template<typename TFormat, typename TFormatO>
typename TFormat::ExpandType 
Trait<TFormat, TFormatO, typename std::enable_if<
    decltype(test::_helper::_math::_integer::_fmt::
        _Has<TFormat, TFormatO>(0))::value &&
    decltype(test::_helper::_math::_integer::_fmt::
        _IsSame<TFormat, TFormatO>(0))::value, void>::type>::
            ExpandSplit(const ExpandType& expand)
{
    return TFormat::ExpandSplit(expand);
}

template<typename TFormat, typename TFormatO>
typename TFormat::ExpandType 
Trait<TFormat, TFormatO, typename std::enable_if<
    decltype(test::_helper::_math::_integer::_fmt::
        _Has<TFormat, TFormatO>(0))::value &&
    decltype(test::_helper::_math::_integer::_fmt::
        _IsSame<TFormat, TFormatO>(0))::value, void>::type>::
            ExpandNegationValue(const ExpandType& expand)
{
    return TFormat::ExpandNegationValue(expand);
}

template<typename TFormat, typename TFormatO>
typename TFormat::ElementType 
Trait<TFormat, TFormatO, typename std::enable_if<
    decltype(test::_helper::_math::_integer::_fmt::
        _Has<TFormat, TFormatO>(0))::value &&
    decltype(test::_helper::_math::_integer::_fmt::
        _IsSame<TFormat, TFormatO>(0))::value, void>::type>::
            ExpandElementValue(const ExpandType& expand_split)
{
    return TFormat::ExpandElementValue(expand_split);
}

template<typename TFormat, typename TFormatO>
typename TFormat::ElementType 
Trait<TFormat, TFormatO, typename std::enable_if<
    decltype(test::_helper::_math::_integer::_fmt::
        _Has<TFormat, TFormatO>(0))::value &&
    decltype(test::_helper::_math::_integer::_fmt::
        _IsSame<TFormat, TFormatO>(0))::value, void>::type>::
            ExpandCarryValue(const ExpandType& expand_split)
{
    return TFormat::ExpandCarryValue(expand_split);
}

template<typename TFormat, typename TFormatO>
typename TFormat::ElementType 
Trait<TFormat, TFormatO, typename std::enable_if<
    decltype(test::_helper::_math::_integer::_fmt::
        _Has<TFormat, TFormatO>(0))::value &&
    decltype(test::_helper::_math::_integer::_fmt::
        _IsSame<TFormat, TFormatO>(0))::value, void>::type>::
            LogElementValue(const ElementType& element)
{
    return TFormat::LogElementValue(element);
}

template<typename TFormat, typename TFormatO>
typename TFormat::ElementType
Trait<TFormat, TFormatO, typename std::enable_if<
    decltype(test::_helper::_math::_integer::_fmt::
        _Has<TFormat, TFormatO>(0))::value &&
    decltype(test::_helper::_math::_integer::_fmt::
        _IsSame<TFormat, TFormatO>(0))::value, void>::type>::
            ShiftRightElementValue(const ElementType& element, 
                const SizeType& n)
{
    return TFormat::ShiftRightElementValue(element, n);
}


template<typename TFormat, typename TFormatO>
typename TFormat::ElementType
Trait<TFormat, TFormatO, typename std::enable_if<
    decltype(test::_helper::_math::_integer::_fmt::
        _Has<TFormat, TFormatO>(0))::value &&
    decltype(test::_helper::_math::_integer::_fmt::
        _IsSame<TFormat, TFormatO>(0))::value, void>::type>::
            ShiftLeftElementValue(const ElementType& element, 
                const SizeType& n)
{
    return TFormat::ShiftLeftElementValue(element, n);
}

template<typename TFormat, typename TFormatO>
typename TFormat::ElementType 
Trait<TFormat, TFormatO, typename std::enable_if<
    decltype(test::_helper::_math::_integer::_fmt::
        _Has<TFormat, TFormatO>(0))::value &&
    decltype(test::_helper::_math::_integer::_fmt::
        _IsSame<TFormat, TFormatO>(0))::value, void>::type>::
            GetElement(const TFormat& format, const SizeType& at)
{
    return TFormat::GetElement(format, at);
}

template<typename TFormat, typename TFormatO>
typename TFormat::ElementType 
Trait<TFormat, TFormatO, typename std::enable_if<
    decltype(test::_helper::_math::_integer::_fmt::
        _Has<TFormat, TFormatO>(0))::value &&
    decltype(test::_helper::_math::_integer::_fmt::
        _IsSame<TFormat, TFormatO>(0))::value, void>::type>::
            SetElement(TFormat& format, const SizeType& at,
                const ElementType& val)
{
    return TFormat::SetElement(format, at, val);
}


} //!fmt

} //!integer

} //!math

} //!test

#endif //!TEST_MATH_INTEGER_FMT_TRAIT_H_
