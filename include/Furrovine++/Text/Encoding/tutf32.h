#ifndef FURROVINETUTF32_H
#define FURROVINETUTF32_H

#include <array>
#include <Furrovine++/Text/Encoding/TextEncodingUnit.h>

namespace Furrovine { namespace Text { namespace Encoding {

	template <typename TChar32, typename TEndian>
	struct tutf32 : public TextEncodingUnit<tutf32<TChar32, TEndian>, TChar32, 1> {
	public:
		using TextEncodingUnit::EncodeOne;
		using TextEncodingUnit::DecodeOne;

		template <typename TIterator>
		TIterator EncodeOneBytes ( codepoint c, TIterator bytes ) const {
			byte* cbytes = reinterpret_cast<byte*>( &c );
			c = TEndian::Value( c );
			for ( uint c = 0; c < 4; ++c ) {
				*bytes++ = *cbytes++;
			}

			return bytes;
		}

		template <typename TIterator>
		TIterator DecodeOneBytes( TIterator bytes, codepoint& c ) const {
			byte* cbytes = (byte*)&c;
			for ( uint b = 0; b < 4; ++b ) {
				*cbytes++ = *bytes++;
			}
			c = TEndian::Value( c );

			return bytes;
		}

		template <typename TIterator>
		TIterator ReverseDecodeOneBytes( TIterator forwardbytes, codepoint& c ) const {
			byte* cbytes = (byte*)&c;
			cbytes += 3;
			auto bytes = std::reverse_iterator<TIterator>( forwardbytes );
			for ( uint b = 0; b < 4; ++b ) {
				*cbytes-- = *bytes++;
			}
			c = TEndian::Value( c );

			return bytes.base();
		}

	};

}}}

#endif // FURROVINETUTF32_H 