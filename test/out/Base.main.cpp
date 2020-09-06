#include "test/out/Base.h"

#include <cassert>

struct Out1 : test::out::Base<char>
{
    Out1() {}
    Out1(const char * f, const ModeType& m) :
        test::out::Base<char>(f, m) {}
    Out1(const char * f, const ModeType& m, const SizeType& s) :
        test::out::Base<char>(f, m, s) {}
    ~Out1() {}
    using test::out::Base<char>::VPrint;
    using test::out::Base<char>::Print;
    using test::out::Base<char>::Puts;
};
template<std::size_t N>
struct Out2 : test::out::Base<char, N>
{
    Out2() {}
    ~Out2() {}
    using test::out::Base<char, N>::VPrint;
    using test::out::Base<char, N>::Print;
    using test::out::Base<char, N>::Puts;
};

template<typename T>
std::size_t Print(T& out, const char * format, ...) 
    __ATTRIBUTE__((__format__ (__printf__, 2, 3)));
template<typename T, typename TT>
std::size_t Print(T& out, const TT& tag, const char * format, ...) 
    __ATTRIBUTE__((__format__ (__printf__, 3, 4)));

template<typename T>
std::size_t Print(T& out, const char * format, ...) 
{
    va_list args;
    va_start(args, format);
    const auto res = out.VPrint(format, args);
    va_end(args);
    return res;
}

template<typename T, typename TT>
std::size_t Print(T& out, const TT& tag, const char * format, ...) 
{
    va_list args;
    va_start(args, format);
    const auto res = out.VPrint(tag, format, args);
    va_end(args);
    return res;
}

bool CheckFileExist(const char * fname);
bool ReadFile(const char * fname, const char * str, 
    const std::size_t& size);

int main()
{
    {
        typedef Out1::StatusType StatusType;
        Out1 out1;
        {
            assert(Print(out1, "test : %d\n", 1) == 9);
            assert(out1.Print("test : %d\n", 2) == 9);
            assert(out1.Puts("test : 3\n") == 9);
            assert(out1.Puts("test : 4\n", 9) == 9);
            assert(out1.Puts(test::CString<char>("test : 5\n", 9)) == 9);
            assert(out1.Puts(test::CString<const char>("test : 6\n")) == 9);
            assert(out1.IsGood() == true);
            assert(out1.IsBad() == false);
            assert(out1.GetBadCode() == StatusType::good);
        }
    }
    {
        typedef typename Out1::StatusType StatusType;
        typedef typename Out1::TagCritType CritType;
        typedef typename Out1::TagDebugType DebugType;
        typedef typename Out1::TagErrorType ErrorType;
        typedef typename Out1::TagInfoType InfoType;
        typedef typename Out1::TagWarnType WarnType;
        Out1 out1;
        {
            assert(Print(out1, CritType{}, "test : %d", 1) == 8);
            assert(out1.Print(CritType{}, "test : %d", 2) == 8);
            assert(out1.Puts(CritType{}, "test : 3") == 8);
            assert(out1.Puts(CritType{}, "test : 4", 8) == 8);
            assert(out1.Puts(CritType{}, test::CString<char>("test : 5", 8)) == 8);
            assert(out1.Puts(CritType{}, test::CString<const char>("test : 6")) == 8);
            assert(out1.IsGood() == true);
            assert(out1.IsBad() == false);
            assert(out1.GetBadCode() == StatusType::good);
        }
        {
            assert(Print(out1, DebugType{}, "test : %d", 1) == 8);
            assert(out1.Print(DebugType{}, "test : %d", 2) == 8);
            assert(out1.Puts(DebugType{}, "test : 3") == 8);
            assert(out1.Puts(DebugType{}, "test : 4", 8) == 8);
            assert(out1.Puts(DebugType{}, test::CString<char>("test : 5", 8)) == 8);
            assert(out1.Puts(DebugType{}, test::CString<const char>("test : 6")) == 8);
            assert(out1.IsGood() == true);
            assert(out1.IsBad() == false);
            assert(out1.GetBadCode() == StatusType::good);
        }
        {
            assert(Print(out1, ErrorType{}, "test : %d", 1) == 8);
            assert(out1.Print(ErrorType{}, "test : %d", 2) == 8);
            assert(out1.Puts(ErrorType{}, "test : 3") == 8);
            assert(out1.Puts(ErrorType{}, "test : 4", 8) == 8);
            assert(out1.Puts(ErrorType{}, test::CString<char>("test : 5", 8)) == 8);
            assert(out1.Puts(ErrorType{}, test::CString<const char>("test : 6")) == 8);
            assert(out1.IsGood() == true);
            assert(out1.IsBad() == false);
            assert(out1.GetBadCode() == StatusType::good);
        }
        {
            assert(Print(out1, InfoType{}, "test : %d", 1) == 8);
            assert(out1.Print(InfoType{}, "test : %d", 2) == 8);
            assert(out1.Puts(InfoType{}, "test : 3") == 8);
            assert(out1.Puts(InfoType{}, "test : 4", 8) == 8);
            assert(out1.Puts(InfoType{}, test::CString<char>("test : 5", 8)) == 8);
            assert(out1.Puts(InfoType{}, test::CString<const char>("test : 6")) == 8);
            assert(out1.IsGood() == true);
            assert(out1.IsBad() == false);
            assert(out1.GetBadCode() == StatusType::good);
        }
        {
            assert(Print(out1, WarnType{}, "test : %d", 1) == 8);
            assert(out1.Print(WarnType{}, "test : %d", 2) == 8);
            assert(out1.Puts(WarnType{}, "test : 3") == 8);
            assert(out1.Puts(WarnType{}, "test : 4", 8) == 8);
            assert(out1.Puts(WarnType{}, test::CString<char>("test : 5", 8)) == 8);
            assert(out1.Puts(WarnType{}, test::CString<const char>("test : 6")) == 8);
            assert(out1.IsGood() == true);
            assert(out1.IsBad() == false);
            assert(out1.GetBadCode() == StatusType::good);
        }
    }
    {
        typedef typename Out1::StatusType StatusType;
        Out1 out1;
        {
            auto crit = out1.Crit();
            assert(Print(crit, "test%d,", 1) == 6);
            assert(crit.Print("test%d,", 2) == 6);
            assert(crit.Puts("test3,") == 6);
            assert(crit.Puts("test4,", 6) == 6);
            assert(crit.Puts(test::CString<char>("test5,", 6)) == 6);
            assert(crit.Puts(test::CString<const char>("test6")) == 5);
            assert(out1.IsGood() == true);
            assert(out1.IsBad() == false);
            assert(out1.GetBadCode() == StatusType::good);

            auto crit1 = out1.Log(test::out::tag::Crit{});
            assert(Print(crit1, "test%d,", 1) == 6);
            assert(crit1.Print("test%d,", 2) == 6);
            assert(crit1.Puts("test3,") == 6);
            assert(crit1.Puts("test4,", 6) == 6);
            assert(crit1.Puts(test::CString<char>("test5,", 6)) == 6);
            assert(crit1.Puts(test::CString<const char>("test6")) == 5);
            assert(out1.IsGood() == true);
            assert(out1.IsBad() == false);
            assert(out1.GetBadCode() == StatusType::good);
        }
        {
            auto debug = out1.Debug();
            assert(Print(debug, "test%d,", 1) == 6);
            assert(debug.Print("test%d,", 2) == 6);
            assert(debug.Puts("test3,") == 6);
            assert(debug.Puts("test4,", 6) == 6);
            assert(debug.Puts(test::CString<char>("test5,", 6)) == 6);
            assert(debug.Puts(test::CString<const char>("test6")) == 5);
            assert(out1.IsGood() == true);
            assert(out1.IsBad() == false);
            assert(out1.GetBadCode() == StatusType::good);

            auto debug1 = out1.Log(test::out::tag::Debug{});
            assert(Print(debug1, "test%d,", 1) == 6);
            assert(debug1.Print("test%d,", 2) == 6);
            assert(debug1.Puts("test3,") == 6);
            assert(debug1.Puts("test4,", 6) == 6);
            assert(debug1.Puts(test::CString<char>("test5,", 6)) == 6);
            assert(debug1.Puts(test::CString<const char>("test6")) == 5);
            assert(out1.IsGood() == true);
            assert(out1.IsBad() == false);
            assert(out1.GetBadCode() == StatusType::good);
        }
        {
            auto error = out1.Error();
            assert(Print(error, "test%d,", 1) == 6);
            assert(error.Print("test%d,", 2) == 6);
            assert(error.Puts("test3,") == 6);
            assert(error.Puts("test4,", 6) == 6);
            assert(error.Puts(test::CString<char>("test5,", 6)) == 6);
            assert(error.Puts(test::CString<const char>("test6")) == 5);
            assert(out1.IsGood() == true);
            assert(out1.IsBad() == false);
            assert(out1.GetBadCode() == StatusType::good);
            
            auto error1 = out1.Log(test::out::tag::Error{});
            assert(Print(error1, "test%d,", 1) == 6);
            assert(error1.Print("test%d,", 2) == 6);
            assert(error1.Puts("test3,") == 6);
            assert(error1.Puts("test4,", 6) == 6);
            assert(error1.Puts(test::CString<char>("test5,", 6)) == 6);
            assert(error1.Puts(test::CString<const char>("test6")) == 5);
            assert(out1.IsGood() == true);
            assert(out1.IsBad() == false);
            assert(out1.GetBadCode() == StatusType::good);
        }
        {
            auto info = out1.Info();
            assert(Print(info, "test%d,", 1) == 6);
            assert(info.Print("test%d,", 2) == 6);
            assert(info.Puts("test3,") == 6);
            assert(info.Puts("test4,", 6) == 6);
            assert(info.Puts(test::CString<char>("test5,", 6)) == 6);
            assert(info.Puts(test::CString<const char>("test6")) == 5);
            assert(out1.IsGood() == true);
            assert(out1.IsBad() == false);
            assert(out1.GetBadCode() == StatusType::good);

            auto info1 = out1.Log(test::out::tag::Info{});
            assert(Print(info1, "test%d,", 1) == 6);
            assert(info1.Print("test%d,", 2) == 6);
            assert(info1.Puts("test3,") == 6);
            assert(info1.Puts("test4,", 6) == 6);
            assert(info1.Puts(test::CString<char>("test5,", 6)) == 6);
            assert(info1.Puts(test::CString<const char>("test6")) == 5);
            assert(out1.IsGood() == true);
            assert(out1.IsBad() == false);
            assert(out1.GetBadCode() == StatusType::good);
        }
        {
            auto warn = out1.Warn();
            assert(Print(warn, "test%d,", 1) == 6);
            assert(warn.Print("test%d,", 2) == 6);
            assert(warn.Puts("test3,") == 6);
            assert(warn.Puts("test4,", 6) == 6);
            assert(warn.Puts(test::CString<char>("test5,", 6)) == 6);
            assert(warn.Puts(test::CString<const char>("test6")) == 5);
            assert(out1.IsGood() == true);
            assert(out1.IsBad() == false);
            assert(out1.GetBadCode() == StatusType::good);

            auto warn1 = out1.Log(test::out::tag::Warn{});
            assert(Print(warn1, "test%d,", 1) == 6);
            assert(warn1.Print("test%d,", 2) == 6);
            assert(warn1.Puts("test3,") == 6);
            assert(warn1.Puts("test4,", 6) == 6);
            assert(warn1.Puts(test::CString<char>("test5,", 6)) == 6);
            assert(warn1.Puts(test::CString<const char>("test6")) == 5);
            assert(out1.IsGood() == true);
            assert(out1.IsBad() == false);
            assert(out1.GetBadCode() == StatusType::good);
        }
    }
    {
        typedef typename Out1::StatusType StatusType;
        typedef typename Out1::TagDebugType DebugType;
        Out1 out1;
        {
            auto debug1 = out1.Debug();
            out1.Print(DebugType{}, "test-2");
            auto debug2 = out1.Debug();
            out1.Print(DebugType{}, "test-4");
            auto debug3 = out1.Log(DebugType{});
            out1.Print(DebugType{}, "test-6");
            debug1.Print("test-1");
            debug2.Print("test-3");
            debug3.Print("test-5");
        }
        assert(out1.IsGood() == true);
        assert(out1.IsBad() == false);
        assert(out1.GetBadCode() == StatusType::good);
    }
    
    {
        Out2<4> out2;
        typedef typename Out2<4>::StatusType StatusType;
        {
            auto d = out2.Debug();
            out2.Debug().Print("2");
            out2.Debug().Print("3");
            out2.Debug().Print("4");
            out2.Debug().Print("5");
            d.Print("1");
        }
        assert(out2.IsGood() == false);
        assert(out2.IsBad() == true);
        assert(out2.GetBadCode() == StatusType::queue_overflow);
    }

    {
        typedef typename Out1::FileType FileType;
        typedef typename Out1::StatusType StatusType;

        const char * fname = "test1.log";

        auto fname_exist = CheckFileExist(fname);
        if (fname_exist)
        {
            auto ret_rem = remove(fname);
            assert(ret_rem == 0);
        }
        {
            Out1 out1(fname, FileType::mode_write);
            {
                assert(Print(out1, "test : %d\n", 1) == 9);
                assert(out1.Print("test : %d\n", 2) == 9);
                assert(out1.Puts("test : 3\n") == 9);
                assert(out1.Puts("test : 4\n", 9) == 9);
                assert(out1.Puts(test::CString<char>("test : 5\n", 9)) == 9);
                assert(out1.Puts(test::CString<const char>("test : 6\n")) == 9);
                assert(out1.IsGood() == true);
                assert(out1.IsBad() == false);
                assert(out1.GetBadCode() == StatusType::good);
            }
        }
        
        assert(ReadFile(fname, "test : 1\ntest : 2\ntest : 3\ntest : 4\ntest : 5\n"
            "test : 6\n", 54) == true);
        
        fname_exist = CheckFileExist(fname);
        if (fname_exist)
        {
            auto ret_rem = remove(fname);
            assert(ret_rem == 0);
        }

    }
    {
        typedef typename Out1::FileType FileType;
        typedef typename Out1::StatusType StatusType;
        
        {
            const char * fname = "test2.log";
            auto fname_exist = CheckFileExist(fname);
            if (fname_exist)
            {
                auto ret_rem = remove(fname);
                assert(ret_rem == 0);
            }
            
            test::out::CString<char> out_cstr;
            {
                Out1 out1(fname, FileType::mode_write);
                {
                    auto crit = out1.Crit();
                    assert(Print(crit, "test%d,", 1) == 6);
                    assert(crit.Print("test%d,", 2) == 6);
                    assert(crit.Puts("test3,") == 6);
                    assert(crit.Puts("test4,", 6) == 6);
                    assert(crit.Puts(test::CString<char>("test5,", 6)) == 6);
                    assert(crit.Puts(test::CString<const char>("test6")) == 5);
                    assert(out1.IsGood() == true);
                    assert(out1.IsBad() == false);
                    assert(out1.GetBadCode() == StatusType::good);
                    crit.Output(out_cstr);

                    auto crit1 = out1.Log(test::out::tag::Crit());
                    assert(Print(crit1, "test%d,", 1) == 6);
                    assert(crit1.Print("test%d,", 2) == 6);
                    assert(crit1.Puts("test3,") == 6);
                    assert(crit1.Puts("test4,", 6) == 6);
                    assert(crit1.Puts(test::CString<char>("test5,", 6)) == 6);
                    assert(crit1.Puts(test::CString<const char>("test6")) == 5);
                    assert(out1.IsGood() == true);
                    assert(out1.IsBad() == false);
                    assert(out1.GetBadCode() == StatusType::good);
                    crit1.Output(out_cstr);
                }
                
            }
            auto cstr = out_cstr.Get();
            assert(ReadFile(fname, *cstr, cstr.Size()) == true);

            fname_exist = CheckFileExist(fname);
            if (fname_exist)
            {
                auto ret_rem = remove(fname);
                assert(ret_rem == 0);
            }
        }
        
        {
            const char * fname = "test3.log";
            auto fname_exist = CheckFileExist(fname);
            if (fname_exist)
            {
                auto ret_rem = remove(fname);
                assert(ret_rem == 0);
            }
            
            test::out::CString<char> out_cstr;
            {
                Out1 out1(fname, FileType::mode_write);
                {
                    auto debug = out1.Debug();
                    assert(Print(debug, "test%d,", 1) == 6);
                    assert(debug.Print("test%d,", 2) == 6);
                    assert(debug.Puts("test3,") == 6);
                    assert(debug.Puts("test4,", 6) == 6);
                    assert(debug.Puts(test::CString<char>("test5,", 6)) == 6);
                    assert(debug.Puts(test::CString<const char>("test6")) == 5);
                    assert(out1.IsGood() == true);
                    assert(out1.IsBad() == false);
                    assert(out1.GetBadCode() == StatusType::good);
                    debug.Output(out_cstr);

                    auto debug2 = out1.Log(test::out::tag::Debug{});
                    assert(Print(debug2, "test%d,", 1) == 6);
                    assert(debug2.Print("test%d,", 2) == 6);
                    assert(debug2.Puts("test3,") == 6);
                    assert(debug2.Puts("test4,", 6) == 6);
                    assert(debug2.Puts(test::CString<char>("test5,", 6)) == 6);
                    assert(debug2.Puts(test::CString<const char>("test6")) == 5);
                    assert(out1.IsGood() == true);
                    assert(out1.IsBad() == false);
                    assert(out1.GetBadCode() == StatusType::good);
                    debug2.Output(out_cstr);
                }
            }
            auto cstr = out_cstr.Get();
            assert(ReadFile(fname, *cstr, cstr.Size()) == true);

            fname_exist = CheckFileExist(fname);
            if (fname_exist)
            {
                auto ret_rem = remove(fname);
                assert(ret_rem == 0);
            }
        }
        
        {
            const char * fname = "test4.log";
            auto fname_exist = CheckFileExist(fname);
            if (fname_exist)
            {
                auto ret_rem = remove(fname);
                assert(ret_rem == 0);
            }
            
            test::out::CString<char> out_cstr;
            {
                Out1 out1(fname, FileType::mode_write);
                {
                    auto error = out1.Error();
                    assert(Print(error, "test%d,", 1) == 6);
                    assert(error.Print("test%d,", 2) == 6);
                    assert(error.Puts("test3,") == 6);
                    assert(error.Puts("test4,", 6) == 6);
                    assert(error.Puts(test::CString<char>("test5,", 6)) == 6);
                    assert(error.Puts(test::CString<const char>("test6")) == 5);
                    assert(out1.IsGood() == true);
                    assert(out1.IsBad() == false);
                    assert(out1.GetBadCode() == StatusType::good);
                    error.Output(out_cstr);

                    auto error1 = out1.Log(test::out::tag::Error{});
                    assert(Print(error1, "test%d,", 1) == 6);
                    assert(error1.Print("test%d,", 2) == 6);
                    assert(error1.Puts("test3,") == 6);
                    assert(error1.Puts("test4,", 6) == 6);
                    assert(error1.Puts(test::CString<char>("test5,", 6)) == 6);
                    assert(error1.Puts(test::CString<const char>("test6")) == 5);
                    assert(out1.IsGood() == true);
                    assert(out1.IsBad() == false);
                    assert(out1.GetBadCode() == StatusType::good);
                    error1.Output(out_cstr);
                }
            }
            auto cstr = out_cstr.Get();
            assert(ReadFile(fname, *cstr, cstr.Size()) == true);

            fname_exist = CheckFileExist(fname);
            if (fname_exist)
            {
                auto ret_rem = remove(fname);
                assert(ret_rem == 0);
            }
        }
        
        {
            const char * fname = "test5.log";
            auto fname_exist = CheckFileExist(fname);
            if (fname_exist)
            {
                auto ret_rem = remove(fname);
                assert(ret_rem == 0);
            }
            
            test::out::CString<char> out_cstr;
            {
                Out1 out1(fname, FileType::mode_write);
                {
                    auto info = out1.Info();
                    assert(Print(info, "test%d,", 1) == 6);
                    assert(info.Print("test%d,", 2) == 6);
                    assert(info.Puts("test3,") == 6);
                    assert(info.Puts("test4,", 6) == 6);
                    assert(info.Puts(test::CString<char>("test5,", 6)) == 6);
                    assert(info.Puts(test::CString<const char>("test6")) == 5);
                    assert(out1.IsGood() == true);
                    assert(out1.IsBad() == false);
                    assert(out1.GetBadCode() == StatusType::good);
                    info.Output(out_cstr);

                    auto info1 = out1.Log(test::out::tag::Info{});
                    assert(Print(info1, "test%d,", 1) == 6);
                    assert(info1.Print("test%d,", 2) == 6);
                    assert(info1.Puts("test3,") == 6);
                    assert(info1.Puts("test4,", 6) == 6);
                    assert(info1.Puts(test::CString<char>("test5,", 6)) == 6);
                    assert(info1.Puts(test::CString<const char>("test6")) == 5);
                    assert(out1.IsGood() == true);
                    assert(out1.IsBad() == false);
                    assert(out1.GetBadCode() == StatusType::good);
                    info1.Output(out_cstr);
                }
            }
            auto cstr = out_cstr.Get();
            assert(ReadFile(fname, *cstr, cstr.Size()) == true);

            fname_exist = CheckFileExist(fname);
            if (fname_exist)
            {
                auto ret_rem = remove(fname);
                assert(ret_rem == 0);
            }
        }
        
        {
            const char * fname = "test6.log";
            auto fname_exist = CheckFileExist(fname);
            if (fname_exist)
            {
                auto ret_rem = remove(fname);
                assert(ret_rem == 0);
            }
            
            test::out::CString<char> out_cstr;
            {
                Out1 out1(fname, FileType::mode_write);
                {
                    auto warn = out1.Warn();
                    assert(Print(warn, "test%d,", 1) == 6);
                    assert(warn.Print("test%d,", 2) == 6);
                    assert(warn.Puts("test3,") == 6);
                    assert(warn.Puts("test4,", 6) == 6);
                    assert(warn.Puts(test::CString<char>("test5,", 6)) == 6);
                    assert(warn.Puts(test::CString<const char>("test6")) == 5);
                    assert(out1.IsGood() == true);
                    assert(out1.IsBad() == false);
                    assert(out1.GetBadCode() == StatusType::good);
                    warn.Output(out_cstr);

                    auto warn1 = out1.Log(test::out::tag::Warn{});
                    assert(Print(warn1, "test%d,", 1) == 6);
                    assert(warn1.Print("test%d,", 2) == 6);
                    assert(warn1.Puts("test3,") == 6);
                    assert(warn1.Puts("test4,", 6) == 6);
                    assert(warn1.Puts(test::CString<char>("test5,", 6)) == 6);
                    assert(warn1.Puts(test::CString<const char>("test6")) == 5);
                    assert(out1.IsGood() == true);
                    assert(out1.IsBad() == false);
                    assert(out1.GetBadCode() == StatusType::good);
                    warn1.Output(out_cstr);
                }
            }
            auto cstr = out_cstr.Get();
            assert(ReadFile(fname, *cstr, cstr.Size()) == true);

            fname_exist = CheckFileExist(fname);
            if (fname_exist)
            {
                auto ret_rem = remove(fname);
                assert(ret_rem == 0);
            }
        }
    }

    {
        typedef typename Out1::FileType FileType;
        typedef typename Out1::StatusType StatusType;

        const char * fname = "test7.log";
        auto fname_exist = CheckFileExist(fname);
        if (fname_exist)
        {
            auto ret_rem = remove(fname);
            assert(ret_rem == 0);
        }
        
        test::out::CString<char> out_cstr;
        {
            Out1 out1(fname, FileType::mode_write, 16);
            {
                auto debug = out1.Debug();
                assert(Print(debug, "test%d,", 1) == 6);
                assert(debug.Print("test%d,", 2) == 6);
                assert(debug.Puts("test3,") == 6);
                assert(debug.Puts("test4,", 6) == 6);
                assert(debug.Puts(test::CString<char>("test5,", 6)) == 6);
                assert(debug.Puts(test::CString<const char>("test6")) == 5);
                debug.Output(out_cstr);
            }
            assert(out1.IsGood() == false);
            assert(out1.IsBad() == true);
            assert(out1.GetBadCode() == StatusType::task_execute_failed);
        }

        fname_exist = CheckFileExist(fname);
        if (fname_exist)
        {
            auto ret_rem = remove(fname);
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

