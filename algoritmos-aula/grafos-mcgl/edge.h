// ============================================================
#ifndef __EDGE_H__
#define __EDGE_H__
// ============================================================

// ============================================================
#include "vertex.h"
// ------------------------------------------------------------
#include <string>
#include <vector>
// ============================================================

class vertex;

class edge
{
public:
    edge( vertex* dest, int weight = 0 );
    virtual ~edge();

    int weight();
    void set_weight( int weight );

    vertex* dest();
    void set_dest( vertex* p_dest );

private:
    std::string m_name;
    int m_weight;
    vertex* m_dest;
};