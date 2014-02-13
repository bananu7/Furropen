#pragma once

#include <Furrovine++/buffer_view.h>
#include <Furrovine++/Graphics/ShaderPassParameter.h>
#include <unordered_map>

namespace Furrovine { namespace Graphics {

	class ShaderPassParameterCollection {
	private:
		std::unordered_map<String, ulword> parameterindices;
		std::vector<ShaderPassParameter> parameters;

		furrovineapi void Add( ShaderPass& pass, Shader& shader );

	public:
		furrovineapi ShaderPassParameterCollection( );
		furrovineapi ShaderPassParameterCollection( ShaderPass& pass );
		furrovineapi ShaderPassParameterCollection( ShaderPassParameterCollection&& mov );
		furrovineapi ShaderPassParameterCollection& operator=( ShaderPassParameterCollection&& mov );

		furrovineapi ulword ParameterCount( ) const;

		furrovineapi void Apply( );

		furrovineapi bool TryGetParameterAt( ulword index, ShaderParameter*& parameter );
		furrovineapi bool TryGetParameterByName( const String& name, ShaderParameter*& parameter );
		furrovineapi ShaderParameter& ParameterAt( ulword index );
		furrovineapi ShaderParameter& ParameterByName( const String& name );
		furrovineapi ShaderParameter& operator[] ( ulword index );
		furrovineapi ShaderParameter& operator[] ( const String& name );

		furrovineapi bool ContainsParameter( const String& parametername ) const;
	
	};

}}