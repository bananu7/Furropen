#pragma once

namespace Furrovine { namespace Unicode {

	struct basic_properties {
	public:
		bool reserved;
		bool surrogate;
		bool deprecated;
		bool default_ignorable;
		bool other_default_ignorable;
		bool logical_order_exception;
		bool id_start;
		bool other_id_start;
		bool xid_start;
		bool id_continue;
		bool other_id_continue;
		bool xid_continue;
		bool pattern_syntax;
		bool pattern_whitespace;
		bool dash;
		bool hyphen;
		bool quotation_mark;
		bool terminal_punctuation;
		bool diacritic;
		bool extender;
		bool alphabetic;
		bool other_alphabetic;
		bool math;
		bool other_math;
		bool hex_digit;
		bool ascii_hex_digit;
		bool white_space;
		bool variation_selector;
		bool noncharacter;
		bool ideographic;
		bool unified_ideograph;
		bool ids_binary_operator;
		bool ids_trinary_operator;
		bool radical;
	};

}}