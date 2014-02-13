#pragma once

#include <Furrovine++/Threading/Thread.h>

namespace Furrovine { namespace Threading {

	template <typename TFx, typename ...Tn>
	Thread::Thread( TFx&& fx, Tn&&... argn ) 
	: info( std::make_shared<ThreadInfo>( ) ), detached(false) {
		info->threadjump = std::bind( std::forward<TFx>( fx ), std::forward<Tn>( argn )... );
		Start();
	}

	template <typename TFx, typename ...Tn>
	Thread::Thread( bool start, TFx&& fx, Tn&&... argn ) 
	: info( std::make_shared<ThreadInfo>( ) ), detached( false ) {
		
		info->threadjump = std::bind( std::forward<TFx>( fx ), std::forward<Tn>( argn )... );
		if ( start )
			Start();
	}

	template <typename TFx, typename ...Tn>
	void Thread::Reset ( TFx&& fx, Tn&&... argn ) {
		Reset( true, std::forward<TFx>( fx ), std::forward<Tn>( argn )... );
	}
	
	template <typename TFx, typename ...Tn>
	void Thread::Reset ( bool start, TFx&& fx, Tn&&... argn ) {
		Join();
		
		if ( info == null )
			info = std::move( std::make_shared<ThreadInfo>( ) );
		
		info->threadjump = std::bind( std::forward<TFx>( fx ), std::forward<Tn>( argn )... );
		
		if ( start )
			Start();
	}

}}
