#pragma once

#include <Furrovine++/ptr.h>
#include <Furrovine++/handle.h>
#include <Furrovine++/Graphics/graphics_handle.h>
#include <Furrovine++/optional.h>
#include <Furrovine++/runtime_type.h>
#include <Furrovine++/Color.h>
#include <Furrovine++/Region.h>
#include <Furrovine++/Viewport.h>
#include <Furrovine++/Graphics/Declarations.Graphics.h>
#include <Furrovine++/Graphics/Constants.h>
#include <Furrovine++/Graphics/Buffering.h>
#include <Furrovine++/Graphics/GraphicsDeviceCreationFlags.h>
#include <Furrovine++/Graphics/GraphicsDriverType.h>
#include <Furrovine++/Graphics/PrimitiveTopology.h>
#include <Furrovine++/Graphics/Primitives.h>
#include <Furrovine++/Graphics/ResourceUsage.h>
#include <Furrovine++/Graphics/CpuAccessFlags.h>
#include <Furrovine++/Graphics/DisplayFilterFlags.h>
#include <Furrovine++/Graphics/FeatureLevel.h>
#include <Furrovine++/Graphics/FillMode.h>
#include <Furrovine++/Graphics/CullMode.h>
#include <Furrovine++/Graphics/ClearFlags.h>
#include <Furrovine++/Graphics/ShaderVersion.h>
#include <Furrovine++/Graphics/ColorWriteChannels.h>
#include <Furrovine++/Graphics/GraphicsAdapter.h>
#include <Furrovine++/Graphics/GraphicsCapability.h>
#include <Furrovine++/Graphics/ShaderStage.h>
#include <Furrovine++/Graphics/GraphicsRuntime.h>
#include <Furrovine++/Graphics/GraphicsDeviceSettings.h>
#include <Furrovine++/Graphics/ConstantBufferState.h>

namespace Furrovine { namespace Graphics {
	
	class GraphicsDevice {
	public:
		furrovineapi static const MultisampleDescription DefaultMultisampleDescription;
		furrovineapi static const bool DefaultVerticalSync = true;
		furrovineapi static const ulword BackBufferIndex = 0;
		furrovineapi static const GraphicsCapability FeatureLevelCapabilities[ 7 ];
		furrovineapi static const Color DefaultClearColor;
		furrovineapi static const byte DefaultClearStencil;
		furrovineapi static const float DefaultClearDepth;
		furrovineapi static const SurfaceFormat DefaultSurfaceFormat = SurfaceFormat::Red8Green8Blue8Alpha8Normalized;

	private:
		struct swap_chain_deleter {
			furrovineapi void operator()( graphics_handle p );
		};

		struct device_deleter {
			furrovineapi void operator()( graphics_handle p );
		};

		struct device_context_deleter {
			furrovineapi void operator()( graphics_handle p );
		};

		const GraphicsCapability* capabilities;
		
		GraphicsDeviceCreationFlags creationflags;
		DisplayFilterFlags displaymodeflags;
		GraphicsDriverType drivertype;
		FeatureLevel featurelevel;
		Buffering framebuffering;
		bool vsync;
		MultisampleDescription msdesc;
		GraphicsDeviceSettings settings;
		
		IWindow* targetwindow;

		std::vector<GraphicsAdapter> adapters;
		handle<graphics_handle, swap_chain_deleter> swapchainresource;
		handle<graphics_handle, device_deleter> deviceresource;
		handle<graphics_handle, device_context_deleter> devicecontextresource;
		
		std::array<RenderBuffer2D*, detail::SimultaneousRenderTargets> rendertargets;
		std::array<graphics_handle, detail::SimultaneousRenderTargets> irendertargets;
		std::array<graphics_handle, detail::SimultaneousRenderTargets> idepthstencils;
		std::unordered_map<graphics_handle, std::pair<ShaderStage, ulword>> inputrendertargetsrvs; 
		std::unordered_map<graphics_handle, ulword> outputrendertargetsrvs; 
		ConstantBufferState constantbuffers;
		ptr<RenderBuffer2D> backbuffer;
		ptr<DepthStencilBuffer> depthstencilbuffer;
		ptr<DepthStencilState> depthstencilstate;
		ptr<RasterizerState> rasterizerstate;
		ptr<BlendStateCollection> blendstatecollection;
		ptr<SamplerStateCollection> samplerstatecollection;
		ptr<ShaderResourceViewCollection> resourcecollection;
		bool hassetdepthstencil;
		bool hassetrasterizer;
		bool hassetblendstate;
		bool hassetsamplerstate;

		const InputLayout* activelayout;
		ulword activert;
		std::unique_ptr<VertexShader> renderimagevertexshader;
		std::unique_ptr<PixelShader> renderimagepixelshader;
		ShaderParameter* renderimagetexture0;
		ShaderParameter* renderimageviewprojection;
		std::unordered_map<runtime_type, ulword> instantindices;
		std::vector<VertexBuffer> instantvtxbuffers;
		std::vector<IndexBuffer> instantidxbuffers;	
		const IndexBuffer* idxbuffer;
		graphics_handle iidxbuffer;
		uint32 idxoffset;
		uint32 idxbyteoffset;
		const VertexBuffer* vtxbuffer;
		std::array<graphics_handle, 32> vtxbufferhandles;
		std::array<uint32, 32> vtxbufferstrides;
		std::array<uint32, 32> vtxbufferoffsets;
		std::array<uint32, 32> vtxbufferbyteoffsets;
		std::array<Viewport, 32> viewports;
		Shader* vertexshader;
		Shader* hullshader;
		Shader* domainshader;
		Shader* geometryshader;
		Shader* pixelshader;
		Shader* computeshader;
		Viewport viewport;

	protected:
		
		furrovineapi void EnsureLayout ( const VertexDeclaration& declaration, InputLayout*& layout );
		furrovineapi static void BestDisplay ( const std::vector<GraphicsAdapter>& adapters, GraphicsDeviceSettings& settings );
		furrovineapi bool Create( IWindow& window );

	public:

		Event<const std::vector<GraphicsAdapter>&, GraphicsDeviceSettings&> PrepareDeviceSettings;
		
		furrovineapi GraphicsDevice(
			IWindow& window,
			FeatureLevel level = FeatureLevel::LevelDx111,
			bool verticalsync = DefaultVerticalSync, const MultisampleDescription& multisampling = DefaultMultisampleDescription,
			Buffering buffering = Buffering::Double,
			DisplayFilterFlags filterflags = DisplayFilterFlags::Interlaced,
			GraphicsDeviceCreationFlags createflags = GraphicsDeviceCreationFlags::BlueGreenRedAlphaSupport
#ifdef FURROVINEDEBUG
			| GraphicsDeviceCreationFlags::Debug
#else
			| GraphicsDeviceCreationFlags::None
#endif // FURROVINEDEBUG 
			,
			GraphicsDriverType drivertype = GraphicsDriverType::Hardware
			);

		furrovineapi graphics_handle DeviceContextResource( ) const;
		furrovineapi graphics_handle DeviceResource( ) const;
		furrovineapi graphics_handle SwapChainResource( ) const;
		furrovineapi bool HasDeviceContextResource( ) const;
		furrovineapi bool HasDeviceResource( ) const;
		furrovineapi bool HasSwapChainResource( ) const;
		
		furrovineapi bool Ready( ) const;

		furrovineapi FeatureLevel Feature( );
		furrovineapi ShaderVersion BestShaderVersion( );

		furrovineapi void Clear ( const Color& color = DefaultClearColor, float depth = DefaultClearDepth, byte stencil = DefaultClearStencil );
		furrovineapi void Clear ( ClearFlags clearflags, const Color& color, float depth = DefaultClearDepth, byte stencil = DefaultClearStencil );
		furrovineapi void Clear( float depth );
		furrovineapi void Clear( byte stencil );
		furrovineapi void ClearColor( const Color& color = DefaultClearColor );
		furrovineapi void ClearStencil( byte stencil = DefaultClearStencil );
		furrovineapi void ClearDepth( float depth = DefaultClearDepth );

		furrovineapi void Clear( RenderBuffer2D& target, const Color& color = DefaultClearColor );
		furrovineapi void Clear( DepthStencilBuffer& target, float depth = DefaultClearDepth, byte stencil = DefaultClearStencil );
		furrovineapi void Clear( DepthStencilBuffer& target, ClearFlags clearflags, float depth = DefaultClearDepth, byte stencil = DefaultClearStencil );
		furrovineapi void ClearDepth( DepthStencilBuffer& target, float depth = DefaultClearDepth );
		furrovineapi void ClearStencil( DepthStencilBuffer& target, byte stencil = DefaultClearStencil );
		furrovineapi void ClearColor ( RenderBuffer2D& target, const Color& color = DefaultClearColor );
		furrovineapi void ClearDepthStencil( DepthStencilBuffer& target, float depth = DefaultClearDepth, byte stencil = DefaultClearStencil );
		furrovineapi void ClearRenderTarget( ulword index );
		furrovineapi void ClearRenderTarget ( ulword index, const Color& color );
		
		furrovineapi RenderBuffer2D& BackBuffer( );
		furrovineapi DepthStencilBuffer& BackBufferDepthStencil( );

		furrovineapi void Present ();
		furrovineapi void Flush ();

		furrovineapi void SetViewport( Viewport port );
		furrovineapi void SetViewports( Viewport* ports, ulword count );
		furrovineapi Viewport GetViewport ();
		furrovineapi void GetViewports ( Viewport* viewports, ulword start, ulword count );
		furrovineapi void GetViewports ( Viewport* viewports, ulword count );
		
		furrovineapi void SetVertexBuffer( const VertexBuffer& vertexbuffer, uint32 offset = 0 );
		furrovineapi void SetVertexBuffer( const VertexBuffer* vertexbuffer, uint32 offset = 0 );
		furrovineapi void SetIndexBuffer( const IndexBuffer& indexbuffer, uint32 offset = 0 );
		furrovineapi void SetIndexBuffer( const IndexBuffer* indexbuffer, uint32 offset = 0 );

		furrovineapi void SetShaderPass ( ShaderPass& pass );
		furrovineapi void ClearShaderPass( );
		furrovineapi void SetShader( Shader& shader );
		furrovineapi void ClearShader( ShaderStage stage );

		furrovineapi void SetResource( ShaderResourceView* resource, ulword index = 0, ShaderStage method = ShaderStage::Pixel );
		furrovineapi void SetResource( ShaderResourceView& resource, ulword index = 0, ShaderStage method = ShaderStage::Pixel );
		furrovineapi void SetRawResource( ShaderResourceView* origin, graphics_handle rawresource, ulword index = 0, ShaderStage method = ShaderStage::Pixel );

		furrovineapi ShaderResourceView& GetResource( ulword index = 0, ShaderStage method = ShaderStage::Pixel );
		furrovineapi ShaderResourceView* TryGetResource( ulword index = 0, ShaderStage method = ShaderStage::Pixel );

		furrovineapi void SetRenderBuffer( RenderBuffer2D& rendertarget, ulword index = 0 );
		furrovineapi void SetRenderBuffer( RenderBuffer2D* rendertarget, ulword index = 0 );

		furrovineapi void SetDepthStencilBuffer( DepthStencilBuffer& target );
		furrovineapi void SetDepthStencilBuffer( DepthStencilBuffer* target );

		furrovineapi void SetRasterizer( const RasterizerState& value );
		furrovineapi void SetDepthStencil ( const DepthStencilState& value );
		furrovineapi void SetBlend( const BlendState& value, ulword rendertargetindex = 0 );
		furrovineapi void SetSampler( const SamplerState& value, ulword rendertargetindex = 0, ShaderStage shader = ShaderStage::Pixel );
		
		furrovineapi void SetConstantBuffers( GpuBuffer& buffer, ulword index = 0, ShaderStage shader = ShaderStage::Vertex );
		furrovineapi void SetConstantBuffers( GpuBuffer* buffer, ulword count, ulword index = 0, ShaderStage shader = ShaderStage::Vertex );
		furrovineapi void ApplyConstantBuffers ();

		furrovineapi const RasterizerState& GetRasterizer ( );
		furrovineapi const DepthStencilState& GetDepthStencil ( );
		furrovineapi const BlendState& GetBlend ( ulword index = 0 );
		furrovineapi const SamplerState& GetSampler ( ulword index = 0 );
		furrovineapi const BlendStateCollection& GetBlendCollection ( );
		furrovineapi const SamplerStateCollection& GetSamplerCollection ( );

		furrovineapi void SetInputLayout ( const InputLayout& inputlayout );
		furrovineapi void SetInputLayout ( const InputLayout* inputlayout );
		furrovineapi void RawSetInputLayout ( graphics_handle inputlayout );
		furrovineapi void RenderImage( const Image2D& image );
		furrovineapi void RenderImage( const Image2D& image, const Region& bounds );
		furrovineapi void RenderImage( const Image2D& image, const Region& bounds, const Region& source );
		furrovineapi void RenderImage( Texture2D& texture );
		furrovineapi void RenderImage( Texture2D& texture, const Region& bounds );
		furrovineapi void RenderImage( Texture2D& texture, const Region& bounds, const Region& source );
		furrovineapi void RenderPrimitives( PrimitiveTopology primitive, uint32 startvertex, uint32 primitivecount );
		furrovineapi void RenderPrimitives ( PrimitiveTopology primitive, const VertexDeclaration& declaration, uint32 startvertex, uint32 primitivecount );
		furrovineapi void RenderPrimitives ( PrimitiveTopology primitive, const InputLayout& declaration, uint32 startvertex, uint32 primitivecount );
		furrovineapi void RawRenderPrimitives ( PrimitiveTopology primitive, uint32 startvertex, uint32 primitivecount );
		furrovineapi void RawRenderVertices ( PrimitiveTopology primitive, uint32 startvertex, uint32 primitivecount );
		furrovineapi void RenderIndexedPrimitives ( PrimitiveTopology primitive, uint32 basevertex, uint32 vertexoffset, uint32 vertexcount, uint32 startindex, uint32 primitivecount );
		furrovineapi void RenderIndexedPrimitives ( PrimitiveTopology primitive, const VertexDeclaration& declaration, uint32 basevertex, uint32 vertexoffset, uint32 vertexcount, uint32 startindex, uint32 primitivecount );
		furrovineapi void RenderIndexedPrimitives ( PrimitiveTopology primitive, const InputLayout& declaration, uint32 basevertex, uint32 vertexoffset, uint32 vertexcount, uint32 startindex, uint32 primitivecount );
		furrovineapi void RawRenderIndexedPrimitives ( PrimitiveTopology primitive, uint32 basevertex, uint32 vertexoffset, uint32 vertexcount, uint32 startindex, uint32 primitivecount );
		furrovineapi void RawRenderIndexedVertices ( PrimitiveTopology primitive, uint32 basevertex, uint32 vertexoffset, uint32 vertexcount, uint32 startindex, uint32 indexcount );
		template <typename TVertex>
		void RenderUserPrimitives ( PrimitiveTopology primitive, TVertex* vertices, uint32 vertexoffset, uint32 primitivecount );
		template <typename TVertex>
		void RenderUserPrimitives ( PrimitiveTopology primitive, const VertexDeclaration& declaration, TVertex* vertices, uint32 vertexoffset, uint32 primitivecount );
		furrovineapi void RenderUserPrimitives( PrimitiveTopology primitive, const VertexDeclaration& declaration, VertexBuffer& vbuffer, uint32 basevertex, uint32 vertexoffset, uint32 primitivecount );
		
		template <typename TVertex, typename TIndex>
		void RenderUserIndexedPrimitives ( PrimitiveTopology primitive, TVertex* vertices, uint32 vertexoffset, uint32 vertexcount, TIndex* indices, uint32 startindex, uint32 primitivecount );
		template <typename TVertex, typename TIndex> 
		void RenderUserIndexedPrimitives ( PrimitiveTopology primitive, TVertex* vertices, uint32 basevertex, uint32 vertexoffset, uint32 vertexcount, TIndex* indices, uint32 startindex, uint32 primitivecount );
		template <typename TVertex, typename TIndex> 
		void RenderUserIndexedPrimitives ( PrimitiveTopology primitive, const VertexDeclaration& declaration, TVertex* vertices, uint32 basevertex, uint32 vertexoffset, uint32 vertexcount, TIndex* indices, uint32 startindex, uint32 primitivecount );
		furrovineapi void RenderUserIndexedPrimitives( PrimitiveTopology primitive, const VertexDeclaration& declaration, VertexBuffer& vbuffer, uint32 basevertex, uint32 vertexoffset, uint32 vertexcount, IndexBuffer& indices, uint32 startindex, uint32 primitivecount );

		furrovineapi const GraphicsCapability& Capabilities ( ) const;

		furrovineapi ~GraphicsDevice();

	};

}}
