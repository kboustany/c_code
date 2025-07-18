#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int main(void) {
    Stack s = create();
    int command;
    
    for (;;) {
        printf("\nEnter command: ");
        scanf("%d", &command);

        switch(command) {
            case 0: {
                destroy(s); 
                return 0;
            }
            case 1: {
                clear(s);
                printf("Cleared stack\n");
                break;
            }
            case 2: {
                printf("Length of stack is %d\n", length(s));
                break;
            }
            case 3: {
                printf("Item at top of stack is %d\n", *top(s));
                break;
            }
            case 4: {
                Item *entry = malloc(sizeof(int));
                printf("Enter item: ");
                scanf("%d", entry);
                push(s, entry);
                printf("Pushed %d onto stack\n", *entry);
                break;
            }
            case 5: {
                Item *deleted = pop(s);
                printf("Popped %d from stack\n", *deleted);
                free(deleted);
                break;
            }
            default: {
                printf("Invalid command\n");
                break;
            }
        }
    }
}