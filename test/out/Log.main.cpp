#include "test/out/Log.h"
#include "test/out/CString.h"
#include "test/out/log/tag/Crit.h"
#include "test/out/log/tag/Debug.h"
#include "test/out/log/tag/Error.h"
#include "test/out/log/tag/Info.h"
#include "test/out/log/tag/Warn.h"

#include <cassert>
#include <cstring>
#include <chrono>

static int count = 0;

struct Out : test::out::CString<char>
{
    Out()
    {
        count++;
    }
    ~Out()
    {
        count--;
    }
};

std::size_t Print(test::out::Log<char>& cstr, const char * format, ...) 
    __ATTRIBUTE__((__format__ (__printf__, 2, 3)));

std::size_t Print(test::out::Log<char>& log, const char * format, ...) 
{
    va_list args;
    va_start(args, format);
    const auto res = log.VPrint(format, args);
    va_end(args);
    return res;
}
bool OnBegin(test::out::Interface<char>& out, 
    std::chrono::time_point<std::chrono::system_clock> timestamp, 
    test::CString<char> tag)
{
    using namespace std::chrono;
    auto time = system_clock::to_time_t(timestamp);
    struct tm * timeinfo;
    timeinfo = std::localtime (&time);
    char * tmp = new char[64];
    const auto size = strftime(tmp, 64, "%F %r", timeinfo);
    if (size >= 64)
    {
        delete[] tmp;
        tmp = new char[size + 1];
        strftime(tmp, size + 1, "%F %r", timeinfo);
    }
    auto out_size = out.Puts(tmp, size);
    delete[] tmp;
    if (out_size == 0) return false;
    out_size = out.Print(" [%s] ", *tag);
    return out_size != 0;
}

bool OnEnd(test::out::Interface<char>& out,
    std::chrono::time_point<std::chrono::system_clock> timestamp,
    test::CString<char> tag)
{
    using namespace std::chrono;
    auto out_size = out.Print(" [%s] ", *tag);
    if (out_size == 0) return false;
    auto time = system_clock::to_time_t(timestamp);
    struct tm * timeinfo;
    timeinfo = std::localtime (&time);
    char * tmp = new char[64];
    const auto size = strftime(tmp, 64, "%F %r", timeinfo);
    if (size >= 64)
    {
        delete[] tmp;
        tmp = new char[size + 1];
        strftime(tmp, size + 1, "%F %r", timeinfo);
    }
    out_size = out.Puts(tmp, size);
    delete[] tmp;
    if (out_size == 0) return false;
    out_size = out.Print("\n");
    return out_size != 0;
}

void Deleter(test::out::Interface<char> * out)
{
    delete out;
}

int main()
{
    typedef test::out::Log<char> Log;
    typedef test::out::CString<char> OutCString;
    typedef test::CString<char> CString;
    typedef test::CString<const char> C_CString;

    {
        Log log1;
        OutCString out_cstr1;
        assert(strncmp(*(log1.GetTag()), "Undefined", 9) == 0);
        assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
        assert(log1.Print("%d", 1) == 1);
        assert(Print(log1, "%d", 23) == 2);
        assert(log1.Puts("4"));
        assert(log1.Puts("56", 2));
        assert(log1.Puts(CString("7")));
        assert(log1.Puts(C_CString("8")));
        assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
        assert(log1.GetOnBegin() == &Log::DefaultOnBegin);
        assert(log1.GetOnEnd() == &Log::DefaultOnEnd);
        assert(log1.IsGood() == true);
        assert(log1.IsBad() == false);
        assert(log1.IsEnd() == false);
        assert(log1.GetBadCode() == Log::StatusType::good);
        assert(log1.End() == false);

        OutCString out_cstr2;
        Log::DefaultOnBegin(out_cstr2, log1.GetTimestamp(), log1.GetTag());
        out_cstr2.Puts(log1.GetMessage());
        Log::DefaultOnEnd(out_cstr2, log1.GetTimestamp(), log1.GetTag());

        auto res = log1.Output(out_cstr1);
        assert(res == true);
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
    }

    {
        char debug_cstr[] = "debug";
        Log log1(debug_cstr);
        OutCString out_cstr1;
        
        assert(strncmp(*(log1.GetTag()), debug_cstr, 6) == 0);
        assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
        assert(log1.Print("%d", 1) == 1);
        assert(Print(log1, "%d", 23) == 2);
        assert(log1.Puts("4"));
        assert(log1.Puts("56", 2));
        assert(log1.Puts(CString("7")));
        assert(log1.Puts(C_CString("8")));
        assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
        assert(log1.GetOnBegin() == &Log::DefaultOnBegin);
        assert(log1.GetOnEnd() == &Log::DefaultOnEnd);
        assert(log1.IsGood() == true);
        assert(log1.IsBad() == false);
        assert(log1.IsEnd() == false);
        assert(log1.GetBadCode() == Log::StatusType::good);
        assert(log1.End() == false);

        OutCString out_cstr2;
        Log::DefaultOnBegin(out_cstr2, log1.GetTimestamp(), log1.GetTag());
        out_cstr2.Puts(log1.GetMessage());
        Log::DefaultOnEnd(out_cstr2, log1.GetTimestamp(), log1.GetTag());

        auto res = log1.Output(out_cstr1);
        assert(res == true);
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
    }
    
    {
        char debug_cstr[] = "debug";
        Log log1(debug_cstr, &OnBegin);
        OutCString out_cstr1;
        
        assert(strncmp(*(log1.GetTag()), debug_cstr, 6) == 0);
        assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
        assert(log1.Print("%d", 1) == 1);
        assert(Print(log1, "%d", 23) == 2);
        assert(log1.Puts("4"));
        assert(log1.Puts("56", 2));
        assert(log1.Puts(CString("7")));
        assert(log1.Puts(C_CString("8")));
        assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
        assert(log1.GetOnBegin() == &OnBegin);
        assert(log1.GetOnEnd() == &Log::DefaultOnEnd);
        assert(log1.IsGood() == true);
        assert(log1.IsBad() == false);
        assert(log1.IsEnd() == false);
        assert(log1.GetBadCode() == Log::StatusType::good);
        assert(log1.End() == false);

        OutCString out_cstr2;
        OnBegin(out_cstr2, log1.GetTimestamp(), log1.GetTag());
        out_cstr2.Puts(log1.GetMessage());
        Log::DefaultOnEnd(out_cstr2, log1.GetTimestamp(), log1.GetTag());

        auto res = log1.Output(out_cstr1);
        assert(res == true);
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
    }

    {
        char debug_cstr[] = "debug";
        Log log1(debug_cstr, &OnBegin, &OnEnd);
        OutCString out_cstr1;
        
        assert(strncmp(*(log1.GetTag()), debug_cstr, 6) == 0);
        assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
        assert(log1.Print("%d", 1) == 1);
        assert(Print(log1, "%d", 23) == 2);
        assert(log1.Puts("4"));
        assert(log1.Puts("56", 2));
        assert(log1.Puts(CString("7")));
        assert(log1.Puts(C_CString("8")));
        assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
        assert(log1.GetOnBegin() == &OnBegin);
        assert(log1.GetOnEnd() == &OnEnd);
        assert(log1.IsGood() == true);
        assert(log1.IsBad() == false);
        assert(log1.IsEnd() == false);
        assert(log1.GetBadCode() == Log::StatusType::good);
        assert(log1.End() == false);

        OutCString out_cstr2;
        OnBegin(out_cstr2, log1.GetTimestamp(), log1.GetTag());
        out_cstr2.Puts(log1.GetMessage());
        OnEnd(out_cstr2, log1.GetTimestamp(), log1.GetTag());

        auto res = log1.Output(out_cstr1);
        assert(res == true);
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
    }

    {
        char debug_cstr[] = "debug";
        Log log1(debug_cstr, nullptr, &OnEnd);
        OutCString out_cstr1;
        
        assert(strncmp(*(log1.GetTag()), debug_cstr, 6) == 0);
        assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
        assert(log1.Print("%d", 1) == 1);
        assert(Print(log1, "%d", 23) == 2);
        assert(log1.Puts("4"));
        assert(log1.Puts("56", 2));
        assert(log1.Puts(CString("7")));
        assert(log1.Puts(C_CString("8")));
        assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
        assert(log1.GetOnBegin() == &Log::DefaultOnBegin);
        assert(log1.GetOnEnd() == &OnEnd);
        assert(log1.IsGood() == true);
        assert(log1.IsBad() == false);
        assert(log1.IsEnd() == false);
        assert(log1.GetBadCode() == Log::StatusType::good);
        assert(log1.End() == false);

        OutCString out_cstr2;
        Log::DefaultOnBegin(out_cstr2, log1.GetTimestamp(), log1.GetTag());
        out_cstr2.Puts(log1.GetMessage());
        OnEnd(out_cstr2, log1.GetTimestamp(), log1.GetTag());

        auto res = log1.Output(out_cstr1);
        assert(res == true);
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
    }
    //
    
    {
        CString debug_cstr("debug", 5);
        Log log1(debug_cstr);
        OutCString out_cstr1;
        
        assert(strncmp(*(log1.GetTag()), *debug_cstr, 6) == 0);
        assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
        assert(log1.Print("%d", 1) == 1);
        assert(Print(log1, "%d", 23) == 2);
        assert(log1.Puts("4"));
        assert(log1.Puts("56", 2));
        assert(log1.Puts(CString("7")));
        assert(log1.Puts(C_CString("8")));
        assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
        assert(log1.GetOnBegin() == &Log::DefaultOnBegin);
        assert(log1.GetOnEnd() == &Log::DefaultOnEnd);
        assert(log1.IsGood() == true);
        assert(log1.IsBad() == false);
        assert(log1.IsEnd() == false);
        assert(log1.GetBadCode() == Log::StatusType::good);
        assert(log1.End() == false);

        OutCString out_cstr2;
        Log::DefaultOnBegin(out_cstr2, log1.GetTimestamp(), log1.GetTag());
        out_cstr2.Puts(log1.GetMessage());
        Log::DefaultOnEnd(out_cstr2, log1.GetTimestamp(), log1.GetTag());

        auto res = log1.Output(out_cstr1);
        assert(res == true);
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
    }
    
    {
        CString debug_cstr("debug", 5);
        Log log1(debug_cstr, &OnBegin);
        OutCString out_cstr1;
        
        assert(strncmp(*(log1.GetTag()), *debug_cstr, 6) == 0);
        assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
        assert(log1.Print("%d", 1) == 1);
        assert(Print(log1, "%d", 23) == 2);
        assert(log1.Puts("4"));
        assert(log1.Puts("56", 2));
        assert(log1.Puts(CString("7")));
        assert(log1.Puts(C_CString("8")));
        assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
        assert(log1.GetOnBegin() == &OnBegin);
        assert(log1.GetOnEnd() == &Log::DefaultOnEnd);
        assert(log1.IsGood() == true);
        assert(log1.IsBad() == false);
        assert(log1.IsEnd() == false);
        assert(log1.GetBadCode() == Log::StatusType::good);
        assert(log1.End() == false);

        OutCString out_cstr2;
        OnBegin(out_cstr2, log1.GetTimestamp(), log1.GetTag());
        out_cstr2.Puts(log1.GetMessage());
        Log::DefaultOnEnd(out_cstr2, log1.GetTimestamp(), log1.GetTag());

        auto res = log1.Output(out_cstr1);
        assert(res == true);
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
    }

    {
        CString debug_cstr("debug", 5);
        Log log1(debug_cstr, &OnBegin, &OnEnd);
        OutCString out_cstr1;
        
        assert(strncmp(*(log1.GetTag()), *debug_cstr, 6) == 0);
        assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
        assert(log1.Print("%d", 1) == 1);
        assert(Print(log1, "%d", 23) == 2);
        assert(log1.Puts("4"));
        assert(log1.Puts("56", 2));
        assert(log1.Puts(CString("7")));
        assert(log1.Puts(C_CString("8")));
        assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
        assert(log1.GetOnBegin() == &OnBegin);
        assert(log1.GetOnEnd() == &OnEnd);
        assert(log1.IsGood() == true);
        assert(log1.IsBad() == false);
        assert(log1.IsEnd() == false);
        assert(log1.GetBadCode() == Log::StatusType::good);
        assert(log1.End() == false);

        OutCString out_cstr2;
        OnBegin(out_cstr2, log1.GetTimestamp(), log1.GetTag());
        out_cstr2.Puts(log1.GetMessage());
        OnEnd(out_cstr2, log1.GetTimestamp(), log1.GetTag());

        auto res = log1.Output(out_cstr1);
        assert(res == true);
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
    }

    {
        CString debug_cstr("debug", 5);
        Log log1(debug_cstr, nullptr, &OnEnd);
        OutCString out_cstr1;
        
        assert(strncmp(*(log1.GetTag()), *debug_cstr, 6) == 0);
        assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
        assert(log1.Print("%d", 1) == 1);
        assert(Print(log1, "%d", 23) == 2);
        assert(log1.Puts("4"));
        assert(log1.Puts("56", 2));
        assert(log1.Puts(CString("7")));
        assert(log1.Puts(C_CString("8")));
        assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
        assert(log1.GetOnBegin() == &Log::DefaultOnBegin);
        assert(log1.GetOnEnd() == &OnEnd);
        assert(log1.IsGood() == true);
        assert(log1.IsBad() == false);
        assert(log1.IsEnd() == false);
        assert(log1.GetBadCode() == Log::StatusType::good);
        assert(log1.End() == false);

        OutCString out_cstr2;
        Log::DefaultOnBegin(out_cstr2, log1.GetTimestamp(), log1.GetTag());
        out_cstr2.Puts(log1.GetMessage());
        OnEnd(out_cstr2, log1.GetTimestamp(), log1.GetTag());

        auto res = log1.Output(out_cstr1);
        assert(res == true);
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
    }

    {
        OutCString out_cstr1_1;
        OutCString out_cstr1_2;
        {
            char debug_cstr[] = "debug";
            Log log1(&out_cstr1_1, debug_cstr);
            OutCString out_cstr1;
            
            assert(strncmp(*(log1.GetTag()), debug_cstr, 6) == 0);
            assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
            assert(log1.Print("%d", 1) == 1);
            assert(Print(log1, "%d", 23) == 2);
            assert(log1.Puts("4"));
            assert(log1.Puts("56", 2));
            assert(log1.Puts(CString("7")));
            assert(log1.Puts(C_CString("8")));
            assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
            assert(log1.GetOnBegin() == &Log::DefaultOnBegin);
            assert(log1.GetOnEnd() == &Log::DefaultOnEnd);
            assert(log1.IsGood() == true);
            assert(log1.IsBad() == false);
            assert(log1.IsEnd() == false);
            assert(log1.GetBadCode() == Log::StatusType::good);
            assert(log1.End() == true);
            assert(log1.IsEnd() == true);

            Log::DefaultOnBegin(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());
            out_cstr1_2.Puts(log1.GetMessage());
            Log::DefaultOnEnd(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());

            auto res = log1.Output(out_cstr1);
            assert(res == true);
            assert(strncmp(*(out_cstr1.Get()), *(out_cstr1_2.Get()), 
                out_cstr1_2.Size()) == 0);
            
            res = log1.End();
            assert(res == false);

            assert(strncmp(*(out_cstr1_1.Get()), *(out_cstr1_2.Get()), 
                out_cstr1_2.Size()) == 0);
        }
        assert(strncmp(*(out_cstr1_1.Get()), *(out_cstr1_2.Get()), 
            out_cstr1_2.Size()) == 0);
    }
    {
        OutCString out_cstr1_1;
        OutCString out_cstr1_2;
        {
            char debug_cstr[] = "debug";
            Log log1(&out_cstr1_1, debug_cstr, &OnBegin);
            OutCString out_cstr1;
            
            assert(strncmp(*(log1.GetTag()), debug_cstr, 6) == 0);
            assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
            assert(log1.Print("%d", 1) == 1);
            assert(Print(log1, "%d", 23) == 2);
            assert(log1.Puts("4"));
            assert(log1.Puts("56", 2));
            assert(log1.Puts(CString("7")));
            assert(log1.Puts(C_CString("8")));
            assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
            assert(log1.GetOnBegin() == &OnBegin);
            assert(log1.GetOnEnd() == &Log::DefaultOnEnd);
            assert(log1.IsGood() == true);
            assert(log1.IsBad() == false);
            assert(log1.IsEnd() == false);
            assert(log1.GetBadCode() == Log::StatusType::good);

            OnBegin(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());
            out_cstr1_2.Puts(log1.GetMessage());
            Log::DefaultOnEnd(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());

            auto res = log1.Output(out_cstr1);
            assert(res == true);
            assert(strncmp(*(out_cstr1.Get()), *(out_cstr1_2.Get()), 
                out_cstr1_2.Size()) == 0);
        }
        assert(strncmp(*(out_cstr1_1.Get()), *(out_cstr1_2.Get()), 
            out_cstr1_2.Size()) == 0);
    }
    
    {
        OutCString out_cstr1_1;
        OutCString out_cstr1_2;
        {
            char debug_cstr[] = "debug";
            Log log1(&out_cstr1_1, debug_cstr, &OnBegin, &OnEnd);
            OutCString out_cstr1;
            
            assert(strncmp(*(log1.GetTag()), debug_cstr, 6) == 0);
            assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
            assert(log1.Print("%d", 1) == 1);
            assert(Print(log1, "%d", 23) == 2);
            assert(log1.Puts("4"));
            assert(log1.Puts("56", 2));
            assert(log1.Puts(CString("7")));
            assert(log1.Puts(C_CString("8")));
            assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
            assert(log1.GetOnBegin() == &OnBegin);
            assert(log1.GetOnEnd() == &OnEnd);
            assert(log1.IsGood() == true);
            assert(log1.IsBad() == false);
            assert(log1.IsEnd() == false);
            assert(log1.GetBadCode() == Log::StatusType::good);

            OnBegin(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());
            out_cstr1_2.Puts(log1.GetMessage());
            OnEnd(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());

            auto res = log1.Output(out_cstr1);
            assert(res == true);
            assert(strncmp(*(out_cstr1.Get()), *(out_cstr1_2.Get()), 
                out_cstr1_2.Size()) == 0);
        }
        assert(strncmp(*(out_cstr1_1.Get()), *(out_cstr1_2.Get()), 
            out_cstr1_2.Size()) == 0);
    }
    
    {
        OutCString out_cstr1_1;
        OutCString out_cstr1_2;
        {
            char debug_cstr[] = "debug";
            Log log1(&out_cstr1_1, debug_cstr, nullptr, &OnEnd);
            OutCString out_cstr1;
            
            assert(strncmp(*(log1.GetTag()), debug_cstr, 6) == 0);
            assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
            assert(log1.Print("%d", 1) == 1);
            assert(Print(log1, "%d", 23) == 2);
            assert(log1.Puts("4"));
            assert(log1.Puts("56", 2));
            assert(log1.Puts(CString("7")));
            assert(log1.Puts(C_CString("8")));
            assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
            assert(log1.GetOnBegin() == &Log::DefaultOnBegin);
            assert(log1.GetOnEnd() == &OnEnd);
            assert(log1.IsGood() == true);
            assert(log1.IsBad() == false);
            assert(log1.IsEnd() == false);
            assert(log1.GetBadCode() == Log::StatusType::good);

            Log::DefaultOnBegin(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());
            out_cstr1_2.Puts(log1.GetMessage());
            OnEnd(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());

            auto res = log1.Output(out_cstr1);
            assert(res == true);
            assert(strncmp(*(out_cstr1.Get()), *(out_cstr1_2.Get()), 
                out_cstr1_2.Size()) == 0);
        }
        assert(strncmp(*(out_cstr1_1.Get()), *(out_cstr1_2.Get()), 
            out_cstr1_2.Size()) == 0);
    }
    //
    {
        OutCString out_cstr1_1;
        OutCString out_cstr1_2;
        {
            CString debug_cstr("debug", 5);
            Log log1(&out_cstr1_1, debug_cstr);
            OutCString out_cstr1;
            
            assert(strncmp(*(log1.GetTag()), *debug_cstr, 6) == 0);
            assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
            assert(log1.Print("%d", 1) == 1);
            assert(Print(log1, "%d", 23) == 2);
            assert(log1.Puts("4"));
            assert(log1.Puts("56", 2));
            assert(log1.Puts(CString("7")));
            assert(log1.Puts(C_CString("8")));
            assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
            assert(log1.GetOnBegin() == &Log::DefaultOnBegin);
            assert(log1.GetOnEnd() == &Log::DefaultOnEnd);
            assert(log1.IsGood() == true);
            assert(log1.IsBad() == false);
            assert(log1.IsEnd() == false);
            assert(log1.GetBadCode() == Log::StatusType::good);
            assert(log1.End() == true);
            assert(log1.IsEnd() == true);

            Log::DefaultOnBegin(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());
            out_cstr1_2.Puts(log1.GetMessage());
            Log::DefaultOnEnd(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());

            auto res = log1.Output(out_cstr1);
            assert(res == true);
            assert(strncmp(*(out_cstr1.Get()), *(out_cstr1_2.Get()), 
                out_cstr1_2.Size()) == 0);
            
            res = log1.End();
            assert(res == false);

            assert(strncmp(*(out_cstr1_1.Get()), *(out_cstr1_2.Get()), 
                out_cstr1_2.Size()) == 0);
        }
        assert(strncmp(*(out_cstr1_1.Get()), *(out_cstr1_2.Get()), 
            out_cstr1_2.Size()) == 0);
    }
    {
        OutCString out_cstr1_1;
        OutCString out_cstr1_2;
        {
            CString debug_cstr("debug", 5);
            Log log1(&out_cstr1_1, debug_cstr, &OnBegin);
            OutCString out_cstr1;
            
            assert(strncmp(*(log1.GetTag()), *debug_cstr, 6) == 0);
            assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
            assert(log1.Print("%d", 1) == 1);
            assert(Print(log1, "%d", 23) == 2);
            assert(log1.Puts("4"));
            assert(log1.Puts("56", 2));
            assert(log1.Puts(CString("7")));
            assert(log1.Puts(C_CString("8")));
            assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
            assert(log1.GetOnBegin() == &OnBegin);
            assert(log1.GetOnEnd() == &Log::DefaultOnEnd);
            assert(log1.IsGood() == true);
            assert(log1.IsBad() == false);
            assert(log1.IsEnd() == false);
            assert(log1.GetBadCode() == Log::StatusType::good);

            OnBegin(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());
            out_cstr1_2.Puts(log1.GetMessage());
            Log::DefaultOnEnd(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());

            auto res = log1.Output(out_cstr1);
            assert(res == true);
            assert(strncmp(*(out_cstr1.Get()), *(out_cstr1_2.Get()), 
                out_cstr1_2.Size()) == 0);
        }
        assert(strncmp(*(out_cstr1_1.Get()), *(out_cstr1_2.Get()), 
            out_cstr1_2.Size()) == 0);
    }
    
    {
        OutCString out_cstr1_1;
        OutCString out_cstr1_2;
        {
            CString debug_cstr("debug", 5);
            Log log1(&out_cstr1_1, debug_cstr, &OnBegin, &OnEnd);
            OutCString out_cstr1;
            
            assert(strncmp(*(log1.GetTag()), *debug_cstr, 6) == 0);
            assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
            assert(log1.Print("%d", 1) == 1);
            assert(Print(log1, "%d", 23) == 2);
            assert(log1.Puts("4"));
            assert(log1.Puts("56", 2));
            assert(log1.Puts(CString("7")));
            assert(log1.Puts(C_CString("8")));
            assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
            assert(log1.GetOnBegin() == &OnBegin);
            assert(log1.GetOnEnd() == &OnEnd);
            assert(log1.IsGood() == true);
            assert(log1.IsBad() == false);
            assert(log1.IsEnd() == false);
            assert(log1.GetBadCode() == Log::StatusType::good);

            OnBegin(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());
            out_cstr1_2.Puts(log1.GetMessage());
            OnEnd(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());

            auto res = log1.Output(out_cstr1);
            assert(res == true);
            assert(strncmp(*(out_cstr1.Get()), *(out_cstr1_2.Get()), 
                out_cstr1_2.Size()) == 0);
        }
        assert(strncmp(*(out_cstr1_1.Get()), *(out_cstr1_2.Get()), 
            out_cstr1_2.Size()) == 0);
    }
    
    {
        OutCString out_cstr1_1;
        OutCString out_cstr1_2;
        {
            CString debug_cstr("debug", 5);
            Log log1(&out_cstr1_1, debug_cstr, nullptr, &OnEnd);
            OutCString out_cstr1;
            
            assert(strncmp(*(log1.GetTag()), *debug_cstr, 6) == 0);
            assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
            assert(log1.Print("%d", 1) == 1);
            assert(Print(log1, "%d", 23) == 2);
            assert(log1.Puts("4"));
            assert(log1.Puts("56", 2));
            assert(log1.Puts(CString("7")));
            assert(log1.Puts(C_CString("8")));
            assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
            assert(log1.GetOnBegin() == &Log::DefaultOnBegin);
            assert(log1.GetOnEnd() == &OnEnd);
            assert(log1.IsGood() == true);
            assert(log1.IsBad() == false);
            assert(log1.IsEnd() == false);
            assert(log1.GetBadCode() == Log::StatusType::good);

            Log::DefaultOnBegin(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());
            out_cstr1_2.Puts(log1.GetMessage());
            OnEnd(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());

            auto res = log1.Output(out_cstr1);
            assert(res == true);
            assert(strncmp(*(out_cstr1.Get()), *(out_cstr1_2.Get()), 
                out_cstr1_2.Size()) == 0);
        }
        assert(strncmp(*(out_cstr1_1.Get()), *(out_cstr1_2.Get()), 
            out_cstr1_2.Size()) == 0);
    }
    
    {
        char debug_cstr[] = "debug";
        Log log1(new Out(), &Deleter, debug_cstr);
        OutCString out_cstr1;
        
        assert(strncmp(*(log1.GetTag()), debug_cstr, 6) == 0);
        assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
        assert(log1.Print("%d", 1) == 1);
        assert(Print(log1, "%d", 23) == 2);
        assert(log1.Puts("4"));
        assert(log1.Puts("56", 2));
        assert(log1.Puts(CString("7")));
        assert(log1.Puts(C_CString("8")));
        assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
        assert(log1.GetOnBegin() == &Log::DefaultOnBegin);
        assert(log1.GetOnEnd() == &Log::DefaultOnEnd);
        assert(log1.IsGood() == true);
        assert(log1.IsBad() == false);
        assert(log1.IsEnd() == false);
        assert(log1.GetBadCode() == Log::StatusType::good);

        OutCString out_cstr1_2;
        Log::DefaultOnBegin(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());
        out_cstr1_2.Puts(log1.GetMessage());
        Log::DefaultOnEnd(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());

        auto res = log1.Output(out_cstr1);
        assert(res == true);
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr1_2.Get()), 
            out_cstr1_2.Size()) == 0);
    }
    {
        char debug_cstr[] = "debug";
        Log log1(new Out(), &Deleter, debug_cstr, &OnBegin);
        OutCString out_cstr1;
        
        assert(strncmp(*(log1.GetTag()), debug_cstr, 6) == 0);
        assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
        assert(log1.Print("%d", 1) == 1);
        assert(Print(log1, "%d", 23) == 2);
        assert(log1.Puts("4"));
        assert(log1.Puts("56", 2));
        assert(log1.Puts(CString("7")));
        assert(log1.Puts(C_CString("8")));
        assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
        assert(log1.GetOnBegin() == &OnBegin);
        assert(log1.GetOnEnd() == &Log::DefaultOnEnd);
        assert(log1.IsGood() == true);
        assert(log1.IsBad() == false);
        assert(log1.IsEnd() == false);
        assert(log1.GetBadCode() == Log::StatusType::good);

        OutCString out_cstr1_2;
        OnBegin(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());
        out_cstr1_2.Puts(log1.GetMessage());
        Log::DefaultOnEnd(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());

        auto res = log1.Output(out_cstr1);
        assert(res == true);
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr1_2.Get()), 
            out_cstr1_2.Size()) == 0);
    }
    
    {
        char debug_cstr[] = "debug";
        Log log1(new Out(), &Deleter, debug_cstr, &OnBegin, &OnEnd);
        OutCString out_cstr1;
        
        assert(strncmp(*(log1.GetTag()), debug_cstr, 6) == 0);
        assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
        assert(log1.Print("%d", 1) == 1);
        assert(Print(log1, "%d", 23) == 2);
        assert(log1.Puts("4"));
        assert(log1.Puts("56", 2));
        assert(log1.Puts(CString("7")));
        assert(log1.Puts(C_CString("8")));
        assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
        assert(log1.GetOnBegin() == &OnBegin);
        assert(log1.GetOnEnd() == &OnEnd);
        assert(log1.IsGood() == true);
        assert(log1.IsBad() == false);
        assert(log1.IsEnd() == false);
        assert(log1.GetBadCode() == Log::StatusType::good);

        OutCString out_cstr1_2;
        OnBegin(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());
        out_cstr1_2.Puts(log1.GetMessage());
        OnEnd(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());

        auto res = log1.Output(out_cstr1);
        assert(res == true);
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr1_2.Get()), 
            out_cstr1_2.Size()) == 0);
    }
    
    {
        char debug_cstr[] = "debug";
        Log log1(new Out(), &Deleter, debug_cstr, nullptr, &OnEnd);
        OutCString out_cstr1;
        
        assert(strncmp(*(log1.GetTag()), debug_cstr, 6) == 0);
        assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
        assert(log1.Print("%d", 1) == 1);
        assert(Print(log1, "%d", 23) == 2);
        assert(log1.Puts("4"));
        assert(log1.Puts("56", 2));
        assert(log1.Puts(CString("7")));
        assert(log1.Puts(C_CString("8")));
        assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
        assert(log1.GetOnBegin() == &Log::DefaultOnBegin);
        assert(log1.GetOnEnd() == &OnEnd);
        assert(log1.IsGood() == true);
        assert(log1.IsBad() == false);
        assert(log1.IsEnd() == false);
        assert(log1.GetBadCode() == Log::StatusType::good);

        OutCString out_cstr1_2;
        Log::DefaultOnBegin(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());
        out_cstr1_2.Puts(log1.GetMessage());
        OnEnd(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());

        auto res = log1.Output(out_cstr1);
        assert(res == true);
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr1_2.Get()), 
            out_cstr1_2.Size()) == 0);
    }
    
    {
        CString debug_cstr("debug", 5);
        Log log1(new Out(), &Deleter, debug_cstr);
        OutCString out_cstr1;
        
        assert(strncmp(*(log1.GetTag()), *debug_cstr, 6) == 0);
        assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
        assert(log1.Print("%d", 1) == 1);
        assert(Print(log1, "%d", 23) == 2);
        assert(log1.Puts("4"));
        assert(log1.Puts("56", 2));
        assert(log1.Puts(CString("7")));
        assert(log1.Puts(C_CString("8")));
        assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
        assert(log1.GetOnBegin() == &Log::DefaultOnBegin);
        assert(log1.GetOnEnd() == &Log::DefaultOnEnd);
        assert(log1.IsGood() == true);
        assert(log1.IsBad() == false);
        assert(log1.IsEnd() == false);
        assert(log1.GetBadCode() == Log::StatusType::good);

        OutCString out_cstr1_2;
        Log::DefaultOnBegin(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());
        out_cstr1_2.Puts(log1.GetMessage());
        Log::DefaultOnEnd(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());

        auto res = log1.Output(out_cstr1);
        assert(res == true);
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr1_2.Get()), 
            out_cstr1_2.Size()) == 0);
    }
    {
        CString debug_cstr("debug", 5);
        Log log1(new Out(), &Deleter, debug_cstr, &OnBegin);
        OutCString out_cstr1;
        
        assert(strncmp(*(log1.GetTag()), *debug_cstr, 6) == 0);
        assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
        assert(log1.Print("%d", 1) == 1);
        assert(Print(log1, "%d", 23) == 2);
        assert(log1.Puts("4"));
        assert(log1.Puts("56", 2));
        assert(log1.Puts(CString("7")));
        assert(log1.Puts(C_CString("8")));
        assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
        assert(log1.GetOnBegin() == &OnBegin);
        assert(log1.GetOnEnd() == &Log::DefaultOnEnd);
        assert(log1.IsGood() == true);
        assert(log1.IsBad() == false);
        assert(log1.IsEnd() == false);
        assert(log1.GetBadCode() == Log::StatusType::good);

        OutCString out_cstr1_2;
        OnBegin(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());
        out_cstr1_2.Puts(log1.GetMessage());
        Log::DefaultOnEnd(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());

        auto res = log1.Output(out_cstr1);
        assert(res == true);
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr1_2.Get()), 
            out_cstr1_2.Size()) == 0);
    }
    
    {
        CString debug_cstr("debug", 5);
        Log log1(new Out(), &Deleter, debug_cstr, &OnBegin, &OnEnd);
        OutCString out_cstr1;
        
        assert(strncmp(*(log1.GetTag()), *debug_cstr, 6) == 0);
        assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
        assert(log1.Print("%d", 1) == 1);
        assert(Print(log1, "%d", 23) == 2);
        assert(log1.Puts("4"));
        assert(log1.Puts("56", 2));
        assert(log1.Puts(CString("7")));
        assert(log1.Puts(C_CString("8")));
        assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
        assert(log1.GetOnBegin() == &OnBegin);
        assert(log1.GetOnEnd() == &OnEnd);
        assert(log1.IsGood() == true);
        assert(log1.IsBad() == false);
        assert(log1.IsEnd() == false);
        assert(log1.GetBadCode() == Log::StatusType::good);

        OutCString out_cstr1_2;
        OnBegin(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());
        out_cstr1_2.Puts(log1.GetMessage());
        OnEnd(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());

        auto res = log1.Output(out_cstr1);
        assert(res == true);
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr1_2.Get()), 
            out_cstr1_2.Size()) == 0);
    }
    
    {
        CString debug_cstr("debug", 5);
        Log log1(new Out(), &Deleter, debug_cstr, nullptr, &OnEnd);
        OutCString out_cstr1;
        
        assert(strncmp(*(log1.GetTag()), *debug_cstr, 6) == 0);
        assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
        assert(log1.Print("%d", 1) == 1);
        assert(Print(log1, "%d", 23) == 2);
        assert(log1.Puts("4"));
        assert(log1.Puts("56", 2));
        assert(log1.Puts(CString("7")));
        assert(log1.Puts(C_CString("8")));
        assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
        assert(log1.GetOnBegin() == &Log::DefaultOnBegin);
        assert(log1.GetOnEnd() == &OnEnd);
        assert(log1.IsGood() == true);
        assert(log1.IsBad() == false);
        assert(log1.IsEnd() == false);
        assert(log1.GetBadCode() == Log::StatusType::good);

        OutCString out_cstr1_2;
        Log::DefaultOnBegin(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());
        out_cstr1_2.Puts(log1.GetMessage());
        OnEnd(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());

        auto res = log1.Output(out_cstr1);
        assert(res == true);
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr1_2.Get()), 
            out_cstr1_2.Size()) == 0);
    }
    
    {
        CString debug_cstr("debug", 5);
        Log log1_1(new Out(), &Deleter, debug_cstr, &OnBegin, &OnEnd);
        {
            Log log1(std::move(log1_1));
            OutCString out_cstr1;
            
            assert(strncmp(*(log1.GetTag()), *debug_cstr, 6) == 0);
            assert(strncmp(*(log1.GetMessage()), "", 1) == 0);
            assert(log1.Print("%d", 1) == 1);
            assert(Print(log1, "%d", 23) == 2);
            assert(log1.Puts("4"));
            assert(log1.Puts("56", 2));
            assert(log1.Puts(CString("7")));
            assert(log1.Puts(C_CString("8")));
            assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
            assert(log1.GetOnBegin() == &OnBegin);
            assert(log1.GetOnEnd() == &OnEnd);
            assert(log1.IsGood() == true);
            assert(log1.IsBad() == false);
            assert(log1.IsEnd() == false);
            assert(log1.GetBadCode() == Log::StatusType::good);

            OutCString out_cstr1_2;
            OnBegin(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());
            out_cstr1_2.Puts(log1.GetMessage());
            OnEnd(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());

            auto res = log1.Output(out_cstr1);
            assert(res == true);
            assert(strncmp(*(out_cstr1.Get()), *(out_cstr1_2.Get()), 
                out_cstr1_2.Size()) == 0);
        }
    }

    {
        CString debug_cstr("debug", 5);
        Log log1_1(new Out(), &Deleter, debug_cstr, &OnBegin, &OnEnd);

        assert(strncmp(*(log1_1.GetTag()), *debug_cstr, 6) == 0);
        assert(strncmp(*(log1_1.GetMessage()), "", 1) == 0);
        assert(log1_1.Print("%d", 1) == 1);
        assert(Print(log1_1, "%d", 23) == 2);
        assert(log1_1.Puts("4"));
        assert(log1_1.Puts("56", 2));
        assert(log1_1.Puts(CString("7")));
        assert(log1_1.Puts(C_CString("8")));
        assert(strncmp(*(log1_1.GetMessage()), "12345678", 9) == 0);
        assert(log1_1.GetOnBegin() == &OnBegin);
        assert(log1_1.GetOnEnd() == &OnEnd);
        assert(log1_1.IsGood() == true);
        assert(log1_1.IsBad() == false);
        assert(log1_1.IsEnd() == false);
        assert(log1_1.GetBadCode() == Log::StatusType::good);
        assert(log1_1.End() == true);

        {
            Log log1(std::move(log1_1));
            OutCString out_cstr1;
            
            assert(strncmp(*(log1.GetTag()), *debug_cstr, 6) == 0);
            assert(strncmp(*(log1.GetMessage()), "12345678", 9) == 0);
            assert(log1.GetOnBegin() == &OnBegin);
            assert(log1.GetOnEnd() == &OnEnd);
            assert(log1.IsGood() == true);
            assert(log1.IsBad() == false);
            assert(log1.IsEnd() == true);
            assert(log1.GetBadCode() == Log::StatusType::good);

            OutCString out_cstr1_2;
            OnBegin(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());
            out_cstr1_2.Puts(log1.GetMessage());
            OnEnd(out_cstr1_2, log1.GetTimestamp(), log1.GetTag());

            auto res = log1.Output(out_cstr1);
            assert(res == true);
            assert(strncmp(*(out_cstr1.Get()), *(out_cstr1_2.Get()), 
                out_cstr1_2.Size()) == 0);
        }
    }
    {
        Log log1(test::out::log::tag::Crit{});
        
        assert(strncmp(*(log1.GetTag()), test::out::log::tag::Crit{}.GetName(), 
            test::out::log::tag::Crit{}.GetNameSize()) == 0);

        Log log2(test::out::log::tag::Debug{});
        
        assert(strncmp(*(log2.GetTag()), test::out::log::tag::Debug{}.GetName(), 
            test::out::log::tag::Debug{}.GetNameSize()) == 0);

        Log log4(test::out::log::tag::Error{});
        
        assert(strncmp(*(log4.GetTag()), test::out::log::tag::Error{}.GetName(), 
            test::out::log::tag::Error{}.GetNameSize()) == 0);

        Log log5(test::out::log::tag::Info{});
        
        assert(strncmp(*(log5.GetTag()), test::out::log::tag::Info{}.GetName(), 
            test::out::log::tag::Info{}.GetNameSize()) == 0);

        Log log6(test::out::log::tag::Warn{});
        
        assert(strncmp(*(log6.GetTag()), test::out::log::tag::Warn{}.GetName(), 
            test::out::log::tag::Warn{}.GetNameSize()) == 0);
    }

    {
        OutCString out_cstr1_1;
        {
            Log log1(&out_cstr1_1, test::out::log::tag::Crit{});
        
            assert(strncmp(*(log1.GetTag()), test::out::log::tag::Crit{}.GetName(), 
                test::out::log::tag::Crit{}.GetNameSize()) == 0);

            Log log2(&out_cstr1_1, test::out::log::tag::Debug{});
            
            assert(strncmp(*(log2.GetTag()), test::out::log::tag::Debug{}.GetName(), 
                test::out::log::tag::Debug{}.GetNameSize()) == 0);

            Log log4(&out_cstr1_1, test::out::log::tag::Error{});
            
            assert(strncmp(*(log4.GetTag()), test::out::log::tag::Error{}.GetName(), 
                test::out::log::tag::Error{}.GetNameSize()) == 0);

            Log log5(&out_cstr1_1, test::out::log::tag::Info{});
            
            assert(strncmp(*(log5.GetTag()), test::out::log::tag::Info{}.GetName(), 
                test::out::log::tag::Info{}.GetNameSize()) == 0);

            Log log6(&out_cstr1_1, test::out::log::tag::Warn{});
            
            assert(strncmp(*(log6.GetTag()), test::out::log::tag::Warn{}.GetName(), 
                test::out::log::tag::Warn{}.GetNameSize()) == 0);
        }
    }
    {
        Log log1(new Out(), &Deleter, test::out::log::tag::Crit{});
        
        assert(strncmp(*(log1.GetTag()), test::out::log::tag::Crit{}.GetName(), 
            test::out::log::tag::Crit{}.GetNameSize()) == 0);

        Log log2(new Out(), &Deleter, test::out::log::tag::Debug{});
        
        assert(strncmp(*(log2.GetTag()), test::out::log::tag::Debug{}.GetName(), 
            test::out::log::tag::Debug{}.GetNameSize()) == 0);

        Log log4(new Out(), &Deleter, test::out::log::tag::Error{});
        
        assert(strncmp(*(log4.GetTag()), test::out::log::tag::Error{}.GetName(), 
            test::out::log::tag::Error{}.GetNameSize()) == 0);

        Log log5(new Out(), &Deleter, test::out::log::tag::Info{});
        
        assert(strncmp(*(log5.GetTag()), test::out::log::tag::Info{}.GetName(), 
            test::out::log::tag::Info{}.GetNameSize()) == 0);

        Log log6(new Out(), &Deleter, test::out::log::tag::Warn{});
        
        assert(strncmp(*(log6.GetTag()), test::out::log::tag::Warn{}.GetName(), 
            test::out::log::tag::Warn{}.GetNameSize()) == 0);
    }

    assert(count == 0);

    return 1;
}