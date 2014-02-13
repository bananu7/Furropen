#pragma once

#include <Furrovine++/std_defines.h>
#include <array>
#include <Furrovine++/Graphics/ShaderStage.h>
#include <Furrovine++/Graphics/ShaderCompilationFlags.h>
#include <Furrovine++/Graphics/ShaderVersion.h>
#include <Furrovine++/Graphics/ShaderParameterOptions.h>
#include <Furrovine++/Graphics/ShaderInclude.h>
#include <Furrovine++/buffer_container.h>

namespace Furrovine { namespace Graphics {

	struct ShaderSource {
	private:
		furrovineapi void GuessMethodType( );

	public:
		furrovineapi static const ShaderSource Empty;
		ShaderParameterOptions ParameterOptions;
		ShaderCompilationFlags CompileFlags;
		ShaderStage Stage;
		ShaderVersion Version;
		String SourceFile;
		buffer_container<byte> Source;
		String EntryPoint;
		ShaderInclude Include;

		furrovineapi ShaderSource( );
		furrovineapi ShaderSource( String source, const String& entrypoint, const String& file = "", ShaderStage method = ShaderStage::Unknown );
		furrovineapi ShaderSource( ShaderStage method );
		furrovineapi ShaderSource( const ShaderSource& copy ) = default;
		furrovineapi ShaderSource& operator=( const ShaderSource& copy ) = default;
		furrovineapi ShaderSource( ShaderSource&& mov );
		furrovineapi ShaderSource& operator=( ShaderSource&& mov );

		furrovineapi bool Compilable () const;

		furrovineapi String ShaderModel () const;

		furrovineapi String ShaderModel ( ShaderVersion version ) const;

		furrovineapi static String ShaderModel( ShaderStage method, ShaderVersion version, ShaderCompilationFlags flags );

		furrovineapi static void ShaderMethodVersion ( const String& model, ShaderStage& method, ShaderVersion& version, ShaderCompilationFlags& flags );

	};

}}
