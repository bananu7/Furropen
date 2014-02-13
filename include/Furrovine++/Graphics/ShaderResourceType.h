#pragma once

namespace Furrovine { namespace Graphics {

	enum class ShaderResourceType {
		ConstantBuffer,
		TextureBuffer,
		Texture,
		Sampler,
		UorderedAccessViewRWTyped,
		Structured,
		UnorderedAccessViewRWStructured,
		ByteAddress,
		RWByteAddress,
		UnorderedAccessViewAppendStructured,
		UnorderedAccessViewConsumeStructured,
		UnorderedAccessViewRWStructuredCounter,
	};

}}