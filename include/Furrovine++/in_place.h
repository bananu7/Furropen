#pragma once

struct in_place_t {};
const auto in_place = in_place_t( );

template <typename T>
struct in_place_of {
	typedef T type;
};
