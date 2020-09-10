#ifndef TEST_DEF_TYPE_NAME_VAL_NULLPTR_H_
#define TEST_DEF_TYPE_NAME_VAL_NULLPTR_H_

#include "../../../../CString.h"
#include "../../../../type/name/val/Get.h"

#include <cstddef>

namespace test
{
namespace type
{
namespace name
{
namespace val
{

template<>
struct Get<std::nullptr_t>
{
    template<std::nullptr_t V, typename TChar= char>
    static test::CString<TChar> CStr()
    {
        static TChar _val[] = "nullptr";
        return {_val};
    }
};

} //!val

} //!name

} //!type

} //!test


#endif //!TEST_DEF_TYPE_NAME_VAL_NULLPTR_H_
