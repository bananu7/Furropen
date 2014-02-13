#pragma once

#include <Furrovine++/Platform.Conventions.h>
#include <Furrovine++/FloatColor.h>
#include <Furrovine++/ByteColor.h>
#include <Furrovine++/HalfColor.h>
#include <Furrovine++/HSLColor.h>
#include <Furrovine++/Vector4.h>

namespace Furrovine {

#ifdef FURROVINEFLOATCOLOR
	typedef FloatColor Color;
#elif FURROVINEBYTECOLOR
	typedef ByteColor Color;
#endif // BYTECOLOR || FLOATCOLOR

	template <typename T>
	Vector4 ToShader( const RRgba<T>& color ) {
		typedef typename Vector4::value_type Tv;
		return Vector4( 
			color_normalize<Tv>( color.r ),
			color_normalize<Tv>( color.g ),
			color_normalize<Tv>( color.b ),
			color_normalize<Tv>( color.a )
		);
	}

	template <typename T>
	Color FromShader( const RVector4<T>& shadercolor ) {
		return Color(
			color_normalize<T>( shadercolor.r ),
			color_normalize<T>( shadercolor.g ),
			color_normalize<T>( shadercolor.b ),
			color_normalize<T>( shadercolor.a )
		);
	}

}
