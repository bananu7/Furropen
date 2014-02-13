#pragma once

#include <Furrovine++/FurrovineApi.h>
#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/Strings.h>
#include <array>

namespace Furrovine { namespace Text {

	struct CharacterRange {
		furrovineapi static const CharacterRange Ascii[ 1 ];
		furrovineapi static const CharacterRange Latin1[ 2 ];
		codepoint First;
		codepoint Last;

		furrovineapi CharacterRange( );

		furrovineapi CharacterRange( codepoint first, codepoint last );

		template <typename TString = String>
		TString GetCodepoints( codepoint inbetween = ' ' ) const;
		template <typename T>
		void AppendCodepoints( T& item, codepoint inbetween = ' ' ) const;
	};

}}
