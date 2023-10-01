#include"headFile.h"
class Solution {
public:
    void dfs(vector<vector<int>>& ans,vector<int>& candidates, vector<int>& combine,int target,int idx) {
        if (target == 0) {
            ans.push_back(combine);
            return;
        }
        //Ҫ���ظ�����»��ݣ�ָ����ʼλ��idx������֮��ı����в��ظ���������ֵ
        for (int i = idx; i < candidates.size() && target - candidates[idx] >= 0; ++i) {
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            combine.push_back(candidates[i]);
            dfs(ans,candidates,combine,target - candidates[i],i+1);
            combine.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        sort(candidates.begin(), candidates.end());
        dfs(ans, candidates, combine, target, 0);
        return ans;
    }
};