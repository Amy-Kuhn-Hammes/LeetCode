// As bibliotecas foram incluidas e a definição do treenode foram descomentadas só para o envio da tarefa, já que, não são necessarias no leetCode

/*
    Amy Kuhn Hammes
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int p, pCount;
struct TreeNode* ans;

void findDeepest(struct TreeNode* root, int deep) {
    if(root->left != NULL) {
        findDeepest(root->left, deep+1);
    }
    if(root->right != NULL) {
        findDeepest(root->right, deep+1);
    }
    if(root->right == NULL && root->left == NULL) {
        if(p == deep) {
            pCount++;
        } else if(deep > p) {
            p = deep;
            pCount = 1;
        }
    }


}

int findSubtree(struct TreeNode* root, int deep) {
    if(root->right == NULL && root->left == NULL) {
        if(deep == p) {
            if(1 == pCount && ans == NULL) {
                ans = root;
            }
            return 1;
        }
        return 0;
    }
    int aux = 0;

    if(root->left != NULL) {
        aux += findSubtree(root->left, deep+1);
    }
    if(root->right != NULL) {
        aux += findSubtree(root->right, deep+1);
    }
    if(aux == pCount && ans == NULL) {
        ans = root;
    }
    return aux;
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    p = -1;
    pCount = 0;
    ans = NULL;
    findDeepest(root, 0);
    findSubtree(root, 0);
    if(ans) {
        return ans;
    }
    return root;
}