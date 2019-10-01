00001 // ============================================================
00002 #include "edge.h"
00003 // ============================================================
00004 
00005 
00012 edge::edge( vertex* dest, int weight/* = 0*/ )
00013 {
00014     set_dest( dest );
00015     set_weight( weight );
00016 }
00017 
00021 edge::~edge()
00022 {
00023 }
00024 
00028 int edge::weight()
00029 {
00030     return m_weight;
00031 }
00032 
00037 void edge::set_weight( int weight )
00038 {
00039     m_weight = weight;
00040 }
00041 
00045 vertex* edge::dest()
00046 {
00047     if( m_dest )
00048     {
00049         return m_dest;
00050     }
00051 
00052     return 0;
00053 }
00054 
00058 void edge::set_dest( vertex* p_dest )
00059 {
00060     m_dest = p_dest;
00061 }
00062 

