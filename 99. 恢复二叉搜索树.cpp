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
    TreeNode* first = nullptr, * second = nullptr, * prev = nullptr;
public:
    void recoverTreeHelp(TreeNode* root)
    {
        if (root == nullptr)return;
        recoverTreeHelp(root->left);
        if (prev != nullptr && prev->val >= root->val)
        {
            if (first == nullptr) first = prev;
            second = root;
        }
        prev = root;
        recoverTreeHelp(root->right);

    }
    void recoverTree(TreeNode* root)
    {
        recoverTreeHelp(root);
        swap(first->val, second->val);
    }
};