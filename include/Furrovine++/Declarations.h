#pragma once

#include <Furrovine++/PrimitiveTypes.h>

namespace Furrovine {

	namespace Audio {

		struct AudioData;
		class AudioDevice;
		class AudioResource;

	}

	namespace Collections {
		
		namespace Concurrent {
			
			template <typename T, typename TContainer>
			class BlockingQueue;

		}

	}

	namespace Shaders {
		
		class QuadShaderEffect;
		class NymphShaderEffect;
	}

	namespace IO {

		class File;
		class Directory;
		class Path;
		class Stream;
		class FileBasedStream;
		class FileStream;
		class RawFileStream;
		class MemoryStream;

		class FileSystem;

		class BitReader;
		class ByteReader;
		class TextReader;
		class FlacReader;
	}

	namespace Sys {

		class FileWatcher;
	}

	namespace Text {

		class RasterFont;
		struct RasterGlyph;
		struct RasterFontDescription;
		struct RasterFontData;
	}

	namespace Threading {

		class WaitHandle;
		class Semaphore;
		class AutoResetEvent;
		class ManualResetEvent;
		class Thread;
		class ThreadPool;
	}

	namespace Text {

		namespace Encoding {
			struct utf8;
		}
	}

	class runtime_type;

	template <typename T, typename TDx, bool isarray>
	class ptr;
	template <typename TParent, typename TPtr, typename TCast, bool isvoid>
	class ptrptr_type;
	template <typename T>
	class buffer_view;

	union primitive_pointer_union;
	union primitive_union;

	struct Int8;
	struct UInt8;
	struct Int16;
	struct UInt16;
	struct Int32;
	struct UInt32;
	struct Int64;
	struct UInt64;
	struct Single;
	struct Double;

	template <typename T>
	struct RVector2;
	template <typename T>
	struct RVector3;
	template <typename T>
	struct RVector4;

	template <typename T>
	struct TVector2;
	template <typename T>
	struct TVector3;
	template <typename T>
	struct TVector4;

	template <typename T>
	struct RMatrix3;
	template <typename T>
	struct RMatrix4;
	
	template <typename T>
	struct TMatrix3;
	template <typename T>
	struct TMatrix4;

	template <typename T>
	struct TRegion;
	template <typename T>
	struct TRectangle;

	template <typename TEncoding, typename TChar, typename TCharTraits, typename TAlloc>
	class string_base;

	typedef string_base<Text::Encoding::utf8, charutf8, std::char_traits<charutf8>, std::allocator<charutf8>> String;

	struct IWindow;
	struct IWindowDriver;

	struct MessageHeader;
	struct MessageData;
	template <typename T>
	struct Message;
	class MessageQueue;

	class GameTime;
	struct IServiceProvider;
	class ServiceProvider;
	class FurrovineGame;

	class BufferData;

}
