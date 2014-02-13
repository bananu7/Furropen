#pragma once

#include <Furrovine++/Graphics/Shader.h>
#include <Furrovine++/Graphics/InputLayout.h>

namespace Furrovine { namespace Graphics {

	class VertexShader : public Shader {
	protected:
		std::unordered_map<const VertexDeclaration*, lword, std::hash<const VertexDeclaration*>, VertexDeclarationCompatible> compatiblelayoutindices;
		std::vector<InputLayout> compatiblelayouts;
		
		furrovineapi virtual void OnReflectSuccess ( ) override;

		furrovineapi void CreateInputLayout( );

		furrovineapi void ClearLayouts( );

	public:

		furrovineapi VertexShader( GraphicsDevice& graphics, const ShaderSource& methoddesc = ShaderSource::Empty );
		furrovineapi VertexShader( GraphicsDevice& graphics, ShaderSource&& methoddesc );
		furrovineapi VertexShader( VertexShader&& methoddesc );
		furrovineapi VertexShader& operator=( VertexShader&& methoddesc );
		
		furrovineapi virtual void EnsureLayout( const VertexDeclaration& vertexdeclaration, InputLayout*& inputlayout ) override;

		furrovineapi virtual bool TryGetLayout ( const VertexDeclaration& vertexdeclaration, InputLayout*& inputlayout ) override;

	};

}}
