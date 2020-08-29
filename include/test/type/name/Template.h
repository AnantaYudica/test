#ifndef TEST_TYPE_NAME_TEMPLATE_H_
#define TEST_TYPE_NAME_TEMPLATE_H_

#include "../../CString.h"
#include "../../cstr/Format.h"
#include "Value.h"
#include "Parameter.h"
#include "tmpl/Get.h"
#include "tmpl/Parameter.h"

namespace test
{
namespace type
{
namespace name
{

template<typename T>
struct Template
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<char> _tmpl = test::cstr::Format((3 +
            test::type::name::tmpl::Get<decltype(
                test::type::name::tmpl::Parameter(std::declval<T*>()))>::
                template CStr<TChar>().Size()),
            "<%s>", *( test::type::name::tmpl::Get<decltype(
                test::type::name::tmpl::Parameter(std::declval<T*>()))>::
                template CStr<TChar>()));
        return {_tmpl};
    }
};

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_TEMPLATE_H_
