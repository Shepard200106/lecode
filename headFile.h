#pragma once
#include<iostream>
#include<vector>
#include<string>
#include <map>
#include<algorithm>
#include <unordered_map>
#include<stack>
#include<set>
#include<numeric>
#include <queue>
using namespace std;
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