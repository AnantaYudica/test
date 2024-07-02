#ifndef TEST_SYS_BUFFER_RECORD_H_
#define TEST_SYS_BUFFER_RECORD_H_

#include "../Definition.h"

#include <chrono>
#include <cstdlib>

namespace test
{
namespace sys
{
namespace buffer
{

template<std::size_t N>
class Record;

} //!buffer

} //!sys

} //!test

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS \
    test::sys::dbg::type::Value<std::size_t, N>

template<std::size_t N>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE(
    "test::sys::buffer::Record", 
    test::sys::buffer::Record<N>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS


namespace test
{
namespace sys
{
namespace buffer
{

template<std::size_t N>
class Record
{
public:
    typedef typename test::sys::Definition::TimestampType TimestampType;
private:
    TimestampType m_timestamp;
    const char* m_message;
public:
    Record(const TimestampType& timestamp, const char* msg);
public:
    ~Record();
public:
    Record(const Record<N>& cpy);
    Record(Record<N>&& mov);
public:
    Record<N>& operator=(const Record<N>& cpy);
    Record<N>& operator=(Record<N>&& mov);
public:
    TimestampType GetTimestamp() const;
public:
    const char* GetMessage() const;
};

template<std::size_t N>
Record<N>::Record(const TimestampType& timestamp, 
    const char* msg) :
        m_timestamp(timestamp),
        m_message(msg)
{}

template<std::size_t N>
Record<N>::~Record()
{}

template<std::size_t N>
Record<N>::Record(const Record<N>& cpy) :
    m_timestamp(cpy.m_timestamp),
    m_message(cpy.m_message)
{}

template<std::size_t N>
Record<N>::Record(Record<N>&& mov) :
    m_timestamp(mov.m_timestamp),
    m_message(mov.m_message)
{}

template<std::size_t N>
Record<N>& Record<N>::operator=(const Record<N>& cpy)
{
    m_timestamp = cpy.m_timestamp;
    m_message = cpy.m_message;
    return *this;
}

template<std::size_t N>
Record<N>& Record<N>::operator=(Record<N>&& mov)
{
    m_timestamp = mov.m_timestamp;
    m_message = mov.m_message;
    return *this;
}

template<std::size_t N>
typename Record<N>::TimestampType 
Record<N>::GetTimestamp() const
{
    return m_timestamp;
}

template<std::size_t N>
const char* Record<N>::GetMessage() const
{
    return m_message;
}

} //!buffer

} //!sys

} //!test

#endif //!TEST_SYS_BUFFER_RECORD_H_
