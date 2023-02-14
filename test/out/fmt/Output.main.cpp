#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/fmt/Output.h"

#include <cassert>
#include <atomic>
#include <cstdint>

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
        test::out::fmt::Output<char> o1;

        assert(o1.Size() == 1);
        assert(o1.Get<char>() == nullptr);
        assert(o1.Get<wchar_t>() == nullptr);
        assert(o1.GetSize() == 0);
        assert(o1.Get(0).GetType() == 
            test::out::fmt::Definition::output_char);
        assert(o1.Get(0).GetFormatOutput<void>() == nullptr);
    }
    {
        test::out::fmt::Output<char> o1{
            test::out::fmt::flag::Output<char>{&Fun1<char>}
        };

        assert(o1.Size() == 1);
        assert(o1.Get<char>() == &Fun1<char>);
        assert(o1.Get<wchar_t>() == nullptr);
        assert(o1.GetSize() == 1);
        assert(o1.Get(0).GetType() == 
            test::out::fmt::Definition::output_char);
        assert(o1.Get(0).GetFormatOutput<void>() == &Fun1<char>);
    }
    {
        test::out::fmt::Output<char> o1{
            test::out::fmt::flag::Output<wchar_t>{&Fun1<wchar_t>}
        };

        assert(o1.Size() == 1);
        assert(o1.Get<char>() == nullptr);
        assert(o1.Get<wchar_t>() == nullptr);
        assert(o1.GetSize() == 0);
        assert(o1.Get(0).GetType() == 
            test::out::fmt::Definition::output_char);
        assert(o1.Get(0).GetFormatOutput<void>() == nullptr);
    }
    {
        test::out::fmt::Output<char> o1{
            test::out::fmt::flag::Output<char, wchar_t>{&Fun1<char>,
                &Fun1<wchar_t>}
        };

        assert(o1.Size() == 1);
        assert(o1.Get<char>() == &Fun1<char>);
        assert(o1.Get<wchar_t>() == nullptr);
        assert(o1.GetSize() == 1);
        assert(o1.Get(0).GetType() == 
            test::out::fmt::Definition::output_char);
        assert(o1.Get(0).GetFormatOutput<void>() == &Fun1<char>);
    }
    {
        test::out::fmt::Output<char> o1{
            test::out::fmt::flag::Output<wchar_t, char>{&Fun1<char>,
                &Fun1<wchar_t>}
        };

        assert(o1.Size() == 1);
        assert(o1.Get<char>() == &Fun1<char>);
        assert(o1.Get<wchar_t>() == nullptr);
        assert(o1.GetSize() == 1);
        assert(o1.Get(0).GetType() == 
            test::out::fmt::Definition::output_char);
        assert(o1.Get(0).GetFormatOutput<void>() == &Fun1<char>);
    }

    {
        test::out::fmt::Output<wchar_t> o1{
            test::out::fmt::flag::Output<char>{&Fun1<char>}
        };

        assert(o1.Size() == 1);
        assert(o1.Get<char>() == nullptr);
        assert(o1.Get<wchar_t>() == nullptr);
        assert(o1.GetSize() == 0);
        assert(o1.Get(0).GetType() == 
            test::out::fmt::Definition::output_wchar);
        assert(o1.Get(0).GetFormatOutput<void>() == nullptr);
    }
    {
        test::out::fmt::Output<wchar_t> o1{
            test::out::fmt::flag::Output<wchar_t>{&Fun1<wchar_t>}
        };

        assert(o1.Size() == 1);
        assert(o1.Get<char>() == nullptr);
        assert(o1.Get<wchar_t>() == &Fun1<wchar_t>);
        assert(o1.GetSize() == 1);
        assert(o1.Get(0).GetType() == 
            test::out::fmt::Definition::output_wchar);
        assert(o1.Get(0).GetFormatOutput<void>() == &Fun1<wchar_t>);
    }
    {
        test::out::fmt::Output<wchar_t> o1{
            test::out::fmt::flag::Output<char, wchar_t>{&Fun1<char>,
                &Fun1<wchar_t>}
        };

        assert(o1.Size() == 1);
        assert(o1.Get<char>() == nullptr);
        assert(o1.Get<wchar_t>() == &Fun1<wchar_t>);
        assert(o1.GetSize() == 1);
        assert(o1.Get(0).GetType() == 
            test::out::fmt::Definition::output_wchar);
        assert(o1.Get(0).GetFormatOutput<void>() == &Fun1<wchar_t>);
    }
    {
        test::out::fmt::Output<wchar_t> o1{
            test::out::fmt::flag::Output<wchar_t, char>{&Fun1<char>,
                &Fun1<wchar_t>}
        };

        assert(o1.Size() == 1);
        assert(o1.Get<char>() == nullptr);
        assert(o1.Get<wchar_t>() == &Fun1<wchar_t>);
        assert(o1.GetSize() == 1);
        assert(o1.Get(0).GetType() == 
            test::out::fmt::Definition::output_wchar);
        assert(o1.Get(0).GetFormatOutput<void>() == &Fun1<wchar_t>);
    }
    {
        test::out::fmt::Output<char, wchar_t> o1{};
        
        assert(o1.Size() == 2);
        assert(o1.Get<char>() == nullptr);
        assert(o1.Get<wchar_t>() == nullptr);
        assert(o1.GetSize() == 0);
        assert(o1.Get(0).GetType() == 
            test::out::fmt::Definition::output_char);
        assert(o1.Get(0).GetFormatOutput<void>() == nullptr);
        assert(o1.Get(1).GetType() == 
            test::out::fmt::Definition::output_wchar);
        assert(o1.Get(1).GetFormatOutput<void>() == nullptr);
    }
    {
        test::out::fmt::Output<char, wchar_t> o1{
            test::out::fmt::flag::Output<char>{&Fun1<char>}
        };

        assert(o1.Size() == 2);
        assert(o1.Get<char>() == &Fun1<char>);
        assert(o1.Get<wchar_t>() == nullptr);
        assert(o1.GetSize() == 1);
        assert(o1.Get(0).GetType() == 
            test::out::fmt::Definition::output_char);
        assert(o1.Get(0).GetFormatOutput<void>() == &Fun1<char>);
        assert(o1.Get(1).GetType() == 
            test::out::fmt::Definition::output_wchar);
        assert(o1.Get(1).GetFormatOutput<void>() == nullptr);
    }
    {
        test::out::fmt::Output<char, wchar_t> o1{
            test::out::fmt::flag::Output<wchar_t>{&Fun1<wchar_t>}
        };

        assert(o1.Size() == 2);
        assert(o1.Get<char>() == nullptr);
        assert(o1.Get<wchar_t>() == &Fun1<wchar_t>);
        assert(o1.GetSize() == 1);
        assert(o1.Get(0).GetType() == 
            test::out::fmt::Definition::output_char);
        assert(o1.Get(0).GetFormatOutput<void>() == nullptr);
        assert(o1.Get(1).GetType() == 
            test::out::fmt::Definition::output_wchar);
        assert(o1.Get(1).GetFormatOutput<void>() == &Fun1<wchar_t>);
    }
    {
        test::out::fmt::Output<char, wchar_t> o1{
            test::out::fmt::flag::Output<char, wchar_t>{&Fun1<char>,
                &Fun1<wchar_t>}
        };

        assert(o1.Size() == 2);
        assert(o1.Get<char>() == &Fun1<char>);
        assert(o1.Get<wchar_t>() == &Fun1<wchar_t>);
        assert(o1.GetSize() == 2);
        assert(o1.Get(0).GetType() == 
            test::out::fmt::Definition::output_char);
        assert(o1.Get(0).GetFormatOutput<void>() == &Fun1<char>);
        assert(o1.Get(1).GetType() == 
            test::out::fmt::Definition::output_wchar);
        assert(o1.Get(1).GetFormatOutput<void>() == &Fun1<wchar_t>);
    }
    {
        test::out::fmt::Output<char, wchar_t> o1{
            test::out::fmt::flag::Output<wchar_t, char>{&Fun1<char>,
                &Fun1<wchar_t>}
        };

        assert(o1.Size() == 2);
        assert(o1.Get<char>() == &Fun1<char>);
        assert(o1.Get<wchar_t>() == &Fun1<wchar_t>);
        assert(o1.GetSize() == 2);
        assert(o1.Get(0).GetType() == 
            test::out::fmt::Definition::output_char);
        assert(o1.Get(0).GetFormatOutput<void>() == &Fun1<char>);
        assert(o1.Get(1).GetType() == 
            test::out::fmt::Definition::output_wchar);
        assert(o1.Get(1).GetFormatOutput<void>() == &Fun1<wchar_t>);
    }

    {
        test::out::fmt::Output<wchar_t, char> o1{};
        
        assert(o1.Size() == 2);
        assert(o1.Get<char>() == nullptr);
        assert(o1.Get<wchar_t>() == nullptr);
        assert(o1.GetSize() == 0);
        assert(o1.Get(0).GetType() == 
            test::out::fmt::Definition::output_wchar);
        assert(o1.Get(0).GetFormatOutput<void>() == nullptr);
        assert(o1.Get(1).GetType() == 
            test::out::fmt::Definition::output_char);
        assert(o1.Get(1).GetFormatOutput<void>() == nullptr);
    }
    {
        test::out::fmt::Output<wchar_t, char> o1{
            test::out::fmt::flag::Output<char>{&Fun1<char>}
        };

        assert(o1.Size() == 2);
        assert(o1.Get<char>() == &Fun1<char>);
        assert(o1.Get<wchar_t>() == nullptr);
        assert(o1.GetSize() == 1);
        assert(o1.Get(0).GetType() == 
            test::out::fmt::Definition::output_wchar);
        assert(o1.Get(0).GetFormatOutput<void>() == nullptr);
        assert(o1.Get(1).GetType() == 
            test::out::fmt::Definition::output_char);
        assert(o1.Get(1).GetFormatOutput<void>() == &Fun1<char>);
    }
    {
        test::out::fmt::Output<wchar_t, char> o1{
            test::out::fmt::flag::Output<wchar_t>{&Fun1<wchar_t>}
        };

        assert(o1.Size() == 2);
        assert(o1.Get<char>() == nullptr);
        assert(o1.Get<wchar_t>() == &Fun1<wchar_t>);
        assert(o1.GetSize() == 1);
        assert(o1.Get(0).GetType() == 
            test::out::fmt::Definition::output_wchar);
        assert(o1.Get(0).GetFormatOutput<void>() == &Fun1<wchar_t>);
        assert(o1.Get(1).GetType() == 
            test::out::fmt::Definition::output_char);
        assert(o1.Get(1).GetFormatOutput<void>() == nullptr);
    }
    {
        test::out::fmt::Output<wchar_t, char> o1{
            test::out::fmt::flag::Output<char, wchar_t>{&Fun1<char>,
                &Fun1<wchar_t>}
        };

        assert(o1.Size() == 2);
        assert(o1.Get<char>() == &Fun1<char>);
        assert(o1.Get<wchar_t>() == &Fun1<wchar_t>);
        assert(o1.GetSize() == 2);
        assert(o1.Get(0).GetType() == 
            test::out::fmt::Definition::output_wchar);
        assert(o1.Get(0).GetFormatOutput<void>() == &Fun1<wchar_t>);
        assert(o1.Get(1).GetType() == 
            test::out::fmt::Definition::output_char);
        assert(o1.Get(1).GetFormatOutput<void>() == &Fun1<char>);
    }
    {
        test::out::fmt::Output<wchar_t, char> o1{
            test::out::fmt::flag::Output<wchar_t, char>{&Fun1<char>,
                &Fun1<wchar_t>}
        };

        assert(o1.Size() == 2);
        assert(o1.Get<char>() == &Fun1<char>);
        assert(o1.Get<wchar_t>() == &Fun1<wchar_t>);
        assert(o1.GetSize() == 2);
        assert(o1.Get(0).GetType() == 
            test::out::fmt::Definition::output_wchar);
        assert(o1.Get(0).GetFormatOutput<void>() == &Fun1<wchar_t>);
        assert(o1.Get(1).GetType() == 
            test::out::fmt::Definition::output_char);
        assert(o1.Get(1).GetFormatOutput<void>() == &Fun1<char>);
    }

    return 0;
}
