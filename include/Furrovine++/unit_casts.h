#ifndef FURROVINEUNIT_CASTS_H
#define FURROVINEUNIT_CASTS_H

namespace Furrovine {

	template<typename T>
	static T as_radians ( T degrees ) {
		return (T)(degrees * 0.0174532925);
	}

	template<typename T>
	static T as_degrees ( T radians ) {
		return (T)(radians * 57.2957795);
	}

	template<typename T>
	static T radians_as_turns ( T radians ) {
		return (T)( radians / Mathema<T>::TwoPi );
	}

	template<typename T>
	static T degrees_as_turns ( T degrees ) {
		return (T)( degrees * ( 1.0 / 360.0 ) );
	}

}

#endif // FURROVINEUNIT_CASTS_H 