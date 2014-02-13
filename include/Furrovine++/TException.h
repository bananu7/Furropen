#pragma once

#include <Furrovine++/Strings.h>

namespace Furrovine {

	template <typename TExc>
	class TException : TExc {
	protected:
		String exdesc;

	public:

		template <typename ...Tn>
		TException ( Tn&&... argn ) : TExc( std::forward<Tn>( argn )... ) {
			exdesc.Assign( make_buffer_view( const_cast<char*>( TExc::what( ) ), 
				std::char_traits<char>::length( TExc::what() ) ) );
		}

		template <typename ...Tn>
		TException ( const String& message, Tn&&... argn ) : TExc( std::forward<Tn>( argn )... ), exdesc( message ) {

		}

		template <typename ...Tn>
		TException ( String&& message, Tn&&... argn ) : TExc( std::forward<Tn>( argn )... ), exdesc( std::move( message ) ) {

		}

		virtual const char* what( ) const override {
			return reinterpret_cast<const char*>( exdesc.data( ) );
		}

		virtual String Message () const {
			return exdesc;
		}

		virtual Furrovine::ulword HashCode ( ) const {
			return HashCode( *this );
		}

		static Furrovine::ulword HashCode ( const TException& hashee ) {
			ulword hash = 0;
			Hashers::FowlerNollVo1a( &hashee, sizeof( TException ), &hash );
			return hash;
		}

		~TException () {

		}

	};

}
