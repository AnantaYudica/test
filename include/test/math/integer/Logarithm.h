#ifndef TEST_MATH_INTEGER_LOGARITHM_H_
#define TEST_MATH_INTEGER_LOGARITHM_H_

namespace test
{
namespace math
{
namespace integer
{

namespace log
{
    
enum class Flag : int
{
    Ok = 0,
    ZeroValue
};

} //!log

template<typename TElementValue, typename TValue,
    typename TExpandValue, typename TSize, TSize N,
    TExpandValue(FGetValue)(const TValue&, const TSize&),
    TElementValue(FLogValue)(const TElementValue&),
    TSize NElementP1MaxExponent = 0>
static test::math::integer::log::Flag Logarithm(const TValue& v, 
    TSize& value_out, TElementValue* elem_out = nullptr, 
    TSize* at_out = nullptr)
{
    TElementValue elem_def;
    TSize at_def;

    TElementValue* elem_ptr = elem_out != nullptr ? elem_out : &elem_def;
    TSize* at_ptr = at_out != nullptr ? at_out : &at_def;

    for(TSize i = N; i > 0; --i)
    {
        auto elem = FGetValue(v, i - 1);
        if (elem == 0) continue;
        *elem_ptr = FLogValue(elem);
        *at_ptr = i - 1;
        value_out = *elem_ptr + (*at_ptr * NElementP1MaxExponent);
        return test::math::integer::log::Flag::Ok;
    }

    *elem_ptr = 0;
    *at_ptr = 0;
    value_out = 0;
    return test::math::integer::log::Flag::ZeroValue;
}

} //!integer

} //!math

} //!test

#endif //!TEST_MATH_INTEGER_LOGARITHM_H_
