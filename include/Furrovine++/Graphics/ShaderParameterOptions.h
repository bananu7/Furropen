#pragma once

#include <Furrovine++/Export.h>

namespace Furrovine { namespace Graphics {

	struct ShaderParameterOptions {

		furrovineapi static const ShaderParameterOptions Default;

		bool RowMajor;

		furrovineapi ShaderParameterOptions ();

	};

}}
