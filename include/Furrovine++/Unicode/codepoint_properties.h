#pragma once

#include <Furrovine++/Unicode/name_properties.h>
#include <Furrovine++/Unicode/iso_properties.h>
#include <Furrovine++/Unicode/jamo_short_name_properties.h>
#include <Furrovine++/Unicode/script_properties.h>
#include <Furrovine++/Unicode/alias_properties.h>
#include <Furrovine++/Unicode/basic_properties.h>
#include <Furrovine++/Unicode/general_properties.h>
#include <Furrovine++/Unicode/casing_properties.h>
#include <Furrovine++/Unicode/boundary_properties.h>
#include <Furrovine++/Unicode/bidirectional_properties.h>
#include <Furrovine++/Unicode/normalization_properties.h>
#include <Furrovine++/Unicode/composition_properties.h>
#include <Furrovine++/Unicode/unihan_properties.h>

namespace Furrovine { namespace Unicode {

	struct codepoint_properties {
	public:
		const name_properties* name;
		const iso_properties* iso;
		const jamo_short_name_properties* jamo_short_name;
		const script_properties* script;
		const alias_properties* alias;
		const basic_properties* basic;
		const general_properties* general;
		const casing_properties* casing;
		const boundary_properties* boundary;
		const bidirectional_properties* bidirectional;
		const normalization_properties* normalization;
		const composition_properties* composition;
		unihan_properties unihan;
	};

	const unsigned int unihan_properties_size = sizeof( unihan_properties );
	const unsigned int normalization_properties_size = sizeof( normalization_properties );
	const unsigned int boundary_properties_size = sizeof( boundary_properties );
	const unsigned int bidirectional_properties_size = sizeof( bidirectional_properties );
	const unsigned int casing_properties_size = sizeof( casing_properties );
	const unsigned int general_properties_size = sizeof( general_properties );
	const unsigned int basic_properties_size = sizeof( basic_properties );
	const unsigned int composition_properties_size = sizeof( composition_properties );
	const unsigned int codepoint_properties_size = sizeof( codepoint_properties );

}}