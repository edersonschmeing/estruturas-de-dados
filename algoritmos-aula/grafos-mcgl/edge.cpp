#include "edge.h"

edge::edge( vertex* dest, int weight/* = 0*/ ) {
    set_dest( dest );
    set_weight( weight );
}

edge::~edge() {}

int edge::weight() {
    return m_weight;
}

void edge::set_weight( int weight ) {
    m_weight = weight;
}

vertex* edge::dest() {
    if( m_dest ) {
        return m_dest;
    }
    return 0;
}

void edge::set_dest( vertex* p_dest ) {
    m_dest = p_dest;
}