#pragma once

namespace Furrovine {

	template <typename TFx>
	struct overload_selector {
		TFx fx;
		
		template <typename... Tn>
		overload_selector( Tn&&... argn ) : fx( std::forward<Tn>( argn )... ) {

		}

		template <typename... Tn>
		auto operator () ( Tn&&... argn ) -> decltype( fx( std::forward<Tn>( argn )... ) ) {
			return fx( std::forward<Tn>( argn )... );
		}

	};

	template <typename... Tn, typename TFx>
	overload_selector<TFx> overloaded( TFx&& fx ) {
		return overload_selector<TFx>( std:forward<TFx>( fx ) );
	}

}