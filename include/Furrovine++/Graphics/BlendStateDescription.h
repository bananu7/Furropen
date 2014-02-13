#pragma once

#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/Graphics/BlendFactor.h>
#include <Furrovine++/Graphics/BlendOperation.h>
#include <Furrovine++/Graphics/ColorWriteChannels.h>
#include <Furrovine++/Vector4.h>

namespace Furrovine { namespace Graphics {

	struct BlendStateDescription {
		bool blendenabled;
		BlendFactor sourcergbblendfactor;
		BlendFactor destinationrgbblendfactor;
		BlendOperation rgbblendop;
		BlendFactor sourceablendfactor;
		BlendFactor destinationablendfactor;
		BlendOperation ablendop;
		ColorWriteChannels writemask;
		Vector4 blendfactors;

		furrovineapi BlendStateDescription( );

		furrovineapi BlendStateDescription(
			BlendFactor asourcergbblendfactor,
			BlendFactor adestinationrgbblendfactor,
			BlendOperation argbblendop,
			BlendFactor asourceablendfactor,
			BlendFactor adestinationablendfactor,
			BlendOperation aablendop,
			ColorWriteChannels awritemask = ColorWriteChannels::All,
			bool ablendenabled = true,
			Vector4 blendfactors = Vector4::Zero );

		furrovineapi BlendStateDescription(
			BlendFactor asourceblendfactor,
			BlendFactor adestinationblendfactor,
			BlendOperation ablendop,
			ColorWriteChannels awritemask = ColorWriteChannels::All,
			bool ablendenabled = true,
			Vector4 blendfactors = Vector4::Zero );

		furrovineapi bool ManualBlend( ) const;

	};

}}