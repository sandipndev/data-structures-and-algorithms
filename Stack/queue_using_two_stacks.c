/*
    We need to implement FIFO using two LIFO. There can be two basic approaches.

    * 1st Approach: (dequeue costly)
    Stack 1 -> TOP[ rear, ..., front]
    We can push into stack 1 for every enqueue operation and when dequeue is asked for, we pop all items in 
    stack 1 into stack 2, pop stack 2 (this element will be dequeued, think), and then push back all items in 
    their popped order back into stack 1.

    * 2nd Approach: (enqueue costly)
    Stack 1 -> TOP[ front, ..., rear]
    We can pop from stack 1 for every dequeue operation and when enqueue is asked for, we pop all items in
    stack 1 into stack 2, push the new term into stack 2 and then push back all items in their popper order
    back into stack 1.

    Below is the implementation of the 1st approach.
    @author: Sandipan Dey, github.com/triethyl

*/

#include <stdio.h>
#include "int_stack_proto.h"

int main() {

    // Maximum length of Queue
    int max_len;
    printf("? Max Length of Queue: ");
    scanf("%d", &max_len);

    // Initialize the two stacks
    stack stk1 = create_stack(max_len);
    stack stk2 = create_stack(max_len);

    // Display Menu
    printf("[QUEUE USING STACK]\n");
    printf("1. EnQueue\n");
    printf("2. DeQueue\n");
    printf("3. Print\n");

    // Vars
    int choice, key;

    // Menu Driven
    while (1) {

        fflush(stdin);

        // Choice
        printf("? Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Enqueue
                    printf("? Term to Enqueue: ");
                    scanf("%d", &key);
                    push(&stk1, key);
            break;
            case 2: // Dequeue
                    if (is_empty(stk1)) {
                        printf("[!] Queue is empty\n");
                    } else {
                        while (is_empty(stk1) != 1) {
                            push(&stk2, pop(&stk1));
                        }
                        key = pop(&stk2); // The dequeue term
                        while (is_empty(stk2) != 1) {
                            push(&stk1, pop(&stk2));
                        }
                        printf("Dequeued: %d\n", key);
                    }
            break;
            case 3: // Print
                    printf("Queue is: ");
                    print_stack(stk1);
            break;
            default:    printf("Wrong Option, quitting!\n");
                        goto END;
        }

    }

    END:
    free_stack(stk1);
    free_stack(stk2);

    return 0;
}