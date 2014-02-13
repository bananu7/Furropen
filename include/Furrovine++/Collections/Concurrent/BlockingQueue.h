#ifndef FURROVINEBLOCKINGQUEUE_H
#define FURROVINEBLOCKINGQUEUE_H

#include <Furrovine++/std_defines.h>
#include <deque>
#include <mutex>
#include <array>
#include <queue>
#include <Furrovine++/Threading/AutoResetEvent.h>
#include <Furrovine++/Threading/Semaphore.h>

namespace Furrovine { namespace Collections { namespace Concurrent {

	template <typename T, typename TContainer = std::deque<T>>
	class BlockingQueue {
	private:
		typedef std::lock_guard<std::mutex> TLockGuard;

		std::mutex op;
		Threading::Semaphore itemsignal;
		Threading::AutoResetEvent diesignal;
		std::array<HANDLE, 2> signals;
		std::queue<T, TContainer> q;
		
		void Lock () {
			TLockGuard guard( op );
		}

		void LockedPush ( const T& item ) {
			TLockGuard guard( op );
			q.push( item );
		}

		void LockedPush ( T&& item ) {
			TLockGuard guard( op );
			q.push( item );
		}

		template <typename ...Tn>
		void LockedEmplace ( Tn&&... args ) {
			TLockGuard guard( op );
			q.emplace( std::forward<Tn>( args )... );
		}

		T LockedPop ( ) {
			TLockGuard guard( op );
			T item = q.front();
			q.pop();
			return item;
		}

		bool LockedEmpty () {
			TLockGuard guard( op );
			return q.empty();
		}

		ulword LockedSize () {
			TLockGuard guard( op );
			return q.size();
		}

		int32 Wait () {
			return Threading::WaitHandle::WaitMultiple( signals.data(), signals.size(), false );
		}

	public:
		BlockingQueue ( ) {
			signals[0] = diesignal.Handle();
			signals[1] = itemsignal.Handle();
		}

		BlockingQueue ( BlockingQueue&& mov ) {
			TLockGuard movguard( mov.op );
			TLockGuard guard( op );
			itemsignal = std::move( mov.itemsignal );
			diesignal = std::move( mov.diesignal );
			q = std::move( mov.q );
			signals[0] = diesignal.Handle();
			signals[1] = itemsignal.Handle();
		}

		BlockingQueue& operator= ( BlockingQueue&& mov ) {
			TLockGuard movguard( mov.op );
			TLockGuard guard( op );
			itemsignal = std::move( mov.itemsignal );
			diesignal = std::move( mov.diesignal );
			q = std::move( mov.q );
			signals[0] = diesignal.Handle();
			signals[1] = itemsignal.Handle();
		}

		template <typename ...Tn>
		void Emplace ( Tn&&... args ) {
			LockedEmplace( std::forward<Tn>( args )... );
			itemsignal.Set();
		}

		void Push ( const T& item ) {
			LockedPush( item );
			itemsignal.Set();
		}

		void Push ( T&& item ) {
			LockedPush( std::move( item ) );
			itemsignal.Set();
		}

		bool Pop ( T& item ) {
			if ( Wait() == 1 ) {
				item = LockedPop( );
				return true;
			}
			return false;
		}

		bool Empty () {
			return LockedEmpty( );
		}

		ulword Size () {
			return LockedSize( );
		}

		~BlockingQueue ( ) {
			diesignal.Set();
			Lock();
		}
	};

}}}

#endif // FURROVINEBLOCKINGQUEUE_H 