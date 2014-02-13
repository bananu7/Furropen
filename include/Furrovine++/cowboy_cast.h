#pragma once

#include <utility>

namespace Furrovine {

	///<summary>
	/// Only the baddest of any o' ya'll sugar cubes 
	/// can handle this here rootin' tootin' bad boy, Yeeeeeee haaaaaw!
	///</summary>
	template <typename TTo, typename T>
	TTo cowboy_cast ( const T& cow ) {
		union u {
			T hat;
			TTo boy;
		};
		return u(cow).boy;
	}

}
