#pragma once

#include <vector>
#include <Furrovine++/Size2.h>
#include <Furrovine++/Vector2.h>
#include <Furrovine++/WindowStyle.h>
#include <Furrovine++/WindowState.h>
#include <Furrovine++/Strings.h>
#include <Furrovine++/IWindowDriver.h>

namespace Furrovine {

	struct IWindow {
	public:
		furrovineapi static const void* InvalidHandle;

		virtual void* Handle( ) const = 0;
		virtual void Create( ) = 0;
		virtual void Destroy( ) = 0;
		virtual void Show( ) = 0;
		virtual void Hide( ) = 0;
		virtual void Maximize( ) = 0;
		virtual void Normalize( ) = 0;
		virtual void Minimize( ) = 0;

		virtual void SetStyle( WindowStyle style ) = 0;
		virtual WindowStyle GetStyle( ) const = 0;

		virtual void SetState( WindowState style ) = 0;
		virtual WindowState GetState( ) const = 0;

		virtual bool GetFullScreen( ) const = 0;
		virtual void SetFullScreen( bool value ) = 0;

		virtual void SetPosition( Vector2i value ) = 0;
		virtual Vector2i GetPosition( ) const = 0;
		virtual void SetSize( Size2ui value ) = 0;
		virtual Size2ui GetSize( ) const = 0;
		virtual double GetAspectRatio( ) const = 0;

		virtual const String& GetTitle( ) const = 0;
		virtual void SetTitle( const String& value ) = 0;
		virtual const String& GetId( ) const = 0;
		virtual void SetId( const String& value ) = 0;
		virtual bool GetCursorVisible( ) const = 0;
		virtual void SetCursorVisible( bool value ) = 0;

		virtual void ClearWindowDriver( ) = 0;
		virtual void SetWindowDriver( IWindowDriver& iwindowdriver ) = 0;
		virtual bool HasWindowDriver( ) const = 0;
		virtual IWindowDriver& GetWindowDriver( ) = 0;
		virtual const IWindowDriver& GetWindowDriver( ) const = 0;

		furrovineapi virtual ~IWindow( );

		furrovineapi static bool IsValidWindow( const IWindow* window );

		furrovineapi static bool IsValid( const IWindow* window );

		furrovineapi static bool IsValidHandle( void* handle );

	};

}
