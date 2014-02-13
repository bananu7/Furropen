#pragma once

#include <Furrovine++/handle.h>
#include <Furrovine++/Graphics/graphics_handle.h>
#include <Furrovine++/Graphics/ShaderParameter.h>
#include <Furrovine++/Graphics/ShaderVariableDescription.h>
#include <Furrovine++/Graphics/ShaderVariableTypeDescription.h>
#include <Furrovine++/Graphics/ShaderParameterOptions.h>
#include <Furrovine++/Graphics/ShaderStage.h>
#include <Furrovine++/buffer_view.h>
#include <Furrovine++/Color.h>

namespace Furrovine { namespace Graphics {

	class ShaderVariable : public ShaderParameter {
	protected:
		friend class ShaderVariableBuffer;
		friend class ShaderParameterCollection;
		struct deleter {
			furrovineapi void operator()( graphics_handle p );
		};
		
		ulword bufferindex;
		ShaderVariableDescription variabledesc;
		ShaderVariableTypeDescription variabletypedesc;
		ShaderParameterOptions paramoptions;
		ShaderVariableBuffer* variablebuffer;
		handle<graphics_handle, deleter> varreflection;


		furrovineapi virtual buffer_view<void> GetData( bool markdirty ) override;

	public:
		furrovineapi ShaderVariable( GraphicsDevice& graphics, ShaderVariableBuffer& buffer, ShaderStage methodology, ulword bufferindex, void* varrefl, const ShaderParameterOptions& options = ShaderParameterOptions::Default );
		furrovineapi ShaderVariable( ShaderVariable&& variable );
		furrovineapi ShaderVariable& operator=( ShaderVariable&& mov );
		
		furrovineapi const ShaderVariableDescription& Description( ) const;
		furrovineapi const ShaderVariableTypeDescription& TypeDescription( ) const;
		furrovineapi virtual const String& Name( ) const override;
		furrovineapi virtual void SetValue( const void* value, ulword bytesize ) override;
		furrovineapi virtual void GetValue( void*& value, ulword bytesize ) override;

		furrovineapi graphics_handle ReflectionResource( ) const;

	};

}}