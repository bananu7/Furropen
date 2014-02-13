#ifndef FURROVINEBATCHSHADERSTAGE_H
#define FURROVINEBATCHSHADERSTAGE_H

namespace Furrovine { namespace Graphics {

	enum class BatchShaderStage {
		BeforeBatch,
		BeforePasses,
		DuringPass,
		AfterPasses,
		AfterBatch
	};

}}

#endif // FURROVINEBATCHSHADERSTAGE_H 