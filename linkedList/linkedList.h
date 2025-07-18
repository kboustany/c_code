#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#ifndef CUSTOM_ITEM

typedef int Item;

#endif

struct node {
    Item *data;
    struct node *prev;
    struct node *next;
};

typedef struct node Node;

struct LinkedList_type {
    Node *header;
    Node *trailer;
    int length;
};

typedef struct LinkedList_type *LinkedList;

LinkedList create(void);
void destroy(LinkedList);
void clear(LinkedList);
int length(LinkedList);
void insertNode(LinkedList, Item *, Node *, Node *);
Item *deleteNode(LinkedList, Node *);

#endif