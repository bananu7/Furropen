#pragma once

#include <Furrovine++/MessageQueue.h>

namespace Furrovine {

	template <typename T, typename... Tn>
	Message<T>& MessageQueue::emplace( Tn&&... argn ) {
		buffer_view<byte> data = emplace( sizeof( Message<T> ) );
		new ( data.data( ) ) Message<T>( std::forward<Tn>( argn )... );
		return *reinterpret_cast<Message<T>*>( data.data() );
	}

	template <typename T>
	void MessageQueue::push( const Message<T>& item ) {
		push( item.header, item.item );
	}

	template <typename T>
	void MessageQueue::push( const MessageHeader& header, const T& item ) {
		push( header, std::addressof( item ), sizeof( item ) );
	}

}