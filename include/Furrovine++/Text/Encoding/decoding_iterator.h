#pragma once

#include <Furrovine++/bidirectional_iterator.h>

namespace Furrovine { namespace Text { namespace Encoding {

	template <typename TEnco, typename TIter>
	struct decoding_iterator 
	: bidirectional_iterator<decoding_iterator<TEnco, TIter>, codepoint, lword, decoding_iterator<TEnco, TIter>, codepoint> {
	public:
		typedef TIter iterator_type;
		typedef TEnco encoding_type;

	private:
		iterator_type first, last;
		encoding_type encoder;

	public:
		decoding_iterator( iterator_type first, iterator_type last, encoding_type encoding = encoding_type() ) : first( std::move( first ) ), last( std::move( last ) ), encoder( encoding ) {

		}

		codepoint dereference( ) const {
			codepoint u;
			encoder.DecodeOne( first, u );
			return u;
		}

		bool equals ( const decoding_iterator& right ) const {
			return first == right.first || (first == last && right.first == right.last);
		}

		bool next( ) {
			codepoint c;
			if ( first != last ) {
				first = encoder.DecodeOne( first, c );
				return true;
			}
			return false;
		}

		bool prev( ) {
			codepoint c;
			if ( first != last ) {
				first = encoder.ReverseDecodeOne( first, c );
				return true;
			}
			return false;
		}

		iterator_type internal_iterator () {
			return first;
		}
	};

}}}
 