#pragma once

namespace Furrovine { namespace Unicode {

	enum class indic_matra_category : unsigned char {
		Right,
		Left,
		Visual_Order_Left,
		Left_And_Right,
		Top,
		Bottom,
		Top_And_Bottom,
		Top_And_Right,
		Top_And_Left,
		Top_And_Left_And_Right,
		Bottom_And_Right,
		Top_And_Bottom_And_Right,
		Overstruck,
		Invisible,
		NA,
	};

}}