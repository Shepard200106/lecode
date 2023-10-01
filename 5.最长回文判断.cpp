#include"iostream"
#include"string"
#include"vector"
using namespace std;
//使用 数组和字符串模拟二维数组，定义bool常量来控制转折。
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        bool goDown=false;
        vector<string>rows(min(numRows, int(s.size())));
        int line = 0;
        for (char c : s) {
            rows[line] += c;
            if (line == 0 || line == numRows - 1) {
                goDown = !goDown;
            }
            line += goDown ? 1 : -1;
        }
        string ans;
        for (string row : rows) {
            ans += row;
        }
        return ans;
    }
};