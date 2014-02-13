#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Graphics {
	
	enum class ShaderCompilationFlags {
		None = 0x0,
		Debug = 0x0001,
		SkipValidation = 0x0002,
		NoOptimizations = 0x0004,
		MatrixRowMajor = 0x0008,
		MatrixColumnMajor = 0x0010,
		LessAccurateFastMath = 0x0020,
		ForceVertexSoftwareVersionDebug = 0x0040,
		ForcePixelSoftwareVersionDebug = 0x0080,
		DisableStaticOptomization = 0x0100,
		AvoidFlowControl = 0x0200,
		PreferFlowControl = 0x0400,
		Strict = 0x0800,
		BackwardsCompatibility = 0x1000,
		IEEEStrict = 0x2000,
		Software = 0x4000,
	};
	
	enumflagoperators( ShaderCompilationFlags );

}}
