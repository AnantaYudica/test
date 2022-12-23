#ifndef TEST_SYS_DBG_NMSPC_INDEX_H_
#define TEST_SYS_DBG_NMSPC_INDEX_H_

#include "Definition.h"

#include <cstddef>
#include <cstdint>
#include <type_traits>

namespace test
{
namespace sys
{
namespace dbg
{
namespace nmspc
{

template<std::size_t N>
class Index
{
public:
    static constexpr std::size_t Count = 
        N / test::sys::dbg::nmspc::Definition::Split;
private:
    const char(&m_name)[N];
public:
    constexpr Index(const char(&name)[N]) :
        m_name(name)
    {};
public:
    template<std::size_t I>
    constexpr std::uint64_t Value()
    {
        return (I > Count ? 0 : test::sys::dbg::nmspc::Definition::Key(
            m_name, I * test::sys::dbg::nmspc::Definition::Split));
    }
};


} //!nmspc

} //!dbg

} //!sys

} //!test


#endif //!TEST_SYS_DBG_NMSPC_INDEX_H_
