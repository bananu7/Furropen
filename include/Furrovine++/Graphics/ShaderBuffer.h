#pragma once

#include <Furrovine++/ptr.h>
#include <Furrovine++/Graphics/GpuBuffer.h>
#include <Furrovine++/Graphics/ShaderBufferDescription.h>
#include <Furrovine++/Graphics/ShaderStage.h>

namespace Furrovine { namespace Graphics {

	class ShaderBuffer : public GpuBuffer {
	protected:
		struct deleter {
			ShaderBuffer* buffer;

			furrovineapi deleter( ShaderBuffer& shaderbuffer );
			furrovineapi deleter( const deleter& copy ) = default;
			furrovineapi deleter& operator=( const deleter& copy ) = default;
			furrovineapi deleter( deleter&& mov );
			furrovineapi deleter& operator=( deleter&& copy );

			furrovineapi void operator ()( graphics_handle p );
		};

		handle<graphics_handle, deleter> bufferreflection;
		ShaderStage shaderstage;
		ulword bufferindex;
		
	public:
		furrovineapi ShaderBuffer( GraphicsDevice& graphics, ShaderStage shaderstage, ulword bufferindex, void* bufferresource );
		furrovineapi ShaderBuffer( ShaderBuffer&& mov );
		furrovineapi ShaderBuffer& operator=( ShaderBuffer&& mov );

		furrovineapi graphics_handle ReflectionResource( ) const;

	};

}}