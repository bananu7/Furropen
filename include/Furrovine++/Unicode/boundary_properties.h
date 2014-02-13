#pragma once

#include <Furrovine++/Unicode/line_break_t.h>
#include <Furrovine++/Unicode/grapheme_cluster_break_t.h>
#include <Furrovine++/Unicode/word_break_t.h>
#include <Furrovine++/Unicode/sentence_break_t.h>
#include <Furrovine++/Unicode/east_asian_width_t.h>
#include <Furrovine++/Unicode/joining_group_t.h>
#include <Furrovine++/Unicode/joining_type_t.h>

namespace Furrovine { namespace Unicode {

	struct boundary_properties {
	public:
		line_break_t line_break;
		grapheme_cluster_break_t grapheme_cluster_break;
		word_break_t word_break;
		sentence_break_t sentence_break;
		east_asian_width_t east_asian_width;
		joining_group_t joining_group;
		joining_type_t joining_type;
		bool join_control : 1;
		bool grapheme_base : 1;
		bool grapheme_extend : 1;
		bool other_grapheme_extend : 1;
		bool grapheme_link : 1;
		bool sentence_terminal : 1;
		
	};

}}