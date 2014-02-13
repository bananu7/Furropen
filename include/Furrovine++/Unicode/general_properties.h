#pragma once

#include <Furrovine++/buffer_view.h>
#include <Furrovine++/Unicode/general_category.h>
#include <Furrovine++/Unicode/numeric.h>
#include <Furrovine++/Unicode/numeric_t.h>
#include <Furrovine++/Unicode/script_t.h>
#include <Furrovine++/Unicode/hangul_syllable_type.h>
#include <Furrovine++/Unicode/indic_syllabic_category.h>
#include <Furrovine++/Unicode/indic_matra_category.h>
#include <Furrovine++/Unicode/unicode_age.h>
#include <Furrovine++/Unicode/block_t.h>

namespace Furrovine { namespace Unicode {

	struct general_properties {
	public:
		int canonical_combining_class;
		general_category general;
		numeric numeric_value;
		numeric_t numeric_type;
		hangul_syllable_type hangul_syllable;
		indic_syllabic_category indic_syllabic;
		indic_matra_category indic_matra;
		unicode_age age;
		block_t block;
	};

}}