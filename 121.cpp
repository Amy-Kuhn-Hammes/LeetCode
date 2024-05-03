#include <vector>
#include <stdlib.h>
#include <stdio.h>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, min = prices[0], best = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] - min > best) {
                best = prices[i] - min;
            }
            if(min > prices[i]) {
                min = prices[i];
            }
        }
        return best;
    }
};