#pragma once

#include <Furrovine++/Export.h>
#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/fixed_vector.h>

namespace Furrovine { 
	
	struct Char {
	
		furrovineapi static bool IsUpper (codepoint c);

		furrovineapi static bool IsLower (codepoint c);

		furrovineapi static bool IsLetterOrDigit (codepoint c);

		furrovineapi static bool IsLetter (codepoint c);

		furrovineapi static bool IsDigit( codepoint c );

		furrovineapi static bool IsNumber( codepoint c );

		furrovineapi static codepoint_casing Casefold( codepoint c );
		
		furrovineapi static codepoint_casing ToUpper( codepoint c );

		furrovineapi static codepoint_casing ToLower( codepoint c );

		furrovineapi static codepoint_casing ToTitlecase( codepoint c );

		furrovineapi static bool TryCasefold( codepoint c, codepoint_casing& upper );

		furrovineapi static bool TryToUpper( codepoint c, codepoint_casing& upper );

		furrovineapi static bool TryToLower( codepoint c, codepoint_casing& lower );

		furrovineapi static bool TryToTitlecase( codepoint c, codepoint_casing& title );

		furrovineapi static bool IsAlphaNumeric( codepoint c );

		furrovineapi static bool IsWhiteSpace (codepoint c);

		furrovineapi static bool IsBlankSpace (codepoint c);

	};

	struct IsWhiteSpace {
		furrovineapi bool operator () ( codepoint c ) const;
	};
}
