00001 // ============================================================
00002 #include "vertex.h"
00003 // ============================================================
00004 
00005 
00012 vertex::vertex( std::string name, int weight /*= 0*/ )
00013 {
00014     set_name( name );
00015     set_weight( weight );
00016 }
00017 
00023 vertex::~vertex()
00024 {
00025     std::vector<edge*>::iterator it = m_neighbors.begin();
00026 
00027     while( it != m_neighbors.end() )
00028     {
00029         delete *it; // implicitly calls destructor of edge
00030         it++;
00031     }
00032 
00033     m_neighbors.clear();
00034 }
00035 
00039 std::string vertex::name()
00040 {
00041     return m_name;
00042 }
00043 
00047 void vertex::set_name( std::string name )
00048 {
00049     if( !name.empty() )
00050     {
00051         m_name = name;
00052     }
00053 }
00054 
00058 int vertex::weight()
00059 {
00060     return m_weight;
00061 }
00062 
00066 void vertex::set_weight( int weight )
00067 {
00068     m_weight = weight;
00069 }
00070 
00076 std::vector<edge*>& vertex::neighbors()
00077 {
00078     return m_neighbors;
00079 }
00080 
00086 bool vertex::has_successor( vertex* p_vertex )
00087 {
00088     std::vector<edge*>::iterator it = m_neighbors.begin();
00089 
00090     while( it != m_neighbors.end() )
00091     {
00092         if( (*it)->dest() == p_vertex )
00093         {
00094             return true;
00095         }
00096 
00097         it++;
00098     }
00099 
00100     return false;
00101 }
00102 
00108 bool vertex::has_exact_edge( edge* p_edge )
00109 {
00110 
00111     std::vector<edge*>::iterator it = m_neighbors.begin();
00112 
00113     while( it != m_neighbors.end() )
00114     {
00115         if( *it == p_edge )
00116         {
00117             return true;
00118         }
00119 
00120         it++;
00121     }
00122 
00123     return false;
00124 }
00125 
00131 bool vertex::has_according_edge( edge* p_edge )
00132 {
00133 
00134     std::vector<edge*>::iterator it = m_neighbors.begin();
00135 
00136     while( it != m_neighbors.end() )
00137     {
00138         if( (*it)->dest() == p_edge->dest() )
00139         {
00140             return true;
00141         }
00142 
00143         it++;
00144     }
00145 
00146     return false;
00147 }
00148 
00154 void vertex::add_edge( edge* p_edge )
00155 {
00156     m_neighbors.push_back( p_edge );
00157 }
00158 
00166 std::vector<edge*>::iterator vertex::remove_edge( edge* p_edge )
00167 {
00168     std::vector<edge*>::iterator it = m_neighbors.begin();
00169 
00170     while( *it != p_edge )
00171     {
00172         if( it == m_neighbors.end() )
00173         {
00174             return it;
00175         }
00176 
00177         it++;
00178     }
00179 
00180     // delete edge itself
00181     delete *it;
00182 
00183     // remove edge from vector and save iterator position
00184     std::vector<edge*>::iterator result_it = m_neighbors.erase( it );
00185 
00186     return result_it;
00187 
00188     //return true;
00189 }
