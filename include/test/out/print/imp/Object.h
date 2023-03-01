#ifndef TEST_OUT_PRINT_IMP_OBJECT_H_
#define TEST_OUT_PRINT_IMP_OBJECT_H_

#include "../../../System.h"
#include "../../Definition.h"
#include "../../CString.h"
#include "../Object.h"
#include "sub/Width.h"
#include "sub/Length.h"

#include <cstddef>
#include <cwchar>
#include <type_traits>

namespace test
{
namespace out
{
namespace print
{
namespace imp
{

template<typename T, 
    test::out::Definition::FlagType::IntegerValueType VFlagInteger = 0>
struct Object
{
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;

    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Puts("...");
    }
    
};

template<typename T>
struct Object<T, test::out::print::Object::obj_fmt>
{
public:
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;
        
    template<typename TChar>
    using FormatOutputFuncType = 
        test::out::Definition::FormatOutputFuncType<TChar>;

private:
    template<typename T_, typename TChar>
    static constexpr std::false_type _HasOutputStaticFunc(...);
    template<typename T_, typename TChar>
    static constexpr auto _HasOutputStaticFunc(int) -> 
        decltype(test::out::print::imp::Object<T_>::
            Output(std::declval<OutputInterfaceType<TChar>&>(), NULL, 
                (std::size_t)0, FlagType{}, 0, 0), std::true_type());
public:
    template<typename T_, typename TChar>
    using HasOutputStaticFuncType = 
        decltype(_HasOutputStaticFunc<T_, TChar>(0));
protected:
    static std::size_t Output_(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return test::out::print::imp::Object<T>::Output(out, value, 
            value_size, flag, width, len_pred);
    }
    
    template<typename T_ = T, 
        typename TCond_ = HasOutputStaticFuncType<T_, wchar_t>,
        typename std::enable_if<TCond_::value, int>::type = 0>
    static std::size_t Output_(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return test::out::print::imp::Object<T>::Output(out, value, 
            value_size, flag, width, len_pred);
    }
    
    template<typename T_ = T, 
        typename TCond_ = HasOutputStaticFuncType<T_, wchar_t>,
        typename std::enable_if<!TCond_::value, int>::type = 1>
    static std::size_t Output_(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        test::out::CString<char> tmp;
        test::out::print::imp::Object<T>::Output(tmp, value, value_size, 
            flag, width, len_pred);
        return out.Print(L"%s", *(tmp.Get()));
    }
public:
    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        test::out::CString<char> tmp;
        test::out::print::imp::Object<T>::Output(tmp, value, 
            value_size, flag, width, len_pred);
        return out.Print("{%s}", *(tmp.Get()));
    }
    
    template<typename T_ = T, 
        typename TCond_ = HasOutputStaticFuncType<T_, wchar_t>,
        typename std::enable_if<TCond_::value, int>::type = 0>
    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        test::out::CString<wchar_t> tmp;
        test::out::print::imp::Object<T>::Output(tmp, value, 
            value_size, flag, width, len_pred);
        return out.Print(L"{%ls}", *(tmp.Get()));
    }
    
    template<typename T_ = T, 
        typename TCond_ = HasOutputStaticFuncType<T_, wchar_t>,
        typename std::enable_if<!TCond_::value, int>::type = 1>
    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        test::out::CString<char> tmp;
        test::out::print::imp::Object<T>::Output(tmp, value, value_size, 
            flag, width, len_pred);
        return out.Print(L"{%s}", *(tmp.Get()));
    }
};

template<typename T>
struct Object<T, test::out::print::Object::w_obj_fmt> :
    Object<T, test::out::print::Object::obj_fmt>
{
public:
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;
        
    template<typename TChar>
    using FormatOutputFuncType = 
        test::out::Definition::FormatOutputFuncType<TChar>;

public:
    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        typedef test::out::print::imp::sub::Width<
            test::out::print::sub::Width::w_fmt> WidthType;
        typedef test::out::print::imp::Object<T, 
            test::out::print::Object::obj_fmt> ObjectType;

        const auto fmt_out = (FormatOutputFuncType<char>) ObjectType::Output;
        return WidthType::Output(fmt_out, out, value, value_size, 
            flag, width, len_pred);
    }
    
    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        typedef test::out::print::imp::sub::Width<
            test::out::print::sub::Width::w_fmt> WidthType;
        typedef test::out::print::imp::Object<T, 
            test::out::print::Object::obj_fmt> ObjectType;

        const auto fmt_out = 
            (FormatOutputFuncType<wchar_t>) ObjectType::Output;
        return WidthType::Output(fmt_out, out, value, value_size, 
            flag, width, len_pred);
    }
    
};

template<typename T>
struct Object<T, test::out::print::Object::l_obj_fmt> :
    Object<T, test::out::print::Object::obj_fmt>
{
public:
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;
        
    template<typename TChar>
    using FormatOutputFuncType = 
        test::out::Definition::FormatOutputFuncType<TChar>;

public:
    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        typedef test::out::print::imp::sub::Length<
            test::out::print::sub::Length::l_fmt> LengthType;
        typedef test::out::print::imp::Object<T> ObjectType;

        if (len_pred <= 0)
        {
            return Object<T, test::out::print::Object::obj_fmt>::
                Output(out, value, value_size, flag, width, len_pred);
        }

        if (len_pred <= 2)
        {
            return out.Print("%.*s", len_pred, "{}");
        }

        test::out::CString<char> tmp;
        const auto fmt_out = (FormatOutputFuncType<char>) ObjectType::Output;
        const std::size_t size = LengthType::Output(fmt_out, tmp, 
            value, value_size, flag, width, len_pred);
        if (size == 0)
        {
            return out.Puts("{?}");
        }
        else if (len_pred <= 5)
        {
            return out.Print("{%.*s}", len_pred - 2, *(tmp.Get()));
        }
        else if ((size + 2) <= len_pred)
        {
            return out.Print("{%.*s}", size, *(tmp.Get()));
        }
        return out.Print("{%.*s...}", len_pred - 5, *(tmp.Get()));
    }
    
    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        typedef test::out::print::imp::sub::Length<
            test::out::print::sub::Length::l_fmt> LengthType;
        typedef Object<T, test::out::print::Object::obj_fmt> ObjectType;

        if (len_pred <= 0)
        {
            return Object<T, test::out::print::Object::obj_fmt>::
                Output(out, value, value_size, flag, width, len_pred);
        }

        if (len_pred <= 2)
        {
            return out.Print(L"%.*s", len_pred, "{}");
        }
        
        test::out::CString<wchar_t> tmp;
        const auto fmt_out = 
            (FormatOutputFuncType<wchar_t>) ObjectType::Output_;
        const std::size_t size = LengthType::Output(fmt_out, tmp, 
            value, value_size, flag, width, len_pred);
        if (size == 0)
        {
            return out.Puts(L"{?}");
        }
        else if (len_pred <= 5)
        {
            return out.Print(L"{%.*ls}", len_pred - 2, *(tmp.Get()));
        }
        else if ((size + 2) <= len_pred)
        {
            return out.Print(L"{%.*ls}", size, *(tmp.Get()));
        }
        return out.Print(L"{%.*ls...}", len_pred - 5, *(tmp.Get()));
    }
    
};

template<typename T>
struct Object<T, test::out::print::Object::wl_obj_fmt> :
    Object<T, test::out::print::Object::obj_fmt>
{
public:
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;
        
    template<typename TChar>
    using FormatOutputFuncType = 
        test::out::Definition::FormatOutputFuncType<TChar>;
private:
    template<typename T_, typename TChar>
    static constexpr std::false_type _HasOutputStaticFunc(...);
    template<typename T_, typename TChar>
    static constexpr auto _HasOutputStaticFunc(int) -> 
        decltype(test::out::print::imp::Object<T_>::
            Output(std::declval<OutputInterfaceType<TChar>&>(), NULL, 
                (std::size_t)0, FlagType{}, 0, 0), std::true_type());
public:
    template<typename T_, typename TChar>
    using HasOutputStaticFuncType = decltype(_HasOutputStaticFunc<T_, TChar>(0));
public:
    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        typedef test::out::print::imp::Object<T,
            test::out::print::Object::l_obj_fmt> ObjectType;
        
        test::out::CString<char> tmp;
        ObjectType::Output(tmp, value, value_size, flag, width, len_pred);
        return out.Print("%*s", width, *(tmp.Get()));
    }
    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        typedef test::out::print::imp::Object<T,
            test::out::print::Object::l_obj_fmt> ObjectType;
            
        test::out::CString<wchar_t> tmp;
        ObjectType::Output(tmp, value, value_size, flag, width, len_pred);
        return out.Print(L"%*ls", width, *(tmp.Get()));
    }
};

} //!imp

} //!print

} //!out

} //!test

#ifndef TEST_OUT_PRINT_IMP_OBJECT_DLEVEL

#define TEST_OUT_PRINT_IMP_OBJECT_DLEVEL 2

#endif //!TEST_OUT_PRINT_IMP_OBJECT_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>,\
    test::sys::dbg::type::Value<typename test::out::Definition::FlagType::\
        IntegerValueType, VFlagInteger>

template<typename T,
    test::out::Definition::FlagType::IntegerValueType VFlagInteger>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_PRINT_IMP_OBJECT_DLEVEL, 
    "test::out::print::imp::Object", 
    test::out::print::imp::Object<T, VFlagInteger>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#endif //!TEST_OUT_PRINT_IMP_OBJECT_H_
