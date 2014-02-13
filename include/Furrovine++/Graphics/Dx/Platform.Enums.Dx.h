#pragma once

#include <Furrovine++/Platform.Graphics.h>
#include <Furrovine++/Strings.h>
#include <Furrovine++/Bits.h>
#include <Furrovine++/make_array.h>
#include <Furrovine++/Comparison.h>
#include <Furrovine++/Graphics/FeatureLevel.h>
#include <Furrovine++/Graphics/DepthWriteMask.h>
#include <Furrovine++/Graphics/StencilOperation.h>
#include <Furrovine++/Graphics/TextureAddress.h>
#include <Furrovine++/Graphics/TextureFilter.h>
#include <Furrovine++/Graphics/ClearFlags.h>
#include <Furrovine++/Graphics/ColorWriteChannels.h>
#include <Furrovine++/Graphics/FillMode.h>
#include <Furrovine++/Graphics/CullMode.h>
#include <Furrovine++/Graphics/BlendOperation.h>
#include <Furrovine++/Graphics/BlendFactor.h>
#include <Furrovine++/Graphics/FrontFace.h>
#include <Furrovine++/Graphics/SurfaceFormat.h>
#include <Furrovine++/Graphics/DepthStencilFormat.h>
#include <Furrovine++/Graphics/PrimitiveTopology.h>
#include <Furrovine++/Graphics/MonitorScaling.h>
#include <Furrovine++/Graphics/MonitorRotation.h>
#include <Furrovine++/Graphics/SurfaceScanlineOrder.h>
#include <Furrovine++/Graphics/DisplayFilterFlags.h>
#include <Furrovine++/Graphics/ResourceOptionFlags.h>
#include <Furrovine++/Graphics/ResourceMapping.h>
#include <Furrovine++/Graphics/CpuAccessFlags.h>
#include <Furrovine++/Graphics/ResourceUsage.h>
#include <Furrovine++/Graphics/BindFlags.h>
#include <Furrovine++/Graphics/DepthStencilViewFlags.h>
#include <Furrovine++/Graphics/IndexElementFormat.h>
#include <Furrovine++/Graphics/IndexElementSize.h>
#include <Furrovine++/Graphics/IndexElementSize.h>
#include <Furrovine++/Graphics/VertexElementComponent.h>
#include <Furrovine++/Graphics/VertexElementFormat.h>
#include <Furrovine++/Graphics/VertexDataUsage.h>
#include <Furrovine++/Graphics/GraphicsDriverType.h>
#include <Furrovine++/Graphics/GraphicsDeviceCreationFlags.h>
#include <Furrovine++/Graphics/ShaderVersion.h>
#include <Furrovine++/Graphics/ShaderCompilationFlags.h>
#include <Furrovine++/Graphics/ShaderVariableFlags.h>
#include <Furrovine++/Graphics/ShaderVariablePrimitive.h>
#include <Furrovine++/Graphics/ShaderVariableType.h>
#include <Furrovine++/Graphics/ShaderBufferType.h>
#include <Furrovine++/Graphics/ShaderBufferFlags.h>
#include <Furrovine++/Graphics/ShaderResourceType.h>
#include <Furrovine++/Graphics/ShaderResourceReturnType.h>
#include <Furrovine++/Graphics/ShaderResourceFlags.h>
#include <Furrovine++/Graphics/ShaderResourceViewDimension.h>
#include <Furrovine++/Graphics/DepthStencilViewDimension.h>
#include <Furrovine++/Graphics/RenderBufferViewDimension.h>
#include <Furrovine++/Graphics/ResourceDimension.h>
#include <Furrovine++/Graphics/UnorderedAccessViewDimension.h>
#include <Furrovine++/Graphics/ShaderIncludeMode.h>

namespace Furrovine { namespace Graphics { namespace Dx {

#ifdef FURROVINEDIRECTX

	enum class FeatureLevel {
		LevelDx091 = D3D_FEATURE_LEVEL_9_1,
		LevelDx092 = D3D_FEATURE_LEVEL_9_2,
		LevelDx093 = D3D_FEATURE_LEVEL_9_3,
		LevelDx100 = D3D_FEATURE_LEVEL_10_0,
		LevelDx101 = D3D_FEATURE_LEVEL_10_1,
		LevelDx110 = D3D_FEATURE_LEVEL_11_0,
		LevelDx111 = D3D_FEATURE_LEVEL_11_1,
	};

	enum class ShaderResourceReturnType {
		UNorm = D3D_RETURN_TYPE_UNORM,
		Normalized = D3D_RETURN_TYPE_SNORM,
		Int = D3D_RETURN_TYPE_SINT,
		UInt = D3D_RETURN_TYPE_UINT,
		Float = D3D_RETURN_TYPE_FLOAT,
		Mixed = D3D_RETURN_TYPE_MIXED,
		Double = D3D_RETURN_TYPE_DOUBLE,
		Continued = D3D_RETURN_TYPE_CONTINUED,
	};

	enum class ShaderResourceType {
		ConstantBuffer = D3D_SIT_CBUFFER,
		TextureBuffer = D3D_SIT_TBUFFER,
		Texture = D3D_SIT_TEXTURE,
		Sampler = D3D_SIT_SAMPLER,
		UorderedAccessViewRWTyped = D3D_SIT_UAV_RWTYPED,
		Structured = D3D_SIT_STRUCTURED,
		UnorderedAccessViewRWStructured = D3D_SIT_UAV_RWSTRUCTURED,
		ByteAddress = D3D_SIT_BYTEADDRESS,
		RWByteAddress = D3D_SIT_UAV_RWBYTEADDRESS,
		UnorderedAccessViewAppendStructured = D3D_SIT_UAV_APPEND_STRUCTURED,
		UnorderedAccessViewConsumeStructured = D3D_SIT_UAV_CONSUME_STRUCTURED,
		UnorderedAccessViewRWStructuredCounter = D3D_SIT_UAV_RWSTRUCTURED_WITH_COUNTER,
	};

	enum class ShaderVariableType {
		Scalar = D3D_SVC_SCALAR,
		Vector = D3D_SVC_VECTOR,
		MatrixRows = D3D_SVC_MATRIX_ROWS,
		MatrixColums = D3D_SVC_MATRIX_COLUMNS,
		Object = D3D_SVC_OBJECT,
		Struct = D3D_SVC_STRUCT,
		InterfaceClass = D3D_SVC_INTERFACE_CLASS,
		InterfacePointer = D3D_SVC_INTERFACE_POINTER,
	};

	enum class ShaderVariablePrimitive {
		Void = D3D_SVT_VOID,
		Bool = D3D_SVT_BOOL,
		Int = D3D_SVT_INT,
		Float = D3D_SVT_FLOAT,
		String = D3D_SVT_STRING,
		Texture = D3D_SVT_TEXTURE,
		Texture1D = D3D_SVT_TEXTURE1D,
		Texture2D = D3D_SVT_TEXTURE2D,
		Texture3D = D3D_SVT_TEXTURE3D,
		TextureCube = D3D_SVT_TEXTURECUBE,
		Sampler = D3D_SVT_SAMPLER,
		Sampler1D = D3D_SVT_SAMPLER1D,
		Sampler2D = D3D_SVT_SAMPLER2D,
		Sampler3D = D3D_SVT_SAMPLER3D,
		SamplerCube = D3D_SVT_SAMPLERCUBE,
		PixelShader = D3D_SVT_PIXELSHADER,
		VertexShader = D3D_SVT_VERTEXSHADER,
		PixelFragment = D3D_SVT_PIXELFRAGMENT,
		VertexFragment = D3D_SVT_VERTEXFRAGMENT,
		UInt = D3D_SVT_UINT,
		UInt8 = D3D_SVT_UINT8,
		GeometryShader = D3D_SVT_GEOMETRYSHADER,
		Rasterizer = D3D_SVT_RASTERIZER,
		DepthStencil = D3D_SVT_DEPTHSTENCIL,
		Blend = D3D_SVT_BLEND,
		Buffer = D3D_SVT_BUFFER,
		CBuffer = D3D_SVT_CBUFFER,
		TBuffer = D3D_SVT_TBUFFER,
		Texture1DArray = D3D_SVT_TEXTURE1DARRAY,
		Texture2DArray = D3D_SVT_TEXTURE2DARRAY,
		RenderBufferView = D3D_SVT_RENDERTARGETVIEW,
		DepthStencilView = D3D_SVT_DEPTHSTENCILVIEW,
		Texture2DMS = D3D_SVT_TEXTURE2DMS,
		Texture2DMSArray = D3D_SVT_TEXTURE2DMSARRAY,
		TextureCubeArray = D3D_SVT_TEXTURECUBEARRAY,
		HullShader = D3D_SVT_HULLSHADER,
		DomainShader = D3D_SVT_DOMAINSHADER,
		InterfacePointer = D3D_SVT_INTERFACE_POINTER,
		ComputeShader = D3D_SVT_COMPUTESHADER,
		Double = D3D_SVT_DOUBLE,
		RWTexture1D = D3D_SVT_RWTEXTURE1D,
		RWTexture1DArray = D3D_SVT_RWTEXTURE1DARRAY,
		RWTexture2D = D3D_SVT_RWTEXTURE2D,
		RWTexture2DArray = D3D_SVT_RWTEXTURE2DARRAY,
		RWTexture3D = D3D_SVT_RWTEXTURE3D,
		RWBuffer = D3D_SVT_RWBUFFER,
		ByteAddressBuffer = D3D_SVT_BYTEADDRESS_BUFFER,
		RWByteAddressBuffer = D3D_SVT_RWBYTEADDRESS_BUFFER,
		StructuredBuffer = D3D_SVT_STRUCTURED_BUFFER,
		RWStructuredBuffer = D3D_SVT_RWSTRUCTURED_BUFFER,
		AppendStructuredBuffer = D3D_SVT_APPEND_STRUCTURED_BUFFER,
		ConsumeStructuredBuffer = D3D_SVT_CONSUME_STRUCTURED_BUFFER,
		Min8Float = D3D_SVT_MIN8FLOAT,
		Min10Float = D3D_SVT_MIN10FLOAT,
		Min16Float = D3D_SVT_MIN16FLOAT,
		Min12Int = D3D_SVT_MIN12INT,
		Min16Int = D3D_SVT_MIN16INT,
		Min16UInt = D3D_SVT_MIN16UINT,
	};

	enum class ShaderBufferType {
		ConstantBuffer = D3D11_CT_CBUFFER,
		TextureBuffer = D3D11_CT_TBUFFER,
		InterfacePointers = D3D11_CT_INTERFACE_POINTERS,
		ResourceBindInfo = D3D11_CT_RESOURCE_BIND_INFO
	};

	enum class ShaderBufferFlags {
		None = 0x0,
		Userpacked = D3D_CBF_USERPACKED,
	};

	enum class ShaderVersion {
		Version20Software,
		Version20,
		Version20a,
		Version20b,
		Version30Software,
		Version30,
		Version40Level91,
		Version40Level93,
		Version40,
		Version41,
		Version50,
		ShaderModel20 = Version20,
		ShaderModel30 = Version30,
		ShaderModel40_d3d91 = Version40Level91,
		ShaderModel40_d3d93 = Version40Level93,
		ShaderModel40 = Version40,
		ShaderModel41 = Version41,
		ShaderModel50 = Version50,
		Default = ShaderModel40_d3d93
	};

	const std::array<String, 11> ModelVersion = {
		"2_sw",
		"2_0",
		"2_a",
		"2_b",
		"3_sw",
		"3_0",
		"4_0_level_9_1",
		"4_0_level_9_3",
		"4_0",
		"4_1",
		"5_0"
	};

	enum class DepthWriteMask {
		None = D3D11_DEPTH_WRITE_MASK_ZERO,
		All = D3D11_DEPTH_WRITE_MASK_ALL
	};

	enum class StencilOperations {
		Keep = D3D11_STENCIL_OP_KEEP,
		Zero = D3D11_STENCIL_OP_ZERO,
		Replace = D3D11_STENCIL_OP_REPLACE,
		IncrementClamp = D3D11_STENCIL_OP_INCR_SAT,
		DecrementClamp = D3D11_STENCIL_OP_DECR_SAT,
		Invert = D3D11_STENCIL_OP_INVERT,
		Increment = D3D11_STENCIL_OP_INCR,
		Decrement = D3D11_STENCIL_OP_DECR,
	};

	enum class ShaderVariableFlags {
		None = 0,
		Userpacked = D3D_SVF_USERPACKED,
		Used = D3D_SVF_USED,
		InterfacePointer = D3D_SVF_INTERFACE_POINTER,
		InterfaceParameter = D3D_SVF_INTERFACE_PARAMETER,
	};

	enum class ShaderResourceFlags {
		None = 0x0,
		Userpacked = D3D_SIF_USERPACKED,
		ComparisonSampler = D3D_SIF_COMPARISON_SAMPLER,
		TextureComponent0 = D3D_SIF_TEXTURE_COMPONENT_0,
		TextureComponent1 = D3D_SIF_TEXTURE_COMPONENT_1,
		Unused = D3D_SIF_UNUSED,
		TextureComponent01 = TextureComponent0 | TextureComponent1,
	};

	enum class TextureAddress {
		Wrap = D3D11_TEXTURE_ADDRESS_WRAP,
		Mirror = D3D11_TEXTURE_ADDRESS_MIRROR,
		Clamp = D3D11_TEXTURE_ADDRESS_CLAMP,
		Border = D3D11_TEXTURE_ADDRESS_BORDER,
		MirrorOnce = D3D11_TEXTURE_ADDRESS_MIRROR_ONCE,
		Repeat = Wrap,
		MirrorRepeat = Mirror,
		Default = Clamp,
	};

	enum class TextureFilter {
		Point = D3D11_FILTER_MIN_MAG_MIP_POINT,
		Linear = D3D11_FILTER_MIN_MAG_MIP_LINEAR,
		Anisotropic = D3D11_FILTER_ANISOTROPIC,
		MinPointMagLinearMipPoint = D3D11_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT,
		MinLinearMagPointMipLinear = D3D11_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR,
		MinMagPointMipLinear = D3D11_FILTER_MIN_MAG_POINT_MIP_LINEAR,
		MinMagLinearMipPoint = D3D11_FILTER_MIN_MAG_LINEAR_MIP_POINT,
	};

	enum class Comparison {
		Never = D3D11_COMPARISON_NEVER,
		Less = D3D11_COMPARISON_LESS,
		Equal = D3D11_COMPARISON_EQUAL,
		LessEqual = D3D11_COMPARISON_LESS_EQUAL,
		Greater = D3D11_COMPARISON_GREATER,
		NotEqual = D3D11_COMPARISON_NOT_EQUAL,
		GreaterEqual = D3D11_COMPARISON_GREATER_EQUAL,
		Always = D3D11_COMPARISON_ALWAYS,
	};

	enum class ComparisonFlags {
		None = 0,
		Never = 1 << (unsigned)Comparison::Never,
		Less = 1 << (unsigned)Comparison::Less,
		Equal = 1 << (unsigned)Comparison::Equal,
		LessEqual = 1 << (unsigned)Comparison::LessEqual,
		Greater = 1 << (unsigned)Comparison::Greater,
		NotEqual = 1 << (unsigned)Comparison::NotEqual,
		GreaterEqual = 1 << (unsigned)Comparison::GreaterEqual,
		Always = 1 << (unsigned)Comparison::Always
	};

	enum class DepthStencilViewFlags {
		None = 0x0,
		ReadOnlyDepth = 0x1L,
		ReadOnlyStencil = 0x2L
	};

	enum class BlendFactor {
		Zero = D3D11_BLEND_ZERO,
		One = D3D11_BLEND_ONE,
		SourceColor = D3D11_BLEND_SRC_COLOR,
		InverseSourceColor = D3D11_BLEND_INV_SRC_COLOR,
		SourceAlpha = D3D11_BLEND_SRC_ALPHA,
		InverseSourceAlpha = D3D11_BLEND_INV_SRC_ALPHA,
		DestinationAlpha = D3D11_BLEND_DEST_ALPHA,
		InverseDestinationAlpha = D3D11_BLEND_INV_DEST_ALPHA,
		DestinationColor = D3D11_BLEND_DEST_COLOR,
		InverseDestinationColor = D3D11_BLEND_INV_DEST_COLOR,
		SourceAlphaClamped = D3D11_BLEND_SRC_ALPHA_SAT,
		Manual = D3D11_BLEND_BLEND_FACTOR,
		InverseManual = D3D11_BLEND_INV_BLEND_FACTOR,
		PixelShaderSourceColor = D3D11_BLEND_SRC1_COLOR,
		InversePixelShaderSourceColor = D3D11_BLEND_INV_SRC1_COLOR,
		PixelShaderSourceAlpha = D3D11_BLEND_SRC1_ALPHA,
		InversePixelShaderSourceAlpha = D3D11_BLEND_INV_SRC1_ALPHA
	};

	enum class BlendOperation {
		Add = D3D11_BLEND_OP_ADD,
		Subtract = D3D11_BLEND_OP_SUBTRACT,
		ReverseSubtract = D3D11_BLEND_OP_REV_SUBTRACT,
		Min = D3D11_BLEND_OP_MIN,
		Max = D3D11_BLEND_OP_MAX
	};

	enum class ColorWriteChannels : byte {
		None = 0x0,
		Red = D3D11_COLOR_WRITE_ENABLE_RED,
		Green = D3D11_COLOR_WRITE_ENABLE_GREEN,
		Blue = D3D11_COLOR_WRITE_ENABLE_BLUE,
		Alpha = D3D11_COLOR_WRITE_ENABLE_ALPHA,
		All = Red | Green | Blue | Alpha,
	};

	enum class ClearFlags {
		None = 0x0,
		Depth = D3D11_CLEAR_DEPTH,
		Stencil = D3D11_CLEAR_STENCIL,
		Color = 0x04,
		DepthStencil = Depth | Stencil,
		DepthStencilColor = Depth | Stencil | Color
	};

	enum class FrontFace {
		Clockwise = 0,
		CounterClockwise = 1,
	};

	enum class CullMode {
		None = D3D11_CULL_NONE,
		Front = D3D11_CULL_FRONT,
		Back = D3D11_CULL_BACK,
	};

	enum class PrimitiveTopology {
		Points = D3D11_PRIMITIVE_TOPOLOGY_POINTLIST,
		PointList = Points,
		Lines = D3D11_PRIMITIVE_TOPOLOGY_LINELIST,
		LineList = Lines,
		LineStrip = D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP,
		Triangles = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
		TriangleList = Triangles,
		TriangleStrip = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP,
	};

	enum class GraphicsDeviceCreationFlags {
		None = 0,
		SingleThreaded = D3D11_CREATE_DEVICE_SINGLETHREADED,
		Debug = D3D11_CREATE_DEVICE_DEBUG,
		SwitchToReference = D3D11_CREATE_DEVICE_SWITCH_TO_REF,
		PreventInternalThreadingOptimizations = D3D11_CREATE_DEVICE_PREVENT_INTERNAL_THREADING_OPTIMIZATIONS,
		BlueGreenRedAlphaSupport = D3D11_CREATE_DEVICE_BGRA_SUPPORT,
		Debuggable = D3D11_CREATE_DEVICE_DEBUGGABLE,
		PreventRegistryDeviceAlterting = D3D11_CREATE_DEVICE_PREVENT_ALTERING_LAYER_SETTINGS_FROM_REGISTRY,
		NoTimeout = D3D11_CREATE_DEVICE_DISABLE_GPU_TIMEOUT,
		VideoSupport = D3D11_CREATE_DEVICE_VIDEO_SUPPORT,
	};

	enum class FillMode {
		Point = 1,
		Wireframe = D3D11_FILL_WIREFRAME,
		Solid = D3D11_FILL_SOLID,
	};

	enum class GraphicsDriverType {
		Unknown = D3D_DRIVER_TYPE_UNKNOWN,
		Hardware = D3D_DRIVER_TYPE_HARDWARE,
		Reference = D3D_DRIVER_TYPE_REFERENCE,
		Null = D3D_DRIVER_TYPE_NULL,
		Software = D3D_DRIVER_TYPE_SOFTWARE,
		Warp = D3D_DRIVER_TYPE_WARP,
	};

	enum class VertexDataUsage {
		PerVertex = D3D11_INPUT_PER_VERTEX_DATA,
		PerInstance = D3D11_INPUT_PER_INSTANCE_DATA,
	};

	enum class MonitorScaling {
		Unknown = DXGI_MODE_SCALING_UNSPECIFIED,
		Centered = DXGI_MODE_SCALING_CENTERED,
		Stretched = DXGI_MODE_SCALING_STRETCHED
	};

	enum class MonitorRotation {
		Unspecified = DXGI_MODE_ROTATION_UNSPECIFIED,
		Identity = DXGI_MODE_ROTATION_IDENTITY,
		Rotate90 = DXGI_MODE_ROTATION_ROTATE90,
		Rotate180 = DXGI_MODE_ROTATION_ROTATE180,
		Rotate270 = DXGI_MODE_ROTATION_ROTATE270
	};

	enum class SurfaceScanlineOrder {
		Unknown = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED,
		Progressive = DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE,
		UpperField = DXGI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST,
		LowerField = DXGI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST,
	};

	enum DisplayFilterFlags {
		None = 0,
		Interlaced = DXGI_ENUM_MODES_INTERLACED,
		Scaling = DXGI_ENUM_MODES_SCALING,
		Stereo = /*DXGI_ENUM_MODES_STEREO*/4,
		HiddenStereo = /*DXGI_ENUM_MODES_DISABLED_STEREO*/8
	};

	enum class ResourceOptionFlags {
		None = 0,
		GENERATE_MIPS = D3D11_RESOURCE_MISC_GENERATE_MIPS,
		SHARED = D3D11_RESOURCE_MISC_SHARED,
		TEXTURECUBE = D3D11_RESOURCE_MISC_TEXTURECUBE,
		DRAWINDIRECT_ARGS = D3D11_RESOURCE_MISC_DRAWINDIRECT_ARGS,
		BUFFER_ALLOW_RAW_VIEWS = D3D11_RESOURCE_MISC_BUFFER_ALLOW_RAW_VIEWS,
		BUFFER_STRUCTURED = D3D11_RESOURCE_MISC_BUFFER_STRUCTURED,
		RESOURCE_CLAMP = D3D11_RESOURCE_MISC_RESOURCE_CLAMP,
		SHARED_KEYEDMUTEX = D3D11_RESOURCE_MISC_SHARED_KEYEDMUTEX,
		GDI_COMPATIBLE = D3D11_RESOURCE_MISC_GDI_COMPATIBLE,
		SHARED_NTHANDLE = D3D11_RESOURCE_MISC_SHARED_NTHANDLE,
		RESTRICTED_CONTENT = D3D11_RESOURCE_MISC_RESTRICTED_CONTENT,
		RESTRICT_SHARED_RESOURCE = D3D11_RESOURCE_MISC_RESTRICT_SHARED_RESOURCE,
		RESTRICT_SHARED_RESOURCE_DRIVER = D3D11_RESOURCE_MISC_RESTRICT_SHARED_RESOURCE_DRIVER,
		GUARDED = D3D11_RESOURCE_MISC_GUARDED,
		TILE_POOL = D3D11_RESOURCE_MISC_TILE_POOL,
		TILED = D3D11_RESOURCE_MISC_TILED,
	};

	enum class ShaderIncludeMode {
		Local = D3D_INCLUDE_LOCAL,
		System = D3D_INCLUDE_SYSTEM
	};

	enum class BindFlags {
		None = 0,
		VertexBuffer = D3D11_BIND_VERTEX_BUFFER,
		IndexBuffer = D3D11_BIND_INDEX_BUFFER,
		UniformConstantBuffer = D3D11_BIND_CONSTANT_BUFFER,
		ShaderResource = D3D11_BIND_SHADER_RESOURCE,
		StreamOutput = D3D11_BIND_STREAM_OUTPUT,
		RenderBuffer = D3D11_BIND_RENDER_TARGET,
		DepthStencil = D3D11_BIND_DEPTH_STENCIL
	};

	enum class CpuAccessFlags {
		None = 0,
		Readable = D3D11_CPU_ACCESS_READ,
		Writable = D3D11_CPU_ACCESS_WRITE,
	};

	enum class ResourceMapping {
		Read = D3D11_MAP_READ,
		Write = D3D11_MAP_WRITE,
		ReadWrite = D3D11_MAP_READ_WRITE,
		WriteAndDiscard = D3D11_MAP_WRITE_DISCARD,
		WriteAndDiscardNoOverwrite = D3D11_MAP_WRITE_NO_OVERWRITE,
	};

	enum class IndexElementFormat {
		Zero = 0,
		EightBits = DXGI_FORMAT_R8_UINT,
		SixteenBits = DXGI_FORMAT_R16_UINT,
		ThirtyTwoBits = DXGI_FORMAT_R32_UINT,
		SixtyFourBits = DXGI_FORMAT_R32G32_UINT,
		Default = SixteenBits
	};

	enum class ResourceUsage {
		Default = D3D11_USAGE_DEFAULT,
		Immutable = D3D11_USAGE_IMMUTABLE,
		Dynamic = D3D11_USAGE_DYNAMIC,
		Staging = D3D11_USAGE_STAGING,
	};

	enum class ShaderResourceViewDimension {
		Unknown = D3D11_SRV_DIMENSION_UNKNOWN,
		Buffer = D3D11_SRV_DIMENSION_BUFFER,
		Texture1D = D3D11_SRV_DIMENSION_TEXTURE1D,
		Texture1DArray = D3D11_SRV_DIMENSION_TEXTURE1DARRAY,
		Texture2D = D3D11_SRV_DIMENSION_TEXTURE2D,
		Texture2DArray = D3D11_SRV_DIMENSION_TEXTURE2DARRAY,
		Texture2DMultiSampled = D3D11_SRV_DIMENSION_TEXTURE2DMS,
		Texture2DMultiSampledArray = D3D11_SRV_DIMENSION_TEXTURE2DMSARRAY,
		Texture3D = D3D11_SRV_DIMENSION_TEXTURE3D,
		TextureCube = D3D11_SRV_DIMENSION_TEXTURECUBE,
		TextureCubeArray = D3D11_SRV_DIMENSION_TEXTURECUBEARRAY,
		BufferExtended = D3D11_SRV_DIMENSION_BUFFEREX,
	};

	enum class RenderBufferViewDimension {
		Unknown = D3D11_RTV_DIMENSION_UNKNOWN,
		Buffer = D3D11_RTV_DIMENSION_BUFFER,
		Texture1D = D3D11_RTV_DIMENSION_TEXTURE1D,
		Texture1DArray = D3D11_RTV_DIMENSION_TEXTURE1DARRAY,
		Texture2D = D3D11_RTV_DIMENSION_TEXTURE2D,
		Texture2DArray = D3D11_RTV_DIMENSION_TEXTURE2DARRAY,
		Texture2DMultiSampled = D3D11_RTV_DIMENSION_TEXTURE2DMS,
		Texture2DMultiSampledArray = D3D11_RTV_DIMENSION_TEXTURE2DMSARRAY,
		Texture3D = D3D11_RTV_DIMENSION_TEXTURE3D,
	};

	enum class ResourceDimension {
		Unknown = D3D11_RESOURCE_DIMENSION_UNKNOWN,
		Buffer = D3D11_RESOURCE_DIMENSION_BUFFER,
		Texture1D = D3D11_RESOURCE_DIMENSION_TEXTURE1D,
		Texture2D = D3D11_RESOURCE_DIMENSION_TEXTURE2D,
		Texture3D = D3D11_RESOURCE_DIMENSION_TEXTURE3D,
	};

	enum class DepthStencilViewDimension {
		Unknown = D3D11_DSV_DIMENSION_UNKNOWN,
		Texture1D = D3D11_DSV_DIMENSION_TEXTURE1D,
		Texture1DArray = D3D11_DSV_DIMENSION_TEXTURE1DARRAY,
		Texture2D = D3D11_DSV_DIMENSION_TEXTURE2D,
		Texture2DArray = D3D11_DSV_DIMENSION_TEXTURE2DARRAY,
		Texture2DMultiSampled = D3D11_DSV_DIMENSION_TEXTURE2DMS,
		Texture2DMultiSampledArray = D3D11_DSV_DIMENSION_TEXTURE2DMSARRAY,
	};

	enum class ShaderCompilationFlags {
		None = 0x0,
		Debug = D3D10_SHADER_DEBUG,
		SkipValidation = D3D10_SHADER_SKIP_VALIDATION,
		NoOptimizations = D3D10_SHADER_SKIP_OPTIMIZATION,
		MatrixRowMajor = D3D10_SHADER_PACK_MATRIX_ROW_MAJOR,
		MatrixColumnMajor = D3D10_SHADER_PACK_MATRIX_COLUMN_MAJOR,
		LessAccurateFastMath = D3D10_SHADER_PARTIAL_PRECISION,
		ForceVertexSoftwareVersionDebug = D3D10_SHADER_FORCE_VS_SOFTWARE_NO_OPT,
		ForcePixelSoftwareVersionDebug = D3D10_SHADER_FORCE_PS_SOFTWARE_NO_OPT,
		DisableStaticOptomization = D3D10_SHADER_NO_PRESHADER,
		AvoidFlowControl = D3D10_SHADER_AVOID_FLOW_CONTROL,
		PreferFlowControl = D3D10_SHADER_PREFER_FLOW_CONTROL,
		Strict = D3D10_SHADER_ENABLE_STRICTNESS,
		BackwardsCompatibility = D3D10_SHADER_ENABLE_BACKWARDS_COMPATIBILITY,
		IEEEStrict = D3D10_SHADER_IEEE_STRICTNESS,
	};

	enum class DepthStencilFormat {
		None = 0,
		Depth16NoStencil = DXGI_FORMAT_D16_UNORM,
		Depth24Stencil8 = DXGI_FORMAT_D24_UNORM_S8_UINT,
		Depth32Stencil8 = DXGI_FORMAT_D32_FLOAT_S8X24_UINT,
	};

	enum class SurfaceFormat {
		Unknown = DXGI_FORMAT_UNKNOWN,
		Red8Green8Blue8Alpha8NormalizedsRGB = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB,
		Red8Green8Blue8Alpha8Normalized = DXGI_FORMAT_R8G8B8A8_UNORM,
		Red8Green8Blue8Alpha8UInt32 = DXGI_FORMAT_R8G8B8A8_UINT,
		Red8Green8Blue8Alpha8 = DXGI_FORMAT_R8G8B8A8_TYPELESS,
		Red8Green8Blue8NormalizedsRGB = DXGI_FORMAT_B8G8R8X8_UNORM_SRGB,
		Red8Green8Blue8Normalized = DXGI_FORMAT_B8G8R8X8_UNORM,
		Red8Green8Blue8 = DXGI_FORMAT_B8G8R8X8_TYPELESS,
		Red32Green32Blue32Alpha32 = DXGI_FORMAT_R32G32B32A32_FLOAT,
		Red16Green16Blue16Alpha16 = DXGI_FORMAT_R16G16B16A16_FLOAT,
		Red32Green32Blue32 = DXGI_FORMAT_R32G32B32_FLOAT,
		Red10Green10Blue10Alpha2Normalized = DXGI_FORMAT_R10G10B10A2_UNORM,
		Red10Green10Blue10Alpha2UInt32 = DXGI_FORMAT_R10G10B10A2_UINT,
		Red10Green10Blue10Alpha2 = DXGI_FORMAT_R10G10B10A2_TYPELESS,
		Blue8Green8Red8Alpha8NormalizedsRGB = DXGI_FORMAT_B8G8R8A8_UNORM_SRGB,
		Blue8Green8Red8Alpha8Normalized = DXGI_FORMAT_B8G8R8A8_UNORM,
		Blue8Green8Red8Alpha8 = DXGI_FORMAT_B8G8R8A8_TYPELESS,
		Blue5Green6Red5Alpha1Normalized = DXGI_FORMAT_B5G5R5A1_UNORM,
		Blue5Green6Red5Normalized = DXGI_FORMAT_B5G6R5_UNORM,
		Alpha8 = DXGI_FORMAT_A8_UNORM,
		Float = DXGI_FORMAT_R32_FLOAT,
		Red16Green16 = DXGI_FORMAT_R16G16_FLOAT,
		DXT1 = DXGI_FORMAT_BC1_TYPELESS,
		DXT2 = DXGI_FORMAT_BC1_TYPELESS,
		DXT3 = DXGI_FORMAT_BC2_TYPELESS,
		DXT4 = DXGI_FORMAT_BC2_TYPELESS,
		DXT5 = DXGI_FORMAT_BC3_TYPELESS,
		DXT1Normalized = DXGI_FORMAT_BC1_UNORM,
		DXT2Normalized = DXGI_FORMAT_BC1_UNORM,
		DXT3Normalized = DXGI_FORMAT_BC2_UNORM,
		DXT4Normalized = DXGI_FORMAT_BC2_UNORM,
		DXT5Normalized = DXGI_FORMAT_BC3_UNORM,
		DXT1NormalizedsRGB = DXGI_FORMAT_BC1_UNORM_SRGB,
		DXT2NormalizedsRGB = DXGI_FORMAT_BC1_UNORM_SRGB,
		DXT3NormalizedsRGB = DXGI_FORMAT_BC2_UNORM_SRGB,
		DXT4NormalizedsRGB = DXGI_FORMAT_BC2_UNORM_SRGB,
		DXT5NormalizedsRGB = DXGI_FORMAT_BC3_UNORM_SRGB,
		ATI1 = DXGI_FORMAT_BC4_TYPELESS,
		ATI2 = DXGI_FORMAT_BC5_TYPELESS,
		ATI1Normalized = DXGI_FORMAT_BC4_UNORM,
		ATI2Normalized = DXGI_FORMAT_BC5_UNORM,
		BlockCompression6HDR = DXGI_FORMAT_BC6H_TYPELESS,
		BlockCompression7 = DXGI_FORMAT_BC7_TYPELESS,
		Single = Float,
		Vector3 = Red32Green32Blue32,
		Vector4 = Red32Green32Blue32Alpha32,
		HalfVector4 = Red16Green16Blue16Alpha16,
		HalfVector2 = Red16Green16,
		FloatColor = Red32Green32Blue32Alpha32,
		ByteColor = Red8Green8Blue8Alpha8Normalized,
#ifdef FURROVINEFLOATCOLOR
		Color = FloatColor,
#else
		Color = ByteColor,
#endif
		Rgb = Red8Green8Blue8Normalized,
		Rgba = Red8Green8Blue8Alpha8Normalized,
		sRgb = Red8Green8Blue8NormalizedsRGB,
		sRgba = Red8Green8Blue8Alpha8NormalizedsRGB,
	};

	enum class VertexElementComponent {
		Unknown = D3D_REGISTER_COMPONENT_UNKNOWN,
		UInt = D3D_REGISTER_COMPONENT_UINT32,
		Int = D3D_REGISTER_COMPONENT_SINT32,
		Float = D3D_REGISTER_COMPONENT_FLOAT32,
		Double = 4,
		Byte = 5,
		Bool = 6,
		SByte = 7,
		Short = 8,
		UShort = 9,
		Half = 10
	};

	enum class VertexElementFormat {
		None = 0,
		Any = 0x7FFFFFFF,
		Bool = DXGI_FORMAT_R1_UNORM,
		Bool2 = -2,
		Bool3 = -3,
		Bool4 = -4,
		Int = DXGI_FORMAT_R32_SINT,
		Int2 = DXGI_FORMAT_R32G32_SINT,
		Int3 = DXGI_FORMAT_R32G32B32_SINT,
		Int4 = DXGI_FORMAT_R32G32B32A32_SINT,
		Point = Int2,
		Point3 = Int3,
		Point4 = Int4,
		UInt = DXGI_FORMAT_R32_UINT,
		UInt2 = DXGI_FORMAT_R32G32_UINT,
		UInt3 = DXGI_FORMAT_R32G32B32_UINT,
		UInt4 = DXGI_FORMAT_R32G32B32A32_UINT,
		Short = DXGI_FORMAT_R16_SINT,
		Short2 = DXGI_FORMAT_R16G16_SINT,
		Short4 = DXGI_FORMAT_R16G16B16A16_SINT,
		UShort = DXGI_FORMAT_R16_UINT,
		UShort2 = DXGI_FORMAT_R16G16_UINT,
		UShort4 = DXGI_FORMAT_R16G16B16A16_UINT,
		Half = DXGI_FORMAT_R16_FLOAT,
		Half2 = DXGI_FORMAT_R16G16_FLOAT,
		Half3 = -32,
		Half4 = DXGI_FORMAT_R16G16B16A16_FLOAT,
		Float = DXGI_FORMAT_R32_FLOAT,
		Float2 = DXGI_FORMAT_R32G32_FLOAT,
		Float3 = DXGI_FORMAT_R32G32B32_FLOAT,
		Float4 = DXGI_FORMAT_R32G32B32A32_FLOAT,
		Vector2 = Float2,
		Vector3 = Float3,
		Vector4 = Float4,
#ifdef FURROVINEFLOATCOLOR
		Color = Vector4,
#endif
		Float2x2 = -5,
		Float2x3 = -6,
		Float2x4 = -7,
		Float3x2 = -9,
		Float3x3 = -10,
		Float3x4 = -11,
		Float4x2 = -12,
		Float4x3 = -13,
		Float4x4 = -14,
		Double = -200,
		Double2 = -15,
		Double3 = -16,
		Double4 = -17,
		Double2x2 = -18,
		Double2x3 = -19,
		Double2x4 = -20,
		Double3x2 = -21,
		Double3x3 = -22,
		Double3x4 = -23,
		Double4x2 = -24,
		Double4x3 = -25,
		Double4x4 = -26,
		Byte = DXGI_FORMAT_R8_UNORM,
		Byte2 = DXGI_FORMAT_R8G8_UNORM,
		Byte3 = DXGI_FORMAT_B8G8R8X8_UNORM,
		Byte4 = DXGI_FORMAT_R8G8B8A8_UNORM,
		SByte = DXGI_FORMAT_R8_SNORM,
		SByte2 = DXGI_FORMAT_R8G8_SNORM,
		SByte3 = -30,
		SByte4 = DXGI_FORMAT_R8G8B8A8_SNORM,
#ifndef FURROVINEFLOATCOLOR
		Color = Byte4,
#endif
	};

	enumflagoperators( ClearFlags ); 
	enumflagoperators( DisplayFilterFlags );
	enumflagoperators( ResourceOptionFlags );
	enumflagoperators( CpuAccessFlags );
	enumflagoperators( BindFlags );
	enumflagoperators( ColorWriteChannels );
	enumflagoperators( ComparisonFlags );
	enumflagoperators( ShaderResourceFlags );
	enumflagoperators( ShaderVariableFlags );

	furrovineapi Graphics::FeatureLevel FromPlatform( FeatureLevel value );

	furrovineapi Graphics::ShaderVersion FromPlatform( ShaderVersion value );

	furrovineapi Graphics::ShaderVersion ShaderVersionFromPlatform( const String& longversion );

	furrovineapi Graphics::VertexDataUsage FromPlatform( VertexDataUsage value );

	furrovineapi Graphics::ShaderIncludeMode FromPlatform( ShaderIncludeMode value );

	furrovineapi Graphics::DepthWriteMask FromPlatform( DepthWriteMask value );

	furrovineapi Graphics::StencilOperation FromPlatform( StencilOperation value );

	furrovineapi Graphics::VertexElementFormat FromPlatform( VertexElementFormat value );

	furrovineapi Graphics::CpuAccessFlags FromPlatform( CpuAccessFlags value );

	furrovineapi Graphics::ShaderResourceFlags FromPlatform( ShaderResourceFlags value );

	furrovineapi Graphics::CullMode FromPlatform( CullMode value );

	furrovineapi Graphics::ClearFlags FromPlatform( ClearFlags value );

	furrovineapi Graphics::DepthStencilViewFlags FromPlatform( DepthStencilViewFlags value );

	furrovineapi Graphics::ColorWriteChannels FromPlatform( ColorWriteChannels value );

	furrovineapi Graphics::BlendOperation FromPlatform( BlendOperation value );

	furrovineapi Graphics::BlendFactor FromPlatform( BlendFactor value );

	furrovineapi Graphics::VertexElementComponent FromPlatform( VertexElementComponent value );

	furrovineapi Graphics::TextureFilter FromPlatform( TextureFilter value );

	furrovineapi Graphics::TextureAddress FromPlatform( TextureAddress value );

	furrovineapi Graphics::FillMode FromPlatform( FillMode value );

	furrovineapi Graphics::FrontFace FromPlatform( FrontFace value );

	furrovineapi Graphics::ShaderCompilationFlags FromPlatform( ShaderCompilationFlags value );

	furrovineapi Graphics::ShaderVariableFlags FromPlatform( ShaderVariableFlags value );

	furrovineapi Graphics::ShaderVariableType FromPlatform( ShaderVariableType value );

	furrovineapi Graphics::ShaderResourceType FromPlatform( ShaderResourceType value );

	furrovineapi Graphics::ShaderResourceReturnType FromPlatform( ShaderResourceReturnType value );

	furrovineapi Graphics::ShaderVariablePrimitive FromPlatform( ShaderVariablePrimitive value );

	furrovineapi Graphics::ShaderBufferType FromPlatform( ShaderBufferType value );

	furrovineapi Graphics::ShaderBufferFlags FromPlatform( ShaderBufferFlags value );

	furrovineapi Graphics::GraphicsDriverType FromPlatform( GraphicsDriverType value );

	furrovineapi Graphics::GraphicsDeviceCreationFlags FromPlatform( GraphicsDeviceCreationFlags value );

	furrovineapi Graphics::PrimitiveTopology FromPlatform( PrimitiveTopology value );

	furrovineapi Graphics::MonitorScaling FromPlatform( MonitorScaling value );

	furrovineapi Graphics::SurfaceScanlineOrder FromPlatform( SurfaceScanlineOrder value );

	furrovineapi Furrovine::Comparison FromPlatform( Comparison value );

	furrovineapi Graphics::ResourceMapping FromPlatform( ResourceMapping value );

	furrovineapi Graphics::ResourceUsage FromPlatform( ResourceUsage value );

	furrovineapi Graphics::ResourceOptionFlags FromPlatform( ResourceOptionFlags value );

	furrovineapi Graphics::MonitorRotation FromPlatform( MonitorRotation value );

	furrovineapi Graphics::ShaderResourceViewDimension FromPlatform( ShaderResourceViewDimension value );

	furrovineapi Graphics::UnorderedAccessViewDimension FromPlatform( UnorderedAccessViewDimension value );

	furrovineapi Graphics::RenderBufferViewDimension FromPlatform( RenderBufferViewDimension value );

	furrovineapi Graphics::DepthStencilViewDimension FromPlatform( DepthStencilViewDimension value );

	furrovineapi Graphics::ResourceDimension FromPlatform( ResourceDimension value );

	furrovineapi Graphics::BindFlags FromPlatform( BindFlags value );

	furrovineapi Graphics::SurfaceFormat FromPlatform( SurfaceFormat value );

	furrovineapi FeatureLevel ToPlatform( Graphics::FeatureLevel value );

	furrovineapi ClearFlags ToPlatform( Graphics::ClearFlags value );

	furrovineapi DepthStencilViewFlags ToPlatform( Graphics::DepthStencilViewFlags value );

	furrovineapi StencilOperation ToPlatform( Graphics::StencilOperation value );

	furrovineapi ColorWriteChannels ToPlatform( Graphics::ColorWriteChannels value );

	furrovineapi VertexElementComponent ToPlatform( Graphics::VertexElementComponent value );

	furrovineapi FillMode ToPlatform( Graphics::FillMode value );

	furrovineapi CullMode ToPlatform( Graphics::CullMode value );

	furrovineapi FrontFace ToPlatform( Graphics::FrontFace value );

	furrovineapi DepthWriteMask ToPlatform( Graphics::DepthWriteMask value );

	furrovineapi VertexDataUsage ToPlatform( Graphics::VertexDataUsage value );

	furrovineapi ShaderCompilationFlags ToPlatform( Graphics::ShaderCompilationFlags value );

	furrovineapi PrimitiveTopology ToPlatform( Graphics::PrimitiveTopology value );

	furrovineapi GraphicsDriverType ToPlatform( Graphics::GraphicsDriverType value );

	furrovineapi ShaderVariableFlags ToPlatform( Graphics::ShaderVariableFlags value );

	furrovineapi ShaderResourceFlags ToPlatform( Graphics::ShaderResourceFlags value );

	furrovineapi GraphicsDeviceCreationFlags ToPlatform( Graphics::GraphicsDeviceCreationFlags value );

	furrovineapi MonitorScaling ToPlatform( Graphics::MonitorScaling value );

	furrovineapi MonitorRotation ToPlatform( Graphics::MonitorRotation value );

	furrovineapi SurfaceScanlineOrder ToPlatform( Graphics::SurfaceScanlineOrder value );

	furrovineapi Comparison ToPlatform( Furrovine::Comparison value );

	furrovineapi ResourceMapping ToPlatform( Graphics::ResourceMapping value );

	furrovineapi ResourceUsage ToPlatform( Graphics::ResourceUsage value );

	furrovineapi ShaderResourceViewDimension ToPlatform( Graphics::ShaderResourceViewDimension value );

	furrovineapi UnorderedAccessViewDimension ToPlatform( Graphics::UnorderedAccessViewDimension value );

	furrovineapi RenderBufferViewDimension ToPlatform( Graphics::RenderBufferViewDimension value );

	furrovineapi DepthStencilViewDimension ToPlatform( Graphics::DepthStencilViewDimension value );

	furrovineapi ResourceDimension ToPlatform( Graphics::ResourceDimension value );

	furrovineapi ShaderIncludeMode ToPlatform( Graphics::ShaderIncludeMode value );

	furrovineapi ShaderVersion ToPlatform( Graphics::ShaderVersion value );

	furrovineapi ShaderVersion ToPlatform( Graphics::ShaderVersion value, Graphics::ShaderCompilationFlags flags );

	furrovineapi const String& ShaderVersionToPlatform( Graphics::ShaderVersion ver, Graphics::ShaderCompilationFlags flags );

	furrovineapi TextureAddress ToPlatform( Graphics::TextureAddress value );

	furrovineapi TextureFilter ToPlatform( Graphics::TextureFilter value );

	furrovineapi DepthStencilFormat ToPlatform( Graphics::DepthStencilFormat value );

	furrovineapi DisplayFilterFlags ToPlatform( Graphics::DisplayFilterFlags value );

	furrovineapi CpuAccessFlags ToPlatform( Graphics::CpuAccessFlags value );

	furrovineapi BindFlags ToPlatform( Graphics::BindFlags value );

	furrovineapi ResourceOptionFlags ToPlatform( Graphics::ResourceOptionFlags value );

	furrovineapi IndexElementFormat ToPlatform( Graphics::IndexElementFormat value );

	furrovineapi BlendOperation ToPlatform( Graphics::BlendOperation value );

	furrovineapi BlendFactor ToPlatform( Graphics::BlendFactor value );

	furrovineapi SurfaceFormat ToPlatform( Graphics::SurfaceFormat value );

	furrovineapi VertexElementFormat ToPlatform( Graphics::VertexElementFormat value );

	furrovineapi bool IsNormalized( VertexElementFormat format );

	template <typename T, typename TValue, typename... Tn>
	auto FromPlatform( TValue value, Tn&&... argn ) -> decltype( FromPlatform( static_cast<T>( value ), std::forward<Tn>( argn )... ) ) {
		return FromPlatform( static_cast<T>( value ), std::forward<Tn>( argn )... );
	}

	template <typename T, typename TValue, typename... Tn>
	auto ToPlatform( TValue value, Tn&&... argn ) -> decltype( static_cast<T>( ToPlatform( value, std::forward<Tn>( argn )... ) ) ) {
		return static_cast<T>( ToPlatform( value, std::forward<Tn>( argn )... ) );
	}

#endif // DIRECTX

}}}
