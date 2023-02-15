#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#define TEST_OUT_FMT_BLOCK_DLEVEL 0x7f

#include "test/out/fmt/Block.h"
#include "test/out/fmt/arg/Integer.h"
#include "test/out/fmt/arg/String.h"
#include "test/out/fmt/arg/Object.h"

#include <cassert>

template<typename TChar>
std::size_t Fun1(test::out::Interface<TChar>& out, 
    void* value, std::size_t value_size, 
    typename test::out::fmt::Definition::FlagType flag, 
    int width, int len_pred)
{
    return 0;
}

class Obj1
{
public:
    char ch;
    double dl;
    std::size_t sz;
public:
    Obj1() :
        ch('l'),
        dl(3.14),
        sz(-1)
    {}
    Obj1(double d) :
        ch('k'),
        dl(d),
        sz(0xffff)
    {}
public:
    Obj1(const Obj1& c) :
        ch(c.ch),
        dl(c.dl),
        sz(c.sz)
    {}
public:
    Obj1& operator=(const Obj1& c)
    {
        ch = c.ch;
        dl = c.dl;
        sz = c.sz;
        return *this;
    }
};

int main()
{
    {
        test::out::fmt::Block b1;
        test::Pointer<char> raw;

        assert(b1.Flag().GetSpecifier() == b1.Flag().undefined);
        assert(b1.AllocationSize() == 0);
        assert(b1.Offset() == 0);
        assert(b1.GetValue<int>(raw) == 0);
        assert(b1.GetValue<void>(raw) == &b1.GetValue<int>(raw));
        assert(b1.GetValueSize() == 0);
        assert(b1.GetWidth(raw) == 0);
        assert(b1.GetLength(raw) == 0);
        assert(b1.GetPrecision(raw) == 0);
        assert(b1.GetFormatOutput<char>(raw) == nullptr);
        assert(b1.GetFormatOutput<wchar_t>(raw) == nullptr);

        b1.SetValue<int>(raw, 20);
        assert(b1.GetValue<int>(raw) == 0);
        assert(b1.GetValue<void>(raw) == &b1.GetValue<int>(raw));
        assert(b1.GetValueSize() == 0);

        b1.SetWidth(raw, 30);
        assert(b1.GetWidth(raw) == 0);

        b1.SetLength(raw, 40);
        assert(b1.GetLength(raw) == 0);

        b1.SetPrecision(raw, 50);
        assert(b1.GetPrecision(raw) == 0);

        test::out::fmt::Block b2(b1);
        assert(b2.Flag().GetSpecifier() == b1.Flag().undefined);
        assert(b2.AllocationSize() == 0);
        assert(b2.Offset() == 0);
        assert(b2.GetValue<int>(raw) == 0);
        assert(b2.GetValue<void>(raw) == &b2.GetValue<int>(raw));
        assert(b2.GetValueSize() == 0);
        assert(b2.GetWidth(raw) == 0);
        assert(b2.GetLength(raw) == 0);
        assert(b2.GetPrecision(raw) == 0);
        assert(b2.GetFormatOutput<char>(raw) == nullptr);
        assert(b2.GetFormatOutput<wchar_t>(raw) == nullptr);

        test::out::fmt::Block b3(std::move(b2));
        
        assert(b3.Flag().GetSpecifier() == b1.Flag().undefined);
        assert(b3.AllocationSize() == 0);
        assert(b3.Offset() == 0);
        assert(b3.GetValue<int>(raw) == 0);
        assert(b3.GetValue<void>(raw) == &b3.GetValue<int>(raw));
        assert(b3.GetValueSize() == 0);
        assert(b3.GetWidth(raw) == 0);
        assert(b3.GetLength(raw) == 0);
        assert(b3.GetPrecision(raw) == 0);
        assert(b3.GetFormatOutput<char>(raw) == nullptr);
        assert(b3.GetFormatOutput<wchar_t>(raw) == nullptr);
        
        assert(b2.Flag().GetSpecifier() == b1.Flag().undefined);
        assert(b2.AllocationSize() == 0);
        assert(b2.Offset() == 0);
        assert(b2.GetValue<int>(raw) == 0);
        assert(b2.GetValue<void>(raw) == &b2.GetValue<int>(raw));
        assert(b2.GetValueSize() == 0);
        assert(b2.GetWidth(raw) == 0);
        assert(b2.GetLength(raw) == 0);
        assert(b2.GetPrecision(raw) == 0);
        assert(b2.GetFormatOutput<char>(raw) == nullptr);
        assert(b2.GetFormatOutput<wchar_t>(raw) == nullptr);

        test::out::fmt::Block b4;
        b4 = b3;
        
        assert(b4.Flag().GetSpecifier() == b1.Flag().undefined);
        assert(b4.AllocationSize() == 0);
        assert(b4.Offset() == 0);
        assert(b4.GetValue<int>(raw) == 0);
        assert(b4.GetValue<void>(raw) == &b4.GetValue<int>(raw));
        assert(b4.GetValueSize() == 0);
        assert(b4.GetWidth(raw) == 0);
        assert(b4.GetLength(raw) == 0);
        assert(b4.GetPrecision(raw) == 0);
        assert(b4.GetFormatOutput<char>(raw) == nullptr);
        assert(b4.GetFormatOutput<wchar_t>(raw) == nullptr);
        
        test::out::fmt::Block b5;
        b5 = std::move(b4);
        
        assert(b5.Flag().GetSpecifier() == b1.Flag().undefined);
        assert(b5.AllocationSize() == 0);
        assert(b5.Offset() == 0);
        assert(b5.GetValue<int>(raw) == 0);
        assert(b5.GetValue<void>(raw) == &b5.GetValue<int>(raw));
        assert(b5.GetValueSize() == 0);
        assert(b5.GetWidth(raw) == 0);
        assert(b5.GetLength(raw) == 0);
        assert(b5.GetPrecision(raw) == 0);
        assert(b5.GetFormatOutput<char>(raw) == nullptr);
        assert(b5.GetFormatOutput<wchar_t>(raw) == nullptr);
        
        assert(b4.Flag().GetSpecifier() == b1.Flag().undefined);
        assert(b4.AllocationSize() == 0);
        assert(b4.Offset() == 0);
        assert(b4.GetValue<int>(raw) == 0);
        assert(b4.GetValue<void>(raw) == &b4.GetValue<int>(raw));
        assert(b4.GetValueSize() == 0);
        assert(b4.GetWidth(raw) == 0);
        assert(b4.GetLength(raw) == 0);
        assert(b4.GetPrecision(raw) == 0);
        assert(b4.GetFormatOutput<char>(raw) == nullptr);
        assert(b4.GetFormatOutput<wchar_t>(raw) == nullptr);
    }
    {
        test::out::fmt::arg::Integer<int> arg1{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40},
            test::out::fmt::flag::Output<char, wchar_t>(&Fun1<char>, 
                &Fun1<wchar_t>)
        };

        const std::size_t size = 
            test::out::fmt::Block::DataAllocationSize(arg1); 
        test::Pointer<char> raw{test::ptr::arg::Array{size}};
        test::out::fmt::Block b1{arg1.GetFlag(), 0, size};

        b1.Initialize(raw, arg1);
        
        assert(b1.Flag().IsSpecifierInteger() == true);
        assert(b1.AllocationSize() == size);
        assert(b1.Offset() == 0);
        assert(b1.GetValue<int>(raw) == 4);
        assert(b1.GetValue<void>(raw) == &b1.GetValue<int>(raw));
        assert(b1.GetValueSize() == sizeof(int));
        assert(b1.GetWidth(raw) == 20);
        assert(b1.GetLength(raw) == 40);
        assert(b1.GetPrecision(raw) == 40);
        assert(b1.GetFormatOutput<char>(raw) == &Fun1<char>);
        assert(b1.GetFormatOutput<wchar_t>(raw) == &Fun1<wchar_t>);
        
        b1.SetValue<int>(raw, 44);
        assert(b1.GetValue<int>(raw) == 44);
        assert(b1.GetValue<void>(raw) == &b1.GetValue<int>(raw));
        assert(b1.GetValueSize() == sizeof(int));

        b1.SetWidth(raw, 30);
        assert(b1.GetWidth(raw) == 30);

        b1.SetLength(raw, 60);
        assert(b1.GetLength(raw) == 60);

        b1.SetPrecision(raw, 90);
        assert(b1.GetPrecision(raw) == 90);

        test::out::fmt::Block b2(b1);
        
        assert(b2.Flag().IsSpecifierInteger() == true);
        assert(b2.AllocationSize() == size);
        assert(b2.Offset() == 0);
        assert(b2.GetValue<int>(raw) == 44);
        assert(b2.GetValue<void>(raw) == &b2.GetValue<int>(raw));
        assert(b2.GetValueSize() == sizeof(int));
        assert(b2.GetWidth(raw) == 30);
        assert(b2.GetLength(raw) == 90);
        assert(b2.GetPrecision(raw) == 90);
        assert(b2.GetFormatOutput<char>(raw) == &Fun1<char>);
        assert(b2.GetFormatOutput<wchar_t>(raw) == &Fun1<wchar_t>);
        
        test::out::fmt::Block b3(std::move(b2));
        
        assert(b3.Flag().IsSpecifierInteger() == true);
        assert(b3.AllocationSize() == size);
        assert(b3.Offset() == 0);
        assert(b3.GetValue<int>(raw) == 44);
        assert(b3.GetValue<void>(raw) == &b3.GetValue<int>(raw));
        assert(b3.GetValueSize() == sizeof(int));
        assert(b3.GetWidth(raw) == 30);
        assert(b3.GetLength(raw) == 90);
        assert(b3.GetPrecision(raw) == 90);
        assert(b3.GetFormatOutput<char>(raw) == &Fun1<char>);
        assert(b3.GetFormatOutput<wchar_t>(raw) == &Fun1<wchar_t>);
        
        assert(b2.Flag().GetSpecifier() == b1.Flag().undefined);
        assert(b2.AllocationSize() == 0);
        assert(b2.Offset() == 0);
        assert(b2.GetValue<int>(raw) == 0);
        assert(b2.GetValue<void>(raw) == &b2.GetValue<int>(raw));
        assert(b2.GetValueSize() == 0);
        assert(b2.GetWidth(raw) == 0);
        assert(b2.GetLength(raw) == 0);
        assert(b2.GetPrecision(raw) == 0);
        assert(b2.GetFormatOutput<char>(raw) == nullptr);
        assert(b2.GetFormatOutput<wchar_t>(raw) == nullptr);

        test::out::fmt::Block b4;
        b4 = b3;
        
        assert(b4.Flag().IsSpecifierInteger() == true);
        assert(b4.AllocationSize() == size);
        assert(b4.Offset() == 0);
        assert(b4.GetValue<int>(raw) == 44);
        assert(b4.GetValue<void>(raw) == &b4.GetValue<int>(raw));
        assert(b4.GetValueSize() == sizeof(int));
        assert(b4.GetWidth(raw) == 30);
        assert(b4.GetLength(raw) == 90);
        assert(b4.GetPrecision(raw) == 90);
        assert(b4.GetFormatOutput<char>(raw) == &Fun1<char>);
        assert(b4.GetFormatOutput<wchar_t>(raw) == &Fun1<wchar_t>);
        
        test::out::fmt::Block b5;
        b5 = std::move(b4);
        
        assert(b5.Flag().IsSpecifierInteger() == true);
        assert(b5.AllocationSize() == size);
        assert(b5.Offset() == 0);
        assert(b5.GetValue<int>(raw) == 44);
        assert(b5.GetValue<void>(raw) == &b5.GetValue<int>(raw));
        assert(b5.GetValueSize() == sizeof(int));
        assert(b5.GetWidth(raw) == 30);
        assert(b5.GetLength(raw) == 90);
        assert(b5.GetPrecision(raw) == 90);
        assert(b5.GetFormatOutput<char>(raw) == &Fun1<char>);
        assert(b5.GetFormatOutput<wchar_t>(raw) == &Fun1<wchar_t>);
        
        assert(b4.Flag().GetSpecifier() == b1.Flag().undefined);
        assert(b4.AllocationSize() == 0);
        assert(b4.Offset() == 0);
        assert(b4.GetValue<int>(raw) == 0);
        assert(b4.GetValue<void>(raw) == &b4.GetValue<int>(raw));
        assert(b4.GetValueSize() == 0);
        assert(b4.GetWidth(raw) == 0);
        assert(b4.GetLength(raw) == 0);
        assert(b4.GetPrecision(raw) == 0);
        assert(b4.GetFormatOutput<char>(raw) == nullptr);
        assert(b4.GetFormatOutput<wchar_t>(raw) == nullptr);
    }
    {
        const char str1[] = "test out 1234";
        const char str2[] = "1234 test out";
        test::out::fmt::arg::String<char*> arg1{str1,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40},
            test::out::fmt::flag::Output<char, wchar_t>(&Fun1<char>, 
                &Fun1<wchar_t>)
        };
        
        const std::size_t size = 
            test::out::fmt::Block::DataAllocationSize(arg1);
        test::Pointer<char> raw{test::ptr::arg::Array{size}};
        test::Pointer<char> raw_str2{test::ptr::arg::Array{sizeof(str2)}};
        test::out::fmt::Block b1{arg1.GetFlag(), 0, size};

        memcpy(&*raw_str2, str2, sizeof(str2));

        b1.Initialize(raw, arg1);
        
        assert(b1.Flag().IsSpecifierString() == true);
        assert(b1.AllocationSize() == size);
        assert(b1.Offset() == 0);
        assert(strcmp(&*(b1.GetValue<test::Pointer<char>>(raw)), str1) == 0);
        assert(b1.GetValue<void>(raw) == 
            &b1.GetValue<test::Pointer<char>>(raw));
        assert(b1.GetValueSize() == sizeof(test::Pointer<char>));
        assert(b1.GetWidth(raw) == 20);
        assert(b1.GetLength(raw) == 40);
        assert(b1.GetPrecision(raw) == 40);
        assert(b1.GetFormatOutput<char>(raw) == &Fun1<char>);
        assert(b1.GetFormatOutput<wchar_t>(raw) == &Fun1<wchar_t>);

        b1.SetValue(raw, raw_str2);
        assert(strcmp(&*(b1.GetValue<test::Pointer<char>>(raw)), str2) == 0);
        assert(b1.GetValue<void>(raw) == 
            &b1.GetValue<test::Pointer<char>>(raw));
        assert(b1.GetValueSize() == sizeof(test::Pointer<char>));
        
    }
    {
        const char str1[] = "test out 1234";
        const char str2[] = "1234 test out";
         test::out::fmt::arg::String<char*> arg1{str1,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40},
            test::out::fmt::flag::Output<char, wchar_t>(&Fun1<char>, 
                &Fun1<wchar_t>)
        };
        test::out::fmt::arg::Integer<int> arg2{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40},
            test::out::fmt::flag::Output<char, wchar_t>(&Fun1<char>, 
                &Fun1<wchar_t>)
        };
        
        const std::size_t size1 = 
            test::out::fmt::Block::DataAllocationSize(arg1);
        const std::size_t size2 =
            test::out::fmt::Block::DataAllocationSize(arg2); 

        test::Pointer<char> raw{test::ptr::arg::Array{size1 +size2 }};
        test::Pointer<char> raw_str2{test::ptr::arg::Array{sizeof(str2)}};
            
        test::out::fmt::Block b1{arg1.GetFlag(), 0, size1};
        test::out::fmt::Block b2{arg2.GetFlag(), size1, size2};
        
        memcpy(&*raw_str2, str2, sizeof(str2));

        b1.Initialize(raw, arg1);
        b2.Initialize(raw, arg2);
        
        assert(b1.Flag().IsSpecifierString() == true);
        assert(b1.AllocationSize() == size1);
        assert(b1.Offset() == 0);
        assert(strcmp(&*(b1.GetValue<test::Pointer<char>>(raw)), str1) == 0);
        assert(b1.GetValue<void>(raw) == 
            &b1.GetValue<test::Pointer<char>>(raw));
        assert(b1.GetValueSize() == sizeof(test::Pointer<char>));
        assert(b1.GetWidth(raw) == 20);
        assert(b1.GetLength(raw) == 40);
        assert(b1.GetPrecision(raw) == 40);
        assert(b1.GetFormatOutput<char>(raw) == &Fun1<char>);
        assert(b1.GetFormatOutput<wchar_t>(raw) == &Fun1<wchar_t>);
        
        assert(b2.Flag().IsSpecifierInteger() == true);
        assert(b2.AllocationSize() == size2);
        assert(b2.Offset() == size1);
        assert(b2.GetValue<int>(raw) == 4);
        assert(b2.GetValue<void>(raw) == &b2.GetValue<int>(raw));
        assert(b2.GetValueSize() == sizeof(int));
        assert(b2.GetWidth(raw) == 20);
        assert(b2.GetLength(raw) == 40);
        assert(b2.GetPrecision(raw) == 40);
        assert(b2.GetFormatOutput<char>(raw) == &Fun1<char>);
        assert(b2.GetFormatOutput<wchar_t>(raw) == &Fun1<wchar_t>);
        
        b1.SetValue(raw, raw_str2);
        assert(strcmp(&*(b1.GetValue<test::Pointer<char>>(raw)), str2) == 0);
        assert(b1.GetValue<void>(raw) == 
            &b1.GetValue<test::Pointer<char>>(raw));
        assert(b1.GetValueSize() == sizeof(test::Pointer<char>));
        
        b2.SetValue<int>(raw, 44);
        assert(b2.GetValue<int>(raw) == 44);
        assert(b2.GetValue<void>(raw) == &b2.GetValue<int>(raw));
        assert(b2.GetValueSize() == sizeof(int));
    }
    
    {
        const char str1[] = "test out 1234";
        const char str2[] = "1234 test out";
         test::out::fmt::arg::String<char*> arg1{str1,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40},
            test::out::fmt::flag::Output<char, wchar_t>(&Fun1<char>, 
                &Fun1<wchar_t>)
        };
        test::out::fmt::arg::Integer<int> arg2{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40},
            test::out::fmt::flag::Output<char, wchar_t>(&Fun1<char>, 
                &Fun1<wchar_t>)
        };
        test::out::fmt::arg::String<char*> arg3{str2,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40},
            test::out::fmt::flag::Output<char, wchar_t>(&Fun1<char>, 
                &Fun1<wchar_t>)
        };
        test::out::fmt::arg::Object<Obj1> arg4{
            Obj1{6.28},
            test::out::fmt::flag::Width{10},
            test::out::fmt::flag::Length{20},
            test::out::fmt::flag::Output<char>(&Fun1<char>)
        };
        
        const std::size_t size1 = 
            test::out::fmt::Block::DataAllocationSize(arg1);
        const std::size_t size2 =
            test::out::fmt::Block::DataAllocationSize(arg2); 
        const std::size_t size3 =
            test::out::fmt::Block::DataAllocationSize(arg3); 
        const std::size_t size4 =
            test::out::fmt::Block::DataAllocationSize(arg4); 

        test::Pointer<char> raw{test::ptr::arg::Array{size1 + size2 +
            size3 + size4}};
        test::Pointer<char> raw_str1{test::ptr::arg::Array{sizeof(str1)}};
        test::Pointer<char> raw_str2{test::ptr::arg::Array{sizeof(str2)}};
            
        test::out::fmt::Block b1{arg1.GetFlag(), 0, size1};
        test::out::fmt::Block b2{arg2.GetFlag(), size1, size2};
        test::out::fmt::Block b3{arg3.GetFlag(), size1 + size2, size3};
        test::out::fmt::Block b4{arg4.GetFlag(), size1 + size2 + size3, size4};
        
        memcpy(&*raw_str1, str1, sizeof(str1));
        memcpy(&*raw_str2, str2, sizeof(str2));

        b1.Initialize(raw, arg1);
        b2.Initialize(raw, arg2);
        b3.Initialize(raw, arg3);
        b4.Initialize(raw, arg4);
        
        assert(b1.Flag().IsSpecifierString() == true);
        assert(b1.AllocationSize() == size1);
        assert(b1.Offset() == 0);
        assert(strcmp(&*(b1.GetValue<test::Pointer<char>>(raw)), str1) == 0);
        assert(b1.GetValue<void>(raw) == 
            &b1.GetValue<test::Pointer<char>>(raw));
        assert(b1.GetValueSize() == sizeof(test::Pointer<char>));
        assert(b1.GetWidth(raw) == 20);
        assert(b1.GetLength(raw) == 40);
        assert(b1.GetPrecision(raw) == 40);
        assert(b1.GetFormatOutput<char>(raw) == &Fun1<char>);
        assert(b1.GetFormatOutput<wchar_t>(raw) == &Fun1<wchar_t>);
        
        assert(b2.Flag().IsSpecifierInteger() == true);
        assert(b2.AllocationSize() == size2);
        assert(b2.Offset() == size1);
        assert(b2.GetValue<int>(raw) == 4);
        assert(b2.GetValue<void>(raw) == &b2.GetValue<int>(raw));
        assert(b2.GetValueSize() == sizeof(int));
        assert(b2.GetWidth(raw) == 20);
        assert(b2.GetLength(raw) == 40);
        assert(b2.GetPrecision(raw) == 40);
        assert(b2.GetFormatOutput<char>(raw) == &Fun1<char>);
        assert(b2.GetFormatOutput<wchar_t>(raw) == &Fun1<wchar_t>);
        
        assert(b3.Flag().IsSpecifierString() == true);
        assert(b3.AllocationSize() == size3);
        assert(b3.Offset() == size1 + size2);
        assert(strcmp(&*(b3.GetValue<test::Pointer<char>>(raw)), str2) == 0);
        assert(b3.GetValue<void>(raw) == 
            &b3.GetValue<test::Pointer<char>>(raw));
        assert(b3.GetValueSize() == sizeof(test::Pointer<char>));
        assert(b3.GetWidth(raw) == 20);
        assert(b3.GetLength(raw) == 40);
        assert(b3.GetPrecision(raw) == 40);
        assert(b3.GetFormatOutput<char>(raw) == &Fun1<char>);
        assert(b3.GetFormatOutput<wchar_t>(raw) == &Fun1<wchar_t>);
        
        assert(b4.Flag().IsSpecifierObject() == true);
        assert(b4.AllocationSize() == size4);
        assert(b4.Offset() == size1 + size2 + size3);
        assert(b4.GetValue<Obj1>(raw).ch == 'k');
        assert(b4.GetValue<Obj1>(raw).dl == 6.28);
        assert(b4.GetValue<Obj1>(raw).sz == 0xffff);
        assert(b4.GetValue<void>(raw) == &b4.GetValue<Obj1>(raw));
        assert(b4.GetValueSize() == sizeof(Obj1));
        assert(b4.GetWidth(raw) == 10);
        assert(b4.GetLength(raw) == 20);
        assert(b4.GetPrecision(raw) == 20);
        assert(b4.GetFormatOutput<char>(raw) == &Fun1<char>);
        assert(b4.GetFormatOutput<wchar_t>(raw) == nullptr);
        
        b1.SetValue(raw, raw_str2);
        assert(strcmp(&*(b1.GetValue<test::Pointer<char>>(raw)), str2) == 0);
        assert(b1.GetValue<void>(raw) == 
            &b1.GetValue<test::Pointer<char>>(raw));
        assert(b1.GetValueSize() == sizeof(test::Pointer<char>));
        
        b2.SetValue<int>(raw, 44);
        assert(b2.GetValue<int>(raw) == 44);
        assert(b2.GetValue<void>(raw) == &b2.GetValue<int>(raw));
        assert(b2.GetValueSize() == sizeof(int));
        
        b3.SetValue(raw, raw_str1);
        assert(strcmp(&*(b3.GetValue<test::Pointer<char>>(raw)), str1) == 0);
        assert(b3.GetValue<void>(raw) == 
            &b3.GetValue<test::Pointer<char>>(raw));
        assert(b3.GetValueSize() == sizeof(test::Pointer<char>));
        
        b4.SetValue<Obj1>(raw, Obj1());
        assert(b4.GetValue<Obj1>(raw).ch == 'l');
        assert(b4.GetValue<Obj1>(raw).dl == 3.14);
        assert(b4.GetValue<Obj1>(raw).sz == -1);
        assert(b4.GetValue<void>(raw) == &b4.GetValue<Obj1>(raw));
        assert(b4.GetValueSize() == sizeof(Obj1));
        
    }
    return 0;
}
