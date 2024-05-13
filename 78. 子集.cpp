#include"headFile.h"
#include<functional>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int l = nums.size();
        function<void(int)>dfs = [&](int i) {
            if (i == l) {
                ans.push_back(path);
                return;
            }
            dfs(i + 1);
            path.push_back(nums[i]);
            dfs(i + 1);
            path.pop_back();
        };
        dfs(0);
        return ans;
    }
};