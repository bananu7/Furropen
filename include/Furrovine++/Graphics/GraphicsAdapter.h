#pragma once

#include <Furrovine++/handle.h>
#include <Furrovine++/Graphics/graphics_handle.h>
#include <Furrovine++/Graphics/GraphicsAdapterOutput.h>
#include <Furrovine++/Graphics/DisplayMode.h>
#include <Furrovine++/Graphics/DisplayFilterFlags.h>
#include <Furrovine++/Graphics/AdapterDescription.h>

namespace Furrovine { namespace Graphics {

	class GraphicsAdapter {
	private:
		struct deleter {
			furrovineapi void operator () ( graphics_handle p );
		};

		handle<graphics_handle, deleter>  adapterresource;
		std::vector<GraphicsAdapterOutput> outputs;
		AdapterDescription desc;

	public:

		furrovineapi GraphicsAdapter( graphics_handle adapterresource, DisplayFilterFlags displaymodeflags = DisplayFilterFlags::Interlaced );
		furrovineapi GraphicsAdapter( GraphicsAdapter&& mov );
		furrovineapi GraphicsAdapter& operator=( GraphicsAdapter&& mov );

		furrovineapi graphics_handle Resource( ) const;

		furrovineapi ulword Count () const;

		furrovineapi GraphicsAdapterOutput& operator[] ( ulword index );

		furrovineapi const GraphicsAdapterOutput& operator[] ( ulword index ) const;

		furrovineapi ~GraphicsAdapter ();

	};

}}
