#pragma once

#include <Furrovine++/numeric_integer_def.h>
#include <Furrovine++/Export.h>
#include <memory>

namespace Furrovine { namespace Audio {

	class RicePartitions {
	public:
		furrovineapi static const lword MaxRiceParams = 14;
		furrovineapi static const lword MaxPartitionOrder = 8;
		furrovineapi static const lword MaxPartitions = 1 << MaxPartitionOrder;

		/// <summary>
		/// partition order
		/// </summary>
		lword porder;

		/// <summary>
		/// coding method: rice parameters use 4 bits for coding_method 0 and 5 bits for coding_method 1
		/// </summary>
		lword coding_method;

		/// <summary>
		/// Rice parameters
		/// </summary>
		std::unique_ptr<int[]> rparams;

		/// <summary>
		/// bps if using escape code
		/// </summary>
		std::unique_ptr<int[]> esc_bps;

		furrovineapi RicePartitions( );

		furrovineapi ~RicePartitions( );
	};

}}
