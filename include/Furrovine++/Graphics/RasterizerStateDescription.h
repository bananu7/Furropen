#pragma once

#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/Graphics/FillMode.h>
#include <Furrovine++/Graphics/CullMode.h>
#include <Furrovine++/Graphics/FrontFace.h>

namespace Furrovine { namespace Graphics {

	struct RasterizerStateDescription {
		FillMode fillmode;
		CullMode cullmode;
		FrontFace frontface;
		int depthbias;
		float depthbiasclamp;
		float slopescaleddepthbias;
		bool depthclipenabled;
		bool scissorenabled;
		bool multisampleenabled;
		bool antialiasedlineenabled;

		furrovineapi RasterizerStateDescription( FillMode fill = FillMode::Solid,
			CullMode cull = CullMode::None,
#ifdef FURROVINECOORDINATESYSTEMLEFTHANDED
			FrontFace front = FrontFace::CounterClockwise,
#else
			FrontFace front = FrontFace::Clockwise,
#endif // COORDINATESYSTEMLEFTHANDED || COORDINATESYSTEMRIGHTHANDED
			int depthvaluebias = 0, float depthvaluebiasclamp = 0.0f, float slopescaleddepthvaluebias = 0.0f,
			bool enabledepthclipping = true, bool enablescissoring = false,
			bool enablemultisampling = false, bool enableantialiasedlines = false );

	};

}}