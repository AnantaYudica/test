#ifndef TEST_SYS_SIGNALS_H_
#define TEST_SYS_SIGNALS_H_

#include "Signals.defn.h"
#include "Signal.h"

namespace test
{
namespace sys
{

template<typename TStatus>
Signals<TStatus>::Signals(StatusType& status, LogType& log) :
    m_lastSig(0),
    m_size(0),
    m_alloc(8),
    m_list(NULL),
    m_status(status),
    m_log(log),
    m_mutex()
{
    Allocation();
}

template<typename TStatus>
Signals<TStatus>::~Signals()
{
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
    if (m_list == NULL)
    {
        if (m_alloc == 0)
        {
            m_alloc = 8;
        }
        
        m_list = (SignalType**)malloc(m_alloc * sizeof(SignalType*));

        if (m_list == NULL)
        {
            m_status.Error(StatusType::sSignalsAllocFailed);
            m_log.Output("Signals Allocation is failed");
        }
    }
}

template<typename TStatus>
bool Signals<TStatus>::Reallocation()
{
    const std::size_t new_alloc = m_alloc << 1;
    if (m_alloc >= new_alloc)
    {
        m_status.Error(StatusType::sSignalsReallocOverflow);
        m_log.Output("Signals Reallocation is overflow");
        return false;
    }
    auto new_list = (SignalType**)realloc(m_list, new_alloc * sizeof(SignalType*));
    if (new_list == NULL)
    {
        m_status.Error(StatusType::sSignalsReallocFailed);
        m_log.Output("Signals Reallocation is failed");
        return false;
    }
    m_list = new_list;
    m_alloc = new_alloc;

    return true;
}

template<typename TStatus>
bool Signals<TStatus>::Insert(SignalType* sig)
{
    if (m_lastSig != 0 || m_list == NULL || sig == NULL)
    {
        return false;
    }

    std::lock_guard<std::mutex> guard(m_mutex);
    
    if (m_alloc == m_size && !Reallocation())
    {
        m_status.Error(StatusType::sSignalsReallocFailed);
        m_log.Output("Signals Reallocation is failed");
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
    return m_size;
}

template<typename TStatus>
void Signals<TStatus>::Raise(int sig)
{
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
