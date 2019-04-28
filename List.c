/*************************************************
Aaron Monajjemi
amonajje
Programming Assignment 4
Implementation file for List ADT
*************************************************/
#include<stdio.h>
#include<stdlib.h>
#include "List.h"

// structs --------------------------------------------------------------------

// private NodeObj type
typedef struct NodeObj{
   int data;
   struct NodeObj* next;
   struct NodeObj* prev;
} NodeObj;

// private Node type
typedef NodeObj* Node;

// private ListObj type
typedef struct ListObj{
   Node front;
   Node back;
   Node cursor;
   int length;
   int index;
} ListObj;


// Constructors-Destructors ---------------------------------------------------

// newNode()
// Returns reference to new Node object. Initializes next and data fields.
// Private.
Node newNode(int data){
   Node N = malloc(sizeof(NodeObj));
   N->data = data;
   N->next = NULL;
   N->prev = NULL;
   return(N);
}

// freeNode()
// Frees heap memory pointed to by *pN, sets *pN to NULL.
// Private.
void freeNode(Node* pN){
   if( pN != NULL && *pN != NULL ){
      free(*pN);
      *pN = NULL;
   }
}

// newList()
// Returns reference to new empty List object.
List newList(void){
   List L;
   L = malloc(sizeof(ListObj));
   L->front = L->back = L->cursor = NULL;
   L->length = 0;
   L->index = 0;
   return (L);
}


// freeList()
// Frees all heap memory associated with List *pL, and sets *pL to NULL.S
void freeList(List* pL){
	clear(*pL);
   /*if(pL!=NULL && *pL!=NULL) { 
      while( !isEmpty(*pL) ) { 
         deleteBack(*pL); 
      }
      free(*pL);
      *pL = NULL;
   }*/
        free(*pL);
}


// Access functions -----------------------------------------------------------

// front()
// Returns the value at the front of L.
// Pre: !isEmpty(L)
int front(List L){
   if( L==NULL ){
      fprintf(stderr, "List Error: calling front() on NULL List reference\n");
      exit(1);
   }
   if( isEmpty(L) ){
      fprintf(stderr, "List Error: calling front() on an empty List\n");
      exit(1);
   }
   return(L->front->data);
}

// back()
// Returns the value at the back of L.
// Pre: !isEmpty(L)
int back(List L){
   if( L==NULL ){
      fprintf(stderr, "List Error: calling back() on NULL List reference\n");
      exit(1);
   }
   if( isEmpty(L) ){
      fprintf(stderr, "List Error: calling back() on an empty List\n");
      exit(1);
   }
   return(L->back->data);
}

// get()
// Returns the value that the cursor is currently on.
// Pre: !isEmpty(L), index() >= 0
int get(List L){
	if( L==NULL ){
      fprintf(stderr, "List Error: calling get() on NULL List reference\n");
      exit(1);
   }
   if( isEmpty(L) ){
      fprintf(stderr, "List Error: calling get() on an empty List\n");
      exit(1);
   }
   if(index(L) < -1){
	  fprintf(stderr, "List Error: calling get() on an undefined cursor\n");
      exit(1);
   }
   return (L->cursor->data);
}

// length()
// Returns the length of L.
int length(List L){
   if( L==NULL ){
      fprintf(stderr, "List Error: calling length() on NULL List reference\n");
      exit(1);
   }
   return(L->length);
}

// index()
// Returns the index of the cursor element in L.
int index(List L){
   if( L==NULL ){
      fprintf(stderr, "List Error: calling index() on NULL List reference\n");
      exit(1);
   }
   if( L->cursor == NULL ){
	  return (-1);
   }
   return (L->index);
}

// isEmpty()
// Returns true (1) if L is empty, otherwise returns false (0)
int isEmpty(List L){
   if( L==NULL ){
      fprintf(stderr, "List Error: calling isEmpty() on NULL List reference\n");
      exit(1);
   }
   return(L->length==0);
}


// Manipulation procedures ----------------------------------------------------

// clear()
// resets this list to its original empty state.
// Pre: !isEmpty(L)
void clear(List pL){
	if(pL!=NULL) { 
            while( !isEmpty(pL) ) { 
            deleteBack(pL); 
        }
        pL = NULL;
        }
}

// moveFront()
// If List is non-empty, places the cursor under the front element,
// otherwise does nothing.
// Pre: !isEmpty(L)
void moveFront(List L){
	if( L==NULL ){
      fprintf(stderr, "List Error: calling moveFront() on NULL List reference\n");
      exit(1);
	}
	if( isEmpty(L) ){
      fprintf(stderr, "List Error: calling moveFront() on empty List reference\n");
      exit(1);
    }
	(L->cursor) = (L->front);
	L->index = 0;
}

// moveBack()
// If List is non-empty, places the cursor under the back element,
// otherwise does nothing.
// Pre: !isEmpty(L)
void moveBack(List L){
	if( L==NULL ){
      fprintf(stderr, "List Error: calling moveback() on NULL List reference\n");
      exit(1);
	}
	if( isEmpty(L) ){
      fprintf(stderr, "List Error: calling moveBack() on NULL List reference\n");
      exit(1);
    }
	(L->cursor) = (L->back);
	L->index = L->length - 1;
}

// movePrev()
// If the cursor is defined and not at front, moves cursor one step toward
// front of this List, if cursor is defined and at front, cursor becomes
// undefined, if cursor is undefined, does nothing.
void movePrev(List L){
	if( L==NULL ){
      fprintf(stderr, "List Error: calling movePrev() on NULL List reference\n");
      exit(1);
	}
	if( isEmpty(L) ){
      fprintf(stderr, "List Error: calling movePrev() on empty List\n");
      exit(1);
	}
	if( index(L) == -1 ){
	  fprintf(stderr, "List Error: calling movePrev() on undefined cursor\n");
      exit(1);
	}
	if( L->cursor == L->front)
	{
		L->cursor = NULL;
		L->index = -1;
	}
	else{
		L->cursor = L->cursor->prev;
		L->index--;
	}
}

// moveNext()
// If the cursor is defined and not at back, moves cursor one step toward
// back of this List, if cursor is defined and at back, cursor becomes
// undefined, if cursor is undefined, does nothing.
void moveNext(List L){
	if( L==NULL ){
      fprintf(stderr, "List Error: calling moveNext() on NULL List reference\n");
      exit(1);
	}
	if( isEmpty(L) ){
      fprintf(stderr, "List Error: calling moveNext() on empty List\n");
      exit(1);
	}
	if( index(L) == -1 ){
	  fprintf(stderr, "List Error: calling moveNext() on undefined cursor\n");
      exit(1);
	}
	if( L->cursor == L->back)
	{
		L->cursor = NULL;
		L->index = -1;
	}
	else{
		L->cursor = L->cursor->next;
		L->index++;
	}
}

// prepend()
// Places new data element at the front of L
void prepend(List L, int data){
	Node N = newNode(data);
   if( L==NULL ){
      fprintf(stderr, "List Error: calling prepend() on NULL List reference\n");
      exit(1);
   }
   if( isEmpty(L) ) { 
      L->front = L->back = N; 
   }else{ 
      L->front->prev = N;
      N->next = L->front; 
      L->front = N;
   }
   if( index(L) != -1){
	   L->index++;
   }
   L->length++;
}

// append()
// Places new data element at the end of L
void append(List L, int data)
{
   Node N = newNode(data);

   if( L==NULL ){
      fprintf(stderr, "List Error: calling append() on NULL List reference\n");
      exit(1);
   }
   if( isEmpty(L) ) { 
      L->front = L->back = N; 
   }else{ 
      L->back->next = N;
      N->prev = L->back;
      L->back = N; 
   }
   L->length++;
}

// insertBefore()
// Insert new element before cursor.
// pre: length() > 0, index >= 0
void insertBefore(List L, int data){
   if( L==NULL ){
      fprintf(stderr, "List Error: calling insertBefore() on NULL List reference\n");
      exit(1);
   }
   if( isEmpty(L)){
	  fprintf(stderr, "List Error: calling insertBefore() on empty List\n");
      exit(1);
   }
   if( index(L) == -1 ){
      fprintf(stderr, "List Error: calling insertBefore() on undefined cursor\n");
      exit(1);
   }
   if( index(L) == 0 ){
	   prepend(L, data);
   }
   else{
	   Node N = newNode(data);
	   L->cursor->prev->next = N;
	   N->next = L->cursor;
	   N->prev = L->cursor->prev;
	   L->cursor->prev = N;
	   L->index++;
	   L->length++;
   }
   
}

// insertAfter()
// Insert new element after cursor.
// pre: length() > 0, index >= 0
void insertAfter(List L, int data){
if( L == NULL ){
      fprintf(stderr, "List Error: calling insertAfter() on NULL List reference\n");
      exit(1);
   }
   if( isEmpty(L)){
	  fprintf(stderr, "List Error: calling insertAfter() on empty List\n");
      exit(1);
   }
	if( index(L) == -1 ){
      fprintf(stderr, "List Error: calling insertAfter() on undefined cursor\n");
      exit(1);
   }
   if( index(L) == (length(L) - 1)) {
	   append(L, data);
   }
   else{
	   Node N = newNode(data);
	   L->cursor->next->prev = N;
	   N->prev = L->cursor;
	   N->next = L->cursor->next;
	   L->cursor->next = N;
	   L->length++;
   }
}

// deleteFront()
// Deletes element at front of L
// Pre: !isEmpty(L)
void deleteFront(List L){
   Node N = NULL;

   if( L==NULL ){
      fprintf(stderr, "List Error: calling deleteFront() on NULL List reference\n");
      exit(1);
   }
   if( isEmpty(L) ){
      fprintf(stderr, "List Error: calling deleteFront() on an empty List\n");
      exit(1);
   }
   N = L->front;
   if( length(L)>1 ) { 
      L->front = L->front->next; 
   }else{ 
      L->front = L->back = L->cursor = NULL; 
   }
   if( L->cursor == N){
	   L->cursor = NULL;
	   L->index = -1;
   }
   L->length--;
   if(index(L) != -1){
	   L->index--;  
   }
   freeNode(&N);
}

// deleteBack()
// Deletes element at back of L
// Pre: !isEmpty(L)
void deleteBack(List L){
   Node N = NULL;

   if( L==NULL ){
      fprintf(stderr, "List Error: calling deleteBack() on NULL List reference\n");
      exit(1);
   }
   if( isEmpty(L) ){
      fprintf(stderr, "List Error: calling deleteBack() on an empty List\n");
      exit(1);
   }
   N = L->back;
   if( length(L) > 1 ) {
      L->back = L->back->prev; 
   }else{ 
      L->back = L->front = L->cursor = NULL; 
   }
   if( L->cursor == N){
	   L->cursor = NULL;
           L->index = -1;
   }
   L->length--;
   freeNode(&N);
}

// delete()
// Deletes cursor element, making cursor undefined.
// Pre: length() > 0, index >= 0
void delete(List L){
   if( L == NULL ){
      fprintf(stderr, "List Error: calling delete() on NULL List reference\n");
      exit(1);
   }
   if( isEmpty(L) ){
      fprintf(stderr, "List Error: calling delete() on an empty List\n");
      exit(1);
   }
   if( index(L) == -1 ){
	  fprintf(stderr, "List Error: calling delete() on an undefined cursor\n");
      exit(1);
   }
   	Node N = NULL;
	
   N = L->cursor;
   if( length(L) == 1 ) {
      L->back = L->front = L->cursor = NULL;
	  L->index = -1;
   }
   else if( index(L) == (length(L) - 1) ){
	   deleteBack(L);
   }
   else{
      L->cursor->prev->next = L->cursor->next;
      L->cursor->next->prev = L->cursor->prev;
	  L->cursor = NULL;
	  L->index = -1;
   }
   L->length--;
   freeNode(&N);
}


// Other Functions ------------------------------------------------------------

// printList()
// Prints data elements in L on a single line to stdout.
void printList(FILE* out, List L){
   Node N = NULL;

   if( L==NULL ){
      fprintf(stderr,"List Error: calling printList() on NULL List reference\n");
      exit(1);
   }

   for(N = L->front; N != NULL; N = N->next){
      fprintf(out, "%d", N->data);
      if(N->next != NULL){
         fprintf(out, " ");
      }
   }
}

// copyList()
// Returns a new List identical to List passed in
List copyList(List L){
   List cL = newList();
   Node N = L->front;
   
   while(N != NULL){
   append(cL, N->data);
   N = N->next;
   }

   return cL;
}

// equals()
// returns true (1) if A is identical to B, false (0) otherwise
int equals(List A, List B){
   int eq = 0;
   Node N = NULL;
   Node M = NULL;

   if( A==NULL || B==NULL ){
      fprintf(stderr, "List Error: calling equals() on NULL List reference\n");
      exit(1);
   }

   eq = ( A->length == B->length );
   N = A->front;
   M = B->front;
   while( eq && N!=NULL){
      eq = (N->data==M->data);
      N = N->next;
      M = M->next;
   }
   return eq;
}
