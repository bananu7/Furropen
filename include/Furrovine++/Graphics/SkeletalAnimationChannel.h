#pragma once

#include <Furrovine++/Strings.h>
#include <Furrovine++/TimeValue.h>
#include <Furrovine++/Vector2.h>
#include <Furrovine++/Vector3.h>
#include <Furrovine++/Vector4.h>
#include <Furrovine++/Quaternion.h>
#include <Furrovine++/Matrix.h>
#include <Furrovine++/Graphics/Declarations.Graphics.h>

namespace Furrovine { namespace Graphics {

	class SkeletalAnimationChannel {
	public:
		typedef TimeValue<Vector3> TranslationKey;
		typedef TimeValue<Vector3> ScaleKey;
		typedef TimeValue<Quaternion> RotationKey;
		typedef TimeValue<Matrix> TransformKey;

	private:
		Matrix transformmatrix;
		String name;
		ulword lasttranslationindex;
		ulword lastscalingindex;
		ulword lastrotationindex;
		double duration;
		double currenttime, lasttime;
		std::vector<TransformKey> transformkeys;

		void UpdateTransformMatrix ( float step );

	public:

		furrovineapi SkeletalAnimationChannel ( String name, double duration, std::vector<TransformKey> transforms );
		furrovineapi SkeletalAnimationChannel( SkeletalAnimationChannel&& mov );
		furrovineapi SkeletalAnimationChannel& operator=( SkeletalAnimationChannel&& mov );
		furrovineapi SkeletalAnimationChannel( const SkeletalAnimationChannel& nocopy ) = delete;
		furrovineapi SkeletalAnimationChannel& operator=( const SkeletalAnimationChannel& nocopy ) = delete;
		
		furrovineapi const String& Name( ) const;
		furrovineapi void Calculate ( float time );
		furrovineapi void UpdateTransform( Skeleton& skeleton );
	};

}}
