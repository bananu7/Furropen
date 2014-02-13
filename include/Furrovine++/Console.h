#ifndef FURROVINECONSOLE_H
#define FURROVINECONSOLE_H

#include <Furrovine++/Diagnostics/Logger.h>

namespace Furrovine {

	class Console {
	private:
		furrovineapi static Diagnostics::Log& getout(  ) {
			static Diagnostics::Log out( std::cout );
			return out;
		}

		furrovineapi static Diagnostics::Log& geterr(  ) {
			static Diagnostics::Log err( std::cerr );
			return err;
		}

	public:

		template <typename T> 
		static void Write ( T&& object ) {
			getout().RawDump( object );
			getout().Sink();
		}

		template <typename T> 
		static void WriteLine ( T&& object ) {
			static const char nline = '\n';
			getout().RawDump( object );
			getout().RawDump( nline );
			getout().Sink();
		}

	};

}

#endif // FURROVINECONSOLE_H 