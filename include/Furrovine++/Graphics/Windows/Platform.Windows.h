#pragma once

#include <Furrovine++/Platform.h>
#include <Furrovine++/WindowStyle.h>
#include <Furrovine++/make_array.h>

namespace Furrovine { namespace Graphics { namespace Windows {

#ifdef FURROVINEWIN

	enum class WindowStyle : ULONG {
		None = 0x00000000L,
		Bordered = 0x00800000L,
		TitleBar = 0x00C00000L,
		Child = 0x40000000L,
		ChildWindow = 0x40000000L,
		ClipChildren = 0x02000000L,
		ClipSiblings = 0x04000000L,
		Disabled = 0x08000000L,
		DialogFrame = 0x00400000L,
		Group = 0x00020000L,
		HorizontalScrollBar = 0x00100000L,
		Iconic = 0x20000000L,
		MaximizeState = 0x01000000L,
		MaximizeBox = 0x00010000L,
		MinimizeState = 0x20000000L,
		MinimizeBox = 0x00020000L,
		Overlapped = 0x00000000L,
		Popup = 0x80000000L,
		ResizeBox = 0x00040000L,
		SystemMenu = 0x00080000L,
		TabStop = 0x00010000L,
		ThickFrame = 0x00040000L,
		Tiled = 0x00000000L,
		VisibleState = 0x10000000L,
		VerticalScrollBar = 0x00200000L,
		PopupWindow = ( WS_POPUP | WS_BORDER | WS_SYSMENU ),
		TiledWindow = ( WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX ),
		OverlappedWindow = ( WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX ),
	};

	WindowStyle ToPlatform( Furrovine::WindowStyle value ) {
		const static auto platformlookup = make_array(
			WindowStyle::None,
			WindowStyle::VisibleState,
			WindowStyle::Bordered,
			WindowStyle::None,
			WindowStyle::Bordered,
			WindowStyle::TitleBar,
			WindowStyle::MinimizeBox,
			WindowStyle::MaximizeBox,
			WindowStyle::SystemMenu,
			WindowStyle::VerticalScrollBar,
			WindowStyle::HorizontalScrollBar,
			WindowStyle::Popup,
			WindowStyle::ThickFrame,
			WindowStyle::None,
			WindowStyle::Popup
		);

		WindowStyle flags = accumulate_flags( value, platformlookup );
		return flags;
	}

	RECT GetLocalCoordinates( HWND hWnd ) {
		RECT Rect;
		GetWindowRect( hWnd, &Rect );
		MapWindowPoints( HWND_DESKTOP, GetParent( hWnd ), (LPPOINT)&Rect, 2 );
		return Rect;
	}

	template <typename T, typename TValue>
	auto FromPlatform( TValue value ) -> decltype( FromPlatform( static_cast<T>( value ) ) ) {
		return FromPlatform( static_cast<T>( value ) );
	}

	template <typename T, typename TValue>
	auto ToPlatform( TValue value ) -> decltype( static_cast<T>( ToPlatform( value ) ) ) {
		return static_cast<T>( ToPlatform( value ) );
	}

#endif // WIN

}}}
