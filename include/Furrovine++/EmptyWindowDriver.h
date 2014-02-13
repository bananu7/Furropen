#pragma once

#include <Furrovine++/IWindowDriver.h>

namespace Furrovine {

	struct EmptyWindowDriver : public IWindowDriver {
		
		furrovineapi virtual void Process( any& data ) override;

		furrovineapi virtual void Push( IWindow& iwindow, MessageQueue& messagequeue ) override;

	};

}