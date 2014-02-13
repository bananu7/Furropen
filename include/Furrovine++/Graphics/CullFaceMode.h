#ifndef FURROVINECULLFACEMODE_H
#define FURROVINECULLFACEMODE_H

#include <Furrovine++/Graphics/CullMode.h>
#include <Furrovine++/Graphics/FrontFace.h>

namespace Furrovine { namespace Graphics {

	enum class CullFaceMode {
		CullNone = ((int32)CullMode::None) | ((int32)FrontFace::Clockwise << 16),
		CullCounterClockwise = ((int32)CullMode::Back) | ((int32)FrontFace::Clockwise << 16),
		CullClockwise = ((int32)CullMode::Back) | ((int32)FrontFace::CounterClockwise << 16),
		CullFrontCounterClockwise = ((int32)CullMode::Front) | ((int32)FrontFace::Clockwise << 16),
		CullFrontClockwise = ((int32)CullMode::Front) | ((int32)FrontFace::CounterClockwise << 16),
		CullBackCounterClockwise = ((int32)CullMode::Back) | ((int32)FrontFace::Clockwise << 16),
		CullBackClockwise = ((int32)CullMode::Back) | ((int32)FrontFace::CounterClockwise << 16),
	};

	static FrontFace ToFrontFace ( CullFaceMode mode ) {
		return (FrontFace)( ( (int32)mode & 0xFFFFFFFF00000000 ) >> 32 );
	}

	static CullMode ToCullMode ( CullFaceMode mode ) {
		return (CullMode)( (int32)mode & 0x00000000FFFFFFFF );
	}

	static CullFaceMode ToCullFaceMode ( CullMode cull, FrontFace frontface ) {
		return (CullFaceMode)( ((int32)cull) | ((int32)frontface << 16) );
	}

}}

#endif // FURROVINECULLFACEMODE_H 