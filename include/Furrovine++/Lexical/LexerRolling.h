#ifndef FURROVINELEXERROLLING_H
#define FURROVINELEXERROLLING_H

#include <Furrovine++/Strings.h>
#include <Furrovine++/Lexical/LexerCharFlag.h>


namespace Furrovine { namespace Lexical {
	
	struct LexerRolling {
	public:
		LexerCharFlag Flags;
		LexerCharFlag Start;
		String Buffer;

	};
	
}}

#endif // FURROVINELEXERROLLING_H 