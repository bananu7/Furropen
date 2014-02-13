#pragma once

#include <Furrovine++/std_defines.h>
#include <utility>
#include <type_traits>
#include <functional>
#include <Furrovine++/PrimitiveTypes.h>

namespace Furrovine {

	template <typename TR, typename ...Tn>
	struct function_chain {
	private:

		template <ulword n, typename Ti, typename ...TFxn>
		struct flink;

		template <ulword n, typename ...TFxn>
		struct fchain;

		template <ulword n, typename TFx, typename ...TFxn>
		struct fchain<n, TFx, TFxn...> {
			typedef typename std::result_of< TFx( Tn... ) >::type TResult;
			TFx fx;
			flink<n - 1, TResult, TFxn...> next;

			fchain ( TFx&& fx, TFxn&&... fxn ) : fx( std::forward<TFx>( fx ) ), next( std::forward<TFxn>( fxn )... ) {

			}

			TR operator () ( Tn&&... argn ) {
				return next( fx( std::forward<Tn>( argn )... ) );
			}
		};

		template <typename TFx, typename ...TFxn>
		struct fchain<1, TFx, TFxn...> {
			typedef typename std::result_of< TFx( Tn... ) >::type TResult;
			TFx fx;

			fchain ( TFx&& fx, TFxn&&... fxn ) : fx( std::forward<TFx>( fx ) ) {

			}

			TR operator () ( Tn&&... argn ) {
				return fx( std::forward<Tn>( argn )... );
			}
		};

		template <typename ...TFxn>
		struct fchain<0, TFxn...> {
			typedef TR TResult;

			fchain ( TFxn&&... ) {

			}

			TR operator () ( Tn&&... argn ) {
				return TR();
			}
		};

		template <ulword n, typename Ti, typename TFx, typename ... TFxn>
		struct flink<n, Ti, TFx, TFxn...> {
			typedef typename std::result_of< TFx( Ti ) >::type TResult;
			TFx fx;
			flink<n - 1, TResult, TFxn...> next;

			flink ( TFx&& fx, TFxn&&... fxn ) : fx( std::forward<TFx>( fx ) ), next( std::forward<TFxn>( fxn )... ) {

			}

			TR operator () ( Ti&& argi ) {
				return next( fx( std::forward<Ti>( argi ) ) );
			}

		};

		template <ulword n, typename TFx, typename ... TFxn>
		struct flink<n, void, TFx, TFxn...> {
			typedef typename std::result_of< TFx( ) >::type TResult;
			TFx fx;
			flink<n - 1, TResult, TFxn...> next;

			flink ( TFx&& fx, TFxn&&... fxn ) : fx( std::forward<TFx>( fx ) ), next( std::forward<TFxn>( fxn )... ) {

			}

			TR operator () ( ) {
				fx( );
				return next(  );
			}

		};

		template <typename Ti, typename TFx>
		struct flink <1, Ti, TFx> {
			typedef typename std::result_of< TFx( Ti ) >::type TResult;
			TFx fx;

			flink ( TFx&& fx ) : fx( std::forward<TFx>( fx ) ) {

			}

			TR operator () ( Ti&& argi ) {
				return fx( std::forward<Ti>( argi ) );
			}

		};

		template <typename TFx>
		struct flink <1, void, TFx> {
			typedef typename std::result_of< TFx( ) >::type TResult;
			TFx fx;

			flink ( TFx&& fx ) : fx( std::forward<TFx>( fx ) ) {

			}

			TR operator () ( ) {
				fx( );
			}

		};

	private:
		typedef std::function<TR( Tn...)> TFunction;
		TFunction chainbegin;

	public:

		template <typename ...TFxn> 
		explicit function_chain ( TFxn&&... fxn ) : chainbegin( fchain<sizeof...( TFxn ), TFxn...>( std::forward<TFxn>( fxn )... ) ) {

		}

		template <typename TFx0>
		explicit function_chain ( TFx0&& fx0 ) : chainbegin( fchain<1, TFx0>( std::forward<TFx0>( fx0 ) ) ) {

		}

		template <typename TFx0, typename TFx1>
		function_chain ( TFx0&& fx0, TFx1&& fx1 ) : chainbegin( fchain<2, TFx0, TFx1>( std::forward<TFx0>( fx0 ), std::forward<TFx1>( fx1 ) ) ) {

		}

		function_chain ( const function_chain& copy ) : chainbegin( copy.chainbegin ) {

		}

		function_chain ( function_chain&& mov ) : chainbegin(std::move(mov.chainbegin)) {

		}

		function_chain& operator= ( const function_chain& copy ) {
			chainbegin = copy.chainbegin;
			return *this;
		}

		function_chain& operator= ( function_chain&& mov ) {
			chainbegin = std::move(mov.chainbegin);
			return *this;
		}

		template <typename ...TFxn> 
		void reset ( TFxn&&... fxn ) {
			chainbegin = TFunction( fchain<sizeof...( TFxn ), TFxn...>( std::forward<TFxn>( fxn )... ) );
		}

		TR operator () ( Tn&&... argn ) {
			return chainbegin( std::forward<Tn>( argn ) ... );
		}

		template <typename... TKickn>
		TR operator () ( TKickn&&... argn ) {
			return chainbegin( std::forward<TKickn>( argn ) ... );
		}

	};

	template <typename TR>
	struct function_chain<TR, void> {
	private:

		template <ulword n, typename Ti, typename ...TFxn>
		struct flink;

		template <ulword n, typename ...TFxn>
		struct fchain;

		template <ulword n, typename TFx, typename ...TFxn>
		struct fchain<n, TFx, TFxn...> {
			typedef typename std::result_of< TFx( ) >::type TResult;
			TFx fx;
			flink<n - 1, TResult, TFxn...> next;

			fchain ( TFx&& fx, TFxn&&... fxn ) : fx( std::forward<TFx>( fx ) ), next( std::forward<TFxn>( fxn )... ) {

			}

			TR operator () ( ) {
				return next( fx( ) );
			}
		};

		template <typename TFx, typename ...TFxn>
		struct fchain<1, TFx, TFxn...> {
			typedef typename std::result_of< TFx( ) >::type TResult;
			TFx fx;

			fchain ( TFx&& fx, TFxn&&... fxn ) : fx( std::forward<TFx>( fx ) ) {

			}

			TR operator () ( ) {
				return fx( );
			}
		};

		template <typename ...TFxn>
		struct fchain<0, TFxn...> {
			typedef TR TResult;

			fchain ( TFxn&&... ) {

			}

			TR operator () ( ) {
				return TR();
			}
		};

		template <ulword n, typename Ti, typename TFx, typename ... TFxn>
		struct flink<n, Ti, TFx, TFxn...> {
			typedef typename std::result_of< TFx( Ti ) >::type TResult;
			TFx fx;
			flink<n - 1, TResult, TFxn...> next;

			flink ( TFx&& fx, TFxn&&... fxn ) : fx( std::forward<TFx>( fx ) ), next( std::forward<TFxn>( fxn )... ) {

			}

			TR operator () ( Ti&& argi ) {
				return next( fx( std::forward<Ti>( argi ) ) );
			}

		};

		template <ulword n, typename TFx, typename ... TFxn>
		struct flink<n, void, TFx, TFxn...> {
			typedef typename std::result_of< TFx( ) >::type TResult;
			TFx fx;
			flink<n - 1, TResult, TFxn...> next;

			flink ( TFx&& fx, TFxn&&... fxn ) : fx( std::forward<TFx>( fx ) ), next( std::forward<TFxn>( fxn )... ) {

			}

			TR operator () ( ) {
				fx( );
				return next(  );
			}

		};

		template <typename Ti, typename TFx>
		struct flink <1, Ti, TFx> {
			typedef typename std::result_of< TFx( Ti ) >::type TResult;
			TFx fx;

			flink ( TFx&& fx ) : fx( std::forward<TFx>( fx ) ) {

			}

			TR operator () ( Ti&& argi ) {
				return fx( std::forward<Ti>( argi ) );
			}

		};

		template <typename TFx>
		struct flink <1, void, TFx> {
			typedef typename std::result_of< TFx( ) >::type TResult;
			TFx fx;

			flink ( TFx&& fx ) : fx( std::forward<TFx>( fx ) ) {

			}

			TR operator () ( ) {
				fx( );
			}

		};

	private:
		std::function<TR( )> chainbegin;

	public:

		template <typename ...TFxn> 
		explicit function_chain ( TFxn&&... fxn ) : chainbegin( fchain<sizeof...( TFxn ), TFxn...>( std::forward<TFxn>( fxn )... ) ) {

		}

		function_chain ( const function_chain& copy ) : chainbegin( copy.chainbegin ) {

		}

		function_chain ( function_chain&& mov ) : chainbegin(std::move(mov.chainbegin)) {

		}

		function_chain& operator= ( const function_chain& copy ) {
			chainbegin = copy.chainbegin;
			return *this;
		}

		function_chain& operator= ( function_chain&& mov ) {
			chainbegin = std::move(mov.chainbegin);
			return *this;
		}

		template <typename ...TFxn> 
		void reset ( TFxn&&... fxn ) {
			chainbegin = TFunction( fchain<sizeof...( TFxn ), TFxn...>( std::forward<TFxn>( fxn )... ) );
		}

		TR operator () ( ) {
			return chainbegin( );
		}

	};

	template <>
	struct function_chain<void> {
	private:

		template <ulword n, typename Ti, typename ...TFxn>
		struct flink;

		template <ulword n, typename ...TFxn>
		struct fchain;

		template <ulword n, typename TFx, typename ...TFxn>
		struct fchain<n, TFx, TFxn...> {
			typedef typename std::result_of< TFx( ) >::type TResult;
			TFx fx;
			flink<n - 1, TResult, TFxn...> next;

			fchain ( TFx&& fx, TFxn&&... fxn ) : fx( std::forward<TFx>( fx ) ), next( std::forward<TFxn>( fxn )... ) {

			}

			void operator () ( ) {
				fx( );
				return next(  );
			}
		};

		template <typename TFx, typename ...TFxn>
		struct fchain<1, TFx, TFxn...> {
			typedef typename std::result_of< TFx( ) >::type TResult;
			TFx fx;

			fchain ( TFx&& fx, TFxn&&... fxn ) : fx( std::forward<TFx>( fx ) ) {

			}

			void operator () ( ) {
				return fx( );
			}
		};

		template <typename ...TFxn>
		struct fchain<0, TFxn...> {
			
			fchain ( TFxn&&... ) {

			}

			void operator () ( ) {
				return ;
			}
		};

		template <ulword n, typename Ti, typename TFx, typename ... TFxn>
		struct flink<n, Ti, TFx, TFxn...> {
			typedef typename std::result_of< TFx( Ti ) >::type TResult;
			TFx fx;
			flink<n - 1, TResult, TFxn...> next;

			flink ( TFx&& fx, TFxn&&... fxn ) : fx( std::forward<TFx>( fx ) ), next( std::forward<TFxn>( fxn )... ) {

			}

			void operator () ( Ti&& argi ) {
				return next( fx( std::forward<Ti>( argi ) ) );
			}

		};

		template <ulword n, typename TFx, typename ... TFxn>
		struct flink<n, void, TFx, TFxn...> {
			typedef typename std::result_of< TFx( ) >::type TResult;
			TFx fx;
			flink<n - 1, TResult, TFxn...> next;

			flink ( TFx&& fx, TFxn&&... fxn ) : fx( std::forward<TFx>( fx ) ), next( std::forward<TFxn>( fxn )... ) {

			}

			void operator () ( ) {
				fx( );
				return next(  );
			}

		};

		template <typename Ti, typename TFx>
		struct flink <1, Ti, TFx> {
			typedef typename std::result_of< TFx( Ti ) >::type TResult;
			TFx fx;

			flink ( TFx&& fx ) : fx( std::forward<TFx>( fx ) ) {

			}

			void operator () ( Ti&& argi ) {
				return fx( std::forward<Ti>( argi ) );
			}

		};

		template <typename TFx>
		struct flink <1, void, TFx> {
			typedef typename std::result_of< TFx( ) >::type TResult;
			TFx fx;

			flink ( TFx&& fx ) : fx( std::forward<TFx>( fx ) ) {

			}

			void operator () ( ) {
				fx( );
			}

		};

	private:
		std::function<void( )> chainbegin;

	public:

		template <typename ...TFxn> 
		explicit function_chain ( TFxn&&... fxn ) : chainbegin( fchain<sizeof...( TFxn ), TFxn...>( std::forward<TFxn>( fxn )... ) ) {

		}

		function_chain ( const function_chain& copy ) : chainbegin( copy.chainbegin ) {

		}

		function_chain ( function_chain&& mov ) : chainbegin(std::move(mov.chainbegin)) {

		}

		function_chain& operator= ( const function_chain& copy ) {
			chainbegin = copy.chainbegin;
			return *this;
		}

		function_chain& operator= ( function_chain&& mov ) {
			chainbegin = std::move(mov.chainbegin);
			return *this;
		}

		template <typename ...TFxn> 
		void reset ( TFxn&&... fxn ) {
			chainbegin = TFunction( fchain<sizeof...( TFxn ), TFxn...>( std::forward<TFxn>( fxn )... ) );
		}

		void operator () ( ) {
			return chainbegin( );
		}

	};

	template <typename TR, typename ...Tn, typename ...TFxn>
	function_chain<TR, Tn...> make_chain ( TFxn&&... fxn ) {
		return function_chain<TR, Tn...>( std::forward<TFxn>( fxn )... );
	}
	
}
