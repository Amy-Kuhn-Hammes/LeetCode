#include <stdbool.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode** r;
int size, *td, tdSize;

bool contain(int val) {
    for (int i = 0; i < tdSize; i++) {
        if (td[i] == val)
            return true;
    }
    return false;
}

bool del(struct TreeNode* root) {
    if (root->left) {
        if(del(root->left)) {
            root->left = NULL;
        }
    }
    if (root->right) {
        if(del(root->right)) {
            root->right = NULL;
        }
    }
    if (contain(root->val)) {
        if (root->left) {
            r[size] = root->left;
            size++;
        }
        if (root->right) {
            r[size] = root->right;
            size++;
        }
        return true;
    }
    return false;
}

struct TreeNode** delNodes(struct TreeNode* root, int* to_delete,
int to_deleteSize, int* returnSize) {
    size = 0;
    td = to_delete;
    tdSize = to_deleteSize;
    r = malloc(sizeof(struct TreeNode*) * 1001);
    if(!contain(root->val)) {
        r[0] = root;
        size++;
    }
    del(root);
    *returnSize = size;
    return r;
}