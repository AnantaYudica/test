#ifndef TEST_MSG_BASE_H_
#define TEST_MSG_BASE_H_

#include "../type/Index.h"
#include "../trait/type/index/IsBaseOf.h"
#include "Format.h"
#include "Argument.h"
#include "Tag.h"
#include "Case.h"

#include <type_traits>

namespace test
{
namespace msg
{

template<typename TChar, typename... TCaseArgs>
class Base
{
public:
    typedef test::msg::Format<TChar> FormatType;
    typedef void CaseType;
    typedef test::msg::Argument<> ArgumentType;
public:
    template<typename _TCaseId>
    using HasCaseType = std::false_type;
protected:
    template<typename _TCaseId>
    using GetBaseType = Base<TChar, TCaseArgs...>;
protected:
    Base();
public:
    ~Base();
protected:
    void GetCase();
protected:
    template<typename TCaseId, typename TTag, typename... TArgs>
    void SetFormat(...);
public:
    template<typename TCaseId, typename TTag>
    FormatType GetFormat(...) const;
public:
    template<typename TCaseId, typename TTag>
    ArgumentType GetArgument(...) const;
};

template<typename TChar, typename TId, typename... TTagArgs, 
    typename... TCaseArgs>
class Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
    TCaseArgs...> : public Base<TChar, TCaseArgs...>,
        public test::msg::Case<TId, TChar, TTagArgs...>
{
public:
    typedef test::msg::Format<TChar> FormatType;
    typedef test::msg::Case<TId, TChar, TTagArgs...> CaseType;
    typedef typename CaseType::ArgumentType ArgumentType;
public:
    template<typename _TCaseId>
    using HasCaseType = typename std::conditional<
        std::is_same<_TCaseId, TId>::value, std::true_type,
        typename Base<TChar, TCaseArgs...>::template HasCaseType<
            _TCaseId>>::type;
protected:
    template<typename _TCaseId>
    using GetBaseType = typename std::conditional<
        std::is_same<_TCaseId, TId>::value,
        Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
            TCaseArgs...>,
        typename Base<TChar, TCaseArgs...>::template GetBaseType<
            _TCaseId>>::type;
protected:
    template<typename _TCaseId, typename _TTag>
    using GetArgumentType = decltype(std::declval<typename GetBaseType<
        _TCaseId>::CaseType*>()->GetArgument(std::declval<_TTag>()));
protected:
    Base();
public:
    ~Base();
protected:
    CaseType& GetCase();
    const CaseType& GetCase() const;
protected:
    template<typename TTag, typename... TArgs,
        typename _TTag = typename std::remove_cv<typename std::remove_pointer<
            typename std::remove_reference<TTag>::type>::type>::type,
        typename _THasCase = HasCaseType<_TTag>,
        typename std::enable_if<!_THasCase::value, int>::type = 0>
    void SetFormat(TTag&&, TArgs&&...);
    template<typename TCaseId, typename TTag, typename... TArgs,
        typename _THasCase = HasCaseType<TCaseId>,
        typename std::enable_if<_THasCase::value, int>::type = 0>
    void SetFormat(const TCaseId&, TTag&&, TArgs&&...);
public:
    template<typename TCaseId, typename TTag, typename _THasCase = 
        HasCaseType<TCaseId>, typename std::enable_if<
        (!test::trait::type::index::IsBaseOf<TCaseId>::Value &&
        !test::trait::type::index::IsBaseOf<TTag>::Value) &&
        _THasCase::value, int>::type = 0>
    FormatType GetFormat(const TCaseId&, const TTag&) const;
    template<typename TCaseId, typename TTag, std::size_t ITAgAt, 
        typename _THasCase = HasCaseType<TCaseId>,
        typename std::enable_if<!test::trait::type::index::IsBaseOf<
            TCaseId>::Value && _THasCase::value, int>::type = 0>
    FormatType GetFormat(const TCaseId&, 
        const test::type::Index<TTag, ITAgAt>&) const;
    template<typename TCaseId, typename TTag, std::size_t ICaseId, 
        typename _THasCase = HasCaseType<TCaseId>,
        typename std::enable_if<!test::trait::type::index::IsBaseOf<
            TTag>::Value && _THasCase::value, int>::type = 0>
    FormatType GetFormat(const test::type::Index<TCaseId, ICaseId>&, 
        const TTag&) const;
    template<typename TCaseId, typename TTag, std::size_t ICaseId, 
        std::size_t ITAgAt, typename _THasCase = HasCaseType<TCaseId>,
        typename std::enable_if<_THasCase::value, int>::type = 0>
    FormatType GetFormat(const test::type::Index<TCaseId, ICaseId>&, 
        const test::type::Index<TTag, ITAgAt>&) const;
public:
    template<typename TCaseId, typename TTag, typename _TRet = 
        GetArgumentType<TCaseId, TTag>, typename _THasCase = 
        HasCaseType<TCaseId>, typename std::enable_if<
        (!test::trait::type::index::IsBaseOf<TCaseId>::Value &&
        !test::trait::type::index::IsBaseOf<TTag>::Value) &&
        _THasCase::value, int>::type = 0>
    _TRet GetArgument(const TCaseId&, const TTag&) const;
    template<typename TCaseId, typename TTag, std::size_t ITAgAt, 
        typename _TRet = GetArgumentType<TCaseId, test::type::Index<TTag, 
        ITAgAt>>, typename _THasCase = HasCaseType<TCaseId>, 
        typename std::enable_if<!test::trait::type::index::IsBaseOf<
            TCaseId>::Value && _THasCase::value, int>::type = 0>
    _TRet GetArgument(const TCaseId&, 
        const test::type::Index<TTag, ITAgAt>&) const;
    template<typename TCaseId, typename TTag, std::size_t ICaseId, 
        typename _TRet = GetArgumentType<TCaseId, TTag>, 
        typename _THasCase = HasCaseType<TCaseId>, 
        typename std::enable_if<!test::trait::type::index::IsBaseOf<
            TTag>::Value && _THasCase::value, int>::type = 0>
    _TRet GetArgument(const test::type::Index<TCaseId, ICaseId>&, 
        const TTag&) const;
    template<typename TCaseId, typename TTag, std::size_t ICaseId, 
        std::size_t ITAgAt, typename _TRet = GetArgumentType<TCaseId, 
            test::type::Index<TTag, ITAgAt>>, 
        typename _THasCase = HasCaseType<TCaseId>, 
        typename std::enable_if<_THasCase::value, int>::type = 0>
    _TRet GetArgument(const test::type::Index<TCaseId, ICaseId>&, 
        const test::type::Index<TTag, ITAgAt>&) const;
};

template<typename TChar, typename... TCaseArgs>
Base<TChar, TCaseArgs...>::Base()
{}

template<typename TChar, typename... TCaseArgs>
Base<TChar, TCaseArgs...>::~Base()
{}

template<typename TChar, typename... TCaseArgs>
void Base<TChar, TCaseArgs...>::GetCase()
{}

template<typename TChar, typename... TCaseArgs>
template<typename TCaseId, typename TTag, typename... TArgs>
void Base<TChar, TCaseArgs...>::SetFormat(...)
{}

template<typename TChar, typename... TCaseArgs>
template<typename TCaseId, typename TTag>
typename Base<TChar, TCaseArgs...>::FormatType 
Base<TChar, TCaseArgs...>::GetFormat(...) const
{
    return {};
}

template<typename TChar, typename... TCaseArgs>
template<typename TCaseId, typename TTag>
typename Base<TChar, TCaseArgs...>::ArgumentType 
Base<TChar, TCaseArgs...>::GetArgument(...) const
{
    return {};
}

template<typename TChar, typename TId, typename... TTagArgs, 
    typename... TCaseArgs>
Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
    TCaseArgs...>::Base()
{}

template<typename TChar, typename TId, typename... TTagArgs, 
    typename... TCaseArgs>
Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
    TCaseArgs...>::~Base()
{}

template<typename TChar, typename TId, typename... TTagArgs, 
    typename... TCaseArgs>
typename Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
    TCaseArgs...>::CaseType&
Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
    TCaseArgs...>::GetCase()
{
    return *this;
}

template<typename TChar, typename TId, typename... TTagArgs, 
    typename... TCaseArgs>
const typename Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
    TCaseArgs...>::CaseType& 
Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
    TCaseArgs...>::GetCase() const
{
    return *this;
}

template<typename TChar, typename TId, typename... TTagArgs, 
    typename... TCaseArgs>
template<typename TTag, typename... TArgs, typename _TTag,
    typename _THasCase, typename std::enable_if<!_THasCase::value, 
        int>::type>
void Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
    TCaseArgs...>::SetFormat(TTag&& tag, TArgs&&... args)
{
    test::msg::Case<TId, TChar, TTagArgs...>::SetFormat(
        std::forward<TTag>(tag), std::forward<TArgs>(args)...);
}

template<typename TChar, typename TId, typename... TTagArgs, 
    typename... TCaseArgs>
template<typename TCaseId, typename TTag, typename... TArgs,
    typename _THasCase, typename std::enable_if<_THasCase::value, int>::type>
void Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
    TCaseArgs...>::SetFormat(const TCaseId &, TTag&& tag, TArgs&&... args)
{
    GetBaseType<TCaseId>::SetFormat(std::forward<TTag>(tag),
        std::forward<TArgs>(args)...);
}

template<typename TChar, typename TId, typename... TTagArgs, 
    typename... TCaseArgs>
template<typename TCaseId, typename TTag, 
    typename _THasCase, typename std::enable_if<
    (!test::trait::type::index::IsBaseOf<TCaseId>::Value &&
    !test::trait::type::index::IsBaseOf<TTag>::Value) &&
    _THasCase::value, int>::type = 0>
typename Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
    TCaseArgs...>::FormatType 
Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
    TCaseArgs...>::GetFormat(const TCaseId&, const TTag& tag) const
{
    return GetBaseType<TCaseId>::GetCase().GetFormat(tag);
}

template<typename TChar, typename TId, typename... TTagArgs, 
    typename... TCaseArgs>
template<typename TCaseId, typename TTag, std::size_t ITAgAt, 
    typename _THasCase, typename std::enable_if<!test::trait::type::index::
        IsBaseOf<TCaseId>::Value && _THasCase::value, int>::type = 0>
typename Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
    TCaseArgs...>::FormatType 
Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
    TCaseArgs...>::GetFormat(const TCaseId&, 
        const test::type::Index<TTag, ITAgAt>& tag) const
{
    return GetBaseType<TCaseId>::GetCase().GetFormat(tag);
}
    
template<typename TChar, typename TId, typename... TTagArgs, 
    typename... TCaseArgs>
template<typename TCaseId, typename TTag, std::size_t ICaseId, 
    typename _THasCase, typename std::enable_if<!test::trait::type::index::
        IsBaseOf<TTag>::Value && _THasCase::value, int>::type = 0>
typename Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
    TCaseArgs...>::FormatType 
Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
    TCaseArgs...>::GetFormat(const test::type::Index<TCaseId, ICaseId>&, 
        const TTag& tag) const
{
    return GetBaseType<TCaseId>::GetCase().GetFormat(tag);
}
    
template<typename TChar, typename TId, typename... TTagArgs, 
    typename... TCaseArgs>
template<typename TCaseId, typename TTag, std::size_t ICaseId, 
    std::size_t ITAgAt, typename _THasCase,
    typename std::enable_if<_THasCase::value, int>::type>
typename Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
    TCaseArgs...>::FormatType 
Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
    TCaseArgs...>::GetFormat(const test::type::Index<TCaseId, ICaseId>&, 
        const test::type::Index<TTag, ITAgAt>& tag) const
{
    return GetBaseType<TCaseId>::GetCase().GetFormat(tag);
}

template<typename TChar, typename TId, typename... TTagArgs, 
    typename... TCaseArgs>
template<typename TCaseId, typename TTag, typename _TRet, typename _THasCase, 
    typename std::enable_if<
        (!test::trait::type::index::IsBaseOf<TCaseId>::Value &&
        !test::trait::type::index::IsBaseOf<TTag>::Value) &&
        _THasCase::value, int>::type>
_TRet Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
    TCaseArgs...>::GetArgument(const TCaseId&, const TTag& tag) const
{
    return GetBaseType<TCaseId>::GetCase().GetArgument(tag);
}

template<typename TChar, typename TId, typename... TTagArgs, 
    typename... TCaseArgs>
template<typename TCaseId, typename TTag, std::size_t ITAgAt, typename _TRet, 
    typename _THasCase, typename std::enable_if<!test::trait::type::index::
        IsBaseOf<TCaseId>::Value && _THasCase::value, int>::type>
_TRet Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
    TCaseArgs...>::GetArgument(const TCaseId&, 
        const test::type::Index<TTag, ITAgAt>& tag) const
{
    return GetBaseType<TCaseId>::GetCase().GetArgument(tag);
}
    
template<typename TChar, typename TId, typename... TTagArgs, 
    typename... TCaseArgs>
template<typename TCaseId, typename TTag, std::size_t ICaseId, typename _TRet, 
    typename _THasCase, typename std::enable_if<!test::trait::type::index::
        IsBaseOf<TTag>::Value && _THasCase::value, int>::type>
_TRet Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
    TCaseArgs...>::GetArgument(const test::type::Index<TCaseId, ICaseId>&, 
        const TTag& tag) const
{
    return GetBaseType<TCaseId>::GetCase().GetArgument(tag);
}
    
template<typename TChar, typename TId, typename... TTagArgs, 
    typename... TCaseArgs>
template<typename TCaseId, typename TTag, std::size_t ICaseId, 
    std::size_t ITAgAt, typename _TRet, typename _THasCase, 
    typename std::enable_if<_THasCase::value, int>::type>
_TRet Base<TChar, test::msg::Case<TId, TChar, TTagArgs...>,
    TCaseArgs...>::GetArgument(const test::type::Index<TCaseId, ICaseId>&, 
        const test::type::Index<TTag, ITAgAt>& tag) const
{
    return GetBaseType<TCaseId>::GetCase().GetArgument(tag);
}

} //!msg

} //!test

#endif //!TEST_MSG_BASE_H_