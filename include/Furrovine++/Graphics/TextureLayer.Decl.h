#pragma once

#include <Furrovine++/Rectangle.h>
#include <Furrovine++/Graphics/Texture2D.h>

namespace Furrovine { namespace Graphics {

	class TextureLayer {
	public:
		Texture* Layer;
		Rectangle Source;

		furrovineapi TextureLayer ();

		furrovineapi TextureLayer ( Texture2D* texture );

		furrovineapi TextureLayer ( Texture2D* texture, const Rectangle& source );

	};

}}
