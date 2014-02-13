#pragma once

#include <Furrovine++/Sys/ByteOrder.h>

namespace Furrovine { namespace Sys {

	template <typename T>
	class RuntimeByteOrder : public T, public ByteOrder {
	public:
		RuntimeByteOrder ( T order = T() ) : T(std::move(order)), ByteOrder( *static_cast<const T*>( this ) ) {

		}

		virtual int8 Int8 ( byte* bytes ) const override {
			const T& crtp = *static_cast<const T*>( this );
			return crtp.Value<int8>( bytes );
		}

		virtual uint8 UInt8 ( byte* bytes ) const override {
			const T& crtp = *static_cast<const T*>( this );
			return crtp.Value<uint8>( bytes );
		}

		virtual int16 Int16 ( byte* bytes ) const override {
			const T& crtp = *static_cast<const T*>( this );
			return crtp.Value<int16>( bytes );
		}

		virtual uint16 UInt16 ( byte* bytes ) const override {
			const T& crtp = *static_cast<const T*>( this );
			return crtp.Value<uint16>( bytes );
		}

		virtual int32 Int24 ( byte* bytes ) const override {
			const T& crtp = *static_cast<const T*>( this );
			return crtp.Value<int32>( bytes );
		}

		virtual uint32 UInt24 ( byte* bytes ) const override {
			const T& crtp = *static_cast<const T*>( this );
			return crtp.Value<uint32>( bytes );
		}

		virtual int32 Int32 ( byte* bytes ) const override {
			const T& crtp = *static_cast<const T*>( this );
			return crtp.Value<int32>( bytes );
		}

		virtual uint32 UInt32 ( byte* bytes ) const override {
			const T& crtp = *static_cast<const T*>( this );
			return crtp.Value<uint32>( bytes );
		}

		virtual int64 Int64 ( byte* bytes ) const override {
			const T& crtp = *static_cast<const T*>( this );
			return crtp.Value<int64>( bytes );
		}

		virtual uint64 UInt64 ( byte* bytes ) const override {
			const T& crtp = *static_cast<const T*>( this );
			return crtp.Value<uint64>( bytes );
		}

		virtual float Single ( byte* bytes ) const override {
			const T& crtp = *static_cast<const T*>( this );
			return crtp.Value<float>( bytes );
		}

		virtual double Double ( byte* bytes ) const override {
			const T& crtp = *static_cast<const T*>( this );
			return crtp.Value<double>( bytes );
		}

		virtual ~RuntimeByteOrder ( ) {

		}

	};

}}
