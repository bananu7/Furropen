#ifndef FURROVINEPADDEVICE_H
#define FURROVINEPADDEVICE_H

#include <Furrovine++/Input/InputCore.h>
#include <Furrovine++/Input/PadState.h>

namespace Furrovine { namespace Input {

	class PadDevice {
	private:
		static const double releasedouble;
		int32 deviceid;
		PadState state;
		PadState last;
		std::vector<double> downtime;
		PadButtons downed;

	public:
		
		furrovineapi PadState State () {
			return state;
		}

		furrovineapi PadState LastState () {
			return last;
		}

		furrovineapi int DeviceId () {
			return deviceid;
		}

		furrovineapi PadButtons Buttons () {
			return state.Buttons();
		}

		furrovineapi PadButtons DownedButtons () {
			return downed;
		}

		furrovineapi PadDevice ( int32 device = 0 ) : downed( PadButtons::None ), deviceid( device ) {
			deviceid = device;
			state = PadState::Dead;
			Update();
		}

		furrovineapi void Update () {
			last = state;
			state = PadState::GetState( deviceid );
			downed = state.Buttons();
			
		}

		furrovineapi void Rumble ( int32 motorid, float magnitude ) {
			state.Rumble( motorid, magnitude );
		}

		furrovineapi void Rumble ( float magnitude ) {
			state.Rumble( 0, magnitude );
			state.Rumble( 1, magnitude );
		}

		furrovineapi bool Down (PadButtons button) {
			return state.Down(button);
		}

		furrovineapi bool Up (PadButtons button) {
			return state.Up(button);
		}

		furrovineapi bool Pressed (PadButtons button) {
			return last.Down(button) && state.Up(button);
		}

		furrovineapi bool Released (PadButtons button) {
			return last.Down(button) && state.Up(button);
		}

		furrovineapi bool Held (PadButtons button) {
			return last.Down(button) && state.Up(button);
		}

	};

#ifdef FURROVINECOMPILE

	const double PadDevice::releasedouble = -0.0000001;

#endif // FURROVINECOMPILE 

}}

#endif // FURROVINEPADDEVICE_H 
