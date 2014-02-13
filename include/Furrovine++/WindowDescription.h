#pragma once

#include <Furrovine++/WindowStyle.h>
#include <Furrovine++/WindowState.h>
#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/Vector2.h>
#include <Furrovine++/Size2.h>
#include <Furrovine++/Strings.h>
#include <Furrovine++/optional.h>

namespace Furrovine {

	struct WindowDescription {
		furrovineapi static const int32 AutoCenter = 0x7FFFFFFF;
		furrovineapi static const uint32 DefaultWidth = 800;
		furrovineapi static const uint32 DefaultHeight = 600;

		String Title = "Furrovine";
		String ID = "";
		Size2ui Size = Size2ui( DefaultWidth, DefaultHeight );
		WindowStyle Style = WindowStyles::Bordered;
		WindowState State = WindowState::Normal;
		optional<Vector2i> Position = nullopt;
		bool Fullscreen = false;
		bool CursorVisible = true;
		
		furrovineapi WindowDescription( String Title = "Furrovine",
			Size2ui Size = Size2ui( DefaultWidth, DefaultHeight ),
			optional<Vector2i> Position = nullopt,
			WindowStyle Style = WindowStyles::Bordered,
			WindowState State = WindowState::Normal,
			bool Fullscreen = false,
			bool CursorVisible = true,
			String ID = "" );
	};

}