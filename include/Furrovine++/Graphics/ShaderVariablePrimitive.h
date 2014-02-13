#pragma once

namespace Furrovine { namespace Graphics {

	enum class ShaderVariablePrimitive {
		Void,
		Bool,
		Int,
		Float,
		String,
		Texture,
		Texture1D,
		Texture2D,
		Texture3D,
		TextureCube,
		Sampler,
		Sampler1D,
		Sampler2D,
		Sampler3D,
		SamplerCube,
		PixelShader,
		VertexShader,
		PixelFragment,
		VertexFragment,
		UInt,
		UInt8,
		GeometryShader,
		Rasterizer,
		DepthStencil,
		Blend,
		Buffer,
		CBuffer,
		TBuffer,
		Texture1DArray,
		Texture2DArray,
		RenderTargetView,
		DepthStencilView,
		Texture2DMS,
		Texture2DMSArray,
		TextureCubeArray,
		HullShader,
		DomainShader,
		Interface_Pointer,
		ComputeShader,
		Double,
		RWTexture1D,
		RWTexture1DArray,
		RWTexture2D,
		RWTexture2DArray,
		RWTexture3D,
		RWBuffer,
		ByteAddressBuffer,
		RWByteAddressBuffer,
		StructuredBuffer,
		RWStructuredBuffer,
		AppendStructuredBuffer,
		ConsumemeStructuredBuffer,
		Min8Float,
		Min10Float,
		Min16Float,
		Min12Int,
		Min16Int,
		Min16UInt,
	};

}}