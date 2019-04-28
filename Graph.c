/*************************************************
Aaron Monajjemi
amonajje
Programming Assignment 4
Impltementation File for Graph ADT
*************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"
#include"List.h"
#include<string.h>

// structs --------------------------------------------------------------------
// private GraphObj type
typedef struct GraphObj{
   List *L;
   int *C;
   int *P;
   int *D;
   int order;
   int size;
   int source;
} GraphObj;


// Constructors-Destructors ---------------------------------------------------

//newGraph()
//Creates a new Graph with n vertices and no edges
Graph newGraph(int n){
   Graph G;
   G = malloc(sizeof(GraphObj));
   G->L = calloc(n+1, sizeof(List));
   G->C = calloc(n+1, sizeof(int));
   G->P = calloc(n+1, sizeof(int));
   G->D = calloc(n+1, sizeof(int));
   //G->L = malloc(sizeof(List) * (n+1));
   //memset(G->L, newList(), sizeof(List)*(n+1));
   memset(G->P, NIL, sizeof(int)*(n+1));
   memset(G->D, INF, sizeof(int)*(n+1));
   for(int i = 1; i <= n; ++i){
	   (G->L)[i] = newList();
   }

   G->order = n;
   G->size = 0;
   G->source = NIL;
   return (G);
}

//freeGraph()
//Frees all dynamic memory in Graph *pG
void freeGraph(Graph* pG){
   if(pG != NULL && *pG != NULL){
      for(int i = 1; i <= getOrder(*pG); ++i){
         freeList(&((*pG)->L)[i]);
      }
      free((*pG)->L);
      free((*pG)->C);
      free((*pG)->P);
      free((*pG)->D);
      free(*pG);
      *pG = NULL;
   }
}


// Access functions -----------------------------------------------------------

//getOrder()
//returns the number of vertices in the graph
int getOrder(Graph G){
   if( G==NULL ){
      fprintf(stderr, "Graph Error: calling getOrder() on NULL Graph reference\n");
      exit(1);
   }
   return (G->order);
}

//getSize()
//returns the number of edges in the graph
int getSize(Graph G){
   if( G==NULL ){
      fprintf(stderr, "Graph Error: calling getSize() on NULL Graph reference\n");
      exit(1);
   }
   return (G->size);
}

//getSource()
//returns the last used source vertex for BFS or NIL if BFS not yet called
int getSource(Graph G){
   if( G==NULL ){
      fprintf(stderr, "Graph Error: calling getSource() on NULL Graph reference\n");
      exit(1);
   }
   return (G->source);
}

//getParent()
//returns the parent of vertex u or NIL if BFS not yet called
//pre: 1 <= u, v <= getOrder(G)
int getParent(Graph G, int u){
   if( G==NULL ){
      fprintf(stderr, "Graph Error: calling getParent() on NULL Graph reference\n");
      exit(1);
   }
   if( u < 1 || u > getOrder(G)){
      fprintf(stderr, "Graph Error: calling getParent() on non-existent vertex\n");
      exit(1);
   }
   return ((G->P)[u]);
}

//getDist()
//returns the distance from the most recent BFS source to u
//pre: 1 <= u, v <= getOrder(G)
int getDist(Graph G, int u){
   if( G==NULL ){
      fprintf(stderr, "Graph Error: calling getDist() on NULL Graph reference\n");
      exit(1);
   }
   if( u < 1 || u > getOrder(G)){
      fprintf(stderr, "Graph Error: calling getDist() on non-existent vertex\n");
      exit(1);
   }
   return ((G->D)[u]);
}

//getPath()
//Appends the shortest path in G from source to u into L or NIL if no path
//exists.
//pre:getSource(G) != NIL (BFS must be called before getPath)
//pre: 1 <= u, v <= getOrder(G)
void getPath(List L, Graph G, int u){
   if( G==NULL ){
      fprintf(stderr, "Graph Error: calling getDist() on NULL Graph reference\n");
      exit(1);
   }
   if( u < 1 || u > getOrder(G)){
      fprintf(stderr, "Graph Error: calling getPath() on non-existent vertex\n");
      exit(1);
   }

   /*//if there is no shortest path do nothing
   if(getDist(G, u) == INF){
      prepend(L, NIL);
      return;
   }

   prepend(L, u);//append destination vertices
   int temp = getParent(G, u);
   while(temp != NIL){ //append parents of vertices until reaching the source
      prepend(L, getParent(G, u));
      temp = getParent(G, temp);
   }*/

   if(u == G->source){
      append(L, u);
   }
   else if((G->P)[u] == NIL){
      append(L, NIL);
   }
   else{
      getPath(L, G, (G->P)[u]);
      append(L, u);
   }

//done
}


// Manipulation procedures ----------------------------------------------------

//makeNull()
//deletes all edges of G
void makeNull(Graph G){
	if( G==NULL ){
      fprintf(stderr, "Graph Error: calling makeNull() on NULL Graph reference\n");
    exit(1);
   }
   for(int i = 1; i <= getOrder(G); ++i){
	   if(length((G->L)[i]) != 0){
		   clear((G->L)[i]);
	   }
   }
   G->size = 0;
}

//addEdge()
//inserts a new edge joining u to v. u and v are added toe ach other's adjacency
//lists.
//pre:adj lists must be in sorted order
//pre: 1 <= u, v <= getOrder(G)
void addEdge(Graph G, int u, int v){
   if( G==NULL ){
    fprintf(stderr, "Graph Error: calling addEdge() on NULL Graph reference\n");
    exit(1);
   }
   if( u < 1 || u > getOrder(G)){
      fprintf(stderr, "Graph Error: calling addEdge() on non-existent vertex\n");
      exit(1);
   }
   if( v < 1 || v > getOrder(G)){
      fprintf(stderr, "Graph Error: calling addEdge() on non-existent vertex\n");
      exit(1);
   }
   
   if(isEmpty((G->L)[u])){
      append((G->L)[u], v);
   }
   else{
      moveFront((G->L)[u]);
      while(index((G->L)[u]) != -1 && v > get((G->L)[u])){
         moveNext((G->L)[u]);
      }
      if(index((G->L)[u]) == -1){
         append((G->L)[u], v);
      }else{
         insertBefore((G->L)[u], v);
      }
   }
   
   if(isEmpty((G->L)[v])){
      append((G->L)[v], u);
   }
   else{
      moveFront((G->L)[v]);
      while(index((G->L)[v]) != -1 && u > get((G->L)[v])){
         moveNext((G->L)[v]);
      }
      if(index((G->L)[v]) == -1){
      append((G->L)[v], u);
      }else{
         insertBefore((G->L)[v], u);
      }
   }
   ++(G->size);
}

//addArc()
//inserts a new directed edge from u to v. Adds v to u's adj List
//pre: 1 <= u, v <= getOrder(G)
void addArc(Graph G, int u, int v){
   if( G==NULL ){
      fprintf(stderr, "Graph Error: calling addArc() on NULL Graph reference\n");
    exit(1);
   }
   if( u < 1 || u > getOrder(G)){
      fprintf(stderr, "Graph Error: calling addArc() on non-existent vertex\n");
      exit(1);
   }
   if( v < 1 || v > getOrder(G)){
      fprintf(stderr, "Graph Error: calling addArc() on non-existent vertex\n");
      exit(1);
   }
   
   if(isEmpty((G->L)[u])){
      append((G->L)[u], v);
   }
   else{
      moveFront((G->L)[u]);
      while(index((G->L)[u]) != -1 && v > get((G->L)[u])){
         moveNext((G->L)[u]);
      }
      if(index((G->L)[u]) == -1){
         append((G->L)[u], v);
      }else{
         insertBefore((G->L)[u], v);
      }
   }
   ++(G->size);
}

//BFS
//Finds the shortest path between the source s and all other vertices
void BFS(Graph G, int s){
	if( G==NULL ){
      fprintf(stderr, "Graph Error: calling BFS() on NULL Graph reference\n");
    exit(1);
   }
   
   List Q = newList();
   G->source = s;
   // -1 = white, 0 = gray, 1 = black
   for(int i = 1; i <= getOrder(G); ++i){
	   if(i != s){
		   (G->C)[i] = -1;
		   (G->D)[i] = INF;
		   (G->P)[i] = NIL;
	   }
   }
   (G->C)[s] = 0;
   (G->D)[s] = 0;
   (G->P)[s] = NIL;
   append(Q, s);
   while(!isEmpty(Q)){
	   int u = front(Q);
	   deleteFront(Q);
           if(length((G->L)[u]) != 0){
	      moveFront((G->L)[u]);
	      while(index((G->L)[u]) != -1){
		   int v =get((G->L)[u]);
		   if((G->C)[v] == -1){
			   (G->C)[v] = 0;
			   (G->D)[v] = (G->D)[u] + 1;
			   (G->P)[v] = u;
			   append(Q, v);
		   }
                   moveNext((G->L)[u]);
	      }
           }
	   (G->C)[u] = 1;
   }
   freeList(&Q);
}


// Other Functions ------------------------------------------------------------

//printGraph()
//prints the adj list representation of G to a file
void printGraph(FILE* out, Graph G){
   if( G==NULL ){
      fprintf(stderr, "Graph Error: calling printGraph() on NULL Graph reference\n");
    exit(1);
   }
   
   for(int i = 1; i <= getOrder(G); ++i){
      fprintf(out, "%d%s", i, ": ");
      printList(out, (G->L)[i]);
      fprintf(out, "\n");
   }
   
}










