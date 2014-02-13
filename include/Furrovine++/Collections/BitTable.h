#ifndef FURROVINEBITTABLE_H
#define FURROVINEBITTABLE_H

#include <Furrovine++/Collections/CollectionsCore.h>

namespace Furrovine { namespace Collections {
	
	template <lword n> class BitTable {
	private:
		friend struct BitTableBool;
	
	public:
		typedef byte TElement;

		static const lword BitElementSize = sizeof(TElement);
		static const lword BitElementBitSize = BitElementSize * CHAR_BIT;
		static const lword TableSize = ( n + ( BitElementBitSize - 1 ) ) / BitElementBitSize;
		static const lword Size = n;
		TElement data[ TableSize ];
		
		static const lword Length () {
			return n;
		}

		static const lword Count () {
			return n;
		}

		struct BitTableBool {
		private:
			lword index;
			BitTable* list;
			friend class BitTable;

			BitTableBool ( BitTable* target, lword idx ) {
				list = target;
				index = idx;
			}

		public:

			operator bool () const {
				return ( list->data[ index / BitElementBitSize ] >> ( index % BitElementBitSize ) ) & 0x1; 
			}

			BitTableBool& operator= ( bool value ) {
				if ( value )
					list->data[ index / BitElementBitSize ] |= 0x1 << ( index % BitElementBitSize) ;
				else
					list->data[ index / BitElementBitSize ] &= ~( 0x1 << ( index % BitElementBitSize ) );
				
				return *this;
			}

			BitTableBool& operator|= ( bool value ) {
				value = ((bool)*this) | value;
				if ( value )
					list->data[ index / BitElementBitSize ] |= 0x1 << ( index % BitElementBitSize) ;
				else
					list->data[ index / BitElementBitSize ] &= ~( 0x1 << ( index % BitElementBitSize ) );

				return *this;
			}

			BitTableBool& operator&= ( bool value ) {
				value = ((bool)*this) & value;
				if ( value )
					list->data[ index / BitElementBitSize ] |= 0x1 << ( index % BitElementBitSize) ;
				else
					list->data[ index / BitElementBitSize ] &= ~( 0x1 << ( index % BitElementBitSize ) );

				return *this;
			}

		};

		BitTableBool operator[  ] ( lword index ) {
			return BitTableBool(this, index);
		}

		void ZeroFill () {
			Fill( false );
		}

		void Fill ( bool value ) {
			memset( data, value ? 0xFFFFFF : 0, sizeof(TElement) * n );
		}

		~BitTable () {
	
		}
	};
	
}}

#endif // FURROVINEBITTABLE_H 