#ifndef TEST_OUT_FMT_OUT_BLOCK_H_DEFN_
#define TEST_OUT_FMT_OUT_BLOCK_H_DEFN_

#include "../../../System.h"
#include "../Definition.h"

#include <utility>
#include <type_traits>
#include <cstdlib>

#ifndef TEST_OUT_FMT_OUT_BLOCK_DLEVEL

#define TEST_OUT_FMT_OUT_BLOCK_DLEVEL 2

#endif //!TEST_OUT_FMT_OUT_BLOCK_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_OUT_BLOCK_DLEVEL, 
    "test::out::fmt::out::Block", test::out::fmt::out::Block);

namespace test
{
namespace out
{
namespace fmt
{
namespace out
{

class Block
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::out::fmt::out::Block> DebugType;
public:
    typedef test::out::fmt::Definition DefinitionType;
    typedef typename DefinitionType::OutputIntegerType OutputIntegerType;
    template<typename TChar>
    using FormatOutputFuncType = DefinitionType::FormatOutputFuncType<TChar>;
private:
    OutputIntegerType m_type;
    void* m_pointer;
public:
    inline Block();
    template<typename TChar>
    inline Block(FormatOutputFuncType<TChar> func);
    inline ~Block();
public:
    inline Block(const Block& cpy);
    inline Block(Block&& mov);
public:
    inline Block& operator=(const Block& cpy);
    inline Block& operator=(Block&& mov);
public:
    inline OutputIntegerType GetType() const;
public:
    template<typename TChar, typename TChar_ = typename std::remove_cv<
            typename std::remove_reference<TChar>::type>::type,
        typename std::enable_if<std::is_void<TChar_>::value, int>::type = 0>
    inline void* GetFormatOutput() const;
    template<typename TChar, typename TChar_ = typename std::remove_cv<
            typename std::remove_reference<TChar>::type>::type,
        typename std::enable_if<!std::is_void<TChar_>::value, int>::type = 1>
    inline FormatOutputFuncType<TChar> GetFormatOutput() const;
};

} //!out

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_OUT_BLOCK_H_DEFN_
