#pragma once

namespace Furrovine { namespace Graphics {
	
	enum class TextureAddress {
		Wrap = 1,
		Mirror,
		Clamp,
		Border,
		MirrorOnce,
		Repeat = Wrap,
		MirrorRepeat = Mirror,
		Default = Clamp,
	};
	
}}
