#pragma once

#include <Furrovine++/Platform.Conventions.h>
#include <Furrovine++/Platform.OS.h>

namespace Furrovine {

#ifdef FURROVINEDIRECTX

	const double normalizedevicecoordinatesrange = 1.0;
	const double normalizedevicecoordinatesstart = 0;

#endif // DIRECTX

#ifdef FURROVINEOPENGL

	const double normalizedevicecoordinatesrange = 2.0;
	const double normalizedevicecoordinatesstart = -1.0;

#endif // FURROVINEOPENGL

}
