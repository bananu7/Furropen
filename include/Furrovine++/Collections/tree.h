#ifndef FURROVINETREE_H
#define FURROVINETREE_H

#include <Furrovine++/Collections/naive_tree.h>

namespace Furrovine { namespace Collections {

	template <typename T, typename TEq = std::equal_to<T>>
	class tree : public naive_tree<T, TEq> {
	private:
		typedef naive_tree<T, TEq> parent_type;

	public:
	
		template <typename ...Tn>
		explicit tree ( Tn&&... argn ) : parent_type( std::forward<Tn>( argn )... ) {

		}


	};

}}

#endif // FURROVINETREE_H 