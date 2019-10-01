00001 // ============================================================
00002 #ifndef __DIRECTED_GRAPH_H__
00003 #define __DIRECTED_GRAPH_H__
00004 // ============================================================
00005 
00006 // ============================================================
00007 #include "graph.h"
00008 #include "vertex.h"
00009 #include "edge.h"
00010 // ============================================================
00011 
00012 #define DLL __declspec(dllexport)
00013 
00023 class directed_graph : public graph
00024 {
00025 public:
00026     DLL directed_graph( std::string name = "", bool parallels_allowed = true );
00027     ~directed_graph();
00028 
00029     bool are_strongly_adjacent( vertex* p_vertex_0, vertex* p_vertex_1 );
00030 
00031     DLL bool add_edge( vertex* p_src, vertex* p_dest, int weight = 0 );
00032     DLL bool add_edge( vertex* p_src, edge* p_edge );
00033 
00034     DLL bool remove_edge( vertex* p_vertex_0, vertex* p_vertex_1 );
00035     DLL bool remove_edge( edge* p_edge );
00036 
00037 };
00038 
00039 
00040 #endif // __DIRECTED_GRAPH_H__


