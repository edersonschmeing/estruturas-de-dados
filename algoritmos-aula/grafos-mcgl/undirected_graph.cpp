// ============================================================
#include <iostream>
#include <fstream>
// ------------------------------------------------------------
#include "undirected_graph.h"
// ============================================================


undirected_graph::undirected_graph( std::string name /*= ""*/, bool parallels_allowed /*= true*/ )
{
    set_name( name );
    set_parallels_allowed( parallels_allowed );
}

undirected_graph::~undirected_graph()
{
    // delete all vertices
    std::vector<vertex*>::iterator vertex_it = vertices().begin();

    while( vertex_it != vertices().end() )
    {
        // free the memory that had been allocated for a vertex
        delete *vertex_it; // implicitly calls destructor of vertex

        vertex_it++;
    }

    // call erase() for every item in the vector
    vertices().clear();
}

bool undirected_graph::add_edge( vertex* p_src, vertex* p_dest, int weight/* = 0*/ )
{
    edge* _edge = new edge( p_dest, weight );

    if( add_edge( p_src, _edge ) )
    {
        return true;
    }

    return false;
}

bool undirected_graph::add_edge( vertex* p_src, edge *p_edge )
{
    if( !parallels_allowed() )
    {
        // parallel edges not allowed, so check if there is already a matching edge
        if( p_src->has_according_edge( p_edge ) )
        {
            return false;
        }
    }

    // from source to destination
    p_src->add_edge( p_edge );

    // if edge is not a loop
    if( p_src != p_edge->dest() )
    {
        // from destination to source
        p_edge->dest()->add_edge( new edge( p_src, p_edge->weight() ) );
    }

    return true;
}

bool undirected_graph::remove_edge( vertex *p_vertex_0, vertex *p_vertex_1 )
{
    std::vector<edge*>::iterator it_0 = p_vertex_0->neighbors().begin();
    std::vector<edge*>::iterator it_1 = p_vertex_1->neighbors().begin();

    // find destination vertex p_vertex_1 in neighbors of p_vertex_0
    while( it_0 != p_vertex_0->neighbors().end() )
    {
        if( (*it_0)->dest() == p_vertex_1 )
        {
            p_vertex_0->remove_edge( *it_0 );

            // find destination vertex p_vertex_0 in neighbors of p_vertex_1
            while( it_1 != p_vertex_1->neighbors().end() )
            {
                if( (*it_1)->dest() == p_vertex_0 )
                {
                    p_vertex_1->remove_edge( *it_1 );
                }
            }

            return true;
        }
    }

    return false;
}

bool undirected_graph::remove_edge( edge *p_edge )
{
    vertex* _vertex_src = find_source( p_edge );
    vertex* _vertex_dest = p_edge->dest();

    if( remove_edge( _vertex_src, _vertex_dest ) )
    {
        return true;
    }

    return false;
}