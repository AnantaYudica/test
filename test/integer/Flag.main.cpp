#include "test/integer/Flag.h"

#include <cstdint>
#include <cassert>
#include <type_traits>
#include <utility>

int main()
{
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0;
        typedef typename FlagType::ValueType FlagValueType;

        assert((FlagValueType)fl_0 == 0);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);

        fl_0.SetNegative();
        assert(fl_0.IsNegative() == false);

        fl_0.UnsetNegative();
        assert(fl_0.IsNegative() == false);


        assert(fl_0.IsUndefinedFormat() == true);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == 0);

        FlagType fl_1 = -fl_0;

        assert((FlagValueType)fl_1 == 0);
        assert(fl_1.IsSigned() == false);
        assert(fl_1.IsNegative() == false);
        assert(fl_1.IsUndefinedFormat() == true);
        assert(fl_1.IsBinaryFormat() == false);
        assert(fl_1.IsOctalFormat() == false);
        assert(fl_1.IsDecimalFormat() == false);
        assert(fl_1.Format() == 0);
        
        FlagType fl_2(std::move(fl_1));

        assert((FlagValueType)fl_2 == 0);
        assert(fl_2.IsSigned() == false);
        assert(fl_2.IsNegative() == false);
        assert(fl_2.IsUndefinedFormat() == true);
        assert(fl_2.IsBinaryFormat() == false);
        assert(fl_2.IsOctalFormat() == false);
        assert(fl_2.IsDecimalFormat() == false);
        assert(fl_2.Format() == 0);
        
        assert((FlagValueType)fl_1 == 0);
        assert(fl_1.IsSigned() == false);
        assert(fl_1.IsNegative() == false);
        assert(fl_1.IsUndefinedFormat() == true);
        assert(fl_1.IsBinaryFormat() == false);
        assert(fl_1.IsOctalFormat() == false);
        assert(fl_1.IsDecimalFormat() == false);
        assert(fl_1.Format() == 0);

        fl_2 = -fl_0;
        assert((FlagValueType)fl_2 == 0);
        assert(fl_2.IsSigned() == false);
        assert(fl_2.IsNegative() == false);
        assert(fl_2.IsUndefinedFormat() == true);
        assert(fl_2.IsBinaryFormat() == false);
        assert(fl_2.IsOctalFormat() == false);
        assert(fl_2.IsDecimalFormat() == false);
        assert(fl_2.Format() == 0);

        FlagType fl_3(fl_2);

        fl_3 = std::move(fl_2);
        assert((FlagValueType)fl_3 == 0);
        assert(fl_3.IsSigned() == false);
        assert(fl_3.IsNegative() == false);
        assert(fl_3.IsUndefinedFormat() == true);
        assert(fl_3.IsBinaryFormat() == false);
        assert(fl_3.IsOctalFormat() == false);
        assert(fl_3.IsDecimalFormat() == false);
        assert(fl_3.Format() == 0);
        
        assert((FlagValueType)fl_2 == 0);
        assert(fl_2.IsSigned() == false);
        assert(fl_2.IsNegative() == false);
        assert(fl_2.IsUndefinedFormat() == true);
        assert(fl_2.IsBinaryFormat() == false);
        assert(fl_2.IsOctalFormat() == false);
        assert(fl_2.IsDecimalFormat() == false);
        assert(fl_2.Format() == 0);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kBinaryFormat);
        typedef typename FlagType::ValueType FlagValueType;

        assert((FlagValueType)fl_0 == FlagType::kBinaryFormat);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);

        fl_0.SetNegative();
        assert(fl_0.IsNegative() == false);

        fl_0.UnsetNegative();
        assert(fl_0.IsNegative() == false);


        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == true);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kBinaryFormat);

        FlagType fl_1 = -fl_0;
        
        assert((FlagValueType)fl_1 == FlagType::kBinaryFormat);
        assert(fl_1.IsSigned() == false);
        assert(fl_1.IsNegative() == false);
        assert(fl_1.IsUndefinedFormat() == false);
        assert(fl_1.IsBinaryFormat() == true);
        assert(fl_1.IsOctalFormat() == false);
        assert(fl_1.IsDecimalFormat() == false);
        assert(fl_1.Format() == FlagType::kBinaryFormat);
        
        FlagType fl_2(std::move(fl_1));

        assert((FlagValueType)fl_2 == FlagType::kBinaryFormat);
        assert(fl_2.IsSigned() == false);
        assert(fl_2.IsNegative() == false);
        assert(fl_2.IsUndefinedFormat() == false);
        assert(fl_2.IsBinaryFormat() == true);
        assert(fl_2.IsOctalFormat() == false);
        assert(fl_2.IsDecimalFormat() == false);
        assert(fl_2.Format() == FlagType::kBinaryFormat);
        
        assert((FlagValueType)fl_1 == 0);
        assert(fl_1.IsSigned() == false);
        assert(fl_1.IsNegative() == false);
        assert(fl_1.IsUndefinedFormat() == true);
        assert(fl_1.IsBinaryFormat() == false);
        assert(fl_1.IsOctalFormat() == false);
        assert(fl_1.IsDecimalFormat() == false);
        assert(fl_1.Format() == 0);

        fl_2 = -fl_0;
        assert((FlagValueType)fl_2 == FlagType::kBinaryFormat);
        assert(fl_2.IsSigned() == false);
        assert(fl_2.IsNegative() == false);
        assert(fl_2.IsUndefinedFormat() == false);
        assert(fl_2.IsBinaryFormat() == true);
        assert(fl_2.IsOctalFormat() == false);
        assert(fl_2.IsDecimalFormat() == false);
        assert(fl_2.Format() == FlagType::kBinaryFormat);

        FlagType fl_3(fl_2);

        fl_3 = std::move(fl_2);
        assert((FlagValueType)fl_3 == FlagType::kBinaryFormat);
        assert(fl_3.IsSigned() == false);
        assert(fl_3.IsNegative() == false);
        assert(fl_3.IsUndefinedFormat() == false);
        assert(fl_3.IsBinaryFormat() == true);
        assert(fl_3.IsOctalFormat() == false);
        assert(fl_3.IsDecimalFormat() == false);
        assert(fl_3.Format() == FlagType::kBinaryFormat);
        
        assert((FlagValueType)fl_2 == FlagType::kBinaryFormat);
        assert(fl_2.IsSigned() == false);
        assert(fl_2.IsNegative() == false);
        assert(fl_2.IsUndefinedFormat() == false);
        assert(fl_2.IsBinaryFormat() == true);
        assert(fl_2.IsOctalFormat() == false);
        assert(fl_2.IsDecimalFormat() == false);
        assert(fl_2.Format() == FlagType::kBinaryFormat);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kBinaryFormat | FlagType::kSigned);
        typedef typename FlagType::ValueType FlagValueType;

        assert((FlagValueType)fl_0 == (FlagType::kBinaryFormat | 
            FlagType::kSigned));

        assert(fl_0.IsSigned() == true);
        assert(fl_0.IsNegative() == false);

        fl_0.SetNegative();
        assert(fl_0.IsNegative() == true);

        fl_0.UnsetNegative();
        assert(fl_0.IsNegative() == false);


        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == true);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kBinaryFormat);

        FlagType fl_1 = -fl_0;
        assert((FlagValueType)fl_1 == (FlagType::kBinaryFormat | 
            FlagType::kSigned | FlagType::kNegative));
        assert(fl_1.IsSigned() == true);
        assert(fl_1.IsNegative() == true);
        assert(fl_1.IsUndefinedFormat() == false);
        assert(fl_1.IsBinaryFormat() == true);
        assert(fl_1.IsOctalFormat() == false);
        assert(fl_1.IsDecimalFormat() == false);
        assert(fl_1.Format() == FlagType::kBinaryFormat);
        
        FlagType fl_2(std::move(fl_1));

        assert((FlagValueType)fl_2 == FlagType::kBinaryFormat | 
            FlagType::kSigned);
        assert(fl_2.IsSigned() == true);
        assert(fl_2.IsNegative() == true);
        assert(fl_2.IsUndefinedFormat() == false);
        assert(fl_2.IsBinaryFormat() == true);
        assert(fl_2.IsOctalFormat() == false);
        assert(fl_2.IsDecimalFormat() == false);
        assert(fl_2.Format() == FlagType::kBinaryFormat);
        
        assert((FlagValueType)fl_1 == 0);
        assert(fl_1.IsSigned() == false);
        assert(fl_1.IsNegative() == false);
        assert(fl_1.IsUndefinedFormat() == true);
        assert(fl_1.IsBinaryFormat() == false);
        assert(fl_1.IsOctalFormat() == false);
        assert(fl_1.IsDecimalFormat() == false);
        assert(fl_1.Format() == 0);

        fl_2 = -fl_0;
        assert((FlagValueType)fl_2 == (FlagType::kBinaryFormat | 
            FlagType::kSigned | FlagType::kNegative));
        assert(fl_2.IsSigned() == true);
        assert(fl_2.IsNegative() == true);
        assert(fl_2.IsUndefinedFormat() == false);
        assert(fl_2.IsBinaryFormat() == true);
        assert(fl_2.IsOctalFormat() == false);
        assert(fl_2.IsDecimalFormat() == false);
        assert(fl_2.Format() == FlagType::kBinaryFormat);

        FlagType fl_3(fl_2);

        fl_3 = std::move(fl_2);
        assert((FlagValueType)fl_3 == (FlagType::kBinaryFormat | 
            FlagType::kSigned | FlagType::kNegative));
        assert(fl_3.IsSigned() == true);
        assert(fl_3.IsNegative() == true);
        assert(fl_3.IsUndefinedFormat() == false);
        assert(fl_3.IsBinaryFormat() == true);
        assert(fl_3.IsOctalFormat() == false);
        assert(fl_3.IsDecimalFormat() == false);
        assert(fl_3.Format() == FlagType::kBinaryFormat);
        
        assert((FlagValueType)fl_2 == (FlagType::kBinaryFormat | 
            FlagType::kSigned | FlagType::kNegative));
        assert(fl_2.IsSigned() == true);
        assert(fl_2.IsNegative() == true);
        assert(fl_2.IsUndefinedFormat() == false);
        assert(fl_2.IsBinaryFormat() == true);
        assert(fl_2.IsOctalFormat() == false);
        assert(fl_2.IsDecimalFormat() == false);
        assert(fl_2.Format() == FlagType::kBinaryFormat);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kOctalFormat);
        typedef typename FlagType::ValueType FlagValueType;

        assert((FlagValueType)fl_0 == FlagType::kOctalFormat);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);

        fl_0.SetNegative();
        assert(fl_0.IsNegative() == false);

        fl_0.UnsetNegative();
        assert(fl_0.IsNegative() == false);


        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == true);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kOctalFormat);

        FlagType fl_1 = -fl_0;
        
        assert((FlagValueType)fl_1 == FlagType::kOctalFormat);
        assert(fl_1.IsSigned() == false);
        assert(fl_1.IsNegative() == false);
        assert(fl_1.IsUndefinedFormat() == false);
        assert(fl_1.IsBinaryFormat() == false);
        assert(fl_1.IsOctalFormat() == true);
        assert(fl_1.IsDecimalFormat() == false);
        assert(fl_1.Format() == FlagType::kOctalFormat);
        
        FlagType fl_2(std::move(fl_1));

        assert((FlagValueType)fl_2 == FlagType::kOctalFormat);
        assert(fl_2.IsSigned() == false);
        assert(fl_2.IsNegative() == false);
        assert(fl_2.IsUndefinedFormat() == false);
        assert(fl_2.IsBinaryFormat() == false);
        assert(fl_2.IsOctalFormat() == true);
        assert(fl_2.IsDecimalFormat() == false);
        assert(fl_2.Format() == FlagType::kOctalFormat);
        
        assert((FlagValueType)fl_1 == 0);
        assert(fl_1.IsSigned() == false);
        assert(fl_1.IsNegative() == false);
        assert(fl_1.IsUndefinedFormat() == true);
        assert(fl_1.IsBinaryFormat() == false);
        assert(fl_1.IsOctalFormat() == false);
        assert(fl_1.IsDecimalFormat() == false);
        assert(fl_1.Format() == 0);

        fl_2 = -fl_0;
        assert((FlagValueType)fl_2 == FlagType::kOctalFormat);
        assert(fl_2.IsSigned() == false);
        assert(fl_2.IsNegative() == false);
        assert(fl_2.IsUndefinedFormat() == false);
        assert(fl_2.IsBinaryFormat() == false);
        assert(fl_2.IsOctalFormat() == true);
        assert(fl_2.IsDecimalFormat() == false);
        assert(fl_2.Format() == FlagType::kOctalFormat);

        FlagType fl_3(fl_2);

        fl_3 = std::move(fl_2);
        assert((FlagValueType)fl_3 == FlagType::kOctalFormat);
        assert(fl_3.IsSigned() == false);
        assert(fl_3.IsNegative() == false);
        assert(fl_3.IsUndefinedFormat() == false);
        assert(fl_3.IsBinaryFormat() == false);
        assert(fl_3.IsOctalFormat() == true);
        assert(fl_3.IsDecimalFormat() == false);
        assert(fl_3.Format() == FlagType::kOctalFormat);
        
        assert((FlagValueType)fl_2 == FlagType::kOctalFormat);
        assert(fl_2.IsSigned() == false);
        assert(fl_2.IsNegative() == false);
        assert(fl_2.IsUndefinedFormat() == false);
        assert(fl_2.IsBinaryFormat() == false);
        assert(fl_2.IsOctalFormat() == true);
        assert(fl_2.IsDecimalFormat() == false);
        assert(fl_2.Format() == FlagType::kOctalFormat);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kOctalFormat | FlagType::kSigned);
        typedef typename FlagType::ValueType FlagValueType;

        assert((FlagValueType)fl_0 == (FlagType::kOctalFormat | 
            FlagType::kSigned));

        assert(fl_0.IsSigned() == true);
        assert(fl_0.IsNegative() == false);

        fl_0.SetNegative();
        assert(fl_0.IsNegative() == true);

        fl_0.UnsetNegative();
        assert(fl_0.IsNegative() == false);


        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == true);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kOctalFormat);

        FlagType fl_1 = -fl_0;
        
        assert((FlagValueType)fl_1 == (FlagType::kOctalFormat | 
            FlagType::kSigned | FlagType::kNegative));
        assert(fl_1.IsSigned() == true);
        assert(fl_1.IsNegative() == true);
        assert(fl_1.IsUndefinedFormat() == false);
        assert(fl_1.IsBinaryFormat() == false);
        assert(fl_1.IsOctalFormat() == true);
        assert(fl_1.IsDecimalFormat() == false);
        assert(fl_1.Format() == FlagType::kOctalFormat);
        
        FlagType fl_2(std::move(fl_1));

        assert((FlagValueType)fl_2 == (FlagType::kOctalFormat | 
            FlagType::kSigned | FlagType::kNegative));
        assert(fl_2.IsSigned() == true);
        assert(fl_2.IsNegative() == true);
        assert(fl_2.IsUndefinedFormat() == false);
        assert(fl_2.IsBinaryFormat() == false);
        assert(fl_2.IsOctalFormat() == true);
        assert(fl_2.IsDecimalFormat() == false);
        assert(fl_2.Format() == FlagType::kOctalFormat);
        
        assert((FlagValueType)fl_1 == 0);
        assert(fl_1.IsSigned() == false);
        assert(fl_1.IsNegative() == false);
        assert(fl_1.IsUndefinedFormat() == true);
        assert(fl_1.IsBinaryFormat() == false);
        assert(fl_1.IsOctalFormat() == false);
        assert(fl_1.IsDecimalFormat() == false);
        assert(fl_1.Format() == 0);

        fl_2 = -fl_0;
        assert((FlagValueType)fl_2 == (FlagType::kOctalFormat | 
            FlagType::kSigned | FlagType::kNegative));
        assert(fl_2.IsSigned() == true);
        assert(fl_2.IsNegative() == true);
        assert(fl_2.IsUndefinedFormat() == false);
        assert(fl_2.IsBinaryFormat() == false);
        assert(fl_2.IsOctalFormat() == true);
        assert(fl_2.IsDecimalFormat() == false);
        assert(fl_2.Format() == FlagType::kOctalFormat);

        FlagType fl_3(fl_2);

        fl_3 = std::move(fl_2);
        assert((FlagValueType)fl_3 == (FlagType::kOctalFormat | 
            FlagType::kSigned | FlagType::kNegative));
        assert(fl_3.IsSigned() == true);
        assert(fl_3.IsNegative() == true);
        assert(fl_3.IsUndefinedFormat() == false);
        assert(fl_3.IsBinaryFormat() == false);
        assert(fl_3.IsOctalFormat() == true);
        assert(fl_3.IsDecimalFormat() == false);
        assert(fl_3.Format() == FlagType::kOctalFormat);
        
        assert((FlagValueType)fl_2 == (FlagType::kOctalFormat | 
            FlagType::kSigned | FlagType::kNegative));
        assert(fl_2.IsSigned() == true);
        assert(fl_2.IsNegative() == true);
        assert(fl_2.IsUndefinedFormat() == false);
        assert(fl_2.IsBinaryFormat() == false);
        assert(fl_2.IsOctalFormat() == true);
        assert(fl_2.IsDecimalFormat() == false);
        assert(fl_2.Format() == FlagType::kOctalFormat);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kDecimalFormat);
        typedef typename FlagType::ValueType FlagValueType;

        assert((FlagValueType)fl_0 == FlagType::kDecimalFormat);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);

        fl_0.SetNegative();
        assert(fl_0.IsNegative() == false);

        fl_0.UnsetNegative();
        assert(fl_0.IsNegative() == false);


        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == true);
        assert(fl_0.Format() == FlagType::kDecimalFormat);

        FlagType fl_1 = -fl_0;
        
        assert((FlagValueType)fl_1 == FlagType::kDecimalFormat);
        assert(fl_1.IsSigned() == false);
        assert(fl_1.IsNegative() == false);
        assert(fl_1.IsUndefinedFormat() == false);
        assert(fl_1.IsBinaryFormat() == false);
        assert(fl_1.IsOctalFormat() == false);
        assert(fl_1.IsDecimalFormat() == true);
        assert(fl_1.Format() == FlagType::kDecimalFormat);
        
        FlagType fl_2(std::move(fl_1));

        assert((FlagValueType)fl_2 == FlagType::kDecimalFormat);
        assert(fl_2.IsSigned() == false);
        assert(fl_2.IsNegative() == false);
        assert(fl_2.IsUndefinedFormat() == false);
        assert(fl_2.IsBinaryFormat() == false);
        assert(fl_2.IsOctalFormat() == false);
        assert(fl_2.IsDecimalFormat() == true);
        assert(fl_2.Format() == FlagType::kDecimalFormat);
        
        assert((FlagValueType)fl_1 == 0);
        assert(fl_1.IsSigned() == false);
        assert(fl_1.IsNegative() == false);
        assert(fl_1.IsUndefinedFormat() == true);
        assert(fl_1.IsBinaryFormat() == false);
        assert(fl_1.IsOctalFormat() == false);
        assert(fl_1.IsDecimalFormat() == false);
        assert(fl_1.Format() == 0);

        fl_2 = -fl_0;
        assert((FlagValueType)fl_2 == FlagType::kDecimalFormat);
        assert(fl_2.IsSigned() == false);
        assert(fl_2.IsNegative() == false);
        assert(fl_2.IsUndefinedFormat() == false);
        assert(fl_2.IsBinaryFormat() == false);
        assert(fl_2.IsOctalFormat() == false);
        assert(fl_2.IsDecimalFormat() == true);
        assert(fl_2.Format() == FlagType::kDecimalFormat);

        FlagType fl_3(fl_2);

        fl_3 = std::move(fl_2);
        assert((FlagValueType)fl_3 == FlagType::kDecimalFormat);
        assert(fl_3.IsSigned() == false);
        assert(fl_3.IsNegative() == false);
        assert(fl_3.IsUndefinedFormat() == false);
        assert(fl_3.IsBinaryFormat() == false);
        assert(fl_3.IsOctalFormat() == false);
        assert(fl_3.IsDecimalFormat() == true);
        assert(fl_3.Format() == FlagType::kDecimalFormat);
        
        assert((FlagValueType)fl_2 == FlagType::kDecimalFormat);
        assert(fl_2.IsSigned() == false);
        assert(fl_2.IsNegative() == false);
        assert(fl_2.IsUndefinedFormat() == false);
        assert(fl_2.IsBinaryFormat() == false);
        assert(fl_2.IsOctalFormat() == false);
        assert(fl_2.IsDecimalFormat() == true);
        assert(fl_2.Format() == FlagType::kDecimalFormat);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kDecimalFormat | FlagType::kSigned);
        typedef typename FlagType::ValueType FlagValueType;

        assert((FlagValueType)fl_0 == (FlagType::kDecimalFormat | 
            FlagType::kSigned));

        assert(fl_0.IsSigned() == true);
        assert(fl_0.IsNegative() == false);

        fl_0.SetNegative();
        assert(fl_0.IsNegative() == true);

        fl_0.UnsetNegative();
        assert(fl_0.IsNegative() == false);


        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == true);
        assert(fl_0.Format() == FlagType::kDecimalFormat);

        FlagType fl_1 = -fl_0;
        
        assert((FlagValueType)fl_1 == (FlagType::kDecimalFormat | 
            FlagType::kSigned | FlagType::kNegative));
        assert(fl_1.IsSigned() == true);
        assert(fl_1.IsNegative() == true);
        assert(fl_1.IsUndefinedFormat() == false);
        assert(fl_1.IsBinaryFormat() == false);
        assert(fl_1.IsOctalFormat() == false);
        assert(fl_1.IsDecimalFormat() == true);
        assert(fl_1.Format() == FlagType::kDecimalFormat);
        
        FlagType fl_2(std::move(fl_1));

        assert((FlagValueType)fl_2 == (FlagType::kDecimalFormat | 
            FlagType::kSigned | FlagType::kNegative));
        assert(fl_2.IsSigned() == true);
        assert(fl_2.IsNegative() == true);
        assert(fl_2.IsUndefinedFormat() == false);
        assert(fl_2.IsBinaryFormat() == false);
        assert(fl_2.IsOctalFormat() == false);
        assert(fl_2.IsDecimalFormat() == true);
        assert(fl_2.Format() == FlagType::kDecimalFormat);
        
        assert((FlagValueType)fl_1 == 0);
        assert(fl_1.IsSigned() == false);
        assert(fl_1.IsNegative() == false);
        assert(fl_1.IsUndefinedFormat() == true);
        assert(fl_1.IsBinaryFormat() == false);
        assert(fl_1.IsOctalFormat() == false);
        assert(fl_1.IsDecimalFormat() == false);
        assert(fl_1.Format() == 0);

        fl_2 = -fl_0;
        assert((FlagValueType)fl_2 == (FlagType::kDecimalFormat | 
            FlagType::kSigned | FlagType::kNegative));
        assert(fl_2.IsSigned() == true);
        assert(fl_2.IsNegative() == true);
        assert(fl_2.IsUndefinedFormat() == false);
        assert(fl_2.IsBinaryFormat() == false);
        assert(fl_2.IsOctalFormat() == false);
        assert(fl_2.IsDecimalFormat() == true);
        assert(fl_2.Format() == FlagType::kDecimalFormat);

        FlagType fl_3(fl_2);

        fl_3 = std::move(fl_2);
        assert((FlagValueType)fl_3 == (FlagType::kDecimalFormat | 
            FlagType::kSigned | FlagType::kNegative));
        assert(fl_3.IsSigned() == true);
        assert(fl_3.IsNegative() == true);
        assert(fl_3.IsUndefinedFormat() == false);
        assert(fl_3.IsBinaryFormat() == false);
        assert(fl_3.IsOctalFormat() == false);
        assert(fl_3.IsDecimalFormat() == true);
        assert(fl_3.Format() == FlagType::kDecimalFormat);
        
        assert((FlagValueType)fl_2 == (FlagType::kDecimalFormat | 
            FlagType::kSigned | FlagType::kNegative));
        assert(fl_2.IsSigned() == true);
        assert(fl_2.IsNegative() == true);
        assert(fl_2.IsUndefinedFormat() == false);
        assert(fl_2.IsBinaryFormat() == false);
        assert(fl_2.IsOctalFormat() == false);
        assert(fl_2.IsDecimalFormat() == true);
        assert(fl_2.Format() == FlagType::kDecimalFormat);
    }
    ////
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kBinaryFormat);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == FlagType::kBinaryFormat);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == true);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kBinaryFormat);
        
        FlagType fl_1(FlagType::kBinaryFormat);

        assert((fl_0 += fl_1) == FlagType::kAdditionOp);
        assert((fl_0 -= fl_1) == FlagType::kSubtractionOp);
        assert((fl_0 *= fl_1) == FlagType::kMultiplicationOp);
        assert((fl_0 /= fl_1) == FlagType::kDivisionOp);
        assert((fl_0 %= fl_1) == FlagType::kModuloOp);
        assert((fl_0 |= fl_1) == FlagType::kOrOp);
        assert((fl_0 &= fl_1) == FlagType::kAndOp);
        assert((fl_0 ^= fl_1) == FlagType::kXorOp);
        assert((fl_0 >>= fl_1) == FlagType::kRShiftOp);
        assert((fl_0 <<= fl_1) == FlagType::kLShiftOp);
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == FlagType::kNotOp);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kBinaryFormat);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == FlagType::kBinaryFormat);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == true);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kBinaryFormat);
        
        FlagType fl_1(FlagType::kBinaryFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == false);

        assert((fl_0 += fl_1) == FlagType::kAdditionOp);
        assert((fl_0 -= fl_1) == FlagType::kSubtractionOp);
        assert((fl_0 *= fl_1) == FlagType::kMultiplicationOp);
        assert((fl_0 /= fl_1) == FlagType::kDivisionOp);
        assert((fl_0 %= fl_1) == FlagType::kModuloOp);
        assert((fl_0 |= fl_1) == FlagType::kOrOp);
        assert((fl_0 &= fl_1) == FlagType::kAndOp);
        assert((fl_0 ^= fl_1) == FlagType::kXorOp);
        assert((fl_0 >>= fl_1) == FlagType::kRShiftOp);
        assert((fl_0 <<= fl_1) == FlagType::kLShiftOp);
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == FlagType::kNotOp);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == FlagType::kSubtractionOp);
        assert((fl_0 -= fl_1) == FlagType::kAdditionOp);

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == (FlagType::kMultiplicationOp |
            FlagType::kNegationOp));
        assert(fl_0.IsNegative() == false);

        assert(fl_0.IsNegative() == false);
        assert((fl_0 /= fl_1) == (FlagType::kDivisionOp |
            FlagType::kNegationOp));
        assert(fl_0.IsNegative() == false);
        
        fl_0.UnsetNegative();
        assert((fl_0 %= fl_1) == FlagType::kModuloOp);

        assert((fl_0 |= fl_1) == FlagType::kOrOp);
        assert((fl_0 &= fl_1) == FlagType::kAndOp);
        assert((fl_0 ^= fl_1) == FlagType::kXorOp);
        assert((fl_0 >>= fl_1) == FlagType::kRShiftOp);
        assert((fl_0 <<= fl_1) == FlagType::kLShiftOp);
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kBinaryFormat |
            FlagType::kSigned);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == (FlagType::kBinaryFormat |
            FlagType::kSigned));

        assert(fl_0.IsSigned() == true);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == true);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kBinaryFormat);
        
        FlagType fl_1(FlagType::kBinaryFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == false);

        assert((fl_0 += fl_1) == FlagType::kAdditionOp);
        assert((fl_0 -= fl_1) == FlagType::kSubtractionOp);
        assert((fl_0 *= fl_1) == FlagType::kMultiplicationOp);
        assert((fl_0 /= fl_1) == FlagType::kDivisionOp);
        assert((fl_0 %= fl_1) == FlagType::kModuloOp);
        assert((fl_0 |= fl_1) == FlagType::kOrOp);
        assert((fl_0 &= fl_1) == FlagType::kAndOp);
        assert((fl_0 ^= fl_1) == FlagType::kXorOp);
        assert((fl_0 >>= fl_1) == FlagType::kRShiftOp);
        assert((fl_0 <<= fl_1) == FlagType::kLShiftOp);
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == FlagType::kNotOp);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == FlagType::kSubtractionOp);
        assert((fl_0 -= fl_1) == FlagType::kAdditionOp);

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == FlagType::kMultiplicationOp);
        assert(fl_0.IsNegative() == true);

        fl_0.UnsetNegative();
        assert(fl_0.IsNegative() == false);
        assert((fl_0 /= fl_1) == FlagType::kDivisionOp);
        assert(fl_0.IsNegative() == true);
        
        fl_0.UnsetNegative();
        assert((fl_0 %= fl_1) == FlagType::kModuloOp);

        assert((fl_0 |= fl_1) == FlagType::kOrOp);
        assert((fl_0 &= fl_1) == FlagType::kAndOp);
        assert((fl_0 ^= fl_1) == FlagType::kXorOp);
        assert((fl_0 >>= fl_1) == FlagType::kRShiftOp);
        assert((fl_0 <<= fl_1) == FlagType::kLShiftOp);
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kBinaryFormat |
            FlagType::kSigned);
        typedef typename FlagType::ValueType FlagValueType;

        fl_0.SetNegative();
        
        assert((FlagValueType)fl_0 == (FlagType::kBinaryFormat |
            FlagType::kSigned | FlagType::kNegative));

        assert(fl_0.IsSigned() == true);
        assert(fl_0.IsNegative() == true);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == true);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kBinaryFormat);
        
        FlagType fl_1(FlagType::kBinaryFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == true);

        assert((fl_0 += fl_1) == FlagType::kSubtractionOp);
        assert((fl_0 -= fl_1) == FlagType::kAdditionOp);
        assert((fl_0 *= fl_1) == FlagType::kMultiplicationOp);
        assert((fl_0 /= fl_1) == FlagType::kDivisionOp);
        assert((fl_0 %= fl_1) == FlagType::kModuloOp);
        assert((fl_0 |= fl_1) == FlagType::kOrOp);
        assert((fl_0 &= fl_1) == FlagType::kAndOp);
        assert((fl_0 ^= fl_1) == FlagType::kXorOp);
        assert((fl_0 >>= fl_1) == (FlagType::kRShiftOp | 
            FlagType::kIncrementOp));
        assert((fl_0 <<= fl_1) == FlagType::kLShiftOp);
        assert((fl_0 >>= 1) == (FlagType::kRShiftOp | 
            FlagType::kIncrementOp));
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == FlagType::kNotOp);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == FlagType::kAdditionOp);
        assert((fl_0 -= fl_1) == FlagType::kSubtractionOp);

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == FlagType::kMultiplicationOp);
        assert(fl_0.IsNegative() == false);

        fl_0.SetNegative();
        assert(fl_0.IsNegative() == true);
        assert((fl_0 /= fl_1) == FlagType::kDivisionOp);
        assert(fl_0.IsNegative() == false);
        
        fl_0.SetNegative();
        assert((fl_0 %= fl_1) == FlagType::kModuloOp);

        assert((fl_0 |= fl_1) == FlagType::kOrOp);
        assert((fl_0 &= fl_1) == FlagType::kAndOp);
        assert((fl_0 ^= fl_1) == FlagType::kXorOp);
        assert((fl_0 >>= fl_1) == (FlagType::kRShiftOp | 
            FlagType::kIncrementOp));
        assert((fl_0 <<= fl_1) == FlagType::kLShiftOp);
        assert((fl_0 >>= 1) == (FlagType::kRShiftOp | 
            FlagType::kIncrementOp));
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    ////
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kBinaryFormat);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == FlagType::kBinaryFormat);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == true);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kBinaryFormat);
        
        FlagType fl_1(FlagType::kOctalFormat);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp | 
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == (FlagType::kConversionOp |
            FlagType::kOrOp));
        assert((fl_0 &= fl_1) == (FlagType::kConversionOp |
            FlagType::kAndOp));
        assert((fl_0 ^= fl_1) == (FlagType::kConversionOp |
            FlagType::kXorOp));
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp | 
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp | 
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == FlagType::kNotOp);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kBinaryFormat);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == FlagType::kBinaryFormat);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == true);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kBinaryFormat);
        
        FlagType fl_1(FlagType::kOctalFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == false);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp | 
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp | 
            FlagType::kSubtractionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp | 
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp | 
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp | 
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == (FlagType::kConversionOp | 
            FlagType::kOrOp));
        assert((fl_0 &= fl_1) == (FlagType::kConversionOp | 
            FlagType::kAndOp));
        assert((fl_0 ^= fl_1) == (FlagType::kConversionOp | 
            FlagType::kXorOp));
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp | 
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp | 
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == FlagType::kNotOp);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp | 
            FlagType::kSubtractionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp | 
            FlagType::kAdditionOp));

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp | FlagType::kNegationOp));
        assert(fl_0.IsNegative() == false);

        assert(fl_0.IsNegative() == false);
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp | 
            FlagType::kDivisionOp | FlagType::kNegationOp));
        assert(fl_0.IsNegative() == false);
        
        fl_0.UnsetNegative();
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp | 
            FlagType::kModuloOp));

        assert((fl_0 |= fl_1) == (FlagType::kConversionOp | 
            FlagType::kOrOp));
        assert((fl_0 &= fl_1) == (FlagType::kConversionOp | 
            FlagType::kAndOp));
        assert((fl_0 ^= fl_1) == (FlagType::kConversionOp | 
            FlagType::kXorOp));
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp | 
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp | 
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kBinaryFormat |
            FlagType::kSigned);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == (FlagType::kBinaryFormat |
            FlagType::kSigned));

        assert(fl_0.IsSigned() == true);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == true);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kBinaryFormat);
        
        FlagType fl_1(FlagType::kOctalFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == false);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp | 
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp | 
            FlagType::kSubtractionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp | 
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp | 
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp | 
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == (FlagType::kConversionOp | 
            FlagType::kOrOp));
        assert((fl_0 &= fl_1) == (FlagType::kConversionOp | 
            FlagType::kAndOp));
        assert((fl_0 ^= fl_1) == (FlagType::kConversionOp | 
            FlagType::kXorOp));
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp | 
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp | 
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == FlagType::kNotOp);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp | 
            FlagType::kSubtractionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp | 
            FlagType::kAdditionOp));

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp | 
            FlagType::kMultiplicationOp));
        assert(fl_0.IsNegative() == true);

        fl_0.UnsetNegative();
        assert(fl_0.IsNegative() == false);
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp | 
            FlagType::kDivisionOp));
        assert(fl_0.IsNegative() == true);
        
        fl_0.UnsetNegative();
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp | 
            FlagType::kModuloOp));

        assert((fl_0 |= fl_1) == (FlagType::kConversionOp | 
            FlagType::kOrOp));
        assert((fl_0 &= fl_1) == (FlagType::kConversionOp | 
            FlagType::kAndOp));
        assert((fl_0 ^= fl_1) == (FlagType::kConversionOp | 
            FlagType::kXorOp));
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp | 
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp | 
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kBinaryFormat |
            FlagType::kSigned);
        typedef typename FlagType::ValueType FlagValueType;

        fl_0.SetNegative();
        
        assert((FlagValueType)fl_0 == (FlagType::kBinaryFormat |
            FlagType::kSigned | FlagType::kNegative));

        assert(fl_0.IsSigned() == true);
        assert(fl_0.IsNegative() == true);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == true);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kBinaryFormat);
        
        FlagType fl_1(FlagType::kOctalFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp | 
            FlagType::kSubtractionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp | 
            FlagType::kAdditionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp | 
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp | 
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp | 
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == (FlagType::kConversionOp | 
            FlagType::kOrOp));
        assert((fl_0 &= fl_1) == (FlagType::kConversionOp | 
            FlagType::kAndOp));
        assert((fl_0 ^= fl_1) == (FlagType::kConversionOp | 
            FlagType::kXorOp));
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp | 
            FlagType::kRShiftOp | FlagType::kIncrementOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp | 
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == (FlagType::kRShiftOp | 
            FlagType::kIncrementOp));
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == FlagType::kNotOp);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp | 
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp | 
            FlagType::kSubtractionOp));

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp | 
            FlagType::kMultiplicationOp));
        assert(fl_0.IsNegative() == false);

        fl_0.SetNegative();
        assert(fl_0.IsNegative() == true);
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp | 
            FlagType::kDivisionOp));
        assert(fl_0.IsNegative() == false);
        
        fl_0.SetNegative();
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp | 
            FlagType::kModuloOp));

        assert((fl_0 |= fl_1) == (FlagType::kConversionOp | 
            FlagType::kOrOp));
        assert((fl_0 &= fl_1) == (FlagType::kConversionOp | 
            FlagType::kAndOp));
        assert((fl_0 ^= fl_1) == (FlagType::kConversionOp | 
            FlagType::kXorOp));
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp | FlagType::kIncrementOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == (FlagType::kRShiftOp | 
            FlagType::kIncrementOp));
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    ////
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kBinaryFormat);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == FlagType::kBinaryFormat);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == true);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kBinaryFormat);
        
        FlagType fl_1(FlagType::kDecimalFormat);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp | 
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == (FlagType::kConversionOp |
            FlagType::kOrOp));
        assert((fl_0 &= fl_1) == (FlagType::kConversionOp |
            FlagType::kAndOp));
        assert((fl_0 ^= fl_1) == (FlagType::kConversionOp |
            FlagType::kXorOp));
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == FlagType::kNotOp);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kBinaryFormat);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == FlagType::kBinaryFormat);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == true);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kBinaryFormat);
        
        FlagType fl_1(FlagType::kDecimalFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == false);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp | 
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp | 
            FlagType::kSubtractionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp | 
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp | 
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp | 
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == (FlagType::kConversionOp | 
            FlagType::kOrOp));
        assert((fl_0 &= fl_1) == (FlagType::kConversionOp | 
            FlagType::kAndOp));
        assert((fl_0 ^= fl_1) == (FlagType::kConversionOp | 
            FlagType::kXorOp));
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp | 
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp | 
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == FlagType::kNotOp);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp | 
            FlagType::kSubtractionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp | 
            FlagType::kAdditionOp));

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp | FlagType::kNegationOp));
        assert(fl_0.IsNegative() == false);

        assert(fl_0.IsNegative() == false);
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp | 
            FlagType::kDivisionOp | FlagType::kNegationOp));
        assert(fl_0.IsNegative() == false);
        
        fl_0.UnsetNegative();
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp | 
            FlagType::kModuloOp));

        assert((fl_0 |= fl_1) == (FlagType::kConversionOp | 
            FlagType::kOrOp));
        assert((fl_0 &= fl_1) == (FlagType::kConversionOp | 
            FlagType::kAndOp));
        assert((fl_0 ^= fl_1) == (FlagType::kConversionOp | 
            FlagType::kXorOp));
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp | 
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp | 
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kBinaryFormat |
            FlagType::kSigned);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == (FlagType::kBinaryFormat |
            FlagType::kSigned));

        assert(fl_0.IsSigned() == true);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == true);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kBinaryFormat);
        
        FlagType fl_1(FlagType::kDecimalFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == false);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp | 
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp | 
            FlagType::kSubtractionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp | 
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp | 
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp | 
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == (FlagType::kConversionOp | 
            FlagType::kOrOp));
        assert((fl_0 &= fl_1) == (FlagType::kConversionOp | 
            FlagType::kAndOp));
        assert((fl_0 ^= fl_1) == (FlagType::kConversionOp | 
            FlagType::kXorOp));
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp | 
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp | 
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == FlagType::kNotOp);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp | 
            FlagType::kSubtractionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp | 
            FlagType::kAdditionOp));

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp | 
            FlagType::kMultiplicationOp));
        assert(fl_0.IsNegative() == true);

        fl_0.UnsetNegative();
        assert(fl_0.IsNegative() == false);
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp | 
            FlagType::kDivisionOp));
        assert(fl_0.IsNegative() == true);
        
        fl_0.UnsetNegative();
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp | 
            FlagType::kModuloOp));

        assert((fl_0 |= fl_1) == (FlagType::kConversionOp | 
            FlagType::kOrOp));
        assert((fl_0 &= fl_1) == (FlagType::kConversionOp | 
            FlagType::kAndOp));
        assert((fl_0 ^= fl_1) == (FlagType::kConversionOp | 
            FlagType::kXorOp));
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp | 
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp | 
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kBinaryFormat |
            FlagType::kSigned);
        typedef typename FlagType::ValueType FlagValueType;

        fl_0.SetNegative();
        
        assert((FlagValueType)fl_0 == (FlagType::kBinaryFormat |
            FlagType::kSigned | FlagType::kNegative));

        assert(fl_0.IsSigned() == true);
        assert(fl_0.IsNegative() == true);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == true);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kBinaryFormat);
        
        FlagType fl_1(FlagType::kDecimalFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp | 
            FlagType::kSubtractionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp | 
            FlagType::kAdditionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp | 
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp | 
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp | 
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == (FlagType::kConversionOp | 
            FlagType::kOrOp));
        assert((fl_0 &= fl_1) == (FlagType::kConversionOp | 
            FlagType::kAndOp));
        assert((fl_0 ^= fl_1) == (FlagType::kConversionOp | 
            FlagType::kXorOp));
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp | 
            FlagType::kRShiftOp | FlagType::kIncrementOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp | 
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == (FlagType::kRShiftOp | 
            FlagType::kIncrementOp));
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == FlagType::kNotOp);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp | 
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp | 
            FlagType::kSubtractionOp));

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp | 
            FlagType::kMultiplicationOp));
        assert(fl_0.IsNegative() == false);

        fl_0.SetNegative();
        assert(fl_0.IsNegative() == true);
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp | 
            FlagType::kDivisionOp));
        assert(fl_0.IsNegative() == false);
        
        fl_0.SetNegative();
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp | 
            FlagType::kModuloOp));

        assert((fl_0 |= fl_1) == (FlagType::kConversionOp | 
            FlagType::kOrOp));
        assert((fl_0 &= fl_1) == (FlagType::kConversionOp | 
            FlagType::kAndOp));
        assert((fl_0 ^= fl_1) == (FlagType::kConversionOp | 
            FlagType::kXorOp));
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp | 
            FlagType::kRShiftOp | FlagType::kIncrementOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp | 
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == (FlagType::kRShiftOp | 
            FlagType::kIncrementOp));
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    ////
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kOctalFormat);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == FlagType::kOctalFormat);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == true);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kOctalFormat);
        
        FlagType fl_1(FlagType::kBinaryFormat);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp |
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp | 
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp | 
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp | 
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kOctalFormat);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == FlagType::kOctalFormat);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == true);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kOctalFormat);
        
        FlagType fl_1(FlagType::kBinaryFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == false);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp |
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kAdditionOp));

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp | FlagType::kNegationOp));
        assert(fl_0.IsNegative() == false);

        assert(fl_0.IsNegative() == false);
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp | FlagType::kNegationOp));
        assert(fl_0.IsNegative() == false);
        
        fl_0.UnsetNegative();
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));

        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kOctalFormat |
            FlagType::kSigned);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == (FlagType::kOctalFormat |
            FlagType::kSigned));

        assert(fl_0.IsSigned() == true);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == true);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kOctalFormat);
        
        FlagType fl_1(FlagType::kBinaryFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == false);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp |
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kAdditionOp));

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp));
        assert(fl_0.IsNegative() == true);

        fl_0.UnsetNegative();
        assert(fl_0.IsNegative() == false);
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp));
        assert(fl_0.IsNegative() == true);
        
        fl_0.UnsetNegative();
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));

        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kOctalFormat |
            FlagType::kSigned);
        typedef typename FlagType::ValueType FlagValueType;

        fl_0.SetNegative();
        
        assert((FlagValueType)fl_0 == (FlagType::kOctalFormat |
            FlagType::kSigned | FlagType::kNegative));

        assert(fl_0.IsSigned() == true);
        assert(fl_0.IsNegative() == true);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == true);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kOctalFormat);
        
        FlagType fl_1(FlagType::kBinaryFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kAdditionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp |
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp));
        assert(fl_0.IsNegative() == false);

        fl_0.SetNegative();
        assert(fl_0.IsNegative() == true);
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp));
        assert(fl_0.IsNegative() == false);
        
        fl_0.SetNegative();
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));

        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    ////
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kOctalFormat);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == FlagType::kOctalFormat);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == true);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kOctalFormat);
        
        FlagType fl_1(FlagType::kOctalFormat);

        assert((fl_0 += fl_1) == FlagType::kAdditionOp);
        assert((fl_0 -= fl_1) == FlagType::kSubtractionOp);
        assert((fl_0 *= fl_1) == FlagType::kMultiplicationOp);
        assert((fl_0 /= fl_1) == FlagType::kDivisionOp);
        assert((fl_0 %= fl_1) == FlagType::kModuloOp);
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == FlagType::kRShiftOp);
        assert((fl_0 <<= fl_1) == FlagType::kLShiftOp);
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kOctalFormat);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == FlagType::kOctalFormat);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == true);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kOctalFormat);
        
        FlagType fl_1(FlagType::kOctalFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == false);

        assert((fl_0 += fl_1) == FlagType::kAdditionOp);
        assert((fl_0 -= fl_1) == FlagType::kSubtractionOp);
        assert((fl_0 *= fl_1) == FlagType::kMultiplicationOp);
        assert((fl_0 /= fl_1) == FlagType::kDivisionOp);
        assert((fl_0 %= fl_1) == FlagType::kModuloOp);
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == FlagType::kRShiftOp);
        assert((fl_0 <<= fl_1) == FlagType::kLShiftOp);
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == FlagType::kSubtractionOp);
        assert((fl_0 -= fl_1) == FlagType::kAdditionOp);

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == (FlagType::kMultiplicationOp | 
            FlagType::kNegationOp));
        assert(fl_0.IsNegative() == false);

        assert(fl_0.IsNegative() == false);
        assert((fl_0 /= fl_1) == (FlagType::kDivisionOp | 
            FlagType::kNegationOp));
        assert(fl_0.IsNegative() == false);
        
        fl_0.UnsetNegative();
        assert((fl_0 %= fl_1) == FlagType::kModuloOp);

        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == FlagType::kRShiftOp);
        assert((fl_0 <<= fl_1) == FlagType::kLShiftOp);
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kOctalFormat |
            FlagType::kSigned);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == (FlagType::kOctalFormat |
            FlagType::kSigned));

        assert(fl_0.IsSigned() == true);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == true);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kOctalFormat);
        
        FlagType fl_1(FlagType::kOctalFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == false);

        assert((fl_0 += fl_1) == FlagType::kAdditionOp);
        assert((fl_0 -= fl_1) == FlagType::kSubtractionOp);
        assert((fl_0 *= fl_1) == FlagType::kMultiplicationOp);
        assert((fl_0 /= fl_1) == FlagType::kDivisionOp);
        assert((fl_0 %= fl_1) == FlagType::kModuloOp);
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == FlagType::kRShiftOp);
        assert((fl_0 <<= fl_1) == FlagType::kLShiftOp);
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == FlagType::kSubtractionOp);
        assert((fl_0 -= fl_1) == FlagType::kAdditionOp);

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == FlagType::kMultiplicationOp);
        assert(fl_0.IsNegative() == true);

        fl_0.UnsetNegative();
        assert(fl_0.IsNegative() == false);
        assert((fl_0 /= fl_1) == FlagType::kDivisionOp);
        assert(fl_0.IsNegative() == true);
        
        fl_0.UnsetNegative();
        assert((fl_0 %= fl_1) == FlagType::kModuloOp);

        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == FlagType::kRShiftOp);
        assert((fl_0 <<= fl_1) == FlagType::kLShiftOp);
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kOctalFormat |
            FlagType::kSigned);
        typedef typename FlagType::ValueType FlagValueType;

        fl_0.SetNegative();
        
        assert((FlagValueType)fl_0 == (FlagType::kOctalFormat |
            FlagType::kSigned | FlagType::kNegative));

        assert(fl_0.IsSigned() == true);
        assert(fl_0.IsNegative() == true);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == true);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kOctalFormat);
        
        FlagType fl_1(FlagType::kOctalFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == true);

        assert((fl_0 += fl_1) == FlagType::kSubtractionOp);
        assert((fl_0 -= fl_1) == FlagType::kAdditionOp);
        assert((fl_0 *= fl_1) == FlagType::kMultiplicationOp);
        assert((fl_0 /= fl_1) == FlagType::kDivisionOp);
        assert((fl_0 %= fl_1) == FlagType::kModuloOp);
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == FlagType::kRShiftOp);
        assert((fl_0 <<= fl_1) == FlagType::kLShiftOp);
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == FlagType::kAdditionOp);
        assert((fl_0 -= fl_1) == FlagType::kSubtractionOp);

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == FlagType::kMultiplicationOp);
        assert(fl_0.IsNegative() == false);

        fl_0.SetNegative();
        assert(fl_0.IsNegative() == true);
        assert((fl_0 /= fl_1) == FlagType::kDivisionOp);
        assert(fl_0.IsNegative() == false);
        
        fl_0.SetNegative();
        assert((fl_0 %= fl_1) == FlagType::kModuloOp);

        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == FlagType::kRShiftOp);
        assert((fl_0 <<= fl_1) == FlagType::kLShiftOp);
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    ////
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kOctalFormat);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == FlagType::kOctalFormat);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == true);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kOctalFormat);
        
        FlagType fl_1(FlagType::kDecimalFormat);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp | 
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kOctalFormat);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == FlagType::kOctalFormat);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == true);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kOctalFormat);
        
        FlagType fl_1(FlagType::kDecimalFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == false);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp | 
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp | 
            FlagType::kSubtractionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp | 
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp | 
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp | 
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp | 
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp | 
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp | 
            FlagType::kSubtractionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp | 
            FlagType::kAdditionOp));

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp | FlagType::kNegationOp));
        assert(fl_0.IsNegative() == false);

        assert(fl_0.IsNegative() == false);
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp | 
            FlagType::kDivisionOp | FlagType::kNegationOp));
        assert(fl_0.IsNegative() == false);
        
        fl_0.UnsetNegative();
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp | 
            FlagType::kModuloOp));

        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp | 
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp | 
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kOctalFormat |
            FlagType::kSigned);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == (FlagType::kOctalFormat |
            FlagType::kSigned));

        assert(fl_0.IsSigned() == true);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == true);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kOctalFormat);
        
        FlagType fl_1(FlagType::kDecimalFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == false);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp | 
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp | 
            FlagType::kSubtractionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp | 
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp | 
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp | 
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) ==  (FlagType::kConversionOp | 
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) ==  (FlagType::kConversionOp | 
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp | 
            FlagType::kSubtractionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp | 
            FlagType::kAdditionOp));

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp | 
            FlagType::kMultiplicationOp));
        assert(fl_0.IsNegative() == true);

        fl_0.UnsetNegative();
        assert(fl_0.IsNegative() == false);
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp | 
            FlagType::kDivisionOp));
        assert(fl_0.IsNegative() == true);
        
        fl_0.UnsetNegative();
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp | 
            FlagType::kModuloOp));

        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp | 
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp | 
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kOctalFormat |
            FlagType::kSigned);
        typedef typename FlagType::ValueType FlagValueType;

        fl_0.SetNegative();
        
        assert((FlagValueType)fl_0 == (FlagType::kOctalFormat |
            FlagType::kSigned | FlagType::kNegative));

        assert(fl_0.IsSigned() == true);
        assert(fl_0.IsNegative() == true);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == true);
        assert(fl_0.IsDecimalFormat() == false);
        assert(fl_0.Format() == FlagType::kOctalFormat);
        
        FlagType fl_1(FlagType::kDecimalFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp | 
            FlagType::kSubtractionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp | 
            FlagType::kAdditionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp | 
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp | 
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp | 
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp | 
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp | 
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp | 
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp | 
            FlagType::kSubtractionOp));

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp | 
            FlagType::kMultiplicationOp));
        assert(fl_0.IsNegative() == false);

        fl_0.SetNegative();
        assert(fl_0.IsNegative() == true);
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp | 
            FlagType::kDivisionOp));
        assert(fl_0.IsNegative() == false);
        
        fl_0.SetNegative();
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp | 
            FlagType::kModuloOp));

        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp | 
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp | 
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    ////
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kDecimalFormat);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == FlagType::kDecimalFormat);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == true);
        assert(fl_0.Format() == FlagType::kDecimalFormat);
        
        FlagType fl_1(FlagType::kBinaryFormat);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp |
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp | 
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp | 
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp | 
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kDecimalFormat);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == FlagType::kDecimalFormat);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == true);
        assert(fl_0.Format() == FlagType::kDecimalFormat);
        
        FlagType fl_1(FlagType::kBinaryFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == false);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp |
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kAdditionOp));

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp | FlagType::kNegationOp));
        assert(fl_0.IsNegative() == false);

        assert(fl_0.IsNegative() == false);
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp | FlagType::kNegationOp));
        assert(fl_0.IsNegative() == false);
        
        fl_0.UnsetNegative();
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));

        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kDecimalFormat |
            FlagType::kSigned);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == (FlagType::kDecimalFormat |
            FlagType::kSigned));

        assert(fl_0.IsSigned() == true);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == true);
        assert(fl_0.Format() == FlagType::kDecimalFormat);
        
        FlagType fl_1(FlagType::kBinaryFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == false);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp |
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kAdditionOp));

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp));
        assert(fl_0.IsNegative() == true);

        fl_0.UnsetNegative();
        assert(fl_0.IsNegative() == false);
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp));
        assert(fl_0.IsNegative() == true);
        
        fl_0.UnsetNegative();
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));

        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kDecimalFormat |
            FlagType::kSigned);
        typedef typename FlagType::ValueType FlagValueType;

        fl_0.SetNegative();
        
        assert((FlagValueType)fl_0 == (FlagType::kDecimalFormat |
            FlagType::kSigned | FlagType::kNegative));

        assert(fl_0.IsSigned() == true);
        assert(fl_0.IsNegative() == true);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == true);
        assert(fl_0.Format() == FlagType::kDecimalFormat);
        
        FlagType fl_1(FlagType::kBinaryFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kAdditionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp |
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp));
        assert(fl_0.IsNegative() == false);

        fl_0.SetNegative();
        assert(fl_0.IsNegative() == true);
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp));
        assert(fl_0.IsNegative() == false);
        
        fl_0.SetNegative();
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));

        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    ////
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kDecimalFormat);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == FlagType::kDecimalFormat);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == true);
        assert(fl_0.Format() == FlagType::kDecimalFormat);
        
        FlagType fl_1(FlagType::kOctalFormat);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp |
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kDecimalFormat);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == FlagType::kDecimalFormat);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == true);
        assert(fl_0.Format() == FlagType::kDecimalFormat);
        
        FlagType fl_1(FlagType::kOctalFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == false);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp |
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kAdditionOp));

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp | FlagType::kNegationOp));
        assert(fl_0.IsNegative() == false);

        assert(fl_0.IsNegative() == false);
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp | FlagType::kNegationOp));
        assert(fl_0.IsNegative() == false);
        
        fl_0.UnsetNegative();
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));

        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kDecimalFormat |
            FlagType::kSigned);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == (FlagType::kDecimalFormat |
            FlagType::kSigned));

        assert(fl_0.IsSigned() == true);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == true);
        assert(fl_0.Format() == FlagType::kDecimalFormat);
        
        FlagType fl_1(FlagType::kOctalFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == false);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp |
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kAdditionOp));

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp));
        assert(fl_0.IsNegative() == true);

        fl_0.UnsetNegative();
        assert(fl_0.IsNegative() == false);
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp));
        assert(fl_0.IsNegative() == true);
        
        fl_0.UnsetNegative();
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));

        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kDecimalFormat |
            FlagType::kSigned);
        typedef typename FlagType::ValueType FlagValueType;

        fl_0.SetNegative();
        
        assert((FlagValueType)fl_0 == (FlagType::kDecimalFormat |
            FlagType::kSigned | FlagType::kNegative));

        assert(fl_0.IsSigned() == true);
        assert(fl_0.IsNegative() == true);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == true);
        assert(fl_0.Format() == FlagType::kDecimalFormat);
        
        FlagType fl_1(FlagType::kOctalFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kAdditionOp));
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp));
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp));
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == (FlagType::kConversionOp |
            FlagType::kAdditionOp));
        assert((fl_0 -= fl_1) == (FlagType::kConversionOp |
            FlagType::kSubtractionOp));

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == (FlagType::kConversionOp |
            FlagType::kMultiplicationOp));
        assert(fl_0.IsNegative() == false);

        fl_0.SetNegative();
        assert(fl_0.IsNegative() == true);
        assert((fl_0 /= fl_1) == (FlagType::kConversionOp |
            FlagType::kDivisionOp));
        assert(fl_0.IsNegative() == false);
        
        fl_0.SetNegative();
        assert((fl_0 %= fl_1) == (FlagType::kConversionOp |
            FlagType::kModuloOp));

        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == (FlagType::kConversionOp |
            FlagType::kRShiftOp));
        assert((fl_0 <<= fl_1) == (FlagType::kConversionOp |
            FlagType::kLShiftOp));
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    ////
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kDecimalFormat);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == FlagType::kDecimalFormat);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == true);
        assert(fl_0.Format() == FlagType::kDecimalFormat);
        
        FlagType fl_1(FlagType::kDecimalFormat);

        assert((fl_0 += fl_1) == FlagType::kAdditionOp);
        assert((fl_0 -= fl_1) == FlagType::kSubtractionOp);
        assert((fl_0 *= fl_1) == FlagType::kMultiplicationOp);
        assert((fl_0 /= fl_1) == FlagType::kDivisionOp);
        assert((fl_0 %= fl_1) == FlagType::kModuloOp);
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == FlagType::kRShiftOp);
        assert((fl_0 <<= fl_1) == FlagType::kLShiftOp);
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kDecimalFormat);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == FlagType::kDecimalFormat);

        assert(fl_0.IsSigned() == false);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == true);
        assert(fl_0.Format() == FlagType::kDecimalFormat);
        
        FlagType fl_1(FlagType::kDecimalFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == false);

        assert((fl_0 += fl_1) == FlagType::kAdditionOp);
        assert((fl_0 -= fl_1) == FlagType::kSubtractionOp);
        assert((fl_0 *= fl_1) == FlagType::kMultiplicationOp);
        assert((fl_0 /= fl_1) == FlagType::kDivisionOp);
        assert((fl_0 %= fl_1) == FlagType::kModuloOp);
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == FlagType::kRShiftOp);
        assert((fl_0 <<= fl_1) == FlagType::kLShiftOp);
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == FlagType::kSubtractionOp);
        assert((fl_0 -= fl_1) == FlagType::kAdditionOp);

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == (FlagType::kMultiplicationOp | 
            FlagType::kNegationOp));
        assert(fl_0.IsNegative() == false);

        assert(fl_0.IsNegative() == false);
        assert((fl_0 /= fl_1) == (FlagType::kDivisionOp | 
            FlagType::kNegationOp));
        assert(fl_0.IsNegative() == false);
        
        fl_0.UnsetNegative();
        assert((fl_0 %= fl_1) == FlagType::kModuloOp);

        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == FlagType::kRShiftOp);
        assert((fl_0 <<= fl_1) == FlagType::kLShiftOp);
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kDecimalFormat |
            FlagType::kSigned);
        typedef typename FlagType::ValueType FlagValueType;
        
        assert((FlagValueType)fl_0 == (FlagType::kDecimalFormat |
            FlagType::kSigned));

        assert(fl_0.IsSigned() == true);
        assert(fl_0.IsNegative() == false);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == true);
        assert(fl_0.Format() == FlagType::kDecimalFormat);
        
        FlagType fl_1(FlagType::kDecimalFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == false);

        assert((fl_0 += fl_1) == FlagType::kAdditionOp);
        assert((fl_0 -= fl_1) == FlagType::kSubtractionOp);
        assert((fl_0 *= fl_1) == FlagType::kMultiplicationOp);
        assert((fl_0 /= fl_1) == FlagType::kDivisionOp);
        assert((fl_0 %= fl_1) == FlagType::kModuloOp);
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == FlagType::kRShiftOp);
        assert((fl_0 <<= fl_1) == FlagType::kLShiftOp);
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == FlagType::kSubtractionOp);
        assert((fl_0 -= fl_1) == FlagType::kAdditionOp);

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == FlagType::kMultiplicationOp);
        assert(fl_0.IsNegative() == true);

        fl_0.UnsetNegative();
        assert(fl_0.IsNegative() == false);
        assert((fl_0 /= fl_1) == FlagType::kDivisionOp);
        assert(fl_0.IsNegative() == true);
        
        fl_0.UnsetNegative();
        assert((fl_0 %= fl_1) == FlagType::kModuloOp);

        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == FlagType::kRShiftOp);
        assert((fl_0 <<= fl_1) == FlagType::kLShiftOp);
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }
    {
        typedef test::integer::Flag FlagType;
        FlagType fl_0(FlagType::kDecimalFormat |
            FlagType::kSigned);
        typedef typename FlagType::ValueType FlagValueType;

        fl_0.SetNegative();
        
        assert((FlagValueType)fl_0 == (FlagType::kDecimalFormat |
            FlagType::kSigned | FlagType::kNegative));

        assert(fl_0.IsSigned() == true);
        assert(fl_0.IsNegative() == true);
        assert(fl_0.IsUndefinedFormat() == false);
        assert(fl_0.IsBinaryFormat() == false);
        assert(fl_0.IsOctalFormat() == false);
        assert(fl_0.IsDecimalFormat() == true);
        assert(fl_0.Format() == FlagType::kDecimalFormat);
        
        FlagType fl_1(FlagType::kDecimalFormat |
            FlagType::kSigned);
            
        assert(fl_0.IsNegative() == true);

        assert((fl_0 += fl_1) == FlagType::kSubtractionOp);
        assert((fl_0 -= fl_1) == FlagType::kAdditionOp);
        assert((fl_0 *= fl_1) == FlagType::kMultiplicationOp);
        assert((fl_0 /= fl_1) == FlagType::kDivisionOp);
        assert((fl_0 %= fl_1) == FlagType::kModuloOp);
        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == FlagType::kRShiftOp);
        assert((fl_0 <<= fl_1) == FlagType::kLShiftOp);
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
        assert((~fl_0) == 0);

        fl_1.SetNegative();
        assert(fl_1.IsNegative() == true);

        assert((fl_0 += fl_1) == FlagType::kAdditionOp);
        assert((fl_0 -= fl_1) == FlagType::kSubtractionOp);

        assert(fl_1.IsNegative() == true);
        assert((fl_0 *= fl_1) == FlagType::kMultiplicationOp);
        assert(fl_0.IsNegative() == false);

        fl_0.SetNegative();
        assert(fl_0.IsNegative() == true);
        assert((fl_0 /= fl_1) == FlagType::kDivisionOp);
        assert(fl_0.IsNegative() == false);
        
        fl_0.SetNegative();
        assert((fl_0 %= fl_1) == FlagType::kModuloOp);

        assert((fl_0 |= fl_1) == 0);
        assert((fl_0 &= fl_1) == 0);
        assert((fl_0 ^= fl_1) == 0);
        assert((fl_0 >>= fl_1) == FlagType::kRShiftOp);
        assert((fl_0 <<= fl_1) == FlagType::kLShiftOp);
        assert((fl_0 >>= 1) == FlagType::kRShiftOp);
        assert((fl_0 <<= 1) == FlagType::kLShiftOp);
    }

    return 0;
}
