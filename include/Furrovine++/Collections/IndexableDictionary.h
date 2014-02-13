#pragma once

#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/optional.h>
#include <vector>
#include <unordered_map>

namespace Furrovine { namespace Collections {
	
	template <typename TK, typename TV, typename TH = std::hash<TK>, typename TKEq = std::equal_to<TK>> 
	class IndexableDictionary {
	public:
		typedef TK TKey;
		typedef TV TValue;
		typedef TH THash;
		typedef TKEq TKeyEquality;

	protected:
		std::unordered_map<TKey, ulword, THash, TKeyEquality> indices;
		std::vector<TValue> items;
		optional<TKey> defaultkey;

	public:

		IndexableDictionary ( ) : defaultkey( nullopt ) {

		}

		IndexableDictionary( const IndexableDictionary& copy ) : items( copy.items ), indices( copy.indices ), defaultkey( copy.defaultkey ) {

		}

		IndexableDictionary( IndexableDictionary&& mov ) : items( std::move( mov.items ) ), indices( std::move( mov.indices ) ), defaultkey( std::move( mov.defaultkey ) ) {
			mov.items.clear();
			mov.indices.clear();
			mov.defaultkey = nullopt;
		}

		typename std::vector<TValue>::iterator begin () {
			return items.begin();
		}

		typename std::vector<TValue>::iterator end () {
			return items.end();
		}

		ulword size ( ) const {
			return items.size();
		}

		bool set_default ( const TKey& key ) {
			ulword index;
			if ( try_get_index( key, index ) ) {
				defaultkey = key;
				return true;
			}
			defaultkey = nullopt;
			return false;
		}

		TValue& get_default () {
			return items[indices[defaultkey.value()]];
		}

		const TValue& get_default () const {
			return items[indices[defaultkey.value()]];
		}

		void insert ( const TKey& key, const TValue& value ) {
			indices.emplace( key, items.size() );
			items.push_back( value );
		}

		void insert ( const TKey& key, TValue&& value ) {
			indices.emplace( key, items.size() );
			items.push_back( std::move( value ) );
		}

		template <typename ...Tn>
		void emplace ( const TKey& key, Tn&&... argn ) {
			indices.Add( key, items.size() );
			items.emplace_back( std::forward<Tn>( argn )... );
		}

		bool replace ( const TKey& key, const TValue& value ) {
			bool replaced = remove( key );
			insert( key, value );
			return replaced;
		}

		bool replace ( const TKey& key, TValue&& value ) {
			optional<ulword> indexof = index_of( key );
			if ( indexof ) {
				bool replaced = remove( key );
				items[ indexof.value() ] = std::move( value );
			}
			else {
				insert( key, value );
			}
			return replaced;
		}

		bool remove ( const TKey& key ) {
			ulword index;
			if ( try_get_index( key, index ) ) {
				items.erase( items.begin() + index );
				indices.Remove( key );
				TKeq keq;
				if ( keq( key, *defaultkey ) ) {
					defaultkey = null;
				}
				return true;
			}
			return false;
		}

		bool contains ( const TKey& key ) const {
			return indices.find( key ) != indices.end();
		}

		optional<ulword> index_of ( const TKey& key ) const {
			auto idx = indices.find( key );
			if ( idx == indices.end( ) )
				return nullopt;
			return idx->second;
		}

		bool try_get_index ( const TKey& key, ulword& index ) {
			auto idx = indices.find( key );
			if ( idx == indices.end( ) )
				return false;
			index = idx->second;
			return true;
		}

		optional<TValue&> try_get_value ( const TKey& key ) {
			ulword index;
			if ( try_get_index( key, index ) ) {
				return items[ index ];
			}
			if ( indices.try_get_index( *defaultkey, index ) ) {
				return items[ index ];
			}
			return nullopt;
		}

		TValue& at_index ( ulword index ) {
			return items[ index ];
		}

		const TValue& at_index ( ulword index ) const {
			return items[ index ];
		}

		TValue& at ( const TKey& key ) {
			return items[ indices.at( key ) ];
		}

		const TValue& at ( const TKey& key ) const {
			return items[ indices.at( key ) ];
		}

		void clear ( ) {
			items.clear();
			indices.clear();
		}

		void reserve ( ulword requestedcapacity ) {
			items.reserve( requestedcapacity );
			indices.reserve( requestedcapacity );
		}

		TValue& operator [ ] ( const TKey& key ) {
			return items[ indices[ key ] ];
		}

		const TValue& operator [ ] ( const TKey& key ) const {
			ulword index;
			try_get_index( key, index );
			return items[ index ];
		}

		TValue& operator [ ] ( ulword index ) {
			return at_index( index );
		}

		const TValue& operator [ ] ( ulword index ) const {
			return at_index( index );
		}

		IndexableDictionary& operator= ( IndexableDictionary&& mov ) {
			items = std::move( mov.items );
			indices = std::move( mov.indices );
			defaultkey = std::move( mov.defaultkey );
			mov.items.clear();
			mov.indices.clear();
			mov.defaultkey = nullopt;
			return *this;
		}

		IndexableDictionary& operator = ( const IndexableDictionary& copy ) {
			items = copy.items;
			indices = copy.indices;
			defaultkey = copy.defaultkey;
			return *this;
		}
	};
	
}}
