#ifndef FURROVINESUPERSAMPLING_H
#define FURROVINESUPERSAMPLING_H

#include <Furrovine++/Core.h>

namespace Furrovine { namespace Graphics {
	
	/*typedef Vector2 Sampling;
	
	class furrovineexport SuperSampling {
	public:

		static void Grid (Array2D<Sampling>& samplepoints, const uint& n, const uint& m) {
			if (samplepoints.Width() != n || samplepoints.Height() != m) {
				samplepoints.Resize(n, m);
			}
			Grid(samplepoints);
		}

		static void Grid (Array2D<Sampling>& samplepoints) {
			uint n = samplepoints.Width(), m = samplepoints.Height(), y, x;
			for (y = 0; y < m; ++y) {
				samplepoints[y][0].y = y / (T)m;
				for (x = 0; x < n; ++x) {
					samplepoints[y][0].x = x / (T)n;
					samplepoints[y][x].y = samplepoints[y][0].y;
				}
			}
		}

		static void Jittered (Array2D<Sampling>& samplepoints, const uint& n, const uint& m) {
			if (samplepoints.Width() != n || samplepoints.Height() != m) {
				samplepoints.Resize(n, m);
			}
			Jittered(samplepoints);
		}

		static void Jittered (Array2D<Sampling>& samplepoints) {
			uint n = samplepoints.Width(), m = samplepoints.Height(), ix, iy;
			T invn = 1.0f / n, invm = 1.0f / m, x, y;
			for (ix = 0, x = 0; x < n; ++x, ++ix) {
				for (iy = 0, y = 0; y < m; ++y, ++iy) {
					samplepoints[iy][ix].x = (x / n) + Random::RangeFloat() * invn;
					samplepoints[iy][ix].y = (y / m) + Random::RangeFloat() * invm;
				}
			}
		}
	};
	*/
}}

#endif // FURROVINESUPERSAMPLING_H 