#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int getValue(char ch)
    {
        switch (ch)
        {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
        }
    };
    int romanToInt(string s) {
        int ans = 0;
        for (int i = s.size()-1; i >=0; i--) {
            if (i + 1== s.size()) {
                ans += getValue(s[i]);
            }
            else if (getValue(s[i]) >= getValue(s[i+1])) {
                ans += getValue(s[i]);
            }
            else {
                ans -= getValue(s[i]);
            }
        }
        return ans;
    }
};