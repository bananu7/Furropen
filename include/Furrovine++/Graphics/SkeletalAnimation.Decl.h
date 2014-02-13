#pragma once

#include <Furrovine++/std_defines.h>
#include <unordered_map>
#include <Furrovine++/Matrix.h>
#include <Furrovine++/TimeValue.h>
#include <Furrovine++/Strings.h>
#include <Furrovine++/Graphics/AnimationRepeatBehavior.h>
#include <Furrovine++/Graphics/SkeletalAnimationChannel.h>
#include <Furrovine++/Graphics/Skeleton.h>
#include <Furrovine++/Graphics/SkeletalAnimationDescription.h>
#include <Furrovine++/raw.h>

namespace Furrovine { namespace Graphics {

	class SkeletalAnimation {
	public:
		typedef TimeValue<std::vector<Matrix>> MatrixKey;
		furrovineapi static const float DefaultAnimationStep;

	private:
		String name;
		Skeleton skeleton;
		std::vector<SkeletalAnimationChannel> channels;
		std::vector<std::vector<MatrixKey>> skeletonbonematrices;
		std::unordered_map<String, ulword> skeletonnameindices;
		std::vector<ulword> previousskeletontoboneindices;
		std::vector<Matrix*> transforms;
		double previoustime;
		double elapsedtime;
		double duration;
		float step;
		AnimationRepeatBehavior repeatbehavior;

		furrovineapi void Initialize( Skeleton& skeleton );

	public:

		furrovineapi SkeletalAnimation ( SkeletalAnimationDescription desc, float steprate = DefaultAnimationStep );
		furrovineapi SkeletalAnimation ( String name, Skeleton skeleton, double duration, std::vector<SkeletalAnimationChannel> channels, float steprate = DefaultAnimationStep );

		template <typename TContainer>
		void CopyTransforms ( TContainer& container ) const;
		furrovineapi std::vector<Matrix> CopyTransforms () const;
		furrovineapi void CopyTransforms ( buffer_view<Matrix>& view ) const;
		furrovineapi void CopyTransforms ( Matrix* data, ulword size ) const;
		furrovineapi void CopyTransforms ( Matrix* data, ulword size, ulword& index ) const;

		furrovineapi const String& Name () const;
		furrovineapi const Graphics::Skeleton& AnimationSkeleton () const;
		furrovineapi void Update ( float time );
		furrovineapi void Update ( float time, Graphics::Skeleton& skeleton );
	};

}}
