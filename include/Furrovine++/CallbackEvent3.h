#ifndef FURROVINECALLBACKEVENT3_H
#define FURROVINECALLBACKEVENT3_H

#include <Furrovine++/Callback.h>

namespace Furrovine {
	
#ifdef FURROVINENOVARIADICS

	template <typename T0, typename T1, typename T2> 
	class CallbackEvent3 {
	public:
		typedef void(* TFunctionPointerSignature)(T0, T1, T2);
		typedef void( TFunctionSignature)(T0, T1, T2);
		typedef Callback<void(T0, T1, T2)> TCallback;
		typedef std::vector<TCallback> InvocationTable;

	protected:
		InvocationTable invocations;

	public:
		static const std::size_t DefaultFunctorCapacity = 4;

		CallbackEvent3 () : invocations() {
			invocations.reserve( DefaultFunctorCapacity );
		}

		CallbackEvent3 ( int expectedfunctorcount ) : invocations() {
			invocations.reserve( expectedfunctorcount );
		}

		template <void (* TFunc)(T0, T1, T2)> 
		void Add (  ) {
			TCallback c = DeduceCallback3( TFunc ).template Bind< TFunc >( );
			invocations.emplace_back( c );
		}

		template <typename T, void (T::* TFunc)(T0, T1, T2)> 
		void Add ( T& object ) {
			Add<T, TFunc>( &object );
		}

		template <typename T, void (T::* TFunc)(T0, T1, T2)> 
		void Add ( T* object ) {
			TCallback c = DeduceCallback3( TFunc ).template Bind< TFunc >( object );
			invocations.emplace_back( c );
		}

		template <typename T, void (T::* TFunc)(T0, T1, T2) const> 
		void Add ( T& object ) {
			Add<T, TFunc>( &object );
		}

		template <typename T, void (T::* TFunc)(T0, T1, T2) const> 
		void Add ( T* object ) {
			TCallback c = DeduceCallback3( TFunc ).template Bind< TFunc >( object );
			invocations.emplace_back( c );
		}

		template <typename A0, typename A1, typename A2>
		void Invoke ( A0&& t0, A1&& t1, A2&& t2 ) {
			std::size_t i;
			for ( i = 0; i < invocations.size(); ++i ) {
				invocations[i]( std::forward<T0>( t0 ), std::forward<T1>( t1 ), std::forward<T2>( t2 ) );
			}
		}

		template <typename A0, typename A1, typename A2>
		void operator() ( A0&& t0, A1&& t1, A2&& t2 ) {
			Invoke( std::forward<A0>( t0 ), std::forward<A1>( t1 ), std::forward<A2>( t2 ) );
		}

		std::size_t InvocationCount ( ) const {
			return invocations.size( );
		}

		operator bool () const {
			return InvocationCount() > 0;
		}

		template <void (* TFunc)(T0, T1, T2)> 
		bool Remove () { return Remove (DeduceCallback3(TFunc).template Bind<TFunc>()); } 
		
		template <typename T, void (T::* TFunc)(T0, T1, T2)> 
		bool Remove (T& object) { return Remove <T, TFunc>(&object); } 
		
		template <typename T, void (T::* TFunc)(T0, T1, T2)> 
		bool Remove (T* object) { return Remove (DeduceCallback3(TFunc).template Bind<TFunc>(object)); } 
		
		template <typename T, void (T::* TFunc)(T0, T1, T2) const> 
		bool Remove (T& object) { return Remove <T, TFunc>(&object); } 
		
		template <typename T, void (T::* TFunc)(T0, T1, T2) const> 
		bool Remove (T* object) { return Remove (DeduceCallback3(TFunc).template Bind<TFunc>(object)); } 

	protected:

		bool Remove( TCallback const& target ) {
			auto it = std::find(invocations.begin(), invocations.end(), target);
			if ( it == invocations.end()) 
				return false;
			invocations.erase(it);
			return true;
		}

	};

#endif
	
}

#endif // FURROVINECALLBACKEVENT3_H 