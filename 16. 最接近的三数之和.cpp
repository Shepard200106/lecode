#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0;
        int t1 = INT_MAX;
        int n = nums.size();
        int x = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                x = nums[i] + nums[j] + nums[k];
                int y = abs(target - x);
                if (t1 > y) {
                    t1 = y;
                    ans = x;
                }
                else {
                    if (x > target) {
                        k--;
                    }
                    else if (x < target) {
                        j++;
                    }
                    else {
                        return target;
                    }
                }
            }
        }
        return ans;
    }
};
