#ifndef TEST_SYS_BUFFER_H_
#define TEST_SYS_BUFFER_H_

#include "buffer/Record.h"
#include "out/Interface.h"

#include <thread>
#include <cstdlib>

namespace test
{
namespace sys
{

template<typename TStatus, std::size_t NLine, std::size_t NBuffer>
class Buffer;

} //!sys

} //!test


#ifndef TEST_SYS_BUFFER_DLEVEL

#define TEST_SYS_BUFFER_DLEVEL 2

#endif //!TEST_SYS_BUFFER_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TStatus>,\
    test::sys::dbg::type::Value<std::size_t, NLine>,\
    test::sys::dbg::type::Value<std::size_t, NBuffer>

template<typename TStatus, std::size_t NLine, std::size_t NBuffer>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_SYS_BUFFER_DLEVEL, 
    "test::sys::Buffer", 
    test::sys::Buffer<TStatus, NLine, NBuffer>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace sys
{

template<typename TStatus, std::size_t NLine, std::size_t NBuffer>
class Buffer : public test::sys::out::Interface<TStatus>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::
        Buffer<TStatus, NLine, NBuffer>> _DebugType;
public:
    typedef TStatus StatusType;
    typedef test::sys::Definition DefinitionType;
    typedef typename test::sys::Definition::Status StatusEnumType;
    typedef typename test::sys::Definition::StatusIntegerType StatusIntegerType;
    typedef typename test::sys::Definition::TimestampType TimestampType;
    typedef test::sys::Debug DebugType;
public:
    typedef int(*FormatDebugCallbackFunc)(char* buffer, 
        const std::size_t& buffer_size, DebugType& dbg, std::int8_t level, 
        const void * obj, const StatusType& status, 
        const char* msg);
public:
    typedef int(*FormatCallbackFunc)(char* buffer, 
        const std::size_t& buffer_size, const StatusType& status, 
        const char* msg);
private:
    static int DefaultFormat(char* buffer, 
        const std::size_t& buffer_size, const StatusType& status, 
        const char* msg);
private:
    static int DefaultDebugFormat(char* buffer, 
        const std::size_t& buffer_size, DebugType& dbg, std::int8_t level, 
        const void * obj, const StatusType& status, 
        const char* msg);
private:
    static int InsertBufferEmpty(Buffer<TStatus, NLine, NBuffer>* obj, 
        const char* buffer);
private:
    static int InsertBufferDefault(Buffer<TStatus, NLine, NBuffer>* obj, 
        const char* buffer);
private:
    static int InsertRecordEmpty(Buffer<TStatus, NLine, NBuffer>* obj, 
        const TimestampType& timestamp, const char* buffer);
    static int InsertRecordDefault(Buffer<TStatus, NLine, NBuffer>* obj, 
        const TimestampType& timestamp, const char* buffer);
private:
    std::size_t m_begin, m_end;
    StatusType& m_status;
    char* m_buffer;
    test::sys::buffer::Record<NBuffer>* m_records;
    int (*m_insertBuffer)(Buffer<TStatus, NLine, NBuffer>*, const char*);
    int (*m_insertRecord)(Buffer<TStatus, NLine, NBuffer>*, 
        const TimestampType&, const char*);
public:
    Buffer(StatusType& status);
public:
    Buffer(const Buffer<TStatus, NLine, NBuffer>&) = delete;
    Buffer(Buffer<TStatus, NLine, NBuffer>&&) = delete;
public:
    virtual ~Buffer();
public:
    Buffer<TStatus, NLine, NBuffer>& 
        operator=(const Buffer<TStatus, NLine, NBuffer>& cpy) = delete;
    Buffer<TStatus, NLine, NBuffer>& 
        operator=(Buffer<TStatus, NLine, NBuffer>&& mov) = delete;
private:
    char* GetBuffer();
    char* GetBuffer(const std::size_t& index);
private:
    test::sys::buffer::Record<NBuffer>& GetRecord();
    test::sys::buffer::Record<NBuffer>& 
        GetRecord(const std::size_t& index);
private:
    void Next();
protected:
    virtual int BufferOutput(char * buffer);
public:
    std::size_t Size() const;
public:
    int Clear(test::sys::out::Interface<TStatus>& out);
public:
    void Reset();
public:
    test::sys::buffer::Record<NBuffer>&
    operator[](const std::size_t& index);
};

template<typename TStatus, std::size_t NLine, std::size_t NBuffer>
int Buffer<TStatus, NLine, NBuffer>::
    InsertBufferEmpty(Buffer<TStatus, NLine, NBuffer>*, const char*)
{
    return 0;
}
    
template<typename TStatus, std::size_t NLine, std::size_t NBuffer>
int Buffer<TStatus, NLine, NBuffer>::
    InsertBufferDefault(Buffer<TStatus, NLine, NBuffer>* obj, 
        const char* buffer)
{
    return snprintf(obj->GetBuffer(), NBuffer, "%s", buffer);
}
    
template<typename TStatus, std::size_t NLine, std::size_t NBuffer>
int Buffer<TStatus, NLine, NBuffer>::
    InsertRecordEmpty(Buffer<TStatus, NLine, NBuffer>*, 
        const TimestampType&, const char*)
{
    return 0;
}
    
template<typename TStatus, std::size_t NLine, std::size_t NBuffer>
int Buffer<TStatus, NLine, NBuffer>::
    InsertRecordDefault(Buffer<TStatus, NLine, NBuffer>* obj, 
        const TimestampType& timestamp, const char* buffer)
{
    obj->GetRecord() = test::sys::buffer::Record<NBuffer>{timestamp, buffer};
    return 1;
}

template<typename TStatus, std::size_t NLine, std::size_t NBuffer>
Buffer<TStatus, NLine, NBuffer>::Buffer(StatusType& status) :
    test::sys::out::Interface<TStatus>(status),
        m_begin(0), 
        m_end(0),
        m_status(status),
        m_buffer(NULL),
        m_records(NULL),
        m_insertBuffer(InsertBufferEmpty),
        m_insertRecord(InsertRecordEmpty)
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 1, this, 
        "Constructor(status=%p)", &status);

    m_buffer = (char*)malloc(NBuffer * (NLine + 1));
    if (m_buffer == NULL)
    {
        SystemType::GetInstance().Error(
            DefinitionType::Status::sBufferAllocationFailed,
            "buffers allocation failed");
    }
    else
    {
        m_insertBuffer = InsertBufferDefault;
    }
    m_records = (test::sys::buffer::Record<NBuffer>*)
        malloc(sizeof(test::sys::buffer::Record<NBuffer>) * (NLine + 1));
    if (m_records == NULL)
    {
        SystemType::GetInstance().Error(
            DefinitionType::Status::sBufferAllocationFailed,
            "records allocation failed");
    }
    else
    {
        m_insertRecord = InsertRecordDefault;
    }
}

template<typename TStatus, std::size_t NLine, std::size_t NBuffer>
Buffer<TStatus, NLine, NBuffer>::~Buffer()
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 1, this, "Destructor");

    if (m_buffer != NULL)
    {
        free(m_buffer);
        m_buffer = NULL;
    }
    if (m_records != NULL)
    {
        free(m_records);
        m_records = NULL;
    }
}

template<typename TStatus, std::size_t NLine, std::size_t NBuffer>
char* Buffer<TStatus, NLine, NBuffer>::GetBuffer()
{
    const std::size_t last = m_end;
    return &m_buffer[last * NBuffer];
}

template<typename TStatus, std::size_t NLine, std::size_t NBuffer>
char* Buffer<TStatus, NLine, NBuffer>::
    GetBuffer(const std::size_t& index)
{
    return m_buffer[(index % (NLine + 1)) * NBuffer];
}

template<typename TStatus, std::size_t NLine, std::size_t NBuffer>
test::sys::buffer::Record<NBuffer>&
Buffer<TStatus, NLine, NBuffer>::GetRecord()
{
    const std::size_t last = m_end;
    return m_records[last];
}

template<typename TStatus, std::size_t NLine, std::size_t NBuffer>
test::sys::buffer::Record<NBuffer>&
Buffer<TStatus, NLine, NBuffer>::GetRecord(const std::size_t& index)
{
    return m_records[(index % (NLine + 1))];
}

template<typename TStatus, std::size_t NLine, std::size_t NBuffer>
void Buffer<TStatus, NLine, NBuffer>::Next()
{
    m_end = std::size_t((m_end + 1) % (NLine + 1));
}

template<typename TStatus, std::size_t NLine, std::size_t NBuffer>
int Buffer<TStatus, NLine, NBuffer>::BufferOutput(char * buffer)
{
    const auto timestamp = DefinitionType::GetTimestampNow();
    if ((Size() + 1) == (NLine + 1)) 
    {
        m_begin = (m_begin + 1) % (NLine + 1);
    }
    const auto res = m_insertBuffer(this, buffer);
    const auto ref = GetBuffer();
    m_insertRecord(this, timestamp, ref);
    Next();
    return 1;
}

template<typename TStatus, std::size_t NLine, std::size_t NBuffer>
std::size_t Buffer<TStatus, NLine, NBuffer>::Size() const
{
    const std::size_t bg = m_begin;
    const std::size_t ed = m_end;
    return bg <= ed ? ed - bg : ((NLine + 1) + ed) - bg;
}

template<typename TStatus, std::size_t NLine, std::size_t NBuffer>
int Buffer<TStatus, NLine, NBuffer>::
    Clear(test::sys::out::Interface<TStatus>& out)
{
    const std::size_t bg = m_begin;
    const std::size_t ed = m_end;
    const std::size_t size = Size();
    for (std::size_t i = 0; i < size; ++i)
    {
        const auto rec = GetRecord((bg + i) % (NLine + 1));
        char * ref = const_cast<char*>(rec.GetMessage());
        out.BufferOutput(ref);
    }
    return size;
}

template<typename TStatus, std::size_t NLine, std::size_t NBuffer>
void Buffer<TStatus, NLine, NBuffer>::Reset()
{
    m_begin = m_end;
}

template<typename TStatus, std::size_t NLine, std::size_t NBuffer>
test::sys::buffer::Record<NBuffer>& 
Buffer<TStatus, NLine, NBuffer>::operator[](const std::size_t& index)
{
    return GetRecord(m_begin + index);
}

} //!sys

} //!test


#endif //!TEST_SYS_BUFFER_H_
