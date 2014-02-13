#pragma once

#include <Furrovine++/ptr.h>
#include <Furrovine++/buffer_view.h>
#include <Furrovine++/Graphics/mapped.h>
#include <Furrovine++/Graphics/GraphicsResource.h>
#include <Furrovine++/Graphics/ShaderStage.h>
#include <Furrovine++/Graphics/ShaderParameterOptions.h>
#include <Furrovine++/Color.h>
#include <Furrovine++/RMatrix3.h>
#include <Furrovine++/RMatrix4.h>

namespace Furrovine { namespace Graphics {

	class ShaderParameter : public GraphicsResource {
	protected:
		typedef std::function<void( void*, ulword )> TMapper;
		ShaderStage stage;
		ShaderParameterOptions paramoptions;
		
		struct Proxy {
			ShaderParameter& parameter;
			
			furrovineapi Proxy( ShaderParameter& parameter );

			template <typename T>
			operator buffer_view<T>( );
			template <typename T>
			operator T ( );
			furrovineapi operator ShaderResourceView& ( );

			template <typename T>
			ShaderParameter& operator= ( const buffer_view<T>& value );
			template <typename T>
			ShaderParameter& operator= ( const T& value );
			furrovineapi ShaderParameter& operator= ( ShaderResourceView& value );
		};

		furrovineapi virtual TMapper GetMapper( );
	
	public:

		furrovineapi ShaderParameter( GraphicsDevice& graphics, ShaderStage method, const ShaderParameterOptions& options = ShaderParameterOptions::Default );
		furrovineapi ShaderParameter( ShaderParameter&& mov );
		furrovineapi ShaderParameter& operator=( ShaderParameter&& mov );
		
		furrovineapi ShaderStage Stage( ) const;

		template <typename T>
		void SetMultiValue( const buffer_view<T>& value );
		template <typename T>
		void SetMultiValue( const T* value, ulword count );
		template <typename T>
		void SetValue( const T& value );
		template <typename T>
		void SetValue( const T& value, ulword bytesize );
		template <typename T>
		void SetValue( const RMatrix4<T>& value );
		template <typename T>
		void SetValue( const TMatrix4<T>& value );
		template <typename T>
		void SetValue( const RRgba<T>& value );
		template <typename T>
		void SetValue( const TRgba<T>& value );
		furrovineapi void SetValue( const buffer_view<void>& value );
		
		template <typename T>
		buffer_view<T> GetMultiValue( ulword count );
		template <typename T>
		void GetMultiValue( buffer_view<T>& value );
		template <typename T>
		void GetMultiValue( T* value, ulword count ); 
		template <typename T>
		mapped<T> Map( );
		template <typename T>
		T GetValue( );
		template <typename T>
		void GetValue( T& value );
		template <typename T>
		void GetValue( RMatrix4<T>& value );
		template <typename T>
		void GetValue( TMatrix4<T>& value );
		template <typename T>
		void GetValue( T& value, ulword bytesize );
		template <>
		furrovineapi void GetValue<Color>( Color& value );
		furrovineapi void GetValue( buffer_view<void>& data );
		furrovineapi ShaderResourceView& GetResourceValue( );
		
		furrovineapi virtual const String& Name( ) const;
		furrovineapi virtual buffer_view<void> GetData( bool markdirty );
		furrovineapi virtual void SetValue( const void* value, ulword bytesize );
		furrovineapi virtual void SetResourceValue( ShaderResourceView& view );
		furrovineapi virtual void GetValue( void*& data, ulword bytesize );
		furrovineapi virtual void GetResourceValue( ShaderResourceView*& value );


		furrovineapi virtual ~ShaderParameter( );
	};

}}