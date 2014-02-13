#ifndef FURROVINEPADBUTTONS_H
#define FURROVINEPADBUTTONS_H

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Input {

	static const uint32 PadButtonsDPadBaseBit = 28;
	static const uint32 PadButtonsStickBaseBit = 20;

	enum class Xbox360Buttons : uint32 {
#ifdef XBOX360
		A = 0,
		B = 1,
		X = 2,
		Y = 3,
		LeftButton = 4,
		RightButton = 5,
		Back = 6,
		Start = 7,
		LeftTrigger = 8,
		RightTrigger = 9,
		LeftStick = 10,
		RightStick = 11,
#else
		A = 0x00000001,
		B = 0x00000002,
		X = 0x00000004,
		Y = 0x00000008,
		LeftShoulder = 0x010,
		RightShoulder = 0x020,
		L = 0x010,
		R = 0x020,
		Back = 0x40,
		XStart = 0x80,
		Forward = XStart,
		LeftStick = 0x000000100,
		RightStick = 0x000000200,
		LeftTrigger = 0x0400,
		RightTrigger = 0x0800,
		BigButton = 0x0001000,

		LeftStickUp = 0x00100000,
		LeftStickDown = 0x00400000,
		LeftStickLeft = 0x00800000,
		LeftStickRight = 0x00200000,
		RightStickLeft = 0x08000000,
		RightStickRight = 0x02000000,
		RightStickUp = 0x01000000,
		RightStickDown = 0x04000000,
		DPadLeft = 0x80000000,
		DPadRight = 0x20000000,
		DPadUp = 0x10000000,
		DPadDown = 0x40000000,
#endif
	};

	enum class PlayStation3Buttons : uint32 {
#if VITA || PLAYSTATION3
		Triangle = 0,
		Circle = 1,
		Cross = 2,
		Square = 3,
		LeftButton2 = 4,
		RightButton2 = 5,
		LeftButton1 = 6,
		RightButton1 = 7,
		Select = 8,
		Start = 9,
		LeftButton3 = 10,
		RightButtton3 = 11,
		Home = 12
#else
		Triangle = 0x00000001,
		Circle = 0x00000002,
		Cross = 0x00000004,
		Square = 0x00000008,
		L1 = 0x0000010,
		R1 = 0x0000020,
		L2 = 0x0000040,
		R2 = 0x0000080,
		Select = 0x0100,
		Start = 0x00800,
		L3 = 0x0000200,
		R3 = 0x0000400,
		Home = 0x00001000,

		LeftStickUp = 0x00100000,
		LeftStickDown = 0x00400000,
		LeftStickLeft = 0x00800000,
		LeftStickRight = 0x00200000,
		RightStickLeft = 0x08000000,
		RightStickRight = 0x02000000,
		RightStickUp = 0x01000000,
		RightStickDown = 0x04000000,
		DPadLeft = 0x80000000,
		DPadRight = 0x20000000,
		DPadUp = 0x10000000,
		DPadDown = 0x40000000,
#endif
	};

	enum class GenericPadButtons : uint32 {
		None = 0x0,
		Zero = 0x01,
		One = 0x02,
		Two = 0x04,
		Three = 0x08,
		Four = 0x10,
		Five = 0x20,
		Six = 0x40,
		Seven = 0x80,
		Eight = 0x0100,
		Nine = 0x0200,
		Ten = 0x0400,
		Eleven = 0x0800,
		Twelve = 0x1000,
		Thirteen = 0x2000,
		Fourteen = 0x4000,
		Fifteen = 0x8000,
		Sixteen = 0x10000,
		Seventeen = 0x20000,
		Eighteen = 0x40000
	};

	enum class PadButtons : uint32 {
		None = 0,
#if VITA || PLAYSTATION3
		DPadLeft = 0x10000000,
		DPadRight = 0x20000000,
		DPadUp = 0x40000000,
		DPadDown = 0x80000000,
		BigButton = 1 << PlayStation3Buttons.Home,
		Home = 1 << PlayStation3Buttons.Home,
		Select = 1 << PlayStation3Buttons.Select,
		Back = 1 << PlayStation3Buttons.Select,
		Start = 1 << PlayStation3Buttons.Start,
		Cross = 1 <<PlayStation3Buttons.Cross,
		Circle = 1 << PlayStation3Buttons.Circle,
		Square = 1 << PlayStation3Buttons.Square,
		Triangle = 1 <<PlayStation3Buttons.Triangle,
		A = Cross,
		B = Circle,
		X = Square,
		Y = Triangle,
		LeftShoulder = 1 << PlayStation3Buttons.LeftButton1,
		RightShoulder = 1 << PlayStation3Buttons.RightButton1,
		L = 1 << PlayStation3Buttons.LeftButton1,
		R = 1 << PlayStation3Buttons.RightButton1,
		L1 = 1 << PlayStation3Buttons.LeftButton1,
		R1 = 1 << PlayStation3Buttons.RightButton1,
		LeftStick = 0x00040000,
		RightStick = 0x00080000,
		LeftStickLeft = 0x00100000,
		LeftStickRight = 0x00200000,
		LeftStickUp = 0x00400000,
		LeftStickDown = 0x00800000,
		RightStickLeft = 0x01000000,
		RightStickRight = 0x02000000,
		RightStickUp = 0x04000000,
		RightStickDown = 0x08000000,
		LeftTrigger = 1 << PlayStation3Buttons.LeftButton2,
		RightTrigger = 1 << PlayStation3Buttons.RightButton2,
		L2 = 1 << PlayStation3Buttons.LeftButton2,
		R2 = 1 << PlayStation3Buttons.RightButton2,
		L3 = 1 << PlayStation3Buttons.LeftButton3,
		R3 = 1 << PlayStation3Buttons.RightButton3,
			
		Available = ( PadButtons.Back | PadButtons.Start | PadButtons.Enter | PadButtons.Select | 
		PadButtons.R | PadButtons.L | 
		PadButtons.Circle | PadButtons.Cross | PadButtons.Square | PadButtons.Triangle | 
		PadButtons.DPadUp | PadButtons.DPadDown | PadButtons.DPadRight | PadButtons.DPadLeft | 
		PadButtons.LeftStickDown | PadButtons.LeftStickLeft | PadButtons.LeftStickRight | PadButtons.LeftStickUp |
		PadButtons.RightStickDown | PadButtons.RightStickLeft | PadButtons.RightStickRight | PadButtons.RightStickUp ),
#elif XBOX360
		Home = None,
		BigButton = None,
		Back = 1 << Xbox360Buttons.Back,
		Start = 1 << Xbox360Buttons.Start,
		Select = 1 << Xbox360Buttons.Back,
		Enter = 1 << Xbox360Buttons.Start,
		A = 1 << Xbox360Buttons.A,
		B = 1 << Xbox360Buttons.B,
		X = 1 << Xbox360Buttons.X,
		Y = 1 << Xbox360Buttons.Y,
		Cross = A,
		Circle = B,
		Square = X,
		Triangle = Y,
		LeftShoulder = 1 << Xbox360Buttons.LeftShoulder,
		RightShoulder = 1 << Xbox360Buttons.RightShoulder,
		L = 1 << Xbox360Buttons.LeftShoulder,
		R = 1 << Xbox360Buttons.RightShoulder,
		L1 = 1 << Xbox360Buttons.LeftShoulder,
		R1 = 1 << Xbox360Buttons.RightShoulder,
		LeftTrigger = 1 << Xbox360Buttons.LeftTrigger,
		RightTrigger = 1 << Xbox360Buttons.RightTrigger,
		L2 = 1 << Xbox360Buttons.LeftTrigger,
		R2 = 1 << Xbox360Buttons.RightTrigger,
		L3 = None,
		R3 = None,
		LeftStick = 1 << Xbox360Buttons.LeftStick,
		RightStick = 1 << Xbox360Buttons.RightStick,
		
		LeftStickUp = 0x00100000,
		LeftStickDown = 0x00400000,
		LeftStickLeft = 0x00800000,
		LeftStickRight = 0x00200000,
		RightStickLeft = 0x08000000,
		RightStickRight = 0x02000000,
		RightStickUp = 0x01000000,
		RightStickDown = 0x04000000,
		DPadLeft = 0x80000000,
		DPadRight = 0x20000000,
		DPadUp = 0x10000000,
		DPadDown = 0x40000000,


		Available = ( PadButtons.Back | PadButtons.Start | PadButtons.Enter | PadButtons.Select | 
		PadButtons.RightTrigger | PadButtons.LeftTrigger | PadButtons.RightShoulder | PadButtons.LeftShoulder |   
		PadButtons.Circle | PadButtons.Cross | PadButtons.Square | PadButtons.Triangle | 
		PadButtons.DPadUp | PadButtons.DPadDown | PadButtons.DPadRight | PadButtons.DPadLeft | 
		PadButtons.LeftStick | PadButtons.RightStick | 
		PadButtons.LeftStickDown | PadButtons.LeftStickLeft | PadButtons.LeftStickRight | PadButtons.LeftStickUp |
		PadButtons.RightStickDown | PadButtons.RightStickLeft | PadButtons.RightStickRight | PadButtons.RightStickUp ),
#else
		A = 0x00000001,
		B = 0x00000002,
		X = 0x00000004,
		Y = 0x00000008,
		LeftShoulder = 0x010,
		RightShoulder = 0x020,
		L = 0x010,
		R = 0x020,
		Back = 0x40,
		XStart = 0x80,
		Forward = XStart,
		LeftStick = 0x000000100,
		RightStick = 0x000000200,
		LeftTrigger = 0x0400,
		RightTrigger = 0x0800,
		BigButton = 0x0001000,

		Triangle = 0x00000001,
		Circle = 0x00000002,
		Cross = 0x00000004,
		Square = 0x00000008,
		L1 = 0x0000010,
		R1 = 0x0000020,
		L2 = 0x0000040,
		R2 = 0x0000080,
		Select = 0x0100,
		Start = 0x00800,
		L3 = 0x0000200,
		R3 = 0x0000400,
		Home = 0x00001000,

		LeftStickUp = 0x00100000,
		LeftStickDown = 0x00400000,
		LeftStickLeft = 0x00800000,
		LeftStickRight = 0x00200000,
		RightStickLeft = 0x08000000,
		RightStickRight = 0x02000000,
		RightStickUp = 0x01000000,
		RightStickDown = 0x04000000,
		DPadLeft = 0x40000000,
		DPadRight = 0x80000000,
		DPadUp = 0x10000000,
		DPadDown = 0x20000000,

		Available = ( Back | Start | Forward | Select | 
		RightTrigger | LeftTrigger | RightShoulder | LeftShoulder | R3 | L3 | 
		Circle | Cross | Square | Triangle | 
		DPadUp | DPadDown | DPadRight | DPadLeft | 
		LeftStick | RightStick | 
		LeftStickDown | LeftStickLeft | LeftStickRight | LeftStickUp |
		RightStickDown | RightStickLeft | RightStickRight | RightStickUp ),
#endif
	};

	enumflagoperators( PadButtons );
	enumflagoperators( GenericPadButtons );

#ifndef PLAYSTATION
	enumflagoperators( PlayStation3Buttons );
#endif // PLAYSTATION3 

#ifndef XBOX360
	enumflagoperators( Xbox360Buttons );
#endif // PLAYSTATION3 

}}

#endif // FURROVINEPADBUTTONS_H 