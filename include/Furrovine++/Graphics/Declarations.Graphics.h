#pragma once

#include <Furrovine++/PrimitiveTypes.h>

namespace Furrovine { namespace Graphics {

	struct ShaderEffectDescription;
	struct ShaderTechniqueDescription;
	struct ShaderPassDescription;
	struct ShaderDeclaration;
	struct ShaderSource;

	class Shader;
	class VertexShader;
	class GeometryShader;
	class HullShader;
	class DomainShader;
	class PixelShader;
	class ComputeShader;

	class ShaderParameter;
	class ShaderResource;
	class ShaderResourceBuffer;
	class ShaderVariable;
	class ShaderVariableBuffer;
	
	class ShaderPass;
	class ShaderTechnique;
	class ShaderEffect;

	struct VertexDeclaration;
	class VertexBufferData;
	class IndexBufferData;

	class GraphicsAdapter;
	class GraphicsAdapterOutput;
	class GraphicsDevice;
	class GraphicsDevice2D;

	class InputLayout;

	class Image1D;
	class Image2D;
	class Image3D;
	class Texture;
	class Texture1D;
	class Texture2D;
	class Texture3D;
	class RenderBuffer2D;
	class DepthStencilBuffer;

	class ShaderResourceView;
	class GpuBuffer;
	class GpuMultiBuffer;
	class VertexBuffer;
	class IndexBuffer;

	class ConstantBufferState;
	class ShaderResourceViewCollection;
	class Bone;
	class Skeleton;
	class SubMesh;

	class RasterizerState;
	class DepthStencilState;
	class SamplerState;
	class SamplerStateCollection;
	class BlendState;
	class BlendStateCollection;
	struct RasterizerStateDescription;
	struct DepthStencilStateDescription;
	struct SamplerStateDescription;
	struct SamplerStateCollectionDescription;
	struct BlendStateDescription;
	struct BlendStateCollectionDescription;

	struct ModelDescription;
	struct MeshDescription;
	struct SubMeshDescription;
	class Mesh;
	class Model;
	class ModelBoneCollection;
	class SkeletalAnimationCollection;
	class ModelMaterialCollection;
	class MeshCollection;
	class SubMeshCollection;
	class AnimatedModel;
	class SkeletalAnimation;
	class SkeletalAnimationChannel;

	class QuadBatch;
	class NymphBatch;

}}