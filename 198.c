#include <stdio.h>
#include <string.h>

int *casas, numCasas, memo[101]; 

int max(int a, int b) {
    if(a>b) return a;
    return b;
}

int rouba(int atual, int grana) {
    if(atual >= numCasas) return grana;
    if(memo[atual] != -1 && memo[atual] >= grana) return 0;
    memo[atual] = grana;
    return max(
        rouba(atual+2, grana+casas[atual]),
        rouba(atual+3, grana+casas[atual])
    );
}


int rob(int* nums, int numsSize) {
    casas = nums;
    numCasas = numsSize;
    memset(memo, -1, sizeof(memo));
    return max(rouba(0, 0), rouba(1, 0));
}

int main() {
    int aux[4] = {1,2,3,1};
    printf("%d\n", rob(aux, 4));
}