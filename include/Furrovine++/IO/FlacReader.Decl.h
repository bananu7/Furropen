#ifndef FURROVINEFLACREADER_DECL_H
#define FURROVINEFLACREADER_DECL_H

#include <Furrovine++/IO/Streams.h>
#include <Furrovine++/Sys/RuntimeByteOrder.h>

namespace Furrovine { namespace IO {

	class FlacReader {
	public:
		furrovineapi static const ulword DefaultStreamBufferSize = 16384;

	private:

		String filename, directory;
		byte* streambuffer;
		int streambuffersize;
		int64 position, len, bitposition;
		int bitshift, streambufferposition, streambufferlen;
		uint32 cache;
		bool endofstream, bufferedend;
		ptr<Stream, optional_delete<Stream>> stream;

	public:

		furrovineapi Stream& BaseStream ();

		furrovineapi bool ReadingFromFile ();

		furrovineapi String Directory ();

		furrovineapi String FileName ();

		furrovineapi int64 Position ();

		furrovineapi int64 BitPosition ();

		furrovineapi int64 Length ();

		furrovineapi int64 BitLength ();

		furrovineapi bool EoF ();

		furrovineapi FlacReader ( Stream& readerstream, bool ownsstream = false );

		furrovineapi FlacReader ( Stream* readerstream, bool ownsstream = false );

		furrovineapi FlacReader ( Stream& readerstream, int streambuffersize, bool ownsstream = false );

		furrovineapi FlacReader ( Stream* readerstream, int buffersize, bool ownsstream = false );

		furrovineapi void Seek ( int64 offset, SeekOrigin origin );

	public:
		furrovineapi uint UPeek ( );

		/* skip any number of bits */
		furrovineapi void SkipBits ( int bits );

		/* skip up to 16 bits */
		furrovineapi void Skip16Bits ( int bits );

		/* skip up to 8 bits */
		furrovineapi void Skip8Bits ( int bits );

		/* supports reading 1 to 24 bits, in big RuntimeByteOrder format */
		furrovineapi uint Read24UBits ( int bits );

		furrovineapi uint Peek24UBits ( int bits );

		furrovineapi uint Read32UBits ( int bits );

		furrovineapi uint64 Read64UBits ( int bits );

		/* reads a single bit */
		furrovineapi uint ReadBit ( );

		furrovineapi uint ReadUnsignedUnary ( );

		furrovineapi int Read32Bits ( int bits );

		furrovineapi uint ReadUtf8 ( );

		furrovineapi int ReadRiceSigned ( int k );

		furrovineapi int ReadUnary ( );

		furrovineapi void ReadRice ( int n, int k, int* ricepartitions, int index );

		furrovineapi void ReadAdvancingRice ( int n, int k, int* ricepartitions, int& index );

		furrovineapi void ReadRice ( int n, int k, int* ricepartitions );

		furrovineapi void Align ( );

		furrovineapi void Close ( );

		furrovineapi ~FlacReader ( );

	private:

		furrovineapi void LoadBuffer ( );

		furrovineapi void BufferShift ( );
	};

}}

#endif // FURROVINEFLACREADER_DECL_H