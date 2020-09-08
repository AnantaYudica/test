#ifndef TEST_MESSAGE_H_
#define TEST_MESSAGE_H_

#include "trait/type/index/IsBaseOf.h"
#include "Variable.h"
#include "var/Value.h"
#include "var/type/Function.h"
#include "var/type/Value.h"
#include "var/type/val/Sequence.h"
#include "var/val/Function.h"
#include "var/val/Sequence.h"
#include "var/val/Parameter.h"

#include "msg/Base.h"

#include "type/Index.h"

#include <cstddef>
#include <type_traits>

namespace test
{

template<typename TTest, typename TDerived>
class Message
{
private:
    TDerived& m_derived;
protected:
    Message(TDerived& d);
public:
    template<typename TTag, typename TCaseId, typename... TVarArgs, 
        typename... TArgs, typename std::enable_if<
        !test::trait::type::index::IsBaseOf<TTag>::Value, int>::type = 0>
    std::size_t Output(const TTag & tag, const TCaseId&, 
        test::Variable<TVarArgs...>& var, TArgs&&... args);
    template<typename TTag, typename TCaseId, std::size_t IAt,
        typename... TVarArgs, typename... TArgs>
    std::size_t Output(const test::type::Index<TTag, IAt> & index_tag, 
        const TCaseId&, test::Variable<TVarArgs...>& var, TArgs&&... args);
public:
    template<typename TCaseId, typename... TVarArgs, typename... TArgs>
    std::size_t Info(const TCaseId&, test::Variable<TVarArgs...>& var,
        TArgs&&... args);
    template<typename TCaseId, typename... TVarArgs, typename... TArgs>
    std::size_t Debug(const TCaseId&, test::Variable<TVarArgs...>& var,
        TArgs&&... args);
    template<typename TCaseId, typename... TVarArgs, typename... TArgs>
    std::size_t Error(const TCaseId&, test::Variable<TVarArgs...>& var,
        TArgs&&... args);
public:
    template<std::size_t I, typename TCaseId, typename... TVarArgs, 
        typename... TArgs>
    std::size_t IndexInfo(const TCaseId&, test::Variable<TVarArgs...>& var,
        TArgs&&... args);
    template<std::size_t I, typename TCaseId, typename... TVarArgs, 
        typename... TArgs>
    std::size_t IndexDebug(const TCaseId&, test::Variable<TVarArgs...>& var,
        TArgs&&... args);
    template<std::size_t I, typename TCaseId, typename... TVarArgs, 
        typename... TArgs>
    std::size_t IndexError(const TCaseId&, test::Variable<TVarArgs...>& var,
        TArgs&&... args);
};

template<typename TTest, typename TDerived>
Message<TTest, TDerived>::Message(TDerived& d) :
    m_derived(d)
{}

template<typename TTest, typename TDerived>
template<typename TTag, typename TCaseId, typename... TVarArgs, 
    typename... TArgs, typename std::enable_if<
    !test::trait::type::index::IsBaseOf<TTag>::Value, int>::type>
std::size_t Message<TTest, TDerived>::Output(const TTag & tag, 
    const TCaseId& case_id, test::Variable<TVarArgs...>& var, TArgs&&... args)
{
    auto& out = TTest::GetInstance().Output();
    auto fmt = m_derived.GetFormat(case_id, tag);
    std::size_t ret = 0;
    {
        auto log = out.Log(tag);
        if (log.IsBad()) return 0;
        auto arg = m_derived.GetArgument(case_id, tag);
        ret = arg.template Call<std::size_t>(case_id, 
            &test::msg::Format<char>::Output, 
            fmt, var, (test::out::Interface<char>&)log, 
            std::forward<TArgs>(args)...);
    }
    fmt.Unset();
    return ret;
}

template<typename TTest, typename TDerived>
template<typename TTag, typename TCaseId, std::size_t IAt,
    typename... TVarArgs, typename... TArgs>
std::size_t Message<TTest, TDerived>::Output(const test::type::Index<TTag, 
    IAt> & index_tag, const TCaseId& case_id, test::Variable<TVarArgs...>& var,
    TArgs&&... args)
{
    auto& out = TTest::GetInstance().Output();
    auto fmt = m_derived.GetFormat(case_id, index_tag);
    std::size_t ret = 0;
    {
        auto log = out.Log(TTag{});
        if (log.IsBad()) return 0;
        auto arg = m_derived.GetArgument(case_id, index_tag);
        ret = arg.template Call<std::size_t>(case_id, 
            &test::msg::Format<char>::Output, 
            fmt, var, (test::out::Interface<char>&)log, 
            std::forward<TArgs>(args)...);
    }
    fmt.Unset();
    return ret;
}

template<typename TTest, typename TDerived>
template<typename TCaseId, typename... TVarArgs, typename... TArgs>
std::size_t Message<TTest, TDerived>::Info(const TCaseId& case_id, 
    test::Variable<TVarArgs...>& var, TArgs&&... args)
{
    return Output(test::out::tag::Info{}, case_id, var,
        std::forward<TArgs>(args)...);
}

template<typename TTest, typename TDerived>
template<typename TCaseId, typename... TVarArgs, typename... TArgs>
std::size_t Message<TTest, TDerived>::Debug(const TCaseId& case_id,
    test::Variable<TVarArgs...>& var, TArgs&&... args)
{
    return Output(test::out::tag::Debug{}, case_id, var,
        std::forward<TArgs>(args)...);
}

template<typename TTest, typename TDerived>
template<typename TCaseId, typename... TVarArgs, typename... TArgs>
std::size_t Message<TTest, TDerived>::Error(const TCaseId& case_id,
    test::Variable<TVarArgs...>& var, TArgs&&... args)
{
    return Output(test::out::tag::Error{}, case_id, var,
        std::forward<TArgs>(args)...);
}

template<typename TTest, typename TDerived>
template<std::size_t I, typename TCaseId, typename... TVarArgs, 
    typename... TArgs>
std::size_t Message<TTest, TDerived>::IndexInfo(const TCaseId& case_id, 
    test::Variable<TVarArgs...>& var, TArgs&&... args)
{
    return Output(test::type::Index<test::out::tag::Info, I>{}, case_id, var,
        std::forward<TArgs>(args)...);
}
    
template<typename TTest, typename TDerived>
template<std::size_t I, typename TCaseId, typename... TVarArgs, 
    typename... TArgs>
std::size_t Message<TTest, TDerived>::IndexDebug(const TCaseId& case_id, 
    test::Variable<TVarArgs...>& var, TArgs&&... args)
{
    return Output(test::type::Index<test::out::tag::Debug, I>{}, case_id, var,
        std::forward<TArgs>(args)...);
}
    
template<typename TTest, typename TDerived>
template<std::size_t I, typename TCaseId, typename... TVarArgs, 
    typename... TArgs>
std::size_t Message<TTest, TDerived>::IndexError(const TCaseId& case_id, 
    test::Variable<TVarArgs...>& var, TArgs&&... args)
{
    return Output(test::type::Index<test::out::tag::Error, I>{}, case_id, var,
        std::forward<TArgs>(args)...);
}
    
} //!test

#endif //!TEST_MESSAGE_H_
