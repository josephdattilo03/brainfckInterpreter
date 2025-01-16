#ifndef STACK_H
#define STACK_H

struct StackNode;
struct Stack;

void stackInit(struct Stack *stack);
void stackAdd(struct Stack *stack, int value);
int stackPop(struct Stack *stack);
void freeStack(struct Stack *stack);
#endif
