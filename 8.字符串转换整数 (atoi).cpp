#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int ans = 0;
        bool isNegative = false;
        while ((s[i] == ' ') && i<s.size()) {
            i++;
        }
        if (s[i] == '-') {
            isNegative = true;
            i++;
        }else if(s[i]=='+') {
            i++;
        }
        while (i < s.size() && isdigit(s[i])) {
            int n = s[i] - '0';
            if (ans > INT_MAX / 10 || (ans == INT_MAX/10 && n > INT_MAX % 10)) {
                return !isNegative ? INT_MAX : INT_MIN;
            }
            ans = ans * 10 + n;
            i++;
        }
        if (!isNegative) {
            return ans;
        }else {
            return -ans;
        }
    }
};