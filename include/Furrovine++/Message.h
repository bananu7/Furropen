#pragma once

#include <Furrovine++/raw_storage.h>
#include <Furrovine++/MessageId.h>
#include <Furrovine++/MessageHeader.h>
#include <Furrovine++/MouseEvent.h>
#include <Furrovine++/KeyboardEvent.h>
#include <Furrovine++/WindowEvent.h>

namespace Furrovine {

	struct MessageData {	
		MessageHeader header;
		raw_storage<128> data;
		
		template <typename T>
		static ulword size_of( ) {
			return sizeof(MessageHeader)+sizeof( T );
		}

		template <typename T>
		Message<T> as( ) {
			static_assert( sizeof( Message<T> ) < sizeof( MessageData ), "Requested type has a size greater than possible" );
			return *reinterpret_cast<Message<T>*>( reinterpret_cast<byte*>( this ) );
		}
	};

	template <typename T>
	struct Message {
		static_assert( sizeof( T ) < 128, "Message type must be smaller than the size of Message Storage" );
		MessageHeader header;
		T item;

		template <typename... Tn>
		Message( MessageId id, Tn&&... argn ) : header( id ), item( std::forward<Tn>( argn )... ) {

		}

		template <typename... Tn>
		Message( uint32 id, Tn&&... argn ) : header( id ), item( std::forward<Tn>( argn ) ) {

		}

		operator T& ( ) {
			return item;
		}

		operator const T& ( ) const {
			return item;
		}
	};

}
