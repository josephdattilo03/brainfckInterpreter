#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
  int value;
  struct StackNode *next;
} LinkedNode;

typedef struct Stack {
  LinkedNode *top;
} LinkedStack;

void stackInit(LinkedStack *stack) { stack->top = NULL; }

void stackAdd(LinkedStack *stack, int value) {
  LinkedNode *newNode = (LinkedNode *)malloc(sizeof(LinkedNode));
  if (!newNode) {
    printf("failed to allocate space for a node");
    exit(EXIT_FAILURE);
  }
  newNode->value = value;
  newNode->next = stack->top;
  stack->top = newNode;
}

int stackPop(LinkedStack *stack) {
  if (stack->top == NULL) {
    printf("The stack is already empty");
    exit(EXIT_FAILURE);
  }
  LinkedNode *temp = stack->top;
  int val = temp->value;
  stack->top = stack->top->next;
  free(temp);
  return val;
}

void freeStack(struct Stack *stack) {
  LinkedNode *currNode = stack->top;
  while (currNode != NULL) {
    LinkedNode *nextNode = currNode->next;
    free(currNode);
    currNode = nextNode;
  }
  stack->top = NULL;
}
