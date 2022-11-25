#ifndef TEST_SYS_MEM_BLOCK_H_
#define TEST_SYS_MEM_BLOCK_H_

#include "block/Base.h"
#include "block/FileLine.h"
#include "../Definition.h"
#include "../Log.h"

#include <cstdlib>

namespace test
{
namespace sys
{
namespace mem
{

template<typename... TDerives>
class Block
{
};

template<typename TSysStatus>
class Block<test::sys::mem::block::Base<TSysStatus>,
    test::sys::mem::block::FileLine> : 
        public test::sys::mem::block::Base<TSysStatus>,
        public test::sys::mem::block::FileLine
{
private:
    typedef test::sys::Log<TSysStatus> LogType;
public:
    typedef typename test::sys::Definition::TimestampType TimestampType;
public:
    Block(LogType& log);
    template<std::size_t N>
    Block(LogType& log, void * pointer, const std::size_t& size,
        const std::size_t& id, const char (&f)[N], const int& l);
public:
    Block(const Block<test::sys::mem::block::Base<TSysStatus>,
        test::sys::mem::block::FileLine>& cpy) = delete;
    Block(Block<test::sys::mem::block::Base<TSysStatus>,
        test::sys::mem::block::FileLine>&& mov);
public:
    ~Block();
public:
    Block<test::sys::mem::block::Base<TSysStatus>,
        test::sys::mem::block::FileLine>& 
    operator=(const Block<test::sys::mem::block::Base<TSysStatus>,
        test::sys::mem::block::FileLine>& cpy) = delete;
    Block<test::sys::mem::block::Base<TSysStatus>,
        test::sys::mem::block::FileLine>& 
    operator=(Block<test::sys::mem::block::Base<TSysStatus>,
        test::sys::mem::block::FileLine>&& mov);
public:
    using test::sys::mem::block::Base<TSysStatus>::Allocate;
    using test::sys::mem::block::Base<TSysStatus>::Reallocate;
    using test::sys::mem::block::Base<TSysStatus>::Deallocate;
    using test::sys::mem::block::Base<TSysStatus>::Release;
public:
    using test::sys::mem::block::Base<TSysStatus>::SetDeallocator;
public:
    using test::sys::mem::block::Base<TSysStatus>::Pointer;
    using test::sys::mem::block::Base<TSysStatus>::Size;
    using test::sys::mem::block::Base<TSysStatus>::AllocationTimestamp;
    using test::sys::mem::block::Base<TSysStatus>::DeallocationTimestamp;
    using test::sys::mem::block::Base<TSysStatus>::ReferenceCount;
    using test::sys::mem::block::Base<TSysStatus>::AddReference;
    using test::sys::mem::block::Base<TSysStatus>::ReleaseReference;
    using test::sys::mem::block::Base<TSysStatus>::operator bool;
    using test::sys::mem::block::Base<TSysStatus>::operator==;
    using test::sys::mem::block::Base<TSysStatus>::operator!=;
    using test::sys::mem::block::FileLine::File;
    using test::sys::mem::block::FileLine::Line;
};

template<typename TSysStatus>
class Block<test::sys::mem::block::Base<TSysStatus>> : 
    public test::sys::mem::block::Base<TSysStatus>
{
private:
    typedef test::sys::Log<TSysStatus> LogType;
public:
    typedef typename test::sys::Definition::TimestampType TimestampType;
public:
    Block(LogType& log);
    Block(LogType& log, void * pointer, const std::size_t& size,
        const std::size_t& id);
    template<std::size_t N>
    Block(LogType& log, void * pointer, const std::size_t& size,
        const std::size_t& id, const char (&)[N], const int& );
public:
    Block(const Block<test::sys::mem::block::Base<TSysStatus>>& cpy) = delete;
    Block(Block<test::sys::mem::block::Base<TSysStatus>>&& mov);
public:
    ~Block();
public:
    Block<test::sys::mem::block::Base<TSysStatus>>& 
    operator=(const Block<test::sys::mem::block::Base<TSysStatus>>& cpy) = delete;
    Block<test::sys::mem::block::Base<TSysStatus>>& 
    operator=(Block<test::sys::mem::block::Base<TSysStatus>>&& mov);
public:
    using test::sys::mem::block::Base<TSysStatus>::Allocate;
    using test::sys::mem::block::Base<TSysStatus>::Reallocate;
    using test::sys::mem::block::Base<TSysStatus>::Deallocate;
    using test::sys::mem::block::Base<TSysStatus>::Release;
public:
    using test::sys::mem::block::Base<TSysStatus>::SetDeallocator;
public:
    using test::sys::mem::block::Base<TSysStatus>::Pointer;
    using test::sys::mem::block::Base<TSysStatus>::Size;
    using test::sys::mem::block::Base<TSysStatus>::AllocationTimestamp;
    using test::sys::mem::block::Base<TSysStatus>::DeallocationTimestamp;
    using test::sys::mem::block::Base<TSysStatus>::ReferenceCount;
    using test::sys::mem::block::Base<TSysStatus>::AddReference;
    using test::sys::mem::block::Base<TSysStatus>::ReleaseReference;
    using test::sys::mem::block::Base<TSysStatus>::operator bool;
    using test::sys::mem::block::Base<TSysStatus>::operator==;
    using test::sys::mem::block::Base<TSysStatus>::operator!=;
public:
    inline const char* File() const;
    inline int Line() const;
};

template<typename TSysStatus>
Block<test::sys::mem::block::Base<TSysStatus>,
    test::sys::mem::block::FileLine>::Block(LogType& log) :
        test::sys::mem::block::Base<TSysStatus>(log),
        test::sys::mem::block::FileLine()
{}

template<typename TSysStatus>
template<std::size_t N>
Block<test::sys::mem::block::Base<TSysStatus>,
    test::sys::mem::block::FileLine>::Block(LogType& log, void * pointer, 
    const std::size_t& size, const std::size_t& id, const char (&f)[N], 
    const int& l) :
        test::sys::mem::block::Base<TSysStatus>(log, id),
        test::sys::mem::block::FileLine(f, l)
{
    test::sys::mem::block::Base<TSysStatus>::Allocate(pointer, size);
}
    
template<typename TSysStatus>
Block<test::sys::mem::block::Base<TSysStatus>,
    test::sys::mem::block::FileLine>::Block(
        Block<test::sys::mem::block::Base<TSysStatus>,
        test::sys::mem::block::FileLine>&& mov) :
            test::sys::mem::block::Base<TSysStatus>(std::move(mov)),
            test::sys::mem::block::FileLine(std::move(mov))
{}

template<typename TSysStatus>
Block<test::sys::mem::block::Base<TSysStatus>,
    test::sys::mem::block::FileLine>::~Block()
{}

template<typename TSysStatus>
Block<test::sys::mem::block::Base<TSysStatus>,
    test::sys::mem::block::FileLine>& 
Block<test::sys::mem::block::Base<TSysStatus>,
    test::sys::mem::block::FileLine>::
        operator=(Block<test::sys::mem::block::Base<TSysStatus>,
            test::sys::mem::block::FileLine>&& mov)
{
    test::sys::mem::block::Base<TSysStatus>::operator=(std::move(mov));
    test::sys::mem::block::FileLine::operator=(std::move(mov));
    return *this;
}

template<typename TSysStatus>
Block<test::sys::mem::block::Base<TSysStatus>>::Block(LogType& log) :
    test::sys::mem::block::Base<TSysStatus>(log)
{}

template<typename TSysStatus>
Block<test::sys::mem::block::Base<TSysStatus>>::Block(LogType& log, 
    void * pointer, const std::size_t& size, const std::size_t& id) :
        test::sys::mem::block::Base<TSysStatus>(log, id)
{
    test::sys::mem::block::Base<TSysStatus>::Allocate(pointer, size);
}

template<typename TSysStatus>
template<std::size_t N>
Block<test::sys::mem::block::Base<TSysStatus>>::Block(LogType& log,
    void * pointer, const std::size_t& size, const std::size_t& id, 
    const char (&)[N], const int&) :
        test::sys::mem::block::Base<TSysStatus>(log, pointer, size, id)
{}

template<typename TSysStatus>
Block<test::sys::mem::block::Base<TSysStatus>>::
    Block(Block<test::sys::mem::block::Base<TSysStatus>>&& mov) :
        test::sys::mem::block::Base<TSysStatus>(std::move(mov))
{}

template<typename TSysStatus>
Block<test::sys::mem::block::Base<TSysStatus>>::~Block()
{}

template<typename TSysStatus>
Block<test::sys::mem::block::Base<TSysStatus>>& 
Block<test::sys::mem::block::Base<TSysStatus>>::
    operator=(Block<test::sys::mem::block::Base<TSysStatus>>&& mov)
{
    test::sys::mem::block::Base<TSysStatus>::operator=(std::move(mov));
    return *this;
}

template<typename TSysStatus>
const char* Block<test::sys::mem::block::Base<TSysStatus>>::File() const
{
    static const char * tmp = TEST_MEM_BLOCK_FILE_DEFAULT_STR;
    return tmp;
}

template<typename TSysStatus>
int Block<test::sys::mem::block::Base<TSysStatus>>::Line() const
{
    return -1;
}

} //!mem

} //!sys

} //!test

#endif //!TEST_SYS_MEM_BLOCK_H_
