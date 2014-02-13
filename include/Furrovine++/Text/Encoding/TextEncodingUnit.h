#pragma once

#include <Furrovine++/std_defines.h>
#include <vector>
#include <Furrovine++/is_integer_equal.h>
#include <Furrovine++/asserts.h>
#include <Furrovine++/byte_iterator.h>

namespace Furrovine { namespace Text { namespace Encoding {

	template <typename TEncoding>
	struct codeunit_traits {
	public:
		typedef typename TEncoding::codeunit codeunit;
	};

	template <typename T, typename Tcodeunit, int maxwidth = 1, int minwidth = 1, Tcodeunit replacement = '\x1A'> 
	struct TextEncodingUnit {
	public:
		typedef Tcodeunit codeunit;
		static const ulword CodeUnitByteWidth = sizeof( codeunit );
		static const ulword MinWidth = minwidth;
		static const ulword MaxWidth = maxwidth;
		static const ulword MinByteWidth = minwidth * sizeof( codeunit );
		static const ulword MaxByteWidth = maxwidth * sizeof( codeunit );
		static const bool VariableWidth = MaxWidth != MinWidth;
		static const bool FixedWidth = MaxWidth == MinWidth;
		static const codeunit ReplacementCodeUnit = replacement;
		static const codepoint ReplacementCodePoint = 0xFFFE;

		ulword MaxDecodedCount ( ulword bytecount ) const {
			return ( bytecount / MinByteWidth );
		}

		template <typename T>
		ulword MaxDecodedCount ( ulword count ) const {
			return ( ( count * sizeof( T ) ) / MinByteWidth );
		}

		ulword MaxEncodedCount ( ulword codepointcount ) const {
			return codepointcount * MaxByteWidth;
		}

		template <typename T>
		ulword MaxEncodedCount ( ulword codepointcount ) const {
			return ( codepointcount * MaxByteWidth ) / sizeof( T );
		}

		template <typename TIterator>
		ulword DecodedCount ( TIterator bytesbegin, TIterator bytesend ) const {
			TIterator bytescurrent = bytesbegin;
			TIterator bytesnext;
			codepoint codepoint;
			ulword count = 0;
			while ( bytescurrent != bytesend ) {
				bytesnext = DecodeOne( bytescurrent, codepoint );
				++count;
				bytescurrent = bytesnext;
			}
			return count;
		}

		template <typename TIterator>
		ulword EncodedCount ( TIterator codepointsbegin, TIterator codepointsend ) const {
			TIterator codepointscurrent = codepointsbegin;
			codeunit_bytes bytes;
			byte* bytesnext;
			ulword count = 0;
			while ( codepointscurrent != codepointsend ) {
				bytesnext = EncodeOne( *codepointscurrent++, bytes.data() );
				count += bytesnext - bytes.data();
			}
			return count;
		}

		void EncodeOne( codepoint codepoint, codeunit_bytes& bytes ) const {
			bytes.clear();
			auto bi = std::back_inserter( bytes );
			const T& crtp = static_cast<const T&>( *this );
			crtp.EncodeOneBytes( codepoint, bi );
		}

		byte* EncodeOne( codepoint codepoint, byte* bytes ) const {
			const T& crtp = static_cast<const T&>( *this );
			return crtp.EncodeOneBytes( codepoint, bytes );
		}

		template <typename TIterator>
		TIterator EncodeOne( codepoint codepoint, TIterator iterator  ) const {
			typedef typename expanded_iterator_traits<TIterator>::value_type value_type;
			return EncodeOne( codepoint, iterator, is_integer_equal<sizeof( value_type ), 1>::type() );
		}

		template <typename TIterator>
		TIterator EncodeOne( codepoint codepoint, TIterator iterator, std::false_type is1 ) const {
			typedef typename expanded_iterator_traits<TIterator>::value_type value_type;
			const std::size_t value_size = sizeof( value_type );
			const T& crtp = static_cast<const T&>( *this );
			std::array<byte, MaxByteWidth> buffer;
			byte* diff;
			byte* start = buffer.data();
			ulword bytesize;
			value_type* pvalue = static_cast<value_type*>( static_cast<void*>( buffer.data() ) );
			
			diff = crtp.EncodeOneBytes( codepoint, buffer.data() );
			
			bytesize = diff - start;
			furrovineassert( ( bytesize % MinByteWidth ) == 0, "decoded value is not a multiple of the minimum byte size of encoding" );
			for ( ; bytesize > 0; start += value_size, bytesize -= value_size ) {
				*iterator = *pvalue;
				++iterator;
				++pvalue;
			}
			return iterator;
		}

		template <typename TIterator>
		TIterator EncodeOne( codepoint codepoint, TIterator iterator, std::true_type is1 ) const {
			const T& crtp = static_cast<const T&>( *this );
			return crtp.EncodeOneBytes( codepoint, iterator );
		}

		template <typename T, typename TInContainer>
		std::vector<T> Encode ( TInContainer&& codepoints ) const {
			const std::size_t value_size = sizeof( T );
			/*ulword reserve = MaxEncodedCount( std::distance( std::begin( codepoints ), std::end( codepoints ) ) );
			std::vector<T> encoded( reserve / value_size ) ;
			byte* bytedata = reinterpret_cast<byte*>( encoded.data() );
			byte* diff = Encode( std::begin( codepoints ), std::end( codepoints ), bytedata );
			encoded.resize( ( diff - bytedata ) / value_size );
			*/
			std::vector<T> encoded;
			auto data = std::back_inserter( encoded );
			Encode( std::begin( codepoints ), std::end( codepoints ), data );
			return encoded;
		}

		template <typename TInContainer>
		std::vector<byte> Encode ( TInContainer&& codepoints ) const {
			ulword reserve = MaxEncodedCount( std::distance( std::begin( codepoints ), std::end( codepoints ) ) );
			std::vector<byte> encoded( reserve ) ;
			byte* diff = Encode( std::begin( codepoints ), std::end( codepoints ), encoded.data() );
			encoded.resize( diff - encoded.data() );
			return encoded;
		}

		template <typename TInContainer, typename TOutIterator>
		TOutIterator Encode ( TInContainer&& codepoints, TOutIterator bytes ) const {
			return Encode( std::begin( codepoints ), std::end( codepoints ), bytes );
		}

		template <typename TInIterator, typename TOutIterator>
		TOutIterator Encode ( TInIterator codepointsbegin, TInIterator codepointsend, TOutIterator bytes ) const {
			TInIterator codepointscurrent = codepointsbegin;
			while ( codepointscurrent != codepointsend ) {
				bytes = EncodeOne( *codepointscurrent++, bytes );
			}
			return bytes;
		}

		void DecodeOne( const codeunit_bytes& bytes, codepoint& codepoint ) const {
			const T& crtp = static_cast<const T&>( *this );
			crtp.DecodeOneBytes( std::begin( bytes ), codepoint );
		}

		const byte* DecodeOne( const byte* bytes, codepoint& codepoint ) const {
			const T& crtp = static_cast<const T&>( *this );
			return crtp.DecodeOneBytes( bytes, codepoint );
		}

		template <typename TIterator>
		TIterator DecodeOne( TIterator iterator, codepoint& codepoint ) const {
			typedef expanded_iterator_traits<TIterator>::value_type value_type;
			return DecodeOne( iterator, codepoint, is_integer_equal<sizeof( value_type ), 1>::type() );
		}

		template <typename TIterator>
		TIterator DecodeOne( TIterator iterator, codepoint& codepoint, std::false_type is1 ) const {
			const T& crtp = static_cast<const T&>( *this );
			
			bidirectional_byte_iterator<TIterator> bytes( iterator );
			auto diff = crtp.DecodeOneBytes( bytes, codepoint );
			ulword jump = std::distance( iterator, diff.internal_iterator() );
			iterator += jump;
			
			return iterator;
		}

		template <typename TIterator>
		TIterator DecodeOne( TIterator iterator, codepoint& codepoint, std::true_type is1 ) const {
			const T& crtp = static_cast<const T&>( *this );
			return crtp.DecodeOneBytes( iterator, codepoint );
		}

		template <typename TIterator>
		TIterator ReverseDecodeOne( TIterator forwarditerator, codepoint& codepoint ) const {
			typedef expanded_iterator_traits<TIterator>::value_type value_type;
			return ReverseDecodeOne( forwarditerator, codepoint, is_integer_equal<sizeof( value_type ), 1>::type( ) );
		}

		template <typename TIterator>
		TIterator ReverseDecodeOne( TIterator forwarditerator, codepoint& codepoint, std::true_type is1 ) const {
			const T& crtp = static_cast<const T&>( *this );
			return crtp.ReverseDecodeOneBytes( forwarditerator, codepoint );
		}

		template <typename TIterator>
		TIterator ReverseDecodeOne( TIterator iterator, codepoint& codepoint, std::false_type is1 ) const {
			typedef expanded_iterator_traits<TIterator>::value_type value_type;
			const T& crtp = static_cast<const T&>( *this );

			bidirectional_byte_iterator<TIterator> bytes( iterator );
			auto diff = crtp.ReverseDecodeOneBytes( bytes, codepoint );
			ulword jump = std::distance( iterator, diff.internal_iterator( ) );
			iterator += jump;

			return iterator;
		}

		template <typename TInContainer>
		std::vector<codepoint> Decode ( TInContainer&& bytes ) const {
			ulword reserve = MaxDecodedCount( std::distance( std::begin( bytes ), std::end( bytes ) ) * sizeof( std::iterator_traits<decltype(std::begin( bytes ))>::value_type ) );
			std::vector<codepoint> decoded( reserve );
			codepoint* diff = Decode( std::begin( bytes ), std::end( bytes ), decoded.data() );
			decoded.resize( diff - decoded.data() );
			return decoded;
		}

		template <typename TInContainer, typename TOutIterator>
		TOutIterator Decode ( TInContainer&& bytes, TOutIterator codepoints ) const {
			return Decode( std::begin( bytes ), std::end( bytes ), codepoints );
		}

		template <typename TInIterator, typename TOutIterator>
		TOutIterator Decode ( TInIterator bytesbegin, TInIterator bytesend, TOutIterator codepoints ) const {
			TInIterator bytescurrent = bytesbegin;
			codepoint codepoint;
			while ( bytescurrent != bytesend ) {
				bytescurrent = DecodeOne( bytescurrent, codepoint );
				*codepoints++ = codepoint;
			}
			return codepoints;
		}

	};

}}}
