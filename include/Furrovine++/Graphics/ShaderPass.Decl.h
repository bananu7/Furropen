#pragma once

#include <Furrovine++/Graphics/ShaderSource.h>
#include <Furrovine++/Graphics/VertexShader.h>
#include <Furrovine++/Graphics/GeometryShader.h>
#include <Furrovine++/Graphics/HullShader.h>
#include <Furrovine++/Graphics/DomainShader.h>
#include <Furrovine++/Graphics/PixelShader.h>
#include <Furrovine++/Graphics/ComputeShader.h>
#include <Furrovine++/Graphics/ShaderPassDescription.h>
#include <Furrovine++/Graphics/ShaderPassParameterCollection.h>

namespace Furrovine { namespace Graphics {

	class ShaderPass : public GraphicsResource {
	protected:
		String passname;
		VertexShader vertexshader;
		GeometryShader geometryshader;
		HullShader hullshader;
		DomainShader domainshader;
		PixelShader pixelshader;
		ShaderPassParameterCollection parameters;

		furrovineapi void Compile ( Shader& method );

		furrovineapi void Compile ();

	public:
		furrovineapi ShaderPass( GraphicsDevice& graphicsdevice, const String& name, const ShaderSource& vertex, const ShaderSource& pixel );
		furrovineapi ShaderPass( GraphicsDevice& graphicsdevice, ShaderPassDescription&& passdescription );
		furrovineapi ShaderPass( GraphicsDevice& graphicsdevice, const ShaderPassDescription& passdescription );
		furrovineapi ShaderPass( ShaderPass&& mov );
		furrovineapi ShaderPass& operator=( ShaderPass&& mov );

		furrovineapi const String& Name( ) const;

		furrovineapi VertexShader& Vertex( );

		furrovineapi HullShader& Hull( );

		furrovineapi DomainShader& Domain( );

		furrovineapi GeometryShader& Geometry( );

		furrovineapi PixelShader& Pixel( );

		furrovineapi ShaderPassParameterCollection& Parameters( );

		furrovineapi void Apply ();
	};

}}
