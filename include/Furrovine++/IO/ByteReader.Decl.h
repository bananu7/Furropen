#pragma once

#include <Furrovine++/partial_array.h>
#include <Furrovine++/ptr.h>
#include <Furrovine++/Strings.h>
#include <Furrovine++/deleters.h>
#include <Furrovine++/IO/Stream.h>
#include <Furrovine++/IO/FileMode.h>
#include <Furrovine++/IO/SeekOrigin.h>
#include <Furrovine++/Sys/RuntimeByteOrder.h>
#include <Furrovine++/Text/Encoding/TextEncoding.h>
#include <Furrovine++/Vector2.h>
#include <Furrovine++/Vector3.h>
#include <Furrovine++/Vector4.h>
#include <Furrovine++/Matrix.h>
#include <Furrovine++/Color.h>
#include <Furrovine++/Rectangle.h>
#include <vector>

namespace Furrovine { namespace IO {

	class ByteReader {
	protected:
		std::array<byte, 16> readbuffer;
		String file, dir;
		ptr<Text::Encoding::TextEncoding> encoding;
		ptr<Sys::ByteOrder> byteorder;
		ptr<Stream, optional_delete<Stream>> stream;

	public:

		furrovineapi ByteReader ( const String& file, FileMode filemode = FileMode::Open );
		furrovineapi ByteReader ( Stream& bytestream );
		template <typename TByteOrder, typename TEncoding = Text::Encoding::utf8>
		ByteReader ( const String& file, FileMode filemode, TByteOrder bitendian, TEncoding textencoding = TEncoding() );
		template <typename TByteOrder, typename TEncoding = Text::Encoding::utf8>
		ByteReader ( Stream& bytestream, TByteOrder bitendian, TEncoding textencoding = TEncoding() );
		template <typename TByteOrder, typename TEncoding = Text::Encoding::utf8>
		ByteReader ( ptr<Stream, optional_delete<Stream>> bytestream, TByteOrder bitendian, TEncoding textencoding = TEncoding() );

		furrovineapi Stream& BaseStream ();

		furrovineapi bool ReadingFromFile ();

		furrovineapi bool EoF ();

		furrovineapi bool IsOpen ();

		furrovineapi String Directory ();

		furrovineapi String FileName ();

		furrovineapi int64 Position ();

		furrovineapi int64 Length ();

		furrovineapi Text::Encoding::TextEncoding& Encoding ();

		furrovineapi Sys::ByteOrder& ByteOrder ();

		furrovineapi codepoint ReadChar ();

		furrovineapi codepoint PeekChar ();

		furrovineapi void Seek ( uint64 offset, SeekOrigin origin );

		furrovineapi void Seek ( uint32 offset, SeekOrigin origin );

		furrovineapi void Seek ( int64 offset, SeekOrigin origin );

		furrovineapi void Seek ( int32 offset, SeekOrigin origin );

		furrovineapi void Read ( byte* bytes, ulword start, ulword count );

		furrovineapi void Read ( byte* bytes, ulword count );

		furrovineapi void Read ( void* bytes, ulword bytecount );

		template <typename T> 
		void Read ( T& item );

		template <typename T> 
		void Read ( T& item, lword size );

		template <typename T> 
		void ReadInto ( T& item, lword bytestart, lword size );

		template <typename T> 
		void ReadInto ( T& item, lword bytestart );

		furrovineapi Vector2i ReadVector2i ( );

		furrovineapi Rectangle ReadRectangle ( );

		furrovineapi Vector2 ReadVector2 ( );

		furrovineapi Vector3 ReadVector3 ( );

		furrovineapi Vector4 ReadVector4 ( );

		furrovineapi Color ReadColor ( );

		furrovineapi Matrix ReadMatrix ( );

		furrovineapi void ReadInt16 ( int16& bit16 );

		furrovineapi void ReadInt24 ( int32& bit24 );

		furrovineapi void ReadInt32 ( int32& bit32 );

		furrovineapi void ReadInt64 ( int64& bit64 );

		furrovineapi void ReadUInt16 ( ushort& bit16 );

		furrovineapi void ReadUInt24 ( uint& bit24 );

		furrovineapi void ReadUInt32 ( uint& bit32 );

		furrovineapi void ReadUInt64 ( uint64& bit64 );

		furrovineapi void ReadSingle ( single& bit32 );

		furrovineapi void ReadDouble ( double& bit64 );

		furrovineapi sbyte ReadInt8 ( );

		furrovineapi byte ReadUInt8 ( );

		furrovineapi int16 ReadInt16 ( );

		furrovineapi int32 ReadInt24 ( );

		furrovineapi int32 ReadInt32 ( );

		furrovineapi int64 ReadInt64 ( );

		furrovineapi ushort ReadUInt16 ( );

		furrovineapi uint ReadUInt24 ( );

		furrovineapi uint ReadUInt32 ( );

		furrovineapi uint64 ReadUInt64 ( );

		furrovineapi single ReadSingle ( );

		furrovineapi double ReadDouble ( );

		furrovineapi void ReadShort ( short& bit16 );

		furrovineapi void ReadInt ( int& bit32 );

		furrovineapi void ReadLong ( int64& bit64 );

		furrovineapi void ReadUShort ( ushort& bit16 );

		furrovineapi void ReadUInt ( uint& bit32 );

		furrovineapi void ReadULong ( uint64& bit64 );

		furrovineapi void ReadFloat ( float& bit32 );

		furrovineapi sbyte ReadSByte ( );

		furrovineapi byte ReadByte ( );

		furrovineapi short ReadShort ( );

		furrovineapi int ReadInt ( );

		furrovineapi int64 ReadLong ( );

		furrovineapi ushort ReadUShort ( );

		furrovineapi uint ReadUInt ( );

		furrovineapi uint64 ReadULong ( );

		furrovineapi float ReadFloat ( );

		furrovineapi void ReadVector2i ( Vector2i& point );

		furrovineapi void ReadRectangle ( Rectangle& rect );

		furrovineapi void ReadVector2 ( Vector2& vector );

		furrovineapi void ReadVector3 ( Vector3& vector );

		furrovineapi void ReadVector4 ( Vector4& vector );

		furrovineapi void ReadColor ( Color& color );

		furrovineapi void ReadMatrix ( Matrix& matrix );

		furrovineapi ~ByteReader();

	};

}}
