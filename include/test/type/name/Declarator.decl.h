#ifndef TEST_TYPE_NAME_DECLARATOR_H_DECL_
#define TEST_TYPE_NAME_DECLARATOR_H_DECL_

namespace test
{
namespace type
{
namespace name
{

template<typename T, typename TB = T, typename... TArgs>
struct Declarator;

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_DECLARATOR_H_DECL_
