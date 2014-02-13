#pragma once

namespace Furrovine {
	
#if defined (__GLIBC__)
# include <endian.h>
# if (__BYTE_ORDER == __LITTLE_ENDIAN)
#  define FURROVINELITTLEENDIAN
# elif (__BYTE_ORDER == __BIG_ENDIAN)
#  define FURROVINEBIGENDIAN
# elif (__BYTE_ORDER == __PDP_ENDIAN)
#  define FURROVINEPDPENDIAN
# else
#  error Unknown machine endianness detected.
# endif
# define FURROVINEBYTEORDERRAW __BYTE_ORDER
#elif defined(_BIG_ENDIAN) && !defined(_LITTLE_ENDIAN) || \
	defined(__BIG_ENDIAN__) && !defined(__LITTLE_ENDIAN__) || \
	defined(_STLP_BIG_ENDIAN) && !defined(_STLP_LITTLE_ENDIAN)
# define FURROVINEBIGENDIAN
# define FURROVINEBYTEORDERRAW 4321
#elif defined(_LITTLE_ENDIAN) && !defined(_BIG_ENDIAN) || \
	defined(__LITTLE_ENDIAN__) && !defined(__BIG_ENDIAN__) || \
	defined(_STLP_LITTLE_ENDIAN) && !defined(_STLP_BIG_ENDIAN)
# define FURROVINELITTLEENDIAN
# define FURROVINEBYTEORDERRAW 1234
#elif defined(__sparc) || defined(__sparc__) \
	|| defined(_POWER) || defined(__powerpc__) \
	|| defined(__ppc__) || defined(__hpux) || defined(__hppa) \
	|| defined(_MIPSEB) || defined(_POWER) \
	|| defined(__s390__)
# define FURROVINEBIGENDIAN
# define FURROVINEBYTEORDERRAW 4321
#elif defined(__i386__) || defined(__alpha__) \
	|| defined(__ia64) || defined(__ia64__) \
	|| defined(_M_IX86) || defined(_M_IA64) \
	|| defined(_M_ALPHA) || defined(__amd64) \
	|| defined(__amd64__) || defined(_M_AMD64) \
	|| defined(__x86_64) || defined(__x86_64__) \
	|| defined(_M_X64) || defined(__bfin__)

# define FURROVINELITTLEENDIAN
# define FURROVINEBYTEORDERRAW 1234

#else
# error The file Furrovine++/PlatformEndian.h needs to be set up for your CPU type.
#endif

# define FURROVINEBYTEORDER FURROVINEBYTEORDERRAW
	
}
