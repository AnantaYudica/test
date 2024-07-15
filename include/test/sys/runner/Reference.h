#ifndef TEST_SYS_RUNNER_REFERENCE_H_
#define TEST_SYS_RUNNER_REFERENCE_H_

namespace test
{
namespace sys
{
namespace runner
{

class Reference;

} //!runner

} //!sys

} //!test

TEST_SYS_DBG_TYPE_DEFINE("test::sys::Task", 
    test::sys::runner::Reference);

namespace test
{
namespace sys
{
namespace runner
{

class Reference
{
public:
    typedef void(*ClearFuncType)(void* ptr);
    typedef bool(*IsStopFuncType)(void* ptr);
private:
    static inline void DefaultClear(void* ptr);
    static inline bool DefaultIsStop(void* ptr);
private:
    void* m_ptr;
    ClearFuncType m_clearFunc;
    IsStopFuncType m_isStopFunc;
public:
    inline Reference();
    inline Reference(void* m_ptr, ClearFuncType clear_func, 
        IsStopFuncType is_stop_func);
public:
    inline ~Reference();
public:
    inline Reference(const Reference& cpy);
    inline Reference(Reference&& mov);
public:
    inline Reference& operator=(const Reference& cpy);
    inline Reference& operator=(Reference&& mov);
public:
    void* operator new (std::size_t) = delete;
    void* operator new[] (std::size_t) = delete;
    void operator delete(void*) = delete;
    void operator delete[](void*) = delete;
public:
    inline void Clear(); 
public:
    inline bool IsStop() const;
};

inline void Reference::DefaultClear(void*)
{}

inline bool Reference::DefaultIsStop(void*)
{
    return false;
}

inline Reference::Reference() :
    m_ptr(NULL),
    m_clearFunc(DefaultClear),
    m_isStopFunc(DefaultIsStop)
{}

inline Reference::Reference(void* ptr, ClearFuncType clear_func, 
    IsStopFuncType is_stop_func) :
        m_ptr(ptr),
        m_clearFunc(ptr != NULL && clear_func != NULL ? 
            clear_func : DefaultClear),
        m_isStopFunc(ptr != NULL && is_stop_func != NULL ? 
            is_stop_func : DefaultIsStop)
{}

inline Reference::~Reference()
{
    m_ptr = NULL;
}

inline Reference::Reference(const Reference& cpy) :
    m_ptr(cpy.m_ptr),
    m_clearFunc(cpy.m_clearFunc),
    m_isStopFunc(cpy.m_isStopFunc)
{}

inline Reference::Reference(Reference&& mov) :
    m_ptr(mov.m_ptr),
    m_clearFunc(mov.m_clearFunc),
    m_isStopFunc(mov.m_isStopFunc)
{
    mov.m_ptr = NULL;
    mov.m_clearFunc = DefaultClear;
    mov.m_isStopFunc = DefaultIsStop;
}

inline Reference& Reference::operator=(const Reference& cpy)
{
    m_ptr = cpy.m_ptr;
    m_clearFunc = cpy.m_clearFunc;
    m_isStopFunc = cpy.m_isStopFunc;

    return *this;
}

inline Reference& Reference::operator=(Reference&& mov)
{
    m_ptr = mov.m_ptr;
    m_clearFunc = mov.m_clearFunc;
    m_isStopFunc = mov.m_isStopFunc;

    mov.m_ptr = NULL;
    mov.m_clearFunc = DefaultClear;
    mov.m_isStopFunc = DefaultIsStop;
    return *this;
}

inline void Reference::Clear()
{
    m_clearFunc(m_ptr);
}

inline bool Reference::IsStop() const
{
    return m_isStopFunc(m_ptr);
}

} //!runner

} //!sys

} //!test

#endif //!TEST_SYS_RUNNER_REFERENCE_H_
