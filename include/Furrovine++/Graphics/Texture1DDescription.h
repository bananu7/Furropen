#pragma once

#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/Graphics/SurfaceFormat.h>
#include <Furrovine++/Graphics/DepthStencilFormat.h>
#include <Furrovine++/Graphics/ResourceOptionFlags.h>
#include <Furrovine++/Graphics/ResourceMapping.h>
#include <Furrovine++/Graphics/ResourceUsage.h>
#include <Furrovine++/Graphics/BindFlags.h>
#include <Furrovine++/Graphics/CpuAccessFlags.h>

namespace Furrovine { namespace Graphics {

	struct Texture1DDescription {
		uint width;
		uint miplevels;
		uint arraysize;
		SurfaceFormat surfaceformat;
		ResourceUsage usage;
		BindFlags binding;
		CpuAccessFlags access;
		ResourceOptionFlags misc;
	};

}}