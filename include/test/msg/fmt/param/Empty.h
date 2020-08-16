#ifndef TEST_MSG_FMT_PARAM_EMPTY_H_
#define TEST_MSG_FMT_PARAM_EMPTY_H_

#include "../Parameter.h"

#include <cstdarg>
#include <utility>
#include <type_traits>

namespace test
{
namespace msg
{
namespace fmt
{
namespace var
{

typedef void Empty;

} //!var

template<typename TChar>
class Parameter<TChar, test::msg::fmt::var::Empty> :
    public Parameter<TChar>
{
public:
    typedef typename Parameter<TChar>::StatusType StatusType;
    typedef typename StatusType::ValueType ValueStatusType;
    typedef typename StatusType::IntegerValueType IntegerValueStatusType;
    typedef typename Parameter<TChar>::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename Parameter<TChar>::StatusPointerType StatusPointerType;
public:
    Parameter();
public:
    Parameter(StatusPointerType&& status);
public:
    virtual ~Parameter();
public:
    Parameter(const Parameter<TChar, test::msg::fmt::var::Empty>& cpy);
    Parameter(Parameter<TChar, test::msg::fmt::var::Empty>&& mov);
public:
    Parameter<TChar, test::msg::fmt::var::Empty>& 
        operator=(const Parameter<TChar, test::msg::fmt::var::Empty>& cpy);
    Parameter<TChar, test::msg::fmt::var::Empty>& 
        operator=(Parameter<TChar, test::msg::fmt::var::Empty>&& mov);
public:
    virtual std::size_t VLoad(std::size_t size, std::size_t index, 
        va_list& args) override;
    virtual std::size_t Load(std::size_t size, ...) override;
public:
    virtual typename OutputInterfaceType::SizeType 
        Output(OutputInterfaceType& out) override;
public:
    virtual void Unset() override;
public:
    virtual bool IsSet() const override;
};

template<typename TChar>
Parameter<TChar, test::msg::fmt::var::Empty>::Parameter() :
    Parameter<TChar>()
{}

template<typename TChar>
Parameter<TChar, test::msg::fmt::var::Empty>::
    Parameter(StatusPointerType&& status) :
        Parameter<TChar>()
{}

template<typename TChar>
Parameter<TChar, test::msg::fmt::var::Empty>::~Parameter()
{}

template<typename TChar>
Parameter<TChar, test::msg::fmt::var::Empty>::
    Parameter(const Parameter<TChar, test::msg::fmt::var::Empty>& cpy) :
        Parameter<TChar>(cpy)
{}

template<typename TChar>
Parameter<TChar, test::msg::fmt::var::Empty>::
    Parameter(Parameter<TChar, test::msg::fmt::var::Empty>&& mov) :
        Parameter<TChar>(std::move(mov))
{}

template<typename TChar>
Parameter<TChar, test::msg::fmt::var::Empty>& 
Parameter<TChar, test::msg::fmt::var::Empty>::
    operator=(const Parameter<TChar, test::msg::fmt::var::Empty>& cpy)
{
    Parameter<TChar>::operator=(cpy);
    return *this;
}
    
template<typename TChar>
Parameter<TChar, test::msg::fmt::var::Empty>& 
Parameter<TChar, test::msg::fmt::var::Empty>::
    operator=(Parameter<TChar, test::msg::fmt::var::Empty>&& mov)
{
    Parameter<TChar>::operator=(std::move(mov));
    return *this;
}
    
template<typename TChar>
std::size_t Parameter<TChar, test::msg::fmt::var::Empty>::
    VLoad(std::size_t, std::size_t index, va_list&)
{
    return index;
}
    
template<typename TChar>
std::size_t 
Parameter<TChar, test::msg::fmt::var::Empty>::Load(std::size_t, ...)
{
    return 0;
}

template<typename TChar>
typename Parameter<TChar, test::msg::fmt::var::Empty>::
    OutputInterfaceType::SizeType 
Parameter<TChar, test::msg::fmt::var::Empty>::Output(OutputInterfaceType&)
{
    return 0;
}

template<typename TChar>
void Parameter<TChar, test::msg::fmt::var::Empty>::Unset()
{}

template<typename TChar>
bool Parameter<TChar, test::msg::fmt::var::Empty>::IsSet() const 
{
    return false;
}

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_PARAM_EMPTY_H_
