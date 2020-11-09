#include "test/out/print/Prefix.h"

#include <cassert>
#include <cstring>

int main()
{
    typedef test::out::fmt::FlagType FlagType;
    {
        test::CString<char> val_cstr1{"123"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_oct |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, false, 0);
        assert(strcmp(*cstr1, "0123") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_oct |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "0123") == 0);
        assert(cstr2.Size() == 4);
        
        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_oct |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0123") == 0);
        assert(cstr3.Size() == 4);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_oct |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "0123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_oct |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "0123") == 0);
        assert(cstr5.Size() == 4);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_oct |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "0123") == 0);
        assert(cstr6.Size() == 4);
    }
    
    {
        test::CString<char> val_cstr1{"123"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false);
        assert(strcmp(*cstr1, "0123") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "0123") == 0);
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0000000123") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true);
        assert(strcmp(*cstr4, "0123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "0123") == 0);
        assert(cstr5.Size() == 4);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "0000000123") == 0);
        assert(cstr6.Size() == 10);
    }

    {
        test::CString<char> val_cstr1{"123"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false);
        assert(strcmp(*cstr1, "123") == 0);
        assert(cstr1.Size() == 3);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "123") == 0);
        assert(cstr2.Size() == 3);
        
        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "123") == 0);
        assert(cstr3.Size() == 3);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "123") == 0);
        assert(cstr4.Size() == 3);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "123") == 0);
        assert(cstr5.Size() == 3);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "123") == 0);
        assert(cstr6.Size() == 3);
    }

    {
        test::CString<char> val_cstr1{"123"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false);
        assert(strcmp(*cstr1, "123") == 0);
        assert(cstr1.Size() == 3);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "123") == 0);
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0000000123") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true);
        assert(strcmp(*cstr4, "123") == 0);
        assert(cstr4.Size() == 3);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "123") == 0);
        assert(cstr5.Size() == 3);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "0000000123") == 0);
        assert(cstr6.Size() == 10);
    }

    {
        test::CString<char> val_cstr1{"123"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(strcmp(*cstr1, "123") == 0);
        assert(cstr1.Size() == 3);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "123") == 0);
        assert(cstr2.Size() == 3);
        
        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "123") == 0);
        assert(cstr3.Size() == 3);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-123") == 0);
        assert(cstr5.Size() == 4);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-123") == 0);
        assert(cstr6.Size() == 4);
    }

    {
        test::CString<char> val_cstr1{"123"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(strcmp(*cstr1, "123") == 0);
        assert(cstr1.Size() == 3);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "123") == 0);
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0000000123") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true);
        assert(strcmp(*cstr4, "-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-123") == 0);
        assert(cstr5.Size() == 4);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-000000123") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, "1.23") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "1.23") == 0);
        assert(cstr2.Size() == 4);
        
        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "1.23") == 0);
        assert(cstr3.Size() == 4);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.23") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-1.23") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<char> val_cstr1{"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, "1.23") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "1.23") == 0);
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0000001.23") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(strcmp(*cstr4, "-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.23") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-000001.23") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"123"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(strcmp(*cstr1, "+123") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "+123") == 0);
        assert(cstr2.Size() == 4);
        
        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "+123") == 0);
        assert(cstr3.Size() == 4);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-123") == 0);
        assert(cstr5.Size() == 4);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-123") == 0);
        assert(cstr6.Size() == 4);
    }

    {
        test::CString<char> val_cstr1{"123"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(strcmp(*cstr1, "+123") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "+123") == 0);
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "+000000123") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true);
        assert(strcmp(*cstr4, "-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-123") == 0);
        assert(cstr5.Size() == 4);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-000000123") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, "+1.23") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "+1.23") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "+1.23") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix | 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.23") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-1.23") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<char> val_cstr1{"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, "+1.23") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "+1.23") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "+000001.23") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(strcmp(*cstr4, "-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.23") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-000001.23") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"123"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(strcmp(*cstr1, " 123") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, " 123") == 0);
        assert(cstr2.Size() == 4);
        
        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, " 123") == 0);
        assert(cstr3.Size() == 4);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-123") == 0);
        assert(cstr5.Size() == 4);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-123") == 0);
        assert(cstr6.Size() == 4);
    }

    {
        test::CString<char> val_cstr1{"123"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(strcmp(*cstr1, " 123") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, " 123") == 0);
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, " 000000123") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true);
        assert(strcmp(*cstr4, "-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-123") == 0);
        assert(cstr5.Size() == 4);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-000000123") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, " 1.23") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, " 1.23") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, " 1.23") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix | 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.23") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-1.23") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<char> val_cstr1{"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, " 1.23") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, " 1.23") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, " 000001.23") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(strcmp(*cstr4, "-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.23") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-000001.23") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"abc"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false);
        assert(strcmp(*cstr1, "0xabc") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "0xabc") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0xabc") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "0xabc") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "0xabc") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "0xabc") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<char> val_cstr1{"abc"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false);
        assert(strcmp(*cstr1, "0xabc") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "0xabc") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0x00000abc") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true);
        assert(strcmp(*cstr4, "0xabc") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "0xabc") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "0x00000abc") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, "0x1.ab") == 0);
        assert(cstr1.Size() == 6);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "0x1.ab") == 0);
        assert(cstr2.Size() == 6);
        
        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0x1.ab") == 0);
        assert(cstr3.Size() == 6);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-0x1.ab") == 0);
        assert(cstr5.Size() == 7);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-0x1.ab") == 0);
        assert(cstr6.Size() == 7);
    }

    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, "0x1.ab") == 0);
        assert(cstr1.Size() == 6);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "0x1.ab") == 0);
        assert(cstr2.Size() == 6);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0x00001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(strcmp(*cstr4, "-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-0x1.ab") == 0);
        assert(cstr5.Size() == 7);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-0x0001.ab") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, "+0x1.ab") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "+0x1.ab") == 0);
        assert(cstr2.Size() == 7);
        
        auto cstr3 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "+0x1.ab") == 0);
        assert(cstr3.Size() == 7);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix | 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-0x1.ab") == 0);
        assert(cstr5.Size() == 7);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-0x1.ab") == 0);
        assert(cstr6.Size() == 7);
    }

    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, "+0x1.ab") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "+0x1.ab") == 0);
        assert(cstr2.Size() == 7);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "+0x0001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(strcmp(*cstr4, "-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-0x1.ab") == 0);
        assert(cstr5.Size() == 7);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-0x0001.ab") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, " 0x1.ab") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, " 0x1.ab") == 0);
        assert(cstr2.Size() == 7);
        
        auto cstr3 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, " 0x1.ab") == 0);
        assert(cstr3.Size() == 7);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix | 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-0x1.ab") == 0);
        assert(cstr5.Size() == 7);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-0x1.ab") == 0);
        assert(cstr6.Size() == 7);
    }

    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, " 0x1.ab") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, " 0x1.ab") == 0);
        assert(cstr2.Size() == 7);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, " 0x0001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(strcmp(*cstr4, "-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-0x1.ab") == 0);
        assert(cstr5.Size() == 7);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-0x0001.ab") == 0);
        assert(cstr6.Size() == 10);
    }

    {
        test::CString<char> val_cstr1{"abc"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(strcmp(*cstr1, "0xabc") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "0xabc") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0xabc") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "0xabc") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "0xabc") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "0xabc") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<char> val_cstr1{"abc"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(strcmp(*cstr1, "0xabc") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "0xabc") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0x00000abc") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, true);
        assert(strcmp(*cstr4, "0xabc") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "0xabc") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "0x00000abc") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(strcmp(*cstr1, "0x1.ab") == 0);
        assert(cstr1.Size() == 6);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "0x1.ab") == 0);
        assert(cstr2.Size() == 6);
        
        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0x1.ab") == 0);
        assert(cstr3.Size() == 6);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-0x1.ab") == 0);
        assert(cstr5.Size() == 7);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-0x1.ab") == 0);
        assert(cstr6.Size() == 7);
    }

    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(strcmp(*cstr1, "0x1.ab") == 0);
        assert(cstr1.Size() == 6);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "0x1.ab") == 0);
        assert(cstr2.Size() == 6);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0x00001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true);
        assert(strcmp(*cstr4, "-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-0x1.ab") == 0);
        assert(cstr5.Size() == 7);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-0x0001.ab") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(strcmp(*cstr1, "+0x1.ab") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "+0x1.ab") == 0);
        assert(cstr2.Size() == 7);
        
        auto cstr3 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "+0x1.ab") == 0);
        assert(cstr3.Size() == 7);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix | 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-0x1.ab") == 0);
        assert(cstr5.Size() == 7);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-0x1.ab") == 0);
        assert(cstr6.Size() == 7);
    }

    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(strcmp(*cstr1, "+0x1.ab") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "+0x1.ab") == 0);
        assert(cstr2.Size() == 7);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "+0x0001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true);
        assert(strcmp(*cstr4, "-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-0x1.ab") == 0);
        assert(cstr5.Size() == 7);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-0x0001.ab") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(strcmp(*cstr1, " 0x1.ab") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, " 0x1.ab") == 0);
        assert(cstr2.Size() == 7);
        
        auto cstr3 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, " 0x1.ab") == 0);
        assert(cstr3.Size() == 7);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix | 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-0x1.ab") == 0);
        assert(cstr5.Size() == 7);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-0x1.ab") == 0);
        assert(cstr6.Size() == 7);
    }

    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(strcmp(*cstr1, " 0x1.ab") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, " 0x1.ab") == 0);
        assert(cstr2.Size() == 7);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, " 0x0001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true);
        assert(strcmp(*cstr4, "-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-0x1.ab") == 0);
        assert(cstr5.Size() == 7);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-0x0001.ab") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"ABC"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(strcmp(*cstr1, "0XABC") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "0XABC") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0XABC") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "0XABC") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "0XABC") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "0XABC") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<char> val_cstr1{"ABC"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(strcmp(*cstr1, "0XABC") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "0XABC") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0X00000ABC") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, true);
        assert(strcmp(*cstr4, "0XABC") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "0XABC") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "0X00000ABC") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(strcmp(*cstr1, "0X1.AB") == 0);
        assert(cstr1.Size() == 6);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "0X1.AB") == 0);
        assert(cstr2.Size() == 6);
        
        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0X1.AB") == 0);
        assert(cstr3.Size() == 6);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-0X1.AB") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-0X1.AB") == 0);
        assert(cstr5.Size() == 7);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-0X1.AB") == 0);
        assert(cstr6.Size() == 7);
    }

    {
        test::CString<char> val_cstr1{"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(strcmp(*cstr1, "0X1.AB") == 0);
        assert(cstr1.Size() == 6);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "0X1.AB") == 0);
        assert(cstr2.Size() == 6);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0X00001.AB") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true);
        assert(strcmp(*cstr4, "-0X1.AB") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-0X1.AB") == 0);
        assert(cstr5.Size() == 7);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-0X0001.AB") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(strcmp(*cstr1, "+0X1.AB") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "+0X1.AB") == 0);
        assert(cstr2.Size() == 7);
        
        auto cstr3 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "+0X1.AB") == 0);
        assert(cstr3.Size() == 7);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-0X1.AB") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix | 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-0X1.AB") == 0);
        assert(cstr5.Size() == 7);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-0X1.AB") == 0);
        assert(cstr6.Size() == 7);
    }

    {
        test::CString<char> val_cstr1{"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(strcmp(*cstr1, "+0X1.AB") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "+0X1.AB") == 0);
        assert(cstr2.Size() == 7);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "+0X0001.AB") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true);
        assert(strcmp(*cstr4, "-0X1.AB") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-0X1.AB") == 0);
        assert(cstr5.Size() == 7);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-0X0001.AB") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(strcmp(*cstr1, " 0X1.AB") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, " 0X1.AB") == 0);
        assert(cstr2.Size() == 7);
        
        auto cstr3 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, " 0X1.AB") == 0);
        assert(cstr3.Size() == 7);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-0X1.AB") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix | 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-0X1.AB") == 0);
        assert(cstr5.Size() == 7);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-0X1.AB") == 0);
        assert(cstr6.Size() == 7);
    }

    {
        test::CString<char> val_cstr1{"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(strcmp(*cstr1, " 0X1.AB") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, " 0X1.AB") == 0);
        assert(cstr2.Size() == 7);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, " 0X0001.AB") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true);
        assert(strcmp(*cstr4, "-0X1.AB") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-0X1.AB") == 0);
        assert(cstr5.Size() == 7);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-0X0001.AB") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"123"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false);
        assert(strcmp(*cstr1, "123") == 0);
        assert(cstr1.Size() == 3);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "123") == 0);
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0000000123") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true);
        assert(strcmp(*cstr4, "123") == 0);
        assert(cstr4.Size() == 3);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "123") == 0);
        assert(cstr5.Size() == 3);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "0000000123") == 0);
        assert(cstr6.Size() == 10);
    }

    {
        test::CString<char> val_cstr1{"123"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false);
        assert(strcmp(*cstr1, "123") == 0);
        assert(cstr1.Size() == 3);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "123") == 0);
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0000000123") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true);
        assert(strcmp(*cstr4, "123") == 0);
        assert(cstr4.Size() == 3);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "123") == 0);
        assert(cstr5.Size() == 3);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "0000000123") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"123"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(strcmp(*cstr1, "123") == 0);
        assert(cstr1.Size() == 3);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "123") == 0);
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0000000123") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true);
        assert(strcmp(*cstr4, "-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-123") == 0);
        assert(cstr5.Size() == 4);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-000000123") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, "1.23") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "1.23") == 0);
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0000001.23") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(strcmp(*cstr4, "-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.23") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-000001.23") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"123"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(strcmp(*cstr1, "+123") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "+123") == 0);
        assert(cstr2.Size() == 4);
        
        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "+123") == 0);
        assert(cstr3.Size() == 4);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-123") == 0);
        assert(cstr5.Size() == 4);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-123") == 0);
        assert(cstr6.Size() == 4);
    }

    {
        test::CString<char> val_cstr1{"123"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(strcmp(*cstr1, "+123") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "+123") == 0);
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "+000000123") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true);
        assert(strcmp(*cstr4, "-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-123") == 0);
        assert(cstr5.Size() == 4);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-000000123") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, "+1.23") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "+1.23") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "+1.23") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.23") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-1.23") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<char> val_cstr1{"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, "+1.23") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "+1.23") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "+000001.23") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(strcmp(*cstr4, "-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.23") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-000001.23") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"123"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(strcmp(*cstr1, " 123") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, " 123") == 0);
        assert(cstr2.Size() == 4);
        
        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, " 123") == 0);
        assert(cstr3.Size() == 4);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-123") == 0);
        assert(cstr5.Size() == 4);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-123") == 0);
        assert(cstr6.Size() == 4);
    }

    {
        test::CString<char> val_cstr1{"123"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(strcmp(*cstr1, " 123") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, " 123") == 0);
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, " 000000123") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true);
        assert(strcmp(*cstr4, "-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-123") == 0);
        assert(cstr5.Size() == 4);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-000000123") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, " 1.23") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, " 1.23") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, " 1.23") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.23") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-1.23") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<char> val_cstr1{"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, " 1.23") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, " 1.23") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, " 000001.23") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(strcmp(*cstr4, "-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.23") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-000001.23") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"abc"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false);
        assert(strcmp(*cstr1, "abc") == 0);
        assert(cstr1.Size() == 3);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "abc") == 0);
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0000000abc") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true);
        assert(strcmp(*cstr4, "abc") == 0);
        assert(cstr4.Size() == 3);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "abc") == 0);
        assert(cstr5.Size() == 3);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "0000000abc") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, "1.ab") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "1.ab") == 0);
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0000001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(strcmp(*cstr4, "-1.ab") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.ab") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-000001.ab") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, "+1.ab") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "+1.ab") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "+1.ab") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-1.ab") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.ab") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-1.ab") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, "+1.ab") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "+1.ab") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "+000001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(strcmp(*cstr4, "-1.ab") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.ab") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-000001.ab") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, " 1.ab") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, " 1.ab") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, " 1.ab") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-1.ab") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.ab") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-1.ab") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(strcmp(*cstr1, " 1.ab") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, " 1.ab") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, " 000001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(strcmp(*cstr4, "-1.ab") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.ab") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-000001.ab") == 0);
        assert(cstr6.Size() == 10);
    }

    {
        test::CString<char> val_cstr1{"abc"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(strcmp(*cstr1, "abc") == 0);
        assert(cstr1.Size() == 3);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "abc") == 0);
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0000000abc") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, true);
        assert(strcmp(*cstr4, "abc") == 0);
        assert(cstr4.Size() == 3);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "abc") == 0);
        assert(cstr5.Size() == 3);

        auto cstr6 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "0000000abc") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(strcmp(*cstr1, "1.ab") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "1.ab") == 0);
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0000001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true);
        assert(strcmp(*cstr4, "-1.ab") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.ab") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-000001.ab") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(strcmp(*cstr1, "+1.ab") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "+1.ab") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "+1.ab") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-1.ab") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.ab") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-1.ab") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(strcmp(*cstr1, "+1.ab") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "+1.ab") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "+000001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true);
        assert(strcmp(*cstr4, "-1.ab") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.ab") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-000001.ab") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(strcmp(*cstr1, " 1.ab") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, " 1.ab") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, " 1.ab") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-1.ab") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.ab") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-1.ab") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<char> val_cstr1{"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(strcmp(*cstr1, " 1.ab") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, " 1.ab") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, " 000001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true);
        assert(strcmp(*cstr4, "-1.ab") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.ab") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-000001.ab") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"ABC"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(strcmp(*cstr1, "ABC") == 0);
        assert(cstr1.Size() == 3);
        
        auto cstr2 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "ABC") == 0);
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0000000ABC") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, true);
        assert(strcmp(*cstr4, "ABC") == 0);
        assert(cstr4.Size() == 3);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "ABC") == 0);
        assert(cstr5.Size() == 3);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "0000000ABC") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(strcmp(*cstr1, "1.AB") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "1.AB") == 0);
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "0000001.AB") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true);
        assert(strcmp(*cstr4, "-1.AB") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.AB") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-000001.AB") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(strcmp(*cstr1, "+1.AB") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "+1.AB") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "+1.AB") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-1.AB") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.AB") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-1.AB") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<char> val_cstr1{"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(strcmp(*cstr1, "+1.AB") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, "+1.AB") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, "+000001.AB") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true);
        assert(strcmp(*cstr4, "-1.AB") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.AB") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-000001.AB") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<char> val_cstr1{"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(strcmp(*cstr1, " 1.AB") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, " 1.AB") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, " 1.AB") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 0);
        assert(strcmp(*cstr4, "-1.AB") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.AB") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-1.AB") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<char> val_cstr1{"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(strcmp(*cstr1, " 1.AB") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(strcmp(*cstr2, " 1.AB") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(strcmp(*cstr3, " 000001.AB") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true);
        assert(strcmp(*cstr4, "-1.AB") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<char,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(strcmp(*cstr5, "-1.AB") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<char, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(strcmp(*cstr6, "-000001.AB") == 0);
        assert(cstr6.Size() == 10);
    }
    ///WCHAR
    {
        test::CString<wchar_t> val_cstr1{L"123"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_oct |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, false, 0);
        assert(wcscmp(*cstr1, L"0123") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_oct |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"0123") == 0);
        assert(cstr2.Size() == 4);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_oct |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0123") == 0);
        assert(cstr3.Size() == 4);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_oct |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"0123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_oct |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"0123") == 0);
        assert(cstr5.Size() == 4);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_oct |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"0123") == 0);
        assert(cstr6.Size() == 4);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"123"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"0123") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"0123") == 0);
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0000000123") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"0123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"0123") == 0);
        assert(cstr5.Size() == 4);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"0000000123") == 0);
        assert(cstr6.Size() == 10);
    }

    {
        test::CString<wchar_t> val_cstr1{L"123"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"123") == 0);
        assert(cstr1.Size() == 3);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"123") == 0);
        assert(cstr2.Size() == 3);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"123") == 0);
        assert(cstr3.Size() == 3);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"123") == 0);
        assert(cstr4.Size() == 3);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"123") == 0);
        assert(cstr5.Size() == 3);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"123") == 0);
        assert(cstr6.Size() == 3);
    }

    {
        test::CString<wchar_t> val_cstr1{L"123"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"123") == 0);
        assert(cstr1.Size() == 3);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"123") == 0);
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0000000123") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"123") == 0);
        assert(cstr4.Size() == 3);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"123") == 0);
        assert(cstr5.Size() == 3);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"0000000123") == 0);
        assert(cstr6.Size() == 10);
    }

    {
        test::CString<wchar_t> val_cstr1{L"123"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"123") == 0);
        assert(cstr1.Size() == 3);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"123") == 0);
        assert(cstr2.Size() == 3);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"123") == 0);
        assert(cstr3.Size() == 3);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-123") == 0);
        assert(cstr5.Size() == 4);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-123") == 0);
        assert(cstr6.Size() == 4);
    }

    {
        test::CString<wchar_t> val_cstr1{L"123"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"123") == 0);
        assert(cstr1.Size() == 3);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"123") == 0);
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0000000123") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-123") == 0);
        assert(cstr5.Size() == 4);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-000000123") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"1.23") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"1.23") == 0);
        assert(cstr2.Size() == 4);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"1.23") == 0);
        assert(cstr3.Size() == 4);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.23") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-1.23") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<wchar_t> val_cstr1{L"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"1.23") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"1.23") == 0);
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0000001.23") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.23") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-000001.23") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"123"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"+123") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"+123") == 0);
        assert(cstr2.Size() == 4);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"+123") == 0);
        assert(cstr3.Size() == 4);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-123") == 0);
        assert(cstr5.Size() == 4);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-123") == 0);
        assert(cstr6.Size() == 4);
    }

    {
        test::CString<wchar_t> val_cstr1{L"123"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"+123") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"+123") == 0);
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"+000000123") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-123") == 0);
        assert(cstr5.Size() == 4);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-000000123") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"+1.23") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"+1.23") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"+1.23") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix | 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.23") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-1.23") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<wchar_t> val_cstr1{L"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"+1.23") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"+1.23") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"+000001.23") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.23") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-000001.23") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"123"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(wcscmp(*cstr1, L" 123") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L" 123") == 0);
        assert(cstr2.Size() == 4);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L" 123") == 0);
        assert(cstr3.Size() == 4);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-123") == 0);
        assert(cstr5.Size() == 4);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-123") == 0);
        assert(cstr6.Size() == 4);
    }

    {
        test::CString<wchar_t> val_cstr1{L"123"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(wcscmp(*cstr1, L" 123") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L" 123") == 0);
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L" 000000123") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-123") == 0);
        assert(cstr5.Size() == 4);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-000000123") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L" 1.23") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L" 1.23") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L" 1.23") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix | 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.23") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-1.23") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<wchar_t> val_cstr1{L"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L" 1.23") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L" 1.23") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L" 000001.23") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.23") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-000001.23") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"abc"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"0xabc") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"0xabc") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0xabc") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"0xabc") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"0xabc") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"0xabc") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<wchar_t> val_cstr1{L"abc"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"0xabc") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"0xabc") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0x00000abc") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"0xabc") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"0xabc") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"0x00000abc") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"0x1.ab") == 0);
        assert(cstr1.Size() == 6);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"0x1.ab") == 0);
        assert(cstr2.Size() == 6);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0x1.ab") == 0);
        assert(cstr3.Size() == 6);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-0x1.ab") == 0);
        assert(cstr5.Size() == 7);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-0x1.ab") == 0);
        assert(cstr6.Size() == 7);
    }

    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"0x1.ab") == 0);
        assert(cstr1.Size() == 6);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"0x1.ab") == 0);
        assert(cstr2.Size() == 6);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0x00001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-0x1.ab") == 0);
        assert(cstr5.Size() == 7);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-0x0001.ab") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"+0x1.ab") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"+0x1.ab") == 0);
        assert(cstr2.Size() == 7);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"+0x1.ab") == 0);
        assert(cstr3.Size() == 7);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix | 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-0x1.ab") == 0);
        assert(cstr5.Size() == 7);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-0x1.ab") == 0);
        assert(cstr6.Size() == 7);
    }

    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"+0x1.ab") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"+0x1.ab") == 0);
        assert(cstr2.Size() == 7);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"+0x0001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-0x1.ab") == 0);
        assert(cstr5.Size() == 7);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-0x0001.ab") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L" 0x1.ab") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L" 0x1.ab") == 0);
        assert(cstr2.Size() == 7);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L" 0x1.ab") == 0);
        assert(cstr3.Size() == 7);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix | 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-0x1.ab") == 0);
        assert(cstr5.Size() == 7);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-0x1.ab") == 0);
        assert(cstr6.Size() == 7);
    }

    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L" 0x1.ab") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L" 0x1.ab") == 0);
        assert(cstr2.Size() == 7);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L" 0x0001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-0x1.ab") == 0);
        assert(cstr5.Size() == 7);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-0x0001.ab") == 0);
        assert(cstr6.Size() == 10);
    }

    {
        test::CString<wchar_t> val_cstr1{L"abc"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"0xabc") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"0xabc") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0xabc") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"0xabc") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"0xabc") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"0xabc") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<wchar_t> val_cstr1{L"abc"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"0xabc") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"0xabc") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0x00000abc") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"0xabc") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"0xabc") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"0x00000abc") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"0x1.ab") == 0);
        assert(cstr1.Size() == 6);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"0x1.ab") == 0);
        assert(cstr2.Size() == 6);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0x1.ab") == 0);
        assert(cstr3.Size() == 6);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-0x1.ab") == 0);
        assert(cstr5.Size() == 7);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-0x1.ab") == 0);
        assert(cstr6.Size() == 7);
    }

    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"0x1.ab") == 0);
        assert(cstr1.Size() == 6);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"0x1.ab") == 0);
        assert(cstr2.Size() == 6);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0x00001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-0x1.ab") == 0);
        assert(cstr5.Size() == 7);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-0x0001.ab") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"+0x1.ab") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"+0x1.ab") == 0);
        assert(cstr2.Size() == 7);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"+0x1.ab") == 0);
        assert(cstr3.Size() == 7);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix | 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-0x1.ab") == 0);
        assert(cstr5.Size() == 7);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-0x1.ab") == 0);
        assert(cstr6.Size() == 7);
    }

    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"+0x1.ab") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"+0x1.ab") == 0);
        assert(cstr2.Size() == 7);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"+0x0001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-0x1.ab") == 0);
        assert(cstr5.Size() == 7);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-0x0001.ab") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L" 0x1.ab") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L" 0x1.ab") == 0);
        assert(cstr2.Size() == 7);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L" 0x1.ab") == 0);
        assert(cstr3.Size() == 7);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix | 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-0x1.ab") == 0);
        assert(cstr5.Size() == 7);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-0x1.ab") == 0);
        assert(cstr6.Size() == 7);
    }

    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L" 0x1.ab") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L" 0x1.ab") == 0);
        assert(cstr2.Size() == 7);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L" 0x0001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-0x1.ab") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-0x1.ab") == 0);
        assert(cstr5.Size() == 7);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-0x0001.ab") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"ABC"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"0XABC") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"0XABC") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0XABC") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"0XABC") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"0XABC") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_int | 
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"0XABC") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<wchar_t> val_cstr1{L"ABC"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"0XABC") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"0XABC") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0X00000ABC") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"0XABC") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"0XABC") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"0X00000ABC") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"0X1.AB") == 0);
        assert(cstr1.Size() == 6);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"0X1.AB") == 0);
        assert(cstr2.Size() == 6);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0X1.AB") == 0);
        assert(cstr3.Size() == 6);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-0X1.AB") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-0X1.AB") == 0);
        assert(cstr5.Size() == 7);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-0X1.AB") == 0);
        assert(cstr6.Size() == 7);
    }

    {
        test::CString<wchar_t> val_cstr1{L"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"0X1.AB") == 0);
        assert(cstr1.Size() == 6);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"0X1.AB") == 0);
        assert(cstr2.Size() == 6);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0X00001.AB") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-0X1.AB") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-0X1.AB") == 0);
        assert(cstr5.Size() == 7);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-0X0001.AB") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"+0X1.AB") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"+0X1.AB") == 0);
        assert(cstr2.Size() == 7);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"+0X1.AB") == 0);
        assert(cstr3.Size() == 7);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-0X1.AB") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix | 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-0X1.AB") == 0);
        assert(cstr5.Size() == 7);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-0X1.AB") == 0);
        assert(cstr6.Size() == 7);
    }

    {
        test::CString<wchar_t> val_cstr1{L"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"+0X1.AB") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"+0X1.AB") == 0);
        assert(cstr2.Size() == 7);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"+0X0001.AB") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-0X1.AB") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-0X1.AB") == 0);
        assert(cstr5.Size() == 7);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-0X0001.AB") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L" 0X1.AB") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L" 0X1.AB") == 0);
        assert(cstr2.Size() == 7);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L" 0X1.AB") == 0);
        assert(cstr3.Size() == 7);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-0X1.AB") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix | 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-0X1.AB") == 0);
        assert(cstr5.Size() == 7);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-0X1.AB") == 0);
        assert(cstr6.Size() == 7);
    }

    {
        test::CString<wchar_t> val_cstr1{L"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L" 0X1.AB") == 0);
        assert(cstr1.Size() == 7);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L" 0X1.AB") == 0);
        assert(cstr2.Size() == 7);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L" 0X0001.AB") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-0X1.AB") == 0);
        assert(cstr4.Size() == 7);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-0X1.AB") == 0);
        assert(cstr5.Size() == 7);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix |
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-0X0001.AB") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"123"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"123") == 0);
        assert(cstr1.Size() == 3);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"123") == 0);
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0000000123") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"123") == 0);
        assert(cstr4.Size() == 3);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"123") == 0);
        assert(cstr5.Size() == 3);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_oct |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"0000000123") == 0);
        assert(cstr6.Size() == 10);
    }

    {
        test::CString<wchar_t> val_cstr1{L"123"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"123") == 0);
        assert(cstr1.Size() == 3);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"123") == 0);
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0000000123") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"123") == 0);
        assert(cstr4.Size() == 3);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"123") == 0);
        assert(cstr5.Size() == 3);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"0000000123") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"123"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"123") == 0);
        assert(cstr1.Size() == 3);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"123") == 0);
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0000000123") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-123") == 0);
        assert(cstr5.Size() == 4);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-000000123") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"1.23") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"1.23") == 0);
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0000001.23") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.23") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-000001.23") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"123"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"+123") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"+123") == 0);
        assert(cstr2.Size() == 4);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"+123") == 0);
        assert(cstr3.Size() == 4);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-123") == 0);
        assert(cstr5.Size() == 4);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-123") == 0);
        assert(cstr6.Size() == 4);
    }

    {
        test::CString<wchar_t> val_cstr1{L"123"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"+123") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"+123") == 0);
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"+000000123") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-123") == 0);
        assert(cstr5.Size() == 4);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-000000123") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"+1.23") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"+1.23") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"+1.23") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.23") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-1.23") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<wchar_t> val_cstr1{L"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"+1.23") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"+1.23") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"+000001.23") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.23") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-000001.23") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"123"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(wcscmp(*cstr1, L" 123") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L" 123") == 0);
        assert(cstr2.Size() == 4);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L" 123") == 0);
        assert(cstr3.Size() == 4);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-123") == 0);
        assert(cstr5.Size() == 4);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_int | 
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-123") == 0);
        assert(cstr6.Size() == 4);
    }

    {
        test::CString<wchar_t> val_cstr1{L"123"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false);
        assert(wcscmp(*cstr1, L" 123") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L" 123") == 0);
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L" 000000123") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-123") == 0);
        assert(cstr4.Size() == 4);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-123") == 0);
        assert(cstr5.Size() == 4);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_int |
            FlagType::specifier_int_signed>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-000000123") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L" 1.23") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L" 1.23") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L" 1.23") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.23") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-1.23") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<wchar_t> val_cstr1{L"1.23"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L" 1.23") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L" 1.23") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L" 000001.23") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-1.23") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.23") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_dec |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-000001.23") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"abc"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"abc") == 0);
        assert(cstr1.Size() == 3);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"abc") == 0);
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0000000abc") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"abc") == 0);
        assert(cstr4.Size() == 3);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"abc") == 0);
        assert(cstr5.Size() == 3);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"0000000abc") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"1.ab") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"1.ab") == 0);
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0000001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-1.ab") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.ab") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-000001.ab") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"+1.ab") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"+1.ab") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"+1.ab") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-1.ab") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.ab") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-1.ab") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"+1.ab") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"+1.ab") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"+000001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-1.ab") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.ab") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-000001.ab") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L" 1.ab") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L" 1.ab") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L" 1.ab") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-1.ab") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.ab") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-1.ab") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false);
        assert(wcscmp(*cstr1, L" 1.ab") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L" 1.ab") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L" 000001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-1.ab") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.ab") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-000001.ab") == 0);
        assert(cstr6.Size() == 10);
    }

    {
        test::CString<wchar_t> val_cstr1{L"abc"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"abc") == 0);
        assert(cstr1.Size() == 3);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"abc") == 0);
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0000000abc") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"abc") == 0);
        assert(cstr4.Size() == 3);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"abc") == 0);
        assert(cstr5.Size() == 3);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"0000000abc") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"1.ab") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"1.ab") == 0);
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0000001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-1.ab") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.ab") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-000001.ab") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"+1.ab") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"+1.ab") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"+1.ab") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-1.ab") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.ab") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-1.ab") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"+1.ab") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"+1.ab") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"+000001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-1.ab") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.ab") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-000001.ab") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L" 1.ab") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L" 1.ab") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L" 1.ab") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-1.ab") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.ab") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-1.ab") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<wchar_t> val_cstr1{L"1.ab"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L" 1.ab") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L" 1.ab") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L" 000001.ab") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-1.ab") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.ab") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_lower_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-000001.ab") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"ABC"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"ABC") == 0);
        assert(cstr1.Size() == 3);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"ABC") == 0);
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0000000ABC") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"ABC") == 0);
        assert(cstr4.Size() == 3);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"ABC") == 0);
        assert(cstr5.Size() == 3);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_int |
            FlagType::specifier_int_unsigned |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"0000000ABC") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"1.AB") == 0);
        assert(cstr1.Size() == 4);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"1.AB") == 0);
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"0000001.AB") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-1.AB") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.AB") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-000001.AB") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"+1.AB") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"+1.AB") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"+1.AB") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-1.AB") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.AB") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-1.AB") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<wchar_t> val_cstr1{L"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L"+1.AB") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L"+1.AB") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L"+000001.AB") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-1.AB") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.AB") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_plus |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-000001.AB") == 0);
        assert(cstr6.Size() == 10);
    }
    
    {
        test::CString<wchar_t> val_cstr1{L"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L" 1.AB") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L" 1.AB") == 0);
        assert(cstr2.Size() == 5);
        
        auto cstr3 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L" 1.AB") == 0);
        assert(cstr3.Size() == 5);

        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 0);
        assert(wcscmp(*cstr4, L"-1.AB") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.AB") == 0);
        assert(cstr5.Size() == 5);
        
        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-1.AB") == 0);
        assert(cstr6.Size() == 5);
    }

    {
        test::CString<wchar_t> val_cstr1{L"1.AB"};
        auto cstr1 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false);
        assert(wcscmp(*cstr1, L" 1.AB") == 0);
        assert(cstr1.Size() == 5);
        
        auto cstr2 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 1);
        assert(wcscmp(*cstr2, L" 1.AB") == 0);
        assert(cstr2.Size() == 5);

        auto cstr3 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, false, 10);
        assert(wcscmp(*cstr3, L" 000001.AB") == 0);
        assert(cstr3.Size() == 10);
        
        auto cstr4 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true);
        assert(wcscmp(*cstr4, L"-1.AB") == 0);
        assert(cstr4.Size() == 5);
        
        auto cstr5 = test::out::print::Prefix::CStr<wchar_t,
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 1);
        assert(wcscmp(*cstr5, L"-1.AB") == 0);
        assert(cstr5.Size() == 5);

        auto cstr6 = test::out::print::Prefix::CStr<wchar_t, 
            FlagType::specifier_flag_prefix_space |
            FlagType::specifier_flag_prefix_zero |
            FlagType::specifier_base_hex |
            FlagType::specifier_fp |
            FlagType::specifier_upper_case>(val_cstr1, true, 10);
        assert(wcscmp(*cstr6, L"-000001.AB") == 0);
        assert(cstr6.Size() == 10);
    }
    return 0;
}
