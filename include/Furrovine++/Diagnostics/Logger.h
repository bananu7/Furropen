#ifndef FURROVINELOGGER_H
#define FURROVINELOGGER_H

#include <Furrovine++/Diagnostics/Log.h>

namespace Furrovine { namespace Diagnostics {

	class Logger {
	private:
		Log& l;
		LogLevel level;

	public:

		Logger ( Log& log, LogLevel writelevel = LogLevel::FYI ) : l( log ), level(writelevel) {

		}

		Log& Target () {
			return l;
		}

		Logger& SetLevel ( LogLevel writelevel ) {
			level = writelevel;
			return *this;
		}

		template <typename T>
		Logger& Write ( T&& item ) {
			l.Write( item, level );
			return *this;
		}

		template <typename T>
		Logger& operator << ( T&& item ) {
			return Write( item );
		}

		Logger& operator << ( LogLevel item ) {
			return SetLevel( item );
		}

		~Logger ( ) {
			l.Sink();
		}
	};

}}

#endif // FURROVINELOGGER_H 