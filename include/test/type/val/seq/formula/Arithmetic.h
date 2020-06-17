#ifndef TEST_TYPE_VAL_SEQ_FORMULA_ARITHMETIC_H_
#define TEST_TYPE_VAL_SEQ_FORMULA_ARITHMETIC_H_

#include <utility>

namespace test
{
namespace type
{
namespace val
{
namespace seq
{
namespace formula
{

template<typename TValue, typename TDiff, TDiff Diff>
struct Arithmetic
{
    static constexpr TValue Formula(const TValue& first_value, 
        const std::size_t& term);
};

template<typename TValue, typename TDiff, TDiff Diff>
constexpr TValue Arithmetic<TValue, TDiff, Diff>::
    Formula(const TValue& first_value, const std::size_t& term)
{
    return first_value + TValue(Diff * term);
}

} //!formula

} //!seq

} //!val

} //!type

} //!test

#endif //!TEST_TYPE_VAL_SEQ_FORMULA_ARITHMETIC_H_
