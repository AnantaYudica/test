#ifndef TEST_OUT_DEFINITION_H_
#define TEST_OUT_DEFINITION_H_

#include "../System.h"
#include "Interface.h"
#include "fmt/Flag.decl.h"

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
    typedef test::out::fmt::Flag<std::uint32_t, std::uint32_t> FlagType;
public:
    template<typename TChar>
    using OutputInterfaceType = test::out::Interface<TChar>;
public:
    template<typename TChar>
    using FormatOutputFuncType = std::size_t (*)(OutputInterfaceType<TChar>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred);
};

} //!out

} //!test

#ifndef TEST_OUT_DEFINITION_DLEVEL

#define TEST_OUT_DEFINITION_DLEVEL 2

#endif //!TEST_OUT_DEFINITION_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_DEFINITION_DLEVEL, 
    "test::out::Definition", test::out::Definition);

#endif //!TEST_OUT_DEFINITION_H_
