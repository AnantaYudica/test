#ifndef TEST_ARG_HEADER_H_
#define TEST_ARG_HEADER_H_

#include "../System.h"

#include <cstdint>
#include <cstdlib>
#include <utility>

namespace test::arg
{

class Header;

}

#ifndef TEST_ARG_HEADER_DLEVEL

#define TEST_ARG_HEADER_DLEVEL 2

#endif //!TEST_ARG_HEADER_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_ARG_HEADER_DLEVEL, 
    "test::arg::Header", test::arg::Header);

namespace test
{
namespace arg
{
class Header
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::arg::Header> DebugType;
public:
    typedef std::uint32_t FlagType;
public:
    static constexpr FlagType DefineChar                = 0x00001;
    static constexpr FlagType DefineWchar               = 0x00002;
    static constexpr FlagType DefineBool                = 0x00004;
    static constexpr FlagType DefineSignedChar          = 0x00008;
    static constexpr FlagType DefineShort               = 0x00010;
    static constexpr FlagType DefineInt                 = 0x00020;
    static constexpr FlagType DefineLong                = 0x00040;
    static constexpr FlagType DefineLongLong            = 0x00080;
    static constexpr FlagType DefineUnsignedChar        = 0x00100;
    static constexpr FlagType DefineUnsignedShort       = 0x00200;
    static constexpr FlagType DefineUnsignedInt         = 0x00400;
    static constexpr FlagType DefineUnsignedLong        = 0x00800;
    static constexpr FlagType DefineUnsignedLongLong    = 0x01000;
    static constexpr FlagType DefineFloat               = 0x02000;
    static constexpr FlagType DefineDouble              = 0x04000;
    static constexpr FlagType DefineLongDouble          = 0x08000;
    static constexpr FlagType DefinePointer             = 0x10000;
public:
    static constexpr FlagType DefineString              = 
        DefinePointer | DefineChar | DefineWchar;
    static constexpr FlagType DefineCharacter           =
        DefineWchar | DefineChar;
    static constexpr FlagType DefineSigned              =
        DefineSignedChar | DefineShort | DefineInt |
        DefineLong | DefineLongLong | DefineUnsignedChar;
    static constexpr FlagType DefineUnsigned            =
        DefineUnsignedShort | DefineUnsignedInt | 
        DefineUnsignedLong | DefineUnsignedLongLong;
    static constexpr FlagType DefineInteger             =
        DefineBool | DefineSigned | DefineUnsigned;
    static constexpr FlagType DefineFloatingPoint       =
        DefineFloat | DefineDouble | DefineLongDouble;
    static constexpr FlagType DefineType                = 0x0000ffff;
    static constexpr FlagType DefinePadding             = 0xfffe0000;
private:
    static constexpr inline FlagType Set(...);
    static constexpr inline FlagType Set(char*);
    static constexpr inline FlagType Set(wchar_t*);
    static constexpr inline FlagType Set(const char*);
    static constexpr inline FlagType Set(const wchar_t*);
    static constexpr inline FlagType Set(char);
    static constexpr inline FlagType Set(wchar_t);
    static constexpr inline FlagType Set(signed char);
    static constexpr inline FlagType Set(short);
    static constexpr inline FlagType Set(int);
    static constexpr inline FlagType Set(long);
    static constexpr inline FlagType Set(long long);
    static constexpr inline FlagType Set(unsigned char);
    static constexpr inline FlagType Set(unsigned short);
    static constexpr inline FlagType Set(unsigned int);
    static constexpr inline FlagType Set(unsigned long);
    static constexpr inline FlagType Set(unsigned long long);
    static constexpr inline FlagType Set(float);
    static constexpr inline FlagType Set(double);
    static constexpr inline FlagType Set(long double);
private:
    template<typename T, typename T_ = typename std::remove_reference<T>::type,
        typename std::enable_if<std::is_same<bool, T_>::value, int>::type = 1>
    static constexpr inline FlagType SetType(T&& t);
    template<typename T, typename T_ = typename std::remove_reference<T>::type, 
        typename std::enable_if<!std::is_same<bool, T_>::value, int>::type = 0>
    static constexpr inline FlagType SetType(T&& t);
    template<typename T, 
        typename std::enable_if<std::is_same<bool, T>::value, int>::type = 1>
    static constexpr inline FlagType SetType(const T& t);
    template<typename T, 
        typename std::enable_if<!std::is_same<bool, T>::value, int>::type = 0>
    static constexpr inline FlagType SetType(const T& t);
private:
    template<typename T, 
        typename std::enable_if<std::is_pointer<T>::value, int>::type = 1>
    static constexpr inline FlagType SetPointer(T &&);
    template<typename T, 
        typename std::enable_if<std::is_array<T>::value, int>::type = 2>
    static constexpr inline FlagType SetPointer(T &&);
    template<typename T, 
        typename std::enable_if<!std::is_pointer<T>::value &&
            !std::is_array<T>::value, int>::type = 0>
    static constexpr inline FlagType SetPointer(T &&);
    template<typename T, 
        typename std::enable_if<std::is_pointer<T>::value, int>::type = 1>
    static constexpr inline FlagType SetPointer(T &);
    template<typename T, 
        typename std::enable_if<std::is_array<T>::value, int>::type = 2>
    static constexpr inline FlagType SetPointer(T &);
    template<typename T, 
        typename std::enable_if<!std::is_pointer<T>::value &&
            !std::is_array<T>::value, int>::type = 0>
    static constexpr inline FlagType SetPointer(T &);
private:
    FlagType m_flag;
    std::uint32_t m_size;
public:
    inline Header();
    template<typename T>
    inline Header(const std::size_t& size, T&& t);
public:
    inline ~Header();
public:
    inline Header(const Header& cpy);
    inline Header(Header&& mov);
public:
    inline Header& operator=(const Header& cpy);
    inline Header& operator=(Header&& mov);
public:
    inline bool IsGood() const;
    inline bool IsBad() const;
public:
    inline bool IsDefineBool() const;
    inline bool IsDefineChar() const;
    inline bool IsDefineSignedChar() const;
    inline bool IsDefineShort() const;
    inline bool IsDefineInt() const;
    inline bool IsDefineLong() const;
    inline bool IsDefineLongLong() const;
    inline bool IsDefineUnsignedChar() const;
    inline bool IsDefineUnsignedShort() const;
    inline bool IsDefineUnsignedInt() const;
    inline bool IsDefineUnsignedLong() const;
    inline bool IsDefineUnsignedLongLong() const;
    inline bool IsDefineFloat() const;
    inline bool IsDefineDouble() const;
    inline bool IsDefineLongDouble() const;
    inline bool IsDefineWchar() const;
    inline bool IsDefinePointer() const;
    inline bool IsDefineString() const;
public:
    inline bool IsDefineCharacter() const;
    inline bool IsDefineInteger() const;
    inline bool IsDefineSigned() const;
    inline bool IsDefineUnsigned() const;
    inline bool IsDefineFloatingPoint() const;
public:
    inline FlagType Flag() const;
public:
    inline std::size_t Size() const;
public:
    inline bool operator==(const Header& other) const;
    inline bool operator!=(const Header& other) const;
};

constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::Set(...)
{
    return 0;
}

constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::Set(char*)
{
    return test::arg::Header::DefineChar;
}

constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::Set(wchar_t*)
{
    return test::arg::Header::DefineWchar;
}

constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::Set(const char*)
{
    return test::arg::Header::DefineChar;
}

constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::Set(const wchar_t*)
{
    return test::arg::Header::DefineWchar;
}

constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::Set(char)
{
    return test::arg::Header::DefineChar;
}

constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::Set(wchar_t)
{
    return test::arg::Header::DefineWchar;
}

constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::Set(signed char)
{
    return test::arg::Header::DefineSignedChar;
}

constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::Set(short)
{
    return test::arg::Header::DefineShort;
}

constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::Set(int)
{
    return test::arg::Header::DefineInt;
}

constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::Set(long)
{
    return test::arg::Header::DefineLong;
}

constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::Set(long long)
{
    return test::arg::Header::DefineLongLong;
}

constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::Set(unsigned char)
{
    return test::arg::Header::DefineUnsignedChar;
}

constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::Set(unsigned short)
{
    return test::arg::Header::DefineUnsignedShort;
}

constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::Set(unsigned int)
{
    return test::arg::Header::DefineUnsignedInt;
}

constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::Set(unsigned long)
{
    return test::arg::Header::DefineUnsignedLong;
}

constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::Set(unsigned long long)
{
    return test::arg::Header::DefineUnsignedLongLong;
}

constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::Set(float)
{
    return test::arg::Header::DefineFloat;
}

constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::Set(double)
{
    return test::arg::Header::DefineDouble;
}

constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::Set(long double)
{
    return test::arg::Header::DefineLongDouble;
}

template<typename T, typename T_,
    typename std::enable_if<std::is_same<bool, T_>::value, int>::type>
constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::SetType(T&& t)
{
    return test::arg::Header::DefineBool;
}

template<typename T, typename T_,
    typename std::enable_if<!std::is_same<bool, T_>::value, int>::type>
constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::SetType(T&& t)
{
    return test::arg::Header::Set(std::forward<T>(t));
}

template<typename T, 
    typename std::enable_if<std::is_same<bool, T>::value, int>::type>
constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::SetType(const T& t)
{
    return test::arg::Header::DefineBool;
}

template<typename T,
    typename std::enable_if<!std::is_same<bool, T>::value, int>::type>
constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::SetType(const T& t)
{
    return test::arg::Header::Set(t);
}

template<typename T, 
    typename std::enable_if<std::is_pointer<T>::value, int>::type>
constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::SetPointer(T &&)
{
    return test::arg::Header::DefinePointer;
}

template<typename T, 
    typename std::enable_if<std::is_array<T>::value, int>::type>
constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::SetPointer(T &&)
{
    return test::arg::Header::DefinePointer;
}

template<typename T, 
    typename std::enable_if<!std::is_pointer<T>::value &&
        !std::is_array<T>::value, int>::type>
constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::SetPointer(T &&)
{
    return 0;
}

template<typename T, 
    typename std::enable_if<std::is_pointer<T>::value, int>::type>
constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::SetPointer(T &)
{
    return test::arg::Header::DefinePointer;
}

template<typename T, 
    typename std::enable_if<std::is_array<T>::value, int>::type>
constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::SetPointer(T &)
{
    return test::arg::Header::DefinePointer;
}

template<typename T, 
    typename std::enable_if<!std::is_pointer<T>::value &&
        !std::is_array<T>::value, int>::type>
constexpr inline typename test::arg::Header::FlagType 
test::arg::Header::SetPointer(T &)
{
    return 0;
}

inline test::arg::Header::Header() :
    m_flag(0),
    m_size(0)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Default Constructor");
    
}

template<typename T>
inline test::arg::Header::Header(const std::size_t& size, T&& t) :
    m_flag(SetType(std::forward<T>(t)) | SetPointer(std::forward<T>(t))),
    m_size((std::uint32_t)size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor<%s>(size=%zu, t=%s)", 
        TEST_SYS_DEBUG_T_NAME_STR(T),
        size, TEST_SYS_DEBUG_TARGS_VALUE_STR(t));

}

inline test::arg::Header::~Header()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

    m_flag = 0;
    m_size = 0;
}

inline test::arg::Header::Header(const Header& cpy) :
    m_flag(cpy.m_flag),
    m_size(cpy.m_size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Copy Constructor");

}

inline test::arg::Header::Header(Header&& mov) :
    m_flag(mov.m_flag),
    m_size(mov.m_size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Move Constructor");

    mov.m_flag = 0;
    mov.m_size = 0;
}

inline Header& test::arg::Header::operator=(const Header& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Copy Assignment");

    m_flag = cpy.m_flag;
    m_size = cpy.m_size;
    return *this;
}

inline Header& test::arg::Header::operator=(Header&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Move Assignment");

    m_flag = mov.m_flag;
    m_size = mov.m_size;
    mov.m_flag = 0;
    mov.m_size = 0;
    return *this;
}

inline bool test::arg::Header::IsGood() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsGood() const");

    return (m_flag & DefinePadding) == 0 &&
        (m_flag & ~DefinePadding) != 0 &&
        ((m_flag & DefineBool) == DefineBool ||
            (m_flag & DefineType) == DefineChar ||
            (m_flag & DefineType) == DefineSignedChar ||
            (m_flag & DefineType) == DefineShort ||
            (m_flag & DefineType) == DefineInt ||
            (m_flag & DefineType) == DefineLong ||
            (m_flag & DefineType) == DefineLongLong ||
            (m_flag & DefineType) == DefineUnsignedChar ||
            (m_flag & DefineType) == DefineUnsignedShort ||
            (m_flag & DefineType) == DefineUnsignedInt ||
            (m_flag & DefineType) == DefineUnsignedLong ||
            (m_flag & DefineType) == DefineUnsignedLongLong ||
            (m_flag & DefineType) == DefineFloat ||
            (m_flag & DefineType) == DefineDouble ||
            (m_flag & DefineType) == DefineLongDouble ||
            (m_flag & DefineType) == DefineWchar ||
            (m_flag & DefinePointer) == DefinePointer);
}

inline bool test::arg::Header::IsBad() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsBad() const");
    
    return !IsGood();
}

inline bool test::arg::Header::IsDefineBool() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsDefineBool() const");
    
    return (m_flag & DefineType) == DefineBool;
}

inline bool test::arg::Header::IsDefineChar() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsDefineChar() const");
    
    return (m_flag & DefineType) == DefineChar;
}

inline bool test::arg::Header::IsDefineSignedChar() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this,
        "IsDefineSignedChar() const");
    
    return (m_flag & DefineType) == DefineSignedChar;
}

inline bool test::arg::Header::IsDefineShort() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsDefineShort() const");

    return (m_flag & DefineType) == DefineShort;
}

inline bool test::arg::Header::IsDefineInt() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsDefineInt() const");
    
    return (m_flag & DefineType) == DefineInt;
}

inline bool test::arg::Header::IsDefineLong() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsDefineLong() const");
    
    return (m_flag & DefineType) == DefineLong;
}

inline bool test::arg::Header::IsDefineLongLong() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsDefineLongLong() const");
    
    return (m_flag & DefineType) == DefineLongLong;
}

inline bool test::arg::Header::IsDefineUnsignedChar() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "IsDefineUnsignedChar() const");
    
    return (m_flag & DefineType) == DefineUnsignedChar;
}

inline bool test::arg::Header::IsDefineUnsignedShort() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "IsDefineUnsignedShort() const");
    
    return (m_flag & DefineType) == DefineUnsignedShort;
}

inline bool test::arg::Header::IsDefineUnsignedInt() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "IsDefineUnsignedInt() const");
    
    return (m_flag & DefineType) == DefineUnsignedInt;
}

inline bool test::arg::Header::IsDefineUnsignedLong() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "IsDefineUnsignedLong() const");
    
    return (m_flag & DefineType) == DefineUnsignedLong;
}

inline bool test::arg::Header::IsDefineUnsignedLongLong() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "IsDefineUnsignedLongLong() const");
    
    return (m_flag & DefineType) == DefineUnsignedLongLong;
}

inline bool test::arg::Header::IsDefineFloat() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsDefineFloat() const");
    
    return (m_flag & DefineType) == DefineFloat;
}

inline bool test::arg::Header::IsDefineDouble() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsDefineDouble() const");
    
    return (m_flag & DefineType) == DefineDouble;
}

inline bool test::arg::Header::IsDefineLongDouble() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "IsDefineLongDouble() const");
    
    return (m_flag & DefineType) == DefineLongDouble;
}

inline bool test::arg::Header::IsDefineWchar() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsDefineWchar() const");
    
    return (m_flag & DefineType) == DefineWchar;
}

inline bool test::arg::Header::IsDefinePointer() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsDefinePointer() const");
    
    return (m_flag & ~DefineType) == DefinePointer;
}

inline bool test::arg::Header::IsDefineString() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsDefineString() const");
    
    return (IsDefinePointer() && IsDefineChar()) ||
        (IsDefinePointer() && IsDefineWchar());
}

inline bool test::arg::Header::IsDefineCharacter() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "IsDefineCharacter() const");

    return (IsDefineChar() || IsDefineWchar()) && !IsDefinePointer();
}

inline bool test::arg::Header::IsDefineInteger() const
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "IsDefineInteger() const");

    return IsDefineBool() || IsDefineSigned() || IsDefineUnsigned();
}

inline bool test::arg::Header::IsDefineSigned() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "IsDefineSigned() const");

    return IsDefineSignedChar() || IsDefineShort() || IsDefineInt() ||
        IsDefineLong() || IsDefineLongLong();
}

inline bool test::arg::Header::IsDefineUnsigned() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "IsDefineUnsigned() const");

    return IsDefineUnsignedChar() || IsDefineUnsignedShort() || 
        IsDefineUnsignedInt() || IsDefineUnsignedLong() || 
        IsDefineUnsignedLongLong();
}

inline bool test::arg::Header::IsDefineFloatingPoint() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "IsDefineFloatingPoint() const");

    return IsDefineFloat() || IsDefineDouble() || IsDefineLongDouble();
}

inline typename test::arg::Header::FlagType 
test::arg::Header::Flag() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Flag() const");

    return m_flag;
}

inline std::size_t test::arg::Header::Size() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Size() const");
    
    return m_size;
}

inline bool test::arg::Header::operator==(const Header& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", &other);

    return m_flag == other.m_flag &&
        m_size == other.m_size;
}

inline bool test::arg::Header::operator!=(const Header& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", &other);
    
    return m_flag != other.m_flag ||
        m_size != other.m_size;
}

} //!arg

} //!test

#endif //!TEST_ARG_HEADER_H_
