#pragma once

#include <Furrovine++/std_defines.h>
#include <functional>
#include <type_traits>
#include <future>
#include <memory>
#include <Furrovine++/Threading/Thread.h>
#include <Furrovine++/Collections/Concurrent/BlockingQueue.h>

namespace Furrovine { namespace Threading {

	class WorkerThread {
	public:
		typedef std::function<void()> TWork;

	private:
		Collections::Concurrent::BlockingQueue<TWork> threadwork;
		Thread thread;

		furrovineapi WorkerThread ( const WorkerThread& nocopy );

		furrovineapi WorkerThread& operator= ( const WorkerThread& nocopy );

		furrovineapi void RunThread ( );

	public:

		furrovineapi WorkerThread ();

		template <typename TFx, typename... Tn> 
		std::future< typename std::result_of<TFx( Tn... )>::type > Queue ( TFx&& fx, Tn&&... argn );

		furrovineapi void QueueWork ( TWork item );

		furrovineapi ~WorkerThread ( );

	private:

		template <typename TResult, typename T>
		TWork MakeWork ( std::shared_ptr<std::promise<TResult>> promise, T&& binding );

		template <typename TResult, typename T>
		TWork MakeWork ( std::false_type f, std::shared_ptr<std::promise<TResult>> promise, T&& binding );

		template <typename TResult, typename T>
		TWork MakeWork ( std::true_type t, std::shared_ptr<std::promise<TResult>> promise, T&& binding );
	};

}}
