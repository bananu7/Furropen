#pragma once

#include <Furrovine++/fixed_vector.h>
#include <Furrovine++/Graphics/ShaderParameter.h>

namespace Furrovine { namespace Graphics {

	class ShaderPassParameter : public ShaderParameter {
	private:
		fixed_vector<ShaderParameter*, 5> parameters;

		furrovineapi void AddParameter( const String& name, Shader& shader );

	protected:

		furrovineapi virtual TMapper GetMapper( );

		furrovineapi virtual buffer_view<void> GetData( bool markdirty );

	public:
		furrovineapi ShaderPassParameter( ShaderPass& pass, const String& name );
		furrovineapi ShaderPassParameter( ShaderPassParameter&& mov );
		furrovineapi ShaderPassParameter& operator=( ShaderPassParameter&& mov );
		
		furrovineapi virtual const String& Name( ) const override;

		furrovineapi virtual void SetValue( const void* value, ulword bytesize ) override;

		furrovineapi virtual void GetValue( void*& value, ulword bytesize ) override;

		furrovineapi virtual void GetResourceValue( ShaderResourceView*& value ) override;

		furrovineapi virtual void SetResourceValue( ShaderResourceView& value ) override;
	};

}}
