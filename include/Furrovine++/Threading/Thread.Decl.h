#pragma once

#include <Furrovine++/FurrovineApi.h>
#include <Furrovine++/std_defines.h>
#include <Furrovine++/ptr.h>
#include <Furrovine++/make_ptr.h>
#include <atomic>
#include <thread>
#include <functional>

namespace Furrovine { namespace Threading {

	class Thread {
	private:
		struct ThreadInfo {
			std::function<void()> threadjump;
			std::atomic<bool> working;

			furrovineapi ThreadInfo ();
		};

		std::shared_ptr<ThreadInfo> info;
		std::thread thread;
		std::atomic<bool> detached;

		furrovineapi Thread ( const Thread& nocopy );

		furrovineapi Thread& operator= ( const Thread& nocopy );

		furrovineapi static void Run ( std::shared_ptr<ThreadInfo> threadinfo );

	public:

		furrovineapi Thread ( );

		furrovineapi Thread ( Thread&& mov );

		furrovineapi Thread& operator= ( Thread&& mov );

		template <typename Fx, typename ...Tn>
		Thread ( Fx&& fx, Tn&&... args );

		template <typename Fx, typename ...Tn>
		Thread ( bool start, Fx&& fx, Tn&&... args );

		template <typename Fx, typename ...Tn>
		void Reset ( Fx&& fx, Tn&&... args );

		template <typename Fx, typename ...Tn>
		void Reset ( bool start, Fx&& fx, Tn&&... args );

		furrovineapi std::thread::native_handle_type Handle ();

		furrovineapi std::thread::id ID () const;

		furrovineapi void Start ();

		furrovineapi bool Done () const;

		furrovineapi bool Started () const;

		furrovineapi bool Joinable () const;

		furrovineapi void Join ();

		furrovineapi void Detach ();

		furrovineapi static unsigned int HardwareThreads ();

		furrovineapi ~Thread ();
	};

}}
