#pragma once

#include <Furrovine++/default_epsilon.h>

namespace Furrovine {

	template <typename value_type, typename time_type = double>
	struct TimeValue {
		typedef time_type TTime;
		typedef value_type TValue;
		static const TTime Epsilon;
		TTime time;
		TValue value;

		bool operator == ( const TimeValue& obj ) const {
			return time == obj.time;
		}

		bool operator != ( const TimeValue& obj ) const {
			return time != obj.time;
		}

		bool operator < ( const TimeValue& obj ) const {
			return time < obj.time;
		}

		bool operator > ( const TimeValue& obj ) const {
			return time > obj.time;
		}
	};

	template <typename value_type, typename time_type>
	time_type TimeValue<value_type, time_type>::Epsilon = default_epsilon<time_type>::Epsilon;

}
