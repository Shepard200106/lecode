#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 1;
        bool flag = false;
        if (n == 0) {
            return;
        }
        while (n > 0) {
            if (nums[n] <= nums[n - 1]) {
                n--;
                flag = true;
            }
            else {
                flag = false;
                break;
            }
        }
        if (flag) {
            sort(nums.begin(), nums.end());
            return;
        }
        int m = nums.size() - 1;
        while (m > 0) {
            if (nums[m] <= nums[n - 1]) {
                m--;
            }
            else {
                break;
            }
        }
        int t = nums[n - 1];
        nums[n - 1] = nums[m];
        nums[m] = t;
         sort(nums.begin() + n , nums.end());
    }
};