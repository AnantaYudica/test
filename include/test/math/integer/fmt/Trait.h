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


template<typename T1, typename T2 = T1>
static constexpr auto _IsSameElementType(int) -> 
    decltype(std::declval<typename std::enable_if<
        std::is_same<typename T1::ElementType, 
            typename T2::ElementType>::value, int>::type>(), 
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type _IsSameElementType(...);

template<typename T1, typename T2 = T1>
static constexpr auto _IsSameExpandType(int) -> 
    decltype(std::declval<typename std::enable_if<
        std::is_same<typename T1::ExpandType, 
            typename T2::ExpandType>::value, int>::type>(), 
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type _IsSameExpandType(...);

template<typename T1, typename T2 = T1>
static constexpr auto _IsSameSizeType(int) -> 
    decltype(std::declval<typename std::enable_if<
        std::is_same<typename T1::SizeType, 
            typename T2::SizeType>::value, int>::type>(), 
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type _IsSameSizeType(...);

template<typename T1, typename T2 = T1>
static constexpr auto _IsSameElementMaxExponentStaticConstantMember(int) -> 
    decltype(std::declval<typename std::enable_if<
        T1::ElementMaxExponent == T2::ElementMaxExponent, int>::type>(), 
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type 
    _IsSameElementMaxExponentStaticConstantMember(...);

template<typename T1, typename T2 = T1>
static constexpr auto _IsSameExpandSplitStaticMemberFunction(int) -> 
    decltype(std::declval<typename std::enable_if<
        T1::ExpandSplit == T2::ExpandSplit, int>::type>(), 
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type _IsSameExpandSplitStaticMemberFunction(...);

template<typename T1, typename T2 = T1>
static constexpr auto _IsSameExpandNegationValueStaticMemberFunction(int) -> 
    decltype(std::declval<typename std::enable_if<
        T1::ExpandNegationValue == T2::ExpandNegationValue, int>::type>(), 
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type 
    _IsSameExpandNegationValueStaticMemberFunction(...);

template<typename T1, typename T2 = T1>
static constexpr auto _IsSameExpandElementValueStaticMemberFunction(int) -> 
    decltype(std::declval<typename std::enable_if<
        T1::ExpandElementValue == T2::ExpandElementValue, int>::type>(), 
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type 
    _IsSameExpandElementValueStaticMemberFunction(...);

template<typename T1, typename T2 = T1>
static constexpr auto _IsSameExpandCarryValueStaticMemberFunction(int) -> 
    decltype(std::declval<typename std::enable_if<
        T1::ExpandCarryValue == T2::ExpandCarryValue, int>::type>(), 
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type 
    _IsSameExpandCarryValueStaticMemberFunction(...);

template<typename T1, typename T2 = T1>
static constexpr auto _IsSameLogElementValueStaticMemberFunction(int) -> 
    decltype(std::declval<typename std::enable_if<
        T1::LogElementValue == T2::LogElementValue, int>::type>(), 
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type 
    _IsSameLogElementValueStaticMemberFunction(...);
    
template<typename T1, typename T2 = T1>
static constexpr auto _IsSameShiftRightElementValueStaticMemberFunction(int) ->
    decltype(std::declval<typename std::enable_if<
        T1::ShiftRightElementValue == T2::ShiftRightElementValue, 
            int>::type>(), 
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type 
    _IsSameShiftRightElementValueStaticMemberFunction(...);

template<typename T1, typename T2 = T1>
static constexpr auto _IsSameShiftLeftElementValueStaticMemberFunction(int) ->
    decltype(std::declval<typename std::enable_if<
        T1::ShiftLeftElementValue == T2::ShiftLeftElementValue, 
            int>::type>(), 
        std::true_type());

template<typename T1, typename T2 = T1>
static constexpr std::false_type 
    _IsSameShiftLeftElementValueStaticMemberFunction(...);

    
template<typename T1, typename T2 = T1>
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

template<typename T1, typename T2 = T1>
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

template<typename TFormat, typename... TArgs>
struct Trait
{
    static constexpr bool IsDefault = true;

    static constexpr bool IsInvalid = true;

};

template<typename TFormatA, typename TFormatB, typename... TArgs>
struct Trait<TFormatA, TFormatB, TArgs...> :
    std::conditional<
        decltype(test::_helper::_math::_integer::_fmt::
            _Has<TFormatA, TFormatB>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _IsSame<TFormatA, TFormatB>(0))::value,
        Trait<TFormatA, TArgs...>,
        Trait<std::pair<TFormatA*, TFormatB*>, TFormatA>>::type
{
    typedef typename std::conditional<
        decltype(test::_helper::_math::_integer::_fmt::
            _Has<TFormatA, TFormatB>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _IsSame<TFormatA, TFormatB>(0))::value,
        Trait<TFormatA, TArgs...>,
        Trait<std::pair<TFormatA*, TFormatB*>, TFormatA>>::type _BaseType;

    typedef typename _BaseType::ElementType ElementType;
    typedef typename _BaseType::ExpandType ExpandType;
    typedef typename _BaseType::SizeType SizeType;
    
    static constexpr bool IsDefault = _BaseType::IsDefault;

    static constexpr bool IsInvalid = _BaseType::IsInvalid;

    static constexpr bool Has = _BaseType::Has;

    static constexpr bool HasElementType = _BaseType::HasElementType;

    static constexpr bool HasExpandType = _BaseType::HasExpandType;

    static constexpr bool HasSizeType = _BaseType::HasSizeType;

    static constexpr bool HasConstantSize = _BaseType::HasConstantSize;
            
    static constexpr bool HasConstantElementMaxExponent = 
        _BaseType::HasConstantElementMaxExponent;

    static constexpr bool HasExpandSplitFunction = 
        _BaseType::HasExpandSplitFunction;
    
    static constexpr bool HasExpandNegationValueFunction = 
        _BaseType::HasExpandNegationValueFunction;
                
    static constexpr bool HasExpandElementValueFunction = 
        _BaseType::HasExpandElementValueFunction;

    static constexpr bool HasExpandCarryValueFunction =
        _BaseType::HasExpandCarryValueFunction;

    static constexpr bool HasLogElementValueFunction = 
        _BaseType::HasLogElementValueFunction;
        
    static constexpr bool HasShiftRightElementValueFunction = 
        _BaseType::HasShiftRightElementValueFunction;
    
    static constexpr bool HasShiftLeftElementValueFunction = 
        _BaseType::HasShiftLeftElementValueFunction;

    static constexpr bool HasGetElementFunction = 
        _BaseType::HasGetElementFunction;
    
    static constexpr bool HasSetElementFunction = 
        _BaseType::HasSetElementFunction;

    static constexpr bool IsSame = _BaseType::IsSame;

    static constexpr bool IsSameElementType = _BaseType::IsSameElementType;

    static constexpr bool IsSameExpandType = _BaseType::IsSameExpandType;

    static constexpr bool IsSameSizeType = _BaseType::IsSameSizeType;

    static constexpr bool IsSameConstantElementMaxExponent = 
        _BaseType::IsSameConstantElementMaxExponent;

    static constexpr bool IsSameExpandSplitFunction = 
        _BaseType::IsSameExpandSplitFunction;

    static constexpr bool IsSameExpandNegationValueFunction = 
        _BaseType::IsSameExpandNegationValueFunction;

    static constexpr bool IsSameExpandElementValueFunction = 
        _BaseType::IsSameExpandElementValueFunction;

    static constexpr bool IsSameExpandCarryValueFunction = 
        _BaseType::IsSameExpandCarryValueFunction;

    static constexpr bool IsSameLogElementValueFunction = 
        _BaseType::IsSameLogElementValueFunction;

    static constexpr bool IsSameShiftRightElementValueFunction = 
        _BaseType::IsSameShiftRightElementValueFunction;

    static constexpr bool IsSameShiftLeftElementValueFunction = 
        _BaseType::IsSameShiftLeftElementValueFunction;

    static constexpr int Size = _BaseType::Size;

    static constexpr int ElementMaxExponent = _BaseType::ElementMaxExponent;
    
    using _BaseType::ExpandSplit;
    using _BaseType::ExpandNegationValue;
    using _BaseType::ExpandElementValue;
    using _BaseType::ExpandCarryValue;
    using _BaseType::LogElementValue;
    using _BaseType::ShiftRightElementValue;
    using _BaseType::ShiftLeftElementValue;
    using _BaseType::GetElement;
    using _BaseType::SetElement;
};

template<typename TFormat>
struct Trait<TFormat> :
    Trait<typename std::conditional<
        decltype(test::_helper::_math::_integer::_fmt::
            _Has<TFormat>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _IsSame<TFormat>(0))::value, std::nullptr_t, 
                std::pair<TFormat*, TFormat*>>::type, TFormat>
{
    typedef Trait<typename std::conditional<
        decltype(test::_helper::_math::_integer::_fmt::
            _Has<TFormat, TFormat>(0))::value &&
        decltype(test::_helper::_math::_integer::_fmt::
            _IsSame<TFormat, TFormat>(0))::value, std::nullptr_t, 
                std::pair<TFormat*, TFormat*>>::type, TFormat> _BaseType;

    typedef typename _BaseType::ElementType ElementType;
    typedef typename _BaseType::ExpandType ExpandType;
    typedef typename _BaseType::SizeType SizeType;

    static constexpr bool IsDefault = _BaseType::IsDefault;

    static constexpr bool IsInvalid = _BaseType::IsInvalid;

    static constexpr bool Has = _BaseType::Has;

    static constexpr bool HasElementType = _BaseType::HasElementType;

    static constexpr bool HasExpandType = _BaseType::HasExpandType;

    static constexpr bool HasSizeType = _BaseType::HasSizeType;

    static constexpr bool HasConstantSize = _BaseType::HasConstantSize;
            
    static constexpr bool HasConstantElementMaxExponent = 
        _BaseType::HasConstantElementMaxExponent;

    static constexpr bool HasExpandSplitFunction = 
        _BaseType::HasExpandSplitFunction;
    
    static constexpr bool HasExpandNegationValueFunction = 
        _BaseType::HasExpandNegationValueFunction;
                
    static constexpr bool HasExpandElementValueFunction = 
        _BaseType::HasExpandElementValueFunction;

    static constexpr bool HasExpandCarryValueFunction =
        _BaseType::HasExpandCarryValueFunction;

    static constexpr bool HasLogElementValueFunction = 
        _BaseType::HasLogElementValueFunction;
        
    static constexpr bool HasShiftRightElementValueFunction = 
        _BaseType::HasShiftRightElementValueFunction;
    
    static constexpr bool HasShiftLeftElementValueFunction = 
        _BaseType::HasShiftLeftElementValueFunction;

    static constexpr bool HasGetElementFunction = 
        _BaseType::HasGetElementFunction;
    
    static constexpr bool HasSetElementFunction = 
        _BaseType::HasSetElementFunction;

    static constexpr bool IsSame = _BaseType::IsSame;

    static constexpr bool IsSameElementType = _BaseType::IsSameElementType;

    static constexpr bool IsSameExpandType = _BaseType::IsSameExpandType;

    static constexpr bool IsSameSizeType = _BaseType::IsSameSizeType;

    static constexpr bool IsSameConstantElementMaxExponent = 
        _BaseType::IsSameConstantElementMaxExponent;

    static constexpr bool IsSameExpandSplitFunction = 
        _BaseType::IsSameExpandSplitFunction;

    static constexpr bool IsSameExpandNegationValueFunction = 
        _BaseType::IsSameExpandNegationValueFunction;

    static constexpr bool IsSameExpandElementValueFunction = 
        _BaseType::IsSameExpandElementValueFunction;

    static constexpr bool IsSameExpandCarryValueFunction = 
        _BaseType::IsSameExpandCarryValueFunction;

    static constexpr bool IsSameLogElementValueFunction = 
        _BaseType::IsSameLogElementValueFunction;

    static constexpr bool IsSameShiftRightElementValueFunction = 
        _BaseType::IsSameShiftRightElementValueFunction;

    static constexpr bool IsSameShiftLeftElementValueFunction = 
        _BaseType::IsSameShiftLeftElementValueFunction;

    static constexpr int Size = _BaseType::Size;

    static constexpr int ElementMaxExponent = _BaseType::ElementMaxExponent;
    
    using _BaseType::ExpandSplit;
    using _BaseType::ExpandNegationValue;
    using _BaseType::ExpandElementValue;
    using _BaseType::ExpandCarryValue;
    using _BaseType::LogElementValue;
    using _BaseType::ShiftRightElementValue;
    using _BaseType::ShiftLeftElementValue;
    using _BaseType::GetElement;
    using _BaseType::SetElement;
};

template<typename TFormatA, typename TFormatB>
struct Trait<std::pair<TFormatA*, TFormatB*>, TFormatA>
{
    typedef int ElementType;
    typedef int ExpandType;
    typedef int SizeType;
    
    static constexpr bool IsDefault = false;

    static constexpr bool IsInvalid = true;

    static constexpr bool Has = decltype(
        test::_helper::_math::_integer::_fmt::
            _Has<TFormatA, TFormatB>(0))::value;

    static constexpr bool HasElementType = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasElementType<TFormatA, TFormatB>(0))::value;

    static constexpr bool HasExpandType = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasExpandType<TFormatA, TFormatB>(0))::value;

    static constexpr bool HasSizeType = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasSizeType<TFormatA, TFormatB>(0))::value;

    static constexpr bool HasConstantSize = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasSizeStaticConstantMember<TFormatA, TFormatB>(0))::value;
            
    static constexpr bool HasConstantElementMaxExponent = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasElementMaxExponentStaticConstantMember<TFormatA,
                TFormatB>(0))::value;

    static constexpr bool HasExpandSplitFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasExpandSplitStaticMemberFunction<TFormatA,
                TFormatB>(0))::value;
    
    static constexpr bool HasExpandNegationValueFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasExpandNegationValueStaticMemberFunction<TFormatA,
                TFormatB>(0))::value;
                
    static constexpr bool HasExpandElementValueFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasExpandElementValueStaticMemberFunction<TFormatA,
                TFormatB>(0))::value;

    static constexpr bool HasExpandCarryValueFunction =decltype(
        test::_helper::_math::_integer::_fmt::
            _HasExpandCarryValueStaticMemberFunction<TFormatA,
                TFormatB>(0))::value;

    static constexpr bool HasLogElementValueFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasLogElementValueStaticMemberFunction<TFormatA,
                TFormatB>(0))::value;
        
    static constexpr bool HasShiftRightElementValueFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasShiftRightElementValueStaticMemberFunction<TFormatA,
                TFormatB>(0))::value;
    
    static constexpr bool HasShiftLeftElementValueFunction =  decltype(
        test::_helper::_math::_integer::_fmt::
            _HasShiftLeftElementValueStaticMemberFunction<TFormatA,
                TFormatB>(0))::value;

    static constexpr bool HasGetElementFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasGetElementStaticMemberFunction<TFormatA,
                TFormatB>(0))::value;
    
    static constexpr bool HasSetElementFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _HasSetElementStaticMemberFunction<TFormatA,
                TFormatB>(0))::value;

    static constexpr bool IsSame = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSame<TFormatA, TFormatB>(0))::value;

    static constexpr bool IsSameElementType = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameElementType<TFormatA, TFormatB>(0))::value;

    static constexpr bool IsSameExpandType = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameExpandType<TFormatA, TFormatB>(0))::value;

    static constexpr bool IsSameSizeType = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameSizeType<TFormatA, TFormatB>(0))::value;

    static constexpr bool IsSameConstantElementMaxExponent = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameElementMaxExponentStaticConstantMember<TFormatA,
                TFormatB>(0))::value;

    static constexpr bool IsSameExpandSplitFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameExpandSplitStaticMemberFunction<TFormatA,
                TFormatB>(0))::value;

    static constexpr bool IsSameExpandNegationValueFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameExpandNegationValueStaticMemberFunction<TFormatA,
                TFormatB>(0))::value;

    static constexpr bool IsSameExpandElementValueFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameExpandElementValueStaticMemberFunction<TFormatA,
                TFormatB>(0))::value;

    static constexpr bool IsSameExpandCarryValueFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameExpandCarryValueStaticMemberFunction<TFormatA,
                TFormatB>(0))::value;

    static constexpr bool IsSameLogElementValueFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameLogElementValueStaticMemberFunction<TFormatA,
                TFormatB>(0))::value;

    static constexpr bool IsSameShiftRightElementValueFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameShiftRightElementValueStaticMemberFunction<
                TFormatA, TFormatB>(0))::value;

    static constexpr bool IsSameShiftLeftElementValueFunction = decltype(
        test::_helper::_math::_integer::_fmt::
            _IsSameShiftLeftElementValueStaticMemberFunction<
                TFormatA, TFormatB>(0))::value;

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

template<typename TFormat>
struct Trait<std::nullptr_t, TFormat>
{
    typedef typename TFormat::ElementType ElementType;
    typedef typename TFormat::ExpandType ExpandType;
    typedef typename TFormat::SizeType SizeType;

    static constexpr bool IsDefault = false;

    static constexpr bool IsInvalid = false;

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

    static constexpr ElementType ElementMaxExponent = 
        TFormat::ElementMaxExponent;

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

template<typename TFormatA, typename TFormatB>
int Trait<std::pair<TFormatA*, TFormatB*>, TFormatA>::ExpandSplit(...)
{
    return 0;
}

template<typename TFormatA, typename TFormatB>
int Trait<std::pair<TFormatA*, TFormatB*>, TFormatA>::
    ExpandNegationValue(...)
{
    return 0;
}

template<typename TFormatA, typename TFormatB>
int Trait<std::pair<TFormatA*, TFormatB*>, TFormatA>::
    ExpandElementValue(...)
{
    return 0;
}

template<typename TFormatA, typename TFormatB>
int Trait<std::pair<TFormatA*, TFormatB*>, TFormatA>::
    ExpandCarryValue(...)
{
    return 0;
}

template<typename TFormatA, typename TFormatB>
int Trait<std::pair<TFormatA*, TFormatB*>, TFormatA>::
    LogElementValue(...)
{
    return 0;
}

template<typename TFormatA, typename TFormatB>
int Trait<std::pair<TFormatA*, TFormatB*>, TFormatA>::
    ShiftRightElementValue(...)
{
    return 0;
}

template<typename TFormatA, typename TFormatB>
int Trait<std::pair<TFormatA*, TFormatB*>, TFormatA>::
    ShiftLeftElementValue(...)
{
    return 0;
}

template<typename TFormatA, typename TFormatB>
int Trait<std::pair<TFormatA*, TFormatB*>, TFormatA>::GetElement(...)
{
    return 0;
}

template<typename TFormatA, typename TFormatB>
int Trait<std::pair<TFormatA*, TFormatB*>, TFormatA>::SetElement(...)
{
    return 0;
}

template<typename TFormat>
typename TFormat::ExpandType 
Trait<std::nullptr_t, TFormat>::ExpandSplit(const ExpandType& expand)
{
    return TFormat::ExpandSplit(expand);
}

template<typename TFormat>
typename TFormat::ExpandType 
Trait<std::nullptr_t, TFormat>::ExpandNegationValue(const ExpandType& expand)
{
    return TFormat::ExpandNegationValue(expand);
}

template<typename TFormat>
typename TFormat::ElementType 
Trait<std::nullptr_t, TFormat>::
    ExpandElementValue(const ExpandType& expand_split)
{
    return TFormat::ExpandElementValue(expand_split);
}

template<typename TFormat>
typename TFormat::ElementType 
Trait<std::nullptr_t, TFormat>::
    ExpandCarryValue(const ExpandType& expand_split)
{
    return TFormat::ExpandCarryValue(expand_split);
}

template<typename TFormat>
typename TFormat::ElementType 
Trait<std::nullptr_t, TFormat>::LogElementValue(const ElementType& element)
{
    return TFormat::LogElementValue(element);
}

template<typename TFormat>
typename TFormat::ElementType
Trait<std::nullptr_t, TFormat>::
    ShiftRightElementValue(const ElementType& element, const SizeType& n)
{
    return TFormat::ShiftRightElementValue(element, n);
}


template<typename TFormat>
typename TFormat::ElementType
Trait<std::nullptr_t, TFormat>::
    ShiftLeftElementValue(const ElementType& element, const SizeType& n)
{
    return TFormat::ShiftLeftElementValue(element, n);
}

template<typename TFormat>
typename TFormat::ElementType 
Trait<std::nullptr_t, TFormat>::GetElement(const TFormat& format, 
    const SizeType& at)
{
    return TFormat::GetElement(format, at);
}

template<typename TFormat>
typename TFormat::ElementType 
Trait<std::nullptr_t, TFormat>::SetElement(TFormat& format, const SizeType& at,
    const ElementType& val)
{
    return TFormat::SetElement(format, at, val);
}

} //!fmt

} //!integer

} //!math

} //!test

#endif //!TEST_MATH_INTEGER_FMT_TRAIT_H_
