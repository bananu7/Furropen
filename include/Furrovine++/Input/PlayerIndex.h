#ifndef FURROVINEPLAYERINDEX_H
#define FURROVINEPLAYERINDEX_H

#include <Furrovine++/Input/InputCore.h>

namespace Furrovine { namespace Input {

	enum class PlayerIndexMask {
		None = 0x00, 
		One = 0x01,
		Two = 0x02,
		Three = 0x04,
		Four = 0x08
	};


	enum class PlayerIndex {
		One,
		Two,
		Three,
		Four
	};
	
	PlayerIndexMask ToPlayerIndexMask ( PlayerIndex a ) {
		return (PlayerIndexMask)(1 << ((int)a + 1)); 
	}
	
	enumflagoperators( PlayerIndexMask );

}}

#endif // FURROVINEPLAYERINDEX_H 