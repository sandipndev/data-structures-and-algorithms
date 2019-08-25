#define STR_MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "char_stack_proto.h"

int is_operator(char *);
int precedence(char);

int main() {
    char str[STR_MAX];
    printf("Enter infix expression: ");
    fgets(str, STR_MAX, stdin);

    stack operator_stk = create_stack(STR_MAX);

    // 1.1 - Push ( to stack
    push(&operator_stk, '(');

    // 1.2 - Manipulating the string to not contain the last \n, instead contain )
    int pos = strlen(str);
    str[pos-1] = ' ';
    str[pos] = ')';
    str[pos+1] = '\0';

    // 2 - Traverse the string
    char ch;
    char *ptr = strtok(str, " ");

    while(ptr!=NULL) {

        if (!is_operator(ptr)) {
            // Operand
            printf("%d ", atoi(ptr));
        } else {
            // Operator

            // Opening parenthesis
            if (strcmp(ptr, "(\0") == 0) {
                push(&operator_stk, ptr[0]);
                goto X;
            }

            // Closing parenthesis
            if (strcmp(ptr, ")\0") == 0) {
                ch = peek(operator_stk);
                if (ch == CHAR_MIN) {
                    printf("Incorrect infix expression.\n");
                    exit(0);
                }
                while (ch != '(') {
                    ch = pop(&operator_stk);
                    if (ch == CHAR_MIN) {
                        printf("Incorrect infix expression.\n");
                        exit(0);
                    }
                    if (ch != '(')
                        printf("%c ", ch);
                }
                goto X;
            }

            // It's a genuine operator
            ch = peek(operator_stk);
            if (ch == CHAR_MIN) {
                printf("Incorrect infix expression.\n");
                exit(0);
            }

            while (precedence(ch) > precedence(ptr[0])) {
                ch = pop(&operator_stk);
                if (ch == CHAR_MIN) {
                    printf("Incorrect infix expression.\n");
                    exit(0);
                }
                printf("%c ", ch);
                ch = peek(operator_stk);
            }

            while (precedence(ch) == precedence(ptr[0])) {
                if (ptr[0] == '^') {
                    push(&operator_stk, ptr[0]);
                    goto X;
                } else {
                    ch = pop(&operator_stk);
                    if (ch == CHAR_MIN) {
                        printf("Incorrect infix expression.\n");
                        exit(0);
                    }
                    printf("%c ", ch);
                    ch = peek(operator_stk);
                }
            }

            if (precedence(ch) < precedence(ptr[0])) {
                push(&operator_stk, ptr[0]);
            }

        }
        
        X:
        ptr = strtok(NULL, " ");
    }

    printf("\n");

    free_stack(operator_stk);
    return 0;
}

int is_operator(char *x) {
    return strcmp(x, "+\0")==0 || strcmp(x, "-\0")==0 || strcmp(x, "*\0")==0 || strcmp(x, "/\0")==0 || strcmp(x, "^\0")==0 || strcmp(x, "(\0")==0 || strcmp(x, ")\0")==0;
}

int precedence(char x) {
    if (x == '+' || x == '-')       return 1;
    else if (x == '*' || x == '/')  return 2;
    else if (x == '^')              return 3;
    else if (x == '(')              return -1;
}