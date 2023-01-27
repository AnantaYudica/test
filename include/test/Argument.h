#ifndef TEST_ARGUMENT_H_
#define TEST_ARGUMENT_H_

#include "Pointer.h"
#include "arg/Flag.h"
#include "arg/Structure.h"

#include <cstdint>
#include <cstring>
#include <type_traits>

namespace test
{

class Argument : 
    public test::arg::Structure
{
private:
    test::arg::Flag m_flag;
    std::size_t m_pos;
public:
    inline Argument();
    template<typename TArg, typename... TArgs, typename _TArg =
        typename std::remove_cv<typename std::remove_pointer<
            typename std::remove_reference<TArg>::type>::type>::type,
        typename std::enable_if<
            !std::is_base_of<Argument, _TArg>::value ,int>::type = 0>
    inline Argument(TArg&& arg, TArgs&&... args);
public:
    inline ~Argument();
public:
    inline Argument(const Argument& cpy);
    inline Argument(Argument&& mov);
public:
    inline Argument& operator=(const Argument& cpy);
    inline Argument& operator=(Argument&& mov);
public:
    template<typename T>
    inline std::size_t Load(T& val);
public:
    inline std::size_t Size() const;
public:
    inline std::size_t AllocationSize() const;
    inline std::size_t AllocationSize(const std::size_t& index) const;
public:
    inline std::size_t Current() const;
public:
    inline Argument Begin() const;
    inline Argument End() const;
public:
    inline Argument& operator+=(const std::size_t& n);
    inline Argument& operator-=(const std::size_t& n);
public:
    inline Argument& operator++();
    inline Argument operator++(int);
public:
    inline Argument& operator--();
    inline Argument operator--(int);
public:
    inline Argument operator+(const std::size_t& n);
    inline Argument operator-(const std::size_t& n);
    inline Argument operator+(const int& n);
    inline Argument operator-(const int& n);
public:
    inline bool operator==(const Argument& other) const;
    inline bool operator!=(const Argument& other) const;
    inline bool operator==(const test::arg::Structure& other) const;
    inline bool operator!=(const test::arg::Structure& other) const;
public:
    inline operator bool() const;
};

inline Argument::Argument() :
    test::arg::Structure(),
    m_flag(),
    m_pos(0)
{}

template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<
        !std::is_base_of<Argument, _TArg>::value ,int>::type >
inline Argument::Argument(TArg&& arg, TArgs&&... args) :
    test::arg::Structure(std::forward<TArg>(arg),
        std::forward<TArgs>(args)...),
    m_flag(sizeof...(TArgs) + 1),
    m_pos(m_flag.Position(0, sizeof...(TArgs) + 1))
{}

inline Argument::~Argument()
{
    m_pos = 0;
}

inline Argument::Argument(const Argument& cpy) :
    test::arg::Structure(cpy),
    m_flag(cpy.m_flag),
    m_pos(cpy.m_pos)
{}

inline Argument::Argument(Argument&& mov) :
    test::arg::Structure(std::move(mov)),
    m_flag(mov.m_flag),
    m_pos(mov.m_pos)
{}

inline Argument& Argument::operator=(const Argument& cpy)
{
    test::arg::Structure::operator=(cpy);
    m_flag = cpy.m_flag;
    m_pos = cpy.m_pos;
    return *this;
}

inline Argument& Argument::operator=(Argument&& mov)
{
    test::arg::Structure::operator=(std::move(mov));
    m_flag = mov.m_flag;
    m_pos = mov.m_pos;
    return *this;
}

template<typename T>
inline std::size_t Argument::Load(T& val)
{
    const auto size = test::arg::Structure::Size();
    const std::size_t pos = m_flag.Position(m_pos, size);
    if (pos == size) return 0;
    val = *test::arg::Structure::Get<T>(pos);
    return test::arg::Structure::AllocationSize(pos);
}

inline std::size_t Argument::Size() const
{
    return test::arg::Structure::Size();
}

inline std::size_t Argument::AllocationSize() const
{
    return test::arg::Structure::AllocationSize();
}

inline std::size_t Argument::AllocationSize(const std::size_t& index) const
{
    return test::arg::Structure::AllocationSize(index);
}

inline std::size_t Argument::Current() const
{
    return m_flag.Position(m_pos, test::arg::Structure::Size());
}

inline Argument Argument::Begin() const
{
    Argument ret{*this};
    const auto size = Size();
    ret.m_pos = 0;
    ret.m_flag = test::arg::Flag{size};
    return ret;
}

inline Argument Argument::End() const
{
    Argument ret{*this};
    const auto size = Size();
    ret.m_flag = test::arg::Flag{test::arg::Flag::forward_end};
    ret.m_pos = size;
    return ret;
}

inline Argument& Argument::operator+=(const std::size_t& n)
{
    const auto size = test::arg::Structure::Size();
    m_pos = m_flag.Forward(n, m_pos, size);
    return *this;
}

inline Argument& Argument::operator-=(const std::size_t& n)
{
    const auto size = test::arg::Structure::Size();
    m_pos = m_flag.Backward(n, m_pos, size);
    return *this;
}

inline Argument& Argument::operator++()
{
    *this += (std::size_t)1;
    return *this;
}

inline Argument Argument::operator++(int)
{
    Argument ret{*this};
    ++(*this);
    return ret;
}

inline Argument& Argument::operator--()
{
    *this -= (std::size_t)1;
    return *this;
}

inline Argument Argument::operator--(int)
{
    Argument ret{*this};
    --(*this);
    return ret;
}

inline Argument Argument::operator+(const std::size_t& n)
{
    Argument ret{*this};
    ret += n;
    return ret;
}

inline Argument Argument::operator-(const std::size_t& n)
{
    Argument ret{*this};
    ret -= n;
    return ret;
}

inline Argument Argument::operator+(const int& n)
{
    if (n >= 0)
        return (*this + std::size_t(n));
    return (*this - std::size_t(-n));
}

inline Argument Argument::operator-(const int& n)
{
    if (n >= 0)
        return (*this - std::size_t(n));
    return (*this + std::size_t(-n));
}

inline bool Argument::operator==(const Argument& other) const
{
    return m_pos == other.m_pos &&
        m_flag == other.m_flag &&
        test::arg::Structure::operator==(other);
}

inline bool Argument::operator!=(const Argument& other) const
{
    return !(*this == other);
}

inline bool Argument::operator==(const test::arg::Structure& other) const
{
    return test::arg::Structure::operator==(other);
}

inline bool Argument::operator!=(const test::arg::Structure& other) const
{
    return test::arg::Structure::operator!=(other);
}

inline Argument::operator bool() const
{
    return !m_flag.IsEnd();
}

} //!test

#endif //!TEST_ARGUMENT_H_
