#ifndef TEST_SYS_SIGNALS_H_
#define TEST_SYS_SIGNALS_H_

#include "Interface.h"
#include "Signals.defn.h"
#include "Signal.defn.h"

namespace test
{
namespace sys
{

template<typename TStatus>
Signals<TStatus>::Signals(StatusType& status) :
    m_lastSig(0),
    m_size(0),
    m_alloc(8),
    m_list(NULL),
    m_status(status),
    m_mutex()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(status=%p)", &status);
    
    Allocation();
}

template<typename TStatus>
Signals<TStatus>::~Signals()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");
    
    for (std::size_t i = 0; i < m_size; ++i)
    {
        m_list[i] = nullptr;
    }
    free(m_list);
    m_list = nullptr;
    m_size = 0;
    m_alloc = 0;
}

template<typename TStatus>
void Signals<TStatus>::Allocation()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "Allocation()");
    
    if (m_list == NULL)
    {
        if (m_alloc == 0)
        {
            m_alloc = 8;
        }
        
        m_list = (SignalType**)malloc(m_alloc * sizeof(SignalType*));

        if (m_list == NULL)
        {
            SystemType::GetInstance().Error(
                DefinitionType::Status::sSignalsAllocationFailed, 
                "Signals Allocation is failed");
        }
    }
}

template<typename TStatus>
bool Signals<TStatus>::Reallocation()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "Reallocation()");
    
    const std::size_t new_alloc = m_alloc << 1;
    if (m_alloc >= new_alloc)
    {
        SystemType::GetInstance().Error(
            DefinitionType::Status::sSignalsReallocationOverflow, 
            "Signals Reallocation is overflow");
        return false;
    }
    auto new_list = (SignalType**)realloc(m_list, new_alloc * sizeof(SignalType*));
    if (new_list == NULL)
    {
        SystemType::GetInstance().Error(
            DefinitionType::Status::sSignalsReallocationFailed,
            "Signals Reallocation is failed");
        return false;
    }
    m_list = new_list;
    m_alloc = new_alloc;

    return true;
}

template<typename TStatus>
bool Signals<TStatus>::Insert(SignalType* sig)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "Insert(sig=%p)", sig);
    
    if (m_lastSig != 0 || m_list == NULL || sig == NULL)
    {
        return false;
    }

    std::lock_guard<std::mutex> guard(m_mutex);
    
    if (m_alloc == m_size && !Reallocation())
    {
        SystemType::GetInstance().Error(
            DefinitionType::Status::sSignalsReallocationFailed,
            "Signals Reallocation is failed");
        return false;
    }

    for (std::size_t i = 0; i < m_size; ++i)
    {
        if (m_list[i] == sig)
        {
            return false;
        }
    }

    m_list[m_size++] = sig;

    return true;
}

template<typename TStatus>
bool Signals<TStatus>::Remove(SignalType* sig)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "Remove(sig=%p)", sig);
    
    if (m_lastSig != 0 || m_list == NULL || sig == NULL)
    {
        return false;
    }
    
    std::lock_guard<std::mutex> guard(m_mutex);
    
    bool result = false;

    for (std::size_t i = 0; i < m_size; ++i)
    {
        if (!result && m_list[i] == sig)
        {
            result = true;
            m_list[i] = nullptr;
        }
        else
        {
            m_list[i - 1] = m_list[i];
            m_list[i] = nullptr;
        }
    }

    if (result)
    {
        --m_size;
    }

    return result;
}

template<typename TStatus>
void Signals<TStatus>::Clear()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "Clear()");
    
    if (m_lastSig != 0 || m_list == NULL)
    {
        return;
    }

    std::lock_guard<std::mutex> guard(m_mutex);

    for (std::size_t i = 0; i < m_size; ++i)
    {
        m_list[i] = nullptr;
    } 

    m_size = 0;
}

template<typename TStatus>
std::size_t Signals<TStatus>::Size() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Size() const");
    
    return m_size;
}

template<typename TStatus>
void Signals<TStatus>::Raise(int sig)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Raise(sig=%d)", sig);
    
    if (m_lastSig != 0) 
    {
        return;
    }

    m_lastSig = sig;

    if (m_list == NULL)
    {
        return;
    }
    
    {
        std::lock_guard<std::mutex> guard(m_mutex);

        for (std::size_t i = 0; i < m_size; ++i)
        {
            m_list[i]->Termination(sig);
            m_list[i] = nullptr;
        } 

        free(m_list);
        m_list = nullptr;
        m_size = 0;
        m_alloc = 8;
    }
    
}

} //!sys

} //!test

#endif //!TEST_SYS_SIGNALS_H_
