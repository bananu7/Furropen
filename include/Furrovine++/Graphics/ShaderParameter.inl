#pragma once

#include <Furrovine++/Graphics/ShaderParameter.h>

namespace Furrovine { namespace Graphics {
	
	template <typename T>
	mapped<T> ShaderParameter::Map( ) {
		return mapped<T>( GetData( std::is_const<T>::value ), GetMapper() );
	}

	template <typename T>
	void ShaderParameter::SetMultiValue( const buffer_view<T>& value ) {
		SetMultiValue( value.data( ), value.size( ) );
	}

	template <typename T>
	void ShaderParameter::SetMultiValue( const T* value, ulword count ) {
		SetValue( static_cast<const void*>( value ), sizeof( T ) * count );
	}

	template <typename T>
	void ShaderParameter::SetValue( const T& value ) {
		SetValue( value, sizeof( value ) );
	}

	template <typename T>
	void ShaderParameter::SetValue( const T& value, ulword bytesize ) {
		SetValue( static_cast<const void*>( std::addressof( value ) ), bytesize );
	}

	template <typename T>
	void ShaderParameter::SetValue( const RMatrix4<T>& value ) {
		RMatrix4<T> shadervalue = ToShader( value, paramoptions.RowMajor ? MemoryLayout::RowMajor : MemoryLayout::ColumnMajor );
		SetValue( shadervalue, sizeof( shadervalue ) );
	}

	template <typename T>
	void ShaderParameter::SetValue( const TMatrix4<T>& value ) {
		SetValue( static_cast<const RMatrix4<T>&>( value ) );
	}

	template <typename T>
	void ShaderParameter::SetValue( const RRgba<T>& value ) {
		RRgba<T> shadervalue = ToShader( value );
		SetValue( shadervalue, sizeof( shadervalue ) );
	}

	template <typename T>
	void ShaderParameter::SetValue( const TRgba<T>& value ) {
		SetValue( static_cast<const RRgba<T>&>( value ) );
	}

	template <typename T>
	T ShaderParameter::GetValue( ) {
		T value;
		GetValue( value );
		return value;
	}

	template <typename T>
	void ShaderParameter::GetValue( T& value ) {
		GetValue( value, sizeof( value ) );
	}

	template <typename T>
	void ShaderParameter::GetValue( RMatrix4<T>& value ) {
		GetValue( value, sizeof( Matrix ) );
		UnShaderize( value, paramoptions.RowMajor ? MemoryLayout::RowMajor : MemoryLayout::ColumnMajor );
	}

	template <typename T>
	void ShaderParameter::GetValue( TMatrix4<T>& value ) {
		GetValue( static_cast<RMatrix4<T>&>( value ) );
	}

	template <typename T>
	void ShaderParameter::GetValue( T& value, ulword bytesize ) {
		buffer_view<void> data( static_cast<void*>( std::addressof( value ) ), bytesize );
		GetValue( data );
	}

	template <typename T>
	buffer_view<T> ShaderParameter::GetMultiValue( ulword count ) {
		buffer_view<T> value( null, count );
		GetMultiValue( value );
		return value;
	}

	template <typename T>
	void ShaderParameter::GetMultiValue( buffer_view<T>& value ) {
		GetMultiValue( value.data(), value.size() );
	}

	template <typename T>
	void ShaderParameter::GetMultiValue( T* value, ulword count ) {
		for ( ulword i = 0; i < count; ++i ) {
			GetValue( value[i], sizeof( T ) );
		}
	}

	template <typename T>
	ShaderParameter& ShaderParameter::Proxy::operator= ( const T& value ) {
		SetValue( value );
		return *this;
	}

	template <typename T>
	ShaderParameter& ShaderParameter::Proxy::operator= ( const buffer_view<T>& value ) {
		SetMultiValue( value );
		return *this;
	}

	template <typename T>
	ShaderParameter::Proxy::operator T ( ) {
		return GetValue<T>( );
	}

	template <typename T>
	ShaderParameter::Proxy::operator buffer_view<T>( ) {
		return GetMultiValue<T>( );
	}

}}
