#pragma once

#include <Furrovine++/rational.h>
#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/Graphics/SurfaceFormat.h>
#include <Furrovine++/Graphics/SurfaceScanlineOrder.h>
#include <Furrovine++/Graphics/MonitorScaling.h>

namespace Furrovine { namespace Graphics {

	struct DisplayModeDescription {
		uint32 Width;
		uint32 Height;
		rational<uint32> RefreshRate;
		SurfaceFormat Format;
		SurfaceScanlineOrder ScanlineOrder;
		MonitorScaling Scaling;
	};

}}