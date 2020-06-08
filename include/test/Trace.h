#ifndef TEST_TRACE_H_
#define TEST_TRACE_H_

#include <cstddef>

namespace basic
{
namespace test
{
    
struct Trace
{
    const char* File;
    const std::size_t Line;
    Trace(const char* file, const std::size_t line) :
        File(file), Line(line)
    {}
};

} //!test

} //!basic

#endif //!TEST_TRACE_H_
