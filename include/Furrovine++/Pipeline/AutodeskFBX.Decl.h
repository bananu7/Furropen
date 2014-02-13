#pragma once

#define FBXSDK_SHARED 1

#include <Furrovine++/std_defines.h>
#include <fbxsdk.h>
#include <Furrovine++/Matrix.h>
#include <Furrovine++/Graphics/Skeleton.h>

namespace Furrovine { namespace Pipeline {

	inline furrovineapi float ToUVy( double value );

	inline furrovineapi float ToUVy( float value );

	inline furrovineapi float ToUVx( double value );

	inline furrovineapi float ToUVx( float value );

	inline furrovineapi Matrix ToMatrix ( const FbxAMatrix& mat );

	inline furrovineapi std::vector<Graphics::Skeleton> ProcessSkeletons ( FbxScene* scene, FbxNode* node, FbxMesh* mesh );

}}
