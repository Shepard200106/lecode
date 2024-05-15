#include"headFile.h"
class Solution {
public:
    int minDepth(TreeNode* root)
    {
        if (root == nullptr)return 0;
        int hl = minDepth(root->left);
        int hr = minDepth(root->right);
        if (hl == 0 || hr == 0)
        {
            return max(hl, hr) + 1;
        }
        else
        {
            return min(hl, hr) + 1;
        }
    }
};