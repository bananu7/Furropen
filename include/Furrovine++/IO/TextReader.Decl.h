#pragma once

#include <Furrovine++/fixed_vector.h>
#include <Furrovine++/ptr.h>
#include <Furrovine++/Strings.h>
#include <Furrovine++/deleters.h>
#include <Furrovine++/IO/Stream.h>
#include <Furrovine++/Text/Encoding/TextEncoding.h>
#include <Furrovine++/IO/FileMode.h>
#include <Furrovine++/IO/SeekOrigin.h>
#include <Furrovine++/Text/Encoding/TextEncoding.h>
#include <vector>

namespace Furrovine { namespace IO {

	class TextReader {
	protected:
		furrovineapi static const ulword DefaultBufferSize = 8192;
		ulword bytebuffersize, charbufferposition, charbufferlen;
		ullong openingposition;
		String file, dir;
		fixed_vector<byte, 8> preamble;
		std::vector<codepoint> charbuffer;
		std::vector<byte> bytebuffer;
		ptr<Text::Encoding::TextEncoding> encoding;
		ptr<Stream, optional_delete<Stream>> stream;
		String buffer;
		
	public:

		furrovineapi TextReader( const String& path, FileMode filemode = FileMode::Open, bool detectEncodingFromByteOrderMarks = true, ulword buffsize = DefaultBufferSize );
		furrovineapi TextReader( ptr<Stream, optional_delete<Stream>> textstream, bool detectencodingfrombyteordermarks = true, ulword buffsize = DefaultBufferSize );
		furrovineapi TextReader( Stream& textstream, bool detectEncodingFromByteOrderMarks = true, ulword buffsize = DefaultBufferSize );
		template <typename TEncoding>
		TextReader ( const String& path, FileMode filemode, TEncoding encoding, bool detectEncodingFromByteOrderMarks = true, ulword buffsize = DefaultBufferSize );
		template <typename TEncoding>
		TextReader ( Stream& stream, TEncoding textencoding, bool detectencodingfrombyteordermarks = true, ulword buffsize = DefaultBufferSize );
		template <typename TEncoding>
		TextReader( ptr<Stream, optional_delete<Stream>> textstream, TEncoding textencoding, bool detectencodingfrombyteordermarks = true, ulword buffsize = DefaultBufferSize );
		furrovineapi TextReader( ptr<Stream, optional_delete<Stream>> textstream, ptr<Text::Encoding::TextEncoding> textencoding, bool detectencodingfrombyteordermarks = true, ulword buffsize = DefaultBufferSize );

		furrovineapi bool HasStream ();

		furrovineapi Stream& BaseStream ();

		furrovineapi bool EoF ();

		furrovineapi String Directory ();

		furrovineapi String FileName ();

		furrovineapi ullong Length ( );

		furrovineapi ullong Position ( );

		furrovineapi void Rewind( );

		furrovineapi Text::Encoding::TextEncoding& Encoding( );

		furrovineapi int Peek ( );

		furrovineapi int Read ( );

		furrovineapi int ReadChar ( );

		furrovineapi int Unread ( );

#pragma region Skip

		furrovineapi bool Skip ( int count );

		furrovineapi void SkipWhiteSpace ( );

		furrovineapi void SkipBlankSpace ( );

		furrovineapi void SkipAlphaNumeric ( );

		furrovineapi void SkipLetters ( );

		furrovineapi void SkipDigits ( bool decimalpoint = true );

		furrovineapi void SkipNumeric ( bool decimalpoint = true, bool negativesign = true );

		furrovineapi bool SkipLine ( );

#pragma endregion

#pragma region Counting

		furrovineapi ullong LineCount ( );

#pragma endregion

#pragma region At

		furrovineapi bool At ( codepoint m );

		furrovineapi bool At ( String marker, bool skipoveriftrue = false );

		furrovineapi bool AtNewLine ( );

		furrovineapi bool AtDigit ( );

		furrovineapi bool AtNumeric ( );

		furrovineapi bool AtLetter ( );

		furrovineapi bool AtAlphaNumeric ( );

#pragma endregion

#pragma region Read

		furrovineapi String ReadLine ( );

		furrovineapi void ReadLine ( String& value );

		furrovineapi String ReadToEnd ( );

		furrovineapi void ReadToEnd ( String& value );

		furrovineapi String ReadFor( ullong count );
		
		furrovineapi void ReadFor( ullong count, String& value );

		furrovineapi String ReadBlankSpace ( );

		furrovineapi String ReadWhiteSpace ( );

		furrovineapi bool ReadBlankSpace ( String& value );

		furrovineapi bool ReadWhiteSpace ( String& value );

		furrovineapi String ReadTo ( codepoint delimeter, bool stopatnewline = true );

		furrovineapi bool ReadTo ( codepoint delimeter, String& value, bool stopatnewline = true );

		furrovineapi String ReadToNewLine ( );

		furrovineapi bool ReadToNewLine ( String& value );

		furrovineapi String ReadDigits ( bool negativesign = false, bool decimalpoint = false );

		furrovineapi String ReadSignedDigits ( bool decimalpoint = false );

		furrovineapi bool ReadDigits ( String& value, bool negativesign = false, bool decimalpoint = false );

		furrovineapi bool ReadSignedDigits ( String& value, bool decimalpoint = false );

		furrovineapi bool ReadUnsignedDigits ( String& value, bool decimalpoint = false );

		furrovineapi String ReadNumeric ( bool E = false );

		furrovineapi bool ReadNumeric ( String& value, bool E = false );

		furrovineapi String ReadLetters ( );

		furrovineapi bool ReadLetters ( String& value );

		furrovineapi String ReadAlphaNumeric ( );

		furrovineapi bool ReadAlphaNumeric ( String& value );

		furrovineapi bool ReadInt16 ( short& value );

		furrovineapi bool ReadUInt16 ( ushort& value );

		furrovineapi bool ReadInt32 ( int& value );

		furrovineapi bool ReadUInt32 ( uint& value );

		furrovineapi bool ReadInt64 ( llong& value );

		furrovineapi bool ReadUInt64 ( ullong& value );

		furrovineapi bool ReadSingle ( float& value );

		furrovineapi bool ReadDouble ( double& value );

		furrovineapi bool ReadShort ( short& value );

		furrovineapi bool ReadUShort ( ushort& value );

		furrovineapi bool ReadInt ( int& value );

		furrovineapi bool ReadUInt ( uint& value );

		furrovineapi bool ReadLong ( llong& value );

		furrovineapi bool ReadULong ( ullong& value );

		furrovineapi short ReadInt16 ( );

		furrovineapi ushort ReadUInt16 ( );

		furrovineapi int ReadInt32 ( );

		furrovineapi uint ReadUInt32 ( );

		furrovineapi llong ReadInt64 ( );

		furrovineapi ullong ReadUInt64 ( );

		furrovineapi short ReadShort ( );

		furrovineapi ushort ReadUShort ( );

		furrovineapi int ReadInt ( );

		furrovineapi uint ReadUInt ( );

		furrovineapi llong ReadLong ( );

		furrovineapi ullong ReadULong ( );

		furrovineapi double ReadDouble ( );

		furrovineapi bool ReadFloat ( float& value );

		furrovineapi float ReadFloat ( );

		furrovineapi float ReadSingle ( );

#pragma endregion

		furrovineapi void Close ( );

		furrovineapi void DebufferStream ( );

		furrovineapi ~TextReader();


	protected:
		furrovineapi void BufferStream ( );

		furrovineapi void BackBufferStream ( );

	};

}}
