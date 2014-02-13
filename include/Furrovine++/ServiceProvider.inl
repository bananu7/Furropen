#pragma once

#include <Furrovine++/ServiceProvider.h>
#include <utility>
#include <Furrovine++/unqualified.h>

namespace Furrovine {

	template <typename TService>
	bool ServiceProvider::RemoveService( ) {
		typedef typename unqualified<TService>::type T;
		typedef T* pointer;
		runtime_type runtime = typeof<T>( );
		auto target = services.find( runtime );
		if ( target == services.end( ) )
			return false;
		services.erase( runtime );
		return true;
	}

	template <typename TService>
	bool ServiceProvider::ContainsService( ) const {
		typedef typename unqualified<TService>::type T;
		typedef T* pointer;
		runtime_type runtime = typeof<T>( );
		return services.find( runtime ) != services.end( );
	}

	template <typename T>
	T& ServiceProvider::GetService() {
		return *GetServicePtr<T>();
	}

	template <typename TService>
	TService* ServiceProvider::GetServicePtr() {
		typedef typename unqualified<TService>::type T;
		typedef T* pointer;
		runtime_type runtime = typeof<T>( );
		auto p = services.find( runtime );
		if ( p == services.end() )
			throw ServiceNotFoundException( "Service does not exist" );

		return p->second.as<pointer>();
	}

	template <typename TService>
	bool ServiceProvider::ReplaceService( TService* service, TService*& old ) {
		typedef typename unqualified<TService>::type T;
		typedef T* pointer;
		runtime_type runtime = typeof<T>( );
		bool replaced = false;
		auto s = services.find( runtime );
		if ( s != services.end() ) {
			if ( s->second.is<pointer>() ) {
				old = s->second.as<pointer>();
			}
			services.erase( s );
			replaced = true;
		}
		services.emplace_hint( s, std::move( runtime ), make_any<pointer>( service ) );
		return replaced;
	}

	template <typename TService>
	bool ServiceProvider::TryGetService( TService*& service ) {
		typedef typename unqualified<TService>::type T;
		typedef T* pointer;
		runtime_type runtime = typeof<T>( );
		auto s = services.find( runtime );
		if ( s == services.end() )
			return false;

		service = s->second.as<pointer>( );
		return true;
	}

	template <typename T>
	T* ServiceProvider::TryGetService( ) {
		T* service = null;
		TryGetService( service );
		return service;
	}

	template <typename T>
	bool ServiceProvider::AddService( T& service ) {
		return AddService( std::addressof( service ) );
	}

	template <typename TService>
	bool ServiceProvider::AddService( TService* service ) {
		typedef typename unqualified<TService>::type T;
		typedef T* pointer;
		runtime_type runtime = typeof<T>( );
		auto s = services.find( runtime );
		if ( s != services.end() ) {
			return false;
		}

		services.emplace_hint( s, std::move( runtime ), make_any<pointer>( service ) );
		return true;
	}

}
