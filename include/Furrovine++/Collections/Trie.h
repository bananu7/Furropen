#ifndef FURROVINETRIE_H
#define FURROVINETRIE_H

#include <unordered_map>
#include <set>
#include <vector>
#include <array>
#include <bitset>
#include <utility>
#include <iostream>

namespace Furrovine { namespace Collections {

	template <typename TKey, typename TValue, typename THash = std::hash<TKey>, typename TKEq = std::equal_to<TKey>>
	class Trie {
	private:
		typedef std::pair<std::set<TKey>, TValue> TNode;
		typedef std::unordered_map<std::size_t, TNode> TDepthNode;
		std::unordered_map<TKey, TDepthNode, THash, TKEq> tree;

	public:

		Trie () {

		}

		template <typename TContainer>
		void Remove ( TContainer& container ) {
			return Insert( std::begin( container ), std::end( container ) );
		}

		template <typename TIterator>
		void Remove ( TIterator seqbegin, TIterator seqend ) {
			throw std::logic_error( "Wut" );
		}

		template <typename TContainer>
		void Insert ( TContainer& container, const TValue& value ) {
			return Insert( std::begin( container ), std::end( container ), value );
		}

		template <typename TIterator>
		void Insert ( TIterator seqbegin, TIterator seqend, const TValue& value ) {
			std::size_t depth = 0;
			if ( seqbegin == seqend )
				return;
			TIterator current = seqbegin;
			TNode* node = nullptr;
			TKey* k = nullptr;
			while ( current != seqend ) {
				k = std::addressof( *current );

				TDepthNode& depthnode = tree[ *k ];
				node = std::addressof( depthnode[ depth ] );

				++depth;
				++current;
			}
			if ( node != nullptr ) {
				node->first.insert( *k );
				node->second = value;
			}
		}

		template <typename TIterator>
		void Insert ( TIterator seqbegin, TIterator seqend, TValue&& value ) {
			std::size_t depth = 0;
			if ( seqbegin == seqend )
				return;
			TIterator current = seqbegin;
			TNode* node = nullptr;
			TKey* k = nullptr;
			while ( current != seqend ) {
				k = std::addressof( *current );

				TDepthNode& depthnode = tree[ *k ];
				node = std::addressof( depthnode[ depth ] );

				++depth;
				++current;
			}
			if ( node != nullptr ) {
				node->first.insert( *k );
				node->second = std::move( value );
			}
		}

		template <typename TContainer>
		bool Exists ( TContainer& container ) const {
			return Exists( std::begin( container ), std::end( container ) );
		}

		template <typename TIterator>
		bool Exists ( TIterator seqbegin, TIterator seqend ) const {
			std::size_t depth = 0;
			if ( seqbegin == seqend )
				return false;
			TIterator current = seqbegin;
			TNode* node = nullptr;
			TKey* k = nullptr;
			while ( current != seqend ) {
				k = std::addressof( *current );

				auto existingk = tree.find( *k );
				if ( existingk == tree.end() )
					return false;

				TDepthNode& depthnode = existingk->second;
				auto hasdepth = depthnode.find( depth );
				if ( hasdepth == depthnode.end() )
					return false;

				node = std::addressof( hasdepth->second );

				++current;
				++depth;
			}
			if ( node == nullptr || 
				node->first.find( *k ) == node->first.end() )
				return false;

			return true;
		}

		template <typename TContainer>
		bool TryGetValue ( TContainer& container, TValue& value ) {
			return TryGetValue( std::begin( container ), std::end( container ), value );
		}

		template <typename TIterator>
		bool TryGetValue ( TIterator seqbegin, TIterator seqend, TValue& value ) {
			std::size_t depth = 0;
			if ( seqbegin == seqend )
				return false;
			TIterator current = seqbegin;
			TNode* node = nullptr;
			TKey* k = nullptr;
			while ( current != seqend ) {
				k = std::addressof( *current );

				auto existingk = tree.find( *k );
				if ( existingk == tree.end() )
					return false;

				TDepthNode& depthnode = existingk->second;
				auto hasdepth = depthnode.find( depth );
				if ( hasdepth == depthnode.end() )
					return false;

				node = std::addressof( hasdepth->second );

				++current;
				++depth;
			}
			if ( node == nullptr || 
				node->first.find( *k ) == node->first.end() )
				return false;

			value = node->second;

			return true;
		}

	};

}}

#endif // FURROVINETRIE_H 