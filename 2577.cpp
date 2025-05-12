    #include <vector>
    #include <stdlib.h>
    #include <algorithm>
    #include <stdio.h>
    using std::vector;

    struct Item
    {
        int hora;
        int x;
        int y;
    };  

    int buscaBinaria(vector<Item> heap, int piso, int teto, int val) {
        if(piso == 0 && teto == 0) return 0;
        int meio = (piso + teto) / 2;
        if(teto <= piso) return meio;
        if(heap[meio].hora == val) return meio;
        if(heap[meio].hora > val) return buscaBinaria(heap, piso, meio-1, val);
        return buscaBinaria(heap, meio+1, teto, val);
    }

    class Solution {
    public:
        int minimumTime(vector<vector<int>>& grid) {
            int pos, aux, matrizX[4] = {0,0 ,1,-1}, matrizY[4] = {1,-1,0, 0}, gridYSize = grid[0].size(), gridXSize = grid.size(), tempX, tempY, tempHora; 
            int v[1001][1001][2] = {0};
            vector<Item> heap;
            struct Item it;
            it.hora = 0;
            it.x = 0;
            it.y = 0;
            heap.push_back(it);
            while(!heap.empty()) {
                for(int i = 0; i < 4; i++) {
                    tempX = heap[0].x + matrizX[i];
                    tempY = heap[0].y + matrizY[i];
                    tempHora = heap[0].hora;
                    if(!(tempX < 0 || tempX >= gridXSize || tempY < 0 || tempY >= gridYSize)) {
                        if((v[tempX][tempY][(tempHora+1)%2] == 0 || v[tempX][tempY][(tempHora+1)%2] > tempHora+1) && grid[tempX][tempY] % 2 == (tempHora+1) % 2) {
                            aux = grid[tempX][tempY];
                            if(aux < tempHora + 1) aux = tempHora+1;
                            if(tempX == gridXSize-1 && tempY == gridYSize-1) {
                                return aux;
                            }
                            struct Item it;
                            it.hora = aux;
                            it.x = tempX;
                            it.y = tempY;

                            pos = buscaBinaria(heap, 0, heap.size(), it.hora);

                            heap.insert(heap.begin() + pos, it);
                            v[tempX][tempY][it.hora%2] = it.hora;
                        }
                    }
                }
                heap.erase(heap.begin(), heap.begin() + 1);
            }
            return -1;
        }
    };