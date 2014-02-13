#pragma once

#include <Furrovine++/Graphics/Dx/Platform.Enums.Dx.h>
#include <Furrovine++/Graphics/graphics_handle.h>
#include <Furrovine++/Graphics/Declarations.Graphics.h>
#include <Furrovine++/Graphics/Texture1DDescription.h>
#include <Furrovine++/Graphics/Texture2DDescription.h>
#include <Furrovine++/Graphics/Texture3DDescription.h>
#include <Furrovine++/Graphics/MultisampleDescription.h>
#include <Furrovine++/Graphics/DepthStencilBufferDescription.h>
#include <Furrovine++/Graphics/DepthStencilBufferDescription.h>
#include <Furrovine++/Graphics/GpuBufferDescription.h>
#include <Furrovine++/Graphics/DisplayModeDescription.h>
#include <Furrovine++/Graphics/AdapterDescription.h>
#include <Furrovine++/Graphics/AdapterOutputDescription.h>
#include <Furrovine++/Graphics/SubresourceData.h>
#include <Furrovine++/Graphics/VertexElement.h>
#include <Furrovine++/Graphics/SamplerStateDescription.h>
#include <Furrovine++/Graphics/BlendStateDescription.h>
#include <Furrovine++/Graphics/BlendStateCollectionDescription.h>
#include <Furrovine++/Graphics/RasterizerStateDescription.h>
#include <Furrovine++/Graphics/DepthStencilStateDescription.h>
#include <Furrovine++/Graphics/ShaderVariableDescription.h>
#include <Furrovine++/Graphics/ShaderResourceDescription.h>
#include <Furrovine++/Graphics/ShaderVariableTypeDescription.h>
#include <Furrovine++/Graphics/ShaderBufferDescription.h>
#include <Furrovine++/rational.h>

namespace Furrovine { namespace Graphics { namespace Dx {

#ifdef FURROVINEDIRECTX

	furrovineapi Rectangle FromPlatform( const RECT& rect );

	furrovineapi rational<uint32> FromPlatform( const DXGI_RATIONAL& plat );

	furrovineapi MultisampleDescription FromPlatform( const DXGI_SAMPLE_DESC& desc );

	furrovineapi D3D11_TEXTURE1D_DESC ToPlatform( const Texture1DDescription& value );

	furrovineapi DXGI_SAMPLE_DESC ToPlatform( const MultisampleDescription& value );

	furrovineapi D3D11_TEXTURE2D_DESC ToPlatform( const Texture2DDescription& value );

	furrovineapi D3D11_TEXTURE2D_DESC ToPlatform( Graphics::SurfaceFormat, const DepthStencilBufferDescription& value );

	furrovineapi D3D11_TEXTURE2D_DESC ToPlatform( Graphics::DepthStencilFormat, const DepthStencilBufferDescription& value );

	furrovineapi D3D11_TEXTURE2D_DESC ToPlatform( const DepthStencilBufferDescription& value );

	furrovineapi D3D11_TEXTURE3D_DESC ToPlatform( const Texture3DDescription& value );

	furrovineapi DXGI_RATIONAL ToPlatform( const rational<uint32>& value );

	furrovineapi D3D11_BUFFER_DESC ToPlatform( const GpuBufferDescription& value );

	furrovineapi DXGI_MODE_DESC ToPlatform( const DisplayModeDescription& mode );

	furrovineapi D3D11_SUBRESOURCE_DATA ToPlatform( const SubresourceData& value );

	furrovineapi D3D11_INPUT_ELEMENT_DESC ToPlatform( const VertexElement& value );

	furrovineapi D3D11_SAMPLER_DESC ToPlatform( const SamplerStateDescription& value );

	furrovineapi D3D11_RASTERIZER_DESC ToPlatform( const RasterizerStateDescription& value );

	furrovineapi D3D11_DEPTH_STENCILOP_DESC ToPlatform( const StencilOperationDescription& value );

	furrovineapi D3D11_DEPTH_STENCIL_DESC ToPlatform( const DepthStencilStateDescription& value );

	furrovineapi D3D11_RENDER_TARGET_BLEND_DESC ToPlatform( const BlendStateDescription& value );

	furrovineapi D3D11_BLEND_DESC ToPlatform( const BlendStateCollectionDescription& value );

	furrovineapi Texture1DDescription FromPlatform( const D3D11_TEXTURE1D_DESC& desc );

	furrovineapi Texture2DDescription FromPlatform( const D3D11_TEXTURE2D_DESC& desc );

	furrovineapi Texture3DDescription FromPlatform( const D3D11_TEXTURE3D_DESC& desc );

	furrovineapi AdapterOutputDescription FromPlatform( const DXGI_OUTPUT_DESC& desc );

	furrovineapi AdapterDescription FromPlatform( const DXGI_ADAPTER_DESC& desc );

	furrovineapi VertexElement FromPlatform( const D3D11_INPUT_ELEMENT_DESC& desc );

	furrovineapi VertexElement FromPlatform( const D3D11_INPUT_ELEMENT_DESC& desc, VertexElementComponent component, uint32 componentcount );

	furrovineapi SamplerStateDescription FromPlatform( const D3D11_SAMPLER_DESC& desc );

	furrovineapi RasterizerStateDescription FromPlatform( const D3D11_RASTERIZER_DESC& desc );

	furrovineapi BlendStateDescription FromPlatform( const D3D11_RENDER_TARGET_BLEND_DESC& desc );

	furrovineapi BlendStateCollectionDescription FromPlatform( const D3D11_BLEND_DESC& desc );

	furrovineapi StencilOperationDescription FromPlatform( const D3D11_DEPTH_STENCILOP_DESC& desc );

	furrovineapi DepthStencilStateDescription FromPlatform( const D3D11_DEPTH_STENCIL_DESC& desc );

	furrovineapi ShaderVariableDescription FromPlatform( const D3D11_SHADER_VARIABLE_DESC& desc );

	furrovineapi ShaderVariableTypeDescription FromPlatform( const D3D11_SHADER_TYPE_DESC& desc );

	furrovineapi ShaderBufferDescription FromPlatform( const D3D11_SHADER_BUFFER_DESC& desc );

	furrovineapi ShaderResourceDescription FromPlatform( const D3D11_SHADER_INPUT_BIND_DESC& desc );

	furrovineapi DisplayModeDescription FromPlatform( const DXGI_MODE_DESC& desc );

	furrovineapi std::pair<uint32, std::vector<VertexElement>> CreateVertexElements( graphics_handle reflectionresource, bool output = false );

#endif // DIRECTX

}}}