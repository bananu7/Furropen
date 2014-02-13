#pragma once

#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Graphics {
	
	enum class VertexElementFormat {
		None,
		Any,
		Bool,
		Bool2,
		Bool3,
		Bool4,
		Int,
		Int2,
		Int3,
		Int4,
		Point = Int2,
		Point3 = Int3,
		Point4 = Int4,
		UInt,
		UInt2,
		UInt3,
		UInt4,
		Short,
		Short2,
		Short4,
		UShort,
		UShort2,
		UShort4,
		Half,
		Half2,
		Half3,
		Half4,
		Float,
		Float2,
		Float3,
		Float4,
		Vector2 = Float2,
		Vector3 = Float3,
		Vector4 = Float4,
#ifdef FURROVINEFLOATCOLOR
		Color = Vector4,
#endif
		Float2x2,
		Float2x3,
		Float2x4,
		Float3x2,
		Float3x3,
		Float3x4,
		Float4x2,
		Float4x3,
		Float4x4,
		Double,
		Double2,
		Double3,
		Double4,
		Double2x2,
		Double2x3,
		Double2x4,
		Double3x2,
		Double3x3,
		Double3x4,
		Double4x2,
		Double4x3,
		Double4x4,
		Byte,
		Byte2,
		Byte3,
		Byte4,
		SByte,
		SByte2,
		SByte3,
		SByte4,
#ifndef FURROVINEFLOATCOLOR
		Color = Byte4,
#endif
	};

	inline furrovineapi ulword ToByteSize ( VertexElementFormat format, bool normalized = true ) {
		int bytesize = 0;
		switch (format) {
		case VertexElementFormat::Bool:
			bytesize = 1;
			break;
		case VertexElementFormat::SByte:
		case VertexElementFormat::Byte:
			bytesize = normalized ? 4 : 1;
			break;
		case VertexElementFormat::Bool2:
			bytesize = 2;
			break;
		case VertexElementFormat::Half:
			bytesize = normalized ? 4 : 2;
			break;
		case VertexElementFormat::SByte2:
		case VertexElementFormat::Byte2:
			bytesize = normalized ? 8 : 2;
			break;
		case VertexElementFormat::Bool3:
			bytesize = 3;
			break;
		case VertexElementFormat::SByte3:
		case VertexElementFormat::Byte3:
			bytesize = normalized ? 12 : 3;
			break;
		case VertexElementFormat::Half2:
			bytesize = normalized ? 8 : 4;
			break;
		case VertexElementFormat::SByte4:
		case VertexElementFormat::Byte4:
			bytesize = normalized ? 16 : 4;
		case VertexElementFormat::Bool4:
		case VertexElementFormat::Float:
		case VertexElementFormat::Int:
		case VertexElementFormat::UInt:
			bytesize = 4;
			break;
		case VertexElementFormat::Float2:
		case VertexElementFormat::Double:
		case VertexElementFormat::Int2:
		case VertexElementFormat::UInt2:
			bytesize = 8;
			break;
		case VertexElementFormat::Float3:
		case VertexElementFormat::Int3:
		case VertexElementFormat::UInt3:
			bytesize = 12;
			break;
		case VertexElementFormat::Float4:
		case VertexElementFormat::Double2:
		case VertexElementFormat::Int4:
		case VertexElementFormat::UInt4:
			bytesize = 16;
			break;
		case VertexElementFormat::Float2x3:
		case VertexElementFormat::Float3x2:
			bytesize = 20;
		case VertexElementFormat::Double3:
		case VertexElementFormat::Float3x3:
			bytesize = 24;
		case VertexElementFormat::Float4x3:
		case VertexElementFormat::Float3x4:
			bytesize = 28;
			break;
		case VertexElementFormat::Double2x2:
		case VertexElementFormat::Double4:
		case VertexElementFormat::Float4x4:
			bytesize = 32;
		case VertexElementFormat::Double2x3:
		case VertexElementFormat::Double3x2:
			bytesize = 40;
			break;
		case VertexElementFormat::Double3x3:
			bytesize = 48;
			break;
		case VertexElementFormat::Double4x3:
		case VertexElementFormat::Double3x4:
			bytesize = 56;
			break;
		case VertexElementFormat::Double4x4:
			bytesize = 64;
			break;
		default:
			bytesize = 0;
			break;
		}
		return bytesize;
	}

	inline furrovineapi std::pair<VertexElementComponent, ulword> ToComponents( VertexElementFormat format ) {
		std::pair<VertexElementComponent, ulword> desc;
		switch ( format ) {
		case VertexElementFormat::Bool:
			desc.second = 1;
			desc.first = VertexElementComponent::Bool;
			break;
		case VertexElementFormat::Bool2:
			desc.second = 2;
			desc.first = VertexElementComponent::Bool;
			break;
		case VertexElementFormat::Bool3:
			desc.second = 3;
			desc.first = VertexElementComponent::Bool;
			break;
		case VertexElementFormat::Bool4:
			desc.second = 4;
			desc.first = VertexElementComponent::Bool;
			break;
		case VertexElementFormat::Float:
			desc.second = 1;
			desc.first = VertexElementComponent::Float;
			break;
		case VertexElementFormat::Float2:
			desc.second = 2;
			desc.first = VertexElementComponent::Float;
			break;
		case VertexElementFormat::Float3:
			desc.second = 3;
			desc.first = VertexElementComponent::Float;
			break;
		case VertexElementFormat::Float4:
			desc.second = 4;
			desc.first = VertexElementComponent::Float;
			break;
		case VertexElementFormat::Double:
			desc.second = 1;
			desc.first = VertexElementComponent::Double;
			break;
		case VertexElementFormat::Double2:
			desc.second = 2;
			desc.first = VertexElementComponent::Double;
			break;
		case VertexElementFormat::Double3:
			desc.second = 3;
			desc.first = VertexElementComponent::Double;
			break;
		case VertexElementFormat::Double4:
			desc.second = 4;
			desc.first = VertexElementComponent::Double;
			break;
		case VertexElementFormat::Int:
			desc.second = 1;
			desc.first = VertexElementComponent::Int;
			break;
		case VertexElementFormat::Int2:
			desc.second = 2;
			desc.first = VertexElementComponent::Int;
			break;
		case VertexElementFormat::Int3:
			desc.second = 3;
			desc.first = VertexElementComponent::Int;
			break;
		case VertexElementFormat::Int4:
			desc.second = 4;
			desc.first = VertexElementComponent::Int;
			break;
		case VertexElementFormat::UInt:
			desc.second = 1;
			desc.first = VertexElementComponent::UInt;
			break;
		case VertexElementFormat::UInt2:
			desc.second = 2;
			desc.first = VertexElementComponent::UInt;
			break;
		case VertexElementFormat::UInt3:
			desc.second = 3;
			desc.first = VertexElementComponent::Int;
			break;
		case VertexElementFormat::UInt4:
			desc.second = 4;
			desc.first = VertexElementComponent::UInt;
			break;
		case VertexElementFormat::Byte:
			desc.second = 1;
			desc.first = VertexElementComponent::Byte;
			break;
		case VertexElementFormat::Byte2:
			desc.second = 2;
			desc.first = VertexElementComponent::Byte;
			break;
		case VertexElementFormat::Byte3:
			desc.second = 3;
			desc.first = VertexElementComponent::Byte;
			break;
		case VertexElementFormat::Byte4:
			desc.second = 4;
			desc.first = VertexElementComponent::Byte;
			break;
		case VertexElementFormat::SByte:
			desc.second = 1;
			desc.first = VertexElementComponent::SByte;
			break;
		case VertexElementFormat::SByte2:
			desc.second = 2;
			desc.first = VertexElementComponent::SByte;
			break;
		case VertexElementFormat::SByte3:
			desc.second = 3;
			desc.first = VertexElementComponent::SByte;
			break;
		case VertexElementFormat::SByte4:
			desc.second = 4;
			desc.first = VertexElementComponent::SByte;
			break;
		case VertexElementFormat::Float2x2:
			desc.second = 4;
			desc.first = VertexElementComponent::Float;
			break;
		case VertexElementFormat::Float2x3:
			desc.second = 6;
			desc.first = VertexElementComponent::Float;
			break;
		case VertexElementFormat::Float2x4:
			desc.second = 8;
			desc.first = VertexElementComponent::Float;
			break;
		case VertexElementFormat::Float3x2:
			desc.second = 6;
			desc.first = VertexElementComponent::Float;
			break;
		case VertexElementFormat::Float3x3:
			desc.second = 9;
			desc.first = VertexElementComponent::Float;
			break;
		case VertexElementFormat::Float3x4:
			desc.second = 12;
			desc.first = VertexElementComponent::Float;
			break;
		case VertexElementFormat::Float4x2:
			desc.second = 8;
			desc.first = VertexElementComponent::Float;
			break;
		case VertexElementFormat::Float4x3:
			desc.second = 12;
			desc.first = VertexElementComponent::Float;
			break;
		case VertexElementFormat::Float4x4:
			desc.second = 16;
			desc.first = VertexElementComponent::Float;
			break;
		case VertexElementFormat::Double2x3:
			desc.second = 6;
			desc.first = VertexElementComponent::Double;
			break;
		case VertexElementFormat::Double2x4:
			desc.second = 8;
			desc.first = VertexElementComponent::Double;
			break;
		case VertexElementFormat::Double3x2:
			desc.second = 6;
			desc.first = VertexElementComponent::Double;
			break;
		case VertexElementFormat::Double3x3:
			desc.second = 9;
			desc.first = VertexElementComponent::Double;
			break;
		case VertexElementFormat::Double3x4:
			desc.second = 12;
			desc.first = VertexElementComponent::Double;
			break;
		case VertexElementFormat::Double4x2:
			desc.second = 8;
			desc.first = VertexElementComponent::Double;
			break;
		case VertexElementFormat::Double4x3:
			desc.second = 12;
			desc.first = VertexElementComponent::Double;
			break;
		case VertexElementFormat::Double4x4:
			desc.second = 16;
			desc.first = VertexElementComponent::Double;
			break;
		default:
			desc.second = 0;
			desc.first = VertexElementComponent::Unknown;
			break;
		}
		return desc;
	}
	
}}
 