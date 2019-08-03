#define STRING_MAX 100
#define STACK_MAX 10

#include <stdio.h>
#include <string.h>
#include "char_stack_proto.h"

int valid_brace_pairs(char *);

int main() {
    char str[STRING_MAX];
    
    // User input
    printf("Enter braces pairs to validate: ");
    fgets(str, STRING_MAX, stdin);

    if (valid_brace_pairs(str)) 
        printf("Valid!\n");
    else
        printf("Not Valid!\n");
}

int valid_brace_pairs(char *str) {
    stack brackets = create_stack(strlen(str));

    int c=0;

    while(str[c] != '\0') {
        if (str[c] == '(' || str[c] == '{' || str[c] == '[') {
            push(&brackets, str[c]);
        } else if (str[c] == ')' || str[c] == '}' || str[c] == ']') {
            if (str[c] == ')') {
                if (peek(brackets) != '(')
                    return 0;
                else
                    pop(&brackets);
            } else if (str[c] == '}') {
                if (peek(brackets) != '{')
                    return 0;
                else
                    pop(&brackets);
            } else {
                if (peek(brackets) != '[')
                    return 0;
                else
                    pop(&brackets);
            }
        }

        c++;
    }

    return 1;
}
