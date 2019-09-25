#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

int tempo = 0;

typedef struct _node {
    int color; 
    int pi;
    int distance; 
    int f;
} ;
typedef node;


void visit_dfs(node *graph, int size, int u)
{
    int t;
    tempo++;
    graph[u].distance = tempo;
    graph[u].color = GRAY;
    for (int v = 0; v < size; v++)
    {
        if ((v != u) && (isAdjacent(graph, u, v)) && (graph[v].color == WHITE))
        {
            graph[v].pi = (int)&graph[u];
            visit_dfs(graph, size, v);
        }
    }
    graph[u].color = BLACK;
    tempo++;
    graph[u].f = tempo;
}

void dfs(node *graph, int size)
{
    for (int i = 0; i < size; i++)
    {
        graph[i].color = WHITE;
        graph[i].pi = NULL;
        graph[i].distance = 0;
    }
    tempo = 0;
    //in = 0;  out = 0; n_queue = 0;
    for (int i = 0; i < size; i++)
    {
        if (graph[i].color == WHITE)
        {
            visit_dfs(graph, size, i);
        }
    }
}

int main()
{
    int nodes, edges, node_search, last;

    printf("Nodes, edges? ");
    scanf("%d %d", &nodes, &edges);

    node *graph;
    
    graph =  (node*) malloc(5*sizeof(node));

    dfs(graph, nodes );


/*
    for (int i = 0; i < edges; i++)
    {
        printf("Edge %d: ", i);
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
    }
    printf("node_search");
    scanf("%d", &node_search);

    // scanf("%d %d", &node_search, &last);

    printf("\n");
    printf("Color: ");
    for (int i = 0; i < nodes; i++)
    {
        printf("%d - ", color[i]);
    }

    printf("\n");
    printf("Distance: ");
    for (int i = 0; i < nodes; i++)
    {
        printf("%d - ", dist[i]);
    }

    printf("\n");
    printf("Matriz \n");
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
            printf("%d - ", graph[i][j]);
        printf("\n");
    }

    //run BFS
    queue<int> q;        //create a queue
    q.push(node_search); //1. put root node on the queue
    dist[node_search] = 1;
    do
    {
        int u = q.front(); //2. pull a node from the beginning of the queue
        q.pop();
        printf("%d ", u); //print the node
        for (int i = 0; i < nodes; i++)
        {                          //4. get all the adjacent nodes
            if ((graph[u][i] == 1) //if an edge exists between these two nodes,
                && (color[i] == WHITE))
            {                    //and this adjacent node is still WHITE,
                q.push(i);       //4. push this node into the queue
                color[i] = GRAY; //color this adjacent node with GRAY
                dist[i] = dist[u] + 1;
            }
        }
        color[u] = BLACK; //color the current node black to mark it as dequeued
    } while (!q.empty()); //5. if the queue is empty, then all the nodes have been visited

    printf("\n");
    printf("Color: ");
    for (int i = 0; i < nodes; i++)
    {
        printf("%d - ", color[i]);
    }
    printf("\n");
    printf("Distance: ");
    for (int i = 0; i < nodes; i++)
    {
        printf("%d - ", dist[i]);
    }

    // printf("%d\n", dist[last]);
    return 0; */
}