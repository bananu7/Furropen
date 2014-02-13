#ifndef FURROVINENAIVE_TREE_H
#define FURROVINENAIVE_TREE_H

#include <algorithm>
#include <set>
#include <Furrovine++/is_integer_equal.h>

namespace Furrovine { namespace Collections {

	template <typename T, typename TEq = std::equal_to<T>>
	class naive_unordered_tree {
	private:
		struct node {
			T value;
			std::unordered_map<std::unique_ptr<node>> children;

			template <typename ...Tn>
			explicit node ( Tn&&... argn ) : value( std::forward<Tn>( argn )... ) {

			}

			node ( const node& copy ) : value( copy.value ), children( copy.children ) {

			}

			node ( node&& mov ) : value( std::move( mov.value ) ), children( std::move( mov.children ) ) {

			}

			template <typename TIterator>
			bool ContainsPath ( const TEq& eq, TIterator begin, TIterator end ) const {
				if ( begin == end )
					return true;
				if ( !eq( value, arg ) )
					return false;
				for ( const auto& n : children ) {
					if ( n.ContainsPath( eq, ++begin, end ) )
						return true;
				}
				return false;
			}

			template <typename T, typename ...Tn>
			bool ContainsPathN ( const TEq& eq, T&& arg, Tn&&... argn ) const {
				if ( !eq( value, arg ) )
					return false;
				return ContainsPathN0( is_integer_equal<sizeof...( Tn ), 0>(), eq, std::forward<Tn>( argn )... );
			}

			template <typename ...Tn>
			bool ContainsPathN0 ( std::true_type is0, const TEq& eq, Tn&&... argn ) const { 
				return true;
			}

			template <typename ...Tn>
			bool ContainsPathN0 ( std::false_type is0, const TEq& eq, Tn&&... argn ) const {
				for (const auto& n : children ) {
					if ( n.ContainsPathN( eq, std::forward<Tn>( argn )... ) )
						return true;
				}
				return false;
			}

		};

		TEq eq;
		node root;

	public:

		template <typename ...Tn>
		explicit naive_tree ( Tn&&... argn ) : root( std::forward<Tn>( argn )... ) {

		}

		template <typename ...Tn>
		bool ContainsPathN ( Tn&&... argn ) const {
			return root.ContainsPathN( eq, std::forward<Tn>( argn )... );
		}

		template <typename TContainer>
		bool ContainsPath ( TContainer&& cont ) const {
			return root.ContainsPath( eq, std::begin( cont ), std::end( cont ) );
		}

		template <typename TIterator>
		bool ContainsPath ( TIterator begin, TIterator end  ) const {
			return root.ContainsPath( eq, begin, end );
		}

	};

}}

#endif // FURROVINENAIVE_TREE_H 