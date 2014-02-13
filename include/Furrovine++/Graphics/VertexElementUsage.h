#pragma once

#include <Furrovine++/Strings.h>
#include <Furrovine++/FurrovineApi.h>

namespace Furrovine { namespace Graphics {

	enum class VertexElementUsage {
		SVPosition,
		LegacyPosition,
		TransformedPosition,
		TextureCoordinate,
		PixelPosition,
		Color,
		Normal,
		Binormal,
		Tangent,
		SVOutputTarget,
		PointSize,
		SVDepth,
		Depth,
		Fog,
		BlendWeights,
		BlendIndices,
		BackfaceValue,
		TesselationFactor,
		Any,
		Position = SVPosition,
	};

	furrovineapi const String& ToSemantic ( VertexElementUsage usage );

	furrovineapi VertexElementUsage ToUsage ( const String& semantic );

	furrovineapi VertexElementUsage ToUsage ( const char* semantic );

}}
