#ifndef FURROVINEASCII_H
#define FURROVINEASCII_H

#include <Furrovine++/Text/Encoding/TextEncodingUnit.h>

namespace Furrovine { namespace Text { namespace Encoding {

	struct ascii : public TextEncodingUnit<ascii, char> {
	public:
		
		template <typename TIterator>
		TIterator EncodeOneBytes( codepoint c, TIterator bytes ) const {
			if ( c <= 0x7F ) {
				*bytes++ = static_cast<byte>( c );
			}
			else {
				// TODO: encoder error
				*bytes++ = ReplacementCodeUnit;
			}

			return bytes;
		}

		template <typename TIterator>
		TIterator DecodeOneBytes( TIterator bytes, codepoint &c ) const {
			c = *bytes++;
			if ( c > 0x7F ) {
				// TODO: decoder error
				c = ReplacementCodePoint;
			}
			return bytes;
		}

		template <typename TIterator>
		TIterator ReverseDecodeOneBytes( TIterator forwardbytes, codepoint &c ) const {
			auto bytes = std::reverse_iterator<TIterator>( forwardbytes );
			c = *bytes++;
			if ( c > 0x7F ) {
				// TODO: decoder error
				c = ReplacementCodePoint;
			}
			return bytes;
		}


	};

}}}

#endif // FURROVINEASCII_H 