#pragma once

#include <Furrovine++/Enums.h>
#include <Furrovine++/Platform.h>
#include <Furrovine++/IO/FileAttribute.h>

namespace Furrovine { namespace IO { namespace Windows {

	enum class FileAttribute : ulong {
		None = 0x0,
		Readonly = 0x00000001,
		Hidden = 0x00000002,
		System = 0x00000004,
		Directory = 0x00000010,
		Archive = 0x00000020,
		Device = 0x00000040,
		Normal = 0x00000080,
		Temporary = 0x00000100,
		SparseFile = 0x00000200,
		ReparsePoint = 0x00000400,
		Compressed = 0x00000800,
		Offline = 0x00001000,
		NonContextIndexed = 0x00002000,
		Encrypted = 0x00004000,
		IntegrityStream = 0x00008000,
		Virtual = 0x00010000,
		NoScrubData = 0x00020000,
		Invalid = (ulong)-1,
	};

	enumflagoperators( FileAttribute );

	inline furrovineapi FileAttribute ToPlatform ( IO::FileAttribute value ) {
		return enum_cast<FileAttribute>( value );
	}

}}}