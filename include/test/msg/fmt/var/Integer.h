#ifndef TEST_MSG_FMT_VAR_INTEGER_H_
#define TEST_MSG_FMT_VAR_INTEGER_H_

#include "../Parameter.h"
#include "../val/specifier/Integer.h"

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

template<typename TChar>
class Integer :
    public test::msg::fmt::Parameter<TChar>
{
public:
    typedef test::msg::fmt::val::specifier::Integer<TChar> SpecifierType;
    typedef test::msg::fmt::Parameter<TChar> BaseType;
    typedef typename BaseType::OutputInterfaceType OutputInterfaceType;
private:
    SpecifierType m_specifier;
public:
    Integer();
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_reference<
            typename std::remove_cv<TArg>::type>::type,
        typename std::enable_if<!std::is_same<_TArg, 
            Integer<TChar>>::value, int>::type = 0>
    Integer(TArg&& arg, TArgs&&... args);
public:
    ~Integer();
public:
    Integer(const Integer<TChar>& cpy);
    Integer(Integer<TChar>&& mov);
public:
    Integer<TChar>& operator=(const Integer<TChar>& cpy);
    Integer<TChar>& operator=(Integer<TChar>&& mov);
public:
    std::size_t VLoad(std::size_t size, std::size_t index, va_list& args);
    std::size_t Load(std::size_t size, ...);
public:
    typename OutputInterfaceType::SizeType Output(OutputInterfaceType& out);
public:
    void Unset();
public:
    bool IsSet() const;
};

template<typename TChar>
Integer<TChar>::Integer() :
    test::msg::fmt::Parameter<TChar>(),
    m_specifier()
{}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_same<_TArg, 
        Integer<TChar>>::value, int>::type>
Integer<TChar>::Integer(TArg&& arg, TArgs&&... args) :
    test::msg::fmt::Parameter<TChar>(),
    m_specifier(std::forward<TArg>(arg), std::forward<TArgs>(args)...)
{}

template<typename TChar>
Integer<TChar>::~Integer()
{}

template<typename TChar>
Integer<TChar>::Integer(const Integer<TChar>& cpy) :
    test::msg::fmt::Parameter<TChar>(cpy),
    m_specifier(cpy.m_specifier)
{}

template<typename TChar>
Integer<TChar>::Integer(Integer<TChar>&& mov) :
    test::msg::fmt::Parameter<TChar>(std::move(mov)),
    m_specifier(std::move(mov.m_specifier))
{}

template<typename TChar>
Integer<TChar>& Integer<TChar>::operator=(const Integer<TChar>& cpy)
{
    test::msg::fmt::Parameter<TChar>::operator=(cpy);
    m_specifier = cpy.m_specifier;
    return *this;
}

template<typename TChar>
Integer<TChar>& Integer<TChar>::operator=(Integer<TChar>&& mov)
{
    test::msg::fmt::Parameter<TChar>::operator=(std::move(mov));
    m_specifier = std::move(mov.m_specifier);
    return *this;
}

template<typename TChar>
std::size_t Integer<TChar>::VLoad(std::size_t size, std::size_t index, 
    va_list& args)
{
    return m_specifier.VLoad(size, index, args);
}

template<typename TChar>
std::size_t Integer<TChar>::Load(std::size_t size, ...)
{
    va_list args;
    va_start(args, size);
    auto ret = VLoad(size, 0, args);
    va_end(args);
    return ret;
}

template<typename TChar>
typename Integer<TChar>::OutputInterfaceType::SizeType 
Integer<TChar>::Output(OutputInterfaceType& out)
{
    return m_specifier.Output(out);
}

template<typename TChar>
void Integer<TChar>::Unset()
{
    m_specifier.Unset();
}

template<typename TChar>
bool Integer<TChar>::IsSet() const
{
    return m_specifier.IsSet();
}

} //!var

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAR_INTEGER_H_