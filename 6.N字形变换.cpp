#include"iostream"
#include"string"
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        ans=s;
        if (numRows == 1) {
            return s;
        }
        else if (numRows > 2) {
            step = (numRows - 1) * 2;
        }
        num = 1;
        i = step;
        int k = 0;
        while(num<s.size()) {
            if (i>= s.size()) {
                step = step - 2;
                k++;
                if (k == numRows-1) {
                    step = (numRows - 1) * 2; ;
                }
                i = k;
            }
            if (i < s.size()) {
                ans[num] = s[i];
                i = i+step;
                num++;
            }
            
        }
        return ans;
    }
private:
    int step=2;
    int num, i = 0;
    string ans;
};
