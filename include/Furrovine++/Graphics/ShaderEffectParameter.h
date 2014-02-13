#pragma once

#include <Furrovine++/fixed_vector.h>
#include <Furrovine++/Graphics/ShaderPassParameter.h>

namespace Furrovine { namespace Graphics {

	class ShaderEffectParameter : public ShaderParameter {
	private:
		String name;
		std::vector<ShaderParameter*> parameters;

	protected:

		furrovineapi virtual TMapper GetMapper( );

		furrovineapi virtual buffer_view<void> GetData( bool markdirty );

	public:

		furrovineapi ShaderEffectParameter( GraphicsDevice& graphics, String name, std::vector<ShaderParameter*> parameters );

		furrovineapi virtual const String& Name( ) const override;

		furrovineapi virtual void SetValue( const void* value, ulword bytesize ) override;

		furrovineapi virtual void GetValue( void*& value, ulword bytesize ) override;

		furrovineapi virtual void GetResourceValue( ShaderResourceView*& value ) override;

		furrovineapi virtual void SetResourceValue( ShaderResourceView& value ) override;
	};

}}
