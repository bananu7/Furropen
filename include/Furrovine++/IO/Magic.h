#pragma once

#include <Furrovine++/Declarations.h>
#include <Furrovine++/numeric_integer_def.h>
#include <Furrovine++/IO/MagicIdentity.h>
#include <Furrovine++/Export.h>

namespace Furrovine { namespace IO {

	furrovineapi MagicIdentity Identify( Stream& stream, bool skipmagiciffound = false );
	furrovineapi MagicIdentity Identify( const buffer_view<byte>& bytes );
	furrovineapi MagicIdentity Identify( const String& ext );

}}