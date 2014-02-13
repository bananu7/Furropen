#ifndef FURROVINEUTF8_H
#define FURROVINEUTF8_H
#pragma once

#include <array>
#include <Furrovine++/Text/Encoding/detail.h>
#include <Furrovine++/Text/Encoding/TextEncodingUnit.h>

namespace Furrovine { namespace Text { namespace Encoding {

	struct utf8 : public TextEncodingUnit<utf8, byte, 4> {
	public:
		typedef std::array<byte, 256> count_t;
		typedef std::array<byte, 7> lbm_t;
		typedef std::array<ulong, 6> offset_t;

		static const lbm_t& LeadingBitMark () {
			static const std::array<byte, 7> leadingbitmark = {
				0x00, 0x00, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC
			};
			return leadingbitmark;
		}

		static const offset_t& Offsets () {
			static const std::array<ulong, 6> offsets = {
				0x00000000UL, 0x00003080UL, 0x000E2080UL,
				0x03C82080UL, 0xFA082080UL, 0x82082080UL
			};
			return offsets;
		}

		static const count_t& ByteCounts () {
			static const std::array<byte, 256> bytecount = {
				1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
				1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
				1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
				1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
				1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
				1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
				2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
				3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3, 4,4,4,4,4,4,4,4,5,5,5,5,6,6,6,6
			};
			return bytecount;
		}

		template <typename T>
		static bool trailing_code_unit( T byte ) {
			return ( detail::mask8( byte ) >> 6 ) == 0x2;
		}

		template <typename TIterator>
		TIterator EncodeOneBytes( codepoint c, TIterator bytes ) const {
			if ( c <= 0x7F ) {
				*bytes++ = static_cast<byte>( c );
			}
			else if (c <= 0x7FF) {
				*bytes++ = static_cast<byte>( (c >> 6)            | 0xc0 ); /* 110x xxxx */
				*bytes++ = static_cast<byte>( (c          & 0x3f) | 0x80 ); /* 10xx xxxx */
			}
			else if (c <= 0xFFFF) {
				*bytes++ = static_cast<byte>(  (c >> 12)         | 0xe0 ); /* 1110 xxxx */
				*bytes++ = static_cast<byte>( ((c >>  6) & 0x3f) | 0x80 ); /* 10xx xxxx */
				*bytes++ = static_cast<byte>(  (c        & 0x3f) | 0x80 ); /* 10xx xxxx */
			}
			else if (c <= 0x1FFFFF) {
				*bytes++ = static_cast<byte>(  (c >> 18)         | 0xf0 ); /* 1111 0xxx */
				*bytes++ = static_cast<byte>( ((c >> 12) & 0x3f) | 0x80 ); /* 10xx xxxx */
				*bytes++ = static_cast<byte>( ((c >>  6) & 0x3f) | 0x80 ); /* 10xx xxxx */
				*bytes++ = static_cast<byte>( ( c        & 0x3f) | 0x80 ); /* 10xx xxxx */
			}
			/*else if (c <= 0x3FFFFFF) {
				*bytes++ = static_cast<byte>(  (c >> 24)         | 0xf8 ); // 1111 10xx 
				*bytes++ = static_cast<byte>( ((c >> 18) & 0x3f) | 0x80 ); // 10xx xxxx 
				*bytes++ = static_cast<byte>( ((c >> 12) & 0x3f) | 0x80 ); // 10xx xxxx 
				*bytes++ = static_cast<byte>( ((c >>  6) & 0x3f) | 0x80 ); // 10xx xxxx 
				*bytes++ = static_cast<byte>( ( c        & 0x3f) | 0x80 ); // 10xx xxxx 
			}
			else if (c <= 0x7FFFFFFF) {
				*bytes++ = static_cast<byte>(  (c >> 30)         | 0xfc ); // 1111 110x
				*bytes++ = static_cast<byte>( ((c >> 24) & 0x3f) | 0x80 ); // 10xx xxxx
				*bytes++ = static_cast<byte>( ((c >> 18) & 0x3f) | 0x80 ); // 10xx xxxx
				*bytes++ = static_cast<byte>( ((c >> 12) & 0x3f) | 0x80 ); // 10xx xxxx
				*bytes++ = static_cast<byte>( ((c >>  6) & 0x3f) | 0x80 ); // 10xx xxxx
				*bytes++ = static_cast<byte>( ( c        & 0x3f) | 0x80 ); // 10xx xxxx
			}*/
			else {
				/* Error Invalid Utf-8 */
				// TODO: encoding error
				return EncodeOneBytes( ReplacementCodePoint, bytes );	
			}
			return bytes;
		}

		template <typename TIterator>
		TIterator ReverseDecodeOneBytes( TIterator forwardbytes, codepoint &c ) const {
			auto bytes = std::reverse_iterator<TIterator>( forwardbytes );
			ulword bytecount = 0;
			while ( trailing_code_unit( *bytes ) ) {
				if ( bytecount >= 4 ) {
					// TODO: decoding error
					break;
				}
				*bytes++;
				++bytecount;
			}
			*bytes++;
			++bytecount;
			
			DecodeOneBytes( bytes.base(), c );

			return bytes.base();
		}

		template <typename TIterator>
		TIterator DecodeOneBytes( TIterator bytes, codepoint &c ) const {
			c = 0;
			ulword bytecount = ByteCounts( )[ static_cast<byte>( *bytes ) ];
			switch ( bytecount ) {
			/*case 6:
				// This should never happen
				c += static_cast<byte>( *bytes++ );
				c <<= 6;
			case 5:
				// Neither should this
				c += static_cast<byte>( *bytes++ );
				c <<= 6;*/
			case 4:
				c += static_cast<byte>( *bytes++ );
				c <<= 6;
			case 3:
				c += static_cast<byte>( *bytes++ );
				c <<= 6;
			case 2:
				c += static_cast<byte>( *bytes++ );
				c <<= 6;
			case 1:
				c += static_cast<byte>( *bytes++ );
			case 0:
				c -= Offsets()[ bytecount - 1 ];
				break;
			default:
				// TODO: decoding error
				c = ReplacementCodePoint;
				// advance at least one?
				++bytes;
				break;
			}

			return bytes;
		}


	};

}}}

#endif // FURROVINEUTF8_H 