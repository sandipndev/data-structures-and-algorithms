/* The logic of stack using linked list is quite simple. A stack is Last In First Out (LIFO).
   If, we consider the head element (first element) of the linked list as Top of Stack,
   we can just insert_first to push an element and delete_first to pop an element.

   Benefit of this approach is that we are using a Linked List instead of a fixed-length Array to 
   implement the stack. This is why, we can push elements till our memory permits.

   The very same logic has been implemented in this program.
   @author: Sandipan Dey, github.com/triethyl

*/

#include <stdio.h>
#include "linked_list.h"

int main() {
    fflush(stdin);

    // The linked list, first element holding the top of stack
    node *top = NULL;

    // The menu
    printf("[ STACK USING LINKED LIST ]\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Print\n");

    // Some variables we might need later
    int choice, key;
    
    // Infinite loop for menu-driven approach
    while (1) {

        // User input the choice
        printf("? Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Push
                    printf("? Item to push: ");
                    scanf("%d", &key);
                    top = insert_first(top, key);
            break;
            case 2: // Pop
                    if (top == NULL) {
                        printf("[!] Stack Underflow!");
                    } else {
                        top = delete_first(top);
                    }
            break;
            case 3: // Peek
                    if (top == NULL) {
                        printf("[!] No item to peek");
                    } else {
                        printf("Peek-a-boo: %d\n", top->data);
                    }
            break;
            case 4: // Print
                    printf("Your stack is: ");
                    display_list(top);
            break;
            default:    
                    printf("Wrong choice! Quitting!\n");
                    goto END;
        }
    }

    // At the end
    END:
    free_list(top);
}