#include <vector>
#include <stdlib.h>
#include <algorithm>
using std::vector;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int i, count=1;
        for(i = 0; i<nums.size()-1; i++) {
            if(nums[i] == nums[i+1]) {
                count++;
            } else {
                count = 1;
            }
            if(count >= (nums.size()+1)/2) {
                return nums[i];
            }
        }
        return nums[0];
    }
};