#include <stdio.h>
#include <limits.h>
#include "linear_queue_proto.h"

int main () {
    // Max length
    int m;
    printf("?Max: ");
    scanf("%d", &m);

    // Creating queue
    queue que = create_queue(m);

    // Displaying menu
    printf("1. EnQueue\n2. DeQueue\n3. Is Empty\n4. Is Full\n5. Print\n6. Print Extra\n");

    int choice, term;
    while (1) {
        printf("?Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:     // EnQueue
                        printf("?Term: ");
                        scanf("%d", &term);
                        enqueue(&que, term);
            break;

            case 2:     // DeQueue
                        term = dequeue(&que);
                        if (term != INT_MIN)
                            printf("Popped Element is %d\n", term);
            break;

            case 3:     // Is Empty
                        if (is_queue_empty(que))
                            printf("[i] Queue is Empty\n");
                        else
                            printf("[i] Queue is Non Empty\n");
            break;

            case 4:     // Is Full
                        if (is_queue_full(que))
                            printf("[i] Queue is Full\n");
                        else
                            printf("[i] Queue is Non Full\n");
            break;

            case 6:     // Print Extra
                        printf("Front: %d, Rear: %d\n", que.FRONT, que.REAR);
            
            case 5:     // Print Queue
                        printf("Queue here: ");
                        print_queue(que);
            break;

            default:    free_queue(que);
                        printf("Okay, Goodbye!\n");
                        return 0;

        }
    }

    return 0;
}