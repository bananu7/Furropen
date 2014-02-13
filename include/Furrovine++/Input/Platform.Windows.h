#pragma once

#include <Furrovine++/Platform.h>
#include <Furrovine++/Input/Key.h>

namespace Furrovine { namespace Input { namespace Windows {

#ifdef FURROVINEWIN

	inline furrovineapi Key VKeyToKey( WPARAM wparam, LPARAM lparam, bool async = false ) {
		auto fx = async ? GetAsyncKeyState : GetKeyState;
		auto check = [ &fx ] ( uint32 code )-> bool {
			USHORT ret = fx( code );
			return AnyFlags( ret, 0x8000 );
		};
		Key key = static_cast<Key>( wparam );
		switch ( key ) {
		case Key::Control:
			if ( check( VK_LCONTROL ) ) {
				key = Key::LeftControl;
			}
			else if ( check( VK_RCONTROL ) ) {
				key = Key::RightControl;
			}
			break;
		case Key::Alt:
			if ( check( VK_LMENU ) ) {
				key = Key::LeftAlt;
			}
			else if ( check( VK_RMENU ) ) {
				key = Key::RightAlt;
			}
			break;
		case Key::Shift:
			if ( check( VK_LSHIFT ) ) {
				key = Key::LeftShift;
			}
			else if ( check( VK_RSHIFT ) ) {
				key = Key::RightShift;
			}
			break;
		}
		return key;
	}

	inline furrovineapi Key ToKey( USHORT scancode, USHORT keybdflags ) {
		if ( HasFlags( keybdflags, RI_KEY_E0 ) ) {
			switch ( scancode ) {
			case 0x1C: return Key::NumpadEnter;
			case 0x1D: return Key::RightControl;
			case 0x35: return Key::NumpadSlash;
			case 0x38: return Key::RightAlt;
			case 0x47: return Key::Home;
			case 0x48: return Key::Up;
			case 0x49: return Key::PageUp;
			case 0x4B: return Key::Left;
			case 0x4D: return Key::Right;
			case 0x4F: return Key::End;
			case 0x50: return Key::Down;
			case 0x51: return Key::PageDown;
			case 0x52: return Key::Insert;
			case 0x53: return Key::Delete;
			default:
				return Key::Unknown;
			}
		}
		else {
			switch ( scancode ) {
			case 0x01: return Key::Escape;
			case 0x02: return Key::D1;
			case 0x03: return Key::D2;
			case 0x04: return Key::D3;
			case 0x05: return Key::D4;
			case 0x06: return Key::D5;
			case 0x07: return Key::D6;
			case 0x08: return Key::D7;
			case 0x09: return Key::D8;
			case 0x0A: return Key::D9;
			case 0x0B: return Key::D0;
			case 0x0C: return Key::NumpadMinus;
			case 0x0D: return Key::Equals;
			case 0x0E: return Key::Backspace;
			case 0x0F: return Key::Tab;
			case 0x10: return Key::Q;
			case 0x11: return Key::W;
			case 0x12: return Key::E;
			case 0x13: return Key::R;
			case 0x14: return Key::T;
			case 0x15: return Key::Y;
			case 0x16: return Key::U;
			case 0x17: return Key::I;
			case 0x18: return Key::O;
			case 0x19: return Key::P;
			case 0x1A: return Key::OpenBrackets;
			case 0x1B: return Key::CloseBrackets;
			case 0x1C: return Key::Enter;
			case 0x1D: return Key::LeftControl;
			case 0x1E: return Key::A;
			case 0x1F: return Key::S;
			case 0x20: return Key::D;
			case 0x21: return Key::F;
			case 0x22: return Key::G;
			case 0x23: return Key::H;
			case 0x24: return Key::J;
			case 0x25: return Key::K;
			case 0x26: return Key::L;
			case 0x27: return Key::Semicolon;
			case 0x28: return Key::Quotes;
			case 0x29: return Key::Tilde;
			case 0x2A: return Key::LeftShift;
			case 0x2B: return Key::Backslash;
			case 0x2C: return Key::Z;
			case 0x2D: return Key::X;
			case 0x2E: return Key::C;
			case 0x2F: return Key::V;
			case 0x30: return Key::B;
			case 0x31: return Key::N;
			case 0x32: return Key::M;
			case 0x33: return Key::Comma;
			case 0x34: return Key::Dot;
			case 0x35: return Key::ForwardSlash;
			case 0x36: return Key::RightShift;
			case 0x37: return Key::NumpadStar;
			case 0x38: return Key::LeftAlt;
			case 0x39: return Key::Space;
			case 0x3A: return Key::CapsLock;
			case 0x3B: return Key::F1;
			case 0x3C: return Key::F2;
			case 0x3D: return Key::F3;
			case 0x3E: return Key::F4;
			case 0x3F: return Key::F5;
			case 0x40: return Key::F6;
			case 0x41: return Key::F7;
			case 0x42: return Key::F8;
			case 0x43: return Key::F9;
			case 0x44: return Key::F10;
			case 0x45: return Key::NumLock;
			case 0x46: return Key::ScrollLock;
			case 0x47: return Key::Numpad7;
			case 0x48: return Key::Numpad8;
			case 0x49: return Key::Numpad9;
			case 0x4A: return Key::NumpadMinus;
			case 0x4B: return Key::Numpad4;
			case 0x4C: return Key::Numpad5;
			case 0x4D: return Key::Numpad6;
			case 0x4E: return Key::NumpadPlus;
			case 0x4F: return Key::Numpad1;
			case 0x50: return Key::Numpad2;
			case 0x51: return Key::Numpad3;
			case 0x52: return Key::Numpad0;
			case 0x53: return Key::NumpadDot;
			case 0x57: return Key::F11;
			case 0x58: return Key::F12;
			default:
				return Key::Unknown;
			}
		}
	}

#endif // WIN

}}}