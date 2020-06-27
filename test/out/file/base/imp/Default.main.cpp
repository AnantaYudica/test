#include "test/out/file/base/imp/Default.h"

#include <cassert>

class Obj1 :
    public test::out::file::base::imp::Default
{
private:
    typedef test::out::file::base::imp::Default BaseType;
public:
    bool call_initialize, call_mode, call_size, call_filename, 
        call_print, call_puts, call_buffer;
    Obj1() :
        test::out::file::base::imp::Default(),
        call_initialize(false),
        call_mode(false),
        call_size(false),
        call_filename(false),
        call_print(false),
        call_puts(false),
        call_buffer(false)
    {}
    void Initialize()
    {
        auto guard = BaseType::InitializeGuard();
        if (guard)
            call_initialize = true;
        else
            call_initialize = false;
    }
    void Mode()
    {
        auto guard = BaseType::ModeGuard();
        if (guard)
            call_mode = true;
        else
            call_mode = false;
    }
    void Size()
    {
        auto guard = BaseType::SizeGuard();
        if (guard)
            call_size = true;
        else
            call_size = false;
    }
    void Filename()
    {
        auto guard = BaseType::FilenameGuard();
        if (guard)
            call_filename = true;
        else
            call_filename = false;
    }
    void Print()
    {
        auto guard = BaseType::PrintGuard();
        if (guard)
            call_print = true;
        else
            call_print = false;
    }
    void Puts()
    {
        auto guard = BaseType::PutsGuard();
        if (guard)
            call_puts = true;
        else
            call_puts = false;
    }
    void Buffer()
    {
        auto guard = BaseType::BufferGuard();
        if (guard)
            call_buffer = true;
        else
            call_buffer = false;
    }
};

int main()
{
    Obj1 obj1_1;
    assert(obj1_1.call_initialize == false); 
    assert(obj1_1.call_mode == false);
    assert(obj1_1.call_size == false);
    assert(obj1_1.call_filename == false);
    assert(obj1_1.call_print == false);
    assert(obj1_1.call_puts == false);
    assert(obj1_1.call_buffer == false);

    obj1_1.Initialize();
    assert(obj1_1.call_initialize == true); 
    assert(obj1_1.call_mode == false);
    assert(obj1_1.call_size == false);
    assert(obj1_1.call_filename == false);
    assert(obj1_1.call_print == false);
    assert(obj1_1.call_puts == false);
    assert(obj1_1.call_buffer == false);

    obj1_1.Mode();
    assert(obj1_1.call_initialize == true); 
    assert(obj1_1.call_mode == true);
    assert(obj1_1.call_size == false);
    assert(obj1_1.call_filename == false);
    assert(obj1_1.call_print == false);
    assert(obj1_1.call_puts == false);
    assert(obj1_1.call_buffer == false);
    
    obj1_1.Size();
    assert(obj1_1.call_initialize == true); 
    assert(obj1_1.call_mode == true);
    assert(obj1_1.call_size == true);
    assert(obj1_1.call_filename == false);
    assert(obj1_1.call_print == false);
    assert(obj1_1.call_puts == false);
    assert(obj1_1.call_buffer == false);
    
    obj1_1.Filename();
    assert(obj1_1.call_initialize == true); 
    assert(obj1_1.call_mode == true);
    assert(obj1_1.call_size == true);
    assert(obj1_1.call_filename == true);
    assert(obj1_1.call_print == false);
    assert(obj1_1.call_puts == false);
    assert(obj1_1.call_buffer == false);

    obj1_1.Print();
    assert(obj1_1.call_initialize == true); 
    assert(obj1_1.call_mode == true);
    assert(obj1_1.call_size == true);
    assert(obj1_1.call_filename == true);
    assert(obj1_1.call_print == true);
    assert(obj1_1.call_puts == false);
    assert(obj1_1.call_buffer == false);

    obj1_1.Puts();
    assert(obj1_1.call_initialize == true); 
    assert(obj1_1.call_mode == true);
    assert(obj1_1.call_size == true);
    assert(obj1_1.call_filename == true);
    assert(obj1_1.call_print == true);
    assert(obj1_1.call_puts == true);
    assert(obj1_1.call_buffer == false);

    obj1_1.Buffer();
    assert(obj1_1.call_initialize == true); 
    assert(obj1_1.call_mode == true);
    assert(obj1_1.call_size == true);
    assert(obj1_1.call_filename == true);
    assert(obj1_1.call_print == true);
    assert(obj1_1.call_puts == true);
    assert(obj1_1.call_buffer == true);
    
    return 1;
}