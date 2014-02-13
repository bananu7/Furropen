#pragma once

#include <Furrovine++/big_constant.h>
#include <Furrovine++/rotl.h>
#include <Furrovine++/Export.h>
#include <Furrovine++/inline.h>
#include <Furrovine++/Mathema.h>

namespace Furrovine {

	struct Hashers {
	public:
		furrovineapi static const uint32 HashSeed32 = (uint32)6553765537;
		furrovineapi static const uint64 HashSeed64 = (uint64)0x14074431CADeEFFF;

		furrovineapi inlinealways static ushort get16bits ( const void* p ) {
			return *((const ushort*)p);
		}

		furrovineapi inlinealways static uint32 getblock ( const uint32 * p, const lword i ) {
			return p[i];
		}

		furrovineapi inlinealways static ullong getblock ( const uint64* p, const lword i ) {
			return p[i];
		}

		furrovineapi inlinealways static uint32 fmix ( uint32 h ) {
			h ^= h >> 16;
			h *= 0x85ebca6b;
			h ^= h >> 13;
			h *= 0xc2b2ae35;
			h ^= h >> 16;

			return h;
		}

		furrovineapi inlinealways static uint64 fmix ( uint64 k ) {
			k ^= k >> 33;
			k *= BIG_CONSTANT(0xff51afd7ed558ccd);
			k ^= k >> 33;
			k *= BIG_CONSTANT(0xc4ceb9fe1a85ec53);
			k ^= k >> 33;

			return k;
		}

		furrovineapi inlinealways static void hashmix (ulword& a, ulword& b, ulword& c) {
			a -= b; a -= c; a ^= (c>>13);
			b -= c; b -= a; b ^= (a<<8);
			c -= a; c -= b; c ^= (b>>13);
			a -= b; a -= c; a ^= (c>>12); 
			b -= c; b -= a; b ^= (a<<16);
			c -= a; c -= b; c ^= (b>>5);
			a -= b; a -= c; a ^= (c>>3);
			b -= c; b -= a; b ^= (a<<10);
			c -= a; c -= b; c ^= (b>>15);
		}
	
		furrovineapi static void HseishHash (const void* key, lword len, void* out) {
			ulword hash = 0, tmp;
			const byte* data = (const byte*)key;
			lword rem;

			if (len <= 0 || data == NULL) {
				*(ulword *)out = hash;
				return;
			}
			rem = len & 3;
			len >>= 2;

			/* Main loop */
			for (;len > 0; len--) {
				hash  += get16bits(data);
				tmp    = (get16bits(data+2) << 11) ^ hash;
				hash   = (hash << 16) ^ tmp;
				data  += 2*sizeof (ushort);
				hash  += hash >> 11;
			}

			/* Handle end cases */
			switch (rem) {
			case 3:	hash += get16bits (data);
				hash ^= hash << 16;
				hash ^= data[sizeof (ushort)] << 18;
				hash += hash >> 11;
				break;
			case 2:	hash += get16bits (data);
				hash ^= hash << 11;
				hash += hash >> 17;
				break;
			case 1: hash += *data;
				hash ^= hash << 10;
				hash += hash >> 1;
			}

			/* Force "avalanching" of final 127 bits */
			hash ^= hash << 3;
			hash += hash >> 5;
			hash ^= hash << 4;
			hash += hash >> 17;
			hash ^= hash << 25;
			hash += hash >> 6;

			*(ulword *)out = hash;
		}

		furrovineapi static void FowlerNollVo1a (const void* key, const lword len, void* out) {
			lword i = 0;
			ulword & hash = *((ulword *)out);
			const char*& data = (const char*&)key;
			hash = 2166136261;
			while (i < len)
				hash = (hash ^ data[i++]) * 16777619;
		}

		furrovineapi static void Firefox3Cache (const void* key, const lword& len, const ulword seed, void* out) {
			const ulword * k = reinterpret_cast<const ulword *>(key);
			ulword a, b, c, length;

			/* Set up the internal state */
			length = len;

			a = b = 0x9e3779b9;  /* the golden ratio; an arbitrary value */
			c = seed;         /* variable initialization of internal state */

			/*---------------------------------------- handle most of the key */
			while (len >= 12) {
				a += k[0] + (ulword (k[1])<<8) + (ulword (k[2])<<16) + (ulword (k[3])<<24);
				b += k[4] + (ulword (k[5])<<8) + (ulword (k[6])<<16) + (ulword (k[7])<<24);
				c += k[8] + (ulword (k[9])<<8) + (ulword (k[10])<<16) + (ulword (k[11])<<24);
				hashmix(a, b, c);
				k += 12; length -= 12;
			}

			/*------------------------------------- handle the last 11 bytes */
			c += len;

			switch (len) {              /* all the case statements fall through */
			case 11: c += (ulword (k[10])<<24);
			case 10: c += (ulword (k[9])<<16);
			case 9 : c += (ulword (k[8])<<8);
				/* the low-order byte of c is reserved for the length */
			case 8 : b += (ulword (k[7])<<24);
			case 7 : b += (ulword (k[6])<<16);
			case 6 : b += (ulword (k[5])<<8);
			case 5 : b += k[4];
			case 4 : a += (ulword (k[3])<<24);
			case 3 : a += (ulword (k[2])<<16);
			case 2 : a += (ulword (k[1])<<8);
			case 1 : a += k[0];
				/* case 0: nothing left to add */
			}

			hashmix(a, b, c);

			*((ulword *)out) = c;
		}

		furrovineapi static void MurmurHash32 ( const void* key, const ulword len, uint32 seed, void* out) {
			return MurmurHash32x86(key, len, seed, out);
		}

		furrovineapi static void MurmurHash64 ( const void* key, const ulword len, uint32 seed, void* out) {
#ifdef FURROVINEX86
			return MurmurHash64x86(key, len, seed, out);
#elif FURROVINEX64
			return MurmurHash64x64(key, len, seed, out);
#else
#error Platform is not 64-bit or 32-bit
#endif
		}

		furrovineapi static void MurmurHash128 ( const void* key, const ulword len, uint32 seed, void* out) {
#ifdef FURROVINEX86
			return MurmurHash128x86(key, len, seed, out);
#elif FURROVINEX64
			return MurmurHash128x64(key, len, seed, out);
#else
#error Platform is not 64-bit or 32-bit
#endif
		}

		furrovineapi static void MurmurHash32x86 ( const void * key, lword len,
			uint32 seed, void * out )
		{
			const uint8 * data = (const uint8*)key;
			const lword nblocks = len / 4;

			uint32 h1 = seed;

			const uint32 c1 = 0xcc9e2d51;
			const uint32 c2 = 0x1b873593;

			//----------
			// body

			const uint32 * blocks = (const uint32 *)(data + nblocks*4);

			for(lword i = -nblocks; i; i++)
			{
				uint32 k1 = getblock(blocks,i);

				k1 *= c1;
				k1 = ROTL32(k1,15);
				k1 *= c2;

				h1 ^= k1;
				h1 = ROTL32(h1,13);
				h1 = h1*5+0xe6546b64;
			}

			//----------
			// tail

			const uint8 * tail = (const uint8*)(data + nblocks*4);

			uint32 k1 = 0;

			switch(len & 3)
			{
			case 3: k1 ^= tail[2] << 16;
			case 2: k1 ^= tail[1] << 8;
			case 1: k1 ^= tail[0];
				k1 *= c1; k1 = ROTL32(k1,15); k1 *= c2; h1 ^= k1;
			};

			//----------
			// finalization

			h1 ^= len;

			h1 = fmix(h1);

			*(uint32*)out = h1;
		}

		//-----------------------------------------------------------------------------

		furrovineapi static void MurmurHash128x86 ( const void * key, const lword len,
			uint32 seed, void * out )
		{
			const uint8 * data = (const uint8*)key;
			const lword nblocks = len / 16;

			uint32 h1 = seed;
			uint32 h2 = seed;
			uint32 h3 = seed;
			uint32 h4 = seed;

			const uint32 c1 = 0x239b961b;
			const uint32 c2 = 0xab0e9789;
			const uint32 c3 = 0x38b34ae5;
			const uint32 c4 = 0xa1e38b93;

			//----------
			// body

			const uint32 * blocks = (const uint32 *)(data + nblocks*16);

			for(lword i = -nblocks; i; i++)
			{
				uint32 k1 = getblock(blocks,i*4+0);
				uint32 k2 = getblock(blocks,i*4+1);
				uint32 k3 = getblock(blocks,i*4+2);
				uint32 k4 = getblock(blocks,i*4+3);

				k1 *= c1; k1  = ROTL32(k1,15); k1 *= c2; h1 ^= k1;

				h1 = ROTL32(h1,19); h1 += h2; h1 = h1*5+0x561ccd1b;

				k2 *= c2; k2  = ROTL32(k2,16); k2 *= c3; h2 ^= k2;

				h2 = ROTL32(h2,17); h2 += h3; h2 = h2*5+0x0bcaa747;

				k3 *= c3; k3  = ROTL32(k3,17); k3 *= c4; h3 ^= k3;

				h3 = ROTL32(h3,15); h3 += h4; h3 = h3*5+0x96cd1c35;

				k4 *= c4; k4  = ROTL32(k4,18); k4 *= c1; h4 ^= k4;

				h4 = ROTL32(h4,13); h4 += h1; h4 = h4*5+0x32ac3b17;
			}

			//----------
			// tail

			const uint8 * tail = (const uint8*)(data + nblocks*16);

			uint32 k1 = 0;
			uint32 k2 = 0;
			uint32 k3 = 0;
			uint32 k4 = 0;

			switch(len & 15)
			{
			case 15: k4 ^= tail[14] << 16;
			case 14: k4 ^= tail[13] << 8;
			case 13: k4 ^= tail[12] << 0;
				k4 *= c4; k4  = ROTL32(k4,18); k4 *= c1; h4 ^= k4;

			case 12: k3 ^= tail[11] << 24;
			case 11: k3 ^= tail[10] << 16;
			case 10: k3 ^= tail[ 9] << 8;
			case  9: k3 ^= tail[ 8] << 0;
				k3 *= c3; k3  = ROTL32(k3,17); k3 *= c4; h3 ^= k3;

			case  8: k2 ^= tail[ 7] << 24;
			case  7: k2 ^= tail[ 6] << 16;
			case  6: k2 ^= tail[ 5] << 8;
			case  5: k2 ^= tail[ 4] << 0;
				k2 *= c2; k2  = ROTL32(k2,16); k2 *= c3; h2 ^= k2;

			case  4: k1 ^= tail[ 3] << 24;
			case  3: k1 ^= tail[ 2] << 16;
			case  2: k1 ^= tail[ 1] << 8;
			case  1: k1 ^= tail[ 0] << 0;
				k1 *= c1; k1  = ROTL32(k1,15); k1 *= c2; h1 ^= k1;
			};

			//----------
			// finalization

			h1 ^= len; h2 ^= len; h3 ^= len; h4 ^= len;

			h1 += h2; h1 += h3; h1 += h4;
			h2 += h1; h3 += h1; h4 += h1;

			h1 = fmix(h1);
			h2 = fmix(h2);
			h3 = fmix(h3);
			h4 = fmix(h4);

			h1 += h2; h1 += h3; h1 += h4;
			h2 += h1; h3 += h1; h4 += h1;

			((uint32*)out)[0] = h1;
			((uint32*)out)[1] = h2;
			((uint32*)out)[2] = h3;
			((uint32*)out)[3] = h4;
		}

		furrovineapi static void MurmurHash128x64 ( const void * key, const lword len,
			const uint32 seed, void * out )
		{
			const uint8 * data = (const uint8*)key;
			const lword nblocks = len / 16;

			uint64 h1 = seed;
			uint64 h2 = seed;

			const uint64 c1 = BIG_CONSTANT(0x87c37b91114253d5);
			const uint64 c2 = BIG_CONSTANT(0x4cf5ad432745937f);

			//----------
			// body

			const uint64 * blocks = (const uint64 *)(data);

			for(lword i = 0; i < nblocks; i++)
			{
				uint64 k1 = getblock(blocks,i*2+0);
				uint64 k2 = getblock(blocks,i*2+1);

				k1 *= c1; k1  = ROTL64(k1,31); k1 *= c2; h1 ^= k1;

				h1 = ROTL64(h1,27); h1 += h2; h1 = h1*5+0x52dce729;

				k2 *= c2; k2  = ROTL64(k2,33); k2 *= c1; h2 ^= k2;

				h2 = ROTL64(h2,31); h2 += h1; h2 = h2*5+0x38495ab5;
			}

			//----------
			// tail

			const uint8 * tail = (const uint8*)(data + nblocks*16);

			uint64 k1 = 0;
			uint64 k2 = 0;

			switch(len & 15)
			{
			case 15: k2 ^= uint64(tail[14]) << 48;
			case 14: k2 ^= uint64(tail[13]) << 40;
			case 13: k2 ^= uint64(tail[12]) << 32;
			case 12: k2 ^= uint64(tail[11]) << 24;
			case 11: k2 ^= uint64(tail[10]) << 16;
			case 10: k2 ^= uint64(tail[ 9]) << 8;
			case  9: k2 ^= uint64(tail[ 8]) << 0;
				k2 *= c2; k2  = ROTL64(k2,33); k2 *= c1; h2 ^= k2;

			case  8: k1 ^= uint64(tail[ 7]) << 56;
			case  7: k1 ^= uint64(tail[ 6]) << 48;
			case  6: k1 ^= uint64(tail[ 5]) << 40;
			case  5: k1 ^= uint64(tail[ 4]) << 32;
			case  4: k1 ^= uint64(tail[ 3]) << 24;
			case  3: k1 ^= uint64(tail[ 2]) << 16;
			case  2: k1 ^= uint64(tail[ 1]) << 8;
			case  1: k1 ^= uint64(tail[ 0]) << 0;
				k1 *= c1; k1  = ROTL64(k1,31); k1 *= c2; h1 ^= k1;
			};

			//----------
			// finalization

			h1 ^= len; h2 ^= len;

			h1 += h2;
			h2 += h1;

			h1 = fmix(h1);
			h2 = fmix(h2);

			h1 += h2;
			h2 += h1;

			((uint64*)out)[0] = h1;
			((uint64*)out)[1] = h2;
		}

		furrovineapi static void MurmurHash64x86 ( const void * key, const lword len,
			uint32 seed, void * out )
		{
			const uint8 * data = (const uint8*)key;
			const lword nblocks = len / 16;

			uint32 h1 = seed;
			uint32 h2 = seed;
			uint32 h3 = seed;
			uint32 h4 = seed;

			const uint32 c1 = 0x239b961b;
			const uint32 c2 = 0xab0e9789;
			const uint32 c3 = 0x38b34ae5;
			const uint32 c4 = 0xa1e38b93;

			//----------
			// body

			const uint32 * blocks = (const uint32 *)(data + nblocks*16);

			for(lword i = -nblocks; i; i++)
			{
				uint32 k1 = getblock(blocks,i*4+0);
				uint32 k2 = getblock(blocks,i*4+1);
				uint32 k3 = getblock(blocks,i*4+2);
				uint32 k4 = getblock(blocks,i*4+3);

				k1 *= c1; k1  = ROTL32(k1,15); k1 *= c2; h1 ^= k1;

				h1 = ROTL32(h1,19); h1 += h2; h1 = h1*5+0x561ccd1b;

				k2 *= c2; k2  = ROTL32(k2,16); k2 *= c3; h2 ^= k2;

				h2 = ROTL32(h2,17); h2 += h3; h2 = h2*5+0x0bcaa747;

				k3 *= c3; k3  = ROTL32(k3,17); k3 *= c4; h3 ^= k3;

				h3 = ROTL32(h3,15); h3 += h4; h3 = h3*5+0x96cd1c35;

				k4 *= c4; k4  = ROTL32(k4,18); k4 *= c1; h4 ^= k4;

				h4 = ROTL32(h4,13); h4 += h1; h4 = h4*5+0x32ac3b17;
			}

			//----------
			// tail

			const uint8 * tail = (const uint8*)(data + nblocks*16);

			uint32 k1 = 0;
			uint32 k2 = 0;
			uint32 k3 = 0;
			uint32 k4 = 0;

			switch(len & 15)
			{
			case 15: k4 ^= tail[14] << 16;
			case 14: k4 ^= tail[13] << 8;
			case 13: k4 ^= tail[12] << 0;
				k4 *= c4; k4  = ROTL32(k4,18); k4 *= c1; h4 ^= k4;

			case 12: k3 ^= tail[11] << 24;
			case 11: k3 ^= tail[10] << 16;
			case 10: k3 ^= tail[ 9] << 8;
			case  9: k3 ^= tail[ 8] << 0;
				k3 *= c3; k3  = ROTL32(k3,17); k3 *= c4; h3 ^= k3;

			case  8: k2 ^= tail[ 7] << 24;
			case  7: k2 ^= tail[ 6] << 16;
			case  6: k2 ^= tail[ 5] << 8;
			case  5: k2 ^= tail[ 4] << 0;
				k2 *= c2; k2  = ROTL32(k2,16); k2 *= c3; h2 ^= k2;

			case  4: k1 ^= tail[ 3] << 24;
			case  3: k1 ^= tail[ 2] << 16;
			case  2: k1 ^= tail[ 1] << 8;
			case  1: k1 ^= tail[ 0] << 0;
				k1 *= c1; k1  = ROTL32(k1,15); k1 *= c2; h1 ^= k1;
			};

			//----------
			// finalization

			h1 ^= len; h2 ^= len; h3 ^= len; h4 ^= len;

			h1 += h2; h1 += h3; h1 += h4;
			h2 += h1; h3 += h1; h4 += h1;

			h1 = fmix(h1);
			h2 = fmix(h2);
			h3 = fmix(h3);
			h4 = fmix(h4);

			h1 += h2; h1 += h3; h1 += h4;
			h2 += h1; h3 += h1; h4 += h1;

			((uint32*)out)[0] = h1;
			((uint32*)out)[1] = h2;
		}

		furrovineapi static void MurmurHash64x64 ( const void * key, const lword len,
			const uint32 seed, void * out )
		{
			const uint8 * data = (const uint8*)key;
			const lword nblocks = len / 16;

			uint64 h1 = seed;
			uint64 h2 = seed;

			const uint64 c1 = BIG_CONSTANT(0x87c37b91114253d5);
			const uint64 c2 = BIG_CONSTANT(0x4cf5ad432745937f);

			//----------
			// body

			const uint64 * blocks = (const uint64 *)(data);

			for(lword i = 0; i < nblocks; i++)
			{
				uint64 k1 = getblock(blocks,i*2+0);
				uint64 k2 = getblock(blocks,i*2+1);

				k1 *= c1; k1  = ROTL64(k1,31); k1 *= c2; h1 ^= k1;

				h1 = ROTL64(h1,27); h1 += h2; h1 = h1*5+0x52dce729;

				k2 *= c2; k2  = ROTL64(k2,33); k2 *= c1; h2 ^= k2;

			}

			//----------
			// tail

			const uint8 * tail = (const uint8*)(data + nblocks*16);

			uint64 k1 = 0;
			uint64 k2 = 0;

			switch(len & 15)
			{
			case 15: k2 ^= uint64(tail[14]) << 48;
			case 14: k2 ^= uint64(tail[13]) << 40;
			case 13: k2 ^= uint64(tail[12]) << 32;
			case 12: k2 ^= uint64(tail[11]) << 24;
			case 11: k2 ^= uint64(tail[10]) << 16;
			case 10: k2 ^= uint64(tail[ 9]) << 8;
			case  9: k2 ^= uint64(tail[ 8]) << 0;
				k2 *= c2; k2  = ROTL64(k2,33); k2 *= c1; h2 ^= k2;

			case  8: k1 ^= uint64(tail[ 7]) << 56;
			case  7: k1 ^= uint64(tail[ 6]) << 48;
			case  6: k1 ^= uint64(tail[ 5]) << 40;
			case  5: k1 ^= uint64(tail[ 4]) << 32;
			case  4: k1 ^= uint64(tail[ 3]) << 24;
			case  3: k1 ^= uint64(tail[ 2]) << 16;
			case  2: k1 ^= uint64(tail[ 1]) << 8;
			case  1: k1 ^= uint64(tail[ 0]) << 0;
				k1 *= c1; k1  = ROTL64(k1,31); k1 *= c2; h1 ^= k1;
			};

			//----------
			// finalization

			h1 ^= len;

			h1 += h2;
			h2 += h1;

			h1 = fmix(h1);
			h2 = fmix(h2);

			h1 += h2;
			h2 += h1;

			((uint64*)out)[0] = h1;
		}

		template <typename T> 
		static ulword Std ( const T& key ) {
			std::hash<T> h;
			return h( key );
		}
	};

}