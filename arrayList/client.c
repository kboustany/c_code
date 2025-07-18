#include <stdlib.h>
#include <stdio.h>
#include "arrayList.h"

int main(void) {
    ArrayList l = create();
    int command, i;
    
    for (;;) {
        printf("\nEnter command: ");
        scanf("%d", &command);

        switch(command) {
            case 0: {
                destroy(l);
                return 0;
            }
            case 1: {
                clear(l);
                printf("Cleared list.\n");
                break;
            }
            case 2: {
                printf("Length of list is %d\n", length(l));
                break;
            }
            case 3: {
                printf("Enter index: ");
                scanf("%d", &i);
                printf("Item at index %d is %d\n", i, *item(l, i));
                break;
            }
            case 4: {
                Item *entry = malloc(sizeof(Item));
                printf("Enter item: ");
                scanf("%d", entry);
                append(l, entry);
                printf("Appended %d to list\n", *entry);
                break;
            }
            case 5: {
                Item *entry = malloc(sizeof(Item));
                printf("Enter index: ");
                scanf("%d", &i);
                printf("Enter item: ");
                scanf("%d", entry);
                assignAt(l, i, entry);
                printf("Assigned %d at index %d\n", *entry, i);
                break;
            }
            case 6: {
                Item *entry = malloc(sizeof(Item));
                printf("Enter index: ");
                scanf("%d", &i);
                printf("Enter item: ");
                scanf("%d", entry);
                insertAt(l, i, entry);
                printf("Inserted %d at index %d\n", *entry, i);
                break;
            }
            case 7: {
                printf("Enter index: ");
                scanf("%d", &i);
                Item *deleted = deleteAt(l, i);
                printf("Deleted %d at index %d\n", *deleted, i);
                free(deleted);
                break;
            }
            case 8: {
                printf("[%d", *item(l, 0));
                for (int j = 1; j < length(l); j++) {
                    printf(", %d", *item(l, j));
                }
                printf("]\n");
                break;
            }
            default: {
                printf("Invalid command\n");
                break;
            }
        }
    }
}