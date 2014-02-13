#pragma once

#include <Furrovine++/Declarations.h>
#include <Furrovine++/Graphics/DisplayModeDescription.h>

namespace Furrovine { namespace Graphics {

	class DisplayMode {
	private:
		friend class GraphicsAdapter;
		friend class GraphicsAdapterOutput;
		GraphicsAdapter* adapter;
		GraphicsAdapterOutput* adapteroutput;
		DisplayModeDescription desc;

	public:
		
		furrovineapi DisplayMode( );
		furrovineapi DisplayMode( GraphicsAdapter& graphicsadapter, GraphicsAdapterOutput& graphicsadapteroutput, const DisplayModeDescription& displaymodedesc );

		furrovineapi bool HasAdapter( ) const;

		furrovineapi bool HasAdapterOutput( ) const;

		furrovineapi GraphicsAdapter& Adapter( );

		furrovineapi GraphicsAdapterOutput& AdapterOutput( );

		furrovineapi const GraphicsAdapter& Adapter( ) const;

		furrovineapi const GraphicsAdapterOutput& AdapterOutput( ) const;

		furrovineapi DisplayModeDescription& Description( );

		furrovineapi const DisplayModeDescription& Description( ) const;

	};

}}
