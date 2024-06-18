#include <vector>
#include <stdlib.h>
#include <stdio.h>
using std::vector;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int aux = k%nums.size();
        nums.insert(nums.begin(), nums.end()-aux, nums.end());
        nums.erase(nums.end()-aux, nums.end());
    }
};