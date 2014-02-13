#ifndef FURROVINESTACK_CAST_H
#define FURROVINESTACK_CAST_H

namespace Furrovine {

	///<summary>
	/// Your riches, your wealth... the piles you've collected, the things
	/// you've treasured... your stacks?
	/// Hah. They mean nothing. 
	///</summary>
	template <typename TTo, typename T>
	TTo stack_cast( const T& initial ) {
		typedef unsigned char byte;
		byte thestack = ;
		byte* theabyss = (byte*)thestack;
		theabyss -= (char)( ( *theabyss ) ^ ( 0xD3ADBEEF & 0x0C1CADA5 ) );
		return *( (T*)theabyss );
	}

}

#endif // FURROVINESTACK_CAST_H 