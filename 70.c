#include <stdio.h>

int climbStair(int a, int memo[46]) {
    if(a==0) return 1;
    if(a==-1) return 0;
    if(memo[a] != 0) return memo[a];
    int aux = climbStair(a-1, memo);
    aux += climbStair(a-2, memo);
    memo[a] = aux;
    return aux;
}

int climbStairs(int n) {
    int memo[46] = {0};
    climbStair(n, memo);
    return memo[n];
}

int main() {
    int a = climbStairs(3);
    printf("%d\n", a);
}