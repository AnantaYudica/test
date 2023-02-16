#ifndef TEST_OUT_DEFINITION_H_
#define TEST_OUT_DEFINITION_H_

#include "../System.h"
#include "fmt/Definition.h"

#include <cstdint>
#include <cwchar>
#include <type_traits>

namespace test
{
namespace out
{

class Definition
{
public:
    typedef typename test::out::fmt::Definition::FlagType FlagType;
public:
    template<typename TChar>
    using OutputInterfaceType = test::out::Interface<TChar>;
public:
    template<typename TChar>
    using FormatOutputFuncType = typename test::out::fmt::Definition::
        FormatOutputFuncType<TChar>;
};

} //!out

} //!test

#ifndef TEST_OUT_DEFINITION_DLEVEL

#define TEST_OUT_DEFINITION_DLEVEL 2

#endif //!TEST_OUT_DEFINITION_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_DEFINITION_DLEVEL, 
    "test::out::Definition", test::out::Definition);

#endif //!TEST_OUT_DEFINITION_H_
