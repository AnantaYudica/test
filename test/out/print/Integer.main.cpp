#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/print/Integer.h"

#include <cassert>

int main()
{

    assert((test::out::print::Integer::ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ds_char_fmt);

    assert((test::out::print::Integer::ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ds_short_fmt);

    assert((test::out::print::Integer::ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ds_int_fmt);

    assert((test::out::print::Integer::ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ds_long_fmt);

    assert((test::out::print::Integer::ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ds_long_long_fmt);

    assert((test::out::print::Integer::ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ds_u_char_fmt);

    assert((test::out::print::Integer::ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ds_u_short_fmt);

    assert((test::out::print::Integer::ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ds_u_int_fmt);

    assert((test::out::print::Integer::ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ds_u_long_fmt);

    assert((test::out::print::Integer::ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ds_u_long_long_fmt);


    assert((test::out::print::Integer::du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::du_char_fmt);

    assert((test::out::print::Integer::du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::du_short_fmt);

    assert((test::out::print::Integer::du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::du_int_fmt);

    assert((test::out::print::Integer::du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::du_long_fmt);

    assert((test::out::print::Integer::du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::du_long_long_fmt);

    assert((test::out::print::Integer::du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::du_u_char_fmt);

    assert((test::out::print::Integer::du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::du_u_short_fmt);

    assert((test::out::print::Integer::du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::du_u_int_fmt);

    assert((test::out::print::Integer::du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::du_u_long_fmt);

    assert((test::out::print::Integer::du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::du_u_long_long_fmt);


    assert((test::out::print::Integer::o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::o_char_fmt);

    assert((test::out::print::Integer::o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::o_short_fmt);

    assert((test::out::print::Integer::o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::o_int_fmt);

    assert((test::out::print::Integer::o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::o_long_fmt);

    assert((test::out::print::Integer::o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::o_long_long_fmt);

    assert((test::out::print::Integer::o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::o_u_char_fmt);

    assert((test::out::print::Integer::o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::o_u_short_fmt);

    assert((test::out::print::Integer::o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::o_u_int_fmt);

    assert((test::out::print::Integer::o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::o_u_long_fmt);

    assert((test::out::print::Integer::o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::o_u_long_long_fmt);

    
    assert((test::out::print::Integer::lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::lh_char_fmt);

    assert((test::out::print::Integer::lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::lh_short_fmt);

    assert((test::out::print::Integer::lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::lh_int_fmt);

    assert((test::out::print::Integer::lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::lh_long_fmt);

    assert((test::out::print::Integer::lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::lh_long_long_fmt);

    assert((test::out::print::Integer::lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::lh_u_char_fmt);

    assert((test::out::print::Integer::lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::lh_u_short_fmt);

    assert((test::out::print::Integer::lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::lh_u_int_fmt);

    assert((test::out::print::Integer::lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::lh_u_long_fmt);

    assert((test::out::print::Integer::lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::uh_char_fmt);

    assert((test::out::print::Integer::uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::uh_short_fmt);

    assert((test::out::print::Integer::uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::uh_int_fmt);

    assert((test::out::print::Integer::uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::uh_long_fmt);

    assert((test::out::print::Integer::uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::uh_long_long_fmt);

    assert((test::out::print::Integer::uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::uh_u_char_fmt);

    assert((test::out::print::Integer::uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::uh_u_short_fmt);

    assert((test::out::print::Integer::uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::uh_u_int_fmt);

    assert((test::out::print::Integer::uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::uh_u_long_fmt);

    assert((test::out::print::Integer::uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::uh_u_long_long_fmt);


    assert((test::out::print::Integer::p__ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__ds_char_fmt);

    assert((test::out::print::Integer::p__ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__ds_short_fmt);

    assert((test::out::print::Integer::p__ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__ds_int_fmt);

    assert((test::out::print::Integer::p__ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__ds_long_fmt);

    assert((test::out::print::Integer::p__ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__ds_long_long_fmt);

    assert((test::out::print::Integer::p__ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__ds_u_char_fmt);

    assert((test::out::print::Integer::p__ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__ds_u_short_fmt);

    assert((test::out::print::Integer::p__ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__ds_u_int_fmt);

    assert((test::out::print::Integer::p__ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__ds_u_long_fmt);

    assert((test::out::print::Integer::p__ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__ds_u_long_long_fmt);


    assert((test::out::print::Integer::p__du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__du_char_fmt);

    assert((test::out::print::Integer::p__du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__du_short_fmt);

    assert((test::out::print::Integer::p__du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__du_int_fmt);

    assert((test::out::print::Integer::p__du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__du_long_fmt);

    assert((test::out::print::Integer::p__du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__du_long_long_fmt);

    assert((test::out::print::Integer::p__du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__du_u_char_fmt);

    assert((test::out::print::Integer::p__du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__du_u_short_fmt);

    assert((test::out::print::Integer::p__du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__du_u_int_fmt);

    assert((test::out::print::Integer::p__du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__du_u_long_fmt);

    assert((test::out::print::Integer::p__du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__du_u_long_long_fmt);


    assert((test::out::print::Integer::p__o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__o_char_fmt);

    assert((test::out::print::Integer::p__o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__o_short_fmt);

    assert((test::out::print::Integer::p__o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__o_int_fmt);

    assert((test::out::print::Integer::p__o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__o_long_fmt);

    assert((test::out::print::Integer::p__o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__o_long_long_fmt);

    assert((test::out::print::Integer::p__o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__o_u_char_fmt);

    assert((test::out::print::Integer::p__o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__o_u_short_fmt);

    assert((test::out::print::Integer::p__o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__o_u_int_fmt);

    assert((test::out::print::Integer::p__o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__o_u_long_fmt);

    assert((test::out::print::Integer::p__o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__o_u_long_long_fmt);

    
    assert((test::out::print::Integer::p__lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__lh_char_fmt);

    assert((test::out::print::Integer::p__lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__lh_short_fmt);

    assert((test::out::print::Integer::p__lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__lh_int_fmt);

    assert((test::out::print::Integer::p__lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__lh_long_fmt);

    assert((test::out::print::Integer::p__lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__lh_long_long_fmt);

    assert((test::out::print::Integer::p__lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__lh_u_char_fmt);

    assert((test::out::print::Integer::p__lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__lh_u_short_fmt);

    assert((test::out::print::Integer::p__lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__lh_u_int_fmt);

    assert((test::out::print::Integer::p__lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__lh_u_long_fmt);

    assert((test::out::print::Integer::p__lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::p__uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__uh_char_fmt);

    assert((test::out::print::Integer::p__uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__uh_short_fmt);

    assert((test::out::print::Integer::p__uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__uh_int_fmt);

    assert((test::out::print::Integer::p__uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__uh_long_fmt);

    assert((test::out::print::Integer::p__uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__uh_long_long_fmt);

    assert((test::out::print::Integer::p__uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__uh_u_char_fmt);

    assert((test::out::print::Integer::p__uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__uh_u_short_fmt);

    assert((test::out::print::Integer::p__uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__uh_u_int_fmt);

    assert((test::out::print::Integer::p__uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__uh_u_long_fmt);

    assert((test::out::print::Integer::p__uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p__uh_u_long_long_fmt);


    assert((test::out::print::Integer::ppp__ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__ds_char_fmt);

    assert((test::out::print::Integer::ppp__ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__ds_short_fmt);

    assert((test::out::print::Integer::ppp__ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__ds_int_fmt);

    assert((test::out::print::Integer::ppp__ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__ds_long_fmt);

    assert((test::out::print::Integer::ppp__ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__ds_long_long_fmt);

    assert((test::out::print::Integer::ppp__ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__ds_u_char_fmt);

    assert((test::out::print::Integer::ppp__ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__ds_u_short_fmt);

    assert((test::out::print::Integer::ppp__ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__ds_u_int_fmt);

    assert((test::out::print::Integer::ppp__ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__ds_u_long_fmt);

    assert((test::out::print::Integer::ppp__ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__ds_u_long_long_fmt);


    assert((test::out::print::Integer::ppp__du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__du_char_fmt);

    assert((test::out::print::Integer::ppp__du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__du_short_fmt);

    assert((test::out::print::Integer::ppp__du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__du_int_fmt);

    assert((test::out::print::Integer::ppp__du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__du_long_fmt);

    assert((test::out::print::Integer::ppp__du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__du_long_long_fmt);

    assert((test::out::print::Integer::ppp__du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__du_u_char_fmt);

    assert((test::out::print::Integer::ppp__du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__du_u_short_fmt);

    assert((test::out::print::Integer::ppp__du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__du_u_int_fmt);

    assert((test::out::print::Integer::ppp__du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__du_u_long_fmt);

    assert((test::out::print::Integer::ppp__du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__du_u_long_long_fmt);


    assert((test::out::print::Integer::ppp__o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__o_char_fmt);

    assert((test::out::print::Integer::ppp__o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__o_short_fmt);

    assert((test::out::print::Integer::ppp__o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__o_int_fmt);

    assert((test::out::print::Integer::ppp__o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__o_long_fmt);

    assert((test::out::print::Integer::ppp__o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__o_long_long_fmt);

    assert((test::out::print::Integer::ppp__o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__o_u_char_fmt);

    assert((test::out::print::Integer::ppp__o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__o_u_short_fmt);

    assert((test::out::print::Integer::ppp__o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__o_u_int_fmt);

    assert((test::out::print::Integer::ppp__o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__o_u_long_fmt);

    assert((test::out::print::Integer::ppp__o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__o_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppp__lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__lh_char_fmt);

    assert((test::out::print::Integer::ppp__lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__lh_short_fmt);

    assert((test::out::print::Integer::ppp__lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__lh_int_fmt);

    assert((test::out::print::Integer::ppp__lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__lh_long_fmt);

    assert((test::out::print::Integer::ppp__lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__lh_long_long_fmt);

    assert((test::out::print::Integer::ppp__lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__lh_u_char_fmt);

    assert((test::out::print::Integer::ppp__lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__lh_u_short_fmt);

    assert((test::out::print::Integer::ppp__lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__lh_u_int_fmt);

    assert((test::out::print::Integer::ppp__lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__lh_u_long_fmt);

    assert((test::out::print::Integer::ppp__lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppp__uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__uh_char_fmt);

    assert((test::out::print::Integer::ppp__uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__uh_short_fmt);

    assert((test::out::print::Integer::ppp__uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__uh_int_fmt);

    assert((test::out::print::Integer::ppp__uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__uh_long_fmt);

    assert((test::out::print::Integer::ppp__uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__uh_long_long_fmt);

    assert((test::out::print::Integer::ppp__uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__uh_u_char_fmt);

    assert((test::out::print::Integer::ppp__uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__uh_u_short_fmt);

    assert((test::out::print::Integer::ppp__uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__uh_u_int_fmt);

    assert((test::out::print::Integer::ppp__uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__uh_u_long_fmt);

    assert((test::out::print::Integer::ppp__uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp__uh_u_long_long_fmt);


    assert((test::out::print::Integer::ppppz__ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__ds_char_fmt);

    assert((test::out::print::Integer::ppppz__ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__ds_short_fmt);

    assert((test::out::print::Integer::ppppz__ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__ds_int_fmt);

    assert((test::out::print::Integer::ppppz__ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__ds_long_fmt);

    assert((test::out::print::Integer::ppppz__ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__ds_long_long_fmt);

    assert((test::out::print::Integer::ppppz__ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__ds_u_char_fmt);

    assert((test::out::print::Integer::ppppz__ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__ds_u_short_fmt);

    assert((test::out::print::Integer::ppppz__ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__ds_u_int_fmt);

    assert((test::out::print::Integer::ppppz__ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__ds_u_long_fmt);

    assert((test::out::print::Integer::ppppz__ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__ds_u_long_long_fmt);


    assert((test::out::print::Integer::ppppz__du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__du_char_fmt);

    assert((test::out::print::Integer::ppppz__du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__du_short_fmt);

    assert((test::out::print::Integer::ppppz__du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__du_int_fmt);

    assert((test::out::print::Integer::ppppz__du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__du_long_fmt);

    assert((test::out::print::Integer::ppppz__du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__du_long_long_fmt);

    assert((test::out::print::Integer::ppppz__du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__du_u_char_fmt);

    assert((test::out::print::Integer::ppppz__du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__du_u_short_fmt);

    assert((test::out::print::Integer::ppppz__du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__du_u_int_fmt);

    assert((test::out::print::Integer::ppppz__du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__du_u_long_fmt);

    assert((test::out::print::Integer::ppppz__du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__du_u_long_long_fmt);


    assert((test::out::print::Integer::ppppz__o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__o_char_fmt);

    assert((test::out::print::Integer::ppppz__o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__o_short_fmt);

    assert((test::out::print::Integer::ppppz__o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__o_int_fmt);

    assert((test::out::print::Integer::ppppz__o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__o_long_fmt);

    assert((test::out::print::Integer::ppppz__o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__o_long_long_fmt);

    assert((test::out::print::Integer::ppppz__o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__o_u_char_fmt);

    assert((test::out::print::Integer::ppppz__o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__o_u_short_fmt);

    assert((test::out::print::Integer::ppppz__o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__o_u_int_fmt);

    assert((test::out::print::Integer::ppppz__o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__o_u_long_fmt);

    assert((test::out::print::Integer::ppppz__o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__o_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppppz__lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__lh_char_fmt);

    assert((test::out::print::Integer::ppppz__lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__lh_short_fmt);

    assert((test::out::print::Integer::ppppz__lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__lh_int_fmt);

    assert((test::out::print::Integer::ppppz__lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__lh_long_fmt);

    assert((test::out::print::Integer::ppppz__lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__lh_long_long_fmt);

    assert((test::out::print::Integer::ppppz__lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__lh_u_char_fmt);

    assert((test::out::print::Integer::ppppz__lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__lh_u_short_fmt);

    assert((test::out::print::Integer::ppppz__lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__lh_u_int_fmt);

    assert((test::out::print::Integer::ppppz__lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__lh_u_long_fmt);

    assert((test::out::print::Integer::ppppz__lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppppz__uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__uh_char_fmt);

    assert((test::out::print::Integer::ppppz__uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__uh_short_fmt);

    assert((test::out::print::Integer::ppppz__uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__uh_int_fmt);

    assert((test::out::print::Integer::ppppz__uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__uh_long_fmt);

    assert((test::out::print::Integer::ppppz__uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__uh_long_long_fmt);

    assert((test::out::print::Integer::ppppz__uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__uh_u_char_fmt);

    assert((test::out::print::Integer::ppppz__uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__uh_u_short_fmt);

    assert((test::out::print::Integer::ppppz__uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__uh_u_int_fmt);

    assert((test::out::print::Integer::ppppz__uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__uh_u_long_fmt);

    assert((test::out::print::Integer::ppppz__uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz__uh_u_long_long_fmt);


    assert((test::out::print::Integer::pps__ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__ds_char_fmt);

    assert((test::out::print::Integer::pps__ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__ds_short_fmt);

    assert((test::out::print::Integer::pps__ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__ds_int_fmt);

    assert((test::out::print::Integer::pps__ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__ds_long_fmt);

    assert((test::out::print::Integer::pps__ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__ds_long_long_fmt);

    assert((test::out::print::Integer::pps__ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__ds_u_char_fmt);

    assert((test::out::print::Integer::pps__ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__ds_u_short_fmt);

    assert((test::out::print::Integer::pps__ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__ds_u_int_fmt);

    assert((test::out::print::Integer::pps__ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__ds_u_long_fmt);

    assert((test::out::print::Integer::pps__ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__ds_u_long_long_fmt);


    assert((test::out::print::Integer::pps__du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__du_char_fmt);

    assert((test::out::print::Integer::pps__du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__du_short_fmt);

    assert((test::out::print::Integer::pps__du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__du_int_fmt);

    assert((test::out::print::Integer::pps__du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__du_long_fmt);

    assert((test::out::print::Integer::pps__du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__du_long_long_fmt);

    assert((test::out::print::Integer::pps__du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__du_u_char_fmt);

    assert((test::out::print::Integer::pps__du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__du_u_short_fmt);

    assert((test::out::print::Integer::pps__du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__du_u_int_fmt);

    assert((test::out::print::Integer::pps__du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__du_u_long_fmt);

    assert((test::out::print::Integer::pps__du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__du_u_long_long_fmt);


    assert((test::out::print::Integer::pps__o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__o_char_fmt);

    assert((test::out::print::Integer::pps__o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__o_short_fmt);

    assert((test::out::print::Integer::pps__o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__o_int_fmt);

    assert((test::out::print::Integer::pps__o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__o_long_fmt);

    assert((test::out::print::Integer::pps__o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__o_long_long_fmt);

    assert((test::out::print::Integer::pps__o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__o_u_char_fmt);

    assert((test::out::print::Integer::pps__o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__o_u_short_fmt);

    assert((test::out::print::Integer::pps__o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__o_u_int_fmt);

    assert((test::out::print::Integer::pps__o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__o_u_long_fmt);

    assert((test::out::print::Integer::pps__o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__o_u_long_long_fmt);

    
    assert((test::out::print::Integer::pps__lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__lh_char_fmt);

    assert((test::out::print::Integer::pps__lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__lh_short_fmt);

    assert((test::out::print::Integer::pps__lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__lh_int_fmt);

    assert((test::out::print::Integer::pps__lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__lh_long_fmt);

    assert((test::out::print::Integer::pps__lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__lh_long_long_fmt);

    assert((test::out::print::Integer::pps__lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__lh_u_char_fmt);

    assert((test::out::print::Integer::pps__lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__lh_u_short_fmt);

    assert((test::out::print::Integer::pps__lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__lh_u_int_fmt);

    assert((test::out::print::Integer::pps__lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__lh_u_long_fmt);

    assert((test::out::print::Integer::pps__lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::pps__uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__uh_char_fmt);

    assert((test::out::print::Integer::pps__uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__uh_short_fmt);

    assert((test::out::print::Integer::pps__uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__uh_int_fmt);

    assert((test::out::print::Integer::pps__uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__uh_long_fmt);

    assert((test::out::print::Integer::pps__uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__uh_long_long_fmt);

    assert((test::out::print::Integer::pps__uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__uh_u_char_fmt);

    assert((test::out::print::Integer::pps__uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__uh_u_short_fmt);

    assert((test::out::print::Integer::pps__uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__uh_u_int_fmt);

    assert((test::out::print::Integer::pps__uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__uh_u_long_fmt);

    assert((test::out::print::Integer::pps__uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps__uh_u_long_long_fmt);


    assert((test::out::print::Integer::ppspz__ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__ds_char_fmt);

    assert((test::out::print::Integer::ppspz__ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__ds_short_fmt);

    assert((test::out::print::Integer::ppspz__ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__ds_int_fmt);

    assert((test::out::print::Integer::ppspz__ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__ds_long_fmt);

    assert((test::out::print::Integer::ppspz__ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__ds_long_long_fmt);

    assert((test::out::print::Integer::ppspz__ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__ds_u_char_fmt);

    assert((test::out::print::Integer::ppspz__ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__ds_u_short_fmt);

    assert((test::out::print::Integer::ppspz__ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__ds_u_int_fmt);

    assert((test::out::print::Integer::ppspz__ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__ds_u_long_fmt);

    assert((test::out::print::Integer::ppspz__ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__ds_u_long_long_fmt);


    assert((test::out::print::Integer::ppspz__du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__du_char_fmt);

    assert((test::out::print::Integer::ppspz__du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__du_short_fmt);

    assert((test::out::print::Integer::ppspz__du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__du_int_fmt);

    assert((test::out::print::Integer::ppspz__du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__du_long_fmt);

    assert((test::out::print::Integer::ppspz__du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__du_long_long_fmt);

    assert((test::out::print::Integer::ppspz__du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__du_u_char_fmt);

    assert((test::out::print::Integer::ppspz__du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__du_u_short_fmt);

    assert((test::out::print::Integer::ppspz__du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__du_u_int_fmt);

    assert((test::out::print::Integer::ppspz__du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__du_u_long_fmt);

    assert((test::out::print::Integer::ppspz__du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__du_u_long_long_fmt);


    assert((test::out::print::Integer::ppspz__o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__o_char_fmt);

    assert((test::out::print::Integer::ppspz__o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__o_short_fmt);

    assert((test::out::print::Integer::ppspz__o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__o_int_fmt);

    assert((test::out::print::Integer::ppspz__o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__o_long_fmt);

    assert((test::out::print::Integer::ppspz__o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__o_long_long_fmt);

    assert((test::out::print::Integer::ppspz__o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__o_u_char_fmt);

    assert((test::out::print::Integer::ppspz__o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__o_u_short_fmt);

    assert((test::out::print::Integer::ppspz__o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__o_u_int_fmt);

    assert((test::out::print::Integer::ppspz__o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__o_u_long_fmt);

    assert((test::out::print::Integer::ppspz__o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__o_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppspz__lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__lh_char_fmt);

    assert((test::out::print::Integer::ppspz__lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__lh_short_fmt);

    assert((test::out::print::Integer::ppspz__lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__lh_int_fmt);

    assert((test::out::print::Integer::ppspz__lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__lh_long_fmt);

    assert((test::out::print::Integer::ppspz__lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__lh_long_long_fmt);

    assert((test::out::print::Integer::ppspz__lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__lh_u_char_fmt);

    assert((test::out::print::Integer::ppspz__lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__lh_u_short_fmt);

    assert((test::out::print::Integer::ppspz__lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__lh_u_int_fmt);

    assert((test::out::print::Integer::ppspz__lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__lh_u_long_fmt);

    assert((test::out::print::Integer::ppspz__lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppspz__uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__uh_char_fmt);

    assert((test::out::print::Integer::ppspz__uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__uh_short_fmt);

    assert((test::out::print::Integer::ppspz__uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__uh_int_fmt);

    assert((test::out::print::Integer::ppspz__uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__uh_long_fmt);

    assert((test::out::print::Integer::ppspz__uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__uh_long_long_fmt);

    assert((test::out::print::Integer::ppspz__uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__uh_u_char_fmt);

    assert((test::out::print::Integer::ppspz__uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__uh_u_short_fmt);

    assert((test::out::print::Integer::ppspz__uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__uh_u_int_fmt);

    assert((test::out::print::Integer::ppspz__uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__uh_u_long_fmt);

    assert((test::out::print::Integer::ppspz__uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz__uh_u_long_long_fmt);


    assert((test::out::print::Integer::ppz__ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__ds_char_fmt);

    assert((test::out::print::Integer::ppz__ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__ds_short_fmt);

    assert((test::out::print::Integer::ppz__ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__ds_int_fmt);

    assert((test::out::print::Integer::ppz__ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__ds_long_fmt);

    assert((test::out::print::Integer::ppz__ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__ds_long_long_fmt);

    assert((test::out::print::Integer::ppz__ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__ds_u_char_fmt);

    assert((test::out::print::Integer::ppz__ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__ds_u_short_fmt);

    assert((test::out::print::Integer::ppz__ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__ds_u_int_fmt);

    assert((test::out::print::Integer::ppz__ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__ds_u_long_fmt);

    assert((test::out::print::Integer::ppz__ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__ds_u_long_long_fmt);


    assert((test::out::print::Integer::ppz__du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__du_char_fmt);

    assert((test::out::print::Integer::ppz__du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__du_short_fmt);

    assert((test::out::print::Integer::ppz__du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__du_int_fmt);

    assert((test::out::print::Integer::ppz__du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__du_long_fmt);

    assert((test::out::print::Integer::ppz__du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__du_long_long_fmt);

    assert((test::out::print::Integer::ppz__du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__du_u_char_fmt);

    assert((test::out::print::Integer::ppz__du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__du_u_short_fmt);

    assert((test::out::print::Integer::ppz__du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__du_u_int_fmt);

    assert((test::out::print::Integer::ppz__du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__du_u_long_fmt);

    assert((test::out::print::Integer::ppz__du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__du_u_long_long_fmt);


    assert((test::out::print::Integer::ppz__o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__o_char_fmt);

    assert((test::out::print::Integer::ppz__o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__o_short_fmt);

    assert((test::out::print::Integer::ppz__o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__o_int_fmt);

    assert((test::out::print::Integer::ppz__o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__o_long_fmt);

    assert((test::out::print::Integer::ppz__o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__o_long_long_fmt);

    assert((test::out::print::Integer::ppz__o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__o_u_char_fmt);

    assert((test::out::print::Integer::ppz__o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__o_u_short_fmt);

    assert((test::out::print::Integer::ppz__o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__o_u_int_fmt);

    assert((test::out::print::Integer::ppz__o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__o_u_long_fmt);

    assert((test::out::print::Integer::ppz__o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__o_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppz__lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__lh_char_fmt);

    assert((test::out::print::Integer::ppz__lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__lh_short_fmt);

    assert((test::out::print::Integer::ppz__lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__lh_int_fmt);

    assert((test::out::print::Integer::ppz__lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__lh_long_fmt);

    assert((test::out::print::Integer::ppz__lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__lh_long_long_fmt);

    assert((test::out::print::Integer::ppz__lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__lh_u_char_fmt);

    assert((test::out::print::Integer::ppz__lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__lh_u_short_fmt);

    assert((test::out::print::Integer::ppz__lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__lh_u_int_fmt);

    assert((test::out::print::Integer::ppz__lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__lh_u_long_fmt);

    assert((test::out::print::Integer::ppz__lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppz__uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__uh_char_fmt);

    assert((test::out::print::Integer::ppz__uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__uh_short_fmt);

    assert((test::out::print::Integer::ppz__uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__uh_int_fmt);

    assert((test::out::print::Integer::ppz__uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__uh_long_fmt);

    assert((test::out::print::Integer::ppz__uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__uh_long_long_fmt);

    assert((test::out::print::Integer::ppz__uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__uh_u_char_fmt);

    assert((test::out::print::Integer::ppz__uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__uh_u_short_fmt);

    assert((test::out::print::Integer::ppz__uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__uh_u_int_fmt);

    assert((test::out::print::Integer::ppz__uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__uh_u_long_fmt);

    assert((test::out::print::Integer::ppz__uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz__uh_u_long_long_fmt);


    assert((test::out::print::Integer::pp__ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__ds_char_fmt);

    assert((test::out::print::Integer::pp__ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__ds_short_fmt);

    assert((test::out::print::Integer::pp__ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__ds_int_fmt);

    assert((test::out::print::Integer::pp__ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__ds_long_fmt);

    assert((test::out::print::Integer::pp__ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__ds_long_long_fmt);

    assert((test::out::print::Integer::pp__ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__ds_u_char_fmt);

    assert((test::out::print::Integer::pp__ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__ds_u_short_fmt);

    assert((test::out::print::Integer::pp__ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__ds_u_int_fmt);

    assert((test::out::print::Integer::pp__ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__ds_u_long_fmt);

    assert((test::out::print::Integer::pp__ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__ds_u_long_long_fmt);


    assert((test::out::print::Integer::pp__du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__du_char_fmt);

    assert((test::out::print::Integer::pp__du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__du_short_fmt);

    assert((test::out::print::Integer::pp__du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__du_int_fmt);

    assert((test::out::print::Integer::pp__du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__du_long_fmt);

    assert((test::out::print::Integer::pp__du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__du_long_long_fmt);

    assert((test::out::print::Integer::pp__du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__du_u_char_fmt);

    assert((test::out::print::Integer::pp__du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__du_u_short_fmt);

    assert((test::out::print::Integer::pp__du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__du_u_int_fmt);

    assert((test::out::print::Integer::pp__du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__du_u_long_fmt);

    assert((test::out::print::Integer::pp__du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__du_u_long_long_fmt);


    assert((test::out::print::Integer::pp__o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__o_char_fmt);

    assert((test::out::print::Integer::pp__o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__o_short_fmt);

    assert((test::out::print::Integer::pp__o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__o_int_fmt);

    assert((test::out::print::Integer::pp__o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__o_long_fmt);

    assert((test::out::print::Integer::pp__o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__o_long_long_fmt);

    assert((test::out::print::Integer::pp__o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__o_u_char_fmt);

    assert((test::out::print::Integer::pp__o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__o_u_short_fmt);

    assert((test::out::print::Integer::pp__o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__o_u_int_fmt);

    assert((test::out::print::Integer::pp__o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__o_u_long_fmt);

    assert((test::out::print::Integer::pp__o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__o_u_long_long_fmt);

    
    assert((test::out::print::Integer::pp__lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__lh_char_fmt);

    assert((test::out::print::Integer::pp__lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__lh_short_fmt);

    assert((test::out::print::Integer::pp__lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__lh_int_fmt);

    assert((test::out::print::Integer::pp__lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__lh_long_fmt);

    assert((test::out::print::Integer::pp__lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__lh_long_long_fmt);

    assert((test::out::print::Integer::pp__lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__lh_u_char_fmt);

    assert((test::out::print::Integer::pp__lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__lh_u_short_fmt);

    assert((test::out::print::Integer::pp__lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__lh_u_int_fmt);

    assert((test::out::print::Integer::pp__lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__lh_u_long_fmt);

    assert((test::out::print::Integer::pp__lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::pp__uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__uh_char_fmt);

    assert((test::out::print::Integer::pp__uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__uh_short_fmt);

    assert((test::out::print::Integer::pp__uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__uh_int_fmt);

    assert((test::out::print::Integer::pp__uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__uh_long_fmt);

    assert((test::out::print::Integer::pp__uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__uh_long_long_fmt);

    assert((test::out::print::Integer::pp__uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__uh_u_char_fmt);

    assert((test::out::print::Integer::pp__uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__uh_u_short_fmt);

    assert((test::out::print::Integer::pp__uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__uh_u_int_fmt);

    assert((test::out::print::Integer::pp__uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__uh_u_long_fmt);

    assert((test::out::print::Integer::pp__uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp__uh_u_long_long_fmt);


    assert((test::out::print::Integer::pppz__ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__ds_char_fmt);

    assert((test::out::print::Integer::pppz__ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__ds_short_fmt);

    assert((test::out::print::Integer::pppz__ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__ds_int_fmt);

    assert((test::out::print::Integer::pppz__ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__ds_long_fmt);

    assert((test::out::print::Integer::pppz__ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__ds_long_long_fmt);

    assert((test::out::print::Integer::pppz__ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__ds_u_char_fmt);

    assert((test::out::print::Integer::pppz__ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__ds_u_short_fmt);

    assert((test::out::print::Integer::pppz__ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__ds_u_int_fmt);

    assert((test::out::print::Integer::pppz__ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__ds_u_long_fmt);

    assert((test::out::print::Integer::pppz__ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__ds_u_long_long_fmt);


    assert((test::out::print::Integer::pppz__du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__du_char_fmt);

    assert((test::out::print::Integer::pppz__du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__du_short_fmt);

    assert((test::out::print::Integer::pppz__du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__du_int_fmt);

    assert((test::out::print::Integer::pppz__du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__du_long_fmt);

    assert((test::out::print::Integer::pppz__du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__du_long_long_fmt);

    assert((test::out::print::Integer::pppz__du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__du_u_char_fmt);

    assert((test::out::print::Integer::pppz__du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__du_u_short_fmt);

    assert((test::out::print::Integer::pppz__du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__du_u_int_fmt);

    assert((test::out::print::Integer::pppz__du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__du_u_long_fmt);

    assert((test::out::print::Integer::pppz__du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__du_u_long_long_fmt);


    assert((test::out::print::Integer::pppz__o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__o_char_fmt);

    assert((test::out::print::Integer::pppz__o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__o_short_fmt);

    assert((test::out::print::Integer::pppz__o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__o_int_fmt);

    assert((test::out::print::Integer::pppz__o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__o_long_fmt);

    assert((test::out::print::Integer::pppz__o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__o_long_long_fmt);

    assert((test::out::print::Integer::pppz__o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__o_u_char_fmt);

    assert((test::out::print::Integer::pppz__o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__o_u_short_fmt);

    assert((test::out::print::Integer::pppz__o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__o_u_int_fmt);

    assert((test::out::print::Integer::pppz__o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__o_u_long_fmt);

    assert((test::out::print::Integer::pppz__o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__o_u_long_long_fmt);

    
    assert((test::out::print::Integer::pppz__lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__lh_char_fmt);

    assert((test::out::print::Integer::pppz__lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__lh_short_fmt);

    assert((test::out::print::Integer::pppz__lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__lh_int_fmt);

    assert((test::out::print::Integer::pppz__lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__lh_long_fmt);

    assert((test::out::print::Integer::pppz__lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__lh_long_long_fmt);

    assert((test::out::print::Integer::pppz__lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__lh_u_char_fmt);

    assert((test::out::print::Integer::pppz__lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__lh_u_short_fmt);

    assert((test::out::print::Integer::pppz__lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__lh_u_int_fmt);

    assert((test::out::print::Integer::pppz__lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__lh_u_long_fmt);

    assert((test::out::print::Integer::pppz__lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::pppz__uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__uh_char_fmt);

    assert((test::out::print::Integer::pppz__uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__uh_short_fmt);

    assert((test::out::print::Integer::pppz__uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__uh_int_fmt);

    assert((test::out::print::Integer::pppz__uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__uh_long_fmt);

    assert((test::out::print::Integer::pppz__uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__uh_long_long_fmt);

    assert((test::out::print::Integer::pppz__uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__uh_u_char_fmt);

    assert((test::out::print::Integer::pppz__uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__uh_u_short_fmt);

    assert((test::out::print::Integer::pppz__uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__uh_u_int_fmt);

    assert((test::out::print::Integer::pppz__uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__uh_u_long_fmt);

    assert((test::out::print::Integer::pppz__uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz__uh_u_long_long_fmt);


    assert((test::out::print::Integer::ps__ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__ds_char_fmt);

    assert((test::out::print::Integer::ps__ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__ds_short_fmt);

    assert((test::out::print::Integer::ps__ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__ds_int_fmt);

    assert((test::out::print::Integer::ps__ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__ds_long_fmt);

    assert((test::out::print::Integer::ps__ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__ds_long_long_fmt);

    assert((test::out::print::Integer::ps__ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__ds_u_char_fmt);

    assert((test::out::print::Integer::ps__ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__ds_u_short_fmt);

    assert((test::out::print::Integer::ps__ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__ds_u_int_fmt);

    assert((test::out::print::Integer::ps__ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__ds_u_long_fmt);

    assert((test::out::print::Integer::ps__ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__ds_u_long_long_fmt);


    assert((test::out::print::Integer::ps__du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__du_char_fmt);

    assert((test::out::print::Integer::ps__du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__du_short_fmt);

    assert((test::out::print::Integer::ps__du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__du_int_fmt);

    assert((test::out::print::Integer::ps__du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__du_long_fmt);

    assert((test::out::print::Integer::ps__du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__du_long_long_fmt);

    assert((test::out::print::Integer::ps__du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__du_u_char_fmt);

    assert((test::out::print::Integer::ps__du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__du_u_short_fmt);

    assert((test::out::print::Integer::ps__du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__du_u_int_fmt);

    assert((test::out::print::Integer::ps__du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__du_u_long_fmt);

    assert((test::out::print::Integer::ps__du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__du_u_long_long_fmt);


    assert((test::out::print::Integer::ps__o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__o_char_fmt);

    assert((test::out::print::Integer::ps__o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__o_short_fmt);

    assert((test::out::print::Integer::ps__o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__o_int_fmt);

    assert((test::out::print::Integer::ps__o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__o_long_fmt);

    assert((test::out::print::Integer::ps__o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__o_long_long_fmt);

    assert((test::out::print::Integer::ps__o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__o_u_char_fmt);

    assert((test::out::print::Integer::ps__o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__o_u_short_fmt);

    assert((test::out::print::Integer::ps__o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__o_u_int_fmt);

    assert((test::out::print::Integer::ps__o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__o_u_long_fmt);

    assert((test::out::print::Integer::ps__o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__o_u_long_long_fmt);

    
    assert((test::out::print::Integer::ps__lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__lh_char_fmt);

    assert((test::out::print::Integer::ps__lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__lh_short_fmt);

    assert((test::out::print::Integer::ps__lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__lh_int_fmt);

    assert((test::out::print::Integer::ps__lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__lh_long_fmt);

    assert((test::out::print::Integer::ps__lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__lh_long_long_fmt);

    assert((test::out::print::Integer::ps__lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__lh_u_char_fmt);

    assert((test::out::print::Integer::ps__lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__lh_u_short_fmt);

    assert((test::out::print::Integer::ps__lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__lh_u_int_fmt);

    assert((test::out::print::Integer::ps__lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__lh_u_long_fmt);

    assert((test::out::print::Integer::ps__lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::ps__uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__uh_char_fmt);

    assert((test::out::print::Integer::ps__uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__uh_short_fmt);

    assert((test::out::print::Integer::ps__uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__uh_int_fmt);

    assert((test::out::print::Integer::ps__uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__uh_long_fmt);

    assert((test::out::print::Integer::ps__uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__uh_long_long_fmt);

    assert((test::out::print::Integer::ps__uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__uh_u_char_fmt);

    assert((test::out::print::Integer::ps__uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__uh_u_short_fmt);

    assert((test::out::print::Integer::ps__uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__uh_u_int_fmt);

    assert((test::out::print::Integer::ps__uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__uh_u_long_fmt);

    assert((test::out::print::Integer::ps__uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps__uh_u_long_long_fmt);


    assert((test::out::print::Integer::pspz__ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__ds_char_fmt);

    assert((test::out::print::Integer::pspz__ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__ds_short_fmt);

    assert((test::out::print::Integer::pspz__ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__ds_int_fmt);

    assert((test::out::print::Integer::pspz__ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__ds_long_fmt);

    assert((test::out::print::Integer::pspz__ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__ds_long_long_fmt);

    assert((test::out::print::Integer::pspz__ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__ds_u_char_fmt);

    assert((test::out::print::Integer::pspz__ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__ds_u_short_fmt);

    assert((test::out::print::Integer::pspz__ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__ds_u_int_fmt);

    assert((test::out::print::Integer::pspz__ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__ds_u_long_fmt);

    assert((test::out::print::Integer::pspz__ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__ds_u_long_long_fmt);


    assert((test::out::print::Integer::pspz__du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__du_char_fmt);

    assert((test::out::print::Integer::pspz__du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__du_short_fmt);

    assert((test::out::print::Integer::pspz__du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__du_int_fmt);

    assert((test::out::print::Integer::pspz__du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__du_long_fmt);

    assert((test::out::print::Integer::pspz__du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__du_long_long_fmt);

    assert((test::out::print::Integer::pspz__du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__du_u_char_fmt);

    assert((test::out::print::Integer::pspz__du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__du_u_short_fmt);

    assert((test::out::print::Integer::pspz__du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__du_u_int_fmt);

    assert((test::out::print::Integer::pspz__du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__du_u_long_fmt);

    assert((test::out::print::Integer::pspz__du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__du_u_long_long_fmt);


    assert((test::out::print::Integer::pspz__o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__o_char_fmt);

    assert((test::out::print::Integer::pspz__o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__o_short_fmt);

    assert((test::out::print::Integer::pspz__o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__o_int_fmt);

    assert((test::out::print::Integer::pspz__o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__o_long_fmt);

    assert((test::out::print::Integer::pspz__o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__o_long_long_fmt);

    assert((test::out::print::Integer::pspz__o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__o_u_char_fmt);

    assert((test::out::print::Integer::pspz__o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__o_u_short_fmt);

    assert((test::out::print::Integer::pspz__o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__o_u_int_fmt);

    assert((test::out::print::Integer::pspz__o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__o_u_long_fmt);

    assert((test::out::print::Integer::pspz__o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__o_u_long_long_fmt);

    
    assert((test::out::print::Integer::pspz__lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__lh_char_fmt);

    assert((test::out::print::Integer::pspz__lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__lh_short_fmt);

    assert((test::out::print::Integer::pspz__lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__lh_int_fmt);

    assert((test::out::print::Integer::pspz__lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__lh_long_fmt);

    assert((test::out::print::Integer::pspz__lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__lh_long_long_fmt);

    assert((test::out::print::Integer::pspz__lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__lh_u_char_fmt);

    assert((test::out::print::Integer::pspz__lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__lh_u_short_fmt);

    assert((test::out::print::Integer::pspz__lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__lh_u_int_fmt);

    assert((test::out::print::Integer::pspz__lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__lh_u_long_fmt);

    assert((test::out::print::Integer::pspz__lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::pspz__uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__uh_char_fmt);

    assert((test::out::print::Integer::pspz__uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__uh_short_fmt);

    assert((test::out::print::Integer::pspz__uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__uh_int_fmt);

    assert((test::out::print::Integer::pspz__uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__uh_long_fmt);

    assert((test::out::print::Integer::pspz__uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__uh_long_long_fmt);

    assert((test::out::print::Integer::pspz__uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__uh_u_char_fmt);

    assert((test::out::print::Integer::pspz__uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__uh_u_short_fmt);

    assert((test::out::print::Integer::pspz__uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__uh_u_int_fmt);

    assert((test::out::print::Integer::pspz__uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__uh_u_long_fmt);

    assert((test::out::print::Integer::pspz__uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz__uh_u_long_long_fmt);


    assert((test::out::print::Integer::pz__ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__ds_char_fmt);

    assert((test::out::print::Integer::pz__ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__ds_short_fmt);

    assert((test::out::print::Integer::pz__ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__ds_int_fmt);

    assert((test::out::print::Integer::pz__ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__ds_long_fmt);

    assert((test::out::print::Integer::pz__ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__ds_long_long_fmt);

    assert((test::out::print::Integer::pz__ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__ds_u_char_fmt);

    assert((test::out::print::Integer::pz__ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__ds_u_short_fmt);

    assert((test::out::print::Integer::pz__ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__ds_u_int_fmt);

    assert((test::out::print::Integer::pz__ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__ds_u_long_fmt);

    assert((test::out::print::Integer::pz__ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__ds_u_long_long_fmt);


    assert((test::out::print::Integer::pz__du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__du_char_fmt);

    assert((test::out::print::Integer::pz__du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__du_short_fmt);

    assert((test::out::print::Integer::pz__du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__du_int_fmt);

    assert((test::out::print::Integer::pz__du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__du_long_fmt);

    assert((test::out::print::Integer::pz__du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__du_long_long_fmt);

    assert((test::out::print::Integer::pz__du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__du_u_char_fmt);

    assert((test::out::print::Integer::pz__du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__du_u_short_fmt);

    assert((test::out::print::Integer::pz__du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__du_u_int_fmt);

    assert((test::out::print::Integer::pz__du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__du_u_long_fmt);

    assert((test::out::print::Integer::pz__du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__du_u_long_long_fmt);


    assert((test::out::print::Integer::pz__o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__o_char_fmt);

    assert((test::out::print::Integer::pz__o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__o_short_fmt);

    assert((test::out::print::Integer::pz__o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__o_int_fmt);

    assert((test::out::print::Integer::pz__o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__o_long_fmt);

    assert((test::out::print::Integer::pz__o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__o_long_long_fmt);

    assert((test::out::print::Integer::pz__o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__o_u_char_fmt);

    assert((test::out::print::Integer::pz__o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__o_u_short_fmt);

    assert((test::out::print::Integer::pz__o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__o_u_int_fmt);

    assert((test::out::print::Integer::pz__o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__o_u_long_fmt);

    assert((test::out::print::Integer::pz__o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__o_u_long_long_fmt);

    
    assert((test::out::print::Integer::pz__lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__lh_char_fmt);

    assert((test::out::print::Integer::pz__lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__lh_short_fmt);

    assert((test::out::print::Integer::pz__lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__lh_int_fmt);

    assert((test::out::print::Integer::pz__lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__lh_long_fmt);

    assert((test::out::print::Integer::pz__lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__lh_long_long_fmt);

    assert((test::out::print::Integer::pz__lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__lh_u_char_fmt);

    assert((test::out::print::Integer::pz__lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__lh_u_short_fmt);

    assert((test::out::print::Integer::pz__lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__lh_u_int_fmt);

    assert((test::out::print::Integer::pz__lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__lh_u_long_fmt);

    assert((test::out::print::Integer::pz__lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::pz__uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__uh_char_fmt);

    assert((test::out::print::Integer::pz__uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__uh_short_fmt);

    assert((test::out::print::Integer::pz__uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__uh_int_fmt);

    assert((test::out::print::Integer::pz__uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__uh_long_fmt);

    assert((test::out::print::Integer::pz__uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__uh_long_long_fmt);

    assert((test::out::print::Integer::pz__uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__uh_u_char_fmt);

    assert((test::out::print::Integer::pz__uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__uh_u_short_fmt);

    assert((test::out::print::Integer::pz__uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__uh_u_int_fmt);

    assert((test::out::print::Integer::pz__uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__uh_u_long_fmt);

    assert((test::out::print::Integer::pz__uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz__uh_u_long_long_fmt);


///
    assert((test::out::print::Integer::w_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_ds_char_fmt);

    assert((test::out::print::Integer::w_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_ds_short_fmt);

    assert((test::out::print::Integer::w_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_ds_int_fmt);

    assert((test::out::print::Integer::w_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_ds_long_fmt);

    assert((test::out::print::Integer::w_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_ds_long_long_fmt);

    assert((test::out::print::Integer::w_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_ds_u_char_fmt);

    assert((test::out::print::Integer::w_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_ds_u_short_fmt);

    assert((test::out::print::Integer::w_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_ds_u_int_fmt);

    assert((test::out::print::Integer::w_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_ds_u_long_fmt);

    assert((test::out::print::Integer::w_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_ds_u_long_long_fmt);


    assert((test::out::print::Integer::w_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_du_char_fmt);

    assert((test::out::print::Integer::w_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_du_short_fmt);

    assert((test::out::print::Integer::w_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_du_int_fmt);

    assert((test::out::print::Integer::w_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_du_long_fmt);

    assert((test::out::print::Integer::w_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_du_long_long_fmt);

    assert((test::out::print::Integer::w_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_du_u_char_fmt);

    assert((test::out::print::Integer::w_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_du_u_short_fmt);

    assert((test::out::print::Integer::w_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_du_u_int_fmt);

    assert((test::out::print::Integer::w_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_du_u_long_fmt);

    assert((test::out::print::Integer::w_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_du_u_long_long_fmt);


    assert((test::out::print::Integer::w_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_o_char_fmt);

    assert((test::out::print::Integer::w_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_o_short_fmt);

    assert((test::out::print::Integer::w_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_o_int_fmt);

    assert((test::out::print::Integer::w_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_o_long_fmt);

    assert((test::out::print::Integer::w_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_o_long_long_fmt);

    assert((test::out::print::Integer::w_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_o_u_char_fmt);

    assert((test::out::print::Integer::w_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_o_u_short_fmt);

    assert((test::out::print::Integer::w_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_o_u_int_fmt);

    assert((test::out::print::Integer::w_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_o_u_long_fmt);

    assert((test::out::print::Integer::w_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::w_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_lh_char_fmt);

    assert((test::out::print::Integer::w_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_lh_short_fmt);

    assert((test::out::print::Integer::w_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_lh_int_fmt);

    assert((test::out::print::Integer::w_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_lh_long_fmt);

    assert((test::out::print::Integer::w_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_lh_long_long_fmt);

    assert((test::out::print::Integer::w_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_lh_u_char_fmt);

    assert((test::out::print::Integer::w_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_lh_u_short_fmt);

    assert((test::out::print::Integer::w_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_lh_u_int_fmt);

    assert((test::out::print::Integer::w_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_lh_u_long_fmt);

    assert((test::out::print::Integer::w_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::w_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_uh_char_fmt);

    assert((test::out::print::Integer::w_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_uh_short_fmt);

    assert((test::out::print::Integer::w_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_uh_int_fmt);

    assert((test::out::print::Integer::w_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_uh_long_fmt);

    assert((test::out::print::Integer::w_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_uh_long_long_fmt);

    assert((test::out::print::Integer::w_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_uh_u_char_fmt);

    assert((test::out::print::Integer::w_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_uh_u_short_fmt);

    assert((test::out::print::Integer::w_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_uh_u_int_fmt);

    assert((test::out::print::Integer::w_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_uh_u_long_fmt);

    assert((test::out::print::Integer::w_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::w_uh_u_long_long_fmt);


    assert((test::out::print::Integer::p_w_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_ds_char_fmt);

    assert((test::out::print::Integer::p_w_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_ds_short_fmt);

    assert((test::out::print::Integer::p_w_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_ds_int_fmt);

    assert((test::out::print::Integer::p_w_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_ds_long_fmt);

    assert((test::out::print::Integer::p_w_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_ds_long_long_fmt);

    assert((test::out::print::Integer::p_w_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_ds_u_char_fmt);

    assert((test::out::print::Integer::p_w_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_ds_u_short_fmt);

    assert((test::out::print::Integer::p_w_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_ds_u_int_fmt);

    assert((test::out::print::Integer::p_w_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_ds_u_long_fmt);

    assert((test::out::print::Integer::p_w_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_ds_u_long_long_fmt);


    assert((test::out::print::Integer::p_w_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_du_char_fmt);

    assert((test::out::print::Integer::p_w_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_du_short_fmt);

    assert((test::out::print::Integer::p_w_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_du_int_fmt);

    assert((test::out::print::Integer::p_w_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_du_long_fmt);

    assert((test::out::print::Integer::p_w_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_du_long_long_fmt);

    assert((test::out::print::Integer::p_w_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_du_u_char_fmt);

    assert((test::out::print::Integer::p_w_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_du_u_short_fmt);

    assert((test::out::print::Integer::p_w_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_du_u_int_fmt);

    assert((test::out::print::Integer::p_w_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_du_u_long_fmt);

    assert((test::out::print::Integer::p_w_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_du_u_long_long_fmt);


    assert((test::out::print::Integer::p_w_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_o_char_fmt);

    assert((test::out::print::Integer::p_w_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_o_short_fmt);

    assert((test::out::print::Integer::p_w_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_o_int_fmt);

    assert((test::out::print::Integer::p_w_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_o_long_fmt);

    assert((test::out::print::Integer::p_w_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_o_long_long_fmt);

    assert((test::out::print::Integer::p_w_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_o_u_char_fmt);

    assert((test::out::print::Integer::p_w_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_o_u_short_fmt);

    assert((test::out::print::Integer::p_w_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_o_u_int_fmt);

    assert((test::out::print::Integer::p_w_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_o_u_long_fmt);

    assert((test::out::print::Integer::p_w_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::p_w_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_lh_char_fmt);

    assert((test::out::print::Integer::p_w_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_lh_short_fmt);

    assert((test::out::print::Integer::p_w_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_lh_int_fmt);

    assert((test::out::print::Integer::p_w_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_lh_long_fmt);

    assert((test::out::print::Integer::p_w_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_lh_long_long_fmt);

    assert((test::out::print::Integer::p_w_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_lh_u_char_fmt);

    assert((test::out::print::Integer::p_w_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_lh_u_short_fmt);

    assert((test::out::print::Integer::p_w_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_lh_u_int_fmt);

    assert((test::out::print::Integer::p_w_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_lh_u_long_fmt);

    assert((test::out::print::Integer::p_w_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::p_w_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_uh_char_fmt);

    assert((test::out::print::Integer::p_w_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_uh_short_fmt);

    assert((test::out::print::Integer::p_w_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_uh_int_fmt);

    assert((test::out::print::Integer::p_w_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_uh_long_fmt);

    assert((test::out::print::Integer::p_w_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_uh_long_long_fmt);

    assert((test::out::print::Integer::p_w_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_uh_u_char_fmt);

    assert((test::out::print::Integer::p_w_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_uh_u_short_fmt);

    assert((test::out::print::Integer::p_w_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_uh_u_int_fmt);

    assert((test::out::print::Integer::p_w_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_uh_u_long_fmt);

    assert((test::out::print::Integer::p_w_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_w_uh_u_long_long_fmt);


    assert((test::out::print::Integer::ppp_w_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_ds_char_fmt);

    assert((test::out::print::Integer::ppp_w_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_ds_short_fmt);

    assert((test::out::print::Integer::ppp_w_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_ds_int_fmt);

    assert((test::out::print::Integer::ppp_w_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_ds_long_fmt);

    assert((test::out::print::Integer::ppp_w_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_ds_long_long_fmt);

    assert((test::out::print::Integer::ppp_w_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_ds_u_char_fmt);

    assert((test::out::print::Integer::ppp_w_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_ds_u_short_fmt);

    assert((test::out::print::Integer::ppp_w_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_ds_u_int_fmt);

    assert((test::out::print::Integer::ppp_w_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_ds_u_long_fmt);

    assert((test::out::print::Integer::ppp_w_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_ds_u_long_long_fmt);


    assert((test::out::print::Integer::ppp_w_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_du_char_fmt);

    assert((test::out::print::Integer::ppp_w_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_du_short_fmt);

    assert((test::out::print::Integer::ppp_w_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_du_int_fmt);

    assert((test::out::print::Integer::ppp_w_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_du_long_fmt);

    assert((test::out::print::Integer::ppp_w_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_du_long_long_fmt);

    assert((test::out::print::Integer::ppp_w_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_du_u_char_fmt);

    assert((test::out::print::Integer::ppp_w_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_du_u_short_fmt);

    assert((test::out::print::Integer::ppp_w_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_du_u_int_fmt);

    assert((test::out::print::Integer::ppp_w_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_du_u_long_fmt);

    assert((test::out::print::Integer::ppp_w_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_du_u_long_long_fmt);


    assert((test::out::print::Integer::ppp_w_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_o_char_fmt);

    assert((test::out::print::Integer::ppp_w_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_o_short_fmt);

    assert((test::out::print::Integer::ppp_w_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_o_int_fmt);

    assert((test::out::print::Integer::ppp_w_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_o_long_fmt);

    assert((test::out::print::Integer::ppp_w_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_o_long_long_fmt);

    assert((test::out::print::Integer::ppp_w_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_o_u_char_fmt);

    assert((test::out::print::Integer::ppp_w_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_o_u_short_fmt);

    assert((test::out::print::Integer::ppp_w_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_o_u_int_fmt);

    assert((test::out::print::Integer::ppp_w_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_o_u_long_fmt);

    assert((test::out::print::Integer::ppp_w_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppp_w_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_lh_char_fmt);

    assert((test::out::print::Integer::ppp_w_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_lh_short_fmt);

    assert((test::out::print::Integer::ppp_w_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_lh_int_fmt);

    assert((test::out::print::Integer::ppp_w_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_lh_long_fmt);

    assert((test::out::print::Integer::ppp_w_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_lh_long_long_fmt);

    assert((test::out::print::Integer::ppp_w_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_lh_u_char_fmt);

    assert((test::out::print::Integer::ppp_w_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_lh_u_short_fmt);

    assert((test::out::print::Integer::ppp_w_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_lh_u_int_fmt);

    assert((test::out::print::Integer::ppp_w_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_lh_u_long_fmt);

    assert((test::out::print::Integer::ppp_w_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppp_w_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_uh_char_fmt);

    assert((test::out::print::Integer::ppp_w_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_uh_short_fmt);

    assert((test::out::print::Integer::ppp_w_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_uh_int_fmt);

    assert((test::out::print::Integer::ppp_w_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_uh_long_fmt);

    assert((test::out::print::Integer::ppp_w_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_uh_long_long_fmt);

    assert((test::out::print::Integer::ppp_w_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_uh_u_char_fmt);

    assert((test::out::print::Integer::ppp_w_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_uh_u_short_fmt);

    assert((test::out::print::Integer::ppp_w_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_uh_u_int_fmt);

    assert((test::out::print::Integer::ppp_w_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_uh_u_long_fmt);

    assert((test::out::print::Integer::ppp_w_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_w_uh_u_long_long_fmt);


    assert((test::out::print::Integer::ppppz_w_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_ds_char_fmt);

    assert((test::out::print::Integer::ppppz_w_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_ds_short_fmt);

    assert((test::out::print::Integer::ppppz_w_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_ds_int_fmt);

    assert((test::out::print::Integer::ppppz_w_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_ds_long_fmt);

    assert((test::out::print::Integer::ppppz_w_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_ds_long_long_fmt);

    assert((test::out::print::Integer::ppppz_w_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_ds_u_char_fmt);

    assert((test::out::print::Integer::ppppz_w_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_ds_u_short_fmt);

    assert((test::out::print::Integer::ppppz_w_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_ds_u_int_fmt);

    assert((test::out::print::Integer::ppppz_w_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_ds_u_long_fmt);

    assert((test::out::print::Integer::ppppz_w_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_ds_u_long_long_fmt);


    assert((test::out::print::Integer::ppppz_w_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_du_char_fmt);

    assert((test::out::print::Integer::ppppz_w_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_du_short_fmt);

    assert((test::out::print::Integer::ppppz_w_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_du_int_fmt);

    assert((test::out::print::Integer::ppppz_w_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_du_long_fmt);

    assert((test::out::print::Integer::ppppz_w_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_du_long_long_fmt);

    assert((test::out::print::Integer::ppppz_w_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_du_u_char_fmt);

    assert((test::out::print::Integer::ppppz_w_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_du_u_short_fmt);

    assert((test::out::print::Integer::ppppz_w_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_du_u_int_fmt);

    assert((test::out::print::Integer::ppppz_w_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_du_u_long_fmt);

    assert((test::out::print::Integer::ppppz_w_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_du_u_long_long_fmt);


    assert((test::out::print::Integer::ppppz_w_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_o_char_fmt);

    assert((test::out::print::Integer::ppppz_w_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_o_short_fmt);

    assert((test::out::print::Integer::ppppz_w_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_o_int_fmt);

    assert((test::out::print::Integer::ppppz_w_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_o_long_fmt);

    assert((test::out::print::Integer::ppppz_w_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_o_long_long_fmt);

    assert((test::out::print::Integer::ppppz_w_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_o_u_char_fmt);

    assert((test::out::print::Integer::ppppz_w_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_o_u_short_fmt);

    assert((test::out::print::Integer::ppppz_w_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_o_u_int_fmt);

    assert((test::out::print::Integer::ppppz_w_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_o_u_long_fmt);

    assert((test::out::print::Integer::ppppz_w_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppppz_w_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_lh_char_fmt);

    assert((test::out::print::Integer::ppppz_w_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_lh_short_fmt);

    assert((test::out::print::Integer::ppppz_w_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_lh_int_fmt);

    assert((test::out::print::Integer::ppppz_w_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_lh_long_fmt);

    assert((test::out::print::Integer::ppppz_w_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_lh_long_long_fmt);

    assert((test::out::print::Integer::ppppz_w_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_lh_u_char_fmt);

    assert((test::out::print::Integer::ppppz_w_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_lh_u_short_fmt);

    assert((test::out::print::Integer::ppppz_w_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_lh_u_int_fmt);

    assert((test::out::print::Integer::ppppz_w_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_lh_u_long_fmt);

    assert((test::out::print::Integer::ppppz_w_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppppz_w_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_uh_char_fmt);

    assert((test::out::print::Integer::ppppz_w_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_uh_short_fmt);

    assert((test::out::print::Integer::ppppz_w_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_uh_int_fmt);

    assert((test::out::print::Integer::ppppz_w_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_uh_long_fmt);

    assert((test::out::print::Integer::ppppz_w_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_uh_long_long_fmt);

    assert((test::out::print::Integer::ppppz_w_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_uh_u_char_fmt);

    assert((test::out::print::Integer::ppppz_w_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_uh_u_short_fmt);

    assert((test::out::print::Integer::ppppz_w_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_uh_u_int_fmt);

    assert((test::out::print::Integer::ppppz_w_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_uh_u_long_fmt);

    assert((test::out::print::Integer::ppppz_w_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_w_uh_u_long_long_fmt);


    assert((test::out::print::Integer::pps_w_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_ds_char_fmt);

    assert((test::out::print::Integer::pps_w_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_ds_short_fmt);

    assert((test::out::print::Integer::pps_w_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_ds_int_fmt);

    assert((test::out::print::Integer::pps_w_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_ds_long_fmt);

    assert((test::out::print::Integer::pps_w_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_ds_long_long_fmt);

    assert((test::out::print::Integer::pps_w_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_ds_u_char_fmt);

    assert((test::out::print::Integer::pps_w_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_ds_u_short_fmt);

    assert((test::out::print::Integer::pps_w_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_ds_u_int_fmt);

    assert((test::out::print::Integer::pps_w_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_ds_u_long_fmt);

    assert((test::out::print::Integer::pps_w_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_ds_u_long_long_fmt);


    assert((test::out::print::Integer::pps_w_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_du_char_fmt);

    assert((test::out::print::Integer::pps_w_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_du_short_fmt);

    assert((test::out::print::Integer::pps_w_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_du_int_fmt);

    assert((test::out::print::Integer::pps_w_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_du_long_fmt);

    assert((test::out::print::Integer::pps_w_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_du_long_long_fmt);

    assert((test::out::print::Integer::pps_w_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_du_u_char_fmt);

    assert((test::out::print::Integer::pps_w_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_du_u_short_fmt);

    assert((test::out::print::Integer::pps_w_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_du_u_int_fmt);

    assert((test::out::print::Integer::pps_w_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_du_u_long_fmt);

    assert((test::out::print::Integer::pps_w_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_du_u_long_long_fmt);


    assert((test::out::print::Integer::pps_w_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_o_char_fmt);

    assert((test::out::print::Integer::pps_w_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_o_short_fmt);

    assert((test::out::print::Integer::pps_w_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_o_int_fmt);

    assert((test::out::print::Integer::pps_w_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_o_long_fmt);

    assert((test::out::print::Integer::pps_w_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_o_long_long_fmt);

    assert((test::out::print::Integer::pps_w_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_o_u_char_fmt);

    assert((test::out::print::Integer::pps_w_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_o_u_short_fmt);

    assert((test::out::print::Integer::pps_w_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_o_u_int_fmt);

    assert((test::out::print::Integer::pps_w_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_o_u_long_fmt);

    assert((test::out::print::Integer::pps_w_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::pps_w_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_lh_char_fmt);

    assert((test::out::print::Integer::pps_w_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_lh_short_fmt);

    assert((test::out::print::Integer::pps_w_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_lh_int_fmt);

    assert((test::out::print::Integer::pps_w_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_lh_long_fmt);

    assert((test::out::print::Integer::pps_w_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_lh_long_long_fmt);

    assert((test::out::print::Integer::pps_w_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_lh_u_char_fmt);

    assert((test::out::print::Integer::pps_w_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_lh_u_short_fmt);

    assert((test::out::print::Integer::pps_w_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_lh_u_int_fmt);

    assert((test::out::print::Integer::pps_w_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_lh_u_long_fmt);

    assert((test::out::print::Integer::pps_w_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::pps_w_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_uh_char_fmt);

    assert((test::out::print::Integer::pps_w_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_uh_short_fmt);

    assert((test::out::print::Integer::pps_w_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_uh_int_fmt);

    assert((test::out::print::Integer::pps_w_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_uh_long_fmt);

    assert((test::out::print::Integer::pps_w_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_uh_long_long_fmt);

    assert((test::out::print::Integer::pps_w_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_uh_u_char_fmt);

    assert((test::out::print::Integer::pps_w_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_uh_u_short_fmt);

    assert((test::out::print::Integer::pps_w_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_uh_u_int_fmt);

    assert((test::out::print::Integer::pps_w_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_uh_u_long_fmt);

    assert((test::out::print::Integer::pps_w_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_w_uh_u_long_long_fmt);


    assert((test::out::print::Integer::ppspz_w_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_ds_char_fmt);

    assert((test::out::print::Integer::ppspz_w_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_ds_short_fmt);

    assert((test::out::print::Integer::ppspz_w_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_ds_int_fmt);

    assert((test::out::print::Integer::ppspz_w_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_ds_long_fmt);

    assert((test::out::print::Integer::ppspz_w_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_ds_long_long_fmt);

    assert((test::out::print::Integer::ppspz_w_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_ds_u_char_fmt);

    assert((test::out::print::Integer::ppspz_w_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_ds_u_short_fmt);

    assert((test::out::print::Integer::ppspz_w_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_ds_u_int_fmt);

    assert((test::out::print::Integer::ppspz_w_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_ds_u_long_fmt);

    assert((test::out::print::Integer::ppspz_w_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_ds_u_long_long_fmt);


    assert((test::out::print::Integer::ppspz_w_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_du_char_fmt);

    assert((test::out::print::Integer::ppspz_w_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_du_short_fmt);

    assert((test::out::print::Integer::ppspz_w_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_du_int_fmt);

    assert((test::out::print::Integer::ppspz_w_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_du_long_fmt);

    assert((test::out::print::Integer::ppspz_w_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_du_long_long_fmt);

    assert((test::out::print::Integer::ppspz_w_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_du_u_char_fmt);

    assert((test::out::print::Integer::ppspz_w_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_du_u_short_fmt);

    assert((test::out::print::Integer::ppspz_w_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_du_u_int_fmt);

    assert((test::out::print::Integer::ppspz_w_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_du_u_long_fmt);

    assert((test::out::print::Integer::ppspz_w_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_du_u_long_long_fmt);


    assert((test::out::print::Integer::ppspz_w_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_o_char_fmt);

    assert((test::out::print::Integer::ppspz_w_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_o_short_fmt);

    assert((test::out::print::Integer::ppspz_w_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_o_int_fmt);

    assert((test::out::print::Integer::ppspz_w_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_o_long_fmt);

    assert((test::out::print::Integer::ppspz_w_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_o_long_long_fmt);

    assert((test::out::print::Integer::ppspz_w_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_o_u_char_fmt);

    assert((test::out::print::Integer::ppspz_w_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_o_u_short_fmt);

    assert((test::out::print::Integer::ppspz_w_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_o_u_int_fmt);

    assert((test::out::print::Integer::ppspz_w_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_o_u_long_fmt);

    assert((test::out::print::Integer::ppspz_w_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppspz_w_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_lh_char_fmt);

    assert((test::out::print::Integer::ppspz_w_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_lh_short_fmt);

    assert((test::out::print::Integer::ppspz_w_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_lh_int_fmt);

    assert((test::out::print::Integer::ppspz_w_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_lh_long_fmt);

    assert((test::out::print::Integer::ppspz_w_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_lh_long_long_fmt);

    assert((test::out::print::Integer::ppspz_w_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_lh_u_char_fmt);

    assert((test::out::print::Integer::ppspz_w_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_lh_u_short_fmt);

    assert((test::out::print::Integer::ppspz_w_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_lh_u_int_fmt);

    assert((test::out::print::Integer::ppspz_w_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_lh_u_long_fmt);

    assert((test::out::print::Integer::ppspz_w_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppspz_w_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_uh_char_fmt);

    assert((test::out::print::Integer::ppspz_w_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_uh_short_fmt);

    assert((test::out::print::Integer::ppspz_w_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_uh_int_fmt);

    assert((test::out::print::Integer::ppspz_w_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_uh_long_fmt);

    assert((test::out::print::Integer::ppspz_w_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_uh_long_long_fmt);

    assert((test::out::print::Integer::ppspz_w_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_uh_u_char_fmt);

    assert((test::out::print::Integer::ppspz_w_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_uh_u_short_fmt);

    assert((test::out::print::Integer::ppspz_w_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_uh_u_int_fmt);

    assert((test::out::print::Integer::ppspz_w_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_uh_u_long_fmt);

    assert((test::out::print::Integer::ppspz_w_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_w_uh_u_long_long_fmt);


    assert((test::out::print::Integer::ppz_w_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_ds_char_fmt);

    assert((test::out::print::Integer::ppz_w_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_ds_short_fmt);

    assert((test::out::print::Integer::ppz_w_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_ds_int_fmt);

    assert((test::out::print::Integer::ppz_w_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_ds_long_fmt);

    assert((test::out::print::Integer::ppz_w_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_ds_long_long_fmt);

    assert((test::out::print::Integer::ppz_w_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_ds_u_char_fmt);

    assert((test::out::print::Integer::ppz_w_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_ds_u_short_fmt);

    assert((test::out::print::Integer::ppz_w_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_ds_u_int_fmt);

    assert((test::out::print::Integer::ppz_w_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_ds_u_long_fmt);

    assert((test::out::print::Integer::ppz_w_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_ds_u_long_long_fmt);


    assert((test::out::print::Integer::ppz_w_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_du_char_fmt);

    assert((test::out::print::Integer::ppz_w_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_du_short_fmt);

    assert((test::out::print::Integer::ppz_w_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_du_int_fmt);

    assert((test::out::print::Integer::ppz_w_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_du_long_fmt);

    assert((test::out::print::Integer::ppz_w_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_du_long_long_fmt);

    assert((test::out::print::Integer::ppz_w_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_du_u_char_fmt);

    assert((test::out::print::Integer::ppz_w_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_du_u_short_fmt);

    assert((test::out::print::Integer::ppz_w_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_du_u_int_fmt);

    assert((test::out::print::Integer::ppz_w_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_du_u_long_fmt);

    assert((test::out::print::Integer::ppz_w_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_du_u_long_long_fmt);


    assert((test::out::print::Integer::ppz_w_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_o_char_fmt);

    assert((test::out::print::Integer::ppz_w_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_o_short_fmt);

    assert((test::out::print::Integer::ppz_w_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_o_int_fmt);

    assert((test::out::print::Integer::ppz_w_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_o_long_fmt);

    assert((test::out::print::Integer::ppz_w_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_o_long_long_fmt);

    assert((test::out::print::Integer::ppz_w_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_o_u_char_fmt);

    assert((test::out::print::Integer::ppz_w_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_o_u_short_fmt);

    assert((test::out::print::Integer::ppz_w_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_o_u_int_fmt);

    assert((test::out::print::Integer::ppz_w_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_o_u_long_fmt);

    assert((test::out::print::Integer::ppz_w_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppz_w_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_lh_char_fmt);

    assert((test::out::print::Integer::ppz_w_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_lh_short_fmt);

    assert((test::out::print::Integer::ppz_w_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_lh_int_fmt);

    assert((test::out::print::Integer::ppz_w_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_lh_long_fmt);

    assert((test::out::print::Integer::ppz_w_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_lh_long_long_fmt);

    assert((test::out::print::Integer::ppz_w_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_lh_u_char_fmt);

    assert((test::out::print::Integer::ppz_w_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_lh_u_short_fmt);

    assert((test::out::print::Integer::ppz_w_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_lh_u_int_fmt);

    assert((test::out::print::Integer::ppz_w_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_lh_u_long_fmt);

    assert((test::out::print::Integer::ppz_w_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppz_w_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_uh_char_fmt);

    assert((test::out::print::Integer::ppz_w_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_uh_short_fmt);

    assert((test::out::print::Integer::ppz_w_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_uh_int_fmt);

    assert((test::out::print::Integer::ppz_w_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_uh_long_fmt);

    assert((test::out::print::Integer::ppz_w_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_uh_long_long_fmt);

    assert((test::out::print::Integer::ppz_w_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_uh_u_char_fmt);

    assert((test::out::print::Integer::ppz_w_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_uh_u_short_fmt);

    assert((test::out::print::Integer::ppz_w_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_uh_u_int_fmt);

    assert((test::out::print::Integer::ppz_w_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_uh_u_long_fmt);

    assert((test::out::print::Integer::ppz_w_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_w_uh_u_long_long_fmt);


    assert((test::out::print::Integer::pp_w_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_ds_char_fmt);

    assert((test::out::print::Integer::pp_w_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_ds_short_fmt);

    assert((test::out::print::Integer::pp_w_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_ds_int_fmt);

    assert((test::out::print::Integer::pp_w_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_ds_long_fmt);

    assert((test::out::print::Integer::pp_w_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_ds_long_long_fmt);

    assert((test::out::print::Integer::pp_w_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_ds_u_char_fmt);

    assert((test::out::print::Integer::pp_w_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_ds_u_short_fmt);

    assert((test::out::print::Integer::pp_w_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_ds_u_int_fmt);

    assert((test::out::print::Integer::pp_w_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_ds_u_long_fmt);

    assert((test::out::print::Integer::pp_w_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_ds_u_long_long_fmt);


    assert((test::out::print::Integer::pp_w_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_du_char_fmt);

    assert((test::out::print::Integer::pp_w_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_du_short_fmt);

    assert((test::out::print::Integer::pp_w_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_du_int_fmt);

    assert((test::out::print::Integer::pp_w_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_du_long_fmt);

    assert((test::out::print::Integer::pp_w_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_du_long_long_fmt);

    assert((test::out::print::Integer::pp_w_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_du_u_char_fmt);

    assert((test::out::print::Integer::pp_w_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_du_u_short_fmt);

    assert((test::out::print::Integer::pp_w_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_du_u_int_fmt);

    assert((test::out::print::Integer::pp_w_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_du_u_long_fmt);

    assert((test::out::print::Integer::pp_w_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_du_u_long_long_fmt);


    assert((test::out::print::Integer::pp_w_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_o_char_fmt);

    assert((test::out::print::Integer::pp_w_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_o_short_fmt);

    assert((test::out::print::Integer::pp_w_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_o_int_fmt);

    assert((test::out::print::Integer::pp_w_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_o_long_fmt);

    assert((test::out::print::Integer::pp_w_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_o_long_long_fmt);

    assert((test::out::print::Integer::pp_w_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_o_u_char_fmt);

    assert((test::out::print::Integer::pp_w_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_o_u_short_fmt);

    assert((test::out::print::Integer::pp_w_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_o_u_int_fmt);

    assert((test::out::print::Integer::pp_w_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_o_u_long_fmt);

    assert((test::out::print::Integer::pp_w_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::pp_w_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_lh_char_fmt);

    assert((test::out::print::Integer::pp_w_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_lh_short_fmt);

    assert((test::out::print::Integer::pp_w_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_lh_int_fmt);

    assert((test::out::print::Integer::pp_w_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_lh_long_fmt);

    assert((test::out::print::Integer::pp_w_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_lh_long_long_fmt);

    assert((test::out::print::Integer::pp_w_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_lh_u_char_fmt);

    assert((test::out::print::Integer::pp_w_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_lh_u_short_fmt);

    assert((test::out::print::Integer::pp_w_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_lh_u_int_fmt);

    assert((test::out::print::Integer::pp_w_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_lh_u_long_fmt);

    assert((test::out::print::Integer::pp_w_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::pp_w_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_uh_char_fmt);

    assert((test::out::print::Integer::pp_w_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_uh_short_fmt);

    assert((test::out::print::Integer::pp_w_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_uh_int_fmt);

    assert((test::out::print::Integer::pp_w_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_uh_long_fmt);

    assert((test::out::print::Integer::pp_w_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_uh_long_long_fmt);

    assert((test::out::print::Integer::pp_w_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_uh_u_char_fmt);

    assert((test::out::print::Integer::pp_w_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_uh_u_short_fmt);

    assert((test::out::print::Integer::pp_w_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_uh_u_int_fmt);

    assert((test::out::print::Integer::pp_w_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_uh_u_long_fmt);

    assert((test::out::print::Integer::pp_w_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_w_uh_u_long_long_fmt);


    assert((test::out::print::Integer::pppz_w_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_ds_char_fmt);

    assert((test::out::print::Integer::pppz_w_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_ds_short_fmt);

    assert((test::out::print::Integer::pppz_w_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_ds_int_fmt);

    assert((test::out::print::Integer::pppz_w_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_ds_long_fmt);

    assert((test::out::print::Integer::pppz_w_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_ds_long_long_fmt);

    assert((test::out::print::Integer::pppz_w_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_ds_u_char_fmt);

    assert((test::out::print::Integer::pppz_w_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_ds_u_short_fmt);

    assert((test::out::print::Integer::pppz_w_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_ds_u_int_fmt);

    assert((test::out::print::Integer::pppz_w_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_ds_u_long_fmt);

    assert((test::out::print::Integer::pppz_w_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_ds_u_long_long_fmt);


    assert((test::out::print::Integer::pppz_w_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_du_char_fmt);

    assert((test::out::print::Integer::pppz_w_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_du_short_fmt);

    assert((test::out::print::Integer::pppz_w_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_du_int_fmt);

    assert((test::out::print::Integer::pppz_w_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_du_long_fmt);

    assert((test::out::print::Integer::pppz_w_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_du_long_long_fmt);

    assert((test::out::print::Integer::pppz_w_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_du_u_char_fmt);

    assert((test::out::print::Integer::pppz_w_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_du_u_short_fmt);

    assert((test::out::print::Integer::pppz_w_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_du_u_int_fmt);

    assert((test::out::print::Integer::pppz_w_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_du_u_long_fmt);

    assert((test::out::print::Integer::pppz_w_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_du_u_long_long_fmt);


    assert((test::out::print::Integer::pppz_w_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_o_char_fmt);

    assert((test::out::print::Integer::pppz_w_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_o_short_fmt);

    assert((test::out::print::Integer::pppz_w_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_o_int_fmt);

    assert((test::out::print::Integer::pppz_w_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_o_long_fmt);

    assert((test::out::print::Integer::pppz_w_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_o_long_long_fmt);

    assert((test::out::print::Integer::pppz_w_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_o_u_char_fmt);

    assert((test::out::print::Integer::pppz_w_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_o_u_short_fmt);

    assert((test::out::print::Integer::pppz_w_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_o_u_int_fmt);

    assert((test::out::print::Integer::pppz_w_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_o_u_long_fmt);

    assert((test::out::print::Integer::pppz_w_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::pppz_w_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_lh_char_fmt);

    assert((test::out::print::Integer::pppz_w_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_lh_short_fmt);

    assert((test::out::print::Integer::pppz_w_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_lh_int_fmt);

    assert((test::out::print::Integer::pppz_w_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_lh_long_fmt);

    assert((test::out::print::Integer::pppz_w_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_lh_long_long_fmt);

    assert((test::out::print::Integer::pppz_w_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_lh_u_char_fmt);

    assert((test::out::print::Integer::pppz_w_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_lh_u_short_fmt);

    assert((test::out::print::Integer::pppz_w_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_lh_u_int_fmt);

    assert((test::out::print::Integer::pppz_w_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_lh_u_long_fmt);

    assert((test::out::print::Integer::pppz_w_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::pppz_w_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_uh_char_fmt);

    assert((test::out::print::Integer::pppz_w_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_uh_short_fmt);

    assert((test::out::print::Integer::pppz_w_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_uh_int_fmt);

    assert((test::out::print::Integer::pppz_w_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_uh_long_fmt);

    assert((test::out::print::Integer::pppz_w_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_uh_long_long_fmt);

    assert((test::out::print::Integer::pppz_w_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_uh_u_char_fmt);

    assert((test::out::print::Integer::pppz_w_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_uh_u_short_fmt);

    assert((test::out::print::Integer::pppz_w_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_uh_u_int_fmt);

    assert((test::out::print::Integer::pppz_w_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_uh_u_long_fmt);

    assert((test::out::print::Integer::pppz_w_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_w_uh_u_long_long_fmt);


    assert((test::out::print::Integer::ps_w_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_ds_char_fmt);

    assert((test::out::print::Integer::ps_w_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_ds_short_fmt);

    assert((test::out::print::Integer::ps_w_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_ds_int_fmt);

    assert((test::out::print::Integer::ps_w_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_ds_long_fmt);

    assert((test::out::print::Integer::ps_w_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_ds_long_long_fmt);

    assert((test::out::print::Integer::ps_w_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_ds_u_char_fmt);

    assert((test::out::print::Integer::ps_w_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_ds_u_short_fmt);

    assert((test::out::print::Integer::ps_w_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_ds_u_int_fmt);

    assert((test::out::print::Integer::ps_w_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_ds_u_long_fmt);

    assert((test::out::print::Integer::ps_w_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_ds_u_long_long_fmt);


    assert((test::out::print::Integer::ps_w_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_du_char_fmt);

    assert((test::out::print::Integer::ps_w_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_du_short_fmt);

    assert((test::out::print::Integer::ps_w_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_du_int_fmt);

    assert((test::out::print::Integer::ps_w_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_du_long_fmt);

    assert((test::out::print::Integer::ps_w_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_du_long_long_fmt);

    assert((test::out::print::Integer::ps_w_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_du_u_char_fmt);

    assert((test::out::print::Integer::ps_w_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_du_u_short_fmt);

    assert((test::out::print::Integer::ps_w_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_du_u_int_fmt);

    assert((test::out::print::Integer::ps_w_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_du_u_long_fmt);

    assert((test::out::print::Integer::ps_w_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_du_u_long_long_fmt);


    assert((test::out::print::Integer::ps_w_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_o_char_fmt);

    assert((test::out::print::Integer::ps_w_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_o_short_fmt);

    assert((test::out::print::Integer::ps_w_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_o_int_fmt);

    assert((test::out::print::Integer::ps_w_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_o_long_fmt);

    assert((test::out::print::Integer::ps_w_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_o_long_long_fmt);

    assert((test::out::print::Integer::ps_w_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_o_u_char_fmt);

    assert((test::out::print::Integer::ps_w_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_o_u_short_fmt);

    assert((test::out::print::Integer::ps_w_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_o_u_int_fmt);

    assert((test::out::print::Integer::ps_w_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_o_u_long_fmt);

    assert((test::out::print::Integer::ps_w_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::ps_w_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_lh_char_fmt);

    assert((test::out::print::Integer::ps_w_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_lh_short_fmt);

    assert((test::out::print::Integer::ps_w_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_lh_int_fmt);

    assert((test::out::print::Integer::ps_w_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_lh_long_fmt);

    assert((test::out::print::Integer::ps_w_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_lh_long_long_fmt);

    assert((test::out::print::Integer::ps_w_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_lh_u_char_fmt);

    assert((test::out::print::Integer::ps_w_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_lh_u_short_fmt);

    assert((test::out::print::Integer::ps_w_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_lh_u_int_fmt);

    assert((test::out::print::Integer::ps_w_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_lh_u_long_fmt);

    assert((test::out::print::Integer::ps_w_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::ps_w_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_uh_char_fmt);

    assert((test::out::print::Integer::ps_w_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_uh_short_fmt);

    assert((test::out::print::Integer::ps_w_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_uh_int_fmt);

    assert((test::out::print::Integer::ps_w_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_uh_long_fmt);

    assert((test::out::print::Integer::ps_w_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_uh_long_long_fmt);

    assert((test::out::print::Integer::ps_w_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_uh_u_char_fmt);

    assert((test::out::print::Integer::ps_w_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_uh_u_short_fmt);

    assert((test::out::print::Integer::ps_w_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_uh_u_int_fmt);

    assert((test::out::print::Integer::ps_w_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_uh_u_long_fmt);

    assert((test::out::print::Integer::ps_w_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_w_uh_u_long_long_fmt);


    assert((test::out::print::Integer::pspz_w_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_ds_char_fmt);

    assert((test::out::print::Integer::pspz_w_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_ds_short_fmt);

    assert((test::out::print::Integer::pspz_w_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_ds_int_fmt);

    assert((test::out::print::Integer::pspz_w_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_ds_long_fmt);

    assert((test::out::print::Integer::pspz_w_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_ds_long_long_fmt);

    assert((test::out::print::Integer::pspz_w_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_ds_u_char_fmt);

    assert((test::out::print::Integer::pspz_w_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_ds_u_short_fmt);

    assert((test::out::print::Integer::pspz_w_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_ds_u_int_fmt);

    assert((test::out::print::Integer::pspz_w_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_ds_u_long_fmt);

    assert((test::out::print::Integer::pspz_w_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_ds_u_long_long_fmt);


    assert((test::out::print::Integer::pspz_w_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_du_char_fmt);

    assert((test::out::print::Integer::pspz_w_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_du_short_fmt);

    assert((test::out::print::Integer::pspz_w_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_du_int_fmt);

    assert((test::out::print::Integer::pspz_w_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_du_long_fmt);

    assert((test::out::print::Integer::pspz_w_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_du_long_long_fmt);

    assert((test::out::print::Integer::pspz_w_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_du_u_char_fmt);

    assert((test::out::print::Integer::pspz_w_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_du_u_short_fmt);

    assert((test::out::print::Integer::pspz_w_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_du_u_int_fmt);

    assert((test::out::print::Integer::pspz_w_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_du_u_long_fmt);

    assert((test::out::print::Integer::pspz_w_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_du_u_long_long_fmt);


    assert((test::out::print::Integer::pspz_w_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_o_char_fmt);

    assert((test::out::print::Integer::pspz_w_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_o_short_fmt);

    assert((test::out::print::Integer::pspz_w_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_o_int_fmt);

    assert((test::out::print::Integer::pspz_w_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_o_long_fmt);

    assert((test::out::print::Integer::pspz_w_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_o_long_long_fmt);

    assert((test::out::print::Integer::pspz_w_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_o_u_char_fmt);

    assert((test::out::print::Integer::pspz_w_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_o_u_short_fmt);

    assert((test::out::print::Integer::pspz_w_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_o_u_int_fmt);

    assert((test::out::print::Integer::pspz_w_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_o_u_long_fmt);

    assert((test::out::print::Integer::pspz_w_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::pspz_w_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_lh_char_fmt);

    assert((test::out::print::Integer::pspz_w_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_lh_short_fmt);

    assert((test::out::print::Integer::pspz_w_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_lh_int_fmt);

    assert((test::out::print::Integer::pspz_w_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_lh_long_fmt);

    assert((test::out::print::Integer::pspz_w_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_lh_long_long_fmt);

    assert((test::out::print::Integer::pspz_w_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_lh_u_char_fmt);

    assert((test::out::print::Integer::pspz_w_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_lh_u_short_fmt);

    assert((test::out::print::Integer::pspz_w_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_lh_u_int_fmt);

    assert((test::out::print::Integer::pspz_w_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_lh_u_long_fmt);

    assert((test::out::print::Integer::pspz_w_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::pspz_w_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_uh_char_fmt);

    assert((test::out::print::Integer::pspz_w_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_uh_short_fmt);

    assert((test::out::print::Integer::pspz_w_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_uh_int_fmt);

    assert((test::out::print::Integer::pspz_w_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_uh_long_fmt);

    assert((test::out::print::Integer::pspz_w_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_uh_long_long_fmt);

    assert((test::out::print::Integer::pspz_w_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_uh_u_char_fmt);

    assert((test::out::print::Integer::pspz_w_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_uh_u_short_fmt);

    assert((test::out::print::Integer::pspz_w_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_uh_u_int_fmt);

    assert((test::out::print::Integer::pspz_w_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_uh_u_long_fmt);

    assert((test::out::print::Integer::pspz_w_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_w_uh_u_long_long_fmt);


    assert((test::out::print::Integer::pz_w_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_ds_char_fmt);

    assert((test::out::print::Integer::pz_w_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_ds_short_fmt);

    assert((test::out::print::Integer::pz_w_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_ds_int_fmt);

    assert((test::out::print::Integer::pz_w_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_ds_long_fmt);

    assert((test::out::print::Integer::pz_w_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_ds_long_long_fmt);

    assert((test::out::print::Integer::pz_w_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_ds_u_char_fmt);

    assert((test::out::print::Integer::pz_w_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_ds_u_short_fmt);

    assert((test::out::print::Integer::pz_w_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_ds_u_int_fmt);

    assert((test::out::print::Integer::pz_w_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_ds_u_long_fmt);

    assert((test::out::print::Integer::pz_w_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_ds_u_long_long_fmt);


    assert((test::out::print::Integer::pz_w_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_du_char_fmt);

    assert((test::out::print::Integer::pz_w_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_du_short_fmt);

    assert((test::out::print::Integer::pz_w_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_du_int_fmt);

    assert((test::out::print::Integer::pz_w_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_du_long_fmt);

    assert((test::out::print::Integer::pz_w_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_du_long_long_fmt);

    assert((test::out::print::Integer::pz_w_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_du_u_char_fmt);

    assert((test::out::print::Integer::pz_w_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_du_u_short_fmt);

    assert((test::out::print::Integer::pz_w_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_du_u_int_fmt);

    assert((test::out::print::Integer::pz_w_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_du_u_long_fmt);

    assert((test::out::print::Integer::pz_w_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_du_u_long_long_fmt);


    assert((test::out::print::Integer::pz_w_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_o_char_fmt);

    assert((test::out::print::Integer::pz_w_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_o_short_fmt);

    assert((test::out::print::Integer::pz_w_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_o_int_fmt);

    assert((test::out::print::Integer::pz_w_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_o_long_fmt);

    assert((test::out::print::Integer::pz_w_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_o_long_long_fmt);

    assert((test::out::print::Integer::pz_w_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_o_u_char_fmt);

    assert((test::out::print::Integer::pz_w_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_o_u_short_fmt);

    assert((test::out::print::Integer::pz_w_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_o_u_int_fmt);

    assert((test::out::print::Integer::pz_w_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_o_u_long_fmt);

    assert((test::out::print::Integer::pz_w_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::pz_w_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_lh_char_fmt);

    assert((test::out::print::Integer::pz_w_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_lh_short_fmt);

    assert((test::out::print::Integer::pz_w_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_lh_int_fmt);

    assert((test::out::print::Integer::pz_w_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_lh_long_fmt);

    assert((test::out::print::Integer::pz_w_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_lh_long_long_fmt);

    assert((test::out::print::Integer::pz_w_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_lh_u_char_fmt);

    assert((test::out::print::Integer::pz_w_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_lh_u_short_fmt);

    assert((test::out::print::Integer::pz_w_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_lh_u_int_fmt);

    assert((test::out::print::Integer::pz_w_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_lh_u_long_fmt);

    assert((test::out::print::Integer::pz_w_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::pz_w_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_uh_char_fmt);

    assert((test::out::print::Integer::pz_w_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_uh_short_fmt);

    assert((test::out::print::Integer::pz_w_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_uh_int_fmt);

    assert((test::out::print::Integer::pz_w_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_uh_long_fmt);

    assert((test::out::print::Integer::pz_w_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_uh_long_long_fmt);

    assert((test::out::print::Integer::pz_w_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_uh_u_char_fmt);

    assert((test::out::print::Integer::pz_w_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_uh_u_short_fmt);

    assert((test::out::print::Integer::pz_w_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_uh_u_int_fmt);

    assert((test::out::print::Integer::pz_w_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_uh_u_long_fmt);

    assert((test::out::print::Integer::pz_w_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_w_uh_u_long_long_fmt);


///
    assert((test::out::print::Integer::p_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_ds_char_fmt);

    assert((test::out::print::Integer::p_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_ds_short_fmt);

    assert((test::out::print::Integer::p_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_ds_int_fmt);

    assert((test::out::print::Integer::p_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_ds_long_fmt);

    assert((test::out::print::Integer::p_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_ds_long_long_fmt);

    assert((test::out::print::Integer::p_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_ds_u_char_fmt);

    assert((test::out::print::Integer::p_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_ds_u_short_fmt);

    assert((test::out::print::Integer::p_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_ds_u_int_fmt);

    assert((test::out::print::Integer::p_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_ds_u_long_fmt);

    assert((test::out::print::Integer::p_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_ds_u_long_long_fmt);


    assert((test::out::print::Integer::p_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_du_char_fmt);

    assert((test::out::print::Integer::p_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_du_short_fmt);

    assert((test::out::print::Integer::p_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_du_int_fmt);

    assert((test::out::print::Integer::p_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_du_long_fmt);

    assert((test::out::print::Integer::p_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_du_long_long_fmt);

    assert((test::out::print::Integer::p_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_du_u_char_fmt);

    assert((test::out::print::Integer::p_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_du_u_short_fmt);

    assert((test::out::print::Integer::p_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_du_u_int_fmt);

    assert((test::out::print::Integer::p_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_du_u_long_fmt);

    assert((test::out::print::Integer::p_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_du_u_long_long_fmt);


    assert((test::out::print::Integer::p_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_o_char_fmt);

    assert((test::out::print::Integer::p_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_o_short_fmt);

    assert((test::out::print::Integer::p_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_o_int_fmt);

    assert((test::out::print::Integer::p_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_o_long_fmt);

    assert((test::out::print::Integer::p_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_o_long_long_fmt);

    assert((test::out::print::Integer::p_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_o_u_char_fmt);

    assert((test::out::print::Integer::p_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_o_u_short_fmt);

    assert((test::out::print::Integer::p_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_o_u_int_fmt);

    assert((test::out::print::Integer::p_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_o_u_long_fmt);

    assert((test::out::print::Integer::p_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::p_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_lh_char_fmt);

    assert((test::out::print::Integer::p_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_lh_short_fmt);

    assert((test::out::print::Integer::p_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_lh_int_fmt);

    assert((test::out::print::Integer::p_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_lh_long_fmt);

    assert((test::out::print::Integer::p_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_lh_long_long_fmt);

    assert((test::out::print::Integer::p_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_lh_u_char_fmt);

    assert((test::out::print::Integer::p_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_lh_u_short_fmt);

    assert((test::out::print::Integer::p_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_lh_u_int_fmt);

    assert((test::out::print::Integer::p_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_lh_u_long_fmt);

    assert((test::out::print::Integer::p_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::p_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_uh_char_fmt);

    assert((test::out::print::Integer::p_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_uh_short_fmt);

    assert((test::out::print::Integer::p_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_uh_int_fmt);

    assert((test::out::print::Integer::p_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_uh_long_fmt);

    assert((test::out::print::Integer::p_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_uh_long_long_fmt);

    assert((test::out::print::Integer::p_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_uh_u_char_fmt);

    assert((test::out::print::Integer::p_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_uh_u_short_fmt);

    assert((test::out::print::Integer::p_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_uh_u_int_fmt);

    assert((test::out::print::Integer::p_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_uh_u_long_fmt);

    assert((test::out::print::Integer::p_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_uh_u_long_long_fmt);


    assert((test::out::print::Integer::p_p_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_ds_char_fmt);

    assert((test::out::print::Integer::p_p_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_ds_short_fmt);

    assert((test::out::print::Integer::p_p_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_ds_int_fmt);

    assert((test::out::print::Integer::p_p_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_ds_long_fmt);

    assert((test::out::print::Integer::p_p_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_ds_long_long_fmt);

    assert((test::out::print::Integer::p_p_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_ds_u_char_fmt);

    assert((test::out::print::Integer::p_p_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_ds_u_short_fmt);

    assert((test::out::print::Integer::p_p_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_ds_u_int_fmt);

    assert((test::out::print::Integer::p_p_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_ds_u_long_fmt);

    assert((test::out::print::Integer::p_p_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_ds_u_long_long_fmt);


    assert((test::out::print::Integer::p_p_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_du_char_fmt);

    assert((test::out::print::Integer::p_p_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_du_short_fmt);

    assert((test::out::print::Integer::p_p_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_du_int_fmt);

    assert((test::out::print::Integer::p_p_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_du_long_fmt);

    assert((test::out::print::Integer::p_p_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_du_long_long_fmt);

    assert((test::out::print::Integer::p_p_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_du_u_char_fmt);

    assert((test::out::print::Integer::p_p_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_du_u_short_fmt);

    assert((test::out::print::Integer::p_p_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_du_u_int_fmt);

    assert((test::out::print::Integer::p_p_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_du_u_long_fmt);

    assert((test::out::print::Integer::p_p_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_du_u_long_long_fmt);


    assert((test::out::print::Integer::p_p_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_o_char_fmt);

    assert((test::out::print::Integer::p_p_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_o_short_fmt);

    assert((test::out::print::Integer::p_p_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_o_int_fmt);

    assert((test::out::print::Integer::p_p_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_o_long_fmt);

    assert((test::out::print::Integer::p_p_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_o_long_long_fmt);

    assert((test::out::print::Integer::p_p_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_o_u_char_fmt);

    assert((test::out::print::Integer::p_p_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_o_u_short_fmt);

    assert((test::out::print::Integer::p_p_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_o_u_int_fmt);

    assert((test::out::print::Integer::p_p_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_o_u_long_fmt);

    assert((test::out::print::Integer::p_p_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::p_p_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_lh_char_fmt);

    assert((test::out::print::Integer::p_p_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_lh_short_fmt);

    assert((test::out::print::Integer::p_p_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_lh_int_fmt);

    assert((test::out::print::Integer::p_p_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_lh_long_fmt);

    assert((test::out::print::Integer::p_p_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_lh_long_long_fmt);

    assert((test::out::print::Integer::p_p_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_lh_u_char_fmt);

    assert((test::out::print::Integer::p_p_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_lh_u_short_fmt);

    assert((test::out::print::Integer::p_p_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_lh_u_int_fmt);

    assert((test::out::print::Integer::p_p_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_lh_u_long_fmt);

    assert((test::out::print::Integer::p_p_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::p_p_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_uh_char_fmt);

    assert((test::out::print::Integer::p_p_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_uh_short_fmt);

    assert((test::out::print::Integer::p_p_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_uh_int_fmt);

    assert((test::out::print::Integer::p_p_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_uh_long_fmt);

    assert((test::out::print::Integer::p_p_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_uh_long_long_fmt);

    assert((test::out::print::Integer::p_p_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_uh_u_char_fmt);

    assert((test::out::print::Integer::p_p_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_uh_u_short_fmt);

    assert((test::out::print::Integer::p_p_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_uh_u_int_fmt);

    assert((test::out::print::Integer::p_p_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_uh_u_long_fmt);

    assert((test::out::print::Integer::p_p_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_p_uh_u_long_long_fmt);


    assert((test::out::print::Integer::ppp_p_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_ds_char_fmt);

    assert((test::out::print::Integer::ppp_p_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_ds_short_fmt);

    assert((test::out::print::Integer::ppp_p_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_ds_int_fmt);

    assert((test::out::print::Integer::ppp_p_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_ds_long_fmt);

    assert((test::out::print::Integer::ppp_p_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_ds_long_long_fmt);

    assert((test::out::print::Integer::ppp_p_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_ds_u_char_fmt);

    assert((test::out::print::Integer::ppp_p_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_ds_u_short_fmt);

    assert((test::out::print::Integer::ppp_p_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_ds_u_int_fmt);

    assert((test::out::print::Integer::ppp_p_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_ds_u_long_fmt);

    assert((test::out::print::Integer::ppp_p_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_ds_u_long_long_fmt);


    assert((test::out::print::Integer::ppp_p_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_du_char_fmt);

    assert((test::out::print::Integer::ppp_p_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_du_short_fmt);

    assert((test::out::print::Integer::ppp_p_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_du_int_fmt);

    assert((test::out::print::Integer::ppp_p_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_du_long_fmt);

    assert((test::out::print::Integer::ppp_p_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_du_long_long_fmt);

    assert((test::out::print::Integer::ppp_p_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_du_u_char_fmt);

    assert((test::out::print::Integer::ppp_p_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_du_u_short_fmt);

    assert((test::out::print::Integer::ppp_p_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_du_u_int_fmt);

    assert((test::out::print::Integer::ppp_p_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_du_u_long_fmt);

    assert((test::out::print::Integer::ppp_p_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_du_u_long_long_fmt);


    assert((test::out::print::Integer::ppp_p_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_o_char_fmt);

    assert((test::out::print::Integer::ppp_p_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_o_short_fmt);

    assert((test::out::print::Integer::ppp_p_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_o_int_fmt);

    assert((test::out::print::Integer::ppp_p_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_o_long_fmt);

    assert((test::out::print::Integer::ppp_p_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_o_long_long_fmt);

    assert((test::out::print::Integer::ppp_p_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_o_u_char_fmt);

    assert((test::out::print::Integer::ppp_p_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_o_u_short_fmt);

    assert((test::out::print::Integer::ppp_p_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_o_u_int_fmt);

    assert((test::out::print::Integer::ppp_p_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_o_u_long_fmt);

    assert((test::out::print::Integer::ppp_p_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppp_p_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_lh_char_fmt);

    assert((test::out::print::Integer::ppp_p_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_lh_short_fmt);

    assert((test::out::print::Integer::ppp_p_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_lh_int_fmt);

    assert((test::out::print::Integer::ppp_p_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_lh_long_fmt);

    assert((test::out::print::Integer::ppp_p_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_lh_long_long_fmt);

    assert((test::out::print::Integer::ppp_p_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_lh_u_char_fmt);

    assert((test::out::print::Integer::ppp_p_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_lh_u_short_fmt);

    assert((test::out::print::Integer::ppp_p_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_lh_u_int_fmt);

    assert((test::out::print::Integer::ppp_p_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_lh_u_long_fmt);

    assert((test::out::print::Integer::ppp_p_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppp_p_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_uh_char_fmt);

    assert((test::out::print::Integer::ppp_p_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_uh_short_fmt);

    assert((test::out::print::Integer::ppp_p_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_uh_int_fmt);

    assert((test::out::print::Integer::ppp_p_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_uh_long_fmt);

    assert((test::out::print::Integer::ppp_p_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_uh_long_long_fmt);

    assert((test::out::print::Integer::ppp_p_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_uh_u_char_fmt);

    assert((test::out::print::Integer::ppp_p_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_uh_u_short_fmt);

    assert((test::out::print::Integer::ppp_p_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_uh_u_int_fmt);

    assert((test::out::print::Integer::ppp_p_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_uh_u_long_fmt);

    assert((test::out::print::Integer::ppp_p_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_p_uh_u_long_long_fmt);


    assert((test::out::print::Integer::ppppz_p_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_ds_char_fmt);

    assert((test::out::print::Integer::ppppz_p_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_ds_short_fmt);

    assert((test::out::print::Integer::ppppz_p_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_ds_int_fmt);

    assert((test::out::print::Integer::ppppz_p_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_ds_long_fmt);

    assert((test::out::print::Integer::ppppz_p_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_ds_long_long_fmt);

    assert((test::out::print::Integer::ppppz_p_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_ds_u_char_fmt);

    assert((test::out::print::Integer::ppppz_p_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_ds_u_short_fmt);

    assert((test::out::print::Integer::ppppz_p_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_ds_u_int_fmt);

    assert((test::out::print::Integer::ppppz_p_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_ds_u_long_fmt);

    assert((test::out::print::Integer::ppppz_p_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_ds_u_long_long_fmt);


    assert((test::out::print::Integer::ppppz_p_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_du_char_fmt);

    assert((test::out::print::Integer::ppppz_p_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_du_short_fmt);

    assert((test::out::print::Integer::ppppz_p_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_du_int_fmt);

    assert((test::out::print::Integer::ppppz_p_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_du_long_fmt);

    assert((test::out::print::Integer::ppppz_p_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_du_long_long_fmt);

    assert((test::out::print::Integer::ppppz_p_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_du_u_char_fmt);

    assert((test::out::print::Integer::ppppz_p_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_du_u_short_fmt);

    assert((test::out::print::Integer::ppppz_p_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_du_u_int_fmt);

    assert((test::out::print::Integer::ppppz_p_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_du_u_long_fmt);

    assert((test::out::print::Integer::ppppz_p_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_du_u_long_long_fmt);


    assert((test::out::print::Integer::ppppz_p_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_o_char_fmt);

    assert((test::out::print::Integer::ppppz_p_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_o_short_fmt);

    assert((test::out::print::Integer::ppppz_p_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_o_int_fmt);

    assert((test::out::print::Integer::ppppz_p_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_o_long_fmt);

    assert((test::out::print::Integer::ppppz_p_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_o_long_long_fmt);

    assert((test::out::print::Integer::ppppz_p_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_o_u_char_fmt);

    assert((test::out::print::Integer::ppppz_p_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_o_u_short_fmt);

    assert((test::out::print::Integer::ppppz_p_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_o_u_int_fmt);

    assert((test::out::print::Integer::ppppz_p_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_o_u_long_fmt);

    assert((test::out::print::Integer::ppppz_p_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppppz_p_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_lh_char_fmt);

    assert((test::out::print::Integer::ppppz_p_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_lh_short_fmt);

    assert((test::out::print::Integer::ppppz_p_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_lh_int_fmt);

    assert((test::out::print::Integer::ppppz_p_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_lh_long_fmt);

    assert((test::out::print::Integer::ppppz_p_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_lh_long_long_fmt);

    assert((test::out::print::Integer::ppppz_p_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_lh_u_char_fmt);

    assert((test::out::print::Integer::ppppz_p_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_lh_u_short_fmt);

    assert((test::out::print::Integer::ppppz_p_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_lh_u_int_fmt);

    assert((test::out::print::Integer::ppppz_p_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_lh_u_long_fmt);

    assert((test::out::print::Integer::ppppz_p_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppppz_p_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_uh_char_fmt);

    assert((test::out::print::Integer::ppppz_p_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_uh_short_fmt);

    assert((test::out::print::Integer::ppppz_p_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_uh_int_fmt);

    assert((test::out::print::Integer::ppppz_p_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_uh_long_fmt);

    assert((test::out::print::Integer::ppppz_p_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_uh_long_long_fmt);

    assert((test::out::print::Integer::ppppz_p_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_uh_u_char_fmt);

    assert((test::out::print::Integer::ppppz_p_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_uh_u_short_fmt);

    assert((test::out::print::Integer::ppppz_p_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_uh_u_int_fmt);

    assert((test::out::print::Integer::ppppz_p_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_uh_u_long_fmt);

    assert((test::out::print::Integer::ppppz_p_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_p_uh_u_long_long_fmt);


    assert((test::out::print::Integer::pps_p_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_ds_char_fmt);

    assert((test::out::print::Integer::pps_p_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_ds_short_fmt);

    assert((test::out::print::Integer::pps_p_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_ds_int_fmt);

    assert((test::out::print::Integer::pps_p_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_ds_long_fmt);

    assert((test::out::print::Integer::pps_p_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_ds_long_long_fmt);

    assert((test::out::print::Integer::pps_p_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_ds_u_char_fmt);

    assert((test::out::print::Integer::pps_p_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_ds_u_short_fmt);

    assert((test::out::print::Integer::pps_p_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_ds_u_int_fmt);

    assert((test::out::print::Integer::pps_p_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_ds_u_long_fmt);

    assert((test::out::print::Integer::pps_p_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_ds_u_long_long_fmt);


    assert((test::out::print::Integer::pps_p_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_du_char_fmt);

    assert((test::out::print::Integer::pps_p_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_du_short_fmt);

    assert((test::out::print::Integer::pps_p_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_du_int_fmt);

    assert((test::out::print::Integer::pps_p_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_du_long_fmt);

    assert((test::out::print::Integer::pps_p_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_du_long_long_fmt);

    assert((test::out::print::Integer::pps_p_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_du_u_char_fmt);

    assert((test::out::print::Integer::pps_p_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_du_u_short_fmt);

    assert((test::out::print::Integer::pps_p_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_du_u_int_fmt);

    assert((test::out::print::Integer::pps_p_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_du_u_long_fmt);

    assert((test::out::print::Integer::pps_p_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_du_u_long_long_fmt);


    assert((test::out::print::Integer::pps_p_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_o_char_fmt);

    assert((test::out::print::Integer::pps_p_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_o_short_fmt);

    assert((test::out::print::Integer::pps_p_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_o_int_fmt);

    assert((test::out::print::Integer::pps_p_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_o_long_fmt);

    assert((test::out::print::Integer::pps_p_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_o_long_long_fmt);

    assert((test::out::print::Integer::pps_p_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_o_u_char_fmt);

    assert((test::out::print::Integer::pps_p_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_o_u_short_fmt);

    assert((test::out::print::Integer::pps_p_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_o_u_int_fmt);

    assert((test::out::print::Integer::pps_p_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_o_u_long_fmt);

    assert((test::out::print::Integer::pps_p_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::pps_p_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_lh_char_fmt);

    assert((test::out::print::Integer::pps_p_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_lh_short_fmt);

    assert((test::out::print::Integer::pps_p_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_lh_int_fmt);

    assert((test::out::print::Integer::pps_p_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_lh_long_fmt);

    assert((test::out::print::Integer::pps_p_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_lh_long_long_fmt);

    assert((test::out::print::Integer::pps_p_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_lh_u_char_fmt);

    assert((test::out::print::Integer::pps_p_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_lh_u_short_fmt);

    assert((test::out::print::Integer::pps_p_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_lh_u_int_fmt);

    assert((test::out::print::Integer::pps_p_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_lh_u_long_fmt);

    assert((test::out::print::Integer::pps_p_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::pps_p_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_uh_char_fmt);

    assert((test::out::print::Integer::pps_p_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_uh_short_fmt);

    assert((test::out::print::Integer::pps_p_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_uh_int_fmt);

    assert((test::out::print::Integer::pps_p_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_uh_long_fmt);

    assert((test::out::print::Integer::pps_p_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_uh_long_long_fmt);

    assert((test::out::print::Integer::pps_p_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_uh_u_char_fmt);

    assert((test::out::print::Integer::pps_p_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_uh_u_short_fmt);

    assert((test::out::print::Integer::pps_p_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_uh_u_int_fmt);

    assert((test::out::print::Integer::pps_p_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_uh_u_long_fmt);

    assert((test::out::print::Integer::pps_p_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_p_uh_u_long_long_fmt);


    assert((test::out::print::Integer::ppspz_p_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_ds_char_fmt);

    assert((test::out::print::Integer::ppspz_p_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_ds_short_fmt);

    assert((test::out::print::Integer::ppspz_p_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_ds_int_fmt);

    assert((test::out::print::Integer::ppspz_p_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_ds_long_fmt);

    assert((test::out::print::Integer::ppspz_p_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_ds_long_long_fmt);

    assert((test::out::print::Integer::ppspz_p_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_ds_u_char_fmt);

    assert((test::out::print::Integer::ppspz_p_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_ds_u_short_fmt);

    assert((test::out::print::Integer::ppspz_p_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_ds_u_int_fmt);

    assert((test::out::print::Integer::ppspz_p_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_ds_u_long_fmt);

    assert((test::out::print::Integer::ppspz_p_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_ds_u_long_long_fmt);


    assert((test::out::print::Integer::ppspz_p_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_du_char_fmt);

    assert((test::out::print::Integer::ppspz_p_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_du_short_fmt);

    assert((test::out::print::Integer::ppspz_p_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_du_int_fmt);

    assert((test::out::print::Integer::ppspz_p_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_du_long_fmt);

    assert((test::out::print::Integer::ppspz_p_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_du_long_long_fmt);

    assert((test::out::print::Integer::ppspz_p_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_du_u_char_fmt);

    assert((test::out::print::Integer::ppspz_p_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_du_u_short_fmt);

    assert((test::out::print::Integer::ppspz_p_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_du_u_int_fmt);

    assert((test::out::print::Integer::ppspz_p_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_du_u_long_fmt);

    assert((test::out::print::Integer::ppspz_p_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_du_u_long_long_fmt);


    assert((test::out::print::Integer::ppspz_p_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_o_char_fmt);

    assert((test::out::print::Integer::ppspz_p_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_o_short_fmt);

    assert((test::out::print::Integer::ppspz_p_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_o_int_fmt);

    assert((test::out::print::Integer::ppspz_p_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_o_long_fmt);

    assert((test::out::print::Integer::ppspz_p_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_o_long_long_fmt);

    assert((test::out::print::Integer::ppspz_p_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_o_u_char_fmt);

    assert((test::out::print::Integer::ppspz_p_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_o_u_short_fmt);

    assert((test::out::print::Integer::ppspz_p_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_o_u_int_fmt);

    assert((test::out::print::Integer::ppspz_p_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_o_u_long_fmt);

    assert((test::out::print::Integer::ppspz_p_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppspz_p_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_lh_char_fmt);

    assert((test::out::print::Integer::ppspz_p_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_lh_short_fmt);

    assert((test::out::print::Integer::ppspz_p_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_lh_int_fmt);

    assert((test::out::print::Integer::ppspz_p_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_lh_long_fmt);

    assert((test::out::print::Integer::ppspz_p_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_lh_long_long_fmt);

    assert((test::out::print::Integer::ppspz_p_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_lh_u_char_fmt);

    assert((test::out::print::Integer::ppspz_p_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_lh_u_short_fmt);

    assert((test::out::print::Integer::ppspz_p_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_lh_u_int_fmt);

    assert((test::out::print::Integer::ppspz_p_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_lh_u_long_fmt);

    assert((test::out::print::Integer::ppspz_p_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppspz_p_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_uh_char_fmt);

    assert((test::out::print::Integer::ppspz_p_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_uh_short_fmt);

    assert((test::out::print::Integer::ppspz_p_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_uh_int_fmt);

    assert((test::out::print::Integer::ppspz_p_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_uh_long_fmt);

    assert((test::out::print::Integer::ppspz_p_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_uh_long_long_fmt);

    assert((test::out::print::Integer::ppspz_p_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_uh_u_char_fmt);

    assert((test::out::print::Integer::ppspz_p_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_uh_u_short_fmt);

    assert((test::out::print::Integer::ppspz_p_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_uh_u_int_fmt);

    assert((test::out::print::Integer::ppspz_p_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_uh_u_long_fmt);

    assert((test::out::print::Integer::ppspz_p_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_p_uh_u_long_long_fmt);


    assert((test::out::print::Integer::ppz_p_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_ds_char_fmt);

    assert((test::out::print::Integer::ppz_p_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_ds_short_fmt);

    assert((test::out::print::Integer::ppz_p_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_ds_int_fmt);

    assert((test::out::print::Integer::ppz_p_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_ds_long_fmt);

    assert((test::out::print::Integer::ppz_p_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_ds_long_long_fmt);

    assert((test::out::print::Integer::ppz_p_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_ds_u_char_fmt);

    assert((test::out::print::Integer::ppz_p_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_ds_u_short_fmt);

    assert((test::out::print::Integer::ppz_p_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_ds_u_int_fmt);

    assert((test::out::print::Integer::ppz_p_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_ds_u_long_fmt);

    assert((test::out::print::Integer::ppz_p_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_ds_u_long_long_fmt);


    assert((test::out::print::Integer::ppz_p_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_du_char_fmt);

    assert((test::out::print::Integer::ppz_p_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_du_short_fmt);

    assert((test::out::print::Integer::ppz_p_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_du_int_fmt);

    assert((test::out::print::Integer::ppz_p_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_du_long_fmt);

    assert((test::out::print::Integer::ppz_p_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_du_long_long_fmt);

    assert((test::out::print::Integer::ppz_p_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_du_u_char_fmt);

    assert((test::out::print::Integer::ppz_p_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_du_u_short_fmt);

    assert((test::out::print::Integer::ppz_p_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_du_u_int_fmt);

    assert((test::out::print::Integer::ppz_p_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_du_u_long_fmt);

    assert((test::out::print::Integer::ppz_p_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_du_u_long_long_fmt);


    assert((test::out::print::Integer::ppz_p_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_o_char_fmt);

    assert((test::out::print::Integer::ppz_p_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_o_short_fmt);

    assert((test::out::print::Integer::ppz_p_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_o_int_fmt);

    assert((test::out::print::Integer::ppz_p_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_o_long_fmt);

    assert((test::out::print::Integer::ppz_p_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_o_long_long_fmt);

    assert((test::out::print::Integer::ppz_p_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_o_u_char_fmt);

    assert((test::out::print::Integer::ppz_p_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_o_u_short_fmt);

    assert((test::out::print::Integer::ppz_p_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_o_u_int_fmt);

    assert((test::out::print::Integer::ppz_p_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_o_u_long_fmt);

    assert((test::out::print::Integer::ppz_p_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppz_p_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_lh_char_fmt);

    assert((test::out::print::Integer::ppz_p_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_lh_short_fmt);

    assert((test::out::print::Integer::ppz_p_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_lh_int_fmt);

    assert((test::out::print::Integer::ppz_p_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_lh_long_fmt);

    assert((test::out::print::Integer::ppz_p_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_lh_long_long_fmt);

    assert((test::out::print::Integer::ppz_p_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_lh_u_char_fmt);

    assert((test::out::print::Integer::ppz_p_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_lh_u_short_fmt);

    assert((test::out::print::Integer::ppz_p_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_lh_u_int_fmt);

    assert((test::out::print::Integer::ppz_p_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_lh_u_long_fmt);

    assert((test::out::print::Integer::ppz_p_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppz_p_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_uh_char_fmt);

    assert((test::out::print::Integer::ppz_p_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_uh_short_fmt);

    assert((test::out::print::Integer::ppz_p_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_uh_int_fmt);

    assert((test::out::print::Integer::ppz_p_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_uh_long_fmt);

    assert((test::out::print::Integer::ppz_p_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_uh_long_long_fmt);

    assert((test::out::print::Integer::ppz_p_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_uh_u_char_fmt);

    assert((test::out::print::Integer::ppz_p_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_uh_u_short_fmt);

    assert((test::out::print::Integer::ppz_p_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_uh_u_int_fmt);

    assert((test::out::print::Integer::ppz_p_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_uh_u_long_fmt);

    assert((test::out::print::Integer::ppz_p_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_p_uh_u_long_long_fmt);


    assert((test::out::print::Integer::pp_p_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_ds_char_fmt);

    assert((test::out::print::Integer::pp_p_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_ds_short_fmt);

    assert((test::out::print::Integer::pp_p_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_ds_int_fmt);

    assert((test::out::print::Integer::pp_p_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_ds_long_fmt);

    assert((test::out::print::Integer::pp_p_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_ds_long_long_fmt);

    assert((test::out::print::Integer::pp_p_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_ds_u_char_fmt);

    assert((test::out::print::Integer::pp_p_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_ds_u_short_fmt);

    assert((test::out::print::Integer::pp_p_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_ds_u_int_fmt);

    assert((test::out::print::Integer::pp_p_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_ds_u_long_fmt);

    assert((test::out::print::Integer::pp_p_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_ds_u_long_long_fmt);


    assert((test::out::print::Integer::pp_p_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_du_char_fmt);

    assert((test::out::print::Integer::pp_p_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_du_short_fmt);

    assert((test::out::print::Integer::pp_p_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_du_int_fmt);

    assert((test::out::print::Integer::pp_p_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_du_long_fmt);

    assert((test::out::print::Integer::pp_p_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_du_long_long_fmt);

    assert((test::out::print::Integer::pp_p_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_du_u_char_fmt);

    assert((test::out::print::Integer::pp_p_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_du_u_short_fmt);

    assert((test::out::print::Integer::pp_p_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_du_u_int_fmt);

    assert((test::out::print::Integer::pp_p_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_du_u_long_fmt);

    assert((test::out::print::Integer::pp_p_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_du_u_long_long_fmt);


    assert((test::out::print::Integer::pp_p_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_o_char_fmt);

    assert((test::out::print::Integer::pp_p_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_o_short_fmt);

    assert((test::out::print::Integer::pp_p_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_o_int_fmt);

    assert((test::out::print::Integer::pp_p_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_o_long_fmt);

    assert((test::out::print::Integer::pp_p_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_o_long_long_fmt);

    assert((test::out::print::Integer::pp_p_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_o_u_char_fmt);

    assert((test::out::print::Integer::pp_p_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_o_u_short_fmt);

    assert((test::out::print::Integer::pp_p_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_o_u_int_fmt);

    assert((test::out::print::Integer::pp_p_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_o_u_long_fmt);

    assert((test::out::print::Integer::pp_p_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::pp_p_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_lh_char_fmt);

    assert((test::out::print::Integer::pp_p_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_lh_short_fmt);

    assert((test::out::print::Integer::pp_p_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_lh_int_fmt);

    assert((test::out::print::Integer::pp_p_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_lh_long_fmt);

    assert((test::out::print::Integer::pp_p_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_lh_long_long_fmt);

    assert((test::out::print::Integer::pp_p_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_lh_u_char_fmt);

    assert((test::out::print::Integer::pp_p_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_lh_u_short_fmt);

    assert((test::out::print::Integer::pp_p_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_lh_u_int_fmt);

    assert((test::out::print::Integer::pp_p_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_lh_u_long_fmt);

    assert((test::out::print::Integer::pp_p_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::pp_p_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_uh_char_fmt);

    assert((test::out::print::Integer::pp_p_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_uh_short_fmt);

    assert((test::out::print::Integer::pp_p_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_uh_int_fmt);

    assert((test::out::print::Integer::pp_p_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_uh_long_fmt);

    assert((test::out::print::Integer::pp_p_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_uh_long_long_fmt);

    assert((test::out::print::Integer::pp_p_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_uh_u_char_fmt);

    assert((test::out::print::Integer::pp_p_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_uh_u_short_fmt);

    assert((test::out::print::Integer::pp_p_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_uh_u_int_fmt);

    assert((test::out::print::Integer::pp_p_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_uh_u_long_fmt);

    assert((test::out::print::Integer::pp_p_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_p_uh_u_long_long_fmt);


    assert((test::out::print::Integer::pppz_p_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_ds_char_fmt);

    assert((test::out::print::Integer::pppz_p_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_ds_short_fmt);

    assert((test::out::print::Integer::pppz_p_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_ds_int_fmt);

    assert((test::out::print::Integer::pppz_p_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_ds_long_fmt);

    assert((test::out::print::Integer::pppz_p_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_ds_long_long_fmt);

    assert((test::out::print::Integer::pppz_p_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_ds_u_char_fmt);

    assert((test::out::print::Integer::pppz_p_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_ds_u_short_fmt);

    assert((test::out::print::Integer::pppz_p_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_ds_u_int_fmt);

    assert((test::out::print::Integer::pppz_p_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_ds_u_long_fmt);

    assert((test::out::print::Integer::pppz_p_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_ds_u_long_long_fmt);


    assert((test::out::print::Integer::pppz_p_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_du_char_fmt);

    assert((test::out::print::Integer::pppz_p_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_du_short_fmt);

    assert((test::out::print::Integer::pppz_p_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_du_int_fmt);

    assert((test::out::print::Integer::pppz_p_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_du_long_fmt);

    assert((test::out::print::Integer::pppz_p_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_du_long_long_fmt);

    assert((test::out::print::Integer::pppz_p_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_du_u_char_fmt);

    assert((test::out::print::Integer::pppz_p_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_du_u_short_fmt);

    assert((test::out::print::Integer::pppz_p_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_du_u_int_fmt);

    assert((test::out::print::Integer::pppz_p_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_du_u_long_fmt);

    assert((test::out::print::Integer::pppz_p_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_du_u_long_long_fmt);


    assert((test::out::print::Integer::pppz_p_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_o_char_fmt);

    assert((test::out::print::Integer::pppz_p_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_o_short_fmt);

    assert((test::out::print::Integer::pppz_p_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_o_int_fmt);

    assert((test::out::print::Integer::pppz_p_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_o_long_fmt);

    assert((test::out::print::Integer::pppz_p_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_o_long_long_fmt);

    assert((test::out::print::Integer::pppz_p_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_o_u_char_fmt);

    assert((test::out::print::Integer::pppz_p_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_o_u_short_fmt);

    assert((test::out::print::Integer::pppz_p_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_o_u_int_fmt);

    assert((test::out::print::Integer::pppz_p_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_o_u_long_fmt);

    assert((test::out::print::Integer::pppz_p_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::pppz_p_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_lh_char_fmt);

    assert((test::out::print::Integer::pppz_p_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_lh_short_fmt);

    assert((test::out::print::Integer::pppz_p_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_lh_int_fmt);

    assert((test::out::print::Integer::pppz_p_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_lh_long_fmt);

    assert((test::out::print::Integer::pppz_p_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_lh_long_long_fmt);

    assert((test::out::print::Integer::pppz_p_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_lh_u_char_fmt);

    assert((test::out::print::Integer::pppz_p_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_lh_u_short_fmt);

    assert((test::out::print::Integer::pppz_p_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_lh_u_int_fmt);

    assert((test::out::print::Integer::pppz_p_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_lh_u_long_fmt);

    assert((test::out::print::Integer::pppz_p_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::pppz_p_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_uh_char_fmt);

    assert((test::out::print::Integer::pppz_p_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_uh_short_fmt);

    assert((test::out::print::Integer::pppz_p_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_uh_int_fmt);

    assert((test::out::print::Integer::pppz_p_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_uh_long_fmt);

    assert((test::out::print::Integer::pppz_p_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_uh_long_long_fmt);

    assert((test::out::print::Integer::pppz_p_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_uh_u_char_fmt);

    assert((test::out::print::Integer::pppz_p_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_uh_u_short_fmt);

    assert((test::out::print::Integer::pppz_p_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_uh_u_int_fmt);

    assert((test::out::print::Integer::pppz_p_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_uh_u_long_fmt);

    assert((test::out::print::Integer::pppz_p_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_p_uh_u_long_long_fmt);


    assert((test::out::print::Integer::ps_p_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_ds_char_fmt);

    assert((test::out::print::Integer::ps_p_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_ds_short_fmt);

    assert((test::out::print::Integer::ps_p_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_ds_int_fmt);

    assert((test::out::print::Integer::ps_p_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_ds_long_fmt);

    assert((test::out::print::Integer::ps_p_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_ds_long_long_fmt);

    assert((test::out::print::Integer::ps_p_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_ds_u_char_fmt);

    assert((test::out::print::Integer::ps_p_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_ds_u_short_fmt);

    assert((test::out::print::Integer::ps_p_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_ds_u_int_fmt);

    assert((test::out::print::Integer::ps_p_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_ds_u_long_fmt);

    assert((test::out::print::Integer::ps_p_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_ds_u_long_long_fmt);


    assert((test::out::print::Integer::ps_p_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_du_char_fmt);

    assert((test::out::print::Integer::ps_p_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_du_short_fmt);

    assert((test::out::print::Integer::ps_p_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_du_int_fmt);

    assert((test::out::print::Integer::ps_p_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_du_long_fmt);

    assert((test::out::print::Integer::ps_p_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_du_long_long_fmt);

    assert((test::out::print::Integer::ps_p_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_du_u_char_fmt);

    assert((test::out::print::Integer::ps_p_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_du_u_short_fmt);

    assert((test::out::print::Integer::ps_p_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_du_u_int_fmt);

    assert((test::out::print::Integer::ps_p_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_du_u_long_fmt);

    assert((test::out::print::Integer::ps_p_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_du_u_long_long_fmt);


    assert((test::out::print::Integer::ps_p_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_o_char_fmt);

    assert((test::out::print::Integer::ps_p_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_o_short_fmt);

    assert((test::out::print::Integer::ps_p_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_o_int_fmt);

    assert((test::out::print::Integer::ps_p_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_o_long_fmt);

    assert((test::out::print::Integer::ps_p_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_o_long_long_fmt);

    assert((test::out::print::Integer::ps_p_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_o_u_char_fmt);

    assert((test::out::print::Integer::ps_p_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_o_u_short_fmt);

    assert((test::out::print::Integer::ps_p_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_o_u_int_fmt);

    assert((test::out::print::Integer::ps_p_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_o_u_long_fmt);

    assert((test::out::print::Integer::ps_p_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::ps_p_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_lh_char_fmt);

    assert((test::out::print::Integer::ps_p_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_lh_short_fmt);

    assert((test::out::print::Integer::ps_p_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_lh_int_fmt);

    assert((test::out::print::Integer::ps_p_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_lh_long_fmt);

    assert((test::out::print::Integer::ps_p_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_lh_long_long_fmt);

    assert((test::out::print::Integer::ps_p_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_lh_u_char_fmt);

    assert((test::out::print::Integer::ps_p_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_lh_u_short_fmt);

    assert((test::out::print::Integer::ps_p_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_lh_u_int_fmt);

    assert((test::out::print::Integer::ps_p_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_lh_u_long_fmt);

    assert((test::out::print::Integer::ps_p_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::ps_p_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_uh_char_fmt);

    assert((test::out::print::Integer::ps_p_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_uh_short_fmt);

    assert((test::out::print::Integer::ps_p_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_uh_int_fmt);

    assert((test::out::print::Integer::ps_p_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_uh_long_fmt);

    assert((test::out::print::Integer::ps_p_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_uh_long_long_fmt);

    assert((test::out::print::Integer::ps_p_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_uh_u_char_fmt);

    assert((test::out::print::Integer::ps_p_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_uh_u_short_fmt);

    assert((test::out::print::Integer::ps_p_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_uh_u_int_fmt);

    assert((test::out::print::Integer::ps_p_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_uh_u_long_fmt);

    assert((test::out::print::Integer::ps_p_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_p_uh_u_long_long_fmt);


    assert((test::out::print::Integer::pspz_p_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_ds_char_fmt);

    assert((test::out::print::Integer::pspz_p_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_ds_short_fmt);

    assert((test::out::print::Integer::pspz_p_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_ds_int_fmt);

    assert((test::out::print::Integer::pspz_p_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_ds_long_fmt);

    assert((test::out::print::Integer::pspz_p_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_ds_long_long_fmt);

    assert((test::out::print::Integer::pspz_p_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_ds_u_char_fmt);

    assert((test::out::print::Integer::pspz_p_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_ds_u_short_fmt);

    assert((test::out::print::Integer::pspz_p_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_ds_u_int_fmt);

    assert((test::out::print::Integer::pspz_p_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_ds_u_long_fmt);

    assert((test::out::print::Integer::pspz_p_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_ds_u_long_long_fmt);


    assert((test::out::print::Integer::pspz_p_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_du_char_fmt);

    assert((test::out::print::Integer::pspz_p_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_du_short_fmt);

    assert((test::out::print::Integer::pspz_p_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_du_int_fmt);

    assert((test::out::print::Integer::pspz_p_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_du_long_fmt);

    assert((test::out::print::Integer::pspz_p_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_du_long_long_fmt);

    assert((test::out::print::Integer::pspz_p_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_du_u_char_fmt);

    assert((test::out::print::Integer::pspz_p_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_du_u_short_fmt);

    assert((test::out::print::Integer::pspz_p_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_du_u_int_fmt);

    assert((test::out::print::Integer::pspz_p_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_du_u_long_fmt);

    assert((test::out::print::Integer::pspz_p_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_du_u_long_long_fmt);


    assert((test::out::print::Integer::pspz_p_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_o_char_fmt);

    assert((test::out::print::Integer::pspz_p_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_o_short_fmt);

    assert((test::out::print::Integer::pspz_p_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_o_int_fmt);

    assert((test::out::print::Integer::pspz_p_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_o_long_fmt);

    assert((test::out::print::Integer::pspz_p_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_o_long_long_fmt);

    assert((test::out::print::Integer::pspz_p_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_o_u_char_fmt);

    assert((test::out::print::Integer::pspz_p_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_o_u_short_fmt);

    assert((test::out::print::Integer::pspz_p_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_o_u_int_fmt);

    assert((test::out::print::Integer::pspz_p_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_o_u_long_fmt);

    assert((test::out::print::Integer::pspz_p_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::pspz_p_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_lh_char_fmt);

    assert((test::out::print::Integer::pspz_p_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_lh_short_fmt);

    assert((test::out::print::Integer::pspz_p_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_lh_int_fmt);

    assert((test::out::print::Integer::pspz_p_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_lh_long_fmt);

    assert((test::out::print::Integer::pspz_p_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_lh_long_long_fmt);

    assert((test::out::print::Integer::pspz_p_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_lh_u_char_fmt);

    assert((test::out::print::Integer::pspz_p_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_lh_u_short_fmt);

    assert((test::out::print::Integer::pspz_p_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_lh_u_int_fmt);

    assert((test::out::print::Integer::pspz_p_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_lh_u_long_fmt);

    assert((test::out::print::Integer::pspz_p_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::pspz_p_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_uh_char_fmt);

    assert((test::out::print::Integer::pspz_p_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_uh_short_fmt);

    assert((test::out::print::Integer::pspz_p_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_uh_int_fmt);

    assert((test::out::print::Integer::pspz_p_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_uh_long_fmt);

    assert((test::out::print::Integer::pspz_p_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_uh_long_long_fmt);

    assert((test::out::print::Integer::pspz_p_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_uh_u_char_fmt);

    assert((test::out::print::Integer::pspz_p_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_uh_u_short_fmt);

    assert((test::out::print::Integer::pspz_p_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_uh_u_int_fmt);

    assert((test::out::print::Integer::pspz_p_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_uh_u_long_fmt);

    assert((test::out::print::Integer::pspz_p_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_p_uh_u_long_long_fmt);


    assert((test::out::print::Integer::pz_p_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_ds_char_fmt);

    assert((test::out::print::Integer::pz_p_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_ds_short_fmt);

    assert((test::out::print::Integer::pz_p_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_ds_int_fmt);

    assert((test::out::print::Integer::pz_p_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_ds_long_fmt);

    assert((test::out::print::Integer::pz_p_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_ds_long_long_fmt);

    assert((test::out::print::Integer::pz_p_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_ds_u_char_fmt);

    assert((test::out::print::Integer::pz_p_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_ds_u_short_fmt);

    assert((test::out::print::Integer::pz_p_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_ds_u_int_fmt);

    assert((test::out::print::Integer::pz_p_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_ds_u_long_fmt);

    assert((test::out::print::Integer::pz_p_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_ds_u_long_long_fmt);


    assert((test::out::print::Integer::pz_p_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_du_char_fmt);

    assert((test::out::print::Integer::pz_p_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_du_short_fmt);

    assert((test::out::print::Integer::pz_p_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_du_int_fmt);

    assert((test::out::print::Integer::pz_p_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_du_long_fmt);

    assert((test::out::print::Integer::pz_p_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_du_long_long_fmt);

    assert((test::out::print::Integer::pz_p_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_du_u_char_fmt);

    assert((test::out::print::Integer::pz_p_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_du_u_short_fmt);

    assert((test::out::print::Integer::pz_p_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_du_u_int_fmt);

    assert((test::out::print::Integer::pz_p_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_du_u_long_fmt);

    assert((test::out::print::Integer::pz_p_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_du_u_long_long_fmt);


    assert((test::out::print::Integer::pz_p_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_o_char_fmt);

    assert((test::out::print::Integer::pz_p_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_o_short_fmt);

    assert((test::out::print::Integer::pz_p_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_o_int_fmt);

    assert((test::out::print::Integer::pz_p_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_o_long_fmt);

    assert((test::out::print::Integer::pz_p_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_o_long_long_fmt);

    assert((test::out::print::Integer::pz_p_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_o_u_char_fmt);

    assert((test::out::print::Integer::pz_p_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_o_u_short_fmt);

    assert((test::out::print::Integer::pz_p_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_o_u_int_fmt);

    assert((test::out::print::Integer::pz_p_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_o_u_long_fmt);

    assert((test::out::print::Integer::pz_p_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::pz_p_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_lh_char_fmt);

    assert((test::out::print::Integer::pz_p_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_lh_short_fmt);

    assert((test::out::print::Integer::pz_p_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_lh_int_fmt);

    assert((test::out::print::Integer::pz_p_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_lh_long_fmt);

    assert((test::out::print::Integer::pz_p_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_lh_long_long_fmt);

    assert((test::out::print::Integer::pz_p_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_lh_u_char_fmt);

    assert((test::out::print::Integer::pz_p_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_lh_u_short_fmt);

    assert((test::out::print::Integer::pz_p_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_lh_u_int_fmt);

    assert((test::out::print::Integer::pz_p_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_lh_u_long_fmt);

    assert((test::out::print::Integer::pz_p_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::pz_p_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_uh_char_fmt);

    assert((test::out::print::Integer::pz_p_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_uh_short_fmt);

    assert((test::out::print::Integer::pz_p_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_uh_int_fmt);

    assert((test::out::print::Integer::pz_p_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_uh_long_fmt);

    assert((test::out::print::Integer::pz_p_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_uh_long_long_fmt);

    assert((test::out::print::Integer::pz_p_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_uh_u_char_fmt);

    assert((test::out::print::Integer::pz_p_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_uh_u_short_fmt);

    assert((test::out::print::Integer::pz_p_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_uh_u_int_fmt);

    assert((test::out::print::Integer::pz_p_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_uh_u_long_fmt);

    assert((test::out::print::Integer::pz_p_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_p_uh_u_long_long_fmt);


///
    assert((test::out::print::Integer::wp_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_ds_char_fmt);

    assert((test::out::print::Integer::wp_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_ds_short_fmt);

    assert((test::out::print::Integer::wp_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_ds_int_fmt);

    assert((test::out::print::Integer::wp_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_ds_long_fmt);

    assert((test::out::print::Integer::wp_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_ds_long_long_fmt);

    assert((test::out::print::Integer::wp_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_ds_u_char_fmt);

    assert((test::out::print::Integer::wp_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_ds_u_short_fmt);

    assert((test::out::print::Integer::wp_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_ds_u_int_fmt);

    assert((test::out::print::Integer::wp_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_ds_u_long_fmt);

    assert((test::out::print::Integer::wp_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_ds_u_long_long_fmt);


    assert((test::out::print::Integer::wp_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_du_char_fmt);

    assert((test::out::print::Integer::wp_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_du_short_fmt);

    assert((test::out::print::Integer::wp_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_du_int_fmt);

    assert((test::out::print::Integer::wp_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_du_long_fmt);

    assert((test::out::print::Integer::wp_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_du_long_long_fmt);

    assert((test::out::print::Integer::wp_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_du_u_char_fmt);

    assert((test::out::print::Integer::wp_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_du_u_short_fmt);

    assert((test::out::print::Integer::wp_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_du_u_int_fmt);

    assert((test::out::print::Integer::wp_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_du_u_long_fmt);

    assert((test::out::print::Integer::wp_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_du_u_long_long_fmt);


    assert((test::out::print::Integer::wp_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_o_char_fmt);

    assert((test::out::print::Integer::wp_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_o_short_fmt);

    assert((test::out::print::Integer::wp_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_o_int_fmt);

    assert((test::out::print::Integer::wp_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_o_long_fmt);

    assert((test::out::print::Integer::wp_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_o_long_long_fmt);

    assert((test::out::print::Integer::wp_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_o_u_char_fmt);

    assert((test::out::print::Integer::wp_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_o_u_short_fmt);

    assert((test::out::print::Integer::wp_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_o_u_int_fmt);

    assert((test::out::print::Integer::wp_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_o_u_long_fmt);

    assert((test::out::print::Integer::wp_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::wp_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_lh_char_fmt);

    assert((test::out::print::Integer::wp_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_lh_short_fmt);

    assert((test::out::print::Integer::wp_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_lh_int_fmt);

    assert((test::out::print::Integer::wp_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_lh_long_fmt);

    assert((test::out::print::Integer::wp_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_lh_long_long_fmt);

    assert((test::out::print::Integer::wp_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_lh_u_char_fmt);

    assert((test::out::print::Integer::wp_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_lh_u_short_fmt);

    assert((test::out::print::Integer::wp_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_lh_u_int_fmt);

    assert((test::out::print::Integer::wp_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_lh_u_long_fmt);

    assert((test::out::print::Integer::wp_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::wp_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_uh_char_fmt);

    assert((test::out::print::Integer::wp_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_uh_short_fmt);

    assert((test::out::print::Integer::wp_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_uh_int_fmt);

    assert((test::out::print::Integer::wp_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_uh_long_fmt);

    assert((test::out::print::Integer::wp_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_uh_long_long_fmt);

    assert((test::out::print::Integer::wp_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_uh_u_char_fmt);

    assert((test::out::print::Integer::wp_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_uh_u_short_fmt);

    assert((test::out::print::Integer::wp_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_uh_u_int_fmt);

    assert((test::out::print::Integer::wp_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_uh_u_long_fmt);

    assert((test::out::print::Integer::wp_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::wp_uh_u_long_long_fmt);


    assert((test::out::print::Integer::p_wp_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_ds_char_fmt);

    assert((test::out::print::Integer::p_wp_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_ds_short_fmt);

    assert((test::out::print::Integer::p_wp_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_ds_int_fmt);

    assert((test::out::print::Integer::p_wp_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_ds_long_fmt);

    assert((test::out::print::Integer::p_wp_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_ds_long_long_fmt);

    assert((test::out::print::Integer::p_wp_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_ds_u_char_fmt);

    assert((test::out::print::Integer::p_wp_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_ds_u_short_fmt);

    assert((test::out::print::Integer::p_wp_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_ds_u_int_fmt);

    assert((test::out::print::Integer::p_wp_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_ds_u_long_fmt);

    assert((test::out::print::Integer::p_wp_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_ds_u_long_long_fmt);


    assert((test::out::print::Integer::p_wp_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_du_char_fmt);

    assert((test::out::print::Integer::p_wp_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_du_short_fmt);

    assert((test::out::print::Integer::p_wp_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_du_int_fmt);

    assert((test::out::print::Integer::p_wp_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_du_long_fmt);

    assert((test::out::print::Integer::p_wp_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_du_long_long_fmt);

    assert((test::out::print::Integer::p_wp_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_du_u_char_fmt);

    assert((test::out::print::Integer::p_wp_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_du_u_short_fmt);

    assert((test::out::print::Integer::p_wp_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_du_u_int_fmt);

    assert((test::out::print::Integer::p_wp_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_du_u_long_fmt);

    assert((test::out::print::Integer::p_wp_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_du_u_long_long_fmt);


    assert((test::out::print::Integer::p_wp_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_o_char_fmt);

    assert((test::out::print::Integer::p_wp_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_o_short_fmt);

    assert((test::out::print::Integer::p_wp_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_o_int_fmt);

    assert((test::out::print::Integer::p_wp_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_o_long_fmt);

    assert((test::out::print::Integer::p_wp_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_o_long_long_fmt);

    assert((test::out::print::Integer::p_wp_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_o_u_char_fmt);

    assert((test::out::print::Integer::p_wp_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_o_u_short_fmt);

    assert((test::out::print::Integer::p_wp_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_o_u_int_fmt);

    assert((test::out::print::Integer::p_wp_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_o_u_long_fmt);

    assert((test::out::print::Integer::p_wp_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::p_wp_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_lh_char_fmt);

    assert((test::out::print::Integer::p_wp_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_lh_short_fmt);

    assert((test::out::print::Integer::p_wp_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_lh_int_fmt);

    assert((test::out::print::Integer::p_wp_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_lh_long_fmt);

    assert((test::out::print::Integer::p_wp_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_lh_long_long_fmt);

    assert((test::out::print::Integer::p_wp_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_lh_u_char_fmt);

    assert((test::out::print::Integer::p_wp_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_lh_u_short_fmt);

    assert((test::out::print::Integer::p_wp_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_lh_u_int_fmt);

    assert((test::out::print::Integer::p_wp_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_lh_u_long_fmt);

    assert((test::out::print::Integer::p_wp_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::p_wp_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_uh_char_fmt);

    assert((test::out::print::Integer::p_wp_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_uh_short_fmt);

    assert((test::out::print::Integer::p_wp_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_uh_int_fmt);

    assert((test::out::print::Integer::p_wp_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_uh_long_fmt);

    assert((test::out::print::Integer::p_wp_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_uh_long_long_fmt);

    assert((test::out::print::Integer::p_wp_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_uh_u_char_fmt);

    assert((test::out::print::Integer::p_wp_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_uh_u_short_fmt);

    assert((test::out::print::Integer::p_wp_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_uh_u_int_fmt);

    assert((test::out::print::Integer::p_wp_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_uh_u_long_fmt);

    assert((test::out::print::Integer::p_wp_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::p_wp_uh_u_long_long_fmt);


    assert((test::out::print::Integer::ppp_wp_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_ds_char_fmt);

    assert((test::out::print::Integer::ppp_wp_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_ds_short_fmt);

    assert((test::out::print::Integer::ppp_wp_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_ds_int_fmt);

    assert((test::out::print::Integer::ppp_wp_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_ds_long_fmt);

    assert((test::out::print::Integer::ppp_wp_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_ds_long_long_fmt);

    assert((test::out::print::Integer::ppp_wp_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_ds_u_char_fmt);

    assert((test::out::print::Integer::ppp_wp_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_ds_u_short_fmt);

    assert((test::out::print::Integer::ppp_wp_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_ds_u_int_fmt);

    assert((test::out::print::Integer::ppp_wp_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_ds_u_long_fmt);

    assert((test::out::print::Integer::ppp_wp_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_ds_u_long_long_fmt);


    assert((test::out::print::Integer::ppp_wp_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_du_char_fmt);

    assert((test::out::print::Integer::ppp_wp_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_du_short_fmt);

    assert((test::out::print::Integer::ppp_wp_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_du_int_fmt);

    assert((test::out::print::Integer::ppp_wp_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_du_long_fmt);

    assert((test::out::print::Integer::ppp_wp_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_du_long_long_fmt);

    assert((test::out::print::Integer::ppp_wp_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_du_u_char_fmt);

    assert((test::out::print::Integer::ppp_wp_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_du_u_short_fmt);

    assert((test::out::print::Integer::ppp_wp_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_du_u_int_fmt);

    assert((test::out::print::Integer::ppp_wp_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_du_u_long_fmt);

    assert((test::out::print::Integer::ppp_wp_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_du_u_long_long_fmt);


    assert((test::out::print::Integer::ppp_wp_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_o_char_fmt);

    assert((test::out::print::Integer::ppp_wp_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_o_short_fmt);

    assert((test::out::print::Integer::ppp_wp_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_o_int_fmt);

    assert((test::out::print::Integer::ppp_wp_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_o_long_fmt);

    assert((test::out::print::Integer::ppp_wp_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_o_long_long_fmt);

    assert((test::out::print::Integer::ppp_wp_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_o_u_char_fmt);

    assert((test::out::print::Integer::ppp_wp_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_o_u_short_fmt);

    assert((test::out::print::Integer::ppp_wp_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_o_u_int_fmt);

    assert((test::out::print::Integer::ppp_wp_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_o_u_long_fmt);

    assert((test::out::print::Integer::ppp_wp_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppp_wp_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_lh_char_fmt);

    assert((test::out::print::Integer::ppp_wp_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_lh_short_fmt);

    assert((test::out::print::Integer::ppp_wp_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_lh_int_fmt);

    assert((test::out::print::Integer::ppp_wp_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_lh_long_fmt);

    assert((test::out::print::Integer::ppp_wp_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_lh_long_long_fmt);

    assert((test::out::print::Integer::ppp_wp_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_lh_u_char_fmt);

    assert((test::out::print::Integer::ppp_wp_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_lh_u_short_fmt);

    assert((test::out::print::Integer::ppp_wp_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_lh_u_int_fmt);

    assert((test::out::print::Integer::ppp_wp_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_lh_u_long_fmt);

    assert((test::out::print::Integer::ppp_wp_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppp_wp_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_uh_char_fmt);

    assert((test::out::print::Integer::ppp_wp_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_uh_short_fmt);

    assert((test::out::print::Integer::ppp_wp_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_uh_int_fmt);

    assert((test::out::print::Integer::ppp_wp_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_uh_long_fmt);

    assert((test::out::print::Integer::ppp_wp_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_uh_long_long_fmt);

    assert((test::out::print::Integer::ppp_wp_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_uh_u_char_fmt);

    assert((test::out::print::Integer::ppp_wp_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_uh_u_short_fmt);

    assert((test::out::print::Integer::ppp_wp_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_uh_u_int_fmt);

    assert((test::out::print::Integer::ppp_wp_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_uh_u_long_fmt);

    assert((test::out::print::Integer::ppp_wp_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppp_wp_uh_u_long_long_fmt);


    assert((test::out::print::Integer::ppppz_wp_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_ds_char_fmt);

    assert((test::out::print::Integer::ppppz_wp_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_ds_short_fmt);

    assert((test::out::print::Integer::ppppz_wp_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_ds_int_fmt);

    assert((test::out::print::Integer::ppppz_wp_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_ds_long_fmt);

    assert((test::out::print::Integer::ppppz_wp_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_ds_long_long_fmt);

    assert((test::out::print::Integer::ppppz_wp_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_ds_u_char_fmt);

    assert((test::out::print::Integer::ppppz_wp_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_ds_u_short_fmt);

    assert((test::out::print::Integer::ppppz_wp_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_ds_u_int_fmt);

    assert((test::out::print::Integer::ppppz_wp_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_ds_u_long_fmt);

    assert((test::out::print::Integer::ppppz_wp_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_ds_u_long_long_fmt);


    assert((test::out::print::Integer::ppppz_wp_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_du_char_fmt);

    assert((test::out::print::Integer::ppppz_wp_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_du_short_fmt);

    assert((test::out::print::Integer::ppppz_wp_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_du_int_fmt);

    assert((test::out::print::Integer::ppppz_wp_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_du_long_fmt);

    assert((test::out::print::Integer::ppppz_wp_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_du_long_long_fmt);

    assert((test::out::print::Integer::ppppz_wp_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_du_u_char_fmt);

    assert((test::out::print::Integer::ppppz_wp_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_du_u_short_fmt);

    assert((test::out::print::Integer::ppppz_wp_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_du_u_int_fmt);

    assert((test::out::print::Integer::ppppz_wp_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_du_u_long_fmt);

    assert((test::out::print::Integer::ppppz_wp_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_du_u_long_long_fmt);


    assert((test::out::print::Integer::ppppz_wp_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_o_char_fmt);

    assert((test::out::print::Integer::ppppz_wp_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_o_short_fmt);

    assert((test::out::print::Integer::ppppz_wp_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_o_int_fmt);

    assert((test::out::print::Integer::ppppz_wp_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_o_long_fmt);

    assert((test::out::print::Integer::ppppz_wp_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_o_long_long_fmt);

    assert((test::out::print::Integer::ppppz_wp_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_o_u_char_fmt);

    assert((test::out::print::Integer::ppppz_wp_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_o_u_short_fmt);

    assert((test::out::print::Integer::ppppz_wp_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_o_u_int_fmt);

    assert((test::out::print::Integer::ppppz_wp_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_o_u_long_fmt);

    assert((test::out::print::Integer::ppppz_wp_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppppz_wp_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_lh_char_fmt);

    assert((test::out::print::Integer::ppppz_wp_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_lh_short_fmt);

    assert((test::out::print::Integer::ppppz_wp_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_lh_int_fmt);

    assert((test::out::print::Integer::ppppz_wp_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_lh_long_fmt);

    assert((test::out::print::Integer::ppppz_wp_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_lh_long_long_fmt);

    assert((test::out::print::Integer::ppppz_wp_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_lh_u_char_fmt);

    assert((test::out::print::Integer::ppppz_wp_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_lh_u_short_fmt);

    assert((test::out::print::Integer::ppppz_wp_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_lh_u_int_fmt);

    assert((test::out::print::Integer::ppppz_wp_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_lh_u_long_fmt);

    assert((test::out::print::Integer::ppppz_wp_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppppz_wp_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_uh_char_fmt);

    assert((test::out::print::Integer::ppppz_wp_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_uh_short_fmt);

    assert((test::out::print::Integer::ppppz_wp_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_uh_int_fmt);

    assert((test::out::print::Integer::ppppz_wp_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_uh_long_fmt);

    assert((test::out::print::Integer::ppppz_wp_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_uh_long_long_fmt);

    assert((test::out::print::Integer::ppppz_wp_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_uh_u_char_fmt);

    assert((test::out::print::Integer::ppppz_wp_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_uh_u_short_fmt);

    assert((test::out::print::Integer::ppppz_wp_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_uh_u_int_fmt);

    assert((test::out::print::Integer::ppppz_wp_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_uh_u_long_fmt);

    assert((test::out::print::Integer::ppppz_wp_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppppz_wp_uh_u_long_long_fmt);


    assert((test::out::print::Integer::pps_wp_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_ds_char_fmt);

    assert((test::out::print::Integer::pps_wp_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_ds_short_fmt);

    assert((test::out::print::Integer::pps_wp_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_ds_int_fmt);

    assert((test::out::print::Integer::pps_wp_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_ds_long_fmt);

    assert((test::out::print::Integer::pps_wp_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_ds_long_long_fmt);

    assert((test::out::print::Integer::pps_wp_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_ds_u_char_fmt);

    assert((test::out::print::Integer::pps_wp_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_ds_u_short_fmt);

    assert((test::out::print::Integer::pps_wp_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_ds_u_int_fmt);

    assert((test::out::print::Integer::pps_wp_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_ds_u_long_fmt);

    assert((test::out::print::Integer::pps_wp_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_ds_u_long_long_fmt);


    assert((test::out::print::Integer::pps_wp_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_du_char_fmt);

    assert((test::out::print::Integer::pps_wp_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_du_short_fmt);

    assert((test::out::print::Integer::pps_wp_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_du_int_fmt);

    assert((test::out::print::Integer::pps_wp_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_du_long_fmt);

    assert((test::out::print::Integer::pps_wp_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_du_long_long_fmt);

    assert((test::out::print::Integer::pps_wp_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_du_u_char_fmt);

    assert((test::out::print::Integer::pps_wp_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_du_u_short_fmt);

    assert((test::out::print::Integer::pps_wp_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_du_u_int_fmt);

    assert((test::out::print::Integer::pps_wp_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_du_u_long_fmt);

    assert((test::out::print::Integer::pps_wp_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_du_u_long_long_fmt);


    assert((test::out::print::Integer::pps_wp_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_o_char_fmt);

    assert((test::out::print::Integer::pps_wp_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_o_short_fmt);

    assert((test::out::print::Integer::pps_wp_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_o_int_fmt);

    assert((test::out::print::Integer::pps_wp_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_o_long_fmt);

    assert((test::out::print::Integer::pps_wp_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_o_long_long_fmt);

    assert((test::out::print::Integer::pps_wp_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_o_u_char_fmt);

    assert((test::out::print::Integer::pps_wp_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_o_u_short_fmt);

    assert((test::out::print::Integer::pps_wp_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_o_u_int_fmt);

    assert((test::out::print::Integer::pps_wp_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_o_u_long_fmt);

    assert((test::out::print::Integer::pps_wp_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::pps_wp_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_lh_char_fmt);

    assert((test::out::print::Integer::pps_wp_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_lh_short_fmt);

    assert((test::out::print::Integer::pps_wp_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_lh_int_fmt);

    assert((test::out::print::Integer::pps_wp_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_lh_long_fmt);

    assert((test::out::print::Integer::pps_wp_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_lh_long_long_fmt);

    assert((test::out::print::Integer::pps_wp_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_lh_u_char_fmt);

    assert((test::out::print::Integer::pps_wp_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_lh_u_short_fmt);

    assert((test::out::print::Integer::pps_wp_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_lh_u_int_fmt);

    assert((test::out::print::Integer::pps_wp_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_lh_u_long_fmt);

    assert((test::out::print::Integer::pps_wp_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::pps_wp_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_uh_char_fmt);

    assert((test::out::print::Integer::pps_wp_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_uh_short_fmt);

    assert((test::out::print::Integer::pps_wp_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_uh_int_fmt);

    assert((test::out::print::Integer::pps_wp_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_uh_long_fmt);

    assert((test::out::print::Integer::pps_wp_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_uh_long_long_fmt);

    assert((test::out::print::Integer::pps_wp_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_uh_u_char_fmt);

    assert((test::out::print::Integer::pps_wp_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_uh_u_short_fmt);

    assert((test::out::print::Integer::pps_wp_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_uh_u_int_fmt);

    assert((test::out::print::Integer::pps_wp_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_uh_u_long_fmt);

    assert((test::out::print::Integer::pps_wp_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pps_wp_uh_u_long_long_fmt);


    assert((test::out::print::Integer::ppspz_wp_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_ds_char_fmt);

    assert((test::out::print::Integer::ppspz_wp_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_ds_short_fmt);

    assert((test::out::print::Integer::ppspz_wp_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_ds_int_fmt);

    assert((test::out::print::Integer::ppspz_wp_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_ds_long_fmt);

    assert((test::out::print::Integer::ppspz_wp_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_ds_long_long_fmt);

    assert((test::out::print::Integer::ppspz_wp_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_ds_u_char_fmt);

    assert((test::out::print::Integer::ppspz_wp_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_ds_u_short_fmt);

    assert((test::out::print::Integer::ppspz_wp_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_ds_u_int_fmt);

    assert((test::out::print::Integer::ppspz_wp_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_ds_u_long_fmt);

    assert((test::out::print::Integer::ppspz_wp_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_ds_u_long_long_fmt);


    assert((test::out::print::Integer::ppspz_wp_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_du_char_fmt);

    assert((test::out::print::Integer::ppspz_wp_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_du_short_fmt);

    assert((test::out::print::Integer::ppspz_wp_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_du_int_fmt);

    assert((test::out::print::Integer::ppspz_wp_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_du_long_fmt);

    assert((test::out::print::Integer::ppspz_wp_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_du_long_long_fmt);

    assert((test::out::print::Integer::ppspz_wp_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_du_u_char_fmt);

    assert((test::out::print::Integer::ppspz_wp_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_du_u_short_fmt);

    assert((test::out::print::Integer::ppspz_wp_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_du_u_int_fmt);

    assert((test::out::print::Integer::ppspz_wp_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_du_u_long_fmt);

    assert((test::out::print::Integer::ppspz_wp_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_du_u_long_long_fmt);


    assert((test::out::print::Integer::ppspz_wp_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_o_char_fmt);

    assert((test::out::print::Integer::ppspz_wp_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_o_short_fmt);

    assert((test::out::print::Integer::ppspz_wp_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_o_int_fmt);

    assert((test::out::print::Integer::ppspz_wp_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_o_long_fmt);

    assert((test::out::print::Integer::ppspz_wp_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_o_long_long_fmt);

    assert((test::out::print::Integer::ppspz_wp_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_o_u_char_fmt);

    assert((test::out::print::Integer::ppspz_wp_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_o_u_short_fmt);

    assert((test::out::print::Integer::ppspz_wp_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_o_u_int_fmt);

    assert((test::out::print::Integer::ppspz_wp_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_o_u_long_fmt);

    assert((test::out::print::Integer::ppspz_wp_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppspz_wp_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_lh_char_fmt);

    assert((test::out::print::Integer::ppspz_wp_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_lh_short_fmt);

    assert((test::out::print::Integer::ppspz_wp_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_lh_int_fmt);

    assert((test::out::print::Integer::ppspz_wp_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_lh_long_fmt);

    assert((test::out::print::Integer::ppspz_wp_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_lh_long_long_fmt);

    assert((test::out::print::Integer::ppspz_wp_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_lh_u_char_fmt);

    assert((test::out::print::Integer::ppspz_wp_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_lh_u_short_fmt);

    assert((test::out::print::Integer::ppspz_wp_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_lh_u_int_fmt);

    assert((test::out::print::Integer::ppspz_wp_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_lh_u_long_fmt);

    assert((test::out::print::Integer::ppspz_wp_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppspz_wp_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_uh_char_fmt);

    assert((test::out::print::Integer::ppspz_wp_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_uh_short_fmt);

    assert((test::out::print::Integer::ppspz_wp_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_uh_int_fmt);

    assert((test::out::print::Integer::ppspz_wp_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_uh_long_fmt);

    assert((test::out::print::Integer::ppspz_wp_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_uh_long_long_fmt);

    assert((test::out::print::Integer::ppspz_wp_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_uh_u_char_fmt);

    assert((test::out::print::Integer::ppspz_wp_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_uh_u_short_fmt);

    assert((test::out::print::Integer::ppspz_wp_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_uh_u_int_fmt);

    assert((test::out::print::Integer::ppspz_wp_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_uh_u_long_fmt);

    assert((test::out::print::Integer::ppspz_wp_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppspz_wp_uh_u_long_long_fmt);


    assert((test::out::print::Integer::ppz_wp_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_ds_char_fmt);

    assert((test::out::print::Integer::ppz_wp_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_ds_short_fmt);

    assert((test::out::print::Integer::ppz_wp_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_ds_int_fmt);

    assert((test::out::print::Integer::ppz_wp_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_ds_long_fmt);

    assert((test::out::print::Integer::ppz_wp_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_ds_long_long_fmt);

    assert((test::out::print::Integer::ppz_wp_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_ds_u_char_fmt);

    assert((test::out::print::Integer::ppz_wp_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_ds_u_short_fmt);

    assert((test::out::print::Integer::ppz_wp_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_ds_u_int_fmt);

    assert((test::out::print::Integer::ppz_wp_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_ds_u_long_fmt);

    assert((test::out::print::Integer::ppz_wp_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_ds_u_long_long_fmt);


    assert((test::out::print::Integer::ppz_wp_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_du_char_fmt);

    assert((test::out::print::Integer::ppz_wp_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_du_short_fmt);

    assert((test::out::print::Integer::ppz_wp_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_du_int_fmt);

    assert((test::out::print::Integer::ppz_wp_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_du_long_fmt);

    assert((test::out::print::Integer::ppz_wp_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_du_long_long_fmt);

    assert((test::out::print::Integer::ppz_wp_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_du_u_char_fmt);

    assert((test::out::print::Integer::ppz_wp_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_du_u_short_fmt);

    assert((test::out::print::Integer::ppz_wp_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_du_u_int_fmt);

    assert((test::out::print::Integer::ppz_wp_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_du_u_long_fmt);

    assert((test::out::print::Integer::ppz_wp_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_du_u_long_long_fmt);


    assert((test::out::print::Integer::ppz_wp_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_o_char_fmt);

    assert((test::out::print::Integer::ppz_wp_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_o_short_fmt);

    assert((test::out::print::Integer::ppz_wp_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_o_int_fmt);

    assert((test::out::print::Integer::ppz_wp_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_o_long_fmt);

    assert((test::out::print::Integer::ppz_wp_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_o_long_long_fmt);

    assert((test::out::print::Integer::ppz_wp_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_o_u_char_fmt);

    assert((test::out::print::Integer::ppz_wp_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_o_u_short_fmt);

    assert((test::out::print::Integer::ppz_wp_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_o_u_int_fmt);

    assert((test::out::print::Integer::ppz_wp_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_o_u_long_fmt);

    assert((test::out::print::Integer::ppz_wp_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppz_wp_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_lh_char_fmt);

    assert((test::out::print::Integer::ppz_wp_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_lh_short_fmt);

    assert((test::out::print::Integer::ppz_wp_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_lh_int_fmt);

    assert((test::out::print::Integer::ppz_wp_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_lh_long_fmt);

    assert((test::out::print::Integer::ppz_wp_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_lh_long_long_fmt);

    assert((test::out::print::Integer::ppz_wp_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_lh_u_char_fmt);

    assert((test::out::print::Integer::ppz_wp_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_lh_u_short_fmt);

    assert((test::out::print::Integer::ppz_wp_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_lh_u_int_fmt);

    assert((test::out::print::Integer::ppz_wp_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_lh_u_long_fmt);

    assert((test::out::print::Integer::ppz_wp_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::ppz_wp_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_uh_char_fmt);

    assert((test::out::print::Integer::ppz_wp_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_uh_short_fmt);

    assert((test::out::print::Integer::ppz_wp_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_uh_int_fmt);

    assert((test::out::print::Integer::ppz_wp_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_uh_long_fmt);

    assert((test::out::print::Integer::ppz_wp_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_uh_long_long_fmt);

    assert((test::out::print::Integer::ppz_wp_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_uh_u_char_fmt);

    assert((test::out::print::Integer::ppz_wp_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_uh_u_short_fmt);

    assert((test::out::print::Integer::ppz_wp_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_uh_u_int_fmt);

    assert((test::out::print::Integer::ppz_wp_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_uh_u_long_fmt);

    assert((test::out::print::Integer::ppz_wp_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ppz_wp_uh_u_long_long_fmt);


    assert((test::out::print::Integer::pp_wp_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_ds_char_fmt);

    assert((test::out::print::Integer::pp_wp_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_ds_short_fmt);

    assert((test::out::print::Integer::pp_wp_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_ds_int_fmt);

    assert((test::out::print::Integer::pp_wp_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_ds_long_fmt);

    assert((test::out::print::Integer::pp_wp_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_ds_long_long_fmt);

    assert((test::out::print::Integer::pp_wp_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_ds_u_char_fmt);

    assert((test::out::print::Integer::pp_wp_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_ds_u_short_fmt);

    assert((test::out::print::Integer::pp_wp_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_ds_u_int_fmt);

    assert((test::out::print::Integer::pp_wp_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_ds_u_long_fmt);

    assert((test::out::print::Integer::pp_wp_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_ds_u_long_long_fmt);


    assert((test::out::print::Integer::pp_wp_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_du_char_fmt);

    assert((test::out::print::Integer::pp_wp_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_du_short_fmt);

    assert((test::out::print::Integer::pp_wp_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_du_int_fmt);

    assert((test::out::print::Integer::pp_wp_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_du_long_fmt);

    assert((test::out::print::Integer::pp_wp_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_du_long_long_fmt);

    assert((test::out::print::Integer::pp_wp_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_du_u_char_fmt);

    assert((test::out::print::Integer::pp_wp_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_du_u_short_fmt);

    assert((test::out::print::Integer::pp_wp_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_du_u_int_fmt);

    assert((test::out::print::Integer::pp_wp_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_du_u_long_fmt);

    assert((test::out::print::Integer::pp_wp_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_du_u_long_long_fmt);


    assert((test::out::print::Integer::pp_wp_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_o_char_fmt);

    assert((test::out::print::Integer::pp_wp_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_o_short_fmt);

    assert((test::out::print::Integer::pp_wp_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_o_int_fmt);

    assert((test::out::print::Integer::pp_wp_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_o_long_fmt);

    assert((test::out::print::Integer::pp_wp_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_o_long_long_fmt);

    assert((test::out::print::Integer::pp_wp_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_o_u_char_fmt);

    assert((test::out::print::Integer::pp_wp_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_o_u_short_fmt);

    assert((test::out::print::Integer::pp_wp_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_o_u_int_fmt);

    assert((test::out::print::Integer::pp_wp_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_o_u_long_fmt);

    assert((test::out::print::Integer::pp_wp_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::pp_wp_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_lh_char_fmt);

    assert((test::out::print::Integer::pp_wp_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_lh_short_fmt);

    assert((test::out::print::Integer::pp_wp_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_lh_int_fmt);

    assert((test::out::print::Integer::pp_wp_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_lh_long_fmt);

    assert((test::out::print::Integer::pp_wp_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_lh_long_long_fmt);

    assert((test::out::print::Integer::pp_wp_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_lh_u_char_fmt);

    assert((test::out::print::Integer::pp_wp_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_lh_u_short_fmt);

    assert((test::out::print::Integer::pp_wp_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_lh_u_int_fmt);

    assert((test::out::print::Integer::pp_wp_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_lh_u_long_fmt);

    assert((test::out::print::Integer::pp_wp_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::pp_wp_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_uh_char_fmt);

    assert((test::out::print::Integer::pp_wp_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_uh_short_fmt);

    assert((test::out::print::Integer::pp_wp_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_uh_int_fmt);

    assert((test::out::print::Integer::pp_wp_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_uh_long_fmt);

    assert((test::out::print::Integer::pp_wp_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_uh_long_long_fmt);

    assert((test::out::print::Integer::pp_wp_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_uh_u_char_fmt);

    assert((test::out::print::Integer::pp_wp_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_uh_u_short_fmt);

    assert((test::out::print::Integer::pp_wp_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_uh_u_int_fmt);

    assert((test::out::print::Integer::pp_wp_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_uh_u_long_fmt);

    assert((test::out::print::Integer::pp_wp_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pp_wp_uh_u_long_long_fmt);


    assert((test::out::print::Integer::pppz_wp_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_ds_char_fmt);

    assert((test::out::print::Integer::pppz_wp_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_ds_short_fmt);

    assert((test::out::print::Integer::pppz_wp_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_ds_int_fmt);

    assert((test::out::print::Integer::pppz_wp_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_ds_long_fmt);

    assert((test::out::print::Integer::pppz_wp_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_ds_long_long_fmt);

    assert((test::out::print::Integer::pppz_wp_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_ds_u_char_fmt);

    assert((test::out::print::Integer::pppz_wp_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_ds_u_short_fmt);

    assert((test::out::print::Integer::pppz_wp_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_ds_u_int_fmt);

    assert((test::out::print::Integer::pppz_wp_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_ds_u_long_fmt);

    assert((test::out::print::Integer::pppz_wp_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_ds_u_long_long_fmt);


    assert((test::out::print::Integer::pppz_wp_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_du_char_fmt);

    assert((test::out::print::Integer::pppz_wp_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_du_short_fmt);

    assert((test::out::print::Integer::pppz_wp_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_du_int_fmt);

    assert((test::out::print::Integer::pppz_wp_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_du_long_fmt);

    assert((test::out::print::Integer::pppz_wp_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_du_long_long_fmt);

    assert((test::out::print::Integer::pppz_wp_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_du_u_char_fmt);

    assert((test::out::print::Integer::pppz_wp_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_du_u_short_fmt);

    assert((test::out::print::Integer::pppz_wp_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_du_u_int_fmt);

    assert((test::out::print::Integer::pppz_wp_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_du_u_long_fmt);

    assert((test::out::print::Integer::pppz_wp_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_du_u_long_long_fmt);


    assert((test::out::print::Integer::pppz_wp_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_o_char_fmt);

    assert((test::out::print::Integer::pppz_wp_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_o_short_fmt);

    assert((test::out::print::Integer::pppz_wp_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_o_int_fmt);

    assert((test::out::print::Integer::pppz_wp_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_o_long_fmt);

    assert((test::out::print::Integer::pppz_wp_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_o_long_long_fmt);

    assert((test::out::print::Integer::pppz_wp_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_o_u_char_fmt);

    assert((test::out::print::Integer::pppz_wp_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_o_u_short_fmt);

    assert((test::out::print::Integer::pppz_wp_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_o_u_int_fmt);

    assert((test::out::print::Integer::pppz_wp_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_o_u_long_fmt);

    assert((test::out::print::Integer::pppz_wp_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::pppz_wp_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_lh_char_fmt);

    assert((test::out::print::Integer::pppz_wp_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_lh_short_fmt);

    assert((test::out::print::Integer::pppz_wp_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_lh_int_fmt);

    assert((test::out::print::Integer::pppz_wp_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_lh_long_fmt);

    assert((test::out::print::Integer::pppz_wp_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_lh_long_long_fmt);

    assert((test::out::print::Integer::pppz_wp_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_lh_u_char_fmt);

    assert((test::out::print::Integer::pppz_wp_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_lh_u_short_fmt);

    assert((test::out::print::Integer::pppz_wp_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_lh_u_int_fmt);

    assert((test::out::print::Integer::pppz_wp_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_lh_u_long_fmt);

    assert((test::out::print::Integer::pppz_wp_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::pppz_wp_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_uh_char_fmt);

    assert((test::out::print::Integer::pppz_wp_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_uh_short_fmt);

    assert((test::out::print::Integer::pppz_wp_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_uh_int_fmt);

    assert((test::out::print::Integer::pppz_wp_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_uh_long_fmt);

    assert((test::out::print::Integer::pppz_wp_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_uh_long_long_fmt);

    assert((test::out::print::Integer::pppz_wp_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_uh_u_char_fmt);

    assert((test::out::print::Integer::pppz_wp_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_uh_u_short_fmt);

    assert((test::out::print::Integer::pppz_wp_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_uh_u_int_fmt);

    assert((test::out::print::Integer::pppz_wp_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_uh_u_long_fmt);

    assert((test::out::print::Integer::pppz_wp_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pppz_wp_uh_u_long_long_fmt);


    assert((test::out::print::Integer::ps_wp_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_ds_char_fmt);

    assert((test::out::print::Integer::ps_wp_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_ds_short_fmt);

    assert((test::out::print::Integer::ps_wp_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_ds_int_fmt);

    assert((test::out::print::Integer::ps_wp_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_ds_long_fmt);

    assert((test::out::print::Integer::ps_wp_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_ds_long_long_fmt);

    assert((test::out::print::Integer::ps_wp_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_ds_u_char_fmt);

    assert((test::out::print::Integer::ps_wp_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_ds_u_short_fmt);

    assert((test::out::print::Integer::ps_wp_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_ds_u_int_fmt);

    assert((test::out::print::Integer::ps_wp_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_ds_u_long_fmt);

    assert((test::out::print::Integer::ps_wp_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_ds_u_long_long_fmt);


    assert((test::out::print::Integer::ps_wp_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_du_char_fmt);

    assert((test::out::print::Integer::ps_wp_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_du_short_fmt);

    assert((test::out::print::Integer::ps_wp_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_du_int_fmt);

    assert((test::out::print::Integer::ps_wp_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_du_long_fmt);

    assert((test::out::print::Integer::ps_wp_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_du_long_long_fmt);

    assert((test::out::print::Integer::ps_wp_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_du_u_char_fmt);

    assert((test::out::print::Integer::ps_wp_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_du_u_short_fmt);

    assert((test::out::print::Integer::ps_wp_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_du_u_int_fmt);

    assert((test::out::print::Integer::ps_wp_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_du_u_long_fmt);

    assert((test::out::print::Integer::ps_wp_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_du_u_long_long_fmt);


    assert((test::out::print::Integer::ps_wp_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_o_char_fmt);

    assert((test::out::print::Integer::ps_wp_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_o_short_fmt);

    assert((test::out::print::Integer::ps_wp_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_o_int_fmt);

    assert((test::out::print::Integer::ps_wp_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_o_long_fmt);

    assert((test::out::print::Integer::ps_wp_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_o_long_long_fmt);

    assert((test::out::print::Integer::ps_wp_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_o_u_char_fmt);

    assert((test::out::print::Integer::ps_wp_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_o_u_short_fmt);

    assert((test::out::print::Integer::ps_wp_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_o_u_int_fmt);

    assert((test::out::print::Integer::ps_wp_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_o_u_long_fmt);

    assert((test::out::print::Integer::ps_wp_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::ps_wp_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_lh_char_fmt);

    assert((test::out::print::Integer::ps_wp_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_lh_short_fmt);

    assert((test::out::print::Integer::ps_wp_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_lh_int_fmt);

    assert((test::out::print::Integer::ps_wp_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_lh_long_fmt);

    assert((test::out::print::Integer::ps_wp_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_lh_long_long_fmt);

    assert((test::out::print::Integer::ps_wp_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_lh_u_char_fmt);

    assert((test::out::print::Integer::ps_wp_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_lh_u_short_fmt);

    assert((test::out::print::Integer::ps_wp_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_lh_u_int_fmt);

    assert((test::out::print::Integer::ps_wp_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_lh_u_long_fmt);

    assert((test::out::print::Integer::ps_wp_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::ps_wp_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_uh_char_fmt);

    assert((test::out::print::Integer::ps_wp_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_uh_short_fmt);

    assert((test::out::print::Integer::ps_wp_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_uh_int_fmt);

    assert((test::out::print::Integer::ps_wp_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_uh_long_fmt);

    assert((test::out::print::Integer::ps_wp_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_uh_long_long_fmt);

    assert((test::out::print::Integer::ps_wp_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_uh_u_char_fmt);

    assert((test::out::print::Integer::ps_wp_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_uh_u_short_fmt);

    assert((test::out::print::Integer::ps_wp_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_uh_u_int_fmt);

    assert((test::out::print::Integer::ps_wp_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_uh_u_long_fmt);

    assert((test::out::print::Integer::ps_wp_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::ps_wp_uh_u_long_long_fmt);


    assert((test::out::print::Integer::pspz_wp_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_ds_char_fmt);

    assert((test::out::print::Integer::pspz_wp_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_ds_short_fmt);

    assert((test::out::print::Integer::pspz_wp_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_ds_int_fmt);

    assert((test::out::print::Integer::pspz_wp_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_ds_long_fmt);

    assert((test::out::print::Integer::pspz_wp_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_ds_long_long_fmt);

    assert((test::out::print::Integer::pspz_wp_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_ds_u_char_fmt);

    assert((test::out::print::Integer::pspz_wp_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_ds_u_short_fmt);

    assert((test::out::print::Integer::pspz_wp_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_ds_u_int_fmt);

    assert((test::out::print::Integer::pspz_wp_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_ds_u_long_fmt);

    assert((test::out::print::Integer::pspz_wp_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_ds_u_long_long_fmt);


    assert((test::out::print::Integer::pspz_wp_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_du_char_fmt);

    assert((test::out::print::Integer::pspz_wp_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_du_short_fmt);

    assert((test::out::print::Integer::pspz_wp_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_du_int_fmt);

    assert((test::out::print::Integer::pspz_wp_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_du_long_fmt);

    assert((test::out::print::Integer::pspz_wp_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_du_long_long_fmt);

    assert((test::out::print::Integer::pspz_wp_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_du_u_char_fmt);

    assert((test::out::print::Integer::pspz_wp_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_du_u_short_fmt);

    assert((test::out::print::Integer::pspz_wp_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_du_u_int_fmt);

    assert((test::out::print::Integer::pspz_wp_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_du_u_long_fmt);

    assert((test::out::print::Integer::pspz_wp_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_du_u_long_long_fmt);


    assert((test::out::print::Integer::pspz_wp_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_o_char_fmt);

    assert((test::out::print::Integer::pspz_wp_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_o_short_fmt);

    assert((test::out::print::Integer::pspz_wp_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_o_int_fmt);

    assert((test::out::print::Integer::pspz_wp_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_o_long_fmt);

    assert((test::out::print::Integer::pspz_wp_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_o_long_long_fmt);

    assert((test::out::print::Integer::pspz_wp_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_o_u_char_fmt);

    assert((test::out::print::Integer::pspz_wp_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_o_u_short_fmt);

    assert((test::out::print::Integer::pspz_wp_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_o_u_int_fmt);

    assert((test::out::print::Integer::pspz_wp_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_o_u_long_fmt);

    assert((test::out::print::Integer::pspz_wp_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::pspz_wp_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_lh_char_fmt);

    assert((test::out::print::Integer::pspz_wp_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_lh_short_fmt);

    assert((test::out::print::Integer::pspz_wp_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_lh_int_fmt);

    assert((test::out::print::Integer::pspz_wp_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_lh_long_fmt);

    assert((test::out::print::Integer::pspz_wp_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_lh_long_long_fmt);

    assert((test::out::print::Integer::pspz_wp_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_lh_u_char_fmt);

    assert((test::out::print::Integer::pspz_wp_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_lh_u_short_fmt);

    assert((test::out::print::Integer::pspz_wp_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_lh_u_int_fmt);

    assert((test::out::print::Integer::pspz_wp_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_lh_u_long_fmt);

    assert((test::out::print::Integer::pspz_wp_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::pspz_wp_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_uh_char_fmt);

    assert((test::out::print::Integer::pspz_wp_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_uh_short_fmt);

    assert((test::out::print::Integer::pspz_wp_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_uh_int_fmt);

    assert((test::out::print::Integer::pspz_wp_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_uh_long_fmt);

    assert((test::out::print::Integer::pspz_wp_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_uh_long_long_fmt);

    assert((test::out::print::Integer::pspz_wp_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_uh_u_char_fmt);

    assert((test::out::print::Integer::pspz_wp_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_uh_u_short_fmt);

    assert((test::out::print::Integer::pspz_wp_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_uh_u_int_fmt);

    assert((test::out::print::Integer::pspz_wp_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_uh_u_long_fmt);

    assert((test::out::print::Integer::pspz_wp_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pspz_wp_uh_u_long_long_fmt);


    assert((test::out::print::Integer::pz_wp_ds_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_ds_char_fmt);

    assert((test::out::print::Integer::pz_wp_ds_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_ds_short_fmt);

    assert((test::out::print::Integer::pz_wp_ds_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_ds_int_fmt);

    assert((test::out::print::Integer::pz_wp_ds_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_ds_long_fmt);

    assert((test::out::print::Integer::pz_wp_ds_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_ds_long_long_fmt);

    assert((test::out::print::Integer::pz_wp_ds_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_ds_u_char_fmt);

    assert((test::out::print::Integer::pz_wp_ds_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_ds_u_short_fmt);

    assert((test::out::print::Integer::pz_wp_ds_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_ds_u_int_fmt);

    assert((test::out::print::Integer::pz_wp_ds_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_ds_u_long_fmt);

    assert((test::out::print::Integer::pz_wp_ds_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_ds_u_long_long_fmt);


    assert((test::out::print::Integer::pz_wp_du_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_du_char_fmt);

    assert((test::out::print::Integer::pz_wp_du_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_du_short_fmt);

    assert((test::out::print::Integer::pz_wp_du_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_du_int_fmt);

    assert((test::out::print::Integer::pz_wp_du_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_du_long_fmt);

    assert((test::out::print::Integer::pz_wp_du_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_du_long_long_fmt);

    assert((test::out::print::Integer::pz_wp_du_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_du_u_char_fmt);

    assert((test::out::print::Integer::pz_wp_du_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_du_u_short_fmt);

    assert((test::out::print::Integer::pz_wp_du_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_du_u_int_fmt);

    assert((test::out::print::Integer::pz_wp_du_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_du_u_long_fmt);

    assert((test::out::print::Integer::pz_wp_du_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_du_u_long_long_fmt);


    assert((test::out::print::Integer::pz_wp_o_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_o_char_fmt);

    assert((test::out::print::Integer::pz_wp_o_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_o_short_fmt);

    assert((test::out::print::Integer::pz_wp_o_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_o_int_fmt);

    assert((test::out::print::Integer::pz_wp_o_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_o_long_fmt);

    assert((test::out::print::Integer::pz_wp_o_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_o_long_long_fmt);

    assert((test::out::print::Integer::pz_wp_o_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_o_u_char_fmt);

    assert((test::out::print::Integer::pz_wp_o_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_o_u_short_fmt);

    assert((test::out::print::Integer::pz_wp_o_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_o_u_int_fmt);

    assert((test::out::print::Integer::pz_wp_o_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_o_u_long_fmt);

    assert((test::out::print::Integer::pz_wp_o_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_o_u_long_long_fmt);

    
    assert((test::out::print::Integer::pz_wp_lh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_lh_char_fmt);

    assert((test::out::print::Integer::pz_wp_lh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_lh_short_fmt);

    assert((test::out::print::Integer::pz_wp_lh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_lh_int_fmt);

    assert((test::out::print::Integer::pz_wp_lh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_lh_long_fmt);

    assert((test::out::print::Integer::pz_wp_lh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_lh_long_long_fmt);

    assert((test::out::print::Integer::pz_wp_lh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_lh_u_char_fmt);

    assert((test::out::print::Integer::pz_wp_lh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_lh_u_short_fmt);

    assert((test::out::print::Integer::pz_wp_lh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_lh_u_int_fmt);

    assert((test::out::print::Integer::pz_wp_lh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_lh_u_long_fmt);

    assert((test::out::print::Integer::pz_wp_lh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_lh_u_long_long_fmt);

    
    assert((test::out::print::Integer::pz_wp_uh_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_uh_char_fmt);

    assert((test::out::print::Integer::pz_wp_uh_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_uh_short_fmt);

    assert((test::out::print::Integer::pz_wp_uh_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_uh_int_fmt);

    assert((test::out::print::Integer::pz_wp_uh_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_uh_long_fmt);

    assert((test::out::print::Integer::pz_wp_uh_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_uh_long_long_fmt);

    assert((test::out::print::Integer::pz_wp_uh_u_char_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_uh_u_char_fmt);

    assert((test::out::print::Integer::pz_wp_uh_u_short_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_uh_u_short_fmt);

    assert((test::out::print::Integer::pz_wp_uh_u_int_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_uh_u_int_fmt);

    assert((test::out::print::Integer::pz_wp_uh_u_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_uh_u_long_fmt);

    assert((test::out::print::Integer::pz_wp_uh_u_long_long_fmt &
        test::out::print::Integer::MaskValue) ==
        test::out::print::Integer::pz_wp_uh_u_long_long_fmt);



    return 0;
}
