#pragma once

#include <Furrovine++/Declarations.h>
#include <Furrovine++/Graphics/GraphicsRuntimeException.h>
#include <Furrovine++/Graphics/InputLayout.h>
#include <Furrovine++/Graphics/ShaderStage.h>
#include <Furrovine++/Graphics/ShaderSource.h>
#include <Furrovine++/Graphics/ShaderDeclaration.h>
#include <Furrovine++/Graphics/ShaderParameterOptions.h>
#include <Furrovine++/Graphics/ShaderParameterCollection.h>

namespace Furrovine { namespace Graphics {

	class Shader : public GraphicsResource {
	protected:
		struct bytecode_deleter {
			furrovineapi void operator() ( void* p );
		};

		struct errors_deleter {
			furrovineapi void operator() ( void* p );
		};

		struct reflection_deleter {
			furrovineapi void operator() ( graphics_handle p );
		};

		struct shader_deleter {
			Shader* commonshader;
			furrovineapi shader_deleter( Shader& shader );
			furrovineapi void operator() ( graphics_handle p );
		};

		ShaderSource methodsource;
		ptr<void, bytecode_deleter> bytecode;
		ptr<void, errors_deleter> errors;
		handle<graphics_handle, shader_deleter> shader;
		handle<graphics_handle, reflection_deleter> reflection;
		ShaderDeclaration declaration;
		ShaderParameterCollection parameters;

		furrovineapi uint64 CompileEC( );
		furrovineapi virtual void OnCompileSuccess( );
		furrovineapi virtual void OnCompileFail( uint64 r );

		furrovineapi uint64 ReflectEC( );
		furrovineapi virtual void OnReflectSuccess( );
		furrovineapi virtual void OnReflectFail( uint64 r );
		
		furrovineapi virtual void Create( );
		
	public:
		furrovineapi Shader( GraphicsDevice& graphicsdevice, const ShaderSource& description = ShaderSource::Empty );
		furrovineapi Shader( GraphicsDevice& graphicsdevice, ShaderSource&& description );
		furrovineapi Shader( Shader&& mov );
		furrovineapi Shader& operator=( Shader&& mov );
		furrovineapi ShaderStage Stage( ) const;

		furrovineapi const ShaderParameterOptions& VariableOptions( ) const;

		furrovineapi const ShaderSource& Source( ) const;

		furrovineapi const ShaderDeclaration& InputDeclaration( ) const;

		furrovineapi ShaderParameterCollection& Parameters( );

		furrovineapi const ShaderParameterCollection& Parameters( ) const;

		furrovineapi graphics_handle ShaderResource( ) const;

		furrovineapi graphics_handle ReflectionResource( ) const;

		furrovineapi buffer_view<void> Bytecode( ) const;

		furrovineapi bool Compiled( ) const;
		
		furrovineapi void Compile( );

		furrovineapi void Reflect( );

		furrovineapi virtual void EnsureLayout( const VertexDeclaration& declaration, InputLayout*& layout );

		furrovineapi virtual bool TryGetLayout( const VertexDeclaration& declaration, InputLayout*& layout );

		furrovineapi virtual void Apply( );

		furrovineapi virtual ~Shader( );

	};

}}
