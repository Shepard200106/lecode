#include"iostream"
#include"string"
#include"vector"
using namespace std;
//ʹ�� ������ַ���ģ���ά���飬����bool����������ת�ۡ�
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