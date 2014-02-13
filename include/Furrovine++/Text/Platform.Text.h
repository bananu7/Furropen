#pragma once

#include <Furrovine++/Platform.Text.h>

#ifdef FURROVINEDIRECTWRITE
#include <Furrovine++/Text/Dw/Platform.Dw.h>
#endif // DIRECTWRITE
#ifdef FURROVINEFREETYPE
#include <Furrovine++/Text/Ft/Platform.Ft.h>
#endif // FREETYPE