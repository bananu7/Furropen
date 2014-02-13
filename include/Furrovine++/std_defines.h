#ifndef FURROVINESTD_DEFINES_H
#define FURROVINESTD_DEFINES_H

#ifndef UNICODE
#define UNICODE 1
#endif // UNICODE
#ifndef _UNICODE
#define _UNICODE 1
#endif // _UNICODE

#ifdef _MSC_VER
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // _CRT_SECURE_NO_WARNINGS
#ifndef _SCL_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#endif // _SCL_SECURE_NO_WARNINGS
#endif

/*#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(_WIN32_) || defined(__WIN32__)
#include <direct.h>
#define GetCwd _getcwd
#else
#include <unistd.h>
#define GetCwd getcwd
#endif
*/

#endif // FURROVINESTD_DEFINES_H