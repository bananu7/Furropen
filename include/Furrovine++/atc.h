#pragma once

#include <Furrovine++/integral_type.h>
#include <Furrovine++/numeric_integer_def.h>

namespace Furrovine {

	template <ulword n>
	using atc_return = typename integral_type<n>::type;

	template <ulword n>
	typename atc_return<n - 1> atc( const char( &items )[ n ] ) {
		typedef typename atc_return<n - 1> code_t;
		code_t code;
		byte* p_code = static_cast<byte*>( static_cast<void*>( &code ) );
		for ( ulword i = 0; i < n - 1; ++i )
			p_code[ i ] = items[ i ];
		for ( ulword i = n - 1; i < sizeof( code_t ); ++i )
			p_code[ i ] = 0;

		// Can we make these work with constexpr one day?
		/*std::memcpy( &code, items, n - 1 );
		std::memset( static_cast<byte*>( static_cast<void*>( &code ) ) + ( n - 1 ), 0, sizeof( code_t ) - ( n - 1 ) );
		*/
		return code;
	}

#define cc2(b0, b1) ( (b0) | ((b1) << 8) )
#define cc3(b0, b1, b2) ( (b0) | ((b1) << 8) | ((b2) << 16) )
#define cc4(b0, b1, b2, b3) ( (b0) | ((b1) << 8) | ((b2) << 16) | ((b3) << 24) )
#define cc5(b0, b1, b2, b3, b4) ( static_cast<Furrovine::uint64>(b0) | static_cast<Furrovine::uint64>((b1) << 8) | static_cast<Furrovine::uint64>((b2) << 16) | static_cast<Furrovine::uint64>((b3) << 24) | static_cast<Furrovine::uint64>(static_cast<Furrovine::uint64>(b4) << 32) )
#define cc6(b0, b1, b2, b3, b4, b5) ( static_cast<Furrovine::uint64>(b0) | static_cast<Furrovine::uint64>((b1) << 8) | static_cast<Furrovine::uint64>((b2) << 16) | static_cast<Furrovine::uint64>((b3) << 24) | static_cast<Furrovine::uint64>(static_cast<Furrovine::uint64>(b4) << 32) | static_cast<Furrovine::uint64>(static_cast<Furrovine::uint64>(b5) << 40) )
#define cc7(b0, b1, b2, b3, b4, b5, b6) ( static_cast<Furrovine::uint64>(b0) | static_cast<Furrovine::uint64>((b1) << 8) | static_cast<Furrovine::uint64>((b2) << 16) | static_cast<Furrovine::uint64>((b3) << 24) | static_cast<Furrovine::uint64>(static_cast<Furrovine::uint64>(b4) << 32) | static_cast<Furrovine::uint64>(static_cast<Furrovine::uint64>(b5) << 40) | static_cast<Furrovine::uint64>(static_cast<Furrovine::uint64>(b6) << 48) )
#define cc8(b0, b1, b2, b3, b4, b5, b6, b7) ( static_cast<Furrovine::uint64>(b0) | static_cast<Furrovine::uint64>((b1) << 8) | static_cast<Furrovine::uint64>((b2) << 16) | static_cast<Furrovine::uint64>((b3) << 24) | static_cast<Furrovine::uint64>(static_cast<Furrovine::uint64>(b4) << 32) | static_cast<Furrovine::uint64>(static_cast<Furrovine::uint64>(b5) << 40) | static_cast<Furrovine::uint64>(static_cast<Furrovine::uint64>(b6) << 48) | static_cast<Furrovine::uint64>(static_cast<Furrovine::uint64>(b7) << 56) )

#define charcc2(b0, b1) ( (#@b0) | ((#@b1) << 8) )
#define charcc3(b0, b1, b2) ( (#@b0) | ((#@b1) << 8) | ((#@b2) << 16) )
#define charcc4(b0, b1, b2, b3) ( (#@b0) | ((#@b1) << 8) | ((#@b2) << 16) | ((#@b3) << 24) )
#define charcc5(b0, b1, b2, b3, b4) ( static_cast<Furrovine::uint64>(#@b0) | static_cast<Furrovine::uint64>((#@b1) << 8) | static_cast<Furrovine::uint64>((#@b2) << 16) | static_cast<Furrovine::uint64>((#@b3) << 24) | static_cast<Furrovine::uint64>(static_cast<Furrovine::uint64>(#@b4) << 32) )
#define charcc6(b0, b1, b2, b3, b4, b5) ( static_cast<Furrovine::uint64>(#@b0) | static_cast<Furrovine::uint64>((#@b1) << 8) | static_cast<Furrovine::uint64>((#@b2) << 16) | static_cast<Furrovine::uint64>((#@b3) << 24) | static_cast<Furrovine::uint64>(static_cast<Furrovine::uint64>(#@b4) << 32) | static_cast<Furrovine::uint64>(static_cast<Furrovine::uint64>(#@b5) << 40) )
#define charcc7(b0, b1, b2, b3, b4, b5, b6) ( static_cast<Furrovine::uint64>(#@b0) | static_cast<Furrovine::uint64>((#@b1) << 8) | static_cast<Furrovine::uint64>((#@b2) << 16) | static_cast<Furrovine::uint64>((#@b3) << 24) | static_cast<Furrovine::uint64>(static_cast<Furrovine::uint64>(#@b4) << 32) | static_cast<Furrovine::uint64>(static_cast<Furrovine::uint64>(#@b5) << 40) | static_cast<Furrovine::uint64>(static_cast<Furrovine::uint64>(#@b6) << 48) )
#define charcc8(b0, b1, b2, b3, b4, b5, b6, b7) ( static_cast<Furrovine::uint64>(#@b0) | static_cast<Furrovine::uint64>((#@b1) << 8) | static_cast<Furrovine::uint64>((#@b2) << 16) | static_cast<Furrovine::uint64>((#@b3) << 24) | static_cast<Furrovine::uint64>(static_cast<Furrovine::uint64>(#@b4) << 32) | static_cast<Furrovine::uint64>(static_cast<Furrovine::uint64>(#@b5) << 40) | static_cast<Furrovine::uint64>(static_cast<Furrovine::uint64>(#@b6) << 48) | static_cast<Furrovine::uint64>(static_cast<Furrovine::uint64>(#@b7) << 56) )

}