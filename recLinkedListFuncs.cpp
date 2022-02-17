#include "linkedList.h"
#include "linkedListFuncs.h"


//head: ptr to a Node * which is the head of a linked list
//return sum of all values in linked list using a recursive approach
//if head is null return 0
int recursiveSum(Node* head) {
  if (head != NULL) {
    return head->data + recursiveSum(head->next); 
  }
  return 0;
}

//head: ptr to a Node* which is the head of a linked list
//return the largest value in the linked list using a recursive approach
//you may assume the list has at least one element
int recursiveLargestValue(Node* head) {
  int currentMax = head->data;
  int nextValue;
  if (head->next == NULL) {
    return currentMax;
  } else {
    nextValue = recursiveLargestValue(head->next);
  }

  if (currentMax > nextValue) {
    return currentMax;
  } else {
    return nextValue;
  }
}
