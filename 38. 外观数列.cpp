#include"headFile.h"
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 2; i <= n; i++) {
            string temp = "";
            int pos = 0;
            int start = 0;
            while (pos < ans.size()) {
                while (pos < ans.size() && ans[pos] == ans[start]) {
                    pos++;
                }
                temp += to_string(pos - start) + ans[start];
                start = pos;
            }
            ans = temp;
        }
        return ans;
    }
};
