#pragma once

#include <Furrovine++/handle.h>
#include <Furrovine++/Export.h>

namespace Furrovine { namespace Text {

	class TextResources {
	private:
		struct deleter {
			furrovineapi void operator ()( void* p );
		};
		handle<void*, deleter> factoryresource;

	public:

		furrovineapi TextResources( );

		furrovineapi void* FactoryResource( ) const;

	};

}}