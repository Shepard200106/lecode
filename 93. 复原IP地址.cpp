#include"headFile.h"
class Solution {
private:
    vector<string>ans;
    vector<string>temp;
public:
    void dfs(int start, string s)
    {
        if (start == s.size() && temp.size() == 4)
        {
            //temp÷–”–4∂Œ«“sΩ· ¯
            string str = temp[0];
            for (int i = 0; i < 3; i++)
            {
                str = str + "." + temp[i + 1];
            }
            ans.push_back(str);
            return;
        }
        else if (start < s.size() && temp.size() == 4)
        {
            return;
        }
        for (int len = 1; len <= 3; len++)
        {
            if (start >= s.size())
                return;
            if (len != 1 && s[start] == '0')
                return;
            string str = s.substr(start, len);
            if (len == 3 && atoi(str.c_str()) > 255)
                return;
            temp.push_back(str);
            dfs(start+len, s);
            temp.pop_back();
        }

    }
    vector<string> restoreIpAddresses(string s)
    {
        dfs(0, s);
        return ans;
    }
};