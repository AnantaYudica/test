#ifndef TEST_ARG_STRUCTURE_H_
#define TEST_ARG_STRUCTURE_H_

#include "../Pointer.h"
#include "Value.h"

#include <cstddef>
#include <type_traits>
#include <utility>

namespace test
{
namespace arg
{

class Structure
{
private:
    static inline std::size_t _Set(std::size_t total,
        test::Pointer<std::size_t>& list);
    template<typename... TArgs>
    static inline std::size_t _Set(std::size_t total,
        test::Pointer<std::size_t>& list, std::size_t&& size_arg, 
        TArgs&&... size_args);
private:
    test::Pointer<std::size_t> m_size_list;
    test::arg::Value m_values;
public:
    inline Structure();
    template<typename TArg, typename... TArgs, typename _TArgs =
        typename std::remove_cv<typename std::remove_pointer<
            typename std::remove_reference<TArg>::type>::type>::type,
        typename std::enable_if<
            !std::is_base_of<Structure, _TArgs>::value, int>::type = 0>
    inline Structure(TArg&& size_arg, TArgs&&... size_args);
public:
    inline ~Structure();
public:
    inline Structure(const Structure& cpy);
    inline Structure(Structure&& mov);
public:
    inline Structure& operator=(const Structure& cpy);
    inline Structure& operator=(Structure&& mov);
public:
    template<typename T>
    inline void Set(const std::size_t& index, const T& val);
public:
    template<typename T>
    inline T* Get(const std::size_t& index);
public:
    inline std::size_t Size() const;
public:
    inline std::size_t AllocationSize() const;
    inline std::size_t AllocationSize(const std::size_t& index) const;
public:
    inline bool operator==(const Structure& other) const;
    inline bool operator!=(const Structure& other) const;
};

inline std::size_t Structure::_Set(std::size_t total,
    test::Pointer<std::size_t>& list)
{
    return total;
}

template<typename... TArgs>
inline std::size_t Structure::_Set(std::size_t total,
    test::Pointer<std::size_t>& list, std::size_t&& size_arg, 
    TArgs&&... size_args)
{
    *list = total; ++list;
    return _Set(total + size_arg, list, 
        std::forward<TArgs>(size_args)...);
}

inline Structure::Structure() :
    m_size_list(),
    m_values()
{}

template<typename TArg, typename... TArgs, typename _TArgs,
    typename std::enable_if<
        !std::is_base_of<Structure, _TArgs>::value, int>::type>
inline Structure::Structure(TArg&& size_arg, TArgs&&... size_args) :
    m_size_list(test::ptr::arg::Array(sizeof...(TArgs) + 1)),
    m_values(_Set(0, m_size_list, std::forward<TArg>(size_arg),
        std::forward<TArgs>(size_args)...))
{}

inline Structure::~Structure()
{}

inline Structure::Structure(const Structure& cpy) :
    m_size_list(cpy.m_size_list),
    m_values(cpy.m_values)
{}

inline Structure::Structure(Structure&& mov) :
    m_size_list(mov.m_size_list),
    m_values(mov.m_values)
{}

inline Structure& Structure::operator=(const Structure& cpy)
{
    m_size_list = cpy.m_size_list;
    m_values = cpy.m_values;
    return *this;
}

inline Structure& Structure::operator=(Structure&& mov)
{
    m_size_list = mov.m_size_list;
    m_values = mov.m_values;
    return *this;
}

template<typename T>
inline void Structure::Set(const std::size_t& index, const T& val)
{
    m_values.template Set<T>(m_size_list[index], val);
}

template<typename T>
inline T* Structure::Get(const std::size_t& index)
{
    return m_values.template Get<T>(m_size_list[index]);
}

inline std::size_t Structure::Size() const
{
    return m_size_list.Size();
}

inline std::size_t Structure::AllocationSize() const
{
    return m_values.AllocationSize();
}

inline std::size_t Structure::
    AllocationSize(const std::size_t& index) const
{
    const auto size = Size();
    if (size == 0 || index >= size) return 0;
    if (index == (size - 1)) return AllocationSize() -
        m_size_list[index];
    else if (index == 0) return m_size_list[1];
    return m_size_list[index + 1] - m_size_list[index];
}

inline bool Structure::operator==(const Structure& other) const
{
    return m_size_list == other.m_size_list.GetData() &&
        m_values == other.m_values;
}

inline bool Structure::operator!=(const Structure& other) const
{
    return  m_size_list != other.m_size_list.GetData() ||
        m_values != other.m_values;
}

} //!arg

} //!test

#endif //!TEST_ARG_STRUCTURE_H_
