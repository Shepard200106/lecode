#include"headFile.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),right(right) {}
};

class Solution {
public:
    vector<TreeNode*>generateTrees(int start, int end)
    {
        if (start > end)return { nullptr };
        vector<TreeNode*>allTrees;
        //枚举可行根节点
        for (int i = start; i <= end; i++)
        {
            //获取左子树集合
            vector<TreeNode*>leftTrees = generateTrees(start, i - 1);

            //获取右子树集合
            vector<TreeNode*>rightTrees = generateTrees(i + 1, end);

            // 从左子树集合中选出一棵左子树，从右子树集合中选出一棵右子树，拼接根节点上
            for (auto& left : leftTrees)
            {
                for (auto& right : rightTrees)
                {
                    TreeNode* currTress = new TreeNode(i);
                    currTress->left = left;
                    currTress->right = right;
                    allTrees.emplace_back(currTress);
                }
            }
        }
        return allTrees;


    }
    vector<TreeNode*> generateTrees(int n)
    {
        if (!n)
        {
            return { };
        }
        return generateTrees(1, n);
    }
};