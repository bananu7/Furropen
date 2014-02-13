#ifndef FURROVINECONTENTLOADER_INL
#define FURROVINECONTENTLOADER_INL

#include <Furrovine++/Pipeline/ContentLoader.Decl.h>
#include <Furrovine++/function_chain.h>
#include <Furrovine++/release.h>
#include <Furrovine++/get.h>
 
namespace Furrovine { namespace Pipeline {

	template <typename T, typename TFx, typename ...TFxn>
	T* ContentLoader::ChainedLoad ( const String& id, ResourceCache<String>& cache, TFx&& fx, TFxn&&... fxn ) {
		return ChainedLoad<T, TFx, TFxn...>( id, &cache, std::forward<TFx>( fx ), std::forward<TFxn>( fxn )... );
	}

	template <typename T, typename TFx, typename ...TFxn>
	T* ContentLoader::ChainedLoad ( const String& id, ResourceCache<String>* cache, TFx&& fx, TFxn&&... fxn ) {
		T* value = null;
		ChainedLoad<T, TFx, TFxn...>( id, value, cache, std::forward<TFx>( fx ), std::forward<TFxn>( fxn )... );
		return value;
	}

	template <typename T, typename TFx, typename ...TFxn>
	void ContentLoader::ChainedLoad ( const String& id, T*& value, ResourceCache<String>& cache, TFx&& fx, TFxn&&... fxn ) {
		ChainedLoad<T, TFx, TFxn...>( id, value, &cache, std::forward<TFx>( fx ), std::forward<TFxn>( fxn )... );
	}

	template <typename T, typename TFx, typename ...TFxn>
	void ContentLoader::ChainedLoad ( const String& id, T*& value, ResourceCache<String>* cache, TFx&& fx, TFxn&&... fxn ) {
		auto composition = make_chain<T*, IO::Stream&>( std::forward<TFx>( fx ), std::forward<TFxn>( fxn )... );
		typedef decltype( composition ) TComp;

		Load<T, TComp>( id, value, cache, composition );
	}

	template <typename T, typename TFx>
	T* ContentLoader::Load ( const String& id, ResourceCache<String>& cache, TFx&& fx ) {
		return Load<T, TFx>( id, &cache, std::forward<TFx>( fx ) );
	}

	template <typename T, typename TFx>
	T* ContentLoader::Load ( const String& id, ResourceCache<String>* cache, TFx&& fx ) {
		T* value = null;
		Load<T, TFx>( id, value, cache, std::forward<TFx>( fx ) );
		return value;
	}

	template <typename T, typename TFx>
	void ContentLoader::Load ( const String& id, T*& value, ResourceCache<String>& cache, TFx&& fx ) {
		Load<T, TFx>( id, value, &cache, std::forward<TFx>( fx ) );
	}

	template <typename T, typename TFx>
	void ContentLoader::Load ( const String& id, T*& value, ResourceCache<String>* cache, TFx&& fx ) {
		String absoluteid = Resolve( id );
		LoadResolved<T, TFx>( id, absoluteid, value, cache, std::forward<TFx>( fx ) );
	}

	template <typename T, typename TFx>
	void ContentLoader::LoadResolved ( const String& id, const String& absoluteid, T*& value, ResourceCache<String>* cache, TFx&& fx ) {
		bool replace = false;

		if ( cache == null && services != null ) {
			services->TryGetService<ResourceCache<String>>( cache );
		}

		if ( cache != null && 
			cache->TryGet( id, value ) &&
			!( replace = value == null ) ) {

				return;
		}

		ReloadResolved( id, absoluteid, value, cache, std::forward<TFx>( fx ) );

	}

	template <typename T, typename TFx>
	void ContentLoader::LoadStream ( const String& id, IO::Stream& stream, T*& value, ResourceCache<String>* cache, TFx&& fx ) {
		if ( TryRetrieve( id, value, cache ) )
			return;
		ReloadStream( id, stream, value, cache, std::forward<TFx>( fx ) );

	}

	template <typename T>
	bool ContentLoader::TryRetrieve( const String& id, T*& value, ResourceCache<String>*& cache ) {
		if ( cache == null && services != null ) {
			services->TryGetService<ResourceCache<String>>( cache );
		}
		if ( cache != null && 
			cache->TryGet( id, value ) &&
			value != null ) {

			return true;
		}

		return false;
	}

	template <typename T, typename TFx>
	void ContentLoader::ReloadResolved( const String& id, const String& absoluteid, T*& value, ResourceCache<String>* cache, TFx&& fx ) {
		loadchains[ absoluteid ] = [ = ]( ContentLoader& cl ) mutable { 
			IO::FileStream f( absoluteid, IO::FileMode::Open );
			T* v = null; 
			ReloadStream( id, f, v, cache, fx ); 
		};
		IO::FileStream f( absoluteid, IO::FileMode::Open );

		ReloadStream( id, f, value, cache, std::forward<TFx>( fx ) );
	}

	template <typename T, typename TFx>
	void ContentLoader::ReloadStream( const String& id, IO::Stream& stream, T*& value, ResourceCache<String>* cache, TFx&& fx ) {
		auto loaded = fx( stream );
		value = get( loaded );

		if ( value == null ) {
			throw ErrorCodeException( Format( "Loading failed for '{0}'", id ) );
		}

		Collect( true, id, std::forward<decltype(loaded)>( loaded ), cache );
	}

	template <typename T>
	void ContentLoader::Collect ( bool replace, const String& id, T*& value, ResourceCache<String>* cache /* = null */ ) {
		if ( cache == null )
			return;

		if ( replace ) {
			cache->Replace( id, value );
		}
		else {
			cache->Add( id, value );
		}
	}

	template <typename T>
	void ContentLoader::Collect ( bool replace, const String& id, T&& value, ResourceCache<String>* cache /* = null */ ) {
		if ( cache == null )
			return;

		if ( replace ) {
			cache->Replace( id, std::forward<T>( value ) );
		}
		else {
			cache->Add( id, std::forward<T>( value ) );
		}
	}

}}

#endif // FURROVINECONTENTLOADER_INL 