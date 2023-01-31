#ifndef TEST_OUT_FMT_DEFINITION_H_
#define TEST_OUT_FMT_DEFINITION_H_

#include "../../System.h"
#include "Flag.h"

#include <cstdint>

namespace test
{
namespace out
{
namespace fmt
{

class Definition
{
public:
    typedef test::out::fmt::Flag<std::uint32_t, std::uint32_t> FlagType;
public:
    static constexpr int value_character = 1;
    static constexpr int value_boolean = 2;
    static constexpr int value_integer = 3;
    static constexpr int value_floatingPoint = 4;
    static constexpr int value_pointer = 5;
    static constexpr int value_string = 6;
    static constexpr int value_nothing = 7;
    static constexpr int value_object = 8;
public:

};

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_DEFINITION_DLEVEL

#define TEST_OUT_FMT_DEFINITION_DLEVEL 2

#endif //!TEST_OUT_FMT_DEFINITION_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_DEFINITION_DLEVEL, 
    "test::out::fmt::Definition", test::out::fmt::Definition);

#endif //!TEST_OUT_FMT_DEFINITION_H_
