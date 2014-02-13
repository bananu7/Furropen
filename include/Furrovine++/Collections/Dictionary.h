#pragma once

#include <type_traits>
#include <memory>
#include <exception>
#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/default_hash.h>
#include <Furrovine++/scoped_destructor.h>

namespace Furrovine { namespace Collections {

	template < typename TK, typename TV, typename TH = std::hash<TK>, 
		typename TKEq = std::equal_to< TK >, 
		typename TAlloc = std::allocator< std::pair<const TK, TV> > > 
	class Dictionary {
	public:
		typedef TK TKey;
		typedef TV TValue;
		typedef TH THash;
		typedef TKEq TKeyEquality;
		typedef TAlloc TAllocator;
		typedef std::pair<const TKey, TValue> TKeyValuePair;
		typedef std::pair<ulword, ulword> TMeta;
		typedef typename std::allocator_traits< TAllocator >::template rebind_alloc< TMeta >::other TMetaAllocator;
		
	private:
		struct noexceptor_constructor_t {} noexcept_constructor;

		// While these utility functions exist elsewhere,
		// it is best to have this header as an independent header at all times
		static ulword NextPow2( ulword value ) {
			ulword pow2( 1 );
			while ( pow2 < value ) {
				pow2 <<= 1;
			}
			return pow2;
		}

		static ulword LeastSignificantSet( ulword v ) {
			ulword pos = 0;
			while ( !( v & 1 ) ) {
				v >>= 1;
				++pos;
			}
			return pos;
		}

		static const ulword neighborhood = sizeof( ulword ) * CHAR_BIT;
		
		TKEq keq;
		THash hash;
		TAlloc dataalloc;
		TMetaAllocator metaalloc;
		ulword range, count,
			capacity, bucketmask;
		TKeyValuePair* tabledatastorage;
		TMeta* tablemetastorage;

		bool is_null( ) const {
			return tabledatastorage == null;
		}

		bool is_not_null( ) const {
			return tabledatastorage != null;
		}

		void ressurect( ) {
			if ( is_not_null( ) )
				return;
			ressurect_unchecked( );
		}

		void ressurect_unchecked( ulword withcapacity = 2 ) {
			count = 0;
			set_capacity( withcapacity );
			make_storage( );
		}

		void make_storage( ) {
			tabledatastorage = dataalloc.allocate( capacity );
			tablemetastorage = metaalloc.allocate( capacity );
			// the meta storage is the only thing we need zero'd out
			// because the Hop value of `0` tells us that the bucket
			// hasn't been used yet
			// Can't use memset, have to explicitly construct
			// std::memset( tablemetastorage, 0, sizeof( TMeta ) * capacity );
			TMeta meta( 0, 0 );
			for ( ulword i = 0; i < capacity; ++i ) {
				metaalloc.construct( std::addressof( tablemetastorage[ i ] ), meta );
			}
		}

		void delete_storage( ) {
			dataalloc.deallocate( tabledatastorage, capacity );
			metaalloc.deallocate( tablemetastorage, capacity );
			tabledatastorage = null;
			tablemetastorage = null;
		}

		void clear_meta( ) {
			// Clear metadata
			// It could do this, but we're using allocators now
			//std::memset( tablemetastorage, 0, sizeof( TMetaPair ) * capacity );
			for ( ulword i = 0; i < capacity; ++i ) {
				metaalloc.destroy( std::addressof( tablemetastorage[ i ] ) );
			}
		}

		void clear_data( ) {
			// Destruct key/values
			for ( ulword i = 0; i < capacity && count > 0; ++i ) {
				if ( tablemetastorage[ i ].first != 0 ) {
					dataalloc.destroy( std::addressof( tabledatastorage[ i ] ) );
					tablemetastorage[ i ].first = 0;
					--count;
				}
			}
		}

		void clear_all( ) {
			for ( ulword i = 0; i < capacity; ++i ) {
				bool nodestruct = count < 0 || tablemetastorage[ i ].first == 0;
				metaalloc.destroy( std::addressof( tablemetastorage[ i ] ) );
				if ( nodestruct )
					continue;
				dataalloc.destroy( std::addressof( tabledatastorage[ i ] ) );
				--count;
			}
		}

		void set_capacity( ulword targetcapacity ) {
			capacity = NextPow2( targetcapacity );
			if ( capacity > 128 )
				range = capacity >> 1;
			else
				range = capacity;
			bucketmask = capacity - 1;
		}

		TMeta& meta_of( const TKeyValuePair& pair ) {
			return *meta_of( std::addressof( pair ) );
		}

		TMeta* meta_of( const TKeyValuePair* pair ) {
			return std::addressof( tablemetastorage[ pair - tabledatastorage ] );
		}

		const TMeta& meta_of( const TKeyValuePair& pair ) const {
			return *meta_of( std::addressof( pair ) );
		}

		const TMeta* meta_of( const TKeyValuePair* pair ) const {
			return std::addressof( tablemetastorage[ pair - tabledatastorage ] );
		}

		TKeyValuePair& data_of( const TMeta& pair ) {
			return *data_of( std::addressof( pair ) );
		}

		TKeyValuePair* data_of( const TMeta* pair ) {
			return std::addressof( tabledatastorage[ pair - tablemetastorage ] );
		}

		const TKeyValuePair& data_of( const TMeta& pair ) const {
			return *data_of( std::addressof( pair ) );
		}

		const TKeyValuePair* data_of( const TMeta* pair ) const {
			return std::addressof( tabledatastorage[ pair - tablemetastorage ] );
		}

		void Expand( ulword requestedcapacity ) {
			ulword oldcapacity = capacity;
			ulword oldcount = count;
			set_capacity( NextPow2( requestedcapacity ) );
			TMeta* oldtablemetastorage = tablemetastorage;
			TKeyValuePair* oldtabledatastorage = tabledatastorage;
			auto exitor = make_destructor( [ & ]( ) { 
				dataalloc.deallocate( oldtabledatastorage, oldcapacity );
				metaalloc.deallocate( oldtablemetastorage, oldcapacity ); 
			} );
			make_storage( );
			if ( count < 1 ) {
				return;
			}
			
			count = 0;
			for ( ulword i = 0; i < oldcapacity; i++ ) {
				bool nodestruct = oldcount < 1 || oldtablemetastorage[ i ].first == 0;
				metaalloc.destroy( std::addressof( oldtablemetastorage[ i ] ) );
				if ( nodestruct )
					continue;
				dataalloc.destroy( std::addressof( oldtabledatastorage[ i ] ) );
				--oldcount;
			}
		}

		bool ScotchSearch( ulword address, const TKey& key, TMeta*& bucket ) {
			ulword scotch( bucket->first );
			while ( scotch != 0 ) {
				ulword jump = LeastSignificantSet( scotch );
				bucket = &tablemetastorage[ ( address + jump ) & bucketmask ];
				if ( bucket->first != 0 && keq( key, data_of( bucket )->first ) ) {
					// Failure - the Key already exists
					return true;
				}
				scotch &= ~( 1 << jump );
			}
			return false;
		}

		bool FullShiftAndSearch( TMeta* initialbucket, TMeta* bucket, ulword address, ulword freebucketsearch, TMeta*& targetbucket ) {
			TMeta* shiftingbucket = null;
			
			do {
				if ( freebucketsearch < neighborhood ) {
					// Success! We've done it.
					initialbucket->first |= ( 1ULL << freebucketsearch );
					targetbucket = bucket;
					return true;
				}
				// Use Hop Information to Find Closer Bucket
				ulword shiftingaddress = ( address - range - 1 ) % bucketmask;
				bool shiftfail = true;
				shiftingbucket = &tablemetastorage[ shiftingaddress & bucketmask ];
				for ( ulword freebucketcurrentrange = range; freebucketcurrentrange--; ) {
					ulword initialscotch = shiftingbucket->first;
					lword freebucketcurrentsearchmarker = -1;
					ulword freebucketmask = 1;
					for ( ulword i = 0; i < freebucketcurrentrange; ++i, freebucketmask <<= 1 ) {
						if ( ( freebucketmask & initialscotch ) == 1 ) {
							freebucketcurrentsearchmarker = i;
							break;
						}
					}
					if ( freebucketcurrentsearchmarker != -1 ) {
						if ( initialscotch == shiftingbucket->first ) {
							TMeta* newtargetbucket = shiftingbucket + freebucketcurrentsearchmarker;
							shiftingbucket->first |= static_cast<ulword>( 1 ) << freebucketcurrentrange;
							if ( shiftingbucket->first != 0 ) {
								dataalloc.destroy( data_of( bucket ) );
								dataalloc.construct( data_of( bucket ), data_of( *newtargetbucket ) );
								dataalloc.destroy( data_of( newtargetbucket ) );
								bucket->second = newtargetbucket->second;
							}
							shiftingbucket->first |= ~( 1 << freebucketcurrentrange );
							shiftingbucket->first &= ~( 1 << freebucketcurrentsearchmarker );
							bucket = newtargetbucket;
							freebucketsearch -= freebucketcurrentrange;
							shiftfail = false;
							break;
						}
					}
					shiftingbucket = &tablemetastorage[ ( ++shiftingaddress ) & bucketmask ];
				}
				if ( shiftfail )
					bucket = null;
			} while ( bucket != null );

			// Out of room or out of potential hop
			// spaces; full search has failed
			return false;
		}

		bool AddPrecomputed( ulword hashcode, const TKey& key, TValue && value ) {
			ulword address( hashcode & bucketmask );
			TMeta* bucket( std::addressof( tablemetastorage[ address ] ) );
			// If early search finds it, the key already exists
			if ( ScotchSearch( address, key, bucket ) )
				return false;

			TMeta* initialbucket( bucket );
			ulword freebucketsearch = 0;

			for ( ulword i = 0; i < range; ++i, ++freebucketsearch ) {
				if ( bucket->first == 0 )
					break;
				bucket = std::addressof( tablemetastorage[ ( ++address ) & bucketmask ] );
			}

			if ( freebucketsearch >= range ) {
				Expand( capacity * 2 );
				return AddPrecomputed( hashcode, key, std::move( value ) );
			}

			TMeta* targetbucket;
			if ( FullShiftAndSearch( initialbucket, bucket, address, freebucketsearch, targetbucket ) ) {
				targetbucket->first |= 1;
				targetbucket->second = hashcode;
				dataalloc.construct( data_of( targetbucket ), key, std::move( value ) );
				return true;
			}
			Expand( capacity * 2 );
			return AddPrecomputed( hashcode, key, value );
		}

		bool AddPrecomputed( ulword hashcode, const TKey& key, const TValue& value ) {
			ulword address( hashcode & bucketmask );
			TMeta* bucket( std::addressof( tablemetastorage[ address ] ) );
			// If early search finds it, the key already exists
			if ( ScotchSearch( address, key, bucket ) )
				return false;

			TMeta* initialbucket( bucket );
			ulword freebucketsearch = 0;

			for ( ulword i = 0; i < range; ++i, ++freebucketsearch ) {
				if ( bucket->first == 0 )
					break;
				bucket = std::addressof( tablemetastorage[ ( ++address ) & bucketmask ] );
			}

			if ( freebucketsearch >= range ) {
				Expand( capacity * 2 );
				return AddPrecomputed( hashcode, key, std::move( value ) );
			}

			TMeta* targetbucket;
			if ( FullShiftAndSearch( initialbucket, bucket, address, freebucketsearch, targetbucket ) ) {
				targetbucket->first |= 1;
				targetbucket->second = hashcode;
				dataalloc.construct( data_of( targetbucket ), key, value );
				return true;
			}

			Expand( capacity * 2 );
			return AddPrecomputed( hashcode, key, value );
		}

		template <typename... Tn>
		bool EmplacePrecomputed( ulword hashcode, const TKey& key, Tn&&... argn ) {
			ulword address( hashcode & bucketmask );
			TMeta* bucket( std::addressof( tablemetastorage[ address ] ) );
			// If early search finds it, the key already exists
			if ( ScotchSearch( address, bucket ) )
				return false;

			TMeta* initialbucket( bucket );
			ulword freebucketsearch = 0;

			for ( ulword i = 0; i < range; ++i, ++freebucketsearch ) {
				if ( bucket->first == 0 )
					break;
				bucket = std::addressof( tablemetastorage[ ( ++address ) & bucketmask ] );
			}

			if ( freebucketsearch >= range ) {
				Expand( capacity * 2 );
				return AddPrecomputed( hashcode, key, std::forward<Tn>( argn )... );
			}

			TMeta* targetbucket;
			if ( FullShiftAndSearch( initialbucket, bucket, address, freebucketsearch, targetbucket ) ) {
				targetbucket->first |= 1;
				targetbucket->second = hashcode;
				dataalloc.construct( data_of( targetbucket ), key, TValue( std::forward<Tn>( argn )... ) );
				return true;
			}

			Expand( capacity * 2 );
			return EmplacePrecomputed( hashcode, key, std::forward<Tn>( argn )... );
		}

		Dictionary( const noexceptor_constructor_t&, THash && hasher = THash( ), TKeyEquality && keyequals = TKeyEquality( ), TAllocator && dataallocator = TAllocator( ), TMetaAllocator && metaallocator = TMetaAllocator( ) )
		: count( 0 ), capacity( 0 ), hash( std::move( hasher ) ), keq( std::move( keyequals ) ), dataalloc( std::move( dataallocator ) ), metaalloc( std::move( metaallocator ) ), tabledatastorage( null ), tablemetastorage( null ) {

		}

	public:

		Dictionary ( THash&& hasher = THash(), TKeyEquality&& keyequals = TKeyEquality(), TAllocator&& dataallocator = TAllocator(), TMetaAllocator&& metaallocator = TMetaAllocator() ) 
		: Dictionary( noexcept_constructor, std::move( hasher ), std::move( keyequals ), std::move( dataallocator ), std::move( metaallocator ) ) {
			ressurect_unchecked( );
		}

		Dictionary( ulword initialcapacity, THash&& hasher = THash( ), TKeyEquality&& keyequals = TKeyEquality( ), TAllocator&& dataallocator = TAllocator( ), TMetaAllocator&& metaallocator = TMetaAllocator( ) )
		: Dictionary( noexcept_constructor, std::move( hasher ), std::move( keyequals ), std::move( dataallocator ), std::move( metaallocator ) ) {
			ressurect_unchecked( initialcapacity );
		}

		Dictionary( Dictionary&& mov ) 
		: Dictionary( std::move( mov.hash ), std::move( mov.keq ), std::move( mov.dataalloc ), std::move( mov.metaalloc ) ) {
			count = mov.count;
			capacity = mov.capacity;
			range = mov.range;
			bucketmask = mov.bucketmask;
			tabledatastorage = mov.tabledatastorage;
			tablemetastorage = mov.tablemetastorage;
			mov.tabledatastorage = null;
			mov.tablemetastorage = null;
			mov.count = 0;
			mov.capacity = 0;
			mov.bucketmask = 0;
			mov.range = 0;
		}

		Dictionary ( const Dictionary& copy ) : Dictionary( noexcept_constructor, THash( copy.hash ), TKeyEquality( copy.keq ), TAllocator( copy.dataalloc ), TMetaAllocator( copy.metaalloc ) ) {
			count = copy.count;
			capacity = copy.capacity;
			range = copy.range;
			bucketmask = copy.bucketmask;
			make_storage( );
			for ( ulword i = 0; i < capacity; i++ ) {
				if ( copy.tablemetastorage[i].first != 0 ) {
					AddPrecomputed( copy.tablemetastorage[i].second, copy.tabledatastorage[i].first, copy.tabledatastorage[i].second );
				}
			}
		}

		Dictionary& operator= ( const Dictionary& copy ) {
			if ( is_not_null() ) {
				clear_data( );
				delete_storage( );
			}
			hash = copy.hash;
			keq = copy.keq;
			dataalloc = copy.dataalloc;
			metaalloc = copy.metaalloc;
			count = copy.count;
			capacity = copy.capacity;
			range = copy.range;
			bucketmask = copy.bucketmask;
			make_storage( );
			for ( ulword i = 0; i < capacity; i++ ) {
				if ( copy.tablemetastorage[ i ].first != 0 ) {
					AddPrecomputed( copy.tablemetastorage[ i ].second, copy.tabledatastorage[ i ].first, copy.tabledatastorage[ i ].second );
				}
			}
			return *this;
		}

		Dictionary& operator= ( Dictionary&& mov ) {
			count = mov.count;
			capacity = mov.capacity;
			range = mov.range;
			bucketmask = mov.bucketmask;
			tabledatastorage = mov.tabledatastorage;
			tablemetastorage = mov.tablemetastorage;
			hash = std::move( mov.hash );
			keq = std::move( mov.keq );
			dataalloc = std::move( mov.dataalloc );
			metaalloc = std::move( mov.metaalloc );

			mov.tabledatastorage = null;
			mov.tablemetastorage = null;
			mov.count = 0;
			mov.capacity = 0;
			mov.bucketmask = 0;
			mov.range = 0;
			return *this;
		}

		~Dictionary( ) {
			if ( is_not_null( ) ) {
				clear_all( );
				delete_storage( );
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

		TKey const* TryGetCollisionKey( const TKey& Key ) const {
			const TKey* pcollisionkey = TryGetCollisionKey( Key );
			TryGetCollisionKey( Key, pcollisionkey );
			return pcolliionkey;
		}

		bool TryGetCollisionKey( const TKey& Key, TKey const* collisionkey ) const {
			ulword hashcode( hash( Key ) );
			ulword address( hashcode & bucketmask );
			const TMeta* bucket( std::addressof( tabledatastorage[ address ] ) );
			if ( bucket->first == 0 )
				return null;
			
			collisionkey = std::addressof( data_of( bucket )->first );
			return true;
		}

		bool TryGetCollisionKey( const TKey& Key, TKey& collisionkey ) const {
			const TKey const* pcollisionkey = TryGetCollisionKey( Key );
			collisionkey = *pcollisionkey;
			return collisionkey != null;
		}

		template <typename... Tn>
		bool Emplace( const TKey& key, Tn&& ... argn ) {
			ulword hashcode( hash( key ) );
			return EmplacePrecomputed( hashcode, key, std::forward<Tn>( argn )... );
		}

		bool Add ( const TKey& key, const TValue& value ) {
			ulword hashcode( hash( key ) );
			return AddPrecomputed( hashcode, key, value );
		}

		bool Remove ( const TKey& key ) {
			ulword hashcode( hash( key ) );
			ulword address( hashcode & bucketmask );
			TMeta* bucket = std::addressof( tablemetastorage[address] );
			TMeta* initialbucket = bucket;
			
			if ( bucket->first == 0 ) {
				return false;
			}
			else if ( bucket->first == 1 ) {
				if ( keq( key, data_of( *bucket ).first ) ) {
					bucket->first &= ~1;
					bucket->second = 0;
					count--;
					return true;
				}
				else {
					return false;
				}
			}

			ulword scotch( bucket->first );
			do {
				ulword jump = LeastSignificantSet( scotch );
				bucket = &tablemetastorage[(address + jump) & bucketmask];
				if ( bucket->second && keq(key, data_of( *bucket ).first ) ) {
					ulword mask( 1 );
					mask <<= jump;
					initialbucket->first &= ~(mask);
					bucket->second = 0;
					bucket->first = 0;
					count--;
					return true;
				}
				scotch &= ~(1 << jump);
			} while (scotch != 0);

			return false;
		}

		bool ContainsValue( const TValue& value ) const {
			return ContainsValue<>( value );
		}

		template <typename TValEq = std::equal_to<TV>>
		bool ContainsValue ( const TValue& value ) const {
			TValEq pred;
			return ContainsValue<TValEq>( value, pred );
		}

		template <typename TValEq = std::equal_to<TV>>
		bool ContainsValue ( const TValue& value, TValEq pred ) const {
			for ( ulword i = 0; i < capacity; ++i ) {
				if ( tablemetastorage[i].first == 0 )
					continue;
				if ( pred( value, tabledatastorage[i].second ) )
					return true;
			}
			return false;
		}

		bool ContainsKey ( const TKey& key ) const {
			ulword hashcode( hash( key ) );
			ulword address( hashcode & bucketmask );
			TMeta* bucket( std::addressof( tablemetastorage[address] ) );
			TMeta* startbucket( null );
			TMeta* endbucket = &tablemetastorage[capacity - 1];
			if ( bucket->first == 1 ) {
				return keq( key, data_of( *bucket ).first ); 
			}

			ulword scotch( bucket->first );
			while ( scotch != 0 ) {
				lword jump = Bits::LeastSignificantSet( (lword)scotch );
				bucket = &tablemetastorage[(address + jump) & bucketmask];
				if ( bucket->first != 0 && keq( key, data_of( *bucket ).first ) )
					return true;
				scotch &= ~(1 << jump);
			}

			startbucket = bucket = &tablemetastorage[address];
			if ( bucket->first != 0 && keq( key, data_of( *bucket ).first ) )
				return true;
			
			++bucket;

			for ( lword i = 0; i < neighborhood && bucket != startbucket; ++i, ++bucket ) {
				if ( bucket == endbucket )
					bucket = &tablemetastorage[ 0 ];
				if ( bucket->first != 0 && keq( key, data_of( *bucket ).first ) )
					return true;
			}

			return false;
		}

		const TValue& At ( const TKey& key ) const {
			ulword hashcode( hash( key ) );
			ulword address( hashcode & bucketmask );
			TMeta* bucket( std::addressof( tablemetastorage[ address ] ) );
			ulword scotch( bucket->first );

			while (scotch != 0) {
				ulword jump = LeastSignificantSet( scotch );
				bucket = &tablemetastorage[(address + jump) & bucketmask];
				if ( bucket->first != 0 && keq( key, data_of( *bucket ).first ) ) {
					return data_of( *bucket ).second;
				}
				scotch &= ~(1 << jump);
			}

			bucket = std::addressof( tablemetastorage[address] );
			if (address > capacity - neighborhood) {
				ulword i = 0;
				ulword cap = capacity - address;
				for ( ulword i = 0; i < cap; ++i, ++bucket ) {
					if ( bucket->first != 0 && keq( key, data_of( *bucket ).first ) ) {
						return data_of( *bucket ).second;
					}
				}
				bucket = tablemetastorage;
				for ( i = cap; i < neighborhood; ++i, ++bucket ) {
					if ( bucket->first != 0 && keq( key, data_of( *bucket ).first ) ) {
						return data_of( *bucket ).second;
					}
				}
			}
			else {
				for ( ulword i = 0; i < neighborhood; ++i, ++bucket) {
					if ( bucket->first != 0 && keq( key, data_of( *bucket ).first ) ) {
						return data_of( *bucket ).second;
					}
				}
			}

			throw std::runtime_error( "Key does not exist" );
		}

		bool TryGetValue ( const TKey& key, TValue& value ) const {
			ulword neighbors = Mathema<ulword>::Min( neighborhood, capacity );
			ulword hashcode( hash( key ) );
			ulword address( hashcode & bucketmask );
			TMeta* bucket( std::addressof( tablemetastorage[ address ] ) );
			TMeta* endbucket( tablemetastorage + capacity );
			if ( bucket->first == 1 && keq( key, data_of( *bucket ).first ) ) {
				value = data_of( *bucket ).second;
				return true;
			}
			++bucket;

			ulword scotch( bucket->first );

			while (scotch != 0) {
				ulword jump = LeastSignificantSet( scotch );
				bucket = std::addressof( tablemetastorage[(address + jump) & bucketmask] );
				if ( bucket->first != 0 && keq( key, data_of( *bucket ).first ) ) {
					value = data_of( *bucket ).second;
					return true;
				}
				scotch &= ~(1 << jump);
			}

			bucket = &tablemetastorage[address];
			for ( ulword i = 0; i < neighbors; ++i, ++bucket ) {
				if ( bucket == endbucket )
					bucket = tablemetastorage;
				if ( bucket->first != 0 && keq( key, data_of( *bucket ).first ) ) {
					value = data_of( *bucket ).second;
					return true;
				}
			}

			return false;
		}

		void Reserve ( ulword requestedsize ) {
			if ( requestedsize < capacity )
				return;
			ulword oldcap = capacity;
			capacity = Bits::NextPow2(requestedsize);
			bucketmask = capacity - 1;
			if (capacity > 128)
				range = capacity >> 1;
			else
				range = capacity;
			Bucket* old = tablemetastorage;
			tablemetastorage = new Bucket[capacity];
			if ( count > 0 ) {
				count = 0;
				for ( ulword i( 0 ); i < oldcap; i++ )
					if ( tablemetastorage[i].Hop != 0 )
						Add( old[i].Data.first, old[i].Data.second );
			}
			delete[] old;
			old = null;
		}

		void Clear () {
			clear_data( );
		}
		
		const TValue& operator[] ( const TKey& Key ) const {
			return At( Key );
		}

		TValue& operator[] ( const TKey& key ) {
			ulword hashcode( hash( key ) );
			ulword address( hashcode & bucketmask );
			TMeta* bucket( std::addressof( tablemetastorage[address] ) );
			TMeta* initialbucket = bucket;
			ulword scotch(bucket->first);
			ulword freebucketsearch;

			while (scotch != 0) {
				lword jump = Bits::LeastSignificantSet( (lword)scotch );
				bucket = &tablemetastorage[(address + jump) & bucketmask];
				if ( bucket->first != 0 && keq( key, data_of( *bucket ).first ) ) {
					return data_of( *bucket ).second;
				}
				scotch &= ~(1 << jump);
			}

			bucket = std::addressof( tablemetastorage[address] );
			if (address > capacity - neighborhood) {
				lword i;
				lword cap( capacity - address );
				for ( i = 0; i < cap; ++i, ++bucket ) {
					if ( bucket->first != 0 && keq( key, data_of( *bucket ).first ) ) {
						return data_of( *bucket ).second;
					}
				}
				bucket = tablemetastorage;
				for (i = cap; i < neighborhood; ++i, ++bucket) {
					if ( bucket->first != 0 && keq( key, data_of( *bucket ).first ) ) {
						return data_of( *bucket ).second;
					}
				}
			}
			else {
				for (lword i = 0; i < neighborhood; ++i, ++bucket) {
					if ( bucket->first != 0 && keq( key, data_of( *bucket ).first ) ) {
						return data_of( *bucket ).second;
					}
				}
			}

			bucket = std::addressof( tablemetastorage[address] );
			for ( ulword i = 0; i < range; ++i, freebucketsearch++ ) {
				if (bucket->first == 0)
					break;
				bucket = &tablemetastorage[(address++) & bucketmask];
			}

			TMeta* targetbucket;
			if ( FullShiftAndSearch( initialbucket, bucket, address, freebucketsearch, targetbucket ) ) {
				targetbucket->first |= 1;
				targetbucket->second = hashcode;
				dataalloc.construct( data_of( targetbucket ), key, TValue() );
				return data_of( *targetbucket ).second;
			}

			Expand( capacity * 2 );
			return operator[]( key );
		}

		std::pair<TKey, TValue>& operator() (lword index) {
			return tablemetastorage[ index ].Data;
		}

	};

}}
