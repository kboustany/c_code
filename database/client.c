#include <stdio.h>
#include "database.h"
#include "../reader/reader.h"

int main(void) {
    Database d = create();
    int command;

    for (;;) {
        command = get_int("\nEnter command: ");

        switch(command) {
            case 0: {
                destroy(d);
                return 0;
            }
            case 1: {
                addItem(d);
                break;
            }
            case 2: {
                searchItem(d);
                break;
            }
            case 3: {
                updateItem(d);
                break;
            }
            case 4: {
                deleteItem(d);
                break;
            }
            case 5: {
                display(d);
                break;
            }
            default: {
                printf("Invalid command\n");
                break;
            }
        }
    }
}