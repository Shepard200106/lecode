#include"headFile.h"
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
    {
    }
};
class Solution {
public:
    TreeNode* myBuildTree(int inLeft,int inRight,int postLeft,int postRight, vector<int>& in, vector<int>& post)
    {
        if (inLeft > inRight)return nullptr;
        TreeNode* root = new TreeNode(post[postRight]);
        int inRoot = inLeft;
        while (inRoot <= inRight && in[inRoot] != post[postRight])inRoot++;
        int left = inRoot - inLeft;
        root->left = myBuildTree(inLeft, inRoot - 1, postLeft, postLeft + left - 1, in, post);
        root->right = myBuildTree(inRoot + 1, inRight, postLeft + left, postRight - 1, in, post);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return myBuildTree(0, inorder.size()-1, 0, postorder.size() - 1, inorder, postorder);
    }
};