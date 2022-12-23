#ifndef TEST_SYS_DBG_NMSPC_DEFINITION_H_
#define TEST_SYS_DBG_NMSPC_DEFINITION_H_

#include <cstddef>
#include <cstdint>

namespace test
{
namespace sys
{
namespace dbg
{
namespace nmspc
{

class Definition
{
public:
    static constexpr char Words[] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 
        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
        'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 
        'U', 'V', 'W', 'X', 'Y', 'Z',
        '_'};
public:
    static constexpr std::size_t Split = 10;
public:
    static constexpr inline std::uint64_t Index(std::uint64_t index, 
        std::uint64_t n)
    {
        return (index == 0 ? 0 : (index == 1 ? n :
            Index(index - 1, n) * n));
    }

    static constexpr inline std::uint64_t Key(char ch, std::uint64_t index, 
        std::uint64_t count = 0)
    {
        return (sizeof(Words) == count ? 
            count + Index(index, sizeof(Words) + 1) :
            (ch == Words[count] ? 
                count + Index(index, sizeof(Words) + 1) : 
                Key(ch, index, count + 1)));
    }
    template<std::size_t N>
    static constexpr inline std::uint64_t Key(const char (&name)[N], std::size_t bg, 
        std::uint64_t count = 0, std::uint64_t sum = 0)
    {
        return ((N - 1) < bg ? sum : 
            (count == Split ? sum : 
                Key(name, bg + 1, count + 1, 
                    sum + Key(name[(N - bg) - 1], count))));
    }
public:
    Definition() = delete;
};

} //!nmspc

} //!sys

} //!dbg

} //!test

#endif //!TEST_SYS_DBG_NMSPC_DEFINITION_H_
