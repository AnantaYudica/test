#ifndef TEST_MSG_FMT_VAR_CHARACTER_H_
#define TEST_MSG_FMT_VAR_CHARACTER_H_

#include "../Parameter.h"
#include "../val/specifier/Character.h"

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
class Character :
    public test::msg::fmt::Parameter<TChar>
{
public:
    typedef test::msg::fmt::val::specifier::Character<TChar> SpecifierType;
    typedef test::msg::fmt::Parameter<TChar> BaseType;
    typedef typename BaseType::OutputInterfaceType OutputInterfaceType;
private:
    SpecifierType m_specifier;
public:
    Character();
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_reference<
            typename std::remove_cv<TArg>::type>::type,
        typename std::enable_if<!std::is_same<_TArg, Character<TChar>>::value, 
            int>::type = 0>
    Character(TArg&& arg, TArgs&&... args);
public:
    ~Character();
public:
    Character(const Character<TChar>& cpy);
    Character(Character<TChar>&& mov);
public:
    Character<TChar>& operator=(const Character<TChar>& cpy);
    Character<TChar>& operator=(Character<TChar>&& mov);
public:
    std::size_t VLoad(std::size_t size, std::size_t index, va_list args);
    std::size_t Load(std::size_t size, ...);
public:
    typename OutputInterfaceType::SizeType Output(OutputInterfaceType& out);
public:
    void Unset();
public:
    bool IsSet() const;
};

template<typename TChar>
Character<TChar>::Character() :
    test::msg::fmt::Parameter<TChar>(),
    m_specifier()
{}

template<typename TChar>
template<typename TArg, typename... TArgs,  typename _TArg,
    typename std::enable_if<!std::is_same<_TArg, Character<TChar>>::value, 
        int>::type>
Character<TChar>::Character(TArg&& arg, TArgs&&... args) :
    test::msg::fmt::Parameter<TChar>(),
    m_specifier(std::forward<TArg>(arg), std::forward<TArgs>(args)...)
{}

template<typename TChar>
Character<TChar>::~Character()
{}

template<typename TChar>
Character<TChar>::Character(const Character<TChar>& cpy) :
    test::msg::fmt::Parameter<TChar>(cpy),
    m_specifier(cpy.m_specifier)
{}

template<typename TChar>
Character<TChar>::Character(Character<TChar>&& mov) :
    test::msg::fmt::Parameter<TChar>(std::move(mov)),
    m_specifier(std::move(mov.m_specifier))
{}

template<typename TChar>
Character<TChar>& Character<TChar>::operator=(const Character<TChar>& cpy)
{
    test::msg::fmt::Parameter<TChar>::operator=(cpy);
    m_specifier = cpy.m_specifier;
    return *this;
}

template<typename TChar>
Character<TChar>& Character<TChar>::operator=(Character<TChar>&& mov)
{
    test::msg::fmt::Parameter<TChar>::operator=(std::move(mov));
    m_specifier = std::move(mov.m_specifier);
    return *this;
}

template<typename TChar>
std::size_t Character<TChar>::VLoad(std::size_t size, std::size_t index, 
    va_list args)
{
    return m_specifier.VLoad(size, index, args);
}

template<typename TChar>
std::size_t Character<TChar>::Load(std::size_t size, ...)
{
    va_list args;
    va_start(args, size);
    auto ret = VLoad(size, 0, args);
    va_end(args);
    return ret;
}

template<typename TChar>
typename Character<TChar>::OutputInterfaceType::SizeType 
Character<TChar>::Output(OutputInterfaceType& out)
{
    return m_specifier.Output(out);
}

template<typename TChar>
void Character<TChar>::Unset()
{
    m_specifier.Unset();
}

template<typename TChar>
bool Character<TChar>::IsSet() const
{
    return m_specifier.IsSet();
}

} //!var

} //!fmt

} //!msg

} //!test


#endif //!TEST_MSG_FMT_VAR_CHARACTER_H_