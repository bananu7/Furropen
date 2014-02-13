#pragma once

#include <vector>
#include <Furrovine++/buffer_view.h>

namespace Furrovine { namespace Text {  namespace Encoding {

	// Allow for run-time switching
	// of various encodings,
	// giving a consistent interface for
	// buffers and readers which have their
	// encoding defined at run-time
	struct TextEncoding {
		virtual const byte* DecodeOne( const byte* bytes, codepoint& codepoint ) const = 0;
		virtual void DecodeOne ( const codeunit_bytes& bytes, codepoint& codepoint ) const = 0;	
		
		virtual byte* EncodeOne ( codepoint codepoint, byte* bytes ) const = 0;
		virtual void EncodeOne ( codepoint codepoint, codeunit_bytes& bytes ) const = 0;

		virtual ulword DecodedCount ( const byte* begin, const byte* end ) const = 0;
		virtual ulword MaxDecodedCount ( ulword bytecount ) const = 0;
		virtual ulword EncodedCount ( const codepoint* begin, const codepoint* end ) const = 0;
		virtual ulword MaxEncodedCount ( ulword codepointcount ) const = 0;

		virtual std::vector<byte> Encode ( const buffer_view<codepoint>& codepoints ) const = 0;
		virtual byte* Encode ( const buffer_view<codepoint>& codepoints, byte* bytes ) const = 0;
		virtual byte* Encode ( const codepoint* codepointsbegin, const codepoint* codepointsend, byte* bytes ) const = 0;

		virtual std::vector<codepoint> Decode ( const buffer_view<byte>& bytes ) const = 0;
		virtual codepoint* Decode ( const buffer_view<byte>& bytes, codepoint* codepoints ) const = 0;
		virtual codepoint* Decode ( const byte* bytesbegin, const byte* bytesend, codepoint* codepoints ) const = 0;

		virtual ~TextEncoding () {}
	};

	template <typename TEncoding>
	struct RuntimeTextEncoding : TEncoding, TextEncoding {

		furrovineapi RuntimeTextEncoding( ) {

		}
		
		furrovineapi RuntimeTextEncoding( const RuntimeTextEncoding& copy ) : TEncoding( copy ) {

		}

		furrovineapi RuntimeTextEncoding( RuntimeTextEncoding&& mov ) : TEncoding( std::move( mov ) ) {

		}

		furrovineapi RuntimeTextEncoding( const TEncoding& copy ) : TEncoding( copy ) {

		}

		furrovineapi RuntimeTextEncoding( TEncoding&& mov ) : TEncoding( std::move( mov ) ) {

		}

		furrovineapi virtual void EncodeOne( codepoint codepoint, codeunit_bytes& bytes ) const override {
			const TEncoding& tencoding = static_cast<const TEncoding&>( *this );
			tencoding.EncodeOne( codepoint, bytes );
		}

		furrovineapi virtual byte* EncodeOne( codepoint codepoint, byte* bytes ) const override {
			const TEncoding& tencoding = static_cast<const TEncoding&>( *this );
			return tencoding.EncodeOne( codepoint, bytes );
		}

		furrovineapi virtual const byte* DecodeOne( const byte* bytes, codepoint& c ) const override {
			const TEncoding& tencoding = static_cast<const TEncoding&>( *this );
			return tencoding.DecodeOne( bytes, c );
		}

		furrovineapi virtual void DecodeOne( const codeunit_bytes& bytes, codepoint& c ) const override {
			const TEncoding& tencoding = static_cast<const TEncoding&>( *this );
			tencoding.DecodeOne( bytes, c );
		}

		furrovineapi virtual ulword MaxDecodedCount( ulword bytecount ) const override {
			const TEncoding& tencoding = static_cast<const TEncoding&>( *this );
			return tencoding.MaxDecodedCount( bytecount );
		}

		furrovineapi virtual ulword MaxEncodedCount( ulword codepointcount ) const override {
			const TEncoding& tencoding = static_cast<const TEncoding&>( *this );
			return tencoding.MaxEncodedCount( codepointcount );
		}

		furrovineapi virtual ulword DecodedCount( const byte* begin, const byte* end ) const override {
			const TEncoding& tencoding = static_cast<const TEncoding&>( *this );
			return tencoding.DecodedCount( begin, end );
		}

		furrovineapi virtual ulword EncodedCount( const codepoint* begin, const codepoint* end ) const override {
			const TEncoding& tencoding = static_cast<const TEncoding&>( *this );
			return tencoding.EncodedCount( begin, end );
		}

		furrovineapi virtual std::vector<byte> Encode( const buffer_view<codepoint>& codepoints ) const override {
			const TEncoding& tencoding = static_cast<const TEncoding&>( *this );
			return tencoding.Encode( codepoints );
		}

		furrovineapi virtual byte* Encode( const buffer_view<codepoint>& codepoints, byte* bytes ) const override {
			const TEncoding& tencoding = static_cast<const TEncoding&>( *this );
			return tencoding.Encode( codepoints, bytes );
		}

		furrovineapi virtual byte* Encode( const codepoint* codepointsbegin, const codepoint* codepointsend, byte* bytes ) const override {
			const TEncoding& tencoding = static_cast<const TEncoding&>( *this );
			return tencoding.Encode( codepointsbegin, codepointsend, bytes );
		}

		furrovineapi virtual std::vector<codepoint> Decode( const buffer_view<byte>& bytes ) const override {
			const TEncoding& tencoding = static_cast<const TEncoding&>( *this );
			return tencoding.Decode( bytes );
		}

		furrovineapi virtual codepoint* Decode( const buffer_view<byte>& bytes, codepoint* codepoints ) const override {
			const TEncoding& tencoding = static_cast<const TEncoding&>( *this );
			return tencoding.Decode( bytes, codepoints );
		}

		furrovineapi virtual codepoint* Decode( const byte* bytesbegin, const byte* bytesend, codepoint* codepoints ) const override {
			const TEncoding& tencoding = static_cast<const TEncoding&>( *this );
			return tencoding.Decode( bytesbegin, bytesend, codepoints );
		}

	};

}}}
