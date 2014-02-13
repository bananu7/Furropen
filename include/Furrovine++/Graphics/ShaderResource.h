#pragma once

#include <Furrovine++/handle.h>
#include <Furrovine++/Graphics/graphics_handle.h>
#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/Graphics/ShaderParameter.h>
#include <Furrovine++/Graphics/ShaderResourceDescription.h>

namespace Furrovine { namespace Graphics {

	class ShaderResource : public ShaderParameter {
	private:
		ShaderResourceDescription resourcedesc;
		struct deleter {
			furrovineapi void operator()( graphics_handle p );
		};
		handle<graphics_handle, deleter>  resourcereflection;
		bool dirty;

	public:
		furrovineapi ShaderResource( GraphicsDevice& graphics, ShaderStage stage, ulword resourceindex, graphics_handle resourcerefl );
		furrovineapi ShaderResource( ShaderResource&& mov );
		furrovineapi ShaderResource& operator=( ShaderResource&& mov );

		furrovineapi const ShaderResourceDescription& Description( ) const;
		furrovineapi graphics_handle ResourceReflectionResource( ) const;

		furrovineapi virtual const String& Name( ) const override;
		furrovineapi virtual void SetResourceValue( ShaderResourceView& view ) override;
		furrovineapi virtual void GetResourceValue( ShaderResourceView*& value ) override;

		furrovineapi ShaderResourceView& GetShaderResourceViewValue( );

		furrovineapi ShaderResource& operator= ( ShaderResourceView& value );

	};

}}