#pragma once

#include <Furrovine++/IWindow.h>

namespace Furrovine { namespace Graphics {

	class AbstractWindow : public IWindow {
	protected:
		IWindowDriver* windowdriver;

	public:

		furrovineapi AbstractWindow( );
		furrovineapi AbstractWindow( IWindowDriver& iwindowdriver );

		furrovineapi virtual void ClearWindowDriver( ) override;

		furrovineapi virtual void SetWindowDriver( IWindowDriver& iwindowdriver ) override;

		furrovineapi virtual bool HasWindowDriver( ) const override;

		furrovineapi virtual IWindowDriver& GetWindowDriver( ) override;

		furrovineapi virtual const IWindowDriver& GetWindowDriver( ) const override;

	};

}}
