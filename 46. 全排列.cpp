#include"headFile.h"
class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<bool> used, vector<int>& nums, vector<int>& combine,  int len, int depth) {
        if (depth == len) {
            ans.push_back(combine);
            return;
        }
        for ( int i = 0; i < len; ++i) {
            if (used[i] == true || (i>0 && nums[i-1] ==nums[i] && used[i-1])) {
                continue;
            }
            combine.push_back(nums[i]);
            used[i] = true;
            dfs(ans, used, nums, combine, len, depth+1);
            combine.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>combine;
         int len = nums.size();
        if (len == 0) {
            return ans;
        }
        vector<bool> used(len,false);
        int depth = 0;
        dfs(ans, used, nums, combine, len, depth);
        return ans;
    }
};