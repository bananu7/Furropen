#pragma once

#include <Furrovine++/Strings.h>
#include <Furrovine++/Rectangle.h>
#include <Furrovine++/Graphics/MonitorRotation.h>

namespace Furrovine { namespace Graphics {

	struct AdapterOutputDescription {
		String DeviceName;
		Rectangle DesktopCoordinates;
		bool AttachedToDesktop;
		MonitorRotation Rotation;
		void* Monitor;
	};

}}