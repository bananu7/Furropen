#pragma once

#include <Furrovine++/Input/MouseState.h>

namespace Furrovine { namespace Input {

	class MouseDevice {
	private:
		MouseState state, last;
		int dx, dy;
		int rawwheeldx, rawwheeldy;
		int wheeldx, wheeldy;
		int deviceid;
		std::vector<double> downtime;
		MouseButtons downed;
	
	public:
		
		furrovineapi MouseDevice ( int32 device = 0 ) {
			deviceid = device;
			last = MouseState::Dead;
			Update();
			rawwheeldx = rawwheeldy = wheeldx = wheeldy = dx = dy = 0;
		}

		furrovineapi MouseState State () {
			return state;
		}
		
		furrovineapi MouseState LastState () {
			return last;
		}

		furrovineapi int32 DeviceId () {
			return deviceid;
		}

		furrovineapi void Update () {
			last = state;
			state = MouseState::GetState( deviceid );
			dx = state.X() - last.X();
			dy = state.Y() - last.Y();
			wheeldx = state.WheelX();
			wheeldy = state.WheelY();
			rawwheeldx = state.RawWheelX();
			rawwheeldy = state.RawWheelY();
		}

		furrovineapi void Reset () {
			
		}

		furrovineapi bool Connected () {
			return state.Connected();
		}

		furrovineapi int X () {
			return state.X();
		}

		furrovineapi int Y () {
			return state.Y();
		}

		furrovineapi int DeltaX () {
			return dx;
		}

		furrovineapi int DeltaY () {
			return dy;
		}

		furrovineapi int RawScrollX () {
			return rawwheeldx;
		}

		furrovineapi int RawScrollY () {
			return rawwheeldy;
		}

		furrovineapi int ScrollX () {
			return wheeldx;
		}

		furrovineapi int ScrollY () {
			return wheeldy;
		}

		furrovineapi float NormalizedScrollX () {
			return wheeldx / (float)WHEEL_DELTA;
		}

		furrovineapi float NormalizedScrollY () {
			return wheeldy / (float)WHEEL_DELTA;
		}

		furrovineapi Vector2i Scrolli () {
			return Vector2i( ScrollX(), ScrollY() );
		}

		furrovineapi Vector2 Scroll () {
			return Vector2( NormalizedScrollX(), NormalizedScrollY() );
		}

		furrovineapi Vector2i Delta () {
			return Vector2i(dx, dy);
		}

		furrovineapi bool Down ( MouseButtons button ) {
			return state.Down(button);
		}

		furrovineapi bool Up ( MouseButtons button ) {
			return state.Up(button);
		}

		furrovineapi bool Pressed ( MouseButtons button ) {
			return state.Down(button) && last.Up(button);
		}

		furrovineapi bool Released ( MouseButtons button ) {
			return state.Up(button) && last.Down(button);
		}

		furrovineapi bool Held ( MouseButtons button ) {
			return state.Down(button) && last.Down(button);
		}

	};

}}
 
