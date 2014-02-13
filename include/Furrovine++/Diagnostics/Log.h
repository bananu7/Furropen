#ifndef FURROVINELOG_H
#define FURROVINELOG_H

#include <Furrovine++/std_defines.h>
#include <iomanip>
#include <iostream>
#include <Furrovine++/Collections/Concurrent/BlockingQueue.h>
#include <Furrovine++/Threading/Thread.h>
#include <Furrovine++/Threading/ThreadStopException.h>
#include <Furrovine++/Diagnostics/LogLevel.h>

namespace Furrovine { namespace Diagnostics {

	class Log {
	private:
		typedef std::function<void()> TWork;
		Collections::Concurrent::BlockingQueue<TWork> work;
		Threading::Thread logthread;
		std::stringstream buffer;
		std::ostream& sink;
		std::atomic<LogLevel> workingverbosity, verbosity;

		template <typename T>
		void RawWrite ( T&& object ) {
			buffer << object;
		}

		template <typename T>
		void FormattedWrite ( T&& object, LogLevel level, std::chrono::system_clock::time_point time ) {
			if ( level < workingverbosity )
				return;
			switch ( level ) {
			case LogLevel::LOL:
				buffer << "[ LOL ] ";
				break;
			case LogLevel::FTR:
				buffer << "[ FTR ] ";
				break;
			case LogLevel::FYI:
				buffer << "[ FYI ] ";
				break;
			case LogLevel::WTF:
				buffer << "[ WTF ] ";
				break;
			case LogLevel::OMG:
				buffer << "[ OMG ] ";
				break;
			case LogLevel::FML:
				buffer << "[ FML ] ";
				break;
			}
			std::time_t timec = std::chrono::system_clock::to_time_t( time );
			buffer << "( ";
			buffer << std::put_time( std::localtime( &timec ), "%H:%M:%S | %Y-%m-%d" );
			buffer << " ) ";
			buffer << object;
			buffer << '\n';
		}

		void RunThread () {
			while ( true ) {
				try {
					TWork workitem;
					if ( work.Pop( workitem ) ) {
						workitem( );
					}
				}
				catch ( const Threading::ThreadStopException& ) {
					break;
				}
			}
		}

		void RawSink () {
			sink << buffer.str();
		}

		void RawFlush () {
			Sink();
			sink.flush();
		}

		void ChangeWorkingVerbosity ( LogLevel targetverbosity ) {
			workingverbosity = targetverbosity;
		}

		void ThrowStop () {
			throw Threading::ThreadStopException();
		}

		void Stop () {
			TWork stopworkitem = std::bind( &Log::ThrowStop, this );
			work.Push( stopworkitem );
		}

	public:

		static const LogLevel DefaultLogLevel = LogLevel::FYI;

		Log ( std::ostream& outputstream, LogLevel initialverbosity = LogLevel::LOL ) 
		: sink( outputstream ), workingverbosity( initialverbosity ) {
			logthread.Reset( &Log::RunThread, this );
		}

		LogLevel Verbosity () {
			return verbosity;
		}

		void SetVerbosity ( LogLevel value ) {
			verbosity = value;
			TWork workitem = std::bind( &Log::ChangeWorkingVerbosity, this, value );
			work.Push( workitem );
		}

		template <typename T>
		void RawDump ( T&& object ) {
			TWork workitem = std::bind( &Log::RawWrite<T>, this, std::forward<T>( object ) );
			work.Push( workitem );
		}

		template <typename T>
		void Write ( T&& object, LogLevel level = LogLevel::FYI ) {
			TWork workitem = std::bind( &Log::FormattedWrite<T>, this, std::forward<T>( object ), level, std::chrono::system_clock::now() );
			work.Push( workitem );
		}

		/*template <typename ...Tn>
		void Write ( Tn&&... objects ) {
			Write( DefaultLogLevel, std::forward<Tn>( objects )... );
		}

		template <typename ...Tn>
		void Write ( LogLevel level, Tn&&... objects ) {
			TWork workitem = std::bind( &Log::FormattedWrite, this, level, std::chrono::system_clock::now(), std::forward<Tn>( objects )... );
			work.Push( work );
		}*/

		void Sink () {	
			TWork sinkworkitem = std::bind( &Log::RawSink, this );
			work.Push( sinkworkitem );
		}

		void Flush () {
			TWork sinkworkitem = std::bind( &Log::RawFlush, this );
			work.Push( sinkworkitem );
		}

		~Log () {
			Flush();
			Stop();
			logthread.Join();
		}
	};

}}

#endif // FURROVINELOG_H 