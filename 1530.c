#include <stdbool.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool matrix[1025][1025];
int memo[1025], count, nunLeafs, ans, leafs[1025], dBase;

void fill(struct TreeNode* root) {
    if(root->left) {
        root->left->val = count;
        count++;
        matrix[root->val][root->left->val] = true;
        matrix[root->left->val][root->val] = true;
        fill(root->left);
    }
    if(root->right) {
        root->right->val = count;
        count++;
        matrix[root->val][root->right->val] = true;
        matrix[root->right->val][root->val] = true;
        fill(root->right);
    }
    if(!(root->right) && !(root->left)) {
        leafs[nunLeafs] = root->val;
        nunLeafs++;
    }

} 

int dfs(int pos, int mov) {
    if(mov < 0 || memo[pos] >= mov ) return 0;
    memo[pos] = mov;
    for(int i = 0; i<nunLeafs; i++) {
        if(leafs[i] == pos && mov != dBase) {
            printf("%d\n", pos);
            ans++;
            return 0;
        }
    }
    for(int i = 0; i<count; i++) {
        if(matrix[pos][i]) {
            dfs(i, mov-1);
        }
    }
    return 0;
}

int countPairs(struct TreeNode* root, int distance) {
    int i;
    root->val = 0;
    ans = 0;
    dBase = distance;
    count = 1;
    nunLeafs = 0;
    memset(matrix, false, sizeof(matrix));
    fill(root);
    for(i = 0; i < nunLeafs; i++) {
        memset(memo, -1, sizeof(memo));
        dfs(leafs[i], distance);
    }
    return ans/2;
}