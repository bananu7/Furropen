#pragma once

#include <Furrovine++/Text/CharacterRange.h>

namespace Furrovine { namespace Text {

	template <typename TString>
	TString CharacterRange::GetCodepoints( codepoint inbetween ) const {
		TString s( Last - First );
		for ( codepoint c = First; c < Last; ++c ) {
			s.Append( c );
			s.Append( inbetween );
		}
		s.Append( Last );
		return s;
	}

	template <typename T>
	void CharacterRange::AppendCodepoints( T& appendable, codepoint inbetween ) const {
		for ( codepoint c = First; c < Last; ++c ) {
			appendable.Append( c );
			appendable.Append( inbetween );
		}
		appendable.Append( Last );
	}

}}
