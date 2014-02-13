#pragma once

#include <Furrovine++/Threading/WorkerThread.h>

namespace Furrovine { namespace Threading {

	template <typename TResult, typename T>
	typename WorkerThread::TWork WorkerThread::MakeWork( std::true_type t, std::shared_ptr<std::promise<TResult>> promise, T&& binding ) {
		return TWork( 
			[=]( ){ 
				std::function<TResult()> f = binding;
				try {
					f();
				}
				catch ( ... ) {
					promise->set_exception( std::current_exception() );
				}
		} );
	}

	template <typename TResult, typename T>
	typename WorkerThread::TWork WorkerThread::MakeWork( std::false_type f, std::shared_ptr<std::promise<TResult>> promise, T&& binding ) {
		return TWork(
			[=]( ){ 
				std::function<TResult()> f = binding;
				try {
					// Force any result from f to be moved ( if possible )
					// ( Will the compiler do this automatically? )
					promise->set_value( std::move( f() ) );
				}
				catch ( ... ) {
					promise->set_exception( std::current_exception() );
				}
		} );
	}

	template <typename TResult, typename T>
	typename WorkerThread::TWork WorkerThread::MakeWork( std::shared_ptr<std::promise<TResult>> promise, T&& binding ) {
		return MakeWork<TResult, T>( std::is_void<TResult>(), promise, std::forward<T>( binding ) );
	}

	template <typename TFx, typename... Tn> 
	std::future< typename std::result_of<TFx( Tn... )>::type > WorkerThread::Queue ( TFx&& fx, Tn&&... argn ) {
		typedef std::result_of<TFx( Tn... )>::type TResult;
		typedef std::future<TResult> TFuture;
		typedef std::promise<TResult> TPromise;
		std::shared_ptr<TPromise> promise = std::make_shared<TPromise>( );

		QueueWork( MakeWork<TResult>( promise, std::bind( std::forward<TFx>( fx ), std::forward<Tn>( argn )... ) ) );

		return promise->get_future();
	}

}}
