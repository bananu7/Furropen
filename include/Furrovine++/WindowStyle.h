#pragma once

#include <Furrovine++/Enums.h>
#include <Furrovine++/Export.h>

namespace Furrovine {

	enum class WindowStyle {
		None = 0x0000,
		Visible = 0x0001,
		Border = 0x0002,
		Resizable = 0x0004,
		Movable = 0x0008,
		TitleBar = 0x0010,
		MinimizeBox = 0x0020,
		MaximizeBox = 0x0040,
		SystemMenu = 0x0080,
		VerticalScollbar = 0x0100,
		HorizontalScollbar = 0x0200,
		Popup = 0x0400,
		ThickFrame = 0x0800,
		Shadow = 0x1000,
		Transparent = 0x2000,
	};

	enumflagoperators( WindowStyle );

	struct WindowStyles {
		furrovineapi const static WindowStyle Bordered;
		furrovineapi const static WindowStyle Borderless;
		furrovineapi const static WindowStyle BorderedTransparent;
		furrovineapi const static WindowStyle BorderlessTransparent;
	};

}