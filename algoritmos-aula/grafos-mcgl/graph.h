#pragma region documentation mainpage

#pragma endregion

#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>

#include "vertex.h"
#include "edge.h"

class graph {
public:
    graph();
    ~graph();

    bool add_vertex( std::string name, int weight = 0 );
    bool add_vertex( vertex* p_vertex );

    virtual bool add_edge( vertex* p_src, vertex* p_dest, int weight = 0 )  = 0;    // pure virtual function
    virtual bool add_edge( vertex* p_src, edge* p_edge ) = 0;                       // pure virtual function

    bool remove_vertex( std::string name );
    bool remove_vertex( vertex* p_vertex );

    virtual bool remove_edge( vertex* p_vertex_0, vertex* p_vertex_1 ) = 0;         // pure virtual function
    virtual bool remove_edge( edge* p_edge ) = 0;                                   // pure virtual function

    void vertices_output( std::ostream& ostream );

    std::vector<vertex*>& vertices();

protected:
    size_t vertices_count();
    size_t edges_count();

    std::string name();
    void set_name( std::string name );

    bool parallels_allowed();
    void set_parallels_allowed( bool allowed );

    bool has_loop();

    bool are_adjacent( vertex* p_vertex_0, vertex* p_vertex_1 );

    vertex* get_vertex_by_name( std::string name );

    vertex* find_source( edge* p_edge );

    bool remove_edges_pointing_to( vertex* p_vertex );

private:
    std::string m_name;
    bool m_parallels_allowed;
    std::vector<vertex*>    m_vertices;
};

#endif 