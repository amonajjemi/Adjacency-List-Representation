/*************************************************
Aaron Monajjemi
amonajje
Programming Assignment 4
Header file for Graph.h
*************************************************/

#ifndef _Graph_H_INCLUDE_
#define _Graph_H_INCLUDE_

#define INF -1
#define NIL 0
#include "List.h"


// Exported type --------------------------------------------------------------
typedef struct GraphObj* Graph;

// Constructors-Destructors ---------------------------------------------------

//newGraph()
//Creates a new Graph with n vertices and no edges
Graph newGraph(int n);

//freeGraph()
//Frees all dynamic memory in Graph *pG
void freeGraph(Graph* pG);


// Access functions -----------------------------------------------------------

//getOrder()
//returns the number of vertices in the graph
int getOrder(Graph G);

//getSize()
//returns the number of edges in the graph
int getSize(Graph G);

//getSource()
//returns the last used source vertex for BFS or NIL if BFS not yet called
int getSource(Graph G);

//getParent()
//returns the parent of vertex u or NIL if BFS not yet called
//pre: 1 <= u, v <= getOrder(G)
int getParent(Graph G, int u);

//getDist()
//returns the distance from the most recent BFS source to u
//pre: 1 <= u, v <= getOrder(G)
int getDist(Graph G, int u);

//getPath()
//Appends the shortest path in G from source to u into L or NIL if no path
//exists.
//pre:getSource(G) != NIL (BFS must be called before getPath)
//pre: 1 <= u, v <= getOrder(G)
void getPath(List L, Graph G, int u);


// Manipulation procedures ----------------------------------------------------

//makeNull()
//deletes all edges of G
void makeNull(Graph G);

//addEdge()
//inserts a new edge joining u to v. u and v are added toe ach other's adjacency
//lists.
//pre:adj lists must be in sorted order
//pre: 1 <= u, v <= getOrder(G)
void addEdge(Graph G, int u, int v);

//addArc()
//inserts a new directed edge from u to v. Adds v to u's adj List
//pre: 1 <= u, v <= getOrder(G)
void addArc(Graph G, int u, int v);

//BFS
//Finds the shortest path between the source s and all other vertices
void BFS(Graph G, int s);


// Other Functions ------------------------------------------------------------

//printGraph()
//prints the adj list representation of G to a file
void printGraph(FILE* out, Graph G);




#endif
