#include "test/sys/Log.h"
#include "test/sys/Status.h"

#include <cassert>
#include <cstring>

static test::sys::Status status;
static test::sys::Log<test::sys::Status> log(status);

#define FIRST_LINE "first line"
#define SECOND_LINE "second line"
#define THIRD_LINE "third line"
#define FOURTH_LINE "fourth line"
#define SIXTH_LINE "sixth line"

int Get1()
{
    log.Output(FIRST_LINE);
    return 1;
}

int Formater(char* buffer, 
    const std::size_t& buffer_size, const test::sys::Status& status, 
    const char* msg)
{
    return snprintf(buffer, buffer_size, "1234:%s", msg);
}

int IFormater(char* buffer, 
    const std::size_t& buffer_size, const test::sys::Status& status, 
    const char* msg)
{
    return snprintf(buffer, buffer_size, "INFO:%s", msg);
}

int DFormater(char* buffer, 
    const std::size_t& buffer_size, test::sys::Debug& dbg, std::int8_t level, 
    const void * obj, const test::sys::Status& status, 
    const char* msg)
{
    return snprintf(buffer, buffer_size, "DEBUG:%s", msg);
}

int EFormater(char* buffer, 
    const std::size_t& buffer_size, const test::sys::Status& status, 
    const char* msg)
{
    return snprintf(buffer, buffer_size, "ERR:%s", msg);
}

int main()
{
    FILE * fout = fopen("TestSysLog.out.txt", "w+");
    assert(fout != NULL);

    test::sys::dbg::Type<void>::GetInstance().SetLevel(0);

    log.SetFileOutput(fout);
    log.Output(SECOND_LINE " %d", Get1());
    log.Info(SECOND_LINE " %d", 2);
    log.Error(test::sys::Definition::Status::sOk, SECOND_LINE " %d", 3);
    log.Debug(test::sys::dbg::Type<void>::GetInstance(), 0, NULL, 
        SECOND_LINE " check %s", "debug");

    assert(status.GetCode() == test::sys::Definition::Status::sOk);

    log.SetOutputFormatCallback(Formater);
    log.Output(THIRD_LINE " %d", 1234);
    log.Info(THIRD_LINE " %d", 5678);
    log.Error(test::sys::Definition::Status::sUndefined, THIRD_LINE " %d", 910);
    log.Debug(test::sys::dbg::Type<void>::GetInstance(), 0, NULL, 
        THIRD_LINE " debug %s", "mode");

    assert(status.GetCode() == test::sys::Definition::Status::sUndefined);

    log.SetInfoFormatCallback(IFormater);
    log.SetErrorFormatCallback(EFormater);
    log.SetDebugFormatCallback(DFormater);
    log.Output(FOURTH_LINE " %s", "out");
    log.Info(FOURTH_LINE " %s", "info");
    log.Error(test::sys::Definition::Status::sOk, FOURTH_LINE " %s", "error");
    log.Debug(test::sys::dbg::Type<void>::GetInstance(), 0, NULL, 
        FOURTH_LINE " mode %s", "debug");
    
    char buff[1024];
    fseek(fout, 0 ,SEEK_SET);
    fread(buff, 1024, 1024, fout);

    std::string first_line_1 = "";
    std::string second_line_1 = "";
    std::string second_line_2 = "";
    std::string second_line_3 = "";
    std::string second_line_4 = "";
    std::string third_line_1 = "";
    std::string third_line_2 = "";
    std::string third_line_3 = "";
    std::string third_line_4 = "";
    std::string fourth_line_1 = "";
    std::string fourth_line_2 = "";
    std::string fourth_line_3 = "";
    std::string fourth_line_4 = "";

    std::string* ref[] = {&first_line_1,
        &second_line_1, &second_line_2, &second_line_3, &second_line_4,
        &third_line_1, &third_line_2, &third_line_3, &third_line_4,
        &fourth_line_1, &fourth_line_2, &fourth_line_3, &fourth_line_4};
    int line = 0;
    for (std::size_t i = 0; buff[i] != EOF; ++i)
    {
        if (buff[i] == '\n') 
        {
            printf("%s\n", ref[line]->c_str());
            ++line;
            continue;
        }
        if (line >= (sizeof(ref) / sizeof(std::string*))) break;
        *(ref[line]) += buff[i];
    }
    
    fclose(fout);
    
    // remove("TestSysLog.out.txt");

    assert(first_line_1.compare(FIRST_LINE) == 0);

    assert(second_line_1.compare(SECOND_LINE " 1") == 0);
    assert(second_line_2.compare(SECOND_LINE " 2") == 0);
    assert(second_line_3.compare(SECOND_LINE " 3") == 0);
    assert(second_line_4.compare(SECOND_LINE " check debug") == 0);

    assert(third_line_1.compare("1234:" THIRD_LINE " 1234") == 0);
    assert(third_line_2.compare("1234:" THIRD_LINE " 5678") == 0);
    assert(third_line_3.compare("1234:" THIRD_LINE " 910") == 0);
    assert(third_line_4.compare("1234:" THIRD_LINE " debug mode") == 0);

    assert(fourth_line_1.compare("1234:" FOURTH_LINE " out") == 0);
    assert(fourth_line_2.compare("INFO:" FOURTH_LINE " info") == 0);
    assert(fourth_line_3.compare("ERR:" FOURTH_LINE " error") == 0);
    assert(fourth_line_4.compare("DEBUG:" FOURTH_LINE " mode debug") == 0);

    return 0;
}
