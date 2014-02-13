#pragma once

#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/Graphics/SurfaceFormat.h>
#include <Furrovine++/Graphics/DepthStencilFormat.h>
#include <Furrovine++/Graphics/ResourceOptionFlags.h>
#include <Furrovine++/Graphics/ResourceMapping.h>
#include <Furrovine++/Graphics/ResourceUsage.h>
#include <Furrovine++/Graphics/BindFlags.h>
#include <Furrovine++/Graphics/CpuAccessFlags.h>
#include <Furrovine++/Graphics/MultisampleDescription.h>
#include <Furrovine++/Graphics/DepthStencilViewFlags.h>

namespace Furrovine { namespace Graphics {

	struct RenderBuffer2DDescription {
		uint width;
		uint height;
		uint miplevels;
		uint arraysize;
		SurfaceFormat surfaceformat;
		BindFlags binding;
		MultisampleDescription sample;
		ResourceUsage usage;
		CpuAccessFlags access;
		ResourceOptionFlags misc;	
	};

}}