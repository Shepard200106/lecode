#include"headFile.h"
class Solution {
public:
    int search(vector<int>& nums, int target, bool lower) {
        int n = nums.size() - 1;
        //ans等于nums的大小是为了防止类似于特殊情况{1}，1
        int ans = nums.size();
        int left = 0, right = n;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            }
            else {
                left = mid + 1;
            }   
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        bool lower = true;
        int lf = search(nums, target,true);
        int rl = search(nums, target,false) - 1;
        if (lf <= rl && rl < nums.size() && nums[lf] == target && nums[rl] == target) {
            return { lf,rl };
        }
        return {-1,-1};
    }
};
