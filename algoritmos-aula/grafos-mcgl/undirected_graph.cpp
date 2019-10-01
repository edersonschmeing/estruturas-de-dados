00001 // ============================================================
00002 #include <iostream>
00003 #include <fstream>
00004 // ------------------------------------------------------------
00005 #include "undirected_graph.h"
00006 // ============================================================
00007 
00008 
00015 undirected_graph::undirected_graph( std::string name /*= ""*/, bool parallels_allowed /*= true*/ )
00016 {
00017     set_name( name );
00018     set_parallels_allowed( parallels_allowed );
00019 }
00020 
00026 undirected_graph::~undirected_graph()
00027 {
00028     // delete all vertices
00029     std::vector<vertex*>::iterator vertex_it = vertices().begin();
00030 
00031     while( vertex_it != vertices().end() )
00032     {
00033         // free the memory that had been allocated for a vertex
00034         delete *vertex_it; // implicitly calls destructor of vertex
00035 
00036         vertex_it++;
00037     }
00038 
00039     // call erase() for every item in the vector
00040     vertices().clear();
00041 }
00042 
00050 bool undirected_graph::add_edge( vertex* p_src, vertex* p_dest, int weight/* = 0*/ )
00051 {
00052     edge* _edge = new edge( p_dest, weight );
00053 
00054     if( add_edge( p_src, _edge ) )
00055     {
00056         return true;
00057     }
00058 
00059     return false;
00060 }
00061 
00073 bool undirected_graph::add_edge( vertex* p_src, edge *p_edge )
00074 {
00075     if( !parallels_allowed() )
00076     {
00077         // parallel edges not allowed, so check if there is already a matching edge
00078         if( p_src->has_according_edge( p_edge ) )
00079         {
00080             return false;
00081         }
00082     }
00083 
00084     // from source to destination
00085     p_src->add_edge( p_edge );
00086 
00087     // if edge is not a loop
00088     if( p_src != p_edge->dest() )
00089     {
00090         // from destination to source
00091         p_edge->dest()->add_edge( new edge( p_src, p_edge->weight() ) );
00092     }
00093 
00094     return true;
00095 }
00096 
00105 bool undirected_graph::remove_edge( vertex *p_vertex_0, vertex *p_vertex_1 )
00106 {
00107     std::vector<edge*>::iterator it_0 = p_vertex_0->neighbors().begin();
00108     std::vector<edge*>::iterator it_1 = p_vertex_1->neighbors().begin();
00109 
00110     // find destination vertex p_vertex_1 in neighbors of p_vertex_0
00111     while( it_0 != p_vertex_0->neighbors().end() )
00112     {
00113         if( (*it_0)->dest() == p_vertex_1 )
00114         {
00115             p_vertex_0->remove_edge( *it_0 );
00116 
00117             // find destination vertex p_vertex_0 in neighbors of p_vertex_1
00118             while( it_1 != p_vertex_1->neighbors().end() )
00119             {
00120                 if( (*it_1)->dest() == p_vertex_0 )
00121                 {
00122                     p_vertex_1->remove_edge( *it_1 );
00123                 }
00124             }
00125 
00126             return true;
00127         }
00128     }
00129 
00130     return false;
00131 }
00132 
00140 bool undirected_graph::remove_edge( edge *p_edge )
00141 {
00142     vertex* _vertex_src = find_source( p_edge );
00143     vertex* _vertex_dest = p_edge->dest();
00144 
00145     if( remove_edge( _vertex_src, _vertex_dest ) )
00146     {
00147         return true;
00148     }
00149 
00150     return false;
00151 }
