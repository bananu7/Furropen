#pragma once

#include <Furrovine++/Graphics/ShaderParameterCollection.h>
#include <Furrovine++/Graphics/ShaderEffectParameterCollection.h>
#include <Furrovine++/Graphics/ShaderEffectParameter.h>

namespace Furrovine { namespace Graphics {

	class ShaderEffectParameterCollection {
	private:
		std::unordered_map<String, ulword> parameterindices;
		std::vector<ShaderEffectParameter> parameters;

	public:
		furrovineapi void Add( ShaderPass& pass );

	public:
		furrovineapi ShaderEffectParameterCollection( );
		furrovineapi ShaderEffectParameterCollection( ShaderEffect& pass );
		furrovineapi ShaderEffectParameterCollection( ShaderEffectParameterCollection&& mov );
		furrovineapi ShaderEffectParameterCollection& operator=( ShaderEffectParameterCollection&& mov );

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
