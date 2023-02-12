#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/fmt/arg/Object.h"

#include <cassert>

class Obj1
{
    int val;
public:
    Obj1() : val(-1){}
    Obj1(int v) : val(v){}
    Obj1(const Obj1& cpy) : val(cpy.val){}
    Obj1(Obj1&& mov) : val(mov.val){}
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
    }
    return 0;
}