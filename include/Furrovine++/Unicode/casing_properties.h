#pragma once

#include <initializer_list>
#include <Furrovine++/character_def.h>

namespace Furrovine { namespace Unicode {

	struct casing_properties {
	public:
		std::initializer_list<const codepoint> as_uppercase;
		std::initializer_list<const codepoint> as_lowercase;
		std::initializer_list<const codepoint> as_titlecase;
		std::initializer_list<const codepoint> as_casefold;
		codepoint simple_uppercase;
		codepoint simple_lowercase;
		codepoint simple_titlecase;
		codepoint simple_casefold;
		bool uppercase;
		bool lowercase;
		bool other_uppercase;
		bool other_lowercase;
		bool case_ignorable;
		bool cased;
		bool special_casefold;
		bool soft_dotted;
		bool changes_when_casefolded;
		bool changes_when_casemapped;
		bool changes_when_nfkc_casefolded;
		bool changes_when_titlecased;
		bool changes_when_uppercased;
		bool changes_when_lowercased;
		
	};

}}