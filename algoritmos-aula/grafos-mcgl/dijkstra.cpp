00001 // ============================================================
00002 #include "dijkstra.h"
00003 // ============================================================
00004 
00008 dijkstra::dijkstra( graph *p_graph, vertex *p_start )
00009 : m_graph( p_graph ),
00010 m_start( p_start )
00011 {
00012     if( !initialize() )
00013     {
00014         std::cout << "Processing not possible. Error: Empty maps." << std::endl;
00015     }
00016 
00017     execute();
00018 }
00019 
00030 bool dijkstra::initialize()
00031 {
00032     std::vector<vertex*>::iterator g_vertex_it = m_graph->vertices().begin();
00033 
00034     while( g_vertex_it != m_graph->vertices().end() )
00035     {
00036         // initialize distance and predecessor maps
00037         distance_map.insert( std::pair<vertex*,int>( *g_vertex_it, INT_MAX ) );
00038         pred_map.insert( std::pair<vertex*,vertex*>( *g_vertex_it, NULL ) );
00039 
00040         // insert each vertex into not-visited vertices vector
00041         queue.push_back( *g_vertex_it );
00042 
00043         g_vertex_it++;
00044     }
00045 
00046 
00047 
00048     if( !distance_map.empty() && !pred_map.empty() )
00049     {
00050         // set distance of start vertex to 0
00051         distance_map.find( m_start )->second = 0;
00052 
00053         return true;
00054     }
00055     
00056     return false;
00057 }
00058 
00064 void dijkstra::execute()
00065 {
00066     /*
00067         Summary after initialization:
00068 
00069             queued = { all vertices }
00070             distance = distance for every vertex is "infinite"
00071             pred = predecessor for every vertex is NULL
00072     */
00073 
00074     vertex* _current = 0;
00075 
00076     while( !queue.empty() )
00077     {
00078         _current = get_vertex_with_shortest_distance();
00079         
00080         remove_vertex_from_queue( _current );
00081 
00082         // for every not visited successor of _current
00083         std::vector<edge*>::iterator successor_it = _current->neighbors().begin();
00084 
00085         while( successor_it != _current->neighbors().end() )
00086         {
00087             if( vertex_not_visited( (*successor_it)->dest() ) )
00088             {
00089                 update_distance( _current, *successor_it );
00090             }
00091 
00092             successor_it++;
00093         }
00094     }
00095 }
00096 
00102 vertex* dijkstra::get_vertex_with_shortest_distance()
00103 {
00104     vertex* _min_dist_vertex = 0;
00105     int min_dist = INT_MAX;
00106 
00107     std::vector<vertex*>::iterator queue_it = queue.begin();
00108     while( queue_it != queue.end() )
00109     {
00110         if( distance_map.find( *queue_it )->second < min_dist )
00111         {
00112             min_dist = distance_map.find( *queue_it )->second;
00113             _min_dist_vertex = *queue_it;
00114         }
00115 
00116         queue_it++;
00117     }
00118 
00119     return _min_dist_vertex;
00120 
00121 }
00122 
00128 bool dijkstra::remove_vertex_from_queue( vertex* p_vertex )
00129 {
00130     std::vector<vertex*>::iterator queue_it = queue.begin();
00131 
00132     while( queue_it != queue.end() )
00133     {
00134         if( *queue_it == p_vertex )
00135         {
00136             queue_it = queue.erase( queue_it );
00137 
00138             return true;
00139         }
00140 
00141         queue_it++;
00142     }
00143 
00144     return false;
00145 }
00146 
00154 bool dijkstra::vertex_not_visited( vertex* p_vertex )
00155 {
00156     std::vector<vertex*>::iterator queue_it = queue.begin();
00157 
00158     while( queue_it != queue.end() )
00159     {
00160         if( *queue_it == p_vertex )
00161         {
00162             return true;
00163         }
00164 
00165         queue_it++;
00166     }
00167 
00168     return false;
00169 }
00170 
00174 void dijkstra::update_distance( vertex* p_current, edge* p_successor )
00175 {
00176     int alternative_distance = distance_map.find( p_current )->second + p_successor->weight();
00177 
00178     if( alternative_distance < distance_map.find( p_successor->dest() )->second )
00179     {
00180         distance_map.find( p_successor->dest() )->second = alternative_distance;
00181         pred_map.find( p_successor->dest() )->second = p_current;
00182     }
00183 }
00184 
00196 std::list<vertex*> dijkstra::get_shortest_path_to( vertex* p_target_vertex )
00197 {
00198     vertex* _current = 0;
00199     
00200     std::list<vertex*> path;
00201     path.push_front( p_target_vertex );
00202 
00203     _current = p_target_vertex;
00204 
00205     while( pred_map.find( _current )->second != 0 )
00206     {
00207         _current = pred_map.find( _current )->second;
00208 
00209         path.push_front( _current );
00210     }
00211 
00212     return path;
00213 
00214 }
00215 
00223 void dijkstra::get_shortest_path_output( vertex* p_target_vertex, std::ostream& os )
00224 {
00225     // get shortest path to target vertex
00226     std::list<vertex*> path = get_shortest_path_to( p_target_vertex );
00227 
00228     std::list<vertex*>::iterator path_it = path.begin();
00229 
00230     os << "#########################" << std::endl;
00231     os << "This is the path from start vertex " << m_start->name() << " to target vertex " << p_target_vertex->name() << ":" << std::endl;
00232 
00233     while( path_it != path.end() )
00234     {
00235         os << "Now visiting vertex " << (*path_it)->name() << std::endl;
00236         path_it++;
00237     }
00238 
00239     os << "Done!" << std::endl;
00240     os << "Length of shortest path: " << distance_map.find( p_target_vertex )->second << std::endl;
00241     os << "#########################" << std::endl;
00242 }
