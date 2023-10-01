#include"headFile.h"
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string ans = "0";
        int m = num1.size();
        int n = num2.length();
        for (int i = n - 1; i >= 0; --i) {
            string curr;
            int add = 0;
            for (int j = n - 1; j > i; j--) {
                curr.push_back(0);
            }
            int y = num2.at(i) - '0';
            for (int j = m - 1; j >= 0; j--) {
                int x = num1.at(j) - '0';
                int temp = x * y + add;
                curr.push_back(temp % 10);
                add = temp / 10;
            }
            while (add != 0) {
                curr.push_back(add % 10);
                add = add / 10;
            }
            reverse(curr.begin(), curr.end());
            for (auto& c : curr) {
                c += '0';
            }
            ans = addString(ans, curr);
        }
        return ans;
    }
    string addString(string& num1, string& num2) {
        int m = num1.length() - 1;
        int n = num2.length() - 1;
        int add = 0;
        string ans;
        while (m >= 0 || n >= 0 || add != 0) {
            int x = m >= 0 ? num1.at(m) - '0' : 0;
            int y = n >= 0 ? num2.at(n) - '0' : 0;
            int result = x + y + add;
            ans.push_back(result % 10);
            add = result / 10;
            m--; n--;
        }
        reverse(ans.begin(), ans.end());
        for (auto& c : ans) {
            c += '0';
        }
        return ans;
    }
};
