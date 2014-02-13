#pragma once

#include <Furrovine++/Platform.Graphics.h>
#ifdef FURROVINEDIRECTX
#include <Furrovine++/Graphics/Dx/Platform.Dx.h>
#endif // DIRECTX
#ifdef FURROVINEOPENGL
#include <Furrovine++/Graphics/Gl/Platform.Gl.h>
#endif // OPENGL