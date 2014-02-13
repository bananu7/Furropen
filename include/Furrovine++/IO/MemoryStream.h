#pragma once

#include <Furrovine++/IO/Stream.h>
#include <Furrovine++/deleters.h>
#include <Furrovine++/buffer_view.h>
#include <memory>

namespace Furrovine { namespace IO {
	
	class MemoryStream : public Stream {
	private:
		std::unique_ptr<byte, optional_delete<byte, array_delete<byte>>> buffer;
		buffer_view<byte> view;
		ulword pos;
		StreamAccess access;

	public:
		using Stream::Seek;

		furrovineapi MemoryStream( const buffer_view<byte>& bytes, ulword position = 0 );

		furrovineapi MemoryStream( buffer_view<byte>& bytes, bool ownsmemory );

		furrovineapi MemoryStream( buffer_view<byte>& bytes, ulword position = 0, bool ownsmemory = true );

		furrovineapi virtual StreamAccess Access ();

		furrovineapi virtual bool CanSeek ();

		furrovineapi virtual bool CanRead ();

		furrovineapi virtual bool CanWrite ();

		furrovineapi virtual bool CanTimeout ();

		furrovineapi virtual bool IsOpen ();

		furrovineapi virtual bool EoS ();

		furrovineapi virtual int ReadTimeout ();

		furrovineapi virtual int WriteTimeout ();

		furrovineapi virtual uint64 Length ();

		furrovineapi virtual uint64 Position ();

		furrovineapi virtual void Close ();

		furrovineapi virtual void Flush ();

		furrovineapi virtual uint64 Seek ( int64 offset, SeekOrigin origin );

		furrovineapi virtual uint64 Seek ( uint64 offset, SeekOrigin origin );

		furrovineapi virtual uint64 SetPosition ( uint64 position );

		furrovineapi virtual uint64 SetLength ( uint64 length );

		furrovineapi virtual int ReadByte ( );

		furrovineapi virtual int PeekByte ( );

		furrovineapi virtual ulword Read( byte* bytes, ulword count );

		furrovineapi virtual ulword Read ( byte* bytes, ulword start, ulword count );

		furrovineapi virtual ulword Read ( void* bytes, ulword bytecount );

		furrovineapi virtual void WriteByte ( byte b );

		furrovineapi virtual void Write ( byte* bytes, ulword count );

		furrovineapi virtual void Write ( byte* bytes, ulword start, ulword count );

		furrovineapi ~MemoryStream ( );

	};
	
}}
