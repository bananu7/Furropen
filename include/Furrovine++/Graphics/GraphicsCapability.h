#pragma once

#include <Furrovine++/Graphics/ShaderVersion.h>

namespace Furrovine { namespace Graphics {

	struct GraphicsCapability {
		ShaderVersion MaxShader;
		bool GeometryShader;
		bool StreamOutput;
		bool ComputerShader;
		bool HullDomainShader;
		bool TextureResourceArrays;
		bool CubemapResourceArrays;
		bool BC4BC5Compression;
		bool BC6HBC7Compression;
		bool AlphaToCoverage;
		bool ExtendedFormats;
		bool XRHighColor10bitFormat;
		bool LogicOperationsonOutputMerger;
		bool TargetIndependentRasterization;
		bool MultipleRenderTargetsWithForcedSampleCount;
		int32 UAVSlots;
		bool PerStageUAVs;
		int MaxForcedSampleCountforUAV;
		int32 ConstantBufferOffsettingandPartialUpdates;
		bool Format16BitsPerPixel;
		int32 MaxTextureDimension;
		int32 MaxCubemapDimension;
		int32 MaxVolumeExtent;
		int32 MaxTextureRepeat;
		float MaxAnisotropy;
		int64 MaxPrimitiveCount;
		int32 MaxInputSlots;
		int32 MaxRenderTargets;
		bool OcclusionQueries;
		bool SeparateAlphaBlendPerRenderTarget;
		bool MirrorOnce;
		bool OverlappingVertexElements;
		bool IndependentWriteMasks;
		bool Instancing;
		bool NonPowersof2Unconditionally;
		bool NonPowersof2Conditionally;
	};

}}
 