#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/print/FloatingPoint.h"

#include <cassert>

int main()
{

        assert((test::out::print::FloatingPoint::ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ldf_float_fmt);

        assert((test::out::print::FloatingPoint::ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ldf_double_fmt);

        assert((test::out::print::FloatingPoint::ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::udf_float_fmt);

        assert((test::out::print::FloatingPoint::udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::udf_double_fmt);

        assert((test::out::print::FloatingPoint::udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::lde_float_fmt);

        assert((test::out::print::FloatingPoint::lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::lde_double_fmt);

        assert((test::out::print::FloatingPoint::lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ude_float_fmt);

        assert((test::out::print::FloatingPoint::ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ude_double_fmt);

        assert((test::out::print::FloatingPoint::ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::udfe_float_fmt);

        assert((test::out::print::FloatingPoint::udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::udfe_double_fmt);

        assert((test::out::print::FloatingPoint::udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::lhe_float_fmt);

        assert((test::out::print::FloatingPoint::lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::lhe_double_fmt);

        assert((test::out::print::FloatingPoint::lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::uhe_float_fmt);

        assert((test::out::print::FloatingPoint::uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::uhe_double_fmt);

        assert((test::out::print::FloatingPoint::uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::p__ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__ldf_float_fmt);

        assert((test::out::print::FloatingPoint::p__ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__ldf_double_fmt);

        assert((test::out::print::FloatingPoint::p__ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::p__udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__udf_float_fmt);

        assert((test::out::print::FloatingPoint::p__udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__udf_double_fmt);

        assert((test::out::print::FloatingPoint::p__udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::p__lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__lde_float_fmt);

        assert((test::out::print::FloatingPoint::p__lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__lde_double_fmt);

        assert((test::out::print::FloatingPoint::p__lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::p__ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__ude_float_fmt);

        assert((test::out::print::FloatingPoint::p__ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__ude_double_fmt);

        assert((test::out::print::FloatingPoint::p__ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::p__ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::p__ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::p__ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::p__udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__udfe_float_fmt);

        assert((test::out::print::FloatingPoint::p__udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__udfe_double_fmt);

        assert((test::out::print::FloatingPoint::p__udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::p__lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__lhe_float_fmt);

        assert((test::out::print::FloatingPoint::p__lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__lhe_double_fmt);

        assert((test::out::print::FloatingPoint::p__lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::p__uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__uhe_float_fmt);

        assert((test::out::print::FloatingPoint::p__uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__uhe_double_fmt);

        assert((test::out::print::FloatingPoint::p__uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p__uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp__ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__ldf_float_fmt);

        assert((test::out::print::FloatingPoint::ppp__ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__ldf_double_fmt);

        assert((test::out::print::FloatingPoint::ppp__ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp__udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__udf_float_fmt);

        assert((test::out::print::FloatingPoint::ppp__udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__udf_double_fmt);

        assert((test::out::print::FloatingPoint::ppp__udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp__lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__lde_float_fmt);

        assert((test::out::print::FloatingPoint::ppp__lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__lde_double_fmt);

        assert((test::out::print::FloatingPoint::ppp__lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp__ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__ude_float_fmt);

        assert((test::out::print::FloatingPoint::ppp__ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__ude_double_fmt);

        assert((test::out::print::FloatingPoint::ppp__ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp__ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppp__ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppp__ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp__udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__udfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppp__udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__udfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppp__udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp__lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__lhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppp__lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__lhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppp__lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp__uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__uhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppp__uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__uhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppp__uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp__uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz__ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__ldf_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz__ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__ldf_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz__ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz__udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__udf_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz__udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__udf_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz__udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz__lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__lde_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz__lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__lde_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz__lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz__ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__ude_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz__ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__ude_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz__ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz__ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz__ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz__ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz__udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__udfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz__udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__udfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz__udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz__lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__lhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz__lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__lhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz__lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz__uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__uhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz__uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__uhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz__uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz__uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps__ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__ldf_float_fmt);

        assert((test::out::print::FloatingPoint::pps__ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__ldf_double_fmt);

        assert((test::out::print::FloatingPoint::pps__ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps__udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__udf_float_fmt);

        assert((test::out::print::FloatingPoint::pps__udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__udf_double_fmt);

        assert((test::out::print::FloatingPoint::pps__udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps__lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__lde_float_fmt);

        assert((test::out::print::FloatingPoint::pps__lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__lde_double_fmt);

        assert((test::out::print::FloatingPoint::pps__lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps__ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__ude_float_fmt);

        assert((test::out::print::FloatingPoint::pps__ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__ude_double_fmt);

        assert((test::out::print::FloatingPoint::pps__ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps__ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::pps__ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::pps__ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps__udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__udfe_float_fmt);

        assert((test::out::print::FloatingPoint::pps__udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__udfe_double_fmt);

        assert((test::out::print::FloatingPoint::pps__udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps__lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__lhe_float_fmt);

        assert((test::out::print::FloatingPoint::pps__lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__lhe_double_fmt);

        assert((test::out::print::FloatingPoint::pps__lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps__uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__uhe_float_fmt);

        assert((test::out::print::FloatingPoint::pps__uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__uhe_double_fmt);

        assert((test::out::print::FloatingPoint::pps__uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps__uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz__ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__ldf_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz__ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__ldf_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz__ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz__udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__udf_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz__udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__udf_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz__udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz__lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__lde_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz__lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__lde_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz__lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz__ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__ude_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz__ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__ude_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz__ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz__ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz__ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz__ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz__udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__udfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz__udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__udfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz__udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz__lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__lhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz__lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__lhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz__lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz__uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__uhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz__uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__uhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz__uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz__uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz__ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__ldf_float_fmt);

        assert((test::out::print::FloatingPoint::ppz__ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__ldf_double_fmt);

        assert((test::out::print::FloatingPoint::ppz__ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz__udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__udf_float_fmt);

        assert((test::out::print::FloatingPoint::ppz__udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__udf_double_fmt);

        assert((test::out::print::FloatingPoint::ppz__udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz__lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__lde_float_fmt);

        assert((test::out::print::FloatingPoint::ppz__lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__lde_double_fmt);

        assert((test::out::print::FloatingPoint::ppz__lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz__ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__ude_float_fmt);

        assert((test::out::print::FloatingPoint::ppz__ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__ude_double_fmt);

        assert((test::out::print::FloatingPoint::ppz__ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz__ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppz__ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppz__ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz__udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__udfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppz__udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__udfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppz__udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz__lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__lhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppz__lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__lhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppz__lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz__uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__uhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppz__uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__uhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppz__uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz__uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp__ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__ldf_float_fmt);

        assert((test::out::print::FloatingPoint::pp__ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__ldf_double_fmt);

        assert((test::out::print::FloatingPoint::pp__ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp__udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__udf_float_fmt);

        assert((test::out::print::FloatingPoint::pp__udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__udf_double_fmt);

        assert((test::out::print::FloatingPoint::pp__udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp__lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__lde_float_fmt);

        assert((test::out::print::FloatingPoint::pp__lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__lde_double_fmt);

        assert((test::out::print::FloatingPoint::pp__lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp__ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__ude_float_fmt);

        assert((test::out::print::FloatingPoint::pp__ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__ude_double_fmt);

        assert((test::out::print::FloatingPoint::pp__ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp__ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::pp__ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::pp__ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp__udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__udfe_float_fmt);

        assert((test::out::print::FloatingPoint::pp__udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__udfe_double_fmt);

        assert((test::out::print::FloatingPoint::pp__udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp__lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__lhe_float_fmt);

        assert((test::out::print::FloatingPoint::pp__lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__lhe_double_fmt);

        assert((test::out::print::FloatingPoint::pp__lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp__uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__uhe_float_fmt);

        assert((test::out::print::FloatingPoint::pp__uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__uhe_double_fmt);

        assert((test::out::print::FloatingPoint::pp__uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp__uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz__ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__ldf_float_fmt);

        assert((test::out::print::FloatingPoint::pppz__ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__ldf_double_fmt);

        assert((test::out::print::FloatingPoint::pppz__ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz__udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__udf_float_fmt);

        assert((test::out::print::FloatingPoint::pppz__udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__udf_double_fmt);

        assert((test::out::print::FloatingPoint::pppz__udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz__lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__lde_float_fmt);

        assert((test::out::print::FloatingPoint::pppz__lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__lde_double_fmt);

        assert((test::out::print::FloatingPoint::pppz__lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz__ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__ude_float_fmt);

        assert((test::out::print::FloatingPoint::pppz__ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__ude_double_fmt);

        assert((test::out::print::FloatingPoint::pppz__ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz__ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::pppz__ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::pppz__ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz__udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__udfe_float_fmt);

        assert((test::out::print::FloatingPoint::pppz__udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__udfe_double_fmt);

        assert((test::out::print::FloatingPoint::pppz__udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz__lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__lhe_float_fmt);

        assert((test::out::print::FloatingPoint::pppz__lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__lhe_double_fmt);

        assert((test::out::print::FloatingPoint::pppz__lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz__uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__uhe_float_fmt);

        assert((test::out::print::FloatingPoint::pppz__uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__uhe_double_fmt);

        assert((test::out::print::FloatingPoint::pppz__uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz__uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps__ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__ldf_float_fmt);

        assert((test::out::print::FloatingPoint::ps__ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__ldf_double_fmt);

        assert((test::out::print::FloatingPoint::ps__ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps__udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__udf_float_fmt);

        assert((test::out::print::FloatingPoint::ps__udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__udf_double_fmt);

        assert((test::out::print::FloatingPoint::ps__udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps__lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__lde_float_fmt);

        assert((test::out::print::FloatingPoint::ps__lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__lde_double_fmt);

        assert((test::out::print::FloatingPoint::ps__lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps__ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__ude_float_fmt);

        assert((test::out::print::FloatingPoint::ps__ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__ude_double_fmt);

        assert((test::out::print::FloatingPoint::ps__ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps__ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::ps__ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::ps__ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps__udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__udfe_float_fmt);

        assert((test::out::print::FloatingPoint::ps__udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__udfe_double_fmt);

        assert((test::out::print::FloatingPoint::ps__udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps__lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__lhe_float_fmt);

        assert((test::out::print::FloatingPoint::ps__lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__lhe_double_fmt);

        assert((test::out::print::FloatingPoint::ps__lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps__uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__uhe_float_fmt);

        assert((test::out::print::FloatingPoint::ps__uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__uhe_double_fmt);

        assert((test::out::print::FloatingPoint::ps__uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps__uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz__ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__ldf_float_fmt);

        assert((test::out::print::FloatingPoint::pspz__ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__ldf_double_fmt);

        assert((test::out::print::FloatingPoint::pspz__ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz__udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__udf_float_fmt);

        assert((test::out::print::FloatingPoint::pspz__udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__udf_double_fmt);

        assert((test::out::print::FloatingPoint::pspz__udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz__lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__lde_float_fmt);

        assert((test::out::print::FloatingPoint::pspz__lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__lde_double_fmt);

        assert((test::out::print::FloatingPoint::pspz__lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz__ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__ude_float_fmt);

        assert((test::out::print::FloatingPoint::pspz__ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__ude_double_fmt);

        assert((test::out::print::FloatingPoint::pspz__ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz__ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::pspz__ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::pspz__ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz__udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__udfe_float_fmt);

        assert((test::out::print::FloatingPoint::pspz__udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__udfe_double_fmt);

        assert((test::out::print::FloatingPoint::pspz__udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz__lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__lhe_float_fmt);

        assert((test::out::print::FloatingPoint::pspz__lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__lhe_double_fmt);

        assert((test::out::print::FloatingPoint::pspz__lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz__uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__uhe_float_fmt);

        assert((test::out::print::FloatingPoint::pspz__uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__uhe_double_fmt);

        assert((test::out::print::FloatingPoint::pspz__uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz__uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz__ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__ldf_float_fmt);

        assert((test::out::print::FloatingPoint::pz__ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__ldf_double_fmt);

        assert((test::out::print::FloatingPoint::pz__ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz__udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__udf_float_fmt);

        assert((test::out::print::FloatingPoint::pz__udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__udf_double_fmt);

        assert((test::out::print::FloatingPoint::pz__udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz__lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__lde_float_fmt);

        assert((test::out::print::FloatingPoint::pz__lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__lde_double_fmt);

        assert((test::out::print::FloatingPoint::pz__lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz__ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__ude_float_fmt);

        assert((test::out::print::FloatingPoint::pz__ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__ude_double_fmt);

        assert((test::out::print::FloatingPoint::pz__ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz__ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::pz__ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::pz__ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz__udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__udfe_float_fmt);

        assert((test::out::print::FloatingPoint::pz__udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__udfe_double_fmt);

        assert((test::out::print::FloatingPoint::pz__udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz__lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__lhe_float_fmt);

        assert((test::out::print::FloatingPoint::pz__lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__lhe_double_fmt);

        assert((test::out::print::FloatingPoint::pz__lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz__uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__uhe_float_fmt);

        assert((test::out::print::FloatingPoint::pz__uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__uhe_double_fmt);

        assert((test::out::print::FloatingPoint::pz__uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz__uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::w_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::w_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::w_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::w_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_udf_float_fmt);

        assert((test::out::print::FloatingPoint::w_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_udf_double_fmt);

        assert((test::out::print::FloatingPoint::w_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::w_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_lde_float_fmt);

        assert((test::out::print::FloatingPoint::w_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_lde_double_fmt);

        assert((test::out::print::FloatingPoint::w_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::w_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_ude_float_fmt);

        assert((test::out::print::FloatingPoint::w_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_ude_double_fmt);

        assert((test::out::print::FloatingPoint::w_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::w_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::w_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::w_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::w_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::w_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::w_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::w_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::w_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::w_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::w_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::w_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::w_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::w_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_w_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::p_w_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::p_w_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_w_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_udf_float_fmt);

        assert((test::out::print::FloatingPoint::p_w_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_udf_double_fmt);

        assert((test::out::print::FloatingPoint::p_w_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_w_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_lde_float_fmt);

        assert((test::out::print::FloatingPoint::p_w_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_lde_double_fmt);

        assert((test::out::print::FloatingPoint::p_w_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_w_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_ude_float_fmt);

        assert((test::out::print::FloatingPoint::p_w_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_ude_double_fmt);

        assert((test::out::print::FloatingPoint::p_w_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_w_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::p_w_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::p_w_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_w_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::p_w_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::p_w_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_w_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::p_w_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::p_w_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_w_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::p_w_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::p_w_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_w_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_udf_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_udf_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_lde_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_lde_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_ude_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_ude_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_w_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_w_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_udf_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_udf_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_lde_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_lde_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_ude_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_ude_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_w_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_w_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_w_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::pps_w_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::pps_w_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_w_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_udf_float_fmt);

        assert((test::out::print::FloatingPoint::pps_w_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_udf_double_fmt);

        assert((test::out::print::FloatingPoint::pps_w_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_w_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_lde_float_fmt);

        assert((test::out::print::FloatingPoint::pps_w_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_lde_double_fmt);

        assert((test::out::print::FloatingPoint::pps_w_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_w_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_ude_float_fmt);

        assert((test::out::print::FloatingPoint::pps_w_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_ude_double_fmt);

        assert((test::out::print::FloatingPoint::pps_w_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_w_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::pps_w_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::pps_w_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_w_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::pps_w_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::pps_w_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_w_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::pps_w_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::pps_w_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_w_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::pps_w_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::pps_w_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_w_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_udf_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_udf_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_lde_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_lde_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_ude_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_ude_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_w_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_w_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_udf_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_udf_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_lde_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_lde_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_ude_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_ude_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_w_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_w_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_w_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::pp_w_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::pp_w_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_w_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_udf_float_fmt);

        assert((test::out::print::FloatingPoint::pp_w_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_udf_double_fmt);

        assert((test::out::print::FloatingPoint::pp_w_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_w_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_lde_float_fmt);

        assert((test::out::print::FloatingPoint::pp_w_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_lde_double_fmt);

        assert((test::out::print::FloatingPoint::pp_w_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_w_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_ude_float_fmt);

        assert((test::out::print::FloatingPoint::pp_w_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_ude_double_fmt);

        assert((test::out::print::FloatingPoint::pp_w_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_w_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::pp_w_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::pp_w_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_w_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::pp_w_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::pp_w_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_w_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::pp_w_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::pp_w_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_w_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::pp_w_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::pp_w_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_w_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_udf_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_udf_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_lde_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_lde_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_ude_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_ude_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_w_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_w_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_w_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::ps_w_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::ps_w_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_w_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_udf_float_fmt);

        assert((test::out::print::FloatingPoint::ps_w_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_udf_double_fmt);

        assert((test::out::print::FloatingPoint::ps_w_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_w_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_lde_float_fmt);

        assert((test::out::print::FloatingPoint::ps_w_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_lde_double_fmt);

        assert((test::out::print::FloatingPoint::ps_w_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_w_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_ude_float_fmt);

        assert((test::out::print::FloatingPoint::ps_w_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_ude_double_fmt);

        assert((test::out::print::FloatingPoint::ps_w_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_w_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::ps_w_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::ps_w_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_w_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::ps_w_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::ps_w_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_w_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::ps_w_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::ps_w_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_w_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::ps_w_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::ps_w_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_w_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_udf_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_udf_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_lde_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_lde_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_ude_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_ude_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_w_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_w_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_w_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::pz_w_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::pz_w_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_w_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_udf_float_fmt);

        assert((test::out::print::FloatingPoint::pz_w_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_udf_double_fmt);

        assert((test::out::print::FloatingPoint::pz_w_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_w_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_lde_float_fmt);

        assert((test::out::print::FloatingPoint::pz_w_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_lde_double_fmt);

        assert((test::out::print::FloatingPoint::pz_w_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_w_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_ude_float_fmt);

        assert((test::out::print::FloatingPoint::pz_w_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_ude_double_fmt);

        assert((test::out::print::FloatingPoint::pz_w_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_w_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::pz_w_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::pz_w_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_w_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::pz_w_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::pz_w_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_w_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::pz_w_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::pz_w_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_w_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::pz_w_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::pz_w_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_w_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::p_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::p_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_udf_float_fmt);

        assert((test::out::print::FloatingPoint::p_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_udf_double_fmt);

        assert((test::out::print::FloatingPoint::p_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_lde_float_fmt);

        assert((test::out::print::FloatingPoint::p_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_lde_double_fmt);

        assert((test::out::print::FloatingPoint::p_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_ude_float_fmt);

        assert((test::out::print::FloatingPoint::p_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_ude_double_fmt);

        assert((test::out::print::FloatingPoint::p_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::p_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::p_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::p_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::p_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::p_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::p_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::p_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::p_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_p_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::p_p_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::p_p_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_p_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_udf_float_fmt);

        assert((test::out::print::FloatingPoint::p_p_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_udf_double_fmt);

        assert((test::out::print::FloatingPoint::p_p_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_p_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_lde_float_fmt);

        assert((test::out::print::FloatingPoint::p_p_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_lde_double_fmt);

        assert((test::out::print::FloatingPoint::p_p_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_p_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_ude_float_fmt);

        assert((test::out::print::FloatingPoint::p_p_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_ude_double_fmt);

        assert((test::out::print::FloatingPoint::p_p_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_p_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::p_p_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::p_p_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_p_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::p_p_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::p_p_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_p_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::p_p_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::p_p_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_p_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::p_p_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::p_p_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_p_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_udf_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_udf_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_lde_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_lde_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_ude_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_ude_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_p_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_p_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_udf_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_udf_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_lde_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_lde_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_ude_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_ude_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_p_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_p_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_p_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::pps_p_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::pps_p_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_p_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_udf_float_fmt);

        assert((test::out::print::FloatingPoint::pps_p_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_udf_double_fmt);

        assert((test::out::print::FloatingPoint::pps_p_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_p_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_lde_float_fmt);

        assert((test::out::print::FloatingPoint::pps_p_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_lde_double_fmt);

        assert((test::out::print::FloatingPoint::pps_p_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_p_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_ude_float_fmt);

        assert((test::out::print::FloatingPoint::pps_p_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_ude_double_fmt);

        assert((test::out::print::FloatingPoint::pps_p_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_p_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::pps_p_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::pps_p_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_p_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::pps_p_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::pps_p_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_p_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::pps_p_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::pps_p_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_p_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::pps_p_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::pps_p_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_p_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_udf_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_udf_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_lde_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_lde_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_ude_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_ude_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_p_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_p_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_udf_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_udf_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_lde_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_lde_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_ude_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_ude_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_p_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_p_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_p_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::pp_p_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::pp_p_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_p_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_udf_float_fmt);

        assert((test::out::print::FloatingPoint::pp_p_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_udf_double_fmt);

        assert((test::out::print::FloatingPoint::pp_p_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_p_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_lde_float_fmt);

        assert((test::out::print::FloatingPoint::pp_p_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_lde_double_fmt);

        assert((test::out::print::FloatingPoint::pp_p_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_p_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_ude_float_fmt);

        assert((test::out::print::FloatingPoint::pp_p_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_ude_double_fmt);

        assert((test::out::print::FloatingPoint::pp_p_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_p_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::pp_p_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::pp_p_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_p_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::pp_p_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::pp_p_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_p_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::pp_p_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::pp_p_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_p_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::pp_p_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::pp_p_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_p_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_udf_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_udf_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_lde_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_lde_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_ude_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_ude_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_p_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_p_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_p_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::ps_p_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::ps_p_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_p_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_udf_float_fmt);

        assert((test::out::print::FloatingPoint::ps_p_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_udf_double_fmt);

        assert((test::out::print::FloatingPoint::ps_p_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_p_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_lde_float_fmt);

        assert((test::out::print::FloatingPoint::ps_p_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_lde_double_fmt);

        assert((test::out::print::FloatingPoint::ps_p_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_p_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_ude_float_fmt);

        assert((test::out::print::FloatingPoint::ps_p_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_ude_double_fmt);

        assert((test::out::print::FloatingPoint::ps_p_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_p_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::ps_p_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::ps_p_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_p_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::ps_p_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::ps_p_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_p_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::ps_p_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::ps_p_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_p_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::ps_p_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::ps_p_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_p_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_udf_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_udf_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_lde_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_lde_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_ude_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_ude_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_p_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_p_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_p_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::pz_p_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::pz_p_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_p_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_udf_float_fmt);

        assert((test::out::print::FloatingPoint::pz_p_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_udf_double_fmt);

        assert((test::out::print::FloatingPoint::pz_p_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_p_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_lde_float_fmt);

        assert((test::out::print::FloatingPoint::pz_p_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_lde_double_fmt);

        assert((test::out::print::FloatingPoint::pz_p_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_p_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_ude_float_fmt);

        assert((test::out::print::FloatingPoint::pz_p_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_ude_double_fmt);

        assert((test::out::print::FloatingPoint::pz_p_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_p_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::pz_p_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::pz_p_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_p_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::pz_p_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::pz_p_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_p_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::pz_p_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::pz_p_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_p_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::pz_p_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::pz_p_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_p_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::wp_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::wp_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::wp_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::wp_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_udf_float_fmt);

        assert((test::out::print::FloatingPoint::wp_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_udf_double_fmt);

        assert((test::out::print::FloatingPoint::wp_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::wp_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_lde_float_fmt);

        assert((test::out::print::FloatingPoint::wp_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_lde_double_fmt);

        assert((test::out::print::FloatingPoint::wp_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::wp_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_ude_float_fmt);

        assert((test::out::print::FloatingPoint::wp_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_ude_double_fmt);

        assert((test::out::print::FloatingPoint::wp_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::wp_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::wp_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::wp_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::wp_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::wp_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::wp_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::wp_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::wp_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::wp_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::wp_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::wp_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::wp_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::wp_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_wp_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::p_wp_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::p_wp_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_wp_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_udf_float_fmt);

        assert((test::out::print::FloatingPoint::p_wp_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_udf_double_fmt);

        assert((test::out::print::FloatingPoint::p_wp_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_wp_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_lde_float_fmt);

        assert((test::out::print::FloatingPoint::p_wp_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_lde_double_fmt);

        assert((test::out::print::FloatingPoint::p_wp_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_wp_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_ude_float_fmt);

        assert((test::out::print::FloatingPoint::p_wp_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_ude_double_fmt);

        assert((test::out::print::FloatingPoint::p_wp_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_wp_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::p_wp_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::p_wp_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_wp_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::p_wp_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::p_wp_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_wp_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::p_wp_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::p_wp_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::p_wp_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::p_wp_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::p_wp_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::p_wp_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_udf_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_udf_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_lde_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_lde_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_ude_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_ude_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppp_wp_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppp_wp_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_udf_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_udf_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_lde_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_lde_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_ude_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_ude_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppppz_wp_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppppz_wp_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_udf_float_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_udf_double_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_lde_float_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_lde_double_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_ude_float_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_ude_double_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::pps_wp_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pps_wp_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_udf_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_udf_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_lde_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_lde_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_ude_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_ude_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppspz_wp_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppspz_wp_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_udf_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_udf_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_lde_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_lde_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_ude_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_ude_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::ppz_wp_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ppz_wp_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_udf_float_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_udf_double_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_lde_float_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_lde_double_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_ude_float_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_ude_double_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::pp_wp_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pp_wp_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_udf_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_udf_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_lde_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_lde_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_ude_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_ude_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::pppz_wp_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pppz_wp_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_udf_float_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_udf_double_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_lde_float_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_lde_double_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_ude_float_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_ude_double_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::ps_wp_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::ps_wp_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_udf_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_udf_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_lde_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_lde_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_ude_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_ude_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::pspz_wp_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pspz_wp_uhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_ldf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_ldf_float_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_ldf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_ldf_double_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_ldf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_ldf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_udf_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_udf_float_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_udf_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_udf_double_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_udf_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_udf_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_lde_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_lde_float_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_lde_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_lde_double_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_lde_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_lde_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_ude_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_ude_float_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_ude_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_ude_double_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_ude_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_ude_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_ldfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_ldfe_float_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_ldfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_ldfe_double_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_ldfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_ldfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_udfe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_udfe_float_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_udfe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_udfe_double_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_udfe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_udfe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_lhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_lhe_float_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_lhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_lhe_double_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_lhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_lhe_long_double_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_uhe_float_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_uhe_float_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_uhe_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_uhe_double_fmt);

        assert((test::out::print::FloatingPoint::pz_wp_uhe_long_double_fmt &
            test::out::print::FloatingPoint::MaskValue) ==
            test::out::print::FloatingPoint::pz_wp_uhe_long_double_fmt);

    
    return 0;
}
