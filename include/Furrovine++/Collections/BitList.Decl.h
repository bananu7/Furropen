#ifndef FURROVINEBITLIST_DECL_H
#define FURROVINEBITLIST_DECL_H

#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/FurrovineApi.h>

namespace Furrovine { namespace Collections {

	class BitList {
	public:
		typedef char TElement;

	protected:
		friend struct BitListBool;
		ulword capacity, size, tablesize;
		TElement* data;

		void Resize ();

		void TableResize (ulword cap);

	public:
		static const ulword BitElementSize = sizeof(TElement);
		static const ulword BitElementBitSize = BitElementSize * CHAR_BIT;
		static const ulword BitElementBitMaxIndex = BitElementBitSize - 1;

		struct BitListBool {
		private:
			ulword index;
			BitList* list;
			friend class BitList;

			BitListBool ( BitList* target, ulword idx );

		public:

			operator bool () const;

			BitListBool& operator= ( bool value );

			BitListBool& operator|= ( bool value );

			BitListBool& operator&= ( bool value );

		};

		BitList ( );

		BitList ( ulword initialcapacity );

		BitList ( ulword initialcapacity, bool defaultbit );

		BitList ( bool defaultbit );

		bool At ( ulword index ) const;

		void Add ( bool item );

		void RemoveAt ( ulword index );

		void RemoveFirst ( );

		void RemoveLast ( );

		ulword Capacity () const;

		ulword Count () const;

		void Resize ( ulword cap );

		BitListBool operator[  ] ( ulword index ) {
			return BitListBool(this, index);
		}

		~BitList();

	};

}}

#endif // FURROVINEBITLIST_DECL_H