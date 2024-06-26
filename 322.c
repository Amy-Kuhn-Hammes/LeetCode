#include <stdio.h>
#include <string.h>
int qnts, *moedas, memo[10001];
int MAX = 999999;

int min(int a, int b){
    if(a < b) return a;
    return b;
}

int compra(int falta, int notas) {
    if(falta<0) return MAX;
    if(falta==0) return notas;
    if(memo[falta] != 0 && memo[falta] <= notas) return MAX;
    memo[falta] = notas;

    int aux = MAX, i;
    for(i = 0; i < qnts; i++) {
        aux = min(aux, compra(falta-moedas[i], notas+1));
    }
    return aux;
}

int coinChange(int* coins, int coinsSize, int amount) {
    moedas = coins;
    qnts = coinsSize;
    memset(memo, 0, sizeof(memo));
    int aux = compra(amount, 0);
    if(aux == MAX) return -1;
    return aux;
}