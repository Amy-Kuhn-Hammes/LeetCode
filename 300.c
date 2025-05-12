#include <stdio.h>
#include <string.h>

int MIN = -99999;
int memo[2501][2501], *lista, qnts, max;

int pega(int pos, int last, int count) {
    if(count > max) max = count;
    if(memo[pos][count] != MIN && memo[pos][count] < last) return 0;
    memo[pos][count] = last;
    for(int i = pos; i < qnts; i++){
        if(lista[i] > last) {
            pega(i ,lista[i], count+1);
        }
    }
    return 0;
}


int lengthOfLIS(int* nums, int numsSize) {
    lista = nums;
    qnts = numsSize;
    memset(memo, MIN, sizeof(memo));
    max = 0;
    pega(0, MIN, 0);
    return max;
}

int main() {
    int a[6] ={0,1,0,3,2,3};
    printf("%d\n",lengthOfLIS(a, 6));
}