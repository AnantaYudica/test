#ifndef TEST_MSG_FMT_PARAMETER_H_
#define TEST_MSG_FMT_PARAMETER_H_

#include "../../out/Interface.h"
#include "Status.h"

#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <utility>

namespace test
{
namespace msg
{
namespace fmt
{

template<typename TChar>
class Parameter
{
public:
    typedef test::msg::fmt::Status<std::uint8_t> StatusType;
    typedef test::out::Interface<TChar> OutputInterfaceType;
private:
    StatusType m_status;
protected:
    Parameter();
    template<typename... TArgs>
    Parameter(TArgs&&... args);
public:
    virtual ~Parameter() = default;
public:
    virtual std::size_t VLoad(std::size_t size, std::size_t index, 
        va_list args) = 0;
    virtual std::size_t Load(std::size_t size, ...) = 0;
protected:
    StatusType& GetStatus();
    StatusType GetStatus() const;
};

template<typename TChar>
Parameter<TChar>::Parameter() :
    m_status()
{}

template<typename TChar>
template<typename... TArgs>
Parameter<TChar>::Parameter(TArgs&&... args) :
    m_status(std::forward<TArgs>(args)...)
{}

template<typename TChar>
typename Parameter<TChar>::StatusType& 
Parameter<TChar>::GetStatus()
{
    return m_status;
}

template<typename TChar>
typename Parameter<TChar>::StatusType 
Parameter<TChar>::GetStatus() const
{
    return {m_status};
}

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_PARAMETER_H_
