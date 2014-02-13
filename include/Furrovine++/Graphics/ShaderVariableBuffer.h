#pragma once

#include <Furrovine++/Graphics/ShaderBuffer.h>
#include <Furrovine++/Graphics/ShaderVariable.h>
#include <unordered_map>

namespace Furrovine { namespace Graphics {

	class ShaderVariableBuffer : public ShaderBuffer {
	private:
		std::unordered_map<String, ulword> variableindices;
		std::vector<ShaderVariable> variables;
		std::vector<byte> datastream;
		bool dirty;
		ShaderBufferDescription variabledesc;

	public:
		furrovineapi ShaderVariableBuffer( GraphicsDevice& graphics, ShaderStage shaderstage, ulword bufferindex, void* bufferresource, const ShaderParameterOptions& options = ShaderParameterOptions::Default );
		furrovineapi ShaderVariableBuffer( ShaderVariableBuffer&& mov );
		furrovineapi ShaderVariableBuffer& operator=( ShaderVariableBuffer&& mov );
		
		furrovineapi byte* data( );
		furrovineapi const byte* data( ) const;
		furrovineapi ulword size( ) const;

		furrovineapi const ShaderBufferDescription& Description( ) const;
		furrovineapi void Apply( );

		furrovineapi ShaderVariable& operator[]( ulword index );
	};

}}
