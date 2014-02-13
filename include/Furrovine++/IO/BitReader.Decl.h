#ifndef FURROVINEBITREADER_DECL_H
#define FURROVINEBITREADER_DECL_H

#include <Furrovine++/Strings.h>
#include <Furrovine++/IO/Stream.h>

namespace Furrovine { namespace IO {

	class BitReader {
	protected:
		Stream* stream;

	public:

		BitReader( Stream* stream );

		bool HasStream ();

		Stream& BaseStream();

	};

}}

#endif // FURROVINEBITREADER_DECL_H