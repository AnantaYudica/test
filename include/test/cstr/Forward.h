#ifndef TEST_CSTR_FORWARD_H_
#define TEST_CSTR_FORWARD_H_

#include "../Forward.h"
#include "../CString.h"

namespace test
{

template<typename TChar>
struct Forward<test::CString<TChar>>
{
    typedef const TChar* Type;
    static const TChar* Value(test::CString<TChar> & cstr);
    static const TChar* Value(const test::CString<TChar> & cstr);
    static const TChar* Value(test::CString<TChar> && cstr);
};

template<typename TChar>
const TChar* Forward<test::CString<TChar>>::
    Value(test::CString<TChar> & cstr)
{
    return *cstr;
}

template<typename TChar>
const TChar* Forward<test::CString<TChar>>::
    Value(const test::CString<TChar> & cstr)
{
    return *cstr;
}

template<typename TChar>
const TChar* Forward<test::CString<TChar>>::
    Value(test::CString<TChar> && cstr)
{
    return *cstr;
}

} //!test

#endif //!TEST_CSTR_FORWARD_H_
