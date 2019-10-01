00001 // ============================================================
00002 #ifndef __DIJKSTRA_H__
00003 #define __DIJKSTRA_H__
00004 // ============================================================
00005 
00006 // ============================================================
00007 #include <iostream>
00008 #include <map>
00009 #include <cmath>
00010 #include <list>
00011 // ------------------------------------------------------------
00012 #include "graph.h"
00013 #include "vertex.h"
00014 #include "edge.h"
00015 // ============================================================
00016 
00017 #define DLL __declspec(dllexport)
00018 
00033 class dijkstra
00034 {
00035 public:
00036     DLL dijkstra( graph* p_graph, vertex* p_start );
00037     DLL std::list<vertex*> get_shortest_path_to( vertex* p_target_vertex );
00038     DLL void get_shortest_path_output( vertex* p_target_vertex, std::ostream& os );
00039 
00040 private:
00045     std::map<vertex*,int> distance_map; // first: vertex, second: distance to vertex from start
00046 
00051     std::map<vertex*,vertex*> pred_map; // first: vertex, second: predecessor of vertex
00052 
00057     std::vector<vertex*> queue; // not visited vertices
00058 
00063     graph* m_graph;
00064 
00069     vertex* m_start;
00070 
00071     bool initialize();
00072     void execute();
00073     vertex* get_vertex_with_shortest_distance();
00074     bool remove_vertex_from_queue( vertex* p_vertex );
00075     bool vertex_not_visited( vertex* p_vertex );
00076     void update_distance( vertex* p_current, edge* p_successor );
00077 
00078     
00079 };
00080 
00081 
00082 #endif // __DIJKSTRA_H_
