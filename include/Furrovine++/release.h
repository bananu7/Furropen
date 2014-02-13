#pragma once

namespace Furrovine {

	template <typename TPtr>
	auto release ( TPtr& p ) -> decltype( p.release() ) {
		return p.release();
	}

}
