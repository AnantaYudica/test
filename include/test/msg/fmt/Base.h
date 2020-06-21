#ifndef TEST_MSG_FMT_BASE_H_
#define TEST_MSG_FMT_BASE_H_

#include "../Argument.h"
#include "../../Variable.h"
#include "../../out/CString.h"

namespace test
{
namespace msg
{
namespace fmt
{

template<typename TChar, typename TVar, typename TMsgArg>
class Base
{
public:
    typedef TMsgArg MessageArgumentType;
    typedef TVar VariableType;
    typedef typename test::out::CString<TChar>::SizeType SizeType;
private:
    Base() = default;
public:
    virtual ~Base() = default;
private:
    Base(const Base<TChar, TVar, TMsgArg>&) = default;
    Base(Base<TChar, TVar, TMsgArg>&&) = default;
public:
    virtual Base<TChar, TVar, TMsgArg>& 
        operator=(const Base<TChar, TVar, TMsgArg>&) = 0;
    virtual Base<TChar, TVar, TMsgArg>& 
        operator=(Base<TChar, TVar, TMsgArg>&&) = 0;
public:
    virtual SizeType Puts(test::out::CString<TChar>& out_cstr, 
        VariableType & var) const = 0;
};

template<typename TChar, typename... TVarArgs, typename TMsgArgCaseId, 
    typename... TMsgArgArgs>
class Base<TChar, test::Variable<TVarArgs...>, 
    test::msg::Argument<TMsgArgCaseId, TMsgArgArgs...>>
{
public:
    typedef test::msg::Argument<TMsgArgCaseId, TMsgArgArgs...> MessageArgumentType;
    typedef test::Variable<TVarArgs...> VariableType;
    typedef typename test::out::CString<TChar>::SizeType SizeType;
protected:
    Base() = default;
public:
    virtual ~Base() = default;
public:
    Base(const Base<TChar, test::Variable<TVarArgs...>, 
        test::msg::Argument<TMsgArgCaseId, TMsgArgArgs...>>&) = default;
    Base(Base<TChar, test::Variable<TVarArgs...>, 
        test::msg::Argument<TMsgArgCaseId, TMsgArgArgs...>>&&) = default;
public:
    virtual Base<TChar, test::Variable<TVarArgs...>, 
        test::msg::Argument<TMsgArgCaseId, TMsgArgArgs...>>& 
        operator=(const Base<TChar, test::Variable<TVarArgs...>, 
            test::msg::Argument<TMsgArgCaseId, TMsgArgArgs...>>&) = 0;
    virtual Base<TChar, test::Variable<TVarArgs...>, 
        test::msg::Argument<TMsgArgCaseId, TMsgArgArgs...>>& 
        operator=(Base<TChar, test::Variable<TVarArgs...>, 
            test::msg::Argument<TMsgArgCaseId, TMsgArgArgs...>>&&) = 0;
public:
    virtual SizeType Puts(test::out::CString<TChar>& out_cstr, 
        VariableType & var) const = 0;
};

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_BASE_H_
