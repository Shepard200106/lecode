#include<iostream>
#include<string>
#include<stack>
#include<cmath>
#include<vector>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        //通过余数求最后一位，通过INT_MAX/10防止越界
        int res = 0;
        while (x != 0) {
            //最大位数除10用于防止后续计算越界，如果不除10，当res正好10位时再乘10就会越界
            if (abs(res) > INT_MAX/10)return 0;
            //此处*10用于增加位数，对10取余用于取最后一位进行倒置
            res = res * 10 + x % 10;
            //去除已经转置好的位数
            x /= 10;
        }
        return res;
    }
};