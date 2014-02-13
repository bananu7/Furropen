#pragma once

#include <Furrovine++/std_defines.h>
#include <vector>
#include <unordered_map>
#include <Furrovine++/Graphics/ShaderResource.h>
#include <Furrovine++/Graphics/ShaderVariable.h>
#include <Furrovine++/Graphics/ShaderResourceBuffer.h>
#include <Furrovine++/Graphics/ShaderVariableBuffer.h>

namespace Furrovine { namespace Graphics {

	class ShaderParameterCollection {
	protected:
		friend class ShaderParameter;
		furrovineapi static const String DefaultBufferName;
		std::unordered_map<String, ulword> parameterindices;
		std::unordered_map<String, ulword> resourcebufferindices;
		std::unordered_map<String, ulword> resourceindices;
		std::unordered_map<String, ulword> variablebufferindices;
		std::vector<ShaderResourceBuffer> resourcebuffers;
		std::vector<ShaderResource> resources;
		std::vector<ShaderVariableBuffer> variablebuffers;
		std::vector<ShaderParameter*> parameters;

	public:
		furrovineapi ShaderParameterCollection( );
		furrovineapi ShaderParameterCollection( GraphicsDevice& graphicsdevice, ShaderStage method,
			graphics_handle shaderreflection, const ShaderParameterOptions& options = ShaderParameterOptions::Default );
		furrovineapi ShaderParameterCollection( ShaderParameterCollection&& mov );
		furrovineapi ShaderParameterCollection& operator=( ShaderParameterCollection&& mov );

		furrovineapi ulword VariableBufferCount( ) const;

		furrovineapi ulword ResourceBufferCount( ) const;

		furrovineapi ulword ResourceCount( ) const;

		furrovineapi ulword ParameterCount( ) const;

		furrovineapi void Apply( );

		/*furrovineapi bool TryGetVariableBufferAt( ulword index, ShaderVariableBuffer*& constantbuffer );
		furrovineapi bool TryGetVariableBufferByName( const String& name, ShaderVariableBuffer*& constantbuffer );
		furrovineapi ShaderVariableBuffer& VariableBufferAt( ulword index );
		furrovineapi ShaderVariableBuffer& VariableBufferByName( const String& name );

		furrovineapi bool TryGetResourceBufferAt( ulword index, ShaderResourceBuffer*& constantbuffer );
		furrovineapi bool TryGetResourceBufferByName( const String& name, ShaderResourceBuffer*& constantbuffer );
		furrovineapi ShaderResourceBuffer& ResourceBufferAt( ulword index );
		furrovineapi ShaderResourceBuffer& ResourceBufferByName( const String& name );

		furrovineapi bool TryGetResourceAt( ulword index, ShaderResourceBuffer*& constantbuffer );
		furrovineapi bool TryGetResourceByName( const String& name, ShaderResourceBuffer*& constantbuffer );
		furrovineapi ShaderResourceBuffer& ResourceAt( ulword index );
		furrovineapi ShaderResourceBuffer& ResourceByName( const String& name );
		*/

		furrovineapi bool TryGetParameterAt( ulword index, ShaderParameter*& parameter );
		furrovineapi bool TryGetParameterByName( const String& name, ShaderParameter*& parameter );
		furrovineapi ShaderParameter& ParameterAt( ulword index );
		furrovineapi ShaderParameter& ParameterByName( const String& name );
		furrovineapi ShaderParameter& operator[] ( ulword index );
		furrovineapi ShaderParameter& operator[] ( const String& name );
		
		furrovineapi bool ContainsParameter( const String& parametername ) const;
		furrovineapi bool ContainsResourceBuffer( const String& buffername ) const;
		furrovineapi bool ContainsResources( const String& buffername ) const;
		furrovineapi bool ContainsVariableBuffer( const String& buffername ) const;

	};

}}
