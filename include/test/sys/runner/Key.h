#ifndef TEST_SYS_RUNNER_KEY_H_
#define TEST_SYS_RUNNER_KEY_H_

#include <cstdlib>
#include <thread>

namespace test
{
namespace sys
{
namespace runner
{
    
class Key;

} //!runner

} //!sys

} //!test


TEST_SYS_DBG_TYPE_DEFINE("test::sys::runner::Key", test::sys::runner::Key);

namespace test
{
namespace sys
{
namespace runner
{

class Key
{
private:
    std::size_t m_reducer;
    std::size_t m_divisor;
public:
    inline Key();
    inline Key(const std::size_t& reducer, const std::size_t& divisor);
public:
    inline Key(const Key& cpy);
    inline Key(Key&& mov);
public:
    inline Key& operator=(const Key& cpy);
    inline Key& operator=(Key&& mov);
public:
    inline std::size_t Index(const std::size_t& hid) const;
    inline std::size_t Index(typename std::thread::id id) const;
    inline std::size_t Size() const;
public:
    inline operator bool() const;
};

inline Key::Key() :
    m_reducer(0),
    m_divisor(0)
{}

inline Key::Key(const std::size_t& reducer, const std::size_t& divisor) :
    m_reducer(reducer),
    m_divisor(divisor)
{}

inline Key::Key(const Key& cpy) :
    m_reducer(cpy.m_reducer),
    m_divisor(cpy.m_divisor)
{}

inline Key::Key(Key&& mov) :
    m_reducer(mov.m_reducer),
    m_divisor(mov.m_divisor)
{}

inline Key& Key::operator=(const Key& cpy)
{
    m_reducer = cpy.m_reducer;
    m_divisor = cpy.m_divisor;
    return *this;
}

inline Key& Key::operator=(Key&& mov)
{
    m_reducer = mov.m_reducer;
    m_divisor = mov.m_divisor;
    return *this;
}

inline std::size_t Key::Index(const std::size_t& hid) const
{
    return (hid - m_reducer) % m_divisor;
}

inline std::size_t Key::Index(typename std::thread::id id) const
{
    return Index(std::hash<std::thread::id>{}(id));
}

inline std::size_t Key::Size() const
{
    return m_divisor;
}

inline Key::operator bool() const
{
    return m_divisor != 0;
}

} //!runner

} //!sys

} //!test

#endif //!TEST_SYS_RUNNER_KEY_H_
