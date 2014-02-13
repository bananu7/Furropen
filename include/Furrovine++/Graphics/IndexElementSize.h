#pragma once

#include <Furrovine++/numeric_integer_def.h>
#include <Furrovine++/Graphics/IndexElementFormat.h>

namespace Furrovine { namespace Graphics {
	
	enum class IndexElementSize {
		Zero = 0,
		EightBits = sizeof(uint8),
		SixteenBits = sizeof(uint16),
		ThirtyTwoBits = sizeof(uint32),
		SixtyFourBits = sizeof(uint64),
		Default = SixteenBits
	};

	template <typename T>
	IndexElementFormat ToIndexElementFormat ( ) {
		return ToIndexElementFormat( static_cast<IndexElementSize>( sizeof(T) ) );
	}

	inline furrovineapi IndexElementFormat ToIndexElementFormat ( IndexElementSize a ) {
		switch (a) {
		case IndexElementSize::EightBits:
			return IndexElementFormat::EightBits;
		case IndexElementSize::SixteenBits:
			return IndexElementFormat::SixteenBits;
		case IndexElementSize::ThirtyTwoBits:
			return IndexElementFormat::ThirtyTwoBits;
		case IndexElementSize::SixtyFourBits:
			return IndexElementFormat::SixtyFourBits;
		default:
			return IndexElementFormat::Zero;
		}
	}


	inline furrovineapi IndexElementSize ToIndexElementSize( IndexElementFormat a ) {
		switch ( a ) {
		case IndexElementFormat::EightBits:
			return IndexElementSize::EightBits;
		case IndexElementFormat::SixteenBits:
			return IndexElementSize::SixteenBits;
		case IndexElementFormat::ThirtyTwoBits:
			return IndexElementSize::ThirtyTwoBits;
		case IndexElementFormat::SixtyFourBits:
			return IndexElementSize::SixtyFourBits;
		default:
			return IndexElementSize::Zero;
		}
	}

	inline furrovineapi ulword ToByteSize( IndexElementSize value ) {
		return static_cast<uint32>( value );
	}

	inline furrovineapi ulword ToByteSize( IndexElementFormat value ) {
		return ToByteSize( ToIndexElementSize( value ) );
	}
	
}}
 