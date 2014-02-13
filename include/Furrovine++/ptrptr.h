#pragma once

#include <Furrovine++/ptrptr_type.h>

namespace Furrovine {

	template <typename TPtr>
	ptrptr_type<TPtr> ptrptr( TPtr& p ) { return ptrptr_type<TPtr>( p ); }

	template <typename TInternalPtr, typename TPtr>
	ptrptr_type<TPtr, TInternalPtr> ptrptr( TPtr& p ) { return ptrptr_type<TPtr, TInternalPtr>( p ); }

	template <typename TInternalPtr, typename TCast, typename TPtr>
	ptrptr_type<TPtr, TInternalPtr, TCast> ptrptr( TPtr& p ) { return ptrptr_type<TPtr, TInternalPtr, TCast>( p ); }

}