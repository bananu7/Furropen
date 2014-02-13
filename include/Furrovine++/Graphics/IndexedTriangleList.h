#pragma once

#include <Furrovine++/ArgumentException.h>
#include <Furrovine++/Graphics/TVertexTriangle.h>
#include <Furrovine++/unreachable.h>

namespace Furrovine { namespace Graphics {

	template <typename TVertex, typename TIndex>
	class IndexedTriangleList {
	private:
		std::vector<TVertex> vertices;
		std::vector<TVertex, TIndex> indices;
		PrimitiveTopology topology;

	public:
		typedef TVertexTriangle<TVertex> triangle;
		typedef TVertexTriangle<TVertex&> reference_triangle;

		IndexedTriangleList( PrimitiveTopology primitivetopology ) : topology(primitivetopology) {
			if ( topology != PrimitiveTopology::TriangleList 
				&& topology != PrimitiveTopology::TriangleStrip ) {
				throw ArgumentException( "The specified topology is not supported for IndexedTriangleList" );
			}
		}

		void push_back( const TVertex& vertex ) {
			vertices.push_back( vertex );
		}

		void push_back( TVertex&& vertex ) {
			vertices.push_back( std::move( vertex ) );
		}

		void push_back( const TIndex& index ) {
			vertices.push_back( index );
		}

		void push_back( TIndex&& index ) {
			vertices.push_back( std::move( index ) );
		}

		template <typename... Tn>
		void emplace_index_back( Tn&&... argn ) {
			indices.emplace_back( std::forward<Tn>( argn )... );
		}

		template <typename... Tn>
		void emplace_vertex_back( Tn&&... argn ) {
			vertices.emplace_back( std::forward<Tn>( argn )... );
		}

		reference_triangle operator[] ( std::size_t idx ) {
			switch ( topology ) {
			case PrimitiveTopology::TriangleList:
				idx /= 3;
				return reference_triangle( vertices[ indices[ idx ] ], vertices[ indices[ idx + 1 ] ], vertices[ indices[ idx + 2 ] ] );
				break;
			case PrimitiveTopology::TriangleStrip:
				idx += 2;
				return reference_triangle( vertices[ indices[ idx ] ], vertices[ indices[ idx - 1 ] ], vertices[ indices[ idx - 2 ] ] );
				break;
			default:
				unreachable;
				break;
			}
		}

	};


}}