#ifndef FURROVINEBYTEREADER_INL
#define FURROVINEBYTEREADER_INL

#include <Furrovine++/IO/ByteReader.h>
#include <Furrovine++/IO/FileStream.h>
#include <Furrovine++/IO/Path.h>

namespace Furrovine { namespace IO {

	template <typename TByteOrder, typename TEncoding>
	ByteReader::ByteReader( const String& path, FileMode filemode, TByteOrder order, TEncoding encoding ) 
	: ByteReader( ptr<Stream, optional_delete<Stream>>( new FileStream( path, filemode ), true ), std::move( order ), std::move( encoding ) ) {

	}

	template <typename TByteOrder, typename TEncoding>
	ByteReader::ByteReader( Stream& bytestream, TByteOrder order, TEncoding encoding ) 
	: ByteReader( ptr<Stream, optional_delete<Stream>>( &bytestream, false ), std::move( order ), std::move( encoding ) ) {

	}

	template <typename TByteOrder, typename TEncoding>
	ByteReader::ByteReader( ptr<Stream, optional_delete<Stream>> bytestream, TByteOrder order, TEncoding textencoding ) 
	: stream( std::move( bytestream ) ) {
		byteorder = new Sys::RuntimeByteOrder<TByteOrder>( std::move( order ) );
		encoding = new Text::Encoding::RuntimeTextEncoding<TEncoding>( );

		FileBasedStream* fstream = null;
		if ( ( fstream = dynamic_cast<FileBasedStream*>( stream.get() )  ) != null ) {
			file = fstream->Name();
			dir = Path::GetDirectoryName( file );
		}
	}

	template <typename T>
	void ByteReader::ReadInto( T& item, lword bytestart ) {
		stream->Read( ((byte*)&item) + bytestart, ssizeof( item ) - bytestart );
	}

	template <typename T>
	void ByteReader::ReadInto( T& item, lword bytestart, lword size ) {
		stream->Read( ((byte*)&item) + bytestart, size );
	}

	template <typename T>
	void ByteReader::Read( T& item, lword size ) {
		stream->Read( &item, size );
	}

	template <typename T>
	void ByteReader::Read( T& item ) {
		stream->Read( &item, sizeof( item ) );
	}

}}

#endif // FURROVINEBYTEREADER_INL 