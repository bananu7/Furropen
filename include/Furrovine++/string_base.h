#pragma once

#include <Furrovine++/type_traits.h>
#include <Furrovine++/size_as.h>
#include <Furrovine++/make_vector.h>
#include <Furrovine++/uninitialized_allocator.h>
#include <Furrovine++/Char.h>
#include <Furrovine++/StringSplit.h>
#include <Furrovine++/Text/Encoding/TextEncodingUnit.h>
#include <Furrovine++/Text/Encoding/decoding_iterator.h>
#include <Furrovine++/Text/Encoding/default_encoding.h>
#include <Furrovine++/reserve_arg.h>

namespace Furrovine {

	namespace detail {
		template <typename TChar, typename TTraits, typename TAlloc>
		inline std::basic_string<TChar, TTraits, TAlloc> make_string( ulword count ) {
			std::basic_string<TChar, TTraits, TAlloc> stdstr;
			stdstr.reserve( count );
			return stdstr;
		}

		template <typename TStd>
		inline TStd make_string( ulword count ) {
			TStd stdstr;
			stdstr.reserve( count );
			return stdstr;
		}
	}

	template <typename TEnco, typename TCodeUnit = typename Text::Encoding::codeunit_traits<TEnco>::codeunit, typename TCharTraits = std::char_traits<TCodeUnit>, typename TAlloc = std::allocator<TCodeUnit>>
	class string_base {
	public:
		template <typename TOtherEnco, typename TOtherCodeUnit, typename TOtherTraits, typename TOtherAlloc>
		friend class string_base;
		typedef TEnco TEncoding;
		typedef TCodeUnit TChar;
		typedef TAlloc TAllocator;
		typedef TCharTraits TTraits;
		typedef std::basic_string<TChar, TTraits, TAlloc> TStorage;
		typedef Text::Encoding::decoding_iterator<TEncoding, TChar*> TIterator;
		typedef Text::Encoding::decoding_iterator<TEncoding, const TChar*> TConstIterator;
		typedef TIterator iterator;
		typedef TConstIterator const_iterator;

	private:
		TEncoding encoding;
		TStorage codeunitstorage;

		TChar* data_end( ) {
			return const_cast<TChar*>( codeunitstorage.data( ) + codeunitstorage.size() );
		}

		const TChar* data_end( ) const {
			return codeunitstorage.data( ) + codeunitstorage.size();
		}

		template < typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type >
		string_base& append_direct( const buffer_view<TOtherChar>& value, TOtherEncoding enc, std::true_type same_encoding ) {
			if ( value.is_null() || value.size() < 1 )
				return *this;
			codeunitstorage.append( value.data(), value.data() + value.size() );
			return *this;
		}

		template < typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type >
		string_base& append_direct( const buffer_view<TOtherChar>& value, TOtherEncoding enc, std::false_type same_encoding ) {
			typedef typename Text::Encoding::compatible_encoding<TOtherEncoding, TEncoding> is_compatible;
			return append_compat( value, enc, is_compatible( ) );
		}

		template < typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type >
		string_base& append_compat( const buffer_view<TOtherChar>& value, TOtherEncoding enc, std::true_type same_encoding ) {
			codeunitstorage.append( reinterpret_cast<const TChar*>( value.data() ), value.size() );
			return *this;
		}

		template < typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type >
		string_base& append_compat( const buffer_view<TOtherChar>& value, TOtherEncoding enc, std::false_type same_encoding ) {
			string_base val( value, enc );
			return Append( val );
		}

		template < typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type >
		string_base& prepend_compat( const buffer_view<TOtherChar>& value, TOtherEncoding enc, std::true_type same_encoding ) {
			codeunitstorage.insert( 0, reinterpret_cast<const TChar*>( value.data() ), value.size() );
			return *this;
		}

		template < typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type >
		string_base& prepend_compat( const buffer_view<TOtherChar>& value, TOtherEncoding enc, std::false_type same_encoding ) {
			string_base val( value, enc );
			return Prepend( val );
		}

		template < typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type >
		string_base& prepend_direct( const buffer_view<TOtherChar>& value, TOtherEncoding enc, std::false_type same_encoding ) {
			typedef typename Text::Encoding::compatible_encoding<TOtherEncoding, TEncoding> is_compatible;
			return prepend_compat( value.data(), value.size(), enc, is_compatible( ) );
		}

		template < typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type >
		string_base& prepend_direct( const buffer_view<TOtherChar>& value, TOtherEncoding enc, std::true_type same_encoding ) {
			codeunitstorage.insert( 0, value.data(), value.size() );
			return *this;
		}

		template < typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type >
		void assign_direct( const buffer_view<TOtherChar>& value, TOtherEncoding otherencoding, std::true_type matching ) {
			if ( value.is_null() )
				return;
			if ( value.size() < 1 ) {
				codeunitstorage.clear( );
				return;
			}
			codeunitstorage.assign( value.data(), value.size() );
		}
		
		template < typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type >
		void assign_direct( const buffer_view<TOtherChar>& value, TOtherEncoding otherencoding, std::false_type matching ) {
			typedef typename Text::Encoding::compatible_encoding<TOtherEncoding, TEncoding> is_compatible;
			assign_compat( value, otherencoding, is_compatible() );
		}

		template < typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type >
		void assign_compat( const buffer_view<TOtherChar>& value, TOtherEncoding otherencoding, std::true_type matching ) {
			if ( value.is_null() )
				return;
			if ( value.size() < 1 ) {
				codeunitstorage.clear( );
				return;
			}
			codeunitstorage.assign( reinterpret_cast<const TChar*>( value.data() ), size_as<TChar, TOtherChar>( value.size() ) );
		}

		template < typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type >
		void assign_compat( const buffer_view<TOtherChar>& value, TOtherEncoding otherencoding, std::false_type matching ) {
			if ( value.is_null() )
				return;
			if ( value.size() < 1 ) {
				codeunitstorage.clear( );
				return;
			}

			std::vector<codepoint, uninitialized_allocator<codepoint>> codepoints;
			codepoints.reserve( otherencoding.MaxDecodedCount<TOtherChar>( value.size() ) );

			auto bi = std::back_inserter( codeunitstorage );
			auto decodebi = std::back_inserter( codepoints );
			otherencoding.Decode( value.data( ), value.data( ) + value.size( ), decodebi );
			encoding.Encode( codepoints, bi );
		}

		template <typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type>
		bool equals_direct( const buffer_view<TOtherChar>& value, TOtherEncoding enc, std::true_type ) const {
			if ( value.is_null() || value.size( ) != size() )
				return false;
			for ( ulword i = 0; i < value.size( ); ++i ) {
				if ( value[ i ] != codeunitstorage[ i ] )
					return false;
			}
			return true;
		}

		template <typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type>
		bool equals_direct( const buffer_view<TOtherChar>& value, TOtherEncoding enc, std::false_type ) const {
			if ( value.is_null() || value.size( ) < 1 )
				return false;

			typedef Text::Encoding::decoding_iterator<TOtherEncoding, TOtherChar*> TOtherIterator;
			typedef Text::Encoding::decoding_iterator<TOtherEncoding, const TOtherChar*> TOtherConstIterator;
			TOtherConstIterator ob( value.data( ), value.data( ) + value.size( ) );
			TOtherConstIterator oe( value.data( ) + value.size( ), value.data( ) + value.size( ) );
			TConstIterator b = begin( ), e = end( );
			while ( b != e && ob != oe ) {
				if ( *b++ != *ob++ ) {
					return false;
				}
			}
			return b == e && ob == oe;
		}

		template <typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type>
		bool contains_direct( const buffer_view<TOtherChar>& value, TOtherEncoding enc, std::true_type ) const {
			if ( value.is_null() || value.size( ) > codeunitstorage.size( ) || codeunitstorage.size( ) < 1 )
				return false;

			ulword matched = 0;
			for ( ulword i = 0; i < codeunitstorage.size( ); ++i ) {
				if ( value[ matched ] == codeunitstorage[ i ] ) {
					++matched;
					if ( matched == value.size( ) )
						return true;
				}
				else {
					matched = 0;
				}
			}
			return false;
		}

		template <typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type>
		bool contains_direct( const buffer_view<TOtherChar>& value, TOtherEncoding enc, std::false_type ) const {
			if ( value.is_null() || value.size( ) > codeunitstorage.size( ) || codeunitstorage.size( ) < 1 )
				return false;

			ulword matched = 0;
			typedef Text::Encoding::decoding_iterator<TOtherEncoding, TOtherChar*> TOtherIterator;
			typedef Text::Encoding::decoding_iterator<TOtherEncoding, const TOtherChar*> TOtherConstIterator;
			TOtherConstIterator ob( value.data( ), value.data( ) + value.size( ) );
			TOtherConstIterator oe( value.data( ) + value.size( ), value.data( ) + value.size( ) );
			TConstIterator b = begin( ), e = end( );
			auto i = b; 
			auto oi = ob;
			while ( i != e && oi != oe ) {
				++i;
				if ( *i == *oi ) {
					++oi;
					if ( ob == oe )
						return true;
				}
				else {
					oi = ob;
				}
			}
			return false;
		}

		template <typename TFx>
		string_base& case_shift( TFx&& fx ) {
			TStd value = detail::make_string<TStorage>( length( ) );
			codepoint_casing casing;
			codeunit_bytes encoded{ };
			ulword i;
			for ( auto it = begin( ); it != end( ); ++it ) {
				casing.clear( );
				fx( *it, casing );
				for ( i = 0; i < casing.size( ); ++i ) {
					encoded.clear( );
					encoding.EncodeOne( casing[ i ], encoded );
					value.append( reinterpret_cast<const TChar*>( encoded.data( ) ), size_as<TChar>( encoded.size( ) ) );
				}
			}
			codeunitstorage = std::move( value );
			return *this;
		}

	public:
		static const string_base Empty;

		string_base ( ) {

		}

		string_base( reserve_arg_t, ulword charactercount ) : codeunitstorage( detail::make_string<TStorage>( encoding.MaxEncodedCount( charactercount ) ) ) {

		}

		template <ulword n>
		string_base( const codepoint( &value )[ n ] ) : string_base( make_buffer_view( std::addressof( value[ 0 ] ), size_no_null( value ) ) ) {

		}

		string_base ( const buffer_view<codepoint>& codepoints ) : codeunitstorage( detail::make_string<TStorage>( encoding.MaxEncodedCount<TChar>( codepoints.data() == null ? 0 : codepoints.size() ) ) ) {
			if ( codepoints.is_null() || codepoints.size() < 1 )
				return;
			auto bi = std::back_inserter( codeunitstorage );
			encoding.Encode( codepoints.data(), codepoints.data() + codepoints.size(), bi );
		}

		template <typename TOtherChar, typename TOtherTraits, typename TOtherAlloc, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type>
		string_base( const std::basic_string<TOtherChar, TOtherTraits, TOtherAlloc>& storage, TOtherEncoding e = TOtherEncoding( ) ) : string_base( make_buffer_view( storage ), e ) {

		}

		template <typename TOtherChar, ulword n, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type>
		string_base( const TOtherChar( &value )[ n ], TOtherEncoding e = TOtherEncoding() ) : string_base( make_buffer_view( std::addressof( value[ 0 ] ), size_no_null( value ) ), e ) {

		}

		template <typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type>
		string_base ( const buffer_view<TOtherChar>& value, TOtherEncoding otherencoding = TOtherEncoding() ) 
		: codeunitstorage( detail::make_string<TStorage>( encoding.MaxEncodedCount<TChar>( otherencoding.MaxDecodedCount<TOtherChar>( value.size() ) ) ) ) {
			Assign( value, otherencoding );
		}

		template <typename TOtherEnco, typename TOtherChar, typename TOtherTraits, typename TOtherAlloc>
		string_base ( const string_base<TOtherEnco, TOtherChar, TOtherTraits, TOtherAlloc>& othercopy ) : codeunitstorage( detail::make_string<TStorage>( encoding.MaxEncodedCount( othercopy.codeunitstorage.size() * sizeof( TOtherChar ) ) ) ) {
			if ( othercopy.IsEmpty() )
				return;

			Assign( make_buffer_view( othercopy.data( ), othercopy.size() ), othercopy.encoding );
		}

		explicit string_base ( TStorage&& storage ) : codeunitstorage( std::move( storage ) ) {

		}

		explicit string_base( const TStorage& storage ) : codeunitstorage( storage ) {

		}

		string_base ( const string_base& other ) {
			if ( std::addressof( other ) == this )
				return;
			encoding = other.encoding;
			codeunitstorage = std::move( other.codeunitstorage );
		}

		string_base ( string_base&& other ) {
			if ( std::addressof( other ) == this )
				return;
			encoding = other.encoding;
			codeunitstorage = std::move( other.codeunitstorage );
		}

		template < ulword n, typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type >
		void Assign( const TOtherChar( &value )[ n ], TOtherEncoding e = TOtherEncoding( ) ) {
			Assign( make_buffer_view( value, size_no_null( value ) ), e );
		}

		template <typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type, typename TOtherTraits = std::char_traits<TOtherChar>>
		void Assign( const buffer_view<TOtherChar>& value, TOtherEncoding otherencoding = TOtherEncoding( ) ) {
			typedef typename tmp_all<std::is_same<TOtherEncoding, TEncoding>, std::is_same<TChar, TOtherChar>>::type is_direct_match;
			assign_direct( value, otherencoding, is_direct_match( ) );
		}

		void Assign( const string_base& value ) {
			codeunitstorage = value.codeunitstorage;
		}

		void Assign( string_base&& value ) {
			codeunitstorage = std::move( value.codeunitstorage );
		}

		TChar* Data () {
			return const_cast<TChar*>( data() );
		}

		const TChar* Data () const {
			return data();
		}

		const TStorage& Storage () const {
			return codeunitstorage;
		}

		TStorage&& ExtractStorage () {
			return std::move( codeunitstorage );
		}
		
		ulword Length () const {
			return codeunitstorage.size();
		}

		ulword Count () const {
			return encoding.DecodedCount( codeunitstorage.begin(), codeunitstorage.end() );
		}

		ulword Capacity () const {
			return codeunitstorage.capacity();
		}

		bool IsEmpty () const {
			return Length() < 1;
		}

		bool IsNotEmpty () const {
			return Length() > 0;
		}

		const TEncoding& Encoder ( ) const {
			return encoding;
		}

		string_base Substring ( ulword count ) const {
			return Substring( 0, count );
		}

		string_base SubstringFrom ( ulword from ) const {
			return Substring( from, codeunitstorage.size() - from );
		}

		string_base Substring ( ulword index, ulword count ) const {
			string_base out( reserve_arg, count );
			const TChar* d = codeunitstorage.data();
			d += index;
			for ( ulword i = 0; i < count; ++i ) {
				out.Append( *d++ );
			}
			return out;
		}

		bool Contains ( codepoint value ) const {
			return std::find( begin( ), end( ), value ) != end( );
		}

		bool Contains ( const string_base& value ) const {
			return Contains( make_buffer_view( value.data(), value.size() ), value.encoding );
		}

		template <typename TOtherChar, ulword n, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type>
		bool Contains( const TOtherChar( &value )[ n ], TOtherEncoding enc = TOtherEncoding( ) ) const {
			return Contains( make_buffer_view( value, size_no_null( value ) ), enc );
		}
		
		template <typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type>
		bool Contains( const buffer_view<TOtherChar>& value, TOtherEncoding enc ) const {
			typedef typename tmp_all<std::is_same<TOtherEncoding, TEncoding>, std::is_same<TChar, TOtherChar>>::type is_direct_match;
			return contains_direct( value, enc, is_direct_match() );
		}

		bool StartsWith ( codepoint c ) const {
			if ( codeunitstorage.size() < 1 )
				return false;

			codeunit_bytes units{};
			encoding.EncodeOne( c, units );
			return StartsWith( make_buffer_view_as<TChar>( units.data( ), units.size( ) ) );
		}

		template <typename TOtherChar, ulword n>
		bool StartsWith( const TOtherChar( &value )[n] ) const {
			return StartsWith( make_buffer_view( value, size_no_null( value ) ) );
		}

		bool StartsWith ( const string_base& value ) const {
			return StartsWith( make_buffer_view( value.data(), value.size() ) );
		}

		bool StartsWith ( const buffer_view<TChar>& value ) const {
			if ( value.is_null() )
				return false;

			if ( codeunitstorage.size() < 1 || value.size() > static_cast<ulword>( codeunitstorage.size() ) || value.size() < 1 )
				return false;

			for ( ulword i = 0; i < value.size(); ++i) {
				if ( value[i] != codeunitstorage[i] )
					return false;
			}
			return true;
		}

		bool EndsWith ( const string_base& value ) const {
			return EndsWith( make_buffer_view( value.Data(), value.Length() ) );
		}

		template <typename TOtherChar, ulword n>
		bool EndsWith( const TOtherChar( &value )[ n ] ) const {
			return EndsWith( make_buffer_view( value, size_no_null( value ) ) );
		}

		bool EndsWith ( const buffer_view<TChar>& value ) const {
			if ( value.is_null() )
				return false;

			if ( codeunitstorage.size() < 1 || value.size() > codeunitstorage.size() || value.size() < 1 )
				return false;

			ulword matched = value.size() - 1;
			for ( ulword i = codeunitstorage.size() - 1; i > 0; --i, --matched) {
				if ( value[matched] != codeunitstorage[i] )
					return false;
			}
			return true;
		}

		bool EndsWith( codepoint c ) const {
			codeunit_bytes units{};
			encoding.EncodeOne( c, units );
			return EndsWith( make_buffer_view_as<TChar>( units ) );
		}

		ulword IndexOf ( codepoint value ) const {
			return IndexOf( value, 0, codeunitstorage.size() );
		}

		ulword IndexOf ( codepoint value, ulword start ) const {
			return IndexOf( value, start, codeunitstorage.size() - start ); 
		}

		ulword IndexOf ( codepoint value, ulword start, ulword count ) const {
			/*auto current = begin( );
			auto endit = end( );
			bool totheend = count == codeunitstorage.size();
			ulword i;
			for ( i = 0; i < start && current != endit; ++i ) {
				++current;
			}
			auto last = current;
			for ( i = 0; i < count; ++i ) {
				if ( last == endit )
					break;
				++last;
			}

			auto it = find( current, last, (TChar)value );

			return it != endit ? std::distance( codeunitstorage.begin(), current.internal_iterator() ) : TStorage::npos;
			*/
			if ( start > codeunitstorage.size() )
				return TStorage::npos;
			ulword end = std::min( start + count, codeunitstorage.size() );
			auto it = find( codeunitstorage.begin() + start, codeunitstorage.begin() + end, (TChar)value );

			return it != codeunitstorage.end() ? std::distance( codeunitstorage.begin(), it ) : TStorage::npos;
		}

		ulword IndexOf( const string_base& value ) const {
			return IndexOf( make_buffer_view( value ), 0, codeunitstorage.size( ) );
		}

		ulword IndexOf( const string_base& value, ulword start ) const {
			return IndexOf( make_buffer_view( value ), start, codeunitstorage.size( ) - start );
		}

		ulword IndexOf( const string_base& value, ulword start, ulword count ) const {
			return IndexOf( make_buffer_view( value ), start, count );
		}

		ulword IndexOf( const buffer_view<TChar>& value ) const {
			return IndexOf( value, 0, codeunitstorage.size( ) );
		}

		ulword IndexOf( const buffer_view<TChar>& value, ulword start ) const {
			return IndexOf( value, start, codeunitstorage.size( ) - start );
		}

		ulword IndexOf( const buffer_view<TChar>& value, ulword start, ulword count ) const {
			if ( value.is_null() || codeunitstorage.size() < 1 )
				return TStorage::npos;

			ulword end = std::min( start + count, codeunitstorage.size() );
			const TChar* p = codeunitstorage.data() + start;
			ulword matched = 0;
			for ( ulword i = start; i < end; ++i, ++p ) {
				if (*p == value[matched]) {
					++matched;
					if ( matched == value.size() )
						return 1 + i - value.size();
				}
				else {
					matched = 0;
				}
			}

			return TStorage::npos;
		}

		ulword LastIndexOf ( codepoint value ) const {
			return LastIndexOf( value, codeunitstorage.size() - 1, codeunitstorage.size() );
		}

		ulword LastIndexOf ( codepoint value, ulword start ) const {
			return LastIndexOf( value, start, codeunitstorage.size() - start );
		}

		ulword LastIndexOf( codepoint value, ulword start, ulword count ) const {
			codeunit_bytes unit{};
			encoding.EncodeOne( value, unit );
			return LastIndexOf( make_buffer_view_as<TChar>( unit ), start, count );
		}

		ulword LastIndexOf ( const string_base& value ) const {
			return LastIndexOf( make_buffer_view( value.data(), value.size() ) );
		}

		ulword LastIndexOf( const buffer_view<TChar>& value ) const {
			return LastIndexOf( value, codeunitstorage.size( ) - 1, codeunitstorage.size( ) );
		}

		ulword LastIndexOf( const buffer_view<TChar>& value, ulword start ) const {
			return LastIndexOf( value, start, codeunitstorage.size( ) - start );
		}

		ulword LastIndexOf( const buffer_view<TChar>& value, ulword start, ulword count ) const {
			if ( value.is_null() || codeunitstorage.size() < 1 )
				return TStorage::npos;

			ulword end = std::max( start - count, 0 );
			const TChar* p = codeunitstorage.data() + start;
			ulword matched = value.size() - 1;
			for ( ulword i = start; i > end; --i, --p ) {
				if ( *p == value[matched] ) {
					if ( matched == 0 )
						return i;
					--matched;
				}
				else {
					matched = value.size() - 1;
				}
			}
			return TStorage::npos;
		}

		bool Remove ( const string_base& value ) {
			return Remove( value.Data(), value.Length() );
		}

		bool Remove( const buffer_view<TChar>& value ) {
			ulword idx = IndexOf( value );
			bool success = false;
			while ( idx != TStorage::npos ) {
				codeunitstorage.erase( idx, size );
				success = true;
				idx = IndexOf( value, idx );
			}
			return success;
		}

		bool Remove ( codepoint value ) {
			ulword idx = IndexOf( value );
			if ( idx == TStorage::npos )
				return false;
			ulword removalcount = encoding.EncodedCount( &value, &value + 1 );
			while ( idx != TStorage::npos ) {
				codeunitstorage.erase( idx, removalcount );
				idx = IndexOf( value, idx + removalcount );
			}
			return true;
		}

		string_base& Append( codepoint value ) {
			codeunit_bytes b{ };
			encoding.EncodeOne( value, b );
			codeunitstorage.append( reinterpret_cast<const TChar*>( b.data( ) ), size_as<TChar>( b.size( ) ) );
			return *this;
		}

		string_base& Append( const string_base& value ) {
			codeunitstorage.append( value.codeunitstorage.data( ), value.codeunitstorage.size( ) );
			return *this;
		}

		template <ulword n, typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type>
		string_base& Append( const TOtherChar( &value )[ n ], TOtherEncoding e = TOtherEncoding() ) {
			return Append( make_buffer_view( value, size_no_null( value ) ), e );
		}

		template < typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type >
		string_base& Append( const buffer_view<TOtherChar>& value, TOtherEncoding enc = TOtherEncoding( ) ) {
			typedef typename tmp_all<std::is_same<TOtherEncoding, TEncoding>, std::is_same<TChar, TOtherChar>>::type is_direct_match;
			return append_direct( value, enc, is_direct_match( ) );
		}

		string_base& Prepend( codepoint value ) {
			codeunit_bytes b{ };
			encoding.EncodeOne( value, b );
			codeunitstorage.insert( 0, reinterpret_cast<const TChar*>( b.data( ) ), size_as<TChar>( b.size( ) ) );
			return *this;
		}

		string_base& Prepend( const string_base& value ) {
			codeunitstorage.insert( 0, value.codeunitstorage.data( ), value.codeunitstorage.size( ) );
			return *this;
		}

		template < ulword n, typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type >
		string_base& Prepend( const TOtherChar( &value )[ n ], TOtherEncoding e = TOtherEncoding( ) ) {
			return Prepend( make_buffer_view( value, size_no_null( value ) ), e );
		}

		template < typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type >
		string_base& Prepend( const buffer_view<TOtherChar>& value, TOtherEncoding enc = TOtherEncoding( ) ) {
			typedef typename tmp_all<std::is_same<TOtherEncoding, TEncoding>, std::is_same<TChar, TOtherChar>>::type is_direct_match;
			return prepend_direct( value, enc, is_direct_match( ) );
		}

		bool Equals( const string_base& value ) const {
			return Equals( make_buffer_view( value.data(), value.size() ) );
		}

		template < ulword n, typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type >
		bool Equals( const TOtherChar( &value )[ n ], TOtherEncoding e ) const {
			return Equals( value, n, e );
		}

		template < typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type, typename TOtherTraits = std::char_traits<TOtherChar>>
		bool Equals( const buffer_view<TOtherChar>& value ) const {
			return Equals( value, TOtherEncoding( ) );
		}

		template <typename TOtherChar, typename TOtherEncoding = typename Text::Encoding::default_encoding<TOtherChar>::type >
		bool Equals( const buffer_view<TOtherChar>& value, TOtherEncoding enc ) const {
			typedef typename tmp_all<std::is_same<TOtherEncoding, TEncoding>, std::is_same<TChar, TOtherChar>>::type is_direct_match;
			return equals_direct( value, enc, is_direct_match( ) );
		}

		string_base& TrimStartBy( ulword count ) {
			ulword trimcount = count;
			return TrimStart( [ &] ( codepoint ) { return trimcount-- != 0; } );
		}

		string_base& TrimStart( ) {
			return TrimStart( Char::IsWhiteSpace );
		}

		string_base& TrimStart( std::initializer_list<codepoint> codepoints ) {
			return TrimStart(
				[ &] ( codepoint c ) { return std::find( codepoints.begin( ), codepoints.end( ), c ) != codepoints.end( ); }
			);
		}

		string_base& TrimStart( const buffer_view<codepoint>& codepoints ) {
			return TrimStart(
				[ & ] ( codepoint c ) { return std::find( codepoints.begin( ), codepoints.end( ), c ) != codepoints.end( ); }
			);
		}

		template <typename TFx>
		string_base& TrimStart( TFx&& fx ) {
			codepoint c;
			if ( IsEmpty( ) )
				return *this;

			auto progress = encoding.DecodeOne( codeunitstorage.data( ), c );
			while ( codeunitstorage.begin( ) != codeunitstorage.end( )
				&& fx( c ) ) {
				codeunitstorage.erase( 0, progress - codeunitstorage.data( ) );
				progress = encoding.DecodeOne( codeunitstorage.data( ), c );
			}

			return *this;
		}

		string_base& TrimEndBy( ulword count ) {
			ulword trimcount = count;
			return TrimEnd( [ &] ( codepoint ) { return trimcount-- != 0; } );
		}

		string_base& TrimEnd( ) {
			return TrimEnd( Char::IsWhiteSpace );
		}

		string_base& TrimEnd( std::initializer_list<codepoint> codepoints ) {
			return TrimEnd(
				[ &] ( codepoint c ) { return std::find( codepoints.begin( ), codepoints.end( ), c ) != codepoints.end( ); }
			);
		}

		string_base& TrimEnd( const buffer_view<codepoint>& codepoints ) {
			return TrimEnd(
				[ & ] ( codepoint c ) { return std::find( codepoints.begin( ), codepoints.end( ), c ) != codepoints.end( ); }
			);
		}

		template <typename TFx>
		string_base& TrimEnd( TFx&& fx ) {
			codepoint c;
			if ( IsEmpty( ) )
				return *this;

			auto progress = encoding.ReverseDecodeOne( data_end(), c );
			while ( codeunitstorage.begin( ) != codeunitstorage.end( )
				&& fx( c ) ) {
				codeunitstorage.erase( progress - codeunitstorage.data(), data_end() - progress );
				progress = encoding.ReverseDecodeOne( data_end(), c );
			}

			return *this;
		}

		string_base& Replace ( codepoint value, codepoint replacement ) {
			ulword idx = IndexOf( value );
			if ( idx == TStorage::npos )
				return *this;
			ulword removalcount = size_as<TChar>( encoding.EncodedCount( &value, &value + 1 ) );
			codeunit_bytes encodedreplacement{ };
			encoding.EncodeOne( replacement, encodedreplacement );
			const TChar* encodeddata = reinterpret_cast<const TChar*>( encodedreplacement.data( ) );
			ulword encodedsize = size_as<TChar>( encodedreplacement.size( ) );
			while ( idx != TStorage::npos ) {
				codeunitstorage.replace( idx, removalcount, encodeddata, encodedsize );
				idx = IndexOf( value, idx + encodedsize );
			}
			return *this;
		}

		string_base& Replace ( const string_base& value, const string_base& replacement ) {
			ulword idx = IndexOf( value );
			while ( idx != TStorage::npos ) {
				codeunitstorage.replace( idx, value.size(), replacement.data(), replacement.size() );
				idx = IndexOf( value, idx + replacement.size() );
			}
			return *this;
		}

		string_base& Trim( ) {
			TrimStart( );
			TrimEnd( );
			return *this;
		}

		string_base& Trim( const std::initializer_list<codepoint>& codepoints ) {
			TrimStart( codepoints );
			TrimEnd( codepoints );
			return *this;
		}

		template <typename TFx>
		string_base& Trim ( TFx&& fx ) {
			TrimStart( fx );
			TrimEnd( fx );
			return *this;
		}

		string_base& ToUpper( ) {
			return case_shift( Char::TryToUpper );
		}

		string_base& ToLower( ) {
			return case_shift( Char::TryToLower );
		}

		string_base& ToTitlecase( ) {
			return case_shift( Char::TryToTitlecase );
		}

		void Insert( ulword index, codepoint c ) {
			codeunit_bytes units{ };
			encoding.EncodeOne( c, units );
			const TChar* cdata = reinterpret_cast<const TChar*>( units.data( ) );
			ulword csize = size_as<TChar>( units.size( ) );
			codeunitstorage.insert( index, cdata, csize );
		}

		void Resize ( ulword minimumsize ) {
			codeunitstorage.resize( minimumsize );
		}

		void Reserve( ulword minimumsize ) {
			codeunitstorage.reserve( minimumsize );
		}

		void EnsureCapacity ( ulword minimumsize ) {
			if ( Capacity() < minimumsize ) {
				codeunitstorage.reserve( minimumsize );
			}
		}

		void Clear () {
			clear();
		}

		std::vector<string_base> Split( const string_base& by, StringSplit split = StringSplit::Remove, ulword splithint = 8 ) const {
			std::vector<string_base> splits = make_vector<string_base>( splithint );
			ulword last = 0, current;
			while ( ( current = codeunitstorage.find( by.codeunitstorage, last ) ) != codeunitstorage.npos ) {
				if ( current - last == 0 )
					continue;
				splits.emplace_back( codeunitstorage.data( ) + last, current - last, encoding );
				last = current + by.codeunitstorage.size();
			}
			if ( last != codeunitstorage.size() )
				splits.emplace_back( codeunitstorage.data( ) + last, codeunitstorage.size() - last, encoding );
			return splits;
		}

		template <typename T, typename TNullTraits = std::char_traits<T>>
		static string_base NullTerminated( const T* c_string ) {
			ulword count = TNullTraits::length( c_string );
			return string_base( make_buffer_view( c_string, count ) );
		}

		/* Operators */

		TChar& operator [] ( ulword index ) {
			return codeunitstorage[ index ];
		}

		const TChar& operator [] ( ulword index ) const {
			return codeunitstorage[ index ];
		}

		codepoint operator () ( ulword index ) {
			return *( at + index );
		}

		const codepoint operator () ( ulword index ) const {
			return *( at + index );
		}

		string_base& operator = ( const string_base& right ) {
			codeunitstorage.operator=( right.codeunitstorage );
			return *this;
		}

		string_base& operator = ( string_base&& right ) {
			codeunitstorage.operator=( std::move( right.codeunitstorage ) );
			return *this;
		}

		/*template <ulword n, typename TOtherChar>
		string_base& operator += ( const TOtherChar( &array )[ n ] ) {
			Append( right );
			return *this;
		}

		template <typename TOtherChar>
		string_base& operator += ( const TOtherChar* right ) {
			Append( right, std::char_traits<TOtherChar>::length( right ) );
			return *this;
		}

		template <typename TOtherEnco, typename TOtherChar, typename TOtherTraits, typename TOtherAlloc>
		string_base& operator += ( const string_base<TOtherEnco, TOtherChar, TOtherTraits, TOtherAlloc>& right ) {
			Append( right );
			return *this;
		}*/

		string_base& operator += ( codepoint right ) {
			Append( right );
			return *this;
		}

		string_base& operator += ( const string_base& right ) {
			codeunitstorage += right.codeunitstorage;
			return *this;
		}

		string_base& operator += ( string_base&& right ) {
			codeunitstorage += std::move( right.codeunitstorage );
			return *this;
		}

		explicit operator const TChar* ( ) const {
			return data( );
		}

		explicit operator TChar* ( ) {
			return data( );
		}

		explicit operator const TStorage& ( ) const {
			return Storage( );
		}

		bool operator == ( const string_base& right ) const {
			return Equals( right );
		}

		bool operator == ( const TChar* right ) const {
			return Equals( right, TCharTraits::length( right ) );
		}

		bool operator != ( const string_base& right ) const {
			return !Equals( right );
		}

		bool operator != ( const TChar* right ) const {
			return !Equals( right, TCharTraits::length( right ) );
		}

		/* Compatability members */

		void clear( ) {
			codeunitstorage.clear( );
		}

		iterator begin( ) {
			return iterator( data( ), data_end( ) );
		}

		iterator end( ) {
			return iterator( data_end( ), data_end( ) );
		}

		const_iterator begin( ) const {
			return const_iterator( data( ), data_end( ) );
		}

		const_iterator end( ) const {
			return const_iterator( data_end( ), data_end( ) );
		}

		const_iterator cbegin( ) {
			return const_iterator( data( ), data_end( ) );
		}

		const_iterator cend( ) {
			return const_iterator( data_end( ), data_end( ) );
		}

		const_iterator cbegin( ) const {
			return const_iterator( data( ), data_end( ) );
		}

		const_iterator cend( ) const {
			return const_iterator( data_end( ), data_end( ) );
		}

		TChar* data( ) {
			return const_cast<TChar*>( codeunitstorage.data( ) );
		}

		const TChar* data( ) const {
			return codeunitstorage.data( );
		}

		ulword size( ) const {
			return codeunitstorage.size();
		}

		ulword length( ) const {
			return codeunitstorage.size();
		}

		void reserve( ulword minimumsize ) {
			codeunitstorage.reserve( minimumsize );
		}

		friend std::ostream& operator<< ( std::ostream& os, const string_base& s ) {
			os << s.Data( );
			return os;
		}

		friend std::istream& operator>> ( std::istream& is, const string_base& s ) {
			is << s.Data( );
			return is;
		}

		~string_base () {

		}

	};

	template <typename TEnco, typename TChar, typename TCharTraits, typename TAlloc, typename TOtherEnco, typename TOtherChar, typename TOtherTraits, typename TOtherAlloc>
	string_base<TEnco, TChar, TCharTraits, TAlloc> operator + ( const string_base<TEnco, TChar, TCharTraits, TAlloc>& left, const string_base<TOtherEnco, TOtherChar, TOtherTraits, TOtherAlloc>& right ) {
		string_base<TEnco, TChar, TCharTraits, TAlloc> out( left );
		out.Append( right );
		return out;
	}

	template <typename TEnco, typename TChar, typename TCharTraits, typename TAlloc>
	string_base<TEnco, TChar, TCharTraits, TAlloc> operator + ( const string_base<TEnco, TChar, TCharTraits, TAlloc>& left, codepoint right ) {
		string_base<TEnco, TChar, TCharTraits, TAlloc> out( left );
		out.Append( right );
		return out;
	}

	template <typename TEnco, typename TChar, typename TCharTraits, typename TAlloc>
	string_base<TEnco, TChar, TCharTraits, TAlloc> operator + ( codepoint left, const string_base<TEnco, TChar, TCharTraits, TAlloc>& right ) {
		string_base<TEnco, TChar, TCharTraits, TAlloc> out( left );
		out.Append( right );
		return out;
	}

	/*template <typename TEnco, typename TChar, typename TCharTraits, typename TAlloc>
	string_base<TEnco, TChar, TCharTraits, TAlloc> operator + ( const string_base<TEnco, TChar, TCharTraits, TAlloc>& left, const TChar* right ) {
		string_base<TEnco, TChar, TCharTraits, TAlloc> out( left );
		out.Append( right, TCharTraits::length( right ) );
		return out;
	}

	template <typename TEnco, typename TChar, typename TCharTraits, typename TAlloc, typename TOtherChar>
	string_base<TEnco, TChar, TCharTraits, TAlloc> operator + ( const string_base<TEnco, TChar, TCharTraits, TAlloc>& left, const TOtherChar* right ) {
		string_base<TEnco, TChar, TCharTraits, TAlloc> out( left );
		out.Append( right, std::char_traits<TOtherChar>::length( right ) );
		return out;
	}

	template <ulword n, typename TEnco, typename TChar, typename TCharTraits, typename TAlloc, typename TOtherChar>
	string_base<TEnco, TChar, TCharTraits, TAlloc> operator + ( const string_base<TEnco, TChar, TCharTraits, TAlloc>& left, const TOtherChar( &right )[ n ] ) {
		string_base<TEnco, TChar, TCharTraits, TAlloc> out( left );
		out.Append( right, n );
		return out;
	}

	template <typename TEnco, typename TChar, typename TCharTraits, typename TAlloc, typename TOtherEnco, typename TOtherChar, typename TOtherTraits, typename TOtherAlloc>
	string_base<TEnco, TChar, TCharTraits, TAlloc> operator + ( const string_base<TOtherEnco, TOtherChar, TOtherTraits, TOtherAlloc>& left, const string_base<TEnco, TChar, TCharTraits, TAlloc>& right ) {
		string_base<TEnco, TChar, TCharTraits, TAlloc> out( left );
		out.Append( right );
		return out;
	}

	template <typename TEnco, typename TChar, typename TCharTraits, typename TAlloc>
	string_base<TEnco, TChar, TCharTraits, TAlloc> operator + ( const TChar* left, const string_base<TEnco, TChar, TCharTraits, TAlloc>& right ) {
		string_base<TEnco, TChar, TCharTraits, TAlloc> out( left, TCharTraits::length( left ) );
		out.Append( right );
		return out;
	}

	template <typename TEnco, typename TChar, typename TCharTraits, typename TAlloc, typename TOtherChar>
	string_base<TEnco, TChar, TCharTraits, TAlloc> operator + ( const TOtherChar* left, const string_base<TEnco, TChar, TCharTraits, TAlloc>& right ) {
		string_base<TEnco, TChar, TCharTraits, TAlloc> out( left, std::char_traits<TOtherChar>::length( left ) );
		out.Append( right );
		return out;
	}

	template <ulword n, typename TEnco, typename TChar, typename TCharTraits, typename TAlloc, typename TOtherChar>
	string_base<TEnco, TChar, TCharTraits, TAlloc> operator + ( const TOtherChar( &left )[ n ], const string_base<TEnco, TChar, TCharTraits, TAlloc>& right ) {
		string_base<TEnco, TChar, TCharTraits, TAlloc> out( left );
		out.Append( right );
		return out;
	}
	*/

	template <typename TEnco, typename TChar, typename TCharTraits, typename TAlloc> 
	const string_base<TEnco, TChar, TCharTraits, TAlloc> string_base<TEnco, TChar, TCharTraits, TAlloc>::Empty;

	template <typename TEnco, typename TChar, typename TCharTraits, typename TAlloc>
	const string_base<TEnco, TChar, TCharTraits, TAlloc> Replace( const string_base<TEnco, TChar, TCharTraits, TAlloc>& value, const string_base<TEnco, TChar, TCharTraits, TAlloc>& target, const string_base<TEnco, TChar, TCharTraits, TAlloc>& replacement ) {
		auto trimmed = value;
		trimmed.Replace( target, replacement );
		return trimmed;
	}

	template <typename TEnco, typename TChar, typename TCharTraits, typename TAlloc>
	const string_base<TEnco, TChar, TCharTraits, TAlloc> Replace( const string_base<TEnco, TChar, TCharTraits, TAlloc>& value, codepoint target, codepoint replacement ) {
		auto trimmed = value;
		trimmed.Replace( target, replacement );
		return trimmed;
	}

	template <typename TEnco, typename TChar, typename TCharTraits, typename TAlloc>
	string_base<TEnco, TChar, TCharTraits, TAlloc> Trim( const string_base<TEnco, TChar, TCharTraits, TAlloc>& value ) {
		auto trimmed = value;
		trimmed.Trim( );
		return trimmed;
	}

	template <typename TEnco, typename TChar, typename TCharTraits, typename TAlloc>
	string_base<TEnco, TChar, TCharTraits, TAlloc> ToLower( const string_base<TEnco, TChar, TCharTraits, TAlloc>& value ) {
		auto trimmed = value;
		trimmed.ToLower( );
		return trimmed;
	}

	template <typename TEnco, typename TChar, typename TCharTraits, typename TAlloc>
	string_base<TEnco, TChar, TCharTraits, TAlloc> ToUpper( const string_base<TEnco, TChar, TCharTraits, TAlloc>& value ) {
		auto trimmed = value;
		trimmed.ToUpper( );
		return trimmed;
	}

	template <typename TEnco, typename TChar, typename TCharTraits, typename TAlloc>
	string_base<TEnco, TChar, TCharTraits, TAlloc> ToTitlecase( const string_base<TEnco, TChar, TCharTraits, TAlloc>& value ) {
		auto trimmed = value;
		trimmed.ToTitlecase( );
		return trimmed;
	}

	template <typename TEnco, typename TChar, typename TCharTraits, typename TAlloc>
	string_base<TEnco, TChar, TCharTraits, TAlloc> TrimEnd( const string_base<TEnco, TChar, TCharTraits, TAlloc>& value ) {
		auto trimmed = value;
		trimmed.TrimEnd( );
		return trimmed;
	}

	template <typename TEnco, typename TChar, typename TCharTraits, typename TAlloc>
	string_base<TEnco, TChar, TCharTraits, TAlloc> TrimStart( const string_base<TEnco, TChar, TCharTraits, TAlloc>& value ) {
		auto trimmed = value;
		trimmed.TrimStart( );
		return trimmed;
	}

}
