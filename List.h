/*************************************************
Aaron Monajjemi
amonajje
Programming Assignment 4
List.h
Header file for List.c
*************************************************/

#ifndef _List_H_INCLUDE_
#define _List_H_INCLUDE_


// Exported type --------------------------------------------------------------
typedef struct ListObj* List;


// Constructors-Destructors ---------------------------------------------------

// newList()
// Returns reference to new empty List object. 
List newList(void);

// freeList()
// Frees all heap memory associated with List *pQ, and sets *pQ to NULL.
void freeList(List* pL);


// Access functions -----------------------------------------------------------

// front()
// Returns the value at the front of L.
// Pre: !isEmpty(L)
int front(List L);

// back()
// Returns the value at the back of L.
// Pre: !isEmpty(L)
int back(List L);

// get()
// Returns the value that the cursor is currently on.
// Pre: !isEmpty(L), index() >= 0
int get(List L);

// length()
// Returns the length of L.
int length(List L);

// index()
// Returns the index of the cursor element in L.
int index(List L);

// isEmpty()
// Returns true (1) if L is empty, otherwise returns false (0)
int isEmpty(List L);


// Manipulation procedures ----------------------------------------------------

// clear()
// resets this list to its original empty state.
// Pre: !isEmpty(L)
void clear(List L);

// moveFront()
// If List is non-empty, places the cursor under the front element,
// otherwise does nothing.
// Pre: !isEmpty(L)
void moveFront(List L);

// moveBack()
// If List is non-empty, places the cursor under the back element,
// otherwise does nothing.
// Pre: !isEmpty(L)
void moveBack(List L);

// movePrev()
// If the cursor is defined and not at front, moves cursor one step toward
// front of this List, if cursor is defined and at front, cursor becomes
// undefined, if cursor is undefined, does nothing.
void movePrev(List L);

// moveNext()
// If the cursor is defined and not at back, moves cursor one step toward
// back of this List, if cursor is defined and at back, cursor becomes
// undefined, if cursor is undefined, does nothing.
void moveNext(List L);

// prepend()
// Places new data element at the front of L
void prepend(List L, int data);

// append()
// Places new data element at the end of L
void append(List L, int data);

// insertBefore()
// Insert new element before cursor.
// pre: length() > 0, index >= 0
void insertBefore(List L, int data);

// insertAfter()
// Insert new element after cursor.
// pre: length() > 0, index >= 0
void insertAfter(List L, int data);

// deleteFront()
// Deletes element at front of L
// Pre: !isEmpty(L)
void deleteFront(List L);

// deleteBack()
// Deletes element at back of L
// Pre: !isEmpty(L)
void deleteBack(List L);

// delete()
// Deletes cursor element, making cursor undefined.
// Pre: length() > 0, index >= 0
void delete(List L);


// Other Functions ------------------------------------------------------------

// printList()
// Prints data elements in L on a single line to stdout.
void printList(FILE* out, List L);

// copyList()
// Returns a new List identical to List passed in
List copyList(List L);

// equals()
// returns true (1) if A is identical to B, false (0) otherwise
int equals(List A, List B);

#endif
