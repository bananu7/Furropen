#ifndef FURROVINEDISABLE_H
#define FURROVINEDISABLE_H

#include <type_traits>

namespace Furrovine {

	template <typename TCondition, typename T = void>
	struct enable {

		typedef typename std::enable_if<TCondition::value, T>::type type;

	};

	template <typename TCondition, typename T = void>
	struct disable {

		typedef typename std::enable_if<!TCondition::value, T>::type type;

	};

}

#endif // FURROVINEDISABLE_H 