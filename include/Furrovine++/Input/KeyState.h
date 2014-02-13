#pragma once

#include <Furrovine++/numeric_def.h>

namespace Furrovine { namespace Input {

	struct KeyState {
		static const uint32 DownBit = 25;

		uint32 Data;

		void SetData ( uint32 data, bool down ) {
			Data = data;
			Data &= ~( 1 << DownBit );
			Data |= down << DownBit;
		}

		int RepeatCount () const {
			return Data & 0xFF;
		}

		int ScanCode () const {
			return ( Data >> 16 ) & 0x7F;
		}

		bool Extended () const {
			return ( Data >> 24 ) & 0x01;
		}

		int Context () const {
			return ( Data >> 29 ) & 0x01;
		}

		bool Transition () const {
			return ( Data >> 31 ) & 0x01;
		}

		bool Down () const {
			return ( Data >> DownBit ) & 0x01;
		}

		bool Up () const {
			return !Down( );
		}

		bool PreviousDown () const {
			return ( Data >> 29 ) & 0x01;
		}

		bool PreviousUp () const {
			return !PreviousDown( );
		}

		bool PreviousDown () const {
			return ( Data >> 29 ) & 0x01;
		}

		bool PreviousUp () const {
			return !PreviousDown( );
		}

	}

}}
