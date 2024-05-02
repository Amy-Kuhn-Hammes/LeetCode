#include <vector>
using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = nums.size()-1;
        while(pos--) {
            if(nums[pos]==nums[pos+1]) {
                nums.erase(nums.begin() + pos);
            }
        }
        return nums.size();
    }
};