#pragma once

#include <Furrovine++/Platform.Conventions.h>

#ifdef FURROVINEOPENGL
#include <Furrovine++/platform_gl.api.h>
#endif // OPENGL

namespace Furrovine {

#ifdef FURROVINEOPENGL
	typedef GLuint glresultcode;
#endif // FURROVINEOPENGL

}