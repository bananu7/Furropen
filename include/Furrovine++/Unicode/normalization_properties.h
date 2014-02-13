#pragma once

#include <initializer_list>
#include <Furrovine++/perchance.h>
#include <Furrovine++/character_def.h>

namespace Furrovine { namespace Unicode {

	struct normalization_properties {
	public:
		std::initializer_list<const codepoint> as_nfkc_casefold;
		std::initializer_list<const codepoint> as_fc_nfkc_closure;
		perchance nfc_quick_check;
		perchance nfkc_quick_check;
		bool nfd_quick_check;
		bool nfkd_quick_check;
		bool expands_on_nfc;
		bool expands_on_nfd;
		bool expands_on_nfkc;
		bool expands_on_nfkd;
	};

}}