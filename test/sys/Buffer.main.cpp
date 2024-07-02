#include "test/sys/Buffer.h"
#include "test/sys/Status.h"

#include <cassert>
#include <cstring>

typedef test::sys::Status StatusType;

#define FIRST_LINE "first line"
#define SECOND_LINE "second line"

typedef test::sys::Buffer<StatusType, 10, 128> BufferType;

StatusType status;
BufferType buff{status};

int Get1()
{
    buff.Output(FIRST_LINE);
    return 1;
}

int main()
{
    {

        buff.Output(SECOND_LINE " %d", Get1());

        assert(buff.Size() == 2);

        buff.Info(SECOND_LINE " %d", 2);
    
        assert(buff.Size() == 3);

        buff.Error(test::sys::Definition::Status::sOk, SECOND_LINE " %d", 3);
        
        assert(buff.Size() == 4);

        buff.Debug(test::sys::dbg::Type<void>::GetInstance(), 0, NULL, 
            SECOND_LINE " check %s", "debug");

        assert(buff.Size() == 5);
        
        assert((strncmp(buff[0].GetMessage(), FIRST_LINE, sizeof(FIRST_LINE)) == 0));
        assert((strncmp(buff[1].GetMessage(), 
            SECOND_LINE " 1", sizeof(SECOND_LINE " 1")) == 0));
        assert((strncmp(buff[2].GetMessage(), 
            SECOND_LINE " 2", sizeof(SECOND_LINE " 2")) == 0));
        assert((strncmp(buff[3].GetMessage(), 
            SECOND_LINE " 3", sizeof(SECOND_LINE " 3")) == 0));
        assert((strncmp(buff[4].GetMessage(), 
            SECOND_LINE " check debug", sizeof(SECOND_LINE " check debug")) == 0));
        assert(status.GetCode() == test::sys::Definition::Status::sOk);
    }
    {
        buff.Output("1");
        buff.Output("2");
        buff.Output("3");
        buff.Output("4");
        buff.Output("5");
        
        assert(buff.Size() == 10);

        buff.Output("6");
        
        assert(buff.Size() == 10);
        assert((strncmp(buff[0].GetMessage(), 
            SECOND_LINE " 1", sizeof(SECOND_LINE " 1")) == 0));

        buff.Output("7");
        buff.Output("8");
        buff.Output("9");
        buff.Output("10");
        
        assert(buff.Size() == 10);
        assert((strncmp(buff[0].GetMessage(), "1", 2) == 0));

    }
    {
        buff.Reset();
        assert(buff.Size() == 0);
        
        buff.Output("11");
        
        assert(buff.Size() == 1);
        assert((strncmp(buff[0].GetMessage(), "11", 3) == 0));

    }
    return 0;
}
