#include <stdbool.h>

bool lemonadeChange(int* bills, int billsSize) {
    int c = 0, d = 0, i;

    for(i = 0; i < billsSize;i++) {
        if(bills[i] == 5) {
            c++;
        } else if(bills[i] == 10)  {
            if(c == 0) return false;
            c--;
            d++;
        } else {
            if(d > 0 && c > 0) {
                d--;
                c--;
            } else if(c >= 3) {
                c -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    return 0;
}