#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

static void terminate(const char *);

Item *top(Stack s) {
    if (length(s) == 0) {
        terminate("Error: stack is empty.");
    }
    
    return s->trailer->prev->data;
}

void push(Stack s, Item *item) {
    insertNode(s, item, s->trailer->prev, s->trailer);
}

Item *pop(Stack s) {
    if (length(s) == 0) {
        terminate("Error: stack is empty.");
    }

    return deleteNode(s, s->trailer->prev);
}

static void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}