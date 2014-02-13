#pragma once

#include <Furrovine++/std_defines.h>
#include <future>
#include <Furrovine++/Threading/Thread.h>
#include <Furrovine++/Collections/Concurrent/BlockingQueue.h>
#include <Furrovine++/Threading/ThreadStopException.h>

namespace Furrovine { namespace Threading {

	class ThreadPool {
	private:
		typedef int TCost;
		typedef ulword TIndex;
		typedef std::pair<TIndex, TCost> TThreadCost;
		typedef std::function<void()> TWork;
		typedef Collections::Concurrent::BlockingQueue<TWork> TQueue;

		struct compare_cost {
			furrovineapi bool operator () ( const TThreadCost& left, const TThreadCost& right );
		};

		std::vector<TWork> work;
		std::vector<Thread> threads;
		std::vector<ptr<TQueue>> threadwork;
		std::priority_queue<TThreadCost, std::vector<TThreadCost>, compare_cost> threadpriorities;

		furrovineapi void RunThread ( ulword threadid );

	public:
		
		furrovineapi ThreadPool( );

		furrovineapi ThreadPool( const ThreadPool& nocopy ) = delete;
		furrovineapi ThreadPool& operator= ( const ThreadPool& nocopy ) = delete;

		template <typename TFx, typename... Tn>
		std::future< typename std::result_of<TFx( Tn... )>::type > Queue ( TFx&& fx, Tn&&... argn );

		furrovineapi ~ThreadPool ( );

	private:
		template <typename TFx, typename... Tn> 
		std::future< typename std::result_of<TFx( Tn... )>::type > QueueAt ( ulword threadindex, TFx&& fx, Tn&&... argn );

		template <typename TResult, typename T>
		TWork MakeWork ( std::shared_ptr<std::promise<TResult>> promise, T&& binding );

		template <typename TResult, typename T>
		TWork MakeWork ( std::false_type f, std::shared_ptr<std::promise<TResult>> promise, T&& binding );

		template <typename TResult, typename T>
		TWork MakeWork ( std::true_type t, std::shared_ptr<std::promise<TResult>> promise, T&& binding );

		furrovineapi void QueueWorkAt ( ulword threadindex, TWork item );

		furrovineapi void QueueWork ( TWork item );

	};

}}
