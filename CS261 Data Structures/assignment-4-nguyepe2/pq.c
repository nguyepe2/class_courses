/*
 * In this file, you will write the structures and functions needed to
 * implement a priority queue.  Feel free to implement any helper functions
 * you need in this file to implement a priority queue.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name: Peter Nguyen
 * Email: nguyepe2@oregonstate.edu
 */
#include "dynarray.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "pq.h"

/*
 * This is the structure that represents a priority queue.  You must define
 * this struct to contain the data needed to implement a priority queue.
 */
struct pq {
   struct dynarray* array;
   struct dynarray* prio;
};


/*
 * This function should allocate and initialize an empty priority queue and
 * return a pointer to it.
 */
struct pq* pq_create() {
   struct pq* initial=malloc(sizeof(struct pq));
   initial->array=dynarray_create();
   initial->prio=dynarray_create();
   return initial; 
}


/*
 * This function should free the memory allocated to a given priority queue.
 * Note that this function SHOULD NOT free the individual elements stored in
 * the priority queue.  That is the responsibility of the caller.
 *
 * Params:
 *   pq - the priority queue to be destroyed.  May not be NULL.
 */
void pq_free(struct pq* pq) {
   assert(pq);
   dynarray_free(pq->array);
   dynarray_free(pq->prio);
   free(pq);

}


/*
 * This function should return 1 if the specified priority queue is empty and
 * 0 otherwise.
 *
 * Params:
 *   pq - the priority queue whose emptiness is to be checked.  May not be
 *     NULL.
 *
 * Return:
 *   Should return 1 if pq is empty and 0 otherwise.
 */
int pq_isempty(struct pq* pq) {
   if(dynarray_size(pq->array)==0 && dynarray_size(pq->prio)==0)
      return 1;
   else 
      return 0; 
}


/*
 * This function should insert a given element into a priority queue with a
 * specified priority value.  Note that in this implementation, LOWER priority
 * values are assigned to elements with HIGHER priority.  In other words, the
 * element in the priority queue with the LOWEST priority value should be the
 * FIRST one returned.
 *
 * Params:
 *   pq - the priority queue into which to insert an element.  May not be
 *     NULL.
 *   value - the value to be inserted into pq.
 *   priority - the priority value to be assigned to the newly-inserted
 *     element.  Note that in this implementation, LOWER priority values
 *     should correspond to elements with HIGHER priority.  In other words,
 *     the element in the priority queue with the LOWEST priority value should
 *     be the FIRST one returned.
 */
void pq_insert(struct pq* pq, void* value, int priority) {
   int move_up(struct pq* pq, int end) {
      int parent=(end-1);
      if(dynarray_get(pq->prio,end) < dynarray_get(pq->prio,parent)) {
	 int* new_val=dynarray_get(pq->array,end); //stores value of child
	 int* new_prio=dynarray_get(pq->prio,end); //stores priority of child
	 int* old_val=dynarray_get(pq->array,parent); //stores value of parent
	 int* old_prio=dynarray_get(pq->prio,parent); //stores priority of parent

	 //moves value and priority of parent down
	 dynarray_set(pq->array,end,old_val);
	 dynarray_set(pq->prio,end,old_prio);

	 //moves value and priority of child up
	 dynarray_set(pq->array,parent,new_val);
	 dynarray_set(pq->prio,parent,new_prio);
	 move_up(pq,parent);
      }
   }

   int end=dynarray_size(pq->array);
   dynarray_insert(pq->array,end,value);
   dynarray_insert(pq->prio,end,priority);
   move_up(pq,end); 

}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_first(struct pq* pq) {
   return dynarray_get(pq->array,0);
}


/*
 * This function should return the priority value of the first item in a
 * priority queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a priority value.  May not be
 *     NULL or empty.
 *
 * Return:
 *   Should return the priority value of the first item in pq, i.e. the item
 *   with LOWEST priority value.
 */
int pq_first_priority(struct pq* pq) {
   return dynarray_get(pq->prio,0);
}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value, and then remove that item
 * from the queue.
 *
 * Params:
 *   pq - the priority queue from which to remove a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_remove_first(struct pq* pq) {
   int* hold=dynarray_get(pq->array,0);
   int curr=0;

   int move_down(struct pq* pq, int curr) {
      int leftchild=curr*2+1;
      while(leftchild < dynarray_size(pq->array)) {
	 int rightchild=curr*2+2;
	 if(rightchild < dynarray_size(pq->array)) {
	    if(dynarray_get(pq->prio,curr) > dynarray_get(pq->prio,rightchild)) { //if current index prioity is greater than right child's priority
	       int* child_val=dynarray_get(pq->array,rightchild); //stores value of right child
	       int* child_prio=dynarray_get(pq->prio,rightchild); //stores priority of right child
	       int* curr_val=dynarray_get(pq->array,curr); //stores value of curr
	       int* curr_prio=dynarray_get(pq->prio,curr); //stores priority of curr

	       dynarray_set(pq->array,rightchild,curr_val);
	       dynarray_set(pq->prio,rightchild,curr_prio);
	       dynarray_set(pq->array,curr,child_val);
	       dynarray_set(pq->prio,curr,child_prio);
	       move_down(pq,curr);
	    }
	 }
	 else
	    if(dynarray_get(pq->prio,curr) > dynarray_get(pq->prio,leftchild)) { //if current index prioity is greater than left child's priority
	       int* child_val=dynarray_get(pq->array,leftchild); //stores value of left child
	       int* child_prio=dynarray_get(pq->prio,leftchild); //stores priority of left child
	       int* curr_val=dynarray_get(pq->array,curr); //stores value of curr
	       int* curr_prio=dynarray_get(pq->prio,curr); //stores priority of curr

	       dynarray_set(pq->array,leftchild,curr_val);
	       dynarray_set(pq->prio,leftchild,curr_prio);
	       dynarray_set(pq->array,curr,child_val);
	       dynarray_set(pq->prio,curr,child_prio);
	       move_down(pq,curr);
	    }
	 break;
      }
      
   }


   int end=dynarray_size(pq->array);
   dynarray_set(pq->array,0,end);
   dynarray_set(pq->prio,0,end); 
   dynarray_remove(pq->array,0);
   dynarray_remove(pq->prio,0);
   move_down(pq,curr); 
   return hold;
}
