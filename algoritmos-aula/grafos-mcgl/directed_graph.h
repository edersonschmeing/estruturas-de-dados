// ============================================================
#ifndef __DIRECTED_GRAPH_H__
#define __DIRECTED_GRAPH_H__
// ============================================================

// ============================================================
#include "graph.h"
#include "vertex.h"
#include "edge.h"
// ============================================================

#define DLL __declspec(dllexport)

class directed_graph : public graph
{
public:
    DLL directed_graph( std::string name = "", bool parallels_allowed = true );
    ~directed_graph();

    bool are_strongly_adjacent( vertex* p_vertex_0, vertex* p_vertex_1 );

    DLL bool add_edge( vertex* p_src, vertex* p_dest, int weight = 0 );
    DLL bool add_edge( vertex* p_src, edge* p_edge );

    DLL bool remove_edge( vertex* p_vertex_0, vertex* p_vertex_1 );
    DLL bool remove_edge( edge* p_edge );

};


#endif // __DIRECTED_GRAPH_H__
