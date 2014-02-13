#ifndef FURROVINECALLBACKEVENT1_H
#define FURROVINECALLBACKEVENT1_H

#include <Furrovine++/Callback.h>

namespace Furrovine {
	
#ifdef FURROVINENOVARIADICS

	template <typename T0> 
	class CallbackEvent1 {
	public:
		typedef void(* TFunctionPointerSignature)(T0);
		typedef void( TFunctionSignature)(T0);
		typedef Callback<void(T0)> TCallback;
		typedef std::vector<TCallback> InvocationTable;

	protected:
		InvocationTable invocations;

	public:
		static const std::size_t DefaultFunctorCapacity = 4;

		CallbackEvent1 () : invocations() {
			invocations.reserve( DefaultFunctorCapacity );
		}

		CallbackEvent1 ( int expectedfunctorcount ) : invocations() {
			invocations.reserve( expectedfunctorcount );
		}

		template <void (* TFunc)(T0)> 
		void Add (  ) {
			TCallback c = DeduceCallback1( TFunc ).template Bind< TFunc >( );
			invocations.emplace_back( c );
		}

		template <typename T, void (T::* TFunc)(T0)> 
		void Add ( T& object ) {
			Add<T, TFunc>( &object );
		}

		template <typename T, void (T::* TFunc)(T0)> void 
			Add ( T* object ) {
			TCallback c = DeduceCallback1( TFunc ).template Bind< TFunc >( object );
			invocations.emplace_back( c );
		}

		template <typename T, void (T::* TFunc)(T0) const> 
		void Add ( T& object ) {
			Add<T, TFunc>( &object );
		}

		template <typename T, void (T::* TFunc)(T0) const> void Add ( T* object ) {
			TCallback c = DeduceCallback1( TFunc ).template Bind< TFunc >( object );
			invocations.emplace_back( c );
		}

		template <typename A0>
		void Invoke ( A0&& t0 ) {
			std::size_t i;
			for ( i = 0; i < invocations.size(); ++i ) {
				invocations[i]( std::forward<T0>( t0 ) );
			}
		}

		template <typename A0>
		void operator() ( A0&& t0 ) {
			Invoke( std::forward<A0>( t0 ) );
		}

		std::size_t InvocationCount ( ) const {
			return invocations.size( );
		}

		operator bool () const {
			return InvocationCount() > 0;
		}

		template <void (* TFunc)(T0)> 
		bool Remove () { return Remove (DeduceCallback1(TFunc).template Bind<TFunc>()); } 
		
		template <typename T, void (T::* TFunc)(T0)> 
		bool Remove (T& object) { return Remove <T, TFunc>(&object); } 
		
		template <typename T, void (T::* TFunc)(T0)> 
		bool Remove (T* object) { return Remove (DeduceCallback1(TFunc).template Bind<TFunc>(object)); } 
		
		template <typename T, void (T::* TFunc)(T0) const> 
		bool Remove (T& object) { return Remove <T, TFunc>(&object); } 
		
		template <typename T, void (T::* TFunc)(T0) const> 
		bool Remove (T* object) { return Remove (DeduceCallback1(TFunc).template Bind<TFunc>(object)); } 

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

#endif // FURROVINECALLBACKEVENT1_H 