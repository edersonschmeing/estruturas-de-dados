00001 // ============================================================
00002 #include <iostream>
00003 #include <fstream>
00004 // ------------------------------------------------------------
00005 #include "graph.h"
00006 // ============================================================
00007 
00008 
00012 graph::graph()
00013 {
00014 }
00015 
00021 graph::~graph()
00022 {
00023     // delete all vertices
00024     std::vector<vertex*>::iterator vertex_it = m_vertices.begin();
00025 
00026     while( vertex_it != m_vertices.end() )
00027     {
00028         // free the memory that had been allocated for a vertex
00029         delete *vertex_it; // implicitly calls destructor of vertex
00030 
00031         vertex_it++;
00032     }
00033 
00034     m_vertices.clear();
00035 }
00036 
00042 std::vector<vertex*>& graph::vertices()
00043 {
00044     return m_vertices;
00045 }
00046 
00052 size_t graph::vertices_count()
00053 {
00054     return m_vertices.size();
00055 }
00056 
00062 size_t graph::edges_count()
00063 {
00064     size_t edge_count = 0;
00065 
00066     // add count of edges for every vertex in the graph
00067     for( unsigned int i = 0; i < m_vertices.size(); i++ )
00068     {
00069         edge_count += m_vertices.at( i )->neighbors().size();
00070     }
00071 
00072     return edge_count;
00073 }
00074 
00080 std::string graph::name()
00081 {
00082     return m_name;
00083 }
00084 
00088 void graph::set_name( std::string name )
00089 {
00090     if( !name.empty() )
00091     {
00092         m_name = name;
00093     }
00094 }
00095 
00101 bool graph::parallels_allowed()
00102 {
00103     return m_parallels_allowed;
00104 }
00105 
00109 void graph::set_parallels_allowed( bool allowed )
00110 {
00111     m_parallels_allowed = allowed;
00112 }
00113 
00121 bool graph::add_vertex( std::string name, int weight /*= 0*/ )
00122 {
00123     vertex* _vertex = new vertex( name, weight );
00124     
00125     if( add_vertex( _vertex ) )
00126     {
00127         return true;
00128     }
00129     else
00130     {
00131         return false;
00132     }
00133 }
00134 
00142 bool graph::add_vertex( vertex* p_vertex )
00143 {
00144     // check if graph already contains same vertex or a vertex with same name
00145     std::vector<vertex*>::iterator it = m_vertices.begin();
00146 
00147     while( it != m_vertices.end() )
00148     {
00149         if( (*it) == p_vertex || (*it)->name() == p_vertex->name() )
00150         {
00151             return false;
00152         }
00153 
00154         it++;
00155     }
00156 
00157     // add vertex to graph
00158     m_vertices.push_back( p_vertex );
00159     
00160     return true;
00161 }
00162 
00168 bool graph::remove_vertex( std::string name )
00169 {
00170     vertex* _vertex_to_delete = get_vertex_by_name( name );
00171 
00172     if( remove_vertex( _vertex_to_delete ) )
00173     {
00174         return true;
00175     }
00176 
00177     return false;
00178 }
00179 
00188 bool graph::remove_vertex( vertex* p_vertex )
00189 {
00190     std::vector<vertex*>::iterator it = m_vertices.begin();
00191 
00192     while( it != m_vertices.end() )
00193     {
00194         if( *it == p_vertex )
00195         {
00196             // delete edges pointing to p_vertex
00197             // IMPORTANT: all edges pointing AWAY from p_vertex are implicitly removed by the desctructor of p_vertex
00198             remove_edges_pointing_to( p_vertex );
00199 
00200             // delete what iterator points to (the vertex itself)
00201             delete *it;
00202 
00203             // remove vertex item from vector
00204             m_vertices.erase( it );
00205 
00206             return true;
00207         }
00208 
00209         it++;
00210     }
00211 
00212     return false;
00213 }
00214 
00220 vertex* graph::get_vertex_by_name( std::string name )
00221 {
00222     std::vector<vertex*>::iterator it = m_vertices.begin();
00223 
00224     while( it != m_vertices.end() )
00225     {
00226         if( (*it)->name() == name )
00227         {
00228             return *it;
00229         }
00230 
00231         it++;
00232     }
00233 
00234     return NULL;
00235 }
00236 
00245 bool graph::has_loop()
00246 {
00247     for( unsigned int i = 0; i < m_vertices.size(); i++ )
00248     {
00249         size_t neighbor_count = m_vertices.at(i)->neighbors().size();
00250 
00251         for( unsigned int j = 0; j < neighbor_count; j++ )
00252         {
00253             if( m_vertices.at(i) == m_vertices.at(i)->neighbors().at(j)->dest() )
00254             {
00255                 return true;
00256             }
00257         }
00258     }
00259 
00260     return false;
00261 }
00262 
00268 void graph::vertices_output( std::ostream & ostream )
00269 {
00270     ostream << "=== Output begin ===\n\n";
00271 
00272     std::vector<vertex*>::iterator it = m_vertices.begin();
00273     int i = 0;
00274 
00275     while( it != m_vertices.end() )
00276     {
00277         ostream << "Vertex no. " << i << " with the name \""  << (*it)->name() << "\"\n";
00278         
00279         it++;
00280         i++;
00281     }
00282 
00283     ostream << "\nTotal count of vertices: " << vertices_count() << "\n";
00284     ostream << "Total count of edges: " << edges_count() << "\n";
00285 
00286     ostream << "=== Output end ===\n\n";
00287 }
00288 
00298 bool graph::are_adjacent( vertex* p_vertex_0, vertex* p_vertex_1 )
00299 {
00300     if( p_vertex_0->has_successor( p_vertex_1 ) )
00301     {
00302         return true;
00303     }
00304 
00305     return false;
00306 }
00307 
00313 vertex* graph::find_source( edge* p_edge )
00314 {
00315     std::vector<vertex*>::iterator it = m_vertices.begin();
00316 
00317     while( it != m_vertices.end() )
00318     {
00319         if( (*it)->has_exact_edge( p_edge ) )
00320         {
00321             return *it;
00322         }
00323 
00324         it++;
00325     }
00326 
00327     return NULL;
00328 }
00329 
00337 bool graph::remove_edges_pointing_to( vertex* p_vertex )
00338 {
00339     bool res = false;
00340 
00341     std::vector<vertex*>::iterator vertex_it = m_vertices.begin();
00342 
00343     // iterate through all vertices
00344     while( vertex_it != m_vertices.end() )
00345     {
00346         // iterator on first element of neighbors of vertex
00347         std::vector<edge*>::iterator neighbor_it = (*vertex_it)->neighbors().begin();
00348 
00349         // iterate through all successors of each vertex
00350         while( neighbor_it != (*vertex_it)->neighbors().end() )
00351         {
00352             if( (*neighbor_it)->dest() == p_vertex )
00353             {
00354                 neighbor_it = (*vertex_it)->remove_edge( *neighbor_it );
00355                 res = true;
00356             }
00357             else
00358             {
00359                 neighbor_it++;
00360             }
00361         }
00362 
00363         vertex_it++;
00364     }
00365 
00366     return res;
00367 }
