// ============================================================
#include "dijkstra.h"
// ============================================================

dijkstra::dijkstra( graph *p_graph, vertex *p_start )
: m_graph( p_graph ),
m_start( p_start )
{
    if( !initialize() )
    {
        std::cout << "Processing not possible. Error: Empty maps." << std::endl;
    }

    execute();
}

bool dijkstra::initialize()
{
    std::vector<vertex*>::iterator g_vertex_it = m_graph->vertices().begin();

    while( g_vertex_it != m_graph->vertices().end() )
    {
        // initialize distance and predecessor maps
        distance_map.insert( std::pair<vertex*,int>( *g_vertex_it, INT_MAX ) );
        pred_map.insert( std::pair<vertex*,vertex*>( *g_vertex_it, NULL ) );

        // insert each vertex into not-visited vertices vector
        queue.push_back( *g_vertex_it );

        g_vertex_it++;
    }



    if( !distance_map.empty() && !pred_map.empty() )
    {
        // set distance of start vertex to 0
        distance_map.find( m_start )->second = 0;

        return true;
    }
    
    return false;
}

void dijkstra::execute()
{
    /*
        Summary after initialization:

            queued = { all vertices }
            distance = distance for every vertex is "infinite"
            pred = predecessor for every vertex is NULL
    */

    vertex* _current = 0;

    while( !queue.empty() )
    {
        _current = get_vertex_with_shortest_distance();
        
        remove_vertex_from_queue( _current );

        // for every not visited successor of _current
        std::vector<edge*>::iterator successor_it = _current->neighbors().begin();

        while( successor_it != _current->neighbors().end() )
        {
            if( vertex_not_visited( (*successor_it)->dest() ) )
            {
                update_distance( _current, *successor_it );
            }

            successor_it++;
        }
    }
}

vertex* dijkstra::get_vertex_with_shortest_distance()
{
    vertex* _min_dist_vertex = 0;
    int min_dist = INT_MAX;

    std::vector<vertex*>::iterator queue_it = queue.begin();
    while( queue_it != queue.end() )
    {
        if( distance_map.find( *queue_it )->second < min_dist )
        {
            min_dist = distance_map.find( *queue_it )->second;
            _min_dist_vertex = *queue_it;
        }

        queue_it++;
    }

    return _min_dist_vertex;

}

bool dijkstra::remove_vertex_from_queue( vertex* p_vertex )
{
    std::vector<vertex*>::iterator queue_it = queue.begin();

    while( queue_it != queue.end() )
    {
        if( *queue_it == p_vertex )
        {
            queue_it = queue.erase( queue_it );

            return true;
        }

        queue_it++;
    }

    return false;
}

bool dijkstra::vertex_not_visited( vertex* p_vertex )
{
    std::vector<vertex*>::iterator queue_it = queue.begin();

    while( queue_it != queue.end() )
    {
        if( *queue_it == p_vertex )
        {
            return true;
        }

        queue_it++;
    }

    return false;
}

void dijkstra::update_distance( vertex* p_current, edge* p_successor )
{
    int alternative_distance = distance_map.find( p_current )->second + p_successor->weight();

    if( alternative_distance < distance_map.find( p_successor->dest() )->second )
    {
        distance_map.find( p_successor->dest() )->second = alternative_distance;
        pred_map.find( p_successor->dest() )->second = p_current;
    }
}

std::list<vertex*> dijkstra::get_shortest_path_to( vertex* p_target_vertex )
{
    vertex* _current = 0;
    
    std::list<vertex*> path;
    path.push_front( p_target_vertex );

    _current = p_target_vertex;

    while( pred_map.find( _current )->second != 0 )
    {
        _current = pred_map.find( _current )->second;

        path.push_front( _current );
    }

    return path;

}

void dijkstra::get_shortest_path_output( vertex* p_target_vertex, std::ostream& os )
{
    // get shortest path to target vertex
    std::list<vertex*> path = get_shortest_path_to( p_target_vertex );

    std::list<vertex*>::iterator path_it = path.begin();

    os << "#########################" << std::endl;
    os << "This is the path from start vertex " << m_start->name() << " to target vertex " << p_target_vertex->name() << ":" << std::endl;

    while( path_it != path.end() )
    {
        os << "Now visiting vertex " << (*path_it)->name() << std::endl;
        path_it++;
    }

    os << "Done!" << std::endl;
    os << "Length of shortest path: " << distance_map.find( p_target_vertex )->second << std::endl;
    os << "#########################" << std::endl;
}