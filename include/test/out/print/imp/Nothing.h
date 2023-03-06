#ifndef TEST_OUT_PRINT_IMP_NOTHING_H_
#define TEST_OUT_PRINT_IMP_NOTHING_H_

#include "../../../System.h"
#include "../../Definition.h"
#include "../../fmt/Flag.h"

#include <cstddef>
#include <cwchar>

namespace test
{
namespace out
{
namespace print
{
namespace imp
{

struct Nothing
{
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;

    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return 0;
    }

    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return 0;
    }

};

} //!imp

} //!print

} //!out

} //!test

#ifndef TEST_OUT_PRINT_IMP_NOTHING_DLEVEL

#define TEST_OUT_PRINT_IMP_NOTHING_DLEVEL 2

#endif //!TEST_OUT_PRINT_IMP_NOTHING_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_PRINT_IMP_NOTHING_DLEVEL, 
    "test::out::print::imp::Nothing", test::out::print::imp::Nothing);

#endif //!TEST_OUT_PRINT_IMP_NOTHING_H_
