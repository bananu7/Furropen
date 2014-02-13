#pragma once

#include <Furrovine++/Graphics/Declarations.Graphics.h>
#include <Furrovine++/ptrptr.h>
#include <Furrovine++/Graphics/graphics_handle.h>
#include <Furrovine++/Platform.Graphics.h>

namespace Furrovine { namespace Graphics { namespace Dx {

#ifdef FURROVINEDIRECTX

	struct solid_color_brush_t { };
	const auto solid_color_brush = solid_color_brush_t{ };
	struct render_target_t { };
	const auto render_target = render_target_t{ };
	struct factory_t { };
	const auto factory = factory_t{ };
	struct text_factory_t { };
	const auto text_factory = text_factory_t{ };
	struct device_t { };
	const auto device = device_t{ };
	struct context_t { };
	const auto context = context_t{ };
	struct swap_chain_t { };
	const auto swap_chain = swap_chain_t{ };
	struct shader_resource_view_t { };
	const auto shader_resource_view = shader_resource_view_t{ };
	struct depth_stencil_view_t { };
	const auto depth_stencil_view = depth_stencil_view_t{ };
	struct render_buffer_view_t { };
	const auto render_buffer_view = render_buffer_view_t{ };
	struct depth_texture_t { };
	const auto depth_texture = depth_texture_t{ };
	struct texture_2d_t { };
	const auto texture_2d = texture_2d_t{ };
	struct vertex_t { };
	const auto vertex = vertex_t{ };
	struct hull_t { };
	const auto hull = hull_t{ };
	struct domain_t { };
	const auto domain = domain_t{ };
	struct geometry_t { };
	const auto geometry = geometry_t{ };
	struct pixel_t { };
	const auto pixel = pixel_t{ };
	struct compute_t { };
	const auto compute = compute_t{ };
	struct shader_reflection_t { };
	const auto shader_reflection = shader_reflection_t{ };

	template <typename T>
	struct ptrptr_cast {

		static T* to( graphics_handle a ) {
			return static_cast<T*>( a.dx );
		}

		static graphics_handle from( T* a ) {
			return graphics_handle( static_cast<void*>( a ) );
		}

	};

	template <typename TInternalPtr, typename TPtr>
	ptrptr_type<TPtr, TInternalPtr, ptrptr_cast<TInternalPtr>> ptrptr( TPtr& p ) { return ptrptr_type<TPtr, TInternalPtr, ptrptr_cast<TInternalPtr>>( p ); }

	namespace detail {

		furrovineapi ID3D11InputLayout* native_handle( const InputLayout&, graphics_handle target );
		furrovineapi ID3D11InputLayout* native_handle( const InputLayout& target );

		furrovineapi ID3D11ShaderReflection* native_handle( const ShaderResourceBuffer&, graphics_handle target );
		furrovineapi ID3D11ShaderReflection* native_handle( const ShaderResourceBuffer& target );

		furrovineapi ID3D11ShaderReflection* native_handle( const ShaderResource&, graphics_handle target );
		furrovineapi ID3D11ShaderReflection* native_handle( const ShaderResource& target );

		furrovineapi ID3D11ShaderReflectionVariable* native_handle( const ShaderVariable&, graphics_handle target );
		furrovineapi ID3D11ShaderReflectionVariable* native_handle( const ShaderVariable& target );

		furrovineapi ID3D11ShaderReflectionConstantBuffer* native_handle( const ShaderVariableBuffer&, graphics_handle target );
		furrovineapi ID3D11ShaderReflectionConstantBuffer* native_handle( const ShaderVariableBuffer& target );

		furrovineapi ID2D1DeviceContext* native_handle( const GraphicsDevice2D&, graphics_handle target, context_t hint );
		furrovineapi ID2D1DeviceContext* native_handle( const GraphicsDevice2D& target, context_t hint );
		furrovineapi ID2D1Device* native_handle( const GraphicsDevice2D&, graphics_handle target, device_t hint );
		furrovineapi ID2D1Device* native_handle( const GraphicsDevice2D& target, device_t hint );
		furrovineapi ID2D1Factory1* native_handle( const GraphicsDevice2D&, graphics_handle target, factory_t hint );
		furrovineapi ID2D1Factory1* native_handle( const GraphicsDevice2D& target, factory_t hint );
		furrovineapi ID2D1SolidColorBrush* native_handle( const GraphicsDevice2D&, graphics_handle target, solid_color_brush_t hint );
		furrovineapi ID2D1SolidColorBrush* native_handle( const GraphicsDevice2D& target, solid_color_brush_t hint );
		furrovineapi ID2D1RenderTarget* native_handle( const GraphicsDevice2D&, graphics_handle target, render_target_t hint );
		furrovineapi ID2D1RenderTarget* native_handle( const GraphicsDevice2D& target, render_target_t hint );

		furrovineapi ID3D11DeviceContext* native_handle( const GraphicsDevice&, graphics_handle target, context_t hint );
		furrovineapi ID3D11DeviceContext* native_handle( const GraphicsDevice& target, context_t hint );
		furrovineapi ID3D11Device* native_handle( const GraphicsDevice&, graphics_handle target, device_t hint );
		furrovineapi ID3D11Device* native_handle( const GraphicsDevice& target, device_t hint );
		furrovineapi IDXGISwapChain* native_handle( const GraphicsDevice&, graphics_handle target, swap_chain_t hint );
		furrovineapi IDXGISwapChain* native_handle( const GraphicsDevice& target, swap_chain_t hint );

		furrovineapi ID3D11SamplerState* native_handle( const SamplerState&, graphics_handle target );
		furrovineapi ID3D11SamplerState* native_handle( const SamplerState& target );

		furrovineapi ID3D11BlendState* native_handle( const BlendStateCollection&, graphics_handle target );
		furrovineapi ID3D11BlendState* native_handle( const BlendStateCollection& target );

		furrovineapi ID3D11RasterizerState* native_handle( const RasterizerState&, graphics_handle target );
		furrovineapi ID3D11RasterizerState* native_handle( const RasterizerState& target );

		furrovineapi ID3D11DepthStencilState* native_handle( const DepthStencilState&, graphics_handle target );
		furrovineapi ID3D11DepthStencilState* native_handle( const DepthStencilState& target );

		furrovineapi ID3D11DepthStencilView* native_handle( const DepthStencilBuffer&, graphics_handle target, depth_stencil_view_t );
		furrovineapi ID3D11DepthStencilView* native_handle( const DepthStencilBuffer& target, depth_stencil_view_t hint );
		furrovineapi ID3D11Texture2D* native_handle( const DepthStencilBuffer&, graphics_handle target, depth_texture_t );
		furrovineapi ID3D11Texture2D* native_handle( const DepthStencilBuffer& target, depth_texture_t hint );
		furrovineapi ID3D11Texture2D* native_handle( const DepthStencilBuffer&, graphics_handle target );
		furrovineapi ID3D11Texture2D* native_handle( const DepthStencilBuffer& target );

		furrovineapi ID3D11Texture2D* native_handle( const RenderBuffer2D&, graphics_handle target, depth_texture_t );
		furrovineapi ID3D11Texture2D* native_handle( const RenderBuffer2D& target, depth_texture_t hint );
		furrovineapi ID3D11Texture2D* native_handle( const RenderBuffer2D&, graphics_handle target, texture_2d_t );
		furrovineapi ID3D11Texture2D* native_handle( const RenderBuffer2D& target, texture_2d_t hint );
		furrovineapi ID3D11DepthStencilView* native_handle( const RenderBuffer2D&, graphics_handle target, depth_stencil_view_t );
		furrovineapi ID3D11DepthStencilView* native_handle( const RenderBuffer2D& target, depth_stencil_view_t hint );
		furrovineapi ID3D11RenderTargetView* native_handle( const RenderBuffer2D&, graphics_handle target, render_buffer_view_t );
		furrovineapi ID3D11RenderTargetView* native_handle( const RenderBuffer2D& target, render_buffer_view_t hint );
		furrovineapi ID3D11Texture2D* native_handle( const RenderBuffer2D& empty, graphics_handle target );
		furrovineapi ID3D11Texture2D* native_handle( const RenderBuffer2D& target );

		furrovineapi ID3D11Texture3D* native_handle( const Texture3D&, graphics_handle target );
		furrovineapi ID3D11Texture3D* native_handle( const Texture3D& target );

		furrovineapi ID3D11Texture2D* native_handle( const Texture2D&, graphics_handle target );
		furrovineapi ID3D11Texture2D* native_handle( const Texture2D& target );
		
		furrovineapi ID3D11Texture1D* native_handle( const Texture1D&, graphics_handle target );
		furrovineapi ID3D11Texture1D* native_handle( const Texture1D& target );

		furrovineapi ID3D11ShaderResourceView* native_handle( const ShaderResourceView&, graphics_handle target, shader_resource_view_t );
		furrovineapi ID3D11ShaderResourceView* native_handle( const ShaderResourceView& target, shader_resource_view_t hint );
		furrovineapi ID3D11ShaderResourceView* native_handle( const ShaderResourceView&, graphics_handle target );
		furrovineapi ID3D11ShaderResourceView* native_handle( const ShaderResourceView& target );

		furrovineapi ID3D11Buffer* native_handle( const GpuBuffer&, graphics_handle target );
		furrovineapi ID3D11Buffer* native_handle( const GpuBuffer& target );

		furrovineapi ID3D11Buffer* native_handle( const GpuMultiBuffer&, graphics_handle target );
		furrovineapi ID3D11Buffer* native_handle( const GpuMultiBuffer& target, ulword n = 0 );

		furrovineapi ID3D11VertexShader* native_handle( const Shader&, graphics_handle target, vertex_t );
		furrovineapi ID3D11VertexShader* native_handle( const Shader& target, vertex_t hint );

		furrovineapi ID3D11HullShader* native_handle( const Shader&, graphics_handle target, hull_t );
		furrovineapi ID3D11HullShader* native_handle( const Shader& target, hull_t hint );

		furrovineapi ID3D11DomainShader* native_handle( const Shader&, graphics_handle target, domain_t );
		furrovineapi ID3D11DomainShader* native_handle( const Shader& target, domain_t hint );

		furrovineapi ID3D11GeometryShader* native_handle( const Shader&, graphics_handle target, geometry_t );
		furrovineapi ID3D11GeometryShader* native_handle( const Shader& target, geometry_t hint );

		furrovineapi ID3D11PixelShader* native_handle( const Shader&, graphics_handle target, pixel_t );
		furrovineapi ID3D11PixelShader* native_handle( const Shader& target, pixel_t hint );

		furrovineapi ID3D11ComputeShader* native_handle( const Shader&, graphics_handle target, compute_t );
		furrovineapi ID3D11ComputeShader* native_handle( const Shader& target, compute_t hint );

		furrovineapi IDXGIAdapter* native_handle( const GraphicsAdapter&, graphics_handle target );
		furrovineapi IDXGIAdapter* native_handle( const GraphicsAdapter& target );

		furrovineapi IDXGIOutput* native_handle( const GraphicsAdapterOutput&, graphics_handle target );
		furrovineapi IDXGIOutput* native_handle( const GraphicsAdapterOutput& target );

		template <typename TR, typename T, typename... Tn>
		inline TR native_handle( T* target, Tn&&... argn ) {
			return target == null ? null : detail::native_handle( *target, std::forward<Tn>( argn )... );
		}

	}

	template <typename T, typename... Tn>
	inline auto native_handle( T& target, Tn&&... argn )
	-> decltype( detail::native_handle( target, std::forward<Tn>( argn )... ) ) {
		return detail::native_handle( target, std::forward<Tn>( argn )... );
	}

	template <typename T, typename... Tn>
	inline auto native_handle( T* target, Tn&&... argn )
	-> decltype( detail::native_handle( *target, std::forward<Tn>( argn )... ) ) {
		typedef decltype( detail::native_handle( *target, std::forward<Tn>( argn )... ) ) TR;
		return detail::native_handle<TR>( target, std::forward<Tn>( argn )... );
	}

	template <typename T, typename... Tn>
	inline auto native_handle( graphics_handle target, Tn&&... argn )
	-> decltype( detail::native_handle( null_ref<T>::value, target, std::forward<Tn>( argn )... ) ) {
		return detail::native_handle( null_ref<T>::value, target, std::forward<Tn>( argn )... );
	}

	template <typename... Tn>
	inline auto rnative_handle( Tn&&... argn )
	-> decltype( *native_handle( std::forward<Tn>( argn )... ) ) {
		return *native_handle( std::forward<Tn>( argn )... );
	}

	template <typename T, typename... Tn>
	inline auto rnative_handle( Tn&&... argn )
	-> decltype( *native_handle<T>( std::forward<Tn>( argn )... ) ) {
		return *native_handle<T>( std::forward<Tn>( argn )... );
	}

#endif // DIRECTX

}}}