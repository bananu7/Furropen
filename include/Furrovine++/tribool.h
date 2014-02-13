#ifndef FURROVINETRIBOOL_H
#define FURROVINETRIBOOL_H

#include <Furrovine++/optional.h>

namespace Furrovine {

	struct tribool {
	private:
		optional<bool> tri;
	public:

		tribool () {

		}

		tribool ( none_t ) : tri( none ) {

		}

		tribool ( bool value ) : tri( value ) {

		}

		tribool ( const tribool& copy ) : tri( copy ) {

		}

		tribool ( tribool&& mov ) : tri( std::move( mov ) ) {

		}

		explicit operator bool () const {
			return tri && tri.get();
		}

		bool operator! () const {
			return tri ? !tri.get() : false;
		}

		tribool& operator= ( bool value ) {
			tri = value;
			return *this;
		}

		tribool& operator= ( const none_t& ) {
			tri = none;
			return *this;
		}

		tribool& operator= ( const tribool& copy ) {
			tri = copy.tri;
			return *this;
		}

		tribool& operator= ( tribool&& value ) {
			tri = std::move( value.tri );
			return *this;
		}
	};

}

#endif // FURROVINETRIBOOL_H 