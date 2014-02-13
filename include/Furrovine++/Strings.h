#pragma once

#include <Furrovine++/size_as.h>
#include <Furrovine++/string_base.h>
#include <Furrovine++/Text/Encoding/encodings.h>
#include <Furrovine++/Hash.h>

namespace Furrovine {

	template <typename TEnco, typename TChar, typename TCharTraits, typename TAlloc>
	struct MurmurHash<string_base<TEnco, TChar, TCharTraits, TAlloc>, uint32> {
		static ulword HashCode( const string_base<TEnco, TChar, TCharTraits, TAlloc>& hashee ) {
			ulword hash = 0;
			Hashers::MurmurHash32( hashee.data( ), size_as<byte, TChar>( hashee.size( ) ), Hashers::HashSeed32, &hash );
			return hash;
		}

		ulword operator () ( const string_base<TEnco, TChar, TCharTraits, TAlloc>& hashee ) {
			ulword hash;
			Hashers::MurmurHash32( hashee.data( ), size_as<byte, TChar>( hashee.size( ) ), Hashers::HashSeed32, &hash );
			return hash;
		}
	};

	template <typename TEnco, typename TChar, typename TCharTraits, typename TAlloc>
	struct MurmurHash<string_base<TEnco, TChar, TCharTraits, TAlloc>, uint64> {
		static ulword HashCode( const string_base<TEnco, TChar>& hashee ) {
			ulword hash;
			Hashers::MurmurHash64( hashee.data( ), size_as<byte, TChar>( hashee.size( ) ), Hashers::HashSeed64, &hash );
			return hash;
		}

		ulword operator () ( const string_base<TEnco, TChar, TCharTraits, TAlloc>& hashee ) {
			ulword hash;
			Hashers::MurmurHash64( hashee.data( ), size_as<byte, TChar>( hashee.size( ) ), Hashers::HashSeed64, &hash );
			return hash;
		}
	};

	template <typename EncodingT, typename CharT, typename Traits, typename Allocator>
	std::basic_ostream<CharT, Traits>&
	operator<<( std::basic_ostream<CharT, Traits>& os,
	const string_base<EncodingT, CharT, Traits, Allocator>& str ) {
		os << str.Storage( );
	}

	template <typename EncodingT, typename CharT, typename Traits, typename Allocator>
	std::basic_istream<CharT, Traits>&
	operator>>( std::basic_istream<CharT, Traits>& is,
	string_base<EncodingT, CharT, Traits, Allocator>& str ) {
		std::string<CharT, Traits, Allocator> storage;
		is >> storage;
		str = std::move( storage );
	}

	typedef string_base<Text::Encoding::ascii> ASCIIString;
	typedef string_base<Text::Encoding::utf8> UTF8String;
	typedef string_base<Text::Encoding::utf16> UTF16String;
	typedef string_base<Text::Encoding::utf32> UTF32String;
	typedef string_base<Text::Encoding::wide_encoding> WideString;
	typedef string_base<Text::Encoding::filesystem_encoding> FileSystemString;
	typedef UTF8String String;

}

namespace std {
	
	template <typename TEnco, typename TChar, typename TCharTraits, typename TAlloc> 
	struct hash<Furrovine::string_base<TEnco, TChar, TCharTraits, TAlloc>> {
		Furrovine::ulword operator() ( const Furrovine::string_base<TEnco, TChar, TCharTraits, TAlloc>& value ) const {
			Furrovine::MurmurHash<Furrovine::string_base<TEnco, TChar, TCharTraits, TAlloc>, Furrovine::ulword> h;
			return h( value );
		}
	};

}