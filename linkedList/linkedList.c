#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

static void terminate(const char *);

LinkedList create(void) {
    LinkedList l = malloc(sizeof(struct LinkedList_type));
    if (l == NULL) {
        terminate("Error: could not create list.");
    }

    l->header = malloc(sizeof(Node));
    if (l->header == NULL) {
        free(l);
        terminate("Error: could not create list.");
    }

    l->trailer = malloc(sizeof(Node));
    if (l->trailer == NULL) {
        free(l->header);
        free(l);
        terminate("Error: could not create list.");
    }

    l->header->data = NULL;
    l->header->prev = NULL;
    l->header->next = l->trailer;
    
    l->trailer->data = NULL;
    l->trailer->prev = l->header;
    l->trailer->next = NULL;

    l->length = 0;

    return l;
}

void destroy(LinkedList l) {
    clear(l);
    free(l->header);
    free(l->trailer);
    free(l);
}

void clear(LinkedList l) {
    Node *n = l->header->next;
    while (n->next != NULL) {
        n = n->next;
        free(deleteNode(l, n->prev));
    }
}

int length(LinkedList l) {
    return l->length;
}

void insertNode(LinkedList l, Item *p, Node *prev, Node *next) {
    Node *new = malloc(sizeof(Node));
    if (new == NULL) {
        terminate("Error: could not insert node.");
    }

    new->data = p;
    new->prev = prev;
    new->next = next;

    prev->next = new;
    next->prev = new;

    l->length++;
}

Item *deleteNode(LinkedList l, Node *n) {
    Node *prev = n->prev, *next = n->next;

    prev->next = next;
    next->prev = prev;

    Item *deleted = n->data;
    free(n); 
    l->length--;

    return deleted;
}

static void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}