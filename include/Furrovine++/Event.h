#pragma once

#include <Furrovine++/EventVariadic.h>
#ifdef FURROVINENOVARIADICS
#include <Furrovine++/Event0.h>
#include <Furrovine++/Event1.h>
#include <Furrovine++/Event2.h>
#include <Furrovine++/Event3.h>
#include <Furrovine++/Event4.h>
#endif // FURROVINENOVARIADICS

namespace Furrovine {

#ifdef FURROVINENOVARIADICS

	typedef Event1<void> Event0;
	typedef Event1<void> Event;

#endif // FURROVINENOVARIADICS 

}
