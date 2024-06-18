#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char** dict;
char* palavra;
int num;
int memo[301];
bool compare(char* dic, int pos) {
    if(pos + strlen(dic) > strlen(palavra)) return false;
    for(int i = 0; i < strlen(dic); i++) {
        if(dic[i] != palavra[pos+i]) return false;
    }
    return true;
}

bool pega(int pos) {
    if(pos > strlen(palavra)) return false;
    if(pos == strlen(palavra)) return true;
    if(memo[pos] == 1) return false;
    memo[pos] = 1;
    bool aux = false;
    for(int i = 0; i < num; i++) {
        if(compare(dict[i], pos)){
            aux = aux || pega(pos+strlen(dict[i]));
        }
    }
    return aux;
}

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    dict = wordDict;
    palavra = s;
    num = wordDictSize;
    memset(memo, 0, sizeof(memo));
    return pega(0);
}