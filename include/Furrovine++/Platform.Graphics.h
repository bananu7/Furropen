#pragma once
#include <Furrovine++/Platform.Conventions.h>

#ifdef FURROVINEDIRECTX
#include <Furrovine++/platform_d2d.h>
#include <Furrovine++/platform_d3d.h>
#endif // DIRECTX

#ifdef FURROVINEOPENGL
#include <Furrovine++/platform_gl.h>
#endif // OPENGL