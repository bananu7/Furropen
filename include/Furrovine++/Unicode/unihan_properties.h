#pragma once

#include <Furrovine++/Unicode/unihan_dictionary_properties.h>
#include <Furrovine++/Unicode/unihan_index_properties.h>
#include <Furrovine++/Unicode/unihan_irg_properties.h>
#include <Furrovine++/Unicode/unihan_mapping_properties.h>
#include <Furrovine++/Unicode/unihan_numeric_properties.h>
#include <Furrovine++/Unicode/unihan_reading_properties.h>
#include <Furrovine++/Unicode/unihan_stroke_properties.h>
#include <Furrovine++/Unicode/unihan_variant_properties.h>

namespace Furrovine { namespace Unicode {

	struct unihan_properties {
	public:
		unihan_dictionary_properties* dictionary;
		unihan_index_properties* dictionay_index;
		unihan_irg_properties* irg;
		unihan_mapping_properties* mapping;
		unihan_numeric_properties* numeric;
		unihan_reading_properties* reading;
		unihan_stroke_properties* stroke;
		unihan_variant_properties* variant;

	};

}}