#pragma once

#include <Furrovine++/Event1.h>
#include <Furrovine++/Export.h>

namespace Furrovine {

#ifdef FURROVINENOVARIADICS

	template <> 
	class Event1<void> {
	public:
		typedef void(* TPointerSignature)();
		typedef void( TFunctionSignature)();
		typedef std::function<TFunctionSignature> TCallback;
		typedef std::list<TCallback> InvocationTable;
		typedef InvocationTable::iterator Token;

	protected:
		InvocationTable invocations;

	public:
		furrovineapi Event1 () : invocations() {
			
		}

		template <void (* TFunc)()> 
		Token Add (  ) {
			TCallback c = TFunc;
			return Add( c );
		}

		template <typename T, void (T::* TFunc)()> 
		Token Add ( T& object ) {
			return Add<T, TFunc>( &object );
		}

		template <typename T, void (T::* TFunc)()> 
		Token Add ( T* object ) {
			TCallback c = std::bind( object, TFunc );
			return Add( c );
		}

		template <typename T, void (T::* TFunc)() const> 
		Token Add ( T& object ) {
			return Add<T, TFunc>( &object );
		}

		template <typename T, void (T::* TFunc)() const> 
		Token Add ( T* object ) {
			TCallback c = std::bind( object, TFunc );
			return Add( c );
		}

		furrovineapi Token Add ( TCallback&& c ) {
			invocations.emplace_back( c );
			return --invocations.end();
		}

		furrovineapi void Invoke ( ) {
			for ( auto& invocation : invocations ) {
				invocation( );
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

		furrovineapi bool Remove ( const Token& token )          
		{ invocations.erase( token ); return true; } 

	};

#endif

}
