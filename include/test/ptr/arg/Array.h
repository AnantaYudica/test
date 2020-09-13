#ifndef TEST_PTR_ARG_ARRAY_H_
#define TEST_PTR_ARG_ARRAY_H_

#include <cstddef>

namespace test
{
namespace ptr
{
namespace arg
{

class Array
{
private:
    std::size_t m_size;
public:
    inline constexpr Array();
    inline constexpr Array(const std::size_t& size);
public:
    inline constexpr std::size_t GetSize() const;
};

inline constexpr Array::Array() : m_size(0)
{}

inline constexpr Array::Array(const std::size_t& size) :
    m_size(size)
{}

inline constexpr std::size_t Array::GetSize() const
{
    return m_size;
}

} //!arg

} //!ptr

} //!test

#endif //!TEST_PTR_ARG_ARRAY_H_
