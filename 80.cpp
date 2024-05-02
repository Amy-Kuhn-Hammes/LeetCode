#include <vector>
using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = nums.size()-2;
        if(pos>=0) {
            while(pos--) {
                if(nums[pos]==nums[pos+1] && nums[pos]==nums[pos+2]) {
                    nums.erase(nums.begin() + pos);
                }
            }
        }
        return nums.size();
    }
};