#pragma once

namespace Furrovine { namespace Graphics {
	
	enum class PrimitiveTopology {
		Points = 1,
		PointList = Points,
		Lines,
		LineList = Lines,
		LineStrip,
		Triangles,
		TriangleList = Triangles,
		TriangleStrip,
	};

}}
