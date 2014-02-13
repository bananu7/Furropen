#ifndef FURROVINEPRINT_H
#define FURROVINEPRINT_H

#include <Furrovine++/print.h>
#include <iostream>
#include <utility>

namespace Furrovine {

	template <typename TRange>
	void PrintRange ( TRange&& range, std::ostream& stream = std::cout ) {
		std::cout << "[ ";
		for ( auto& r : range ) {
			stream << r << ' ';
		}
		std::cout << "]" << std::endl;
	}

	template <typename T, typename ...Tn>
	void Print ( std::ostream& stream, T&& arg, Tn&&... argn ) {
		stream << arg;
		Print( stream, std::forward<Tn>( argn )... );
	}

	void Print ( std::ostream& stream ) {

	}

}

#endif // FURROVINEPRINT_H 