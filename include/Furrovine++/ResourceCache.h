#pragma once

#include <Furrovine++/std_defines.h>
#include <unordered_map>
#include <vector>
#include <Furrovine++/ptr.h>
#include <Furrovine++/Collections/Dictionary.h>
#include <Furrovine++/tagged_item.h>

namespace Furrovine {
	
	template <typename key_type = Furrovine::String>
	class ResourceCache {
	public:
		typedef key_type TKey;

	private:
		struct ResourceBase { 

			virtual ~ResourceBase() {

			}

		};

		template < typename T, typename TDx = std::default_delete<T> > 
		struct ResourceHolder : public ResourceBase {
			ptr<T, TDx> resource;

			ResourceHolder( ) : resource( null ) {

			}

			ResourceHolder( T resource ) : resource( std::move( resource ) ) {

			}

			ResourceHolder( T&& res ) : resource( std::move( res ) ) {

			}

			ResourceHolder( T* res ) : resource( res ) {

			}

			ResourceHolder( T* res, const TDx& deleter ) : resource( res, deleter ) {

			}

			ResourceHolder( T* res, TDx&& deleter ) : resource( res, deleter ) {

			}

			ResourceHolder( ptr<T, TDx> res ) : resource( std::move( res ) ) {

			}
		};

		std::unordered_map<TKey, ptr<ResourceBase>> resources;
		
	public:
		template <typename T, typename TDx>
		void Add ( const TKey& key, std::unique_ptr<T, TDx> value ) {
			Add<T, TDx>( key, value.release(), value.get_deleter() );
		}

		template <typename T, typename TDx>
		void Add ( const TKey& key, ptr<T, TDx> value ) {
			Add<T, TDx>( key, value.release(), value.get_deleter() );
		}
		
		template <typename T, typename TDx = std::default_delete<T>>
		void Add ( const TKey& key, T* value, TDx deleter = TDx() ) {
			if ( value == null )
				return;

			auto index = resources.find( key );
			if ( index != resources.end() )
				throw Exception( Format( "Key \"{0}\" already exists in the cache", key ) );

			resources.insert( std::make_pair( key, new ResourceHolder<T, TDx>( value, std::forward<TDx>( deleter ) ) ) );
		}

		template <typename T, typename TDx>
		bool TryAdd ( const TKey& key, std::unique_ptr<T, TDx> value ) {
			return TryAdd<T, TDx>( key, value.release(), value.get_deleter() );
		}

		template <typename T, typename TDx>
		bool TryAdd ( const TKey& key, ptr<T, TDx> value ) {
			return TryAdd<T, TDx>( key, value.release(), value.get_deleter() );
		}

		template <typename T, typename TDx = std::default_delete<T>> 
		bool TryAdd ( const TKey& key, T* value, TDx deleter = TDx() ) {
			if ( value == null )
				return false;

			auto index = resources.find( key );
			if ( index != resources.end() )
				return false;

			resources.insert( std::make_pair( key, new ResourceHolder<T, TDx>( value, std::forward<TDx>( deleter ) ) ) );

			return true;
		}

		template <typename T, typename TDx = std::default_delete<T>> 
		bool TryGet ( const TKey& id, T*& resource ) {
			auto index = resources.find( id );
			if ( index != resources.end() ) {
				ResourceHolder<T, TDx>* cacheholder = dynamic_cast<ResourceHolder<T, TDx>*>( index->second.get() );
				if ( cacheholder != null ) {
					resource = &(cacheholder->resource);
					return true;
				}
			}
			return false;
		}

		template <typename T, typename TDx = std::default_delete<T>> 
		T* TryGet ( const TKey& id ) {
			T* res = null;
			TryGet<T, TDx>( id, res );
			return res;
		}

		template <typename T, typename TDx = std::default_delete<T>> 
		T& Get ( const TKey& id ) {
			ResourceBase* base = null;
			ResourceHolder<T, TDx>* resourceholder = null;
			auto index = resources.find( id );
			furrovineassert( index != resources.end(), "Resource with specific id does not exist" );
			base = index->second.get();
			furrovineassert( base != null, "Resource for id is null" );
			resourceholder = dynamic_cast<ResourceHolder<T, TDx>*>( base );
			furrovineassert( resourceholder != null, "Resource is not of the specified type T" );
			return *(resourceholder->resource);
		}

		template <typename T, typename TDx = std::default_delete<T>> 
		T& At ( ulword index ) {
			ResourceHolder<T, TDx>* resourceholder = null;
			furrovineassert( index < resources.size(), "Index outside the resources bounds" );
			resourceholder = dynamic_cast<ResourceHolder<T, TDx>*>( index->second.get() );
			furrovineassert( resourceholder != null, "Resource is not of the specified type T" );
			return *(resourceholder->resource);
		}

		template <typename T>
		T& operator [] ( ulword index ) {
			return At<T>( index );
		}

		template <typename T>
		T& operator [] ( const TKey& id ) {
			return Get<T>( id );
		}

		template <typename T, typename TDx>
		T& operator [] ( tagged_item<ulword, T, TDx> req ) {
			return At<T>( req.element );
		}

		template <typename TId, typename T, typename TDx>
		T& operator [] ( tagged_item<TId, T, TDx> req ) {
			return Get<T>( req.element );
		}

		bool Remove ( const TKey& id ) {
			auto index = resources.find( id );
			if ( index == resources.end() )
				return false;

			index->second.reset( null );
			resources.erase( index );
			return true;
		}

		template <typename T, typename TDx>
		bool Replace ( const TKey& key, std::unique_ptr<T, TDx> value ) {
			T* p = value.release();
			return Replace<T, TDx>( key, p, value.get_deleter() );
		}

		template <typename T, typename TDx>
		bool Replace ( const TKey& key, ptr<T, TDx> value ) {
			T* p = value.release();
			return Replace<T, TDx>( key, p, value.get_deleter() );
		}

		template <typename T, typename TDx>
		bool Replace ( const TKey& key, T*& value, TDx deleter = TDx() ) {
			ResourceHolder<T>* resourceholder = null;
			if ( value == null )
				return false;

			auto index = resources.find( key );
			if ( index != resources.end() ) {
				ptr<ResourceBase>& resourcebase = index->second;
				resourceholder = dynamic_cast<ResourceHolder<T, TDx>*>( resourcebase.get() );
				if ( resourceholder == null || resourceholder->resource == null ) {
					resourcebase.reset( new ResourceHolder<T, TDx>( value, std::forward<TDx>( deleter ) ) );
				}
				else {
					*(resourceholder->resource) = std::move( *value );
					value = resourceholder->resource;
				}
				return true;
			}
			else {
				resources.insert( std::make_pair( key, new ResourceHolder<T, TDx>( value, std::forward<TDx>( deleter ) ) ) );
				return false;
			}
		}

		template <typename T>
		bool Replace ( const TKey& key, T*& value, T*& oldvalue ) {
			ResourceHolder<T>* resourceholder = null;
			if ( value == null )
				return false;

			auto index = resources.find( key );
			if ( index != resources.end() ) {
				ptr<ResourceBase>& resourcebase = index->second;
				resourceholder = dynamic_cast<ResourceHolder<T>*>( resourcebase.get() );
				if ( resourceholder == null || resourceholder->resource == null ) {
					oldvalue = null;
					resourcebase.reset( new ResourceHolder<T>( value ) );
				}
				else {
					oldvalue = new T( std::move( *resourceholder->resource ) );
					*(resourceholder->resource) = std::move( *value );
					value = resourceholder->resource;
				}
				return true;
			}
			else {
				resources.insert( std::make_pair( key, new ResourceHolder<T>( value ) ) );
				return false;
			}
		}
	};

}
