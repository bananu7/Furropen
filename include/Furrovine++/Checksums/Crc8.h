#include <Furrovine++/PrimitiveTypes.h>
#include <array>

namespace Furrovine { namespace Checksums {

	template <ushort bits = 8, ushort poly8 = 0x07>
	class Crc8 {
	private:
		static const std::array<ushort, 256> table;

		static std::array<ushort, 256> make_table( ) {
			std::array<ushort, 256> tbl;
			ushort poly = (ushort)( poly8 + ( 1U << bits ) );
			for ( ushort i = 0; i < table.size(); i++ ) {
				ushort crc = i;
				for ( lword j = 0; j < bits; j++ ) {
					if ( ( crc & ( 1U << ( bits - 1 ) ) ) != 0 )
						crc = (ushort)( ( crc << 1 ) ^ poly );
					else
						crc <<= 1;
				}
				tbl[ i ] = (ushort)( crc & 0x00ff );
			}
			return tbl;
		}

	public:
		
		Crc8 ( ) {
			
		}

		byte ComputeChecksum ( byte* bytes, ulword offset, ulword count ) {
			if ( bytes == null )
				return 0;
			return ComputeChecksum( bytes + offset, count );
		}

		byte ComputeChecksum ( byte* bytes, ulword count ) {
			byte crc = 0;
			ComputeChecksum( crc, bytes, count );
			return crc;
		}

		void ComputeChecksum ( byte& crc, byte* bytes, ulword offset, ulword count ) {
			return ComputeChecksum( crc, bytes + offset, count );
		}

		void ComputeChecksum ( byte& crc, byte* bytes, ulword count ) {
			if ( bytes == null )
				return;

			byte* bytesend = bytes + count;
			while ( bytes != bytesend ) {
				crc = (byte)table[ crc ^ *bytes++ ];
			}
		}

	};

	template <ushort bits, ushort poly8> 
	const std::array<ushort, 256> Crc8<bits, poly8>::table = Crc8<bits, poly8>::make_table();

}}
