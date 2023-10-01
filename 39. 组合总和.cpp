#include"headFile.h"
class Solution {
public:
    void backTrack(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {
        if (idx == candidates.size()) {
            return;
        }
        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }
        backTrack(candidates, target, ans, combine, idx + 1);
        if (target - candidates[idx] >= 0) {
            combine.emplace_back(candidates[idx]);
            backTrack(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        backTrack(candidates, target, ans, combine, 0);
        return ans;
    }
};
