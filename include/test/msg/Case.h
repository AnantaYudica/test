#ifndef TEST_MSG_CASE_H_
#define TEST_MSG_CASE_H_

#include "../type/Index.h"
#include "../trait/type/index/IsBaseOf.h"
#include "Tag.h"

#include "Format.h"
#include "Argument.h"
#include "arg/Value.h"
#include "arg/type/Function.h"
#include "arg/type/Index.h"
#include "arg/type/Name.h"
#include "arg/type/Value.h"
#include "arg/type/param/Name.h"
#include "arg/type/param/name/At.h"
#include "arg/type/val/Sequence.h"
#include "arg/type/val/seq/At.h"
#include "arg/val/Function.h"
#include "arg/val/Parameter.h"
#include "arg/val/Sequence.h"
#include "arg/val/param/At.h"
#include "arg/val/seq/At.h"

#include <type_traits>

namespace test
{
namespace msg
{

template<typename TId, typename TChar, typename... TTagArgs>
class Case
{
public:
    typedef test::msg::tag::Unknown TagType;
    typedef test::msg::Argument<> ArgumentType;
    typedef TId IdentificationType;
    typedef test::msg::Format<TChar> FormatType;
public:
    template<typename _TTag>
    using HasTagType = std::false_type;
    template<typename _TTag, std::size_t _IAt>
    using HasIndexTagType = std::false_type;
protected:
    template<typename _TTag>
    using GetCaseType = Case<TId, TChar, TTagArgs...>;
    template<typename _TTag, std::size_t _IAt>
    using GetCaseIndexType = Case<TId, TChar, TTagArgs...>;
protected:
    template<typename _TTag>
    using GetTagCaseType = Case<TId, TChar, TTagArgs...>;
    template<typename _TTag, std::size_t _IAt>
    using GetTagIndexCaseType = Case<TId, TChar, TTagArgs...>;
protected:
    FormatType m_format;
protected:
    Case();
public:
    ~Case();
protected:
    void SetFormat(...);
public:
    FormatType GetFormat(...) const;
public:
    ArgumentType GetArgument(...) const;
};

template<typename TId, typename TChar, typename TTag, typename TArg, 
    typename... TTagArgs>
class Case<TId, TChar, test::msg::Tag<TTag, TArg>, TTagArgs...> :
    public Case<TId, TChar, TTagArgs...>
{
public:
    typedef TTag TagType;
    typedef TArg ArgumentType;
    typedef TId IdentificationType;
    typedef test::msg::Format<TChar> FormatType;
public:
    template<typename _TTag>
    using HasTagType = typename std::conditional<
        std::is_same<_TTag, TTag>::value, std::true_type,
        typename Case<TId, TChar, TTagArgs...>::template HasTagType<
            _TTag>>::type;
    template<typename _TTag, std::size_t _IAt>
    using HasIndexTagType = typename Case<TId, TChar, TTagArgs...>::
        template HasIndexTagType<_TTag, _IAt>;
protected:
    template<typename _TTag>
    using GetCaseType = typename std::conditional<
        std::is_same<_TTag, TTag>::value,
        Case<TId, TChar, test::msg::Tag<TTag, TArg>, TTagArgs...>,
        typename Case<TId, TChar, TTagArgs...>::template GetCaseType<
            _TTag>>::type;
    template<typename _TTag, std::size_t _IAt>
    using GetCaseIndexType = typename Case<TId, TChar, TTagArgs...>::
        template GetCaseIndexType<_TTag, _IAt>;
protected:
    template<typename _TTag>
    using GetTagCaseType = typename std::conditional<
        HasTagType<_TTag>::value, GetCaseType<_TTag>,
        GetCaseIndexType<_TTag, 0>>::type;
    template<typename _TTag, std::size_t _IAt>
    using GetTagIndexCaseType = typename std::conditional<
        _IAt == 0 && !HasIndexTagType<_TTag, _IAt>::value, 
        GetCaseType<_TTag>, GetCaseIndexType<_TTag, _IAt>>::type;
protected:
    FormatType m_format;
protected:
    Case();
public:
    ~Case();
protected:
    template<typename TFArg, typename... TFArgs, typename _TFArg = 
        typename std::remove_cv<typename std::remove_reference<TFArg>::
            type>::type,
        typename std::enable_if<!std::is_same<_TFArg, 
            test::msg::Format<TChar>>::value, int>::type = 0>
    void SetFormat(const TagType&, TFArg&& arg, TFArgs&&... args);
    void SetFormat(const TagType&, const FormatType& format);
    void SetFormat(const TagType&, FormatType&& format);
    using Case<TId, TChar, TTagArgs...>::SetFormat;
public:
    template<typename _TTag, typename std::enable_if<!test::trait::type::
        index::IsBaseOf<_TTag>::Value, int>::type = 0>
    FormatType GetFormat(const _TTag&) const;
    template<typename _TTag, std::size_t _IAt>
    FormatType GetFormat(const test::type::Index<_TTag, _IAt>&) const;
public:
    template<typename _TTag, typename _TRet = 
        typename GetTagCaseType<_TTag>::ArgumentType,
        typename std::enable_if<!test::trait::type::
            index::IsBaseOf<_TTag>::Value, int>::type = 0>
    _TRet GetArgument(const _TTag&) const;
    template<typename _TTag, std::size_t _IAt, typename _TRet = 
        typename GetTagIndexCaseType<_TTag, _IAt>::ArgumentType>
    _TRet GetArgument(const test::type::Index<_TTag, _IAt>&) const;
};

template<typename TId, typename TChar, typename TTag, std::size_t IAt,
    typename TArg,  typename... TTagArgs>
class Case<TId, TChar, test::msg::Tag<test::type::Index<TTag, IAt>, 
    TArg>, TTagArgs...> : public Case<TId, TChar, TTagArgs...>
{
public:
    typedef TTag TagType;
    typedef TArg ArgumentType;
    typedef TId IdentificationType;
    typedef test::msg::Format<TChar> FormatType;
public:
    template<typename _TTag>
    using HasTagType = typename Case<TId, TChar, TTagArgs...>::
        template HasTagType<_TTag>;
    template<typename _TTag, std::size_t _IAt>
    using HasIndexTagType = typename std::conditional<
        std::is_same<_TTag, TTag>::value && _IAt == IAt, std::true_type,
        typename Case<TId, TChar, TTagArgs...>::template HasIndexTagType<
            _TTag, _IAt>>::type;
protected:
    template<typename _TTag>
    using GetCaseType = typename Case<TId, TChar, TTagArgs...>::
        template GetCaseType<_TTag>;
    template<typename _TTag, std::size_t _IAt>
    using GetCaseIndexType =  typename std::conditional<
        std::is_same<_TTag, TTag>::value && _IAt == IAt,
        Case<TId, TChar, test::msg::Tag<test::type::Index<TTag, IAt>, 
            TArg>, TTagArgs...>,
        typename Case<TId, TChar, TTagArgs...>::template GetCaseIndexType<
            _TTag, _IAt>>::type;
protected:
    template<typename _TTag>
    using GetTagCaseType = typename std::conditional<
        HasTagType<_TTag>::value, GetCaseType<_TTag>,
        GetCaseIndexType<_TTag, 0>>::type;
    template<typename _TTag, std::size_t _IAt>
    using GetTagIndexCaseType = typename std::conditional<
        _IAt == 0 && !HasIndexTagType<_TTag, _IAt>::value, 
        GetCaseType<_TTag>, GetCaseIndexType<_TTag, _IAt>>::type;
protected:
    FormatType m_format;
protected:
    Case();
public:
    ~Case();
protected:
    template<typename TFArg, typename... TFArgs, typename _TFArg = 
        typename std::remove_cv<typename std::remove_reference<TFArg>::
            type>::type,
        typename std::enable_if<!std::is_same<_TFArg, 
            test::msg::Format<TChar>>::value, int>::type = 0>
    void SetFormat(const test::type::Index<TagType, IAt>&, 
        TFArg&& arg, TFArgs&&... args);
    void SetFormat(const test::type::Index<TagType, IAt>&, 
        const FormatType& format);
    void SetFormat(const test::type::Index<TagType, IAt>&, 
        FormatType&& format);
    using Case<TId, TChar, TTagArgs...>::SetFormat;
public:
    template<typename _TTag, typename std::enable_if<!test::trait::type::
        index::IsBaseOf<_TTag>::Value, int>::type = 0>
    FormatType GetFormat(const _TTag&) const;
    template<typename _TTag, std::size_t _IAt>
    FormatType GetFormat(const test::type::Index<_TTag, _IAt>&) const;
public:
    template<typename _TTag, typename _TRet = 
        typename GetTagCaseType<_TTag>::ArgumentType,
        typename std::enable_if<!test::trait::type::
            index::IsBaseOf<_TTag>::Value, int>::type = 0>
    _TRet GetArgument(const _TTag&) const;
    template<typename _TTag, std::size_t _IAt, typename _TRet = 
        typename GetTagIndexCaseType<_TTag, _IAt>::ArgumentType>
    _TRet GetArgument(const test::type::Index<_TTag, _IAt>&) const;
};

template<typename TId, typename TChar, typename... TTagArgs>
Case<TId, TChar, TTagArgs...>::Case() :
    m_format()
{}

template<typename TId, typename TChar, typename... TTagArgs>
Case<TId, TChar, TTagArgs...>::~Case()
{}

template<typename TId, typename TChar, typename... TTagArgs>
void Case<TId, TChar, TTagArgs...>::SetFormat(...)
{}

template<typename TId, typename TChar, typename... TTagArgs>
typename Case<TId, TChar, TTagArgs...>::FormatType 
Case<TId, TChar, TTagArgs...>::GetFormat(...) const
{
    return m_format;
}

template<typename TId, typename TChar, typename... TTagArgs>
typename Case<TId, TChar, TTagArgs...>::ArgumentType 
Case<TId, TChar, TTagArgs...>::GetArgument(...) const
{
    return {};
}

template<typename TId, typename TChar, typename TTag, typename TArg, 
    typename... TTagArgs>
Case<TId, TChar, test::msg::Tag<TTag, TArg>, TTagArgs...>::Case() :
    m_format()
{}

template<typename TId, typename TChar, typename TTag, typename TArg, 
    typename... TTagArgs>
Case<TId, TChar, test::msg::Tag<TTag, TArg>, TTagArgs...>::~Case()
{}

template<typename TId, typename TChar, typename TTag, typename TArg, 
    typename... TTagArgs>
template<typename TFArg, typename... TFArgs, 
    typename _TFArg, typename std::enable_if<!std::is_same<_TFArg, 
        test::msg::Format<TChar>>::value, int>::type>
void Case<TId, TChar, test::msg::Tag<TTag, TArg>, TTagArgs...>::
    SetFormat(const TagType&, TFArg&& arg, TFArgs&&... args)
{
    m_format = test::msg::Format<char>{std::forward<TFArg>(arg),
        std::forward<TFArgs>(args)...};
}

template<typename TId, typename TChar, typename TTag, typename TArg, 
    typename... TTagArgs>
void Case<TId, TChar, test::msg::Tag<TTag, TArg>, TTagArgs...>::
    SetFormat(const TagType&, const FormatType& format)
{
    m_format = format;
}

template<typename TId, typename TChar, typename TTag, typename TArg, 
    typename... TTagArgs>
void Case<TId, TChar, test::msg::Tag<TTag, TArg>, TTagArgs...>::
    SetFormat(const TagType&, FormatType&& format)
{
    m_format = std::move(format);
}

template<typename TId, typename TChar, typename TTag, typename TArg, 
    typename... TTagArgs>
template<typename _TTag, typename std::enable_if<!test::trait::type::
    index::IsBaseOf<_TTag>::Value, int>::type>
typename Case<TId, TChar, test::msg::Tag<TTag, TArg>, TTagArgs...>::FormatType
Case<TId, TChar, test::msg::Tag<TTag, TArg>, TTagArgs...>::
    GetFormat(const _TTag&) const
{
    return GetTagCaseType<_TTag>::m_format;
}

template<typename TId, typename TChar, typename TTag, typename TArg, 
    typename... TTagArgs>
template<typename _TTag, std::size_t _IAt>
typename Case<TId, TChar, test::msg::Tag<TTag, TArg>, TTagArgs...>::FormatType 
Case<TId, TChar, test::msg::Tag<TTag, TArg>, TTagArgs...>::
    GetFormat(const test::type::Index<_TTag, _IAt>&) const
{
    return GetTagIndexCaseType<_TTag, _IAt>::m_format;
}

template<typename TId, typename TChar, typename TTag, typename TArg, 
    typename... TTagArgs>
template<typename _TTag, typename _TRet, 
    typename std::enable_if<!test::trait::type::
        index::IsBaseOf<_TTag>::Value, int>::type>
_TRet Case<TId, TChar, test::msg::Tag<TTag, TArg>, TTagArgs...>::
    GetArgument(const _TTag&) const
{
    return {};
}

template<typename TId, typename TChar, typename TTag, typename TArg, 
    typename... TTagArgs>
template<typename _TTag, std::size_t _IAt, typename _TRet>
_TRet Case<TId, TChar, test::msg::Tag<TTag, TArg>, TTagArgs...>::
    GetArgument(const test::type::Index<_TTag, _IAt>&) const
{
    return {};
}

template<typename TId, typename TChar, typename TTag, std::size_t IAt,
    typename TArg,  typename... TTagArgs>
Case<TId, TChar, test::msg::Tag<test::type::Index<TTag, IAt>, 
    TArg>, TTagArgs...>::Case() :
        m_format()
{}

template<typename TId, typename TChar, typename TTag, std::size_t IAt,
    typename TArg,  typename... TTagArgs>
Case<TId, TChar, test::msg::Tag<test::type::Index<TTag, IAt>, 
    TArg>, TTagArgs...>::~Case()
{}

template<typename TId, typename TChar, typename TTag, std::size_t IAt,
    typename TArg,  typename... TTagArgs>
template<typename TFArg, typename... TFArgs, 
    typename _TFArg, typename std::enable_if<!std::is_same<_TFArg, 
        test::msg::Format<TChar>>::value, int>::type>
void Case<TId, TChar, test::msg::Tag<test::type::Index<TTag, IAt>, 
    TArg>, TTagArgs...>::SetFormat(const test::type::Index<TagType, IAt>&, 
        TFArg&& arg, TFArgs&&... args)
{
    m_format = test::msg::Format<char>{std::forward<TFArg>(arg),
        std::forward<TFArgs>(args)...};
}

template<typename TId, typename TChar, typename TTag, std::size_t IAt,
    typename TArg,  typename... TTagArgs>
void Case<TId, TChar, test::msg::Tag<test::type::Index<TTag, IAt>, 
    TArg>, TTagArgs...>::SetFormat(const test::type::Index<TagType, IAt>&, 
        const FormatType& format)
{
    m_format = format;
}

template<typename TId, typename TChar, typename TTag, std::size_t IAt,
    typename TArg,  typename... TTagArgs>
void Case<TId, TChar, test::msg::Tag<test::type::Index<TTag, IAt>, 
    TArg>, TTagArgs...>::SetFormat(const test::type::Index<TagType, IAt>&, 
        FormatType&& format)
{
    m_format = std::move(format);
}

template<typename TId, typename TChar, typename TTag, std::size_t IAt,
    typename TArg,  typename... TTagArgs>
template<typename _TTag, typename std::enable_if<!test::trait::type::
    index::IsBaseOf<_TTag>::Value, int>::type>
typename Case<TId, TChar, test::msg::Tag<test::type::Index<TTag, IAt>, 
    TArg>, TTagArgs...>::FormatType 
Case<TId, TChar, test::msg::Tag<test::type::Index<TTag, IAt>, 
    TArg>, TTagArgs...>::GetFormat(const _TTag&) const
{
    return GetTagCaseType<_TTag>::m_format;
}

template<typename TId, typename TChar, typename TTag, std::size_t IAt,
    typename TArg,  typename... TTagArgs>
template<typename _TTag, std::size_t _IAt>
typename Case<TId, TChar, test::msg::Tag<test::type::Index<TTag, IAt>, 
    TArg>, TTagArgs...>::FormatType 
Case<TId, TChar, test::msg::Tag<test::type::Index<TTag, IAt>, TArg>, 
    TTagArgs...>::GetFormat(const test::type::Index<_TTag, _IAt>&) const
{
    return GetTagIndexCaseType<_TTag, _IAt>::m_format;
}

template<typename TId, typename TChar, typename TTag, std::size_t IAt,
    typename TArg,  typename... TTagArgs>
template<typename _TTag, typename _TRet, 
    typename std::enable_if<!test::trait::type::
        index::IsBaseOf<_TTag>::Value, int>::type>
_TRet Case<TId, TChar, test::msg::Tag<test::type::Index<TTag, IAt>, TArg>, 
    TTagArgs...>::GetArgument(const _TTag&) const
{
    return {};
}

template<typename TId, typename TChar, typename TTag, std::size_t IAt,
    typename TArg,  typename... TTagArgs>
template<typename _TTag, std::size_t _IAt, typename _TRet>
_TRet Case<TId, TChar, test::msg::Tag<test::type::Index<TTag, IAt>, TArg>, 
    TTagArgs...>::GetArgument(const test::type::Index<_TTag, _IAt>&) const
{
    return {};
}

} //!msg

} //!test

#endif //!TEST_MSG_CASE_H_
