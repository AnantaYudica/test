#ifndef TEST_MSG_FMT_PARAMETER_H_
#define TEST_MSG_FMT_PARAMETER_H_

#include "../../out/Interface.h"

#include <cstdarg>
#include <cstddef>

namespace test
{
namespace msg
{
namespace fmt
{

template<typename TChar>
class Parameter
{
protected:
    Parameter() = default;
public:
    virtual ~Parameter() = default;
public:
    virtual bool VLoad(std::size_t size, std::size_t index, 
        va_list args) = 0;
    virtual bool Load(std::size_t size, ...) = 0;
};

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_PARAMETER_H_
