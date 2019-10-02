 // ============================================================
 #ifndef __UNDIRECTED_GRAPH_H__
 #define __UNDIRECTED_GRAPH_H__
 // ============================================================
 
 // ============================================================
 // ------------------------------------------------------------
 #include "graph.h"
 #include "vertex.h"
 #include "edge.h"
 // ============================================================
 
 #define DLL __declspec(dllexport)
 
 class undirected_graph : public graph
 {
 public:
     DLL undirected_graph( std::string name = "", bool parallels_allowed = true );
     ~undirected_graph();
 
     DLL bool add_edge( vertex* p_src, vertex* p_dest, int weight = 0 );
     DLL bool add_edge( vertex* p_src, edge* p_edge );
 
     DLL bool remove_edge( vertex* p_vertex_0, vertex* p_vertex_1 );
     DLL bool remove_edge( edge* p_edge );
 };
 
 #endif // __UNDIRECTED_GRAPH_H__