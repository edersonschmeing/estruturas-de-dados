// ============================================================
#ifndef __VERTEX_H__
#define __VERTEX_H__
// ============================================================

// ============================================================
#include <string>
#include <vector>
// ------------------------------------------------------------
#include "edge.h"
// ============================================================


class edge;
class vertex {
public:
    vertex( std::string name, int weight = 0 );
    virtual ~vertex();

    std::string name();
    void set_name( std::string name );

    int weight();
    void set_weight( int weight );

    std::vector<edge*>& neighbors();

    void add_edge( edge* p_edge );
    std::vector<edge*>::iterator remove_edge( edge* p_edge );

    bool has_successor( vertex* p_vertex );

    bool has_exact_edge( edge* p_edge );
    bool has_according_edge( edge* p_edge );

private:
    std::string m_name;
    int m_weight;
    std::vector<edge*> m_neighbors;
};

#endif