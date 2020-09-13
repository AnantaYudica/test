#ifndef TEST_PTR_DEFN_H_
#define TEST_PTR_DEFN_H_

namespace test
{
namespace ptr
{
namespace defn
{

class Finalization
{
protected:
    Finalization() = default;
public:
    virtual ~Finalization() = default;
public:
    virtual void Destructor(void* data) const = 0;
};

} //!defn

} //!ptr

} //!test

#endif //!TEST_PTR_DEFN_H_
