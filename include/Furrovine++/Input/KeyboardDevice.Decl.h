#pragma once

#include <Furrovine++/std_defines.h>
#include <vector>
#include <array>
#include <Furrovine++/Input/KeyboardState.h>

namespace Furrovine { namespace Input {

	class KeyboardDevice {
	private:
		KeyboardState state;
		KeyboardState last;
		int deviceid;
		std::vector<double> downtime;
		std::vector<Key> downed;

	public:

		furrovineapi KeyboardDevice ( int32 device = 0 );

		furrovineapi KeyboardState State ();

		furrovineapi KeyboardState LastState ();

		furrovineapi bool Connected ();

		furrovineapi void Slot ( uint deviceid );

		furrovineapi uint Slot ();

		furrovineapi void Update ( );

		furrovineapi void Reset ();

		furrovineapi bool ShiftDown ();

		furrovineapi bool ControlDown ();

		furrovineapi bool AltDown ();

		furrovineapi bool Down ( Key key );

		furrovineapi bool Up ( Key key );

		furrovineapi bool Pressed ( Key key );

		furrovineapi bool Released ( Key key );

		furrovineapi bool Held ( Key key );
	};

}}
