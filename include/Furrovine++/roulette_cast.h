#ifndef FURROVINEROULETTE_CAST_H
#define FURROVINEROULETTE_CAST_H

namespace Furrovine {

	template <typename T,typename TTo>
	TTo roulette_cast( const T& yey ) {
		static int i = 0;
		
		if ( ++i > 4 ) 
			i = 1;

		switch ( i ) {
		case 1:
			return static_cast<TTo>(yey);
			break;
		case 2:
			return reinterpret_cast<TTo>(yey);
			break;
		case 3:
			return dynamic_cast<TTo>(yey);
			break;
		case 4:
			return *((TTo*)nullptr);
			break;
		}
	}

}

#endif // FURROVINEROULETTE_CAST_H