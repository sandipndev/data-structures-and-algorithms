#include <stdio.h>
#include <limits.h>
#include "int_stack_proto.h"

int main () {
    // Max length
    int m;
    printf("?Max: ");
    scanf("%d", &m);

    // Creating stack
    stack stk = create_stack(m);

    // Displaying menu
    printf("1. Push\n2. Pop\n3. Peek\n4. Is Empty\n5. Is Full\n6. Print\n7. Print Extra\n");

    int choice, term;
    while (1) {
        printf("?Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:     // Push
                        printf("?PushTerm: ");
                        scanf("%d", &term);
                        push(&stk, term);
            break;

            case 2:     // Pop
                        term = pop(&stk);
                        if (term != INT_MIN)
                            printf("Popped Element is %d\n", term);
            break;
            
            case 3:     // Peek
                        term = peek(stk);
                        if (term != INT_MIN)
                            printf("Peek-a-boo %d\n", term);
            break;

            case 4:     // Is Empty
                        if (is_empty(stk))
                            printf("[i] Stack is Empty\n");
                        else
                            printf("[i] Stack is Non Empty\n");
            break;

            case 5:     // Is Full
                        if (is_full(stk))
                            printf("[i] Stack is Full\n");
                        else
                            printf("[i] Stack is Non Full\n");
            break;

            case 7:     // Print Extra
                        printf("TOP: %d\n", stk.TOP);
            
            case 6:     // Print Stack
                        printf("Stack here: ");
                        print_stack(stk);
            break;

            default:    free_stack(stk);
                        printf("Okay, Goodbye!\n");
                        return 0;

        }
    }

    return 0;
}