#ifndef TEST_FP_FORMAT_H_
#define TEST_FP_FORMAT_H_

#include "../Byte.h"
#include "../byte/off/Make.h"

#include <cstddef>
#include <cstdint>
#include <cmath>

namespace test
{
namespace fp
{

template<std::size_t NBit>
struct Format
{};

template<>
struct Format<32>
{
    static constexpr std::size_t size = 4;
    static constexpr std::size_t mantissa_index = 0;
    static constexpr std::size_t mantissa_size = 4;
    static constexpr std::size_t mantissa_bitoff = 0;
    static constexpr std::size_t mantissa_bitfield = 23;
    static constexpr std::size_t exponent_index = 2;
    static constexpr std::size_t exponent_size = 2;
    static constexpr std::size_t exponent_bitoff = 7;
    static constexpr std::size_t exponent_bitfield = 8;
    static constexpr std::size_t sign_index = 3;
    static constexpr std::size_t sign_size = 1;
    static constexpr std::size_t sign_bitoff = 7;
    static constexpr std::size_t sign_bitfield = 1;

    typedef test::Byte<size> FloatByteType;
    typedef test::Byte<sign_size> SignByteType;
    typedef test::Byte<exponent_size> ExponentByteType;
    typedef test::Byte<mantissa_size> MantissaByteType;

    typedef bool SignValueType;
    typedef std::int16_t ExponentValueType;
    typedef std::uint32_t MantissaValueType;
    typedef std::int32_t SignedIntegerType;
    typedef std::uint32_t UnsignedIntegerType;

    static FloatByteType Zero()
    {
        static const FloatByteType instance;
        return instance;
    }

    static SignByteType SignMask()
    {
        static const SignByteType instance{0x01};
        return instance;
    }
    static SignByteType SignMaskByte()
    {
        static const SignByteType instance{0x80};
        return instance;
    }

    static ExponentByteType ExponentMask()
    {
        static const ExponentByteType instance{0x00FF};
        return instance;
    }
    static ExponentByteType ExponentMaskByte()
    {
        static const ExponentByteType instance{0x7F80};
        return instance;
    }

    static MantissaByteType MantissaMask()
    {
        static const MantissaByteType instance{0x007FFFFF};
        return instance;
    }
    
    static MantissaByteType MantissaMaskByte()
    {
        static const MantissaByteType instance{0x007FFFFF};
        return instance;
    }

    static constexpr ExponentValueType ExponentBias()
    {
        return 0x007F;
    }

    static constexpr ExponentValueType ExponentMinimumValue()
    {
        return 0xFF82;
    }

    static constexpr ExponentValueType ExponentMaximumValue()
    {
        return 0x007F;
    }

    static constexpr MantissaValueType MantissaNormalMinimumValue()
    {
        return 0x00800000;
    }
    
    static constexpr MantissaValueType MantissaNormalMaximumValue()
    {
        return 0x00FFFFFF;
    }

    static constexpr MantissaValueType MantissaSubNormalMinimumValue()
    {
        return 0x00000000;
    }

    static constexpr MantissaValueType MantissaSubNormalMaximumValue()
    {
        return 0x007FFFFF;
    }
    static MantissaValueType MantissaFloatToInteger(const float& mant)
    {
        return std::floor(mant);
    }
};

template<>
struct Format<64>
{
    static constexpr std::size_t size = 8;
    static constexpr std::size_t mantissa_index = 0;
    static constexpr std::size_t mantissa_size = 7;
    static constexpr std::size_t mantissa_bitoff = 0;
    static constexpr std::size_t mantissa_bitfield = 52;
    static constexpr std::size_t exponent_index = 6;
    static constexpr std::size_t exponent_size = 2;
    static constexpr std::size_t exponent_bitoff = 4;
    static constexpr std::size_t exponent_bitfield = 11;
    static constexpr std::size_t sign_index = 7;
    static constexpr std::size_t sign_size = 1;
    static constexpr std::size_t sign_bitoff = 7;
    static constexpr std::size_t sign_bitfield = 1;

    typedef test::Byte<size> FloatByteType;
    typedef test::Byte<sign_size> SignByteType;
    typedef test::Byte<exponent_size> ExponentByteType;
    typedef test::Byte<mantissa_size> MantissaByteType;

    typedef bool SignValueType;
    typedef std::int16_t ExponentValueType;
    typedef std::uint64_t MantissaValueType;
    typedef std::int64_t SignedIntegerType;
    typedef std::uint64_t UnsignedIntegerType;
    
    static FloatByteType Zero()
    {
        static const FloatByteType instance;
        return instance;
    }

    static SignByteType SignMask()
    {
        static const SignByteType instance{0x01};
        return instance;
    }
    static SignByteType SignMaskByte()
    {
        static const SignByteType instance{0x80};
        return instance;
    }

    static ExponentByteType ExponentMask()
    {
        static const ExponentByteType instance{0x07FF};
        return instance;
    }
    static ExponentByteType ExponentMaskByte()
    {
        static const ExponentByteType instance{0x7FF0};
        return instance;
    }

    static MantissaByteType MantissaMask()
    {
        static const MantissaByteType instance{0x0FFFFFFFFFFFFF};
        return instance;
    }
    
    static MantissaByteType MantissaMaskByte()
    {
        static const MantissaByteType instance{0x0FFFFFFFFFFFFF};
        return instance;
    }

    static constexpr ExponentValueType ExponentBias()
    {
        return 0x03FF;
    }

    static constexpr ExponentValueType ExponentMinimumValue()
    {
        return 0xFC02;
    }

    static constexpr ExponentValueType ExponentMaximumValue()
    {
        return 0x03FF;
    }

    static constexpr MantissaValueType MantissaNormalMinimumValue()
    {
        return 0x10000000000000;
    }
    
    static constexpr MantissaValueType MantissaNormalMaximumValue()
    {
        return 0x1FFFFFFFFFFFFF;
    }

    static constexpr MantissaValueType MantissaSubNormalMinimumValue()
    {
        return 0x00000000000000;
    }

    static constexpr MantissaValueType MantissaSubNormalMaximumValue()
    {
        return 0x0FFFFFFFFFFFFF;
    }

    static MantissaValueType MantissaFloatToInteger(const double& mant)
    {
        return std::floor(mant);
    }
};

template<>
struct Format<80>
{
    static constexpr std::size_t size = 10;
    static constexpr std::size_t mantissa_index = 0;
    static constexpr std::size_t mantissa_size = 8;
    static constexpr std::size_t mantissa_bitoff = 0;
    static constexpr std::size_t mantissa_bitfield = 63;
    static constexpr std::size_t exponent_index = 8;
    static constexpr std::size_t exponent_size = 2;
    static constexpr std::size_t exponent_bitoff = 0;
    static constexpr std::size_t exponent_bitfield = 15;
    static constexpr std::size_t sign_index = 9;
    static constexpr std::size_t sign_size = 1;
    static constexpr std::size_t sign_bitoff = 7;
    static constexpr std::size_t sign_bitfield = 1;

    typedef test::Byte<size> FloatByteType;
    typedef test::Byte<sign_size> SignByteType;
    typedef test::Byte<exponent_size> ExponentByteType;
    typedef test::Byte<mantissa_size> MantissaByteType;

    typedef bool SignValueType;
    typedef std::int16_t ExponentValueType;
    typedef std::uint64_t MantissaValueType;
    typedef std::int64_t SignedIntegerType;
    typedef std::uint64_t UnsignedIntegerType;
    
    static FloatByteType Zero()
    {
        static const FloatByteType instance{};
        return instance;
    }

    static SignByteType SignMask()
    {
        static const SignByteType instance{0x01};
        return instance;
    }
    static SignByteType SignMaskByte()
    {
        static const SignByteType instance{0x80};
        return instance;
    }

    static ExponentByteType ExponentMask()
    {
        static const ExponentByteType instance{0x7FFF};
        return instance;
    }
    static ExponentByteType ExponentMaskByte()
    {
        static const ExponentByteType instance{0x7FFF};
        return instance;
    }

    static MantissaByteType MantissaMask()
    {
        static const MantissaByteType instance{0x7FFFFFFFFFFFFFFF};
        return instance;
    }
    
    static MantissaByteType MantissaMaskByte()
    {
        static const MantissaByteType instance{0xFFFFFFFFFFFFFFFF};
        return instance;
    }

    static constexpr ExponentValueType ExponentBias()
    {
        return 0x3FFF;
    }

    static constexpr ExponentValueType ExponentMinimumValue()
    {
        return 0xC002;
    }

    static constexpr ExponentValueType ExponentMaximumValue()
    {
        return 0x03FF;
    }

    static constexpr MantissaValueType MantissaNormalMinimumValue()
    {
        return 0x8000000000000000;
    }
    
    static constexpr MantissaValueType MantissaNormalMaximumValue()
    {
        return 0xFFFFFFFFFFFFFFFF;
    }

    static constexpr MantissaValueType MantissaSubNormalMinimumValue()
    {
        return 0x0000000000000000;
    }

    static constexpr MantissaValueType MantissaSubNormalMaximumValue()
    {
        return 0x7FFFFFFFFFFFFFFF;
    }

    static MantissaValueType MantissaFloatToInteger(const long double& mant)
    {
        return std::round(mant);
    }
};

} //!fp

} //!test

#endif //!TEST_FP_FORMAT_H_
