#pragma once

#include <Furrovine++/Declarations.h>
#include <Furrovine++/numeric_integer_def.h>
#include <Furrovine++/uninitialized_allocator.h>
#include <Furrovine++/Export.h>
#include <Furrovine++/buffer_view.h>
#include <Furrovine++/optional.h>
#include <vector>
#include <list>

namespace Furrovine {

	class MessageQueue {
	private:
		typedef std::pair<std::size_t, std::size_t> message_index;
		std::vector<byte, uninitialized_allocator<byte>> messagedata;
		std::list<message_index> freemessages;
		std::list<message_index> messages;

		furrovineapi void push( const MessageHeader& header, const void* data, ulword datasize );
	
		furrovineapi buffer_view<byte> emplace( ulword bytesize );

	public:

		furrovineapi MessageQueue( );

		template <typename T, typename... Tn>
		Message<T>& emplace( Tn&&... argn );

		template <typename T>
		void push( const Message<T>& item );

		template <typename T>
		void push( const MessageHeader& header, const T& item );

		furrovineapi ulword size( ) const;

		furrovineapi bool empty( ) const;

		furrovineapi bool pop( MessageData& msg );

		furrovineapi optional<MessageData> pop( );

	};

}
