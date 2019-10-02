// ============================================================
#include <iostream>
#include <fstream>
// ------------------------------------------------------------
#include "graph.h"
// ============================================================


graph::graph(){}

graph::~graph() {
    // delete all vertices
    std::vector<vertex*>::iterator vertex_it = m_vertices.begin();

    while( vertex_it != m_vertices.end() )     {
        // free the memory that had been allocated for a vertex
        delete *vertex_it; // implicitly calls destructor of vertex
        vertex_it++;
    }
    m_vertices.clear();
}

std::vector<vertex*>& graph::vertices() {
    return m_vertices;
}

size_t graph::vertices_count() {
    return m_vertices.size();
}

size_t graph::edges_count() {
    size_t edge_count = 0;

    // add count of edges for every vertex in the graph
    for( unsigned int i = 0; i < m_vertices.size(); i++ )     {
        edge_count += m_vertices.at( i )->neighbors().size();
    }

    return edge_count;
}

std::string graph::name() {
    return m_name;
}

void graph::set_name( std::string name ) {
    if( !name.empty() )     {
        m_name = name;
    }
}

bool graph::parallels_allowed() {
    return m_parallels_allowed;
}

void graph::set_parallels_allowed( bool allowed ) {
    m_parallels_allowed = allowed;
}

bool graph::add_vertex( std::string name, int weight /*= 0*/ ) {
    vertex* _vertex = new vertex( name, weight );
    
    if( add_vertex( _vertex ) )     {
        return true;
    }else{
        return false;
    }
}

bool graph::add_vertex( vertex* p_vertex ) {
    // check if graph already contains same vertex or a vertex with same name
    std::vector<vertex*>::iterator it = m_vertices.begin();

    while( it != m_vertices.end() )     {
        if( (*it) == p_vertex || (*it)->name() == p_vertex->name() )         {
            return false;
        }
        it++;
    }
    // add vertex to graph
    m_vertices.push_back( p_vertex );
    return true;
}

bool graph::remove_vertex( std::string name ) {
    vertex* _vertex_to_delete = get_vertex_by_name( name );

    if( remove_vertex( _vertex_to_delete ) )     {
        return true;
    }

    return false;
}

bool graph::remove_vertex( vertex* p_vertex ) {
    std::vector<vertex*>::iterator it = m_vertices.begin();

    while( it != m_vertices.end() ) {
        if( *it == p_vertex ) {
            // delete edges pointing to p_vertex
            // IMPORTANT: all edges pointing AWAY from p_vertex are implicitly removed by the desctructor of p_vertex
            remove_edges_pointing_to( p_vertex );

            // delete what iterator points to (the vertex itself)
            delete *it;

            // remove vertex item from vector
            m_vertices.erase( it );

            return true;
        }

        it++;
    }
    return false;
}

vertex* graph::get_vertex_by_name( std::string name ) {
    std::vector<vertex*>::iterator it = m_vertices.begin();

    while( it != m_vertices.end() ) {
        if( (*it)->name() == name ) {
            return *it;
        }
        it++;
    }
    return NULL;
}

bool graph::has_loop() {
    for( unsigned int i = 0; i < m_vertices.size(); i++ ) {
        size_t neighbor_count = m_vertices.at(i)->neighbors().size();

        for( unsigned int j = 0; j < neighbor_count; j++ )         {
            if( m_vertices.at(i) == m_vertices.at(i)->neighbors().at(j)->dest() )             {
                return true;
            }
        }
    }
    return false;
}

void graph::vertices_output( std::ostream & ostream ) {
    ostream << "=== Output begin ===\n\n";

    std::vector<vertex*>::iterator it = m_vertices.begin();
    int i = 0;

    while( it != m_vertices.end() )     {
        ostream << "Vertex no. " << i << " with the name \""  << (*it)->name() << "\"\n";
        
        it++;
        i++;
    }

    ostream << "\nTotal count of vertices: " << vertices_count() << "\n";
    ostream << "Total count of edges: " << edges_count() << "\n";

    ostream << "=== Output end ===\n\n";
}

bool graph::are_adjacent( vertex* p_vertex_0, vertex* p_vertex_1 ) {
    if( p_vertex_0->has_successor( p_vertex_1 ) ) {
        return true;
    }

    return false;
}

vertex* graph::find_source( edge* p_edge ) {
    std::vector<vertex*>::iterator it = m_vertices.begin();

    while( it != m_vertices.end() )     {
        if( (*it)->has_exact_edge( p_edge ) )         {
            return *it;
        }
        it++;
    }
    return NULL;
}

bool graph::remove_edges_pointing_to( vertex* p_vertex ) {
    bool res = false;

    std::vector<vertex*>::iterator vertex_it = m_vertices.begin();

    // iterate through all vertices
    while( vertex_it != m_vertices.end() )     {
        // iterator on first element of neighbors of vertex
        std::vector<edge*>::iterator neighbor_it = (*vertex_it)->neighbors().begin();

        // iterate through all successors of each vertex
        while( neighbor_it != (*vertex_it)->neighbors().end() )         {
            if( (*neighbor_it)->dest() == p_vertex )             {
                neighbor_it = (*vertex_it)->remove_edge( *neighbor_it );
                res = true;
            }else{
                neighbor_it++;
            }
        }
        vertex_it++;
    }
    return res;
}
