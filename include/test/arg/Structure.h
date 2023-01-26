#ifndef TEST_ARG_STRUCTURE_H_
#define TEST_ARG_STRUCTURE_H_

#include "../System.h"
#include "../Pointer.h"
#include "Header.h"
#include "Block.h"
#include "Value.h"
#include "val/Const.h"

#include <cstddef>
#include <type_traits>
#include <utility>

namespace test::arg
{
class Structure;
}

#ifndef TEST_ARG_STRUCTURE_DLEVEL

#define TEST_ARG_STRUCTURE_DLEVEL 2

#endif //!TEST_ARG_STRUCTURE_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_ARG_STRUCTURE_DLEVEL, 
    "test::arg::Structure", test::arg::Structure);

namespace test
{
namespace arg
{

class Structure
{
private:
    template<typename T>
    struct Type
    {
        typedef T BaseType;
        static constexpr std::size_t Size = sizeof(T);
    };
    template<typename T, std::size_t N>
    struct Type<T(&)[N]>
    {
        typedef T* BaseType;
        static constexpr std::size_t Size = sizeof(void*);
    };
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::arg::Structure> DebugType;
public:
    typedef test::arg::Block BlockType;
    typedef test::Pointer<BlockType> MapType;
    typedef test::Pointer<std::uint8_t> BufferType;
    template<typename T = char>
    using ValueType = test::arg::Value<T, BufferType>;
    template<typename T = char>
    using ValueConstType = test::arg::val::Const<T, BufferType>;
private:
    static inline std::size_t _Count(std::size_t total, std::size_t index,
        MapType& maps);
    template<typename TArg, typename... TArgs>
    static inline std::size_t _Count(std::size_t total, std::size_t index,
        MapType& maps, TArg&& size_arg, TArgs&&... size_args);
private:
    static inline std::size_t _Set(BufferType& buff,
        MapType& maps, std::size_t index, std::size_t total);
    template<typename TArg, typename... TArgs>
    static inline std::size_t _Set(BufferType& buff,
        MapType& maps, std::size_t index, std::size_t total, 
        TArg&& arg, TArgs&&... args);
private:
    MapType m_maps;
    BufferType m_buff;
public:
    inline Structure();
    template<typename TArg, typename... TArgs, typename _TArgs =
        typename std::remove_cv<typename std::remove_pointer<
            typename std::remove_reference<TArg>::type>::type>::type,
        typename std::enable_if<
            !std::is_base_of<Structure, _TArgs>::value, int>::type = 0>
    inline Structure(TArg&& arg, TArgs&&... args);
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
    inline void Set(const std::size_t& index, T&& val);
public:
    template<typename T>
    inline ValueType<T> Get(const std::size_t& index);
    template<typename T>
    inline ValueConstType<T> Get(const std::size_t& index) const;
public:
    inline test::arg::Header GetHeader(const std::size_t& index);
public:
    inline std::size_t Size() const;
public:
    inline std::size_t AllocationSize() const;
    inline std::size_t AllocationSize(const std::size_t& index) const;
public:
    inline bool operator==(const Structure& other) const;
    inline bool operator!=(const Structure& other) const;
};

inline std::size_t Structure::_Count(std::size_t total,  std::size_t index,
    MapType& maps)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "_Count(total=%zu, index=%zu, maps=%p)", total, index, &maps);

    return total;
}

template<typename TArg, typename... TArgs>
inline std::size_t Structure::_Count(std::size_t total, std::size_t index,
    MapType& maps, TArg&& arg, TArgs&&... args)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "_Count<%s>(total=%zu, index=%zu, maps=%p, args={%s})", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TArg, TArgs...),
        total, index, &maps, TEST_SYS_DEBUG_TARGS_VALUE_STR(arg, args...));

    typedef typename test::arg::Structure::Type<TArg>::BaseType BaseType;

    const std::size_t size = test::arg::Structure::Type<TArg>::Size;
    maps[index] = BlockType{test::arg::Header::Make<BaseType>(), total, size};
    return _Count(total + size, index + 1, maps, std::forward<TArgs>(args)...);
}

inline std::size_t Structure::_Set(BufferType& buff, MapType& maps, 
    std::size_t index, std::size_t total)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "_Set(buff=%p, maps=%p, index=%zu, total=%zu)", 
        &buff, &maps, index, total);

    return index;
}

template<typename TArg, typename... TArgs>
inline std::size_t Structure::_Set(BufferType& buff, MapType& maps, 
    std::size_t index, std::size_t total, TArg&& arg, TArgs&&... args)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "_Count<%s>(buff=%p, maps=%p, index=%zu, total=%zu, args={%s})", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TArg, TArgs...), &buff, &maps, index, 
        total, TEST_SYS_DEBUG_TARGS_VALUE_STR(arg, args...));

    typedef typename test::arg::Structure::Type<TArg>::BaseType BaseType;
    if (index < total)
    {
        maps[index].template Set<BaseType>(buff, std::forward<TArg>(arg));
        return _Set(buff, maps, index + 1, total, std::forward<TArgs>(args)...);
    }
    else
    {
        return index;
    }
}

inline Structure::Structure() :
    m_maps(),
    m_buff()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");
}

template<typename TArg, typename... TArgs, typename _TArgs,
    typename std::enable_if<
        !std::is_base_of<Structure, _TArgs>::value, int>::type>
inline Structure::Structure(TArg&& arg, TArgs&&... args) :
    m_maps(test::ptr::arg::Array(sizeof...(TArgs) + 1)),
    m_buff(test::ptr::arg::Array(_Count(0, 0, m_maps, std::forward<TArg>(arg),
        std::forward<TArgs>(args)...)))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor<%s>(args={%s})", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TArg, TArgs...),
        TEST_SYS_DEBUG_TARGS_VALUE_STR(arg, args...));

    _Set(m_buff, m_maps, 0, m_maps.Size(), std::forward<TArg>(arg),
        std::forward<TArgs>(args)...);
}

inline Structure::~Structure()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

}

inline Structure::Structure(const Structure& cpy) :
    m_maps(cpy.m_maps),
    m_buff(cpy.m_buff)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Destructor(cpy=%p)", &cpy);

}

inline Structure::Structure(Structure&& mov) :
    m_maps(mov.m_maps),
    m_buff(mov.m_buff)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Destructor(mov=%p)", &mov);

}

inline Structure& Structure::operator=(const Structure& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);

    m_maps = cpy.m_maps;
    m_buff = cpy.m_buff;
    return *this;
}

inline Structure& Structure::operator=(Structure&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);

    m_maps = std::move(mov.m_maps);
    m_buff = std::move(mov.m_buff);
    return *this;
}

template<typename T>
inline void Structure::Set(const std::size_t& index, T&& val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Set<%s>(index=%zu, val=%s)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(T),
        index, TEST_SYS_DEBUG_TARGS_VALUE_STR(val));

    if (index < m_maps.Size())
    {
        return m_maps[index].template Set<T>(m_buff, 
            std::forward<T>(val));
    }
}

template<typename T>
inline typename Structure::ValueType<T> 
Structure::Get(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "Get<%s>(index=%zu) const", TEST_SYS_DEBUG_TARGS_NAME_STR(T), index);
    
    if (index < m_maps.Size())
    {
        return {m_maps[index], m_buff};
    }
    return {};
}

template<typename T>
inline typename Structure::ValueConstType<T> 
Structure::Get(const std::size_t& index) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "Get<%s>(index=%zu) const", TEST_SYS_DEBUG_TARGS_NAME_STR(T), index);
    
    if (index < m_maps.Size())
    {
        return {m_maps[index], m_buff};
    }
    return {};
}

inline test::arg::Header 
Structure::GetHeader(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "GetHeader(index=%zu)", index);

    if (index < m_maps.Size())
    {
        return m_maps[index].GetHeader();
    }
    return {};
}

inline std::size_t Structure::Size() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Size() const");

    return m_maps.Size();
}

inline std::size_t Structure::AllocationSize() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "AllocationSize() const");

    return m_buff.AllocationSize();
}

inline std::size_t Structure::
    AllocationSize(const std::size_t& index) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "AllocationSize(index=%zu) const", index);

    if (index < m_maps.Size())
    {
        return m_maps[index].GetSize();
    }
    return 0;
}

inline bool Structure::operator==(const Structure& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", &other);

    return m_maps == other.m_maps &&
        m_buff == other.m_buff;
}

inline bool Structure::operator!=(const Structure& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", &other);

    return  m_maps != other.m_maps ||
        m_buff != other.m_buff;
}

} //!arg

} //!test

#endif //!TEST_ARG_STRUCTURE_H_
