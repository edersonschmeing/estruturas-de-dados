00001 // ============================================================
00002 #include "directed_graph.h"
00003 // ============================================================
00004 
00011 directed_graph::directed_graph( std::string name /*= ""*/, bool parallels_allowed /*= true*/ )
00012 {
00013     set_name( name );
00014     set_parallels_allowed( parallels_allowed );
00015 }
00016 
00022 directed_graph::~directed_graph()
00023 {
00024     // delete all vertices
00025     std::vector<vertex*>::iterator vertex_it = vertices().begin();
00026 
00027     while( vertex_it != vertices().end() )
00028     {
00029         // free the memory that had been allocated for a vertex
00030         delete *vertex_it; // implicitly calls destructor of vertex
00031 
00032         vertex_it++;
00033     }
00034 
00035     // call erase() for every item in the vector
00036     vertices().clear();
00037 }
00038 
00047 bool directed_graph::are_strongly_adjacent( vertex* p_vertex_0, vertex* p_vertex_1 )
00048 {
00049     if( graph::are_adjacent( p_vertex_0, p_vertex_1 ) && graph::are_adjacent( p_vertex_1, p_vertex_0 ) )
00050     {
00051         return true;
00052     }
00053 
00054     return false;
00055 }
00056 
00057 
00065 bool directed_graph::add_edge( vertex* p_src, vertex* p_dest, int weight/* = 0*/ )
00066 {
00067     edge* _edge = new edge( p_dest, weight );
00068 
00069     if( add_edge( p_src, _edge ) )
00070     {
00071         return true;
00072     }
00073 
00074     return false;
00075 
00076 }
00077 
00088 bool directed_graph::add_edge( vertex* p_src, edge *p_edge )
00089 {
00090     if( !parallels_allowed() )
00091     {
00092         // parallel edges not allowed, so check if there is already a matching edge
00093         if( p_src->has_according_edge( p_edge ) )
00094         {
00095             return false;
00096         }
00097     }
00098 
00099     p_src->add_edge( p_edge );
00100 
00101     return true;
00102 }
00103 
00109 bool directed_graph::remove_edge( vertex *p_vertex_0, vertex *p_vertex_1 )
00110 {
00111     std::vector<edge*>::iterator it_0 = p_vertex_0->neighbors().begin();
00112     std::vector<edge*>::iterator it_1 = p_vertex_1->neighbors().begin();
00113 
00114     // find destination vertex p_vertex_1 in neighbors of p_vertex_0
00115     while( it_0 != p_vertex_0->neighbors().end() )
00116     {
00117         if( (*it_0)->dest() == p_vertex_1 )
00118         {
00119             p_vertex_0->remove_edge( *it_0 );
00120 
00121             return true;
00122         }
00123     }
00124 
00125     return false;
00126 }
00127 
00135 bool directed_graph::remove_edge( edge *p_edge )
00136 {
00137     vertex* _vertex_src = graph::find_source( p_edge );
00138     vertex* _vertex_dest = p_edge->dest();
00139 
00140     if( remove_edge( _vertex_src, _vertex_dest ) )
00141     {
00142         return true;
00143     }
00144 
00145     return false;
00146 }
