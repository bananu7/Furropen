#pragma once

namespace Furrovine {

	template <typename ... Tn>
	void debug_templates( ) {
		static_assert( false, "[ Displaying Templates ]" );
	}

	template <typename ... Tn>
	void debug_template_args ( Tn&&... argn ) {
		static_assert( false, "[ Displaying Templates ]" );
	}

}