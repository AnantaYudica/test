#include "test/sys/Log.h"
#include "test/sys/Status.h"

#include <cassert>
#include <cstring>

static test::sys::Status status;
static test::sys::Log<test::sys::Status> log(status);

#define FIRST_LINE "first line"
#define SECOND_LINE "second line"
#define THIRD_LINE "third line"

int Get1()
{
    log.Output(FIRST_LINE);
    return 1;
}

int Formater(char* buffer, 
    const std::size_t& buffer_size, const test::sys::Status& status, 
    const char* msg)
{
    return snprintf(buffer, buffer_size, "1234:%s\n", msg);
}

int main()
{
    FILE * fout = fopen("TestSysLog.out.txt", "w+");
    assert(fout != NULL);

    log.SetFileOutput(fout);
    log.Output(SECOND_LINE " %d", Get1());

    log.SetFormatCallback(Formater);
    log.Output(THIRD_LINE " %d", 1234);
    
    char buff[1024];
    fseek(fout, 0 ,SEEK_SET);
    fread(buff, 1024, 1024, fout);

    std::string first_line = "";
    std::string second_line = "";
    std::string third_line = "";
    int line = 0;
    for (std::size_t i = 0; buff[i] != EOF; ++i)
    {
        if (buff[i] == '\n') 
        {
            ++line;
            continue;
        }
        if (line == 0)
        {
            first_line += buff[i];
        }
        else if(line == 1)
        {
            second_line += buff[i];
        }
        else if(line == 2)
        {
            third_line += buff[i];
        }
    }
    
    fclose(fout);
    
    remove("TestSysLog.out.txt");

    assert(first_line.compare(FIRST_LINE) == 0);
    assert(second_line.compare(SECOND_LINE " 1") == 0);
    assert(third_line.compare("1234:" THIRD_LINE " 1234") == 0);

    return 0;
}
