/* 
    Double Ended Queue can insert and delete from both rear and front. Keeping the linked list implementation in mind,
    we will hence need to use all the four functions -> insert_first, insert_last, delete_first and delete_last.

    Below is the implementation accordingly.
    @author: Sandipan Dey, github.com/triethyl

*/


#include <stdio.h>
#include "linked_list.h"

int main() {
    fflush(stdin);

    // The linked list, first element holding the front of queue
    node *front = NULL;

    // The menu
    printf("[ QUEUE USING LINKED LIST ]\n");
    printf("1. EnQueue Rear\n");
    printf("2. EnQueue Front\n");
    printf("3. DeQueue Front\n");
    printf("4. DeQueue Rear\n");
    printf("5. Print Queue\n");

    // Some variables we might need later
    int choice, key;
    
    // Infinite loop for menu-driven approach
    while (1) {

        // User input the choice
        printf("? Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // EnQueue Rear
                    printf("? Item to enqueue: ");
                    scanf("%d", &key);
                    front = insert_last(front, key);
            break;
            case 2: // EnQueue Front
                    printf("? Item to enqueue: ");
                    scanf("%d", &key);
                    front = insert_first(front, key);
            break;
            case 3: // DeQueue Front
                    if (front == NULL) {
                        printf("[!] Queue Underflow!\n");
                    } else {
                        front = delete_first(front);
                    }
            break;
            case 4: // DeQueue Rear
                    if (front == NULL) {
                        printf("[!] Queue Underflow!\n");
                    } else {
                        front = delete_last(front);
                    }
            break;
            case 5: // Print
                    printf("The Queue is: ");
                    display_list(front);
            break;
            default:    
                    printf("Wrong choice! Quitting!\n");
                    goto END;
        }
    }

    // In the end
    END:
    free_list(front);
}
