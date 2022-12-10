#ifndef TEST_SYS_MEM_BLOCK_H_
#define TEST_SYS_MEM_BLOCK_H_

#include "block/Base.h"
#include "block/FileLine.h"
#include "../Definition.h"
#include "../Interface.h"
#include "../Debug.h"

#include <cstdlib>

namespace test::sys::mem
{
template<typename... TDerives>
class Block;
}

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TDerives>...

template<typename... TDerives>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("test::sys::mem::Block", 
    test::sys::mem::Block<TDerives...>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

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

template<>
class Block<test::sys::mem::block::Base,
    test::sys::mem::block::FileLine> : 
        public test::sys::mem::block::Base,
        public test::sys::mem::block::FileLine
{
private:
    typedef test::sys::Definition DefinitionType;
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::mem::Block<
        test::sys::mem::block::Base,
        test::sys::mem::block::FileLine>> DebugType;
public:
    typedef typename test::sys::Definition::TimestampType TimestampType;
public:
    Block();
    template<std::size_t N>
    Block(void * pointer, const std::size_t& size,
        const std::size_t& id, const char (&f)[N], const int& l);
public:
    Block(const Block<test::sys::mem::block::Base,
        test::sys::mem::block::FileLine>& cpy) = delete;
    Block(Block<test::sys::mem::block::Base,
        test::sys::mem::block::FileLine>&& mov);
public:
    ~Block();
public:
    Block<test::sys::mem::block::Base,
        test::sys::mem::block::FileLine>& 
    operator=(const Block<test::sys::mem::block::Base,
        test::sys::mem::block::FileLine>& cpy) = delete;
    Block<test::sys::mem::block::Base,
        test::sys::mem::block::FileLine>& 
    operator=(Block<test::sys::mem::block::Base,
        test::sys::mem::block::FileLine>&& mov);
public:
    using test::sys::mem::block::Base::Allocate;
    using test::sys::mem::block::Base::Reallocate;
    using test::sys::mem::block::Base::Deallocate;
    using test::sys::mem::block::Base::Release;
public:
    using test::sys::mem::block::Base::SetDeallocator;
public:
    using test::sys::mem::block::Base::Pointer;
    using test::sys::mem::block::Base::Size;
    using test::sys::mem::block::Base::AllocationTimestamp;
    using test::sys::mem::block::Base::DeallocationTimestamp;
    using test::sys::mem::block::Base::ReferenceCount;
    using test::sys::mem::block::Base::AddReference;
    using test::sys::mem::block::Base::ReleaseReference;
    using test::sys::mem::block::Base::operator bool;
    using test::sys::mem::block::Base::operator==;
    using test::sys::mem::block::Base::operator!=;
    using test::sys::mem::block::FileLine::File;
    using test::sys::mem::block::FileLine::Line;
    using test::sys::mem::block::FileLine::FileAllocationSize;
};

template<>
class Block<test::sys::mem::block::Base> : 
    public test::sys::mem::block::Base
{
private:
    typedef test::sys::Definition DefinitionType;
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::mem::Block<
        test::sys::mem::block::Base>> DebugType;
public:
    typedef typename test::sys::Definition::TimestampType TimestampType;
public:
    typedef typename DefinitionType::Status SysStatusEnumType;
    typedef typename DefinitionType::StatusIntegerType SysStatusIntegerType;
public:
    Block();
    Block(void * pointer, const std::size_t& size,
        const std::size_t& id);
    template<std::size_t N>
    Block(void * pointer, const std::size_t& size,
        const std::size_t& id, const char (&)[N], const int& );
public:
    Block(const Block<test::sys::mem::block::Base>& cpy) = delete;
    Block(Block<test::sys::mem::block::Base>&& mov);
public:
    ~Block();
public:
    Block<test::sys::mem::block::Base>& 
    operator=(const Block<test::sys::mem::block::Base>& cpy) = delete;
    Block<test::sys::mem::block::Base>& 
    operator=(Block<test::sys::mem::block::Base>&& mov);
public:
    using test::sys::mem::block::Base::Allocate;
    using test::sys::mem::block::Base::Reallocate;
    using test::sys::mem::block::Base::Deallocate;
    using test::sys::mem::block::Base::Release;
public:
    using test::sys::mem::block::Base::SetDeallocator;
public:
    using test::sys::mem::block::Base::Pointer;
    using test::sys::mem::block::Base::Size;
    using test::sys::mem::block::Base::AllocationTimestamp;
    using test::sys::mem::block::Base::DeallocationTimestamp;
    using test::sys::mem::block::Base::ReferenceCount;
    using test::sys::mem::block::Base::AddReference;
    using test::sys::mem::block::Base::ReleaseReference;
    using test::sys::mem::block::Base::operator bool;
    using test::sys::mem::block::Base::operator==;
    using test::sys::mem::block::Base::operator!=;
public:
    inline const char* File() const;
    inline int Line() const;
    inline std::size_t FileAllocationSize() const;
};

Block<test::sys::mem::block::Base,
    test::sys::mem::block::FileLine>::Block() :
        test::sys::mem::block::Base(),
        test::sys::mem::block::FileLine()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

template<std::size_t N>
Block<test::sys::mem::block::Base,
    test::sys::mem::block::FileLine>::Block(void * pointer, 
    const std::size_t& size, const std::size_t& id, const char (&f)[N], 
    const int& l) :
        test::sys::mem::block::Base(id),
        test::sys::mem::block::FileLine(f, l)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(pointer=%p, size=%zu, id=%zu, f=%s, l=%d)",
        pointer, size, id, f, l);

    test::sys::mem::block::Base::Allocate(pointer, size);
}

Block<test::sys::mem::block::Base,
    test::sys::mem::block::FileLine>::Block(
        Block<test::sys::mem::block::Base,
        test::sys::mem::block::FileLine>&& mov) :
            test::sys::mem::block::Base(std::move(mov)),
            test::sys::mem::block::FileLine(std::move(mov))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%d)", &mov);

}

Block<test::sys::mem::block::Base,
    test::sys::mem::block::FileLine>::~Block()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

}

Block<test::sys::mem::block::Base,
    test::sys::mem::block::FileLine>& 
Block<test::sys::mem::block::Base,
    test::sys::mem::block::FileLine>::
        operator=(Block<test::sys::mem::block::Base,
            test::sys::mem::block::FileLine>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%d)", &mov);

    test::sys::mem::block::Base::operator=(std::move(mov));
    test::sys::mem::block::FileLine::operator=(std::move(mov));
    return *this;
}

Block<test::sys::mem::block::Base>::Block() :
    test::sys::mem::block::Base()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

Block<test::sys::mem::block::Base>::Block(void * pointer, 
    const std::size_t& size, const std::size_t& id) :
        test::sys::mem::block::Base(id)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(pointer=%p, size=%zu, id=%zu)",
        pointer, size, id);

    test::sys::mem::block::Base::Allocate(pointer, size);
}

template<std::size_t N>
Block<test::sys::mem::block::Base>::Block(void * pointer, 
    const std::size_t& size, const std::size_t& id, 
    const char (&)[N], const int&) :
        test::sys::mem::block::Base(id)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(pointer=%p, size=%zu, id=%zu, "
        "const char(&)[%zu], const int&)",pointer, size, id, N);
    
    test::sys::mem::block::Base::Allocate(pointer, size);
}

Block<test::sys::mem::block::Base>::
    Block(Block<test::sys::mem::block::Base>&& mov) :
        test::sys::mem::block::Base(std::move(mov))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%d)", &mov);

}

Block<test::sys::mem::block::Base>::~Block()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

}

Block<test::sys::mem::block::Base>& 
Block<test::sys::mem::block::Base>::
    operator=(Block<test::sys::mem::block::Base>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%d)", &mov);

    test::sys::mem::block::Base::operator=(std::move(mov));
    return *this;
}

const char* Block<test::sys::mem::block::Base>::File() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "File() const");

    static const char * tmp = TEST_MEM_BLOCK_FILE_DEFAULT_STR;
    return tmp;
}

int Block<test::sys::mem::block::Base>::Line() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Line() const");

    return -1;
}

std::size_t Block<test::sys::mem::block::Base>::FileAllocationSize() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "FileAllocationSize() const");

    return 0;
}

} //!mem

} //!sys

} //!test

#endif //!TEST_SYS_MEM_BLOCK_H_
