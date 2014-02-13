#ifndef FURROVINECALLBACKEVENT0_H
#define FURROVINECALLBACKEVENT0_H

#include <Furrovine++/CallbackEvent1.h>

namespace Furrovine {
	
#ifdef FURROVINENOVARIADICS

	template <> 
	class CallbackEvent1<void> {
	public:
		typedef void(* TFunctionPointerSignature)( );
		typedef void( TFunctionSignature)( );
		typedef Callback<TFunctionSignature> TCallback;
		typedef std::vector<TCallback> InvocationTable;

	protected:
		InvocationTable invocations;

	public:
		static const std::size_t DefaultFunctorCapacity = 4;

		furrovineapi CallbackEvent1 () : invocations() {
			invocations.reserve( DefaultFunctorCapacity );
		}

		furrovineapi CallbackEvent1 ( int expectedfunctorcount ) : invocations() {
			invocations.reserve( expectedfunctorcount );
		}

		template <void (* TFunc)( )> 
		void Add (  ) {
			TCallback c = DeduceCallback0( TFunc ).template Bind< TFunc >( );
			invocations.emplace_back( c );
		}

		template <typename T, void (T::* TFunc)( )> 
		void Add ( T& object ) {
			Add<T, TFunc>( &object );
		}

		template <typename T, void (T::* TFunc)( )> 
		void Add ( T* object ) {
			TCallback c = DeduceCallback0( TFunc ).template Bind< TFunc >( object );
			invocations.emplace_back( c );
		}

		template <typename T, void (T::* TFunc)( ) const> 
		void Add ( T& object ) {
			Add<T, TFunc>( &object );
		}

		template <typename T, void (T::* TFunc)( ) const> 
		void Add ( T* object ) {
			TCallback c = DeduceCallback0( TFunc ).template Bind< TFunc >( object );
			invocations.emplace_back( c );
		}

		furrovineapi void Invoke ( ) {
			std::size_t i;
			for ( i = 0; i < invocations.size(); ++i ) {
				invocations[i]( );
			}
		}

		furrovineapi void operator() ( ) {
			Invoke( );
		}

		furrovineapi operator bool () const {
			return InvocationCount() > 0;
		}

		furrovineapi std::size_t InvocationCount ( ) const {
			return invocations.size( );
		}

		template <void (* TFunc)( )>
		bool Remove () { return Remove (DeduceCallback0(TFunc).template Bind<TFunc>()); } 
		
		template <typename T, void (T::* TFunc)( )> 
		bool Remove (T& object) { return Remove <T, TFunc>(&object); } 
		
		template <typename T, void (T::* TFunc)( )> 
		bool Remove (T* object) { return Remove (DeduceCallback0(TFunc).template Bind<TFunc>(object)); }  
		
		template <typename T, void (T::* TFunc)( ) const> 
		bool Remove (T& object) { return Remove <T, TFunc>(&object); } 
		
		template <typename T, void (T::* TFunc)( ) const> 
		bool Remove (T* object) { return Remove (DeduceCallback0(TFunc).template Bind<TFunc>(object)); } 

	protected:

		furrovineapi bool Remove( TCallback const& target ) {
			auto it = std::find(invocations.begin(), invocations.end(), target);
			if ( it == invocations.end() ) 
				return false;
			invocations.erase( it );
			return true;
		}

	};

#endif
	
}

#endif // FURROVINECALLBACKEVENT0_H 