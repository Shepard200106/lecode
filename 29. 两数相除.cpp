#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    int div(int a, int b) {
        if (a > b)return 0;
        int res = 1, step = b;
        while (a - step <= step) {
            step += step;
            res += res;
        }
        return res + div(a - step, b);
    }
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)return INT_MAX;
        if (divisor == 1)return dividend;
        int flag = 0;
        if (divisor > 0)divisor = -divisor, flag ^= 1;
        if (dividend > 0)dividend = -dividend, flag ^= 1;
        return flag ? -div(dividend, divisor) : div(dividend, divisor);
    }
};
