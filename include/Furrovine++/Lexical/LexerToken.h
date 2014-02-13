#pragma once

namespace Furrovine { namespace Lexical {

	template <typename T, typename V> 
	struct LexerToken {
	public:
		typedef T TToken;
		typedef V TValue;

		TValue Value;
		TToken Token;
		int Index;

		LexerToken ( ) : Index( -1 ) {

		}

		LexerToken ( TToken token ) : Index( -1 ), Token( token ) {

		}

		LexerToken ( int index, TToken token ) : Index( index ), Token(token) {

		}

		LexerToken ( int index, TToken token, TValue value ) : Index( index ), Token( token ), Value( value ) {

		}

	};
	
}}
 