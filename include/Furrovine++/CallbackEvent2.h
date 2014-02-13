#ifndef FURROVINECALLBACKEVENT2_H
#define FURROVINECALLBACKEVENT2_H

#include <Furrovine++/Callback.h>

namespace Furrovine {
	
#ifdef FURROVINENOVARIADICS

	template <typename T0, typename T1> 
	class CallbackEvent2 {
	public:
		typedef void(* TFunctionPointerSignature)(T0, T1);
		typedef void( TFunctionSignature)(T0, T1);
		typedef Callback<void(T0, T1)> TCallback;
		typedef std::vector<TCallback> InvocationTable;

	protected:
		InvocationTable invocations;

	public:
		static const std::size_t DefaultFunctorCapacity = 4;

		CallbackEvent2 () : invocations() {
			invocations.reserve( DefaultFunctorCapacity );
		}

		CallbackEvent2 ( int expectedfunctorcount ) : invocations() {
			invocations.reserve( expectedfunctorcount );
		}

		template <void (* TFunc)(T0, T1)> 
		void Add (  ) {
			TCallback c = DeduceCallback2( TFunc ).template Bind< TFunc >( );
			invocations.emplace_back( c );
		}

		template <typename T, void (T::* TFunc)(T0, T1)> 
		void Add ( T& object ) {
			Add<T, TFunc>( &object );
		}

		template <typename T, void (T::* TFunc)(T0, T1)> 
		void Add ( T* object ) {
			TCallback c = DeduceCallback2( TFunc ).template Bind< TFunc >( object );
			invocations.emplace_back( c );
		}

		template <typename T, void (T::* TFunc)(T0, T1) const> 
		void Add ( T& object ) {
			Add<T, TFunc>( &object );
		}

		template <typename T, void (T::* TFunc)(T0, T1) const> 
		void Add ( T* object ) {
			TCallback c = DeduceCallback2( TFunc ).template Bind< TFunc >( object );
			invocations.emplace_back( c );
		}

		template <typename A0, typename A1>
		void Invoke ( A0&& t0, A1&& t1 ) {
			std::size_t i;
			for ( i = 0; i < invocations.size(); ++i ) {
				invocations[i]( std::forward<T0>( t0 ), std::forward<T1>( t1 ) );
			}
		}

		template <typename A0, typename A1>
		void operator() ( A0&& t0, A1&& t1 ) {
			Invoke( std::forward<A0>( t0 ), std::forward<A1>( t1 ) );
		}

		std::size_t InvocationCount ( ) const {
			return invocations.size( );
		}

		operator bool () const {
			return InvocationCount() > 0;
		}

		template <void (* TFunc)(T0, T1)> 
		bool Remove () { return Remove (DeduceCallback2(TFunc).template Bind<TFunc>()); } 
		
		template <typename T, void (T::* TFunc)(T0, T1)> 
		bool Remove (T& object) { return Remove <T, TFunc>(&object); } 
		
		template <typename T, void (T::* TFunc)(T0, T1)>
		bool Remove (T* object) { return Remove (DeduceCallback2(TFunc).template Bind<TFunc>(object)); } 
		
		template <typename T, void (T::* TFunc)(T0, T1) const>
		bool Remove (T& object) { return Remove <T, TFunc>(&object); } 
		
		template <typename T, void (T::* TFunc)(T0, T1) const> 
		bool Remove (T* object) { return Remove (DeduceCallback2(TFunc).template Bind<TFunc>(object)); } 

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

#endif // FURROVINECALLBACKEVENT2_H 