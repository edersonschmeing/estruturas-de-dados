#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__

#include <iostream>
#include <map>
#include <cmath>
#include <list>

#include "graph.h"
#include "vertex.h"
#include "edge.h"

class dijkstra {
public:
    dijkstra( graph* p_graph, vertex* p_start );
    std::list<vertex*> get_shortest_path_to( vertex* p_target_vertex );
    void get_shortest_path_output( vertex* p_target_vertex, std::ostream& os );

private:
    std::map<vertex*,int> distance_map; // first: vertex, second: distance to vertex from start

    std::map<vertex*,vertex*> pred_map; // first: vertex, second: predecessor of vertex

    std::vector<vertex*> queue; // not visited vertices

    graph* m_graph;

    vertex* m_start;

    bool initialize();
    void execute();
    vertex* get_vertex_with_shortest_distance();
    bool remove_vertex_from_queue( vertex* p_vertex );
    bool vertex_not_visited( vertex* p_vertex );
    void update_distance( vertex* p_current, edge* p_successor );

};

#endif
