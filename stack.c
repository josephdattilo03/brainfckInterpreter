#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int start;
  int end;
  struct Node *next;
} LinkedNode;

typedef struct Stack {
  LinkedNode *top;
} LinkedStack;

void stackInit(LinkedStack *stack) { stack->top = NULL; }

void stackAdd(LinkedStack *stack, int start, int end) {
  LinkedNode *newNode = (LinkedNode *)malloc(sizeof(LinkedNode));
  if (!newNode) {
    printf("failed to allocate space for a node");
  }
  newNode->start = start;
  newNode->end = end;
  newNode->next = stack->top;
  stack->top = newNode;
}

void stackPop(LinkedStack *stack, int *newStart, int *newEnd) {
  LinkedNode *temp = stack->top;
  stack->top = stack->top->next;
  newStart = &temp->start;
  newEnd = &temp->end;
  free(temp);
}

void freeStack(struct Stack *stack) {
  LinkedNode *currNode = stack->top;
  while (currNode != NULL) {
    LinkedNode *nextNode = currNode->next;
    free(currNode);
    currNode = nextNode;
  }
}
