#ifndef TEST_NODE_LINK_H_
#define TEST_NODE_LINK_H_

#include "../Node.h"

#include <cstddef>

namespace test
{
namespace node
{

namespace link
{

enum : std::size_t
{
    next = 0,
    prev = 1,
};

} //!link

template<std::size_t L, typename T, std::size_t N>
inline test::Node<T, N, N - 1>* Link(test::Node<T, N, N - 1> * node)
{
    test::Node<T, N, L> * cast = dynamic_cast<test::Node<T, N, L>*>(node);
    if (cast == nullptr) return nullptr;
    return cast->Link();
}

template<std::size_t L, typename T, std::size_t N>
inline void Link(test::Node<T, N, N - 1> * node, test::Node<T, N, N - 1>* link)
{
    test::Node<T, N, L> * cast = dynamic_cast<test::Node<T, N, L>*>(node);
    if (cast == nullptr) return;
    return cast->Link(link);
}

} //!node

} //!test

#endif //!TEST_NODE_LINK_H_