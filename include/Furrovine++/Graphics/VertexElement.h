#pragma once

#include <Furrovine++/Strings.h>
#include <Furrovine++/Graphics/VertexElementComponent.h>
#include <Furrovine++/Graphics/VertexElementFormat.h>
#include <Furrovine++/Graphics/VertexElementUsage.h>
#include <Furrovine++/Graphics/VertexElementDescription.h>
#include <Furrovine++/Graphics/VertexDataUsage.h>

namespace Furrovine { namespace Graphics {

	struct VertexElement {
	public:
		VertexElementFormat format;
		VertexElementComponent component;
		VertexElementUsage usage;
		String usagename;
		uint32 componentcount;
		uint32 usageindex;
		uint32 inputslot;
		uint32 offset;
		VertexDataUsage datausage;
		uint32 instancestep;
		bool normalize;

		furrovineapi VertexElement (uint Offset = 0, VertexElementFormat Format = VertexElementFormat::Vector3, VertexElementUsage Usage = VertexElementUsage::Position, uint UsageIndex = 0, bool Normalize = false, uint vertexbufferslot = 0);

		furrovineapi VertexElement (VertexElementFormat Format, VertexElementUsage Usage, uint UsageIndex = 0, bool Normalize = false, uint vertexbufferslot = 0);

		furrovineapi ulword Size( ) const;

		furrovineapi bool operator== (const VertexElement& right) const;

	};
}}
