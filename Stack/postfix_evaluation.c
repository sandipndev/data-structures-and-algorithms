#define STR_MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include "int_stack_proto.h"

int is_operator(char *x) {
    return strcmp(x, "+\0")==0 || strcmp(x, "-\0")==0 || strcmp(x, "*\0")==0 || strcmp(x, "/\0")==0 || strcmp(x, "^\0")==0;
}

int calculate_result(int left, int right, char *operator) {
    if (strcmp(operator, "+\0")==0) {
        return left + right;
    } else if (strcmp(operator, "-\0")==0) {
        return left - right;
    } else if (strcmp(operator, "*\0")==0) {
        return left * right;
    } else if (strcmp(operator, "/\0")==0) {
        return left / right;
    } else if (strcmp(operator, "^\0")==0) {
        return pow(left, right);
    }
}

int main() {
    char str[STR_MAX];
    printf("Enter postfix expression: ");
    fgets(str, STR_MAX, stdin);

    // Manipulating the string to not contain the last \n
    int pos = strlen(str);
    str[pos-1] = '\0';

    // Creating the operand stack
    stack operand_stk = create_stack(STR_MAX);

    // Tokenizing the string
    char *ptr = strtok(str, " ");
    while (ptr != NULL) {
        if (!is_operator(ptr)) {
            // Operand - push to stack
            push(&operand_stk, atoi(ptr));
        } else {
            // Operator - pop two from stack, calculate result, push back to stack
            int op1 = pop(&operand_stk);
            int op2 = pop(&operand_stk);

            if (op1 == INT_MIN || op2 == INT_MIN) {
                printf("The entered postfix expression is incorrect.\n");
                exit(0);
            }

            int res = calculate_result(op2, op1, ptr);
            push(&operand_stk, res);
        }
        
        ptr = strtok(NULL, " ");
    }

    if (operand_stk.TOP == 0) {
        printf("Evaluated Result = %d\n", operand_stk.base[0]);
    } else {
        printf("The entered postfix expression is incorrect.\n");
    }

    return 0;
}