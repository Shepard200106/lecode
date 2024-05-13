#include"headFile.h"
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>>ans;
        if (!root)
        {
            return ans;
        }
        queue<TreeNode*>nodeQueue;
        nodeQueue.push(root);
        bool isLeft = true;
        while (!nodeQueue.empty())
        {
            deque<int> levelList;
            int size = nodeQueue.size();
            for (int i = size; i > 0; i--)
            {
                auto node = nodeQueue.front();
                nodeQueue.pop();
                if (isLeft)
                {
                    levelList.push_back(node->val);
                }
                else
                {
                    levelList.push_front(node->val);
                }
                if (node->left)
                    nodeQueue.push(node->left);
                if (node->right)
                    nodeQueue.push(node->right);
            }
            ans.emplace_back(vector<int>{levelList.begin(), levelList.end()});
            isLeft = !isLeft;
        }
        return ans;
    }
};