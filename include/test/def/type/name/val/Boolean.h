#ifndef TEST_DEF_TYPE_NAME_VAL_BOOLEAN_H_
#define TEST_DEF_TYPE_NAME_VAL_BOOLEAN_H_

#include "../../../../CString.h"
#include "../../../../cstr/Format.h"
#include "../../../../type/name/val/Get.h"

#include <cstdint>

namespace test
{
namespace type
{
namespace name
{
namespace val
{

template<>
struct Get<bool>
{
    template<bool V, typename TChar= char>
    static test::CString<TChar> CStr()
    {
        test::CString<TChar> _val = test::cstr::Format(
            (V ? sizeof("true") : sizeof("false")), "%s", 
            (V ? "true" : "false"));
        return {_val};
    }
};

} //!val

} //!name

} //!type

} //!test


#endif //!TEST_DEF_TYPE_NAME_VAL_BOOLEAN_H_