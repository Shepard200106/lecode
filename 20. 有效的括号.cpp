#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if (s.size() == 0)return false;
        if (s.size() % 2 != 0)return false;
        for (char c:s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else if (st.empty()) {
                return false;
            }
            else if ((c == ')' && st.top() == '(') || (c == ']' && st.top() == '[') || (c == '}' && st.top() == '{')) {
                st.pop();
            }
            else {
                return false;
            }
        }
        if (st.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};