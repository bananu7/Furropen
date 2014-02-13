#pragma once

#include <Furrovine++/null.h>

namespace Furrovine {

	template <typename T>
	class IService {
	private:
		T* serv;

	public:
		IService( ) : serv( null ) {

		}

		IService( T* service ) : serv( service ) {

		}

		IService( T& service ) : serv( std::addressof( service ) ) {

		}

		bool HasService( ) const {
			return serv != null;
		}

		void SetService( T& service ) {
			SetService( &service );
		}

		void SetService( T* service ) {
			serv = service;
		}

		T* GetServicePtr( ) {
			return serv;
		}

		T& GetService( ) {
			return *serv;
		}

		T* operator-> ( ) {
			return GetServicePtr();
		}

		operator T& ( ) {
			return GetService();
		}

		~IService( ) {

		}
	};

}