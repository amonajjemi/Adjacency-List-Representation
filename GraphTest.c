/*************************************************
Aaron Monajjemi
amonajje
Programming Assignment 4
GraphTest.c for testing the Graph data structure
*************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"
#include"List.h"

int main(int argc, char* argv[]){
   int n = 6;
   List L = NULL;
   L = newList();
   Graph G = NULL;
   G = newGraph(n);


   printf("%s\n", "Testing getOrder and GetSize");
   printf("%d\n", getOrder(G));
   printf("%d\n", getSize(G));


   addEdge(G, 1, 2);
   addEdge(G, 1, 3);
   printf("%d\n", getOrder(G));
   printf("%d\n", getSize(G));
   printf("%s\n", "Testing getParent and getDist");
   printf("%d\n", getParent(G, 1));
   printf("%d\n", getDist(G, 1));

   /*printf("%s\n", "Testing getPath");
   getPath(L, G, 1);
   printList(stdout, L);
   printf("\n");*/

   printf("%s\n", "Testing makeNull");
   makeNull(G);
   printf("%d\n", getSize(G));

   addArc(G, 1, 4);
   printf("%s\n", "Testing addArc");
   printf("%d\n", getSize(G));



   printf("%s\n", "Testing BFS with addEdge");
   makeNull(G);
   addEdge(G, 1, 2);
   addEdge(G, 1, 3);
   addEdge(G, 2, 4);
   addEdge(G, 2, 5);
   addEdge(G, 2, 6);
   addEdge(G, 3, 4);
   addEdge(G, 4, 5);
   addEdge(G, 5, 6);
   BFS(G, 1);
   printf("%s\n", "getOrder:");
   printf("%d\n", getOrder(G));
   printf("%s\n", "getSize:");
   printf("%d\n", getSize(G));
   printf("%s\n", "getParent:");
   printf("%d\n", getParent(G, 2));
   printf("%s\n", "getDist:");
   printf("%d\n", getDist(G, 4));
   printGraph(stdout, G);
   printf("%s\n", "Testing getPath 1-6");
   getPath(L, G, 6);
   printList(stdout, L);
   printf("\n");


   printf("%s\n", "Testing BFS with addArc");
   Graph F = NULL;
   F = newGraph(n);

   List M = newList();
   addArc(F, 1, 2);
   addArc(F, 1, 3);
   addArc(F, 2, 4);
   addArc(F, 2, 5);
   addArc(F, 2, 6);
   addArc(F, 3, 4);
   addArc(F, 4, 5);
   addArc(F, 5, 6);
   BFS(G, 2);
   printf("%s\n", "getOrder:");
   printf("%d\n", getOrder(G));
   printf("%s\n", "getSize:");
   printf("%d\n", getSize(G));
   printf("%s\n", "getParent:");
   printf("%d\n", getParent(G, 2));
   printf("%s\n", "getDist:");
   printf("%d\n", getDist(G, 4));
   printGraph(stdout, G);
   printf("%s\n", "Testing getPath 2-3");
   getPath(M, G, 3);
   printList(stdout, M);
   printf("\n");


   freeGraph(&G);
   freeGraph(&F);
   freeList(&L);
   freeList(&M);

   return(0);
}
