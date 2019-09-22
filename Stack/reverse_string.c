#define STR_MAX 100

#include <stdio.h>
#include <string.h>
#include "char_stack_proto.h"

int main() {

    // String input
    char str[STR_MAX];
    printf("Enter a string: ");
    fgets(str, STR_MAX, stdin);
    printf("Entered string: %s", str);

    // Length
    int len = strlen(str);

    // Put entire string in stack
    stack wtf = create_stack(len);

    // Put every character in stack
    int c=0;
    while (str[c] != '\0') {
        // Push every character
        push(&wtf, str[c]);

        // Increment
        c++;
    }

    // New string
    char *new_str = malloc((len+1) * sizeof(char));

    // Pop out the stack
    c = 0;
    while (is_empty(wtf) != 1) {
        // Pop and fill
        new_str[c++] = pop(&wtf);
    }
    new_str[c] = '\0';

    printf("Reverse string: %s\n", new_str);
}