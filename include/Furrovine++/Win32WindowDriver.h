#pragma once

#include <Furrovine++/MessageQueue.h>
#include <Furrovine++/IWindowDriver.h>
#include <Furrovine++/WindowDriverFlags.h>
#include <Furrovine++/any.h>
#include <Furrovine++/uninitialized_allocator.h>
#include <vector>

namespace Furrovine {

	class Win32WindowDriver : public IWindowDriver { 
	private:
		std::vector<byte, uninitialized_allocator<byte>> rawinputbuffer;
		MessageQueue* messages;
		void* imecontext;
		uint32 borderlessresizewidth;
		uint32 borderlessmovewidth;
		WindowDriverFlags driverflags;

		furrovineapi void read_raw_input( void*, void* );
		furrovineapi void OnMessage( const MessageData& data );
	public: 

		furrovineapi Win32WindowDriver( WindowDriverFlags windowdriverflags = WindowDriverFlags::Default, uint32 windowborderlessresizewidth = 4, uint32 windowmovableborder = 4 );

		furrovineapi virtual void Process( any& data ) override;
		furrovineapi virtual void Push( IWindow& iwindow, MessageQueue& messagequeue ) override;
		furrovineapi virtual WindowDriverFlags GetWindowDriverFlags( ) const override;
	};

}
