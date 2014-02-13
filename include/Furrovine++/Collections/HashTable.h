#ifndef FURROVINEHASHTABLE_H
#define FURROVINEHASHTABLE_H

/*#include <Furrovine++/Platform.h>

namespace Furrovine { namespace Collections {

	template < typename TK, typename TH = Furrovine::FurrovineHasher< TK >, typename TKEq = std::equal_to< TK > > 
	class HashTable {
	public:
		typedef TK TKey;
		typedef TH THash;
		typedef TKEq TKeyEquality;

	private:
		static const ulword neighborhood = sizeof( ulword ) * CHAR_BIT;

		struct Bucket {
		public:
			ulword Hop;
			ulword Hash;
			TKey Key;

			Bucket () : Hop(0), Hash(0), Key() {

			}

			Bucket ( const Bucket& copy ) : Hop(copy.Hop), Hash(copy.Hash), Key( copy.Key ) {

			}

			~Bucket () {

			}
		};

		ulword range, count,
			capacity, bucketmask;
		Bucket* table;

	public:

		HashTable () {
			count = 0;
			capacity = 2;
			if (capacity > 128)
				range = capacity >> 1;
			else
				range = capacity;
			bucketmask = capacity - 1;
			table = new Bucket[ capacity ];
		}

		HashTable ( ulword MaxCapacity ) {
			count = 0;
			capacity = BitMathema::NextPow2( MaxCapacity );
			if (capacity > 128)
				range = capacity >> 1;
			else
				range = capacity;
			bucketmask = capacity - 1;
			table = new Bucket[capacity];
		}

		HashTable ( HashTable&& mov ) {
			count = mov.count;
			capacity = mov.capacity;
			range = mov.range;
			bucketmask = mov.bucketmask;
			table = mov.table;
			mov.table = null;
		}

		HashTable ( const HashTable& copy ) {
			count = copy.count;
			capacity = copy.capacity;
			range = copy.range;
			bucketmask = copy.bucketmask;
			table = new Bucket[capacity];
			for ( ulword i(0); i < capacity; i++ ) {
				if ( copy.table[i].Hop != 0 ) {
					Add( copy.table[i].Key );
				}
			}
		}

		ulword Capacity () const {
			return capacity;
		}

		ulword Count () const {
			return count;
		}

		double LoadFactor () const {
			return (double)count / (double)capacity;
		}

		bool Empty () const {
			return count == 0;
		}

		bool Collides ( const TKey& Key, TKey& collision ) const {
			THash khash;
			ulword hashcode( khash( Key ) );
			ulword address( hashcode & bucketmask );
			Bucket* bucket( &table[address] );
			if ( bucket->Hop == 0 ) {
				return false;
			}
			else {
				collision = bucket->Key;
				return true; 
			}
		}

		bool Add ( const TKey& Key ) {
			THash khash;
			TKeyEquality keq;
			ulword hashcode( khash( Key ) );
			ulword address( hashcode & bucketmask );
			Bucket* bucket( &table[address] );
			ulword scotch(bucket->Hop);

			while (scotch != 0) {
				lword jump = BitMathema::LeastSignificantSet(scotch);
				bucket = &table[(address + jump) & bucketmask];
				if (bucket->Hop != 0 && keq(Key, bucket->Key)) {
					// Failure - the Key already exists
					return false;
				}
				scotch &= ~( 1 << jump );
			}


			bucket = &table[address];
			Bucket* initialbucket( bucket );
			ulword freedom( 0 );

			for (ulword i( 0 ); i < range; ++i, freedom++) {
				if (bucket->Hop == 0)
					break;
				bucket = &table[(++address) & bucketmask];
			}

			if (freedom < range) {
				Bucket* shiftingbucket = null;
				do {
					if (freedom < neighborhood) {
						initialbucket->Hop |= (1 << freedom);
						bucket->Hop |= 1;
						bucket->Key = Key;
						bucket->Hash = hashcode;
						count++;
						return true;
					}
					// Use Hop Information to Find Closer Bucket
					lword shiftingaddress = (address - range - 1) % bucketmask;
					bool shiftfail = true;
					shiftingbucket = &table[shiftingaddress & bucketmask];
					for (lword freedomrun = range - 1; freedomrun > 0; freedomrun--) {
						ulword initialscotch = shiftingbucket->Hop;
						lword freedomrundistance = -1;
						ulword mask = 1;
						for (lword i(0); i < freedomrun; ++i, mask <<= 1) {
							if ((mask & initialscotch) == 1) {
								freedomrundistance = i;
								break;
							}
						}
						if (freedomrundistance != -1) {
							if (initialscotch == shiftingbucket->Hop) {
								Bucket* newtargetbucket = shiftingbucket + freedomrundistance;
								shiftingbucket->Hop |= (1 << freedomrun);
								if (shiftingbucket->Hop != 0) {
									bucket->Key = newtargetbucket->Key;
									bucket->Hash = newtargetbucket->Hash;
								}
								shiftingbucket->Hop |= ~(1 << freedomrun);
								shiftingbucket->Hop &= ~(1 << freedomrundistance);
								bucket = newtargetbucket;
								freedom -= freedomrun;
								shiftfail = false;
								break;
							}
						}
						shiftingbucket = &table[(++shiftingaddress) & bucketmask];
					}
					if (shiftfail)
						bucket = null;
				} while (bucket != null);
			}
			Resize();
			return Add(Key, value);
		}

		bool Remove (const TKey& Key) {
			THash khash;
			TKeyEquality keq;
			ulword hashcode( khash( Key ) );
			ulword address( hashcode & bucketmask );
			Bucket* bucket( &table[address] );
			Bucket* initialbucket( &table[address] );

			switch ( bucket->Hop ) {
			case 0:
				return false;
			case 1:
				if ( hashcode == bucket->Hash && keq(Key, bucket->Key) ) {
					table[address].Hop &= ~1;
					table[address].Hash = 0;
					count--;
					return true;
				}
				else {
					return false;
				}
			default:
				break;
			}

			ulword scotch( bucket->Hop );
			do {
				lword jump = BitMathema::LeastSignificantSet( scotch );
				bucket = &table[(address + jump) & bucketmask];
				if ( hashcode == bucket->Hash && keq(Key, bucket->Key) ) {
					ulword mask( 1 );
					mask <<= jump;
					initialbucket->Hop &= ~(mask);
					bucket->Hash = 0;
					bucket->Hop = 0;
					count--;
					return true;
				}
				scotch &= ~(1 << jump);
			} while (scotch != 0);

			return false;
		}

		bool Contains ( const TKey& Key ) const {
			THash khash;
			TKeyEquality keq;

			ulword hashcode( khash( Key ) );
			ulword address( hashcode & bucketmask );
			Bucket* bucket( &table[address] );
			if ( bucket->Hop == 1 ) {
				return keq( Key, bucket->Key ); 
			}
			ulword scotch(bucket->Hop);

			while ( scotch != 0 ) {
				lword jump = BitMathema::LeastSignificantSet( scotch );
				bucket = &table[(address + jump) & bucketmask];
				if (bucket->Hop != 0 && keq(Key, bucket->Key))
					return true;
				scotch &= ~(1 << jump);
			}

			bucket = &table[address];
			if (address > capacity - neighborhood) {
				lword i( 0 );
				lword cap( capacity - address );
				for (lword i(0); i < cap; ++i, bucket++) {
					if (bucket->Hop != 0 && keq(Key, bucket->Key))
						return true;
				}
				bucket = table;
				for (i = cap; i < neighborhood; ++i, bucket++) {
					if (bucket->Hop != 0 && keq(Key, bucket->Key))
						return true;
				}
			}
			else {
				for ( lword i( 0 ); i < neighborhood; ++i, bucket++ ) {
					if ( bucket->Hop != 0 && keq(Key, bucket->Key) )
						return true;
				}
			}

			return false;
		}

		void Resize () {
			ulword oldcap = capacity;
			capacity <<= 1;
			bucketmask = capacity - 1;
			if ( capacity > 128 )
				range = capacity >> 1;
			else
				range = capacity;
			Bucket* old = table;
			table = new Bucket[capacity];
			if (count > 0) {
				count = 0;
				for ( ulword i( 0 ); i < oldcap; i++ )
					if ( old[i].Hop != 0 )
						Add( old[i].Key );
			}
			delete[] old;
		}

		void Reserve ( ulword requestedsize ) {
			if (requestedsize < capacity)
				return;
			ulword oldcap = capacity;
			capacity = BitMathema::NextPow2(requestedsize);
			bucketmask = capacity - 1;
			if (capacity > 128)
				range = capacity >> 1;
			else
				range = capacity;
			Bucket* old = table;
			table = new Bucket[capacity];
			if (count > 0) {
				count = 0;
				for (ulword i( 0 ); i < oldcap; i++)
					if (table[i].Hop != 0)
						Add( old[i].Key );
			}
			delete[] old;
			old = null;
		}

		void Clear () {
			for ( ulword i = 0; i < capacity; ++i ) {
				table[i].Hash = 0;
				table[i].Hop = 0;
			}
			count = 0;
		}

		bool operator[] ( const TKey& Key ) {
			return Contains( Key );
		}

		TKey& operator() ( lword index ) {
			return table[ index ].Key;
		}

		HashTable& operator= ( const HashTable& copy ) {
			if ( table != null ) {
				Clear();
				delete[] table;
				table = null;
			}
			count = copy.count;
			capacity = copy.capacity;
			range = copy.range;
			bucketmask = copy.bucketmask;
			table = new Bucket[capacity];
			for (ulword i(0); i < capacity; i++) {
				if ( copy.table[i].Hop != 0 ) {
					Add( copy.table[i].Key, copy.table[i].Key.second );
				}
			}
			return *this;
		}

		HashTable& operator= ( HashTable&& mov ) {
			count = mov.count;
			capacity = mov.capacity;
			range = mov.range;
			bucketmask = mov.bucketmask;
			table = mov.table;
			mov.table = null;
		}

		~HashTable () {
			if ( table != null ) {
				Clear();
				delete[] table;
				table = null;
			}
		}

	};

}}
*/

#endif // FURROVINEHASHTABLE_H 
