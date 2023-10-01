#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0;
        int i = 0;
        int j = height.size() - 1;
        int max=0;
        //使用夹逼法减少时间复杂度
        //由题意可知，宽度每次减一决定面积的是较小的那个高
        //但是同样若想使面积越大则高应越大
        while (i < j) {
            s = (j-i) * (height[i] <= height[j] ? height[i] : height[j]);
            if (max < s) {
                max = s;
            }
            height[i] <= height[j] ? i++ : j--;
        }
        return max;
    }
};
