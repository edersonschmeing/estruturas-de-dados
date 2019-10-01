00001 // ============================================================
00002 #ifndef __VERTEX_H__
00003 #define __VERTEX_H__
00004 // ============================================================
00005 
00006 // ============================================================
00007 #include <string>
00008 #include <vector>
00009 // ------------------------------------------------------------
00010 #include "edge.h"
00011 // ============================================================
00012 
00013 #define DLL __declspec(dllexport)
00014 
00015 
00016 class edge;
00025 class vertex
00026 {
00027 public:
00028     DLL vertex( std::string name, int weight = 0 );
00029     virtual ~vertex();
00030 
00031     DLL std::string name();
00032     DLL void set_name( std::string name );
00033 
00034     int weight();
00035     void set_weight( int weight );
00036 
00037     std::vector<edge*>& neighbors();
00038 
00039     void add_edge( edge* p_edge );
00040     std::vector<edge*>::iterator remove_edge( edge* p_edge );
00041 
00042     bool has_successor( vertex* p_vertex );
00043 
00044     bool has_exact_edge( edge* p_edge );
00045     bool has_according_edge( edge* p_edge );
00046 
00047 private:
00048     std::string m_name;
00049     int m_weight;
00050     std::vector<edge*> m_neighbors;
00051 };
00052 
00053 #endif // __VERTEX_H__
