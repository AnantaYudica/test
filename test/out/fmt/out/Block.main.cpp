#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#define TEST_OUT_FMT_OUT_BLOCK_DLEVEL 0x7f

#include "test/out/fmt/out/Block.h"

#include <cwchar>
#include <utility>
#include <cassert>

template<typename TChar>
std::size_t Fun1(test::out::Interface<TChar>& out, 
    void* value, std::size_t value_size, 
    typename test::out::fmt::Definition::FlagType flag, 
    int width, int len_pred)
{
    return 0;
}

int main()
{
    {
        test::out::fmt::out::Block b1;

        assert(b1.GetType() == 
            test::out::fmt::Definition::output_undefined);
        assert(b1.GetFormatOutput<char>() == nullptr);
        assert(b1.GetFormatOutput<wchar_t>() == nullptr);

        test::out::fmt::out::Block b2(b1);
        
        assert(b2.GetType() == 
            test::out::fmt::Definition::output_undefined);
        assert(b2.GetFormatOutput<char>() == nullptr);
        assert(b2.GetFormatOutput<wchar_t>() == nullptr);

        test::out::fmt::out::Block b3(std::move(b2));
        
        assert(b3.GetType() == 
            test::out::fmt::Definition::output_undefined);
        assert(b3.GetFormatOutput<char>() == nullptr);
        assert(b3.GetFormatOutput<wchar_t>() == nullptr);
        
        assert(b2.GetType() == 
            test::out::fmt::Definition::output_undefined);
        assert(b2.GetFormatOutput<char>() == nullptr);
        assert(b2.GetFormatOutput<wchar_t>() == nullptr);

        test::out::fmt::out::Block b4;
        b4 = b1;
        
        assert(b4.GetType() == 
            test::out::fmt::Definition::output_undefined);
        assert(b4.GetFormatOutput<char>() == nullptr);
        assert(b4.GetFormatOutput<wchar_t>() == nullptr);
        
        test::out::fmt::out::Block b5;
        b5 = std::move(b4);
        
        assert(b5.GetType() == 
            test::out::fmt::Definition::output_undefined);
        assert(b5.GetFormatOutput<char>() == nullptr);
        assert(b5.GetFormatOutput<wchar_t>() == nullptr);
        
        assert(b5.GetType() == 
            test::out::fmt::Definition::output_undefined);
        assert(b5.GetFormatOutput<char>() == nullptr);
        assert(b5.GetFormatOutput<wchar_t>() == nullptr);
    }
    {
        test::out::fmt::out::Block b1{&Fun1<char>};
        
        assert(b1.GetType() == 
            test::out::fmt::Definition::output_char);
        assert(b1.GetFormatOutput<char>() == &Fun1<char>);
        assert(b1.GetFormatOutput<wchar_t>() == nullptr);
        
        test::out::fmt::out::Block b2(b1);
        
        assert(b2.GetType() == 
            test::out::fmt::Definition::output_char);
        assert(b2.GetFormatOutput<char>() == &Fun1<char>);
        assert(b2.GetFormatOutput<wchar_t>() == nullptr);
        
        test::out::fmt::out::Block b3(std::move(b2));
        
        assert(b3.GetType() == 
            test::out::fmt::Definition::output_char);
        assert(b3.GetFormatOutput<char>() == &Fun1<char>);
        assert(b3.GetFormatOutput<wchar_t>() == nullptr);
        
        assert(b2.GetType() == 
            test::out::fmt::Definition::output_undefined);
        assert(b2.GetFormatOutput<char>() == nullptr);
        assert(b2.GetFormatOutput<wchar_t>() == nullptr);

        test::out::fmt::out::Block b4;
        b4 = b1;
        
        assert(b4.GetType() == 
            test::out::fmt::Definition::output_char);
        assert(b4.GetFormatOutput<char>() == &Fun1<char>);
        assert(b4.GetFormatOutput<wchar_t>() == nullptr);
        
        test::out::fmt::out::Block b5;
        b5 = std::move(b4);
        
        assert(b5.GetType() == 
            test::out::fmt::Definition::output_char);
        assert(b5.GetFormatOutput<char>() == &Fun1<char>);
        assert(b5.GetFormatOutput<wchar_t>() == nullptr);
        
        assert(b4.GetType() == 
            test::out::fmt::Definition::output_undefined);
        assert(b4.GetFormatOutput<char>() == nullptr);
        assert(b4.GetFormatOutput<wchar_t>() == nullptr);
    }
    {
        test::out::fmt::out::Block b1{&Fun1<wchar_t>};
        
        assert(b1.GetType() == 
            test::out::fmt::Definition::output_wchar);
        assert(b1.GetFormatOutput<char>() == nullptr);
        assert(b1.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        
        test::out::fmt::out::Block b2(b1);

        assert(b2.GetType() == 
            test::out::fmt::Definition::output_wchar);
        assert(b2.GetFormatOutput<char>() == nullptr);
        assert(b2.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        
        test::out::fmt::out::Block b3(std::move(b2));

        assert(b3.GetType() == 
            test::out::fmt::Definition::output_wchar);
        assert(b3.GetFormatOutput<char>() == nullptr);
        assert(b3.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        
        assert(b2.GetType() == 
            test::out::fmt::Definition::output_undefined);
        assert(b2.GetFormatOutput<char>() == nullptr);
        assert(b2.GetFormatOutput<wchar_t>() == nullptr);

        test::out::fmt::out::Block b4;
        b4 = b3;
        
        assert(b4.GetType() == 
            test::out::fmt::Definition::output_wchar);
        assert(b4.GetFormatOutput<char>() == nullptr);
        assert(b4.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        
        test::out::fmt::out::Block b5;
        b5 = std::move(b4);
        
        assert(b5.GetType() == 
            test::out::fmt::Definition::output_wchar);
        assert(b5.GetFormatOutput<char>() == nullptr);
        assert(b5.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        
        assert(b4.GetType() == 
            test::out::fmt::Definition::output_undefined);
        assert(b4.GetFormatOutput<char>() == nullptr);
        assert(b4.GetFormatOutput<wchar_t>() == nullptr);
    }
    return 0;
}
