#pragma once

#include <unordered_map>
#include <vector>
#include <Furrovine++/IO/TextReader.h>
#include <Furrovine++/Lexical/LexerToken.h>
#include <Furrovine++/Char.h>

namespace Furrovine { namespace Lexical {
	
	template <typename L, typename T = L> 
	class Lexer {
	public:
		typedef T TToken;
		typedef L TLexerToken;
		typedef std::vector<TLexerToken> TLexerTokenList;

	protected:
		int defaulttokenstreamsize;
		std::unordered_map<String, TToken> keywords;
		std::unordered_map<codepoint, TToken> punctuators;
		TToken lasttoken;
		String rolling, keyword;
		int index;
		bool skipwhitespace, clearrollingonwhitespace;

		virtual void KeywordTrigger ( codepoint peek, codepoint prev, String& trigger, const TToken& keywordtoken, TLexerTokenList& tokens ) {
			tokens.push_back( TLexerToken( keywordtoken ) );
			rolling.Clear();
			lasttoken = keywordtoken;
		}

		virtual void PunctuatorTrigger ( codepoint peek, codepoint prev, const TToken& charactertoken, TLexerTokenList& tokens ) {
			tokens.push_back( TLexerToken( charactertoken ) );
			rolling.Clear();
			lasttoken = charactertoken;
		}

		virtual bool LexLoop ( IO::TextReader& reader, codepoint peek, codepoint prev, TLexerTokenList& tokenstream ) {
			if ( Char::IsWhiteSpace( peek ) && skipwhitespace ) {
				reader.ReadChar();
				++index;
				if ( clearrollingonwhitespace ) {
					RollingClear( peek, prev, tokenstream );
				}
				return true;
			}
			RollingAppend( peek, prev, tokenstream );
			CheckPunctuators( peek, prev, tokenstream );
			CheckKeywords( peek, prev, tokenstream );
			reader.ReadChar();
			++index;
			return true;
		}

		virtual void RollingAppend ( codepoint peek, codepoint prev, TLexerTokenList& tokenstream ) {
			rolling += peek;
		}

		virtual void RollingClear ( codepoint peek, codepoint prev, TLexerTokenList& tokenstream ) {
			rolling.Clear();
		}

		virtual void CheckKeywords ( codepoint peek, codepoint prev, TLexerTokenList& tokenstream ) {
			auto kwit = keywords.find( rolling );
			if ( kwit != keywords.end() ) {
				keyword = rolling;
				KeywordTrigger( peek, prev, keyword, kwit->second, tokenstream );
			}
		}

		virtual void CheckPunctuators ( codepoint peek, codepoint prev, TLexerTokenList& tokenstream ) {
			auto puncit = punctuators.find( peek );
			if ( puncit != punctuators.end() ) {
				PunctuatorTrigger( peek, prev, puncit->second, tokenstream );
			}
		}

	public:

		Lexer ( int defaulttokens = 64, int keywordcount = 8, int punctuatorcount = 8 ) : defaulttokenstreamsize(defaulttokens), keywords(keywordcount), punctuators(punctuatorcount), skipwhitespace(true), clearrollingonwhitespace(true) {

		}

		TLexerTokenList Lex ( IO::TextReader& reader, ulword expectedtokencount = 32 ) {
			TLexerTokenList tokenstream = make_vector<TLexerToken>(expectedtokencount < 1 ? defaulttokenstreamsize : expectedtokencount );
			codepoint peek, prev = -1;
			rolling.Clear();
			index = 0;
			
			while ( !reader.EoF() ) {
				peek = reader.Peek(  );
				if ( !LexLoop( reader, peek, prev, tokenstream ) ) {
					break;
				}
				prev = peek;
			}
			return tokenstream;
		}

	};
	
}}
