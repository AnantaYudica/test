#ifndef TEST_ARGUMENT_H_
#define TEST_ARGUMENT_H_

#include "System.h"
#include "Pointer.h"
#include "arg/Flag.h"
#include "arg/Structure.h"

#include <cstdint>
#include <cstring>
#include <type_traits>

namespace test
{
class Argument;
}

#ifndef TEST_ARGUMENT_DLEVEL

#define TEST_ARGUMENT_DLEVEL 2

#endif //!TEST_ARGUMENT_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_ARGUMENT_DLEVEL, 
    "test::Argument", test::Argument);


namespace test
{

class Argument : 
    public test::arg::Structure
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::Argument> DebugType;
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
    inline Argument operator+(const std::size_t& n) const;
    inline Argument operator-(const std::size_t& n) const;
    inline Argument operator+(const int& n) const;
    inline Argument operator-(const int& n) const;
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
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<
        !std::is_base_of<Argument, _TArg>::value ,int>::type >
inline Argument::Argument(TArg&& arg, TArgs&&... args) :
    test::arg::Structure(std::forward<TArg>(arg),
        std::forward<TArgs>(args)...),
    m_flag(sizeof...(TArgs) + 1),
    m_pos(m_flag.Position(0, sizeof...(TArgs) + 1))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor<%s>(args={%s})", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TArg, TArgs...),
        TEST_SYS_DEBUG_TARGS_VALUE_STR(arg, args...));

}

inline Argument::~Argument()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

    m_pos = 0;
}

inline Argument::Argument(const Argument& cpy) :
    test::arg::Structure(cpy),
    m_flag(cpy.m_flag),
    m_pos(cpy.m_pos)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);

}

inline Argument::Argument(Argument&& mov) :
    test::arg::Structure(std::move(mov)),
    m_flag(mov.m_flag),
    m_pos(mov.m_pos)
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

}

inline Argument& Argument::operator=(const Argument& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);

    test::arg::Structure::operator=(cpy);
    m_flag = cpy.m_flag;
    m_pos = cpy.m_pos;
    return *this;
}

inline Argument& Argument::operator=(Argument&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);

    test::arg::Structure::operator=(std::move(mov));
    m_flag = mov.m_flag;
    m_pos = mov.m_pos;
    return *this;
}

template<typename T>
inline std::size_t Argument::Load(T& val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Load<%s>(val=%s)", TEST_SYS_DEBUG_T_NAME_STR(T),
            TEST_SYS_DEBUG_TARGS_VALUE_STR(val));

    const auto size = test::arg::Structure::Size();
    const std::size_t pos = m_flag.Position(m_pos, size);
    if (pos == size) return 0;
    val = *test::arg::Structure::Get<T>(pos);
    return test::arg::Structure::AllocationSize(pos);
}

inline std::size_t Argument::Size() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Size() const");

    return test::arg::Structure::Size();
}

inline std::size_t Argument::AllocationSize() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "AllocationSize() const");

    return test::arg::Structure::AllocationSize();
}

inline std::size_t Argument::AllocationSize(const std::size_t& index) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "AllocationSize(index=%zu) const", index);

    return test::arg::Structure::AllocationSize(index);
}

inline std::size_t Argument::Current() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Current() const");

    return m_flag.Position(m_pos, test::arg::Structure::Size());
}

inline Argument Argument::Begin() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Begin() const");

    Argument ret{*this};
    const auto size = Size();
    ret.m_pos = 0;
    ret.m_flag = test::arg::Flag{size};
    return ret;
}

inline Argument Argument::End() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "End() const");

    Argument ret{*this};
    const auto size = Size();
    ret.m_flag = test::arg::Flag{test::arg::Flag::forward_end};
    ret.m_pos = size;
    return ret;
}

inline Argument& Argument::operator+=(const std::size_t& n)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+=(n=%zu)", n);

    const auto size = test::arg::Structure::Size();
    m_pos = m_flag.Forward(n, m_pos, size);
    return *this;
}

inline Argument& Argument::operator-=(const std::size_t& n)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-=(n=%zu)", n);

    const auto size = test::arg::Structure::Size();
    m_pos = m_flag.Backward(n, m_pos, size);
    return *this;
}

inline Argument& Argument::operator++()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++()");

    *this += (std::size_t)1;
    return *this;
}

inline Argument Argument::operator++(int)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++(int)");

    Argument ret{*this};
    ++(*this);
    return ret;
}

inline Argument& Argument::operator--()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--()");

    *this -= (std::size_t)1;
    return *this;
}

inline Argument Argument::operator--(int)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--(int)");

    Argument ret{*this};
    --(*this);
    return ret;
}

inline Argument Argument::operator+(const std::size_t& n) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+(n=%zu) const", n);

    Argument ret{*this};
    ret += n;
    return ret;
}

inline Argument Argument::operator-(const std::size_t& n) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-(n=%zu) const", n);

    Argument ret{*this};
    ret -= n;
    return ret;
}

inline Argument Argument::operator+(const int& n) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+(n=%d) const", n);

    if (n >= 0)
        return (*this + std::size_t(n));
    return (*this - std::size_t(-n));
}

inline Argument Argument::operator-(const int& n) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-(n=%d) const", n);

    if (n >= 0)
        return (*this - std::size_t(n));
    return (*this + std::size_t(-n));
}

inline bool Argument::operator==(const Argument& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", &other);

    return m_pos == other.m_pos &&
        m_flag == other.m_flag &&
        test::arg::Structure::operator==(other);
}

inline bool Argument::operator!=(const Argument& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", &other);

    return !(*this == other);
}

inline bool Argument::operator==(const test::arg::Structure& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", &other);

    return test::arg::Structure::operator==(other);
}

inline bool Argument::operator!=(const test::arg::Structure& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", &other);

    return test::arg::Structure::operator!=(other);
}

inline Argument::operator bool() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator bool() const");

    return !m_flag.IsEnd();
}

} //!test

#endif //!TEST_ARGUMENT_H_
