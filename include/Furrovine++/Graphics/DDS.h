#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Graphics {

	enum class DDSSurfaceFormat {
		UNKNOWN = 0,
		R32G32B32A32_TYPELESS = 1,
		R32G32B32A32_FLOAT = 2,
		R32G32B32A32_UINT = 3,
		R32G32B32A32_SINT = 4,
		R32G32B32_TYPELESS = 5,
		R32G32B32_FLOAT = 6,
		R32G32B32_UINT = 7,
		R32G32B32_SINT = 8,
		R16G16B16A16_TYPELESS = 9,
		R16G16B16A16_FLOAT = 10,
		R16G16B16A16_UNORM = 11,
		R16G16B16A16_UINT = 12,
		R16G16B16A16_SNORM = 13,
		R16G16B16A16_SINT = 14,
		R32G32_TYPELESS = 15,
		R32G32_FLOAT = 16,
		R32G32_UINT = 17,
		R32G32_SINT = 18,
		R32G8X24_TYPELESS = 19,
		D32_FLOAT_S8X24_UINT = 20,
		R32_FLOAT_X8X24_TYPELESS = 21,
		X32_TYPELESS_G8X24_UINT = 22,
		R10G10B10A2_TYPELESS = 23,
		R10G10B10A2_UNORM = 24,
		R10G10B10A2_UINT = 25,
		R11G11B10_FLOAT = 26,
		R8G8B8A8_TYPELESS = 27,
		R8G8B8A8_UNORM = 28,
		R8G8B8A8_UNORM_SRGB = 29,
		R8G8B8A8_UINT = 30,
		R8G8B8A8_SNORM = 31,
		R8G8B8A8_SINT = 32,
		R16G16_TYPELESS = 33,
		R16G16_FLOAT = 34,
		R16G16_UNORM = 35,
		R16G16_UINT = 36,
		R16G16_SNORM = 37,
		R16G16_SINT = 38,
		R32_TYPELESS = 39,
		D32_FLOAT = 40,
		R32_FLOAT = 41,
		R32_UINT = 42,
		R32_SINT = 43,
		R24G8_TYPELESS = 44,
		D24_UNORM_S8_UINT = 45,
		R24_UNORM_X8_TYPELESS = 46,
		X24_TYPELESS_G8_UINT = 47,
		R8G8_TYPELESS = 48,
		R8G8_UNORM = 49,
		R8G8_UINT = 50,
		R8G8_SNORM = 51,
		R8G8_SINT = 52,
		R16_TYPELESS = 53,
		R16_FLOAT = 54,
		D16_UNORM = 55,
		R16_UNORM = 56,
		R16_UINT = 57,
		R16_SNORM = 58,
		R16_SINT = 59,
		R8_TYPELESS = 60,
		R8_UNORM = 61,
		R8_UINT = 62,
		R8_SNORM = 63,
		R8_SINT = 64,
		A8_UNORM = 65,
		R1_UNORM = 66,
		R9G9B9E5_SHAREDEXP = 67,
		R8G8_B8G8_UNORM = 68,
		G8R8_G8B8_UNORM = 69,
		BC1_TYPELESS = 70,
		BC1_UNORM = 71,
		BC1_UNORM_SRGB = 72,
		BC2_TYPELESS = 73,
		BC2_UNORM = 74,
		BC2_UNORM_SRGB = 75,
		BC3_TYPELESS = 76,
		BC3_UNORM = 77,
		BC3_UNORM_SRGB = 78,
		BC4_TYPELESS = 79,
		BC4_UNORM = 80,
		BC4_SNORM = 81,
		BC5_TYPELESS = 82,
		BC5_UNORM = 83,
		BC5_SNORM = 84,
		B5G6R5_UNORM = 85,
		B5G5R5A1_UNORM = 86,
		B8G8R8A8_UNORM = 87,
		B8G8R8X8_UNORM = 88,
		R10G10B10_XR_BIAS_A2_UNORM = 89,
		B8G8R8A8_TYPELESS = 90,
		B8G8R8A8_UNORM_SRGB = 91,
		B8G8R8X8_TYPELESS = 92,
		B8G8R8X8_UNORM_SRGB = 93,
		BC6H_TYPELESS = 94,
		BC6H_UF16 = 95,
		BC6H_SF16 = 96,
		BC7_TYPELESS = 97,
		BC7_UNORM = 98,
		BC7_UNORM_SRGB = 99,
		AYUV = 100,
		Y410 = 101,
		Y416 = 102,
		NV12 = 103,
		P010 = 104,
		P016 = 105,
		OPAQUE_420 = 106,
		YUY2 = 107,
		Y210 = 108,
		Y216 = 109,
		NV11 = 110,
		AI44 = 111,
		IA44 = 112,
		P8 = 113,
		A8P8 = 114,
		B4G4R4A4_UNORM = 115,
	};

	enum class DDSFlags : uint {
		None = 0x0,
		Caps = 0x01,
		Height = 0x02,
		Width = 0x04,
		Pitch = 0x08,
		PixelFormat = 0x1000,
		MipMapped = 0x20000,
		LinearSize = 0x80000,
		Depth = 0x800000
	};

	enum class DDSPixelFormatFlags : uint {
		None = 0x0,
		Alpha = 0x01,
		CompressionCoded = 0x04,
		RGB = 0x40,
		YUV = 0x200,
		Luminance = 0x20000,
	};

	enum class DDSCapabilitiesFlags0 : uint {
		None = 0x0,
		Complex = 0x8,
		Texture = 0x1000,
		MipMapped = 0x400000,
	};

	enum class DDSCapabilitiesFlags1 : uint {
		None = 0x0,
		Cubemap = 0x200,
		CubemapPositiveX = 0x400,
		CubemapNegativeX = 0x800,
		CubemapPositiveY = 0x1000,
		CubemapNegativeY = 0x2000,
		CubemapPositiveZ = 0x4000,
		CubemapNegativeZ = 0x8000,
		Volume = 0x200000,
	};

	enum class DDSCapabilitiesFlags2 : uint {
		None = 0x0,
	};

	enum class DDSCapabilitiesFlags3 : uint {
		None = 0x0,
	};


	enum class DDSResourceFlags {
		None = 0x0,
		CubeMapped = 0x04,
	};

	enum class DDSCompressionCode {
		Uncompressed = 0,
		DXT1 = 0x31545844,
		DXT2 = 0x32545844,
		DXT3 = 0x33545844,
		DXT4 = 0x34545844,
		DXT5 = 0x35545844,
		DX10 = 0x30315844,
	};

	enum class DDSResourceDimension {
		Unknown = 0,
		Buffer = 1,
		Texture1D = 2,
		Texture2D = 3,
		Texture3D = 4
	};

	enumflagoperators( DDSFlags );
	enumflagoperators( DDSPixelFormatFlags );
	enumflagoperators( DDSCapabilitiesFlags0 );
	enumflagoperators( DDSCapabilitiesFlags1 );
	enumflagoperators( DDSCapabilitiesFlags2 );
	enumflagoperators( DDSCapabilitiesFlags3 );
	enumflagoperators( DDSResourceFlags );

	struct DDSFormat {
		uint Size;
		DDSPixelFormatFlags Flags;
		DDSCompressionCode CompressionCode;
		uint BitsPerPixel,
			RYMask, GUMask, BVMask, AMask;
	};

	struct DX10DDSHeader {
		DDSSurfaceFormat DxgiFormat;
		DDSResourceDimension ResourceDimensions;
		uint Count;
		DDSResourceFlags Flags;
		uint Reserved;
	};

	struct DDSHeader {
		furrovineapi static const uint DDSMagic = cc4( 'D', 'D', 'S', ' ' );
		uint Magic;
		uint Size, Flags, Height, Width, PitchOrLinearSize, Depth, MipMapCount;
		uint Reservation0, Reservation1, Reservation2,
			Reservation3, Reservation4, Reservation5, Reservation6,
			Reservation7, Reservation8, Reservation9, Reservation10;
		DDSFormat Format;
		DDSCapabilitiesFlags0 Capabilities0;
		DDSCapabilitiesFlags1 Capabilities1;
		DDSCapabilitiesFlags2 Capabilities2;
		DDSCapabilitiesFlags3 Capabilities3;
		uint Reservation11;
		DX10DDSHeader DX10Header;
	};

}}