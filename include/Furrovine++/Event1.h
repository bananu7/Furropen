#pragma once

#include <Furrovine++/std_defines.h>
#include <list>
#include <functional>

namespace Furrovine {

#ifdef FURROVINENOVARIADICS

	template <typename T0> class Event1 {
	public:
		typedef void(* TPointerSignature)(T0);
		typedef void( TFunctionSignature)(T0);
		typedef std::function<TFunctionSignature> TCallback;
		typedef std::list<TCallback> InvocationTable;
		typedef typename InvocationTable::iterator Token;
	
	private:
		
		InvocationTable invocations;

	public:
		Event1 () : invocations() {
		
		}

		template <void (* TFunc)(T0)> 
		Token Add (  ) {
			TCallback c = TFunc;
			return Add( c );
		}

		template <typename T, void (T::* TFunc)(T0)> 
		Token Add ( T& object ) {
			return Add<T, TFunc>( &object );
		}

		template <typename T, void (T::* TFunc)(T0)> 
		Token Add ( T* object ) {
			TCallback c = std::bind( object, TFunc, std::placeholders::_1 );
			return Add( c );
		}

		template <typename T, void (T::* TFunc)(T0) const> 
		Token Add ( T& object ) {
			return Add<T, TFunc>( &object );
		}

		template <typename T, void (T::* TFunc)(T0) const> 
		Token Add ( T* object ) {
			TCallback c = std::bind( object, TFunc, std::placeholders::_1 );
			return Add( c );
		}

		Token Add ( TCallback&& c ) {
			invocations.emplace_back( c );
			return --invocations.end();
		}

		template <typename A0>
		void Invoke ( A0&& t0 ) {
			for ( auto& invocation : invocations ) {
				invocation( std::forward<A0>( t0 ) );
			}
		}

		template <typename A0>
		void operator() ( A0&& t0 ) {
			Invoke( std::forward<A0>( t0 ) );
		}

		operator bool () {
			return InvocationCount() > 0;
		}

		std::size_t InvocationCount ( ) {
			return invocations.size( );
		}

		bool Remove ( const Token& token )          
		{ invocations.erase( token ); return true; } 

	};

#endif

}
