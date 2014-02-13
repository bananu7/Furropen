#pragma once

#include <Furrovine++/RVector.h>

namespace Furrovine {
	
	template <typename T>
	struct RVector2 : public RVector<RVector2<T>, T, 2> {
		union {
			std::array<T, 2> res;
			struct {
				T x, y;
			};
			struct {
				T r, g;
			};
			struct {
				T s, t;
			};

			detail::swizzler<T, 2, 0, 0, 0, 0> xxxx;
			detail::swizzler<T, 2, 0, 0, 0, 1> xxxy;
			detail::swizzler<T, 2, 0, 0, 1, 0> xxyx;
			detail::swizzler<T, 2, 0, 0, 1, 1> xxyy;
			detail::swizzler<T, 2, 0, 1, 0, 0> xyxx;
			detail::swizzler<T, 2, 0, 1, 0, 1> xyxy;
			detail::swizzler<T, 2, 0, 1, 1, 0> xyyx;
			detail::swizzler<T, 2, 0, 1, 1, 1> xyyy;
			detail::swizzler<T, 2, 1, 0, 0, 0> yxxx;
			detail::swizzler<T, 2, 1, 0, 0, 1> yxxy;
			detail::swizzler<T, 2, 1, 0, 1, 0> yxyx;
			detail::swizzler<T, 2, 1, 0, 1, 1> yxyy;
			detail::swizzler<T, 2, 1, 1, 0, 0> yyxx;
			detail::swizzler<T, 2, 1, 1, 0, 1> yyxy;
			detail::swizzler<T, 2, 1, 1, 1, 0> yyyx;
			detail::swizzler<T, 2, 1, 1, 1, 1> yyyy;
			detail::swizzler<T, 2, 0, 0, 0> xxx;
			detail::swizzler<T, 2, 0, 0, 1> xxy;
			detail::swizzler<T, 2, 0, 1, 0> xyx;
			detail::swizzler<T, 2, 0, 1, 1> xyy;
			detail::swizzler<T, 2, 1, 0, 0> yxx;
			detail::swizzler<T, 2, 1, 0, 1> yxy;
			detail::swizzler<T, 2, 1, 1, 0> yyx;
			detail::swizzler<T, 2, 1, 1, 1> yyy;
			detail::swizzler<T, 2, 0> xx;
			detail::swizzler<T, 2, 1> yy;
			detail::swizzler<T, 2, 0, 1> xy;
			detail::swizzler<T, 2, 1, 0> yx;

			detail::swizzler<T, 2, 0, 0, 0, 0> ssss;
			detail::swizzler<T, 2, 0, 0, 0, 1> ssst;
			detail::swizzler<T, 2, 0, 0, 1, 0> ssts;
			detail::swizzler<T, 2, 0, 0, 1, 1> sstt;
			detail::swizzler<T, 2, 0, 1, 0, 0> stss;
			detail::swizzler<T, 2, 0, 1, 0, 1> stst;
			detail::swizzler<T, 2, 0, 1, 1, 0> stts;
			detail::swizzler<T, 2, 0, 1, 1, 1> sttt;
			detail::swizzler<T, 2, 1, 0, 0, 0> tsss;
			detail::swizzler<T, 2, 1, 0, 0, 1> tsst;
			detail::swizzler<T, 2, 1, 0, 1, 0> tsts;
			detail::swizzler<T, 2, 1, 0, 1, 1> tstt;
			detail::swizzler<T, 2, 1, 1, 0, 0> ttss;
			detail::swizzler<T, 2, 1, 1, 0, 1> ttst;
			detail::swizzler<T, 2, 1, 1, 1, 0> ttts;
			detail::swizzler<T, 2, 1, 1, 1, 1> tttt;
			detail::swizzler<T, 2, 0, 0, 0> sss;
			detail::swizzler<T, 2, 0, 0, 1> sst;
			detail::swizzler<T, 2, 0, 1, 0> sts;
			detail::swizzler<T, 2, 0, 1, 1> stt;
			detail::swizzler<T, 2, 1, 0, 0> tss;
			detail::swizzler<T, 2, 1, 0, 1> tst;
			detail::swizzler<T, 2, 1, 1, 0> tts;
			detail::swizzler<T, 2, 1, 1, 1> ttt;
			detail::swizzler<T, 2, 0> ss;
			detail::swizzler<T, 2, 1> tt;
			detail::swizzler<T, 2, 0, 1> st;
			detail::swizzler<T, 2, 1, 0> ts;

			detail::swizzler<T, 2, 0, 0, 0, 0> rrrr;
			detail::swizzler<T, 2, 0, 0, 0, 1> rrrg;
			detail::swizzler<T, 2, 0, 0, 1, 0> rrgr;
			detail::swizzler<T, 2, 0, 0, 1, 1> rrgg;
			detail::swizzler<T, 2, 0, 1, 0, 0> rgrr;
			detail::swizzler<T, 2, 0, 1, 0, 1> rgrg;
			detail::swizzler<T, 2, 0, 1, 1, 0> rggr;
			detail::swizzler<T, 2, 0, 1, 1, 1> rggg;
			detail::swizzler<T, 2, 1, 0, 0, 0> grrr;
			detail::swizzler<T, 2, 1, 0, 0, 1> grrg;
			detail::swizzler<T, 2, 1, 0, 1, 0> grgr;
			detail::swizzler<T, 2, 1, 0, 1, 1> grgg;
			detail::swizzler<T, 2, 1, 1, 0, 0> ggrr;
			detail::swizzler<T, 2, 1, 1, 0, 1> ggrg;
			detail::swizzler<T, 2, 1, 1, 1, 0> gggr;
			detail::swizzler<T, 2, 1, 1, 1, 1> gggg;
			detail::swizzler<T, 2, 0, 0, 0> rrr;
			detail::swizzler<T, 2, 0, 0, 1> rrg;
			detail::swizzler<T, 2, 0, 1, 0> rgr;
			detail::swizzler<T, 2, 0, 1, 1> rgg;
			detail::swizzler<T, 2, 1, 0, 0> grr;
			detail::swizzler<T, 2, 1, 0, 1> grg;
			detail::swizzler<T, 2, 1, 1, 0> ggr;
			detail::swizzler<T, 2, 1, 1, 1> ggg;
			detail::swizzler<T, 2, 0> rr;
			detail::swizzler<T, 2, 1> gg;
			detail::swizzler<T, 2, 0, 1> rg;
			detail::swizzler<T, 2, 1, 0> gr;
		};
	};

} 
