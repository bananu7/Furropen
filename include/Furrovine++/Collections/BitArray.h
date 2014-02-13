#ifndef FURROVINEBITARRAY_H
#define FURROVINEBITARRAY_H

#include <Furrovine++/Collections/CollectionsCore.h>

namespace Furrovine { namespace Collections {
	
	class BitArray {
	public:
		typedef byte TElement;

	protected:
		friend struct BitArrayBool;
		lword len, tablesize;
		TElement* data;
		bool bitdefault;

	public:
		static const lword BitElementSize = sizeof(TElement);
		static const lword BitElementBitSize = BitElementSize * CHAR_BIT;
		static const lword BitElementBitMaxIndex = BitElementBitSize - 1;

		struct BitArrayBool {
		private:
			lword index;
			BitArray* arr;
			friend class BitArray;

			BitArrayBool ( BitArray* target, lword idx ) {
				arr = target;
				index = idx;
			}

		public:

			operator bool () const {
				return ( arr->data[ index / BitElementBitSize ] >> ( index % BitElementBitSize ) ) & 0x1; 
			}

			BitArrayBool& operator= ( bool value ) {
				if ( value )
					arr->data[ index / BitElementBitSize ] |= 0x1 << ( index % BitElementBitSize) ;
				else
					arr->data[ index / BitElementBitSize ] &= ~( 0x1 << ( index % BitElementBitSize ) );

				return *this;
			}

			BitArrayBool& operator|= ( bool value ) {
				value = ((bool)*this) | value;
				if ( value )
					arr->data[ index / BitElementBitSize ] |= 0x1 << ( index % BitElementBitSize) ;
				else
					arr->data[ index / BitElementBitSize ] &= ~( 0x1 << ( index % BitElementBitSize ) );

				return *this;
			}

			BitArrayBool& operator&= ( bool value ) {
				value = ((bool)*this) & value;
				if ( value )
					arr->data[ index / BitElementBitSize ] |= 0x1 << ( index % BitElementBitSize) ;
				else
					arr->data[ index / BitElementBitSize ] &= ~( 0x1 << ( index % BitElementBitSize ) );

				return *this;
			}

		};

		BitArray ( ) : len(0), data(null), bitdefault(false), tablesize(0) {
			
		}

		BitArray ( lword initialsize ) : len(initialsize), data(null), bitdefault(false) {
			tablesize = (len + BitElementBitMaxIndex) / BitElementBitSize;
			data = new TElement[ tablesize ];
			if (bitdefault)
				memset(data, 0xFFFFFFFF, tablesize);
			else
				memset(data, 0, tablesize);
		}

		BitArray ( lword initialsize, bool defaultbit ) : len(initialsize), data(null), bitdefault(defaultbit) {
			tablesize = (len + BitElementBitMaxIndex) / BitElementBitSize;
			data = new TElement[ tablesize ];
			if (bitdefault)
				memset(data, 0xFFFFFFFF, tablesize);
			else
				memset(data, 0, tablesize);
		}

		bool At ( lword index ) {
			lword bitindex = index & 0x1F;
			index /= BitElementBitSize;
			return ( ( data[ index ] >> bitindex ) & 0x1 ) == 1;
		}

		void SetAt ( lword index, bool value ) {
			operator[](index) = value;
		}

		void SetRange ( lword index, lword count, bool value ) {
			lword tableindex = index / BitElementBitSize;
			lword spill = count / BitElementBitSize;
			spill = Mathema<lword>::Max( tableindex + spill, tablesize );
			count = Mathema<lword>::Min( index + count, len );
			for ( ; tableindex < spill; ++tableindex ) {
				data[ tableindex ] = value ? (TElement)0xFFFFFFFF : 0;
				index += BitElementSize;
			}
			for ( lword i = index; i < count; ++i )
				operator[](i) = value;
		}

		lword Count () {
			return len;
		}

		lword Length () {
			return len;
		}

		void Resize ( lword cap ) {
			lword oldtablesize = tablesize;
			tablesize = (cap + BitElementBitMaxIndex) / BitElementBitSize;
			TElement* resize = new TElement[ tablesize ];
			lword i;
			for ( i = 0; i < oldtablesize; ++i ) {
				resize[ i ] = data[ i ];
			}
			for (; i < tablesize; ++i) {
				resize[ i ] = (TElement)(bitdefault ? 0xFFFFFFFF : 0);
			}
			delete[] data;
			data = resize;
			resize = null;
			len = cap;
		}

		void ResizeDiscard ( lword cap ) {
			tablesize = (cap + BitElementBitMaxIndex) / BitElementBitSize;
			delete[] data;
			data = new TElement[ tablesize ];
			len = cap;
		}

		void EnsureSize ( lword size ) {
			if (size > len) {
				Resize( size );
			}
		}

		void Fill ( bool value ) {
			memset( data, value ? 0xFFFFFFFF : 0, len * sizeof(TElement) );
		}

		void ZeroFill ( ) {
			Fill( false );
		}

		BitArrayBool operator[ ] ( lword index ) {
			return BitArrayBool(this, index);
		}

		~BitArray() {
			if (data != null) {
				delete[] data;
				data = null;
			}
			len = 0;
			tablesize = 0;
		}

	};
	
}}

#endif // FURROVINEBITARRAY_H 