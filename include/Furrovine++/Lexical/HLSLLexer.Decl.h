#pragma once

#include <Furrovine++/Lexical/Lexer.h>
#include <Furrovine++/Lexical/HLSLLexerToken.h>

namespace Furrovine { namespace Lexical {

	class HLSLLexer : public Lexer<HLSLLexerToken, HLSLToken> {
	protected:
		bool alive, definealive;
		int technesting;

	public:

		furrovineapi HLSLLexer( );

	protected:

		furrovineapi virtual void PunctuatorTrigger( codepoint peek, codepoint prev, const HLSLToken& charactertoken, TLexerTokenList& tokenstream ) override;

		furrovineapi virtual void KeywordTrigger( codepoint peek, codepoint prev, String& trigger, const HLSLToken& keywordtoken, TLexerTokenList& tokenstream ) override;

		furrovineapi virtual bool LexLoop( IO::TextReader& reader, codepoint peek, codepoint prev, TLexerTokenList& tokenstream ) override;

	};

}}

