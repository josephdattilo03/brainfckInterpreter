#ifndef STACK_H
#define STACK_H

struct Node;
struct Stack;

void stackInit(struct Stack *stack);
void stackAdd(struct Stack *stack, int startIdx, int endIdx);
void stackPop(struct Stack *stack, int *newStart, int *newEnd);
void freeStack(struct Stack *stack);
#endif
