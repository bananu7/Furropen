#pragma once

#include <Furrovine++/std_defines.h>
#include <list>
#include <functional>

namespace Furrovine {

#ifdef FURROVINENOVARIADICS

	template <typename T0, typename T1, typename T2, typename T3> 
	class Event4 {
	public:
		typedef void(* TPointerSignature)(T0, T1, T2, T3);
		typedef void( TFunctionSignature)(T0, T1, T2, T3);
		typedef std::function<TFunctionSignature> TCallback;
		typedef std::list<TCallback> InvocationTable;
		typedef typename InvocationTable::iterator Token;

	protected:
		InvocationTable invocations;

	public:
		Event4 () : invocations() {

		}

		template <void (* TFunc)(T0, T1, T2)> 
		Token Add (  ) {
			TCallback c = TFunc;
			return Add( c );
		}

		template <typename T, void (T::* TFunc)(T0, T1, T2)> 
		Token Add ( T& object ) {
			return Add<T, TFunc>( &object );
		}

		template <typename T, void (T::* TFunc)(T0, T1, T2, T3)> 
		Token Add ( T* object ) {
			TCallback c = std::bind( object, TFunc, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4 );
			return Add( c );
		}

		template <typename T, void (T::* TFunc)(T0, T1, T2, T3) const> 
		Token Add ( T& object ) {
			return Add<T, TFunc>( &object );
		}

		template <typename T, void (T::* TFunc)(T0, T1, T2) const> 
		Token Add ( T* object ) {
			TCallback c = std::bind( object, TFunc, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4 );
			return Add( c );
		}

		Token Add ( TCallback&& c ) {
			invocations.emplace_back( c );
			return --invocations.end();
		}

		template <typename A0, typename A1, typename A2, typename A3>
		void Invoke ( A0&& t0, A1&& t1, A2&& t2, A3&& t3 ) {
			for ( auto& invocation : invocations ) {
				invocation( std::forward<T0>( t0 ), std::forward<T1>( t1 ), std::forward<T2>( t2 ), std::forward<T3>( t3 ) );
			}
		}

		template <typename A0, typename A1, typename A2, typename A3>
		void operator() ( A0&& t0, A1&& t1, A2&& t2, A3&& t3 ) {
			Invoke( std::forward<A0>( t0 ), std::forward<A1>( t1 ), std::forward<A2>( t2 ), std::forward<A3>( t3 ) );
		}

		operator bool () const {
			return InvocationCount() > 0;
		}

		std::size_t InvocationCount ( ) const {
			return invocations.size( );
		}

		bool Remove ( const Token& token )          
		{ invocations.erase( token ); return true; } 

	};

#endif

}
 