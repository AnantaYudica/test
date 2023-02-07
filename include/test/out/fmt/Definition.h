#ifndef TEST_OUT_FMT_DEFINITION_H_
#define TEST_OUT_FMT_DEFINITION_H_

#include "../../System.h"
#include "../Interface.h"
#include "Flag.h"

#include <cstdint>
#include <cwchar>

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
    template<typename TChar>
    using OutputInterfaceType = test::out::Interface<TChar>;
public:
    template<typename TChar>
    using FormatOutputFuncType = std::size_t (*)(OutputInterfaceType<TChar>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred);
public:
    typedef std::uint8_t OutputIntegerType;
public:
    static constexpr std::size_t string_max_len = 1024;
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
    static constexpr OutputIntegerType output_undefined = 0;
    static constexpr OutputIntegerType output_char = 1;
    static constexpr OutputIntegerType output_wchar = 2;
public:
    static constexpr inline OutputIntegerType OutputValue(...);
    static constexpr inline OutputIntegerType OutputValue(char&&);
    static constexpr inline OutputIntegerType OutputValue(wchar_t&&);
};

constexpr inline typename Definition::OutputIntegerType 
Definition::OutputValue(...)
{
    return output_undefined;
}

constexpr inline typename Definition::OutputIntegerType 
Definition::OutputValue(char&&)
{
    return output_char;
}

constexpr inline typename Definition::OutputIntegerType 
Definition::OutputValue(wchar_t&&)
{
    return output_wchar;
}

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_DEFINITION_DLEVEL

#define TEST_OUT_FMT_DEFINITION_DLEVEL 2

#endif //!TEST_OUT_FMT_DEFINITION_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_DEFINITION_DLEVEL, 
    "test::out::fmt::Definition", test::out::fmt::Definition);

#endif //!TEST_OUT_FMT_DEFINITION_H_
