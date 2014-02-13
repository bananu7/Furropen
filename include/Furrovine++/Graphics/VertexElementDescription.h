#pragma once

#include <Furrovine++/Graphics/VertexElementFormat.h>
#include <Furrovine++/Graphics/VertexElementUsage.h>
#include <Furrovine++/Graphics/VertexElementComponent.h>

namespace Furrovine { namespace Graphics {

	struct VertexElementDescription {
		VertexElementFormat Format;
		VertexElementUsage Usage;
		VertexElementComponent Component;
		uint UsageIndex;
		uint Offset;
		uint Count;
		bool Normalize;

		VertexElementDescription ()
		: Format( VertexElementFormat::Any ), 
		Usage( VertexElementUsage::Any), 
		Component( VertexElementComponent::Unknown ), 
		UsageIndex(-1), Offset(0), Count(0), Normalize(false) {

		}
    };

}}
 