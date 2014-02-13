#pragma once

#include <Furrovine++/CallbackEventVariadic.h>
#include <Furrovine++/CallbackEvent0.h>
#include <Furrovine++/CallbackEvent1.h>
#include <Furrovine++/CallbackEvent2.h>
#include <Furrovine++/CallbackEvent3.h>
#include <Furrovine++/CallbackEvent4.h>

namespace Furrovine {

#ifdef FURROVINENOVARIADICS

	typedef CallbackEvent1<void> CallbackEvent0;
	typedef CallbackEvent1<void> CallbackEvent;

#endif // FURROVINENOVARIADICS 

}
