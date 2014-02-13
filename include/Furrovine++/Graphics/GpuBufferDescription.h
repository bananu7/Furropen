#pragma once

#include <Furrovine++/Graphics/ResourceMapping.h>
#include <Furrovine++/Graphics/ResourceOptionFlags.h>
#include <Furrovine++/Graphics/BindFlags.h>
#include <Furrovine++/Graphics/IndexElementFormat.h>
#include <Furrovine++/Graphics/IndexElementSize.h>
#include <Furrovine++/Graphics/CpuAccessFlags.h>
#include <Furrovine++/Graphics/ResourceUsage.h>
#include <Furrovine++/Graphics/GraphicsResource.h>

namespace Furrovine { namespace Graphics {

	struct GpuBufferDescription {
	public:
		uint32 bytewidth;
		ResourceUsage usage;
		BindFlags bindflags;
		CpuAccessFlags accessflags;
		ResourceOptionFlags optionflags;
		uint32 structurebytestride;
	};

}}
