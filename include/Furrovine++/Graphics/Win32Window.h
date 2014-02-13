#pragma once

#include <Furrovine++/handle.h>
#include <Furrovine++/platform_deleters.h>
#include <Furrovine++/WindowDirtyFlags.h>
#include <Furrovine++/WindowDescription.h>
#include <Furrovine++/Graphics/AbstractWindow.h>

namespace Furrovine { namespace Graphics {
	
	class Win32Window : public AbstractWindow {
	private:
		struct win32_window_deleter : public platform_handle_null {
			furrovineapi void operator() ( void* p );
		};
		struct win32_no_deleter : public platform_handle_null {
			furrovineapi void operator() ( void* p );
		};

		WindowDirtyFlags dirty;
		WindowStyle style;
		WindowState state;
		String title, id;
		bool fullscreen, cursorvisible;
		bool explicitposition;
		bool firstshow;
		uint width, height;
		uint fswidth, fsheight;
		int x, y;
		
		handle<void*, win32_window_deleter> hwnd;
		handle<void*, win32_no_deleter> hinstance;
	
	public:

		furrovineapi Win32Window ( IWindowDriver& windowdriver, const WindowDescription&desc = WindowDescription(), bool autocreate = true );

		furrovineapi bool Dirty () const;

		furrovineapi void Apply ();

		furrovineapi virtual void Create ( ) override;
		
		furrovineapi virtual void Destroy () override;

		furrovineapi virtual void Minimize () override;

		furrovineapi virtual void Normalize () override;

		furrovineapi virtual void Maximize () override;

		furrovineapi virtual void Show () override;

		furrovineapi virtual void Hide () override;

		furrovineapi virtual void* Handle () const override;			

		furrovineapi virtual const String& GetTitle ( ) const override;

		furrovineapi virtual void SetTitle ( const String& value ) override;

		furrovineapi virtual const String& GetId ( ) const override;

		furrovineapi virtual void SetId ( const String& value ) override;

		furrovineapi virtual bool GetCursorVisible ( ) const override;

		furrovineapi virtual void SetCursorVisible ( bool value ) override;

		furrovineapi virtual void SetStyle( WindowStyle style ) override;
		furrovineapi virtual WindowStyle GetStyle( ) const override;

		furrovineapi virtual void SetState( WindowState style ) override;
		furrovineapi virtual WindowState GetState( ) const override;

		furrovineapi virtual void SetPosition( Vector2i value ) override;

		furrovineapi virtual Vector2i GetPosition () const override;

		furrovineapi virtual void SetSize ( Size2ui value ) override;

		furrovineapi virtual Size2ui GetSize () const override;

		furrovineapi virtual void SetFullScreen ( bool value ) override;

		furrovineapi virtual bool GetFullScreen () const override;

		furrovineapi virtual double GetAspectRatio () const override;

		furrovineapi virtual void* WndProc( void* hwnd, uint umsg, void* wparam, void* lparam );

		furrovineapi ~Win32Window( );

	};

}}
