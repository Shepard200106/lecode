#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        sort(strs.begin(),strs.end());
        string st = strs.front();
        string en = strs.back();
        
        int num = min(st. size(), en.size());
        for (i = 0; i < num && st[i] == en[i] ; i++){}
        string ans = string(st, 0, i);
        return ans;
    }
};

