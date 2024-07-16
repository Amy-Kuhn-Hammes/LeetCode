#include <string.h>
#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

char m[3][100001];
int n[2][100001], s[2];

bool findNode(struct TreeNode* node, int v, int pos, int a) {
    if(node->val == v) {
        n[a][pos] = node->val;
        s[a] = pos;
        return true;
    }
    if(node->left && findNode(node->left, v, pos+1, a)) {
        m[a][pos] = 'L';
        n[a][pos] = node->val;
        return true;
    }
    if(node->right && findNode(node->right, v, pos+1, a)) {
        m[a][pos] = 'R';
        n[a][pos] = node->val;
        return true;
    }
    return false;
}

char* getDirections(struct TreeNode* root, int startValue, int destValue) {
    memset(m, 0,sizeof(m));
    memset(n, 0,sizeof(n));
    findNode(root, startValue, 0, 0);
    findNode(root, destValue, 0, 1);
    int i = 0, j, k;
    while(1) {
        if(n[0][i]!=n[1][i]) {
            i--;
            for(j = 0; j < s[0]-i; j++) {
                m[2][j] = 'U';
            }
            for(k = 0; k < s[1]-i; k++) {
                m[2][k+j] = m[1][k+i];
            }
            return m[2];
        }
        i++;
    }
}