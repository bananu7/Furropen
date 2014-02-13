#pragma once

#include <Furrovine++/deleters.h>
#include <Furrovine++/Graphics/ShaderPass.h>

namespace Furrovine { namespace Graphics {

	class ShaderPassCollection : public GraphicsResource  {
	protected:
		std::unordered_map<String, ulword> passindices;
		std::vector<ShaderPass> passes;
	
	public:
		furrovineapi ShaderPassCollection( GraphicsDevice& graphicsdevice );

		furrovineapi ShaderPassCollection( ShaderPassCollection&& mov );
		furrovineapi ShaderPassCollection& operator=( ShaderPassCollection&& mov );

		furrovineapi std::vector<ShaderPass>::const_iterator cbegin( );

		furrovineapi std::vector<ShaderPass>::iterator begin( );

		furrovineapi std::vector<ShaderPass>::const_iterator cend( );

		furrovineapi std::vector<ShaderPass>::iterator end( );
		
		furrovineapi ulword PassCount( ) const;

		furrovineapi bool TryGetPassByName( const String& name, ShaderPass*& pass ) const;

		furrovineapi bool TryGetPassAt( ulword index, ShaderPass*& pass ) const;

		furrovineapi ShaderPass& PassAt( ulword index ) const;

		furrovineapi ShaderPass& PassByName( const String& name ) const;

		furrovineapi ShaderPass& operator[] ( ulword index );

		furrovineapi ShaderPass& operator[] ( const String& name );

	};

}}
