#pragma once

#include <Furrovine++/Vector2.h>
#include <Furrovine++/Vector3.h>
#include <Furrovine++/Matrix.h>
#include <Furrovine++/Spherical.h>
#include <Furrovine++/Cylindrical.h>
#include <Furrovine++/Frustum.h>

namespace Furrovine { namespace Graphics {

	class Camera3D {
	protected:
		Vector3 referenceup;
		Vector3 referencelockup;
		Vector3 target;
		Vector3 forward;
		Vector3 position;
		Vector3 strafe;
		Vector3 up;
		Vector3 fov;
		Frustum frustum;
		float aspectratio;
		float nearplane;
		float farplane;
		bool refreshviewproj;
		bool refreshfrustum;
		bool refreshpov;
		bool refreshprojection;

	public:
		Matrix view;
		Matrix projection;
		Matrix viewproj;

		furrovineapi Vector3 GetFov( );

		furrovineapi void SetFov( Vector3 value );

		furrovineapi float GetAspectRatio( );

		furrovineapi void SetAspectRatio( float value );

		furrovineapi float GetNearPlane( );

		furrovineapi void SetNearPlane( float value );

		furrovineapi float GetFarPlane( );

		furrovineapi void SetFarPlane( float value );

		furrovineapi Vector3 GetPosition( );

		furrovineapi void SetPosition( const Vector3& value );

		furrovineapi void SetPosition( float x, float y, float z );

		furrovineapi Vector3 GetTarget( );

		furrovineapi void SetTarget( float x, float y, float z );

		furrovineapi void SetTarget( const Vector3& value );

		furrovineapi Vector3 GetUp( );

		furrovineapi Vector3 GetHeading( );

		furrovineapi Vector3 GetRight( );

		furrovineapi Vector3 GetTargetDirection( );

		furrovineapi Vector3 GetPositionDirection( );

		furrovineapi Matrix GetView( );

		furrovineapi Matrix GetProjection( );

		furrovineapi Matrix GetViewProj( );

		furrovineapi Frustum GetFrustum( );

		furrovineapi Camera3D( );

		furrovineapi Camera3D( Vector3 Pos );

		furrovineapi Camera3D( const Vector3& Pos, const Vector3& Targ, float aspectratio = 16.0f / 9.0f, float fov = 45.0f, float nearp = 0.01f, float farp = 10000.0f );

		furrovineapi void DefinePerspectiveFoV( const Vector3& Fov, float aspectRatio, float nearPlane, float farPlane );

		furrovineapi void DefinePoV( const Vector3& CameraPosition, const Vector3& CameraTarget );

		furrovineapi void DefinePerspectiveFoV( float Fovx, float Fovy, float Fovz, float aspectRatio, float nearPlane, float farPlane );

		furrovineapi void DefinePoV( float CameraPositionX, float CameraPositionY, float CameraPositionZ, float CameraTargetX, float CameraTargetY, float CameraTargetZ );

		furrovineapi void Refresh( );

		furrovineapi void UpdateView( );

		furrovineapi void UpdateProjection( );

		furrovineapi void UpdateFrustum( );

		furrovineapi void UpdateViewProjection( );

		furrovineapi void Update( );

		furrovineapi void Pivot( const Vector2& updownleftright );

		furrovineapi void Pivot( float leftright, float updown );

		furrovineapi void Orbit( const Vector2& leftrightupdown );

		furrovineapi void Orbit( float leftright, float updown );

		furrovineapi void Pan( const Vector2& leftrightupdown );

		furrovineapi void Pan( float leftright, float updown );

		furrovineapi void ZoomBy( float percentage );

		furrovineapi void Zoom( float distance );

		furrovineapi void Track( float distance, bool shifttarget );

		furrovineapi void TrackBy ( float percentage, bool shifttarget );
	};

}}
