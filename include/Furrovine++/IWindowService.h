#pragma once

#include <Furrovine++/IService.h>
#include <Furrovine++/ServiceTracker.h>
#include <Furrovine++/IWindow.h>

namespace Furrovine {

	typedef IService<IWindow> IWindowService;
	typedef IService<IWindowDriver> IWindowDriverService;
	
}