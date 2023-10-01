#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
/*
作者：ylb
链接：https://leetcode.cn/problems/3sum/solutions/2336474/python3javacgotypescript-yi-ti-yi-jie-pa-7z00/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2 && nums[i]<= 0; ++i) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1; int k = n - 1;
            while (j < k) {
                int x = nums[i] + nums[j] + nums[k];
                if (x < 0) {
                    ++j;
                }
                else if(x>0){
                    --k;
                }
                else {
                    ans.push_back({ nums[i],nums[j++],nums[k--] });
                    while (j<k && nums[j] == nums[j-1]) {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        --k;
                    }
                }
            }
        }
        return ans;
    }
};