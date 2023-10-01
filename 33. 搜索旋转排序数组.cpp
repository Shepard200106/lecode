#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size() - 1;
        if (n < 0)return -1;
        if (target >= nums[0]) {
            for (int i = 0; i <= n; i++) {
                if (nums[i] == target)return i;
            }
        }
        else if (target <= nums[n]) {
            for (int i = n; i > 0; i-- ) {
                if (nums[i] == target)return i;
            }
        }
        return -1;
    }
};
/*¶þ·Ö·¨*/
/*class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        if (nums.size() == 1) return target == nums[0] ? 0 : -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid])
            {
                if (nums[0] <= target && nums[mid] > target)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < target && nums[nums.size() - 1] >= target)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};*/