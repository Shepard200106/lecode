#include"headFile.h"
/*
* 双指针法，从两边往中间进行遍历；
* 如果左边最大小于右边最大，那么左指针移动计算出每个点的储水量
* 同理右边
* 储水要求两边有墙，储水量跟最小墙高度有关；
* 底固定为1，高为小于另一侧但是高于本侧的墙高；
* 面积为高减储水区高度；
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int maxlelt = height[0];
        int maxright = height[n - 1];
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            maxlelt = max(maxlelt, height[left]);
            maxright = max(maxright, height[right]);
            if (maxlelt < maxright) {
                ans += maxlelt - height[left];
                left++;
            }
            else {
                ans += maxright - height[right];
                right--;
            }
        }
        return ans;
    }
};
