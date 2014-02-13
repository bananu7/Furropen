#pragma once

#include <Furrovine++/handle.h>
#include <Furrovine++/Graphics/graphics_handle.h>
#include <Furrovine++/Graphics/ShaderParameter.h>
#include <Furrovine++/Graphics/ShaderResourceDescription.h>

namespace Furrovine { namespace Graphics {

	class ShaderResourceBuffer : public ShaderParameter {
	private:
		ShaderResourceDescription resourcedesc;
		struct deleter {
			furrovineapi void operator ()( graphics_handle p );
		};
		handle<graphics_handle, deleter> resourcebufferreflection;

	public:
		
		furrovineapi ShaderResourceBuffer( GraphicsDevice& graphicsdevice, ShaderStage stage, ulword bufferindex, graphics_handle bufferrefl );
		furrovineapi ShaderResourceBuffer( ShaderResourceBuffer&& mov );
		furrovineapi ShaderResourceBuffer& operator=( ShaderResourceBuffer&& mov );

		furrovineapi const ShaderResourceDescription& Description( ) const;
		furrovineapi virtual const String& Name( ) const override;

		furrovineapi graphics_handle ResourceBufferReflectionResource( ) const;

	};

}}
