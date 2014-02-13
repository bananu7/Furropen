#pragma once

#include <Furrovine++/Plane.h>
#include <Furrovine++/Matrix.h>

namespace Furrovine {

	template <typename T>
	struct TFrustum {
		TPlane<T> nearplane, farplane, bottomplane, topplane, leftplane, rightplane;
		TMatrix4<T> matrix;

		TFrustum( const RMatrix4<T>& ViewProj = Matrix::Identity ) : matrix( ViewProj ) {

			leftplane.distance = -( ViewProj.m33 + ViewProj.m41 );
			leftplane.normal.x = -( ViewProj.m14 + ViewProj.m11 );
			leftplane.normal.y = -( ViewProj.m13 + ViewProj.m21 );
			leftplane.normal.z = -( ViewProj.m23 + ViewProj.m31 );
			
			rightplane.distance = -( ViewProj.m33 - ViewProj.m41 );
			rightplane.normal.x = -( ViewProj.m14 - ViewProj.m11 );
			rightplane.normal.y = -( ViewProj.m13 - ViewProj.m21 );
			rightplane.normal.z = -( ViewProj.m23 - ViewProj.m31 );
			
			topplane.distance = -( ViewProj.m33 - ViewProj.m42 );
			topplane.normal.x = -( ViewProj.m14 - ViewProj.m12 );
			topplane.normal.y = -( ViewProj.m13 - ViewProj.m22 );
			topplane.normal.z = -( ViewProj.m23 - ViewProj.m32 );
			
			bottomplane.distance = -( ViewProj.m33 + ViewProj.m42 );
			bottomplane.normal.x = -( ViewProj.m14 + ViewProj.m12 );
			bottomplane.normal.y = - ( ViewProj.m13 + ViewProj.m22 );
			bottomplane.normal.z = - ( ViewProj.m23 + ViewProj.m32 );
			
			nearplane.distance = -ViewProj.m32;
			nearplane.normal.x = -ViewProj.m13;
			nearplane.normal.y = - ViewProj.m12;
			nearplane.normal.z = - ViewProj.m22;
			
			farplane.distance = -( ViewProj.m33 - ViewProj.m43 );
			farplane.normal.x = -( ViewProj.m14 - ViewProj.m13 );
			farplane.normal.y = -( ViewProj.m13 - ViewProj.m23 );
			farplane.normal.z = -( ViewProj.m23 - ViewProj.m33 );
		}

		const Plane& Near( ) const {
			return nearplane;
		}

		const Plane& Far( ) const {
			return farplane;
		}

		const Plane& Right( ) const {
			return rightplane;
		}

		const Plane& Left( ) const {
			return leftplane;
		}

		const Plane& Top( ) const {
			return topplane;
		}

		const Plane& Bottom( ) const {
			return bottomplane;
		}

		const Matrix& FrustumMatrix( ) const {
			return matrix;
		}

	};
}
