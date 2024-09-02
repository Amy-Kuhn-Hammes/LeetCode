int aux[10001], auxD[10001];

int mergeSort(int* d, int* p, int b, int t) {
    if(t-b < 1) {
        return 0;
    }
    int mid = (t-b)/2, i = 0, j = 0;
    mergeSort(d, p, b, b+mid);
    mergeSort(d, p, b+mid+1, t);

    for(i = 0; i <= mid; i++) {
        aux[i] = p[i+b];
        auxD[i] = d[i+b];
    }
    i = 0;
    while(i + j <= t- b){
        if(j >= t-(mid+b) || (aux[i] > p[b+mid+j+1] && i <= mid)) {
            p[b+i+j] = aux[i];
            d[b+i+j] = auxD[i];
            i++;
        }else {
            p[b+i+j] = p[b+mid+j+1];
            d[b+i+j] = d[b+mid+j+1];
            j++;
        }
    }
    return 0;
}

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {
    mergeSort(difficulty, profit, 0, profitSize-1);
    mergeSort(worker, worker, 0, workerSize-1);
    
    int i = 0, j = 0, aux = 0;
    while(j < workerSize && i < profitSize){
        if(difficulty[i] <= worker[j]) {
            j++;
            aux += profit[i];
        } else {
            i++;
        }
    }
    return aux;
}