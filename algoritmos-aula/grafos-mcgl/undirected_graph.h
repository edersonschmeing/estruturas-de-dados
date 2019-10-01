00001 // ============================================================
00002 #ifndef __UNDIRECTED_GRAPH_H__
00003 #define __UNDIRECTED_GRAPH_H__
00004 // ============================================================
00005 
00006 // ============================================================
00007 // ------------------------------------------------------------
00008 #include "graph.h"
00009 #include "vertex.h"
00010 #include "edge.h"
00011 // ============================================================
00012 
00013 #define DLL __declspec(dllexport)
00014 
00024 class undirected_graph : public graph
00025 {
00026 public:
00027     DLL undirected_graph( std::string name = "", bool parallels_allowed = true );
00028     ~undirected_graph();
00029 
00030     DLL bool add_edge( vertex* p_src, vertex* p_dest, int weight = 0 );
00031     DLL bool add_edge( vertex* p_src, edge* p_edge );
00032 
00033     DLL bool remove_edge( vertex* p_vertex_0, vertex* p_vertex_1 );
00034     DLL bool remove_edge( edge* p_edge );
00035 };
00036 
00037 #endif // __UNDIRECTED_GRAPH_H__
