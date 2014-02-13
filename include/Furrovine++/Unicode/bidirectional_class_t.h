#pragma once

namespace Furrovine { namespace Unicode {

	enum class bidirectional_class_t : unsigned char {
		L,
		R,
		AL,
		EN,
		ES,
		ET,
		AN,
		CS,
		NSM,
		BN,
		B,
		S,
		WS,
		ON,
		LRE,
		LRO,
		RLE,
		RLO,
		PDF,
		LRI,
		RLI,
		FSI,
		PDI
	};

}}