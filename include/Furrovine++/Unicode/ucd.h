#pragma once

#include <exception>
#include <Furrovine++/UnicodeExport.h>
#include <Furrovine++/character_def.h>
#include <Furrovine++/buffer_view.h>
#include <Furrovine++/Unicode/block.h>
#include <Furrovine++/Unicode/cjk_radical.h>
#include <Furrovine++/Unicode/emoji_source.h>
#include <Furrovine++/Unicode/named_sequence.h>
#include <Furrovine++/Unicode/normalization_correction.h>
#include <Furrovine++/Unicode/standardized_variant.h>
#include <Furrovine++/Unicode/codepoint_properties.h>
#include <Furrovine++/Unicode/ucd_group.h>

namespace Furrovine { namespace Unicode {
	
	struct ucd {
	public:
		furrovineunicodeapi static const codepoint SubstitutionCodepoint = 4294967295;

		furrovineunicodeapi static const buffer_view<const block> blocks;
		furrovineunicodeapi static const buffer_view<const cjk_radical> cjk_radicals;
		furrovineunicodeapi static const buffer_view<const normalization_correction> normalization_corrections;
		furrovineunicodeapi static const buffer_view<const named_sequence> named_sequences;
		furrovineunicodeapi static const buffer_view<const standardized_variant> standardized_variants;
		furrovineunicodeapi static const buffer_view<const emoji_source> emoji_sources;
		
		furrovineunicodeapi static const buffer_view<const ucd_group<name_properties>> names;
		furrovineunicodeapi static const buffer_view<const ucd_group<iso_properties>> isos;
		furrovineunicodeapi static const buffer_view<const ucd_group<jamo_short_name_properties>> jamo_short_names;
		furrovineunicodeapi static const buffer_view<const ucd_group<alias_properties>> aliases;
		furrovineunicodeapi static const buffer_view<const ucd_group<script_properties>> scripts;
		furrovineunicodeapi static const buffer_view<const ucd_group<basic_properties>> basics;
		furrovineunicodeapi static const buffer_view<const ucd_group<bidirectional_properties>> bidirectionals;
		furrovineunicodeapi static const buffer_view<const ucd_group<boundary_properties>> boundaries;
		furrovineunicodeapi static const buffer_view<const ucd_group<casing_properties>> casings;
		furrovineunicodeapi static const buffer_view<const ucd_group<composition_properties>> compositions;
		furrovineunicodeapi static const buffer_view<const ucd_group<general_properties>> generals;
		furrovineunicodeapi static const buffer_view<const ucd_group<normalization_properties>> normalizations;

		furrovineunicodeapi static const buffer_view<const ucd_group<unihan_dictionary_properties>> unihan_dictionaries;
		furrovineunicodeapi static const buffer_view<const ucd_group<unihan_index_properties>> unihan_indices;
		furrovineunicodeapi static const buffer_view<const ucd_group<unihan_irg_properties>> unihan_irgs;
		furrovineunicodeapi static const buffer_view<const ucd_group<unihan_mapping_properties>> unihan_mappings;
		furrovineunicodeapi static const buffer_view<const ucd_group<unihan_numeric_properties>> unihan_numerics;
		furrovineunicodeapi static const buffer_view<const ucd_group<unihan_reading_properties>> unihan_readings;
		furrovineunicodeapi static const buffer_view<const ucd_group<unihan_stroke_properties>> unihan_strokes;
		furrovineunicodeapi static const buffer_view<const ucd_group<unihan_variant_properties>> unihan_variants;

		furrovineunicodeapi static const name_properties& name_properties_of( codepoint c );
		furrovineunicodeapi static const iso_properties& iso_properties_of( codepoint c );
		furrovineunicodeapi static const jamo_short_name_properties& jamo_short_name_properties_of( codepoint c );
		furrovineunicodeapi static const alias_properties& alias_properties_of( codepoint c );
		furrovineunicodeapi static const script_properties& script_properties_of( codepoint c );
		furrovineunicodeapi static const basic_properties& basic_properties_of( codepoint c );
		furrovineunicodeapi static const bidirectional_properties& bidirectional_properties_of( codepoint c );
		furrovineunicodeapi static const boundary_properties& boundary_properties_of( codepoint c );
		furrovineunicodeapi static const casing_properties& casing_properties_of( codepoint c );
		furrovineunicodeapi static const composition_properties& composition_properties_of( codepoint c );
		furrovineunicodeapi static const general_properties& general_properties_of( codepoint c );
		furrovineunicodeapi static const normalization_properties& normalization_properties_of( codepoint c );
		furrovineunicodeapi static const unihan_dictionary_properties& unihan_dictionary_properties_of( codepoint c );
		furrovineunicodeapi static const unihan_index_properties& unihan_index_properties_of( codepoint c );
		furrovineunicodeapi static const unihan_irg_properties& unihan_irg_properties_of( codepoint c );
		furrovineunicodeapi static const unihan_mapping_properties& unihan_mapping_properties_of( codepoint c );
		furrovineunicodeapi static const unihan_numeric_properties& unihan_numeric_properties_of( codepoint c );
		furrovineunicodeapi static const unihan_reading_properties& unihan_reading_properties_of( codepoint c );
		furrovineunicodeapi static const unihan_stroke_properties& unihan_stroke_properties_of( codepoint c );
		furrovineunicodeapi static const unihan_variant_properties& unihan_variant_properties_of( codepoint c );

		furrovineunicodeapi static codepoint_properties properties_of( codepoint c );
		furrovineunicodeapi static void properties_of( codepoint c, codepoint_properties& properties );

	};

}}