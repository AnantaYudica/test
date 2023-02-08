#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#define TEST_OUT_FMT_OUT_VALUE_DLEVEL 0x7f
#define TEST_POINTER_DLEVEL 0x7f
#define TEST_PTR_BASE_DLEVEL 0x7f

#include "test/out/fmt/out/Value.h"

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
        test::out::fmt::out::Value v1;

        assert(v1.Size() == 0);
        assert(v1.GetFormatOutput<char>() == nullptr);
        assert(v1.GetFormatOutput('a') == nullptr);
        assert(v1.GetFormatOutput<wchar_t>() == nullptr);
        assert(v1.GetFormatOutput(L'a') == nullptr);

        test::out::fmt::out::Value v2(v1);
        
        assert(v2.Size() == 0);
        assert(v2.GetFormatOutput<char>() == nullptr);
        assert(v2.GetFormatOutput('a') == nullptr);
        assert(v2.GetFormatOutput<wchar_t>() == nullptr);
        assert(v2.GetFormatOutput(L'a') == nullptr);

        test::out::fmt::out::Value v3(std::move(v1));
        
        assert(v3.Size() == 0);
        assert(v3.GetFormatOutput<char>() == nullptr);
        assert(v3.GetFormatOutput('a') == nullptr);
        assert(v3.GetFormatOutput<wchar_t>() == nullptr);
        assert(v3.GetFormatOutput(L'a') == nullptr);

        assert(v2.Size() == 0);
        assert(v2.GetFormatOutput<char>() == nullptr);
        assert(v2.GetFormatOutput('a') == nullptr);
        assert(v2.GetFormatOutput<wchar_t>() == nullptr);
        assert(v2.GetFormatOutput(L'a') == nullptr);

        test::out::fmt::out::Value v4;
        v4 = v3;

        assert(v4.Size() == 0);
        assert(v4.GetFormatOutput<char>() == nullptr);
        assert(v4.GetFormatOutput('a') == nullptr);
        assert(v4.GetFormatOutput<wchar_t>() == nullptr);
        assert(v4.GetFormatOutput(L'a') == nullptr);

        test::out::fmt::out::Value v5;
        v5 = std::move(v3);

        assert(v5.Size() == 0);
        assert(v5.GetFormatOutput<char>() == nullptr);
        assert(v5.GetFormatOutput('a') == nullptr);
        assert(v5.GetFormatOutput<wchar_t>() == nullptr);
        assert(v5.GetFormatOutput(L'a') == nullptr);

        assert(v4.Size() == 0);
        assert(v4.GetFormatOutput<char>() == nullptr);
        assert(v4.GetFormatOutput('a') == nullptr);
        assert(v4.GetFormatOutput<wchar_t>() == nullptr);
        assert(v4.GetFormatOutput(L'a') == nullptr);

    }
    {
        test::out::fmt::out::Value v1{
            test::out::fmt::out::Block{&Fun1<char>}
        };

        assert(v1.Size() == 1);
        assert(v1.GetFormatOutput<char>() == &Fun1<char>);
        assert(v1.GetFormatOutput('a') == &Fun1<char>);
        assert(v1.GetFormatOutput<wchar_t>() == nullptr);
        assert(v1.GetFormatOutput(L'a') == nullptr);

        test::out::fmt::out::Value v2{v1};

        assert(v2.Size() == 1);
        assert(v2.GetFormatOutput<char>() == &Fun1<char>);
        assert(v2.GetFormatOutput('a') == &Fun1<char>);
        assert(v2.GetFormatOutput<wchar_t>() == nullptr);
        assert(v2.GetFormatOutput(L'a') == nullptr);
        
        test::out::fmt::out::Value v3{std::move(v2)};

        assert(v3.Size() == 1);
        assert(v3.GetFormatOutput<char>() == &Fun1<char>);
        assert(v3.GetFormatOutput('a') == &Fun1<char>);
        assert(v3.GetFormatOutput<wchar_t>() == nullptr);
        assert(v3.GetFormatOutput(L'a') == nullptr);

        assert(v2.Size() == 0);
        assert(v2.GetFormatOutput<char>() == nullptr);
        assert(v2.GetFormatOutput('a') == nullptr);
        assert(v2.GetFormatOutput<wchar_t>() == nullptr);
        assert(v2.GetFormatOutput(L'a') == nullptr);

        test::out::fmt::out::Value v4;
        v4 = v3;
        
        assert(v4.Size() == 1);
        assert(v4.GetFormatOutput<char>() == &Fun1<char>);
        assert(v4.GetFormatOutput('a') == &Fun1<char>);
        assert(v4.GetFormatOutput<wchar_t>() == nullptr);
        assert(v4.GetFormatOutput(L'a') == nullptr);

        test::out::fmt::out::Value v5;
        v5 = std::move(v4);
        
        assert(v5.Size() == 1);
        assert(v5.GetFormatOutput<char>() == &Fun1<char>);
        assert(v5.GetFormatOutput('a') == &Fun1<char>);
        assert(v5.GetFormatOutput<wchar_t>() == nullptr);
        assert(v5.GetFormatOutput(L'a') == nullptr);

        assert(v4.Size() == 0);
        assert(v4.GetFormatOutput<char>() == nullptr);
        assert(v4.GetFormatOutput('a') == nullptr);
        assert(v4.GetFormatOutput<wchar_t>() == nullptr);
        assert(v4.GetFormatOutput(L'a') == nullptr);
    }
    {
        test::out::fmt::out::Value v1{
            test::out::fmt::out::Block{&Fun1<wchar_t>}
        };

        assert(v1.Size() == 1);
        assert(v1.GetFormatOutput<char>() == nullptr);
        assert(v1.GetFormatOutput('a') == nullptr);
        assert(v1.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        assert(v1.GetFormatOutput(L'a') == &Fun1<wchar_t>);
        
        test::out::fmt::out::Value v2{v1};
        
        assert(v2.Size() == 1);
        assert(v2.GetFormatOutput<char>() == nullptr);
        assert(v2.GetFormatOutput('a') == nullptr);
        assert(v2.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        assert(v2.GetFormatOutput(L'a') == &Fun1<wchar_t>);
        
        test::out::fmt::out::Value v3{std::move(v2)};

        assert(v3.Size() == 1);
        assert(v3.GetFormatOutput<char>() == nullptr);
        assert(v3.GetFormatOutput('a') == nullptr);
        assert(v3.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        assert(v3.GetFormatOutput(L'a') == &Fun1<wchar_t>);
        
        assert(v2.Size() == 0);
        assert(v2.GetFormatOutput<char>() == nullptr);
        assert(v2.GetFormatOutput('a') == nullptr);
        assert(v2.GetFormatOutput<wchar_t>() == nullptr);
        assert(v2.GetFormatOutput(L'a') == nullptr);
        
        test::out::fmt::out::Value v4;
        v4 = v3;

        assert(v4.Size() == 1);
        assert(v4.GetFormatOutput<char>() == nullptr);
        assert(v4.GetFormatOutput('a') == nullptr);
        assert(v4.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        assert(v4.GetFormatOutput(L'a') == &Fun1<wchar_t>);
        
        test::out::fmt::out::Value v5;
        v5 = std::move(v4);
        
        assert(v5.Size() == 1);
        assert(v5.GetFormatOutput<char>() == nullptr);
        assert(v5.GetFormatOutput('a') == nullptr);
        assert(v5.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        assert(v5.GetFormatOutput(L'a') == &Fun1<wchar_t>);
        
        assert(v4.Size() == 0);
        assert(v4.GetFormatOutput<char>() == nullptr);
        assert(v4.GetFormatOutput('a') == nullptr);
        assert(v4.GetFormatOutput<wchar_t>() == nullptr);
        assert(v4.GetFormatOutput(L'a') == nullptr);
    }
    {
        test::out::fmt::out::Value v1{
            test::out::fmt::out::Block{&Fun1<char>},
            test::out::fmt::out::Block{&Fun1<wchar_t>}
        };
        
        assert(v1.Size() == 2);
        assert(v1.GetFormatOutput<char>() == &Fun1<char>);
        assert(v1.GetFormatOutput('a') == &Fun1<char>);
        assert(v1.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        assert(v1.GetFormatOutput(L'a') == &Fun1<wchar_t>);

        test::out::fmt::out::Value v2{v1};

        assert(v2.Size() == 2);
        assert(v2.GetFormatOutput<char>() == &Fun1<char>);
        assert(v2.GetFormatOutput('a') == &Fun1<char>);
        assert(v2.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        assert(v2.GetFormatOutput(L'a') == &Fun1<wchar_t>);
        
        test::out::fmt::out::Value v3{std::move(v2)};
        
        assert(v3.Size() == 2);
        assert(v3.GetFormatOutput<char>() == &Fun1<char>);
        assert(v3.GetFormatOutput('a') == &Fun1<char>);
        assert(v3.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        assert(v3.GetFormatOutput(L'a') == &Fun1<wchar_t>);
        
        assert(v2.Size() == 0);
        assert(v2.GetFormatOutput<char>() == nullptr);
        assert(v2.GetFormatOutput('a') == nullptr);
        assert(v2.GetFormatOutput<wchar_t>() == nullptr);
        assert(v2.GetFormatOutput(L'a') == nullptr);

        test::out::fmt::out::Value v4;
        v4 = v3;

        assert(v4.Size() == 2);
        assert(v4.GetFormatOutput<char>() == &Fun1<char>);
        assert(v4.GetFormatOutput('a') == &Fun1<char>);
        assert(v4.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        assert(v4.GetFormatOutput(L'a') == &Fun1<wchar_t>);

        test::out::fmt::out::Value v5;
        v5 = std::move(v4);
        
        assert(v5.Size() == 2);
        assert(v5.GetFormatOutput<char>() == &Fun1<char>);
        assert(v5.GetFormatOutput('a') == &Fun1<char>);
        assert(v5.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        assert(v5.GetFormatOutput(L'a') == &Fun1<wchar_t>);

        assert(v4.Size() == 0);
        assert(v4.GetFormatOutput<char>() == nullptr);
        assert(v4.GetFormatOutput('a') == nullptr);
        assert(v4.GetFormatOutput<wchar_t>() == nullptr);
        assert(v4.GetFormatOutput(L'a') == nullptr);
        
    }
    {
        
        test::out::fmt::out::Value v1{
            test::out::fmt::out::Block{&Fun1<wchar_t>},
            test::out::fmt::out::Block{&Fun1<char>}
        };
        
        assert(v1.Size() == 2);
        assert(v1.GetFormatOutput<char>() == &Fun1<char>);
        assert(v1.GetFormatOutput('a') == &Fun1<char>);
        assert(v1.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        assert(v1.GetFormatOutput(L'a') == &Fun1<wchar_t>);
        
        test::out::fmt::out::Value v2{v1};

        assert(v2.Size() == 2);
        assert(v2.GetFormatOutput<char>() == &Fun1<char>);
        assert(v2.GetFormatOutput('a') == &Fun1<char>);
        assert(v2.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        assert(v2.GetFormatOutput(L'a') == &Fun1<wchar_t>);
        
        test::out::fmt::out::Value v3{std::move(v2)};
        
        assert(v3.Size() == 2);
        assert(v3.GetFormatOutput<char>() == &Fun1<char>);
        assert(v3.GetFormatOutput('a') == &Fun1<char>);
        assert(v3.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        assert(v3.GetFormatOutput(L'a') == &Fun1<wchar_t>);
        
        assert(v2.Size() == 0);
        assert(v2.GetFormatOutput<char>() == nullptr);
        assert(v2.GetFormatOutput('a') == nullptr);
        assert(v2.GetFormatOutput<wchar_t>() == nullptr);
        assert(v2.GetFormatOutput(L'a') == nullptr);

        test::out::fmt::out::Value v4;
        v4 = v3;

        assert(v4.Size() == 2);
        assert(v4.GetFormatOutput<char>() == &Fun1<char>);
        assert(v4.GetFormatOutput('a') == &Fun1<char>);
        assert(v4.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        assert(v4.GetFormatOutput(L'a') == &Fun1<wchar_t>);

        test::out::fmt::out::Value v5;
        v5 = std::move(v4);
        
        assert(v5.Size() == 2);
        assert(v5.GetFormatOutput<char>() == &Fun1<char>);
        assert(v5.GetFormatOutput('a') == &Fun1<char>);
        assert(v5.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        assert(v5.GetFormatOutput(L'a') == &Fun1<wchar_t>);

        assert(v4.Size() == 0);
        assert(v4.GetFormatOutput<char>() == nullptr);
        assert(v4.GetFormatOutput('a') == nullptr);
        assert(v4.GetFormatOutput<wchar_t>() == nullptr);
        assert(v4.GetFormatOutput(L'a') == nullptr);
        
    }
    {
        test::out::fmt::out::Value v1{1};
        
        assert(v1.Size() == 1);
        assert(v1.GetFormatOutput<char>() == nullptr);
        assert(v1.GetFormatOutput('a') == nullptr);
        assert(v1.GetFormatOutput<wchar_t>() == nullptr);
        assert(v1.GetFormatOutput(L'a') == nullptr);

        assert(v1.Set(test::out::fmt::out::Block{&Fun1<char>}) == 1);
        
        assert(v1.Size() == 1);
        assert(v1.GetFormatOutput<char>() == &Fun1<char>);
        assert(v1.GetFormatOutput('a') == &Fun1<char>);
        assert(v1.GetFormatOutput<wchar_t>() == nullptr);
        assert(v1.GetFormatOutput(L'a') == nullptr);
    }
    {
        test::out::fmt::out::Value v1{1};
        
        assert(v1.Size() == 1);
        assert(v1.GetFormatOutput<char>() == nullptr);
        assert(v1.GetFormatOutput('a') == nullptr);
        assert(v1.GetFormatOutput<wchar_t>() == nullptr);
        assert(v1.GetFormatOutput(L'a') == nullptr);

        assert(v1.Set(test::out::fmt::out::Block{&Fun1<wchar_t>},
            test::out::fmt::out::Block{&Fun1<char>}) == 1);
            
        assert(v1.Size() == 1);
        assert(v1.GetFormatOutput<char>() == nullptr);
        assert(v1.GetFormatOutput('a') == nullptr);
        assert(v1.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        assert(v1.GetFormatOutput(L'a') == &Fun1<wchar_t>);
    }
    {
        test::out::fmt::out::Value v1{2};
        
        assert(v1.Size() == 2);
        assert(v1.GetFormatOutput<char>() == nullptr);
        assert(v1.GetFormatOutput('a') == nullptr);
        assert(v1.GetFormatOutput<wchar_t>() == nullptr);
        assert(v1.GetFormatOutput(L'a') == nullptr);

        assert(v1.Set(test::out::fmt::out::Block{&Fun1<char>}) == 1);
        
        assert(v1.Size() == 2);
        assert(v1.GetFormatOutput<char>() == &Fun1<char>);
        assert(v1.GetFormatOutput('a') == &Fun1<char>);
        assert(v1.GetFormatOutput<wchar_t>() == nullptr);
        assert(v1.GetFormatOutput(L'a') == nullptr);
        
        assert(v1.Set(test::out::fmt::out::Block{&Fun1<wchar_t>},
            test::out::fmt::out::Block{&Fun1<char>}) == 2);
            
        assert(v1.Size() == 2);
        assert(v1.GetFormatOutput<char>() == &Fun1<char>);
        assert(v1.GetFormatOutput('a') == &Fun1<char>);
        assert(v1.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        assert(v1.GetFormatOutput(L'a') == &Fun1<wchar_t>);
    }
    {
        test::Pointer<char> raw{test::ptr::arg::Array{sizeof(std::size_t)}};
        *(raw.ReinterpretCast<std::size_t>()) = 0;
        test::out::fmt::out::Value v1{raw};
        
        assert(v1.Size() == 0);
        assert(v1.GetFormatOutput<char>() == nullptr);
        assert(v1.GetFormatOutput('a') == nullptr);
        assert(v1.GetFormatOutput<wchar_t>() == nullptr);
        assert(v1.GetFormatOutput(L'a') == nullptr);
        assert(v1.GetRaw() == raw);
    }
    {
        test::Pointer<char> raw{test::ptr::arg::Array{sizeof(std::size_t) +
            sizeof(test::out::fmt::out::Block)}};
        *(raw.ReinterpretCast<std::size_t>()) = 1;
        test::out::fmt::out::Value v1{raw};
        
        assert(v1.Size() == 1);
        assert(v1.GetFormatOutput<char>() == nullptr);
        assert(v1.GetFormatOutput('a') == nullptr);
        assert(v1.GetFormatOutput<wchar_t>() == nullptr);
        assert(v1.GetFormatOutput(L'a') == nullptr);
        
        assert(v1.Set(test::out::fmt::out::Block{&Fun1<char>}) == 1);
        
        assert(v1.Size() == 1);
        assert(v1.GetFormatOutput<char>() == &Fun1<char>);
        assert(v1.GetFormatOutput('a') == &Fun1<char>);
        assert(v1.GetFormatOutput<wchar_t>() == nullptr);
        assert(v1.GetFormatOutput(L'a') == nullptr);
        
        assert(v1.Set(test::out::fmt::out::Block{&Fun1<wchar_t>},
            test::out::fmt::out::Block{&Fun1<char>}) == 1);
            
        assert(v1.Size() == 1);
        assert(v1.GetFormatOutput<char>() == nullptr);
        assert(v1.GetFormatOutput('a') == nullptr);
        assert(v1.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        assert(v1.GetFormatOutput(L'a') == &Fun1<wchar_t>);
        
        assert(v1.GetRaw() == raw);
    }
    {
        test::Pointer<char> raw{test::ptr::arg::Array{sizeof(std::size_t) +
            (2 * sizeof(test::out::fmt::out::Block))}};
        *(raw.ReinterpretCast<std::size_t>()) = 2;
        test::out::fmt::out::Value v1{raw};
        
        assert(v1.Size() == 2);
        assert(v1.GetFormatOutput<char>() == nullptr);
        assert(v1.GetFormatOutput('a') == nullptr);
        assert(v1.GetFormatOutput<wchar_t>() == nullptr);
        assert(v1.GetFormatOutput(L'a') == nullptr);
        
        assert(v1.Set(test::out::fmt::out::Block{&Fun1<char>}) == 1);
        
        assert(v1.Size() == 2);
        assert(v1.GetFormatOutput<char>() == &Fun1<char>);
        assert(v1.GetFormatOutput('a') == &Fun1<char>);
        assert(v1.GetFormatOutput<wchar_t>() == nullptr);
        assert(v1.GetFormatOutput(L'a') == nullptr);
        
        assert(v1.Set(test::out::fmt::out::Block{&Fun1<wchar_t>},
            test::out::fmt::out::Block{&Fun1<char>}) == 2);
            
        assert(v1.Size() == 2);
        assert(v1.GetFormatOutput<char>() == &Fun1<char>);
        assert(v1.GetFormatOutput('a') == &Fun1<char>);
        assert(v1.GetFormatOutput<wchar_t>() == &Fun1<wchar_t>);
        assert(v1.GetFormatOutput(L'a') == &Fun1<wchar_t>);
        
        assert(v1.GetRaw() == raw);
    }
    return 0;
}
