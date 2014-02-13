#pragma once

#include <Furrovine++/PrimitiveTypes.h>

namespace Furrovine {

	template <typename T>
	struct TBox {
		static const TBox Empty;

		T left, top, front;
		T right, bottom, back;

		TBox( T l = 0, T t = 0, T f = 0, T r = 1, T b = 1, T bk = 1 )
		: left(l), top(t), front(f), right(r), bottom(b), back(bk) {

		}

		bool IsEmpty( ) const {
			return left == right && front == back && top == bottom;
		}

	};

	template <typename T>
	const TBox<T> TBox<T>::Empty = { 0, 0, 0, 0, 0, 0 };

}
