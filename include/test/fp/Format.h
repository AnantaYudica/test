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
    typedef std::int8_t ExponentValueType;
    typedef std::int16_t ExponentExpandValueType;
    typedef test::Byte<mantissa_size> MantissaValueType;
    typedef std::int32_t SignedIntegerType;
    typedef std::uint32_t UnsignedIntegerType;

    static FloatByteType Zero()
    {
        return {};
    }

    static SignByteType SignMask()
    {
        return {0x01};
    }
    static SignByteType SignMaskByte()
    {
        return {0x80};
    }

    static ExponentByteType ExponentMask()
    {
        return {0x00FF};
    }
    static ExponentByteType ExponentMaskByte()
    {
        return {0x7F80};
    }

    static MantissaByteType MantissaMask()
    {
        return {0x007FFFFF};
    }
    
    static MantissaByteType MantissaMaskByte()
    {
        return {0x007FFFFF};
    }

    static ExponentByteType ExponentBias()
    {
        return {0x007F};
    }

    static ExponentByteType ExponentMinimumValue()
    {
        return {0x0FF82};
    }

    static ExponentByteType ExponentMaximumValue()
    {
        return {0x007F};
    }

    static MantissaByteType MantissaNormalMinimumValue()
    {
        return {0x00800000};
    }
    
    static MantissaByteType MantissaNormalMaximumValue()
    {
        return {0x00FFFFFF};
    }

    static MantissaByteType MantissaSubNormalMinimumValue()
    {
        return {0x00000000};
    }

    static MantissaByteType MantissaSubNormalMaximumValue()
    {
        return {0x007FFFFF};
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
    typedef std::int16_t ExponentExpandValueType;
    typedef test::Byte<mantissa_size> MantissaValueType;
    typedef std::int64_t SignedIntegerType;
    typedef std::uint64_t UnsignedIntegerType;
    
    static FloatByteType Zero()
    {
        return {};
    }

    static SignByteType SignMask()
    {
        return {0x01};
    }
    static SignByteType SignMaskByte()
    {
        return {0x80};
    }

    static ExponentByteType ExponentMask()
    {
        return {0x07FF};
    }
    static ExponentByteType ExponentMaskByte()
    {
        return {0x7FF0};
    }

    static MantissaByteType MantissaMask()
    {
        return {0x0FFFFFFFFFFFFF};
    }
    
    static MantissaByteType MantissaMaskByte()
    {
        return {0x0FFFFFFFFFFFFF};
    }

    static ExponentByteType ExponentBias()
    {
        return {0x03FF};
    }

    static ExponentByteType ExponentMinimumValue()
    {
        return {0xFC02};
    }

    static ExponentByteType ExponentMaximumValue()
    {
        return {0x03FF};
    }

    static MantissaByteType MantissaNormalMinimumValue()
    {
        return {0x10000000000000};
    }
    
    static MantissaByteType MantissaNormalMaximumValue()
    {
        return {0x1FFFFFFFFFFFFF};
    }

    static MantissaByteType MantissaSubNormalMinimumValue()
    {
        return {0x00000000000000};
    }

    static MantissaByteType MantissaSubNormalMaximumValue()
    {
        return {0x0FFFFFFFFFFFFF};
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
    typedef std::int16_t ExponentExpandValueType;
    typedef test::Byte<mantissa_size> MantissaValueType;
    typedef std::int64_t SignedIntegerType;
    typedef std::uint64_t UnsignedIntegerType;
    
    static FloatByteType Zero()
    {
        return {};
    }

    static SignByteType SignMask()
    {
        return {0x01};
    }
    static SignByteType SignMaskByte()
    {
        return {0x80};
    }

    static ExponentByteType ExponentMask()
    {
        return {0x7FFF};
    }
    static ExponentByteType ExponentMaskByte()
    {
        return {0x7FFF};
    }

    static MantissaByteType MantissaMask()
    {
        return {0x7FFFFFFFFFFFFFFF};
    }
    
    static MantissaByteType MantissaMaskByte()
    {
        return {0xFFFFFFFFFFFFFFFF};
    }

    static ExponentByteType ExponentBias()
    {
        return {0x3FFF};
    }

    static ExponentByteType ExponentMinimumValue()
    {
        return {0xC002};
    }

    static ExponentByteType ExponentMaximumValue()
    {
        return {0x03FF};
    }

    static MantissaByteType MantissaNormalMinimumValue()
    {
        return {0x8000000000000000};
    }
    
    static MantissaByteType MantissaNormalMaximumValue()
    {
        return {0xFFFFFFFFFFFFFFFF};
    }

    static MantissaByteType MantissaSubNormalMinimumValue()
    {
        return {0x0000000000000000};
    }

    static MantissaByteType MantissaSubNormalMaximumValue()
    {
        return {0x7FFFFFFFFFFFFFFF};
    }
};

} //!fp

} //!test

#endif //!TEST_FP_FORMAT_H_
