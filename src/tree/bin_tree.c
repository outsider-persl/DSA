#include <stdio.h>
#include <stdlib.h>

// 定义树节点结构体
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建新节点
TreeNode* create_node(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 释放树节点内存
void free_tree(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

// 前序遍历
void pre_order_traversal(const TreeNode* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->val);
    pre_order_traversal(node->left);
    pre_order_traversal(node->right);
}

// 中序遍历
void in_order_traversal(const TreeNode* node) {
    if (node == NULL) {
        return;
    }
    in_order_traversal(node->left);
    printf("%d ", node->val);
    in_order_traversal(node->right);
}

// 后序遍历
void post_order_traversal(const TreeNode* node) {
    if (node == NULL) {
        return;
    }
    post_order_traversal(node->left);
    post_order_traversal(node->right);
    printf("%d ", node->val);
}

int main() {
    // 创建树节点
    TreeNode* root = create_node(1);
    TreeNode* A = create_node(2);
    TreeNode* B = create_node(3);

    // 构建树
    root->left = A;
    root->right = B;
    A->left = create_node(4);
    A->right = create_node(5);
    B->left = create_node(6);
    B->right = create_node(7);

    // 打印树的遍历结果
    printf("Pre-order Traversal: ");
    pre_order_traversal(root);
    printf("\n");

    printf("In-order Traversal: ");
    in_order_traversal(root);
    printf("\n");

    printf("Post-order Traversal: ");
    post_order_traversal(root);
    printf("\n");

    // 释放内存
    free_tree(root);

    return 0;
}
