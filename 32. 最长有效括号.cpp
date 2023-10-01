#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<bool>mark(s.length());
        for (int i = 0; i < mark.size(); i++)mark[i] = 0;
        int len = 0, ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else {
                // ������������ǲ���Ҫ�ģ����
                if (st.empty())mark[i] = 1;
                else st.pop();
            }
        }
        // δƥ����������ǲ���Ҫ�ģ����
        while (!st.empty())
        {
            mark[st.top()] = 1;
            st.pop();
        }
        for (int i = 0; i < s.length(); i++) {
            if (mark[i]) {
                len = 0;
                continue;
            }
            len++;
            ans = max(ans, len);
        }
        return ans;
    }
};