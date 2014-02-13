#pragma once

#include <Furrovine++/IO/Stream.h>
#include <Furrovine++/IO/FileBasedStream.h>
#include <Furrovine++/IO/StreamAccess.h>
#include <Furrovine++/IO/FileMode.h>
#include <Furrovine++/IO/FileAccess.h>
#include <Furrovine++/std_defines.h>
#include <fstream>

namespace Furrovine { namespace IO {

	class FileStream : public FileBasedStream {
	protected:
		std::filebuf buff;
		int64 len, pos;
		String file;
		FileMode mode;
		FileAccess access;
		bool eos;

	public:

		furrovineapi FileStream ( const String& filename, FileMode filemode, FileAccess fileaccess = FileAccess::ReadWrite );

		furrovineapi virtual StreamAccess Access() override;

		furrovineapi virtual String Name ();

		furrovineapi virtual bool CanSeek () override;

		furrovineapi virtual bool CanRead () override;

		furrovineapi virtual bool CanWrite () override;

		furrovineapi virtual bool CanTimeout () override;

		furrovineapi virtual bool IsOpen () override;

		furrovineapi virtual bool EoS () override;

		furrovineapi virtual int ReadTimeout () override;

		furrovineapi virtual int WriteTimeout () override;

		furrovineapi virtual uint64 Length () override;

		furrovineapi virtual uint64 Position () override;

		furrovineapi virtual void Close () override;

		furrovineapi virtual void Flush () override;

		furrovineapi virtual uint64 Seek ( int64 offset ) override;

		furrovineapi virtual uint64 Seek ( int64 offset, SeekOrigin origin ) override;

		furrovineapi virtual uint64 Seek ( uint64 offset ) override;

		furrovineapi virtual uint64 Seek ( uint64 offset, SeekOrigin origin ) override;

		furrovineapi virtual uint64 SetLength ( uint64 length ) override;

		furrovineapi virtual uint64 SetPosition ( uint64 position ) override;

		furrovineapi virtual int PeekByte () override;

		furrovineapi virtual int ReadByte () override;

		furrovineapi virtual ulword Read (byte* bytes, ulword count) override;

		furrovineapi virtual ulword Read (void* bytes, ulword bytecount) override;

		furrovineapi virtual ulword Read (byte* bytes, ulword start, ulword count) override;

		furrovineapi virtual void WriteByte (byte b) override;

		furrovineapi virtual void Write (byte* bytes, ulword count) override;

		furrovineapi virtual void Write (byte* bytes, ulword start, ulword count) override;

		furrovineapi ~FileStream();

	};

}}
