#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;


/*void bfs(struct node *graph, int size, int node_search)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (i != node_search)
        {
            graph[i].color = WHITE;
            graph[i].distance = 0;
        }
    }
    graph[node_search].color = GRAY;
    graph[node_search].distance = 0;
    graph[node_search].pi = NULL;
    push_queue(node_search);
    while (in != out)
    {
        int u = pop_queue();
        struct node *v = graph[u].next;
        while (v != NULL)
        {
            if (graph[v->key].color == WHITE)
            {
                graph[v->key].color = GRAY;
                graph[v->key].distance = graph[u].distance + 1;
                graph[v->key].pi = &graph[u];
                push_queue(v->key);
            }
            v = v->next;
        }
        graph[u].color = BLACK;
    }
} */


const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

int main()
{
       
    int nodes, edges, node_search, last;

    printf("Nodes, edges? ");
    scanf("%d %d", &nodes, &edges);
  
    int graph[nodes][nodes], color[nodes], dist[nodes];

      //memset(color, 0, sizeof(color));
      //memset(dist, 0, sizeof(dist));
      //memset(graph, 0, sizeof(graph));

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
    for (int i=0; i < nodes; i++) {
         printf("%d - ", color[i]);
    }

    printf("\n"); 
    printf("Distance: "); 
    for (int i=0; i < nodes; i++) {
         printf("%d - ", dist[i]);
    }
    
    printf("\n"); 
    printf("Matriz \n");
    for (int i=0; i < nodes; i++) {
       for (int j=0; j < nodes; j++)
          printf("%d - ", graph[i][j]);
       printf("\n"); 
    }


    //run BFS
    queue<int> q; //create a queue
    q.push(node_search);  //1. put root node on the queue
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
            {                               //and this adjacent node is still WHITE,
                q.push(i);                 //4. push this node into the queue
                color[i] = GRAY;          //color this adjacent node with GRAY
                dist[i] = dist[u] + 1;
            }
        }
        color[u] = BLACK; //color the current node black to mark it as dequeued
    } while (!q.empty()); //5. if the queue is empty, then all the nodes have been visited
    
    
    printf("\n"); 
    printf("Color: "); 
    for (int i=0; i < nodes; i++) {
         printf("%d - ", color[i]);
    }
    printf("\n");
    printf("Distance: "); 
    for (int i=0; i < nodes; i++) {
         printf("%d - ", dist[i]);
    }

   // printf("%d\n", dist[last]);
    return 0;
}