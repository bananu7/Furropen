#pragma once

#include <Furrovine++/Declarations.h>
#include <Furrovine++/ResourceCache.h>
#include <Furrovine++/IO/FileSystem.h>
#include <functional>
#include <unordered_map>

namespace Furrovine { namespace Pipeline {

	class ContentLoader {
	private:
		ServiceProvider* services;
		IO::FileSystem files;
		std::unordered_map<String, std::function<void( ContentLoader& )>> loadchains;

	public:

		furrovineapi ContentLoader( const String& rootpath );
		furrovineapi ContentLoader( const String& rootpath, ServiceProvider& serviceprovider );
		furrovineapi ContentLoader( const String& rootpath, ServiceProvider* serviceprovider );

		furrovineapi const IO::FileSystem& ContentFileSystem () const;

		furrovineapi String Resolve ( const String& id );

		furrovineapi void Refresh ( );

		template <typename T, typename TFx, typename ...TFxn>
		T* ChainedLoad ( const String& id, ResourceCache<String>& cache, TFx&& fx, TFxn&&... fxn );

		template <typename T, typename TFx, typename ...TFxn>
		T* ChainedLoad ( const String& id, ResourceCache<String>* cache, TFx&& fx, TFxn&&... fxn );

		template <typename T, typename TFx, typename ...TFxn>
		void ChainedLoad ( const String& id, T*& value, ResourceCache<String>& cache, TFx&& fx, TFxn&&... fxn );

		template <typename T, typename TFx, typename ...TFxn>
		void ChainedLoad ( const String& id, T*& value, ResourceCache<String>* cache, TFx&& fx, TFxn&&... fxn );

		template <typename T, typename TFx>
		T* Load ( const String& id, ResourceCache<String>& cache, TFx&& fx );

		template <typename T, typename TFx>
		T* Load ( const String& id, ResourceCache<String>* cache, TFx&& fx );

		template <typename T, typename TFx>
		void Load ( const String& id, T*& value, ResourceCache<String>& cache, TFx&& fx );

		template <typename T, typename TFx>
		void Load ( const String& id, T*& value, ResourceCache<String>* cache, TFx&& fx );

		furrovineapi ~ContentLoader();

	protected:
		template <typename T>
		bool TryRetrieve( const String& id, T*& value, ResourceCache<String>*& cache );

		template <typename T, typename TFx>
		void LoadResolved ( const String& id, const String& absoluteid, T*& value, ResourceCache<String>* cache, TFx&& fx );

		template <typename T, typename TFx>
		void ReloadResolved ( const String& id, const String& absoluteid, T*& value, ResourceCache<String>* cache, TFx&& fx );

		template <typename T, typename TFx>
		void LoadStream ( const String& id, IO::Stream& stream, T*& value, ResourceCache<String>* cache, TFx&& fx );

		template <typename T, typename TFx>
		void ReloadStream ( const String& id, IO::Stream& stream, T*& value, ResourceCache<String>* cache, TFx&& fx );

		template <typename T>
		void Collect ( bool replace, const String& id, T*& value, ResourceCache<String>* cache = null );

		template <typename T>
		void Collect ( bool replace, const String& id, T&& value, ResourceCache<String>* cache = null );

	};

}}
