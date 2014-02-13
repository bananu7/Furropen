#pragma once

#include <Furrovine++/FurrovineApi.h>
#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/ptr.h>

namespace Furrovine {

	class BufferData {
	private:
		struct Preserver {
		public:

			furrovineapi virtual void* data ();

			furrovineapi virtual const void* data () const;

			furrovineapi virtual ulword size () const;

			furrovineapi virtual ulword bytesize () const;

			furrovineapi virtual ~Preserver();
		};

		template <typename T, typename TElem = typename T::value_type>
		struct ContainerPreserver : public Preserver {
		public:
			T container;

			ContainerPreserver ( T&& buffercontainer ) : container( std::move(buffercontainer) ) {

			}

			ContainerPreserver ( const T& buffercontainer ) : container( buffercontainer ) {

			}

			virtual void* data () override {
				return reinterpret_cast<void*>( container.data() );
			}

			virtual const void* data () const override {
				return reinterpret_cast<const void*>( container.data() );
			}

			virtual ulword size () const override {
				return container.size();
			}

			virtual ulword bytesize () const override {
				return container.size() * sizeof( TElem );
			}
		};

		ptr<Preserver> bufferpreserve;

	public:

		template <typename TContainer>
		BufferData ( TContainer&& container, ulword count );

		furrovineapi BufferData ( BufferData&& mov );

		furrovineapi BufferData& operator= ( BufferData&& mov );

		furrovineapi void* data ();

		furrovineapi const void* data () const;

		furrovineapi ulword bytesize () const;

	};

}
