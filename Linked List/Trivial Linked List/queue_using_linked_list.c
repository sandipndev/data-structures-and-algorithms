/* 
   * Also Circular Queue

   A queue is a FIFO (First in First Out) data structure. It can be easily implemented using a Linked List.
   [! Think] Considering the head element as FRONT of queue, we need just the functions delete_first and insert_last.
   (Vise versa also possible, where head element is REAR and we use insert_first and delete_last)

   Benefit of using Linked List for Queue: The problem of a linear queue was that it had a fixed size array length
   limit and after deleting some elements, it didn't circle back even if there were empty places. A circular queue
   tackles that issue very well. But even in a circular queue, the maximum length is still fixed. Hence comes use of
   linked list, which cleverly can expand in either directions.

   Below is the implementation of queue using linked list with front of queue as the head element of the linked list.
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
    printf("1. EnQueue\n");
    printf("2. DeQueue\n");
    printf("3. Print Queue\n");

    // Some variables we might need later
    int choice, key;
    
    // Infinite loop for menu-driven approach
    while (1) {

        // User input the choice
        printf("? Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // EnQueue
                    printf("? Item to enqueue: ");
                    scanf("%d", &key);
                    front = insert_last(front, key);
            break;
            case 2: // DeQueue
                    if (front == NULL) {
                        printf("[!] Queue Underflow!\n");
                    } else {
                        front = delete_first(front);
                    }
            break;
            case 3: // Print
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
