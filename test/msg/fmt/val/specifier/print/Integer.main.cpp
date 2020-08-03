#include "test/msg/fmt/param/specifier/print/Integer.h"
#include "test/out/CString.h"

#include <cassert>
#include <cstring>

int main()
{
    using namespace test::msg::fmt::param;
    specifier::val::Integer val1{.char_value='Z'};
    specifier::val::Integer val2{.short_value=static_cast<short>(-1)};
    specifier::val::Integer val3{.int_value=-1};
    specifier::val::Integer val4{.long_value=-1L};
    specifier::val::Integer val5{.long_long_value=-1LL};
    Width<char> wd1{25};
    Length<char> len1{20};
    {
        constexpr flag::Integer i1{};
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%i", 
            val1.int_value);
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //default
    {
        constexpr flag::Integer i1{
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%lli", 
            val5.long_long_value);
        len_a += out_cstr1_a.Print("%hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%lli", 
            val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal
    {
        constexpr flag::Integer i1{
            flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%lli", 
            val5.long_long_value);
        len_a += out_cstr1_a.Print("%hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%lli", 
            val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%lli", 
            val5.long_long_value);
        len_a += out_cstr1_a.Print("%hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%lli", 
            val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal
    {
        constexpr flag::Integer i1{
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%lli", 
            val5.long_long_value);
        len_a += out_cstr1_a.Print("%hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%lli", 
            val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%lli", 
            val5.long_long_value);
        len_a += out_cstr1_a.Print("%hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%lli", 
            val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-decimal
    {
        constexpr flag::Integer i1{
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%hhu", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%hu", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%u", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lu", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llu", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%hhu", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%hu", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%u", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lu", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llu", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%hhu", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%hu", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%u", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lu", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llu", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%hhu", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%hu", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%u", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lu", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llu", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //octal
    {
        constexpr flag::Integer i1{
            flag::arg::Octal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Octal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Octal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Octal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Octal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llo", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llo", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //octal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llo", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llo", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsinged-octal
    {
        constexpr flag::Integer i1{
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llo", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llo", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-octal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llo", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llo", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal
    {
        constexpr flag::Integer i1{
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llx", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llx", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llx", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llx", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal-upper
    {
        constexpr flag::Integer i1{
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%hhX", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%hX", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%X", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lX", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llX", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%hhX", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%hX", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%X", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lX", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llX", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal
    {
        constexpr flag::Integer i1{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llx", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llx", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llx", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llx", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal-upper
    {
        constexpr flag::Integer i1{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%hhX", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%hX", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%X", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lX", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llX", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%hhX", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%hX", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%X", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%lX", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%llX", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //prefix
    //default
    //decimal
    //decimal-lower
    //signed-decimal
    //signed-decimal-lower
    //unsigned-decimal
    //unsigned-decimal-lower
    //octal
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#llo", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#llo", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //octal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#llo", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#llo", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsinged-octal
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#llo", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#llo", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-octal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#llo", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#llo", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#llx", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#llx", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#llx", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#llx", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal-upper
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#hhX", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#hX", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#X", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#lX", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#llX", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#hhX", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#hX", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#X", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#lX", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#llX", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#llx", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#llx", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#llx", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#llx", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal-upper
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#hhX", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#hX", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#X", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#lX", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#llX", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#hhX", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#hX", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#X", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#lX", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#llX", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //prefix-plus
    //default
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixPlus{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixPlus{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixPlus{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixPlus{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixPlus{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixPlus{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixPlus{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixPlus{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixPlus{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixPlus{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%+hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%+hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%+i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%+li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%+lli", 
            val5.long_long_value);
        len_a += out_cstr1_a.Print("%+hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%+hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%+i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%+li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%+lli", 
            val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixPlus{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixPlus{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixPlus{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixPlus{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixPlus{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixPlus{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixPlus{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixPlus{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixPlus{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixPlus{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%+hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%+hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%+i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%+li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%+lli", 
            val5.long_long_value);
        len_a += out_cstr1_a.Print("%+hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%+hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%+i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%+li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%+lli", 
            val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixPlus{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixPlus{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixPlus{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixPlus{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixPlus{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixPlus{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixPlus{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixPlus{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixPlus{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixPlus{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%+hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%+hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%+i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%+li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%+lli", 
            val5.long_long_value);
        len_a += out_cstr1_a.Print("%+hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%+hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%+i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%+li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%+lli", 
            val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixPlus{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixPlus{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixPlus{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixPlus{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixPlus{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixPlus{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixPlus{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixPlus{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixPlus{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixPlus{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%+hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%+hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%+i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%+li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%+lli", 
            val5.long_long_value);
        len_a += out_cstr1_a.Print("%+hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%+hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%+i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%+li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%+lli", 
            val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixPlus{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixPlus{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixPlus{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixPlus{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixPlus{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixPlus{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixPlus{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixPlus{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixPlus{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixPlus{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%+hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%+hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%+i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%+li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%+lli", 
            val5.long_long_value);
        len_a += out_cstr1_a.Print("%+hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%+hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%+i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%+li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%+lli", 
            val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-decimal
    //unsigned-decimal-lower
    //octal
    //octal-lower
    //unsinged-octal
    //unsigned-octal-lower
    //hexadecimal
    //hexadecimal-lower
    //hexadecimal-upper
    //unsigned-hexadecimal
    //unsigned-hexadecimal-lower
    //unsigned-hexadecimal-upper
    //prefix-space
    //default
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixSpace{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixSpace{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixSpace{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixSpace{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixSpace{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixSpace{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixSpace{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixSpace{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixSpace{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixSpace{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("% hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("% hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("% i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("% li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("% lli", 
            val5.long_long_value);
        len_a += out_cstr1_a.Print("% hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("% hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("% i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("% li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("% lli", 
            val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixSpace{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixSpace{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixSpace{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixSpace{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixSpace{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixSpace{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixSpace{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixSpace{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixSpace{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixSpace{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("% hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("% hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("% i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("% li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("% lli", 
            val5.long_long_value);
        len_a += out_cstr1_a.Print("% hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("% hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("% i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("% li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("% lli", 
            val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixSpace{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixSpace{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixSpace{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixSpace{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixSpace{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixSpace{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixSpace{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixSpace{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixSpace{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixSpace{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("% hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("% hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("% i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("% li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("% lli", 
            val5.long_long_value);
        len_a += out_cstr1_a.Print("% hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("% hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("% i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("% li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("% lli", 
            val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixSpace{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixSpace{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixSpace{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixSpace{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixSpace{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixSpace{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixSpace{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixSpace{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixSpace{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixSpace{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("% hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("% hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("% i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("% li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("% lli", 
            val5.long_long_value);
        len_a += out_cstr1_a.Print("% hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("% hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("% i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("% li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("% lli", 
            val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixSpace{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixSpace{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixSpace{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixSpace{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixSpace{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixSpace{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixSpace{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixSpace{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixSpace{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixSpace{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("% hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("% hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("% i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("% li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("% lli", 
            val5.long_long_value);
        len_a += out_cstr1_a.Print("% hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("% hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("% i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("% li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("% lli", 
            val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-decimal
    //unsigned-decimal-lower
    //octal
    //octal-lower
    //unsinged-octal
    //unsigned-octal-lower
    //hexadecimal
    //hexadecimal-lower
    //hexadecimal-upper
    //unsigned-hexadecimal
    //unsigned-hexadecimal-lower
    //unsigned-hexadecimal-upper
    //prefix-zero
    //default
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%0hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%0i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%0li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%0lli", 
            val5.long_long_value);
        len_a += out_cstr1_a.Print("%0hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%0hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%0i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%0li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%0lli", 
            val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%0hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%0i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%0li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%0lli", 
            val5.long_long_value);
        len_a += out_cstr1_a.Print("%0hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%0hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%0i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%0li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%0lli", 
            val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%0hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%0i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%0li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%0lli", 
            val5.long_long_value);
        len_a += out_cstr1_a.Print("%0hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%0hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%0i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%0li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%0lli", 
            val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%0hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%0i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%0li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%0lli", 
            val5.long_long_value);
        len_a += out_cstr1_a.Print("%0hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%0hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%0i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%0li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%0lli", 
            val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%0hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%0i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%0li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%0lli", 
            val5.long_long_value);
        len_a += out_cstr1_a.Print("%0hhi", 
            val1.char_value);
        len_a += out_cstr1_a.Print("%0hi", 
            val2.short_value);
        len_a += out_cstr1_a.Print("%0i", 
            val3.int_value);
        len_a += out_cstr1_a.Print("%0li", 
            val4.long_value);
        len_a += out_cstr1_a.Print("%0lli", 
            val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0hhu", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0hu", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0u", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lu", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llu", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0hhu", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0hu", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0u", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lu", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llu", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0hhu", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0hu", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0u", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lu", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llu", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0hhu", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0hu", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0u", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lu", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llu", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //octal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llo", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llo", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //octal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llo", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llo", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsinged-octal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llo", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llo", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-octal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llo", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0hho", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0ho", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0o", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lo", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llo", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llx", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llx", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llx", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llx", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal-upper
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0hhX", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0hX", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0X", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lX", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llX", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0hhX", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0hX", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0X", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lX", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llX", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llx", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llx", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llx", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0hhx", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0hx", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0x", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lx", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llx", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal-upper
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0hhX", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0hX", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0X", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lX", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llX", 
            val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0hhX", 
            val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0hX", 
            val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0X", 
            val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0lX", 
            val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0llX", 
            val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //width
    //default
    {
        constexpr flag::Integer i1{
            flag::arg::Width{},
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{},
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{},
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{},
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{},
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{},
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{},
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{},
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{},
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{},
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%*lli", 
            wd1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%*lli", 
            wd1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal
    {
        constexpr flag::Integer i1{
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%*lli", 
            wd1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%*lli", 
            wd1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%*lli", 
            wd1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%*lli", 
            wd1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal
    {
        constexpr flag::Integer i1{
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%*lli", 
            wd1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%*lli", 
            wd1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%*lli", 
            wd1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%*lli", 
            wd1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-decimal
    {
        constexpr flag::Integer i1{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*hhu", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hu", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*u", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lu", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llu", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*hhu", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hu", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*u", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lu", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llu", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*hhu", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hu", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*u", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lu", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llu", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*hhu", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hu", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*u", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lu", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llu", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //octal
    {
        constexpr flag::Integer i1{
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //octal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsinged-octal
    {
        constexpr flag::Integer i1{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-octal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal
    {
        constexpr flag::Integer i1{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal-upper
    {
        constexpr flag::Integer i1{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*hhX", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hX", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*X", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lX", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llX", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*hhX", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hX", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*X", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lX", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llX", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal
    {
        constexpr flag::Integer i1{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal-upper
    {
        constexpr flag::Integer i1{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*hhX", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hX", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*X", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lX", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llX", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*hhX", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hX", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*X", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lX", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llX", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //prefix
    //default
    //decimal
    //decimal-lower
    //signed-decimal
    //signed-decimal-lower
    //unsigned-decimal
    //unsigned-decimal-lower
    //octal
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //octal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsinged-octal
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-octal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal-upper
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#*hhX", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*hX", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*X", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*lX", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*llX", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#*hhX", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*hX", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*X", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*lX", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*llX", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal-upper
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#*hhX", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*hX", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*X", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*lX", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*llX", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#*hhX", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*hX", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*X", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*lX", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*llX", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //prefix-plus
    //default
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%+*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+*lli", 
            wd1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%+*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+*lli", 
            wd1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%+*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+*lli", 
            wd1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%+*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+*lli", 
            wd1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%+*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+*lli", 
            wd1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%+*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+*lli", 
            wd1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%+*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+*lli", 
            wd1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%+*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+*lli", 
            wd1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%+*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+*lli", 
            wd1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%+*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+*lli", 
            wd1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-decimal
    //unsigned-decimal-lower
    //octal
    //octal-lower
    //unsinged-octal
    //unsigned-octal-lower
    //hexadecimal
    //hexadecimal-lower
    //hexadecimal-upper
    //unsigned-hexadecimal
    //unsigned-hexadecimal-lower
    //unsigned-hexadecimal-upper
    //prefix-space
    //default
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("% *hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% *hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% *i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% *li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% *lli", 
            wd1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("% *hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% *hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% *i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% *li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% *lli", 
            wd1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("% *hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% *hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% *i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% *li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% *lli", 
            wd1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("% *hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% *hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% *i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% *li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% *lli", 
            wd1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("% *hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% *hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% *i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% *li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% *lli", 
            wd1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("% *hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% *hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% *i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% *li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% *lli", 
            wd1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("% *hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% *hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% *i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% *li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% *lli", 
            wd1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("% *hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% *hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% *i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% *li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% *lli", 
            wd1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("% *hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% *hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% *i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% *li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% *lli", 
            wd1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("% *hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% *hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% *i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% *li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% *lli", 
            wd1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-decimal
    //unsigned-decimal-lower
    //octal
    //octal-lower
    //unsinged-octal
    //unsigned-octal-lower
    //hexadecimal
    //hexadecimal-lower
    //hexadecimal-upper
    //unsigned-hexadecimal
    //unsigned-hexadecimal-lower
    //unsigned-hexadecimal-upper
    //prefix-zero
    //default
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%0*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%0*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%0*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%0*lli", 
            wd1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%0*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%0*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%0*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%0*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%0*lli", 
            wd1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%0*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%0*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%0*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%0*lli", 
            wd1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%0*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%0*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%0*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%0*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%0*lli", 
            wd1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%0*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%0*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%0*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%0*lli", 
            wd1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%0*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%0*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%0*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%0*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%0*lli", 
            wd1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%0*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%0*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%0*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%0*lli", 
            wd1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%0*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%0*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%0*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%0*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%0*lli", 
            wd1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%0*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%0*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%0*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%0*lli", 
            wd1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%0*hhi", 
            wd1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%0*hi", 
            wd1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%0*i", 
            wd1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%0*li", 
            wd1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%0*lli", 
            wd1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0*hhu", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*hu", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*u", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lu", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llu", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0*hhu", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*hu", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*u", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lu", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llu", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0*hhu", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*hu", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*u", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lu", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llu", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0*hhu", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*hu", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*u", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lu", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llu", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //octal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //octal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsinged-octal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-octal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0*hho", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*ho", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*o", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lo", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llo", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal-upper
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0*hhX", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*hX", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*X", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lX", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llX", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0*hhX", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*hX", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*X", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lX", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llX", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0*hhx", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*hx", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*x", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lx", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llx", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal-upper
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixZero{}, 
            flag::arg::Width{},
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%0*hhX", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*hX", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*X", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lX", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llX", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%0*hhX", 
            wd1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%0*hX", 
            wd1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%0*X", 
            wd1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%0*lX", 
            wd1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%0*llX", 
            wd1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //length
    //default
    {
        constexpr flag::Integer i1{
            flag::arg::Length{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Length{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Length{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Length{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Length{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Length{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Length{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Length{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Length{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Length{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%.*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%.*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%.*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%.*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%.*lli", 
            len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%.*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%.*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%.*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%.*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%.*lli", 
            len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal
    {
        constexpr flag::Integer i1{
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%.*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%.*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%.*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%.*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%.*lli", 
            len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%.*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%.*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%.*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%.*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%.*lli", 
            len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%.*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%.*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%.*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%.*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%.*lli", 
            len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%.*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%.*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%.*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%.*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%.*lli", 
            len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal
    {
        constexpr flag::Integer i1{
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%.*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%.*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%.*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%.*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%.*lli", 
            len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%.*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%.*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%.*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%.*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%.*lli", 
            len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%.*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%.*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%.*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%.*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%.*lli", 
            len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%.*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%.*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%.*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%.*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%.*lli", 
            len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-decimal
    {
        constexpr flag::Integer i1{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%.*hhu", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hu", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*u", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lu", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llu", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%.*hhu", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hu", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*u", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lu", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llu", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%.*hhu", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hu", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*u", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lu", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llu", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%.*hhu", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hu", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*u", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lu", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llu", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //octal
    {
        constexpr flag::Integer i1{
            flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%.*hho", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*ho", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*o", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lo", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llo", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%.*hho", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*ho", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*o", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lo", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llo", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //octal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%.*hho", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*ho", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*o", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lo", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llo", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%.*hho", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*ho", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*o", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lo", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llo", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsinged-octal
    {
        constexpr flag::Integer i1{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%.*hho", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*ho", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*o", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lo", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llo", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%.*hho", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*ho", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*o", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lo", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llo", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-octal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%.*hho", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*ho", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*o", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lo", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llo", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%.*hho", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*ho", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*o", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lo", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llo", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal
    {
        constexpr flag::Integer i1{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%.*hhx", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hx", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*x", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lx", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llx", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%.*hhx", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hx", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*x", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lx", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llx", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%.*hhx", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hx", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*x", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lx", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llx", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%.*hhx", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hx", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*x", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lx", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llx", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal-upper
    {
        constexpr flag::Integer i1{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%.*hhX", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hX", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*X", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lX", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llX", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%.*hhX", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hX", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*X", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lX", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llX", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal
    {
        constexpr flag::Integer i1{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%.*hhx", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hx", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*x", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lx", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llx", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%.*hhx", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hx", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*x", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lx", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llx", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%.*hhx", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hx", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*x", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lx", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llx", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%.*hhx", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hx", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*x", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lx", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llx", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal-upper
    {
        constexpr flag::Integer i1{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%.*hhX", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hX", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*X", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lX", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llX", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%.*hhX", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hX", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*X", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lX", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llX", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //prefix
    //default
    //decimal
    //decimal-lower
    //signed-decimal
    //signed-decimal-lower
    //unsigned-decimal
    //unsigned-decimal-lower
    //octal
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#.*hho", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#.*ho", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#.*o", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#.*lo", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#.*llo", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#.*hho", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#.*ho", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#.*o", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#.*lo", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#.*llo", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //octal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#.*hho", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#.*ho", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#.*o", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#.*lo", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#.*llo", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#.*hho", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#.*ho", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#.*o", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#.*lo", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#.*llo", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsinged-octal
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#.*hho", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#.*ho", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#.*o", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#.*lo", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#.*llo", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#.*hho", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#.*ho", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#.*o", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#.*lo", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#.*llo", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-octal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#.*hho", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#.*ho", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#.*o", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#.*lo", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#.*llo", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#.*hho", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#.*ho", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#.*o", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#.*lo", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#.*llo", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#.*hhx", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#.*hx", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#.*x", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#.*lx", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#.*llx", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#.*hhx", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#.*hx", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#.*x", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#.*lx", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#.*llx", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#.*hhx", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#.*hx", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#.*x", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#.*lx", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#.*llx", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#.*hhx", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#.*hx", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#.*x", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#.*lx", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#.*llx", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal-upper
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#.*hhX", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#.*hX", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#.*X", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#.*lX", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#.*llX", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#.*hhX", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#.*hX", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#.*X", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#.*lX", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#.*llX", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#.*hhx", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#.*hx", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#.*x", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#.*lx", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#.*llx", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#.*hhx", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#.*hx", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#.*x", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#.*lx", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#.*llx", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#.*hhx", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#.*hx", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#.*x", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#.*lx", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#.*llx", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#.*hhx", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#.*hx", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#.*x", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#.*lx", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#.*llx", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal-upper
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#.*hhX", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#.*hX", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#.*X", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#.*lX", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#.*llX", 
            len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#.*hhX", 
            len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#.*hX", 
            len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#.*X", 
            len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#.*lX", 
            len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#.*llX", 
            len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //prefix-plus
    //default
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%+.*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+.*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+.*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+.*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+.*lli", 
            len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%+.*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+.*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+.*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+.*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+.*lli", 
            len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%+.*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+.*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+.*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+.*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+.*lli", 
            len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%+.*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+.*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+.*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+.*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+.*lli", 
            len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%+.*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+.*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+.*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+.*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+.*lli", 
            len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%+.*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+.*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+.*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+.*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+.*lli", 
            len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%+.*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+.*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+.*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+.*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+.*lli", 
            len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%+.*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+.*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+.*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+.*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+.*lli", 
            len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixPlus{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%+.*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+.*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+.*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+.*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+.*lli", 
            len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%+.*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+.*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+.*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+.*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+.*lli", 
            len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-decimal
    //unsigned-decimal-lower
    //octal
    //octal-lower
    //unsinged-octal
    //unsigned-octal-lower
    //hexadecimal
    //hexadecimal-lower
    //hexadecimal-upper
    //unsigned-hexadecimal
    //unsigned-hexadecimal-lower
    //unsigned-hexadecimal-upper
    //prefix-space
    //default
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("% .*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% .*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% .*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% .*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% .*lli", 
            len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("% .*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% .*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% .*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% .*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% .*lli", 
            len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("% .*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% .*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% .*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% .*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% .*lli", 
            len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("% .*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% .*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% .*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% .*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% .*lli", 
            len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("% .*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% .*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% .*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% .*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% .*lli", 
            len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("% .*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% .*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% .*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% .*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% .*lli", 
            len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("% .*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% .*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% .*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% .*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% .*lli", 
            len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("% .*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% .*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% .*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% .*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% .*lli", 
            len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixSpace{}, 
            flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("% .*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% .*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% .*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% .*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% .*lli", 
            len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("% .*hhi", 
            len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% .*hi", 
            len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% .*i", 
            len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% .*li", 
            len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% .*lli", 
            len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-decimal
    //unsigned-decimal-lower
    //octal
    //octal-lower
    //unsinged-octal
    //unsigned-octal-lower
    //hexadecimal
    //hexadecimal-lower
    //hexadecimal-upper
    //unsigned-hexadecimal
    //unsigned-hexadecimal-lower
    //unsigned-hexadecimal-upper
    //prefix-zero
    //default
    //decimal
    //decimal-lower
    //signed-decimal
    //signed-decimal-lower
    //unsigned-decimal
    //unsigned-decimal-lower
    //octal
    //octal-lower
    //unsinged-octal
    //unsigned-octal-lower
    //hexadecimal
    //hexadecimal-lower
    //hexadecimal-upper
    //unsigned-hexadecimal
    //unsigned-hexadecimal-lower
    //unsigned-hexadecimal-upper
    //width-length
    //default
    {
        constexpr flag::Integer i1{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%*.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%*.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%*.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%*.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%*.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%*.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%*.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%*.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%*.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal
    {
        constexpr flag::Integer i1{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%*.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%*.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%*.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%*.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%*.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%*.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%*.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%*.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%*.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%*.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%*.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%*.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%*.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%*.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%*.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%*.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%*.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%*.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal
    {
        constexpr flag::Integer i1{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%*.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%*.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%*.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%*.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%*.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%*.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%*.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%*.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%*.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%*.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%*.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%*.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%*.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%*.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%*.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%*.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%*.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%*.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-decimal
    {
        constexpr flag::Integer i1{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*.*hhu", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hu", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*u", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lu", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llu", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*.*hhu", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hu", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*u", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lu", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llu", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*.*hhu", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hu", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*u", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lu", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llu", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*.*hhu", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hu", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*u", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lu", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llu", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //octal
    {
        constexpr flag::Integer i1{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*.*hho", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*ho", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*o", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lo", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llo", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*.*hho", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*ho", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*o", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lo", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llo", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //octal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*.*hho", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*ho", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*o", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lo", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llo", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*.*hho", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*ho", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*o", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lo", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llo", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsinged-octal
    {
        constexpr flag::Integer i1{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*.*hho", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*ho", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*o", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lo", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llo", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*.*hho", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*ho", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*o", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lo", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llo", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-octal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*.*hho", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*ho", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*o", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lo", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llo", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*.*hho", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*ho", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*o", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lo", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llo", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal
    {
        constexpr flag::Integer i1{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*.*hhx", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hx", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*x", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lx", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llx", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*.*hhx", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hx", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*x", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lx", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llx", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*.*hhx", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hx", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*x", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lx", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llx", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*.*hhx", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hx", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*x", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lx", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llx", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal-upper
    {
        constexpr flag::Integer i1{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*.*hhX", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hX", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*X", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lX", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llX", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*.*hhX", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hX", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*X", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lX", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llX", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal
    {
        constexpr flag::Integer i1{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*.*hhx", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hx", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*x", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lx", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llx", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*.*hhx", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hx", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*x", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lx", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llx", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*.*hhx", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hx", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*x", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lx", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llx", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*.*hhx", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hx", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*x", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lx", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llx", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal-upper
    {
        constexpr flag::Integer i1{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%*.*hhX", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hX", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*X", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lX", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llX", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*.*hhX", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hX", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*X", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lX", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llX", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //prefix
    //default
    //decimal
    //decimal-lower
    //signed-decimal
    //signed-decimal-lower
    //unsigned-decimal
    //unsigned-decimal-lower
    //octal
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#*.*hho", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*.*ho", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*.*o", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*.*lo", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*.*llo", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#*.*hho", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*.*ho", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*.*o", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*.*lo", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*.*llo", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //octal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#*.*hho", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*.*ho", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*.*o", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*.*lo", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*.*llo", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#*.*hho", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*.*ho", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*.*o", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*.*lo", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*.*llo", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsinged-octal
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#*.*hho", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*.*ho", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*.*o", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*.*lo", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*.*llo", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#*.*hho", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*.*ho", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*.*o", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*.*lo", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*.*llo", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-octal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Octal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#*.*hho", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*.*ho", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*.*o", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*.*lo", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*.*llo", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#*.*hho", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*.*ho", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*.*o", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*.*lo", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*.*llo", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#*.*hhx", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*.*hx", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*.*x", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*.*lx", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*.*llx", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#*.*hhx", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*.*hx", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*.*x", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*.*lx", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*.*llx", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#*.*hhx", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*.*hx", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*.*x", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*.*lx", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*.*llx", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#*.*hhx", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*.*hx", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*.*x", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*.*lx", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*.*llx", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //hexadecimal-upper
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Hexadecimal{}, flag::arg::Upper{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#*.*hhX", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*.*hX", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*.*X", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*.*lX", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*.*llX", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#*.*hhX", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*.*hX", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*.*X", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*.*lX", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*.*llX", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#*.*hhx", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*.*hx", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*.*x", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*.*lx", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*.*llx", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#*.*hhx", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*.*hx", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*.*x", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*.*lx", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*.*llx", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Lower{}, flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#*.*hhx", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*.*hx", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*.*x", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*.*lx", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*.*llx", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#*.*hhx", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*.*hx", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*.*x", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*.*lx", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*.*llx", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-hexadecimal-upper
    {
        constexpr flag::Integer i1{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::Prefix{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Unsigned{}, flag::arg::Hexadecimal{}, 
            flag::arg::Upper{}, flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%#*.*hhX", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*.*hX", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*.*X", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*.*lX", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*.*llX", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%#*.*hhX", 
            wd1.GetValue(), len1.GetValue(), val1.unsigned_char_value);
        len_a += out_cstr1_a.Print("%#*.*hX", 
            wd1.GetValue(), len1.GetValue(), val2.unsigned_short_value);
        len_a += out_cstr1_a.Print("%#*.*X", 
            wd1.GetValue(), len1.GetValue(), val3.unsigned_int_value);
        len_a += out_cstr1_a.Print("%#*.*lX", 
            wd1.GetValue(), len1.GetValue(), val4.unsigned_long_value);
        len_a += out_cstr1_a.Print("%#*.*llX", 
            wd1.GetValue(), len1.GetValue(), val5.unsigned_long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //prefix-plus
    //default
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%+*.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+*.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+*.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+*.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+*.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%+*.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+*.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+*.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+*.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+*.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%+*.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+*.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+*.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+*.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+*.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%+*.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+*.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+*.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+*.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+*.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%+*.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+*.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+*.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+*.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+*.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%+*.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+*.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+*.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+*.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+*.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%+*.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+*.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+*.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+*.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+*.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%+*.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+*.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+*.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+*.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+*.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixPlus{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("%+*.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+*.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+*.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+*.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+*.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("%+*.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("%+*.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("%+*.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("%+*.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("%+*.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-decimal
    //unsigned-decimal-lower
    //octal
    //octal-lower
    //unsinged-octal
    //unsigned-octal-lower
    //hexadecimal
    //hexadecimal-lower
    //hexadecimal-upper
    //unsigned-hexadecimal
    //unsigned-hexadecimal-lower
    //unsigned-hexadecimal-upper
    //prefix-space
    //default
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("% *.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% *.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% *.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% *.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% *.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("% *.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% *.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% *.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% *.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% *.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("% *.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% *.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% *.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% *.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% *.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("% *.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% *.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% *.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% *.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% *.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Decimal{}, flag::arg::Lower{},
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("% *.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% *.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% *.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% *.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% *.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("% *.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% *.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% *.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% *.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% *.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("% *.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% *.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% *.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% *.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% *.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("% *.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% *.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% *.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% *.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% *.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //signed-decimal-lower
    {
        constexpr flag::Integer i1{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<char>{}};
        constexpr flag::Integer i2{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<short>{}};
        constexpr flag::Integer i3{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<int>{}};
        constexpr flag::Integer i4{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long>{}};
        constexpr flag::Integer i5{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<long long>{}};
        constexpr flag::Integer i6{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned char>{}};
        constexpr flag::Integer i7{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned short>{}};
        constexpr flag::Integer i8{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned int>{}};
        constexpr flag::Integer i9{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long>{}};
        constexpr flag::Integer i10{
            flag::arg::PrefixSpace{}, 
            flag::arg::Width{}, flag::arg::Length{}, 
            flag::arg::Signed{}, flag::arg::Decimal{}, flag::arg::Lower{}, 
            flag::arg::Define<unsigned long long>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        auto len_a = out_cstr1_a.Print("% *.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% *.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% *.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% *.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% *.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        len_a += out_cstr1_a.Print("% *.*hhi", 
            wd1.GetValue(), len1.GetValue(), val1.char_value);
        len_a += out_cstr1_a.Print("% *.*hi", 
            wd1.GetValue(), len1.GetValue(), val2.short_value);
        len_a += out_cstr1_a.Print("% *.*i", 
            wd1.GetValue(), len1.GetValue(), val3.int_value);
        len_a += out_cstr1_a.Print("% *.*li", 
            wd1.GetValue(), len1.GetValue(), val4.long_value);
        len_a += out_cstr1_a.Print("% *.*lli", 
            wd1.GetValue(), len1.GetValue(), val5.long_long_value);
        
        auto len_b = specifier::print::Integer<char, i1.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i2.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i3.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i4.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i5.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);
        len_b += specifier::print::Integer<char, i6.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val1);
        len_b += specifier::print::Integer<char, i7.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val2);
        len_b += specifier::print::Integer<char, i8.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val3);
        len_b += specifier::print::Integer<char, i9.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val4);
        len_b += specifier::print::Integer<char, i10.GetValue()>::
            Print(out_cstr1_b, wd1, len1, val5);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    //unsigned-decimal
    //unsigned-decimal-lower
    //octal
    //octal-lower
    //unsinged-octal
    //unsigned-octal-lower
    //hexadecimal
    //hexadecimal-lower
    //hexadecimal-upper
    //unsigned-hexadecimal
    //unsigned-hexadecimal-lower
    //unsigned-hexadecimal-upper
    //prefix-zero
    //default
    //decimal
    //decimal-lower
    //signed-decimal
    //signed-decimal-lower
    //unsigned-decimal
    //unsigned-decimal-lower
    //octal
    //octal-lower
    //unsinged-octal
    //unsigned-octal-lower
    //hexadecimal
    //hexadecimal-lower
    //hexadecimal-upper
    //unsigned-hexadecimal
    //unsigned-hexadecimal-lower
    //unsigned-hexadecimal-upper

    return 0;
}