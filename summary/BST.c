#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
} *root;

void search(struct node* curr, int find) {
    if (curr == NULL) {
        printf("not found\n");
        return;
    }

    if (curr->key == find) {
        printf("found\n");
        return;
    }
    
    if (curr->key < find) {
        search(curr->right, find);
    } else {
        search(curr->left, find);
    }
}


void insert(struct node* curr, int val) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->key = val;
    new_node->left = NULL;
    new_node->right = NULL;
    if (root == NULL) {
        root = new_node;
    }
    else if (val != curr->key) 
    {
        if (val < curr->key && curr->left == NULL) {
            curr->left = new_node;
        }
        else if (val > curr->key && curr->right == NULL) {
            curr->right = new_node;
        }
        else if (val < curr->key && curr->left != NULL) {
            insert(curr->left, val);
        }
        else if (val > curr->key && curr->right != NULL) {
            insert(curr->right, val);
        }
    }
}

void inorder_traversal(struct node* curr) {
    if (curr == NULL) return;
    inorder_traversal(curr->left);
    printf("%d ", curr->key);
    inorder_traversal(curr->right);
}

void preorder_traversal(struct node* curr) {
    if (curr == NULL)
    {
        return;
    }
    printf("%d ", curr->key);
    preorder_traversal(curr->left);
    preorder_traversal(curr->right);
}

void postorder_traversal(struct node* curr) {
    if (curr == NULL)
    {
        return;
    }
    postorder_traversal(curr->left);
    postorder_traversal(curr->right);
    printf("%d ", curr->key);
}

void executeDeleteNode(struct node* parent, struct node* curr) {
    if (curr->left == NULL && curr->right == NULL) {
        if (parent == curr) {
            root = NULL;
        }
        else if (parent->left == curr) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(curr);
    } else {
        struct node* replacement;
        if (curr->right != NULL) {
            replacement = curr->right;
            while (replacement->left != NULL) {
                replacement = replacement->left;
            }
        } else {
            replacement = curr->left;
            while (replacement->right != NULL) {
                replacement = replacement->right;
            }
        }
        curr->key = replacement->key;
        executeDeleteNode(curr, replacement);
    }
}

void deleteNode(struct node* curr, int find) {
    struct node *parent;
    parent = curr;
    while (curr != NULL && curr->key != find) {
    if (find < curr->key) {
        parent = curr;
        curr = curr->left;
    }
    else if (find > curr->key) {
        parent = curr;
        curr = curr->right;
    }
    }
    if (curr == NULL) {
        printf("%d is not found", find);
    }
    else if (curr->key == find) {
        executeDeleteNode(parent, curr);
    }
}

int minValue(struct node* node) {
    struct node* curr = node;
    while (curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr->key;
}

int maxValue(struct node* node){
    struct node* curr = node;
    while (curr->right != NULL)
    {
        curr = curr->right;
    }
    return curr->key;
}

int count(struct node* node){
    if (node == NULL)
    {
        return 0;
    }
    int x = count(node->left);
    int y = count(node->right);
    return 1 + x + y;
}

int height_of_binary_tree(struct node *node){
    if (node == NULL)
    {
        return 0;
    }
    int  leftHeight = height_of_binary_tree(node->left);
    int  rightHeight = height_of_binary_tree(node->right);
    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }else
    {
        return rightHeight + 1;
    }
}

int main() {
    system("clear");
    root = NULL;
    insert(root, 54);
    insert(root, 81);
    insert(root, 16);
    insert(root, 27);
    insert(root, 9);
    insert(root, 36);
    insert(root, 63);
    insert(root, 72);
    printf("Total node in BST: %d \n",count(root));
    printf("Height of binary tree : %d\n ", height_of_binary_tree(root));
    printf("\nInorder: "); inorder_traversal(root);
    printf("\nPreorder: "); preorder_traversal(root);
    printf("\nPostorder: "); postorder_traversal(root);
    puts("");
    deleteNode(root, 54);
    printf("\nPreorder (after del 54): "); preorder_traversal(root);
    deleteNode(root, 9);
    printf("\nPostorder (after del 9): "); postorder_traversal(root);
    deleteNode(root, 81);
    printf("\nInorder (after del 81): "); inorder_traversal(root);
    puts("");
    printf("Min value: %d \n", minValue(root));
    printf("Max value: %d \n", maxValue(root));
    puts("");
    search(root, 10);
    search(root, 8);
    getchar();
return 0;
}