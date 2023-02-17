#ifndef TEST_OUT_PRINT_IMP_CHARACTER_H_
#define TEST_OUT_PRINT_IMP_CHARACTER_H_

#include "../../Definition.h"
#include "../Character.h"

#include <cstddef>
#include <cwchar>

namespace test
{
namespace out
{
namespace print
{
namespace imp
{

template<test::out::Definition::FlagType::IntegerValueType Fmt>
struct Character
{
    
};
template<>

struct Character<test::out::print::Character::char_fmt>
{
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;

    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print("%c", *((char*)value));
    }

    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print(L"%c", *((char*)value));
    }
};

template<>
struct Character<test::out::print::Character::w_char_fmt>
{
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;
        
    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print("%*c", width, *((char*)value));
    }

    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print(L"%*c", width, *((char*)value));
    }
};

template<>
struct Character<test::out::print::Character::wchar_fmt>
{
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;
        
    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print("%lc", *((wchar_t*)value));
    }

    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print(L"%lc", *((wchar_t*)value));
    }
};

template<>
struct Character<test::out::print::Character::w_wchar_fmt>
{
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;
        
    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print("%*lc", width, *((wchar_t*)value));
    }

    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print(L"%*lc", width, *((wchar_t*)value));
    }
};

} //!imp

} //!print

} //!out

} //!test

#endif //!TEST_OUT_PRINT_IMP_CHARACTER_H_
