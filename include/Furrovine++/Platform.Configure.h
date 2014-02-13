#pragma once

#include <Furrovine++/Platform.OS.h>

// Define for Floating Point Colors
//#define FURROVINEFLOATCOLOR

// Change the type of the `real` keyword
//#define FURROVINEREALDOUBLE

// Define this to configure based on the platform you are compiling under
#define FURROVINECONFIGURETOPLATFORM 1

#ifndef FURROVINECONFIGURETOPLATFORM
// If you don't define FURROVINECONFIGURETOPLATFORM,
// specify your variants and macros here

#ifdef FURROVINEWIN
#define FURROVINEDIRECTX 1
#define FURROVINEXAUDIO 1
#define FURROVINEXINPUT 1
#define FURROVINEGDIPLUS 1
#define FURROVINEDIRECTWRITE 1
#define FURROVINECOORDINATESYSTEMLEFTHANDED 1
#else
#define FURROVINEOPENGL 1
#define FURROVINEOPENAL 1
#define FURROVINECOORDINATESYSTEMRIGHTHANDED 1
#define FURROVINEFREETYPE 1
#endif // WIN || *NIX

#define FURROVINEMATRIXROWMAJOR 1
#define FURROVINESHADERMATRIXCOLUMNMAJOR 1

#endif // CONFIGURETOPLATFORM