#pragma once

#include <Furrovine++/std_defines.h>
#include <unordered_map>
#include <Furrovine++/any.h>
#include <Furrovine++/PrimitiveTypes.h>

namespace Furrovine {

	class ServiceProvider {
	private:
		std::unordered_map<runtime_type, any, std::hash<runtime_type>, inherited_from> services;

	public:
		
		furrovineapi ServiceProvider( ulword initialcapacity = 8 );

		furrovineapi ServiceProvider( ServiceProvider&& mov );
		furrovineapi ServiceProvider& operator=( ServiceProvider&& mov );
		furrovineapi ServiceProvider( const ServiceProvider& nocopy ) = delete;
		furrovineapi ServiceProvider& operator=( const ServiceProvider& nocopy ) = delete;

		template <typename T> 
		bool TryGetService ( T*& service );

		template <typename T> 
		T* TryGetService ( );

		template <typename T>
		bool AddService ( T& service );

		template <typename T>
		bool AddService ( T* service );

		template <typename T> 
		bool ReplaceService ( T* service, T*& old );

		template <typename T> 
		T& GetService ( );

		template <typename T> 
		T* GetServicePtr ( );

		template <typename T> 
		bool ContainsService ( ) const;

		template <typename T> 
		bool RemoveService ( );

	};

}
