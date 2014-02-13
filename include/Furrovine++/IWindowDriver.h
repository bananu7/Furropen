#pragma once

#include <Furrovine++/Declarations.h>
#include <Furrovine++/Message.h>
#include <Furrovine++/any.h>
#include <Furrovine++/Event.h>
#include <Furrovine++/WindowDriverFlags.h>

namespace Furrovine {

	struct IWindowDriver {
	public:

		Event<const MessageData&> MessageCreated;

		virtual void Process( any& data ) = 0;
		virtual void Push( IWindow& iwindow, MessageQueue& queue ) = 0;
		virtual WindowDriverFlags GetWindowDriverFlags( ) const = 0;
	};

}