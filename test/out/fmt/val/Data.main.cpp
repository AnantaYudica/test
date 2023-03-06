#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#define TEST_OUT_FMT_VAL_DATA_DLEVEL 0x7f

#include "test/out/fmt/val/Data.h"
#include "test/out/fmt/Status.h"

#include <cassert>
#include <cstdint>

typedef test::out::fmt::Status StatusType;
typedef test::out::fmt::val::Data<StatusType> DataType;

int main()
{
    {
        DataType dat1;
        assert(dat1.GetLock().try_lock() == true);
        dat1.GetLock().unlock();

        assert(dat1.GetStatus().IsGood() == false);
        assert(dat1.GetStatus().IsBad() == true);

        assert(dat1.GetLoadSize() == 0);

        assert(dat1.GetBlocks() == nullptr);

        assert(dat1.GetRaw() == nullptr);
    }
    {
        DataType dat1;
        
        dat1.GetLoadSize() = 10;

        dat1.GetBlocks() = DataType::BlocksType(test::ptr::arg::Array{2});

        dat1.GetRaw() = DataType::RawType(test::ptr::arg::Array{4});

        DataType dat2{dat1};

        assert(dat1.GetLock().try_lock() == true);
        
        assert(dat2.GetLock().try_lock() == false);

        dat2.GetLock().unlock();
        
        assert(dat2.GetLock().try_lock() == true);
        
        assert(dat1.GetLock().try_lock() == false);
        
        dat1.GetLock().unlock();

        assert(dat1.GetStatus().IsGood() == false);

        assert(dat1.GetStatus().IsBad() == true);
    
        assert(dat1.GetLoadSize() == 10);

        assert(dat2.GetBlocks() == dat1.GetBlocks());

        assert(dat2.GetRaw() == dat1.GetRaw());
        
        DataType dat3{std::move(dat2)};

        assert(dat1.GetLock().try_lock() == true);
        
        assert(dat3.GetLock().try_lock() == false);

        dat3.GetLock().unlock();
        
        assert(dat3.GetLock().try_lock() == true);
        
        assert(dat1.GetLock().try_lock() == false);
        
        dat1.GetLock().unlock();
        
        assert(dat2.GetLoadSize() == 0);

        assert(dat2.GetBlocks() == nullptr);

        assert(dat2.GetRaw() == nullptr);
        
        assert(dat3.GetLoadSize() == 10);

        assert(dat3.GetBlocks() == dat1.GetBlocks());

        assert(dat3.GetRaw() == dat1.GetRaw());
    }
    {
        DataType dat1;

        dat1.GetLoadSize() = 10;
        
        dat1.GetBlocks() = DataType::BlocksType(test::ptr::arg::Array{2});

        dat1.GetRaw() = DataType::RawType(test::ptr::arg::Array{4});

        DataType dat2;

        dat2 = dat1;

        assert(dat1.GetLock().try_lock() == true);
        
        assert(dat2.GetLock().try_lock() == false);

        dat2.GetLock().unlock();
        
        assert(dat2.GetLock().try_lock() == true);
        
        assert(dat1.GetLock().try_lock() == false);
        
        dat1.GetLock().unlock();

        assert(dat1.GetStatus().IsGood() == false);

        assert(dat1.GetStatus().IsBad() == true);

        assert(dat2.GetLoadSize() == 10);

        assert(dat2.GetBlocks() == dat1.GetBlocks());

        assert(dat2.GetRaw() == dat1.GetRaw());
        
        DataType dat3;
        dat3 = std::move(dat2);

        assert(dat1.GetLock().try_lock() == true);
        
        assert(dat3.GetLock().try_lock() == false);

        dat3.GetLock().unlock();
        
        assert(dat3.GetLock().try_lock() == true);
        
        assert(dat1.GetLock().try_lock() == false);
        
        dat1.GetLock().unlock();

        assert(dat2.GetLoadSize() == 0);

        assert(dat2.GetBlocks() == nullptr);

        assert(dat2.GetRaw() == nullptr);
        
        assert(dat3.GetLoadSize() == 10);

        assert(dat3.GetBlocks() == dat1.GetBlocks());

        assert(dat3.GetRaw() == dat1.GetRaw());
    }
    return 0;
}