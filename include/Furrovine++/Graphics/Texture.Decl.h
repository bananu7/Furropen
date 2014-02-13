#pragma once

#include <Furrovine++/Graphics/ShaderResourceView.h>

namespace Furrovine { namespace Graphics {

	class Texture : public ShaderResourceView {
	public:
		furrovineapi Texture( );
		furrovineapi Texture( GraphicsDevice& device );
		furrovineapi Texture ( Texture&& mov );
		furrovineapi Texture& operator= ( Texture&& mov );

		furrovineapi ~Texture ();

	};

}}
