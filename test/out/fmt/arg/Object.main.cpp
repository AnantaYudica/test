#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/fmt/arg/Object.h"

#include <cassert>

template<typename TChar>
using FormatOutputFuncType = test::out::fmt::Definition::
    FormatOutputFuncType<TChar>;

static std::size_t count_obj1 = 0;

class Obj1
{
    int val;
public:
    Obj1() : val(-1){ count_obj1++; }
    Obj1(int v) : val(v){ count_obj1++; }
    Obj1(const Obj1& cpy) : val(cpy.val){ count_obj1++; }
    Obj1(Obj1&& mov) : val(mov.val){ count_obj1++; }
    ~Obj1() { count_obj1--; }
    int Value() const 
    {
        return val;
    }
};

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
        test::out::fmt::arg::Object<Obj1> arg1;
        
        assert(arg1.GetFlag().IsSpecifierObject() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        
        constexpr auto fmt = test::out::print::Object::obj_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Object<Obj1, fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Object<Obj1, fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Object<Obj1> arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierObject() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Object::w_obj_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Object<Obj1, fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Object<Obj1, fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Object<Obj1> arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierObject() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Object::l_obj_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Object<Obj1, fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Object<Obj1, fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Object<Obj1> arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierObject() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Object::l_obj_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Object<Obj1, fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Object<Obj1, fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        Obj1 o1(4);
        test::out::fmt::arg::Object<Obj1> arg1{o1};
        
        assert(arg1.GetFlag().IsSpecifierObject() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetValue().Value() == 4);
        
        constexpr auto fmt = test::out::print::Object::obj_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Object<Obj1, fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Object<Obj1, fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        Obj1 o1(4);
        test::out::fmt::arg::Object<Obj1> arg1{o1,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierObject() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetValue().Value() == 4);
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Object::w_obj_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Object<Obj1, fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Object<Obj1, fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        Obj1 o1(4);
        test::out::fmt::arg::Object<Obj1> arg1{o1,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierObject() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetValue().Value() == 4);
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Object::l_obj_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Object<Obj1, fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Object<Obj1, fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        Obj1 o1(4);
        test::out::fmt::arg::Object<Obj1> arg1{o1,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierObject() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetValue().Value() == 4);
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Object::l_obj_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Object<Obj1, fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Object<Obj1, fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    
    {
        Obj1 o1(4);
        test::out::fmt::arg::Object<Obj1> arg1{o1,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40}
        };

        assert(arg1.GetFlag().IsSpecifierObject() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetValue().Value() == 4);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetLength() == 40);
        
        constexpr auto fmt = test::out::print::Object::wl_obj_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Object<Obj1, fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Object<Obj1, fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        Obj1 o1(4);
        test::out::fmt::arg::Object<Obj1> arg1{o1,
            test::out::fmt::flag::Output<char>(&Fun1<char>)};
        
        assert(arg1.GetFlag().IsSpecifierObject() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == true);
        assert(arg1.GetValue().Value() == 4);
        
        assert(arg1.GetFormatOutput().template Get<char>() == &Fun1<char>);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            nullptr);
    }
    {
        Obj1 o1(4);
        test::out::fmt::arg::Object<Obj1> arg1{o1,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Output<char>(&Fun1<char>)
        };

        assert(arg1.GetFlag().IsSpecifierObject() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == true);
        assert(arg1.GetValue().Value() == 4);
        assert(arg1.GetWidth() == 20);
        
        assert(arg1.GetFormatOutput().template Get<char>() == &Fun1<char>);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            nullptr);
    }
    {
        Obj1 o1(4);
        test::out::fmt::arg::Object<Obj1> arg1{o1,
            test::out::fmt::flag::Length{20},
            test::out::fmt::flag::Output<char>(&Fun1<char>)
        };

        assert(arg1.GetFlag().IsSpecifierObject() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == true);
        assert(arg1.GetValue().Value() == 4);
        assert(arg1.GetLength() == 20);
        
        assert(arg1.GetFormatOutput().template Get<char>() == &Fun1<char>);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            nullptr);
    }
    {
        Obj1 o1(4);
        test::out::fmt::arg::Object<Obj1> arg1{o1,
            test::out::fmt::flag::Precision{20},
            test::out::fmt::flag::Output<char>(&Fun1<char>)
        };

        assert(arg1.GetFlag().IsSpecifierObject() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == true);
        assert(arg1.GetValue().Value() == 4);
        assert(arg1.GetPrecision() == 20);
        
        assert(arg1.GetFormatOutput().template Get<char>() == &Fun1<char>);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            nullptr);
    }
    {
        test::out::fmt::arg::Object<Obj1> arg1{
            Obj1{10},
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierObject() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetValue().Value() == 10);
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Object::l_obj_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Object<Obj1, fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Object<Obj1, fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Object<Obj1> arg1{
            Obj1{10},
            test::out::fmt::flag::Output<char>(&Fun1<char>)};
        
        assert(arg1.GetFlag().IsSpecifierObject() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == true);
        assert(arg1.GetValue().Value() == 10);
        
        assert(arg1.GetFormatOutput().template Get<char>() == &Fun1<char>);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            nullptr);
    }
    {
        test::out::fmt::arg::Object<Obj1> arg1{
            Obj1{10},
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Output<char>(&Fun1<char>)
        };

        assert(arg1.GetFlag().IsSpecifierObject() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == true);
        assert(arg1.GetValue().Value() == 10);
        assert(arg1.GetWidth() == 20);
        
        assert(arg1.GetFormatOutput().template Get<char>() == &Fun1<char>);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            nullptr);
    }
    {
        test::out::fmt::arg::Object<Obj1> arg1{
            Obj1{10},
            test::out::fmt::flag::Length{20},
            test::out::fmt::flag::Output<char>(&Fun1<char>)
        };

        assert(arg1.GetFlag().IsSpecifierObject() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == true);
        assert(arg1.GetValue().Value() == 10);
        assert(arg1.GetLength() == 20);
        
        assert(arg1.GetFormatOutput().template Get<char>() == &Fun1<char>);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            nullptr);
    }
    {
        test::out::fmt::arg::Object<Obj1> arg1{
            Obj1{10},
            test::out::fmt::flag::Precision{20},
            test::out::fmt::flag::Output<char>(&Fun1<char>)
        };

        assert(arg1.GetFlag().IsSpecifierObject() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == true);
        assert(arg1.GetValue().Value() == 10);
        assert(arg1.GetPrecision() == 20);
        
        assert(arg1.GetFormatOutput().template Get<char>() == &Fun1<char>);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            nullptr);
    }
    {
        test::out::fmt::arg::Object<Obj1> arg1{
            Obj1{10},
            test::out::fmt::flag::Length{40},
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Output<char>(&Fun1<char>)
        };

        assert(arg1.GetFlag().IsSpecifierObject() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == true);
        assert(arg1.GetValue().Value() == 10);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetLength() == 40);
        
        assert(arg1.GetFormatOutput().template Get<char>() == &Fun1<char>);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            nullptr);
    }
    {
        test::out::fmt::arg::Object<int> arg1;
        
        assert(arg1.GetFlag().IsSpecifierObject() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() ==
            (arg1.GetFlag().define_int | arg1.GetFlag().define_signed));
            
        constexpr auto fmt = test::out::print::Object::obj_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Object<int, fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Object<int, fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Object<unsigned int> arg1;
        
        assert(arg1.GetFlag().IsSpecifierObject() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() ==
            (arg1.GetFlag().define_int | arg1.GetFlag().define_unsigned));

        constexpr auto fmt = test::out::print::Object::obj_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Object<unsigned int, fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Object<unsigned int, fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        assert(count_obj1 == 0);
    }
    return 0;
}