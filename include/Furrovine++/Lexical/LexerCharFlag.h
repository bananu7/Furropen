#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Lexical {
	
	enum class LexerCharFlag {
		None = 0x00000000,
		Letter = 0x00000001,
		Punctuation = 0x00000002,
		Number = 0x00000004,
		Decimal = 0x00000008,
		Tab = 0x00000010,
		Space = 0x00000020,
		LineFeed = 0x00000040,
		CarriageReturn = 0x00000080,
		Whitespace = Tab | Space | CarriageReturn | LineFeed,
		DecimalNumber = Number | Decimal
	};

	enumflagoperators(LexerCharFlag);
	
}}
 