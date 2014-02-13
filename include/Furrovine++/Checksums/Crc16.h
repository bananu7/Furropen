#ifndef FURROVINECRC16_H
#define FURROVINECRC16_H

namespace Furrovine { namespace Checksums {

	template <ushort bits = 16, ushort poly16 = 0x8005>
	class Crc16 {
	public:
		static const std::array<ushort, 256> table;

		static std::array<ushort, 256> MakeTable () {
			std::array<ushort, 256> tbl;
			lword poly = ( poly16 + ( 1 << bits ) );
			for ( ushort i = 0; i < tbl.size(); i++ ) {
				lword crc = i;
				for ( lword j = 0; j < bits; j++ ) {
					if ( ( crc & ( 1U << ( bits - 1 ) ) ) != 0 )
						crc = ( ( crc << 1 ) ^ poly );
					else
						crc <<= 1;
				}
				//tbl[i] = (crc & ((1<<bits)-1));
				tbl[ i ] = (ushort)( crc & 0xffff );
			}

			return tbl;
		}

		Crc16 ( ) {
			
		}

		ushort ComputeChecksum ( byte* bytes, ulword offset, ulword count ) {
			return ComputeChecksum( bytes + offset, count );
		}

		ushort ComputeChecksum ( byte* bytes, ulword count ) {
			ushort crc = 0;
			ComputeChecksum( crc, bytes, count );
			return crc;
		}

		void ComputeChecksum (ushort& crc, byte* bytes, ulword offset, ulword count) {
			ComputeChecksum( crc, bytes + offset, count );
		}

		void ComputeChecksum( ushort& crc, byte* bytes, ulword count ) {
			if ( bytes == null )
				return;

			byte* bytesend = bytes + count;
			while ( bytes != bytesend )
				crc = (ushort)( ( crc << 8 ) ^ table[ ( crc >> 8 ) ^ *bytes++ ] );
		}
	};

	template <ushort bits, ushort poly16> 
	const std::array<ushort, 256> Crc16<bits, poly16>::table = Crc16<bits, poly16>::MakeTable();

}}

#endif // FURROVINECRC16_H 