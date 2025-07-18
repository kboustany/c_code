#ifndef STACK_H
#define STACK_H

#include "../linkedList/linkedList.h"

typedef LinkedList Stack;

// Functions inherited from LinkedList.
/******************************************************************************
 * Stack create(void);                                                        *
 * void destroy(Stack);                                                       *
 * void clear(Stack);                                                         *
 * int length(Stack);                                                         *
 ******************************************************************************/

Item *top(Stack);
void push(Stack, Item *);
Item *pop(Stack);

#endif