#pragma once

#include <unordered_map>
#include <vector>
#include <Furrovine++/Declarations.h>
#include <Furrovine++/handle.h>
#include <Furrovine++/Graphics/graphics_handle.h>
#include <Furrovine++/Graphics/SurfaceFormat.h>
#include <Furrovine++/Graphics/MonitorRotation.h>
#include <Furrovine++/Graphics/DisplayFilterFlags.h>
#include <Furrovine++/Graphics/AdapterOutputDescription.h>
#include <Furrovine++/Graphics/DisplayMode.h>

namespace Furrovine { namespace Graphics {

	class GraphicsAdapterOutput {
	private:
		friend class GraphicsAdapter;
		struct deleter {
			furrovineapi void operator()( graphics_handle p );
		};

		GraphicsAdapter* adapter;
		AdapterOutputDescription adapteroutputdesc;
		handle<graphics_handle, deleter>  outputresource;
		DisplayFilterFlags displayfilterflags;
		std::unordered_map<SurfaceFormat, ulword> displaymodeindices;
		std::vector<std::vector<DisplayMode>> displaymodes;

		furrovineapi void reset_adapter( GraphicsAdapter* graphicsadapter );

	public:
		furrovineapi static const std::array<SurfaceFormat, 10> ValidDisplayFormats;

		furrovineapi GraphicsAdapterOutput ( GraphicsAdapter& adapter, graphics_handle output, DisplayFilterFlags flags = DisplayFilterFlags::Interlaced );
		furrovineapi GraphicsAdapterOutput( GraphicsAdapterOutput&& mov );
		furrovineapi GraphicsAdapterOutput& operator=( GraphicsAdapterOutput&& mov );

		furrovineapi const AdapterOutputDescription& Description( ) const;

		furrovineapi graphics_handle Resource( ) const;

		furrovineapi GraphicsAdapter& Adapter( );

		furrovineapi const GraphicsAdapter& Adapter( ) const;

		furrovineapi std::vector<DisplayMode>& operator[] ( SurfaceFormat format );

		furrovineapi const std::vector<DisplayMode>& operator[] ( SurfaceFormat format ) const;

		furrovineapi ~GraphicsAdapterOutput( );

	};

}}
