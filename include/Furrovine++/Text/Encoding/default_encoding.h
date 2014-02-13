#pragma once

#include <Furrovine++/Text/Encoding/ascii.h>
#include <Furrovine++/Text/Encoding/utf8.h>
#include <Furrovine++/Text/Encoding/utf16.h>
#include <Furrovine++/Text/Encoding/utf32.h>
#include <Furrovine++/Text/Encoding/wide_encoding.h>
#include <Furrovine++/Text/Encoding/narrow_encoding.h>
#include <Furrovine++/Text/Encoding/filesystem_encoding.h>

namespace Furrovine { namespace Text { namespace Encoding {

	template <typename TSrc, typename TDest>
	struct compatible_encoding : std::false_type {
		static const bool value = false;
	};

	template <>
	struct compatible_encoding<ascii, utf8> : std::true_type {
		static const bool value = true;
	};

	template <typename TChar>
	struct default_encoding {
		static const bool value = false;
	};

	template <>
	struct default_encoding<charascii> {
		static const bool value = true;
		typedef ascii type;
	};

	template <>
	struct default_encoding<charutf8> {
		static const bool value = true;
		typedef utf8 type;
	};

	template <>
	struct default_encoding<charutf16> {
		static const bool value = true;
		typedef utf16 type;
	};

	template <>
	struct default_encoding<charutf32> {
		static const bool value = true;
		typedef utf32 type;
	};

	template <>
	struct default_encoding<charwide> {
		static const bool value = true;
		typedef wide_encoding type;
	};

}}}
 