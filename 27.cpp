#include <vector>
using std::vector;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos = nums.size();
        while(pos--) {
            if(nums[pos] == val) {
                nums.erase(nums.begin()+pos);
            }
        }
        return nums.size();
    }
};