/*************************************************
Aaron Monajjemi
amonajje
Programming Assignment 4
FindPath.c for testing the Graph data structure
*************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Graph.h"
#include"List.h"

int main(int argc, char* argv[]){
   FILE *in, *out;
   Graph G = NULL;
   int size = 0;
   List L = newList();



// check command line for correct number of arguments
   if( argc != 3 ){
      printf("Usage: %s <input file> <output file>\n", argv[0]);
      exit(1);
   }
   in = fopen(argv[1], "r");
   out = fopen(argv[2], "w");
   if( in==NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
   }
   if( out==NULL ){
      printf("Unable to open file %s for writing\n", argv[2]);
      exit(1);
   }

   fscanf(in, "%d", &size);
   G= newGraph(size);
   int v1 = 0;
   int v2 = 0;
   while(!feof (in) ){
      fscanf(in, "%d", &v1);
      fscanf(in, "%d", &v2);
      if( v1 == 0 || v2 == 0){
         break;
      }
      addEdge(G, v1, v2);
   }
   printGraph(out, G);
   //fprintf(out, "\n");

   while(!feof (in) ){
      fscanf(in, "%d", &v1);
      fscanf(in, "%d", &v2);
      if( v1 == 0 || v2 == 0){
         break;
      }
      fprintf(out, "\n");
      clear(L);
      BFS(G, v1);
      if(getDist(G, v2) == -1){
         fprintf(out, "%s%d%s%d%s\n", "The distance from ", v1, " to ", v2, " is infinity");
      }
      else{
         fprintf(out, "%s%d%s%d%s%d\n", "The distance from ", v1, " to ", v2, " is ", getDist(G, v2));
      }
      getPath(L, G, v2);
      if(front(L) == NIL){
         fprintf(out, "%s%d%s%d%s", "No ", v1, "-", v2, " path exists");
      }
      else{
         fprintf(out, "%s%d%s%d%s", "A shortest ", v1, "-", v2, " path is: ");
         printList(out, L);
      }
      fprintf(out, "\n");
   }

   //printGraph(stdout, G);



   freeList(&L);
   freeGraph(&G);
   fclose(in);
   fclose(out);

   return(0);
}
