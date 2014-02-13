#pragma once

#include <Furrovine++/Export.h>

namespace Furrovine {

	struct platform_handle_null {
		furrovineapi void* get_null( ) const;
	};

	struct delete_platform_handle : public platform_handle_null {
		furrovineapi void operator() ( void* ptr ) const;
	};

	struct delete_platform_notification_handle : public platform_handle_null {
		furrovineapi void operator() ( void* ptr ) const;
	};

	struct delete_platform_find_handle : public platform_handle_null {
		furrovineapi void operator() ( void* ptr ) const;
	};

}
