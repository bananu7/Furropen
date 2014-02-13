#pragma once

#include <Furrovine++/any.h>

namespace Furrovine {

	template <typename T, typename... Tn>
	T* make_copy( std::true_type, Tn&&... argn ) {
		return new T( std::forward<Tn>( argn )... );
	}

	template <typename T, typename... Tn>
	T* make_copy( std::false_type, Tn&&... argn ) {
		throw std::runtime_error( "Cannot make a copy of this type" );
	}

	template <typename T>
	template <typename ...Tn>
	any::typed_any_storage<T>::typed_any_storage( Tn&&... argn ) : item( std::forward<Tn>( argn )... ) {

	}

	template <typename T>
	void* any::typed_any_storage<T>::data( ) {
		return std::addressof( item );
	}

	template <typename T>
	const void* any::typed_any_storage<T>::data( ) const {
		return std::addressof( item );
	}

	template <typename T>
	void any::typed_any_storage<T>::cast( ) {
		throw std::addressof( item );
	}

	template <typename T>
	void any::typed_any_storage<T>::cast( ) const {
		throw std::addressof( item );
	}

	template <typename T>
	any::any_storage* any::typed_any_storage<T>::copy( ) {
		return make_copy<typed_any_storage>( std::has_copy_constructor<T>(), item );
	}

	template <typename T>
	any::typed_any_storage<T>::~typed_any_storage( ) {

	}

	template <typename T, typename TAlloc>
	template <typename... Tn>
	any::typed_allocated_any_storage<T, TAlloc>::typed_allocated_any_storage( Tn&&... argn ) : allocator( TAlloc( ) ), item( allocator.allocate( 1 ), allocator_deleter<TAlloc>( allocator ) ) {
		allocator.construct( item.get( ), std::forward<Tn>( argn )... );
	}

	template <typename T, typename TAlloc>
	template <typename TAl, typename... Tn>
	any::typed_allocated_any_storage<T, TAlloc>::typed_allocated_any_storage( std::allocator_arg_t, TAl&& alloc, Tn&&... argn ) : allocator( std::forward<TAl>( alloc ) ), item( allocator.allocate( 1 ), allocator ) {
		allocator.construct( item.get( ), std::forward<Tn>( argn )... );
	}

	template <typename T, typename TAlloc>
	void* any::typed_allocated_any_storage<T, TAlloc>::data( ) {
		return item.get( );
	}

	template <typename T, typename TAlloc>
	const void* any::typed_allocated_any_storage<T, TAlloc>::data( ) const {
		return item.get( );
	}

	template <typename T, typename TAlloc>
	void any::typed_allocated_any_storage<T, TAlloc>::cast( ) {
		throw item.get( );
	}

	template <typename T, typename TAlloc>
	void any::typed_allocated_any_storage<T, TAlloc>::cast( ) const {
		throw item.get( );
	}

	template <typename T, typename TAlloc>
	any::any_storage* any::typed_allocated_any_storage<T, TAlloc>::copy( ) {
		return make_copy<typed_allocated_any_storage>( std::has_copy_constructor<T>(), *( item.get() ) );
	}

	template <typename T, typename TAlloc>
	any::typed_allocated_any_storage<T, TAlloc>::~typed_allocated_any_storage( ) {

	}

	template <typename T, typename TConcept>
	any::any ( T&& value ) : rtt(null), storage(null) {
		place<TConcept>( std::forward<TConcept>( value ) );
	}

	template <typename T, typename TAl>
	any::any( std::allocator_arg_t, TAl&& alloc, T&& value ) : rtt( typeof<void>( ) ), storage( null ) {
		place<T, TAlloc>( std::allocator_arg, std::forward<TAl>( alloc ), std::forward<T>( value ) );
	}

	template <typename T, typename ...Tn>
	any::any ( in_place_of<T>, Tn&&... argn ) : rtt(typeof<void>()), storage(null) {
		place<T>( std::forward<Tn>( argn )... );
	}

	template <typename T, typename TAlloc, typename ...Tn>
	any::any ( in_place_of<T>, std::allocator_arg_t allocarg, TAlloc&& alloc, Tn&&... argn ) : rtt(null), storage(null) {
		place<T, TAlloc>( allocarg, std::forward<TAlloc>( alloc ), std::forward<Tn>( argn )... );
	}

	template <typename T>
	any& any::operator= ( T&& value ) {
		set( std::forward<T>( value ) );
		return *this;
	}

	template <typename T, typename... Tn>
	void any::place( Tn&&... argn ) {
		rtt = typeof<T>( );
		storage.reset( new typed_any_storage<T>( std::forward<Tn>( argn )... ) );
	}

	template <typename T, typename TAl, typename... Tn>
	void any::place( std::allocator_arg_t allocarg, TAl&& alloc, Tn&&... argn ) {
		rtt = typeof<T>( );
		storage.reset( new typed_allocated_any_storage<T, TAl>( std::forward<TAl>( alloc ), std::forward<Tn>( argn )... ) );
	}

	template <typename T, typename ...Tn>
	void any::set ( Tn&&... argn ) {
		if ( rtt != typeid( void ) )
			destroy();
		place<T>( std::forward<Tn>( argn )... );
	}

	template <typename T, typename TAl, typename ...Tn>
	void any::set ( std::allocator_arg_t allocarg, TAl&& alloc, Tn&&... argn ) {
		if ( rtt != typeid( void ) )
			destroy( );
		place<T, TAlloc>( std::allocator_arg, std::forward<TAl>( alloc ), std::forward<Tn>( argn )... );
	}

	template <typename T>
	bool any::is () const {
		if ( typeid(T) != rtt )
			return false;
		return true;
	}

	template <typename T>
	typename std::decay<T>::type& any::as() {
		typedef typename std::decay<T>::type* pointer;
		typedef typename std::add_const<typename std::decay<T>::type>::type* const_pointer;
		try {
			storage->cast( );
		}
		catch ( pointer e ) {
			return *e;
		}
		catch ( ... ) {
			
		}
		throw std::bad_cast( "any: bad cast" );
	}

	template <typename T>
	const typename std::decay<T>::type& any::as() const {
		typedef typename std::decay<T>::type* pointer;
		typedef typename std::add_const<pointer>::type* const_pointer;
		try {
			storage->cast( );
		}
		catch ( const_pointer e ) {
			return *e;
		}
		catch ( ... ) {
			
		}
		throw std::bad_cast( "any: bad cast" );
	}

	template <typename T>
	typename std::decay<T>::type& any::unsafe_as() {
		typedef typename std::decay<T>::type* pointer;
		return *static_cast<pointer>( storage->data( ) );
	}

	template <typename T>
	const typename std::decay<T>::type& any::unsafe_as() const {
		typedef typename std::decay<T>::type* pointer;
		typedef typename std::add_const<pointer>::type const_pointer;
		return *static_cast<pointer>( storage->data( ) );
	}

}
