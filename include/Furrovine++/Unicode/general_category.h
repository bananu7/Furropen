#pragma  once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Unicode {

	enum class general_category {
		Lu = 0x0001,
		Ll = 0x0002,
		Lt = 0x0004,
		Lc = Lu | Ll | Lt,
		Lm = 0x0008,
		Lo = 0x0010,
		L = Lu | Ll | Lt | Lm | Lo,
		Mn = 0x0020,
		Mc = 0x0040,
		Me = 0x0080,
		M = Mc | Mn | Me,
		Nd = 0x0100,
		Nl = 0x0200,
		No = 0x0400,
		N = Nd | Nl | No,
		Pc = 0x0800,
		Pd = 0x1000,
		Ps = 0x2000,
		Pe = 0x4000,
		Pi = 0x8000,
		Pf = 0x00010000,
		Po = 0x00020000,
		P = Pc | Pd | Ps | Pe | Pi | Pf | Po,
		Sm = 0x00040000,
		Sc = 0x00080000,
		Sk = 0x00100000,
		So = 0x00200000,
		S = Sm | Sc | Sk | So,
		Zs = 0x00400000,
		Zl = 0x00800000,
		Zp = 0x01000000,
		Z = Zs | Zl | Zp,
		Cc = 0x02000000,
		Cf = 0x04000000,
		Cs = 0x08000000,
		Co = 0x10000000,
		Cn = 0x20000000,
		C = Cc | Cf | Cs | Co | Cn
	};

	enumflagoperators( general_category );

}}