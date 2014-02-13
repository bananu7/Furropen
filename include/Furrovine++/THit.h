#pragma once

#include <Furrovine++/optional.h>
#include <Furrovine++/Ray3.h>
#include <Furrovine++/Vector3.h>
#include <Furrovine++/TNormal3.h>
#include <Furrovine++/RTriangle.h>
#include <Furrovine++/RPlane.h>
#include <Furrovine++/RSphere.h>
#include <Furrovine++/RDisk.h>

namespace Furrovine {

	template <typename T>
	struct THit {
		T distance0;
		T distance1;
		TVector3<T> contact;
		TNormal3<T> normal;
		TVector3<T> uvw;
	};

	template <typename T>
	optional<THit<T>> intersect( const TRay3<T>& ray, const RPlane<T>& target ) {
		T denom = ray.direction.dot( target.normal );
		if ( denom <= static_cast<T>( 0 ) )
			return nullopt;

		THit<T> hit;
		hit.distance0 = ( target.normal.dot( ray.origin ) + target.distance ) / denom;
		hit.contact = ray.at( hit.distance0 );
		hit.normal = target.normal;
		return hit;
	}

	template <typename T>
	optional<THit<T>> intersect( const TRay3<T>& ray, const RSphere<T>& target ) {
		RVector3<T> L = target.origin - ray.origin; 
		T tca = L.dot( ray.direction ); 
		if ( tca < 0 ) 
			return nullopt; 
		T radiussquared = target.radius * target.radius;
		T d2 = L.dot( L ) - tca * tca;
		if ( d2 > radiussquared ) 
			return nullopt;
		T thc = static_cast<T>( std::sqrt( radiussquared - d2 ) );
		
		THit<T> hit;
		hit.distance0 = tca - thc;
		hit.distance1 = tca + thc;

		hit.contact = ray.at( hit.distance0 );
		hit.normal = target.origin - hit.contact;
		hit.normal.normalize( );

		return hit;
	}

	template <typename T>
	optional<THit<T>> intersect( const TRay3<T>& ray, const RTriangle<T>& target ) {
		RVector3<T> edge1( target.b ), edge2( target.c );
		edge1 -= target.a;
		edge2 -= target.b;

		RVector3<T> crossproduct( cross( ray.direction, edge2 ) );

		T dotproduct = edge1.dot( crossproduct );

		if ( dotproduct == static_cast<T>(0) )
			return nullopt;

		THit<T> hit;
		
		RVector3<T> vdist( ray.origin - target.a );

		hit.uvw.x = vdist.dot( crossproduct ) / dotproduct;
		if ( hit.uvw.x < static_cast<T>( 0 ) || hit.uvw.x > static_cast<T>( 1 ) )
			return nullopt;

		RVector3<T> vrdist( vdist.cross( edge1 ) );

		hit.uvw.y = dot( ray.direction, vrdist ) / dotproduct;
		if ( hit.uvw.y < static_cast<T>( 0 ) || hit.uvw.x + hit.uvw.y > static_cast<T>( 1 ) )
			return nullopt;

		hit.distance0 = edge2.dot( vrdist ) / dotproduct;
		hit.normal = target.normal( );
		hit.contact = ray.at( hit.distance0 );
		return hit;
	}

	template <typename T>
	optional<THit<T>> intersect( const TRay3<T>& ray, const RDisk<T>& target ) {
		T d = 0;
		auto planehit = intersect( ray, target.plane );
		if ( planehit ) {
			RVector3<T> p = ray.origin + ray.direction * d; 
			RVector3<T> v = p - target.origin; 
			T d2 = v.dot( v ); 
			if ( d2 <= target.radius * target.radius )
				return planehit;
		} 
		return nullopt;
	}

}