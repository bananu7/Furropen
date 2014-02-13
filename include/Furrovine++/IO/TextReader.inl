#pragma once

#include <Furrovine++/IO/TextReader.h>
#include <Furrovine++/IO/FileStream.h>
#include <Furrovine++/Text/Encoding/make_runtime_encoding.h>
#include <Furrovine++/NullPointerException.h>

namespace Furrovine { namespace IO {

	template <typename TEncoding>
	TextReader::TextReader( const String& path, IO::FileMode filemode, TEncoding textencoding, bool detectencodingfrombyteordermarks /* = true */, ulword buffsize /* = DefaultBufferSize */ ) 
	: TextReader( ptr<Stream, optional_delete<Stream>>( new FileStream( path, filemode ), false ), std::move( textencoding ), detectencodingfrombyteordermarks, buffsize ) {

	}

	template <typename TEncoding>
	TextReader::TextReader( Stream& textstream, TEncoding textencoding, bool detectencodingfrombyteordermarks /* = true */, ulword buffsize /* = DefaultBufferSize */ ) 
	: TextReader( ptr<Stream, optional_delete<Stream>>( &textstream, false ), std::move( textencoding ), detectencodingfrombyteordermarks, buffsize ) {

	}

	template <typename TEncoding>
	TextReader::TextReader( ptr<Stream, optional_delete<Stream>> textstream, TEncoding textencoding, bool detectencodingfrombyteordermarks /* = true */, ulword buffsize /* = DefaultBufferSize */ ) 
	: TextReader( std::move( textstream ), make_derived_ptr<Text::Encoding::TextEncoding, Text::Encoding::RuntimeTextEncoding<TEncoding>>( std::move( textencoding ) ), detectencodingfrombyteordermarks, buffsize ) {
		
	}	

}}
