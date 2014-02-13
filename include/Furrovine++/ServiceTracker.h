#pragma once

#include <Furrovine++/IService.h>
#include <Furrovine++/Declarations.h>

namespace Furrovine {

	template <typename T>
	class ServiceTracker : IService<T> {
	private:
		ServiceProvider* provider;
		
	public:

		ServiceTracker( ServiceProvider& serviceprovider, T& providingservice ) : IService( providingservice ), provider( std::addressof( serviceprovider ) ) {
			provider->AddService<IService<T>>( *this );
		}

		~ServiceTracker( ) {
			provider->RemoveService<IService<T>>( );
		}

	};

}