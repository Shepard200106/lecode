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
        //ö�ٿ��и��ڵ�
        for (int i = start; i <= end; i++)
        {
            //��ȡ����������
            vector<TreeNode*>leftTrees = generateTrees(start, i - 1);

            //��ȡ����������
            vector<TreeNode*>rightTrees = generateTrees(i + 1, end);

            // ��������������ѡ��һ������������������������ѡ��һ����������ƴ�Ӹ��ڵ���
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