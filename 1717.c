int min(int a, int b) {
    if (a < b) return a;
    return b;
}

int maximumGain(char* s, int x, int y) {
    char pc = 'a', qc = 'b';
    int i, qCount = 0, pCount = 0, count = 0, aux;
    if (y > x) {
        pc = 'b';
        qc = 'a';
        i = y;
        y = x;
        x = i;
    }
    aux = strlen(s);
    for (i = 0; i <= aux; i++) {
        if (s[i] == pc) {
            pCount++;
        } else if (s[i] == qc) {
            if(pCount > 0) {
                pCount--;
                count+=x;
            } else {
                qCount++;
            }
        } else {
            count += min(pCount, qCount) * y;
            pCount= 0;
            qCount= 0;
        }
    }
    return count;
}