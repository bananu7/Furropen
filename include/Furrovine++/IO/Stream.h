#pragma once

#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/IO/SeekOrigin.h>
#include <Furrovine++/IO/StreamAccess.h>

namespace Furrovine { namespace IO {
	
	class Stream {
	public:
		furrovineapi virtual StreamAccess Access () = 0;
		furrovineapi virtual bool CanSeek () = 0;
		furrovineapi virtual bool CanRead () = 0;
		furrovineapi virtual bool CanWrite () = 0;
		furrovineapi virtual bool CanTimeout () = 0;
		furrovineapi virtual bool EoS () = 0;
		furrovineapi virtual bool IsOpen () = 0;

		furrovineapi virtual int ReadTimeout () = 0;
		furrovineapi virtual int WriteTimeout () = 0;

		furrovineapi virtual uint64 Length () = 0;
		furrovineapi virtual uint64 Position () = 0;

		furrovineapi virtual void Close () = 0;
		furrovineapi virtual void Flush () = 0;

		furrovineapi virtual uint64 Seek ( int64 offset, SeekOrigin origin) = 0;
		furrovineapi virtual uint64 Seek ( uint64 offset, SeekOrigin origin) = 0;

		furrovineapi virtual uint64 Seek ( int64 offset ) {
			return Seek( offset, SeekOrigin::Begin );
		}

		furrovineapi virtual uint64 Seek ( uint64 offset ) {
			return Seek( offset, SeekOrigin::Begin );
		}

		furrovineapi virtual uint64 Seek ( int32 offset ) {
			return Seek( (int64)offset );
		}

		furrovineapi virtual uint64 Seek ( uint32 offset ) {
			return Seek( (uint64)offset );
		}

		furrovineapi virtual uint64 Seek ( int32 offset, SeekOrigin origin) {
			return Seek( (int64)offset, origin );
		}

		furrovineapi virtual uint64 Seek ( uint32 offset, SeekOrigin origin) {
			return Seek( (uint64)offset, origin );
		}

		furrovineapi virtual uint64 SetLength ( uint64 length) = 0;
		furrovineapi virtual uint64 SetPosition ( uint64 position) = 0;

		furrovineapi virtual int PeekByte () = 0;
		furrovineapi virtual int ReadByte () = 0;
		furrovineapi virtual ulword Read ( byte* bytes, ulword count ) = 0;
		furrovineapi virtual ulword Read ( byte* bytes, ulword start, ulword count ) = 0;
		furrovineapi virtual ulword Read ( void* bytes, ulword bytecount ) = 0;

		furrovineapi virtual void WriteByte ( byte b ) = 0;
		furrovineapi virtual void Write ( byte* bytes, ulword count ) = 0;
		furrovineapi virtual void Write ( byte* bytes, ulword start, ulword count ) = 0;

		furrovineapi virtual ~Stream () {

		}
	};
	
}}
