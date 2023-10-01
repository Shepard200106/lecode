#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    /* ���� p[j..] �Ƿ�ƥ�� s[i..] */
    bool dp(string& s, int i, string& p, int j)
    {
        int m = s.size(), n = p.size();

        if (i == s.size())
        {
            // �����ƥ��մ���һ�����ַ��� * �ɶԶ�����
            if ((n - j) % 2 == 1)
            {
                return false;
            }
            // ����Ƿ�Ϊ x*y*z* ������ʽ
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
            // ƥ��
            if (j < p.size() - 1 && p[j + 1] == '*')
            {
                // ͨ���ƥ�� 0 �λ���
                return dp(s, i, p, j + 2)
                    || dp(s, i + 1, p, j);
            }
            else
            {
                // ����ƥ�� 1 ��
                return dp(s, i + 1, p, j + 1);
            }
        }
        else
        {
            // ��ƥ��
            if (j < p.size() - 1 && p[j + 1] == '*')
            {
                // ͨ���ƥ�� 0 ��
                return dp(s, i, p, j + 2);
            }
            else
            {
                // �޷�����ƥ��
                return false;
            }
        }
    }

    // ��̬�滮
    bool isMatch(string s, string p) {
        return dp(s, 0, p, 0);
    }
};
