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
                // 多余的右括号是不需要的，标记
                if (st.empty())mark[i] = 1;
                else st.pop();
            }
        }
        // 未匹配的左括号是不需要的，标记
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