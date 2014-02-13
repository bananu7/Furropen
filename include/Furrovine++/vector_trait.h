#ifndef FURROVINEVECTOR_TRAITS_H
#define FURROVINEVECTOR_TRAITS_H

#include <Furrovine++/platform_d3d.h>

namespace Furrovine {
	
	template <typename T, unsigned int n> 
	struct vector_trait {
		typedef T* TPointer;
		typedef TPointer TApi;
	};

	template <> 
	struct vector_trait<float, 2> {
		typedef float* TPointer;
#ifdef FURROVINEDIRECTX
		typedef DirectX::XMFLOAT2 TApi;
#else
		typedef TPointer TApi;
#endif
	};

	template <> 
	struct vector_trait<float, 3> {
		typedef float* TPointer;
#ifdef FURROVINEDIRECTX
		typedef DirectX::XMFLOAT3 TApi;
#else
		typedef TPointer TApi;
#endif
	};

	template <> 
	struct vector_trait<float, 4> {
		typedef float* TPointer;
#ifdef FURROVINEDIRECTX
		typedef DirectX::XMFLOAT4 TApi;
#else
		typedef TPointer TApi;
#endif
	};

	template <> 
	struct vector_trait<byte, 2> {
	public:
		typedef byte* TPointer;
#ifdef FURROVINEDIRECTX
		typedef DirectX::PackedVector::XMUBYTE2 TApi;
#else
		typedef TPointer TApi;
#endif
	};

	template <> 
	struct vector_trait<byte, 3> {
	public:
		typedef byte* TPointer;
#ifdef FURROVINEDIRECTX
		typedef DirectX::PackedVector::XMUBYTE4 TApi;
#else
		typedef TPointer TApi;
#endif
	};

	template <> 
	struct vector_trait<byte, 4> {
	public:
		typedef byte* TPointer;
#ifdef FURROVINEDIRECTX
		typedef DirectX::PackedVector::XMUBYTE4 TApi;
#else
		typedef TPointer TApi;
#endif
	};

	template <> 
	struct vector_trait<char, 2> {
		typedef char* TPointer;
#ifdef FURROVINEDIRECTX
		typedef DirectX::PackedVector::XMBYTE2 TApi;
#else
		typedef TPointer TApi;
#endif
	};

	template <> 
	struct vector_trait<char, 3> {
		typedef char* TPointer;
#ifdef FURROVINEDIRECTX
		typedef DirectX::PackedVector::XMBYTE4 TApi;
#else
		typedef TPointer TApi;
#endif
	};

	template <> 
	struct vector_trait<char, 4> {
		typedef char* TPointer;
#ifdef FURROVINEDIRECTX
		typedef DirectX::PackedVector::XMBYTE4 TApi;
#else
		typedef TPointer TApi;
#endif
	};

	template <> 
	struct vector_trait<short, 2> {
		typedef short* TPointer;
#ifdef FURROVINEDIRECTX
		typedef DirectX::PackedVector::XMSHORT2 TApi;
#else
		typedef TPointer TApi;
#endif
	};

	template <> 
	struct vector_trait<short, 3> {
		typedef short* TPointer;
#ifdef FURROVINEDIRECTX
		typedef DirectX::PackedVector::XMSHORT4 TApi;
#else
		typedef TPointer TApi;
#endif
	};

	template <> 
	struct vector_trait<short, 4> {
		typedef short* TPointer;
#ifdef FURROVINEDIRECTX
		typedef DirectX::PackedVector::XMSHORT4 TApi;
#else
		typedef TPointer TApi;
#endif
	};

	template <> 
	struct vector_trait<int, 2> {
		typedef int* TPointer;
#ifdef FURROVINEDIRECTX
		typedef DirectX::XMINT2 TApi;
#else
		typedef TPointer TApi;
#endif
	};

	template <> 
	struct vector_trait<int, 3> {
		typedef int* TPointer;
#ifdef FURROVINEDIRECTX
		typedef DirectX::XMINT3 TApi;
#else
		typedef TPointer TApi;
#endif
	};

	template <> 
	struct vector_trait<int, 4> {
		typedef int* TPointer;
#ifdef FURROVINEDIRECTX
		typedef DirectX::XMINT4 TApi;
#else
		typedef TPointer TApi;
#endif
	};
	
}

#endif // FURROVINEVECTOR_TRAITS_H 