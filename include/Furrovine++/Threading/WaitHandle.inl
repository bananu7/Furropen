#pragma once

#include <Furrovine++/Threading/WaitHandle.h>

namespace Furrovine { namespace Threading {

	template <typename THandleIterator>
	static int32 WaitHandle::WaitMultiple ( THandleIterator begin, THandleIterator end, bool waitall /*= false*/, Timeout timeout /*= Timeout::Infinite*/ ) {
		ulword count = std::distance( begin, end );
		std::vector<HANDLE> handles( count );
		THandleIterator current = begin;
		for ( ulword i = 0; i < count && current != end; ++i, ++current ) {
			handles[i] = current->Handle();
		}
		return WaitMultiple( handles.data(), count, waitall, timeout );
	}

	template <typename ...Tn>
	static int32 WaitHandle::WaitMultiple ( Tn&&... handles ) {
		return WaitMultiple( false, Timeout::Infinite, std::forward<Tn>( handles )... );
	}

	template <typename ...Tn>
	static int32 WaitHandle::WaitMultiple ( bool waitall, Tn&&... handles ) {
		return WaitMultiple( waitall, Timeout::Infinite, std::forward<Tn>( handles )... );
	}

	template <typename ...Tn>
	static int32 WaitHandle::WaitMultiple ( bool waitall, Timeout timeout, Tn&&... handles ) {
		std::array<HANDLE, sizeof...( Tn )> handles = {
			( handles.Handle() )...
		};

		return WaitMultiple( handles.data(), sizeof...( Tn ), waitall, timeout );
	}

}}
