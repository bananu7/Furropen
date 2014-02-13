#pragma once

#include <cstddef>
#include <memory>
#include <initializer_list>

namespace Furrovine {

	namespace detail {
		template <typename T>
		auto get_data( std::initializer_list<T>& cont ) -> decltype( cont.begin( ) ) {
			return cont.begin( );
		}

		template <typename T>
		auto get_data( std::initializer_list<T>&& cont ) -> decltype( cont.begin( ) ) {
			return cont.begin( );
		}

		template <typename T>
		auto get_data( std::initializer_list<T> cont ) -> decltype( cont.begin( ) ) {
			return cont.begin( );
		}

		template <typename T>
		auto get_data( std::false_type, T&& cont ) -> decltype( cont.data( ) ) {
			return cont.data( );
		}

		template <typename T>
		auto get_size( std::false_type, T&& cont ) -> decltype( cont.size( ) ) {
			return cont.size( );
		}

		template <typename T, std::size_t n>
		T* get_data( std::true_type, T( &cont )[ n ] ) {
			return std::addressof( cont[ 0 ] );
		}

		template <typename T, std::size_t n>
		std::size_t get_size( std::true_type, T( &cont )[ n ] ) {
			return n;
		}

		inline std::nullptr_t get_data( std::nullptr_t ) {
			return nullptr;
		}

		inline std::size_t get_size( std::nullptr_t ) {
			return 0;
		}

		template <typename T>
		auto get_data( T&& cont ) -> decltype( get_data( std::is_array<T>( ), std::forward<T>( cont ) ) ) {
			return get_data( std::is_array<T>(), std::forward<T>( cont ) );
		}

		template <typename T>
		auto get_size( T&& cont ) -> decltype( get_size( std::is_array<T>( ), std::forward<T>( cont ) ) ) {
			return get_size( std::is_array<T>( ), std::forward<T>( cont ) );
		}
	}

	template <typename T>
	class buffer_view {
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
		T* res;
		std::size_t sz;

	public:

		buffer_view( ) : res( nullptr ), sz( 0 ) {

		}

		buffer_view( T* buffer, std::size_t n )
			: res( buffer ), sz( n ) {

		}

		template<std::size_t n>
		buffer_view( T( &array )[ n ] ) : buffer_view( std::addressof( array[ 0 ] ), n ) {

		}

		template <typename TContainer>
		buffer_view( TContainer&& container ) : buffer_view( detail::get_data( container ), detail::get_size( container ) ) {

		}

		bool is_null( ) const {
			return res == nullptr;
		}

		bool empty( ) const {
			return sz < 1;
		}

		bool not_empty( ) const {
			return sz > 0;
		}

		T* begin( ) {
			return res;
		}

		T* end( ) {
			return res + sz;
		}

		const T* begin( ) const {
			return res;
		}

		const T* end( ) const {
			return res + sz;
		}

		const T* cbegin( ) {
			return res;
		}

		const T* cend( ) {
			return res + sz;
		}

		const T* cbegin( ) const {
			return res;
		}

		const T* cend( ) const {
			return res + sz;
		}

		T& operator[] ( std::size_t i ) {
			return res[ i ];
		}

		const T& operator[] ( std::size_t i ) const {
			return res[ i ];
		}

		T* data( ) {
			return res;
		}

		const T* data( ) const {
			return res;
		}

		reference front( ) {
			return *res;
		}

		reference back( ) {
			return *( res + sz );
		}

		const_reference front( ) const {
			return *res;
		}

		const_reference back( ) const {
			return *( res + sz );
		}

		T*& data_ref( ) {
			return res;
		}

		const T*& data_ref( ) const {
			return res;
		}

		std::size_t& size_ref( ) {
			return sz;
		}

		const std::size_t& size_ref( ) const {
			return sz;
		}

		std::size_t size( ) const {
			return sz;
		}
	};

	template <>
	class buffer_view<void> {
	public:
		typedef void value_type;
		typedef void* pointer_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef pointer_type iterator;
		typedef const pointer_type const_iterator;

	private:
		void* res;
		std::size_t sz;

	public:

		buffer_view( ) : res( nullptr ), sz( 0 ) {

		}

		buffer_view( std::nullptr_t ) : res( nullptr ), sz( 0 ) {

		}

		buffer_view( void* buffer, std::size_t n )
			: res( buffer ), sz( n ) {

		}

		template <typename TContainer>
		buffer_view( TContainer&& container ) : buffer_view( detail::get_data( container ), detail::get_size( container ) ) {

		}

		bool is_null( ) const {
			return res == nullptr;
		}

		bool empty( ) const {
			return sz < 1;
		}

		bool not_empty( ) const {
			return sz > 0;
		}

		void* begin( ) {
			return res;
		}

		void* end( ) {
			return static_cast<void*>( static_cast<char*>( res ) + sz );
		}

		const void* begin( ) const {
			return res;
		}

		const void* end( ) const {
			return static_cast<void*>( static_cast<char*>( res ) + sz );
		}

		const void* cbegin( ) {
			return begin();
		}

		const void* cend( ) {
			return end();
		}

		const void* cbegin( ) const {
			return begin();
		}

		const void* cend( ) const {
			return end();
		}

		void* data( ) {
			return res;
		}

		const void* data( ) const {
			return res;
		}

		void*& data_ref( ) {
			return res;
		}

		const void* const& data_ref( ) const {
			return res;
		}

		std::size_t& size_ref( ) {
			return sz;
		}

		const std::size_t& size_ref( ) const {
			return sz;
		}

		std::size_t size( ) const {
			return sz;
		}
	};

	template <typename T>
	buffer_view<T> make_buffer_view( T* buffer, std::size_t n ) {
		return buffer_view<T>( buffer, n );
	}

	template <typename T>
	buffer_view<T> make_buffer_view( const T* buffer, std::size_t n ) {
		return buffer_view<T>( const_cast<T*>( buffer ), n );
	}

	template <typename T, std::size_t n>
	buffer_view<T> make_buffer_view( T( &container )[ n ] ) {
		return make_buffer_view( container, n );
	}

	template <typename TContainer>
	auto make_buffer_view ( TContainer& container ) -> decltype( make_buffer_view( container.data( ), container.size( ) ) ) {
		return make_buffer_view( container.data(), container.size() );
	}

	template <typename TAs, typename T>
	buffer_view<TAs> make_buffer_view_as( T* buffer, std::size_t n ) {
		void* addr = buffer;
		return buffer_view<TAs>( static_cast<TAs*>( addr ), size_as<TAs, T>( n ) );
	}

	template <typename TAs, typename T, std::size_t n>
	auto make_buffer_view_as( T( &container )[ n ] ) -> decltype( make_buffer_view_as<TAs>( container, n ) ) {
		return make_buffer_view_as<TAs>( container, n );
	}

	template <typename TAs, typename TContainer>
	buffer_view<TAs> make_buffer_view_as ( TContainer& container ) {
		return make_buffer_view_as<TAs>( container.data( ), container.size( ) );
	}

	template <typename T, std::size_t n>
	buffer_view<T> view ( T(& container)[n] ) {
		return make_buffer_view( container );
	}

	template <typename TContainer>
	auto view ( TContainer& container ) -> decltype( make_buffer_view( container ) ) {
		return make_buffer_view( container );
	}

	template <typename TAs, typename T, std::size_t n>
	buffer_view<TAs> view_as ( T(& container)[n] ) {
		return make_buffer_view_as<TAs>( container );
	}

	template <typename TAs, typename TContainer>
	buffer_view<TAs> view_as ( TContainer& container ) {
		return make_buffer_view_as<TAs>( container );
	}

}
 