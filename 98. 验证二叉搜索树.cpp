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
private:
    int r;
public:
    bool isValidBST(TreeNode* root)
    {
        return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
    }
    bool isValidBSTHelper(TreeNode* root, long long minVal, long long maxVal)
    {
        if (root == nullptr)
        {
            return true;
        }

        if (root->val <= minVal || root->val >= maxVal)
        {
            return false;
        }

        // 左子树的值应该小于当前节点的值，右子树的值应该大于当前节点的值
        return isValidBSTHelper(root->left, minVal, root->val) &&
            isValidBSTHelper(root->right, root->val, maxVal);
    }
};