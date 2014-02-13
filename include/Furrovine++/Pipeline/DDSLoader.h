#pragma once

#include <Furrovine++/Graphics/Image2D.h>

namespace Furrovine { namespace Pipeline {

	class DDSLoader {
	public:
		static const bool DefaultDecompress;

		bool Decompress;

		furrovineapi DDSLoader( bool decompress = DefaultDecompress );

		furrovineapi std::vector<Graphics::Image2D> Load( IO::Stream& stream );
		furrovineapi std::vector<Graphics::Image2D> Load( IO::ByteReader& reader );
		furrovineapi std::vector<Graphics::Image2D> operator()( IO::Stream& stream );
		furrovineapi std::vector<Graphics::Image2D> operator()( IO::ByteReader& reader );

	};
}}
