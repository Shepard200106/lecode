#include"headFile.h"

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
    int height(TreeNode* root)
    {
        if (root == nullptr)return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        if (lh >= 0 && rh >= 0 && abs(lh - rh) <= 1)
        { 
            return max(lh, rh) + 1;
        }
        else
        {
            return -1;
        }
    }
    bool isBalanced(TreeNode* root)
    {
        return height(root) >= 0;
    }
};