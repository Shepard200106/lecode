#include"headFile.h"



/*
由题意可知：
1.数组内部除了负数外其余数字只有两种情况
    1.大于数组最大数；
    2.小于数组最大数；
2.对此，我们首先去除负数，进行一遍循环将其置为最大max
再进行一次循环，对数组内的数，将其绝对值位置上的数进行相反化
如果对应位置上的数大于数组大小则说明最小正数存在于数组大小内
如果该正数小于数组大小则说明该数字已经出现将该位置下的数置负
最后返回正数位置或者最后位置；
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0)   nums[i] = INT_MAX;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (abs(nums[i]) <= nums.size() && nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0)    return i + 1;
        }
        return nums.size() + 1;
    }
};