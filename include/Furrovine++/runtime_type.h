#pragma once

#include <typeindex>
#include <Furrovine++/in_place.h>
#include <Furrovine++/Export.h>
#include <Furrovine++/typed_catch_throw.h>

namespace Furrovine {

	class runtime_type {
	private:
		friend inline furrovineapi bool operator== ( const std::type_info& info, const runtime_type& rtt );
		friend inline furrovineapi bool operator== ( const std::type_index& index, const runtime_type& rtt );
		friend inline furrovineapi bool operator== ( const runtime_type& rtt, const std::type_info& info );
		friend inline furrovineapi bool operator== ( const runtime_type& rtt, const std::type_index& index );
		friend inline furrovineapi bool operator!= ( const std::type_info& info, const runtime_type& rtt );
		friend inline furrovineapi bool operator!= ( const std::type_index& index, const runtime_type& rtt );
		friend inline furrovineapi bool operator!= ( const runtime_type& rtt, const std::type_info& info );
		friend inline furrovineapi bool operator!= ( const runtime_type& rtt, const std::type_index& index );

		std::type_index index;
		typed_throw<void>::throw_t check;
		typed_catch<void>::catch_t accept;

	public:
		template <typename T>
		runtime_type( in_place_of<T> ) : index( typeid( T ) ), check( typed_throw<T>::check ), accept( typed_catch<T>::accept ) {
			
		}

		furrovineapi std::size_t hash_code( ) const;

		template <typename T>
		bool search( ) const {
			try {
				check( );
			}
			catch ( T* e ) {
				return true;
			}
			catch ( ... ) {
			}
			return false;
		}

		furrovineapi bool search( const runtime_type& rtt ) const;

		furrovineapi const char* name( ) const;

		furrovineapi bool operator== ( const runtime_type& other ) const;

		furrovineapi bool operator!= ( const runtime_type& other ) const;

		furrovineapi bool operator>= ( const runtime_type& other ) const;

		furrovineapi bool operator> ( const runtime_type& other ) const;

		furrovineapi bool operator<= ( const runtime_type& other ) const;

		furrovineapi bool operator< ( const runtime_type& other ) const;

	};

	furrovineapi bool operator== ( const std::type_info& info, const runtime_type& rtt );
	furrovineapi bool operator== ( const std::type_index& index, const runtime_type& rtt );
	furrovineapi bool operator== ( const runtime_type& rtt, const std::type_info& info );
	furrovineapi bool operator== ( const runtime_type& rtt, const std::type_index& index );

	furrovineapi bool operator!= ( const std::type_info& info, const runtime_type& rtt );
	furrovineapi bool operator!= ( const std::type_index& index, const runtime_type& rtt );
	furrovineapi bool operator!= ( const runtime_type& rtt, const std::type_info& info );
	furrovineapi bool operator!= ( const runtime_type& rtt, const std::type_index& index );

	template <typename T>
	runtime_type typeof( ) {
		typedef in_place_of<T> identity;
		return runtime_type( identity() );
	}

	struct inherited_from {
		bool operator() ( const runtime_type& left, const runtime_type& right ) const {
			return left.search( right );
		}
	};

}

namespace std {

	template <>
	struct hash<Furrovine::runtime_type> {
		size_t operator() ( const Furrovine::runtime_type& hashee ) const {
			return hashee.hash_code( );
		}
	};

}