#pragma once

#include <Furrovine++/Platform.Graphics.h>
#include <Furrovine++/Graphics/BindFlags.h>
#include <Furrovine++/Graphics/CPUAccessFlags.h>
#include <Furrovine++/Graphics/ResourceUsage.h>
#include <Furrovine++/Graphics/ResourceOptionFlags.h>
#include <Furrovine++/make_array.h>
#include <Furrovine++/unreachable.h>
#include <Furrovine++/UnsupportedException.h>

namespace Furrovine { namespace Graphics { namespace Gl {

#ifdef FURROVINEOPENGL

	enum class FillMode {
		Point = gl::POINT,
		Wireframe = gl::LINE,
		Solid = gl::FILL
	};

	enum class VertexElementComponent {
		Unknown = 0x14,
		UInt = gl::UNSIGNED_INT,
		Int = gl::INT,
		Float = gl::FLOAT,
		Double = gl::DOUBLE,
		Byte = gl::UNSIGNED_BYTE,
		Bool = gl::UNSIGNED_BYTE,
		SByte = gl::BYTE,
		Short = gl::SHORT,
		UShort = gl::UNSIGNED_SHORT,
		Half = gl::HALF_FLOAT,
	};

	enum class CullMode {
		None = 0,
		Front = gl::FRONT,
		Back = gl::BACK,
	};


	enum class MaterialOrientation {
		Front = gl::FRONT,
		Back = gl::BACK,
		FrontAndBack = gl::FRONT_AND_BACK
	};

	enum class IndexElementFormat {
		EightBits = gl::UNSIGNED_BYTE,
		SixteenBits = gl::UNSIGNED_SHORT,
		ThirtyTwoBits = gl::UNSIGNED_INT,
		Default = SixteenBits
	};

	enum class CpuAccessFlags {
		None = 0x0,
		Read = gl::MAP_READ_BIT,
		Write = gl::MAP_WRITE_BIT,
		ReadWrite = Read | Write,
	};

	enum class ResourceUsage {
		StreamDraw = gl::STREAM_DRAW,
		StreamRead = gl::STREAM_READ,
		StreamCopy = gl::STREAM_COPY,
		StaticDraw = gl::STATIC_DRAW,
		StaticRead = gl::STATIC_READ,
		StaticCopy = gl::STATIC_COPY,
		DynamicDraw = gl::DYNAMIC_DRAW,
		DynamicRead = gl::DYNAMIC_READ,
		DynamicCopy = gl::DYNAMIC_COPY
	};

	enum class PrimitiveTopology {
		Points = gl::POINTS,
		PointList = Points,
		Lines = gl::LINES,
		LineList = Lines,
		LineStrip = gl::LINE_STRIP,
		Triangle = gl::TRIANGLES,
		TriangleStrip = gl::TRIANGLE_STRIP,
		TriangleFan = gl::TRIANGLE_FAN,
		Quad = gl::QUADS,
	};

	enum class BindTarget {
		VertexBuffer = gl::ARRAY_BUFFER,
		IndexBuffer = gl::ELEMENT_ARRAY_BUFFER,
		UniformConstantBuffer = gl::UNIFORM_BUFFER,
		StorageBuffer = gl::SHADER_STORAGE_BUFFER,
		TransformStreamOutput = gl::TRANSFORM_FEEDBACK_BUFFER,
		RenderBuffer = gl::RENDERBUFFER,
		DepthStencil = gl::DEPTH_STENCIL,
	};

	BindTarget ToPlatform( Graphics::BindFlags bindflags, bool& shaderresource ) {
		shaderresource = HasFlags( bindflags, Graphics::BindFlags::ShaderResource );
		if ( HasFlags( bindflags, Graphics::BindFlags::VertexBuffer ) ) {
			return BindTarget::VertexBuffer;
		}
		else if ( HasFlags( bindflags, Graphics::BindFlags::IndexBuffer ) ) {
			return BindTarget::IndexBuffer;
		}
		else if ( HasFlags( bindflags, Graphics::BindFlags::UniformConstantBuffer ) ) {
			return BindTarget::UniformConstantBuffer;
		}
		else if ( HasFlags( bindflags, Graphics::BindFlags::TransformStreamOutput ) ) {
			return BindTarget::TransformStreamOutput;
		}
		else if ( HasFlags( bindflags, Graphics::BindFlags::RenderBuffer ) ) {
			return BindTarget::RenderBuffer;
		}
		else if ( HasFlags( bindflags, Graphics::BindFlags::DepthStencil ) ) {
			return BindTarget::DepthStencil;
		}
		throw UnsupportedException( "Unknown buffer flag" );
	}

	BindTarget ToPlatform( Graphics::BindFlags value ) {
		bool shaderresource;
		return ToPlatform( value, shaderresource );
	}

	CpuAccessFlags ToPlatform( Graphics::CpuAccessFlags plat, Graphics::ResourceOptionFlags options ) {
		const static auto platformlookup = make_array(
			CpuAccessFlags::Read,
			CpuAccessFlags::Write
		);
		return accumulate_flags( plat, platformlookup );
	}

	CpuAccessFlags ToPlatform( Graphics::CpuAccessFlags value ) {
		return ToPlatform( value, Graphics::ResourceOptionFlags::None );
	}

	ResourceUsage ToPlatform( Graphics::ResourceUsage value ) {
		switch ( value ) {
		case Graphics::ResourceUsage::Default:
			return ResourceUsage::StaticDraw;
		case Graphics::ResourceUsage::Immutable:
			return ResourceUsage::StaticDraw;
		case Graphics::ResourceUsage::Dynamic:
			return ResourceUsage::DynamicDraw;
		case Graphics::ResourceUsage::Staging:
			return ResourceUsage::StaticCopy;
		}
		unreachable;
	}

	template <typename T, typename TValue, typename... Tn>
	auto FromPlatform( TValue value, Tn&&... argn ) -> decltype( FromPlatform( static_cast<T>( value ), std::forward<Tn>( argn )... ) ) {
		return FromPlatform( static_cast<T>(value)std::forward<Tn>( argn )... );
	}

	template <typename T, typename TValue, typename... Tn>
	auto ToPlatform( TValue value, Tn&&... argn ) -> decltype( static_cast<T>( ToPlatform( value, std::forward<Tn>( argn )... ) ) ) {
		return static_cast<T>( ToPlatform( value, std::forward<Tn>( argn )... ) );
	}

#endif // OPENGL

}}}