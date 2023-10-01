#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    /* 计算 p[j..] 是否匹配 s[i..] */
    bool dp(string& s, int i, string& p, int j)
    {
        int m = s.size(), n = p.size();

        if (i == s.size())
        {
            // 如果能匹配空串，一定是字符和 * 成对儿出现
            if ((n - j) % 2 == 1)
            {
                return false;
            }
            // 检查是否为 x*y*z* 这种形式
            for (; j + 1 < p.size(); j += 2)
            {
                if (p[j + 1] != '*')
                {
                    return false;
                }
            }
            return true;
        }

        if (s[i] == p[j] || p[j] == '.')
        {
            // 匹配
            if (j < p.size() - 1 && p[j + 1] == '*')
            {
                // 通配符匹配 0 次或多次
                return dp(s, i, p, j + 2)
                    || dp(s, i + 1, p, j);
            }
            else
            {
                // 常规匹配 1 次
                return dp(s, i + 1, p, j + 1);
            }
        }
        else
        {
            // 不匹配
            if (j < p.size() - 1 && p[j + 1] == '*')
            {
                // 通配符匹配 0 次
                return dp(s, i, p, j + 2);
            }
            else
            {
                // 无法继续匹配
                return false;
            }
        }
    }

    // 动态规划
    bool isMatch(string s, string p) {
        return dp(s, 0, p, 0);
    }
};
