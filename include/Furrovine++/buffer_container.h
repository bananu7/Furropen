#pragma once

#include <Furrovine++/buffer_view.h>
#include <Furrovine++/make_unique.h>

namespace Furrovine {

	template <typename T>
	class buffer_container {
	public:
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* pointer_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef pointer_type iterator;
		typedef const pointer_type const_iterator;

	private:
		struct storage_t {
			virtual std::unique_ptr<storage_t> copy( ) = 0;

			virtual T* data( ) { return nullptr; }
			virtual const T* data( ) const { return nullptr; }
			virtual std::size_t size( ) const { return 0; }

			virtual ~storage_t( ) {}
		};

		template <typename TCont>
		struct basic_storage_t : public storage_t {
			TCont cont;

			template <typename... Tn>
			basic_storage_t( Tn&&... argn ) : cont( std::forward<Tn>( argn )... ) {

			}

			virtual T* data( ) override {
				return cont.data( );
			}

			virtual const T* data( ) const override {
				return cont.data( );
			}

			virtual std::size_t size( ) const override {
				return cont.size( );
			}

			virtual std::unique_ptr<storage_t> copy( ) override {
				return Furrovine::make_unique<basic_storage_t>( cont );
			}
		};

		std::unique_ptr<storage_t> storage;
		buffer_view<T> view;

		template <typename TCont>
		std::unique_ptr<storage_t> make_storage( TCont&& container ) {
			typedef std::decay<TCont>::type TDecayedCont;
			return Furrovine::make_unique<basic_storage_t<TDecayedCont>>( std::forward<TCont>( container ) );
		}

	public:
		buffer_container( ) : storage( nullptr ), view( nullptr ) {

		}

		template <typename TCont>
		buffer_container( TCont&& cont ) : storage( make_storage( std::forward<TCont>( cont ) ) ), view( storage->data(), storage->size() ) {

		}

		buffer_container( buffer_container&& mov ) : storage( std::move( mov.storage ) ), view( std::move( mov.view ) ) {

		}

		buffer_container& operator=( buffer_container&& mov ) {
			storage = std::move( mov.storage );
			view = std::move( mov.view );
			return *this;
		}

		buffer_container( const buffer_container& copy ) {
			if ( copy.storage != nullptr ) {
				storage = copy.storage->copy( );
				view = *storage.get( );
			}
			else {
				storage.reset( nullptr );
				view = nullptr;
			}
		}

		buffer_container& operator=( const buffer_container& copy ) {
			if ( copy.storage != nullptr ) {
				storage = copy.storage->copy( );
				view = *storage.get( );
			}
			else {
				storage.reset( nullptr );
				view = nullptr;
			}
			return *this;
		}
		
		bool is_null( ) const {
			return view.is_null();
		}

		bool empty( ) const {
			return view.empty();
		}

		bool not_empty( ) const {
			return view.not_empty();
		}

		T* begin( ) {
			return view.begin();
		}

		T* end( ) {
			return view.end();
		}

		const T* begin( ) const {
			return view.begin();
		}

		const T* end( ) const {
			return view.end();
		}

		const T* cbegin( ) {
			return view.cbegin();
		}

		const T* cend( ) {
			return view.cend();
		}

		const T* cbegin( ) const {
			return view.cbegin();
		}

		const T* cend( ) const {
			return view.cend();
		}

		T& operator[] ( std::size_t i ) {
			return view[ i ];
		}

		const T& operator[] ( std::size_t i ) const {
			return view[ i ];
		}

		T* data( ) {
			return view.data();
		}

		const T* data( ) const {
			return view.data();
		}

		reference front( ) {
			return view.front();
		}

		reference back( ) {
			return view.back();
		}

		const_reference front( ) const {
			return view.front();
		}

		const_reference back( ) const {
			return view.back();
		}

		std::size_t size( ) const {
			return view.size();
		}
	};

}
