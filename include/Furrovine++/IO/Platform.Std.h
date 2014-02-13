#include <Furrovine++/IO/FileMode.h>
#include <Furrovine++/IO/FileAccess.h>
#include <Furrovine++/make_array.h>
#include <iosfwd>

namespace Furrovine { namespace IO { namespace Std {

	enum class CSeekOrigin {
		Begin = SEEK_SET,
		Current = SEEK_CUR,
		End = SEEK_END,
	};

	enum class SeekOrigin {
		Begin = std::ios_base::beg,
		Current = std::ios_base::cur,
		End = std::ios_base::end,
	};

	enum class FileAccess {
		None = 0x0,
		Read = std::ios_base::in,
		Write = std::ios_base::out,
		ReadWrite = Read | Write,
		Default = ReadWrite
	};

	enum class FileMode {
		None = 0x00,
		Open = std::ios_base::binary | std::ios_base::in,
		Create = std::ios_base::binary | std::ios_base::out,
		Truncate = Open | Create | std::ios_base::trunc,
		OpenOrCreate = Open | Create,
		Append = std::ios_base::binary | std::ios_base::app | std::ios_base::in | std::ios_base::out,
		AtEnd = std::ios_base::ate
	};

	inline furrovineapi SeekOrigin ToPlatform( IO::SeekOrigin origin ) {
		switch ( origin ) {
		case IO::SeekOrigin::Begin:
			return SeekOrigin::Begin;
		case IO::SeekOrigin::Current:
			return SeekOrigin::Current;
		case IO::SeekOrigin::End:
			return SeekOrigin::End;
		default:
			throw Exception( "Bad SeekOrigin value for Std" );
		}
	}

	inline furrovineapi CSeekOrigin ToCPlatform( IO::SeekOrigin origin ) {
		switch ( origin ) {
		case IO::SeekOrigin::Begin:
			return CSeekOrigin::Begin;
		case IO::SeekOrigin::Current:
			return CSeekOrigin::Current;
		case IO::SeekOrigin::End:
			return CSeekOrigin::End;
		default:
			throw Exception( "Bad SeekOrigin value for Std-C" );
		}
	}

	inline furrovineapi std::ios_base::openmode ToPlatform( IO::FileMode mode, IO::FileAccess access ) {
		const static auto modelookup = make_array(
			FileMode::None,
			FileMode::Open,
			FileMode::Create,
			FileMode::Truncate,
			FileMode::Append,
			FileMode::AtEnd
		);
		const static auto accesslookup = make_array(
			FileAccess::None,
			FileAccess::Read,
			FileAccess::Write
		);

		std::ios_base::openmode value = 0;
		FileAccess platformaccess = accumulate_flags( access, accesslookup );
		FileMode platformmode = accumulate_flags( mode, modelookup );
		value |= static_cast<std::ios_base::openmode>( platformaccess );
		value |= static_cast<std::ios_base::openmode>( platformmode );
		value |= std::ios_base::binary;
		return value;
	}

	template <typename T>
	std::array<T, 16> OpenMode( IO::FileMode mode, IO::FileAccess access ) {
		const static auto r = std::ios_base::in;
		const static auto w = std::ios_base::out;
		const static auto w2 = std::ios_base::out | std::ios_base::trunc;
		const static auto a = std::ios_base::app;
		const static auto a2 = std::ios_base::out | std::ios_base::app;
		const static auto rp = std::ios_base::out | std::ios_base::in;
		const static auto wp = std::ios_base::out | std::ios_base::in | std::ios_base::trunc;
		const static auto ap = std::ios_base::out | std::ios_base::in | std::ios_base::app;
		const static auto ap2 = std::ios_base::in | std::ios_base::app;
		const static auto rb = std::ios_base::binary | std::ios_base::in;
		const static auto wb = std::ios_base::binary | std::ios_base::out;
		const static auto wb2 = std::ios_base::binary | std::ios_base::out | std::ios_base::trunc;
		const static auto ab = std::ios_base::binary | std::ios_base::app;
		const static auto ab2 = std::ios_base::binary | std::ios_base::out | std::ios_base::app;
		const static auto rpb = std::ios_base::binary | std::ios_base::out | std::ios_base::in;
		const static auto wpb = std::ios_base::binary | std::ios_base::out | std::ios_base::in | std::ios_base::trunc;
		const static auto apb = std::ios_base::binary | std::ios_base::out | std::ios_base::in | std::ios_base::app;
		const static auto apb2 = std::ios_base::binary | std::ios_base::in | std::ios_base::app;
		std::array<T, 16> openstr = { };
		std::ios_base::openmode openmode = ToPlatform( mode, access );
		switch ( openmode & ~std::ios_base::ate ) {
		case r:
			openstr[ 0 ] = 'r';
			break;
		case w2:
		case w:
			openstr[ 0 ] = 'w';
			break;
		case a:
		case a2:
			openstr[ 0 ] = 'a';
			break;
		case rp:
			openstr[ 0 ] = 'r';
			openstr[ 1 ] = 'p';
			break;
		case wp:
			openstr[ 0 ] = 'w';
			openstr[ 1 ] = 'p';
			break;
		case ap:
		case ap2:
			openstr[ 0 ] = 'a';
			openstr[ 1 ] = 'p';
			break;
		case rb:
			openstr[ 0 ] = 'r';
			openstr[ 1 ] = 'b';
			break;
		case wb:
		case wb2:
			openstr[ 0 ] = 'w';
			openstr[ 1 ] = 'b';
			break;
		case ab:
		case ab2:
			openstr[ 0 ] = 'a';
			openstr[ 1 ] = 'b';
			break;
		case rpb:
			openstr[ 0 ] = 'r';
			openstr[ 1 ] = '+';
			openstr[ 2 ] = 'b';
			break;
		case wpb:
			openstr[ 0 ] = 'w';
			openstr[ 1 ] = '+';
			openstr[ 2 ] = 'b';
			break;
		case apb:
		case apb2:
			openstr[ 0 ] = 'a';
			openstr[ 1 ] = '+';
			openstr[ 2 ] = 'b';
			break;
		default:
			throw Exception( "Unable to create standard stream opening mode" );
			break;
		}
		return openstr;
	}

	template <typename T, typename TValue>
	auto ToPlatform( TValue value )-> decltype( static_cast<T>( ToPlatform( value ) ) ) {
		return static_cast<T>( ToPlatform( value ) );
	}

	template <typename T, typename TValue>
	auto ToCPlatform( TValue value )-> decltype( static_cast<T>( ToCPlatform( value ) ) ) {
		return static_cast<T>( ToCPlatform( value ) );
	}

	inline furrovineapi std::array<char, 16> ToOpenMode( IO::FileMode mode, IO::FileAccess access ) {
		return OpenMode<char>( mode, access );
	}

	inline furrovineapi std::array<wchar_t, 16> ToWOpenMode( IO::FileMode mode, IO::FileAccess access ) {
		return OpenMode<wchar_t>( mode, access );
	}
	
}}}