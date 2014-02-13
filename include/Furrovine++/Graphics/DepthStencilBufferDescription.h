#pragma once

#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/Graphics/SurfaceFormat.h>
#include <Furrovine++/Graphics/DepthStencilFormat.h>
#include <Furrovine++/Graphics/ResourceOptionFlags.h>
#include <Furrovine++/Graphics/ResourceMapping.h>
#include <Furrovine++/Graphics/ResourceUsage.h>
#include <Furrovine++/Graphics/BindFlags.h>
#include <Furrovine++/Graphics/CpuAccessFlags.h>
#include <Furrovine++/Graphics/DepthStencilViewFlags.h>
#include <Furrovine++/Graphics/MultisampleDescription.h>

namespace Furrovine { namespace Graphics {

	struct DepthStencilBufferDescription {
		uint width;
		uint height;
		uint miplevels;
		uint arraysize;
		DepthStencilFormat depthstencilformat;
		MultisampleDescription sample;
		ResourceUsage usage;
		BindFlags binding;
		CpuAccessFlags access;
		ResourceOptionFlags misc;
		DepthStencilViewFlags depthstencilviewflags;
	};

}}