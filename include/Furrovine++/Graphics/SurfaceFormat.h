#pragma once

#include <Furrovine++/FurrovineApi.h>

namespace Furrovine { namespace Graphics {
	
	enum class SurfaceFormat {
		Unknown,
		Red8Green8Blue8Alpha8NormalizedsRGB,
		Red8Green8Blue8Alpha8Normalized,
		Red8Green8Blue8Alpha8UInt32,
		Red8Green8Blue8Alpha8,
		Red8Green8Blue8NormalizedsRGB,
		Red8Green8Blue8Normalized,
		Red8Green8Blue8,
		Red32Green32Blue32Alpha32,
		Red16Green16Blue16Alpha16,
		Red32Green32Blue32,
		Red10Green10Blue10Alpha2Normalized,
		Red10Green10Blue10Alpha2UInt32,
		Red10Green10Blue10Alpha2,
		Blue8Green8Red8Alpha8NormalizedsRGB, 
		Blue8Green8Red8Alpha8Normalized, 
		Blue8Green8Red8Alpha8, 
		Blue5Green6Red5Alpha1Normalized,
		Blue5Green6Red5Normalized,
		Alpha8,
		Float,
		Red16Green16,
		Single,
		DXT1,
		DXT3,
		DXT5,
		DXT1Normalized,
		DXT3Normalized,
		DXT5Normalized,
		DXT1NormalizedsRGB,
		DXT3NormalizedsRGB,
		DXT5NormalizedsRGB,
		ATI1,
		ATI2,
		ATI1Normalized,
		ATI2Normalized,
		BlockCompression6HDR,
		BlockCompression7,
		Vector3 = Red32Green32Blue32,
		Vector4 = Red32Green32Blue32Alpha32,
		HalfVector4 = Red16Green16Blue16Alpha16,
		HalfVector2 = Red16Green16,
		FloatColor =  Red32Green32Blue32Alpha32,
		ByteColor = Red8Green8Blue8Alpha8Normalized,
#ifdef FURROVINEFLOATCOLOR
		Color = FloatColor,
#else
		Color = ByteColor,
#endif
		Rgb = Red8Green8Blue8Normalized,
		Rgba = Red8Green8Blue8Alpha8Normalized,
		sRgb = Red8Green8Blue8NormalizedsRGB,
		sRgba = Red8Green8Blue8Alpha8NormalizedsRGB,
	};

	inline furrovineapi ulword ToByteSize ( SurfaceFormat format ) {
		ulword bytesize = 0;
		switch (format) {
		case SurfaceFormat::Blue5Green6Red5Normalized:
			bytesize = 2;
			break;
		case SurfaceFormat::Red10Green10Blue10Alpha2UInt32:
		case SurfaceFormat::Red8Green8Blue8Alpha8UInt32:
		case SurfaceFormat::Blue8Green8Red8Alpha8Normalized:
		case SurfaceFormat::Red8Green8Blue8Alpha8NormalizedsRGB:
		case SurfaceFormat::Blue8Green8Red8Alpha8NormalizedsRGB:
		case SurfaceFormat::Red8Green8Blue8Alpha8Normalized:
		case SurfaceFormat::Red8Green8Blue8Alpha8:
			bytesize = 4;
			break;
		case SurfaceFormat::Red8Green8Blue8:
		case SurfaceFormat::Red8Green8Blue8NormalizedsRGB:
		case SurfaceFormat::Red8Green8Blue8Normalized:
		case SurfaceFormat::Blue5Green6Red5Alpha1Normalized:
			bytesize = 3;
			break;
		case SurfaceFormat::Red16Green16Blue16Alpha16:
		case SurfaceFormat::ATI1:
		case SurfaceFormat::DXT1Normalized:
		case SurfaceFormat::DXT1NormalizedsRGB:
		case SurfaceFormat::DXT1:
			bytesize = 8;
			break;
		case SurfaceFormat::Red32Green32Blue32:
			bytesize = 16;
			break;
		case SurfaceFormat::Red32Green32Blue32Alpha32:
		case SurfaceFormat::ATI2:
		case SurfaceFormat::DXT3:
		case SurfaceFormat::DXT5:
		case SurfaceFormat::DXT3Normalized:
		case SurfaceFormat::DXT3NormalizedsRGB:
		case SurfaceFormat::DXT5NormalizedsRGB:
		case SurfaceFormat::DXT5Normalized:
		case SurfaceFormat::BlockCompression6HDR:
		case SurfaceFormat::BlockCompression7:
			bytesize = 16;
			break;
		default:

			break;
		}
		return bytesize;
	}

}}
