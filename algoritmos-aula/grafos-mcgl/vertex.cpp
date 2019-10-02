// ============================================================
#include "vertex.h"
// ============================================================

vertex::vertex( std::string name, int weight /*= 0*/ ) {
    set_name( name );
    set_weight( weight );
}

vertex::~vertex() {
    std::vector<edge*>::iterator it = m_neighbors.begin();

    while( it != m_neighbors.end() )     {
        delete *it; // implicitly calls destructor of edge
        it++;
    }
    m_neighbors.clear();
}

std::string vertex::name() {
    return m_name;
}

void vertex::set_name( std::string name ) {
    if( !name.empty() ) {
        m_name = name;
    }
}

int vertex::weight() {
    return m_weight;
}

void vertex::set_weight( int weight ) {
    m_weight = weight;
}

std::vector<edge*>& vertex::neighbors() {
    return m_neighbors;
}

bool vertex::has_successor( vertex* p_vertex ) {
    std::vector<edge*>::iterator it = m_neighbors.begin();

    while( it != m_neighbors.end() )     {
        if( (*it)->dest() == p_vertex )         {
            return true;
        }
        it++;
    }
    return false;
}

bool vertex::has_exact_edge( edge* p_edge ) {

    std::vector<edge*>::iterator it = m_neighbors.begin();

    while( it != m_neighbors.end() ) {
        if( *it == p_edge ) {
            return true;
        }
        it++;
    }
    return false;
}

bool vertex::has_according_edge( edge* p_edge ) {

    std::vector<edge*>::iterator it = m_neighbors.begin();

    while( it != m_neighbors.end() )     {
        if( (*it)->dest() == p_edge->dest() )         {
            return true;
        }
        it++;
    }
    return false;
}

void vertex::add_edge( edge* p_edge ) {
    m_neighbors.push_back( p_edge );
}

std::vector<edge*>::iterator vertex::remove_edge( edge* p_edge ) {
    std::vector<edge*>::iterator it = m_neighbors.begin();

    while( *it != p_edge ) {
        if( it == m_neighbors.end() )         {
            return it;
        }
        it++;
    }
    // delete edge itself
    delete *it;

    // remove edge from vector and save iterator position
    std::vector<edge*>::iterator result_it = m_neighbors.erase( it );

    return result_it;

    //return true;
}