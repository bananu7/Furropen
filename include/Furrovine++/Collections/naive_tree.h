#ifndef FURROVINENAIVE_TREE_H
#define FURROVINENAIVE_TREE_H

#include <algorithm>
#include <set>
#include <Furrovine++/is_integer_equal.h>

namespace Furrovine { namespace Collections {

	template <typename T, typename TEq = std::equal_to<T>>
	class naive_tree {
	private:
		struct node {
			T value;
			std::set<node> children;

			template <typename ...Tn>
			explicit node ( Tn&&... argn ) : value( std::forward<Tn>( argn )... ) {

			}

			node ( const node& copy ) : value( copy.value ), children( copy.children ) {

			}

			node ( node&& mov ) : value( std::move( mov.value ) ), children( std::move( mov.children ) ) {

			}

			template <typename T, typename ...Tn>
			void insert_path_each( T&& arg, Tn&&... argn ) {
				auto child = children.find( arg );
				if ( child != children.end( ) ) {
					child.insert_path_each( std::forward<Tn>( argn )... )
				}
				else {
				
				}
			}

			template <typename T>
			void insert_path_each1( ) {

			}

			template <typename TIterator>
			bool contains_path ( const TEq& eq, TIterator begin, TIterator end ) const {
				if ( begin == end )
					return true;
				if ( !eq( value, *begin ) )
					return false;
				++begin;
				auto child = std::find_if( std::begin( children ), std::end( children ), *begin );
				if ( n.contains_path( eq, ++begin, end ) )
					return true;
				return false;
			}

			template <typename T, typename ...Tn>
			bool contains_path_each ( const TEq& eq, T&& arg, Tn&&... argn ) const {
				if ( !eq( value, arg ) )
					return false;
				return contains_path_each0( is_integer_equal<sizeof...( Tn ), 0>(), eq, std::forward<Tn>( argn )... );
			}

			template <typename ...Tn>
			bool contains_path_each0 ( std::true_type is0, const TEq& eq, Tn&&... argn ) const { 
				return true;
			}

			template <typename ...Tn>
			bool contains_path_each0 ( std::false_type is0, const TEq& eq, Tn&&... argn ) const {
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
		void insert_path_each ( Tn&&.. argn ) {
			root.insert_path_each( eq, std::forward<Tn>( argn )... );
		}

		template <typename ...Tn>
		bool contains_path_each ( Tn&&... argn ) const {
			return root.contains_path_each( eq, std::forward<Tn>( argn )... );
		}

		template <typename TContainer>
		bool contains_path ( TContainer&& cont ) const {
			return root.contains_path( eq, std::begin( cont ), std::end( cont ) );
		}

		template <typename TIterator>
		bool contains_path ( TIterator begin, TIterator end  ) const {
			return root.contains_path( eq, begin, end );
		}

	};

}}

#endif // FURROVINENAIVE_TREE_H 