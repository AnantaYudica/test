#ifndef TEST_REG_BASE_H_
#define TEST_REG_BASE_H_

#include <cstddef>

namespace test
{
namespace reg
{

class Base
{
protected:
    Base();
public:
    Base(const Base&) = delete;
    Base(Base&&);
    virtual ~Base();
public:
    virtual int Run() = 0;
    virtual const char* File() const = 0;
    virtual const std::size_t& Line() const = 0;
};

inline Base::Base()
{}

inline Base::Base(Base&&)
{}

inline Base::~Base()
{}


} //!reg

} //!test

#endif //!TEST_REG_BASE_H_
