#pragma once

namespace Furrovine {
	
	template <typename T, unsigned int n, unsigned int m> 
	struct matrix_trait {
		typedef T* TPointer;
		typedef TPointer TApi;
	};

	template <> 
	struct matrix_trait<float, 4, 4> {
	public:
		typedef float* TPointer;
#ifdef FURROVINEDIRECTX
		typedef DirectX::XMMATRIX TApi;
#else
		typedef TPointer TApi;
#endif
	};

	template <> 
	struct matrix_trait<float, 3, 3> {
	public:
		typedef float* TPointer;
#ifdef FURROVINEDIRECTX
		typedef DirectX::XMFLOAT3X3 TApi;
#else
		typedef TPointer TApi;
#endif
	};
}
