#include"headFile.h"
class Solution {
private:
    vector<vector<int>> res;
public:
    void dfs(TreeNode* root, vector<int>&tmp, int sum)
    {
        if (!root)return;
        tmp.push_back(root->val);
        if (root->val == sum && (root->left == nullptr && root->right == nullptr))
        {
            res.push_back(tmp);
        }
        dfs(root->left, tmp, sum - root->val);
        dfs(root->right, tmp, sum - root->val);
        //��һ���ڵ�����������������Ӧ��ɾ����ʼ������һ��ڵ�
        tmp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<int>tmp;
        dfs(root, tmp, targetSum);
        return res;
    }

};