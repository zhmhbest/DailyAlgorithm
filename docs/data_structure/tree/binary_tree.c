#include <stdio.h>
#include <stdlib.h>
#define ELEMENT int
#define ELEMENT_NULL 0

typedef struct BinaryTreeStructNode {
    struct BinaryTreeStructNode* left;
    struct BinaryTreeStructNode* right;
    ELEMENT value;
} BinaryTreeNode;
typedef struct
{
    BinaryTreeNode* root;
} BinaryTree;

BinaryTree*
binary_tree_create()
{
    BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
    tree->root = NULL;
    return tree;
}
BinaryTreeNode*
binary_tree_new_node(ELEMENT value, BinaryTreeNode* left, BinaryTreeNode* right)
{
    BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (!node)
        return NULL;
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

void binary_tree_recursion_drop(BinaryTreeNode* node)
{
    if (!node)
        return;
    if (node->left)
        binary_tree_recursion_drop(node->left);
    if (node->right)
        binary_tree_recursion_drop(node->right);
    free(node);
}
void binary_tree_drop(BinaryTree* tree)
{
    binary_tree_recursion_drop(tree->root);
    free(tree);
}

int binary_tree_empty(BinaryTree* tree)
{
    return NULL == tree->root;
}

void binary_tree_recursion_print(BinaryTreeNode* node, int depth)
{
    if (!node) {
        for (int i = 0; i < depth; i++)
            printf("........|");
        printf("NIL\n");
        return;
    }
    binary_tree_recursion_print(node->right, depth + 1);
    for (int i = 0; i < depth; i++)
        printf("........|");
    printf("%d\n", node->value);
    binary_tree_recursion_print(node->left, depth + 1);
}
void binary_tree_print(BinaryTree* tree)
{
    binary_tree_recursion_print(tree->root, 0);
}

int main()
{
    BinaryTree* tree = binary_tree_create();
    printf("empty: %d\n", binary_tree_empty(tree));
    tree->root = binary_tree_new_node(
        66,
        binary_tree_new_node(
            62,
            binary_tree_new_node(60,
                binary_tree_new_node(59, NULL, NULL),
                binary_tree_new_node(61, NULL, NULL)),
            binary_tree_new_node(64, NULL, NULL)),
        binary_tree_new_node(70, NULL, NULL));
    printf("empty: %d\n", binary_tree_empty(tree));
    binary_tree_print(tree);
    binary_tree_drop(tree);
    return 0;
}