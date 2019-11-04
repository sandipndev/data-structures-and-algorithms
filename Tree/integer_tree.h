#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
    int VAL;
    struct tnode *LEFT;
    struct tnode *RIGHT;
} tnode;

tnode *create_node(int key) {
    tnode *tx = (tnode *) calloc(1, sizeof(tnode));
    tx->VAL = key;
    tx->LEFT = NULL;
    tx->RIGHT = NULL;
    return tx;
}

tnode *create_tree_user_input() {

    int val;
    printf("? Value at present root: ");
    scanf("%d", &val);

    tnode *this_tnode = create_node(val);

    // LEFT BRANCH
    int ch;
    while (1) {
        printf("? Is there a left branch of this node [Value -> %d]: ", val);
        scanf("%d", &ch);

        if (ch == 0 || ch == 1) {
            break;
        } else {
            printf("Wrong Choice, value must be 0 or 1. Try again!\n");
            continue;
        }
    }

    if (ch == 1) {
        this_tnode->LEFT = create_tree_user_input();
    }

    // RIGHT BRANCH
    while (1) {
        printf("? Is there a right branch of this node [Value -> %d]: ", val);
        scanf("%d", &ch);

        if (ch == 0 || ch == 1) {
            break;
        } else {
            printf("Wrong Choice, value must be 0 or 1. Try again!\n");
            continue;
        }
    }

    if (ch == 1) {
        this_tnode->RIGHT = create_tree_user_input();
    }

    return this_tnode;

}

void prefix_print(tnode *root) {
    if (root != NULL) {
        printf("%d,", root->VAL);
        prefix_print(root->LEFT);
        prefix_print(root->RIGHT);
    }
}

void infix_print(tnode *root) {
    if (root != NULL) {
        infix_print(root->LEFT);
        printf("%d,", root->VAL);
        infix_print(root->RIGHT);
    }
}

void postfix_print(tnode *root) {
    if (root != NULL) {
        postfix_print(root->LEFT);
        postfix_print(root->RIGHT);
        printf("%d,", root->VAL);
    }
}

tnode *bst_insert(tnode *root, int key) {
    if (root == NULL) {
        return create_node(key);
    } else {

        if (key == root->VAL) {
            // Equal keys not supported in bst
        }

        else if (key>root->VAL && root->RIGHT==NULL) {
            root->RIGHT = create_node(key);
        }

        else if (key<root->VAL && root->LEFT==NULL) {
            root->LEFT = create_node(key);
        }

        else if (key>root->VAL) {
            bst_insert(root->RIGHT, key);
        }

        else if (key<root->VAL) {
            bst_insert(root->LEFT, key);
        }

        return root;
        
    }
}