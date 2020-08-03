#ifndef TEST_MSG_FMT_VAL_SPECIFIER_H_
#define TEST_MSG_FMT_VAL_SPECIFIER_H_

#include "../Parameter.h"

#include <utility>

namespace test
{
namespace msg
{
namespace fmt
{
namespace val
{

template<typename TChar>
class Specifier :
    public test::msg::fmt::Parameter<TChar>
{
public:
    typedef test::msg::fmt::Parameter<TChar> ParameterBaseType;
    typedef typename ParameterBaseType::StatusType StatusType;
    typedef typename StatusType::IntegerValueType IntegerValueStatusType;
    typedef typename ParameterBaseType::OutputInterfaceType 
        OutputInterfaceType;
protected:
    Specifier();
    Specifier(const IntegerValueStatusType& val);
public:
    virtual ~Specifier() = default;
protected:
    Specifier(const Specifier<TChar>& cpy);
    Specifier(Specifier<TChar>&& mov);
protected:
    Specifier<TChar>& operator=(const Specifier<TChar>& cpy);
    Specifier<TChar>& operator=(Specifier<TChar>&& mov);
public:
    virtual std::size_t VLoad(std::size_t size, std::size_t index, 
        va_list args) = 0;
    virtual std::size_t Load(std::size_t size, ...) = 0;
public:
    virtual typename OutputInterfaceType::SizeType
        Output(OutputInterfaceType& out) = 0;
public:
    virtual void Unset() = 0;
public:
    virtual bool IsSet() const = 0;
};

template<typename TChar>
Specifier<TChar>::Specifier() :
    ParameterBaseType()
{}

template<typename TChar>
Specifier<TChar>::Specifier(const IntegerValueStatusType& val) :
    ParameterBaseType(val)
{}

template<typename TChar>
Specifier<TChar>::Specifier(const Specifier<TChar>& cpy) :
    ParameterBaseType(cpy)
{}

template<typename TChar>
Specifier<TChar>::Specifier(Specifier<TChar>&& mov) :
    ParameterBaseType(std::move(mov))
{}

template<typename TChar>
Specifier<TChar>& Specifier<TChar>::operator=(const Specifier<TChar>& cpy)
{
    ParameterBaseType::operator=(cpy);
    return *this;
}

template<typename TChar>
Specifier<TChar>& Specifier<TChar>::operator=(Specifier<TChar>&& mov)
{
    ParameterBaseType::operator=(std::move(mov));
    return *this;
}

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_SPECIFIER_H_