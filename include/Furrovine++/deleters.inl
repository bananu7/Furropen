#pragma once

#include <Furrovine++/deleters.h>

namespace Furrovine {

	template<typename T>
	void release_deleter::operator()( T* ptr ) const {
		ptr->Release();
	}

	template< typename T >
	void destroy_deleter::operator()( T* ptr ) const {
		ptr->Destroy();
	}

	template <typename T>
	void destroyvoice_deleter::operator()( T* ptr ) const {
		ptr->DestroyVoice();
	}

	template <typename T>
	void no_delete::operator()( T&& ptr ) const {

	}

	template <typename T, typename TDx>
	optional_delete<T, TDx>::optional_delete( bool calldelete /*= true */, TDx&& deleter/* = TDx()*/ ) 
	: usedeleter( calldelete ), deleter(std::move(deleter)) {

	}

	template <typename T, typename TDx>
	void optional_delete<T, TDx>::operator()( pointer ptr ) const {
		if ( usedeleter )
			deleter( ptr );
	}

	template <typename T>
	void array_delete<T>::operator()( pointer ptr ) const {
		delete[] ptr;
	}

	template <typename TDx>
	optional_deleter<TDx>::optional_deleter( bool calldelete /*= true */, TDx&& deleter /*= TDx()*/ ) 
	: usedeleter( calldelete ), deleter(std::move(deleter)) {

	}

	template <typename TDx>
	template <typename T>
	void optional_deleter<TDx>::operator()( T&& ptr ) const {
		if ( usedeleter )
			deleter( std::forward<T>( ptr ) );
	}

}
