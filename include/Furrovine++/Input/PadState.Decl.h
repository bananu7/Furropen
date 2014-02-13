#pragma once

#include <Furrovine++/std_defines.h>
#include <vector>
#include <Furrovine++/FurrovineApi.h>
#include <Furrovine++/Vector2.h>
#include <Furrovine++/Input/DirectionalPad.h>
#include <Furrovine++/Input/PadButtons.h>
#include <Furrovine++/raw_storage.h>

namespace Furrovine { namespace Input {

	class PadState {
	private:
		int32 deviceid;
		bool connected;
		raw_storage<52 + sizeof( void* )> statestorage;

	public:
		furrovineapi static const PadState Dead;

		furrovineapi PadState ();

		furrovineapi int32 DeviceId ();

		furrovineapi PadButtons Buttons ();

		furrovineapi Vector2 Rumble ();

		furrovineapi void Rumble ( int32 motorid, float rumblemagnitude );

		furrovineapi void Rumble ( float rumblemagnitude );

		furrovineapi bool Down ( PadButtons button );

		furrovineapi bool Up ( PadButtons button );

		furrovineapi int32 Axis1 ();

		furrovineapi float NormalizedAxis1 ();

		furrovineapi int32 Axis2 ();

		furrovineapi float NormalizedAxis2 ();

		furrovineapi int32 Axis3 ();

		furrovineapi float NormalizedAxis3 ();

		furrovineapi int32 Axis4 ();

		furrovineapi float NormalizedAxis4 ();

		furrovineapi int32 Axis5 ();

		furrovineapi float NormalizedAxis5 ();

		furrovineapi int32 Axis6 ();

		furrovineapi float NormalizedAxis6 ();

		furrovineapi int32 AxisX ();

		furrovineapi float NormalizedAxisX ();

		furrovineapi int32 AxisY ();

		furrovineapi float NormalizedAxisY ();

		furrovineapi int32 AxisZ ();

		furrovineapi float NormalizedAxisZ ();

		furrovineapi int32 AxisR ();

		furrovineapi float NormalizedAxisR ();

		furrovineapi int32 AxisU ();

		furrovineapi float NormalizedAxisU ();

		furrovineapi int32 AxisV ();

		furrovineapi float NormalizedAxisV ();

		furrovineapi Vector2 LeftStick ( );

		furrovineapi Vector2 Triggers ( );

		furrovineapi Vector2 RightStick ( );

		furrovineapi DirectionalPad DPad ();

		furrovineapi float DPadAngle ();

		furrovineapi int32 DPadMilliAngleDegrees ();

		furrovineapi ~PadState ();

		furrovineapi static void ManipulateState ( );

		furrovineapi static void ManipulateState ( int32 deviceid );

		furrovineapi static const PadState& GetState ( int32 deviceid = 0 );
	};

}}
 