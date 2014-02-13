#pragma once

#include <Furrovine++/std_defines.h>
#include <vector>
#include <Furrovine++/Vector2.h>
#include <Furrovine++/Input/MouseButtons.h>

namespace Furrovine { namespace Input {

	class MouseState {
	private:
		furrovineapi static std::vector<MouseState> mousestates;
		int32 deviceid;
		uint32 buttons;
		int32 x, y, wheelx, wheely;
		bool connected, wheeled;

		furrovineapi MouseState ( uint32 Buttons, int32 X = 0, int32 Y = 0, bool connection = true );

		furrovineapi void Reset ();

	public:
		furrovineapi static const MouseState Dead;

		furrovineapi MouseState ();

		furrovineapi bool Connected ();

		furrovineapi int32 DeviceId ();

		furrovineapi int X ();

		furrovineapi int Y ();

		furrovineapi int RawWheelX ();

		furrovineapi int RawWheelY ();

		furrovineapi int WheelX ();

		furrovineapi int WheelY ();

		furrovineapi Vector2i Location ();

		furrovineapi bool Down ( MouseButtons button );

		furrovineapi bool Up ( MouseButtons button );

		furrovineapi static void ManipulateState ( int wheel, bool vertical, int32 x, int32 y, int32 deviceid = 0 );

		furrovineapi static void ManipulateState ( MouseButtons buttons, bool down, int32 x, int32 y, int32 deviceid = 0 );

		furrovineapi static void ResetWheels ( );

		furrovineapi static const MouseState& GetState ( int32 deviceid = 0 );
	};

}}
 