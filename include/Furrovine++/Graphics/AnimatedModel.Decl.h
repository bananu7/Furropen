#pragma once

#include <Furrovine++/Graphics/Declarations.Graphics.h>
#include <Furrovine++/FurrovineApi.h>
#include <Furrovine++/Matrix.h>
#include <Furrovine++/std_defines.h>
#include <Furrovine++/Strings.h>
#include <vector>

namespace Furrovine { namespace Graphics {

	class AnimatedModel {
	private:
		Model* model;
		SkeletalAnimationCollection* animations;
		SkeletalAnimation* currentanimation;

	public:

		furrovineapi AnimatedModel( );
		furrovineapi AnimatedModel( Model& skeletalmodel, SkeletalAnimationCollection& anims );

		furrovineapi void Update( float step );

		furrovineapi void SetModel( Model& model );
		furrovineapi void SetAnimations( SkeletalAnimationCollection& skeletalanimations );
		furrovineapi void SetAnimation( const String& animationname );
		
	};

}}
