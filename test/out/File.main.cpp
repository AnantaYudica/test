#include "test/out/File.h"

#include <cstdio>
#include <utility>
#include <cstdarg>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <functional>

constexpr std::size_t Out1MinimumBuffer = 512;
constexpr std::size_t Out1MaximumBuffer = 12288;
constexpr std::size_t Out2MinimumBuffer = 512;
constexpr std::size_t Out2MaximumBuffer = 12288;
constexpr std::size_t Out3MinimumBuffer = 8;
constexpr std::size_t Out3MaximumBuffer = 16;
constexpr std::size_t Out4MinimumBuffer = 32;
constexpr std::size_t Out4MaximumBuffer = 64;

struct Out1 : public test::out::File<char, Out1MinimumBuffer, 
    Out1MaximumBuffer>
{
    typedef test::out::File<char, Out1MinimumBuffer, 
        Out1MaximumBuffer> BaseType;
    Out1() :
        BaseType()
    {
        Initialize();
    }
    Out1(const char * fm, ModeType mode) :
        BaseType(fm, mode)
    {
        Initialize();
    }
    
    Out1(const char * fm, ModeType mode, size_t max) :
        BaseType(fm, mode, max)
    {
        Initialize();
    }

    ~Out1() {}
    using BaseType::Mode;
    using BaseType::Size;
    using BaseType::MaximumSize;
    using BaseType::Filename;
    using BaseType::Print;
    using BaseType::Puts;
    using BaseType::Buffer;
    using BaseType::IsGood;
    using BaseType::IsBad;
    using BaseType::GetBadCode;
    using BaseType::IsStandard;
};

struct Out2 : public test::out::File<char, Out2MinimumBuffer, 
    Out2MaximumBuffer>
{
    typedef test::out::File<char, Out2MinimumBuffer, 
        Out2MaximumBuffer> BaseType;
    Out2() :
        BaseType()
    {}
    Out2(const char * fm, ModeType mode) :
        BaseType(fm, mode)
    {}
    
    Out2(const char * fm, ModeType mode, size_t max) :
        BaseType(fm, mode, max)
    {}

    ~Out2() {}
    using BaseType::Mode;
    using BaseType::Size;
    using BaseType::MaximumSize;
    using BaseType::Filename;
    using BaseType::Print;
    using BaseType::Puts;
    using BaseType::Buffer;
    using BaseType::IsGood;
    using BaseType::IsBad;
    using BaseType::GetBadCode;
    using BaseType::IsStandard;
};

struct Out3 : public test::out::File<char, Out3MinimumBuffer, 
    Out3MaximumBuffer>
{
    typedef test::out::File<char, Out3MinimumBuffer, 
        Out3MaximumBuffer> BaseType;
    Out3() :
        BaseType()
    {}
    Out3(const char * fm, ModeType mode) :
        BaseType(fm, mode)
    {}
    
    Out3(const char * fm, ModeType mode, size_t max) :
        BaseType(fm, mode, max)
    {}

    ~Out3() {}
    using BaseType::Mode;
    using BaseType::Size;
    using BaseType::MaximumSize;
    using BaseType::Filename;
    using BaseType::Print;
    using BaseType::Puts;
    using BaseType::Buffer;
    using BaseType::IsGood;
    using BaseType::IsBad;
    using BaseType::GetBadCode;
    using BaseType::IsStandard;
};

struct Out4 : public test::out::File<char, Out4MinimumBuffer, 
    Out4MaximumBuffer>
{
    typedef std::function<bool(test::CString<char>, test::CString<char>&, ModeType&)> 
        OnMaximumSizeFunctionType;
    typedef test::out::File<char, Out4MinimumBuffer, 
        Out4MaximumBuffer> BaseType;
    OnMaximumSizeFunctionType onMaxSizeCb;
    Out4() :
        BaseType(),
        onMaxSizeCb(nullptr)
    {}
    Out4(const char * fm, ModeType mode) :
        BaseType(fm, mode),
        onMaxSizeCb(nullptr)
    {}
    
    Out4(const char * fm, ModeType mode, size_t max) :
        BaseType(fm, mode, max),
        onMaxSizeCb(nullptr)
    {}
    
    Out4(const char * fm, ModeType mode, size_t max, OnMaximumSizeFunctionType cb) :
        BaseType(fm, mode, max),
        onMaxSizeCb(cb)
    {}

    ~Out4() {}

    bool OnMaximumSize(test::CString<char> old_filename,
        test::CString<char>& new_filename, ModeType& mode)
    {
        if (onMaxSizeCb != nullptr)
        {
            return onMaxSizeCb(old_filename, new_filename, mode);
        } 
        return false;
    }

    using BaseType::Mode;
    using BaseType::Size;
    using BaseType::MaximumSize;
    using BaseType::Filename;
    using BaseType::Print;
    using BaseType::Puts;
    using BaseType::Buffer;
    using BaseType::IsGood;
    using BaseType::IsBad;
    using BaseType::GetBadCode;
    using BaseType::IsStandard;
};

bool CheckFileExist(const char * fname);
bool ReadFile(const char * fname, const char * str, 
    const std::size_t& size);

int main()
{
    // struct Out1
    //Default constructor
    {
        Out1 out1_1;
        const Out1& cout1_1 = out1_1;
        auto size = out1_1.Print("test\n");
        assert(size == 5);
        assert(out1_1.Mode() == Out1::mode_undefined);
        assert(out1_1.Size() == 0);
        assert(out1_1.MaximumSize() == 0);
        assert(strncmp(*(out1_1.Filename()), "", 0) == 0);
        assert(out1_1.Buffer().Size() == 5);
        assert(cout1_1.Buffer().Size() == 5);
        assert(strncmp(*(out1_1.Buffer()), "test\n", 5) == 0);
        assert(strncmp(*(cout1_1.Buffer()), "test\n", 5) == 0);
        assert(out1_1.IsGood() == true);
        assert(out1_1.IsBad() == false);
        assert(out1_1.GetBadCode() == Out1::StatusType::good);
        assert(out1_1.IsStandard() == true);

        size = out1_1.Print("%d,%c,%s,%2.3f\n", 123, (int)'4', "567", 89.248f);
        assert(size == 17);
        assert(out1_1.Mode() == Out1::mode_undefined);
        assert(out1_1.Size() == 0);
        assert(out1_1.MaximumSize() == 0);
        assert(strncmp(*(out1_1.Filename()), "", 0) == 0);
        assert(out1_1.Buffer().Size() == 17);
        assert(cout1_1.Buffer().Size() == 17);
        assert(strncmp(*(out1_1.Buffer()), "123,4,567,89.248\n", 17) == 0);
        assert(strncmp(*(cout1_1.Buffer()), "123,4,567,89.248\n", 17) == 0);
        assert(out1_1.IsGood() == true);
        assert(out1_1.IsBad() == false);
        assert(out1_1.GetBadCode() == Out1::StatusType::good);
        assert(out1_1.IsStandard() == true);

        size = out1_1.Puts("12345678\n");
        assert(size == 9);
        assert(out1_1.Mode() == Out1::mode_undefined);
        assert(out1_1.Size() == 0);
        assert(out1_1.MaximumSize() == 0);
        assert(strncmp(*(out1_1.Filename()), "", 0) == 0);
        assert(out1_1.Buffer().Size() == 9);
        assert(cout1_1.Buffer().Size() == 9);
        assert(strncmp(*(out1_1.Buffer()), "12345678\n", 9) == 0);
        assert(strncmp(*(cout1_1.Buffer()), "12345678\n", 9) == 0);
        assert(out1_1.IsGood() == true);
        assert(out1_1.IsBad() == false);
        assert(out1_1.GetBadCode() == Out1::StatusType::good);
        assert(out1_1.IsStandard() == true);
    }
    
    {
        const char fname[] = "test_out_file1.txt";
        std::size_t fname_size = sizeof(fname)-1;

        auto fname_exist = CheckFileExist(fname);
        if (fname_exist)
        {
            auto ret_rem = remove(fname);
            assert(ret_rem == 0);
        }

        //constructor with filename and undefined mode
        {
            Out1 out1_1(fname, Out1::mode_undefined);
            const Out1& cout1_1 = out1_1;

            assert(out1_1.Mode() == Out1::mode_undefined);
            assert(out1_1.Size() == 0);
            assert(out1_1.MaximumSize() == Out1MaximumBuffer);
            assert(strncmp(*(out1_1.Filename()), fname, fname_size) == 0);
            assert(out1_1.Buffer().Size() == 0);
            assert(cout1_1.Buffer().Size() == 0);
            assert(strncmp(*(out1_1.Buffer()), "", 0) == 0);
            assert(strncmp(*(cout1_1.Buffer()), "", 0) == 0);
            assert(out1_1.IsGood() == false);
            assert(out1_1.IsBad() == true);
            assert(out1_1.GetBadCode() == Out1::StatusType::open_file_mode_undefined);
            assert(out1_1.IsStandard() == false);
        }

        //constructor with filename and write mode
        {
            Out1 out1_1(fname, Out1::mode_write);
            const Out1& cout1_1 = out1_1;

            auto size = out1_1.Print("test\n");
            assert(size == 5);
            assert(out1_1.Mode() == Out1::mode_write);
            assert(out1_1.Size() == 5);
            assert(out1_1.MaximumSize() == Out1MaximumBuffer);
            assert(strncmp(*(out1_1.Filename()), fname, fname_size) == 0);
            assert(out1_1.Buffer().Size() == 5);
            assert(cout1_1.Buffer().Size() == 5);
            assert(strncmp(*(out1_1.Buffer()), "test\n", 5) == 0);
            assert(strncmp(*(cout1_1.Buffer()), "test\n", 5) == 0);
            assert(out1_1.IsGood() == true);
            assert(out1_1.IsBad() == false);
            assert(out1_1.GetBadCode() == Out1::StatusType::good);
            assert(out1_1.IsStandard() == false);
            
            size = out1_1.Print("%d,%c,%s,%2.3f\n", 123, (int)'4', "567", 89.248f);
            assert(size == 17);
            assert(out1_1.Mode() == Out1::mode_write);
            assert(out1_1.Size() == 22);
            assert(out1_1.MaximumSize() == Out1MaximumBuffer);
            assert(strncmp(*(out1_1.Filename()), fname, fname_size) == 0);
            assert(out1_1.Buffer().Size() == 17);
            assert(cout1_1.Buffer().Size() == 17);
            assert(strncmp(*(out1_1.Buffer()), "123,4,567,89.248\n", 17) == 0);
            assert(strncmp(*(cout1_1.Buffer()), "123,4,567,89.248\n", 17) == 0);
            assert(out1_1.IsGood() == true);
            assert(out1_1.IsBad() == false);
            assert(out1_1.GetBadCode() == Out1::StatusType::good);
            assert(out1_1.IsStandard() == false);

            size = out1_1.Puts("12345678\n");
            assert(size == 9);
            assert(out1_1.Mode() == Out1::mode_write);
            assert(out1_1.Size() == 31);
            assert(out1_1.MaximumSize() == Out1MaximumBuffer);
            assert(strncmp(*(out1_1.Filename()), fname, fname_size) == 0);
            assert(out1_1.Buffer().Size() == 9);
            assert(cout1_1.Buffer().Size() == 9);
            assert(strncmp(*(out1_1.Buffer()), "12345678\n", 9) == 0);
            assert(strncmp(*(cout1_1.Buffer()), "12345678\n", 9) == 0);
            assert(out1_1.IsGood() == true);
            assert(out1_1.IsBad() == false);
            assert(out1_1.GetBadCode() == Out1::StatusType::good);
            assert(out1_1.IsStandard() == false);
        }
        assert(ReadFile(fname, "12345678\n", 9) == false);
        assert(ReadFile(fname, "test\n123,4,567,89.248\n12345678\n", 31) == true);

        //constructor with filename and append mode
        {
            Out1 out1_1(fname, Out1::mode_append);
            const Out1& cout1_1 = out1_1;

            assert(out1_1.Mode() == Out1::mode_append);
            assert(out1_1.Size() == 31);
            assert(out1_1.MaximumSize() == Out1MaximumBuffer);
            assert(strncmp(*(out1_1.Filename()), fname, fname_size) == 0);
            assert(out1_1.Buffer().Size() == 0);
            assert(cout1_1.Buffer().Size() == 0);
            assert(strncmp(*(out1_1.Buffer()), "", 0) == 0);
            assert(strncmp(*(cout1_1.Buffer()), "", 0) == 0);
            assert(out1_1.IsGood() == true);
            assert(out1_1.IsBad() == false);
            assert(out1_1.GetBadCode() == Out1::StatusType::good);
            assert(out1_1.IsStandard() == false);

            auto size = out1_1.Print("abcdefghij\n");
            assert(size == 11);
            assert(out1_1.Mode() == Out1::mode_append);
            assert(out1_1.Size() == 42);
            assert(out1_1.MaximumSize() == Out1MaximumBuffer);
            assert(strncmp(*(out1_1.Filename()), fname, fname_size) == 0);
            assert(out1_1.Buffer().Size() == 11);
            assert(cout1_1.Buffer().Size() == 11);
            assert(strncmp(*(out1_1.Buffer()), "abcdefghij\n", 11) == 0);
            assert(strncmp(*(cout1_1.Buffer()), "abcdefghij\n", 11) == 0);
            assert(out1_1.IsGood() == true);
            assert(out1_1.IsBad() == false);
            assert(out1_1.GetBadCode() == Out1::StatusType::good);
            assert(out1_1.IsStandard() == false);

            size = out1_1.Print("%d,%c,%s,%2.3f\n", 404, (int)'1', "424", 34.445f);
            assert(size == 17);
            assert(out1_1.Mode() == Out1::mode_append);
            assert(out1_1.Size() == 59);
            assert(out1_1.MaximumSize() == Out1MaximumBuffer);
            assert(strncmp(*(out1_1.Filename()), fname, fname_size) == 0);
            assert(out1_1.Buffer().Size() == 17);
            assert(cout1_1.Buffer().Size() == 17);
            assert(strncmp(*(out1_1.Buffer()), "404,1,424,34.445\n", 17) == 0);
            assert(strncmp(*(cout1_1.Buffer()), "404,1,424,34.445\n", 17) == 0);
            assert(out1_1.IsGood() == true);
            assert(out1_1.IsBad() == false);
            assert(out1_1.GetBadCode() == Out1::StatusType::good);
            assert(out1_1.IsStandard() == false);

            size = out1_1.Puts("klmnopqrstuvwxy\n");
            assert(size == 16);
            assert(out1_1.Mode() == Out1::mode_append);
            assert(out1_1.Size() == 75);
            assert(out1_1.MaximumSize() == Out1MaximumBuffer);
            assert(strncmp(*(out1_1.Filename()), fname, fname_size) == 0);
            assert(out1_1.Buffer().Size() == 16);
            assert(cout1_1.Buffer().Size() == 16);
            assert(strncmp(*(out1_1.Buffer()), "klmnopqrstuvwxy\n", 16) == 0);
            assert(strncmp(*(cout1_1.Buffer()), "klmnopqrstuvwxy\n", 16) == 0);
            assert(out1_1.IsGood() == true);
            assert(out1_1.IsBad() == false);
            assert(out1_1.GetBadCode() == Out1::StatusType::good);
            assert(out1_1.IsStandard() == false);
        }
        
        assert(ReadFile(fname, "test\n123,4,567,89.248\n12345678\n"
            "abcdefghij\n404,1,424,34.445\nklmnopqrstuvwxy\n", 75) == true);

        //constructor with filename, append mode, and maximum size
        {
            Out1 out1_1(fname, Out1::mode_append, 16);
            const Out1& cout1_1 = out1_1;
            assert(out1_1.Mode() == Out1::mode_append);
            assert(out1_1.Size() == 0);
            assert(out1_1.MaximumSize() == 16);
            assert(strncmp(*(out1_1.Filename()), fname, fname_size) == 0);
            assert(out1_1.Buffer().Size() == 0);
            assert(cout1_1.Buffer().Size() == 0);
            assert(strncmp(*(out1_1.Buffer()), "", 0) == 0);
            assert(strncmp(*(cout1_1.Buffer()), "", 0) == 0);
            assert(out1_1.IsGood() == false);
            assert(out1_1.IsBad() == true);
            assert(out1_1.GetBadCode() == Out1::StatusType::size_overflow);
            assert(out1_1.IsStandard() == false);
        }

        //constructor with filename, write mode, and maximum size
        {
            Out1 out1_1(fname, Out1::mode_write, 16);
            const Out1& cout1_1 = out1_1;
            assert(out1_1.Mode() == Out1::mode_write);
            assert(out1_1.Size() == 0);
            assert(out1_1.MaximumSize() == 16);
            assert(strncmp(*(out1_1.Filename()), fname, fname_size) == 0);
            assert(out1_1.Buffer().Size() == 0);
            assert(cout1_1.Buffer().Size() == 0);
            assert(strncmp(*(out1_1.Buffer()), "", 0) == 0);
            assert(strncmp(*(cout1_1.Buffer()), "", 0) == 0);
            assert(out1_1.IsGood() == true);
            assert(out1_1.IsBad() == false);
            assert(out1_1.GetBadCode() == Out1::StatusType::good);
            assert(out1_1.IsStandard() == false);
        }

        fname_exist = CheckFileExist(fname);
        if (fname_exist)
        {
            auto ret_rem = remove(fname);
            assert(ret_rem == 0);
        }
    }
    
    {
        const char fname[] = "test_out_file2.txt";
        std::size_t fname_size = sizeof(fname)-1;
        
        auto fname_exist = CheckFileExist(fname);
        if (fname_exist)
        {
            auto ret_rem = remove(fname);
            assert(ret_rem == 0);
        }
        {
            Out1 out1_1(fname, Out1::mode_write, 16);
            const Out1& cout1_1 = out1_1;
            
            auto size = out1_1.Print("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 0);
            assert(out1_1.Mode() == Out1::mode_write);
            assert(out1_1.Size() == 0);
            assert(out1_1.MaximumSize() == 16);
            assert(strncmp(*(out1_1.Filename()), fname, fname_size) == 0);
            assert(out1_1.Buffer().Size() == 27);
            assert(cout1_1.Buffer().Size() == 27);
            assert(strncmp(*(out1_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(strncmp(*(cout1_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(out1_1.IsGood() == false);
            assert(out1_1.IsBad() == true);
            assert(out1_1.GetBadCode() == Out1::StatusType::size_overflow);
            assert(out1_1.IsStandard() == false);

        }
        {
            Out1 out1_1(fname, Out1::mode_write, 16);
            const Out1& cout1_1 = out1_1;

            auto size = out1_1.Puts("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 0);
            assert(out1_1.Mode() == Out1::mode_write);
            assert(out1_1.Size() == 0);
            assert(out1_1.MaximumSize() == 16);
            assert(strncmp(*(out1_1.Filename()), fname, fname_size) == 0);
            assert(out1_1.Buffer().Size() == 27);
            assert(cout1_1.Buffer().Size() == 27);
            assert(strncmp(*(out1_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(strncmp(*(cout1_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(out1_1.IsGood() == false);
            assert(out1_1.IsBad() == true);
            assert(out1_1.GetBadCode() == Out1::StatusType::size_overflow);
            assert(out1_1.IsStandard() == false);
        }

        {
            Out1 out1_1(fname, Out1::mode_append, 16);
            const Out1& cout1_1 = out1_1;
            
            auto size = out1_1.Print("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 0);
            assert(out1_1.Mode() == Out1::mode_append);
            assert(out1_1.Size() == 0);
            assert(out1_1.MaximumSize() == 16);
            assert(strncmp(*(out1_1.Filename()), fname, fname_size) == 0);
            assert(out1_1.Buffer().Size() == 27);
            assert(cout1_1.Buffer().Size() == 27);
            assert(strncmp(*(out1_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(strncmp(*(cout1_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(out1_1.IsGood() == false);
            assert(out1_1.IsBad() == true);
            assert(out1_1.GetBadCode() == Out1::StatusType::size_overflow);
            assert(out1_1.IsStandard() == false);

        }
        {
            Out1 out1_1(fname, Out1::mode_append, 16);
            const Out1& cout1_1 = out1_1;

            auto size = out1_1.Puts("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 0);
            assert(out1_1.Mode() == Out1::mode_append);
            assert(out1_1.Size() == 0);
            assert(out1_1.MaximumSize() == 16);
            assert(strncmp(*(out1_1.Filename()), fname, fname_size) == 0);
            assert(out1_1.Buffer().Size() == 27);
            assert(cout1_1.Buffer().Size() == 27);
            assert(strncmp(*(out1_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(strncmp(*(cout1_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(out1_1.IsGood() == false);
            assert(out1_1.IsBad() == true);
            assert(out1_1.GetBadCode() == Out1::StatusType::size_overflow);
            assert(out1_1.IsStandard() == false);
        }

        fname_exist = CheckFileExist(fname);
        if (fname_exist)
        {
            auto ret_rem = remove(fname);
            assert(ret_rem == 0);
        }
    }

    //struct Out2
    //Default constructor
    {
        Out2 out2_1;
        const Out2& cout2_1 = out2_1;
        auto size = out2_1.Print("test\n");
        assert(size == 5);
        assert(out2_1.Mode() == Out2::mode_undefined);
        assert(out2_1.Size() == 0);
        assert(out2_1.MaximumSize() == 0);
        assert(strncmp(*(out2_1.Filename()), "", 0) == 0);
        assert(out2_1.Buffer().Size() == 5);
        assert(cout2_1.Buffer().Size() == 5);
        assert(strncmp(*(out2_1.Buffer()), "test\n", 5) == 0);
        assert(strncmp(*(cout2_1.Buffer()), "test\n", 5) == 0);
        assert(out2_1.IsGood() == true);
        assert(out2_1.IsBad() == false);
        assert(out2_1.GetBadCode() == Out2::StatusType::good);
        assert(out2_1.IsStandard() == true);

        size = out2_1.Print("%d,%c,%s,%2.3f\n", 123, (int)'4', "567", 89.248f);
        assert(size == 17);
        assert(out2_1.Mode() == Out2::mode_undefined);
        assert(out2_1.Size() == 0);
        assert(out2_1.MaximumSize() == 0);
        assert(strncmp(*(out2_1.Filename()), "", 0) == 0);
        assert(out2_1.Buffer().Size() == 17);
        assert(cout2_1.Buffer().Size() == 17);
        assert(strncmp(*(out2_1.Buffer()), "123,4,567,89.248\n", 17) == 0);
        assert(strncmp(*(cout2_1.Buffer()), "123,4,567,89.248\n", 17) == 0);
        assert(out2_1.IsGood() == true);
        assert(out2_1.IsBad() == false);
        assert(out2_1.GetBadCode() == Out2::StatusType::good);
        assert(out2_1.IsStandard() == true);

        size = out2_1.Puts("12345678\n");
        assert(size == 9);
        assert(out2_1.Mode() == Out2::mode_undefined);
        assert(out2_1.Size() == 0);
        assert(out2_1.MaximumSize() == 0);
        assert(strncmp(*(out2_1.Filename()), "", 0) == 0);
        assert(out2_1.Buffer().Size() == 9);
        assert(cout2_1.Buffer().Size() == 9);
        assert(strncmp(*(out2_1.Buffer()), "12345678\n", 9) == 0);
        assert(strncmp(*(cout2_1.Buffer()), "12345678\n", 9) == 0);
        assert(out2_1.IsGood() == true);
        assert(out2_1.IsBad() == false);
        assert(out2_1.GetBadCode() == Out2::StatusType::good);
        assert(out2_1.IsStandard() == true);
    }
    
    {
        const char fname[] = "test_out_file3.txt";
        std::size_t fname_size = sizeof(fname)-1;

        auto fname_exist = CheckFileExist(fname);
        if (fname_exist)
        {
            auto ret_rem = remove(fname);
            assert(ret_rem == 0);
        }

        //constructor with filename and undefined mode
        {
            Out1 out1_1(fname, Out1::mode_undefined);
            const Out1& cout1_1 = out1_1;

            assert(out1_1.Mode() == Out1::mode_undefined);
            assert(out1_1.Size() == 0);
            assert(out1_1.MaximumSize() == Out1MaximumBuffer);
            assert(strncmp(*(out1_1.Filename()), fname, fname_size) == 0);
            assert(out1_1.Buffer().Size() == 0);
            assert(cout1_1.Buffer().Size() == 0);
            assert(strncmp(*(out1_1.Buffer()), "", 0) == 0);
            assert(strncmp(*(cout1_1.Buffer()), "", 0) == 0);
            assert(out1_1.IsGood() == false);
            assert(out1_1.IsBad() == true);
            assert(out1_1.GetBadCode() == Out1::StatusType::open_file_mode_undefined);
            assert(out1_1.IsStandard() == false);
        }

        // struct Out2
        //constructor with filename and write mode
        {
            Out2 out2_1(fname, Out2::mode_write);
            const Out2& cout2_1 = out2_1;

            auto size = out2_1.Print("test\n");
            assert(size == 5);
            assert(out2_1.Mode() == Out2::mode_write);
            assert(out2_1.Size() == 5);
            assert(out2_1.MaximumSize() == Out2MaximumBuffer);
            assert(strncmp(*(out2_1.Filename()), fname, fname_size) == 0);
            assert(out2_1.Buffer().Size() == 5);
            assert(cout2_1.Buffer().Size() == 5);
            assert(strncmp(*(out2_1.Buffer()), "test\n", 5) == 0);
            assert(strncmp(*(cout2_1.Buffer()), "test\n", 5) == 0);
            assert(out2_1.IsGood() == true);
            assert(out2_1.IsBad() == false);
            assert(out2_1.GetBadCode() == Out2::StatusType::good);
            assert(out2_1.IsStandard() == false);
            
            size = out2_1.Print("%d,%c,%s,%2.3f\n", 123, (int)'4', "567", 89.248f);
            assert(size == 17);
            assert(out2_1.Mode() == Out2::mode_write);
            assert(out2_1.Size() == 22);
            assert(out2_1.MaximumSize() == Out2MaximumBuffer);
            assert(strncmp(*(out2_1.Filename()), fname, fname_size) == 0);
            assert(out2_1.Buffer().Size() == 17);
            assert(cout2_1.Buffer().Size() == 17);
            assert(strncmp(*(out2_1.Buffer()), "123,4,567,89.248\n", 17) == 0);
            assert(strncmp(*(cout2_1.Buffer()), "123,4,567,89.248\n", 17) == 0);
            assert(out2_1.IsGood() == true);
            assert(out2_1.IsBad() == false);
            assert(out2_1.GetBadCode() == Out2::StatusType::good);
            assert(out2_1.IsStandard() == false);

            size = out2_1.Puts("12345678\n");
            assert(size == 9);
            assert(out2_1.Mode() == Out2::mode_write);
            assert(out2_1.Size() == 31);
            assert(out2_1.MaximumSize() == Out2MaximumBuffer);
            assert(strncmp(*(out2_1.Filename()), fname, fname_size) == 0);
            assert(out2_1.Buffer().Size() == 9);
            assert(cout2_1.Buffer().Size() == 9);
            assert(strncmp(*(out2_1.Buffer()), "12345678\n", 9) == 0);
            assert(strncmp(*(cout2_1.Buffer()), "12345678\n", 9) == 0);
            assert(out2_1.IsGood() == true);
            assert(out2_1.IsBad() == false);
            assert(out2_1.GetBadCode() == Out2::StatusType::good);
            assert(out2_1.IsStandard() == false);
        }
        assert(ReadFile(fname, "12345678\n", 9) == false);
        assert(ReadFile(fname, "test\n123,4,567,89.248\n12345678\n", 31) == true);

        //constructor with filename and append mode
        {
            Out2 out2_1(fname, Out2::mode_append);
            const Out2& cout2_1 = out2_1;

            assert(out2_1.Mode() == Out2::mode_append);
            assert(out2_1.Size() == 31);
            assert(out2_1.MaximumSize() == Out2MaximumBuffer);
            assert(strncmp(*(out2_1.Filename()), fname, fname_size) == 0);
            assert(out2_1.Buffer().Size() == 0);
            assert(cout2_1.Buffer().Size() == 0);
            assert(strncmp(*(out2_1.Buffer()), "", 0) == 0);
            assert(strncmp(*(cout2_1.Buffer()), "", 0) == 0);
            assert(out2_1.IsGood() == true);
            assert(out2_1.IsBad() == false);
            assert(out2_1.GetBadCode() == Out2::StatusType::good);
            assert(out2_1.IsStandard() == false);

            auto size = out2_1.Print("abcdefghij\n");
            assert(size == 11);
            assert(out2_1.Mode() == Out2::mode_append);
            assert(out2_1.Size() == 42);
            assert(out2_1.MaximumSize() == Out2MaximumBuffer);
            assert(strncmp(*(out2_1.Filename()), fname, fname_size) == 0);
            assert(out2_1.Buffer().Size() == 11);
            assert(cout2_1.Buffer().Size() == 11);
            assert(strncmp(*(out2_1.Buffer()), "abcdefghij\n", 11) == 0);
            assert(strncmp(*(cout2_1.Buffer()), "abcdefghij\n", 11) == 0);
            assert(out2_1.IsGood() == true);
            assert(out2_1.IsBad() == false);
            assert(out2_1.GetBadCode() == Out2::StatusType::good);
            assert(out2_1.IsStandard() == false);

            size = out2_1.Print("%d,%c,%s,%2.3f\n", 404, (int)'1', "424", 34.445f);
            assert(size == 17);
            assert(out2_1.Mode() == Out2::mode_append);
            assert(out2_1.Size() == 59);
            assert(out2_1.MaximumSize() == Out2MaximumBuffer);
            assert(strncmp(*(out2_1.Filename()), fname, fname_size) == 0);
            assert(out2_1.Buffer().Size() == 17);
            assert(cout2_1.Buffer().Size() == 17);
            assert(strncmp(*(out2_1.Buffer()), "404,1,424,34.445\n", 17) == 0);
            assert(strncmp(*(cout2_1.Buffer()), "404,1,424,34.445\n", 17) == 0);
            assert(out2_1.IsGood() == true);
            assert(out2_1.IsBad() == false);
            assert(out2_1.GetBadCode() == Out2::StatusType::good);
            assert(out2_1.IsStandard() == false);

            size = out2_1.Puts("klmnopqrstuvwxy\n");
            assert(size == 16);
            assert(out2_1.Mode() == Out2::mode_append);
            assert(out2_1.Size() == 75);
            assert(out2_1.MaximumSize() == Out2MaximumBuffer);
            assert(strncmp(*(out2_1.Filename()), fname, fname_size) == 0);
            assert(out2_1.Buffer().Size() == 16);
            assert(cout2_1.Buffer().Size() == 16);
            assert(strncmp(*(out2_1.Buffer()), "klmnopqrstuvwxy\n", 16) == 0);
            assert(strncmp(*(cout2_1.Buffer()), "klmnopqrstuvwxy\n", 16) == 0);
            assert(out2_1.IsGood() == true);
            assert(out2_1.IsBad() == false);
            assert(out2_1.GetBadCode() == Out2::StatusType::good);
            assert(out2_1.IsStandard() == false);
        }
        
        assert(ReadFile(fname, "test\n123,4,567,89.248\n12345678\n"
            "abcdefghij\n404,1,424,34.445\nklmnopqrstuvwxy\n", 75) == true);

        //constructor with filename, append mode, and maximum size
        {
            Out2 out2_1(fname, Out2::mode_append, 16);
            const Out2& cout2_1 = out2_1;
            assert(out2_1.Mode() == Out2::mode_append);
            assert(out2_1.Size() == 0);
            assert(out2_1.MaximumSize() == 16);
            assert(strncmp(*(out2_1.Filename()), fname, fname_size) == 0);
            assert(out2_1.Buffer().Size() == 0);
            assert(cout2_1.Buffer().Size() == 0);
            assert(strncmp(*(out2_1.Buffer()), "", 0) == 0);
            assert(strncmp(*(cout2_1.Buffer()), "", 0) == 0);
            assert(out2_1.IsGood() == false);
            assert(out2_1.IsBad() == true);
            assert(out2_1.GetBadCode() == Out2::StatusType::size_overflow);
            assert(out2_1.IsStandard() == false);
        }

        //constructor with filename, write mode, and maximum size
        {
            Out2 out2_1(fname, Out2::mode_write, 16);
            const Out2& cout2_1 = out2_1;
            assert(out2_1.Mode() == Out2::mode_write);
            assert(out2_1.Size() == 0);
            assert(out2_1.MaximumSize() == 16);
            assert(strncmp(*(out2_1.Filename()), fname, fname_size) == 0);
            assert(out2_1.Buffer().Size() == 0);
            assert(cout2_1.Buffer().Size() == 0);
            assert(strncmp(*(out2_1.Buffer()), "", 0) == 0);
            assert(strncmp(*(cout2_1.Buffer()), "", 0) == 0);
            assert(out2_1.IsGood() == true);
            assert(out2_1.IsBad() == false);
            assert(out2_1.GetBadCode() == Out2::StatusType::good);
            assert(out2_1.IsStandard() == false);
        }

        fname_exist = CheckFileExist(fname);
        if (fname_exist)
        {
            auto ret_rem = remove(fname);
            assert(ret_rem == 0);
        }

    }

    {
        const char fname[] = "test_out_file4.txt";
        std::size_t fname_size = sizeof(fname)-1;
        
        auto fname_exist = CheckFileExist(fname);
        if (fname_exist)
        {
            auto ret_rem = remove(fname);
            assert(ret_rem == 0);
        }
        {
            Out2 out2_1(fname, Out2::mode_write, 16);
            const Out2& cout2_1 = out2_1;
            
            auto size = out2_1.Print("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 0);
            assert(out2_1.Mode() == Out2::mode_write);
            assert(out2_1.Size() == 0);
            assert(out2_1.MaximumSize() == 16);
            assert(strncmp(*(out2_1.Filename()), fname, fname_size) == 0);
            assert(out2_1.Buffer().Size() == 27);
            assert(cout2_1.Buffer().Size() == 27);
            assert(strncmp(*(out2_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(strncmp(*(cout2_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(out2_1.IsGood() == false);
            assert(out2_1.IsBad() == true);
            assert(out2_1.GetBadCode() == Out2::StatusType::size_overflow);
            assert(out2_1.IsStandard() == false);

        }
        {
            Out2 out2_1(fname, Out2::mode_write, 16);
            const Out2& cout2_1 = out2_1;

            auto size = out2_1.Puts("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 0);
            assert(out2_1.Mode() == Out2::mode_write);
            assert(out2_1.Size() == 0);
            assert(out2_1.MaximumSize() == 16);
            assert(strncmp(*(out2_1.Filename()), fname, fname_size) == 0);
            assert(out2_1.Buffer().Size() == 27);
            assert(cout2_1.Buffer().Size() == 27);
            assert(strncmp(*(out2_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(strncmp(*(cout2_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(out2_1.IsGood() == false);
            assert(out2_1.IsBad() == true);
            assert(out2_1.GetBadCode() == Out2::StatusType::size_overflow);
            assert(out2_1.IsStandard() == false);
        }

        {
            Out2 out2_1(fname, Out2::mode_append, 16);
            const Out2& cout2_1 = out2_1;
            
            auto size = out2_1.Print("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 0);
            assert(out2_1.Mode() == Out2::mode_append);
            assert(out2_1.Size() == 0);
            assert(out2_1.MaximumSize() == 16);
            assert(strncmp(*(out2_1.Filename()), fname, fname_size) == 0);
            assert(out2_1.Buffer().Size() == 27);
            assert(cout2_1.Buffer().Size() == 27);
            assert(strncmp(*(out2_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(strncmp(*(cout2_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(out2_1.IsGood() == false);
            assert(out2_1.IsBad() == true);
            assert(out2_1.GetBadCode() == Out2::StatusType::size_overflow);
            assert(out2_1.IsStandard() == false);

        }
        {
            Out2 out2_1(fname, Out2::mode_append, 16);
            const Out2& cout2_1 = out2_1;

            auto size = out2_1.Puts("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 0);
            assert(out2_1.Mode() == Out2::mode_append);
            assert(out2_1.Size() == 0);
            assert(out2_1.MaximumSize() == 16);
            assert(strncmp(*(out2_1.Filename()), fname, fname_size) == 0);
            assert(out2_1.Buffer().Size() == 27);
            assert(cout2_1.Buffer().Size() == 27);
            assert(strncmp(*(out2_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(strncmp(*(cout2_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(out2_1.IsGood() == false);
            assert(out2_1.IsBad() == true);
            assert(out2_1.GetBadCode() == Out2::StatusType::size_overflow);
            assert(out2_1.IsStandard() == false);
        }

        fname_exist = CheckFileExist(fname);
        if (fname_exist)
        {
            auto ret_rem = remove(fname);
            assert(ret_rem == 0);
        }
    }
    
    // struct Out3
    //Default constructor
    {
        Out3 out3_1;
        const Out3& cout3_1 = out3_1;
        auto size = out3_1.Print("abcdefghij\n");
        assert(size == 11);
        assert(out3_1.Mode() == Out3::mode_undefined);
        assert(out3_1.Size() == 0);
        assert(out3_1.MaximumSize() == 0);
        assert(strncmp(*(out3_1.Filename()), "", 0) == 0);
        assert(out3_1.Buffer().Size() == 11);
        assert(cout3_1.Buffer().Size() == 11);
        assert(strncmp(*(out3_1.Buffer()), "abcdefghij\n", 11) == 0);
        assert(strncmp(*(cout3_1.Buffer()), "abcdefghij\n", 11) == 0);
        assert(out3_1.IsGood() == true);
        assert(out3_1.IsBad() == false);
        assert(out3_1.GetBadCode() == Out3::StatusType::good);
        assert(out3_1.IsStandard() == true);

        size = out3_1.Print("abcdefghijklmnopqrstuvwxyz\n");
        assert(size == 0);
        assert(out3_1.Mode() == Out3::mode_undefined);
        assert(out3_1.Size() == 0);
        assert(out3_1.MaximumSize() == 0);
        assert(strncmp(*(out3_1.Filename()), "", 0) == 0);
        assert(out3_1.Buffer().Size() == 0);
        assert(cout3_1.Buffer().Size() == 0);
        assert(strncmp(*(out3_1.Buffer()), "", 0) == 0);
        assert(strncmp(*(cout3_1.Buffer()), "", 0) == 0);
        assert(out3_1.IsGood() == false);
        assert(out3_1.IsBad() == true);
        assert(out3_1.GetBadCode() == Out3::StatusType::print_buffer_overflow);
        assert(out3_1.IsStandard() == true);
    }
    {
        Out3 out3_1;
        const Out3& cout3_1 = out3_1;

        auto size = out3_1.Puts("abcdefghij\n");
        assert(size == 11);
        assert(out3_1.Mode() == Out3::mode_undefined);
        assert(out3_1.Size() == 0);
        assert(out3_1.MaximumSize() == 0);
        assert(strncmp(*(out3_1.Filename()), "", 0) == 0);
        assert(out3_1.Buffer().Size() == 11);
        assert(cout3_1.Buffer().Size() == 11);
        assert(strncmp(*(out3_1.Buffer()), "abcdefghij\n", 11) == 0);
        assert(strncmp(*(cout3_1.Buffer()), "abcdefghij\n", 11) == 0);
        assert(out3_1.IsGood() == true);
        assert(out3_1.IsBad() == false);
        assert(out3_1.GetBadCode() == Out3::StatusType::good);
        assert(out3_1.IsStandard() == true);
        
        size = out3_1.Puts("abcdefghijklmnopqrstuvwxyz\n");
        assert(size == 0);
        assert(out3_1.Mode() == Out3::mode_undefined);
        assert(out3_1.Size() == 0);
        assert(out3_1.MaximumSize() == 0);
        assert(strncmp(*(out3_1.Filename()), "", 0) == 0);
        assert(out3_1.Buffer().Size() == 0);
        assert(cout3_1.Buffer().Size() == 0);
        assert(strncmp(*(out3_1.Buffer()), "", 0) == 0);
        assert(strncmp(*(cout3_1.Buffer()), "", 0) == 0);
        assert(out3_1.IsGood() == false);
        assert(out3_1.IsBad() == true);
        assert(out3_1.GetBadCode() == Out3::StatusType::puts_buffer_overflow);
        assert(out3_1.IsStandard() == true);
    }
    
    {
        const char fname[] = "test_out_file5.txt";
        std::size_t fname_size = sizeof(fname)-1;

        auto fname_exist = CheckFileExist(fname);
        if (fname_exist)
        {
            auto ret_rem = remove(fname);
            assert(ret_rem == 0);
        }

        //constructor with filename and undefined mode
        {
            Out3 out3_1(fname, Out3::mode_undefined);
            const Out3& cout3_1 = out3_1;

            assert(out3_1.Mode() == Out3::mode_undefined);
            assert(out3_1.Size() == 0);
            assert(out3_1.MaximumSize() == Out3MaximumBuffer);
            assert(strncmp(*(out3_1.Filename()), fname, fname_size) == 0);
            assert(out3_1.Buffer().Size() == 0);
            assert(cout3_1.Buffer().Size() == 0);
            assert(strncmp(*(out3_1.Buffer()), "", 0) == 0);
            assert(strncmp(*(cout3_1.Buffer()), "", 0) == 0);
            assert(out3_1.IsGood() == false);
            assert(out3_1.IsBad() == true);
            assert(out3_1.GetBadCode() == Out3::StatusType::open_file_mode_undefined);
            assert(out3_1.IsStandard() == false);
        }

        //constructor with filename and write mode
        {
            Out3 out3_1(fname, Out3::mode_write);
            const Out3& cout3_1 = out3_1;

            auto size = out3_1.Print("1234567\n");
            assert(size == 8);
            assert(out3_1.Mode() == Out3::mode_write);
            assert(out3_1.Size() == 8);
            assert(out3_1.MaximumSize() == Out3MaximumBuffer);
            assert(strncmp(*(out3_1.Filename()), fname, fname_size) == 0);
            assert(out3_1.Buffer().Size() == 8);
            assert(cout3_1.Buffer().Size() == 8);
            assert(strncmp(*(out3_1.Buffer()), "1234567\n", 8) == 0);
            assert(strncmp(*(cout3_1.Buffer()), "1234567\n", 8) == 0);
            assert(out3_1.IsGood() == true);
            assert(out3_1.IsBad() == false);
            assert(out3_1.GetBadCode() == Out3::StatusType::good);
            assert(out3_1.IsStandard() == false);
            
            size = out3_1.Print("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 0);
            assert(out3_1.Mode() == Out3::mode_write);
            assert(out3_1.Size() == 8);
            assert(out3_1.MaximumSize() == Out3MaximumBuffer);
            assert(strncmp(*(out3_1.Filename()), fname, fname_size) == 0);
            assert(out3_1.Buffer().Size() == 0);
            assert(cout3_1.Buffer().Size() == 0);
            assert(strncmp(*(out3_1.Buffer()), "", 0) == 0);
            assert(strncmp(*(cout3_1.Buffer()), "", 0) == 0);
            assert(out3_1.IsGood() == false);
            assert(out3_1.IsBad() == true);
            assert(out3_1.GetBadCode() == Out3::StatusType::print_buffer_overflow);
            assert(out3_1.IsStandard() == false);
        }
        assert(ReadFile(fname, "1234567\n", 8) == true);

        {
            Out3 out3_1(fname, Out3::mode_append);
            const Out3& cout3_1 = out3_1;

            assert(out3_1.Mode() == Out3::mode_append);
            assert(out3_1.Size() == 8);
            assert(out3_1.MaximumSize() == Out3MaximumBuffer);
            assert(strncmp(*(out3_1.Filename()), fname, fname_size) == 0);
            assert(out3_1.Buffer().Size() == 0);
            assert(cout3_1.Buffer().Size() == 0);
            assert(strncmp(*(out3_1.Buffer()), "", 0) == 0);
            assert(strncmp(*(cout3_1.Buffer()), "", 0) == 0);
            assert(out3_1.IsGood() == true);
            assert(out3_1.IsBad() == false);
            assert(out3_1.GetBadCode() == Out3::StatusType::good);
            assert(out3_1.IsStandard() == false);

            auto size = out3_1.Print("123456\n");
            assert(size == 7);
            assert(out3_1.Mode() == Out3::mode_append);
            assert(out3_1.Size() == 15);
            assert(out3_1.MaximumSize() == Out3MaximumBuffer);
            assert(strncmp(*(out3_1.Filename()), fname, fname_size) == 0);
            assert(out3_1.Buffer().Size() == 7);
            assert(cout3_1.Buffer().Size() == 7);
            assert(strncmp(*(out3_1.Buffer()), "123456\n", 7) == 0);
            assert(strncmp(*(cout3_1.Buffer()), "123456\n", 7) == 0);
            assert(out3_1.IsGood() == true);
            assert(out3_1.IsBad() == false);
            assert(out3_1.GetBadCode() == Out3::StatusType::good);
            assert(out3_1.IsStandard() == false);

            size = out3_1.Print("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 0);
            assert(out3_1.Mode() == Out3::mode_append);
            assert(out3_1.Size() == 15);
            assert(out3_1.MaximumSize() == Out3MaximumBuffer);
            assert(strncmp(*(out3_1.Filename()), fname, fname_size) == 0);
            assert(out3_1.Buffer().Size() == 0);
            assert(cout3_1.Buffer().Size() == 0);
            assert(strncmp(*(out3_1.Buffer()), "", 0) == 0);
            assert(strncmp(*(cout3_1.Buffer()), "", 0) == 0);
            assert(out3_1.IsGood() == false);
            assert(out3_1.IsBad() == true);
            assert(out3_1.GetBadCode() == Out3::StatusType::print_buffer_overflow);
            assert(out3_1.IsStandard() == false);
        }
        assert(ReadFile(fname, "1234567\n123456\n", 15) == true);

        {
            Out3 out3_1(fname, Out3::mode_write);
            const Out3& cout3_1 = out3_1;

            auto size = out3_1.Puts("1234567\n");
            assert(size == 8);
            assert(out3_1.Mode() == Out3::mode_write);
            assert(out3_1.Size() == 8);
            assert(out3_1.MaximumSize() == Out3MaximumBuffer);
            assert(strncmp(*(out3_1.Filename()), fname, fname_size) == 0);
            assert(out3_1.Buffer().Size() == 8);
            assert(cout3_1.Buffer().Size() == 8);
            assert(strncmp(*(out3_1.Buffer()), "1234567\n", 8) == 0);
            assert(strncmp(*(cout3_1.Buffer()), "1234567\n", 8) == 0);
            assert(out3_1.IsGood() == true);
            assert(out3_1.IsBad() == false);
            assert(out3_1.GetBadCode() == Out3::StatusType::good);
            assert(out3_1.IsStandard() == false);

            size = out3_1.Puts("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 0);
            assert(out3_1.Mode() == Out3::mode_write);
            assert(out3_1.Size() == 8);
            assert(out3_1.MaximumSize() == Out3MaximumBuffer);
            assert(strncmp(*(out3_1.Filename()), fname, fname_size) == 0);
            assert(out3_1.Buffer().Size() == 0);
            assert(cout3_1.Buffer().Size() == 0);
            assert(strncmp(*(out3_1.Buffer()), "", 0) == 0);
            assert(strncmp(*(cout3_1.Buffer()), "", 0) == 0);
            assert(out3_1.IsGood() == false);
            assert(out3_1.IsBad() == true);
            assert(out3_1.GetBadCode() == Out3::StatusType::puts_buffer_overflow);
            assert(out3_1.IsStandard() == false);
        }
        assert(ReadFile(fname, "1234567\n", 8) == true);

        {
            Out3 out3_1(fname, Out3::mode_append);
            const Out3& cout3_1 = out3_1;

            assert(out3_1.Mode() == Out3::mode_append);
            assert(out3_1.Size() == 8);
            assert(out3_1.MaximumSize() == Out3MaximumBuffer);
            assert(strncmp(*(out3_1.Filename()), fname, fname_size) == 0);
            assert(out3_1.Buffer().Size() == 0);
            assert(cout3_1.Buffer().Size() == 0);
            assert(strncmp(*(out3_1.Buffer()), "", 0) == 0);
            assert(strncmp(*(cout3_1.Buffer()), "", 0) == 0);
            assert(out3_1.IsGood() == true);
            assert(out3_1.IsBad() == false);
            assert(out3_1.GetBadCode() == Out3::StatusType::good);
            assert(out3_1.IsStandard() == false);

            auto size = out3_1.Puts("123456\n");
            assert(size == 7);
            assert(out3_1.Mode() == Out3::mode_append);
            assert(out3_1.Size() == 15);
            assert(out3_1.MaximumSize() == Out3MaximumBuffer);
            assert(strncmp(*(out3_1.Filename()), fname, fname_size) == 0);
            assert(out3_1.Buffer().Size() == 7);
            assert(cout3_1.Buffer().Size() == 7);
            assert(strncmp(*(out3_1.Buffer()), "123456\n", 7) == 0);
            assert(strncmp(*(cout3_1.Buffer()), "123456\n", 7) == 0);
            assert(out3_1.IsGood() == true);
            assert(out3_1.IsBad() == false);
            assert(out3_1.GetBadCode() == Out3::StatusType::good);
            assert(out3_1.IsStandard() == false);
            
            size = out3_1.Puts("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 0);
            assert(out3_1.Mode() == Out3::mode_append);
            assert(out3_1.Size() == 15);
            assert(out3_1.MaximumSize() == Out3MaximumBuffer);
            assert(strncmp(*(out3_1.Filename()), fname, fname_size) == 0);
            assert(out3_1.Buffer().Size() == 0);
            assert(cout3_1.Buffer().Size() == 0);
            assert(strncmp(*(out3_1.Buffer()), "", 0) == 0);
            assert(strncmp(*(cout3_1.Buffer()), "", 0) == 0);
            assert(out3_1.IsGood() == false);
            assert(out3_1.IsBad() == true);
            assert(out3_1.GetBadCode() == Out3::StatusType::puts_buffer_overflow);
            assert(out3_1.IsStandard() == false);
        }
        
        assert(ReadFile(fname, "1234567\n123456\n", 15) == true);

        //constructor with filename, append mode, and maximum size
        {
            Out3 out3_1(fname, Out3::mode_append, 15);
            const Out3& cout3_1 = out3_1;
            assert(out3_1.Mode() == Out3::mode_append);
            assert(out3_1.Size() == 0);
            assert(out3_1.MaximumSize() == 15);
            assert(strncmp(*(out3_1.Filename()), fname, fname_size) == 0);
            assert(out3_1.Buffer().Size() == 0);
            assert(cout3_1.Buffer().Size() == 0);
            assert(strncmp(*(out3_1.Buffer()), "", 0) == 0);
            assert(strncmp(*(cout3_1.Buffer()), "", 0) == 0);
            assert(out3_1.IsGood() == false);
            assert(out3_1.IsBad() == true);
            assert(out3_1.GetBadCode() == Out3::StatusType::size_overflow);
            assert(out3_1.IsStandard() == false);
        }

        //constructor with filename, write mode, and maximum size
        {
            Out3 out3_1(fname, Out3::mode_write, 15);
            const Out3& cout3_1 = out3_1;
            assert(out3_1.Mode() == Out3::mode_write);
            assert(out3_1.Size() == 0);
            assert(out3_1.MaximumSize() == 15);
            assert(strncmp(*(out3_1.Filename()), fname, fname_size) == 0);
            assert(out3_1.Buffer().Size() == 0);
            assert(cout3_1.Buffer().Size() == 0);
            assert(strncmp(*(out3_1.Buffer()), "", 0) == 0);
            assert(strncmp(*(cout3_1.Buffer()), "", 0) == 0);
            assert(out3_1.IsGood() == true);
            assert(out3_1.IsBad() == false);
            assert(out3_1.GetBadCode() == Out3::StatusType::good);
            assert(out3_1.IsStandard() == false);
        }

        fname_exist = CheckFileExist(fname);
        if (fname_exist)
        {
            auto ret_rem = remove(fname);
            assert(ret_rem == 0);
        }
    }
    
    {
        const char fname[] = "test_out_file6.txt";
        std::size_t fname_size = sizeof(fname)-1;
        
        auto fname_exist = CheckFileExist(fname);
        if (fname_exist)
        {
            auto ret_rem = remove(fname);
            assert(ret_rem == 0);
        }
        {
            Out3 out3_1(fname, Out3::mode_write, 16);
            const Out3& cout3_1 = out3_1;
            
            auto size = out3_1.Print("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 0);
            assert(out3_1.Mode() == Out3::mode_write);
            assert(out3_1.Size() == 0);
            assert(out3_1.MaximumSize() == 16);
            assert(strncmp(*(out3_1.Filename()), fname, fname_size) == 0);
            assert(out3_1.Buffer().Size() == 0);
            assert(cout3_1.Buffer().Size() == 0);
            assert(strncmp(*(out3_1.Buffer()), "", 0) == 0);
            assert(strncmp(*(cout3_1.Buffer()), "", 0) == 0);
            assert(out3_1.IsGood() == false);
            assert(out3_1.IsBad() == true);
            assert(out3_1.GetBadCode() == Out3::StatusType::print_buffer_overflow);
            assert(out3_1.IsStandard() == false);

        }
        {
            Out3 out3_1(fname, Out3::mode_write, 16);
            const Out3& cout3_1 = out3_1;

            auto size = out3_1.Puts("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 0);
            assert(out3_1.Mode() == Out3::mode_write);
            assert(out3_1.Size() == 0);
            assert(out3_1.MaximumSize() == 16);
            assert(strncmp(*(out3_1.Filename()), fname, fname_size) == 0);
            assert(out3_1.Buffer().Size() == 0);
            assert(cout3_1.Buffer().Size() == 0);
            assert(strncmp(*(out3_1.Buffer()), "", 0) == 0);
            assert(strncmp(*(cout3_1.Buffer()), "", 0) == 0);
            assert(out3_1.IsGood() == false);
            assert(out3_1.IsBad() == true);
            assert(out3_1.GetBadCode() == Out3::StatusType::puts_buffer_overflow);
            assert(out3_1.IsStandard() == false);
        }

        {
            Out3 out3_1(fname, Out3::mode_append, 16);
            const Out3& cout3_1 = out3_1;
            
            auto size = out3_1.Print("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 0);
            assert(out3_1.Mode() == Out3::mode_append);
            assert(out3_1.Size() == 0);
            assert(out3_1.MaximumSize() == 16);
            assert(strncmp(*(out3_1.Filename()), fname, fname_size) == 0);
            assert(out3_1.Buffer().Size() == 0);
            assert(cout3_1.Buffer().Size() == 0);
            assert(strncmp(*(out3_1.Buffer()), "", 0) == 0);
            assert(strncmp(*(cout3_1.Buffer()), "", 0) == 0);
            assert(out3_1.IsGood() == false);
            assert(out3_1.IsBad() == true);
            assert(out3_1.GetBadCode() == Out3::StatusType::print_buffer_overflow);
            assert(out3_1.IsStandard() == false);

        }
        {
            Out3 out3_1(fname, Out3::mode_append, 16);
            const Out3& cout3_1 = out3_1;

            auto size = out3_1.Puts("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 0);
            assert(out3_1.Mode() == Out3::mode_append);
            assert(out3_1.Size() == 0);
            assert(out3_1.MaximumSize() == 16);
            assert(strncmp(*(out3_1.Filename()), fname, fname_size) == 0);
            assert(out3_1.Buffer().Size() == 0);
            assert(cout3_1.Buffer().Size() == 0);
            assert(strncmp(*(out3_1.Buffer()), "", 0) == 0);
            assert(strncmp(*(cout3_1.Buffer()), "", 0) == 0);
            assert(out3_1.IsGood() == false);
            assert(out3_1.IsBad() == true);
            assert(out3_1.GetBadCode() == Out3::StatusType::puts_buffer_overflow);
            assert(out3_1.IsStandard() == false);
        }

        fname_exist = CheckFileExist(fname);
        if (fname_exist)
        {
            auto ret_rem = remove(fname);
            assert(ret_rem == 0);
        }
    }

    {
        const char fname[] = "test_out_file7.txt";
        const char fname_next[] = "test_out_file8.txt";
        std::size_t fname_size = sizeof(fname)-1;
        std::size_t fname_next_size = sizeof(fname_next)-1;
        
        auto fname_exist = CheckFileExist(fname);
        auto fname_next_exist = CheckFileExist(fname_next);
        if (fname_exist)
        {
            auto ret_rem = remove(fname);
            assert(ret_rem == 0);
        }
        if (fname_next_exist)
        {
            auto ret_rem = remove(fname_next);
            assert(ret_rem == 0);
        }
        
        {
            Out4 out4_1(fname, Out4::mode_write, 32, 
                [&](test::CString<char>, test::CString<char>& new_fn, 
                    typename Out4::ModeType& mod)
                {
                    new_fn = test::CString<char>(fname_next, fname_next_size);
                    mod = Out4::mode_write;
                    return true;
                });
            const Out4& cout4_1 = out4_1;
            
            auto size = out4_1.Print("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 27);
            assert(out4_1.Mode() == Out4::mode_write);
            assert(out4_1.Size() == 27);
            assert(out4_1.MaximumSize() == 32);
            assert(strncmp(*(out4_1.Filename()), fname, fname_size) == 0);
            assert(out4_1.Buffer().Size() == 27);
            assert(cout4_1.Buffer().Size() == 27);
            assert(strncmp(*(out4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(strncmp(*(cout4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(out4_1.IsGood() == true);
            assert(out4_1.IsBad() == false);
            assert(out4_1.GetBadCode() == Out4::StatusType::good);
            assert(out4_1.IsStandard() == false);
            
            size = out4_1.Print("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 27);
            assert(out4_1.Mode() == Out4::mode_write);
            assert(out4_1.Size() == 27);
            assert(out4_1.MaximumSize() == 32);
            assert(strncmp(*(out4_1.Filename()), fname_next, fname_next_size) == 0);
            assert(out4_1.Buffer().Size() == 27);
            assert(cout4_1.Buffer().Size() == 27);
            assert(strncmp(*(out4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(strncmp(*(cout4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(out4_1.IsGood() == true);
            assert(out4_1.IsBad() == false);
            assert(out4_1.GetBadCode() == Out4::StatusType::good);
            assert(out4_1.IsStandard() == false);

        }
        assert(ReadFile(fname, "abcdefghijklmnopqrstuvwxyz\n", 27) == true);
        assert(ReadFile(fname_next, "abcdefghijklmnopqrstuvwxyz\n", 27) == true);

        {
            Out4 out4_1(fname, Out4::mode_append, 64, 
                [&](test::CString<char>, test::CString<char>& new_fn, 
                    typename Out4::ModeType& mod)
                {
                    new_fn = test::CString<char>(fname_next, fname_next_size);
                    mod = Out4::mode_append;
                    return true;
                });
            const Out4& cout4_1 = out4_1;
            
            auto size = out4_1.Print("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 27);
            assert(out4_1.Mode() == Out4::mode_append);
            assert(out4_1.Size() == 54);
            assert(out4_1.MaximumSize() == 64);
            assert(strncmp(*(out4_1.Filename()), fname, fname_size) == 0);
            assert(out4_1.Buffer().Size() == 27);
            assert(cout4_1.Buffer().Size() == 27);
            assert(strncmp(*(out4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(strncmp(*(cout4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(out4_1.IsGood() == true);
            assert(out4_1.IsBad() == false);
            assert(out4_1.GetBadCode() == Out4::StatusType::good);
            assert(out4_1.IsStandard() == false);
            
            size = out4_1.Print("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 27);
            assert(out4_1.Mode() == Out4::mode_append);
            assert(out4_1.Size() == 54);
            assert(out4_1.MaximumSize() == 64);
            assert(strncmp(*(out4_1.Filename()), fname_next, fname_next_size) == 0);
            assert(out4_1.Buffer().Size() == 27);
            assert(cout4_1.Buffer().Size() == 27);
            assert(strncmp(*(out4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(strncmp(*(cout4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(out4_1.IsGood() == true);
            assert(out4_1.IsBad() == false);
            assert(out4_1.GetBadCode() == Out4::StatusType::good);
            assert(out4_1.IsStandard() == false);

        }
        assert(ReadFile(fname, "abcdefghijklmnopqrstuvwxyz\n"
            "abcdefghijklmnopqrstuvwxyz\n", 54) == true);
        assert(ReadFile(fname_next, "abcdefghijklmnopqrstuvwxyz\n"
            "abcdefghijklmnopqrstuvwxyz\n", 54) == true);
       
        {
            Out4 out4_1(fname, Out4::mode_write, 32, 
                [&](test::CString<char>, test::CString<char>& new_fn, 
                    typename Out4::ModeType& mod)
                {
                    new_fn = test::CString<char>(fname_next, fname_next_size);
                    mod = Out4::mode_write;
                    return true;
                });
            const Out4& cout4_1 = out4_1;
            
            auto size = out4_1.Puts("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 27);
            assert(out4_1.Mode() == Out4::mode_write);
            assert(out4_1.Size() == 27);
            assert(out4_1.MaximumSize() == 32);
            assert(strncmp(*(out4_1.Filename()), fname, fname_size) == 0);
            assert(out4_1.Buffer().Size() == 27);
            assert(cout4_1.Buffer().Size() == 27);
            assert(strncmp(*(out4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(strncmp(*(cout4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(out4_1.IsGood() == true);
            assert(out4_1.IsBad() == false);
            assert(out4_1.GetBadCode() == Out4::StatusType::good);
            assert(out4_1.IsStandard() == false);
            
            size = out4_1.Puts("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 27);
            assert(out4_1.Mode() == Out4::mode_write);
            assert(out4_1.Size() == 27);
            assert(out4_1.MaximumSize() == 32);
            assert(strncmp(*(out4_1.Filename()), fname_next, fname_next_size) == 0);
            assert(out4_1.Buffer().Size() == 27);
            assert(cout4_1.Buffer().Size() == 27);
            assert(strncmp(*(out4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(strncmp(*(cout4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(out4_1.IsGood() == true);
            assert(out4_1.IsBad() == false);
            assert(out4_1.GetBadCode() == Out4::StatusType::good);
            assert(out4_1.IsStandard() == false);

        }
        assert(ReadFile(fname, "abcdefghijklmnopqrstuvwxyz\n", 27) == true);
        assert(ReadFile(fname_next, "abcdefghijklmnopqrstuvwxyz\n", 27) == true);

        {
            Out4 out4_1(fname, Out4::mode_append, 64, 
                [&](test::CString<char>, test::CString<char>& new_fn, 
                    typename Out4::ModeType& mod)
                {
                    new_fn = test::CString<char>(fname_next, fname_next_size);
                    mod = Out4::mode_append;
                    return true;
                });
            const Out4& cout4_1 = out4_1;
            
            auto size = out4_1.Puts("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 27);
            assert(out4_1.Mode() == Out4::mode_append);
            assert(out4_1.Size() == 54);
            assert(out4_1.MaximumSize() == 64);
            assert(strncmp(*(out4_1.Filename()), fname, fname_size) == 0);
            assert(out4_1.Buffer().Size() == 27);
            assert(cout4_1.Buffer().Size() == 27);
            assert(strncmp(*(out4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(strncmp(*(cout4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(out4_1.IsGood() == true);
            assert(out4_1.IsBad() == false);
            assert(out4_1.GetBadCode() == Out4::StatusType::good);
            assert(out4_1.IsStandard() == false);
            
            size = out4_1.Puts("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 27);
            assert(out4_1.Mode() == Out4::mode_append);
            assert(out4_1.Size() == 54);
            assert(out4_1.MaximumSize() == 64);
            assert(strncmp(*(out4_1.Filename()), fname_next, fname_next_size) == 0);
            assert(out4_1.Buffer().Size() == 27);
            assert(cout4_1.Buffer().Size() == 27);
            assert(strncmp(*(out4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(strncmp(*(cout4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(out4_1.IsGood() == true);
            assert(out4_1.IsBad() == false);
            assert(out4_1.GetBadCode() == Out4::StatusType::good);
            assert(out4_1.IsStandard() == false);

        }
        assert(ReadFile(fname, "abcdefghijklmnopqrstuvwxyz\n"
            "abcdefghijklmnopqrstuvwxyz\n", 54) == true);
        assert(ReadFile(fname_next, "abcdefghijklmnopqrstuvwxyz\n"
            "abcdefghijklmnopqrstuvwxyz\n", 54) == true);

        {
            Out4 out4_1(fname, Out4::mode_append, 96, 
                [&](test::CString<char> old_fn, test::CString<char>& new_fn, 
                    typename Out4::ModeType& mod)
                {
                    new_fn = old_fn;
                    mod = Out4::mode_write;
                    return true;
                });
            const Out4& cout4_1 = out4_1;
            
            auto size = out4_1.Print("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 27);
            assert(out4_1.Mode() == Out4::mode_append);
            assert(out4_1.Size() == 81);
            assert(out4_1.MaximumSize() == 96);
            assert(strncmp(*(out4_1.Filename()), fname, fname_size) == 0);
            assert(out4_1.Buffer().Size() == 27);
            assert(cout4_1.Buffer().Size() == 27);
            assert(strncmp(*(out4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(strncmp(*(cout4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(out4_1.IsGood() == true);
            assert(out4_1.IsBad() == false);
            assert(out4_1.GetBadCode() == Out4::StatusType::good);
            assert(out4_1.IsStandard() == false);
            
            size = out4_1.Print("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 27);
            assert(out4_1.Mode() == Out4::mode_write);
            assert(out4_1.Size() == 27);
            assert(out4_1.MaximumSize() == 96);
            assert(strncmp(*(out4_1.Filename()), fname, fname_size) == 0);
            assert(out4_1.Buffer().Size() == 27);
            assert(cout4_1.Buffer().Size() == 27);
            assert(strncmp(*(out4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(strncmp(*(cout4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(out4_1.IsGood() == true);
            assert(out4_1.IsBad() == false);
            assert(out4_1.GetBadCode() == Out4::StatusType::good);
            assert(out4_1.IsStandard() == false);
        }
        
        assert(ReadFile(fname, "abcdefghijklmnopqrstuvwxyz\n", 27) == true);
        
        {
            Out4 out4_1(fname_next, Out4::mode_append, 96, 
                [&](test::CString<char> old_fn, test::CString<char>& new_fn, 
                    typename Out4::ModeType& mod)
                {
                    new_fn = old_fn;
                    mod = Out4::mode_write;
                    return true;
                });
            const Out4& cout4_1 = out4_1;
            
            auto size = out4_1.Print("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 27);
            assert(out4_1.Mode() == Out4::mode_append);
            assert(out4_1.Size() == 81);
            assert(out4_1.MaximumSize() == 96);
            assert(strncmp(*(out4_1.Filename()), fname_next, fname_next_size) == 0);
            assert(out4_1.Buffer().Size() == 27);
            assert(cout4_1.Buffer().Size() == 27);
            assert(strncmp(*(out4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(strncmp(*(cout4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(out4_1.IsGood() == true);
            assert(out4_1.IsBad() == false);
            assert(out4_1.GetBadCode() == Out4::StatusType::good);
            assert(out4_1.IsStandard() == false);
            
            size = out4_1.Print("abcdefghijklmnopqrstuvwxyz\n");
            assert(size == 27);
            assert(out4_1.Mode() == Out4::mode_write);
            assert(out4_1.Size() == 27);
            assert(out4_1.MaximumSize() == 96);
            assert(strncmp(*(out4_1.Filename()), fname_next, fname_next_size) == 0);
            assert(out4_1.Buffer().Size() == 27);
            assert(cout4_1.Buffer().Size() == 27);
            assert(strncmp(*(out4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(strncmp(*(cout4_1.Buffer()), "abcdefghijklmnopqrstuvwxyz\n", 27) == 0);
            assert(out4_1.IsGood() == true);
            assert(out4_1.IsBad() == false);
            assert(out4_1.GetBadCode() == Out4::StatusType::good);
            assert(out4_1.IsStandard() == false);
        }
        
        assert(ReadFile(fname_next, "abcdefghijklmnopqrstuvwxyz\n", 27) == true);

        fname_exist = CheckFileExist(fname);
        if (fname_exist)
        {
            auto ret_rem = remove(fname);
            assert(ret_rem == 0);
        }
        fname_next_exist = CheckFileExist(fname_next);
        if (fname_next_exist)
        {
            auto ret_rem = remove(fname_next);
            assert(ret_rem == 0);
        }
    }

    return 0;
}

bool CheckFileExist(const char * fname)
{
    FILE * f = nullptr;
#if (defined(_MSC_BUILD) && !defined(_CRT_SECURE_NO_WARNINGS))
    fopen_s(&f, fname, "r");
#else 
    f = fopen(fname, "r");
#endif 
    if (f)
    {
        fclose(f);
        return true;
    }
    return false;
}

bool ReadFile(const char * fname, const char * str, 
    const std::size_t& size)
{
    FILE * f = nullptr;
#if (defined(_MSC_BUILD) && !defined(_CRT_SECURE_NO_WARNINGS))
    fopen_s(&f, fname, "r");
#else 
    f = fopen(fname, "r");
#endif 
    if (f)
    {
        int ch = 0;
        std::size_t i = 0;
        do
        {
            if (i == size) break;
            ch = fgetc(f);
            if (ch != (int) str[i++]) break;
        } while (ch != EOF);
        fclose(f);
        return i == size;
    }
    return false;
}


