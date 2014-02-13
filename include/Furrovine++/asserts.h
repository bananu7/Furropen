#pragma once

#include <cassert>

#define furrovinelazyassert(condition) assert((condition) && "[ Condition Failed! ]")
#define furrovineassert(condition, message) assert(message && (condition))
