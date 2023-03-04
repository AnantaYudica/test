#ifndef TEST_OUT_FMT_VAL_DATA_H_
#define TEST_OUT_FMT_VAL_DATA_H_

#include "../../../System.h"
#include "../../../Pointer.h"
#include "../Definition.h"
#include "../Block.h"
#include "Structure.h"

#include <cstdarg>
#include <utility>
#include <mutex>

namespace test
{
namespace out
{
namespace fmt
{
namespace val
{

template<typename TStatus>
class Data;

} //!val

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_VAL_DATA_DLEVEL

#define TEST_OUT_FMT_VAL_DATA_DLEVEL 2

#endif //!TEST_OUT_FMT_VAL_DATA_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TStatus>

template<typename TStatus>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_FMT_VAL_DATA_DLEVEL, 
    "test::out::fmt::val::Data", 
    test::out::fmt::val::Data<TStatus>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace out
{
namespace fmt
{
namespace val
{

template<typename TStatus>
class Data
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::out::fmt::val::Data<TStatus>> DebugType;
public:
    typedef test::out::fmt::Definition DefinitionType;
public:
    typedef test::out::fmt::val::Structure<TStatus> StructureType;
public:
    typedef typename StructureType::StatusType StatusType;
    typedef typename StructureType::BlocksType BlocksType;
    typedef typename StructureType::RawType RawType;
public:
    typedef typename StatusType::IntegerValueType StatusIntegerValueType;
public:
    test::Pointer<StructureType> m_ptr;
public:
    Data();
    ~Data();
public:
    Data(const Data<TStatus>& cpy);
    Data(Data<TStatus>&& mov);
public:
    Data<TStatus>& operator=(const Data<TStatus>& cpy);
    Data<TStatus>& operator=(Data<TStatus>&& mov);
public:
    std::mutex& GetLock();
public:
    std::size_t& GetLoadSize();
    std::size_t GetLoadSize() const;
public:
    StatusType& GetStatus();
    StatusType GetStatus() const;
public:
    BlocksType& GetBlocks();
public:
    RawType& GetRaw();
};

template<typename TStatus>
Data<TStatus>::Data() :
    m_ptr()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

template<typename TStatus>
Data<TStatus>::~Data()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

}

template<typename TStatus>
Data<TStatus>::Data(const Data<TStatus>& cpy) :
    m_ptr(cpy.m_ptr)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);

}

template<typename TStatus>
Data<TStatus>::Data(Data<TStatus>&& mov) :
    m_ptr(std::move(mov.m_ptr))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

}

template<typename TStatus>
Data<TStatus>& Data<TStatus>::operator=(const Data<TStatus>& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);

    m_ptr = cpy.m_ptr;

    return *this;
}

template<typename TStatus>
Data<TStatus>& Data<TStatus>::operator=(Data<TStatus>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);

    m_ptr = std::move(mov.m_ptr);
    return *this;
}

template<typename TStatus>
std::mutex& Data<TStatus>::GetLock()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetLock()");

    return m_ptr->m_lock;
}

template<typename TStatus>
std::size_t& Data<TStatus>::GetLoadSize()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetLoadSize()");

    return m_ptr->m_loadSize;
}

template<typename TStatus>
std::size_t Data<TStatus>::GetLoadSize() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetLoadSize() const");

    return m_ptr->m_loadSize;
}

template<typename TStatus>
typename Data<TStatus>::StatusType& Data<TStatus>::GetStatus()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetStatus()");

    return m_ptr->m_status;
}

template<typename TStatus>
typename Data<TStatus>::StatusType Data<TStatus>::GetStatus() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetStatus() const");

    return m_ptr->m_status;
}

template<typename TStatus>
typename Data<TStatus>::BlocksType& Data<TStatus>::GetBlocks()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetBlocks()");

    return m_ptr->m_blocks;
}

template<typename TStatus>
typename Data<TStatus>::RawType& Data<TStatus>::GetRaw()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetRaw()");

    return m_ptr->m_raw;
}

} //!val

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_VAL_DATA_H_

