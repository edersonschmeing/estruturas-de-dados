00001 #pragma region documentation mainpage
00002 
00051 #pragma endregion
00052 
00053 // ============================================================
00054 #ifndef __GRAPH_H__
00055 #define __GRAPH_H__
00056 // ============================================================
00057 
00058 // ============================================================
00059 #include <iostream>
00060 // ------------------------------------------------------------
00061 #include "vertex.h"
00062 #include "edge.h"
00063 // ============================================================
00064 
00065 #define DLL __declspec(dllexport)
00066 
00077 class graph
00078 {
00079 public:
00080     graph();
00081     ~graph();
00082 
00083     DLL bool add_vertex( std::string name, int weight = 0 );
00084     DLL bool add_vertex( vertex* p_vertex );
00085 
00086     DLL virtual bool add_edge( vertex* p_src, vertex* p_dest, int weight = 0 )  = 0;    // pure virtual function
00087     DLL virtual bool add_edge( vertex* p_src, edge* p_edge ) = 0;                       // pure virtual function
00088 
00089     DLL bool remove_vertex( std::string name );
00090     DLL bool remove_vertex( vertex* p_vertex );
00091 
00092     DLL virtual bool remove_edge( vertex* p_vertex_0, vertex* p_vertex_1 ) = 0;         // pure virtual function
00093     DLL virtual bool remove_edge( edge* p_edge ) = 0;                                   // pure virtual function
00094 
00095     DLL void vertices_output( std::ostream& ostream );
00096 
00097     DLL std::vector<vertex*>& vertices();
00098 
00099 protected:
00100     size_t vertices_count();
00101     size_t edges_count();
00102 
00103     std::string name();
00104     void set_name( std::string name );
00105 
00106     bool parallels_allowed();
00107     void set_parallels_allowed( bool allowed );
00108 
00109     bool has_loop();
00110 
00111     bool are_adjacent( vertex* p_vertex_0, vertex* p_vertex_1 );
00112 
00113     vertex* get_vertex_by_name( std::string name );
00114 
00115     vertex* find_source( edge* p_edge );
00116 
00117     bool remove_edges_pointing_to( vertex* p_vertex );
00118 
00119 private:
00120     std::string m_name;
00121     bool m_parallels_allowed;
00122     std::vector<vertex*>    m_vertices;
00123 };
00124 
00125 #endif // __GRAPH_H__

