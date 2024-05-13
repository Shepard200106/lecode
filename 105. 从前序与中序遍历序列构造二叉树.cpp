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
    unordered_map<int, int>index;
public:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right)
    {
        if (preorder_left > preorder_right)
        {
            return nullptr;
        }
        //ȷ�ϸ��ڵ�
        int preorder_root = preorder_left;
        //ȷ����������еĸ��ڵ�λ��
        int inorder_root = index[preorder[preorder_left]];
        int size_left_sub = inorder_root - inorder_left;
        //�����½ڵ�
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        //��������
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_sub, inorder_left, inorder_root - 1);
        root->right = myBuildTree(preorder, inorder, preorder_left + size_left_sub + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int n = preorder.size();
        // �����ϣӳ�䣬�������ǿ��ٶ�λ���ڵ�
        for (int i = 0; i < n; ++i)
        {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};