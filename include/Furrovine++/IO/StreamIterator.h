#ifndef FURROVINESTREAMITERATOR_H
#define FURROVINESTREAMITERATOR_H

#include <Furrovine++/IO/Stream.h>

namespace Furrovine { namespace IO {

	struct StreamIterator {
	private:
		usword pos;
		int32 last;
		Stream* basestream;

	public:

		StreamIterator ( Stream* stream ) : basestream(stream), pos(basestream->Position()) {
			last = basestream->PeekByte();
		}

		StreamIterator ( const StreamIterator& it ) : basestream( it.basestream ), last( it.last ), pos(it.pos) {
			
		}
		
		int32 Dereference( ) const {
			return last;
		}

		bool Equals ( const StreamIterator& right ) const {
			return basestream == right.basestream && pos == right.pos;
		}

		bool Next ( ) {
			if ( last != -1 ) {
				basestream->ReadByte();
				last = basestream->PeekByte();
				pos = basestream->Position();
				return true;
			}
			return false;
		}

		bool Previous ( ) {
			if ( pos != 0 ) {
				basestream->Seek( -1LL, SeekOrigin::Current );
				last = basestream->PeekByte();
				pos = basestream->Position();
				return true;
			}
			return false;
		}

		int32 operator* ( ) const {
			return Dereference();
		}

		StreamIterator& operator++ () {
			Next( );
			return *this;
		}

		StreamIterator operator++ ( int ) {
			StreamIterator preserve( *this );
			Next( );
			return preserve;
		}

		StreamIterator& operator+= ( lword moves ) {
			while ( moves-- > 0 ) {
				if ( !Next() )
					break;
			}
			return *this;
		}

		StreamIterator operator+ ( lword moves ) const {
			StreamIterator out( *this );
			while ( moves-- > 0 ) {
				if ( !out.Next( ) )
					break;
			}
			return out;
		}

		StreamIterator& operator-- () {
			Next( );
			return *this;
		}

		StreamIterator operator-- ( int ) {
			StreamIterator preserve( *this );
			Next( );
			return preserve;
		}

		StreamIterator& operator-= ( lword moves ) {
			while ( moves-- > 0 ) {
				if ( !Next() )
					break;
			}
			return *this;
		}

		StreamIterator operator- ( lword moves ) const {
			StreamIterator out( *this );
			while ( moves-- > 0 ) {
				if ( !out.Next( ) )
					break;
			}
			return out;
		}

		bool operator== ( const StreamIterator& right ) const {
			return Equals( right );
		}

		bool operator!= ( const StreamIterator& right ) const {
			return !Equals(right);
		}

	};

}}

#endif // FURROVINESTREAMITERATOR_H 