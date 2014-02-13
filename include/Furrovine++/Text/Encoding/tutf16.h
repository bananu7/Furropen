#ifndef FURROVINETUTF16_H
#define FURROVINETUTF16_H

#include <array>
#include <Furrovine++/Text/Encoding/TextEncodingUnit.h>

namespace Furrovine { namespace Text { namespace Encoding {

	template <typename TChar16, typename TEndian>
	struct tutf16 : public TextEncodingUnit<tutf16<TChar16, TEndian>, TChar16, 2> {
	public:
		template <typename TIterator>
		TIterator DecodeOneBytes( TIterator bytes, codepoint& c ) const {
			uint16 c0, c1;

			c0 = *bytes++;
			c0 |= ( *bytes++ ) << 8;
			c0 = TEndian::Value( c0 );
			c = c0;
			if ( c0 >= 0xD800 && c0 <= 0xDBFF ) {
				TIterator twobytemarker( bytes );
				c1 = *bytes++;
				c1 |= ( *bytes ) << 8;
				if ( c1 >= 0xDC00 && c1 <= 0xDFFF ) {
					c1 = TEndian::Value( c1 );
					c = ( ( c - 0xD800 ) << 10 )
						+ ( c1 - 0xDC00 ) + 0x00010000;
					++bytes;
				}
				else {
					// TODO: decoder error
					return twobytemarker;
				}
			}

			return bytes;
		}

		template <typename TIterator>
		TIterator ReverseDecodeOneBytes( TIterator forwardbytes, codepoint& c ) const {
			std::reverse_iterator<TIterator> bytes( forwardbytes );
			
			uint16 c0, c1;

			c0 = ( *bytes++ ) << 8;
			c0 |= ( *bytes++ );
			c0 = TEndian::Value( c0 );
			if ( c0 > 0xDC00 && c0 < 0xDFFF ) {
				decltype( bytes ) twobytemarker = bytes;
				c1 = c0;
				c0 = ( *bytes++ ) << 8;
				c0 |= ( *bytes++ );
				c0 = TEndian::Value( c0 );
				if ( c0 < 0xD800 || c0 > 0xDBFF ) {
					// TODO: decoder error
					return twobytemarker.base();
				}
				else {
					c = c0;
					c = ( ( c - 0xD800 ) << 10 )
						+ ( c1 - 0xDC00 ) + 0x00010000;
				}
			}
			else {
				c = c0;
			}

			return bytes.base();
		}

		template <typename TIterator>
		TIterator EncodeOneBytes ( codepoint c, TIterator bytes ) const {
			std::array<TChar16, 2> uint16s;
			byte* u16cb = reinterpret_cast<byte*>( uint16s.data() );

			if ( c < 0xFFFF ) {
				uint16s[0] = static_cast<TChar16>( TEndian::Value( static_cast<TChar16>( c ) ) );
				*bytes++ = *u16cb++;
				*bytes++ = *u16cb;
			}
			else if ( c < 0x110000 ) {
				c -= 0x00010000;
				uint16s[0] = static_cast<TChar16>( ( c >> 10 ) + 0xD800 );
				uint16s[1] = static_cast<TChar16>( ( c & 0x03FF ) + 0xDC00 );
				uint16s[0] = static_cast<TChar16>( TEndian::Value( uint16s[0] ) );
				uint16s[1] = static_cast<TChar16>( TEndian::Value( uint16s[1] ) );
				*bytes++ = *u16cb++;
				*bytes++ = *u16cb++;
				*bytes++ = *u16cb++;
				*bytes++ = *u16cb;
			}
			else {
				// TODO: Encoding throw
				return EncodeOneBytes( ReplacementCodePoint, bytes );	
			}

			return bytes;
		}
	};

}}}

#endif // FURROVINETUTF16_H 